// -*- C++ -*-

//=============================================================================
/**
 *  @file ThreadStrategyFactoryImpl.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_SERVANTRETENTIONSTRATEGYRETAIN_FACTORYIMPL_H
#define TAO_PORTABLESERVER_SERVANTRETENTIONSTRATEGYRETAIN_FACTORYIMPL_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"
#include "tao/PortableServer/ServantRetentionStrategyFactory.h"

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export ServantRetentionStrategyRetainFactoryImpl
       : public virtual ServantRetentionStrategyFactory
    {
    public:
      virtual ~ServantRetentionStrategyRetainFactoryImpl (void);

      /// Create a new servant retention strategy
      virtual ServantRetentionStrategy* create (
        ::PortableServer::ServantRetentionPolicyValue value);

      virtual void destroy (ServantRetentionStrategy *strategy);
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, ServantRetentionStrategyRetainFactoryImpl)
    ACE_FACTORY_DECLARE (TAO_PortableServer, ServantRetentionStrategyRetainFactoryImpl)
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_SERVANTRETENTIONSTRATEGYRETAIN_FACTORYIMPL_H*/
