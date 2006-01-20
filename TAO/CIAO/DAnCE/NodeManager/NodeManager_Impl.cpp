// $Id$

#include "NodeManager_Impl.h"
#include "../NodeApplicationManager/NodeApplicationManager_Impl.h"
#include "ace/Log_Msg.h"

CIAO::NodeManager_Impl_Base::NodeManager_Impl_Base (const char *name,
                                          CORBA::ORB_ptr orb,
                                          PortableServer::POA_ptr poa,
                                          const char * nodeapp_loc,
                                          const char * nodeapp_options,
                                          int spawn_delay)
  ACE_THROW_SPEC ((CORBA::SystemException))
  : orb_ (CORBA::ORB::_duplicate (orb)),
    poa_ (PortableServer::POA::_duplicate (poa)),
    name_ (CORBA::string_dup (name)),
    nodeapp_location_ (CORBA::string_dup (nodeapp_loc)),
    nodeapp_options_ (CORBA::string_dup (nodeapp_options)),
    callback_poa_ (PortableServer::POA::_nil ()),
    spawn_delay_ (spawn_delay)
{
}

CIAO::NodeManager_Impl_Base::~NodeManager_Impl_Base ()
{
}

void
CIAO::NodeManager_Impl_Base::init (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_TRY
    {
      //create the call back poa for NAM.
      PortableServer::POAManager_var mgr
        = this->poa_->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      this->callback_poa_ =
        this->poa_->create_POA ("callback_poa",
                                mgr.in (),
                                0
                                ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "NodeManager_Impl::init\t\n");
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
}

PortableServer::POA_ptr
CIAO::NodeManager_Impl_Base::_default_POA (void)
{
  return PortableServer::POA::_duplicate (this->poa_.in ());
}


char *
CIAO::NodeManager_Impl_Base::name (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::string_dup (this->name_.in ());
}

void
CIAO::NodeManager_Impl_Base::shutdown (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
CIAO::NodeManager_Impl_Base::joinDomain (const Deployment::Domain & ,
                                         Deployment::TargetManager_ptr ,
                                         Deployment::Logger_ptr
                                         ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

void
CIAO::NodeManager_Impl_Base::leaveDomain (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  //Implementation undefined.
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

const ::Components::FacetDescriptions &
CIAO::NodeManager_Impl_Base::
get_all_facets (ACE_CString & name)
{
  Component_Facets_Map::ENTRY *entry;
  this->comp_facets_map_.find (name.c_str (), entry);

  return entry->int_id_.in ();
}

const ::Components::ConsumerDescriptions &
CIAO::NodeManager_Impl_Base::
get_all_consumers (ACE_CString & name)
{
  Component_Consumers_Map::ENTRY *entry;
  this->comp_consumers_map_.find (name.c_str (), entry);

  return entry->int_id_.in ();
}

void
CIAO::NodeManager_Impl_Base::
set_all_facets (ACE_CString &name, 
                const ::Components::FacetDescriptions_var & facets)
{
  this->comp_facets_map_.bind (name, facets);
}

void
CIAO::NodeManager_Impl_Base::
set_all_consumers (ACE_CString &name, 
                   const ::Components::ConsumerDescriptions_var & consumers)
{
  this->comp_consumers_map_.bind (name, consumers);
}

Deployment::NodeApplicationManager_ptr
CIAO::NodeManager_Impl_Base::preparePlan (const Deployment::DeploymentPlan &plan
                                          ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StartError,
                   Deployment::PlanError))
{
  CIAO_TRACE("CIAO::NodeManager_Impl::preparePlan");

  if (! this->validate_plan (plan))
    {
      ACE_DEBUG ((LM_DEBUG, "(%P|%t) NodeManager <%s>:prepare_plan:Plan_Error.\n",
        plan.instance[0].node.in ()));
      ACE_DEBUG ((LM_DEBUG, "(%P|%t) All component instances hosted in the "
        "same component server must have the "
        "same \"resourceName\" defined.\n"));

      ACE_THROW_RETURN (Deployment::PlanError (),
                        Deployment::NodeApplicationManager::_nil ());
    }

  // Update the reference count map based on the deployment plan input
  for (CORBA::ULong i = 0; i < plan.instance.length (); ++i)
    {
      Reference_Count_Map::ENTRY *entry = 0;
      if (this->ref_count_map_.find (plan.instance[i].name.in (), entry) != 0)
        {
          // Initial ref count is set to "1"
          this->ref_count_map_.bind (plan.instance[i].name.in (), 1);
        }
      else
        {
          CORBA::ULong len = this->shared_components_.length ();
          shared_components_.length (len + 1);
          this->shared_components_[len] = plan.instance[i].name.in ();
          ++entry->int_id_; // increase ref count by 1
        }
    }

  // Create/find NodeApplicationManager and set/reset plan on it
  ACE_TRY
    {
      if (!this->map_.is_available (plan.UUID.in ()))
        {
          if (CIAO::debug_level () > 10)
            {
              ACE_DEBUG ((LM_DEBUG, "NM:prepare_plan: "
                          "creating a new NAM with UUID: %s\n",
                          plan.UUID.in ()));
            }

          //Implementation undefined.
          CIAO::NodeApplicationManager_Impl_Base *node_app_mgr;
          node_app_mgr = 
            this->create_node_app_manager (this->orb_.in (), this->poa_.in ()
                                           ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          PortableServer::ServantBase_var safe (node_app_mgr);

          //@@ Note: after the init call the servant ref count would
          //   become 2. so we can leave the safeservant along and be
          //   dead. Also note that I added
          PortableServer::ObjectId_var oid  =
            node_app_mgr->init (this->nodeapp_location_.in (),
                                this->nodeapp_options_.in (),
                                this->spawn_delay_,
                                plan,
                                this->callback_poa_.in (),
                                this // pass in a copy of ourself (servant object)
                                ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          this->map_.insert_nam (plan.UUID.in (), oid.in ());

          CORBA::Object_var obj =
            this->poa_->id_to_reference (this->map_.get_nam (plan.UUID.in ()));
          ACE_TRY_CHECK;

          // We should inform NAM about "shared" components, so they
          // won't be instantiated again
          Deployment::NodeApplicationManager_var nam =
            Deployment::NodeApplicationManager::_narrow (obj.in ());
          ACE_TRY_CHECK;

          nam->set_shared_components (this->shared_components_);
          ACE_TRY_CHECK;

          // narrow should return a nil reference if it fails.
          return Deployment::NodeApplicationManager::_narrow (nam.in ());
        }
      else
        {
          if (CIAO::debug_level () > 10)
            {
              ACE_DEBUG ((LM_DEBUG, "NM:prepare_plan: reusing an old NAM "
                          "with UUID: %s\n",
                          plan.UUID.in ()));
            }

          CORBA::Object_var obj =
            this->poa_->id_to_reference (this->map_.get_nam (plan.UUID.in ()));
          ACE_TRY_CHECK;

          Deployment::NodeApplicationManager_var nam =
            Deployment::NodeApplicationManager::_narrow (obj.in ());
          ACE_TRY_CHECK;

          nam->reset_plan (plan);
          ACE_TRY_CHECK;

          // Similarly, we should inform NAM about "shared" components, so 
          // they won't be instantiated again
          nam->set_shared_components (this->shared_components_);
          ACE_TRY_CHECK;

          // Potentially we could reset many other configuration settings
          // such as command line options, service configuration file, etc.
          return nam._retn ();
        }
    }
  ACE_CATCH (PortableServer::POA::ObjectNotActive, ex)
    {
      ACE_THROW_RETURN (Deployment::StartError (),
                        Deployment::NodeApplicationManager::_nil ());
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "(%P|%t) NodeManager_Impl::preparePlan\t\n");
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (Deployment::NodeApplicationManager::_nil ());

  return Deployment::NodeApplicationManager::_nil ();
}

void
CIAO::NodeManager_Impl_Base::destroyManager
        (Deployment::NodeApplicationManager_ptr manager
         ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StopError,
                   Deployment::InvalidReference))
{
  CIAO_TRACE("CIAO::NodeManager_Impl::destroyManager");
  ACE_TRY
    {
      // Deactivate this object
      PortableServer::ObjectId_var id =
        this->poa_->reference_to_id (manager
                                     ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (!this->map_.remove_nam (id.in ()))
        {
          ACE_ERROR ((LM_ERROR,
                      "NodeManager_Impl::destroyManager: "
                      "Unable to remove object from map!\n"));
        }

      this->poa_->deactivate_object (id.in ()
                                     ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCH (PortableServer::POA::WrongAdapter, ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "NodeManager_Impl::destroyManager: EXCEPTION -  "
                  "Invalid reference passed to destroyManager\n"));

      ACE_THROW (::Deployment::InvalidReference ());
    }
  ACE_CATCH (PortableServer::POA::ObjectNotActive, ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "NodeManager_Impl::destroyManager: EXCEPTION - "
                  " asked to destroy an already inactive object.\n"));
      ACE_THROW (::Deployment::InvalidReference ());
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "NodeManager_Impl::destroyManager\t\n");
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
}

void 
CIAO::NodeManager_Impl_Base::
destroyPlan (const Deployment::DeploymentPlan & plan
             ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((::CORBA::SystemException,
                   ::Deployment::StopError))
{
  // Update the reference counting map (subtract by 1 for each instance)
  // If the ref count becomes 0, then remove this component, otherwise,
  // we should remove the necesary bindings on this component specified
  // in the deployment plan.

  // Create a list of components that are not to be removed, and send
  // this list to the NAM, who will delegate to appropriate NAs to 
  // remove bindings from these components.

  // The problem is that we probably also want to call another NAM, which
  // manages the shared components in a different child plan. :(


  // Find the NAM from the map and invoke the destroyPlan() operation on
  // it, which will actuall remove components and connections in this plan.
  // If 
  CORBA::Object_var obj =
    this->poa_->id_to_reference (this->map_.get_nam (plan.UUID.in ()));
  ACE_TRY_CHECK;

  Deployment::NodeApplicationManager_var nam =
    Deployment::NodeApplicationManager::_narrow (obj.in ());
  ACE_TRY_CHECK;

  nam->destroyApplication (0);



  // The problem is that we should NOT actually kill the NA process if
  // there are some components that are shared by other plans.

}


bool
CIAO::NodeManager_Impl_Base::
validate_plan (const Deployment::DeploymentPlan &plan)
{
  const char * resource_id = 0;
  CORBA::ULong i = 0;

  for (i = 0; i < plan.instance.length (); ++i)
    {
      if (plan.instance[i].deployedResource.length () != 0)
        {
          // Since the "name" field represents the server_resource_id, and
          // the "resourceValue" field represents the policy_set_id, so we
          // are checking to make sure that all component instances have
          // the same server_resource_id.
          resource_id =
            plan.instance[i].deployedResource[0].resourceName.in ();
          break;
        }
    }
  if (i == plan.instance.length ()) // No server resource id has been set for any instance
    return true;

  for (i = 0; i < plan.instance.length (); ++i)
    {
      const char * my_resource_id = 0;
      if (plan.instance[i].deployedResource.length () == 0)
        {
          continue;
        }
      else
        {
          my_resource_id =
            plan.instance[i].deployedResource[0].resourceName.in ();;
          if (ACE_OS::strcmp (resource_id, my_resource_id) != 0)
            {
              // Error, inconsistent server resource id found.
              return false;
            }
        }
    }
  return true;
}

CIAO::NodeManager_Impl::~NodeManager_Impl ()
{
}

CIAO::NodeManager_Impl::
NodeManager_Impl (const char *name,
                 CORBA::ORB_ptr orb,
                 PortableServer::POA_ptr poa,
                 const char * nodeapp_loc,
                 const char * nodeapp_options,
                 int spawn_delay)
  : NodeManager_Impl_Base (name, orb, poa, nodeapp_loc, nodeapp_options, spawn_delay)
{}


::CIAO::NodeApplicationManager_Impl_Base *
CIAO::NodeManager_Impl::
create_node_app_manager (CORBA::ORB_ptr orb,
                         PortableServer::POA_ptr poa
                         ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CIAO::NodeApplicationManager_Impl_Base *app_mgr = 0;
  ACE_NEW_THROW_EX (app_mgr,
                    CIAO::NodeApplicationManager_Impl (orb,
                                                       poa),
                    CORBA::NO_MEMORY ());
  return app_mgr;
}

CIAO::Static_NodeManager_Impl::~Static_NodeManager_Impl ()
{
}

CIAO::Static_NodeManager_Impl::
Static_NodeManager_Impl (const char *name,
                        CORBA::ORB_ptr orb,
                        PortableServer::POA_ptr poa,
                        const char * nodeapp_loc,
                        const char * nodeapp_options,
                        int spawn_delay,
                        Static_Config_EntryPoints_Maps* static_config_entrypoints_maps)
  : NodeManager_Impl_Base (name, orb, poa, nodeapp_loc, nodeapp_options, spawn_delay),
    static_config_entrypoints_maps_ (static_config_entrypoints_maps)
{}

::CIAO::NodeApplicationManager_Impl_Base *
CIAO::Static_NodeManager_Impl::
create_node_app_manager (CORBA::ORB_ptr orb,
                         PortableServer::POA_ptr poa
                         ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_DEBUG ((LM_DEBUG, "creating static_node_app_manager\n"));
  CIAO::NodeApplicationManager_Impl_Base *app_mgr = 0;
  ACE_NEW_THROW_EX (app_mgr,
    CIAO::Static_NodeApplicationManager_Impl (orb,
      poa,
      this->static_config_entrypoints_maps_),
    CORBA::NO_MEMORY ());
  return app_mgr;
}

void
CIAO::Static_NodeManager_Impl::destroyManager
        (Deployment::NodeApplicationManager_ptr manager
         ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   Deployment::StopError,
                   Deployment::InvalidReference))
{
  CIAO_TRACE("CIAO::Static_NodeManager_Impl::destroyManager");
  ACE_TRY
    {
      CIAO::NodeManager_Impl_Base::destroyManager (manager ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Static_NodeManager_Impl::destroyManager\t\n");
      ACE_RE_THROW;
    }
  ACE_ENDTRY;

  ACE_CHECK;
}
