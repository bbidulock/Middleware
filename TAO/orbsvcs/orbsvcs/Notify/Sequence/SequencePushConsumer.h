/* -*- C++ -*- */
/**
 *  @file SequencePushConsumer.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_SEQUENCEPUSHCONSUMER_H
#define TAO_Notify_SEQUENCEPUSHCONSUMER_H
#include /**/ "ace/pre.h"

#include "../notify_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Event_Handler.h"
#include "../Event.h"
#include "../Property.h"
#include "../Property_T.h"
#include "../Consumer.h"
#include "../AdminProperties.h"
#include "Batch_Buffering_Strategy.h"
#include "ace/Null_Condition.h"

class TAO_Notify_ProxySupplier;
class TAO_Notify_QoSProperties;
class TAO_Notify_Timer;

/**
 * @class TAO_Notify_SequencePushConsumer
 *
 * @brief
 *
 */
class TAO_Notify_Serv_Export TAO_Notify_SequencePushConsumer : public ACE_Event_Handler, public TAO_Notify_Consumer
{
public:
  /// Constuctor
  TAO_Notify_SequencePushConsumer (TAO_Notify_ProxySupplier* proxy);

  /// Destructor
  ~TAO_Notify_SequencePushConsumer ();

  /// Init the Consumer
  void init (CosNotifyComm::SequencePushConsumer_ptr push_consumer, TAO_Notify_AdminProperties_var& admin_properties ACE_ENV_ARG_DECL);

  /// Shutdown the consumer
  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL);

  /// TAO_Notify_Destroy_Callback methods.
  virtual void release (void);

  /// Push <event> to this consumer.
  virtual void push_i (const TAO_Notify_Event* event ACE_ENV_ARG_DECL);

  virtual void push_i (const TAO_Notify_Event_var& event ACE_ENV_ARG_DECL);

  /// Push <event> to this consumer.
  virtual void push (const CORBA::Any& event ACE_ENV_ARG_DECL);

  // Push event.
  virtual void push (const CosNotification::StructuredEvent & event ACE_ENV_ARG_DECL);

  /// Push <event> to this consumer.
  virtual void push (const CosNotification::EventBatch& event);

  /// Override, Peer::qos_changed
  virtual void qos_changed (const TAO_Notify_QoSProperties& qos_properties);

  /// Retrieve the ior of this peer
  virtual bool get_ior (ACE_CString & iorstr) const;

protected:
  /// When the pacing interval is used, handle_timeout () is called by
  /// the reactor.
  virtual int handle_timeout (const ACE_Time_Value& current_time,
                              const void* act = 0);

  /// Schedule timer
  void schedule_timer (void);

  /// Cancel timer
  void cancel_timer (void);

  ///= Protected Data Members

  /// The Pacing Interval
  ACE_Time_Value pacing_interval_;

  /// Timer Id.
  long timer_id_;

  /// The Consumer
  CosNotifyComm::SequencePushConsumer_var push_consumer_;

  /// The Message queue.
  TAO_Notify_Message_Queue msg_queue_;

  /// The Buffering Strategy
  TAO_Notify_Batch_Buffering_Strategy* buffering_strategy_;

  /// Max. batch size.
  TAO_Notify_Property_Long max_batch_size_;

  /// The Timer Manager that we use.
  TAO_Notify_Timer* timer_;
};

#if defined (__ACE_INLINE__)
#include "SequencePushConsumer.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* TAO_Notify_SEQUENCEPUSHCONSUMER_H */
