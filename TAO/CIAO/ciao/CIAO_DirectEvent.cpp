// -*- C++ -*-

//=============================================================================
/**
 *  @file CIAO_DirectEvent.cpp
 *
 *  $Id$
 *
 *  @author George Edwards <g.edwards@vanderbilt.edu>
 */
//=============================================================================

#include "CIAO_DirectEvent.h"

namespace CIAO
{

  DirectEventService::DirectEventService (
    CORBA::ORB_ptr orb,
    PortableServer::POA_ptr poa) :
  orb_ (CORBA::ORB::_duplicate (orb)),
  root_poa_ (PortableServer::POA::_duplicate (poa))
  {
  }

  void
  DirectEventService::connect_event_supplier (
      Supplier_Config_ptr supplier_config
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
  }

  void
  DirectEventService::connect_event_consumer (
      Consumer_Config_ptr consumer_config
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {

    // @@ George, Any reason not to use ACE_NEW_THROW_EX (). Exceptions
    // comes free then.
    Components::EventConsumerBase_var consumer =
      consumer_config->consumer (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;

    this->consumer_array_.set (consumer._retn (),
                               this->consumer_array_.size ());

  }

  void
  DirectEventService::disconnect_event_consumer (
      const char * connection_id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      Components::InvalidName,
      Components::InvalidConnection))
  {
  }

  void
  DirectEventService::disconnect_event_supplier (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      Components::InvalidName,
      Components::InvalidConnection))
  {
  }


  void
  DirectEventService::push_event (
      Components::EventBase * ev
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    ACE_DEBUG ((LM_DEBUG, "CIAO::DirectEventService::push_event\n"));

    size_t end = this->consumer_array_.size ();

    // Iterate through the array, pushing the event to each consumer.
    for (size_t iter = 0; iter < end; ++iter)
      {
        ev->_add_ref ();
        this->consumer_array_[iter]->push_event (
          ev
          ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }
  }

  Direct_Consumer_Config_impl::Direct_Consumer_Config_impl () :
    service_type_ (DIRECT)
  {
  }

  void
  Direct_Consumer_Config_impl::consumer_id (
      const char * consumer_id 
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    this->consumer_id_ = consumer_id;
  }

  void
  Direct_Consumer_Config_impl::supplier_id (
      const char * supplier_id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    this->supplier_id_ = supplier_id;
  }

  void
  Direct_Consumer_Config_impl::consumer (
      Components::EventConsumerBase_ptr consumer
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    this->consumer_ = consumer;
  }

  CONNECTION_ID
  Direct_Consumer_Config_impl::consumer_id (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return CORBA::string_dup (this->consumer_id_.c_str ());
  }

  CONNECTION_ID
  Direct_Consumer_Config_impl::supplier_id (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return CORBA::string_dup (this->supplier_id_.c_str ());
  }

  EventServiceType
  Direct_Consumer_Config_impl::service_type (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return this->service_type_;
  }

  Components::EventConsumerBase_ptr
  Direct_Consumer_Config_impl::consumer (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return Components::EventConsumerBase::_duplicate (this->consumer_.in ());
  }

  Direct_Supplier_Config_impl::Direct_Supplier_Config_impl () :
    service_type_ (DIRECT)
  {
  }

  void
  Direct_Supplier_Config_impl::supplier_id (
      const char * supplier_id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    this->supplier_id_ = supplier_id;
  }

  CONNECTION_ID
  Direct_Supplier_Config_impl::supplier_id (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return CORBA::string_dup (this->supplier_id_.c_str ());
  }

  EventServiceType
  Direct_Supplier_Config_impl::service_type (
      ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException))
  {
    return this->service_type_;
  }

}
