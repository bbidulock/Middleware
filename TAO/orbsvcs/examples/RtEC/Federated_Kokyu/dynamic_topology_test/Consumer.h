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
//   Bryan Thrall
//
// ============================================================================

#ifndef CONSUMER_H
#define CONSUMER_H

#include "orbsvcs/RtecEventCommS.h"
#include "orbsvcs/RtecSchedulerC.h"

#include "ace/Time_Value.h"
#include "ace/Vector_T.h"

#include "Supplier.h"
#include "Service_Handler.h"

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
  Consumer (RtecEventComm::EventSourceID normal_type,
            RtecEventComm::EventSourceID ft_type,
            ACE_Time_Value& worktime,
            Supplier *fwddest = 0, Service_Handler *handler = 0);
  // Constructor

  Consumer (RtecEventComm::EventSourceID normal_type,
            RtecEventComm::EventSourceID ft_type,
            Supplier *fwddest = 0, Service_Handler *handler = 0);
  // Constructor

  // = The RtecEventComm::PushConsumer methods

  virtual void push (const RtecEventComm::EventSet& events
                     ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void disconnect_push_consumer (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // The skeleton methods.

  void setWorkTime(ACE_Time_Value& worktime);

  typedef ACE_Vector<RtecScheduler::handle_t> RT_Info_Vector;

  void rt_info(RT_Info_Vector& consumer_rt_info);
  RT_Info_Vector& rt_info(void);

  void handler(Service_Handler * handler);

  Service_Handler * handler(void) const;

private:
  int deadline_missed_;
  ACE_Time_Value worktime_;

  Supplier *fwddest_;
  //RtecScheduler::handle_t rt_info_;
  RT_Info_Vector rt_info_;

  Service_Handler * handler_;

  RtecEventComm::EventType norm_type_;
  RtecEventComm::EventType ft_type_;
};

#endif /* CONSUMER_H */
