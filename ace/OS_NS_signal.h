// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_signal.h
 *
 *  $Id$
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_SIGNAL_H
# define ACE_OS_NS_SIGNAL_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_signal.h"

# if !defined (SIG_BLOCK)
#   define SIG_BLOCK   1
# endif /* SIG_BLOCK   */

# if !defined (SIG_UNBLOCK)
#   define SIG_UNBLOCK 2
# endif /* SIG_UNBLOCK */

# if !defined (SIG_SETMASK)
#   define SIG_SETMASK 3
# endif /* SIG_SETMASK */

// Create some useful typedefs.
// @todo: remove, not used  dhinton
//typedef const char **SYS_SIGLIST;

# if !defined (ACE_HAS_SIGINFO_T)
struct ACE_OS_Export siginfo_t
{
  siginfo_t (ACE_HANDLE handle);
  siginfo_t (ACE_HANDLE *handles);      // JCEJ 12/23/96

  /// Win32 HANDLE that has become signaled.
  ACE_HANDLE si_handle_;

  /// Array of Win32 HANDLEs all of which have become signaled.
  ACE_HANDLE *si_handles_;
};
# endif /* ACE_HAS_SIGINFO_T */

namespace ACE_OS {

  //@{ @name A set of wrappers for Signals.

  int kill (pid_t pid,
            int signum);

  int pthread_sigmask (int how,
                       const sigset_t *nsp,
                       sigset_t *osp);

  int sigaction (int signum,
                 const struct sigaction *nsa,
                 struct sigaction *osa);

  int sigaddset (sigset_t *s,
                 int signum);

  int sigdelset (sigset_t *s,
                 int signum);

  int sigemptyset (sigset_t *s);

  int sigfillset (sigset_t *s);

  int sigismember (sigset_t *s,
                   int signum);

  ACE_SignalHandler signal (int signum,
                            ACE_SignalHandler);

  int sigprocmask (int how,
                   const sigset_t *nsp,
                   sigset_t *osp);

  int sigsuspend (const sigset_t *set);

  //@}

} /* namespace ACE_OS */

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_signal.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SIGNAL_H */
