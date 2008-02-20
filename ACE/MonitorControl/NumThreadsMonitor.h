// -*- C++ -*-

//=============================================================================
/**
 * @file NumThreadsMonitor.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef NUMTHREADSMONITOR_H
#define NUMTHREADSMONITOR_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "MonitorControl/LowLevelMonitors_T.h"
#include "MonitorControl/MonitorPoint.h"

#if defined (ACE_WIN32)
#include "MonitorControl/WindowsMonitor.h"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    /**
     * @note This file contains a class declarations for a specialized monitor
     *       point we will want to have at the OS level. In the
     *       enabled ("true") versions, the virtual update() method
     *       is implemented with the appropriate behavior, while in the
     *       disabled ("false") versions, it is implemented as a no-op,
     *       so the compiler may optimize it away. The purpose of the
     *       class should be self-evident from its name.
     */

    /**
     * @class NumThreadsMonitor
     *
     * @brief Template specialization with meaningful implementation of
     * pure virtual method.
     */
    template<>
    class MONITORCONTROL_Export NumThreadsMonitor<true>
      : public MonitorPoint<true>
#if defined (ACE_WIN32)
      , public WindowsMonitor
#endif
    {
    public:
      NumThreadsMonitor (void);
    
      /// Implementation of the pure virtual method.
      virtual void update (void);
      
    private:
#if defined (linux)
      FILE *file_ptr_;
      char buf_[1024];
      unsigned long nthreads_;
#endif
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif // NUMTHREADSMONITOR_H
