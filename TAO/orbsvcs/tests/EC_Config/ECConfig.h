/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = FILENAME
//   ECConfig
//
// = AUTHOR
//   Bryan Thrall (thrall@cse.wustl.edu)
//
// ============================================================================

#ifndef ECCONFIG_H
#define ECCONFIG_H

#include "ace/Array.h"
#include "ace/Synch.h"
#include "orbsvcs/RtecSchedulerS.h" //for POA_RtecScheduler
#include "orbsvcs/RtecSchedulerC.h"
#include "orbsvcs/RtecEventChannelAdminC.h"
#include "orbsvcs/Event/EC_Event_Channel.h"

#include "TestConfig.h"
#include "Consumer.h"
#include "Supplier.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TestConfig {

typedef ACE_Array<RtecEventChannelAdmin::ProxyPushConsumer_var> ProxyList;
typedef ACE_Array<RtecScheduler::handle_t> ConfigList;
typedef ACE_Array<RtecEventComm::EventSourceID> SupplierIDList;

typedef ACE_Array<Consumer*> ConsumerList;
typedef ACE_Array<Supplier*> SupplierList;

template <class SCHED_STRAT>
class ECConfig : public Test_Config {
public:
  ECConfig (void);

  virtual ~ECConfig (void);

  virtual int configure (TCFG_SET_WPTR configs);
  //does not take ownership of the Test_Config_Set but
  //needs to use the test_config_t in that set until
  //the ECConfig goes out of scope

  virtual int run (void);
  //If we try to distinguish between final-push and final-receipt,
  //that might be tracked in the Consumer (which would be easy as long
  //as filtering and correlation isn't used -- in that case, there
  //might be more than one receiver of an event, so you might get
  //multiple receipt-notices). There could also be a race-condition
  //problem between the various threads when reporting the receipt of
  //events.

protected:
  virtual int initEC (void);

  virtual int connectConsumers (void);

  virtual int connectSuppliers (void);

  virtual void reset (void);
  //

private:

  void print_RT_Infos (ACE_Array<RtecScheduler::handle_t> cfg_set);

  Test_Config_Set testcfgs;
  //copy of the currently configured Test_Config_Set
  //using the same test_config_t objects

  CORBA::ORB_var orb;

  PortableServer::POA_var poa;

  PortableServer::POAManager_var poa_manager;

  RtecEventChannelAdmin::EventChannel_var event_channel;

  RtecScheduler::Scheduler_var scheduler;
  /*
  ACE_Strong_Bound_Ptr<TAO_EC_Event_Channel,ACE_Null_Mutex> ec_impl;

  ACE_Strong_Bound_Ptr<POA_RtecScheduler::Scheduler,ACE_Null_Mutex> sched_impl;
  */
  TAO_EC_Event_Channel *ec_impl;

  POA_RtecScheduler::Scheduler *sched_impl;

  ProxyList consumer_proxys;
  //proxy objects for pushing events to consumers

  ConfigList supplier_cfgs;
  //RT_Infos generated by configure() for suppliers.

  ConfigList consumer_cfgs;
  //RT_Infos generated by configure() for consumers.

  SupplierIDList supplier_ids;
  //IDs of the suppliers

  ConsumerList consumers;

  SupplierList suppliers;

  bool configured;
};

} /* namespace TestConfig */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ECConfig.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("ECConfig.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ECCONFIG_H */
