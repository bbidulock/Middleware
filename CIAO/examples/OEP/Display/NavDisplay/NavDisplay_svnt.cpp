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
//    http://www.cs.wustl.edu/~nanbor/projects/CIAO-src/docs/index.html

#include "NavDisplay_svnt.h"
#include "Cookies.h"

namespace CIAO_GLUE_HUDisplay
{
  NavDisplay_Context::NavDisplay_Context (
  ::Components::CCMHome_ptr home,
  ::CIAO::Session_Container *c,
  NavDisplay_Servant *sv)
  : home_ (::Components::CCMHome::_duplicate (home)),
  container_ (c),
  servant_ (sv)
  {
  }

  NavDisplay_Context::~NavDisplay_Context (void)
  {
  }

  // Operations from ::Components::CCMContext.

  ::Components::Principal_ptr
  NavDisplay_Context::get_caller_principal (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::Components::Principal::_nil ());
  }

  ::Components::CCMHome_ptr
  NavDisplay_Context::get_CCM_home (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return ::Components::CCMHome::_duplicate (this->home_.in ());
  }

  CORBA::Boolean
  NavDisplay_Context::get_rollback_only (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::Transaction::UserTransaction_ptr
  NavDisplay_Context::get_user_transaction (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::Components::Transaction::UserTransaction::_nil ());
  }

  CORBA::Boolean
  NavDisplay_Context::is_caller_in_role (
  const char *role
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_UNUSED_ARG (role);
    ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
  }

  void
  NavDisplay_Context::set_rollback_only (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW (CORBA::NO_IMPLEMENT ());
  }

  // Operations from ::Components::SessionContext interface.

  CORBA::Object_ptr
  NavDisplay_Context::get_CCM_object (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    if (CORBA::is_nil (this->component_.in ()))
    {
      CORBA::Object_var obj =
      this->container_->get_objref (
      this->servant_
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());

      this->component_ =
      ::HUDisplay::NavDisplay::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (CORBA::Object::_nil ());

      if (CORBA::is_nil (this->component_.in ()))
      {
        ACE_THROW_RETURN (
        ::CORBA::INTERNAL (),
        ::CORBA::Object::_nil ());
      }
    }

    return ::HUDisplay::NavDisplay::_duplicate (
    this->component_.in ());
  }

  // Operations for NavDisplay receptacles and event sources,
  // defined in ::HUDisplay::CCM_NavDisplay_Context.

  ::HUDisplay::position_ptr
  NavDisplay_Context::get_connection_GPSLocation (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return ::HUDisplay::position::_duplicate (
    this->ciao_uses_GPSLocation_.in ());
  }

  void
  NavDisplay_Context::connect_GPSLocation (
  ::HUDisplay::position_ptr c
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::AlreadyConnected,
  ::Components::InvalidConnection))
  {
    if (! CORBA::is_nil (this->ciao_uses_GPSLocation_.in ()))
    {
      ACE_THROW (::Components::AlreadyConnected ());
    }

    if (CORBA::is_nil (c))
    {
      ACE_THROW (::Components::InvalidConnection ());
    }

    this->ciao_uses_GPSLocation_ =
    ::HUDisplay::position::_duplicate (c);
  }

  ::HUDisplay::position_ptr
  NavDisplay_Context::disconnect_GPSLocation (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::NoConnection))
  {
    if (CORBA::is_nil (this->ciao_uses_GPSLocation_.in ()))
    {
      ACE_THROW_RETURN (
      ::Components::NoConnection (),
      ::HUDisplay::position::_nil ());
    }

    return this->ciao_uses_GPSLocation_._retn ();
  }


  NavDisplay_Servant::NavDisplay_Servant (
  ::HUDisplay::CCM_NavDisplay_ptr exe,
  ::Components::CCMHome_ptr h,
  ::CIAO::Session_Container *c)
  : executor_ (::HUDisplay::CCM_NavDisplay::_duplicate (exe)),
  container_ (c)
  {
    this->context_ = new NavDisplay_Context (h, c, this);

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
      }
    }
    ACE_CATCHANY
    {
    }
    ACE_ENDTRY;
  }

  NavDisplay_Servant::~NavDisplay_Servant (void)
  {
    ACE_TRY_NEW_ENV
    {
      ::Components::SessionComponent_var scom =
      ::Components::SessionComponent::_narrow (
      this->executor_.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (! ::CORBA::is_nil (scom.in ()))
      {
        scom->ccm_remove (ACE_ENV_SINGLE_ARG_PARAMETER);
      }
    }
    ACE_CATCHANY
    {
    }
    ACE_ENDTRY;

    this->context_->_remove_ref ();
  }

  NavDisplay_Servant::tickConsumer_Refresh_Servant::tickConsumer_Refresh_Servant (
  ::HUDisplay::CCM_NavDisplay_ptr executor,
  ::HUDisplay::CCM_NavDisplay_Context_ptr c)
  : executor_ (::HUDisplay::CCM_NavDisplay::_duplicate (executor)),
  ctx_ (::HUDisplay::CCM_NavDisplay_Context::_duplicate (c))
  {
  }

  NavDisplay_Servant::tickConsumer_Refresh_Servant::~tickConsumer_Refresh_Servant (void)
  {
  }

  CORBA::Object_ptr
  NavDisplay_Servant::tickConsumer_Refresh_Servant::_get_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->ctx_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  void
  NavDisplay_Servant::tickConsumer_Refresh_Servant::push_tick (
  ::HUDisplay::tick *evt
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    this->executor_->push_Refresh (
    evt
    ACE_ENV_ARG_PARAMETER);
  }

  // Inherited from ::Components::EventConsumerBase.
  void
  NavDisplay_Servant::tickConsumer_Refresh_Servant::push_event (
  ::Components::EventBase *ev
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::BadEventType))
  {
    ::HUDisplay::tick_var ev_type =
    ::HUDisplay::tick::_downcast (ev);

    if (ev_type != 0)
    {
      this->push_tick (
      ev_type.in ()
      ACE_ENV_SINGLE_ARG_PARAMETER);

      return;
    }

    ACE_THROW (::Components::BadEventType ());
  }

  ::HUDisplay::tickConsumer_ptr
  NavDisplay_Servant::get_consumer_Refresh (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    if (CORBA::is_nil (this->consumes_Refresh_.in ()))
    {
      NavDisplay_Servant::tickConsumer_Refresh_Servant *svt =
      new NavDisplay_Servant::tickConsumer_Refresh_Servant (
      this->executor_.in (),
      this->context_);
      PortableServer::ServantBase_var safe_servant (svt);

      CORBA::Object_var obj =
      this->container_->install_servant (
      svt
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::HUDisplay::tickConsumer::_nil ());

      ::HUDisplay::tickConsumer_var eco =
      ::HUDisplay::tickConsumer::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::HUDisplay::tickConsumer::_nil ());

      this->consumes_Refresh_ = eco;
    }

    return ::HUDisplay::tickConsumer::_duplicate (this->consumes_Refresh_.in ());
  }

  void
  NavDisplay_Servant::connect_GPSLocation (
  ::HUDisplay::position_ptr c
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::AlreadyConnected,
  ::Components::InvalidConnection))
  {
    this->context_->connect_GPSLocation (
    c
    ACE_ENV_ARG_PARAMETER);
  }

  ::HUDisplay::position_ptr
  NavDisplay_Servant::disconnect_GPSLocation (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::NoConnection))
  {
    return this->context_->disconnect_GPSLocation (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  ::HUDisplay::position_ptr
  NavDisplay_Servant::get_connection_GPSLocation (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->context_->get_connection_GPSLocation (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  // Operations for Navigation interface.

  CORBA::Object_ptr
  NavDisplay_Servant::provide_facet (
  const char *name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN (
      ::CORBA::BAD_PARAM (),
      ::CORBA::Object::_nil ());
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::CORBA::Object::_nil ());
  }

  ::Components::FacetDescriptions *
  NavDisplay_Servant::get_all_facets (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::FacetDescriptions *
  NavDisplay_Servant::get_named_facets (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  CORBA::Boolean
  NavDisplay_Servant::same_component (
  CORBA::Object_ptr object_ref
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    if (::CORBA::is_nil (object_ref))
    {
      ACE_THROW_RETURN (::CORBA::BAD_PARAM (), 0);
    }

    ::CORBA::Object_var the_other =
    object_ref->_get_component (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::CORBA::Object_var me =
    this->context_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    return me->_is_equivalent (
    the_other.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // Operations for Receptacles interface.

  ::Components::Cookie *
  NavDisplay_Servant::connect (
  const char *name,
  ::CORBA::Object_ptr connection
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::InvalidConnection,
  ::Components::AlreadyConnected,
  ::Components::ExceededConnectionLimit))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN (::Components::InvalidName (), 0);
    }

    if (ACE_OS::strcmp (name, "GPSLocation") == 0)
    {
      ::HUDisplay::position_var _ciao_conn =
      ::HUDisplay::position::_narrow (
      connection
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (::CORBA::is_nil (_ciao_conn.in ()))
      {
        ACE_THROW_RETURN (::Components::InvalidConnection (), 0);
      }

      // Simplex connect.
      this->connect_GPSLocation (
      _ciao_conn.in ()
      ACE_ENV_ARG_PARAMETER);

      return 0;
    }

    ACE_THROW_RETURN (::Components::InvalidName (), 0);
  }

  CORBA::Object_ptr
  NavDisplay_Servant::disconnect (
  const char *name,
  ::Components::Cookie *ck
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::InvalidConnection,
  ::Components::CookieRequired,
  ::Components::NoConnection))
  {
    if (name == 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::CORBA::Object::_nil ());
    }

    if (ACE_OS::strcmp (name, "GPSLocation") == 0)
    {
      // Simplex disconnect.
      return this->disconnect_GPSLocation (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::CORBA::Object::_nil ());
  }

  ::Components::ConnectionDescriptions *
  NavDisplay_Servant::get_connections (
  const char *name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ReceptacleDescriptions *
  NavDisplay_Servant::get_all_receptacles (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ReceptacleDescriptions *
  NavDisplay_Servant::get_named_receptacles (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  // Operations for Events interface.

  ::Components::EventConsumerBase_ptr
  NavDisplay_Servant::get_consumer (
  const char *sink_name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    if (sink_name == 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    if (ACE_OS::strcmp (sink_name, "Refresh") == 0)
    {
      return this->get_consumer_Refresh (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::Components::EventConsumerBase::_nil ());
  }

  ::Components::Cookie *
  NavDisplay_Servant::subscribe (
  const char *publisher_name,
  ::Components::EventConsumerBase_ptr subscribe
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::InvalidConnection,
  ::Components::ExceededConnectionLimit))
  {
    if (publisher_name == 0)
    {
      ACE_THROW_RETURN (::Components::InvalidName (), 0);
    }

    ACE_THROW_RETURN (::Components::InvalidName (), 0);
  }

  ::Components::EventConsumerBase_ptr
  NavDisplay_Servant::unsubscribe (
  const char *publisher_name,
  ::Components::Cookie *ck
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::InvalidConnection))
  {
    if (publisher_name == 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidName (),
      ::Components::EventConsumerBase::_nil ());
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::Components::EventConsumerBase::_nil ());
  }

  void
  NavDisplay_Servant::connect_consumer (
  const char *emitter_name,
  ::Components::EventConsumerBase_ptr consumer
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::AlreadyConnected,
  ::Components::InvalidConnection))
  {
    ACE_THROW (::CORBA::NO_IMPLEMENT ());
  }

  ::Components::EventConsumerBase_ptr
  NavDisplay_Servant::disconnect_consumer (
  const char *source_name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName,
  ::Components::NoConnection))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ConsumerDescriptions *
  NavDisplay_Servant::get_all_consumers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ConsumerDescriptions *
  NavDisplay_Servant::get_named_consumers (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::EmitterDescriptions *
  NavDisplay_Servant::get_all_emitters (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::EmitterDescriptions *
  NavDisplay_Servant::get_named_emitters (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::PublisherDescriptions *
  NavDisplay_Servant::get_all_publishers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::PublisherDescriptions *
  NavDisplay_Servant::get_named_publishers (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  // Operations for CCMObject interface.

  CORBA::IRObject_ptr
  NavDisplay_Servant::get_component_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  ::Components::CCMHome_ptr
  NavDisplay_Servant::get_ccm_home (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->context_->get_CCM_home (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  ::Components::PrimaryKeyBase *
  NavDisplay_Servant::get_primary_key (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::NoKeyAvailable))
  {
    ACE_THROW_RETURN (::Components::NoKeyAvailable (), 0);
  }

  void
  NavDisplay_Servant::configuration_complete (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidConfiguration))
  {
    // CIAO to-do
  }

  void
  NavDisplay_Servant::remove (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::RemoveFailure))
  {
    // CIAO to-do
  }

  ::Components::ComponentPortDescription *
  NavDisplay_Servant::get_all_ports (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::ComponentPortDescription_var retv =
    new OBV_Components::ComponentPortDescription;

    ::Components::FacetDescriptions_var facets_desc =
    this->get_all_facets (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::Components::ReceptacleDescriptions_var receptacle_desc =
    this->get_all_receptacles (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::Components::ConsumerDescriptions_var consumer_desc =
    this->get_all_consumers (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::Components::EmitterDescriptions_var emitter_desc =
    this->get_all_emitters (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    ::Components::PublisherDescriptions_var publisher_desc =
    this->get_all_publishers (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (0);

    retv->facets (facets_desc.in ());
    retv->receptacles (receptacle_desc.in ());
    retv->consumers (consumer_desc.in ());
    retv->emitters (emitter_desc.in ());
    retv->publishers (publisher_desc.in ());

    return retv._retn ();
  }

  CORBA::Object_ptr
  NavDisplay_Servant::_get_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::SessionContext_var sc =
    ::Components::SessionContext::_narrow (
    this->context_
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (sc.in ()))
    {
      return sc->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::EntityContext_var ec =
    ::Components::EntityContext::_narrow (
    this->context_
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (ec.in ()))
    {
      return ec->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::CORBA::INTERNAL (),
    ::CORBA::Object::_nil ());
  }

  // CIAO-specific operations.

  void
  NavDisplay_Servant::_ciao_activate (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::SessionComponent_var temp =
    ::Components::SessionComponent::_narrow (
    this->executor_.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    if (! ::CORBA::is_nil (temp.in ()))
    {
      temp->ccm_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
  }

  void
  NavDisplay_Servant::_ciao_passivate (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::SessionComponent_var temp =
    ::Components::SessionComponent::_narrow (
    this->executor_.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    if (! ::CORBA::is_nil (temp.in ()))
    {
      temp->ccm_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
    }
  }

  // Supported operations.


  NavDisplayHome_Servant::NavDisplayHome_Servant (
  ::HUDisplay::CCM_NavDisplayHome_ptr exe,
  ::CIAO::Session_Container *c)
  : executor_ (::HUDisplay::CCM_NavDisplayHome::_duplicate (exe)),
  container_ (c)
  {
  }

  NavDisplayHome_Servant::~NavDisplayHome_Servant (void)
  {
  }

  // Operations for keyless home interface.

  ::Components::CCMObject_ptr
  NavDisplayHome_Servant::create_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CreateFailure))
  {
    return this->create (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  // Operations for implicit home interface.

  ::HUDisplay::NavDisplay_ptr
  NavDisplayHome_Servant::create (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CreateFailure))
  {
    if (this->executor_.in () == 0)
    {
      ACE_THROW_RETURN (
      ::CORBA::INTERNAL (),
      ::HUDisplay::NavDisplay::_nil ());
    }

    Components::EnterpriseComponent_var _ciao_ec =
    this->executor_->create (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (::HUDisplay::NavDisplay::_nil ());

    ::HUDisplay::CCM_NavDisplay_var _ciao_comp =
    ::HUDisplay::CCM_NavDisplay::_narrow (
    _ciao_ec.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::HUDisplay::NavDisplay::_nil ());

    return this->_ciao_activate_component (
    _ciao_comp.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // Operations for CCMHome interface.

  ::CORBA::IRObject_ptr
  NavDisplayHome_Servant::get_component_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  ::CORBA::IRObject_ptr
  NavDisplayHome_Servant::get_home_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  void
  NavDisplayHome_Servant::remove_component (
  ::Components::CCMObject_ptr comp
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::RemoveFailure))
  {
    ::HUDisplay::NavDisplay_var _ciao_comp =
    ::HUDisplay::NavDisplay::_narrow (
    comp
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    if (CORBA::is_nil (_ciao_comp.in ()))
    {
      ACE_THROW (CORBA::INTERNAL ());
    }

    _ciao_comp->remove (ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    this->_ciao_passivate_component (
    _ciao_comp.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // CIAO-specific operations.

  ::HUDisplay::NavDisplay_ptr
  NavDisplayHome_Servant::_ciao_activate_component (
  ::HUDisplay::CCM_NavDisplay_ptr exe
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::CORBA::Object_var hobj =
    this->container_->get_objref (
    this
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::HUDisplay::NavDisplay::_nil ());

    ::Components::CCMHome_var home =
    ::Components::CCMHome::_narrow (
    hobj
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::HUDisplay::NavDisplay::_nil ());

    NavDisplay_Servant *svt =
    new NavDisplay_Servant (
    exe,
    home.in (),
    this->container_);

    PortableServer::ServantBase_var safe (svt);
    PortableServer::ObjectId_var oid;

    CORBA::Object_var objref =
    this->container_->install_component (
    svt,
    oid.out ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::HUDisplay::NavDisplay::_nil ());

    svt->_ciao_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (::HUDisplay::NavDisplay::_nil ());

    ::HUDisplay::NavDisplay_var ho =
    ::HUDisplay::NavDisplay::_narrow (
    objref.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::HUDisplay::NavDisplay::_nil ());

    if (this->component_map_.bind (oid.in (), svt) == 0)
    {
      safe._retn ();
    }

    return ho._retn ();
  }

  void
  NavDisplayHome_Servant::_ciao_passivate_component (
  ::HUDisplay::NavDisplay_ptr comp
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    PortableServer::ObjectId_var oid;

    this->container_->uninstall_component (
    comp,
    oid.out ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    NavDisplay_Servant *servant = 0;

    if (this->component_map_.unbind (oid.in (), servant) == 0)
    {
      PortableServer::ServantBase_var safe (servant);
      servant->_ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }
  }

  // Supported operations.


}

extern "C" NAVDISPLAY_SVNT_Export ::PortableServer::Servant
createNavDisplayHome_Servant (
::Components::HomeExecutorBase_ptr p,
CIAO::Session_Container *c
ACE_ENV_ARG_DECL)
{
  if (p == 0)
  {
    return 0;
  }

  ::HUDisplay::CCM_NavDisplayHome_var x =
  ::HUDisplay::CCM_NavDisplayHome::_narrow (
  p
  ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (::CORBA::is_nil (x.in ()))
  {
    return 0;
  }

  return new
  ::CIAO_GLUE_HUDisplay::NavDisplayHome_Servant (
  x.in (),
  c);
}

