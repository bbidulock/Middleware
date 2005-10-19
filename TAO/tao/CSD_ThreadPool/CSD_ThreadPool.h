// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file    CSD_Threadpool.h
 *
 *  $Id$
 *
 *  @author  Tim Bradley <bradley_t@ociweb.com>
 */
//=============================================================================

#ifndef TAO_CSD_THREADPOOL_H
#define TAO_CSD_THREADPOOL_H

#include /**/ "ace/pre.h"

#include "CSD_TP_Export.h"
#include "ace/Service_Object.h"
#include "ace/Service_Config.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class TP_Strategy_Factory
 *
 * @brief An ACE_Service_Object capable of creating TP_Strategy objects.
 *
 * TBD - Explain in more detail.
 *
 */
class TAO_CSD_TP_Export TAO_CSD_ThreadPool
{
 public:
  /// Used to force the initialization of the ORB code.
  static int init (void);
};

#if defined(ACE_HAS_BROKEN_STATIC_CONSTRUCTORS)

typedef int (*TAO_CSD_Threadpool) (void);

static TAO_CSD_Threadpool
TAO_Requires_CSD_Threadpool =
  &TAO_CSD_ThreadPool::init;

#else

static int
TAO_Requires_CSD_Threadpool =
  TAO_CSD_ThreadPool::init ();

#endif /* ACE_HAS_BROKEN_STATIC_CONSTRUCTORS */

#include /**/ "ace/post.h"

#endif /* TAO_CSD_THREADPOOL_H */
