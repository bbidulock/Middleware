// -*- C++ -*-

//=============================================================================
/**
 * @file AutoUpdateStarter.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef AUTOUPDATESTARTER_H
#define AUTOUPDATESTARTER_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Task_T.h"

#include "MonitorControl/MonitorControl_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    /**
     * @class AutoUpdateStarter
     *
     * @brief Starts reactor event loop that handles registered timers.
     *
     * For all the monitors that are periodically updated, the reactor
     * event loop that calls their associated registered timers must
     * be started in a separate thread so the rest of the application
     * can run as well. A very simple struct inheriting from ACE_Task
     * and overriding the svc() method suffices.
     */
    struct MONITORCONTROL_Export AutoUpdateStarter : ACE_Task<ACE_NULL_SYNCH>
    {
      int svc (void);
    };
  }
}

typedef ACE::MonitorControl::AutoUpdateStarter STARTER;

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif // AUTOUPDATESTARTER_H
