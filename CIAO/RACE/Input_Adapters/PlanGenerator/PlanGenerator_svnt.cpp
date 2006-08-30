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

#include "PlanGenerator_svnt.h"
#include "Cookies.h"
#include "ciao/Servant_Activator.h"
#include "ciao/Port_Activator_T.h"
#include "ace/SString.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_PlanGenerator_Impl
    {
      PlanGenerator_Context::PlanGenerator_Context (
        ::Components::CCMHome_ptr h,
        ::CIAO::Session_Container *c,
        PlanGenerator_Servant *sv)
        : ::CIAO::Context_Impl_Base (h, c), 
          ::CIAO::Context_Impl<
              ::CIAO::RACE::CCM_PlanGenerator_Context,
              PlanGenerator_Servant,
              ::CIAO::RACE::PlanGenerator,
              ::CIAO::RACE::PlanGenerator_var
            > (h, c, sv)
      {
      }

      PlanGenerator_Context::~PlanGenerator_Context (void)
      {
      }

      // Operations for PlanGenerator receptacles and event sources,
      // defined in ::CIAO::RACE::CCM_PlanGenerator_Context.

      ::CIAO::RACE::PlanIngress_ptr
      PlanGenerator_Context::get_connection_ingress (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return ::CIAO::RACE::PlanIngress::_duplicate (
          this->ciao_uses_ingress_.in ());
      }

      void
      PlanGenerator_Context::connect_ingress (
        ::CIAO::RACE::PlanIngress_ptr c
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        if (! ::CORBA::is_nil (this->ciao_uses_ingress_.in ()))
        {
          ACE_THROW ( ::Components::AlreadyConnected ());
        }

        if ( ::CORBA::is_nil (c))
        {
          ACE_THROW ( ::Components::InvalidConnection ());
        }

        this->ciao_uses_ingress_ =
          ::CIAO::RACE::PlanIngress::_duplicate (c);
      }

      ::CIAO::RACE::PlanIngress_ptr
      PlanGenerator_Context::disconnect_ingress (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::NoConnection))
      {
        if ( ::CORBA::is_nil (this->ciao_uses_ingress_.in ()))
        {
          ACE_THROW_RETURN ( ::Components::NoConnection (),
                            ::CIAO::RACE::PlanIngress::_nil ());
        }

        return this->ciao_uses_ingress_._retn ();
      }

      // CIAO-specific.

      PlanGenerator_Context *
      PlanGenerator_Context::_narrow (
        ::Components::SessionContext_ptr p
        ACE_ENV_ARG_DECL_NOT_USED)
      {
        return dynamic_cast<PlanGenerator_Context *> (p);
      }

      PlanGenerator_Servant::PlanGenerator_Servant (
        ::CIAO::RACE::CCM_PlanGenerator_ptr exe,
        ::Components::CCMHome_ptr h,
        const char *ins_name,
        ::CIAO::Home_Servant_Impl_Base *hs,
        ::CIAO::Session_Container *c,
        ::CIAO::REC_POL_MAP &rec_pol_map)
        : ::CIAO::Servant_Impl_Base (h, hs, c, rec_pol_map),
          ::CIAO::Servant_Impl<
              ::POA_CIAO::RACE::PlanGenerator,
              ::CIAO::RACE::CCM_PlanGenerator,
              PlanGenerator_Context
            > (exe, h, hs, c, rec_pol_map),
          ins_name_ (ins_name)
      {
        ACE_NEW (this->context_,
                 PlanGenerator_Context (h, c, this));

        // Set the instance id of the component on the context

        this->context_->_ciao_instance_id (this->ins_name_);

        CIAO_REGISTER_OBV_FACTORY (
          ::CIAO::RACE::Deploy_Input_init,
          ::CIAO::RACE::Deploy_Input);

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

      PlanGenerator_Servant::~PlanGenerator_Servant (void)
      {
      }

      void
      PlanGenerator_Servant::set_attributes (
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

      PlanGenerator_Servant::Deploy_InputConsumer_deployment_Servant::Deploy_InputConsumer_deployment_Servant (
        ::CIAO::RACE::CCM_PlanGenerator_ptr executor,
        ::CIAO::RACE::CCM_PlanGenerator_Context_ptr c)
        : executor_ ( ::CIAO::RACE::CCM_PlanGenerator::_duplicate (executor)),
          ctx_ ( ::CIAO::RACE::CCM_PlanGenerator_Context::_duplicate (c))
      {
      }

      PlanGenerator_Servant::Deploy_InputConsumer_deployment_Servant::~Deploy_InputConsumer_deployment_Servant (void)
      {
      }

      ::CORBA::Object_ptr
      PlanGenerator_Servant::Deploy_InputConsumer_deployment_Servant::_get_component (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return this->ctx_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      void
      PlanGenerator_Servant::Deploy_InputConsumer_deployment_Servant::push_Deploy_Input (
        ::CIAO::RACE::Deploy_Input *evt
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        this->executor_->push_deployment (
          evt
          ACE_ENV_ARG_PARAMETER);
      }

      // Inherited from ::Components::EventConsumerBase.
      void
      PlanGenerator_Servant::Deploy_InputConsumer_deployment_Servant::push_event (
        ::Components::EventBase *ev
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::BadEventType))
      {
        ::CIAO::RACE::Deploy_Input_var ev_type =
          ::CIAO::RACE::Deploy_Input::_downcast (ev);

        if (ev_type.in () != 0)
        {
          this->push_Deploy_Input (
            ev_type.in ()
            ACE_ENV_ARG_PARAMETER);

          return;
        }

        ACE_THROW ( ::Components::BadEventType ());
      }

      CORBA::Boolean
      PlanGenerator_Servant::Deploy_InputConsumer_deployment_Servant::ciao_is_substitutable (
        const char * event_repo_id
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (event_repo_id == 0)
        {
          ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (), false);
        }

        PlanGenerator_Context *ctx =
          PlanGenerator_Context::_narrow (
            this->ctx_.in ()
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (false);

        CORBA::ORB_ptr orb = ctx->_ciao_the_Container ()->the_ORB ();

        CORBA::ValueFactory f =
          orb->lookup_value_factory (
            event_repo_id
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (false);

        if (f == 0)
        {
          return false;
        }

        CORBA::ValueBase_var v =
          f->create_for_unmarshal (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK_RETURN (false);

        f->_remove_ref ();

        if (v.in () == 0)
        {
          return false;
        }

        return dynamic_cast< ::CIAO::RACE::Deploy_Input *> (v.in ()) != 0;
      }


      ::CIAO::RACE::Deploy_InputConsumer_ptr
      PlanGenerator_Servant::get_consumer_deployment (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (! ::CORBA::is_nil (this->consumes_deployment_.in ()))
        {
          return ::CIAO::RACE::Deploy_InputConsumer::_duplicate (this->consumes_deployment_.in ());
        }

        ::Components::EventConsumerBase_var obj =
          this->get_consumer_deployment_i (
            ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Deploy_InputConsumer::_nil ());

        ::CIAO::RACE::Deploy_InputConsumer_var eco =
          ::CIAO::RACE::Deploy_InputConsumer::_narrow (
            obj.in ()
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Deploy_InputConsumer::_nil ());

        this->consumes_deployment_ = eco;
        return ::CIAO::RACE::Deploy_InputConsumer::_duplicate (this->consumes_deployment_.in ());
      }

      ::Components::EventConsumerBase_ptr
      PlanGenerator_Servant::get_consumer_deployment_i (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::Components::EventConsumerBase_ptr ret =
          this->lookup_consumer ("deployment");

        if (! ::CORBA::is_nil (ret))
        {
          return ret;
        }

        ::CIAO::Port_Activator_T<
        PlanGenerator_Servant::Deploy_InputConsumer_deployment_Servant,
        ::CIAO::RACE::CCM_PlanGenerator,
        ::CIAO::RACE::CCM_PlanGenerator_Context,
        PlanGenerator_Servant > *tmp = 0;

        typedef  CIAO::Port_Activator_T<
            PlanGenerator_Servant::Deploy_InputConsumer_deployment_Servant,
            ::CIAO::RACE::CCM_PlanGenerator,
            ::CIAO::RACE::CCM_PlanGenerator_Context, 
            PlanGenerator_Servant
          >
        MACRO_MADNESS_TYPEDEF;

        ACE_CString obj_id (this->ins_name_);
        obj_id += "_deployment";

        ACE_NEW_THROW_EX (
          tmp,
          MACRO_MADNESS_TYPEDEF (obj_id.c_str (),
                                 "deployment",
                                 ::CIAO::Port_Activator::Sink,
                                 this->executor_.in (),
                                 this->context_,
                                 this),
          ::CORBA::NO_MEMORY ());

        ::CIAO::Servant_Activator *sa =
          this->container_->ports_servant_activator ();

        if (!sa->register_port_activator (tmp))
        {
          return ::CIAO::RACE::Deploy_InputConsumer::_nil ();
        }

        ::CORBA::Object_var obj =
          this->container_->generate_reference (
            obj_id.c_str (),
            "IDL:CIAO/RACE/Deploy_InputConsumer:1.0",
            ::CIAO::Container::Facet_Consumer
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Deploy_InputConsumer::_nil ());

        ::Components::EventConsumerBase_var ecb =
          ::Components::EventConsumerBase::_narrow (
            obj.in ()
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Deploy_InputConsumer::_nil ());

        this->add_consumer ("deployment",
                            ecb.in ()
                            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Deploy_InputConsumer::_nil ());

        return ecb._retn ();
      }

      ::Components::Cookie *
      PlanGenerator_Servant::connect (
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

        if (ACE_OS::strcmp (name, "ingress") == 0)
        {
          ::CIAO::RACE::PlanIngress_var _ciao_conn =
          ::CIAO::RACE::PlanIngress::_narrow (
            connection
            ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          if ( ::CORBA::is_nil (_ciao_conn.in ()))
          {
            ACE_THROW_RETURN ( ::Components::InvalidConnection (), 0);
          }

          // Simplex connect.
          this->connect_ingress (
            _ciao_conn.in ()
            ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          return 0;
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
      }

      ::CORBA::Object_ptr
      PlanGenerator_Servant::disconnect (
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

        if (ACE_OS::strcmp (name, "ingress") == 0)
        {
          // Simplex disconnect.
          return this->disconnect_ingress (ACE_ENV_SINGLE_ARG_PARAMETER);
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (),
                          ::CORBA::Object::_nil ());
      }

      ::Components::ReceptacleDescriptions *
      PlanGenerator_Servant::get_all_receptacles (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::Components::ReceptacleDescriptions *retval = 0;
        ACE_NEW_RETURN (retval,
                        ::Components::ReceptacleDescriptions,
                        0);
        ::Components::ReceptacleDescriptions_var safe_retval = retval;
        safe_retval->length (1UL);

        ::CIAO::Servant_Impl_Base::describe_simplex_receptacle<
            ::CIAO::RACE::PlanIngress_var
          > ("ingress",
             "IDL:CIAO/RACE/PlanIngress:1.0",
             this->context_->ciao_uses_ingress_,
             safe_retval,
             0UL);

        return safe_retval._retn ();
      }

      void
      PlanGenerator_Servant::connect_ingress (
        ::CIAO::RACE::PlanIngress_ptr c
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        this->context_->connect_ingress (
          c
          ACE_ENV_ARG_PARAMETER);

        this->add_receptacle ("ingress", c, 0);
      }

      ::CIAO::RACE::PlanIngress_ptr
      PlanGenerator_Servant::disconnect_ingress (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::NoConnection))
      {
        return this->context_->disconnect_ingress (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      ::CIAO::RACE::PlanIngress_ptr
      PlanGenerator_Servant::get_connection_ingress (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return this->context_->get_connection_ingress (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      void
      PlanGenerator_Servant::connect_consumer (
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
      PlanGenerator_Servant::disconnect_consumer (
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
      PlanGenerator_Servant::get_all_publishers (
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
      PlanGenerator_Servant::get_all_emitters (
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
      PlanGenerator_Servant::subscribe (
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
      PlanGenerator_Servant::unsubscribe (
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
      PlanGenerator_Servant::get_facet_executor (
        const char *name
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (name == 0)
        {
          ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                            ::CORBA::Object::_nil ());
        }

        return ::CORBA::Object::_nil ();
      }

      // Supported operations.

      // Component attribute operations.

      // Private method to populate the port tables.
      void
      PlanGenerator_Servant::populate_port_tables (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ACE_ENV_ARG_NOT_USED;
        ::CORBA::Object_var obj_var;
        ::Components::EventConsumerBase_var ecb_var;

        ecb_var =
          this->get_consumer_deployment_i (
            ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }

      PlanGenerator_Home_Servant::PlanGenerator_Home_Servant (
        ::CIAO::RACE::CCM_PlanGenerator_Home_ptr exe,
        const char *ins_name,
        ::CIAO::Session_Container *c,
        ::CIAO::REC_POL_MAP &rec_pol_map)
        : ::CIAO::Home_Servant_Impl_Base (c),
          ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::PlanGenerator_Home,
                ::CIAO::RACE::CCM_PlanGenerator_Home,
                PlanGenerator_Servant
              > (exe, c, ins_name, rec_pol_map)
      {
      }

      PlanGenerator_Home_Servant::~PlanGenerator_Home_Servant (void)
      {
      }

      // Home operations.

      // Home supported interface operations.

      // Home factory and finder operations.

      // Home attribute operations.

      extern "C" PLANGENERATOR_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_PlanGenerator_Home_Servant (
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

        ::CIAO::RACE::CCM_PlanGenerator_Home_var x =
        ::CIAO::RACE::CCM_PlanGenerator_Home::_narrow (
          p
          ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (::CORBA::is_nil (x.in ()))
        {
          return 0;
        }

        return new
        PlanGenerator_Home_Servant (
          x.in (),
          ins_name,
          c, rec_pol_map);
      }
    }
  }
}

