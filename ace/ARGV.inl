/* -*- C++ -*- */
// $Id$

#include "ace/Global_Macros.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_Memory.h"

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template < typename CHAR_TYPE > void
ACE_TARGV<CHAR_TYPE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_LIB_TEXT ("argc_ = %d"), this->argc_));

  ACE_TARGV *this_obj = const_cast<ACE_TARGV *> (this);

  for (int i = 0; i < this->argc_; i++)
    ACE_DEBUG ((LM_DEBUG,
                ACE_LIB_TEXT ("\nargv_[%i] = %s"),
                i,
                this_obj->argv ()[i]));

  ACE_DEBUG ((LM_DEBUG,  ACE_LIB_TEXT ("\nbuf = %s\n"), this->buf_));
  ACE_DEBUG ((LM_DEBUG,  ACE_LIB_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// Creates this->argv_ out of this->buf_.  New memory is allocated for
// each element of the array.  This is used by the array-to-string
// style constructor and for creating this->argv_ when in iterative
// mode.

template < typename CHAR_TYPE > int
ACE_TARGV<CHAR_TYPE>::string_to_argv (void)
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::string_to_argv");

  return ACE_OS::string_to_argv (this->buf_,
                                 this->argc_,
                                 this->argv_,
                                 this->substitute_env_args_);
}

template < typename CHAR_TYPE > int
ACE_TARGV<CHAR_TYPE>::argv_to_string (CHAR_TYPE **argv, CHAR_TYPE *&buf)
{
  return ACE_OS::argv_to_string (argv, buf);
}

template < typename CHAR_TYPE >
ACE_TARGV<CHAR_TYPE>::ACE_TARGV (const CHAR_TYPE buf[],
		    int substitute_env_args)
  : substitute_env_args_ (substitute_env_args),
    state_ (TO_PTR_ARRAY),
    argc_ (0),
    argv_ (0),
    buf_ (0),
    length_ (0),
    queue_ ()
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::ACE_TARGV CHAR_TYPE[] to CHAR_TYPE *[]");

  if (buf == 0 || buf[0] == 0)
    return;

  // Make an internal copy of the string.
  ACE_NEW (this->buf_,
           CHAR_TYPE[ACE_OS::strlen (buf) + 1]);
  ACE_OS::strcpy (this->buf_, buf);

  // Create this->argv_.
  if (this->string_to_argv () == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_LIB_TEXT ("%p\n"),
                ACE_LIB_TEXT ("string_to_argv")));
}

template < typename CHAR_TYPE >
ACE_TARGV<CHAR_TYPE>::ACE_TARGV (CHAR_TYPE *argv[],
		    int substitute_env_args)
  : substitute_env_args_ (substitute_env_args),
    state_ (TO_STRING),
    argc_ (0),
    argv_ (0),
    buf_ (0),
    length_ (0),
    queue_ ()
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::ACE_TARGV CHAR_TYPE*[] to CHAR_TYPE[]");

  if (argv == 0 || argv[0] == 0)
    return;

  this->argc_ = ACE_OS::argv_to_string (argv, this->buf_, substitute_env_args);
}

template < typename CHAR_TYPE >
ACE_TARGV<CHAR_TYPE>::ACE_TARGV (CHAR_TYPE *first_argv[],
                    CHAR_TYPE *second_argv[],
                    int substitute_env_args)
  : substitute_env_args_ (substitute_env_args),
    state_ (TO_STRING),
    argc_ (0),
    argv_ (0),
    buf_ (0),
    length_ (0),
    queue_ ()
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::ACE_TARGV CHAR_TYPE*[] + CHAR_TYPE *[] to CHAR_TYPE[]");

  int first_argc;
  int second_argc;

  CHAR_TYPE *first_buf;
  CHAR_TYPE *second_buf;

  // convert the first argv to a string
  first_argc = this->argv_to_string (first_argv, first_buf);

  // convert the second argv to a string
  second_argc = this->argv_to_string (second_argv, second_buf);

  // Add the number of arguments in both the argvs.
  this->argc_ = first_argc + second_argc;

  size_t buf_len =
    ACE_OS::strlen (first_buf) + ACE_OS::strlen (second_buf) + 1;

  // Allocate memory to the lenght of the combined argv string.
  ACE_NEW (this->buf_,
           CHAR_TYPE[buf_len + 1]);

  // copy the first argv string to the buffer
  ACE_OS::strcpy (this->buf_, first_buf);

  // concatenate the second argv string to the buffer
  ACE_OS::strcat (this->buf_, second_buf);

  //   Delete the first and second buffers

  delete [] first_buf;

  delete [] second_buf;
}

template < typename CHAR_TYPE >
ACE_TARGV<CHAR_TYPE>::ACE_TARGV (int substitute_env_args)
  : substitute_env_args_ (substitute_env_args),
    state_ (ITERATIVE),
    argc_ (0),
    argv_ (0),
    buf_ (0),
    length_ (0),
    queue_ ()
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::ACE_TARGV Iterative");

  // Nothing to do yet -- the user puts in arguments via add ()
}

template < typename CHAR_TYPE > int
ACE_TARGV<CHAR_TYPE>::add (const CHAR_TYPE *next_arg)
{
  // Only allow this to work in the "iterative" verion -- the
  // ACE_TARGVs created with the one argument constructor.
  if (this->state_ != ITERATIVE)
    {
      errno = EINVAL;
      return -1;
    }

  // Put the new argument at the end of the queue.
  if (this->queue_.enqueue_tail (const_cast <CHAR_TYPE *> (next_arg)) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_LIB_TEXT ("Can't add more to ARGV queue")),
                      -1);

  this->length_ += ACE_OS::strlen (next_arg);

  this->argc_++;

  // Wipe argv_ and buf_ away so that they will be recreated if the
  // user calls argv () or buf ().
  if (this->argv_ != 0)
    {
      for (int i = 0; this->argv_[i] != 0; i++)
	ACE_OS::free ((void *) this->argv_[i]);

      delete [] this->argv_;
      this->argv_ = 0;
    }

  delete [] this->buf_;
  this->buf_ = 0;

  return 0;
}

template < typename CHAR_TYPE > int
ACE_TARGV<CHAR_TYPE>::add (CHAR_TYPE *argv[])
{
  for (int i = 0; argv[i] != 0; i++)
    if (this->add (argv[i]) == -1)
      return -1;

  return 0;
}

// Free up argv_ and buf_
template < typename CHAR_TYPE >
ACE_TARGV<CHAR_TYPE>::~ACE_TARGV (void)
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::~ACE_TARGV");

  if (this->argv_ != 0)
    for (int i = 0; this->argv_[i] != 0; i++)
      ACE_OS::free ((void *) this->argv_[i]);

  delete [] this->argv_;
  delete [] this->buf_;
}

// Create buf_ out of the queue_.  This is only used in the
// "iterative" mode.

template < typename CHAR_TYPE > int
ACE_TARGV<CHAR_TYPE>::create_buf_from_queue (void)
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::create_buf_from_queue");

  // If the are no arguments, don't do anything
  if (this->argc_ <= 0)
    return -1;

  delete [] this->buf_;

  ACE_NEW_RETURN (this->buf_,
                  CHAR_TYPE[this->length_ + this->argc_],
                  -1);

  // Get an iterator over the queue
  ACE_Unbounded_Queue_Iterator<CHAR_TYPE *> iter (this->queue_);

  CHAR_TYPE **arg;
  CHAR_TYPE *ptr = this->buf_;
  size_t len;
  int more = 0;

  while (!iter.done ())
    {
      // Get next argument from the queue.
      iter.next (arg);

      more = iter.advance ();

      len = ACE_OS::strlen (*arg);

      // Copy the argument into buf_
      ACE_OS::memcpy ((void *) ptr,
                      (const void *) (*arg),
                      len * sizeof (CHAR_TYPE));
      // Move the pointer down.
      ptr += len;

      // Put in an argument separating space.
      if (more != 0)
	*ptr++ = ' ';
    }

  // Put in the NUL terminator
  *ptr = '\0';

  return 0;
}

// Return the number of args
template < typename CHAR_TYPE > int
ACE_TARGV<CHAR_TYPE>::argc (void) const
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::argc");
  return this->argc_;
}

// Return the state of this ACE_TARGV
template < typename CHAR_TYPE > int
ACE_TARGV<CHAR_TYPE>::state(void) const
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::state");
  return this->state_;
}

// Return the arguments in a space-separated string
template < typename CHAR_TYPE > const CHAR_TYPE *
ACE_TARGV<CHAR_TYPE>::buf (void)
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::buf");

  if (this->buf_ == 0 && this->state_ == ITERATIVE)
    this->create_buf_from_queue ();

  return (const CHAR_TYPE *) this->buf_;
}

// Return the arguments in an entry-per-argument array

template < typename CHAR_TYPE > CHAR_TYPE **
ACE_TARGV<CHAR_TYPE>::argv (void)
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::argv");

  // Try to create the argv_ if it isn't there
  if (this->argv_ == 0)
    {
      if (this->state_ == ITERATIVE && this->buf_ == 0)
        this->create_buf_from_queue ();

      // Convert buf_ to argv_
      if (this->string_to_argv () == -1)
        return (CHAR_TYPE **) 0;
    }

  return (CHAR_TYPE **) this->argv_;
}

// Subscript operator.

template < typename CHAR_TYPE > const CHAR_TYPE *
ACE_TARGV<CHAR_TYPE>::operator[] (size_t i)
{
  ACE_TRACE ("ACE_TARGV<CHAR_TYPE>::operator[]");

  // Don't go out of bounds.
  if (i >= static_cast<size_t> (this->argc_))
    return 0;

  return (const CHAR_TYPE *) this->argv ()[i];
}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL
