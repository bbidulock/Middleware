// $Id$

// -*- C++ -*-

//=============================================================================
/**
 *  @file    NodeApplicationManager_Impl.h
 *
 *  @author  Tao Lu <lu@dre.vanderbilt.edu>
 *  @author  Gan Deng <dengg@dre.vanderbilt.edu>
 *
 *  This file contains implementation for the servant of
 *  Deployment::NodeApplicationManager.
 */
//=============================================================================


#ifndef CIAO_NODEAPPLICATIONMANAGER_IMPL_H
#define CIAO_NODEAPPLICATIONMANAGER_IMPL_H
#include /**/ "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ciao/NodeApp_CB_Impl.h"
#include "ciao/DeploymentS.h"
#include "ciao/CIAO_common.h"
#include "CIAO_NAM_Export.h"
#include "ImplementationInfo.h"
#include "NodeManager/NodeManager_Impl.h"
#include "NodeApplication/NodeApplication_Core.h"

namespace CIAO
{
  /**
   * @class NodeApplicationManager_Impl_Base
   */
  class CIAO_NAM_Export NodeApplicationManager_Impl_Base
    : public virtual POA_Deployment::NodeApplicationManager
  {
  public:
    /// Constructor
    NodeApplicationManager_Impl_Base (CORBA::ORB_ptr o,
                                      PortableServer::POA_ptr p);

    /*===========================================================
     * Below are operations from the NodeApplicationManager
     *
     *============================================================*/

    /// The return type is NodeApplication_ptr actually.
    /// For "external/shared" components of this child plan, they are
    /// not actaully installed, however, the object references
    /// of the ports of these external components are returned
    /// through <providedReference>.
    virtual Deployment::Application_ptr
    startLaunch (const Deployment::Properties & configProperty,
                 Deployment::Connections_out providedReference,
                 CORBA::Boolean start
                 ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                              Deployment::ResourceNotAvailable,
                              Deployment::StartError,
                              Deployment::InvalidProperty));

    //@@ Destroy the whole applicaton.
    virtual void destroyApplication (Deployment::Application_ptr
                                     ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                              Deployment::StopError));

    virtual Deployment::Application_ptr
    perform_redeployment (const Deployment::Properties & configProperty,
                          Deployment::Connections_out providedReference,
                          CORBA::Boolean add_or_remove,
                          CORBA::Boolean start
                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::Deployment::PlanError,
                       ::Deployment::InstallationFailure,
                       ::Deployment::UnknownImplId,
                       ::Deployment::ImplEntryPointNotFound,
                       ::Deployment::InvalidConnection,
                       ::Deployment::InvalidProperty,
                       ::Components::RemoveFailure));

    virtual void
    reset_plan (const ::Deployment::DeploymentPlan & plan
                ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException));

    virtual void
    set_shared_components (const Deployment::ComponentPlans & shared
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((::CORBA::SystemException));

    /**
     * A factory operation to create NodeApplicationManager interface, and return
     * the object reference.
     * Initialize the NodeApplicationManager.  The current implementation
     * of CIAO_NodeApplicationManager can only activate CIAO's own
     * NodeApplication processes.  You should specify the location
     * (pathname) of the NodeApplication and the delay.
     * CIAO_NodeApplicationManager should wait (in second) for NodeApplication to
     * call back.
     *
     * @param nodeapp_location A null-termiated char * string pointing
     *    to the pathname of a NodeApplication executable.
     *
     * @param nodeapp_options A null-terminated char * string
     * containing command line options to be passed to the
     * NodeApplication.
     *
     * @param delay instructs how long (in second) a CIAO_NodeApplicationManager
     *   should wait for a newly spawned NodeApplication to pass back
     *   its IOR.
     *
     * @param plan has all the information needed for the NodeAppManager to
     *        construct the application locally. Note, this includes the properties
     *        of the NodeApplication. For example, ORB config options etc.
     *
     * @param callback_poa contains child poa created for the callback interface.
     *
     * @para nm Pointer to the NodeManager_Impl servant object
     *
     * @return NodeApplicationManager_ptr.
     **/
    virtual PortableServer::ObjectId
    init (const char *nodeapp_location,
          const char *nodeapp_options,
          const CORBA::ULong delay,
          const Deployment::DeploymentPlan & plan,
          const PortableServer::POA_ptr callback_poa,
          NodeManager_Impl_Base * nm
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::InvalidProperty))=0;

    /// @note This method doesn't do duplicate.
    Deployment::NodeApplicationManager_ptr get_nodeapp_manager (void);

  protected:
    /// Destructor
    virtual ~NodeApplicationManager_Impl_Base (void);

    /// Add new components
    virtual void
    add_new_components (void)
      ACE_THROW_SPEC ((CORBA::SystemException,
                      ::Deployment::PlanError,
                      ::Deployment::InstallationFailure,
                      ::Deployment::UnknownImplId,
                      ::Deployment::ImplEntryPointNotFound,
                      ::Deployment::InvalidConnection,
                      ::Deployment::InvalidProperty));

    /// Remove existing components
    virtual void
    remove_existing_components (void)
      ACE_THROW_SPEC ((CORBA::SystemException,
                   ::Deployment::PlanError,
                   ::Components::RemoveFailure));

    /// Determine whether a component is absent in the new_plan
    /// Return true if absent
    virtual bool
    is_to_be_removed (const char * name);

    /// Internal help function to create new NodeApplicationProcess
    virtual Deployment::NodeApplication_ptr
    create_node_application (const ACE_CString & options
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::ResourceNotAvailable,
                       Deployment::StartError,
                       Deployment::InvalidProperty))=0;

    /// Helper function to get the connection.
    virtual Deployment::Connections *
    create_connections (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::ResourceNotAvailable,
                       Deployment::StartError,
                       Deployment::InvalidProperty));

    /**
     * Find the configurations in the plan and prepare them to pass to the
     * NodeApplication, from command line probably.
     */
    void parse_config_value (ACE_CString & str
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::InvalidProperty));

    /// Helper function to check wheather a component instance
    /// is in the "shared components list".
    bool is_shared_component (ACE_CString & name);

    /// Helper function to check wheather a component instance
    /// is in the "shared components list".
    bool is_external_component (ACE_CString & name);

  protected:
    /// location of the Nodeapplication
    ACE_CString nodeapp_path_;

    /// Keep a pointer to the managing ORB serving this servant.
    CORBA::ORB_var orb_;

    /// Keep a pointer to the managing POA.
    PortableServer::POA_var poa_;

    /// Pointer to the NodeManager_Impl servant object
    /// We could do this because NodeManager and NodeApplicationManager
    /// are always collocated in the same process, so we don't have
    /// to pass CORBA object reference back and forth.
    NodeManager_Impl_Base * node_manager_;

    /// ObjectRef of ourself which will be needed by the callback
    Deployment::NodeApplicationManager_var objref_;

    /// Child poa that uses active object map.
    PortableServer::POA_var callback_poa_;

    /// Cache a object reference of the underlying NodeApplication
    /// Since I have decided to have only 1 NA in NAM so no map is needed.
    Deployment::NodeApplication_var nodeapp_;

    /// Cached plan (This should be the part of the whole plan local to this node)
    /// The plan will be initialized when init is called.
    Deployment::DeploymentPlan plan_;

    /// Specify the time in second NodeApplicationManager will wait for a
    /// child NodeApplication to callback.  Default is 5 second.
    CORBA::ULong spawn_delay_;

    /// Extracted commandline options to pass to the NodeApplication.
    CORBA::String_var nodeapp_command_op_;

    /// A list of components shared across deployment plans
    Deployment::ComponentPlans shared_components_;

    /// A list of components that are "external" to this plan
    Deployment::ComponentPlans external_components_;

    /// A map of the component created on this node.
    typedef ACE_Hash_Map_Manager_Ex<ACE_CString,
                                    Components::CCMObject_var,
                                    ACE_Hash<ACE_CString>,
                                    ACE_Equal_To<ACE_CString>,
                                    ACE_Null_Mutex> CCMComponent_Map;
    typedef CCMComponent_Map::iterator Component_Iterator;
    CCMComponent_Map component_map_;

    /// Synchronize access to the object set.
    TAO_SYNCH_MUTEX lock_;
  };


  /**
   * @class NodeApplicationManager_Impl
   */
  class CIAO_NAM_Export NodeApplicationManager_Impl
    : public virtual NodeApplicationManager_Impl_Base
  {
  public:
    /// Constructor
    NodeApplicationManager_Impl (CORBA::ORB_ptr o,
                                 PortableServer::POA_ptr p);

    virtual PortableServer::ObjectId
    init (const char *nodeapp_location,
          const char *nodeapp_options,
          const CORBA::ULong delay,
          const Deployment::DeploymentPlan & plan,
          const PortableServer::POA_ptr callback_poa,
          NodeManager_Impl_Base * nm
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::InvalidProperty));

  protected:
    /// Destructor
    virtual ~NodeApplicationManager_Impl (void);

    // Internal help function to create new NodeApplicationProcess
    // Here we override it to create an in-process NodeApplication object
    virtual Deployment::NodeApplication_ptr
    create_node_application (const ACE_CString & options
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::ResourceNotAvailable,
                       Deployment::StartError,
                       Deployment::InvalidProperty));
  };



  struct Static_Config_EntryPoints_Maps;

  /**
   * @class Static_NodeApplicationManager_Impl
   */
  class CIAO_NAM_Export Static_NodeApplicationManager_Impl
    : public virtual NodeApplicationManager_Impl_Base
  {
  public:
    /// Constructor
    Static_NodeApplicationManager_Impl (CORBA::ORB_ptr o,
                                        PortableServer::POA_ptr p,
                                        Static_Config_EntryPoints_Maps* static_config_entrypoints_maps);

    virtual PortableServer::ObjectId
    init (const char *nodeapp_location,
          const char *nodeapp_options,
          const CORBA::ULong delay,
          const Deployment::DeploymentPlan & plan,
          const PortableServer::POA_ptr callback_poa,
          NodeManager_Impl_Base * nm
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::InvalidProperty));

  protected:
    /// Destructor
    virtual ~Static_NodeApplicationManager_Impl (void);

    // Internal help function to create new NodeApplicationProcess
    // Here we override it to create an in-process NodeApplication object
    virtual Deployment::NodeApplication_ptr
    create_node_application (const ACE_CString & options
                             ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::ResourceNotAvailable,
                       Deployment::StartError,
                       Deployment::InvalidProperty));

    Static_Config_EntryPoints_Maps* static_config_entrypoints_maps_;

    CIAO::NoOp_Configurator configurator_;
  };

}

#if defined (__ACE_INLINE__)
# include "NodeApplicationManager_Impl.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* CIAO_NODEAPPLICATIONMANAGER_IMPL_H */
