//$Id$
/**========================================================
 *
 * @file   NodeApplication_Impl.h
 *
 * @Brief  This file contains the implementation of
 *         the NodeApplication interface.
 *
 * @author Tao Lu <lu@dre.vanderbilt.edu>
 * @author Gan Deng <dengg@dre.vanderbilt.edu>
 *========================================================*/

#ifndef NODEAPPLICATION_IMPL_H
#define NODEAPPLICATION_IMPL_H
#include /**/ "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/ORB.h"
#include "ace/Synch.h"
#include "ace/Synch_Traits.h"
#include "Container_Base.h"
#include "Deployment_CoreS.h"
#include "Server_init.h"
#include "CIAO_common.h"
#include "Object_Set_T.h"

using CIAO::Utility::write_IOR;

/**
 *
 * @class NodeApplication_Impl
 *
 * @brief This class implements the NodeApplication interface.
 * This interface is semantically very simillar to container
 * in the old DnC spec. However this class will also be used
 * as a Server for hosting home/component. This way we reduce the
 * complexity of the framework by omitting the componentserver layer.
 *
 * @@TODO add configuration capabilities. Threading is one of them.
 *
 * @@Assumptions:
 * 1. Now the implementation is not thread safe.
 **/

namespace CIAO
{
  class CIAO_SERVER_Export NodeApplication_Impl
    : public virtual POA_Deployment::NodeApplication,
      public virtual PortableServer::RefCountServantBase
  {
  public:
    /// Default constructor.
    NodeApplication_Impl (CORBA::ORB_ptr o,
                          PortableServer::POA_ptr p);

    /// Default destructor.
    virtual ~NodeApplication_Impl (void);

    /**
     * @method finishLaunch
     *
     * @brief This operation dose 2 things.
     *        1. Get the external connction (facet and Event source)
     *           and connect them to the local receptacle/event sink.
     *        2. If the start augment is true, start the Components.
     * @Note:
     * The connection containes the object ref of the provided object
     * reference (facet/event consumer) of components from other NodeApplications.
     * However the name field stores the name of the port on the local component.
     */
    virtual void
    finishLaunch (const Deployment::Connections & providedReference,
                  CORBA::Boolean start
                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::StartError,
                       Deployment::InvalidConnection));

    /**
     * @method start
     */
    virtual void
    start (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::StartError));

    /*-------------  CIAO specific IDL operations (idl)----------
     *
     *-----------------------------------------------------------*/

    /// Initialize the NodeApplication
    virtual CORBA::Long init (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /// Start install homes and components.
    virtual ::Deployment::ComponentInfos *
      install (const ::Deployment::NodeImplementationInfo & node_impl_info
               ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       ::Deployment::UnknownImplId,
                       ::Deployment::ImplEntryPointNotFound,
                       ::Deployment::InstallationFailure,
                       ::Components::InvalidConfiguration));
                       
    /// Get the object reference of the NodeApplicationManager.
    /// This might come in handy later.
    virtual ::CORBA::Object_ptr
    get_node_application_manager (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Access the readonly attribute.
    virtual ::Deployment::Properties *
    properties (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Remove everything inside including all components and homes.
    virtual void remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::RemoveFailure));
      
    /// Create a container interface, which will be hosted in this NodeApplication.
    virtual ::Deployment::Container_ptr 
      create_container (const ::Deployment::Properties &properties
                        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       ::Components::CreateFailure,
                       ::Components::InvalidConfiguration));

    /// Remove a container interface.
    virtual void remove_container (::Deployment::Container_ptr cref
                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       ::Components::RemoveFailure));

    /// Get all container object refs
    virtual ::Deployment::Containers * get_containers (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    /*-------------  CIAO specific helper functions (C++)---------
     *
     *-----------------------------------------------------------*/

    /// Get the containing POA.  This operation does *not*
    /// increase the reference count of the POA.
    virtual PortableServer::POA_ptr _default_POA (void);

    /// Return the cached object reference of this NodeApplication object.
    /// This operation does *NOT* increase the reference count.
    ::Deployment::NodeApplication_ptr
    get_objref (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

  protected:
    /// Create and initialize all the containers
    virtual CORBA::Long init_containers (
        const ::Deployment::NodeImplementationInfo & node_impl_info
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));


    /// This function is a helper for start call. Bala's
    /// Idea of adding those pre/post activate calls doesn't work
    /// with the new sepc.
    ///@@ TODO.   Come up with new ways of synchronized initialization process.
    typedef void (Components::CCMObject::*Funct_Ptr)
      (ACE_ENV_SINGLE_ARG_DECL);

    virtual void start_i (Funct_Ptr functor
                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Deployment::StartError));

    /// To sotre all created Component object.
    typedef ACE_Hash_Map_Manager_Ex<ACE_CString,
                                    Components::CCMObject_ptr,
                                    ACE_Hash<ACE_CString>,
                                    ACE_Equal_To<ACE_CString>,
                                    ACE_Null_Mutex> CCMComponent_Map;
    typedef CCMComponent_Map::iterator Component_Iterator;
    CCMComponent_Map component_map_;

    /// Synchronize access to the object set.
    TAO_SYNCH_MUTEX lock_;

    /// Keep a list of managed Container objects.
    Object_Set<Deployment::Container, Deployment::Container_var> container_set_;

    /// Keep a pointer to the managing ORB serving this servant.
    CORBA::ORB_var orb_;

    /// Keep a pointer to the managing POA.
    PortableServer::POA_var poa_;

    /// Cached properties
    Deployment::Properties properties_;

    /// And a reference to the NodeApplicationManager that created us.
    ::CORBA::Object_var node_app_manager_;

    /// Cache the object reference (of ourselves).
    ::Deployment::NodeApplication_var objref_;
  };
}

#if defined (__ACE_INLINE__)
# include "NodeApplication_Impl.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* NODEAPPLICATION_IMPL_H */
