#include "tao/DiffServPolicy/DiffServPolicy_Factory.h"

ACE_RCSID (DiffServPolicy,
           DiffServPolicy_Factory,
           "$Id$")

#include "tao/DiffServPolicy/Client_Network_Priority_Policy.h"
#include "tao/DiffServPolicy/Server_Network_Priority_Policy.h"
#include "tao/PolicyC.h"
#include "tao/ORB_Constants.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

CORBA::Policy_ptr
TAO_DiffServ_PolicyFactory::create_policy (
    CORBA::PolicyType type,
    const CORBA::Any &value)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   CORBA::PolicyError))
{
  if (type == TAO::CLIENT_NETWORK_PRIORITY_TYPE)
    return TAO_Client_Network_Priority_Policy::create (value);

  if (type == TAO::NETWORK_PRIORITY_TYPE)
    return TAO_Server_Network_Priority_Policy::create (value);

  ACE_THROW_RETURN (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE),
                    CORBA::Policy::_nil ());
}

CORBA::Policy_ptr
TAO_DiffServ_PolicyFactory::_create_policy (CORBA::PolicyType type)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   CORBA::PolicyError))
{
  CORBA::Policy_ptr policy = CORBA::Policy::_nil ();

  if (type == TAO::CLIENT_NETWORK_PRIORITY_TYPE)
    {
      ACE_NEW_THROW_EX (policy,
                        TAO_Client_Network_Priority_Policy (),
                        CORBA::NO_MEMORY (
                          CORBA::SystemException::_tao_minor_code (
                            TAO::VMCID,
                            ENOMEM),
                          CORBA::COMPLETED_NO));

      return policy;
    }

  if (type == TAO::NETWORK_PRIORITY_TYPE)
    {
      ACE_NEW_THROW_EX (policy,
                        TAO_Server_Network_Priority_Policy (),
                        CORBA::NO_MEMORY (
                          CORBA::SystemException::_tao_minor_code (
                            TAO::VMCID,
                            ENOMEM),
                          CORBA::COMPLETED_NO));

      return policy;
    }

  ACE_THROW_RETURN (CORBA::PolicyError (CORBA::BAD_POLICY_TYPE),
                    CORBA::Policy::_nil ());
}

TAO_END_VERSIONED_NAMESPACE_DECL
