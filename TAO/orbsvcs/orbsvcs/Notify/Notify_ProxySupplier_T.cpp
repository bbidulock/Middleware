// $Id$

#ifndef TAO_NOTIFY_PROXYSUPPLIER_T_C
#define TAO_NOTIFY_PROXYSUPPLIER_T_C

#include "Notify_ProxySupplier_T.h"
#include "Notify_Event_Manager.h"
#include "Notify_ConsumerAdmin_i.h"
#include "Notify_Factory.h"
#include "Notify_Channel_Objects_Factory.h"

ACE_RCSID(Notify, Notify_ProxySupplier_T, "$Id$")

template <class SERVANT_TYPE>
TAO_Notify_ProxySupplier<SERVANT_TYPE>::TAO_Notify_ProxySupplier (TAO_Notify_ConsumerAdmin_i* consumer_admin)
  :consumer_admin_ (consumer_admin),
   is_suspended_ (0)
{
  event_manager_ = consumer_admin->get_event_manager ();
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::init (CosNotifyChannelAdmin::ProxyID proxy_id, CORBA::Environment& ACE_TRY_ENV)
{
  consumer_admin_->_add_ref (ACE_TRY_ENV);

  this->proxy_id_ = proxy_id;

  TAO_Notify_CO_Factory* cof =
    TAO_Notify_Factory::get_channel_objects_factory ();

  this->lock_ = cof->create_proxy_supplier_lock (ACE_TRY_ENV);
}

// Implementation skeleton destructor
template <class SERVANT_TYPE>
TAO_Notify_ProxySupplier<SERVANT_TYPE>::~TAO_Notify_ProxySupplier (void)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  this->event_manager_->unregister_from_publication_updates (this,
                                                             ACE_TRY_ENV);

  // unsubscribe it to our current subscriptions.
  CosNotification::EventTypeSeq added (0);
  CosNotification::EventTypeSeq removed (this->subscription_list_.size ());

  this->subscription_list_.populate (removed);
  added.length (0);

  this->event_manager_->subscribe_for_events (this,
                                              added, removed, ACE_TRY_ENV);

  delete this->lock_;

  this->consumer_admin_->proxy_pushsupplier_destroyed (this->proxy_id_);
  consumer_admin_->_remove_ref (ACE_TRY_ENV);
}

template <class SERVANT_TYPE> CORBA::Boolean
TAO_Notify_ProxySupplier<SERVANT_TYPE>::evaluate_filter (TAO_Notify_Event &event, CORBA::Boolean eval_parent, CORBA::Environment &ACE_TRY_ENV)
{
  if (eval_parent == 1)
    {
      CosNotifyChannelAdmin::InterFilterGroupOperator filter_operator =
        consumer_admin_->MyOperator (ACE_TRY_ENV);
      // Inter-filter group operator.

      CORBA::Boolean bval =
        this->consumer_admin_->get_filter_admin ().match (event, ACE_TRY_ENV);
      ACE_CHECK_RETURN (0);

      if ((bval == 1 && filter_operator == CosNotifyChannelAdmin::AND_OP) ||
          (bval == 0 && filter_operator == CosNotifyChannelAdmin::OR_OP))
        {
          return this->filter_admin_.match (event, ACE_TRY_ENV);
        }
      else if (bval == 1 && filter_operator == CosNotifyChannelAdmin::OR_OP)
        return 1;
      else
        return 0;
    }
  else
    return this->filter_admin_.match (event, ACE_TRY_ENV);
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::dispatch_event (TAO_Notify_Event &event, CORBA::Environment &ACE_TRY_ENV)
{
  if (this->is_connected_ == 0)
    {
      ACE_DEBUG ((LM_DEBUG,"%t, %p",
                  "dispatch_event to disconnected proxy supplier from EC\n"));
      return;
    }

  if (this->is_suspended_ == 1)
    {
      ACE_GUARD_THROW_EX (ACE_Lock, ace_mon, *this->lock_,
                          CORBA::INTERNAL ());
      ACE_CHECK;

      this->event_list_.enqueue_tail (event.clone ());
    }
  else
    this->dispatch_event_i (event, ACE_TRY_ENV);
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::subscription_change (const CosNotification::EventTypeSeq & added, const CosNotification::EventTypeSeq & removed, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyComm::InvalidEventType
                   ))
{
  if (this->is_connected_ == 1)
    {
      this->event_manager_->subscribe_for_events (this,
                                                  added, removed, ACE_TRY_ENV);
    }

  {
    ACE_GUARD_THROW_EX (ACE_Lock, ace_mon, *this->lock_,
                        CORBA::INTERNAL ());
    ACE_CHECK;

    // simply update our subscription list.
    this->subscription_list_.insert_seq (added);
    this->subscription_list_.remove_seq (removed);
  }
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::on_connected (CORBA::Environment &ACE_TRY_ENV)
{
  // register with CA
  this->consumer_admin_->register_listener (this, ACE_TRY_ENV);
  ACE_CHECK;

  CosNotification::EventTypeSeq added;

  CosNotification::EventTypeSeq removed (0);
  removed.length (0);

  // subscribe it to our current subscriptions.
  added.length (this->subscription_list_.size ());

  this->subscription_list_.populate (added);

  this->event_manager_->subscribe_for_events (this,
                                              added, removed, ACE_TRY_ENV);
  ACE_CHECK;

  this->event_manager_->register_for_publication_updates (this, ACE_TRY_ENV);
  ACE_CHECK;
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::on_disconnected (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_GUARD_THROW_EX (ACE_Lock, ace_mon, *this->lock_,
                      CORBA::INTERNAL ());
  ACE_CHECK;

  if (this->is_connected_ == 0)
    return;

  this->is_connected_ = 0;

  CosNotification::EventTypeSeq removed;

  CosNotification::EventTypeSeq added (0);
  added.length (0);

    // unsubscribe it to our current subscriptions.
  removed.length (this->subscription_list_.size ());

  this->subscription_list_.populate (removed);

  this->event_manager_->subscribe_for_events (this,
                                              added, removed, ACE_TRY_ENV);
  ACE_CHECK;

  this->event_manager_->unregister_from_publication_updates (this, ACE_TRY_ENV);
  ACE_CHECK;
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::suspend_connection (CORBA::Environment &/*ACE_TRY_ENV*/)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyChannelAdmin::ConnectionAlreadyInactive,
                   CosNotifyChannelAdmin::NotConnected
                   ))
{
  this->is_suspended_ = 1;
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::resume_connection (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyChannelAdmin::ConnectionAlreadyActive,
                   CosNotifyChannelAdmin::NotConnected
                   ))
{
  TAO_Notify_Event* event;

  this->is_suspended_ = 0;

  {
    ACE_GUARD_THROW_EX (ACE_Lock, ace_mon, *this->lock_,
                        CORBA::INTERNAL ());
    ACE_CHECK;

    while (this->event_list_.dequeue_head (event) == 0)
      {
        this->dispatch_event_i (*event, ACE_TRY_ENV);
        delete event;
      }
  }
}

template <class SERVANT_TYPE> CosNotifyChannelAdmin::ConsumerAdmin_ptr
TAO_Notify_ProxySupplier<SERVANT_TYPE>::MyAdmin (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  return this->consumer_admin_->get_ref (ACE_TRY_ENV);
}

template <class SERVANT_TYPE> CosNotifyFilter::MappingFilter_ptr
TAO_Notify_ProxySupplier<SERVANT_TYPE>::priority_filter (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (),
                    CosNotifyFilter::MappingFilter::_nil ());
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::priority_filter (CosNotifyFilter::MappingFilter_ptr /*priority_filter*/, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

template <class SERVANT_TYPE> CosNotifyFilter::MappingFilter_ptr
TAO_Notify_ProxySupplier<SERVANT_TYPE>::lifetime_filter (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (),
                    CosNotifyFilter::MappingFilter::_nil ());
}

template <class SERVANT_TYPE> void
TAO_Notify_ProxySupplier<SERVANT_TYPE>::lifetime_filter (CosNotifyFilter::MappingFilter_ptr /*lifetime_filter*/, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}

template <class SERVANT_TYPE> CosNotification::EventTypeSeq*
TAO_Notify_ProxySupplier<SERVANT_TYPE>::obtain_offered_types (CosNotifyChannelAdmin::ObtainInfoMode mode, CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  CosNotification::EventTypeSeq* event_type_seq = 0;

  if (mode == CosNotifyChannelAdmin::ALL_NOW_UPDATES_OFF ||
      mode == CosNotifyChannelAdmin::ALL_NOW_UPDATES_ON)
    {
      event_type_seq = this->event_manager_->obtain_offered_types ();
    }

  if (mode == CosNotifyChannelAdmin::NONE_NOW_UPDATES_ON ||
      mode == CosNotifyChannelAdmin::ALL_NOW_UPDATES_ON)
    {
      // if updates are currently off, switch them on.
      if (this->updates_on_ == 0)
        this->event_manager_->register_for_publication_updates (this,
                                                                ACE_TRY_ENV);
    }
  else
    {
      // if updates are currently on, switch them off.
      if (this->updates_on_ == 1)
        this->event_manager_->unregister_from_publication_updates (this,
                                                                   ACE_TRY_ENV);
    }
  return event_type_seq;
}

#endif /* TAO_NOTIFY_PROXYSUPPLIER_T_C */
