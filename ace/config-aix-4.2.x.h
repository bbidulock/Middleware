// The following configuration file is designed to work for OS
// platforms running AIX 4.2.x using the IBM C++ compiler.

#if !defined (ACE_CONFIG_H)
#define ACE_CONFIG_H

// Compiling for AIX.
#define AIX
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#define ACE_HAS_ONLY_TWO_PARAMS_FOR_ASCTIME_R_AND_CTIME_R
// Use BSD 4.4 socket definitions
#define _BSD 44

#define ACE_HAS_AIX_HI_RES_TIMER
#define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)
#define ACE_HAS_UNION_WAIT
#define ACE_HAS_MULTICAST
#define ACE_HAS_TID_T
#define ACE_HAS_SIGWAIT
#define ACE_HAS_H_ERRNO
#define ACE_LACKS_THREAD_PROCESS_SCOPING
#define ACE_LACKS_THREAD_STACK_ADDR
#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_HAS_SIN_LEN
#define ACE_HAS_SYSV_IPC			
#define ACE_HAS_STRUCT_NETDB_DATA
#define ACE_HAS_ALLOCA
#define ACE_HAS_LONGLONG_T
#define ACE_HAS_REENTRANT_FUNCTIONS 
#define ACE_HAS_SYSV_IPC
#define ACE_HAS_TLI
#define ACE_HAS_TLI_PROTOTYPES
#define ACE_HAS_TIUSER_H
#define ACE_TEMPLATES_REQUIRE_PRAGMA
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
#define ACE_HAS_THREAD_SELF
#define ACE_HAS_AUTOMATIC_INIT_FINI
#define ACE_HAS_CHARPTR_DL
#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_SVR4_TIME
#define ACE_HAS_THREADS
#define ACE_MT_SAFE
#define ACE_HAS_UTIME
#define ACE_HAS_SELECT_H

#define ACE_HAS_MSG
// #define ACE_LACKS_RECVMSG
// #define ACE_LACKS_SENDMSG

// This environment requires this thing
#define _BSD_INCLUDES

// Compiler supports the getrusage() system call
#define ACE_HAS_GETRUSAGE

// Prototypes for both signal() and struct sigaction are consistent.
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Compiler/platform supports poll().
#define ACE_HAS_POLL

// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK

// Compiler/platform defines the sig_atomic_t typedef
#define ACE_HAS_SIG_ATOMIC_T

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Compiler supports stropts.h
#define ACE_HAS_STREAMS
// #define ACE_HAS_STREAM_PIPES

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// EYE the include file is there

// AIX bzero()
#define ACE_HAS_STRINGS

// ??? has the berkeley stuff
// #define ACE_HAS_SUNOS4_GETTIMEOFDAY
#define ACE_HAS_SVR4_GETTIMEOFDAY

// Note, this only works if the flag is set above!
#define ACE_HAS_GETRUSAGE

// EYE assume it does for now.
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK
#define ACE_HAS_PTHREADS
#define ACE_PTHREADS_MAP

// include there
#define ACE_HAS_TIMOD_H
#define ACE_HAS_TIUSER_H

#if !defined (ACE_NTRACE)
#define ACE_NTRACE 1
#endif /* ACE_NTRACE */
#define ACE_HAS_STRBUF_T

#define ACE_HAS_SIGINFO_T
#define ACE_LACKS_SIGINFO_H
#define ACE_HAS_UCONTEXT_T
#define ACE_HAS_RTLD_LAZY_V
#define ACE_HAS_SIZET_SOCKET_LEN

// BSD 4.4 interface fixes nabbed from config-linux.h
#if !defined (msg_accrights)
#undef msg_control
#define msg_accrights msg_control
#endif /* msg_accrights */
 
#if !defined (msg_accrightslen)
#undef msg_controllen
#define msg_accrightslen msg_controllen
#endif /* msg_accrightslen */

#endif /* ACE_CONFIG_H */
