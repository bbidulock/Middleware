// $Id$

#include "SequencePushConsumer.h"

#if ! defined (__ACE_INLINE__)
#include "SequencePushConsumer.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Notify, TAO_NS_SequencePushConsumer, "$id$")

#include "ace/Reactor.h"
#include "tao/ORB_Core.h"
#include "../QoSProperties.h"
#include "../Properties.h"
#include "../ProxySupplier.h"
#include "../Worker_Task.h"
#include "../Consumer.h"
#include "Method_Request_Dispatch_EventBatch.h"
#include "EventBatch.h"

TAO_NS_SequencePushConsumer::TAO_NS_SequencePushConsumer (TAO_NS_ProxySupplier* proxy)
  :TAO_NS_Consumer (proxy), pacing_interval_ (CosNotification::PacingInterval), timer_id_ (-1)
{
}

TAO_NS_SequencePushConsumer::~TAO_NS_SequencePushConsumer ()
{
}

void
TAO_NS_SequencePushConsumer::init (CosNotifyComm::SequencePushConsumer_ptr push_consumer ACE_ENV_ARG_DECL_NOT_USED)
{
  this->push_consumer_ = CosNotifyComm::SequencePushConsumer::_duplicate (push_consumer);

  this->publish_ = CosNotifyComm::NotifyPublish::_duplicate (push_consumer);
}

void
TAO_NS_SequencePushConsumer::shutdown (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  // Get the ORB
  CORBA::ORB_var orb = TAO_NS_PROPERTIES::instance()->orb ();

  ACE_Reactor* reactor = orb->orb_core ()->reactor ();

  reactor->cancel_timer (this);
}

void
TAO_NS_SequencePushConsumer::release (void)
{
  delete this;
  //@@ inform factory
}

void
TAO_NS_SequencePushConsumer::qos_changed (const TAO_NS_QoSProperties& qos_properties)
{
  const TAO_NS_Property_Long& maximum_batch_size = qos_properties.maximum_batch_size ();

  if (maximum_batch_size.is_valid ())
    this->event_batch_.batch_size (maximum_batch_size.value ());

  this->pacing_interval_ = qos_properties.pacing_interval ();

  if (!this->pacing_interval_.is_valid ())
    this->pacing_interval_ = 0;
}

void
TAO_NS_SequencePushConsumer::schedule_timer (void)
{
  if (this->pacing_interval_ == 0)
    return;

  // Get the ORB
  CORBA::ORB_var orb = TAO_NS_PROPERTIES::instance()->orb ();

  ACE_Reactor* reactor = orb->orb_core ()->reactor ();

  TimeBase::TimeT pacing_interval = this->pacing_interval_.value();

# if defined (ACE_CONFIG_WIN32_H)
  ACE_Time_Value interval (ACE_static_cast (long, pacing_interval));
# else
  ACE_Time_Value interval (pacing_interval / 1);
# endif /* ACE_CONFIG_WIN32_H */

  // Schedule the timer.
  if (reactor->schedule_timer (this, 0, interval, interval) == -1)
    this->pacing_interval_ = 0;
}

void
TAO_NS_SequencePushConsumer::push_i (const TAO_NS_Event_var& event ACE_ENV_ARG_DECL_NOT_USED)
{
  {
    ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, *this->proxy_lock ());
    this->event_batch_.insert (event);

    if (this->event_batch_.size () == 1)
      this->schedule_timer ();
  }

  // If pacing is zero, there is no timer, hence dispatch immediately
  if (this->pacing_interval_ == 0 )
    this->handle_timeout (ACE_Time_Value::zero, 0);
}

void
TAO_NS_SequencePushConsumer::push (const CORBA::Any& /*event*/ ACE_ENV_ARG_DECL_NOT_USED)
{
  //NOP
}

void
TAO_NS_SequencePushConsumer::push (const CosNotification::StructuredEvent& /*notification*/ ACE_ENV_ARG_DECL_NOT_USED)
{
  //NOP
}

int
TAO_NS_SequencePushConsumer::handle_timeout (const ACE_Time_Value& /*current_time*/,
                                             const void* /*act*/)
{
  TAO_NS_Event_Collection event_collection;

  {
    ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, ace_mon, *this->proxy_lock (), 0);

    if (this->event_batch_.size () == 0)
      return -1; // Cancel the timer.

    this->event_batch_.extract (event_collection);
  }

  TAO_NS_Method_Request_Dispatch_EventBatch request (event_collection, this);

  this->proxy_->worker_task ()->exec (request);

  return 0;
}

void
TAO_NS_SequencePushConsumer::push (const TAO_NS_Event_Collection event_collection ACE_ENV_ARG_DECL)
{
  if (this->is_suspended_ == 1) // If we're suspended, queue for later delivery.
    {
      {
        ACE_GUARD (TAO_SYNCH_MUTEX, ace_mon, *this->proxy_lock ());
        this->event_batch_.insert (event_collection);
      }
    }

  ACE_TRY
    {
      CosNotification::EventBatch event_batch;

      TAO_NS_EventBatch::populate (event_collection, event_batch);

      this->push_consumer_->push_structured_events (event_batch ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCH (CORBA::OBJECT_NOT_EXIST, not_exist)
    {
      this->handle_dispatch_exception (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCH (CORBA::SystemException, sysex)
    {
      this->handle_dispatch_exception (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;
}
