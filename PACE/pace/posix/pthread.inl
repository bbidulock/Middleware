/* $Id$ -*- C -*-

 * =============================================================================
 *
 * = LIBRARY
 *    pace
 *
 * = FILENAME
 *    pace/posix/pthread.inl
 *
 * = AUTHOR
 *    Luther Baker
 *
 * ============================================================================= */

#include "pace/unistd.h"

PACE_INLINE
int
pace_pthread_atfork (void (*prepare) (),
                     void (*parent) (),
                     void (*child) ())
{
  return pthread_atfork (prepare, parent, child);
}

PACE_INLINE
int
pace_pthread_attr_destroy (pace_pthread_attr_t * attr)
{
  return pthread_attr_destroy (attr);
}

PACE_INLINE
int
pace_pthread_attr_getdetachstate (const pace_pthread_attr_t * attr,
                                  int * detachstate)
{
  return pthread_attr_getdetachstate (attr, detachstate);
}

PACE_INLINE
int
pace_pthread_attr_getinheritsched (const pace_pthread_attr_t * attr,
                                   int * inheritsched)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  /* Cast away const since LynxOS' prototypes aren't const */
  return pthread_attr_getinheritsched ((pace_pthread_attr_t *) attr,
                                       inheritsched);
#else
  return pthread_attr_getinheritsched (attr, inheritsched);
#endif /* ! PACE_HAS_POSIX == PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_attr_getschedparam (const pace_pthread_attr_t * attr,
                                 pace_sched_param * param)
{
  return pthread_attr_getschedparam (attr, param);
}

PACE_INLINE
int
pace_pthread_attr_getschedpolicy (const pace_pthread_attr_t * attr,
                                  int * policy)
{
  return pthread_attr_getschedpolicy (attr, policy);
}

PACE_INLINE
int
pace_pthread_attr_getscope (const pace_pthread_attr_t * attr,
                            int * contentionscope)
{
  return pthread_attr_getscope (attr, contentionscope);
}

PACE_INLINE
int
pace_pthread_attr_getstackaddr (const pace_pthread_attr_t * attr,
                                void ** stackaddr)
{
  return pthread_attr_getstackaddr (attr, stackaddr);
}

PACE_INLINE
int
pace_pthread_attr_getstacksize (const pace_pthread_attr_t * attr,
                                size_t * stacksize)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  /* Cast away const since LynxOS' prototypes aren't const */
  return pthread_attr_getstacksize ((pace_pthread_attr_t *) attr, stacksize);
#else
  return pthread_attr_getstacksize (attr, stacksize);
#endif /* ! PACE_HAS_POSIX == PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_attr_init (pace_pthread_attr_t * attr)
{
  return pthread_attr_init (attr);
}

PACE_INLINE
int
pace_pthread_attr_setdetachstate (pace_pthread_attr_t * attr,
                                  int detachstate)
{
  return pthread_attr_setdetachstate (attr, detachstate);
}

PACE_INLINE
int
pace_pthread_attr_setinheritsched (pace_pthread_attr_t * attr,
                                   int inheritsched)
{
  return pthread_attr_setinheritsched (attr, inheritsched);
}

PACE_INLINE
int
pace_pthread_attr_setschedparam (pace_pthread_attr_t * attr,
                                 const pace_sched_param * param)
{
  return pthread_attr_setschedparam (attr, param);
}

PACE_INLINE
int
pace_pthread_attr_setschedpolicy (pace_pthread_attr_t * attr,
                                  int policy)
{
  return pthread_attr_setschedpolicy (attr, policy);
}

PACE_INLINE
int
pace_pthread_attr_setscope (pace_pthread_attr_t * attr,
                            int contentionscope)
{
  return pthread_attr_setscope (attr, contentionscope);
}

PACE_INLINE
int
pace_pthread_attr_setstackaddr (pace_pthread_attr_t * attr,
                                void * stackaddr)
{
  return pthread_attr_setstackaddr (attr, stackaddr);
}

PACE_INLINE
int
pace_pthread_attr_setstacksize (pace_pthread_attr_t * attr,
                                size_t stacksize)
{
  return pthread_attr_setstacksize (attr, stacksize);
}

PACE_INLINE
int
pace_pthread_cancel (pace_pthread_t thread)
{
  return pthread_cancel (thread);
}

PACE_INLINE
int
pace_pthread_cond_broadcast (pace_pthread_cond_t * cond)
{
  return pthread_cond_broadcast (cond);
}

PACE_INLINE
int
pace_pthread_cond_destroy (pace_pthread_cond_t * cond)
{
  return pthread_cond_destroy (cond);
}

PACE_INLINE
int
pace_pthread_cond_init (pace_pthread_cond_t * cond,
                        const pace_pthread_condattr_t * attr)
{
  return pthread_cond_init (cond, attr);
}

PACE_INLINE
int
pace_pthread_cond_signal (pace_pthread_cond_t * cond)
{
  return pthread_cond_signal (cond);
}

PACE_INLINE
int
pace_pthread_cond_timedwait (pthread_cond_t * cond,
                             pace_pthread_mutex_t * mutex,
                             const pace_timespec * abstime)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  /* Cast away const since LynxOS' prototypes aren't const */
  return pthread_cond_timedwait (cond, mutex, (struct timespec *) abstime);
#else
  return pthread_cond_timedwait (cond, mutex, abstime);
#endif /* ! PACE_HAS_POSIX == PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_cond_wait (pace_pthread_cond_t * cond,
                        pace_pthread_mutex_t * mutex)
{
  return pthread_cond_wait (cond, mutex);
}

PACE_INLINE
int
pace_pthread_condattr_destroy (pace_pthread_condattr_t * attr)
{
  return pthread_condattr_destroy (attr);
}

PACE_INLINE
int
pace_pthread_condattr_getpshared (const pace_pthread_condattr_t * attr,
                                  int * pshared)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  /* Cast away const since LynxOS' prototypes aren't const */
  return pthread_condattr_getpshared ((pace_pthread_condattr_t *) attr,
                                      pshared);
#else
  return pthread_condattr_getpshared (attr, pshared);
#endif /* ! PACE_HAS_POSIX == PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_condattr_init (pace_pthread_condattr_t * attr)
{
  return pthread_condattr_init (attr);
}

PACE_INLINE
int
pace_pthread_condattr_setpshared (pace_pthread_condattr_t * attr,
                                 int pshared)
{
  return pthread_condattr_setpshared (attr, pshared);
}

PACE_INLINE
int
pace_pthread_create (pace_pthread_t * thread,
                     const pace_pthread_attr_t * attr,
                     void * (*start_routine) (void*),
                     void * arg)
{
  return pthread_create (thread, attr, start_routine, arg);
}

PACE_INLINE
int
pace_pthread_detach (pace_pthread_t thread)
{
  return pthread_detach (thread);
}

PACE_INLINE
int
pace_pthread_equal (pace_pthread_t t1, pthread_t t2)
{
  return pthread_equal (t1, t2);
}

PACE_INLINE
void
pace_pthread_exit (void * value_ptr)
{
  pthread_exit (value_ptr);
  return;
}

PACE_INLINE
int
pace_pthread_getschedparam (pace_pthread_t thread,
                            int * policy,
                            pace_sched_param * param)
{
  return pthread_getschedparam (thread, policy, param);
}

PACE_INLINE
void *
pace_pthread_getspecific (pace_pthread_key_t key)
{
  return pthread_getspecific (key);
}

PACE_INLINE
int
pace_pthread_join (pace_pthread_t thread, void ** value_ptr)
{
  return pthread_join (thread, value_ptr);
}

PACE_INLINE
int
pace_pthread_key_create (pace_pthread_key_t * key,
                         void (*destructor)(void*))
{
  return pthread_key_create (key, destructor);
}

PACE_INLINE
int
pace_pthread_key_delete (pace_pthread_key_t key)
{
  return pthread_key_delete (key);
}

PACE_INLINE
int
pace_pthread_kill (pace_pthread_t thread, int sig)
{
  return pthread_kill (thread, sig);
}

PACE_INLINE
int
pace_pthread_mutex_destroy (pace_pthread_mutex_t * mutex)
{
  return pthread_mutex_destroy (mutex);
}

PACE_INLINE
int
pace_pthread_mutex_getprioceiling (pace_pthread_mutex_t * mutex,
                                   int * prioceiling)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  PACE_ERRNO_NO_SUPPORT_RETURN (-1);
#else  /* ! PACE_LYNXOS */
  return pthread_mutex_getprioceiling (mutex, prioceiling);
#endif /* ! PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_mutex_init (pace_pthread_mutex_t * mutex,
                         const pace_pthread_mutexattr_t * attr)
{
  return pthread_mutex_init (mutex, attr);
}

PACE_INLINE
int
pace_pthread_mutex_lock (pace_pthread_mutex_t * mutex)
{
  return pthread_mutex_lock (mutex);
}

PACE_INLINE
int
pace_pthread_mutex_setprioceiling (pace_pthread_mutex_t * mutex,
                                   int prioceiling,
                                   int * old_ceiling)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  PACE_ERRNO_NO_SUPPORT_RETURN (-1);
#else  /* ! PACE_LYNXOS */
  return pthread_mutex_setprioceiling (mutex, prioceiling, old_ceiling);
#endif /* ! PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_mutex_trylock (pthread_mutex_t * mutex)
{
  return pthread_mutex_trylock (mutex);
}

PACE_INLINE
int
pace_pthread_mutex_unlock (pace_pthread_mutex_t * mutex)
{
  return pthread_mutex_unlock (mutex);
}

PACE_INLINE
int
pace_pthread_mutexattr_destroy (pace_pthread_mutexattr_t * attr)
{
  return pthread_mutexattr_destroy (attr);
}

PACE_INLINE
int
pace_pthread_mutexattr_getprioceiling (pace_pthread_mutexattr_t * attr,
                                       int * prioceiling)
{
  return pthread_mutexattr_getprioceiling (attr, prioceiling);
}

PACE_INLINE
int
pace_pthread_mutexattr_getprotocol (const pace_pthread_mutexattr_t * attr,
                                    int * protocol)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  /* Cast away const since LynxOS' prototypes aren't const */
  return pthread_mutexattr_getprotocol ((pace_pthread_mutexattr_t *) attr,
                                        protocol);
#else
  return pthread_mutexattr_getprotocol (attr, protocol);
#endif /* ! PACE_HAS_POSIX == PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_mutexattr_setprioceiling (pace_pthread_mutexattr_t * attr,
                                       int prioceiling)
{
  return pthread_mutexattr_setprioceiling (attr, prioceiling);
}

PACE_INLINE
int
pace_pthread_mutexattr_setprotocol (pace_pthread_mutexattr_t * attr,
                                    int protocol)
{
  return pthread_mutexattr_setprotocol (attr, protocol);
}

PACE_INLINE
int
pace_pthread_mutexattr_getpshared (const pace_pthread_mutexattr_t * attr,
                                   int * pshared)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  /* Cast away const since LynxOS' prototypes aren't const */
  return pthread_mutexattr_getpshared ((pace_pthread_mutexattr_t *) attr,
                                       pshared);
#else
  return pthread_mutexattr_getpshared (attr, pshared);
#endif /* ! PACE_HAS_POSIX == PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_mutexattr_init (pace_pthread_mutexattr_t * attr)
{
  return pthread_mutexattr_init (attr);
}

PACE_INLINE
int
pace_pthread_mutexattr_setpshared (pace_pthread_mutexattr_t * attr,
                                   int pshared)
{
  return pthread_mutexattr_setpshared (attr, pshared);
}

PACE_INLINE
int
pace_pthread_once (pace_pthread_once_t * once_control,
                   void (*void_routine) ())
{
  return pthread_once (once_control, void_routine);
}

PACE_INLINE
pace_pthread_t
pace_pthread_self ()
{
  return pthread_self ();
}

PACE_INLINE
int
pace_pthread_setcancelstate (int state, int * oldstate)
{
  return pthread_setcancelstate (state, oldstate);
}

PACE_INLINE
int
pace_pthread_setcanceltype (int type, int * oldtype)
{
  return pthread_setcanceltype (type, oldtype);
}


PACE_INLINE
int
pace_pthread_setschedparam (pace_pthread_t thread,
                            int policy,
                            const pace_sched_param * param)
{
  return pthread_setschedparam (thread, policy, param);
}

PACE_INLINE
int
pace_pthread_setspecific (pace_pthread_key_t key, const void * value)
{
#if PACE_HAS_POSIX == PACE_LYNXOS
  /* Cast away const since LynxOS' prototypes aren't const */
  return pthread_setspecific (key, (void *) value);
#else
  return pthread_setspecific (key, value);
#endif /* ! PACE_HAS_POSIX == PACE_LYNXOS */
}

PACE_INLINE
int
pace_pthread_sigmask (int how, const sigset_t * set,
                      sigset_t * oset)
{
  return pthread_sigmask (how, set, oset);
}

PACE_INLINE
void
pace_pthread_testcancel ()
{
  pthread_testcancel ();
  return;
}
