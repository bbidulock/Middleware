// -*- C++ -*-

//=============================================================================
/**
 *  @file    fcntl.h
 *
 *  file control options
 *
 *  $Id$
 *
 *  @author Don Hinton <dhinton@ieee.org>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_FCNTL_H
#define ACE_OS_INCLUDE_FCNTL_H

#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/stat.h"
#include "ace/os_include/sys/types.h"

#if !defined (ACE_LACKS_FCNTL_H)
# include /**/ <fcntl.h>
#endif /* !ACE_LACKS_FCNTL_H */

#   if defined (__BORLANDC__)
#     define _O_CREAT O_CREAT
#     define _O_EXCL  O_EXCL
#     define _O_TRUNC O_TRUNC
      // 0x0800 is used for O_APPEND.  0x08 looks free.
#     define _O_TEMPORARY 0x08 /* see fcntl.h */
#     define _O_RDWR   O_RDWR
#     define _O_WRONLY O_WRONLY
#     define _O_RDONLY O_RDONLY
#     define _O_APPEND O_APPEND
#     define _O_BINARY O_BINARY
#     define _O_TEXT   O_TEXT
#   endif /* __BORLANDC__ */

#if defined (ACE_WIN32)
#  define O_NDELAY    1
#endif /* ACE_WIN32 */

# if defined (ACE_HAS_POSIX_NONBLOCK)
#   define ACE_NONBLOCK O_NONBLOCK
# else
#   define ACE_NONBLOCK O_NDELAY
# endif /* ACE_HAS_POSIX_NONBLOCK */

#include "ace/post.h"
#endif /* ACE_OS_INCLUDE_FCNTL_H */
