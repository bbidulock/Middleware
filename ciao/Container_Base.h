// -*- C++ -*-

//=============================================================================
/**
 *  @file    Container_Base.h
 *
 *  $Id$
 *
 *  Header file for CIAO's container implementations
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================


#ifndef CIAO_CONTAINER_BASE_H
#define CIAO_CONTAINER_BASE_H
#include /**/ "ace/pre.h"

#include "tao/ORB.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"
#include "CCM_ContainerC.h"
#include "CCM_DeploymentC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace CIAO
{
  /**
   * @class Container
   *
   * @brief Common container interface definition.
   *
   * Perhaps we can use local interface to define these interfaces as
   * we will also get reference counting automatically.
   */
  class CIAO_SERVER_Export Container
  {
  public:
    enum OA_Type
      {
        Component,
        Facet_Consumer
      };

    Container (CORBA::ORB_ptr o);

    virtual ~Container (void) = 0;

    /// Get component's POA.
    /**
     * This operation does *NOT* increase the reference count of the
     * POA. Look at the const qualifier in the method.
     */
    PortableServer::POA_ptr the_POA (void) const;

    /// Get a reference to the underlying ORB.
    CORBA::ORB_ptr the_ORB (void) const;

    /// Initialize the container with a name.
    virtual int init (const char *name = 0,
                      const CORBA::PolicyList *more_policies = 0
                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

    /// Install a new home
    virtual Components::CCMHome_ptr ciao_install_home
      (const char *exe_dll_name,
       const char *exe_entrypt,
       const char *sv_dll_name,
       const char *sv_entrypt
       ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::Deployment::UnknownImplId,
                       Components::Deployment::ImplEntryPointNotFound,
                       Components::Deployment::InstallationFailure)) = 0;

    // Uninstall a servant for component or home.
    virtual void ciao_uninstall_home (Components::CCMHome_ptr homeref
                                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

    // Uninstall a servant for component.
    virtual void uninstall_component (::Components::CCMObject_ptr objref,
                                      PortableServer::ObjectId_out oid
                                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  protected:
    CORBA::ORB_var orb_;

    /// POA within which all the components in this container will be
    /// activated.
    PortableServer::POA_var component_poa_;

    /// POA within which all the facets and receptacles will be
    /// activated.
    /**
     * Having two POA's allows us to associate different policies that
     * are distinct from the component.
     */
    PortableServer::POA_var facet_cons_poa_;
  };

  class Session_Container;

  typedef ::Components::HomeExecutorBase_ptr (*HomeFactory) (void);
  typedef ::PortableServer::Servant (*ServantFactory)
    (::Components::HomeExecutorBase_ptr p,
     ::CIAO::Session_Container *c
#if !defined (TAO_HAS_EXCEPTIONS) || defined (ACE_ENV_BKWD_COMPAT)
    , CORBA::Environment &
#endif
    );

  typedef ACE_Hash_Map_Manager_Ex<ACE_CString,
                                  HomeFactory,
                                  ACE_Hash<ACE_CString>,
                                  ACE_Equal_To<ACE_CString>,
                                  ACE_Null_Mutex> HOMECREATOR_FUNCPTR_MAP;

  typedef ACE_Hash_Map_Manager_Ex<ACE_CString,
                                  ServantFactory,
                                  ACE_Hash<ACE_CString>,
                                  ACE_Equal_To<ACE_CString>,
                                  ACE_Null_Mutex> HOMESERVANTCREATOR_FUNCPTR_MAP;

  struct Static_Config_EntryPoints_Maps
  {
    /// Map of home creator entry point name and func ptr
    HOMECREATOR_FUNCPTR_MAP* home_creator_funcptr_map_;

    /// Map of home servant creator entry point name and func ptr
    HOMESERVANTCREATOR_FUNCPTR_MAP* home_servant_creator_funcptr_map_;
  };

  class CIAO_SERVER_Export Session_Container : public Container
  {
  public:

    // @@ (OO) Does the static_config_flag really need to be an int?
    //         It appears to be a boolean value.  Please use bool
    //         instead.
    Session_Container (CORBA::ORB_ptr o,
                       bool static_config_flag = false,
                       const Static_Config_EntryPoints_Maps* static_entrypts_maps =0);

    virtual ~Session_Container (void);

    /// Initialize the container with a name.
    virtual int init (const char *name = 0,
                      const CORBA::PolicyList *more_policies = 0
                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

      ACE_THROW_SPEC ((CORBA::SystemException));

    /**
     * @brief Simply installing a home executor into the component.
     *
     * This operation install a home executor into the component.  It
     * requires the name of the DLLs to executor and the servant glue
     * code, and the entry points to the respective DLLs.  Currently,
     * we don't try to manage the lifetime of DLL objects, but we
     * should at some later point.
     *
     * @retval Home objref of the installed home.
     */
    virtual Components::CCMHome_ptr ciao_install_home
      (const char *exe_dll_name,
       const char *exe_entrypt,
       const char *sv_dll_name,
       const char *sv_entrypt
       ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::Deployment::UnknownImplId,
                       Components::Deployment::ImplEntryPointNotFound,
                       Components::Deployment::InstallationFailure));

    // Uninstall a servant for component or home.
    virtual void ciao_uninstall_home (Components::CCMHome_ptr homeref
                                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Uninstall a servant for component.
    virtual void uninstall_component (::Components::CCMObject_ptr objref,
                                      PortableServer::ObjectId_out oid
                                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Install a component servant.
    CORBA::Object_ptr install_component (PortableServer::Servant p,
                                         PortableServer::ObjectId_out oid
                                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Get an object reference to a component or home from the servant.
    CORBA::Object_ptr get_objref (PortableServer::Servant p
                                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Uninstall a servant for component or home.
    void uninstall (CORBA::Object_ptr objref,
                    Container::OA_Type t
                    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Uninstall a servant for component or home.
    void uninstall (PortableServer::Servant svt,
                    Container::OA_Type t
                    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    // Analog of the POA method that creates an object reference from
    // an object id string.
    CORBA::Object_ptr generate_reference (const char *obj_id,
                                          const char *repo_id
                                          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  private:

    void create_component_POA (const char *name,
                               const CORBA::PolicyList *p,
                               PortableServer::POA_ptr root
                               ACE_ENV_ARG_DECL);

    void create_facet_consumer_POA (PortableServer::POA_ptr root
                                    ACE_ENV_ARG_DECL);

  protected:
    long number_;

    static ACE_Atomic_Op <ACE_SYNCH_MUTEX, long> serial_number_;

    // @@ (OO) Does this really need to be an int?  It appears to be a
    //         boolean value.  Please use bool instead.
    //
    //         It looks like it can also be declared const, as well.
    bool static_config_flag_;
    const Static_Config_EntryPoints_Maps* static_entrypts_maps_;
  };
}

// Macro for registration of an OBV factory in the generated
// servant class. Similar to the macro for TAO in
// tao/ValueType/ValueFactory.h but here we take advantage of
// the fact that we have access to the current ORB indirectly
// through the context and container.
#define CIAO_REGISTER_OBV_FACTORY(FACTORY, VALUETYPE) \
  {  \
    CORBA::ValueFactory factory = new FACTORY; \
    CORBA::ORB_ptr orb = \
      this->context_->_ciao_the_Container ()->the_ORB (); \
    CORBA::ValueFactory prev_factory = \
      orb->register_value_factory ( \
               VALUETYPE::_tao_obv_static_repository_id (), \
               factory); \
    CORBA::remove_ref (prev_factory); \
    CORBA::add_ref (factory);  \
  }

#if defined (__ACE_INLINE__)
# include "Container_Base.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* CIAO_CONTAINER_BASE_H */
