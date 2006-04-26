#include "tao/Incoming_Message_Queue.h"
#include "tao/debug.h"

#include "ace/Log_Msg.h"
#include "ace/Malloc_Base.h"


#if !defined (__ACE_INLINE__)
# include "tao/Incoming_Message_Queue.inl"
#endif /* __ACE_INLINE__ */


ACE_RCSID (tao,
           Incoming_Message_Queue,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Incoming_Message_Queue::TAO_Incoming_Message_Queue (TAO_ORB_Core *orb_core)
  : last_added_ (0),
    size_ (0),
    orb_core_ (orb_core)
{
}

TAO_Incoming_Message_Queue::~TAO_Incoming_Message_Queue (void)
{
  const CORBA::ULong sz = this->size_;

  // Delete all the nodes left behind
  for (CORBA::ULong i = 0;
       i < sz;
       ++i)
    {
      TAO_Queued_Data *qd = this->dequeue_head ();
      TAO_Queued_Data::release (qd);
    }
}


TAO_Queued_Data *
TAO_Incoming_Message_Queue::dequeue_head (void)
{
  if (this->size_ == 0)
    return 0;

  // Get the node on the head of the queue...
  TAO_Queued_Data * const head = this->last_added_->next_;

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


/************************************************************************/
// Methods  for TAO_Queued_Data
/************************************************************************/

/*!
 * @brief Allocate and return a new empty message block of size \a span_size
 * mimicking parameters of \a mb.
 *
 * This function allocates a new aligned message block using the same
 * allocators and flags as found in \a mb.  The size of the new message
 * block is at least \a span_size; the size may be adjusted up in order
 * to accomodate alignment requirements and still fit \a span_size bytes
 * into the aligned buffer.
 *
 * @param mb message block whose parameters should be mimicked
 * @param span_size size of the new message block (will be adjusted for proper
 * alignment)
 * @return an aligned message block with rd_ptr sitting at correct
 * alignment spot, 0 on failure
 */
static ACE_Message_Block*
clone_mb_nocopy_size (ACE_Message_Block *mb, size_t span_size)
{
  // Calculate the required size of the cloned block with alignment
  size_t const aligned_size = ACE_CDR::first_size (span_size + ACE_CDR::MAX_ALIGNMENT);

  // Get the allocators
  ACE_Allocator *data_allocator = 0;
  ACE_Allocator *data_block_allocator = 0;
  ACE_Allocator *message_block_allocator = 0;
  mb->access_allocators (data_allocator,
                         data_block_allocator,
                         message_block_allocator);

  // Create a new Message Block
  ACE_Message_Block *nb = 0;
  ACE_NEW_MALLOC_RETURN (nb,
                         static_cast<ACE_Message_Block*> (
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

TAO_Queued_Data::TAO_Queued_Data (ACE_Allocator *alloc)
  : msg_block_ (0),
    missing_data_ (0),
    major_version_ (0),
    minor_version_ (0),
    byte_order_ (0),
    more_fragments_ (0),
    msg_type_ (TAO_PLUGGABLE_MESSAGE_MESSAGERROR),
    next_ (0),
    allocator_ (alloc)
{
}

TAO_Queued_Data::TAO_Queued_Data (ACE_Message_Block *mb,
                                  ACE_Allocator *alloc)
  : msg_block_ (mb),
    missing_data_ (0),
    major_version_ (0),
    minor_version_ (0),
    byte_order_ (0),
    more_fragments_ (0),
    msg_type_ (TAO_PLUGGABLE_MESSAGE_MESSAGERROR),
    next_ (0),
    allocator_ (alloc)
{
}

TAO_Queued_Data::TAO_Queued_Data (const TAO_Queued_Data &qd)
  : msg_block_ (qd.msg_block_->duplicate ()),
    missing_data_ (qd.missing_data_),
    major_version_ (qd.major_version_),
    minor_version_ (qd.minor_version_),
    byte_order_ (qd.byte_order_),
    more_fragments_ (qd.more_fragments_),
    msg_type_ (qd.msg_type_),
    next_ (0),
    allocator_ (qd.allocator_)
{
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
                  "TAO (%P|%t) - Queued_Data::get_queued_data\n"
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

int
TAO_Queued_Data::consolidate (void)
{
  // Is this a chain of fragments?
  if (this->more_fragments_ && this->msg_block_->cont () != 0)
    {
      // Create a message block big enough to hold the entire chain
      ACE_Message_Block *dest = clone_mb_nocopy_size (
                                      this->msg_block_,
                                      this->msg_block_->total_length ());

      if (0 == dest)
        {
          // out of memory
          return -1;
        }
      // Memory allocation succeeded, the new message block can hold the consolidated
      // message. The following code just copies all the data into this new message block.
      // No further memory allocation will take place.

      // Reset the cont() parameter.  We have cloned the message
      // block but not the chain as we will no longer have chain.
      dest->cont (0);

      // Use ACE_CDR to consolidate the chain for us
      ACE_CDR::consolidate (dest, this->msg_block_);

      // free the original message block chain
      this->msg_block_->release ();

      // Set the message block to the new consolidated message block
      this->msg_block_ = dest;
      this->more_fragments_ = 0;
    }

  return 0;
}

TAO_END_VERSIONED_NAMESPACE_DECL
