/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = LIBRARY
//   ORBSVCS Real-time Event Channel examples
//
// = FILENAME
//   Consumer
//
// = AUTHOR
//   Carlos O'Ryan (coryan@cs.wustl.edu)
//
// ============================================================================

#ifndef CONSUMER_H
#define CONSUMER_H

#include "orbsvcs/RtecEventCommS.h"
#include "Supplier.h"
#include "ace/Time_Value.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class Consumer : public POA_RtecEventComm::PushConsumer
{
  // = TITLE
  //   Simple consumer object
  //
  // = DESCRIPTION
  //   This class is a consumer of events.
  //   It simply register for two event typesone event type
  //   The class is just a helper to simplify common tasks in EC
  //   tests, such as subscribing for a range of events, disconnecting
  //   from the EC, informing the driver of shutdown messages, etc.
  //
  //   There are several ways to connect and disconnect this class,
  //   and it is up to the driver program to use the right one.
  //
public:
  Consumer (ACE_Time_Value& worktime, Supplier *fwddest = 0);
  // Constructor

  Consumer (Supplier *fwddest = 0);
  // Constructor

  // = The RtecEventComm::PushConsumer methods

  virtual void push (const RtecEventComm::EventSet& events
                     ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void disconnect_push_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // The skeleton methods.

  void setWorkTime(ACE_Time_Value& worktime);

private:
  int deadline_missed_;
  ACE_Time_Value worktime_;

  Supplier *fwddest_;
};

#endif /* CONSUMER_H */
