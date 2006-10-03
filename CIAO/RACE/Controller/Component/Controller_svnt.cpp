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

#include "Controller_svnt.h"
#include "Cookies.h"
#include "ciao/Servant_Activator.h"
#include "ciao/Port_Activator_T.h"
#include "ace/SString.h"

namespace CIAO_FACET_CIAO_RACE
{
  template <typename T>
  Descriptors_Servant_T<T>::Descriptors_Servant_T (
    ::CIAO::RACE::CCM_Descriptors_ptr executor,
    ::Components::CCMContext_ptr c)
    : executor_ ( ::CIAO::RACE::CCM_Descriptors::_duplicate (executor)),
      ctx_ ( ::Components::CCMContext::_duplicate (c))
  {
  }

  template <typename T>
  Descriptors_Servant_T<T>::~Descriptors_Servant_T (void)
  {
  }

  template <typename T>
  void
  Descriptors_Servant_T<T>::register_string (
    const ::Deployment::PackageConfiguration & pcd,
    const ::Deployment::DeploymentPlan & plan
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    this->executor_->register_string (
      pcd,
      plan
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  void
  Descriptors_Servant_T<T>::unregister_string (
    const char * UUID
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    this->executor_->unregister_string (
      UUID
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  ::CORBA::Object_ptr
  Descriptors_Servant_T<T>::_get_component (
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

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_Controller_Impl
    {
      Controller_Context::Controller_Context (
        ::Components::CCMHome_ptr h,
        ::CIAO::Session_Container *c,
        Controller_Servant *sv)
        : ::CIAO::Context_Impl_Base (h, c), 
          ::CIAO::Context_Impl<
              ::CIAO::RACE::CCM_Controller_Context,
              Controller_Servant,
              ::CIAO::RACE::Controller,
              ::CIAO::RACE::Controller_var
            > (h, c, sv)
      {
      }

      Controller_Context::~Controller_Context (void)
      {
      }

      // Operations for Controller receptacles and event sources,
      // defined in ::CIAO::RACE::CCM_Controller_Context.

      ::CIAO::TargetManagerExt_ptr
      Controller_Context::get_connection_target_mgr_ext (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return ::CIAO::TargetManagerExt::_duplicate (
          this->ciao_uses_target_mgr_ext_.in ());
      }

      void
      Controller_Context::connect_target_mgr_ext (
        ::CIAO::TargetManagerExt_ptr c
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        if (! ::CORBA::is_nil (this->ciao_uses_target_mgr_ext_.in ()))
        {
          ACE_THROW ( ::Components::AlreadyConnected ());
        }

        if ( ::CORBA::is_nil (c))
        {
          ACE_THROW ( ::Components::InvalidConnection ());
        }

        this->ciao_uses_target_mgr_ext_ =
          ::CIAO::TargetManagerExt::_duplicate (c);
      }

      ::CIAO::TargetManagerExt_ptr
      Controller_Context::disconnect_target_mgr_ext (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::NoConnection))
      {
        if ( ::CORBA::is_nil (this->ciao_uses_target_mgr_ext_.in ()))
        {
          ACE_THROW_RETURN ( ::Components::NoConnection (),
                            ::CIAO::TargetManagerExt::_nil ());
        }

        return this->ciao_uses_target_mgr_ext_._retn ();
      }

      ::Deployment::TargetManager_ptr
      Controller_Context::get_connection_target_mgr (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return ::Deployment::TargetManager::_duplicate (
          this->ciao_uses_target_mgr_.in ());
      }

      void
      Controller_Context::connect_target_mgr (
        ::Deployment::TargetManager_ptr c
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        if (! ::CORBA::is_nil (this->ciao_uses_target_mgr_.in ()))
        {
          ACE_THROW ( ::Components::AlreadyConnected ());
        }

        if ( ::CORBA::is_nil (c))
        {
          ACE_THROW ( ::Components::InvalidConnection ());
        }

        this->ciao_uses_target_mgr_ =
          ::Deployment::TargetManager::_duplicate (c);
      }

      ::Deployment::TargetManager_ptr
      Controller_Context::disconnect_target_mgr (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::NoConnection))
      {
        if ( ::CORBA::is_nil (this->ciao_uses_target_mgr_.in ()))
        {
          ACE_THROW_RETURN ( ::Components::NoConnection (),
                            ::Deployment::TargetManager::_nil ());
        }

        return this->ciao_uses_target_mgr_._retn ();
      }

      ::CIAO::RACE::Execution_Time_Monitor_ptr
      Controller_Context::get_connection_monitor (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return ::CIAO::RACE::Execution_Time_Monitor::_duplicate (
          this->ciao_uses_monitor_.in ());
      }

      void
      Controller_Context::connect_monitor (
        ::CIAO::RACE::Execution_Time_Monitor_ptr c
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        if (! ::CORBA::is_nil (this->ciao_uses_monitor_.in ()))
        {
          ACE_THROW ( ::Components::AlreadyConnected ());
        }

        if ( ::CORBA::is_nil (c))
        {
          ACE_THROW ( ::Components::InvalidConnection ());
        }

        this->ciao_uses_monitor_ =
          ::CIAO::RACE::Execution_Time_Monitor::_duplicate (c);
      }

      ::CIAO::RACE::Execution_Time_Monitor_ptr
      Controller_Context::disconnect_monitor (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::NoConnection))
      {
        if ( ::CORBA::is_nil (this->ciao_uses_monitor_.in ()))
        {
          ACE_THROW_RETURN ( ::Components::NoConnection (),
                            ::CIAO::RACE::Execution_Time_Monitor::_nil ());
        }

        return this->ciao_uses_monitor_._retn ();
      }

      // CIAO-specific.

      Controller_Context *
      Controller_Context::_narrow (
        ::Components::SessionContext_ptr p
        ACE_ENV_ARG_DECL_NOT_USED)
      {
        return dynamic_cast<Controller_Context *> (p);
      }

      Controller_Servant::Controller_Servant (
        ::CIAO::RACE::CCM_Controller_ptr exe,
        ::Components::CCMHome_ptr h,
        const char *ins_name,
        ::CIAO::Home_Servant_Impl_Base *hs,
        ::CIAO::Session_Container *c,
        ::CIAO::REC_POL_MAP &rec_pol_map)
        : ::CIAO::Servant_Impl_Base (h, hs, c, rec_pol_map),
          ::CIAO::Servant_Impl<
              ::POA_CIAO::RACE::Controller,
              ::CIAO::RACE::CCM_Controller,
              Controller_Context
            > (exe, h, hs, c, rec_pol_map),
          ins_name_ (ins_name)
      {
        ACE_NEW (this->context_,
                 Controller_Context (h, c, this));

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

      Controller_Servant::~Controller_Servant (void)
      {
      }

      void
      Controller_Servant::set_attributes (
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

      ::CIAO::RACE::Descriptors_ptr
      Controller_Servant::provide_descriptors (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (! ::CORBA::is_nil (this->provide_descriptors_.in ()))
        {
          return ::CIAO::RACE::Descriptors::_duplicate (this->provide_descriptors_.in ());
        }

        ::CORBA::Object_var obj =
          this->provide_descriptors_i (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Descriptors::_nil ());

        ::CIAO::RACE::Descriptors_var fo =
          ::CIAO::RACE::Descriptors::_narrow (obj.in ()
                                              ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Descriptors::_nil ());

        this->provide_descriptors_ = fo;
        return ::CIAO::RACE::Descriptors::_duplicate (this->provide_descriptors_.in ());
      }

      ::CORBA::Object_ptr
      Controller_Servant::provide_descriptors_i (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::CORBA::Object_ptr ret =
          this->lookup_facet ("descriptors");

        if (! ::CORBA::is_nil (ret))
        {
          return ret;
        }

        ::CIAO::Port_Activator_T<
            ::CIAO_FACET_CIAO_RACE::Descriptors_Servant,
            ::CIAO::RACE::CCM_Descriptors,
            ::Components::CCMContext,
            Controller_Servant
          > *tmp = 0;

        typedef ::CIAO::Port_Activator_T<
            ::CIAO_FACET_CIAO_RACE::Descriptors_Servant,
            ::CIAO::RACE::CCM_Descriptors,
            ::Components::CCMContext,
            Controller_Servant
          >
        MACRO_MADNESS_TYPEDEF;

        ACE_CString obj_id (this->ins_name_);
        obj_id += "_descriptors";

        ACE_NEW_THROW_EX (tmp,
                          MACRO_MADNESS_TYPEDEF (
                            obj_id.c_str (),
                            "descriptors",
                            ::CIAO::Port_Activator::Facet,
                            0,
                            this->context_,
                            this),
                          ::CORBA::NO_MEMORY ());

        ::CIAO::Servant_Activator *sa = 
        this->container_->ports_servant_activator ();

        if (!sa->register_port_activator (tmp))
        {
          return ::CIAO::RACE::Descriptors::_nil ();
        }

        ::CORBA::Object_var obj =
          this->container_->generate_reference (
            obj_id.c_str (),
            "IDL:CIAO/RACE/Descriptors:1.0",
            ::CIAO::Container::Facet_Consumer
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Descriptors::_nil ());

        this->add_facet ("descriptors",
                         obj.in ()
                         ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Descriptors::_nil ());

        return obj._retn ();
      }

      ::Components::Cookie *
      Controller_Servant::connect (
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

        if (ACE_OS::strcmp (name, "target_mgr_ext") == 0)
        {
          ::CIAO::TargetManagerExt_var _ciao_conn =
          ::CIAO::TargetManagerExt::_narrow (
            connection
            ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          if ( ::CORBA::is_nil (_ciao_conn.in ()))
          {
            ACE_THROW_RETURN ( ::Components::InvalidConnection (), 0);
          }

          // Simplex connect.
          this->connect_target_mgr_ext (
            _ciao_conn.in ()
            ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          return 0;
        }

        if (ACE_OS::strcmp (name, "target_mgr") == 0)
        {
          ::Deployment::TargetManager_var _ciao_conn =
          ::Deployment::TargetManager::_narrow (
            connection
            ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          if ( ::CORBA::is_nil (_ciao_conn.in ()))
          {
            ACE_THROW_RETURN ( ::Components::InvalidConnection (), 0);
          }

          // Simplex connect.
          this->connect_target_mgr (
            _ciao_conn.in ()
            ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          return 0;
        }

        if (ACE_OS::strcmp (name, "monitor") == 0)
        {
          ::CIAO::RACE::Execution_Time_Monitor_var _ciao_conn =
          ::CIAO::RACE::Execution_Time_Monitor::_narrow (
            connection
            ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          if ( ::CORBA::is_nil (_ciao_conn.in ()))
          {
            ACE_THROW_RETURN ( ::Components::InvalidConnection (), 0);
          }

          // Simplex connect.
          this->connect_monitor (
            _ciao_conn.in ()
            ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          return 0;
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
      }

      ::CORBA::Object_ptr
      Controller_Servant::disconnect (
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

        if (ACE_OS::strcmp (name, "target_mgr_ext") == 0)
        {
          // Simplex disconnect.
          return this->disconnect_target_mgr_ext (ACE_ENV_SINGLE_ARG_PARAMETER);
        }

        if (ACE_OS::strcmp (name, "target_mgr") == 0)
        {
          // Simplex disconnect.
          return this->disconnect_target_mgr (ACE_ENV_SINGLE_ARG_PARAMETER);
        }

        if (ACE_OS::strcmp (name, "monitor") == 0)
        {
          // Simplex disconnect.
          return this->disconnect_monitor (ACE_ENV_SINGLE_ARG_PARAMETER);
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (),
                          ::CORBA::Object::_nil ());
      }

      ::Components::ReceptacleDescriptions *
      Controller_Servant::get_all_receptacles (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::Components::ReceptacleDescriptions *retval = 0;
        ACE_NEW_RETURN (retval,
                        ::Components::ReceptacleDescriptions,
                        0);
        ::Components::ReceptacleDescriptions_var safe_retval = retval;
        safe_retval->length (3UL);

        ::CIAO::Servant_Impl_Base::describe_simplex_receptacle<
            ::CIAO::TargetManagerExt_var
          > ("target_mgr_ext",
             "IDL:CIAO/TargetManagerExt:1.0",
             this->context_->ciao_uses_target_mgr_ext_,
             safe_retval,
             0UL);

        ::CIAO::Servant_Impl_Base::describe_simplex_receptacle<
            ::Deployment::TargetManager_var
          > ("target_mgr",
             "IDL:Deployment/TargetManager:1.0",
             this->context_->ciao_uses_target_mgr_,
             safe_retval,
             1UL);

        ::CIAO::Servant_Impl_Base::describe_simplex_receptacle<
            ::CIAO::RACE::Execution_Time_Monitor_var
          > ("monitor",
             "IDL:CIAO/RACE/Execution_Time_Monitor:1.0",
             this->context_->ciao_uses_monitor_,
             safe_retval,
             2UL);

        return safe_retval._retn ();
      }

      void
      Controller_Servant::connect_target_mgr_ext (
        ::CIAO::TargetManagerExt_ptr c
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        this->context_->connect_target_mgr_ext (
          c
          ACE_ENV_ARG_PARAMETER);

        this->add_receptacle ("target_mgr_ext", c, 0);
      }

      ::CIAO::TargetManagerExt_ptr
      Controller_Servant::disconnect_target_mgr_ext (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::NoConnection))
      {
        return this->context_->disconnect_target_mgr_ext (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ::CIAO::TargetManagerExt_ptr
      Controller_Servant::get_connection_target_mgr_ext (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return this->context_->get_connection_target_mgr_ext (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      void
      Controller_Servant::connect_target_mgr (
        ::Deployment::TargetManager_ptr c
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        this->context_->connect_target_mgr (
          c
          ACE_ENV_ARG_PARAMETER);

        this->add_receptacle ("target_mgr", c, 0);
      }

      ::Deployment::TargetManager_ptr
      Controller_Servant::disconnect_target_mgr (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::NoConnection))
      {
        return this->context_->disconnect_target_mgr (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ::Deployment::TargetManager_ptr
      Controller_Servant::get_connection_target_mgr (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return this->context_->get_connection_target_mgr (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      void
      Controller_Servant::connect_monitor (
        ::CIAO::RACE::Execution_Time_Monitor_ptr c
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        this->context_->connect_monitor (
          c
          ACE_ENV_ARG_PARAMETER);

        this->add_receptacle ("monitor", c, 0);
      }

      ::CIAO::RACE::Execution_Time_Monitor_ptr
      Controller_Servant::disconnect_monitor (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::NoConnection))
      {
        return this->context_->disconnect_monitor (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ::CIAO::RACE::Execution_Time_Monitor_ptr
      Controller_Servant::get_connection_monitor (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return this->context_->get_connection_monitor (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      void
      Controller_Servant::connect_consumer (
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
      Controller_Servant::disconnect_consumer (
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
      Controller_Servant::get_all_publishers (
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
      Controller_Servant::get_all_emitters (
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
      Controller_Servant::subscribe (
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
      Controller_Servant::unsubscribe (
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
      Controller_Servant::get_facet_executor (
        const char *name
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (name == 0)
        {
          ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                            ::CORBA::Object::_nil ());
        }

        if (ACE_OS::strcmp (name, "descriptors") == 0)
        {
          return this->executor_->get_descriptors (ACE_ENV_SINGLE_ARG_PARAMETER);
        }

        return ::CORBA::Object::_nil ();
      }

      // Supported operations.

      void
      Controller_Servant::start_poller (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        this->executor_->start_poller (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      void
      Controller_Servant::stop_poller (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        this->executor_->stop_poller (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      void
      Controller_Servant::start_controller (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        this->executor_->start_controller (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      void
      Controller_Servant::stop_controller (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        this->executor_->stop_controller (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      // Component attribute operations.

      ::CORBA::Long
      Controller_Servant::sampling_period (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return this->executor_->sampling_period (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      // Private method to populate the port tables.
      void
      Controller_Servant::populate_port_tables (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ACE_ENV_ARG_NOT_USED;
        ::CORBA::Object_var obj_var;
        ::Components::EventConsumerBase_var ecb_var;

        obj_var =
          this->provide_descriptors_i (
            ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }

      Controller_Home_Servant::Controller_Home_Servant (
        ::CIAO::RACE::CCM_Controller_Home_ptr exe,
        const char *ins_name,
        ::CIAO::Session_Container *c,
        ::CIAO::REC_POL_MAP &rec_pol_map)
        : ::CIAO::Home_Servant_Impl_Base (c),
          ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::Controller_Home,
                ::CIAO::RACE::CCM_Controller_Home,
                Controller_Servant
              > (exe, c, ins_name, rec_pol_map)
      {
      }

      Controller_Home_Servant::~Controller_Home_Servant (void)
      {
      }

      // Home operations.

      // Home supported interface operations.

      // Home factory and finder operations.

      // Home attribute operations.

      extern "C" CONTROLLER_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_Controller_Home_Servant (
        ::Components::HomeExecutorBase_ptr p,
        ::CIAO::Session_Container *c,
        const char *ins_name,
        ::CIAO::REC_POL_MAP &rec_pol_map
        ACE_ENV_ARG_DECL)
      {
        if (p == 0)
        {
          return 0;
        }

        ::CIAO::RACE::CCM_Controller_Home_var x =
        ::CIAO::RACE::CCM_Controller_Home::_narrow (
          p
          ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (::CORBA::is_nil (x.in ()))
        {
          return 0;
        }

        return new
        Controller_Home_Servant (
          x.in (),
          ins_name,
          c, rec_pol_map);
      }
    }
  }
}

