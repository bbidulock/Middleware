// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_spawn.h
 *
 *  spawn (ADVANCED REALTIME)
 *
 *  $Id$
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_SPAWN_H
#define ACE_OS_INCLUDE_OS_SPAWN_H

#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/signal.h"
#include "ace/os_include/sys/types.h"
#include "ace/os_include/sched.h"

#if !defined (ACE_LACKS_SPAWN_H)
# include /**/ <spawn.h>
#endif /* !ACE_LACKS_SPAWN_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_SPAWN_H */
