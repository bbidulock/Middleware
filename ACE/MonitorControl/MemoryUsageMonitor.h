// -*- C++ -*-

//=============================================================================
/**
 * @file MemoryUsageMonitor.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MEMORYUSAGEMONITOR_H
#define MEMORYUSAGEMONITOR_H

#include /**/ "ace/pre.h"

#include "ace/Monitor_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_ENABLE_MONITORS)

#if defined (ACE_WIN32)
#include "MonitorControl/WindowsMonitor.h"
#elif defined (linux)
#include <sys/sysinfo.h>
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    /**
     * @class MemoryUsageMonitor
     *
     * @brief Monitor percentage of total available memory used.
     */
    class MONITORCONTROL_Export MemoryUsageMonitor
      : public Monitor_Base
#if defined (ACE_WIN32)
      , public WindowsMonitor
#endif
    {
    public:
      MemoryUsageMonitor (void);
    
      /// Implementation of the pure virtual method.
      virtual void update (void);
      
    private:
#if defined (linux)
      struct sysinfo sysinfo_;
#elif defined (ACE_HAS_KSTAT)
#endif
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_ENABLE_MONITORS */

#include /**/ "ace/post.h"

#endif // MEMORYUSAGEMONITOR_H
