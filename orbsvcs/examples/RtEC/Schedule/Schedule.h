// $Id $

// This file was automatically generated by the Scheduler_Factory.
// Before editing the file please consider generating it again.

#include "orbsvcs/Scheduler_Factory.h"


// There were no scheduling anomalies.


static ACE_Scheduler_Factory::POD_RT_Info infos[] = {
{"Reactor_Task-25000.us",          1,          0,          0,          0,     250000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          0,          0, (RtecScheduler::Info_Type_t) 0 },
{"Reactor_Task-50000.us",          2,          0,          0,          0,     500000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          1,          0, (RtecScheduler::Info_Type_t) 0 },
{"Reactor_Task-100000.us",          3,          0,          0,          0,    1000000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          2,          0, (RtecScheduler::Info_Type_t) 0 },
{"Reactor_Task-200000.us",          4,          0,          0,          0,    2000000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          3,          0, (RtecScheduler::Info_Type_t) 0 },
{"Reactor_Task-1000000.us",          5,          0,          0,          0,   10000000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          4,          0, (RtecScheduler::Info_Type_t) 0 },
{"ACE_ES_Dispatch_Queue-25000.us",          6,          0,          0,          0,     250000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          5,          0, (RtecScheduler::Info_Type_t) 0 },
{"ACE_ES_Dispatch_Queue-50000.us",          7,          0,          0,          0,     500000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          6,          0, (RtecScheduler::Info_Type_t) 0 },
{"ACE_ES_Dispatch_Queue-100000.us",          8,          0,          0,          0,    1000000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          7,          0, (RtecScheduler::Info_Type_t) 0 },
{"ACE_ES_Dispatch_Queue-200000.us",          9,          0,          0,          0,    2000000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          8,          0, (RtecScheduler::Info_Type_t) 0 },
{"ACE_ES_Dispatch_Queue-1000000.us",         10,          0,          0,          0,   10000000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,          9,          0, (RtecScheduler::Info_Type_t) 0 },
{  "consumer_event_1",         11,      20000,      20000,      20000,          0, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,      20000,          0,         99,         10,          0, (RtecScheduler::Info_Type_t) 0 },
{  "consumer_event_2",         12,      10000,      10000,      10000,          0, (RtecScheduler::Criticality_t) 0, (RtecScheduler::Importance_t) 0,      10000,          0,         98,          0,          1, (RtecScheduler::Info_Type_t) 0 },
{  "supplier_event_1",         13,          0,          0,          0,     100000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,         11,          0, (RtecScheduler::Info_Type_t) 0 },
{  "supplier_event_2",         14,          0,          0,          0,     200000, (RtecScheduler::Criticality_t) 4, (RtecScheduler::Importance_t) 0,          0,          1,         99,         12,          0, (RtecScheduler::Info_Type_t) 0 }
};

static int infos_size = sizeof(infos)/sizeof(infos[0]);


static ACE_Scheduler_Factory::POD_Config_Info configs[] = {
  {          0,         99, (RtecScheduler::Dispatching_Type_t) 2 },
  {          1,         98, (RtecScheduler::Dispatching_Type_t) 2 }
};

static int configs_size = sizeof(configs)/sizeof(configs[0]);


// This sets up Scheduler_Factory to use the runtime version.
int scheduler_factory_setup = 
  ACE_Scheduler_Factory::use_runtime (configs_size, configs, infos_size, infos);

// EOF
