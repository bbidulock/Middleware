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

#include "NodeAppTest_RoundTrip_svnt.h"
#include "Cookies.h"
#include "ciao/Servant_Activator.h"
#include "ciao/Port_Activator_T.h"
#include "ace/SString.h"

namespace CIAO_FACET_NodeAppTest
{
  template <typename T>
  LatencyTest_Servant_T<T>::LatencyTest_Servant_T (
    ::NodeAppTest::CCM_LatencyTest_ptr executor,
    ::Components::CCMContext_ptr c)
    : executor_ ( ::NodeAppTest::CCM_LatencyTest::_duplicate (executor)),
      ctx_ ( ::Components::CCMContext::_duplicate (c))
  {
  }

  template <typename T>
  LatencyTest_Servant_T<T>::~LatencyTest_Servant_T (void)
  {
  }

  template <typename T>
  ::CORBA::Long
  LatencyTest_Servant_T<T>::cube_long (
    ::CORBA::Long param
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->cube_long (
      param
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  ::CORBA::Object_ptr
  LatencyTest_Servant_T<T>::_get_component (
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

namespace CIDL_RoundTrip_Impl
{
  NodeAppTest_RoundTrip_Context::NodeAppTest_RoundTrip_Context (
    ::Components::CCMHome_ptr h,
    ::CIAO::Session_Container *c,
    NodeAppTest_RoundTrip_Servant *sv)
    : ::CIAO::Context_Impl_Base (h, c), 
      ::CIAO::Context_Impl<
          ::NodeAppTest::CCM_NodeAppTest_RoundTrip_Context,
          NodeAppTest_RoundTrip_Servant,
          ::NodeAppTest::NodeAppTest_RoundTrip,
          ::NodeAppTest::NodeAppTest_RoundTrip_var
        > (h, c, sv)
  {
  }

  NodeAppTest_RoundTrip_Context::~NodeAppTest_RoundTrip_Context (void)
  {
  }

  // Operations for NodeAppTest_RoundTrip receptacles and event sources,
  // defined in ::NodeAppTest::CCM_NodeAppTest_RoundTrip_Context.

  // CIAO-specific.

  NodeAppTest_RoundTrip_Context *
  NodeAppTest_RoundTrip_Context::_narrow (
    ::Components::SessionContext_ptr p
    ACE_ENV_ARG_DECL_NOT_USED)
  {
    return dynamic_cast<NodeAppTest_RoundTrip_Context *> (p);
  }

  NodeAppTest_RoundTrip_Servant::NodeAppTest_RoundTrip_Servant (
    ::NodeAppTest::CCM_NodeAppTest_RoundTrip_ptr exe,
    ::Components::CCMHome_ptr h,
    const char *ins_name,
    ::CIAO::Home_Servant_Impl_Base *hs,
    ::CIAO::Session_Container *c)
    : ::CIAO::Servant_Impl_Base (h, hs, c),
      ::CIAO::Servant_Impl<
          ::POA_NodeAppTest::NodeAppTest_RoundTrip,
          ::NodeAppTest::CCM_NodeAppTest_RoundTrip,
          NodeAppTest_RoundTrip_Context
        > (exe, h, hs, c),
      ins_name_ (ins_name)
  {
    ACE_NEW (this->context_,
             NodeAppTest_RoundTrip_Context (h, c, this));

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

  NodeAppTest_RoundTrip_Servant::~NodeAppTest_RoundTrip_Servant (void)
  {
  }

  void
  NodeAppTest_RoundTrip_Servant::set_attributes (
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

  ::NodeAppTest::LatencyTest_ptr
  NodeAppTest_RoundTrip_Servant::provide_facet_1 (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    if (! ::CORBA::is_nil (this->provide_facet_1_.in ()))
    {
      return ::NodeAppTest::LatencyTest::_duplicate (this->provide_facet_1_.in ());
    }

    ::CORBA::Object_var obj =
      this->provide_facet_1_i (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::NodeAppTest::LatencyTest::_nil ());

    ::NodeAppTest::LatencyTest_var fo =
      ::NodeAppTest::LatencyTest::_narrow (obj.in ()
                                           ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::NodeAppTest::LatencyTest::_nil ());

    this->provide_facet_1_ = fo;
    return ::NodeAppTest::LatencyTest::_duplicate (this->provide_facet_1_.in ());
  }

  ::CORBA::Object_ptr
  NodeAppTest_RoundTrip_Servant::provide_facet_1_i (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::CORBA::Object_ptr ret =
      this->lookup_facet ("facet_1");

    if (! ::CORBA::is_nil (ret))
    {
      return ret;
    }

    ::CIAO::Port_Activator_T<
        ::CIAO_FACET_NodeAppTest::LatencyTest_Servant,
        ::NodeAppTest::CCM_LatencyTest,
        ::Components::CCMContext,
        NodeAppTest_RoundTrip_Servant
      > *tmp = 0;

    typedef ::CIAO::Port_Activator_T<
        ::CIAO_FACET_NodeAppTest::LatencyTest_Servant,
        ::NodeAppTest::CCM_LatencyTest,
        ::Components::CCMContext,
        NodeAppTest_RoundTrip_Servant
      >
    MACRO_MADNESS_TYPEDEF;

    ACE_CString obj_id (this->ins_name_);
    obj_id += "_facet_1";

    ACE_NEW_THROW_EX (tmp,
                      MACRO_MADNESS_TYPEDEF (
                        obj_id.c_str (),
                        "facet_1",
                        ::CIAO::Port_Activator::Facet,
                        0,
                        this->context_,
                        this),
                      ::CORBA::NO_MEMORY ());

    ::CIAO::Servant_Activator *sa = 
    this->container_->ports_servant_activator ();

    if (!sa->register_port_activator (tmp))
    {
      return ::NodeAppTest::LatencyTest::_nil ();
    }

    ::CORBA::Object_var obj =
      this->container_->generate_reference (
        obj_id.c_str (),
        "IDL:NodeAppTest/LatencyTest:1.0",
        ::CIAO::Container::Facet_Consumer
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::NodeAppTest::LatencyTest::_nil ());

    this->add_facet ("facet_1",
                     obj.in ()
                     ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::NodeAppTest::LatencyTest::_nil ());

    return obj._retn ();
  }

  ::NodeAppTest::LatencyTest_ptr
  NodeAppTest_RoundTrip_Servant::provide_facet_2 (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    if (! ::CORBA::is_nil (this->provide_facet_2_.in ()))
    {
      return ::NodeAppTest::LatencyTest::_duplicate (this->provide_facet_2_.in ());
    }

    ::CORBA::Object_var obj =
      this->provide_facet_2_i (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::NodeAppTest::LatencyTest::_nil ());

    ::NodeAppTest::LatencyTest_var fo =
      ::NodeAppTest::LatencyTest::_narrow (obj.in ()
                                           ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::NodeAppTest::LatencyTest::_nil ());

    this->provide_facet_2_ = fo;
    return ::NodeAppTest::LatencyTest::_duplicate (this->provide_facet_2_.in ());
  }

  ::CORBA::Object_ptr
  NodeAppTest_RoundTrip_Servant::provide_facet_2_i (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::CORBA::Object_ptr ret =
      this->lookup_facet ("facet_2");

    if (! ::CORBA::is_nil (ret))
    {
      return ret;
    }

    ::CIAO::Port_Activator_T<
        ::CIAO_FACET_NodeAppTest::LatencyTest_Servant,
        ::NodeAppTest::CCM_LatencyTest,
        ::Components::CCMContext,
        NodeAppTest_RoundTrip_Servant
      > *tmp = 0;

    typedef ::CIAO::Port_Activator_T<
        ::CIAO_FACET_NodeAppTest::LatencyTest_Servant,
        ::NodeAppTest::CCM_LatencyTest,
        ::Components::CCMContext,
        NodeAppTest_RoundTrip_Servant
      >
    MACRO_MADNESS_TYPEDEF;

    ACE_CString obj_id (this->ins_name_);
    obj_id += "_facet_2";

    ACE_NEW_THROW_EX (tmp,
                      MACRO_MADNESS_TYPEDEF (
                        obj_id.c_str (),
                        "facet_2",
                        ::CIAO::Port_Activator::Facet,
                        0,
                        this->context_,
                        this),
                      ::CORBA::NO_MEMORY ());

    ::CIAO::Servant_Activator *sa = 
    this->container_->ports_servant_activator ();

    if (!sa->register_port_activator (tmp))
    {
      return ::NodeAppTest::LatencyTest::_nil ();
    }

    ::CORBA::Object_var obj =
      this->container_->generate_reference (
        obj_id.c_str (),
        "IDL:NodeAppTest/LatencyTest:1.0",
        ::CIAO::Container::Facet_Consumer
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::NodeAppTest::LatencyTest::_nil ());

    this->add_facet ("facet_2",
                     obj.in ()
                     ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::NodeAppTest::LatencyTest::_nil ());

    return obj._retn ();
  }

  ::Components::Cookie *
  NodeAppTest_RoundTrip_Servant::connect (
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
  NodeAppTest_RoundTrip_Servant::disconnect (
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
  NodeAppTest_RoundTrip_Servant::get_all_receptacles (
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
  NodeAppTest_RoundTrip_Servant::connect_consumer (
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
  NodeAppTest_RoundTrip_Servant::disconnect_consumer (
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
  NodeAppTest_RoundTrip_Servant::get_all_publishers (
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
  NodeAppTest_RoundTrip_Servant::get_all_emitters (
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
  NodeAppTest_RoundTrip_Servant::subscribe (
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
  NodeAppTest_RoundTrip_Servant::unsubscribe (
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
  NodeAppTest_RoundTrip_Servant::get_facet_executor (
    const char *name
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                        ::CORBA::Object::_nil ());
    }

    if (ACE_OS::strcmp (name, "facet_1") == 0)
    {
      return this->executor_->get_facet_1 (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    if (ACE_OS::strcmp (name, "facet_2") == 0)
    {
      return this->executor_->get_facet_2 (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    return ::CORBA::Object::_nil ();
  }

  // Supported operations.

  ::CORBA::Long
  NodeAppTest_RoundTrip_Servant::cube_long (
    ::CORBA::Long param
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->cube_long (
      param
      ACE_ENV_ARG_PARAMETER);
  }

  // Component attribute operations.

  // Private method to populate the port tables.
  void
  NodeAppTest_RoundTrip_Servant::populate_port_tables (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ACE_ENV_ARG_NOT_USED;
    ::CORBA::Object_var obj_var;
    ::Components::EventConsumerBase_var ecb_var;

    obj_var =
      this->provide_facet_1_i (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;

    obj_var =
      this->provide_facet_2_i (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
  }

  NodeAppTest_RoundTripHome_Servant::NodeAppTest_RoundTripHome_Servant (
    ::NodeAppTest::CCM_NodeAppTest_RoundTripHome_ptr exe,
    const char *ins_name,
    ::CIAO::Session_Container *c)
    : ::CIAO::Home_Servant_Impl_Base (c),
      ::CIAO::Home_Servant_Impl<
            ::POA_NodeAppTest::NodeAppTest_RoundTripHome,
            ::NodeAppTest::CCM_NodeAppTest_RoundTripHome,
            NodeAppTest_RoundTrip_Servant
          > (exe, c, ins_name)
  {
  }

  NodeAppTest_RoundTripHome_Servant::~NodeAppTest_RoundTripHome_Servant (void)
  {
  }

  // Home operations.

  // Home supported interface operations.

  // Home factory and finder operations.

  // Home attribute operations.

  extern "C" NODEAPPTEST_ROUNDTRIP_SVNT_Export ::PortableServer::Servant
  create_NodeAppTest_NodeAppTest_RoundTripHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    ::CIAO::Session_Container *c,
    const char *ins_name
    ACE_ENV_ARG_DECL)
  {
    if (p == 0)
    {
      return 0;
    }

    ::NodeAppTest::CCM_NodeAppTest_RoundTripHome_var x =
    ::NodeAppTest::CCM_NodeAppTest_RoundTripHome::_narrow (
      p
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    if (::CORBA::is_nil (x.in ()))
    {
      return 0;
    }

    return new
    NodeAppTest_RoundTripHome_Servant (
      x.in (),
      ins_name,
      c);
  }
}

