// -*- C++ -*-

//=============================================================================
/**
 *  @file    RequestProcessingStrategy.cpp
 *
 *  $Id$
 *
 */
//=============================================================================

#include "tao/Server_Strategy_Factory.h"
#include "tao/ORB_Core.h"
#include "tao/TSS_Resources.h"

#include "tao/PortableServer/ServantActivatorC.h"
#include "tao/PortableServer/ServantLocatorC.h"

#include "tao/PortableServer/RequestProcessingStrategy.h"
#include "tao/PortableServer/ServantRetentionStrategy.h"
#include "tao/PortableServer/LifespanStrategy.h"
#include "tao/PortableServer/Non_Servant_Upcall.h"
#include "tao/PortableServer/POA.h"
#include "tao/PortableServer/POA_Current_Impl.h"
#include "tao/PortableServer/Servant_Upcall.h"

ACE_RCSID (PortableServer,
           Request_Processing,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    RequestProcessingStrategy::~RequestProcessingStrategy()
    {
    }

    void
    RequestProcessingStrategy::strategy_init(TAO_POA *poa)
    {
      poa_ = poa;
      // dependent on type create the correct strategy.
    }
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

