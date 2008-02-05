// $Id$

#include "ace/Monitor_Point_Registry.h"
#include "ace/Singleton.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    Monitor_Point_Registry*
    Monitor_Point_Registry::instance (void)
    {
      return
        ACE_Singleton<Monitor_Point_Registry, ACE_Null_Mutex>::instance ();
      /// @@@ (JP) We may need to use ACE_Recursive_Thread_Mutex instead.
    }
    
    Monitor_Point_Registry::Monitor_Point_Registry (void)
    {}
    
    Monitor_Point_Registry::~Monitor_Point_Registry (void)
    {}
    
    Monitor_Base*
    Monitor_Point_Registry::get (const ACE_CString& name) const
    {
      // TODO
      return 0;
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

