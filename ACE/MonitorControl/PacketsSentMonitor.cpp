// $Id$

#include "MonitorControl/PacketsSentMonitor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    PacketsSentMonitor<true>::PacketsSentMonitor (void)
      : MonitorPoint<true> ("PacketsSent")
    {}
  
    void
    PacketsSentMonitor<true>::update (void)
    {
      // TODO
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

