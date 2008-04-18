// $Id$

#include "ace/MC_Admin_Manager.h"

#if defined (ACE_ENABLE_MONITORS)

#include "ace/Service_Config.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace MonitorControl
  {
    MC_Admin&
    MC_Admin_Manager::admin (void)
    {
      return this->admin_;
    }
    
    int
    MC_Admin_Manager::Initializer (void)
    {
      return
        ACE_Service_Config::process_directive (ace_svc_desc_MC_ADMINMANAGER);
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DEFINE (MC_ADMINMANAGER,
                       ACE_TEXT ("MC_ADMINMANAGER"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (MC_ADMINMANAGER),
                       ACE_Service_Type::DELETE_THIS
                       | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (ACE, MC_ADMINMANAGER)
    
#endif /* ACE_ENABLE_MONITORS */

