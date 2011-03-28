/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   Notify_Push_Consumer.h
 *
 *  $Id$
 *
 * A push consumer implementation.
 *
 *
 *  @author Chad Elliott <elliott_c@ociweb.com>
 */
//=============================================================================

#ifndef TAO_NOTIFY_PUSH_CONSUMER_H
#define TAO_NOTIFY_PUSH_CONSUMER_H
#include "Notify_StructuredPushConsumer.h"

class Notify_Test_Client;

class Notify_Push_Consumer: public TAO_Notify_Tests_StructuredPushConsumer
{
public:
  Notify_Push_Consumer (Notify_Test_Client& client);
  void _connect (CosNotifyChannelAdmin::ConsumerAdmin_ptr consumer_admin,
    CosNotifyFilter::Filter_ptr filter);

  int messages_received();

protected:
  void push_structured_event (const CosNotification::StructuredEvent&);

  Notify_Test_Client& client_;
  int messages_received_;
};

#endif /* TAO_NOTIFY_PUSH_CONSUMER_H */
