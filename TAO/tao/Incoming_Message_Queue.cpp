#include "Incoming_Message_Queue.h"
#include "debug.h"
#include "ace/Malloc_T.h"
#include "ace/Message_Block.h"

#if !defined (__ACE_INLINE__)
# include "Incoming_Message_Queue.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (tao, Incoming_Message_Queue, "$Id$")

#define TAO_DECLARE_IMQ_ERROR_VALUE(valuename) \
  auto_ptr<TAO_Queued_Data> TAO_Queued_Data::valuename (TAO_Queued_Data::make_queued_data(0))

TAO_DECLARE_IMQ_ERROR_VALUE(COULD_NOT_FIND_VALID_HEADER);
TAO_DECLARE_IMQ_ERROR_VALUE(DYNAMIC_ALLOCATION_FAILED);
TAO_DECLARE_IMQ_ERROR_VALUE(COULD_NOT_UNDERSTAND_HEADER);
auto_ptr<TAO_Queued_Data> TAO_Queued_Data::GENERAL_FAILURE (0);

TAO_Incoming_Message_Queue::TAO_Incoming_Message_Queue (TAO_ORB_Core *orb_core)
  : last_added_ (0),
    size_ (0),
    orb_core_ (orb_core)
{
}

TAO_Incoming_Message_Queue::~TAO_Incoming_Message_Queue (void)
{
  const int sz = this->size_;

  // Delete all the nodes left behind
  for (int i = 0;
       i < sz;
       ++i)
    {
      TAO_Queued_Data *qd = this->dequeue_head ();
      TAO_Queued_Data::release (qd);
    }
}

size_t
TAO_Incoming_Message_Queue::copy_tail (ACE_Message_Block &block)
{
  // The size of message that is copied
  size_t n = 0;

  if (this->size_ > 0)
    {
      // Check to see if the length of the incoming block is less than
      // that of the <missing_data_> of the tail.
      if (block.length () <= this->last_added_->missing_data_bytes_)
        {
          n = block.length ();
        }
      else
        {
          n = this->last_added_->missing_data_bytes_;
        }

      // Do the copy
      this->last_added_->msg_block_->copy (block.rd_ptr (),
                                            n);

      // Decerement the missing data
      this->last_added_->missing_data_bytes_ -= n;
    }

  return n;
}

TAO_Queued_Data *
TAO_Incoming_Message_Queue::dequeue_head (void)
{
  if (this->size_ == 0)
    return 0;

  // Get the node on the head of the queue...
  TAO_Queued_Data *head = this->last_added_->next_;

  // Reset the head node..
  this->last_added_->next_ = head->next_;
  
  // Decrease the size and reset last_added_ if empty
  if (--this->size_ == 0)
    this->last_added_ = 0;

  return head;
}

TAO_Queued_Data *
TAO_Incoming_Message_Queue::dequeue_tail (void)
{
  // This is a bit painful stuff...
  if (this->size_ == 0)
    return 0;

  // Get the node on the head of the queue...
  TAO_Queued_Data *head =
    this->last_added_->next_;

  while (head->next_ != this->last_added_)
    {
      head = head->next_;
    }

  // Put the head in tmp.
  head->next_ = this->last_added_->next_;

  TAO_Queued_Data *ret_qd = this->last_added_;

  this->last_added_ = head;

  // Decrease the size
  if (--this->size_ == 0)
    this->last_added_ = 0;

 return ret_qd;
}

int
TAO_Incoming_Message_Queue::enqueue_tail (TAO_Queued_Data *nd)
{
  if (this->size_ == 0)
    {
      this->last_added_ = nd;
      this->last_added_->next_ = this->last_added_;
    }
  else
    {
      nd->next_ = this->last_added_->next_;
      this->last_added_->next_ = nd;
      this->last_added_ = nd;
    }

  ++ this->size_;
  return 0;
}

TAO_Queued_Data *
TAO_Incoming_Message_Queue::find_fragment (CORBA::Octet major,
                                           CORBA::Octet minor) const
{
  TAO_Queued_Data *found = 0;
  if (this->last_added_ != 0)
    {
      TAO_Queued_Data *qd = this->last_added_->next_;

      do {
        if (qd->more_fragments_ &&
            qd->major_version_ == major && qd->minor_version_ == minor)
          {
            found = qd;
          }
        else
          {
            qd = qd->next_;
          }
      } while (found == 0 && qd != this->last_added_->next_);
    }

  return found;
}

TAO_Queued_Data *
TAO_Incoming_Message_Queue::find_fragment (CORBA::ULong request_id) const
{
  TAO_Queued_Data *found = 0;
  if (this->last_added_ != 0)
    {
      TAO_Queued_Data *qd = this->last_added_->next_;

      do {
        if (qd->more_fragments_ && qd->request_id_ == request_id)
          {
            found = qd;
          }
        else
          {
            qd = qd->next_;
          }
      } while (found == 0 && qd != this->last_added_->next_);
    }

  return found;
}


/************************************************************************/
// Methods  for TAO_Queued_Data
/************************************************************************/

TAO_Queued_Data::TAO_Queued_Data (ACE_Allocator *alloc)
  : msg_block_ (0)
  , current_state_ (INVALID)
  , missing_data_bytes_ (0)
  , byte_order_ (0)
  , major_version_ (0)
  , minor_version_ (0)
  , more_fragments_ (0)
  , request_id_ (0)
  , msg_type_ (TAO_PLUGGABLE_MESSAGE_MESSAGERROR)
  , next_ (0)
  , allocator_ (alloc)
{
}

TAO_Queued_Data::TAO_Queued_Data (ACE_Message_Block *mb,
                                  ACE_Allocator *alloc)
  : msg_block_ (mb)
  , current_state_ (INVALID)
  , missing_data_bytes_ (0)
  , byte_order_ (0)
  , major_version_ (0)
  , minor_version_ (0)
  , more_fragments_ (0)
  , request_id_ (0)
  , msg_type_ (TAO_PLUGGABLE_MESSAGE_MESSAGERROR)
  , next_ (0)
  , allocator_ (alloc)
{
}

TAO_Queued_Data::TAO_Queued_Data (const TAO_Queued_Data &qd)
  : msg_block_ (qd.msg_block_->duplicate ())
  , current_state_ (qd.current_state_)
  , missing_data_bytes_ (qd.missing_data_bytes_)
  , byte_order_ (qd.byte_order_)
  , major_version_ (qd.major_version_)
  , minor_version_ (qd.minor_version_)
  , more_fragments_ (qd.more_fragments_)
  , request_id_ (qd.request_id_)
  , msg_type_ (qd.msg_type_)
  , next_ (0)
  , allocator_ (qd.allocator_)
{
}


/*!
  \brief Allocate and return a new empty message block of size \a new_size mimicking parameters of \a mb.

  This function allocates a new aligned message block using the same
  allocators and flags as found in \a mb.  The size of the new message
  block is at least \a new_size; the size may be adjusted up in order
  to accomodate alignment requirements and still fit \a new_size bytes
  into the aligned buffer.
  
  \param mb message block whose parameters should be mimicked
  \param new_size size of the new message block (will be adjusted for proper alignment)
  \return an aligned message block with rd_ptr sitting at correct alignment spot, 0 on failure

  \author Thanks to Rich Seibel for helping implement with the public API for ACE_Message_Block!
 */
static ACE_Message_Block*
clone_mb_nocopy_size (ACE_Message_Block *mb, size_t span_size)
{
  // Calculate the required size of the cloned block with alignment
  size_t aligned_size = ACE_CDR::first_size (span_size + ACE_CDR::MAX_ALIGNMENT);

  // Get the allocators
  ACE_Allocator *data_allocator;
  ACE_Allocator *data_block_allocator;
  ACE_Allocator *message_block_allocator;
  mb->access_allocators (data_allocator, 
                         data_block_allocator, 
                         message_block_allocator);

  // Create a new Message Block
  ACE_Message_Block *nb;
  ACE_NEW_MALLOC_RETURN (nb,
                         ACE_static_cast(ACE_Message_Block*,
                                         message_block_allocator->malloc (
                                           sizeof (ACE_Message_Block))),
                         ACE_Message_Block(aligned_size,
                                           mb->msg_type(),
                                           mb->cont(),
                                           0, //we want the data block created
                                           data_allocator,
                                           mb->locking_strategy(),
                                           mb->msg_priority(),
                                           mb->msg_execution_time (),
                                           mb->msg_deadline_time (),
                                           data_block_allocator,
                                           message_block_allocator),
                         0);

  ACE_CDR::mb_align (nb);

  // Copy the flags over, but be SURE to clear the DONT_DELETE flag, since
  // we just dynamically allocated the two things.
  nb->set_flags (mb->flags());
  nb->clr_flags (ACE_Message_Block::DONT_DELETE);

  return nb;
}

/*!
  \brief Copy data from \a src->rd_ptr to \a dst->wr_ptr, of at most \a span_size bytes.

  (This is similar to memcpy, although with message blocks we can be a
  little smarter.)  This function assumes that \a dst has enough space
  for \a span_size bytes, and that \a src has at least \a span_size
  bytes available to copy.  When everything is copied \a dst->wr_ptr
  gets updated accordingly, but \a src->rd_ptr is left to the caller
  to update.

  \param dst the destination message block
  \param src the source message block
  \param span_size size of the maximum span of bytes to be copied
  \return 0 on failure, otherwise \a dst
 */
static ACE_Message_Block*
copy_mb_span (ACE_Message_Block *dst, ACE_Message_Block *src, size_t span_size)
{
  // @todo check for enough space in dst, and src contains at least span_size

  if (src == 0 || dst == 0)
    return 0;

  if (span_size == 0)
    return dst;

  dst->copy (src->rd_ptr (), span_size);
  return dst;
}

/*static*/
TAO_Queued_Data *
TAO_Queued_Data::make_uncompleted_message (ACE_Message_Block *mb,
                                           TAO_Pluggable_Messaging &msging_obj,
                                           ACE_Allocator *alloc)
{
  register TAO_Queued_Data *new_qd = 0;
  register TAO_Queued_Data *error = GENERAL_FAILURE.get();
  register const size_t HDR_LEN = msging_obj.header_length (); /* COMPUTE ONCE! */
  register const size_t MB_LEN = mb->length (); /* COMPUTE ONCE! */

  // Validate arguments.
  if (mb == 0)
    return GENERAL_FAILURE.get();

  new_qd = make_queued_data (alloc);
  if (new_qd == 0)
    return DYNAMIC_ALLOCATION_FAILED.get();

  // do we have enough bytes to make a complete header?
  if (MB_LEN >= HDR_LEN)
    {
      // Since we have enough bytes to make a complete header,
      // the header needs to be valid.  Check that now, and punt
      // if it's not valid.
      if (! msging_obj.check_for_valid_header (*mb))
        {
          error = COULD_NOT_FIND_VALID_HEADER.get();
          goto failure;
        }
      else
        {
          new_qd->current_state_ = WAITING_TO_COMPLETE_PAYLOAD;
          msging_obj.set_queued_data_from_message_header (new_qd, *mb);
          if (new_qd->current_state_ == INVALID)
            {
              error = COULD_NOT_UNDERSTAND_HEADER.get();
              goto failure;
            }

          // missing_data_bytes_ now has the full GIOP message size, so we allocate
          // a new message block of that size, plus the header.
          new_qd->msg_block_ = clone_mb_nocopy_size  (mb,
                                                      new_qd->missing_data_bytes_ +
                                                      HDR_LEN);
          // Of course, we don't have the whole message (if we did, we
          // wouldn't be here!), so we copy only what we've got, i.e., whatever's
          // in the message block.
          if (copy_mb_span (new_qd->msg_block_, mb, MB_LEN) == 0)
            goto failure;

          // missing_data_bytes_ now has the full GIOP message size, but
          // there might still be stuff in mb.  Therefore, we have to adjust
          // missing_data_bytes_, i.e., decrease it by the number of "actual
          // payload bytes" in mb.
          //
          // "actual payload bytes" :== length of mb (which included the header) - header length
          new_qd->missing_data_bytes_ -= (MB_LEN - HDR_LEN);
          mb->rd_ptr (MB_LEN);
        }
    }
  else
    {
      new_qd->current_state_ = WAITING_TO_COMPLETE_HEADER;
      new_qd->msg_block_ = clone_mb_nocopy_size (mb, HDR_LEN);
      if (new_qd->msg_block_ == 0 ||
          copy_mb_span (new_qd->msg_block_, mb, MB_LEN) == 0)
        goto failure;
      new_qd->missing_data_bytes_ = HDR_LEN - MB_LEN;
      mb->rd_ptr (MB_LEN);
    }

  ACE_ASSERT (new_qd->current_state_ != INVALID);
  if (TAO_debug_level > 7)
    {
      const char* s = "?unk?";
      switch (new_qd->current_state_)
        {
        case WAITING_TO_COMPLETE_HEADER: s = "WAITING_TO_COMPLETE_HEADER"; break;
        case WAITING_TO_COMPLETE_PAYLOAD: s = "WAITING_TO_COMPLETE_PAYLOAD"; break;
        case INVALID: s = "INVALID"; break;
        case COMPLETED: s = "COMPLETED"; break;
        }
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Queued_Data::make_uncompleted_message: ")
                  ACE_TEXT ("made uncompleted message from %u bytes into qd=%-08x:")
                  ACE_TEXT ("state=%s,missing_data_bytes=%u\n"),
                  new_qd->msg_block_->length(), new_qd, s, new_qd->missing_data_bytes_));
    }
  return new_qd;

failure:
  if (TAO_debug_level > 7)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Queued_Data::make_uncompleted_message: ")
                  ACE_TEXT ("failed to make uncompleted message: mb=%-08x, qd=%-08x\n"),
                  mb, new_qd));
    }
  if (error != DYNAMIC_ALLOCATION_FAILED.get())
    TAO_Queued_Data::release (new_qd);
  return error;
}


/*static*/
TAO_Queued_Data *
TAO_Queued_Data::make_completed_message (ACE_Message_Block &mb,
                                         TAO_Pluggable_Messaging &msging_obj,
                                         ACE_Allocator *alloc)
{
  register TAO_Queued_Data* error = GENERAL_FAILURE.get();
  register const size_t HDR_LEN = msging_obj.header_length ();
  register const size_t MB_LEN  = mb.length ();

  // Validate arguments.
  if (MB_LEN < HDR_LEN)
    return GENERAL_FAILURE.get();

  // Verify that we have a valid GIOP message.
  if (msging_obj.check_for_valid_header (mb) != 1)
    return COULD_NOT_FIND_VALID_HEADER.get();

  size_t total_msg_len = 0;
  register TAO_Queued_Data *new_qd = make_queued_data (alloc);
  if (new_qd == 0)
    return DYNAMIC_ALLOCATION_FAILED.get();

  // We can assume that there are enough bytes for a header, so
  // extract the header data.  Don't assume that there's enough for
  // the payload just yet.
  new_qd->current_state_ = WAITING_TO_COMPLETE_PAYLOAD;
  msging_obj.set_queued_data_from_message_header (new_qd, mb);
  if (new_qd->current_state_ == INVALID)
    {
      error = COULD_NOT_UNDERSTAND_HEADER.get();
      goto failure;
    }

  // new_qd_->missing_data_bytes_ + protocol header length should be
  // *at least* the length of the message.  Verify that we have that
  // many bytes in the message block and, if we don't, release the new
  // qd and fail.
  total_msg_len = new_qd->missing_data_bytes_ + HDR_LEN;
  if (total_msg_len > MB_LEN)
    goto failure;

  // Make a copy of the relevant portion of mb and hang on to it
  if ((new_qd->msg_block_ = clone_mb_nocopy_size (&mb, total_msg_len)) == 0)
    goto failure;

  if (copy_mb_span (new_qd->msg_block_, &mb, total_msg_len) == 0)
    goto failure;
  
  // Update missing data and the current state
  new_qd->missing_data_bytes_ = 0;
  new_qd->current_state_ = COMPLETED;

  // Advance the rd_ptr on the message block
  mb.rd_ptr (total_msg_len);

  if (TAO_debug_level > 7)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Queued_Data::make_complete_message: ")
                  ACE_TEXT ("extracted complete message (%u bytes incl hdr) from mblk=%-08x into qd=%-08x\n"),
                  total_msg_len, &mb, new_qd));
    }

  return new_qd;

failure:
  if (TAO_debug_level > 7)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("TAO (%P|%t) Queued_Data::make_complete_message: ")
                  ACE_TEXT ("failed to find complete message in mblk=%-08x; leaving %u bytes in block\n"),
                  &mb, MB_LEN));
      if (TAO_debug_level >= 10)
        ACE_HEX_DUMP ((LM_DEBUG,
                       mb.rd_ptr (), MB_LEN,
                       ACE_TEXT ("                residual bytes in buffer")));

    }
  if (error != DYNAMIC_ALLOCATION_FAILED.get())
    TAO_Queued_Data::release (new_qd);
  return error;
}

/* static */
TAO_Queued_Data*
TAO_Queued_Data::make_close_connection (ACE_Allocator *alloc)
{
  TAO_Queued_Data* qd = TAO_Queued_Data::make_queued_data (alloc);
  if (qd == 0)
    return 0;

  qd->msg_type_ = TAO_PLUGGABLE_MESSAGE_CLOSECONNECTION;
  qd->current_state_ = TAO_Queued_Data::COMPLETED;

  return qd;
}

/*static*/
TAO_Queued_Data *
TAO_Queued_Data::make_queued_data (ACE_Allocator *alloc)
{
  TAO_Queued_Data *qd = 0;

  if (alloc)
    {
      ACE_NEW_MALLOC_RETURN (qd,
                             static_cast<TAO_Queued_Data *> (
                               alloc->malloc (sizeof (TAO_Queued_Data))),
                             TAO_Queued_Data (alloc),
                             0);

      return qd;
    }

  // No allocator, so use the global pool!
  // @@ TODO: We should be removing this at some point of time!
  if (TAO_debug_level == 4)
    {
      // This debug is for testing purposes!
      ACE_DEBUG ((LM_DEBUG,
                  "TAO (%P|%t) - Queued_Data::make_queued_data\n",
                  "Using global pool for allocation \n"));
    }

  ACE_NEW_RETURN (qd,
                  TAO_Queued_Data,
                  0);

  return qd;
}

/*static*/
void
TAO_Queued_Data::release (TAO_Queued_Data *qd)
{
  //// TODO
  ACE_Message_Block::release (qd->msg_block_);

  if (qd->allocator_)
    {
      ACE_DES_FREE (qd,
                    qd->allocator_->free,
                    TAO_Queued_Data);

      return;
    }

  // @@todo: Need to be removed at some point of time!
  if (TAO_debug_level == 4)
    {
      // This debug is for testing purposes!
      ACE_DEBUG ((LM_DEBUG,
                  "TAO (%P|%t) - Queued_Data[%d]::release\n",
                  "Using global pool for releasing \n"));
    }
  delete qd;

}


TAO_Queued_Data *
TAO_Queued_Data::duplicate (TAO_Queued_Data &sqd)
{
  // Check to see if the underlying block is on the stack. If not it
  // is fine. If the datablock is on stack, try to make a copy of that
  // before doing a duplicate.
  // @@ todo: Theoretically this should be within the Message Block,
  // but we dont have much scope to do this in that mess. Probably in
  // the next stage of MB rewrite we should be okay
  ACE_Message_Block::Message_Flags fl =
    sqd.msg_block_->self_flags ();

  if (ACE_BIT_ENABLED (fl,
                       ACE_Message_Block::DONT_DELETE))
    (void) TAO_Queued_Data::replace_data_block (*sqd.msg_block_);


  TAO_Queued_Data *qd = 0;

  if (sqd.allocator_)
    {
      ACE_NEW_MALLOC_RETURN (qd,
                             static_cast<TAO_Queued_Data *> (
                               sqd.allocator_->malloc (sizeof (TAO_Queued_Data))),
                             TAO_Queued_Data (sqd),
                             0);

      return qd;
    }

  // No allocator, so use the global pool!
  // @@ TODO: We should be removing this at some point of time!
  if (TAO_debug_level == 4)
    {
      // This debug is for testing purposes!
      ACE_DEBUG ((LM_DEBUG,
                  "TAO (%P|%t) - Queued_Data[%d]::duplicate\n",
                  "Using global pool for allocation \n"));
    }

  ACE_NEW_RETURN (qd,
                  TAO_Queued_Data (sqd),
                  0);

  return qd;
}

void
TAO_Queued_Data::consolidate (void)
{
  // Is this a chain of fragments?
  if (this->more_fragments_ && this->msg_block_->cont () != 0)
    {
      // Create a message block big enough to hold the entire chain
      ACE_Message_Block *dest = clone_mb_nocopy_size (
                                      this->msg_block_,
                                      this->msg_block_->total_length ());
      // Reset the cont() parameter
      dest->cont (0);

      // Use ACE_CDR to consolidate the chain for us
      ACE_CDR::consolidate (dest, this->msg_block_);

      // free the original message block chain
      this->msg_block_->release ();

      // Set the message block to the new consolidated message block
      this->msg_block_ = dest;
      this->more_fragments_ = 0;
    }
}

