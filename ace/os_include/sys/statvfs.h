// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_statvfs.h
 *
 *  VFS File System information structure
 *
 *  $Id$
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_STATVFS_H
#define ACE_OS_INCLUDE_SYS_OS_STATVFS_H

#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/types.h"

#if !defined (ACE_LACKS_SYS_STATVFS_H)
#  include /**/ <sys/statvfs.h>
#endif /* !ACE_LACKS_SYS_STATVFS_H */

#include "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_STATVFS_H */
