/* -*- C++ -*- */
// $Id$

// The following configuration file contains the defines 
// common to all Win32/MSVC/MFC combinations.

#if !defined (ACE_WIN32_COMMON_H)
#define ACE_WIN32_COMMON_H

// ---------------- platform features or lack of them -------------

#define ACE_HAS_EXCEPTIONS
#define ACE_LACKS_SIGACTION
#define ACE_LACKS_SIGSET
#define ACE_LACKS_EXEC

#define ACE_LACKS_SBRK
#define ACE_LACKS_UTSNAME_T
#define ACE_LACKS_SEMBUF_T
#define ACE_LACKS_MSGBUF_T
#define ACE_LACKS_SYSV_SHMEM

// Compiler/platform correctly calls init()/fini() for shared
// libraries. - applied for DLLs ?
//define ACE_HAS_AUTOMATIC_INIT_FINI

// Compiler doesn't support static data member templates.
#define ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES

#define ACE_LACKS_RECVMSG
#define ACE_LACKS_SENDMSG

// Platform supports POSIX O_NONBLOCK semantics.
//define ACE_HAS_POSIX_NONBLOCK

#define ACE_LACKS_MODE_MASKS
#define ACE_LACKS_STRRECVFD

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Platform supports IP multicast
#define ACE_HAS_IP_MULTICAST

// Sockets may be called in multi-threaded programs.
#define ACE_HAS_MT_SAFE_SOCKETS

// Platform contains <poll.h>.
//define ACE_HAS_POLL

// Platform supports POSIX timers via timestruc_t.
//define ACE_HAS_POSIX_TIME

// Platform supports the /proc file system.
//define ACE_HAS_PROC_FS

//#define ACE_HAS_STANDARD_CPP_LIBRARY

// Platform supports the rusage struct.
#define ACE_HAS_GETRUSAGE

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Andreas Ueltschi tells me this is a good thing...
#define ACE_HAS_SVR5_GETTIMEOFDAY

// Compiler/platform supports poll().
//define ACE_HAS_SVR4_POLL

// Compiler/platform supports SVR4 signal typedef.
//define ACE_HAS_SVR4_SIGNAL_T

// Platform provides <sys/filio.h> header.
//define ACE_HAS_SYS_FILIO_H

// Compiler/platform supports sys_siglist array.
//define ACE_HAS_SYS_SIGLIST

#define ACE_WIN32
#define ACE_HAS_TEMPLATE_INSTANTIATION

//#define ACE_HAS_ALLOC_HOOKS
#define ACE_TEMPLATES_REQUIRE_SOURCE

// Platform supports ACE_TLI timod STREAMS module.
//define ACE_HAS_TIMOD_H

// Platform supports ACE_TLI tiuser header.
//define ACE_HAS_TIUSER_H

// Platform provides ACE_TLI function prototypes.
// For Win32, this is not really true, but saves a lot of hassle!
#define ACE_HAS_TLI_PROTOTYPES
#define ACE_HAS_GNU_CSTRING_H
// Platform supports ACE_TLI.
//define ACE_HAS_TLI

// I'm pretty sure NT lacks these
#define ACE_LACKS_UNIX_DOMAIN_SOCKETS

// Windows NT needs readv() and writev()
#define ACE_NEEDS_WRITEV
#define ACE_NEEDS_READV

#define ACE_LACKS_COND_T
#define ACE_LACKS_RWLOCK_T

#define ACE_LACKS_KEY_T

// Platform support for non-blocking connects is broken
#define ACE_HAS_BROKEN_NON_BLOCKING_CONNECTS

// Platform support linebuffered streaming is broken
#define ACE_LACKS_LINEBUFFERED_STREAMBUF

// iostream header lacks ipfx (), isfx (), etc., declarations
#define ACE_LACKS_IOSTREAM_FX

// Turns off the tracing feature.
#if !defined (ACE_NTRACE)
	#define ACE_NTRACE 1
#endif /* ACE_NTRACE */
// #define ACE_NLOGGING

// ----------------- "derived" defines and includes -----------

// It seems that this works only with MSVC 4.1 and 4.2 
#if (1010 <= _MSC_VER) && (_MSC_VER <= 1020) 
	#define ACE_HAS_TEMPLATE_TYPEDEFS
#endif

// MFC itself defines STRICT.
#if defined ACE_HAS_MFC
	#if !defined(ACE_HAS_STRICT)
		#define ACE_HAS_STRICT
	#endif
#endif

// If you want to use highres timers, ensure that
// Build.Settings.C++.CodeGeneration.Processor is
// set to Pentium !
#if (_M_IX86 > 400)
	// Used for high resolution timers 
	#define ACE_HAS_PENTIUM
#endif

#if defined(ACE_MT_SAFE)
	// Platform supports threads.
	#define ACE_HAS_THREADS

	// Platform supports Windows32 threads.
	#define ACE_HAS_WTHREADS

	// Compiler/platform has thread-specific storage
	#define ACE_HAS_THREAD_SPECIFIC_STORAGE

	// must have _MT defined to include multithreading 
	// features from win32 headers
	#if !defined(_MT)
		#define _MT
	#endif

	// use DLLs instead of static libs
	#if !defined(_DLL)
		#define _DLL
	#endif
#endif

// We are using STL's min and max (in algobase.h).  Therefore the
// macros in window.h are extra
#if !defined NOMINMAX
	#define NOMINMAX
#endif /* NOMINMAX */

// While digging the MSVC 4.0 include files, I found how to disable
// MSVC warnings: --Amos Shapira

#if defined (_MSC_VER)
	// "C4355: 'this' : used in base member initializer list"
	#pragma warning(disable:4355) /* disable C4514 warning */
	//	#pragma warning(default:4355)   // use this to reenable, if desired

	#pragma warning(disable:4201)  /* winnt.h uses nameless structs */
#endif /* _MSC_VER */



#if defined (ACE_HAS_UNICODE) && !defined (UNICODE)
	#define UNICODE
#endif

#if defined (ACE_HAS_UNICODE) && !defined (_UNICODE)
	#define _UNICODE
#endif

#ifdef _DEBUG
	#include <crtdbg.h>
#endif

// We are build ACE and want to use MFC (multithreaded)
#if defined(ACE_BUILD_DLL) && defined(ACE_HAS_MFC) && defined (_MT)
	// force multithreaded MFC DLL
	#define _AFXDLL
#endif

// <windows.h> and MFC's <afxwin.h> are mutually
// incompatible. <windows.h> is brain-dead about MFC; it doesn't check
// to see whether MFC stuff is anticipated or already in progress
// before doing its thing. ACE needs (practically always) <winsock.h>,
// and winsock in turn needs support either from windows.h or from
// afxwin.h. One or the other, not both.
//
// The MSVC++ V4.0 environment defines preprocessor macros that
// indicate the programmer has chosen something from the
// Build-->Settings-->General-->MFC combo-box. <afxwin.h> defines a
// macro itself to protect against double inclusion. We'll take
// advantage of all this to select the proper support for winsock. -
// trl 26-July-1996

// This is necessary since MFC users apparently can't #include
// <windows.h> directly.
#if defined (_AFXDLL) || defined (_WINDLL) || ( defined(ACE_BUILD_DLL) && defined(ACE_HAS_MFC))
	#include /**/ <afxwin.h>   /* He is doing MFC */
		// Windows.h will be included via afxwin.h->afx.h->afx_ver_.h->afxv_w32.h
		// #define	_INC_WINDOWS  // Prevent winsock.h from including windows.h
#endif

#if !defined (_INC_WINDOWS)	/* Already include windows.h ? */
	// Must define strict before including windows.h !
	#if defined (ACE_HAS_STRICT)
		#define STRICT 1
	#endif /* ACE_HAS_STRICT */

	#if !defined (WIN32_LEAN_AND_MEAN)
		#define WIN32_LEAN_AND_MEAN
	#endif /* WIN32_LEAN_AND_MEAN */
#endif /* !defined (_INC_INWDOWS) */

#if defined (ACE_HAS_WINSOCK2)
	#if !defined (_WINSOCK2API_)

		#include /**/ <winsock2.h>		/* will also include windows.h, if not present */
		
		#if defined (_MSC_VER)
			#pragma comment(lib, "ws2_32.lib")
		#endif /* _MSC_VER */
	#endif /* _WINSOCK2API */

	#define ACE_WSOCK_VERSION 2, 0
#else
	#if !defined (_WINSOCKAPI_)
		#include /**/ <winsock.h>	/* will also include windows.h, if not present */

		#if defined (_MSC_VER)
			#pragma comment(lib, "wsock32.lib")
		#endif /* _MSC_VER */
	#endif /* _WINSOCKAPI */

	// Version 1.1 of WinSock
	#define ACE_WSOCK_VERSION 1, 1
#endif /* ACE_HAS_WINSOCK2 */

#if defined (_MSC_VER)
	#pragma warning(default: 4201)  /* winnt.h uses nameless structs */
#endif /* _MSC_VER */

#if(_WIN32_WINNT >= 0x0400)
	#define ACE_HAS_WIN32_TRYLOCK
	#define ACE_HAS_SIGNAL_OBJECT_AND_WAIT

	// If CancelIO is undefined get the updated sp2-sdk 
	// from MS
	#define ACE_HAS_CANCEL_IO
#endif

#if (_MSC_VER >= 1000)
	// Compiler/Platform supports the "using" keyword.
	#define ACE_HAS_USING_KEYWORD
#endif

#if (_MSC_VER < 1000)
	// This needs to be here since MSVC++ 2.0 seems to have forgotten to
	// include it. Does anybody know which MSC_VER MSVC 2.0 has ?
	inline void *operator new (unsigned int, void *p) { return p; }
#endif

#endif /* ACE_WIN32_COMMON_H */
