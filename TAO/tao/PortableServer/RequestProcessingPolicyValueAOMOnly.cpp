#include "RequestProcessingPolicyValueAOMOnly.h"
#include "ace/Dynamic_Service.h"

ACE_RCSID (PortableServer,
           RequestProcessingPolicyValue,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    RequestProcessingPolicyValueAOMOnly::~RequestProcessingPolicyValueAOMOnly (void)
    {
    }

    ::PortableServer::RequestProcessingPolicyValue
    RequestProcessingPolicyValueAOMOnly::policy_type (void)
    {
      return ::PortableServer::USE_ACTIVE_OBJECT_MAP_ONLY;
    }

    ACE_FACTORY_DEFINE (TAO_PortableServer, RequestProcessingPolicyValueAOMOnly)

    ACE_STATIC_SVC_DEFINE (
        RequestProcessingPolicyValueAOMOnly,
        ACE_TEXT ("RequestProcessingPolicyValueAOMOnly"),
        ACE_SVC_OBJ_T,
        &ACE_SVC_NAME (RequestProcessingPolicyValueAOMOnly),
        ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
        0
      )

    #if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

    template class ACE_Dynamic_Service<RequestProcessingPolicyValueAOMOnly>;

    #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

    #pragma instantiate ACE_Dynamic_Service<RequestProcessingPolicyValueAOMOnly>

    #endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */
