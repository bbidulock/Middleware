// $Id$
#include "EventChannel_i.h"

EventChannel_i::EventChannel_i (void)
  : consumer_admin_ (),
    supplier_admin_ (),
    consumeradmin_ (0),
    supplieradmin_ (0)
{
  // No-Op.
}

EventChannel_i::~EventChannel_i (void)
{
  //No-Op.
}

int
EventChannel_i::init (const RtecEventChannelAdmin::ConsumerQOS &consumerqos,
                      const RtecEventChannelAdmin::SupplierQOS &supplierqos,
                      RtecEventChannelAdmin::EventChannel_ptr rtec,
                      CORBA::Environment &TAO_TRY_ENV)
{
  RtecEventChannelAdmin::ConsumerAdmin_ptr rtec_consumeradmin = 
    rtec->for_consumers (TAO_TRY_ENV);
  TAO_CHECK_ENV_RETURN (TAO_TRY_ENV, -1);

  // @@ Pradeep, make sure to check the return value of this and
  // handle failures correctly.
  this->consumer_admin_.init (consumerqos,
                              rtec_consumeradmin);

  this->consumeradmin_ = consumer_admin_._this (TAO_TRY_ENV);
  TAO_CHECK_ENV_RETURN (TAO_TRY_ENV, -1);

  RtecEventChannelAdmin::SupplierAdmin_ptr rtec_supplieradmin =
    rtec->for_suppliers (TAO_TRY_ENV);
  TAO_CHECK_ENV_RETURN (TAO_TRY_ENV, -1);

  // @@ Pradeep, make sure to check the return value of this and
  // handle failures correctly.
  this->supplier_admin_.init (supplierqos,
                              rtec_supplieradmin);

  this->supplieradmin_ = supplier_admin_._this (TAO_TRY_ENV);
  TAO_CHECK_ENV_RETURN (TAO_TRY_ENV, -1);

  return 0;
}

CosEventChannelAdmin::ConsumerAdmin_ptr
EventChannel_i::for_consumers (CORBA::Environment &TAO_TRY_ENV)
{
  return this->consumeradmin_;
}

CosEventChannelAdmin::SupplierAdmin_ptr
EventChannel_i::for_suppliers (CORBA::Environment &TAO_TRY_ENV)
{
  return this->supplieradmin_;
}

void
EventChannel_i::destroy (CORBA::Environment &TAO_TRY_ENV)
{
  // Deactivate the CosEventChannel
  PortableServer::POA_var poa =
    this->_default_POA (TAO_TRY_ENV);
  TAO_CHECK_ENV_RETURN_VOID (TAO_TRY_ENV);

  PortableServer::ObjectId_var id = poa->servant_to_id (this,
                                                        TAO_TRY_ENV);

  TAO_CHECK_ENV_RETURN_VOID (TAO_TRY_ENV);

  poa->deactivate_object (id.in (),
                          TAO_TRY_ENV);
  TAO_CHECK_ENV_RETURN_VOID (TAO_TRY_ENV);
}

void
EventChannel_i::shutdown (CORBA::Environment &TAO_TRY_ENV)
{
  this->destroy (TAO_TRY_ENV);
  delete this;
}
