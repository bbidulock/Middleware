#include "ThreadPolicy.h"
#include "PortableServer.h"

ACE_RCSID (PortableServer,
           ThreadPolicy,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    ThreadPolicy::ThreadPolicy ()
    {
    }

    void
    ThreadPolicy::init (
      const CORBA::Any &value ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::PolicyError))
    {
      ::PortableServer::ThreadPolicyValue thrvalue;
      if ((value >>= thrvalue) == 0)
        ACE_THROW (CORBA::PolicyError (CORBA::BAD_POLICY_VALUE));

      (void) this->init (thrvalue);
    }

    void
    ThreadPolicy::init (
      ::PortableServer::ThreadPolicyValue value)
    {
      value_ = value;
    }

    CORBA::Policy_ptr
    ThreadPolicy::copy (ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ThreadPolicy *copy = 0;
      ACE_NEW_THROW_EX (copy,
                        ThreadPolicy,
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (CORBA::Policy::_nil ());

      (void) copy->init (this->value_);

      return copy;
    }

    void
    ThreadPolicy::destroy (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
    }

    ::PortableServer::ThreadPolicyValue
    ThreadPolicy::value (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return value_;
    }

    CORBA::PolicyType
    ThreadPolicy::policy_type (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return ::PortableServer::THREAD_POLICY_ID;
    }

    TAO_Cached_Policy_Type
    ThreadPolicy::_tao_cached_type (void) const
    {
      return TAO_CACHED_POLICY_THREAD;
    }

    TAO_Policy_Scope
    ThreadPolicy::_tao_scope (void) const
    {
      return TAO_POLICY_POA_SCOPE;
    }

  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */
