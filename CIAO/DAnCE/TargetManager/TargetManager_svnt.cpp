// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#include "TargetManager_svnt.h"
#include "Cookies.h"
#include "ciao/Servant_Activator.h"
#include "ciao/Port_Activator_T.h"
#include "ace/SString.h"

namespace CIAO_FACET_Deployment
{
  template <typename T>
  TargetManager_Servant_T<T>::TargetManager_Servant_T (
    ::Deployment::CCM_TargetManager_ptr executor,
    ::Components::CCMContext_ptr c)
    : executor_ ( ::Deployment::CCM_TargetManager::_duplicate (executor)),
      ctx_ ( ::Components::CCMContext::_duplicate (c))
  {
  }

  template <typename T>
  TargetManager_Servant_T<T>::~TargetManager_Servant_T (void)
  {
  }

  template <typename T>
  ::Deployment::Domain *
  TargetManager_Servant_T<T>::getAllResources (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->getAllResources (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  template <typename T>
  ::Deployment::Domain *
  TargetManager_Servant_T<T>::getAvailableResources (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->getAvailableResources (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  template <typename T>
  void
  TargetManager_Servant_T<T>::commitResources (
    const ::Deployment::DeploymentPlan & plan
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Deployment::ResourceNotAvailable,
                   ::Deployment::PlanError))
  {
    this->executor_->commitResources (
      plan
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  void
  TargetManager_Servant_T<T>::releaseResources (
    const ::Deployment::DeploymentPlan & argname
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    this->executor_->releaseResources (
      argname
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  void
  TargetManager_Servant_T<T>::updateDomain (
    const ::CORBA::StringSeq & elements,
    const ::Deployment::Domain & domainSubset,
    ::Deployment::DomainUpdateKind updateKind
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    this->executor_->updateDomain (
      elements,
      domainSubset,
      updateKind
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  ::CORBA::Object_ptr
  TargetManager_Servant_T<T>::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::SessionContext_var sc =
      ::Components::SessionContext::_narrow (
        this->ctx_.in ()
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (sc.in ()))
    {
      return sc->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::EntityContext_var ec =
    ::Components::EntityContext::_narrow (
      this->ctx_.in ()
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (ec.in ()))
    {
      return ec->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN ( ::CORBA::INTERNAL (), 0);
  }
}

namespace CIAO_FACET_CIAO
{
  template <typename T>
  TargetManagerExt_Servant_T<T>::TargetManagerExt_Servant_T (
    ::CIAO::CCM_TargetManagerExt_ptr executor,
    ::Components::CCMContext_ptr c)
    : executor_ ( ::CIAO::CCM_TargetManagerExt::_duplicate (executor)),
      ctx_ ( ::Components::CCMContext::_duplicate (c))
  {
  }

  template <typename T>
  TargetManagerExt_Servant_T<T>::~TargetManagerExt_Servant_T (void)
  {
  }

  template <typename T>
  ::CORBA::Long
  TargetManagerExt_Servant_T<T>::get_pid (
    const char * component_uuid
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->get_pid (
      component_uuid
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  ::CIAO::Host_Infos *
  TargetManagerExt_Servant_T<T>::get_host_cpu (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->get_host_cpu (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  template <typename T>
  ::CIAO::Component_Infos *
  TargetManagerExt_Servant_T<T>::get_component_cpu (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->get_component_cpu (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  template <typename T>
  ::CIAO::Host_NodeManager_seq *
  TargetManagerExt_Servant_T<T>::get_all_node_managers (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->get_all_node_managers (
      ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  template <typename T>
  ::CORBA::Object_ptr
  TargetManagerExt_Servant_T<T>::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::SessionContext_var sc =
      ::Components::SessionContext::_narrow (
        this->ctx_.in ()
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (sc.in ()))
    {
      return sc->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::EntityContext_var ec =
    ::Components::EntityContext::_narrow (
      this->ctx_.in ()
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (ec.in ()))
    {
      return ec->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN ( ::CORBA::INTERNAL (), 0);
  }
}

namespace CIDL_TargetManager_i
{
  TargetManagerImpl_Context::TargetManagerImpl_Context (
    ::Components::CCMHome_ptr h,
    ::CIAO::Session_Container *c,
    TargetManagerImpl_Servant *sv)
    : ::CIAO::Context_Impl_Base (h, c), 
      ::CIAO::Context_Impl<
          ::CIAO::CCM_TargetManagerImpl_Context,
          TargetManagerImpl_Servant,
          ::CIAO::TargetManagerImpl,
          ::CIAO::TargetManagerImpl_var
        > (h, c, sv)
  {
  }

  TargetManagerImpl_Context::~TargetManagerImpl_Context (void)
  {
  }

  // Operations for TargetManagerImpl receptacles and event sources,
  // defined in ::CIAO::CCM_TargetManagerImpl_Context.

  // CIAO-specific.

  TargetManagerImpl_Context *
  TargetManagerImpl_Context::_narrow (
    ::Components::SessionContext_ptr p
    ACE_ENV_ARG_DECL_NOT_USED)
  {
    return dynamic_cast<TargetManagerImpl_Context *> (p);
  }

  TargetManagerImpl_Servant::TargetManagerImpl_Servant (
    ::CIAO::CCM_TargetManagerImpl_ptr exe,
    ::Components::CCMHome_ptr h,
    const char *ins_name,
    ::CIAO::Home_Servant_Impl_Base *hs,
    ::CIAO::Session_Container *c,
    CIAO::REC_POL_MAP &rec_pol_map)
    : ::CIAO::Servant_Impl_Base (h, hs, c, rec_pol_map),
      ::CIAO::Servant_Impl<
          ::POA_CIAO::TargetManagerImpl,
          ::CIAO::CCM_TargetManagerImpl,
          TargetManagerImpl_Context
        > (exe, h, hs, c, rec_pol_map),
      ins_name_ (ins_name)
  {
    ACE_NEW (this->context_,
             TargetManagerImpl_Context (h, c, this));

    // Set the instance id of the component on the context

    this->context_->_ciao_instance_id (this->ins_name_);

    ACE_TRY_NEW_ENV
    {
      ::Components::SessionComponent_var scom =
        ::Components::SessionComponent::_narrow (
          exe
          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (! ::CORBA::is_nil (scom.in ()))
      {
        scom->set_session_context (
          this->context_
          ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }

      this->populate_port_tables (
        ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }

    ACE_CATCHANY
    {
    }

    ACE_ENDTRY;
  }

  TargetManagerImpl_Servant::~TargetManagerImpl_Servant (void)
  {
  }

  void
  TargetManagerImpl_Servant::set_attributes (
    const ::Components::ConfigValues &descr
    ACE_ENV_ARG_DECL)
  {
    ACE_ENV_EMIT_CODE (ACE_UNUSED_ARG (ACE_TRY_ENV));

    for ( ::CORBA::ULong i = 0; i < descr.length (); ++i)
    {
      const char *descr_name = descr[i]->name ();
      ::CORBA::Any &descr_value = descr[i]->value ();

      ACE_UNUSED_ARG (descr_name);
      ACE_UNUSED_ARG (descr_value);
    }
  }

  ::Deployment::TargetManager_ptr
  TargetManagerImpl_Servant::provide_targetMgr (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    if (! ::CORBA::is_nil (this->provide_targetMgr_.in ()))
    {
      return ::Deployment::TargetManager::_duplicate (this->provide_targetMgr_.in ());
    }

    ::CORBA::Object_var obj =
      this->provide_targetMgr_i (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::Deployment::TargetManager::_nil ());

    ::Deployment::TargetManager_var fo =
      ::Deployment::TargetManager::_narrow (obj.in ()
                                            ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::Deployment::TargetManager::_nil ());

    this->provide_targetMgr_ = fo;
    return ::Deployment::TargetManager::_duplicate (this->provide_targetMgr_.in ());
  }

  ::CORBA::Object_ptr
  TargetManagerImpl_Servant::provide_targetMgr_i (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::CORBA::Object_ptr ret =
      this->lookup_facet ("targetMgr");

    if (! ::CORBA::is_nil (ret))
    {
      return ret;
    }

    ::CIAO::Port_Activator_T<
        ::CIAO_FACET_Deployment::TargetManager_Servant,
        ::Deployment::CCM_TargetManager,
        ::Components::CCMContext,
        TargetManagerImpl_Servant
      > *tmp = 0;

    typedef ::CIAO::Port_Activator_T<
        ::CIAO_FACET_Deployment::TargetManager_Servant,
        ::Deployment::CCM_TargetManager,
        ::Components::CCMContext,
        TargetManagerImpl_Servant
      >
    MACRO_MADNESS_TYPEDEF;

    ACE_CString obj_id (this->ins_name_);
    obj_id += "_targetMgr";

    ACE_NEW_THROW_EX (tmp,
                      MACRO_MADNESS_TYPEDEF (
                        obj_id.c_str (),
                        "targetMgr",
                        ::CIAO::Port_Activator::Facet,
                        0,
                        this->context_,
                        this),
                      ::CORBA::NO_MEMORY ());

    ::CIAO::Servant_Activator *sa = 
    this->container_->ports_servant_activator ();

    if (!sa->register_port_activator (tmp))
    {
      return ::Deployment::TargetManager::_nil ();
    }

    ::CORBA::Object_var obj =
      this->container_->generate_reference (
        obj_id.c_str (),
        "IDL:Deployment/TargetManager:1.0",
        ::CIAO::Container::Facet_Consumer
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::Deployment::TargetManager::_nil ());

    this->add_facet ("targetMgr",
                     obj.in ()
                     ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::Deployment::TargetManager::_nil ());

    return obj._retn ();
  }

  ::CIAO::TargetManagerExt_ptr
  TargetManagerImpl_Servant::provide_target_manager_ext (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    if (! ::CORBA::is_nil (this->provide_target_manager_ext_.in ()))
    {
      return ::CIAO::TargetManagerExt::_duplicate (this->provide_target_manager_ext_.in ());
    }

    ::CORBA::Object_var obj =
      this->provide_target_manager_ext_i (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CIAO::TargetManagerExt::_nil ());

    ::CIAO::TargetManagerExt_var fo =
      ::CIAO::TargetManagerExt::_narrow (obj.in ()
                                         ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CIAO::TargetManagerExt::_nil ());

    this->provide_target_manager_ext_ = fo;
    return ::CIAO::TargetManagerExt::_duplicate (this->provide_target_manager_ext_.in ());
  }

  ::CORBA::Object_ptr
  TargetManagerImpl_Servant::provide_target_manager_ext_i (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::CORBA::Object_ptr ret =
      this->lookup_facet ("target_manager_ext");

    if (! ::CORBA::is_nil (ret))
    {
      return ret;
    }

    ::CIAO::Port_Activator_T<
        ::CIAO_FACET_CIAO::TargetManagerExt_Servant,
        ::CIAO::CCM_TargetManagerExt,
        ::Components::CCMContext,
        TargetManagerImpl_Servant
      > *tmp = 0;

    typedef ::CIAO::Port_Activator_T<
        ::CIAO_FACET_CIAO::TargetManagerExt_Servant,
        ::CIAO::CCM_TargetManagerExt,
        ::Components::CCMContext,
        TargetManagerImpl_Servant
      >
    MACRO_MADNESS_TYPEDEF;

    ACE_CString obj_id (this->ins_name_);
    obj_id += "_target_manager_ext";

    ACE_NEW_THROW_EX (tmp,
                      MACRO_MADNESS_TYPEDEF (
                        obj_id.c_str (),
                        "target_manager_ext",
                        ::CIAO::Port_Activator::Facet,
                        0,
                        this->context_,
                        this),
                      ::CORBA::NO_MEMORY ());

    ::CIAO::Servant_Activator *sa = 
    this->container_->ports_servant_activator ();

    if (!sa->register_port_activator (tmp))
    {
      return ::CIAO::TargetManagerExt::_nil ();
    }

    ::CORBA::Object_var obj =
      this->container_->generate_reference (
        obj_id.c_str (),
        "IDL:CIAO/TargetManagerExt:1.0",
        ::CIAO::Container::Facet_Consumer
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CIAO::TargetManagerExt::_nil ());

    this->add_facet ("target_manager_ext",
                     obj.in ()
                     ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CIAO::TargetManagerExt::_nil ());

    return obj._retn ();
  }

  ::Components::Cookie *
  TargetManagerImpl_Servant::connect (
    const char *name,
    ::CORBA::Object_ptr connection
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::InvalidConnection,
                   ::Components::AlreadyConnected,
                   ::Components::ExceededConnectionLimit))
  {
    // If the component has no receptacles, this will be unused.
    ACE_UNUSED_ARG (connection);

    if (name == 0)
    {
      ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
  }

  ::CORBA::Object_ptr
  TargetManagerImpl_Servant::disconnect (
    const char *name,
    ::Components::Cookie * ck
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::InvalidConnection,
                   ::Components::CookieRequired,
                   ::Components::NoConnection))
  {
    ACE_UNUSED_ARG (ck);

    if (name == 0)
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                        ::CORBA::Object::_nil ());
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (),
                      ::CORBA::Object::_nil ());
  }

  ::Components::ReceptacleDescriptions *
  TargetManagerImpl_Servant::get_all_receptacles (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::ReceptacleDescriptions *retval = 0;
    ACE_NEW_RETURN (retval,
                    ::Components::ReceptacleDescriptions,
                    0);
    ::Components::ReceptacleDescriptions_var safe_retval = retval;
    safe_retval->length (0UL);

    return safe_retval._retn ();
  }

  void
  TargetManagerImpl_Servant::connect_consumer (
    const char * emitter_name,
    ::Components::EventConsumerBase_ptr consumer
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::AlreadyConnected,
                   ::Components::InvalidConnection))
  {
    if (emitter_name == 0)
    {
      ACE_THROW ( ::CORBA::BAD_PARAM ());
    }

    ACE_UNUSED_ARG (consumer);
    ACE_THROW ( ::Components::InvalidName ());
  }

  ::Components::EventConsumerBase_ptr
  TargetManagerImpl_Servant::disconnect_consumer (
    const char *source_name
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::NoConnection))
  {
    if (source_name == 0)
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                        ::Components::EventConsumerBase::_nil ());
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (),
                      ::Components::EventConsumerBase::_nil ());
  }

  ::Components::PublisherDescriptions *
  TargetManagerImpl_Servant::get_all_publishers (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::PublisherDescriptions *retval = 0;
    ACE_NEW_RETURN (retval,
                    ::Components::PublisherDescriptions,
                    0);
    ::Components::PublisherDescriptions_var safe_retval = retval;
    safe_retval->length (0UL);

    return safe_retval._retn ();
  }

  ::Components::EmitterDescriptions *
  TargetManagerImpl_Servant::get_all_emitters (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::EmitterDescriptions *retval = 0;
    ACE_NEW_RETURN (retval,
                    ::Components::EmitterDescriptions,
                    0);
    ::Components::EmitterDescriptions_var safe_retval = retval;
    safe_retval->length (0UL);

    return safe_retval._retn ();
  }

  ::Components::Cookie *
  TargetManagerImpl_Servant::subscribe (
    const char *publisher_name,
    ::Components::EventConsumerBase_ptr subscribe
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::InvalidConnection,
                   ::Components::ExceededConnectionLimit))
  {
    // Just in case there are no if blocks
    ACE_UNUSED_ARG (subscribe);

    if (publisher_name == 0)
    {
      ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
  }

  ::Components::EventConsumerBase_ptr
  TargetManagerImpl_Servant::unsubscribe (
    const char *publisher_name,
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException,
                   ::Components::InvalidName,
                   ::Components::InvalidConnection))
  {
    // Just in case there are no if blocks
    ACE_UNUSED_ARG (ck);

    if (publisher_name == 0)
    {
      ACE_THROW_RETURN ( ::Components::InvalidName (),
                        ::Components::EventConsumerBase::_nil ());
    }

    ACE_THROW_RETURN ( ::Components::InvalidName (),
                      ::Components::EventConsumerBase::_nil ());
  }

  ::CORBA::Object_ptr
  TargetManagerImpl_Servant::get_facet_executor (
    const char *name
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                        ::CORBA::Object::_nil ());
    }

    if (ACE_OS::strcmp (name, "targetMgr") == 0)
    {
      return this->executor_->get_targetMgr (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    if (ACE_OS::strcmp (name, "target_manager_ext") == 0)
    {
      return this->executor_->get_target_manager_ext (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    return ::CORBA::Object::_nil ();
  }

  // Supported operations.

  // Component attribute operations.

  // Private method to populate the port tables.
  void
  TargetManagerImpl_Servant::populate_port_tables (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ACE_ENV_ARG_NOT_USED;
    ::CORBA::Object_var obj_var;
    ::Components::EventConsumerBase_var ecb_var;

    obj_var =
      this->provide_targetMgr_i (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;

    obj_var =
      this->provide_target_manager_ext_i (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
  }

  TargetManagerHome_Servant::TargetManagerHome_Servant (
    ::CIAO::CCM_TargetManagerHome_ptr exe,
    const char *ins_name,
    ::CIAO::Session_Container *c,
    CIAO::REC_POL_MAP &rec_pol_map)
    : ::CIAO::Home_Servant_Impl_Base (c),
      ::CIAO::Home_Servant_Impl<
            ::POA_CIAO::TargetManagerHome,
            ::CIAO::CCM_TargetManagerHome,
            TargetManagerImpl_Servant
          > (exe, c, ins_name, rec_pol_map)
  {
  }

  TargetManagerHome_Servant::~TargetManagerHome_Servant (void)
  {
  }

  // Home operations.

  // Home supported interface operations.

  // Home factory and finder operations.

  // Home attribute operations.

  extern "C" TARGETMANAGER_SVNT_Export ::PortableServer::Servant
  create_CIAO_TargetManagerHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    ::CIAO::Session_Container *c,
    const char *ins_name,
    CIAO::REC_POL_MAP &rec_pol_map
    ACE_ENV_ARG_DECL)
  {
    if (p == 0)
    {
      return 0;
    }

    ::CIAO::CCM_TargetManagerHome_var x =
    ::CIAO::CCM_TargetManagerHome::_narrow (
      p
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    if (::CORBA::is_nil (x.in ()))
    {
      return 0;
    }

    return new
    TargetManagerHome_Servant (
      x.in (),
      ins_name,
      c, rec_pol_map);
  }
}

