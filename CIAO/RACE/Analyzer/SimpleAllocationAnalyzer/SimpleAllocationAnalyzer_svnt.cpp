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

#include "SimpleAllocationAnalyzer_svnt.h"
#include "Cookies.h"
#include "ciao/Servant_Activator.h"
#include "ciao/Port_Activator_T.h"
#include "ace/SString.h"

namespace CIAO_FACET_CIAO_RACE
{
  template <typename T>
  Analyzer_I_Servant_T<T>::Analyzer_I_Servant_T (
    ::CIAO::RACE::CCM_Analyzer_I_ptr executor,
    ::Components::CCMContext_ptr c)
    : executor_ ( ::CIAO::RACE::CCM_Analyzer_I::_duplicate (executor)),
      ctx_ ( ::Components::CCMContext::_duplicate (c))
  {
  }

  template <typename T>
  Analyzer_I_Servant_T<T>::~Analyzer_I_Servant_T (void)
  {
  }

  template <typename T>
  ::CORBA::Boolean
  Analyzer_I_Servant_T<T>::analyze (
    const ::Deployment::DeploymentPlan & plan,
    const ::Deployment::PackageConfiguration & package,
    ::CIAO::RACE::PlannerFlow & flow
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->analyze (
      plan,
      package,
      flow
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  ::CORBA::Object_ptr
  Analyzer_I_Servant_T<T>::_get_component (
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
    namespace CIDL_SimpleAllocationAnalyzer_Impl
    {
      SimpleAllocationAnalyzer_Context::SimpleAllocationAnalyzer_Context (
        ::Components::CCMHome_ptr h,
        ::CIAO::Session_Container *c,
        SimpleAllocationAnalyzer_Servant *sv)
        : ::CIAO::Context_Impl_Base (h, c), 
          ::CIAO::Context_Impl<
              ::CIAO::RACE::CCM_SimpleAllocationAnalyzer_Context,
              SimpleAllocationAnalyzer_Servant,
              ::CIAO::RACE::SimpleAllocationAnalyzer,
              ::CIAO::RACE::SimpleAllocationAnalyzer_var
            > (h, c, sv)
      {
      }

      SimpleAllocationAnalyzer_Context::~SimpleAllocationAnalyzer_Context (void)
      {
      }

      // Operations for SimpleAllocationAnalyzer receptacles and event sources,
      // defined in ::CIAO::RACE::CCM_SimpleAllocationAnalyzer_Context.

      // CIAO-specific.

      SimpleAllocationAnalyzer_Context *
      SimpleAllocationAnalyzer_Context::_narrow (
        ::Components::SessionContext_ptr p
        ACE_ENV_ARG_DECL_NOT_USED)
      {
        return dynamic_cast<SimpleAllocationAnalyzer_Context *> (p);
      }

      SimpleAllocationAnalyzer_Servant::SimpleAllocationAnalyzer_Servant (
        ::CIAO::RACE::CCM_SimpleAllocationAnalyzer_ptr exe,
        ::Components::CCMHome_ptr h,
        const char *ins_name,
        ::CIAO::Home_Servant_Impl_Base *hs,
        ::CIAO::Session_Container *c,
        CIAO::REC_POL_MAP &rec_pol_map)
        : ::CIAO::Servant_Impl_Base (h, hs, c, rec_pol_map),
          ::CIAO::Servant_Impl<
              ::POA_CIAO::RACE::SimpleAllocationAnalyzer,
              ::CIAO::RACE::CCM_SimpleAllocationAnalyzer,
              SimpleAllocationAnalyzer_Context
            > (exe, h, hs, c, rec_pol_map),
          ins_name_ (ins_name)
      {
        ACE_NEW (this->context_,
                 SimpleAllocationAnalyzer_Context (h, c, this));

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

      SimpleAllocationAnalyzer_Servant::~SimpleAllocationAnalyzer_Servant (void)
      {
      }

      void
      SimpleAllocationAnalyzer_Servant::set_attributes (
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

      ::CIAO::RACE::Analyzer_I_ptr
      SimpleAllocationAnalyzer_Servant::provide_analyzer (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (! ::CORBA::is_nil (this->provide_analyzer_.in ()))
        {
          return ::CIAO::RACE::Analyzer_I::_duplicate (this->provide_analyzer_.in ());
        }

        ::CORBA::Object_var obj =
          this->provide_analyzer_i (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Analyzer_I::_nil ());

        ::CIAO::RACE::Analyzer_I_var fo =
          ::CIAO::RACE::Analyzer_I::_narrow (obj.in ()
                                             ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Analyzer_I::_nil ());

        this->provide_analyzer_ = fo;
        return ::CIAO::RACE::Analyzer_I::_duplicate (this->provide_analyzer_.in ());
      }

      ::CORBA::Object_ptr
      SimpleAllocationAnalyzer_Servant::provide_analyzer_i (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::CORBA::Object_ptr ret =
          this->lookup_facet ("analyzer");

        if (! ::CORBA::is_nil (ret))
        {
          return ret;
        }

        ::CIAO::Port_Activator_T<
            ::CIAO_FACET_CIAO_RACE::Analyzer_I_Servant,
            ::CIAO::RACE::CCM_Analyzer_I,
            ::Components::CCMContext,
            SimpleAllocationAnalyzer_Servant
          > *tmp = 0;

        typedef ::CIAO::Port_Activator_T<
            ::CIAO_FACET_CIAO_RACE::Analyzer_I_Servant,
            ::CIAO::RACE::CCM_Analyzer_I,
            ::Components::CCMContext,
            SimpleAllocationAnalyzer_Servant
          >
        MACRO_MADNESS_TYPEDEF;

        ACE_CString obj_id (this->ins_name_);
        obj_id += "_analyzer";

        ACE_NEW_THROW_EX (tmp,
                          MACRO_MADNESS_TYPEDEF (
                            obj_id.c_str (),
                            "analyzer",
                            ::CIAO::Port_Activator::Facet,
                            0,
                            this->context_,
                            this),
                          ::CORBA::NO_MEMORY ());

        ::CIAO::Servant_Activator *sa = 
        this->container_->ports_servant_activator ();

        if (!sa->register_port_activator (tmp))
        {
          return ::CIAO::RACE::Analyzer_I::_nil ();
        }

        ::CORBA::Object_var obj =
          this->container_->generate_reference (
            obj_id.c_str (),
            "IDL:CIAO/RACE/Analyzer_I:1.0",
            ::CIAO::Container::Facet_Consumer
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Analyzer_I::_nil ());

        this->add_facet ("analyzer",
                         obj.in ()
                         ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::Analyzer_I::_nil ());

        return obj._retn ();
      }

      ::Components::Cookie *
      SimpleAllocationAnalyzer_Servant::connect (
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
      SimpleAllocationAnalyzer_Servant::disconnect (
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
      SimpleAllocationAnalyzer_Servant::get_all_receptacles (
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
      SimpleAllocationAnalyzer_Servant::connect_consumer (
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
      SimpleAllocationAnalyzer_Servant::disconnect_consumer (
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
      SimpleAllocationAnalyzer_Servant::get_all_publishers (
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
      SimpleAllocationAnalyzer_Servant::get_all_emitters (
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
      SimpleAllocationAnalyzer_Servant::subscribe (
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
      SimpleAllocationAnalyzer_Servant::unsubscribe (
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
      SimpleAllocationAnalyzer_Servant::get_facet_executor (
        const char *name
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (name == 0)
        {
          ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                            ::CORBA::Object::_nil ());
        }

        if (ACE_OS::strcmp (name, "analyzer") == 0)
        {
          return this->executor_->get_analyzer (ACE_ENV_SINGLE_ARG_PARAMETER);
        }

        return ::CORBA::Object::_nil ();
      }

      // Supported operations.

      // Component attribute operations.

      ::CIAO::RACE::RACE_Classifications *
      SimpleAllocationAnalyzer_Servant::classification (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        return this->executor_->classification (
          ACE_ENV_SINGLE_ARG_PARAMETER);
      }

      // Private method to populate the port tables.
      void
      SimpleAllocationAnalyzer_Servant::populate_port_tables (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ACE_ENV_ARG_NOT_USED;
        ::CORBA::Object_var obj_var;
        ::Components::EventConsumerBase_var ecb_var;

        obj_var =
          this->provide_analyzer_i (
            ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }

      SimpleAllocationAnalyzer_Home_Servant::SimpleAllocationAnalyzer_Home_Servant (
        ::CIAO::RACE::CCM_SimpleAllocationAnalyzer_Home_ptr exe,
        const char *ins_name,
        ::CIAO::Session_Container *c,
        CIAO::REC_POL_MAP &rec_pol_map)
        : ::CIAO::Home_Servant_Impl_Base (c),
          ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::SimpleAllocationAnalyzer_Home,
                ::CIAO::RACE::CCM_SimpleAllocationAnalyzer_Home,
                SimpleAllocationAnalyzer_Servant
              > (exe, c, ins_name, rec_pol_map)
      {
      }

      SimpleAllocationAnalyzer_Home_Servant::~SimpleAllocationAnalyzer_Home_Servant (void)
      {
      }

      // Home operations.

      // Home supported interface operations.

      // Home factory and finder operations.

      // Home attribute operations.

      extern "C" SIMPLEALLOCATIONANALYZER_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_SimpleAllocationAnalyzer_Home_Servant (
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

        ::CIAO::RACE::CCM_SimpleAllocationAnalyzer_Home_var x =
        ::CIAO::RACE::CCM_SimpleAllocationAnalyzer_Home::_narrow (
          p
          ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (::CORBA::is_nil (x.in ()))
        {
          return 0;
        }

        return new
        SimpleAllocationAnalyzer_Home_Servant (
          x.in (),
          ins_name,
          c, rec_pol_map);
      }
    }
  }
}

