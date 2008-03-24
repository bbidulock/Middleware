// -*- C++ -*-

//=============================================================================
/**
 * @file Message_Queue_Monitor.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MESSAGE_QUEUE_MONITOR_H
#define MESSAGE_QUEUE_MONITOR_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Size_Monitor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    class ACE_Export Message_Queue_Monitor : public Size_Monitor
    {
    public:
      Message_Queue_Monitor (void);
      Message_Queue_Monitor (const char* name);
      virtual ~Message_Queue_Monitor (void);
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif // MESSAGE_QUEUE_MONITOR_H
