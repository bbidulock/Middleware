// -*- C++ -*-

//=============================================================================
/**
 * @file MonitorGroup_T.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITORGROUP_T_H
#define MONITORGROUP_T_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Monitor_Base.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    template<bool ENABLED>
    class MonitorGroup : public Monitor_Base
    {
    public:
      MonitorGroup (const char* name);
    
      void add_member (Monitor_Base* member);
      
      virtual void update (void);
      
      virtual void constraint (const ETCL_Constraint* constraint);
      
      virtual void receive (double value);
      
      virtual void receive (size_t value);
      
      virtual void clear (void);
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "MonitorControl/MonitorGroup_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("MonitorGroup_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif // MONITORGROUP_T_H
