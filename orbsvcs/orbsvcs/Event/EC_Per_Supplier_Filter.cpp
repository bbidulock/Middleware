// $Id$

#include "EC_Per_Supplier_Filter.h"
#include "EC_Event_Channel.h"
#include "EC_ProxyPushSupplier_Set.h"
#include "EC_ProxySupplier.h"
#include "EC_ProxyConsumer.h"
#include "EC_Scheduling_Strategy.h"
#include "EC_QOS_Info.h"
#include "orbsvcs/Event_Service_Constants.h"

#if ! defined (__ACE_INLINE__)
#include "EC_Per_Supplier_Filter.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Event, EC_Per_Supplier_Filter, "$Id$")

TAO_EC_Per_Supplier_Filter::
    TAO_EC_Per_Supplier_Filter (TAO_EC_Event_Channel* ec)
  :  event_channel_ (ec),
     consumer_ (0),
     refcnt_ (1)
{
  this->supplier_set_ =
    this->event_channel_->create_proxy_push_supplier_set ();
  this->supplier_set_->busy_hwm (this->event_channel_->busy_hwm ());
  this->supplier_set_->max_write_delay (this->event_channel_->max_write_delay ());
}

TAO_EC_Per_Supplier_Filter::~TAO_EC_Per_Supplier_Filter (void)
{
  this->event_channel_->destroy_proxy_push_supplier_set (this->supplier_set_);
  this->supplier_set_ = 0;
}

void
TAO_EC_Per_Supplier_Filter::bind (TAO_EC_ProxyPushConsumer* consumer)
{
  ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock_);

  if (this->consumer_ != 0)
    return;

  this->consumer_ = consumer;
}

void
TAO_EC_Per_Supplier_Filter::unbind (TAO_EC_ProxyPushConsumer* consumer)
{
  ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock_);

  if (this->consumer_ == 0 || this->consumer_ != consumer)
    return;

  this->consumer_ = 0;

  ACE_TRY_NEW_ENV
    {
      this->shutdown (ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      // @@ Ignore exceptions
    }
  ACE_ENDTRY;
}

void
TAO_EC_Per_Supplier_Filter::connected (TAO_EC_ProxyPushSupplier* supplier,
                                       CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock_);

  if (this->consumer_ == 0)
    return;

  const RtecEventChannelAdmin::SupplierQOS& pub =
    this->consumer_->publications_i ();

  for (CORBA::ULong j = 0; j < pub.publications.length (); ++j)
    {
      const RtecEventComm::Event& event =
        pub.publications[j].event;

      //      ACE_DEBUG ((LM_DEBUG, "Trying %d:%d in %x\n",
      //                  event.header.source, event.header.type,
      //                  this));
      if (supplier->can_match (event.header))
        {
          //          ACE_DEBUG ((LM_DEBUG, "  matched %x\n", supplier));
          this->supplier_set_->connected (supplier, ACE_TRY_ENV);
          return;
        }
    }
}

void
TAO_EC_Per_Supplier_Filter::reconnected (TAO_EC_ProxyPushSupplier* supplier,
                                         CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock_);

  if (this->consumer_ == 0)
    return;

  const RtecEventChannelAdmin::SupplierQOS& pub =
    this->consumer_->publications_i ();

  for (CORBA::ULong j = 0; j < pub.publications.length (); ++j)
    {
      const RtecEventComm::Event& event =
        pub.publications[j].event;

      //      ACE_DEBUG ((LM_DEBUG, "Trying %d:%d in %x\n",
      //                  event.header.source, event.header.type,
      //                  this));
      if (supplier->can_match (event.header))
        {
          //          ACE_DEBUG ((LM_DEBUG, "  matched %x\n", supplier));
          this->supplier_set_->connected (supplier, ACE_TRY_ENV);
          return;
        }
    }
  this->supplier_set_->disconnected (supplier, ACE_TRY_ENV);
}

void
TAO_EC_Per_Supplier_Filter::disconnected (TAO_EC_ProxyPushSupplier* supplier,
                                          CORBA::Environment &ACE_TRY_ENV)
{
  this->supplier_set_->disconnected (supplier, ACE_TRY_ENV);
}

void
TAO_EC_Per_Supplier_Filter::shutdown (CORBA::Environment &ACE_TRY_ENV)
{
  this->supplier_set_->shutdown (ACE_TRY_ENV);
}

void
TAO_EC_Per_Supplier_Filter::push (const RtecEventComm::EventSet& event,
                                     CORBA::Environment &ACE_TRY_ENV)
{
  TAO_EC_Scheduling_Strategy* scheduling_strategy =
    this->event_channel_->scheduling_strategy ();
  for (CORBA::ULong j = 0; j < event.length (); ++j)
    {
      const RtecEventComm::Event& e = event[j];
      RtecEventComm::Event* buffer =
        ACE_const_cast(RtecEventComm::Event*, &e);
      RtecEventComm::EventSet single_event (1, 1, buffer, 0);

      TAO_EC_QOS_Info event_info;
      {
        // We need to grab the mutex to check that we are not
        // disconnected.
        // @@ This lock could be optimized if we knew that the
        // scheduling strategy is trivial...
        ACE_GUARD (ACE_SYNCH_MUTEX, ace_mon, this->lock_);

        if (this->consumer_ == 0)
          return;

        scheduling_strategy->init_event_qos (e.header,
                                             this->consumer_,
                                             event_info,
                                             ACE_TRY_ENV);
        ACE_CHECK;
      }

      // We don't use the consumer_ field anymore, just the
      // supplier_set_, and that one is safe until we reach the
      // destructor.  However, the caller has to increase the
      // reference count before calling us, i.e. we won't be destroyed
      // until push() returns.

      ACE_GUARD_THROW_EX (TAO_EC_ProxyPushSupplier_Set::Busy_Lock,
          ace_mon, this->supplier_set_->busy_lock (),
          RtecEventChannelAdmin::EventChannel::SYNCHRONIZATION_ERROR ());
      ACE_CHECK;

      TAO_EC_ProxyPushSupplier_Set::SupplierSetIterator end =
        this->supplier_set_->end ();

      for (TAO_EC_ProxyPushSupplier_Set::SupplierSetIterator i =
             this->supplier_set_->begin ();
           i != end;
           ++i)
        {
          TAO_EC_QOS_Info qos_info = event_info;

          (*i)->filter (single_event, qos_info, ACE_TRY_ENV);
          ACE_CHECK;
        }
    }
}

CORBA::ULong
TAO_EC_Per_Supplier_Filter::_incr_refcnt (void)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, 0);

  this->refcnt_++;
  return this->refcnt_;
}

CORBA::ULong
TAO_EC_Per_Supplier_Filter::_decr_refcnt (void)
{
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->lock_, 0);

    this->refcnt_--;
    if (this->refcnt_ != 0)
      return this->refcnt_;
  }
  this->event_channel_->supplier_filter_builder ()->destroy (this);
  return 0;
}

// ****************************************************************

TAO_EC_Supplier_Filter*
TAO_EC_Per_Supplier_Filter_Builder::create (
    RtecEventChannelAdmin::SupplierQOS&)
{
  return new TAO_EC_Per_Supplier_Filter (this->event_channel_);
}

void
TAO_EC_Per_Supplier_Filter_Builder::destroy (
    TAO_EC_Supplier_Filter* x)
{
  delete x;
}
