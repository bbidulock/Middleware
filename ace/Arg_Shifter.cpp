// $Id$

#define ACE_BUILD_DLL

// #include "ace/OS.h"
#include "ace/Arg_Shifter.h"

ACE_RCSID(ace, Arg_Shifter, "$Id$")

ACE_Arg_Shifter::ACE_Arg_Shifter (int& argc,
                                  char** argv,
                                  char** temp)
  : argc_ (argc),
    total_size_ (argc),
    temp_ (temp),
    argv_ (argv),
    current_index_ (0),
    back_ (argc - 1),
    front_ (0)
{
  // If not provided with one, allocate a temporary array.
  if (this->temp_ == 0)
    ACE_NEW (this->temp_,
             char*[this->total_size_]);

  if (this->temp_ != 0)
    {
      // Fill the temporary array.
      this->argc_ = 0;
      for (int i = 0; i < this->total_size_; i++)
	{
	  this->temp_[i] = this->argv_[i];
	  this->argv_[i] = 0;
	}
    }
  else
    {
      // Allocation failed, prohibit iteration.
      this->current_index_ = this->argc_;
      this->front_ = this->argc_;
    }
}

ACE_Arg_Shifter::~ACE_Arg_Shifter (void)
{
  // Delete the temporary vector.
  delete [] temp_;
}

char*
ACE_Arg_Shifter::get_current (void) const
{
  char* retval = 0;

  if (this->is_anything_left ())
    retval =  this->temp_[current_index_];

  return retval;
}

char*
ACE_Arg_Shifter::get_the_parameter (const char* flag)
{
  // the return 0's abound because this method
  // would otherwise be a deep if { } else { }

  // check to see if any arguments still exist
  if (!this->is_anything_left())
    return 0;

  // check to see if the flag is the argument
  int offset = this->cur_arg_strncasecmp (flag);
  if (offset == -1)
    return 0;

  if (offset == 0)
    {
      this->consume_arg ();

      if (!this->is_parameter_next())
	{
	  return 0;
	}
    }
  // the paramter is in the middle somewhere...
  return this->temp_[current_index_] + offset;
}

int
ACE_Arg_Shifter::cur_arg_strncasecmp (const char* flag)
{
  // Check for a current argument
  if (this->is_anything_left())
    {
      unsigned int flag_length = ACE_OS::strlen(flag);

      // Check for presence of the flag
      if (ACE_OS::strncasecmp(this->temp_[current_index_],
			      flag,
			      flag_length) == 0)
	{
	  if (ACE_OS::strlen(temp_[current_index_]) ==
	      flag_length)
	    {
	      // match and lengths are equal
	      return 0;
	    }
	  else
	    {
	      // matches, with more info to boot!
	      return ACE_OS::strspn
		(this->temp_[current_index_] + flag_length,
		 " ") + flag_length;
	    }
	}
    }
  // failure
  return -1;
}

int
ACE_Arg_Shifter::consume_arg (int number)
{
  int retval = 0;

  // Stick knowns at the end of the vector (consumed).
  if (this->is_anything_left() >= number)
    {
      for (int i = 0, j = this->back_ - (number - 1);
	   i < number;
	   ++i, ++j, ++this->current_index_)
	this->argv_[j] = this->temp_[this->current_index_];

      this->back_ -= number;
      retval = 1;
    }

  return retval;
}

int
ACE_Arg_Shifter::ignore_arg (int number)
{
  int retval = 0;

  // Keep unknowns at the head of the vector.
  if (this->is_anything_left () >= number)
    {
      for (int i = 0;
	   i < number;
	   i++, this->current_index_++, this->front_++)
	this->argv_[this->front_] = this->temp_[this->current_index_];

      retval = 1;
      this->argc_ += number;
    }

  return retval;
}

int
ACE_Arg_Shifter::is_anything_left (void) const
{
  return this->total_size_ - this->current_index_;
}

int
ACE_Arg_Shifter::is_option_next (void) const
{
  return this->is_anything_left () &&
    this->temp_[this->current_index_][0] == '-';
}

int
ACE_Arg_Shifter::is_parameter_next (void) const
{
  return this->is_anything_left ()
    && this->temp_[this->current_index_][0] != '-';
}

int
ACE_Arg_Shifter::num_ignored_args (void) const
{
  return this->front_;
}
