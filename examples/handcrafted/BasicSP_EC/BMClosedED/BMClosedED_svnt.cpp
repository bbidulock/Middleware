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

#include "BMClosedED_svnt.h"
#include "Cookies.h"

namespace CIAO_GLUE_BasicSP
{
  ReadData_Servant::ReadData_Servant (
  ::BasicSP::CCM_ReadData_ptr executor,
  ::Components::CCMContext_ptr c)
  : executor_ (::BasicSP::CCM_ReadData::_duplicate (executor)),
  ctx_ (::Components::CCMContext::_duplicate (c))
  {
  }

  ReadData_Servant::~ReadData_Servant (void)
  {
  }

  char *
  ReadData_Servant::get_data (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->executor_->get_data (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  CORBA::Object_ptr
  ReadData_Servant::_get_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::Components::SessionContext_var sc =
    ::Components::SessionContext::_narrow (
    this->ctx_.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (CORBA::Object::_nil ());

    if (! CORBA::is_nil (sc.in ()))
    {
      return sc->get_CCM_object (
      ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::EntityContext_var ec =
    ::Components::EntityContext::_narrow (
    this->ctx_.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (CORBA::Object::_nil ());

    if (! CORBA::is_nil (ec.in ()))
    {
      return ec->get_CCM_object (
      ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (CORBA::INTERNAL (), 0);
  }

}

namespace CIAO_GLUE_BasicSP
{
  BMClosedED_Context::BMClosedED_Context (
  ::Components::CCMHome_ptr home,
  ::CIAO::Session_Container *c,
  BMClosedED_Servant *sv)
  : home_ (::Components::CCMHome::_duplicate (home)),
  container_ (c),
  servant_ (sv),
  // START new event code
  ciao_proxy_out_avail_consumer_ (RtecEventChannelAdmin::ProxyPushConsumer::_nil ()),
  ciao_event_channel_ (RtecEventChannelAdmin::EventChannel::_nil ())
  // END new event code
  {
	  this->create_event_channel ();
  }

  // START new event code
  void BMClosedED_Context::create_event_channel (void)
  {
  	// Get a reference to the ORB.
    CORBA::ORB_var orb = this->container_->_ciao_the_ORB ();
    if (CORBA::is_nil (orb.in ()))
      ACE_ERROR ((LM_ERROR, "Nil ORB\n"));

    // Get a reference to the POA
    CORBA::Object_var poa_object =
      orb->resolve_initial_references ("RootPOA" ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;
    PortableServer::POA_var root_poa =
      PortableServer::POA::_narrow (poa_object.in () ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;
    if (CORBA::is_nil (root_poa.in ()))
      ACE_ERROR ((LM_ERROR, "Nil RootPOA\n"));

    // Get a reference to the event channel
    if (CORBA::is_nil (this->ciao_event_channel_.in ()))
      {
        TAO_EC_Event_Channel_Attributes attributes (root_poa.in (), root_poa.in ());
        TAO_EC_Event_Channel * ec_servant;
        ACE_NEW (ec_servant, TAO_EC_Event_Channel (attributes));
        ec_servant->activate ();
        this->ciao_event_channel_ = ec_servant->_this ();
      }
  }
  // END new event code

  BMClosedED_Context::~BMClosedED_Context (void)
  {
    // START new event code
    this->ciao_event_channel_->destroy ();
    // END new event code
  }

  // Operations from ::Components::CCMContext.

  ::Components::Principal_ptr
  BMClosedED_Context::get_caller_principal (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::Components::Principal::_nil ());
  }

  ::Components::CCMHome_ptr
  BMClosedED_Context::get_CCM_home (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return ::Components::CCMHome::_duplicate (this->home_.in ());
  }

  CORBA::Boolean
  BMClosedED_Context::get_rollback_only (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::Transaction::UserTransaction_ptr
  BMClosedED_Context::get_user_transaction (
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
  BMClosedED_Context::is_caller_in_role (
  const char *role
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_UNUSED_ARG (role);
    ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), 0);
  }

  void
  BMClosedED_Context::set_rollback_only (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::IllegalState))
  {
    ACE_THROW (CORBA::NO_IMPLEMENT ());
  }

  // Operations from ::Components::SessionContext interface.

  CORBA::Object_ptr
  BMClosedED_Context::get_CCM_object (
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
      ::BasicSP::BMClosedED::_narrow (
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

    return ::BasicSP::BMClosedED::_duplicate (
    this->component_.in ());
  }

  // Operations for BMClosedED receptacles and event sources,
  // defined in ::BasicSP::CCM_BMClosedED_Context.

  ::BasicSP::ReadData_ptr
  BMClosedED_Context::get_connection_datain (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return ::BasicSP::ReadData::_duplicate (
    this->ciao_uses_datain_.in ());
  }

  void
  BMClosedED_Context::connect_datain (
  ::BasicSP::ReadData_ptr c
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::AlreadyConnected,
  ::Components::InvalidConnection))
  {
    if (! CORBA::is_nil (this->ciao_uses_datain_.in ()))
    {
      ACE_THROW (::Components::AlreadyConnected ());
    }

    if (CORBA::is_nil (c))
    {
      ACE_THROW (::Components::InvalidConnection ());
    }

    this->ciao_uses_datain_ =
    ::BasicSP::ReadData::_duplicate (c);
  }

  ::BasicSP::ReadData_ptr
  BMClosedED_Context::disconnect_datain (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::NoConnection))
  {
    if (CORBA::is_nil (this->ciao_uses_datain_.in ()))
    {
      ACE_THROW_RETURN (
      ::Components::NoConnection (),
      ::BasicSP::ReadData::_nil ());
    }

    return this->ciao_uses_datain_._retn ();
  }

  void
  BMClosedED_Context::push_out_avail (
  ::BasicSP::DataAvailable *ev
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    // START new event code
    RtecEventComm::EventSet events (1);
    events.length (1);
    events[0].header.source = ACE_ES_EVENT_SOURCE_ANY + 3;
    events[0].header.type = ACE_ES_EVENT_UNDEFINED + 3;
    events[0].data.any_value <<= ev;
    ciao_proxy_out_avail_consumer_->push (events ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;
    // END new event code

    // START new event code
    /*
    ACE_Active_Map_Manager<::BasicSP::DataAvailableConsumer_var>::iterator end =
    this->ciao_publishes_out_avail_map_.end ();

    for (ACE_Active_Map_Manager<::BasicSP::DataAvailableConsumer_var>::iterator iter =
    this->ciao_publishes_out_avail_map_.begin ();
    iter != end;
    ++iter)
    {
      ACE_Active_Map_Manager<::BasicSP::DataAvailableConsumer_var>::ENTRY &entry = *iter;
      ::BasicSP::DataAvailableConsumer_var c =
      ::BasicSP::DataAvailableConsumer::_narrow (
      entry.int_id_.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      entry.int_id_->push_DataAvailable (
      ev
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
    */
    // END new event code
  }

  ::Components::Cookie *
  BMClosedED_Context::subscribe_out_avail (
  ::BasicSP::DataAvailableConsumer_ptr c
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::ExceededConnectionLimit))
  {

    // START new event code
    // Get a reference to the ORB.
    CORBA::ORB_var orb = this->container_->_ciao_the_ORB ();

    // Establish supplier's connection to event channel if not done yet
    if (CORBA::is_nil (this->ciao_proxy_out_avail_consumer_.in ()))
      {
        RtecEventChannelAdmin::SupplierAdmin_var supplier_admin =
          this->ciao_event_channel_->for_suppliers (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
        this->ciao_proxy_out_avail_consumer_ =
          supplier_admin->obtain_push_consumer (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;

        // Create and register supplier servant
        out_avail_Supplier_impl * supplier_servant;
        ACE_NEW_RETURN (supplier_servant, out_avail_Supplier_impl (orb.in ()), 0);
        RtecEventComm::PushSupplier_var supplier = supplier_servant->_this ();

        // Set QoS properties and connect
        ACE_SupplierQOS_Factory qos;
        qos.insert (ACE_ES_EVENT_SOURCE_ANY + 3,
                    ACE_ES_EVENT_UNDEFINED + 3,
                    0,
                    1);
        this->ciao_proxy_out_avail_consumer_->connect_push_supplier (supplier.in (),
                                                               qos.get_SupplierQOS ());
      } // End if (ciao_proxy_out_avail_consumer_ is nil)

    // Establish consumer's connection to event channel
    if (CORBA::is_nil (c))
    {
      ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
    }

    return this->subscribe_out_avail_consumer (c);

    // END new event code

    // START old event code
    /*
    if (CORBA::is_nil (c))
    {
      ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
    }

    ::BasicSP::DataAvailableConsumer_var sub =
    ::BasicSP::DataAvailableConsumer::_duplicate (c);

    ACE_Active_Map_Manager_Key key;
    this->ciao_publishes_out_avail_map_.bind (sub.in (), key);

    sub._retn ();

    ::Components::Cookie_var retv = new ::CIAO::Map_Key_Cookie (key);
    return retv._retn ();
    */
    // END old event code

  }

  ::Components::Cookie *
  BMClosedED_Context::subscribe_out_avail_consumer (
  ::BasicSP::DataAvailableConsumer_ptr c)
  {

    // Get a reference to the ORB.
    CORBA::ORB_var orb = this->container_->_ciao_the_ORB ();

    ::BasicSP::DataAvailableConsumer_var sub = ::BasicSP::DataAvailableConsumer::_duplicate (c);

    RtecEventChannelAdmin::ConsumerAdmin_var consumer_admin =
      this->ciao_event_channel_->for_consumers (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
    RtecEventChannelAdmin::ProxyPushSupplier_var ciao_proxy_out_avail_supplier =
      consumer_admin->obtain_push_supplier (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
    
    // Create and register consumer servant
    out_avail_Consumer_impl * consumer_servant;
    ACE_NEW_RETURN (consumer_servant, out_avail_Consumer_impl (orb.in (), sub.in ()), 0);
    RtecEventComm::PushConsumer_var consumer = consumer_servant->_this ();

    // Set QoS properties and connect
    ACE_ConsumerQOS_Factory qos;
    qos.start_disjunction_group (1);
    qos.insert_type (ACE_ES_EVENT_UNDEFINED + 3,
                     0);
    ciao_proxy_out_avail_supplier->connect_push_consumer (consumer.in (),
                                                        qos.get_ConsumerQOS ());

    sub._retn ();

    ::Components::Cookie * return_cookie;
    ACE_NEW_RETURN (return_cookie,
                    ::CIAO::Object_Reference_Cookie (consumer.in ()),
                    0);
    return return_cookie;
  }

  ::BasicSP::DataAvailableConsumer_ptr
  BMClosedED_Context::unsubscribe_out_avail (
  ::Components::Cookie *ck
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidConnection))
  {
    // START new event code
    CORBA::Object_var obj = CORBA::Object::_nil ();
    ::BasicSP::DataAvailableConsumer_var return_consumer;

    if (ck == 0 || ::CIAO::Object_Reference_Cookie::extract (ck, obj.out ()) == -1)
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BasicSP::DataAvailableConsumer::_nil ());
      }

    RtecEventComm::PushConsumer_var push_consumer =
      ::RtecEventComm::PushConsumer::_narrow (obj.in ());

    if (CORBA::is_nil (push_consumer.in ()))
      {
        ACE_THROW_RETURN (
        ::Components::InvalidConnection (),
        ::BasicSP::DataAvailableConsumer::_nil ());
      }

    push_consumer->disconnect_push_consumer (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;

    // @@ Bala, what should I return here?
    return ::BasicSP::DataAvailableConsumer::_nil ();
    // END new event code

    // START old event code
    /*
    ::BasicSP::DataAvailableConsumer_var retv;
    ACE_Active_Map_Manager_Key key;

    if (ck == 0 || ::CIAO::Map_Key_Cookie::extract (ck, key) == -1)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidConnection (),
      ::BasicSP::DataAvailableConsumer::_nil ());
    }

    if (this->ciao_publishes_out_avail_map_.unbind (key, retv) != 0)
    {
      ACE_THROW_RETURN (
      ::Components::InvalidConnection (),
      ::BasicSP::DataAvailableConsumer::_nil ());
    }

    return retv._retn ();
    */
    // END old event code
  }


  BMClosedED_Servant::BMClosedED_Servant (
  ::BasicSP::CCM_BMClosedED_ptr exe,
  ::Components::CCMHome_ptr h,
  ::CIAO::Session_Container *c)
  : executor_ (::BasicSP::CCM_BMClosedED::_duplicate (exe)),
  container_ (c)
  {
    this->context_ = new BMClosedED_Context (h, c, this);

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

  BMClosedED_Servant::~BMClosedED_Servant (void)
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

  ::BasicSP::ReadData_ptr
  BMClosedED_Servant::provide_dataout (
  ACE_ENV_SINGLE_ARG_PARAMETER)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    if (::CORBA::is_nil (this->provide_dataout_.in ()))
    {
      ::BasicSP::CCM_ReadData_var fexe =
      this->executor_->get_dataout (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::ReadData::_nil ());

      if (::CORBA::is_nil (fexe.in ()))
      {
        ACE_THROW_RETURN (
        ::CORBA::INTERNAL (),
        ::BasicSP::ReadData::_nil ());
      }

      ReadData_Servant *svt =
      new ReadData_Servant (
      fexe.in (),
      this->context_);
      PortableServer::ServantBase_var safe_servant (svt);

      ::CORBA::Object_var obj =
      this->container_->install_servant (
      svt
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::ReadData::_nil ());

      ::BasicSP::ReadData_var fo =
      ::BasicSP::ReadData::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::ReadData::_nil ());

      this->provide_dataout_ = fo;
    }

    return ::BasicSP::ReadData::_duplicate (this->provide_dataout_.in ());
  }

  void
  BMClosedED_Servant::connect_datain (
  ::BasicSP::ReadData_ptr c
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::AlreadyConnected,
  ::Components::InvalidConnection))
  {
    this->context_->connect_datain (
    c
    ACE_ENV_ARG_PARAMETER);
  }

  ::BasicSP::ReadData_ptr
  BMClosedED_Servant::disconnect_datain (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::NoConnection))
  {
    return this->context_->disconnect_datain (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  ::BasicSP::ReadData_ptr
  BMClosedED_Servant::get_connection_datain (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->context_->get_connection_datain (
    ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  ::Components::Cookie *
  BMClosedED_Servant::subscribe_out_avail (
  ::BasicSP::DataAvailableConsumer_ptr c
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::ExceededConnectionLimit))
  {
    return this->context_->subscribe_out_avail (
    c
    ACE_ENV_ARG_PARAMETER);
  }

  ::BasicSP::DataAvailableConsumer_ptr
  BMClosedED_Servant::unsubscribe_out_avail (
  ::Components::Cookie *ck
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidConnection))
  {
    return this->context_->unsubscribe_out_avail (
    ck
    ACE_ENV_ARG_PARAMETER);
  }

  BMClosedED_Servant::DataAvailableConsumer_in_avail_Servant::DataAvailableConsumer_in_avail_Servant (
  ::BasicSP::CCM_BMClosedED_ptr executor,
  ::BasicSP::CCM_BMClosedED_Context_ptr c)
  : executor_ (::BasicSP::CCM_BMClosedED::_duplicate (executor)),
  ctx_ (::BasicSP::CCM_BMClosedED_Context::_duplicate (c))
  {
  }

  BMClosedED_Servant::DataAvailableConsumer_in_avail_Servant::~DataAvailableConsumer_in_avail_Servant (void)
  {
  }

  CORBA::Object_ptr
  BMClosedED_Servant::DataAvailableConsumer_in_avail_Servant::_get_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->ctx_->get_CCM_object (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  void
  BMClosedED_Servant::DataAvailableConsumer_in_avail_Servant::push_DataAvailable (
  ::BasicSP::DataAvailable *evt
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    this->executor_->push_in_avail (
    evt
    ACE_ENV_ARG_PARAMETER);
  }

  // Inherited from ::Components::EventConsumerBase.
  void
  BMClosedED_Servant::DataAvailableConsumer_in_avail_Servant::push_event (
  ::Components::EventBase *ev
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::BadEventType))
  {
    ::BasicSP::DataAvailable_var ev_type =
    ::BasicSP::DataAvailable::_downcast (ev);

    if (ev_type != 0)
    {
      this->push_DataAvailable (
      ev_type.in ()
      ACE_ENV_SINGLE_ARG_PARAMETER);

      return;
    }

    ACE_THROW (::Components::BadEventType ());
  }

  ::BasicSP::DataAvailableConsumer_ptr
  BMClosedED_Servant::get_consumer_in_avail (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    if (CORBA::is_nil (this->consumes_in_avail_.in ()))
    {
      BMClosedED_Servant::DataAvailableConsumer_in_avail_Servant *svt =
      new BMClosedED_Servant::DataAvailableConsumer_in_avail_Servant (
      this->executor_.in (),
      this->context_);
      PortableServer::ServantBase_var safe_servant (svt);

      CORBA::Object_var obj =
      this->container_->install_servant (
      svt
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::DataAvailableConsumer::_nil ());

      ::BasicSP::DataAvailableConsumer_var eco =
      ::BasicSP::DataAvailableConsumer::_narrow (
      obj.in ()
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (::BasicSP::DataAvailableConsumer::_nil ());

      this->consumes_in_avail_ = eco;
    }

    return ::BasicSP::DataAvailableConsumer::_duplicate (this->consumes_in_avail_.in ());
  }

  // Operations for Navigation interface.

  CORBA::Object_ptr
  BMClosedED_Servant::provide_facet (
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

    if (ACE_OS::strcmp (name, "dataout") == 0)
    {
      return this->provide_dataout (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::CORBA::Object::_nil ());
  }

  ::Components::FacetDescriptions *
  BMClosedED_Servant::get_all_facets (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::FacetDescriptions *
  BMClosedED_Servant::get_named_facets (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  CORBA::Boolean
  BMClosedED_Servant::same_component (
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
  BMClosedED_Servant::connect (
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

    if (ACE_OS::strcmp (name, "datain") == 0)
    {
      ::BasicSP::ReadData_var _ciao_conn =
      ::BasicSP::ReadData::_narrow (
      connection
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (::CORBA::is_nil (_ciao_conn.in ()))
      {
        ACE_THROW_RETURN (::Components::InvalidConnection (), 0);
      }

      // Simplex connect.
      this->connect_datain (
      _ciao_conn.in ()
      ACE_ENV_ARG_PARAMETER);

      return 0;
    }

    ACE_THROW_RETURN (::Components::InvalidName (), 0);
  }

  CORBA::Object_ptr
  BMClosedED_Servant::disconnect (
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

    if (ACE_OS::strcmp (name, "datain") == 0)
    {
      // Simplex disconnect.
      return this->disconnect_datain (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::CORBA::Object::_nil ());
  }

  ::Components::ConnectionDescriptions *
  BMClosedED_Servant::get_connections (
  const char *name
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ReceptacleDescriptions *
  BMClosedED_Servant::get_all_receptacles (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ReceptacleDescriptions *
  BMClosedED_Servant::get_named_receptacles (
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
  BMClosedED_Servant::get_consumer (
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

    if (ACE_OS::strcmp (sink_name, "in_avail") == 0)
    {
      return this->get_consumer_in_avail (ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::Components::EventConsumerBase::_nil ());
  }

  ::Components::Cookie *
  BMClosedED_Servant::subscribe (
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

    if (ACE_OS::strcmp (publisher_name, "out_avail") == 0)
    {
      ::BasicSP::DataAvailableConsumer_var _ciao_consumer =
      ::BasicSP::DataAvailableConsumer::_narrow (
      subscribe
      ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (::CORBA::is_nil (_ciao_consumer.in ()))
      {
        ACE_THROW_RETURN (::Components::InvalidConnection (), 0);
      }

      return this->subscribe_out_avail (
      _ciao_consumer.in ()
      ACE_ENV_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (::Components::InvalidName (), 0);
  }

  ::Components::EventConsumerBase_ptr
  BMClosedED_Servant::unsubscribe (
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

    if (ACE_OS::strcmp (publisher_name, "out_avail") == 0)
    {
      return this->unsubscribe_out_avail (
      ck
      ACE_ENV_ARG_PARAMETER);
    }

    ACE_THROW_RETURN (
    ::Components::InvalidName (),
    ::Components::EventConsumerBase::_nil ());
  }

  void
  BMClosedED_Servant::connect_consumer (
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
  BMClosedED_Servant::disconnect_consumer (
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
  BMClosedED_Servant::get_all_consumers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::ConsumerDescriptions *
  BMClosedED_Servant::get_named_consumers (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::EmitterDescriptions *
  BMClosedED_Servant::get_all_emitters (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::EmitterDescriptions *
  BMClosedED_Servant::get_named_emitters (
  const ::Components::NameList &names
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidName))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::PublisherDescriptions *
  BMClosedED_Servant::get_all_publishers (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (::CORBA::NO_IMPLEMENT (), 0);
  }

  ::Components::PublisherDescriptions *
  BMClosedED_Servant::get_named_publishers (
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
  BMClosedED_Servant::get_component_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  ::Components::CCMHome_ptr
  BMClosedED_Servant::get_ccm_home (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return this->context_->get_CCM_home (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  ::Components::PrimaryKeyBase *
  BMClosedED_Servant::get_primary_key (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::NoKeyAvailable))
  {
    ACE_THROW_RETURN (::Components::NoKeyAvailable (), 0);
  }

  void
  BMClosedED_Servant::configuration_complete (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::InvalidConfiguration))
  {
    // CIAO to-do
  }

  void
  BMClosedED_Servant::remove (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::RemoveFailure))
  {
    // CIAO to-do
  }

  ::Components::ComponentPortDescription *
  BMClosedED_Servant::get_all_ports (
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
  BMClosedED_Servant::_get_component (
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
  BMClosedED_Servant::_ciao_activate (
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
  BMClosedED_Servant::_ciao_passivate (
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


  BMClosedEDHome_Servant::BMClosedEDHome_Servant (
  ::BasicSP::CCM_BMClosedEDHome_ptr exe,
  ::CIAO::Session_Container *c)
  : executor_ (::BasicSP::CCM_BMClosedEDHome::_duplicate (exe)),
  container_ (c)
  {
  }

  BMClosedEDHome_Servant::~BMClosedEDHome_Servant (void)
  {
  }

  // Operations for keyless home interface.

  ::Components::CCMObject_ptr
  BMClosedEDHome_Servant::create_component (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CreateFailure))
  {
    return this->create (ACE_ENV_SINGLE_ARG_PARAMETER);
  }

  // Operations for implicit home interface.

  ::BasicSP::BMClosedED_ptr
  BMClosedEDHome_Servant::create (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CreateFailure))
  {
    if (this->executor_.in () == 0)
    {
      ACE_THROW_RETURN (
      ::CORBA::INTERNAL (),
      ::BasicSP::BMClosedED::_nil ());
    }

    Components::EnterpriseComponent_var _ciao_ec =
    this->executor_->create (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::BMClosedED::_nil ());

    ::BasicSP::CCM_BMClosedED_var _ciao_comp =
    ::BasicSP::CCM_BMClosedED::_narrow (
    _ciao_ec.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::BMClosedED::_nil ());

    return this->_ciao_activate_component (
    _ciao_comp.in ()
    ACE_ENV_ARG_PARAMETER);
  }

  // Operations for CCMHome interface.

  ::CORBA::IRObject_ptr
  BMClosedEDHome_Servant::get_component_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  ::CORBA::IRObject_ptr
  BMClosedEDHome_Servant::get_home_def (
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_THROW_RETURN (
    ::CORBA::NO_IMPLEMENT (),
    ::CORBA::IRObject::_nil ());
  }

  void
  BMClosedEDHome_Servant::remove_component (
  ::Components::CCMObject_ptr comp
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::RemoveFailure))
  {
    ::BasicSP::BMClosedED_var _ciao_comp =
    ::BasicSP::BMClosedED::_narrow (
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

  ::BasicSP::BMClosedED_ptr
  BMClosedEDHome_Servant::_ciao_activate_component (
  ::BasicSP::CCM_BMClosedED_ptr exe
  ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ::CORBA::Object_var hobj =
    this->container_->get_objref (
    this
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::BMClosedED::_nil ());

    ::Components::CCMHome_var home =
    ::Components::CCMHome::_narrow (
    hobj
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::BMClosedED::_nil ());

    BMClosedED_Servant *svt =
    new BMClosedED_Servant (
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
    ACE_CHECK_RETURN (::BasicSP::BMClosedED::_nil ());

    svt->_ciao_activate (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::BMClosedED::_nil ());

    ::BasicSP::BMClosedED_var ho =
    ::BasicSP::BMClosedED::_narrow (
    objref.in ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (::BasicSP::BMClosedED::_nil ());

    if (this->component_map_.bind (oid.in (), svt) == 0)
    {
      safe._retn ();
    }

    return ho._retn ();
  }

  void
  BMClosedEDHome_Servant::_ciao_passivate_component (
  ::BasicSP::BMClosedED_ptr comp
  ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    PortableServer::ObjectId_var oid;

    this->container_->uninstall_component (
    comp,
    oid.out ()
    ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;

    BMClosedED_Servant *servant = 0;

    if (this->component_map_.unbind (oid.in (), servant) == 0)
    {
      PortableServer::ServantBase_var safe (servant);
      servant->_ciao_passivate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;
    }
  }

  // Supported operations.

  // START new event code
  out_avail_Supplier_impl::out_avail_Supplier_impl (void)
  {
  }

  out_avail_Supplier_impl::out_avail_Supplier_impl (CORBA::ORB_ptr orb) :
    orb_ (CORBA::ORB::_duplicate (orb))
  {
  }
  
  void out_avail_Supplier_impl::disconnect_push_supplier (void)
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

  out_avail_Consumer_impl::out_avail_Consumer_impl (void)
  {
  }

  out_avail_Consumer_impl::out_avail_Consumer_impl (CORBA::ORB_ptr orb,
                                                ::BasicSP::DataAvailableConsumer_ptr out_avail_consumer) :
    orb_ (CORBA::ORB::_duplicate (orb)),
    out_avail_consumer_ (::BasicSP::DataAvailableConsumer::_duplicate (out_avail_consumer))
  {
  }

  void out_avail_Consumer_impl::push (const RtecEventComm::EventSet& events)
  {
    ACE_DEBUG ((LM_DEBUG, "CIAO_GLUE_BasicSP::out_avail_Consumer_impl::push\n"));
    for (unsigned long i = 0; i < events.length (); i++)
      {
        ::BasicSP::DataAvailable * ev;
        if (events[i].data.any_value >>= ev)
          {
            this->out_avail_consumer_->push_DataAvailable (ev
                                             ACE_ENV_ARG_PARAMETER);
            ACE_CHECK;
          }
      }
  }

  void out_avail_Consumer_impl::disconnect_push_consumer (void)
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

extern "C" BMCLOSEDED_SVNT_Export ::PortableServer::Servant
createBMClosedEDHome_Servant (
::Components::HomeExecutorBase_ptr p,
CIAO::Session_Container *c
ACE_ENV_ARG_DECL)
{
  if (p == 0)
  {
    return 0;
  }

  ::BasicSP::CCM_BMClosedEDHome_var x =
  ::BasicSP::CCM_BMClosedEDHome::_narrow (
  p
  ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (::CORBA::is_nil (x.in ()))
  {
    return 0;
  }

  return new
  ::CIAO_GLUE_BasicSP::BMClosedEDHome_Servant (
  x.in (),
  c);
}

