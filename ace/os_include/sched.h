// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_sched.h
 *
 *  execution scheduling (REALTIME)
 *
 *  $Id$
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_SCHED_H
#define ACE_OS_INCLUDE_OS_SCHED_H

#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/time.h"

#if !defined (ACE_LACKS_SCHED_H)
# include /**/ <sched.h>
#endif /* !ACE_LACKS_SCHED_H */

#include "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_SCHED_H */
