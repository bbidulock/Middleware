// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_inet.h
 *
 *  definitions for internet operations
 *
 *  $Id$
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_ARPA_OS_INET_H
#define ACE_OS_INCLUDE_ARPA_OS_INET_H

#include /**/ "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/netinet/os_in.h"

#if !defined (ACE_LACKS_ARPA_INET_H)
   extern "C" {
#  include /**/ <arpa/inet.h>
   }
#endif /* !ACE_LACKS_ARPA_INET_H */

#if defined (VXWORKS)
#  include /**/ <inetLib.h>
#endif /* VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

// @todo move the ACE_HTONL, etc macros here

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_ARPA_OS_INET_H */
