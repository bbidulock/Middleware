// $Id$

#include "SequencePushConsumer.h"

#if ! defined (__ACE_INLINE__)
#include "SequencePushConsumer.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (Notify, TAO_Notify_SequencePushConsumer, "$Id$")

#include "ace/Reactor.h"
#include "tao/debug.h"
#include "../QoSProperties.h"
#include "../ProxySupplier.h"
#include "../Worker_Task.h"
#include "../Consumer.h"
#include "../Method_Request_Event.h"
#include "../Timer.h"
#include "../Proxy.h"
#include "../Properties.h"

TAO_Notify_SequencePushConsumer::TAO_Notify_SequencePushConsumer (TAO_Notify_ProxySupplier* proxy)
  : TAO_Notify_Consumer (proxy), pacing_interval_ (ACE_Time_Value::zero), timer_id_ (-1), buffering_strategy_ (0),
    max_batch_size_ (CosNotification::MaximumBatchSize, 0), timer_ (0)
{
}

TAO_Notify_SequencePushConsumer::~TAO_Notify_SequencePushConsumer ()
{
  delete this->buffering_strategy_;
}

void
TAO_Notify_SequencePushConsumer::init (CosNotifyComm::SequencePushConsumer_ptr push_consumer, TAO_Notify_AdminProperties_var& admin_properties ACE_ENV_ARG_DECL)
{
  this->push_consumer_ = CosNotifyComm::SequencePushConsumer::_duplicate (push_consumer);

  this->publish_ = CosNotifyComm::NotifyPublish::_duplicate (push_consumer);

  ACE_NEW_THROW_EX (this->buffering_strategy_,
                    TAO_Notify_Batch_Buffering_Strategy (this->msg_queue_, admin_properties,
                                                     this->max_batch_size_.value ()),
                    CORBA::NO_MEMORY ());

  this->timer_ = this->proxy ()->timer ();
}

void
TAO_Notify_SequencePushConsumer::shutdown (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  this->cancel_timer ();
  this->timer_->_decr_refcnt ();
}

void
TAO_Notify_SequencePushConsumer::release (void)
{
  delete this;
  //@@ inform factory
}

void
TAO_Notify_SequencePushConsumer::qos_changed (const TAO_Notify_QoSProperties& qos_properties)
{
  this->max_batch_size_ = qos_properties.maximum_batch_size ();

  if (this->max_batch_size_.is_valid ())
    {// set the max batch size.
      this->buffering_strategy_->batch_size (this->max_batch_size_.value ());
    }

  const TAO_Notify_Property_Time &pacing_interval = qos_properties.pacing_interval ();

  if (pacing_interval.is_valid ())
    {
      this->pacing_interval_ =
# if defined (ACE_CONFIG_WIN32_H)
        ACE_Time_Value (ACE_static_cast (long, pacing_interval.value ()));
# else
      ACE_Time_Value (pacing_interval.value () / 1);
# endif /* ACE_CONFIG_WIN32_H */
    }

  // Inform the buffering strategy of qos change.
  this->buffering_strategy_->update_qos_properties (qos_properties);
}

void
TAO_Notify_SequencePushConsumer::schedule_timer (void)
{
  // Schedule the timer.
  if (this->pacing_interval_ != ACE_Time_Value::zero)
    {
      this->timer_id_ = this->timer_->schedule_timer (this, this->pacing_interval_, 0);

      if (this->timer_id_ == -1)
        this->pacing_interval_ = ACE_Time_Value::zero; // some error, revert to no pacing.
    }
}

void
TAO_Notify_SequencePushConsumer::cancel_timer (void)
{
  timer_->cancel_timer (this->timer_id_);
}

void
TAO_Notify_SequencePushConsumer::push_i (const TAO_Notify_Event* event ACE_ENV_ARG_DECL)
{
  const TAO_Notify_Event * copy = event->copy_on_heap (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  TAO_Notify_Event_Copy_var copy_var (copy);

  TAO_Notify_Method_Request_Event* method_request;

  ACE_NEW_THROW_EX (method_request,
                    TAO_Notify_Method_Request_Event (copy_var),
                    CORBA::NO_MEMORY ());

  int msg_count = this->buffering_strategy_->enqueue (*method_request);

  if (msg_count == -1)
    {
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG, "NS_Seq_Reactive_Task (%P|%t) - "
                    "failed to enqueue\n"));
      return;
    }

  if (this->pacing_interval_ == ACE_Time_Value::zero)
    {
      // If pacing is zero, there is no timer, hence dispatch immediately
      this->handle_timeout (ACE_Time_Value::zero, 0);
    }
  else if (msg_count == 1)
    this->schedule_timer ();
}

void
TAO_Notify_SequencePushConsumer::push (const CORBA::Any& /*event*/ ACE_ENV_ARG_DECL_NOT_USED)
{
  //NOP
}

void
TAO_Notify_SequencePushConsumer::push (const CosNotification::StructuredEvent& /*notification*/ ACE_ENV_ARG_DECL_NOT_USED)
{
  //NOP
}

int
TAO_Notify_SequencePushConsumer::handle_timeout (const ACE_Time_Value& /*current_time*/,
                                             const void* /*act*/)
{
  CosNotification::EventBatch event_batch;

  int pending = 0;

  int deq_count = this->buffering_strategy_->dequeue_available (event_batch, pending);

  if (deq_count > 0)
    {
      TAO_Notify_Proxy_Guard ref_guard(this->proxy ()); // Protect this object from being destroyed in this scope.

      this->push (event_batch);

      if (pending)
        this->schedule_timer ();
    }

  return 0;
}

void
TAO_Notify_SequencePushConsumer::push (const CosNotification::EventBatch& event_batch)
{
  ACE_TRY_NEW_ENV
    {
      this->push_consumer_->push_structured_events (event_batch ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      this->handle_dispatch_exception (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // we're scheduled to be destroyed. don't set the timer.
      this->pacing_interval_ = ACE_Time_Value::zero;
    }
  ACE_ENDTRY;
}
bool
TAO_Notify_SequencePushConsumer::get_ior (ACE_CString & iorstr) const
{
  bool result = false;
  CORBA::ORB_var orb = TAO_Notify_PROPERTIES::instance()->orb();
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
  {
    CORBA::String_var ior = orb->object_to_string(this->push_consumer_.in() ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;
    iorstr = ACE_static_cast (const char *, ior.in ());
    result = true;
  }
  ACE_CATCHANY
  {
    ACE_ASSERT(0);
  }
  ACE_ENDTRY;
  return result;
}
