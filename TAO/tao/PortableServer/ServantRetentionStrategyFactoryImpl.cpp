// $Id$

#include "ServantRetentionStrategyFactoryImpl.h"
#include "ace/Dynamic_Service.h"
#include "ServantRetentionStrategyRetain.h"
#include "ServantRetentionStrategyNonRetain.h"

ACE_RCSID (PortableServer,
           ServantRetentionStrategyFactoryImpl,
           "$Id$")

namespace TAO
{
  namespace Portable_Server
  {
    ServantRetentionStrategyFactoryImpl::~ServantRetentionStrategyFactoryImpl (void)
    {
    }
    ServantRetentionStrategy*
    ServantRetentionStrategyFactoryImpl::create (
      ::PortableServer::ServantRetentionPolicyValue value)
    {
      ServantRetentionStrategy* strategy = 0;

      switch (value)
      {
        case ::PortableServer::RETAIN :
        {
          ACE_NEW_RETURN (strategy, ServantRetentionStrategyRetain, 0);
          break;
        }
        case ::PortableServer::NON_RETAIN :
        {
#if (TAO_HAS_MINIMUM_POA == 0)
          ACE_NEW_RETURN (strategy, ServantRetentionStrategyNonRetain, 0);
#endif /* TAO_HAS_MINIMUM_POA == 0 */
          break;
        }
      }

      return strategy;
    }

    ACE_STATIC_SVC_DEFINE (
        ServantRetentionStrategyFactoryImpl,
        ACE_TEXT ("ServantRetentionStrategyFactory"),
        ACE_SVC_OBJ_T,
        &ACE_SVC_NAME (ServantRetentionStrategyFactoryImpl),
        ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
        0
      )

    ACE_FACTORY_DEFINE (TAO_PortableServer, ServantRetentionStrategyFactoryImpl)

    #if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
    template class ACE_Dynamic_Service<ServantRetentionStrategyFactoryImpl>;
    #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
    #pragma instantiate ACE_Dynamic_Service<ServantRetentionStrategyFactoryImpl>
    #endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
  }
}

