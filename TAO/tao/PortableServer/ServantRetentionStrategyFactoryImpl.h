// -*- C++ -*-

//=============================================================================
/**
 *  @file ServantRetentionStrategyFactoryImpl.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_SERVANTRETENTIONSTRATEGYFACTORYIMPL_H
#define TAO_PORTABLESERVER_SERVANTRETENTIONSTRATEGYFACTORYIMPL_H
#include /**/ "ace/pre.h"

#include "tao/PortableServer/portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"
#include "tao/PortableServer/ServantRetentionStrategyFactory.h"

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export ServantRetentionStrategyFactoryImpl :
       public virtual ServantRetentionStrategyFactory
    {
    public:
      virtual ~ServantRetentionStrategyFactoryImpl (void);

      /// Create a new servant retention strategy
      virtual ServantRetentionStrategy* create (
        ::PortableServer::ServantRetentionPolicyValue value);
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, ServantRetentionStrategyFactoryImpl)
    ACE_FACTORY_DECLARE (TAO_PortableServer, ServantRetentionStrategyFactoryImpl)
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_SERVANTRETENTIONSTRATEGYFACTORYIMPL_H */
