// -*- C++ -*-

//=============================================================================
/**
 *  @file ImplicitActivationStrategy.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_ACTIVATION_STRATEGY_H
#define TAO_ACTIVATION_STRATEGY_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "Policy_Strategy.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export ImplicitActivationStrategy
      : public virtual Policy_Strategy
    {
    public:
      virtual ~ImplicitActivationStrategy (void);

      virtual void strategy_init(TAO_POA *poa ACE_ENV_ARG_DECL);

      virtual void strategy_cleanup(ACE_ENV_SINGLE_ARG_DECL);

      virtual bool allow_implicit_activation (void) const = 0;
    };
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_ACTIVATION_STRATEGY_H */
