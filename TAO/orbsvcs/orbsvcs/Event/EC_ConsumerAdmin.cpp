// $Id$

#include "orbsvcs/RtecEventChannelAdminC.h"
#include "EC_ConsumerAdmin.h"
#include "EC_ProxySupplier.h"
#include "EC_Event_Channel.h"
#include "EC_Command.h"

#if ! defined (__ACE_INLINE__)
#include "EC_ConsumerAdmin.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Event, EC_ConsumerAdmin, "$Id$")

TAO_EC_ConsumerAdmin::TAO_EC_ConsumerAdmin (TAO_EC_Event_Channel *ec,
                                            TAO_EC_ProxyPushSupplier_Set* ss)
  :  event_channel_ (ec),
     supplier_set_ (ss)
{
  if (this->supplier_set_ == 0)
    {
      this->supplier_set_ =
        this->event_channel_->create_proxy_push_supplier_set ();
    }
}

TAO_EC_ConsumerAdmin::~TAO_EC_ConsumerAdmin (void)
{
  this->event_channel_->destroy_proxy_push_supplier_set (this->supplier_set_);
  this->supplier_set_ = 0;
}

void
TAO_EC_ConsumerAdmin::set_default_POA (PortableServer::POA_ptr poa)
{
  this->default_POA_ =
    PortableServer::POA::_duplicate (poa);
}

void
TAO_EC_ConsumerAdmin::connected (TAO_EC_ProxyPushConsumer *consumer,
				 CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD_THROW (TAO_EC_ConsumerAdmin::Busy_Lock,
      ace_mon, this->busy_lock (),
      RtecEventChannelAdmin::EventChannel::SYNCHRONIZATION_ERROR ());

  SupplierSetIterator end = this->end ();
  for (SupplierSetIterator i = this->begin ();
       i != end;
       ++i)
    {
      (*i)->connected (consumer, ACE_TRY_ENV);
      ACE_CHECK;
    }
}

void
TAO_EC_ConsumerAdmin::disconnected (TAO_EC_ProxyPushConsumer *consumer,
				    CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD_THROW (TAO_EC_ConsumerAdmin::Busy_Lock,
      ace_mon, this->busy_lock (),
      RtecEventChannelAdmin::EventChannel::SYNCHRONIZATION_ERROR ());

  SupplierSetIterator end = this->end ();
  for (SupplierSetIterator i = this->begin ();
       i != end;
       ++i)
    {
      (*i)->disconnected (consumer, ACE_TRY_ENV);
      ACE_CHECK;
    }
}

void
TAO_EC_ConsumerAdmin::connected (TAO_EC_ProxyPushSupplier *supplier,
				 CORBA::Environment &ACE_TRY_ENV)
{
  this->supplier_set_->connected (supplier, ACE_TRY_ENV);
}

void
TAO_EC_ConsumerAdmin::disconnected (TAO_EC_ProxyPushSupplier *supplier,
				    CORBA::Environment &ACE_TRY_ENV)
{
  this->supplier_set_->disconnected (supplier, ACE_TRY_ENV);
}

RtecEventChannelAdmin::ProxyPushSupplier_ptr
TAO_EC_ConsumerAdmin::obtain_push_supplier (CORBA::Environment &ACE_TRY_ENV)
{
  TAO_EC_ProxyPushSupplier* supplier =
    this->event_channel_->create_proxy_push_supplier ();

  PortableServer::POA_var poa =
    this->event_channel_->supplier_poa (ACE_TRY_ENV);
  supplier->set_default_POA (poa.in ());

  return supplier->_this (ACE_TRY_ENV);
}

PortableServer::POA_ptr
TAO_EC_ConsumerAdmin::_default_POA (CORBA::Environment&)
{
  return PortableServer::POA::_duplicate (this->default_POA_.in ());
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
