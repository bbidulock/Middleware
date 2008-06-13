// -*- C++ -*-

//=============================================================================
/**
 * @file Linux_Network_Interface_Monitor.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef LINUXNETWORKINTERFACEMONITOR_H
#define LINUXNETWORKINTERFACEMONITOR_H

#include /**/ "ace/pre.h"

#include "ace/SString.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Monitor_Control/Monitor_Control_export.h"

#if defined (linux) || defined (AIX)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    /**
     * @class Linux_Network_Interface_Monitor
     *
     * @brief Mixin class for network interface monitors compiled on
     *        Linux machines.
     */
    class MONITOR_CONTROL_Export Linux_Network_Interface_Monitor
    {
    protected:
      /// The Linux system file /proc/net/dev stores a wealth of
      /// network information about the system. To get the specific
      /// value we want to monitor, we just vary the scan format string.
      Linux_Network_Interface_Monitor (const char *scan_format);

      /// Platform-specific implementation.
      void update_i (void);

    protected:
      ACE_UINT64 value_;

    private:
      static const unsigned long MAX_INTERFACES = 10UL;
      ACE_UINT64 value_array_[MAX_INTERFACES];
      ACE_UINT64 start_;
      ACE_CString scan_format_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (linux) || defined (AIX) */

#include /**/ "ace/post.h"

#endif // LINUXNETWORKINTERFACEMONITOR_H
