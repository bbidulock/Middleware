/* -*- C++ -*- */
// $Id$

// The following configuration file is designed to work for SunOS 5.5
// platforms using the GNU g++ compiler (version 2.7.2 or later).

#if !defined (ACE_CONFIG_H)
#define ACE_CONFIG_H

// ACE_HAS_EXCEPTIONS requires -fhandle-exceptions, but that gives
// g++ 2.7.2 fits:  it spits out all kinds of warnings that it doesn't
// without that option (and that are just wrong), and runs out of
// virtual memory when trying to compile ace/Log_Msg.cpp.
// So until -fhandle-exceptions gets fixed, we can't use this with g++ . . .
// #define ACE_HAS_EXCEPTIONS

#define ACE_HAS_UNICODE

#if defined (__ACE_INLINE__)
#define ACE_HAS_INLINED_OSCALLS
#endif /* __ACE_INLINE__ */

// G++ doesn't support template typedefs fully (yet).
// #define ACE_HAS_TEMPLATE_TYPEDEFS

#define ACE_HAS_TERM_IOCTLS

// Must specialize templates due to G++'s lame parameterized type
// support...
#define ACE_TEMPLATES_REQUIRE_SPECIALIZATION

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC			

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Platform supports system configuration information.
#define ACE_HAS_SYSINFO

// Platform supports the POSIX regular expression library
#define ACE_HAS_REGEX

// Platform supports recvmsg and sendmsg.
#define ACE_HAS_MSG

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYSCALL_H

// Platform supports reentrant functions (i.e., all the POSIX *_r functions).
#define ACE_HAS_REENTRANT_FUNCTIONS

// Compiler's template mechanism must see source code (i.e., .C files).
#define ACE_TEMPLATES_REQUIRE_SOURCE

// Denotes that GNU has cstring.h as standard
// which redefines memchr()
#define ACE_HAS_GNU_CSTRING_H

// Compiler doesn't support static data member templates.
#define ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES

// Compiler/platform correctly calls init()/fini() for shared libraries.
#define ACE_HAS_AUTOMATIC_INIT_FINI

// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Compiler/platform supports SunOS high resolution timers.
#define ACE_HAS_HI_RES_TIMER

// Only enable this if you don't mind linking with -lposix4
// #defined ACE_HAS_CLOCK_GETTIME

// Platform supports IP multicast
#define ACE_HAS_IP_MULTICAST

// Compiler/platform supports the "long long" datatype.
#define ACE_HAS_LONGLONG_T

// Compiler/platform supports alloca()
#define ACE_HAS_ALLOCA

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

// Sockets may be called in multi-threaded programs.
#define ACE_HAS_MT_SAFE_SOCKETS

// Platform contains <poll.h>.
#define ACE_HAS_POLL

// Platform supports POSIX timers via timestruc_t.
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_SVR4_TIME

// Platform supports the /proc file system.
#define ACE_HAS_PROC_FS

// Platform supports the prusage_t struct.
#define ACE_HAS_PRUSAGE_T

// Explicit dynamic linking permits "lazy" symbol resolution.
#define ACE_HAS_RTLD_LAZY_V

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Platform supports SVR4 extended signals.
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_UCONTEXT_T

// Compiler/platform provides the sockio.h file.
#define ACE_HAS_SOCKIO_H

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Platform supports STREAMS.
#define ACE_HAS_STREAMS

// Platform supports STREAM pipes.
#define ACE_HAS_STREAM_PIPES

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Compiler/platform supports struct strbuf.
#define ACE_HAS_STRBUF_T

// Compiler/platform supports SVR4 dynamic linking semantics.
#define ACE_HAS_SVR4_DYNAMIC_LINKING

// Compiler/platform supports SVR4 gettimeofday() prototype.
#define ACE_HAS_SVR4_GETTIMEOFDAY

// Compiler/platform supports SVR4 TLI (in particular, T_GETNAME stuff)...
#define ACE_HAS_SVR4_TLI

// Platform provides <sys/filio.h> header.
#define ACE_HAS_SYS_FILIO_H

// Compiler/platform supports sys_siglist array.
#define ACE_HAS_SYS_SIGLIST

/* Turn off the following six defines if you want to disable threading. */
// Compile using multi-thread libraries.
#define _REENTRANT
#define ACE_MT_SAFE

// Platform supports threads.
#define ACE_HAS_THREADS

// Platform supports POSIX pthreads *and* Solaris threads!
#define ACE_HAS_STHREADS
#define ACE_HAS_PTHREADS

// Compiler/platform has thread-specific storage
#define ACE_HAS_THREAD_SPECIFIC_STORAGE

#define ACE_HAS_SIGWAIT
#define ACE_LACKS_CONDATTR_PSHARED

// Platform supports TLI timod STREAMS module.
#define ACE_HAS_TIMOD_H

// Platform supports TLI tiuser header.
#define ACE_HAS_TIUSER_H

// Platform provides TLI function prototypes.
#define ACE_HAS_TLI_PROTOTYPES

// Platform supports TLI.
#define ACE_HAS_TLI

// Use the poll() event demultiplexor rather than select().
//#define ACE_USE_POLL

// Turns off the tracing feature.
#if !defined (ACE_NTRACE)
#define ACE_NTRACE 1
#endif /* ACE_NTRACE */

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

#endif /* ACE_CONFIG_H */
