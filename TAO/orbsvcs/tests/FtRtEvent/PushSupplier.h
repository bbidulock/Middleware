// -*- C++ -*-
//=============================================================================
/**
 *  @file   PushSupplier.h
 *
 *  $Id$
 *
 *  @author Huang-Ming Huang <hh1@cse.wustl.edu>
 */
//=============================================================================

#ifndef PUSHSUPPLIER_H
#define PUSHSUPPLIER_H

#include "orbsvcs/RtecEventCommS.h"
#include "orbsvcs/RtecEventChannelAdminC.h"
#include "orbsvcs/Channel_Clients_T.h"
#include "ace/Event_Handler.h"
#include "ace/Task.h"
#include "ace/Reactor.h"
#include "ace/Time_Value.h"
#include "ace/SString.h"

class ACE_Reactor;
struct Options;
class PushSupplier_impl : public ACE_Event_Handler
{
public:
  PushSupplier_impl();
  ~PushSupplier_impl();

  int init(CORBA::ORB_ptr orb,
           RtecEventChannelAdmin::EventChannel_ptr,
           const Options& options ACE_ENV_ARG_DECL);

  virtual void  disconnect_push_supplier (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
private:

  class ReactorTask : public ACE_Task_Base
  {
  public:
    // ctor
    ReactorTask(ACE_Event_Handler* handler) : handler_(handler){}
    virtual int svc (void);
    // The thread entry point.

    ACE_Reactor* reactor_;
    ACE_Event_Handler* handler_;
    ACE_Time_Value timer_interval_;
  };

  virtual int handle_timeout (const ACE_Time_Value &current_time,
                              const void *act = 0);

  CORBA::ORB_var orb_;
  int num_iterations_;
  ACE_CString proxy_consumer_file_;
  ACE_PushSupplier_Adapter<PushSupplier_impl> supplier_servant_;
  CORBA::ULong seq_no_;
  ReactorTask reactor_task_;
  RtecEventChannelAdmin::ProxyPushConsumer_var consumer_;
  bool in_timeout_handler_;

  PushSupplier_impl(const PushSupplier_impl&);
  void operator==(const PushSupplier_impl&);
};
#endif
