// -*- C++ -*-

//=============================================================================
/**
 *  @file ImplicitActivationStrategyFactory.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_IMPLICITACTIVATIONSTRATEGYFACTORY_H
#define TAO_PORTABLESERVER_IMPLICITACTIVATIONSTRATEGYFACTORY_H
#include /**/ "ace/pre.h"

#include "tao/PortableServer/portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/StrategyFactory.h"
#include "tao/PortableServer/ImplicitActivationPolicyC.h"

namespace TAO
{
  namespace Portable_Server
  {
    class ImplicitActivationStrategy;

    class TAO_PortableServer_Export ImplicitActivationStrategyFactory
      : public virtual StrategyFactory
    {
    public:
      /// Create a new servant retention strategy
      virtual ImplicitActivationStrategy* create (
        ::PortableServer::ImplicitActivationPolicyValue value) = 0;
    };
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_IMPLICITACTIVATIONSTRATEGYFACTORY_H */
