#include "ImplicitActivationPolicyValueImplicit.h"
#include "ace/Dynamic_Service.h"

ACE_RCSID (PortableServer,
           ImplicitActivationPolicyValue,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    Implicit_Implicit_Activation_Policy::~Implicit_Implicit_Activation_Policy (void)
    {
    }

    ::PortableServer::ImplicitActivationPolicyValue
    Implicit_Implicit_Activation_Policy::policy_type (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
          ACE_THROW_SPEC ((CORBA::SystemException))
    {
      return ::PortableServer::IMPLICIT_ACTIVATION;
    }

    ACE_FACTORY_DEFINE (TAO_PortableServer, Implicit_Implicit_Activation_Policy)

    ACE_STATIC_SVC_DEFINE (
        Implicit_Implicit_Activation_Policy,
        ACE_TEXT ("Implicit_Implicit_Activation_Policy"),
        ACE_SVC_OBJ_T,
        &ACE_SVC_NAME (Implicit_Implicit_Activation_Policy),
        ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
        0
      )

    #if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

    template class ACE_Dynamic_Service<Implicit_Implicit_Activation_Policy>;

    #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

    #pragma instantiate ACE_Dynamic_Service<Implicit_Implicit_Activation_Policy>

    #endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */
