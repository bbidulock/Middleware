// This file was automatically generated by Scheduler_Factory
// before editing the file please consider generating it again
// $Id$

#include "orbsvcs/Scheduler_Factory.h"

static ACE_Scheduler_Factory::POD_RT_Info runtime_infos_2[] = {
{ "Reactor_Task-25000.us", 1, {0, 0}, {0, 0}, {0, 0}, 250000,
   4, 0, {0, 0}, 1, 4, 0, 0, 0 },
{ "Reactor_Task-50000.us", 2, {0, 0}, {0, 0}, {0, 0}, 500000,
   4, 0, {0, 0}, 1, 3, 0, 0, 0 },
{ "Reactor_Task-100000.us", 3, {0, 0}, {0, 0}, {0, 0}, 1000000,
   4, 0, {0, 0}, 1, 2, 0, 0, 0 },
{ "Reactor_Task-200000.us", 4, {0, 0}, {0, 0}, {0, 0}, 2000000,
   4, 0, {0, 0}, 1, 1, 0, 0, 0 },
{ "Reactor_Task-1000000.us", 5, {0, 0}, {0, 0}, {0, 0}, 10000000,
   4, 0, {0, 0}, 1, 0, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-25000.us", 6, {0, 0}, {0, 0}, {0, 0}, 0,
   4, 0, {0, 0}, 1, 4, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-50000.us", 7, {0, 0}, {0, 0}, {0, 0}, 0,
   4, 0, {0, 0}, 1, 3, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-100000.us", 8, {0, 0}, {0, 0}, {0, 0}, 0,
   4, 0, {0, 0}, 1, 2, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-200000.us", 9, {0, 0}, {0, 0}, {0, 0}, 0,
   4, 0, {0, 0}, 1, 1, 0, 0, 0 },
{ "ACE_ES_Dispatch_Queue-1000000.us", 10, {0, 0}, {0, 0}, {0, 0}, 0,
   4, 0, {0, 0}, 1, 0, 0, 0, 0 },
{ "hp_supplier_00@ECM2", 11, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_01@ECM2", 12, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_02@ECM2", 13, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_03@ECM2", 14, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_04@ECM2", 15, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_05@ECM2", 16, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_06@ECM2", 17, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_07@ECM2", 18, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_08@ECM2", 19, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "hp_supplier_09@ECM2", 20, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "lp_supplier_00@ECM2", 21, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "lp_supplier_01@ECM2", 22, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "lp_supplier_02@ECM2", 23, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "lp_supplier_03@ECM2", 24, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "lp_supplier_04@ECM2", 25, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "ecg_ECM2@ECM2", 26, {5000, 0}, {5000, 0}, {5000, 0}, 250000,
   4, 0, {5000, 0}, 1, 4, 0, 0, 0 },
{ "ecg_ECM1@ECM2", 27, {5000, 0}, {5000, 0}, {5000, 0}, 250000,
   4, 0, {5000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_00@ECM2", 28, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_01@ECM2", 29, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_02@ECM2", 30, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_03@ECM2", 31, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_04@ECM2", 32, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_05@ECM2", 33, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_06@ECM2", 34, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_07@ECM2", 35, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_08@ECM2", 36, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_09@ECM2", 37, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_10@ECM2", 38, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_11@ECM2", 39, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_12@ECM2", 40, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_13@ECM2", 41, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_14@ECM2", 42, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_15@ECM2", 43, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_16@ECM2", 44, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_17@ECM2", 45, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_18@ECM2", 46, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_19@ECM2", 47, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_20@ECM2", 48, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_21@ECM2", 49, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_22@ECM2", 50, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_23@ECM2", 51, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "hp_consumer_24@ECM2", 52, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 4, 0, 0, 0 },
{ "lp_consumer_00@ECM2", 53, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 0, 0, 0, 0 },
{ "lp_consumer_01@ECM2", 54, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 0, 0, 0, 0 },
{ "lp_consumer_02@ECM2", 55, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 0, 0, 0, 0 },
{ "lp_consumer_03@ECM2", 56, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 0, 0, 0, 0 },
{ "lp_consumer_04@ECM2", 57, {20000, 0}, {20000, 0}, {20000, 0}, 0,
   4, 0, {20000, 0}, 0, 0, 0, 0, 0 },
{ "consumer_hp_supplier_00@ECM2", 58, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_01@ECM2", 59, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_02@ECM2", 60, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_03@ECM2", 61, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_04@ECM2", 62, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_05@ECM2", 63, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_06@ECM2", 64, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_07@ECM2", 65, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_08@ECM2", 66, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_hp_supplier_09@ECM2", 67, {20000, 0}, {20000, 0}, {20000, 0}, 250000,
   4, 0, {20000, 0}, 1, 4, 0, 0, 0 },
{ "consumer_lp_supplier_00@ECM2", 68, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "consumer_lp_supplier_01@ECM2", 69, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "consumer_lp_supplier_02@ECM2", 70, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "consumer_lp_supplier_03@ECM2", 71, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 },
{ "consumer_lp_supplier_04@ECM2", 72, {20000, 0}, {20000, 0}, {20000, 0}, 10000000,
   4, 0, {20000, 0}, 1, 0, 0, 0, 0 }
};
static int runtime_infos_2_size = sizeof(runtime_infos_2)/sizeof(runtime_infos_2[0]);

static ACE_Scheduler_Factory::POD_Config_Info runtime_configs_2[] = {
{          0,        59, (RtecScheduler::Dispatching_Type) 0 }
};
static int runtime_configs_2_size = sizeof(runtime_configs_2)/sizeof(runtime_configs_2[0]);

// EOF
