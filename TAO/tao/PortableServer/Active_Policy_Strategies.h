// -*- C++ -*-

//=============================================================================
/**
 *  @file Active_Policy_Strategies.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_ACTIVE_POLICY_STRATEGIES_H
#define TAO_PORTABLESERVER_ACTIVE_POLICY_STRATEGIES_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/CORBA_macros.h"
#include "tao/Environment.h"

class TAO_Root_POA;

namespace TAO
{
  namespace Portable_Server
  {
    class Cached_Policies;
    class ThreadStrategy;
    class RequestProcessingStrategy;
    class IdAssignmentStrategy;
    class LifespanStrategy;
    class IdUniquenessStrategy;
    class ImplicitActivationStrategy;
    class ServantRetentionStrategy;

    class ThreadStrategyFactory;

    /**
     * This class stores the active policy strategies used for a certain POA.
     */
    class TAO_PortableServer_Export Active_Policy_Strategies
    {
    public:
      Active_Policy_Strategies();

      void update (Cached_Policies &policies,
                   TAO_Root_POA* poa
                   ACE_ENV_ARG_DECL);

      void cleanup (ACE_ENV_SINGLE_ARG_DECL);

      ThreadStrategy *thread_strategy (void) const;

      RequestProcessingStrategy *request_processing_strategy (void) const;

      IdAssignmentStrategy *id_assignment_strategy (void) const;

      IdUniquenessStrategy *id_uniqueness_strategy (void) const;

      LifespanStrategy *lifespan_strategy (void) const;

      ImplicitActivationStrategy *implicit_activation_strategy (void) const;

      ServantRetentionStrategy *servant_retention_strategy (void) const;

    private:
      ThreadStrategy *thread_strategy_;
      RequestProcessingStrategy *request_processing_strategy_;
      IdAssignmentStrategy *id_assignment_strategy_;
      LifespanStrategy *lifespan_strategy_;
      IdUniquenessStrategy *id_uniqueness_strategy_;
      ImplicitActivationStrategy *implicit_activation_strategy_;
      ServantRetentionStrategy *servant_retention_strategy_;

      ThreadStrategyFactory *thread_strategy_factory_;
    };
  }
}

#if defined (__ACE_INLINE__)
# include "Active_Policy_Strategies.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* TAO_PORTABLESERVER_ACTIVE_POLICY_STRATEGIES_H */
