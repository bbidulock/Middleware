// -*- C++ -*-
//
// $Id$

#ifndef TAO_SINGLETON_CPP
#define TAO_SINGLETON_CPP

#include "tao/TAO_Singleton.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Synch_T.h"
#include "ace/Object_Manager.h"
#include "ace/Log_Msg.h"
#include "tao/TAO_Singleton_Manager.h"

#if !defined (__ACE_INLINE__)
#include "tao/TAO_Singleton.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (tao, TAO_Singleton, "$Id$")

template <class TYPE, class ACE_LOCK> void
TAO_Singleton<TYPE, ACE_LOCK>::dump (void)
{
  ACE_TRACE ("TAO_Singleton<TYPE, ACE_LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("instance_ = %x"),
              TAO_Singleton<TYPE, ACE_LOCK>::instance_i ()));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TAO_Singleton<TYPE, ACE_LOCK> *&
TAO_Singleton<TYPE, ACE_LOCK>::instance_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++ and it's (mis-)handling of templates and statics...
  static TAO_Singleton<TYPE, ACE_LOCK> *singleton_ = 0;

  return singleton_;
#else
  return TAO_Singleton<TYPE, ACE_LOCK>::singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TYPE *
TAO_Singleton<TYPE, ACE_LOCK>::instance (void)
{
  ACE_TRACE ("TAO_Singleton<TYPE, ACE_LOCK>::instance");

  TAO_Singleton<TYPE, ACE_LOCK> *&singleton =
    TAO_Singleton<TYPE, ACE_LOCK>::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
      if (TAO_Singleton_Manager::starting_up () ||
          TAO_Singleton_Manager::shutting_down ())
        {
          // The program is still starting up, and therefore assumed
          // to be single threaded.  There's no need to double-check.
          // Or, the TAO_Singleton_Manager instance has been destroyed,
          // so the preallocated lock is not available.  Either way,
          // don't register for destruction with the
          // TAO_Singleton_Manager:  we'll have to leak this instance.
#endif /* ACE_MT_SAFE */

          ACE_NEW_RETURN (singleton, (TAO_Singleton<TYPE, ACE_LOCK>), 0);
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
        }
      else
        {
          // Obtain a lock from the ACE_Object_Manager.  The pointer
          // is static, so we only obtain one per TAO_Singleton
          // instantiation.
          static ACE_LOCK *lock = 0;
          if (ACE_Object_Manager::get_singleton_lock (lock) != 0)
            // Failed to acquire the lock!
            return 0;

          ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *lock, 0);

          if (singleton == 0)
            {
              ACE_NEW_RETURN (singleton, (TAO_Singleton<TYPE, ACE_LOCK>), 0);

              // Register for destruction with TAO_Singleton_Manager.
              TAO_Singleton_Manager::at_exit (singleton);
            }
        }
#endif /* ACE_MT_SAFE */
    }

  return &singleton->instance_;
}

template <class TYPE, class ACE_LOCK> void
TAO_Singleton<TYPE, ACE_LOCK>::cleanup (void *)
{
  delete this;
  TAO_Singleton<TYPE, ACE_LOCK>::instance_i () = 0;
}

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
// Pointer to the Singleton instance.
template <class TYPE, class ACE_LOCK> TAO_Singleton<TYPE, ACE_LOCK> *
TAO_Singleton<TYPE, ACE_LOCK>::singleton_ = 0;

template <class TYPE, class ACE_LOCK> TAO_TSS_Singleton<TYPE, ACE_LOCK> *
TAO_TSS_Singleton<TYPE, ACE_LOCK>::singleton_ = 0;
#endif /* !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES) */


template <class TYPE, class ACE_LOCK> void
TAO_TSS_Singleton<TYPE, ACE_LOCK>::dump (void)
{
  ACE_TRACE ("TAO_TSS_Singleton<TYPE, ACE_LOCK>::dump");

#if !defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("instance_ = %x"),
              TAO_TSS_Singleton<TYPE, ACE_LOCK>::instance_i ()));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TAO_TSS_Singleton<TYPE, ACE_LOCK> *&
TAO_TSS_Singleton<TYPE, ACE_LOCK>::instance_i (void)
{
#if defined (ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES)
  // Pointer to the Singleton instance.  This works around a bug with
  // G++ and it's (mis-)handling of templates and statics...
  static TAO_TSS_Singleton<TYPE, ACE_LOCK> *singleton_ = 0;

  return singleton_;
#else
  return TAO_TSS_Singleton<TYPE, ACE_LOCK>::singleton_;
#endif /* ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES */
}

template <class TYPE, class ACE_LOCK> TYPE *
TAO_TSS_Singleton<TYPE, ACE_LOCK>::instance (void)
{
  ACE_TRACE ("TAO_TSS_Singleton<TYPE, ACE_LOCK>::instance");

  TAO_TSS_Singleton<TYPE, ACE_LOCK> *&singleton =
    TAO_TSS_Singleton<TYPE, ACE_LOCK>::instance_i ();

  // Perform the Double-Check pattern...
  if (singleton == 0)
    {
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
      if (TAO_Singleton_Manager::starting_up () ||
          TAO_Singleton_Manager::shutting_down ())
        {
          // The program is still starting up, and therefore assumed
          // to be single threaded.  There's no need to double-check.
          // Or, the TAO_Singleton_Manager instance has been destroyed,
          // so the preallocated lock is not available.  Either way,
          // don't register for destruction with the
          // TAO_Singleton_Manager:  we'll have to leak this instance.
#endif /* ACE_MT_SAFE */

          ACE_NEW_RETURN (singleton, (TAO_TSS_Singleton<TYPE, ACE_LOCK>), 0);
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
        }
      else
        {
          // Obtain a lock from the ACE_Object_Manager.  The pointer
          // is static, so we only obtain one per TAO_Singleton
          // instantiation.
          static ACE_LOCK *lock = 0;
          if (ACE_Object_Manager::get_singleton_lock (lock) != 0)
            // Failed to acquire the lock!
            return 0;

          ACE_GUARD_RETURN (ACE_LOCK, ace_mon, *lock, 0);

          if (singleton == 0)
            {
              ACE_NEW_RETURN (singleton, (TAO_TSS_Singleton<TYPE, ACE_LOCK>),
                              0);

              // Register for destruction with TAO_Singleton_Manager.
              TAO_Singleton_Manager::at_exit (singleton);
            }
        }
#endif /* ACE_MT_SAFE */
    }

  return ACE_TSS_GET (&singleton->instance_, TYPE);
}

template <class TYPE, class ACE_LOCK> void
TAO_TSS_Singleton<TYPE, ACE_LOCK>::cleanup (void *)
{
  delete this;
  TAO_TSS_Singleton<TYPE, ACE_LOCK>::instance_i () = 0;
}

#endif  /* TAO_SINGLETON_CPP */
