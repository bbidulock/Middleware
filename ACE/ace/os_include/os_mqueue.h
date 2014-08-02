// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_mqueue.h
 *
 *  message queues (REALTIME)
 *
 *  $Id$
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_MQUEUE_H
#define ACE_OS_INCLUDE_OS_MQUEUE_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_signal.h"

#if !defined (ACE_LACKS_MQUEUE_H)
# include /**/ <mqueue.h>
#endif /* !ACE_LACKS_MQUEUE_H */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_MQUEUE_H */
