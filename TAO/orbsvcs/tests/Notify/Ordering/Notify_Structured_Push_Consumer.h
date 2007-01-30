/* -*- C++ -*- */
// $Id$
// ==========================================================================
//
// = LIBRARY
//   TAO/orbsvcs/tests/Notify/Ordering
//
// = FILENAME
//   Notify_Structured_Push_Consumer.h
//
// = DESCRIPTION
//   A structured push consumer implementation.
//
// = AUTHOR
//    Chad Elliott <elliott_c@ociweb.com>
//
// ==========================================================================
#ifndef TAO_NOTIFY_STRUCTURED_PUSH_CONSUMER_H
#define TAO_NOTIFY_STRUCTURED_PUSH_CONSUMER_H

#include "Notify_StructuredPushConsumer.h"

class Notify_Test_Client;

class Notify_Structured_Push_Consumer: public TAO_Notify_Tests_StructuredPushConsumer
{
public:
  Notify_Structured_Push_Consumer (
                        const char* name,
                        CORBA::Short policy,
                        bool use_ordering,
                        int expected,
                        Notify_Test_Client& client);

  void _connect (CosNotifyChannelAdmin::ConsumerAdmin_ptr consumer_admin)
    ACE_THROW_SPEC ((CORBA::SystemException));

protected:
  void push_structured_event (const CosNotification::StructuredEvent&)
    ACE_THROW_SPEC ((CORBA::SystemException));

  ACE_CString name_;
  CORBA::Short order_policy_;
  bool use_ordering_;
  int expected_;
  int count_;
  int first_;
  Notify_Test_Client& client_;
};

#endif /* TAO_NOTIFY_STRUCTURED_PUSH_CONSUMER_H */
