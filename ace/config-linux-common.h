/* -*- C++ -*- */
// $Id$

// This configuration file is designed to be included by another,
// specific configuration file.  It provides config information common
// to all Linux platforms.  It automatically determines the CPU
// architecture, libc (libc5 or glibc), and compiler (g++ or egcs),
// and configures based on those.

#if !defined (ACE_LINUX_COMMON_H)
#define ACE_LINUX_COMMON_H

#define ACE_HAS_BYTESEX_H

#if ! defined (__ACE_INLINE__)
#define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

// Needed to differentiate between libc 5 and libc 6 (aka glibc)
// It's there on all libc 5 systems I checked
#include <features.h>

// JAWS uses this, argh!
#define LINUX

// First the machine specific part

#if defined (i386)
  // If running an Intel, assume that it's a Pentium so that
  // ACE_OS::gethrtime () can use the RDTSC instruction.  If
  // running a 486 or lower, be sure to comment this out.
  // (If not running an Intel CPU, this #define will not be seen
  //  because of the i386 protection, so it can be ignored.)
# define ACE_HAS_PENTIUM
#endif /* i386 */

#if defined (__alpha__)
# define ACE_HAS_64BIT_LONGS

// The following might be necessary on Intel as well as Alpha.
# define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)

// The following might only be necessary on Alpha?
# define ACE_HAS_DLFCN_H_BROKEN_EXTERN_C
# define ACE_LACKS_RPC_H
# define ACE_NEEDS_SYSTIME_H
#endif /* __alpha__ */

// Then glibc/libc5 specific parts

#if defined(__GLIBC__)
// OS/compiler uses size_t * rather than int * for socket lengths
#define ACE_HAS_SIZET_SOCKET_LEN
#else
// Platform lacks POSIX prototypes for certain System V functions 
// like shared memory and message queues.
#define ACE_LACKS_SOME_POSIX_PROTOTYPES
#endif /* __GLIBC__ */


// Then the compiler specific parts

// egcs or really modern gcc
#if __GNUC__ > 2 || ( __GNUC__ == 2 && __GNUC_MINOR__ >= 90)

// Compiler/platform has correctly prototyped header files.
# define ACE_HAS_CPLUSPLUS_HEADERS

# define ACE_LACKS_ACE_IOSTREAM

// Compiler supports to-be-ANSI casts
# define ACE_HAS_ANSI_CASTS

#endif /* EGCS */


// Completely common part :-)

// Platform/compiler has the sigwait(2) prototype
// Was only for Alpha
#define ACE_HAS_SIGWAIT

// Fixes a problem with new versions of Linux...
#ifndef msg_accrights
#undef msg_control
#define msg_accrights msg_control
#endif

#ifndef msg_accrightslen
#undef msg_controllen
#define msg_accrightslen msg_controllen
#endif

// Compiler/platform supports alloca().
#define ACE_HAS_ALLOCA

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE
#define ACE_HAS_GETRUSAGE_PROTO

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// ONLY define this if you have config'd multicast into a 2.x kernel.
// If you do anything else, we've never tested it!
#define ACE_HAS_IP_MULTICAST

#define ACE_HAS_LONGLONG_T

#define ACE_HAS_LONG_FDMASK

#define ACE_HAS_STRING_CLASS

// Linux defines struct msghdr in /usr/include/socket.h
#define ACE_HAS_MSG

// Linux "improved" the interface to select() so that it modifies
// the struct timeval to reflect the amount of time not slept
// (see NOTES in Linux's select(2) man page).
#define ACE_HAS_NONCONST_SELECT_TIMEVAL

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

// Platform defines struct timespec but not timespec_t
#define ACE_LACKS_TIMESPEC_T

#define ACE_LACKS_STRRECVFD

#define ACE_LACKS_MSYNC
#define ACE_LACKS_MADVISE

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYSCALL_H

#define ACE_HAS_SUNOS4_GETTIMEOFDAY

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Compiler/platform defines a union semun for SysV shared memory.
#define ACE_HAS_SEMUN

#define ACE_HAS_POSIX_TIME

// TDN - adapted from file for SunOS4 platforms using the GNU g++ compiler
// Compiler's template mechanism must see source code (i.e., .C files).
#define ACE_TEMPLATES_REQUIRE_SOURCE

#define ACE_HAS_TEMPLATE_SPECIALIZATION
#define ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION

// Compiler doesn't support static data member templates.
#define ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES

// Turns off the tracing feature.
#if !defined (ACE_NTRACE)
#define ACE_NTRACE 1
#endif /* ACE_NTRACE */

#if defined(__EXCEPTIONS)
#define ACE_HAS_EXCEPTIONS
#endif

#endif /* ACE_LINUX_COMMON_H */
