// $Id$
#ifndef ACE_CONFIG_ANDROID_H
#define ACE_CONFIG_ANDROID_H

#define ACE_HAS_NET_IF_DL_H
#define ACE_SIZEOF_LONG_DOUBLE 8
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_SEARCH_H
#define ACE_LACKS_STROPTS_H
#define ACE_HAS_SIGINFO_T
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_SWAB
#define ACE_LACKS_TRUNCATE
#define ACE_LACKS_LOG2
#define ACE_LACKS_PTHREAD_CANCEL
#define ACE_LACKS_TEMPNAM
#define ACE_LACKS_ISCTYPE
#define ACE_LACKS_SEEKDIR
#define ACE_LACKS_TELLDIR
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_SYSV_MSQ_PROTOS
#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_SETSCHED
#define ACE_LACKS_SYS_SYSCTL_H
#define ACE_LACKS_STRRECVFD
#define ACE_TEMPLATES_REQUIRE_SOURCE
#define ACE_LACKS_RAND_R
#define ACE_LACKS_WCSTOLL
#define ACE_LACKS_WCSTOULL
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_HAS_LINUX_SEM_H
#define ACE_HAS_LINUX_SHM_H
#define ACE_LACKS_CUSERID
#define ACE_LACKS_GETHOSTENT

// I'm not sure if this is correct
#define ACE_LACKS_RWLOCK_T

/* This type is mandatory, but Android doesn't define it. */
typedef unsigned long fd_mask;

#include "ace/config-linux.h"

#ifdef ACE_HAS_CLOCK_SETTIME
#undef ACE_HAS_CLOCK_SETTIME
#endif

// epoll lacks some features on Android
#ifdef ACE_HAS_EVENT_POLL
#undef ACE_HAS_EVENT_POLL
#endif

# if defined(ACE_IMPORT_SINGLETON_DECLARATION)
# undef ACE_IMPORT_SINGLETON_DECLARATION
# define ACE_IMPORT_SINGLETON_DECLARATION(T)
# endif

# if defined(ACE_IMPORT_SINGLETON_DECLARE)
# undef ACE_IMPORT_SINGLETON_DECLARE
# define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
# endif

#ifdef ACE_SCANDIR_CMP_USES_VOIDPTR
#undef ACE_SCANDIR_CMP_USES_VOIDPTR
#endif

#ifdef ACE_SCANDIR_CMP_USES_CONST_VOIDPTR
#undef ACE_SCANDIR_CMP_USES_CONST_VOIDPTR
#endif

#ifdef ACE_HAS_UALARM
#undef ACE_HAS_UALARM
#endif

#ifdef ACE_HAS_SYSV_IPC
#undef ACE_HAS_SYSV_IPC
#endif

#ifdef ACE_HAS_GETIFADDRS
#undef ACE_HAS_GETIFADDRS
#endif

#ifdef ACE_HAS_BYTESEX_H
#undef ACE_HAS_BYTESEX_H
#endif

#ifdef ACE_HAS_LINUX_SYSINFO
#undef ACE_HAS_LINUX_SYSINFO
#endif

#define ACE_LACKS_PWD_FUNCTIONS

#define ACE_ERRNO_TYPE volatile int

#endif/* ACE_CONFIG_ANDROID_H*/
