// Singleton.cpp
// $Id$

#if !defined (ACE_SINGLETON_C)
#define ACE_SINGLETON_C

#define ACE_BUILD_DLL
#include "ace/Singleton.h"
#include "ace/Synch_T.h"
#include "ace/Object_Manager.h"

#if !defined (__ACE_INLINE__)
#include "ace/Singleton.i"
#endif /* __ACE_INLINE__ */

template <class TYPE, class LOCK> void
ACE_Singleton<TYPE, LOCK>::dump (void)
{
  ACE_TRACE ("ACE_Singleton<TYPE, LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG, "instance_ = %x", 
	      ACE_Singleton<TYPE, LOCK>::instance_i ()));
  ACE_Singleton<TYPE, LOCK>::singleton_lock_i ().dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class LOCK> ACE_Singleton<TYPE, LOCK> *&
ACE_Singleton<TYPE, LOCK>::instance_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++ and it's (mis-)handling of templates and statics...
  static ACE_Singleton<TYPE, LOCK> *singleton_ = 0;

  return singleton_;
#else
  return ACE_Singleton<TYPE, LOCK>::singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class LOCK> LOCK &
ACE_Singleton<TYPE, LOCK>::singleton_lock_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Lock the creation of the singleton.  This works around a
  // "feature" of G++... ;-)
  static LOCK ace_singleton_lock_;

  return ace_singleton_lock_;
#else
  return ACE_Singleton<TYPE, LOCK>::ace_singleton_lock_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class LOCK> TYPE *
ACE_Singleton<TYPE, LOCK>::instance (void)
{
  ACE_TRACE ("ACE_Singleton<TYPE, LOCK>::instance");

  ACE_Singleton<TYPE, LOCK> *&singleton = 
    ACE_Singleton<TYPE, LOCK>::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
      ACE_GUARD_RETURN (LOCK, ace_mon, (ACE_Singleton<TYPE, LOCK>::singleton_lock_i ()), 0);

      if (singleton == 0)
        {
	  ACE_NEW_RETURN (singleton, (ACE_Singleton<TYPE, LOCK>), 0);

          // Register for destruction with ACE_Object_Manager.
          ACE_Object_Manager::at_exit (singleton);
        }
    }

  return singleton->instance_;
}

template <class TYPE, class LOCK> TYPE *
ACE_Singleton<TYPE, LOCK>::instance (TYPE *new_instance)
{
  ACE_TRACE ("ACE_Singleton::set_instance");

  ACE_GUARD_RETURN (LOCK, ace_mon, (ACE_Singleton<TYPE, LOCK>::singleton_lock_i ()), 0);

  ACE_Singleton<TYPE, LOCK> *&singleton = ACE_Singleton<TYPE, LOCK>::instance_i ();
  TYPE *old_instance = singleton->instance_;
  singleton->instance_ = new_instance;

  return old_instance;
}

template <class TYPE, class LOCK> void
ACE_Singleton<TYPE, LOCK>::cleanup (void *)
{
  if (this->instance_ != 0)
    {
      delete this->instance_;
      this->instance_ = 0;

      delete this;
    }
}

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
// Pointer to the Singleton instance.
template <class TYPE, class LOCK> ACE_Singleton<TYPE, LOCK> *
ACE_Singleton<TYPE, LOCK>::singleton_ = 0;

// Lock the creation of the singleton.  
template <class TYPE, class LOCK> LOCK
ACE_Singleton<TYPE, LOCK>::ace_singleton_lock_;
#endif /* !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES) */

template <class TYPE, class LOCK> void
ACE_TSS_Singleton<TYPE, LOCK>::dump (void)
{
  ACE_TRACE ("ACE_TSS_Singleton<TYPE, LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG, "instance_ = %x", singleton_->instance_));
  ace_singleton_lock_.dump();                                                  
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class LOCK> TYPE *
ACE_TSS_Singleton<TYPE, LOCK>::instance (void)
{
  ACE_TRACE ("ACE_TSS_Singleton<TYPE, LOCK>::instance");

#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++...
  static ACE_TSS_Singleton<TYPE, LOCK> *singleton_ = 0;

  // Lock the creation of the singleton.  This works around a
  // "feature" of G++... ;-)
  static LOCK ace_singleton_lock_;

  // Perform the Double-Check pattern...                                        
  if (singleton_ == 0)
    {
      ACE_GUARD_RETURN (LOCK, ace_mon, ace_singleton_lock_, 0);

      if (singleton_ == 0)
	{
          ACE_NEW_RETURN (singleton_, (ACE_TSS_Singleton<TYPE, LOCK>), 0);

#if 0  /* ACE_Object_Manager::at_thread_exit () is not implemented yet. */
          // Register for destruction with ACE_Object_Manager.
          ACE_Object_Manager::at_thread_exit (instance_);
#endif /* 0 */
	}
    }

#else

  // Perform the Double-Check pattern...
  if (singleton_ == 0)
    {
      ACE_GUARD_RETURN (LOCK, ace_mon, (ACE_TSS_Singleton<TYPE, LOCK>::ace_singleton_lock_), 0);

      if (singleton_ == 0)
	{
          ACE_NEW_RETURN (singleton_, (ACE_TSS_Singleton<TYPE, LOCK>), 0);

#if 0  /* ACE_Object_Manager::at_thread_exit () is not implemented yet. */
          // Register for destruction with ACE_Object_Manager.
          ACE_Object_Manager::at_thread_exit (instance_);
#endif /* 0 */
	}
    }

#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */

  return ACE_TSS_GET (singleton_->instance_, TYPE);
}

template <class TYPE, class LOCK> void
ACE_TSS_Singleton<TYPE, LOCK>::cleanup (void *)
{
  ACE_TRACE ("ACE_TSS_Singleton::cleanup");

  if (this->instance_ != 0)
    {
      delete this->instance_;
      this->instance_ = 0;

      delete this;
    }
}

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
// Pointer to the Singleton instance.
template <class TYPE, class LOCK> ACE_TSS_Singleton <TYPE, LOCK> *
ACE_TSS_Singleton<TYPE, LOCK>::singleton_ = 0;

// Lock the creation of the singleton.
template <class TYPE, class LOCK> LOCK
ACE_TSS_Singleton<TYPE, LOCK>::ace_singleton_lock_;                
#endif /* !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES) */

#endif /* ACE_SINGLETON_C */
