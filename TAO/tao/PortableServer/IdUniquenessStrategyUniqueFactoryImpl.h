// -*- C++ -*-

//=============================================================================
/**
 *  @file ThreadStrategySingleFactoryImpl.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_IDUNIQUENESSSTRATEGYUNIQUEFACTORYIMPL_H
#define TAO_PORTABLESERVER_IDUNIQUENESSSTRATEGYUNIQUEFACTORYIMPL_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"
#include "IdUniquenessStrategyFactory.h"

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export IdUniquenessStrategyUniqueFactoryImpl
      : public virtual IdUniquenessStrategyFactory
    {
    public:
      virtual ~IdUniquenessStrategyUniqueFactoryImpl (void);

      /// Create a new  strategy
      virtual IdUniquenessStrategy* create (
        ::PortableServer::IdUniquenessPolicyValue value);

      virtual void destroy (
        IdUniquenessStrategy *strategy
        ACE_ENV_ARG_DECL);
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, IdUniquenessStrategyUniqueFactoryImpl)
    ACE_FACTORY_DECLARE (TAO_PortableServer, IdUniquenessStrategyUniqueFactoryImpl)
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_IDUNIQUENESSSTRATEGYUNIQUEFACTORYIMPL_H */
