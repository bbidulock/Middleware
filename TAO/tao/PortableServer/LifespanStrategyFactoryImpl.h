// -*- C++ -*-

//=============================================================================
/**
 *  @file LifespanStrategyFactoryImpl.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_LIFEPSPANSTRATEGYFACTORYIMPL_H
#define TAO_PORTABLESERVER_LIFEPSPANSTRATEGYFACTORYIMPL_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Config.h"
#include "LifespanStrategyFactory.h"

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export LifespanStrategyFactoryImpl
      : public virtual LifespanStrategyFactory
    {
    public:
      virtual ~LifespanStrategyFactoryImpl (void);

      /// Create a new servant retention strategy
      virtual LifespanStrategy* create (
        ::PortableServer::LifespanPolicyValue value);
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, LifespanStrategyFactoryImpl)
    ACE_FACTORY_DECLARE (TAO_PortableServer, LifespanStrategyFactoryImpl)
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_LIFEPSPANSTRATEGYFACTORYIMPL_H */
