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

#include "EC_svnt.h"
#include "Cookies.h"

namespace CIAO_GLUE_BasicSP
{
  EC_Context::EC_Context (
  ::Components::CCMHome_ptr home,
  ::CIAO::Session_Container *c,
  EC_Servant *sv)
  : home_ (::Components::CCMHome::_duplicate (home)),
  container_ (c),
  servant_ (sv),
  // START new event code
  ciao_proxy_timeout_consumer_ (RtecEventChannelAdmin::ProxyPushConsumer::_nil ()),
  ciao_event_channel_ (RtecEventChannelAdmin::EventChannel::_nil ())
  // END new event code
  {
  }

  EC_Context::~EC_Context (void)
  {
    // START new event code
    this->ciao_event_channel_->destroy ();
    // END new event code
  }

  // Operations from ::Components::CCMContext.

  ::Components::Principal_ptr
  EC_Context::get_caller_principal (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::Components::Principal::_nil ());
  }

  ::Components::CCMHome_ptr
  EC_Context::get_CCM_home (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return ::Components::CCMHome::_duplicate (this->home_.in ());
  }

  CORBA::Boolean
  EC_Context::get_rollback_only (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::Transaction::UserTransaction_ptr
  EC_Context::get_user_transaction (
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
  EC_Context::is_caller_in_role (
  const char *role
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_UNUSED_ARG (role);
    ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
  }

  void
  EC_Context::set_rollback_only (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW (CORBA::NO_IMPLEMENT ());
  }

  // Operations from ::Components::SessionContext interface.

  CORBA::Object_ptr
  EC_Context::get_CCM_object (
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
      ::BasicSP::EC::_narrow (
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

    return ::BasicSP::EC::_duplicate (
    this->component_.in ());
  }

  // Operations for EC receptacles and event sources,
  // defined in ::BasicSP::CCM_EC_Context.

  void
  EC_Context::push_timeout (
  ::BasicSP::TimeOut *ev
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    // START new event code
    RtecEventComm::EventSet events (1);
    events.length (1);
    events[0].header.source = ACE_ES_EVENT_SOURCE_ANY + 1;
    events[0].header.type = ACE_ES_EVENT_UNDEFINED + 1;
    events[0].data.any_value <<= ev;
    ciao_proxy_timeout_consumer_->push (events);
    // END new event code

    // START old event code
    /*
    ACE_Active_Map_Manager<::BasicSP::TimeOutConsumer_var>::iterator end =
    this->ciao_publishes_timeout_map_.end ();

    for (ACE_Active_Map_Manager<::BasicSP::TimeOutConsumer_var>::iterator iter =
    this->ciao_publishes_timeout_map_.begin ();
    iter != end;
    ++iter)
    {
      ACE_Active_Map_Manager<::BasicSP::TimeOutConsumer_var>::ENTRY &entry = *iter;
      ::BasicSP::TimeOutConsumer_var c =
      ::BasicSP::TimeOutConsumer::_narrow (
      entry.int_id_.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      entry.int_id_->push_TimeOut (
      ev
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
    */
    // END old event code
  }

  ::Components::Cookie *
  EC_Context::subscribe_timeout (
  ::BasicSP::TimeOutConsumer_ptr c
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::ExceededConnectionLimit))
  {
    // START new event code
    // Get a reference to the ORB.
    char * argv[1] = { "EC_exec" };
    int argc = sizeof (argv) / sizeof (argv[0]);
    CORBA::ORB_var orb = CORBA::ORB_init (argc, argv ACE_ENV_ARG_PARAMETER);
		ACE_TRY_CHECK;

    // Get a reference to the POA
	  CORBA::Object_var poa_object =
      orb->resolve_initial_references ("RootPOA" ACE_ENV_ARG_PARAMETER);
	  ACE_TRY_CHECK;
	  PortableServer::POA_var root_poa =
      PortableServer::POA::_narrow (poa_object.in () ACE_ENV_ARG_PARAMETER);
	  ACE_TRY_CHECK;
	  if (CORBA::is_nil (root_poa.in ()))
      ACE_ERROR_RETURN ((LM_ERROR, "Nil RootPOA\n"), 0);

    // Get a reference to the event channel
    if (CORBA::is_nil (this->ciao_event_channel_.in ()))
      {
        TAO_EC_Event_Channel_Attributes attributes (root_poa.in (), root_poa.in ());
        TAO_EC_Event_Channel * ec_servant;
        ACE_NEW_RETURN (ec_servant, TAO_EC_Event_Channel (attributes), 0);
        ec_servant->activate ();
        this->ciao_event_channel_ = ec_servant->_this ();
      }

    // Establish supplier's connection to event channel if not done yet
    if (CORBA::is_nil (this->ciao_proxy_timeout_consumer_.in ()))
      {
        RtecEventChannelAdmin::SupplierAdmin_var supplier_admin =
          this->ciao_event_channel_->for_suppliers ();
        this->ciao_proxy_timeout_consumer_ = supplier_admin->obtain_push_consumer ();

        // Create and register supplier servant
        timeout_Supplier_impl * supplier_servant;
        ACE_NEW_RETURN (supplier_servant, timeout_Supplier_impl (orb.in ()), 0);
        RtecEventComm::PushSupplier_var supplier = supplier_servant->_this ();

        // Set QoS properties and connect
        ACE_SupplierQOS_Factory qos;
        qos.insert (ACE_ES_EVENT_SOURCE_ANY + 1,
                    ACE_ES_EVENT_UNDEFINED + 1,
                    0,
                    1);
        this->ciao_proxy_timeout_consumer_->connect_push_supplier (supplier.in (),
                                                               qos.get_SupplierQOS ());
      } // End if (ciao_proxy_timeout_consumer_ is nil)

    // Establish consumer's connection to event channel
    if (CORBA::is_nil (c))
    {
      ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
    }

    ::BasicSP::TimeOutConsumer_var sub = ::BasicSP::TimeOutConsumer::_duplicate (c);

    RtecEventChannelAdmin::ConsumerAdmin_var consumer_admin =
      this->ciao_event_channel_->for_consumers ();
    RtecEventChannelAdmin::ProxyPushSupplier_var ciao_proxy_timeout_supplier =
      consumer_admin->obtain_push_supplier ();
    
    // Create and register consumer servant
    timeout_Consumer_impl * consumer_servant;
    ACE_NEW_RETURN (consumer_servant, timeout_Consumer_impl (orb.in (), sub.in ()), 0);
    RtecEventComm::PushConsumer_var consumer = consumer_servant->_this ();

    // Put reference to this PushConsumer in the map so we can disconnect later
    ACE_Active_Map_Manager_Key key;
    this->ciao_proxy_timeout_supplier_map_.bind (ciao_proxy_timeout_supplier.in (), key);

    // Set QoS properties and connect
    ACE_ConsumerQOS_Factory qos;
    qos.start_disjunction_group (1);
    qos.insert_type (ACE_ES_EVENT_UNDEFINED + 1,
                     0);
    ciao_proxy_timeout_supplier->connect_push_consumer (consumer.in (),
                                                        qos.get_ConsumerQOS ());

    sub._retn ();

    ::Components::Cookie_var retv = new ::CIAO::Map_Key_Cookie (key);
    return retv._retn ();
    // END new event code

    // START old event code
    /*
    if (CORBA::is_nil (c))
    {
      ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
    }

    ::BasicSP::TimeOutConsumer_var sub =
    ::BasicSP::TimeOutConsumer::_duplicate (c);

    ACE_Active_Map_Manager_Key key;
    this->ciao_publishes_timeout_map_.bind (sub.in (), key);

    sub._retn ();

    ::Components::Cookie_var retv = new ::CIAO::Map_Key_Cookie (key);
    return retv._retn ();
    */
    // END old event code
  }

  ::BasicSP::TimeOutConsumer_ptr
  EC_Context::unsubscribe_timeout (
  ::Components::Cookie *ck
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidConnection))
  {
    // START new event code
    ACE_DEBUG ((LM_DEBUG, "EC_Context::unsubscribe_timeout\n"));
    ::BasicSP::TimeOutConsumer_var retv;
    ACE_Active_Map_Manager_Key key;

    if (ck == 0 || ::CIAO::Map_Key_Cookie::extract (ck, key) == -1)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidConnection (),
      ::BasicSP::TimeOutConsumer::_nil ());
    }

    RtecEventChannelAdmin::ProxyPushSupplier_var ciao_proxy_timeout_supplier;
    
    if (this->ciao_proxy_timeout_supplier_map_.find (key, ciao_proxy_timeout_supplier) != 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidConnection (),
      ::BasicSP::TimeOutConsumer::_nil ());
    }

    ciao_proxy_timeout_supplier->disconnect_push_supplier ();

    if (this->ciao_proxy_timeout_supplier_map_.unbind (key, ciao_proxy_timeout_supplier) != 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidConnection (),
      ::BasicSP::TimeOutConsumer::_nil ());
    }

    return retv._retn ();
    // END new event code

    // START old event code
    /*
    ::BasicSP::TimeOutConsumer_var retv;
    ACE_Active_Map_Manager_Key key;

    if (ck == 0 || ::CIAO::Map_Key_Cookie::extract (ck, key) == -1)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidConnection (),
      ::BasicSP::TimeOutConsumer::_nil ());
    }

    if (this->ciao_publishes_timeout_map_.unbind (key, retv) != 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidConnection (),
      ::BasicSP::TimeOutConsumer::_nil ());
    }

    return retv._retn ();
    */
    // END old event code
  }


  EC_Servant::EC_Servant (
  ::BasicSP::CCM_EC_ptr exe,
  ::Components::CCMHome_ptr h,
  ::CIAO::Session_Container *c)
  : executor_ (::BasicSP::CCM_EC::_duplicate (exe)),
  container_ (c)
  {
    this->context_ = new EC_Context (h, c, this);

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

  EC_Servant::~EC_Servant (void)
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

  ::Components::Cookie *
  EC_Servant::subscribe_timeout (
  ::BasicSP::TimeOutConsumer_ptr c
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::ExceededConnectionLimit))
  {
    return this->context_->subscribe_timeout (
      c
      ACE_ENV_ARG_PARAMETER);
  }

  ::BasicSP::TimeOutConsumer_ptr
  EC_Servant::unsubscribe_timeout (
  ::Components::Cookie *ck
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidConnection))
  {
    return this->context_->unsubscribe_timeout (
      ck
      ACE_ENV_ARG_PARAMETER);
  }

  ::CORBA::Long
  EC_Servant::hertz (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->executor_->hertz (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  void 
  EC_Servant::hertz (
  ::CORBA::Long val
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    this->executor_->hertz (
    val
    ACE_ENV_ARG_PARAMETER);
  }

  // Operations for Navigation interface.

  CORBA::Object_ptr
  EC_Servant::provide_facet (
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
  EC_Servant::get_all_facets (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::FacetDescriptions *
  EC_Servant::get_named_facets (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  CORBA::Boolean
  EC_Servant::same_component (
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
  EC_Servant::connect (
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

    ACE_THROW_RETURN (::Components::InvalidName (), 0);
  }

  CORBA::Object_ptr
  EC_Servant::disconnect (
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

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::CORBA::Object::_nil ());
  }

  ::Components::ConnectionDescriptions *
  EC_Servant::get_connections (
  const char *name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ReceptacleDescriptions *
  EC_Servant::get_all_receptacles (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ReceptacleDescriptions *
  EC_Servant::get_named_receptacles (
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
  EC_Servant::get_consumer (
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

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::Components::EventConsumerBase::_nil ());
  }

  ::Components::Cookie *
  EC_Servant::subscribe (
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

    if (ACE_OS::strcmp (publisher_name, "timeout") == 0)
    {
      ::BasicSP::TimeOutConsumer_var _ciao_consumer =
      ::BasicSP::TimeOutConsumer::_narrow (
      subscribe
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (::CORBA::is_nil (_ciao_consumer.in ()))
      {
        ACE_THROW_RETURN (::Components::InvalidConnection (), 0);
      }

      return this->subscribe_timeout (
      _ciao_consumer.in ()
      ACE_ENV_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (::Components::InvalidName (), 0);
  }

  ::Components::EventConsumerBase_ptr
  EC_Servant::unsubscribe (
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

    if (ACE_OS::strcmp (publisher_name, "timeout") == 0)
    {
      return this->unsubscribe_timeout (
      ck
      ACE_ENV_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::Components::EventConsumerBase::_nil ());
  }

  void
  EC_Servant::connect_consumer (
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
  EC_Servant::disconnect_consumer (
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
  EC_Servant::get_all_consumers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ConsumerDescriptions *
  EC_Servant::get_named_consumers (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::EmitterDescriptions *
  EC_Servant::get_all_emitters (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::EmitterDescriptions *
  EC_Servant::get_named_emitters (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::PublisherDescriptions *
  EC_Servant::get_all_publishers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::PublisherDescriptions *
  EC_Servant::get_named_publishers (
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
  EC_Servant::get_component_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  ::Components::CCMHome_ptr
  EC_Servant::get_ccm_home (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->context_->get_CCM_home (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  ::Components::PrimaryKeyBase *
  EC_Servant::get_primary_key (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::NoKeyAvailable))
  {
    ACE_THROW_RETURN (::Components::NoKeyAvailable (), 0);
  }

  void
  EC_Servant::configuration_complete (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidConfiguration))
  {
    // CIAO to-do
  }

  void
  EC_Servant::remove (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::RemoveFailure))
  {
    // CIAO to-do
  }

  ::Components::ComponentPortDescription *
  EC_Servant::get_all_ports (
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
  EC_Servant::_get_component (
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
  EC_Servant::_ciao_activate (
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
  EC_Servant::_ciao_passivate (
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

  void
  EC_Servant::start (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    this->executor_->start (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  void
  EC_Servant::stop (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    this->executor_->stop (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }


  ECHome_Servant::ECHome_Servant (
  ::BasicSP::CCM_ECHome_ptr exe,
  ::CIAO::Session_Container *c)
  : executor_ (::BasicSP::CCM_ECHome::_duplicate (exe)),
  container_ (c)
  {
  }

  ECHome_Servant::~ECHome_Servant (void)
  {
  }

  ::BasicSP::EC_ptr
  ECHome_Servant::new_EC (
  ::CORBA::Long hertz
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::EnterpriseComponent_var _ciao_ec =
    this->executor_->new_EC (
    hertz
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::EC::_nil ());

    ::BasicSP::CCM_EC_var _ciao_comp =
    ::BasicSP::CCM_EC::_narrow (
    _ciao_ec.in ()
    ACE_ENV_ARG_PARAMETER);

    return this->_ciao_activate_component (
    _ciao_comp.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // Operations for keyless home interface.

  ::Components::CCMObject_ptr
  ECHome_Servant::create_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CreateFailure))
  {
    return this->create (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  // Operations for implicit home interface.

  ::BasicSP::EC_ptr
  ECHome_Servant::create (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CreateFailure))
  {
    if (this->executor_.in () == 0)
    {
      ACE_THROW_RETURN (
      ::CORBA::INTERNAL (),
      ::BasicSP::EC::_nil ());
    }

    Components::EnterpriseComponent_var _ciao_ec =
    this->executor_->create (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::EC::_nil ());

    ::BasicSP::CCM_EC_var _ciao_comp =
    ::BasicSP::CCM_EC::_narrow (
    _ciao_ec.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::EC::_nil ());

    return this->_ciao_activate_component (
    _ciao_comp.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // Operations for CCMHome interface.

  ::CORBA::IRObject_ptr
  ECHome_Servant::get_component_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  ::CORBA::IRObject_ptr
  ECHome_Servant::get_home_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  void
  ECHome_Servant::remove_component (
  ::Components::CCMObject_ptr comp
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::RemoveFailure))
  {
    ::BasicSP::EC_var _ciao_comp =
    ::BasicSP::EC::_narrow (
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

  ::BasicSP::EC_ptr
  ECHome_Servant::_ciao_activate_component (
  ::BasicSP::CCM_EC_ptr exe
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::CORBA::Object_var hobj =
    this->container_->get_objref (
    this
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::EC::_nil ());

    ::Components::CCMHome_var home =
    ::Components::CCMHome::_narrow (
    hobj
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::EC::_nil ());

    EC_Servant *svt =
    new EC_Servant (
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
    ACE_CHECK_RETURN (::BasicSP::EC::_nil ());

    svt->_ciao_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::EC::_nil ());

    ::BasicSP::EC_var ho =
    ::BasicSP::EC::_narrow (
    objref.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::EC::_nil ());

    if (this->component_map_.bind (oid.in (), svt) == 0)
    {
      safe._retn ();
    }

    return ho._retn ();
  }

  void
  ECHome_Servant::_ciao_passivate_component (
  ::BasicSP::EC_ptr comp
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    PortableServer::ObjectId_var oid;

    this->container_->uninstall_component (
    comp,
    oid.out ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    EC_Servant *servant = 0;

    if (this->component_map_.unbind (oid.in (), servant) == 0)
    {
      PortableServer::ServantBase_var safe (servant);
      servant->_ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }
  }

  // Supported operations.

  // START new event code
  timeout_Supplier_impl::timeout_Supplier_impl (void)
  {
  }

  timeout_Supplier_impl::timeout_Supplier_impl (CORBA::ORB_ptr orb) :
    orb_ (CORBA::ORB::_duplicate (orb))
  {
  }
  
  void timeout_Supplier_impl::disconnect_push_supplier (void)
  {
    CORBA::Object_var poa_object =
      orb_->resolve_initial_references ("RootPOA" ACE_ENV_ARG_PARAMETER);
	  ACE_TRY_CHECK;
	  PortableServer::POA_var root_poa =
      PortableServer::POA::_narrow (poa_object.in () ACE_ENV_ARG_PARAMETER);
	  ACE_TRY_CHECK;
	  if (CORBA::is_nil (root_poa.in ()))
      ACE_ERROR ((LM_ERROR, "Nil RootPOA\n"));
    PortableServer::ObjectId_var oid = root_poa->servant_to_id (this);
    root_poa->deactivate_object (oid);
  }

  timeout_Consumer_impl::timeout_Consumer_impl (void)
  {
  }

  timeout_Consumer_impl::timeout_Consumer_impl (CORBA::ORB_ptr orb,
                                                ::BasicSP::TimeOutConsumer_ptr timeout_consumer) :
    orb_ (CORBA::ORB::_duplicate (orb)),
    timeout_consumer_ (::BasicSP::TimeOutConsumer::_duplicate (timeout_consumer))
  {
  }

  void timeout_Consumer_impl::push (const RtecEventComm::EventSet& events)
  {
    ACE_DEBUG ((LM_DEBUG, "CIAO_GLUE_BasicSP::timeout_Consumer_impl::push\n"));
    for (unsigned long i = 0; i < events.length (); i++)
      {
        ::BasicSP::TimeOut * ev;
        if (events[i].data.any_value >>= ev)
          {
            this->timeout_consumer_->push_TimeOut (ev
                                             ACE_ENV_ARG_PARAMETER);
            ACE_CHECK;
          }
      }
  }

  void timeout_Consumer_impl::disconnect_push_consumer (void)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    CORBA::Object_var poa_object =
      orb_->resolve_initial_references ("RootPOA" ACE_ENV_ARG_PARAMETER);
	  ACE_TRY_CHECK;
	  PortableServer::POA_var root_poa =
      PortableServer::POA::_narrow (poa_object.in () ACE_ENV_ARG_PARAMETER);
	  ACE_TRY_CHECK;
	  if (CORBA::is_nil (root_poa.in ()))
      ACE_ERROR ((LM_ERROR, "Nil RootPOA\n"));
    PortableServer::ObjectId_var oid = root_poa->servant_to_id (this);
    root_poa->deactivate_object (oid);
  }
  // END new event code

}

extern "C" EC_SVNT_Export ::PortableServer::Servant
createECHome_Servant (
::Components::HomeExecutorBase_ptr p,
CIAO::Session_Container *c
ACE_ENV_ARG_DECL)
{
  if (p == 0)
  {
    return 0;
  }

  ::BasicSP::CCM_ECHome_var x =
  ::BasicSP::CCM_ECHome::_narrow (
  p
  ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (::CORBA::is_nil (x.in ()))
  {
    return 0;
  }

  return new
  ::CIAO_GLUE_BasicSP::ECHome_Servant (
  x.in (),
  c);
}

