// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Admin.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITOR_ADMIN_H
#define MONITOR_ADMIN_H

#include /**/ "ace/pre.h"

#include "ace/Event_Handler.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK)

#include "ace/Monitor_Base.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    class MonitorQuery;

    /**
     * @class MonitorPointAutoUpdater
     *
     * @brief Automates periodic updating of monitor point classes.
     *
     * A single instance of this class is held by the Admin
     * class below. For a monitor point that must periodically
     * check what they are monitoring, the admin class registers
     * the monitor point with the ACE reactor. Each time the
     * interval times out, the reactor will call the
     * handle_timeout() method below, and pass in the appropriate
     * monitor point. The handle_timeout() method will in turn
     * call the appropriate method on the monitor point to get
     * it to update its data.
     */
    struct MonitorPointAutoUpdater : ACE_Event_Handler
    {
      /// Override of ACE base class method.
      virtual int handle_timeout (const ACE_Time_Value& interval,
                                  const void* monitor_point);
    };

    /**
     * @class Admin
     *
     * @brief Accesses monitor points or groups and manages the registries.
     *
     * Responsible for adding and removing monitor points and control
     * actions to/form their respective global registries. If
     * add_monitor_point() is called with a non-zero auto_update_msec
     * arg, the monitor point will get registered with the reactor, which
     * will prompt it to automatically update its data.
     */
    class ACE_Export MC_Admin
    {
    public:
      MC_Admin (void);
      ~MC_Admin (void);

      /// Add or access monitor points in a global registry
      /// If the auto_update_msec arg is non-zero,
      /// the monitor point, the auto updater member, and the given time
      /// interval are passed to our reactor's register_timeout()
      /// method.

      bool monitor_point (Monitor_Base* monitor_point,
                          const ACE_Time_Value& time);
      Monitor_Base* monitor_point (const char* name);

      /// Works similarly to monitor_point() above, but registers our
      /// auto_query_ member's handle_timeout() method with the reactor,
      /// instead of our auto_updater_'s handle_timeout().
      void auto_query (ACE_Event_Handler* handler,
                       MonitorQuery* query,
                       const ACE_Time_Value& time);

      /// Resets the monitor points found in the registry by
      /// lookup of the passed list of names.
      void clear_statistics (const Monitor_Control_Types::NameList& names);

      /// Called from the application to manually update the monitor points
      /// (or group) specified in @a names. The boolean parameter specifies
      /// whether or not some action should be triggered (constraint check,
      /// logging, or some other action).
      void update_monitors (const Monitor_Control_Types::NameList& names,
                            bool notify);

      /// This mutator allows the application to create its own reactor
      /// and substitute it for the default reactor.
      void reactor (ACE_Reactor* new_reactor);
      ACE_Reactor* reactor (void) const;

    private:
      MonitorPointAutoUpdater auto_updater_;
      ACE_Reactor* reactor_;
      bool default_reactor_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_MONITOR_FRAMEWORK*/

#include /**/ "ace/post.h"

#endif // MONITOR_ADMIN_H
