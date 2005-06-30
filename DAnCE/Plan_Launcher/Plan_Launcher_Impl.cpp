// $Id$
#include "Plan_Launcher_Impl.h"
#include "orbsvcs/CosNamingC.h"
#include "Config_Handlers/XML_File_Intf.h"

#include <iostream>




namespace CIAO
{
  namespace Plan_Launcher
  {
    
    static CORBA::Object_ptr
    fetch_reference_naming (CORBA::ORB_ptr orb
                            ACE_ENV_ARG_DECL)
    {
      CORBA::Object_var tmp =
        orb->resolve_initial_references ("NameService"
                                         ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
      
      CosNaming::NamingContext_var pns =
        CosNaming::NamingContext::_narrow (tmp.in ()
                                           ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
      
      CosNaming::Name name (2);
      name.length (2);
      name[0].id =
        CORBA::string_dup ("CIAO");
      name[1].id =
        CORBA::string_dup ("ExecutionManager");
      
      return pns->resolve (name
                           ACE_ENV_ARG_PARAMETER);
    }

    Plan_Launcher_i::Plan_Launcher_i ()
      : em_ ()
    {
    }
    
    bool
    Plan_Launcher_i::init (const char *em_ior,
                         CORBA::ORB_ptr orb ACE_ENV_ARG_DECL)
    {
      CORBA::Object_var obj;
            
      if (em_ior == 0)
        {
          obj = fetch_reference_naming (orb ACE_ENV_ARG_PARAMETER);
          ACE_CHECK;
        }
      else
        {
          obj = orb->string_to_object (em_ior
                                       ACE_ENV_ARG_PARAMETER);
          ACE_CHECK;
        }
      
      this->em_ = ::CIAO::ExecutionManagerDaemon::_narrow (obj.in ()
                                                           ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
      
      if (CORBA::is_nil (this->em_.in ()))
        {
          ACE_ERROR ((LM_ERROR,
                          "(%P|%t) CIAO_PlanLauncher: nil Execution"
                          " Manager reference, narrow failed\n"));
          return false;
        }
      
      if (CIAO::debug_level () > 10)
        ACE_DEBUG ((LM_DEBUG,
                    "(%P|%t) CIAO_PlanLauncher: Obtained Execution"
                    " Manager ref \n"));
      
      return true;
    }
    
    
    const char * 
    Plan_Launcher_i::launch_plan (const char *plan_uri ACE_ENV_ARG_DECL)
    {
      CIAO::Config_Handlers::XML_File_Intf intf (plan_uri);
      
      ::Deployment::DeploymentPlan_var plan =
          intf.get_plan ();
      
      return this->launch_plan (plan.in ());
    }
    
    const char * 
    Plan_Launcher_i::launch_plan (const ::Deployment::DeploymentPlan &plan ACE_ENV_ARG_DECL)
    {
      if (CORBA::is_nil (this->em_.in ()))
        {
          ACE_ERROR ((LM_ERROR, 
                      ACE_TEXT ("CIAO::Plan_Launcher_i: ")
                      ACE_TEXT ("launch_plan called witn an uninitialized EM.\n")));            
          return 0;
        }
      
      ::Deployment::DomainApplicationManager_var dam (this->em_->preparePlan (plan, 1));
      
      if (CORBA::is_nil (dam.in ()))
        {
          ACE_DEBUG ((LM_DEBUG,
                      "(%P|%t) CIAO_PlanLauncher:preparePlan call failed: "
                      "nil DomainApplicationManager reference\n"));
          return 0;
        }
      
      if (CIAO::debug_level () > 10)
        ACE_DEBUG ((LM_DEBUG,
                    "CIAO_PlanLauncher: Obtained DAM ref \n"));
      
      ::Deployment::Properties_var properties;
      ACE_NEW_RETURN (properties,
                      Deployment::Properties,
                      0);
      
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG,
                    "CIAO_PlanLauncher: start Launch application..."));
      
      // Dont not start the Application immediately since it vialtes
      // the semantics of component activation sequence
      int start = 0;

      dam->startLaunch (properties.in (), 0);
      
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG, "[success]\n"));
      
      // Call finish Launch to complete the connections
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG,
                    "CIAO_PlanLauncher: finish Launch application..."));
      dam->finishLaunch (start);
      
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG, "[success]\n"));
      
      // Call start to activate components
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG,
                    "CIAO_PlanLauncher: start activating components..."));
      dam->start ();
      
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG, "[success]\n"));
      
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("CIAO_PlanLauncher: ")
                    ACE_TEXT ("Application Deployed successfully\n")));
      
      map_.bind_dam_reference (plan.UUID.in (),
                               Deployment::DomainApplicationManager::_duplicate (dam.in ()));

      return plan.UUID.in ();
    }
    
    ::Deployment::DomainApplicationManager_ptr 
    Plan_Launcher_i::get_dam (const char *uuid ACE_ENV_ARG_DECL)
    {
      if (!this->map_.is_plan_available (uuid))
        {
          // Note: we could do an exhaustive (and expensive!) search of the DAMS
          // on our EM at this point, if we wanted.  In most cases, though, this
          // would not produce a different result.
          return Deployment::DomainApplicationManager::_nil ();
        }
      return this->map_.fetch_dam_reference (uuid);
    }
    
    bool
    Plan_Launcher_i::teardown_plan (const char *uuid)
    {
      if (!this->map_.is_plan_available (uuid))
        return false;
      
      ::Deployment::DomainApplicationManager_var dapp_mgr 
          (this->map_.fetch_dam_reference (uuid));
      
      
      this->map_.unbind_dam (uuid);
      
      return true;
    }
    
    bool 
    Plan_Launcher_i::teardown_plan (::Deployment::DomainApplicationManager_ptr dam
                                  ACE_ENV_ARG_DECL)
    {
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG,
                    "CIAO_PlanLauncher: destroy the application....."));
      dam->destroyApplication ();
      
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG, "[success]\n"));

      this->destroy_dam (dam);      
      
      return true;
    }
    
    void 
    Plan_Launcher_i::destroy_dam (::Deployment::DomainApplicationManager_ptr dam
                                ACE_ENV_ARG_DECL)
    {
      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG,
                    "CIAO_PlanLauncher: destroy the manager....."));

      this->em_->destroyManager (dam);

      if (CIAO::debug_level ())
        ACE_DEBUG ((LM_DEBUG, "[success]\n"));
    }
    
  }
  
}
