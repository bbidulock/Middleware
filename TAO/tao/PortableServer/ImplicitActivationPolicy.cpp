#include "ImplicitActivationPolicy.h"
#include "PortableServer.h"

ACE_RCSID (PortableServer,
           ImplicitActivationPolicy,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    ImplicitActivationPolicy::ImplicitActivationPolicy ()
    {
    }

    void
    ImplicitActivationPolicy::init (
      const CORBA::Any &value ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::PolicyError))
    {
      ::PortableServer::ImplicitActivationPolicyValue thrvalue;
      if ((value >>= thrvalue) == 0)
        ACE_THROW (CORBA::PolicyError (CORBA::BAD_POLICY_VALUE));

      (void) this->init (thrvalue);
    }

    void
    ImplicitActivationPolicy::init (
      ::PortableServer::ImplicitActivationPolicyValue value)
    {
      value_ = value;
    }

    CORBA::Policy_ptr
    ImplicitActivationPolicy::copy (ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ImplicitActivationPolicy *copy = 0;
      ACE_NEW_THROW_EX (copy,
                        ImplicitActivationPolicy,
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (CORBA::Policy::_nil ());

      (void) copy->init (this->value_);

      return copy;
    }

    void
    ImplicitActivationPolicy::destroy (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
    }

    ::PortableServer::ImplicitActivationPolicyValue
    ImplicitActivationPolicy::value (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return value_;
    }

    CORBA::PolicyType
    ImplicitActivationPolicy::policy_type (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return ::PortableServer::IMPLICIT_ACTIVATION_POLICY_ID;
    }

    TAO_Cached_Policy_Type
    ImplicitActivationPolicy::_tao_cached_type (void) const
    {
      return TAO_CACHED_POLICY_IMPLICIT_ACTIVATION;
    }

    TAO_Policy_Scope
    ImplicitActivationPolicy::_tao_scope (void) const
    {
      return TAO_POLICY_POA_SCOPE;
    }
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */
