/* -*- C++ -*- */
// $Id$

// This is the config file for IRIX 6.2, 6.4 and hopefully 6.3, using
// the SGI C++ compiler (7.1 or higher).

// For IRIX 6.2 there are several patches that should be applied to
// get reliable operation with multi-threading and exceptions.
// Specifically you should get a reasonable current IRIX, Compiler
// and POSIX patch-sets.

// For IRIX 6.[34] it's less critical, but it's still recommended
// that you apply the applicable patch-sets (IRIX and Compiler I believe).

// These patches are updated frequently, so you should ask your support
// contact or search SGI's web site (http://www.sgi.com) for the latest
// version.

// Since this files gets included from config-irix6.x-sgic++.h we
// cannot use ACE_CONFIG_H here.
#if !defined (ACE_CONFIG_IRIX6X_NTHR_H)
#define ACE_CONFIG_IRIX6X_NTHR_H

// Include this file to set the _MIPS_SIM*ABI* macros.
#include <sgidefs.h>

// The Irix 6.x float.h doesn't allow us to distinguish between a
// double and a long double.  So, we have to hard-code this.  Thanks
// to Bob Laferriere <laferrie@gsao.med.ge.com> for figuring it out.
#if defined (_MIPS_SIM)             /* 6.X System */
# if defined (_MIPS_SIM_NABI32) && (_MIPS_SIM == _MIPS_SIM_NABI32)
#   define ACE_SIZEOF_LONG_DOUBLE 16
# elif defined (_MIPS_SIM_ABI32) && (_MIPS_SIM == _MIPS_SIM_ABI32)
#   define ACE_SIZEOF_LONG_DOUBLE 8
# elif !defined (ACE_SIZEOF_LONG_DOUBLE)
#   define ACE_SIZEOF_LONG_DOUBLE 8
# endif
#else
# define ACE_SIZEOF_LONG_DOUBLE 8   /* 5.3 System */
#endif

#define ACE_HAS_SGIDLADD
#define ACE_HAS_P_READ_WRITE
#define ACE_LACKS_LINEBUFFERED_STREAMBUF
#define ACE_HAS_SETOWN
#define ACE_HAS_SYSENT_H
#define ACE_HAS_SYSINFO
#define ACE_HAS_UALARM

// Platform has support for multi-byte character support compliant
// with the XPG4 Worldwide Portability Interface wide-character
// classification.
#define ACE_HAS_XPG4_MULTIBYTE_CHAR

// We need to setup a very high address or Naming_Test won't run.
#define ACE_DEFAULT_BASE_ADDR ((char *) (1024U * 1024 * 1024))

#define ACE_LACKS_SIGNED_CHAR
// Platform supports getpagesize() call.
#define ACE_HAS_GETPAGESIZE

// Platform supports reentrant functions (i.e., all the POSIX *_r
// functions).
#define ACE_HAS_REENTRANT_FUNCTIONS

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// Platform has terminal ioctl flags like TCGETS and TCSETS.
#define ACE_HAS_TERM_IOCTLS

// Platform does not support reentrant password file accessor functiions.
#define ACE_LACKS_PWD_REENTRANT_FUNCTIONS

// Platform does not support reentrant netdb functions (getprotobyname_r,
// getprotobynumber_r, gethostbyaddr_r, gethostbyname_r,
// getservbyname_r).
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS

// Platform supports the tid_t type (e.g., AIX and Irix 6.2)
#define ACE_HAS_TID_T

// uses ctime_r & asctime_r with only two parameters vs. three
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R

// Platform has no implementation of pthread_condattr_setpshared(),
// even though it supports pthreads! (like Irix 6.2)
#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_MUTEXATTR_PSHARED

#define ACE_LACKS_RWLOCK_T

// Platform/compiler has the sigwait(2) prototype
#define ACE_HAS_SIGWAIT

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// Platform requires void * for mmap().
#define ACE_HAS_VOIDPTR_MMAP

// Platform supports recvmsg and sendmsg.
#define ACE_HAS_MSG

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYSCALL_H

// Compiler/platform supports alloca()
#define ACE_HAS_ALLOCA

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

// Irix needs to define bzero() in this odd file <bstring.h>
#define ACE_HAS_BSTRING

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE

// Denotes that Irix has second argument to gettimeofday() which is
// variable (...)
#define ACE_HAS_IRIX_GETTIMEOFDAY

// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK

// Platform supports POSIX timers via timestruc_t.
#define ACE_HAS_POSIX_TIME
// #define ACE_HAS_SVR4_TIME
#define ACE_NEEDS_SYSTIME_H

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Platform contains <poll.h>.
#define ACE_HAS_POLL

// No multi-threading so use poll() call
// - for easier debugging, if nothing else
// #define ACE_USE_POLL

// Platform supports the /proc file system.
#define ACE_HAS_PROC_FS

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Platform supports SVR4 extended signals.
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_UCONTEXT_T

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Platform supports STREAMS.
#define ACE_HAS_STREAMS

// Platform supports STREAM pipes (note that this is disabled by
// default, see the manual page on pipe(2) to find out how to enable
// it).
// #define ACE_HAS_STREAM_PIPES

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Compiler/platform supports struct strbuf.
#define ACE_HAS_STRBUF_T

// Compiler/platform supports SVR4 dynamic linking semantics.
#define ACE_HAS_SVR4_DYNAMIC_LINKING

// Prototypes for both signal() and struct sigaction are consistent.
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Platform provides <sys/filio.h> header.
#define ACE_HAS_SYS_FILIO_H

// Compiler/platform defines a union semun for SysV shared memory.
#define ACE_HAS_SEMUN

// Platform supports IP multicast
#define ACE_HAS_IP_MULTICAST

// The following three should be enabled/disabled together.
#if _COMPILER_VERSION >= 720
#define ACE_HAS_TEMPLATE_SPECIALIZATION
#define ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION
#else
#define ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA
#endif /* _COMPILER_VERSION >= 720 */
#define ACE_TEMPLATES_REQUIRE_SOURCE
#define ACE_REQUIRES_FUNC_DEFINITIONS

// Platform supports exceptions. Under 6.2 this requires an extra flag
// for the compiler, don't worry is already there in
// platform_irix6.x.GNU
#define ACE_HAS_EXCEPTIONS

// Platform supports STREAM pipes (note that this is disabled by
// default, see the manual page on pipe(2) to find out how to enable
// it).
// #define ACE_HAS_STREAM_PIPES

// Platform supports POSIX timers via timestruc_t.
// This will *NOT* work in 6.4, but ACE doesn't use it anymore.
// #define ACE_HAS_POSIX_TIME
// #define ACE_HAS_SVR4_TIME

// Turns off the tracing feature.
#if !defined (ACE_NTRACE)
#define ACE_NTRACE 1
#endif /* ACE_NTRACE */

#endif /* ACE_CONFIG_IRIX6X_NTHR_H */
