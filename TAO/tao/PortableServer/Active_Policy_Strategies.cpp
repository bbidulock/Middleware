// @(#) $Id$

#include "Active_Policy_Strategies.h"
#include "POA_Cached_Policies.h"
#include "IdAssignmentPolicyC.h"
#include "IdUniquenessPolicyC.h"
#include "ImplicitActivationPolicyC.h"
#include "LifespanPolicyC.h"
#include "RequestProcessingPolicyC.h"
#include "ServantRetentionPolicyC.h"
#include "ThreadPolicyC.h"

#include "Thread_Strategy.h"
#include "Request_Processing_Strategy.h"

ACE_RCSID(PortableServer,
          Active_Policy_Strategies,
          "$Id$")

namespace TAO
{
  namespace Portable_Server
  {
    Active_Policy_Strategies::Active_Policy_Strategies() :
      thread_strategy_(0),
      request_processing_strategy_(0)
    {
    }

    void
    Active_Policy_Strategies::update (Cached_Policies &policies
                                      ACE_ENV_ARG_DECL)
    {
      // This has to changed into having a factory that checks this and loads the correct strategy
      if (policies.thread() == ::PortableServer::ORB_CTRL_MODEL)
      {
        ACE_NEW (thread_strategy_, ORBControl_Thread_Strategy);
      }
      else
      {
        ACE_NEW (thread_strategy_, Single_Thread_Strategy);
      }

      switch (policies.request_processing())
      {
        case ::PortableServer::USE_ACTIVE_OBJECT_MAP_ONLY :
        {
          ACE_NEW (request_processing_strategy_, AOM_Only_Request_Processing_Strategy);
          break;
        }
        case ::PortableServer::USE_DEFAULT_SERVANT :
        {
          ACE_NEW (request_processing_strategy_, Default_Servant_Request_Processing_Strategy);
          break;
        }
        case ::PortableServer::USE_SERVANT_MANAGER :
        {
          switch (policies.servant_retention())
          {
            case ::PortableServer::RETAIN :
            {
              ACE_NEW (request_processing_strategy_, Servant_Activator_Request_Processing_Strategy);
              break;
            }
            case ::PortableServer::NON_RETAIN :
            {
              ACE_NEW (request_processing_strategy_, Servant_Locator_Request_Processing_Strategy);
              break;
            }
          }
          break;
        }
      }
    }

    Thread_Strategy*
    Active_Policy_Strategies::thread_strategy (void) const
    {
      return thread_strategy_;
    }

    Request_Processing_Strategy*
    Active_Policy_Strategies::request_processing_strategy (void) const
    {
      return request_processing_strategy_;
    }

  }
}
