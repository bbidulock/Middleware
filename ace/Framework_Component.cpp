// Framework_Component.cpp
// $Id$

#include "ace/Framework_Component.h"
#include "ace/Object_Manager.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/Framework_Component.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, Framework_Component, "$Id$")

#undef ACE_TRACE
#define ACE_TRACE(X) ACE_TRACE_IMPL(X)

ACE_Framework_Component::~ACE_Framework_Component (void)
{
  ACE_TRACE ("ACE_Framework_Component::~ACE_Framework_Component");
  ACE::strdelete (ACE_const_cast (ACE_TCHAR*, this->dll_name_));
  ACE::strdelete (ACE_const_cast (ACE_TCHAR*, this->name_));
}

/***************************************************************/

ACE_ALLOC_HOOK_DEFINE(ACE_Framework_Repository)

sig_atomic_t ACE_Framework_Repository::shutting_down_ = 0;

// Pointer to the Singleton instance.
ACE_Framework_Repository *ACE_Framework_Repository::repository_ = 0;

ACE_Framework_Repository::~ACE_Framework_Repository (void)
{
  ACE_TRACE ("ACE_Framework_Repository::~ACE_Framework_Repository");
  this->close ();
}

int
ACE_Framework_Repository::open (int size)
{
  ACE_TRACE ("ACE_Framework_Repository::open");

  ACE_Framework_Component **temp;

  ACE_NEW_RETURN (temp,
                  ACE_Framework_Component *[size],
                  -1);

  this->component_vector_ = temp;
  this->total_size_ = size;
  return 0;
}

int
ACE_Framework_Repository::close (void)
{
  ACE_TRACE ("ACE_Framework_Repository::close");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  this->shutting_down_ = 1;

  if (this->component_vector_ != 0)
    {
      // Delete components in reverse order.
      for (int i = this->current_size_ - 1; i >= 0; i--)
        {
          if (this->component_vector_[i])
            {
              ACE_Framework_Component *s = ACE_const_cast (ACE_Framework_Component *,
                                                           this->component_vector_[i]);

              this->component_vector_[i] = 0;
              if (s)
                s->close_singleton ();
            }
        }

      delete [] this->component_vector_;
      this->component_vector_ = 0;
      this->current_size_ = 0;
    }

  //ACE_DEBUG ((LM_DEBUG, ACE_LIB_TEXT ("AFR::close: end\n")));
  return 0;
}

ACE_Framework_Repository *
ACE_Framework_Repository::instance (int size)
{
  ACE_TRACE ("ACE_Framework_Repository::instance");

  if (ACE_Framework_Repository::repository_ == 0)
    {
      // Perform Double-Checked Locking Optimization.
      ACE_MT (ACE_GUARD_RETURN (ACE_Recursive_Thread_Mutex, ace_mon,
                                *ACE_Static_Object_Lock::instance (), 0));
      if (ACE_Framework_Repository::repository_ == 0)
        {
          if (ACE_Object_Manager::starting_up () ||
              !ACE_Object_Manager::shutting_down ())
            {
              ACE_NEW_RETURN (ACE_Framework_Repository::repository_,
                              ACE_Framework_Repository (size),
                              0);
            }
        }
    }

  return ACE_Framework_Repository::repository_;
}

void
ACE_Framework_Repository::close_singleton (void)
{
  ACE_TRACE ("ACE_Framework_Repository::close_singleton");

  ACE_MT (ACE_GUARD (ACE_Recursive_Thread_Mutex, ace_mon,
                     *ACE_Static_Object_Lock::instance ()));

  delete ACE_Framework_Repository::repository_;
  ACE_Framework_Repository::repository_ = 0;
}

int
ACE_Framework_Repository::register_component (ACE_Framework_Component *fc)
{
  ACE_TRACE ("ACE_Framework_Repository::register_component");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));
  int i;

  // Check to see if it's already registered
  for (i = 0; i < this->current_size_; i++)
    if (fc->this_ == this->component_vector_[i]->this_)
      {
        // Delete it since it's already here and component adapter was newed.
        delete fc;
        return 0;
      }

  if (i < this->total_size_)
    {
      this->component_vector_[i] = fc;
      this->current_size_++;
      return 0;
    }

  return -1;
}

int
ACE_Framework_Repository::remove_component (const ACE_TCHAR *name)
{
  ACE_TRACE ("ACE_Framework_Repository::remove_component");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));
  int i;

  for (i = 0; i < this->current_size_; i++)
    if (this->component_vector_[i] &&
        ACE_OS_String::strcmp (this->component_vector_[i]->name_, name) == 0)
      {
        this->component_vector_[i]->close_singleton ();
        delete this->component_vector_[i];
        this->component_vector_[i] = 0;
        return 0;
      }

  return -1;
}

int
ACE_Framework_Repository::remove_dll_components (const ACE_TCHAR *dll_name)
{
  ACE_TRACE ("ACE_Framework_Repository::remove_dll_component");

  if (this->shutting_down_)
    return this->remove_dll_components_i (dll_name);
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1));

  return this->remove_dll_components_i (dll_name);
}

int
ACE_Framework_Repository::remove_dll_components_i (const ACE_TCHAR *dll_name)
{
  ACE_TRACE ("ACE_Framework_Repository::remove_dll_components_i");

  int i;
  int retval = -1;

  //ACE_DEBUG ((LM_DEBUG, ACE_LIB_TEXT ("AFR::remove_dll_components ('%s')\n"), dll_name));

  for (i = 0; i < this->current_size_; i++)
    if (this->component_vector_[i] &&
        ACE_OS_String::strcmp (this->component_vector_[i]->dll_name_, dll_name) == 0)
      {
        //ACE_DEBUG ((LM_DEBUG, ACE_LIB_TEXT ("AFR::remove_dll_c...()\n")));
        this->component_vector_[i]->close_singleton ();
        this->component_vector_[i] = 0;
        ++retval;
      }

  return retval == -1 ? -1 : 0;
}

void
ACE_Framework_Repository::dump (void) const
{
  ACE_TRACE ("ACE_Framework_Repository::dump");
}

ACE_Framework_Repository::ACE_Framework_Repository (int size)
  : current_size_ (0)
{
  ACE_TRACE ("ACE_Framework_Repository::ACE_Framework_Repository");

  if (this->open (size) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_LIB_TEXT ("%p\n"),
                ACE_LIB_TEXT ("ACE_Framework_Repository")));
}
