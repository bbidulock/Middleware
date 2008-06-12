// -*- C++ -*-

//=============================================================================
/**
 * @file Windows_Monitor.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef WINDOWS_MONITOR_H
#define WINDOWS_MONITOR_H

#include /**/ "ace/pre.h"

#include "ace/Monitor_Control/Monitor_Control_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_pdh.h"

#if defined (ACE_HAS_WIN32_PDH)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Windows_Monitor
     *
     * @brief Mixin class for concrete monitors compiled on Windows machines.
     */
    class MONITOR_CONTROL_Export Windows_Monitor
    {
      friend class Windows_Multi_Instance_Monitor;

    protected:
      Windows_Monitor (const ACE_TCHAR *path);

      /// Platform-specific implementation.
      void update_i (void);

    protected:
      PDH_FMT_COUNTERVALUE pdh_value_;
      double value_;

    /// Make these persistent as members so they don't have to be
    /// created & destroyed with each update.
    private:
      HQUERY query_;
      HCOUNTER counter_;
      PDH_STATUS status_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* defined (ACE_HAS_WIN32_PDH) */

#endif // WINDOWS_MONITOR_H
