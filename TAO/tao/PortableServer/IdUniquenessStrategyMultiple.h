// -*- C++ -*-

//=============================================================================
/**
 *  @file IdUniquenessStrategyMultiple.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_ID_UNIQUENESSSTRATEGY_MULITPLE_H
#define TAO_ID_UNIQUENESSSTRATEGY_MULITPLE_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "IdUniquenessStrategy.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export IdUniquenessStrategyMultiple
      : public virtual IdUniquenessStrategy
    {
    public:
      virtual ~IdUniquenessStrategyMultiple (void);

      virtual void strategy_init(TAO_Root_POA *poa ACE_ENV_ARG_DECL);

      virtual void strategy_cleanup(ACE_ENV_SINGLE_ARG_DECL);

      virtual bool is_servant_activation_allowed (
        PortableServer::Servant servant,
        int &wait_occurred_restart_call);

      virtual bool allow_multiple_activations (void) const;
    };

    ACE_STATIC_SVC_DECLARE_EXPORT (TAO_PortableServer, IdUniquenessStrategyMultiple)
    ACE_FACTORY_DECLARE (TAO_PortableServer, IdUniquenessStrategyMultiple)
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_ID_UNIQUENESSSTRATEGY_MULITPLE_H */
