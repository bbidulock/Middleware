// $Id$

#include "ThreadPolicyFactory.h"
#include "ace/Dynamic_Service.h"
#include "ThreadPolicy.h"

ACE_RCSID (PortableServer,
           ThreadPolicyFactory,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace PortableServer
  {
    ThreadPolicyFactory::~ThreadPolicyFactory (void)
    {
    }

    ::PortableServer::ThreadPolicy_ptr
    ThreadPolicyFactory::create (
      ::PortableServer::ThreadPolicyValue value)
    {
      POA_ThreadPolicy* policy = 0;

      ACE_NEW_RETURN (policy,
                      POA_ThreadPolicy,
                      ::PortableServer::ThreadPolicy::_nil ());

      (void) policy->init (value);

      return policy;
    }

    ::PortableServer::ThreadPolicy_ptr
    ThreadPolicyFactory::create (
      const CORBA::Any &value
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::PolicyError))
    {
      POA_ThreadPolicy* policy = 0;

      ACE_NEW_RETURN (policy,
                      POA_ThreadPolicy,
                      ::PortableServer::ThreadPolicy::_nil ());

      (void) policy->init (value ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::PortableServer::ThreadPolicy::_nil ());

      return policy;
    }

    TAO_Cached_Policy_Type
    ThreadPolicyFactory::_tao_cached_type (void) const
    {
      return TAO_CACHED_POLICY_THREAD;
    }

    TAO_Policy_Scope
    ThreadPolicyFactory::_tao_scope (void) const
    {
      return TAO_POLICY_POA_SCOPE;
    }

    ACE_STATIC_SVC_DEFINE (
        ThreadPolicyFactory,
        ACE_TEXT ("ThreadPolicyFactory"),
        ACE_SVC_OBJ_T,
        &ACE_SVC_NAME (ThreadPolicyFactory),
        ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
        0
      )

    ACE_FACTORY_DEFINE (TAO_PortableServer, ThreadPolicyFactory)

    #if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

    template class ACE_Dynamic_Service<ThreadPolicyFactory>;

    #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

    #pragma instantiate ACE_Dynamic_Service<ThreadPolicyFactory>

    #endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

