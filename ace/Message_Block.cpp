// Message_Block.cpp
// $Id$

#define ACE_BUILD_DLL
#include "ace/Message_Block.h"
#include "ace/Synch_T.h"

#if !defined (__ACE_INLINE__)
#include "ace/Message_Block.i"
#endif /* __ACE_INLINE__ */

ACE_ALLOC_HOOK_DEFINE(ACE_Message_Block)

void
ACE_Message_Block::data_block (ACE_Data_Block *db)
{
  ACE_TRACE ("ACE_Message_Block::data_block");
  if (this->data_block_ != 0)
    this->data_block_->release ();

  this->data_block_ = db;

  // Set the read and write pointers in the <Message_Block> to point
  // to the buffer in the <ACE_Data_Block>.
  this->rd_ptr (this->data_block ()->base ());
  this->wr_ptr (this->data_block ()->base ());
}

int
ACE_Message_Block::copy (const char *buf, size_t n)
{
  ACE_TRACE ("ACE_Message_Block::copy");
  // Note that for this to work correct, end() *must* be >= wr_ptr().
  size_t len = ACE_static_cast(size_t, this->end () - this->wr_ptr ());

  if (len < n)
    return -1;
  else
    {
      (void) ACE_OS::memcpy (this->wr_ptr (), buf, n);
      this->wr_ptr (n);
      return 0;
    }
}

int
ACE_Message_Block::copy (const char *buf)
{
  ACE_TRACE ("ACE_Message_Block::copy");
  // Note that for this to work correct, end() *must* be >= wr_ptr().
  size_t len = ACE_static_cast(size_t, (this->end () - this->wr_ptr ()));
  size_t buflen = ACE_OS::strlen (buf) + 1;

  if (len < buflen)
    return -1;
  else
    {
      (void) ACE_OS::memcpy (this->wr_ptr (), buf, buflen);
      this->wr_ptr (buflen);
      return 0;
    }
}

void
ACE_Data_Block::dump (void) const
{
  ACE_TRACE ("ACE_Data_Block::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,
              ASYS_TEXT ("-----( Data Block )-----\n")
              ASYS_TEXT ("type_ = %d\n")
              ASYS_TEXT ("cur_size_ = %u\n")
              ASYS_TEXT ("max_size_ = %u\n")
              ASYS_TEXT ("flags_ = %u\n")
              ASYS_TEXT ("base_ = %u\n")
              ASYS_TEXT ("locking_strategy_ = %u\n")
              ASYS_TEXT ("reference_count_ = %u\n")
              ASYS_TEXT ("---------------------------\n"),
              this->type_,
              this->cur_size_,
              this->max_size_,
              this->flags_,
              this->base_,
              this->locking_strategy_,
              this->reference_count_));
  this->allocator_strategy_->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

void
ACE_Message_Block::dump (void) const
{
  ACE_TRACE ("ACE_Message_Block::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,
              ASYS_TEXT ("-----( Message Block )-----\n")
              ASYS_TEXT ("priority_ = %d\n")
              ASYS_TEXT ("next_ = %u\n")
              ASYS_TEXT ("prev_ = %u\n")
              ASYS_TEXT ("cont_ = %u\n")
              ASYS_TEXT ("rd_ptr_ = %u\n")
              ASYS_TEXT ("wr_ptr_ = %u\n")
              ASYS_TEXT ("---------------------------\n"),
              this->priority_,
              this->next_,
              this->prev_,
              this->cont_,
              this->rd_ptr_,
              this->wr_ptr_));
  this->data_block ()->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

int
ACE_Data_Block::size (size_t length)
{
  ACE_TRACE ("ACE_Data_Block::size");

  if (length <= this->max_size_)
    this->cur_size_ = length;
  else
    {
      // We need to resize!
      char *buf;
      ACE_ALLOCATOR_RETURN (buf,
			    (char *) this->allocator_strategy_->malloc (length),
			    -1);

      ACE_OS::memcpy (buf, this->base_, this->cur_size_);
      if (ACE_BIT_DISABLED (this->flags_, ACE_Message_Block::DONT_DELETE))
	this->allocator_strategy_->free ((void *) this->base_);
      else
	// We now assume ownership.
	ACE_CLR_BITS (this->flags_, ACE_Message_Block::DONT_DELETE);

      this->max_size_ = length;
      this->cur_size_ = length;
      this->base_ = buf;
    }
  return 0;
}

int
ACE_Message_Block::size (size_t length)
{
  ACE_TRACE ("ACE_Message_Block::size");
  char *old_base = this->data_block ()->base ();

  // Resize the underlying <ACE_Data_Block>.
  if (this->data_block ()->size (length) == -1)
    return -1;

  // Reset the read and write pointers if we've changed the underlying
  // memory buffer.
  else if (this->data_block ()->base () != old_base)
    {
      // Compute the old deltas...
      int r_delta = this->rd_ptr_ - old_base;
      int w_delta = this->wr_ptr_ - old_base;

      // ... and use them to initialize the new deltas.
      this->rd_ptr_ = this->data_block ()->base () + r_delta;
      this->wr_ptr_ = this->data_block ()->base () + w_delta;
    }
  return 0;
}

ACE_Data_Block::ACE_Data_Block (void)
  : type_ (ACE_Message_Block::MB_DATA),
    cur_size_ (0),
    max_size_ (0),
    flags_ (ACE_Message_Block::DONT_DELETE),
    base_ (0),
    allocator_strategy_ (0),
    locking_strategy_ (0),
    reference_count_ (1)
{
  ACE_TRACE ("ACE_Data_Block::ACE_Data_Block");
}

ACE_Data_Block::ACE_Data_Block (size_t size,
				ACE_Message_Block::ACE_Message_Type msg_type,
				const char *msg_data,
				ACE_Allocator *allocator_strategy,
				ACE_Lock *locking_strategy,
				ACE_Message_Block::Message_Flags flags)
  : type_ (msg_type),
    cur_size_ (size),
    max_size_ (size),
    flags_ (flags),
    base_ ((char *) msg_data),
    allocator_strategy_ (allocator_strategy),
    locking_strategy_ (locking_strategy),
    reference_count_ (1)
{
  ACE_TRACE ("ACE_Data_Block::ACE_Data_Block");

  // If the user didn't pass one in, let's use the
  // <ACE_Allocator::instance>.
  if (this->allocator_strategy_ == 0)
    ACE_ALLOCATOR (this->allocator_strategy_, ACE_Allocator::instance ());

  if (msg_data == 0)
    ACE_ALLOCATOR (this->base_,
		   (char *) this->allocator_strategy_->malloc (size));
  else
    this->base_ = (char *) msg_data;
}

ACE_Message_Block::ACE_Message_Block (const char *data,
				      size_t size)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (size,    // size
		    MB_DATA, // type
		    0,       // cont
		    data,    // data
		    0,       // allocator
		    0,       // locking strategy
		    ACE_Message_Block::DONT_DELETE, // flags
		    0, // priority
                    ACE_Time_Value::zero, // execution time
                    ACE_Time_Value::zero, // absolute time of deadline
		    0) == -1) // data block
    ACE_ERROR ((LM_ERROR, ASYS_TEXT ("ACE_Message_Block")));
}

ACE_Message_Block::ACE_Message_Block (void)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (0,       // size
		    MB_DATA, // type
		    0,       // cont
		    0,       // data
		    0,       // allocator
		    0,       // locking strategy
		    ACE_Message_Block::DONT_DELETE, // flags
		    0, // priority
                    ACE_Time_Value::zero, // execution time
                    ACE_Time_Value::zero, // absolute time of deadline
		    0) == -1) // data block
    ACE_ERROR ((LM_ERROR, ASYS_TEXT ("ACE_Message_Block")));
}

ACE_Message_Block::ACE_Message_Block (size_t size,
				      ACE_Message_Type msg_type,
				      ACE_Message_Block *msg_cont,
				      const char *msg_data,
				      ACE_Allocator *allocator_strategy,
				      ACE_Lock *locking_strategy,
				      u_long priority,
                                      const ACE_Time_Value & execution_time,
                                      const ACE_Time_Value & deadline_time)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (size,
		    msg_type,
		    msg_cont,
		    msg_data,
		    allocator_strategy,
		    locking_strategy,
		    msg_data ? ACE_Message_Block::DONT_DELETE : 0,
		    priority,
                    execution_time,
                    deadline_time,
		    0) == -1) // data block
    ACE_ERROR ((LM_ERROR, ASYS_TEXT ("ACE_Message_Block")));
}

int
ACE_Message_Block::init (size_t size,
			 ACE_Message_Type msg_type,
			 ACE_Message_Block *msg_cont,
			 const char *msg_data,
			 ACE_Allocator *allocator_strategy,
			 ACE_Lock *locking_strategy,
			 u_long priority,
                         const ACE_Time_Value & execution_time,
                         const ACE_Time_Value & deadline_time)
{
  ACE_TRACE ("ACE_Message_Block::init");

  return this->init_i (size,
		       msg_type,
		       msg_cont,
		       msg_data,
		       allocator_strategy,
		       locking_strategy,
		       msg_data ? ACE_Message_Block::DONT_DELETE : 0,
		       priority,
                       execution_time,
                       deadline_time,
		       0); // data block
}

int
ACE_Message_Block::init (const char *data,
			 size_t size)
{
  ACE_TRACE ("ACE_Message_Block::init");
  // Should we also initialize all the other fields, as well?

  return this->init_i (size,    // size
		       MB_DATA, // type
		       0,       // cont
		       data,    // data
		       0,       // allocator
		       0,       // locking strategy
		       ACE_Message_Block::DONT_DELETE,  // flags
		       0,  // priority
                       ACE_Time_Value::zero, // execution time
                       ACE_Time_Value::zero, // absolute time of deadline
		       0); // data block
}

ACE_Message_Block::ACE_Message_Block (size_t size,
				      ACE_Message_Type msg_type,
				      ACE_Message_Block *msg_cont,
				      const char *msg_data,
				      ACE_Allocator *allocator_strategy,
				      ACE_Lock *locking_strategy,
				      Message_Flags flags,
				      u_long priority,
                                      const ACE_Time_Value & execution_time,
                                      const ACE_Time_Value & deadline_time,
				      ACE_Data_Block *db)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (size,
		    msg_type,
		    msg_cont,
		    msg_data,
		    allocator_strategy,
		    locking_strategy,
		    flags,
		    priority,
                    execution_time,
                    deadline_time,
		    db) == -1)
    ACE_ERROR ((LM_ERROR, ASYS_TEXT ("ACE_Message_Block")));
}

ACE_Message_Block::ACE_Message_Block (ACE_Data_Block *data_block)
{
  ACE_TRACE ("ACE_Message_Block::ACE_Message_Block");

  if (this->init_i (0,         // size
		    MB_NORMAL, // type
		    0,         // cont
		    0,         // data
		    0,         // allocator
		    0,         // locking strategy
		    0,         // flags
		    0,         // priority
                    ACE_Time_Value::zero, // execution time
                    ACE_Time_Value::zero, // absolute time of deadline
		    data_block) == -1) // data block
    ACE_ERROR ((LM_ERROR, ASYS_TEXT ("ACE_Message_Block")));
}

int
ACE_Message_Block::init_i (size_t size,
			   ACE_Message_Type msg_type,
			   ACE_Message_Block *msg_cont,
			   const char *msg_data,
			   ACE_Allocator *allocator_strategy,
			   ACE_Lock *locking_strategy,
			   Message_Flags flags,
			   u_long priority,
                           const ACE_Time_Value & execution_time,
                           const ACE_Time_Value & deadline_time,
			   ACE_Data_Block *db)
{
  ACE_TRACE ("ACE_Message_Block::init_i");

  this->priority_ = priority;
  this->execution_time_ = execution_time;
  this->deadline_time_ = deadline_time;
  this->cont_ = msg_cont;
  this->next_ = 0;
  this->prev_ = 0;
  this->data_block_ = 0;

  if (db == 0)
    // Allocate the <ACE_Data_Block> portion, which is reference
    // counted.
    ACE_NEW_RETURN (db,
		    ACE_Data_Block (size,
				    msg_type,
				    msg_data,
				    allocator_strategy,
				    locking_strategy,
				    flags),
		    -1);

  // Reset the data_block_ pointer.
  this->data_block (db);
  return 0;
}

ACE_Data_Block::~ACE_Data_Block (void)
{
  // Sanity check...
  ACE_ASSERT (this->reference_count_ <= 1);

  // Just to be safe...
  this->reference_count_ = 0;

  if (ACE_BIT_DISABLED (this->flags_, ACE_Message_Block::DONT_DELETE))
    {
      this->allocator_strategy_->free ((void *) this->base_);
      this->base_ = 0;
    }
}

ACE_Data_Block *
ACE_Data_Block::release_i (void)
{
  ACE_TRACE ("ACE_Data_Block::release_i");

  ACE_ASSERT (this->reference_count_ > 0);

  ACE_Data_Block *result = 0;

  // decrement reference count
  this->reference_count_--;

  if (this->reference_count_ == 0)
    // this will cause deletion of this
    result = 0;
  else
    result = this;

  return result;
}

ACE_Data_Block *
ACE_Data_Block::release (ACE_Lock *lock)
{
  ACE_TRACE ("ACE_Data_Block::release");

  ACE_Data_Block *result = 0;
  ACE_Lock *lock_to_be_used = 0;

  // Check if we were passed in a lock
  if (lock != 0)
    {
      // Make sure that the lock passed in and our lock are the same
      if (lock == this->locking_strategy_)
	// In this case no locking is required.
	lock_to_be_used = 0;

      // The lock passed in does not match our lock
      else
	// Lock to be used is our lock
	lock_to_be_used = this->locking_strategy_;
    }
  // This is the case when no lock was passed in
  else
    // Lock to be used is our lock
    lock_to_be_used = this->locking_strategy_;

  // If there's a locking strategy then we need to acquire the lock
  // before decrementing the count.
  if (lock_to_be_used != 0)
    {
      ACE_GUARD_RETURN (ACE_Lock, ace_mon, *lock_to_be_used, 0);

      result = this->release_i ();
    }
  else
    result = this->release_i ();

  // We must delete this outside the scope of the locking_strategy_
  // since otherwise we'd be trying to "release" through a deleted
  // pointer!
  if (result == 0)
    delete this;

  return result;
}

ACE_Message_Block *
ACE_Message_Block::release (void)
{
  ACE_TRACE ("ACE_Message_Block::release");

  ACE_Message_Block *result = 0;
  ACE_Lock *lock = 0;

  // Do we have a valid data block
  if (this->data_block ())
    {
      // Grab the lock that belongs to my data block
      lock = this->data_block ()->locking_strategy ();

      // if we have a lock
      if (lock != 0)
	{
	  // One guard for all
	  ACE_GUARD_RETURN (ACE_Lock, ace_mon, *lock, 0);

	  // Call non-guarded release with <lock>
	  result = this->release_i (lock);
	}
      // This is the case when we have a valid data block but no lock
      else
	// Call non-guarded release with no lock
	result = this->release_i (0);
    }
  else
    // This is the case when we don't even have a valid data block
    result = this->release_i (0);

  return result;
}

ACE_Message_Block *
ACE_Message_Block::release_i (ACE_Lock *lock)
{
  ACE_TRACE ("ACE_Message_Block::release_i");

  // Free up all the continuation messages.
  if (this->cont_)
    {
      ACE_Message_Block *mb = this->cont_;
      ACE_Message_Block *tmp;

      do
        {
          tmp = mb;
          mb = mb->cont_;
          tmp->cont_ = 0;

          tmp->release_i (lock);
        }
      while (mb);

      this->cont_ = 0;
    }

  if (this->data_block ())
    {
      this->data_block ()->release (lock);
      this->data_block_ = 0;
    }

  // We will now commit suicide: this object *must* have come from the heap
  delete this;

  return 0;
}

/* static */ ACE_Message_Block *
ACE_Message_Block::release (ACE_Message_Block *mb)
{
  ACE_TRACE ("ACE_Message_Block::release");

  if (mb != 0)
    return mb->release ();
  else
    return 0;
}

ACE_Message_Block::~ACE_Message_Block (void)
{
  ACE_TRACE ("ACE_Message_Block::~ACE_Message_Block");

  if (this->data_block ())
    this->data_block ()->release ();

  this->prev_ = 0;
  this->next_ = 0;
}

ACE_Data_Block *
ACE_Data_Block::duplicate (void)
{
  ACE_TRACE ("ACE_Data_Block::duplicate");

  // Create a new <ACE_Message_Block>, but share the <base_> pointer
  // data (i.e., don't copy that).
  if (this->locking_strategy_)
    {
      // We need to acquire the lock before incrementing the count.
      ACE_GUARD_RETURN (ACE_Lock, ace_mon, *this->locking_strategy_, 0);
      this->reference_count_++;
    }
  else
    this->reference_count_++;

  return this;
}

ACE_Message_Block *
ACE_Message_Block::duplicate (void) const
{
  ACE_TRACE ("ACE_Message_Block::duplicate");

  ACE_Message_Block *nb;

  // Create a new <ACE_Message_Block> that contains unique copies of
  // the message block fields, but a reference counted duplicate of
  // the <ACE_Data_Block>.
  ACE_NEW_RETURN (nb,
		  ACE_Message_Block (0, // size
				     ACE_Message_Type (0), // type
				     0, // cont
				     0, // data
				     0, // allocator
				     0, // locking strategy
				     0, // flags
				     this->priority_, // priority
                                     this->execution_time_, // execution time
                                     this->deadline_time_, // absolute time to deadline
				     // Get a pointer to a
				     // "duplicated" <ACE_Data_Block>
				     // (will simply increment the
				     // reference count).
				     this->data_block ()->duplicate ()), // data block
		  0);

  // Set the read and write pointers in the new <Message_Block> to the
  // same relative offset as in the existing <Message_Block>.  Note
  // that we are assuming that the data_block()->base() pointer
  // doesn't change when it's duplicated.
  nb->rd_ptr (this->rd_ptr_ - this->data_block ()->base ());
  nb->wr_ptr (this->wr_ptr_ - this->data_block ()->base ());

  // Increment the reference counts of all the continuation messages.
  if (this->cont_)
    {
      nb->cont_ = this->cont_->duplicate ();

      // If things go wrong, release all of our resources and return
      // 0.
      if (nb->cont_ == 0)
	{
	  nb->release ();
	  nb = 0;
	}
    }

  return nb;
}

ACE_Message_Block *
ACE_Message_Block::duplicate (const ACE_Message_Block *mb)
{
  ACE_TRACE ("ACE_Message_Block::duplicate");
  if (mb == 0)
    return 0;
  else
    return mb->duplicate ();
}

ACE_Data_Block *
ACE_Data_Block::clone (ACE_Message_Block::Message_Flags mask) const
{
  ACE_TRACE ("ACE_Data_Block::clone");

  // You always want to clear this one to prevent memory leaks but you
  // might add some others later.
  const ACE_Message_Block::Message_Flags always_clear =
    ACE_Message_Block::DONT_DELETE;

  ACE_Data_Block *nb;

  ACE_NEW_RETURN (nb,
		  ACE_Data_Block (this->max_size_, // size
				  this->type_,     // type
				  0,               // data
				  this->allocator_strategy_, // allocator
				  this->locking_strategy_, // locking strategy
				  this->flags_), // flags
		  0);

  // Copy all of the payload memory into the new object.
  ACE_OS::memcpy (nb->base_, this->base_, this->max_size_);

  // Set new flags minus the mask...
  nb->clr_flags (mask | always_clear);
  return nb;
}

ACE_Message_Block *
ACE_Message_Block::clone (Message_Flags mask) const
{
  ACE_TRACE ("ACE_Message_Block::clone");

  // Get a pointer to a "cloned" <ACE_Data_Block> (will copy the
  // values rather than increment the reference count).

  ACE_Data_Block *db = this->data_block ()->clone (mask);

  if (db == 0)
    return 0;

  ACE_Message_Block *nb =
    new ACE_Message_Block (0, // size
			   ACE_Message_Type (0), // type
			   0, // cont
			   0, // data
			   0, // allocator
			   0, // locking strategy
			   0, // flags
			   this->priority_, // priority
                           this->execution_time_, // execution time
                           this->deadline_time_, // absolute time to deadline
			   db); // data_block
  if (nb == 0)
    {
      db->release ();
      return 0;
    }

  // Set the read and write pointers in the new <Message_Block> to the
  // same relative offset as in the existing <Message_Block>.
  nb->rd_ptr (this->rd_ptr_ - this->data_block ()->base ());
  nb->wr_ptr (this->wr_ptr_ - this->data_block ()->base ());

  // Clone all the continuation messages if necessary.
  if (this->cont () != 0
      && (nb->cont_ = this->cont ()->clone (mask)) == 0)
    {
      nb->release ();
      return 0;
    }
  return nb;
}

// This is private.
ACE_Message_Block &
ACE_Message_Block::operator= (const ACE_Message_Block &)
{
  ACE_TRACE ("ACE_Message_Block::operator=");
  return *this;
}


////////////////////////////////////////
// class ACE_Dynamic_Message_Strategy //
////////////////////////////////////////

ACE_Dynamic_Message_Strategy::ACE_Dynamic_Message_Strategy (u_long static_bit_field_mask,
                                                            u_long static_bit_field_shift,
                                                            u_long pending_threshold,
                                                            u_long dynamic_priority_max,
                                                            u_long dynamic_priority_offset)
  : static_bit_field_mask_ (static_bit_field_mask)
  , static_bit_field_shift_ (static_bit_field_shift)
  , pending_threshold_ (pending_threshold)
  , dynamic_priority_max_ (dynamic_priority_max)
  , dynamic_priority_offset_ (dynamic_priority_offset)
{
}
// ctor
  
ACE_Dynamic_Message_Strategy::~ACE_Dynamic_Message_Strategy ()
{
}
// dtor


int 
ACE_Dynamic_Message_Strategy::drop_message (ACE_Message_Block * &mb) 
{
  ACE_UNUSED_ARG (mb);

  return 0;
}
  // cleanup policy for a message that is later than can be represented,
  // and is being dropped from a dynamic message queue (this is a default
  // method definition that does nothing, which derived classes may override
  // to do things like deleting the message block object, etc).


/////////////////////////////////////////
// class ACE_Deadline_Message_Strategy //
/////////////////////////////////////////

ACE_Deadline_Message_Strategy:: ACE_Deadline_Message_Strategy (u_long static_bit_field_mask,
                                                               u_long static_bit_field_shift,
                                                               u_long pending_threshold,
                                                               u_long dynamic_priority_max,
                                                               u_long dynamic_priority_offset)
  : ACE_Dynamic_Message_Strategy (static_bit_field_mask,
                                  static_bit_field_shift,
                                  pending_threshold,
                                  dynamic_priority_max,
                                  dynamic_priority_offset)
{
}
// ctor
  
ACE_Deadline_Message_Strategy::~ACE_Deadline_Message_Strategy ()
{
}
// dtor

int 
ACE_Deadline_Message_Strategy::update_priority (ACE_Message_Block & mb, 
                                                 const ACE_Time_Value & tv)
{
  // The general formula for this deadline based dynamic priority
  // function is to just subtract the current time and the execution 
  // time from the from the message deadline to get the time to deadline,
  // then subtract the time to deadline from a constant C that depends on
  // whether the time to deadline is negative (C is zero) or non-negative 
  // (C is the maximum allowed priority).  But, to save operations for
  // performance we use an optimized (albeit confusing: our apologies ;-) 
  // formula for the dynamic priority calculation.
 
  // first, compute the *negative* (additive inverse) of the time to deadline
  ACE_Time_Value priority (tv);
  priority -= mb.msg_deadline_time ();

  if (priority >= ACE_Time_Value::zero)
  {
    // if negative time to deadline is positive then the message is late:
    // need to make sure the priority stays below the threshold
    // between pending and late priority values
    ACE_Time_Value 
      max_late (0, dynamic_priority_offset_ - 1);

    if (priority > max_late)
    {
      // if the message is later than can be represented, its priority is 0.
      mb.msg_priority (0);
      return 0;
    }
  }
  else
  {
    // if negative time to deadline is negative then the message is pending:
    // so, we need to shift priority upward by adding the maximum priority 
    // value and then make sure the value stays above the threshold between
    // pending and late message priorities.
    priority += 
      ACE_Time_Value (0, dynamic_priority_max_);

    ACE_Time_Value 
      min_pending (0, dynamic_priority_offset_);

    if (priority < min_pending)
    {
      priority = min_pending;
    }
  }
 
  // use (fast) bitwise operators to isolate and replace
  // the dynamic portion of the message's priority
  mb.msg_priority((mb.msg_priority() & static_bit_field_mask_) | 
                  ((priority.usec () + ACE_ONE_SECOND_IN_USECS * priority.sec ()) <<
                   static_bit_field_shift_));

  return 0;
}
  // priority evaluation function based on time to deadline

int
ACE_Deadline_Message_Strategy::is_beyond_late (const ACE_Message_Block & mb, 
                                               const ACE_Time_Value & tv)
{
  // first, compute the *negative* time to deadline
  ACE_Time_Value priority (tv);
  priority -= mb.msg_deadline_time ();

  // construct a time value with the maximum late value that
  // can be represented in the dynamic priority range
  ACE_Time_Value max_late (0, dynamic_priority_offset_ - 1);

  // if negative time to deadline is greater than the maximum value
  // that can be represented, it is identified as being beyond late
  return (priority > max_late) ? 1 : 0;
}
  // returns true if the message is later than can can be represented  

/////////////////////////////////////////////////
// class ACE_Deadline_Cleanup_Message_Strategy //
/////////////////////////////////////////////////

ACE_Deadline_Cleanup_Message_Strategy:: ACE_Deadline_Cleanup_Message_Strategy (
   u_long static_bit_field_mask,
   u_long static_bit_field_shift,
   u_long pending_threshold,
   u_long dynamic_priority_max,
   u_long dynamic_priority_offset)

  : ACE_Deadline_Message_Strategy (static_bit_field_mask,
                                   static_bit_field_shift,
                                   pending_threshold,
                                   dynamic_priority_max,
                                   dynamic_priority_offset)
{
}
// ctor
  
ACE_Deadline_Cleanup_Message_Strategy::~ACE_Deadline_Cleanup_Message_Strategy ()
{
}
// dtor

int 
ACE_Deadline_Cleanup_Message_Strategy::drop_message (ACE_Message_Block * &mb) 
{
  // free the memory
  delete mb;

  // zero passed pointer to let caller know it's gone
  mb = 0;

  return 0;
}
  // deletion cleanup policy for a message that is later than can be 
  // represented, and is being dropped from a dynamic message queue

///////////////////////////////////////
// class ACE_Laxity_Message_Strategy //
///////////////////////////////////////

ACE_Laxity_Message_Strategy::ACE_Laxity_Message_Strategy (u_long static_bit_field_mask,
                                                          u_long static_bit_field_shift,
                                                          u_long pending_threshold,
                                                          u_long dynamic_priority_max,
                                                          u_long dynamic_priority_offset)
  : ACE_Dynamic_Message_Strategy (static_bit_field_mask,
                                  static_bit_field_shift,
                                  pending_threshold,
                                  dynamic_priority_max,
                                  dynamic_priority_offset)
{
}
// ctor
  
ACE_Laxity_Message_Strategy::~ACE_Laxity_Message_Strategy ()
{
}
// dtor


int 
ACE_Laxity_Message_Strategy::update_priority (ACE_Message_Block & mb, 
                                              const ACE_Time_Value & tv)
{
  // The general formula for this laxity based dynamic priority
  // function is to just subtract the current time and the execution 
  // time from the from the message deadline to get the laxity,
  // then subtract the laxity from a constant C that depends on whether
  // the laxity is negative (C is zero) or non-negative (C is the maximum
  // allowed priority).  But, to save operations for performance we use
  // an optimized (albeit confusing: our apologies ;-) formula
  // for the dynamic priority calculation.
 
  // first, compute the *negative* laxity
  ACE_Time_Value priority (tv);
  priority += mb.msg_execution_time ();
  priority -= mb.msg_deadline_time ();

  if (priority >= ACE_Time_Value::zero)
  {
    // if negative laxity is positive then the message is late:
    // need to make sure the priority stays below the threshold
    // between pending and late priority values
    ACE_Time_Value 
      max_late (0, dynamic_priority_offset_ - 1);

    if (priority > max_late)
    {
      // if the message is later than can be represented, its priority is 0.
      mb.msg_priority (0);
      return 0;
    }
  }
  else
  {
    // if negative laxity is negative then the message is pending: so, we
    // need to shift priority upward by adding the maximum priority value
    // and then make sure the value stays above the threshold between
    // pending and late message priorities.
    priority += 
      ACE_Time_Value (0, dynamic_priority_max_);

    ACE_Time_Value 
      min_pending (0, dynamic_priority_offset_);

    if (priority < min_pending)
    {
      priority = min_pending;
    }
  }

  // use (fast) bitwise operators to isolate and replace
  // the dynamic portion of the message's priority
  mb.msg_priority((mb.msg_priority() & static_bit_field_mask_) | 
                  ((priority.usec () + ACE_ONE_SECOND_IN_USECS * priority.sec ()) << 
                   static_bit_field_shift_));

  return 0;
}
  // priority evaluation function based on laxity

int
ACE_Laxity_Message_Strategy::is_beyond_late (const ACE_Message_Block & mb, 
                                             const ACE_Time_Value & tv)
{
  // first, compute the *negative* laxity
  ACE_Time_Value priority (tv);
  priority += mb.msg_execution_time ();
  priority -= mb.msg_deadline_time ();

  // construct a time value with the maximum late value that
  // can be represented in the dynamic priority range
  ACE_Time_Value max_late (0, dynamic_priority_offset_ - 1);

  // if negative laxity is greater than the maximum value that
  // can be represented, it is identified as being beyond late
  return (priority > max_late) ? 1 : 0;
}
  // returns true if the message is later than can can be represented  

/////////////////////////////////////////////////
// class ACE_Laxity_Cleanup_Message_Strategy //
/////////////////////////////////////////////////

ACE_Laxity_Cleanup_Message_Strategy:: ACE_Laxity_Cleanup_Message_Strategy (
   u_long static_bit_field_mask,
   u_long static_bit_field_shift,
   u_long pending_threshold,
   u_long dynamic_priority_max,
   u_long dynamic_priority_offset)

  : ACE_Laxity_Message_Strategy (static_bit_field_mask,
                                 static_bit_field_shift,
                                 pending_threshold,
                                 dynamic_priority_max,
                                 dynamic_priority_offset)
{
}
// ctor
  
ACE_Laxity_Cleanup_Message_Strategy::~ACE_Laxity_Cleanup_Message_Strategy ()
{
}
// dtor

int 
ACE_Laxity_Cleanup_Message_Strategy::drop_message (ACE_Message_Block * &mb) 
{
  // free the memory
  delete mb;

  // zero passed pointer to let caller know it's gone
  mb = 0;

  return 0;
}
  // deletion cleanup policy for a message that is later than can be 
  // represented, and is being dropped from a dynamic message queue





#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
// These specializations aren't needed for the ACE library because
// Service_Config.cpp has them:
//
// template class ACE_Malloc <ACE_LOCAL_MEMORY_POOL, ACE_Null_Mutex>;
// template class ACE_Allocator_Adapter <ACE_Malloc <ACE_LOCAL_MEMORY_POOL, ACE_Null_Mutex> >;
template class ACE_Guard<ACE_Lock>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
// These specializations aren't needed for the ACE library because
// Service_Config.cpp has them:
//
// #pragma instantiate ACE_Malloc <ACE_LOCAL_MEMORY_POOL, ACE_Null_Mutex>
// #pragma instantiate ACE_Allocator_Adapter <ACE_Malloc <ACE_LOCAL_MEMORY_POOL, ACE_Null_Mutex> >
#pragma instantiate ACE_Guard<ACE_Lock>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


