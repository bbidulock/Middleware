// -*- C++ -*-
//
// $Id$

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace Portable_Server
  {
    ACE_INLINE
    ThreadStrategy*
    Active_Policy_Strategies::thread_strategy (void) const
    {
      return this->thread_strategy_;
    }

    ACE_INLINE
    RequestProcessingStrategy*
    Active_Policy_Strategies::request_processing_strategy (void) const
    {
      return this->request_processing_strategy_;
    }

    ACE_INLINE
    IdAssignmentStrategy *
    Active_Policy_Strategies::id_assignment_strategy (void) const
    {
      return this->id_assignment_strategy_;
    }

    ACE_INLINE
    IdUniquenessStrategy *
    Active_Policy_Strategies::id_uniqueness_strategy (void) const
    {
      return this->id_uniqueness_strategy_;
    }

    ACE_INLINE
    LifespanStrategy*
    Active_Policy_Strategies::lifespan_strategy (void) const
    {
      return this->lifespan_strategy_;
    }

    ACE_INLINE
    ImplicitActivationStrategy*
    Active_Policy_Strategies::implicit_activation_strategy (void) const
    {
      return this->implicit_activation_strategy_;
    }

    ACE_INLINE
    ServantRetentionStrategy*
    Active_Policy_Strategies::servant_retention_strategy (void) const
    {
      return this->servant_retention_strategy_;
    }
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL
