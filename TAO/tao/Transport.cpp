// -*- C++ -*-
// $Id$

#include "Transport.h"

#include "Exception.h"
#include "ORB_Core.h"
#include "Client_Strategy_Factory.h"
#include "Wait_Strategy.h"
#include "Transport_Mux_Strategy.h"
#include "Stub.h"
#include "Sync_Strategies.h"
#include "Queued_Message.h"
#include "Flushing_Strategy.h"
#include "debug.h"

#include "ace/Message_Block.h"

#if !defined (__ACE_INLINE__)
# include "Transport.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(tao, Transport, "$Id$")

// Constructor.
TAO_Transport::TAO_Transport (CORBA::ULong tag,
			      TAO_ORB_Core *orb_core)
  : tag_ (tag)
  , orb_core_ (orb_core)
  , bidirectional_flag_ (-1)
  , head_ (0)
  , tail_ (0)
{
  TAO_Client_Strategy_Factory *cf =
    this->orb_core_->client_factory ();

  // Create WS now.
  this->ws_ = cf->create_wait_strategy (this);

  // Create TMS	now.
  this->tms_ = cf->create_transport_mux_strategy (this);
}

TAO_Transport::~TAO_Transport (void)
{
  delete this->ws_;
  this->ws_ = 0;

  delete this->tms_;
  this->tms_ = 0;

  //  delete this->buffering_queue_;

  TAO_Queued_Message *i = this->head_;
  while (i != 0)
    {
      // @@ This is a good point to insert a flag to indicate that a
      // CloseConnection message was successfully received.
      i->connection_closed ();

      TAO_Queued_Message *tmp = i;
      i = i->next ();

      tmp->destroy ();
    }
}

int
TAO_Transport::handle_output ()
{
  if (TAO_debug_level > 4)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "TAO (%P|%t) - Transport[%d]::handle_output\n",
                  this->handle ()));
    }

  int retval;
  do
    {
      // The reactor is asking us to send more data, first check if
      // there is a current message that needs more sending:
      retval = this->send_current_message ();

      if (TAO_debug_level > 4)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "TAO (%P|%t) - Transport[%d]::handle_output, "
                      "send_current_message returns %d/%d\n",
                      this->handle (),
                      retval, errno));
        }

      if (retval == 1)
        {
          // ... there is no current message or it was completely
          // sent, time to check the queue....
          // ... no more messages in the queue, cancel output...
          TAO_Flushing_Strategy *flushing_strategy =
            this->orb_core ()->flushing_strategy ();

          flushing_strategy->cancel_output (this);
          return 0;
        }
      // ... on Win32 we must continue until we get EWOULDBLOCK ...
    }
  while (retval > 0);

  // Any errors are returned directly to the Reactor
  return retval;
}

static void
dump_iov (iovec *iov, int iovcnt, ACE_HANDLE handle, size_t current_transfer)
{
  ACE_DEBUG ((LM_DEBUG,
              "TAO (%P|%t) - Transport[%d]::send_message_block_chain"
              " sending %d buffers\n",
              handle, iovcnt));
  for (int i = 0; i != iovcnt && 0 < current_transfer; ++i)
    {
      size_t iov_len = iov[i].iov_len;

      // Possibly a partially sent iovec entry.
      if (current_transfer < iov_len)
        iov_len = current_transfer;

      ACE_DEBUG ((LM_DEBUG,
                  "TAO (%P|%t) - Transport[%d]::send_message_block_chain"
                  " buffer %d/%d has %d bytes\n",
                  handle, 
                  i, iovcnt,
                  iov_len));
      size_t len;
      for (size_t offset = 0; offset < iov_len; offset += len)
        {
          len = iov_len - offset;
          if (len > 512)
            len = 512;
          ACE_HEX_DUMP ((LM_DEBUG,
                         ACE_static_cast(char*,iov[i].iov_base) + offset,
                         len,
                         "TAO (%P|%t) - Transport::send_message_block_chain "));
        }
      current_transfer -= iov_len;
    }
  ACE_DEBUG ((LM_DEBUG,
              "TAO (%P|%t) - Transport[%d]::send_mesage_block_chain"
              " end of data\n",
              handle));
}

int
TAO_Transport::send_message_block_chain (const ACE_Message_Block *message_block,
                                         size_t &bytes_transferred,
                                         ACE_Time_Value *timeout)
{
  bytes_transferred = 0;

  iovec iov[IOV_MAX];
  int iovcnt = 0;

  while (message_block != 0)
    {
      size_t message_block_length =
        message_block->length ();

      // Check if this block has any data to be sent.
      if (message_block_length > 0)
        {
              // Collect the data in the iovec.
          iov[iovcnt].iov_base = message_block->rd_ptr ();
          iov[iovcnt].iov_len  = message_block_length;

          // Increment iovec counter.
          iovcnt++;

          // The buffer is full make a OS call.  @@ TODO find a way to
          // find IOV_MAX for platforms that do not define it rather
          // than simply setting IOV_MAX to some arbitrary value such
          // as 16.
          if (iovcnt == IOV_MAX)
            {
              size_t current_transfer = 0;

              ssize_t result =
                this->send (iov, iovcnt, current_transfer, timeout);

              if (TAO_debug_level > 6)
                {
                  dump_iov (iov, iovcnt, this->handle (), current_transfer);
                }

              // Add to total bytes transferred.
              bytes_transferred += current_transfer;

              // Errors.
              if (result == -1 || result == 0)
                return result;

              // Reset iovec counter.
              iovcnt = 0;
            }
        }

      // Select the next message block in the chain.
      message_block = message_block->cont ();
    }

  // Check for remaining buffers to be sent.  This will happen when
  // IOV_MAX is not a multiple of the number of message blocks.
  if (iovcnt != 0)
    {
      size_t current_transfer = 0;

      ssize_t result =
        this->send (iov, iovcnt, current_transfer, timeout);

      if (TAO_debug_level > 6)
        {
          dump_iov (iov, iovcnt, this->handle (), current_transfer);
        }

      // Add to total bytes transferred.
      bytes_transferred += current_transfer;

      // Errors.
      if (result == -1 || result == 0)
        return result;
    }

  // Return total bytes transferred.
  return bytes_transferred;
}

int
TAO_Transport::send_current_message (void)
{
  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, ace_mon, this->queue_mutex_, -1);

  if (this->head_ == 0)
    return 1;

  size_t bytes_transferred;

  ssize_t retval =
    this->send_message_block_chain (this->head_->mb (),
                                    bytes_transferred);
  if (retval == 0)
    {
      // The connection was closed, return -1 to have the Reactor
      // close this transport and event handler
      return -1;
    }

  // Because there can be a partial transfer we need to adjust the
  // number of bytes sent.
  this->head_->bytes_transferred (bytes_transferred);
  if (this->head_->done ())
    {
      // Remove the current message....
      TAO_Queued_Message *head = this->head_;
      head->remove_from_list (this->head_, this->tail_);

      head->destroy ();
    }

  if (retval == -1)
    {
      // ... timeouts and flow control are not real errors, the
      // connection is still valid and we must continue sending the
      // current message ...
      if (errno == EWOULDBLOCK || errno == ETIME)
        return 0;

      return -1;
    }

  if (this->head_ == 0)
    return 1;
  return 0;
}

int
TAO_Transport::send_message_i (TAO_Stub *stub,
                               int twoway_flag,
                               const ACE_Message_Block *message_block,
                               ACE_Time_Value *max_wait_time)
{
  TAO_Flushing_Strategy *flushing_strategy =
    this->orb_core ()->flushing_strategy ();

  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, ace_mon, this->queue_mutex_, -1);

  int queue_empty = (this->head_ == 0);

  // Let's figure out if the message should be queued without trying
  // to send first:
  int must_queue = 0;
  if (this->head_ != 0)
    must_queue = 1;
  else if (!twoway_flag
           && stub->sync_strategy ().must_queue (queue_empty))
    {
      must_queue = 1;
    }
    
  TAO_Queued_Message *queued_message = 0;
  if (must_queue)
    {
      // ... simply queue the message ...

      if (TAO_debug_level > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "TAO (%P|%t) - Transport[%d]::send_message_i, "
                      "message is queued\n",
                      this->handle ()));
        }

      queued_message =
        this->copy_message_block (message_block);

      queued_message->push_back (this->head_, this->tail_);
    }
  else
    {
      // ... in this case we must try to send the message first ...

      if (TAO_debug_level > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "TAO (%P|%t) - Transport[%d]::send_message_i, "
                      "trying to send the message\n",
                      this->handle ()));
        }

      size_t byte_count;

      // @@ I don't think we want to hold the mutex here, however if
      // we release it we need to recheck the status of the transport
      // after we return... once I understand the final form for this
      // code I will re-visit this decision
      ssize_t n = this->send_message_block_chain (message_block,
                                                  byte_count,
                                                  max_wait_time);
      if (n == 0)
        return -1; // EOF
      else if (n == -1)
        {
          // ... if this is just an EWOULDBLOCK we must schedule the
          // message for later ...
          if (errno != EWOULDBLOCK)
            {
              return -1;
            }
        }

      // ... let's figure out if the complete message was sent ...
      if (message_block->total_length () == byte_count)
        {
          // Done, just return.  Notice that there are no allocations
          // or copies up to this point (though some fancy calling
          // back and forth).
          // This is the common case for the critical path, it should
          // be fast.
          return 0;
        }

      // ... the message was only partially sent, schedule reactive
      // output...
      flushing_strategy->schedule_output (this);

      // ... and set it as the current message ...
      if (twoway_flag)
        {
          // ... we are going to block, so there is no need to clone
          // the message block...
          queued_message =
            new TAO_Queued_Message (
                    ACE_const_cast(ACE_Message_Block*,message_block),
                    0);
        }
      else
        {
          queued_message =
            this->copy_message_block (message_block);
        }
      // @@ Revisit message queue allocations

      if (TAO_debug_level > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "TAO (%P|%t) - Transport[%d]::send_message_i, "
                      " queued anyway, %d bytes sent\n",
                      this->handle (),
                      byte_count));

          ACE_DEBUG ((LM_DEBUG,
                      "TAO (%P|%t) - Transport[%d]::send_message_i, "
                      " queued message contains %d bytes, %d transferred\n",
                      this->handle (),
                      queued_message->mb ()->total_length (),
                      byte_count));
        }

      queued_message->bytes_transferred (byte_count);

      if (TAO_debug_level > 6)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "TAO (%P|%t) - Transport[%d]::send_message_i, "
                      " queued message still has %d bytes to go\n",
                      this->handle (),
                      queued_message->mb ()->total_length ()));
        }

      // ... insert at the head of the queue, we can use push_back()
      // because the queue is empty ...
      queued_message->push_back (this->head_, this->tail_);
    }

  // ... two choices, this is a twoway request or not, if it is
  // then we must only return once the complete message has been
  // sent:

  if (twoway_flag)
    {
      // Release the mutex, other threads may modify the queue as we
      // block for a long time writing out data.
      ace_mon.release ();
      int result = flushing_strategy->flush_message (this, queued_message);
      queued_message->destroy ();
      return result;
    }

  // ... this is not a twoway.  We must check if the buffering
  // constraints have been reached, if so, then we should start
  // flushing out data....

  // First let's compute the size of the queue:
  size_t msg_count = 0;
  size_t total_bytes = 0;
  for (TAO_Queued_Message *i = this->head_; i != 0; i = i->next ())
    {
      msg_count++;
      total_bytes += i->mb ()->total_length ();
    }

  int set_timer;
  ACE_Time_Value interval;

  if (stub->sync_strategy ().buffering_constraints_reached (stub,
                                                            msg_count,
                                                            total_bytes,
                                                            set_timer,
                                                            interval))
    {
      ace_mon.release ();
      // @@ memory management of the queued messages is getting tricky.
      int result = flushing_strategy->flush_message (this,
                                                     this->tail_);
      return result;
    }
  else
    {
      // ... it is not time to flush yet, but maybe we need to set a
      // timer ...
      if (set_timer)
        {
          // @@ We need to schedule the timer. We should also be
          // careful not to schedule one if there is one scheduled
          // already.
        }
    }
  return 0;
}

int
TAO_Transport::idle_after_send (void)
{
  return this->tms ()->idle_after_send ();
}

int
TAO_Transport::idle_after_reply	(void)
{
  return this->tms ()->idle_after_reply	();
}

TAO_SYNCH_CONDITION *
TAO_Transport::leader_follower_condition_variable (void)
{
  return this->wait_strategy ()->leader_follower_condition_variable ();
}

int
TAO_Transport::tear_listen_point_list (TAO_InputCDR &)
{
  ACE_NOTSUP_RETURN(-1);
}

int
TAO_Transport::reactor_signalling (void)
{
  return 0;
}

TAO_Queued_Message *
TAO_Transport::copy_message_block (const ACE_Message_Block *message_block)
{
  size_t length = message_block->total_length ();

  // @@ Use Auto_Ptr<> to cleanup the message block, should the second
  // allocation fail
  ACE_Message_Block *copy;
  ACE_NEW_RETURN (copy, ACE_Message_Block (length), 0);
  for (const ACE_Message_Block *i = message_block;
       i != 0;
       i = i->cont ())
    copy->copy (i->rd_ptr (), i->length ());

  TAO_Queued_Message *msg;
  ACE_NEW_RETURN (msg, TAO_Queued_Message (copy, 1), 0);

  return msg;
}
