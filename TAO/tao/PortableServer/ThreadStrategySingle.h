// -*- C++ -*-

//=============================================================================
/**
 *  @file ThreadStrategySingle.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_THREADSTRATEGYSINGLE_H
#define TAO_THREADSTRATEGYSINGLE_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "ThreadStrategy.h"
#include "ace/Service_Config.h"

// Locking
#include "ace/Synch_Traits.h"
#include "ace/Thread_Mutex.h"
#include "ace/Recursive_Thread_Mutex.h"
#include "ace/Null_Mutex.h"

#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export ThreadStrategySingle :
       public virtual ThreadStrategy
    {
    public:
      virtual ~ThreadStrategySingle (void);

      virtual int enter ();

      virtual int exit ();

    private:
      TAO_SYNCH_RECURSIVE_MUTEX lock_;
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, ThreadStrategySingle)
    ACE_FACTORY_DECLARE (TAO_PortableServer, ThreadStrategySingle)
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_THREADSTRATEGYSINGLE_H */
