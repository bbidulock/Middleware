// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "RtecSchedulerS.h"

#if !defined (__ACE_INLINE__)
#include "RtecSchedulerS.i"
#endif // !defined INLINE

static const TAO_operation_db_entry Scheduler_operations [] = {
  {"create", &POA_RtecScheduler::Scheduler::create_skel},
  {"lookup", &POA_RtecScheduler::Scheduler::lookup_skel},
  {"get", &POA_RtecScheduler::Scheduler::get_skel},
  {"set", &POA_RtecScheduler::Scheduler::set_skel},
  {"add_dependency", &POA_RtecScheduler::Scheduler::add_dependency_skel},
  {"priority", &POA_RtecScheduler::Scheduler::priority_skel},
  {"entry_point_priority", &POA_RtecScheduler::Scheduler::entry_point_priority_skel},
  {"compute_scheduling", &POA_RtecScheduler::Scheduler::compute_scheduling_skel},
  {"_is_a", &POA_RtecScheduler::Scheduler::_is_a_skel}
};

TAO_Dynamic_Hash_OpTable tao_Scheduler_optable (Scheduler_operations, 9, 18);
// skeleton constructor
POA_RtecScheduler::Scheduler::Scheduler (const char *obj_name)
{
  const CORBA::String repoID = "IDL:RtecScheduler/Scheduler:1.0"; // repository ID
  IIOP_Object *data; // Actual object reference
  TAO_ORB_Core *ocp = TAO_ORB_Core_instance (); // underlying ORB core instance
  CORBA::POA_ptr oa = TAO_ORB_Core_instance ()->root_poa (); // underlying OA
  const ACE_INET_Addr &addr = ocp->orb_params ()->addr ();
  this->optable_ = &tao_Scheduler_optable;
  
  // set up an IIOP object
  data = new IIOP_Object (CORBA::string_dup (repoID), addr, obj_name);
  this->set_parent (data); // store the IIOP obj ref with us
  this->sub_ = this; // set the most derived type to be us
  if (oa) oa->bind (data->profile.object_key, this); // register ourselves
}

void POA_RtecScheduler::Scheduler::create_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_RtecScheduler::Scheduler_ptr 	 impl;
  CORBA::Any *result;
  RtecScheduler::handle_t *retval = new RtecScheduler::handle_t;
  char *entry_point;
  CORBA::NamedValue_ptr nv_entry_point;
  CORBA::Any 	 any_entry_point (CORBA::_tc_string, &entry_point); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_entry_point = nvlist->add_value ("entry_point", any_entry_point, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_RtecScheduler::Scheduler_ptr) _tao_object_reference->get_subclass ();
   *retval = impl->create(entry_point, _tao_environment);
  result = new CORBA::Any (RtecScheduler::_tc_handle_t, retval, 1); // ORB owns
  _tao_server_request.result (result, _tao_environment);
  
}

void POA_RtecScheduler::Scheduler::lookup_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_RtecScheduler::Scheduler_ptr 	 impl;
  CORBA::Any *result;
  RtecScheduler::handle_t *retval = new RtecScheduler::handle_t;
  char *entry_point;
  CORBA::NamedValue_ptr nv_entry_point;
  CORBA::Any 	 any_entry_point (CORBA::_tc_string, &entry_point); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_entry_point = nvlist->add_value ("entry_point", any_entry_point, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_RtecScheduler::Scheduler_ptr) _tao_object_reference->get_subclass ();
   *retval = impl->lookup(entry_point, _tao_environment);
  result = new CORBA::Any (RtecScheduler::_tc_handle_t, retval, 1); // ORB owns
  _tao_server_request.result (result, _tao_environment);
  
}

void POA_RtecScheduler::Scheduler::get_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_RtecScheduler::Scheduler_ptr 	 impl;
  CORBA::Any *result;
  RtecScheduler::RT_Info *retval;
  RtecScheduler::handle_t handle;
  CORBA::NamedValue_ptr nv_handle;
  CORBA::Any 	 any_handle (RtecScheduler::_tc_handle_t, &handle); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_handle = nvlist->add_value ("handle", any_handle, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_RtecScheduler::Scheduler_ptr) _tao_object_reference->get_subclass ();
  retval = impl->get(handle, _tao_environment);
  result = new CORBA::Any (RtecScheduler::_tc_RT_Info, retval, 1); // ORB owns
  _tao_server_request.result (result, _tao_environment);
  
}

void POA_RtecScheduler::Scheduler::set_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_RtecScheduler::Scheduler_ptr 	 impl;
  RtecScheduler::handle_t handle;
  CORBA::NamedValue_ptr nv_handle;
  CORBA::Any 	 any_handle (RtecScheduler::_tc_handle_t, &handle); // ORB does not own
  RtecScheduler::Time time;
  CORBA::NamedValue_ptr nv_time;
  CORBA::Any 	 any_time (RtecScheduler::_tc_Time, &time); // ORB does not own
  RtecScheduler::Time typical_time;
  CORBA::NamedValue_ptr nv_typical_time;
  CORBA::Any 	 any_typical_time (RtecScheduler::_tc_Time, &typical_time); // ORB does not own
  RtecScheduler::Time cached_time;
  CORBA::NamedValue_ptr nv_cached_time;
  CORBA::Any 	 any_cached_time (RtecScheduler::_tc_Time, &cached_time); // ORB does not own
  RtecScheduler::Period period;
  CORBA::NamedValue_ptr nv_period;
  CORBA::Any 	 any_period (RtecScheduler::_tc_Period, &period); // ORB does not own
  RtecScheduler::Importance importance;
  CORBA::NamedValue_ptr nv_importance;
  CORBA::Any 	 any_importance (RtecScheduler::_tc_Importance, &importance); // ORB does not own
  RtecScheduler::Quantum quantum;
  CORBA::NamedValue_ptr nv_quantum;
  CORBA::Any 	 any_quantum (RtecScheduler::_tc_Quantum, &quantum); // ORB does not own
  CORBA::Long threads;
  CORBA::NamedValue_ptr nv_threads;
  CORBA::Any 	 any_threads (CORBA::_tc_long, &threads); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_handle = nvlist->add_value ("handle", any_handle, CORBA::ARG_IN, _tao_environment);
  nv_time = nvlist->add_value ("time", any_time, CORBA::ARG_IN, _tao_environment);
  nv_typical_time = nvlist->add_value ("typical_time", any_typical_time, CORBA::ARG_IN, _tao_environment);
  nv_cached_time = nvlist->add_value ("cached_time", any_cached_time, CORBA::ARG_IN, _tao_environment);
  nv_period = nvlist->add_value ("period", any_period, CORBA::ARG_IN, _tao_environment);
  nv_importance = nvlist->add_value ("importance", any_importance, CORBA::ARG_IN, _tao_environment);
  nv_quantum = nvlist->add_value ("quantum", any_quantum, CORBA::ARG_IN, _tao_environment);
  nv_threads = nvlist->add_value ("threads", any_threads, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_RtecScheduler::Scheduler_ptr) _tao_object_reference->get_subclass ();
  impl->set(handle, time, typical_time, cached_time, period, importance, quantum, threads, _tao_environment);
  
}

void POA_RtecScheduler::Scheduler::add_dependency_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_RtecScheduler::Scheduler_ptr 	 impl;
  RtecScheduler::handle_t handle;
  CORBA::NamedValue_ptr nv_handle;
  CORBA::Any 	 any_handle (RtecScheduler::_tc_handle_t, &handle); // ORB does not own
  RtecScheduler::handle_t dependency;
  CORBA::NamedValue_ptr nv_dependency;
  CORBA::Any 	 any_dependency (RtecScheduler::_tc_handle_t, &dependency); // ORB does not own
  CORBA::Long number_of_calls;
  CORBA::NamedValue_ptr nv_number_of_calls;
  CORBA::Any 	 any_number_of_calls (CORBA::_tc_long, &number_of_calls); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_handle = nvlist->add_value ("handle", any_handle, CORBA::ARG_IN, _tao_environment);
  nv_dependency = nvlist->add_value ("dependency", any_dependency, CORBA::ARG_IN, _tao_environment);
  nv_number_of_calls = nvlist->add_value ("number_of_calls", any_number_of_calls, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_RtecScheduler::Scheduler_ptr) _tao_object_reference->get_subclass ();
  impl->add_dependency(handle, dependency, number_of_calls, _tao_environment);
  
}

void POA_RtecScheduler::Scheduler::priority_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_RtecScheduler::Scheduler_ptr 	 impl;
  RtecScheduler::handle_t handle;
  CORBA::NamedValue_ptr nv_handle;
  CORBA::Any 	 any_handle (RtecScheduler::_tc_handle_t, &handle); // ORB does not own
  RtecScheduler::OS_Priority priority;
  CORBA::NamedValue_ptr nv_priority;
  CORBA::Any 	 any_priority (RtecScheduler::_tc_OS_Priority, &priority, 1); // ORB owns
  RtecScheduler::Sub_Priority subpriority;
  CORBA::NamedValue_ptr nv_subpriority;
  CORBA::Any 	 any_subpriority (RtecScheduler::_tc_Sub_Priority, &subpriority, 1); // ORB owns
  RtecScheduler::Preemption_Priority p_priority;
  CORBA::NamedValue_ptr nv_p_priority;
  CORBA::Any 	 any_p_priority (RtecScheduler::_tc_Preemption_Priority, &p_priority, 1); // ORB owns
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_handle = nvlist->add_value ("handle", any_handle, CORBA::ARG_IN, _tao_environment);
  nv_priority = nvlist->add_value ("priority", any_priority, CORBA::ARG_OUT, _tao_environment);
  nv_subpriority = nvlist->add_value ("subpriority", any_subpriority, CORBA::ARG_OUT, _tao_environment);
  nv_p_priority = nvlist->add_value ("p_priority", any_p_priority, CORBA::ARG_OUT, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_RtecScheduler::Scheduler_ptr) _tao_object_reference->get_subclass ();
  impl->priority(handle, priority, subpriority, p_priority, _tao_environment);
  
}

void POA_RtecScheduler::Scheduler::entry_point_priority_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_RtecScheduler::Scheduler_ptr 	 impl;
  char *entry_point;
  CORBA::NamedValue_ptr nv_entry_point;
  CORBA::Any 	 any_entry_point (CORBA::_tc_string, &entry_point); // ORB does not own
  RtecScheduler::OS_Priority priority;
  CORBA::NamedValue_ptr nv_priority;
  CORBA::Any 	 any_priority (RtecScheduler::_tc_OS_Priority, &priority, 1); // ORB owns
  RtecScheduler::Sub_Priority subpriority;
  CORBA::NamedValue_ptr nv_subpriority;
  CORBA::Any 	 any_subpriority (RtecScheduler::_tc_Sub_Priority, &subpriority, 1); // ORB owns
  RtecScheduler::Preemption_Priority p_priority;
  CORBA::NamedValue_ptr nv_p_priority;
  CORBA::Any 	 any_p_priority (RtecScheduler::_tc_Preemption_Priority, &p_priority, 1); // ORB owns
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_entry_point = nvlist->add_value ("entry_point", any_entry_point, CORBA::ARG_IN, _tao_environment);
  nv_priority = nvlist->add_value ("priority", any_priority, CORBA::ARG_OUT, _tao_environment);
  nv_subpriority = nvlist->add_value ("subpriority", any_subpriority, CORBA::ARG_OUT, _tao_environment);
  nv_p_priority = nvlist->add_value ("p_priority", any_p_priority, CORBA::ARG_OUT, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_RtecScheduler::Scheduler_ptr) _tao_object_reference->get_subclass ();
  impl->entry_point_priority(entry_point, priority, subpriority, p_priority, _tao_environment);
  
}

void POA_RtecScheduler::Scheduler::compute_scheduling_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_RtecScheduler::Scheduler_ptr 	 impl;
  CORBA::Long minimum_priority;
  CORBA::NamedValue_ptr nv_minimum_priority;
  CORBA::Any 	 any_minimum_priority (CORBA::_tc_long, &minimum_priority); // ORB does not own
  CORBA::Long maximum_priority;
  CORBA::NamedValue_ptr nv_maximum_priority;
  CORBA::Any 	 any_maximum_priority (CORBA::_tc_long, &maximum_priority); // ORB does not own
  RtecScheduler::RT_Info_Set *infos;
  RtecScheduler::RT_Info_Set_out infos_out (infos);
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_minimum_priority = nvlist->add_value ("minimum_priority", any_minimum_priority, CORBA::ARG_IN, _tao_environment);
  nv_maximum_priority = nvlist->add_value ("maximum_priority", any_maximum_priority, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_RtecScheduler::Scheduler_ptr) _tao_object_reference->get_subclass ();
  impl->compute_scheduling(minimum_priority, maximum_priority, infos_out, _tao_environment);
  if (_tao_environment.exception ()) return;

  CORBA::NamedValue_ptr nv_infos;
  CORBA::Any 	 any_infos (RtecScheduler::_tc_RT_Info_Set, infos, 1); // ORB owns
  nv_infos = nvlist->add_value ("infos", any_infos, CORBA::ARG_OUT, _tao_environment);
  
}

void POA_RtecScheduler::Scheduler::_is_a_skel (CORBA::ServerRequest &req, CORBA::Object_ptr /* obj */, CORBA::Environment &env)
{
  const CORBA::String type_id = "IDL:RtecScheduler/Scheduler:1.0"; // repository ID
  CORBA::NVList_ptr nvlist;
  CORBA::NamedValue_ptr nv;
  CORBA::Any temp_value (CORBA::_tc_string);
  CORBA::Any *any;
  CORBA::Boolean *retval;
  CORBA::String value;
  
  req.orb()->create_list (0, nvlist);
  nv = nvlist->add_value (0, temp_value, CORBA::ARG_IN, env);
  req.params (nvlist, env); // parse the args
  if (env.exception () != 0) return;
  value = *(CORBA::String *)nv->value ()->value ();
  if (ACE_OS::strcmp ((char *)value, (char *)type_id) == 0
    || ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (env)) == 0)

  	retval = new CORBA::Boolean (CORBA::B_TRUE);
  else
  	retval = new CORBA::Boolean (CORBA::B_FALSE);
  any = new CORBA::Any (CORBA::_tc_boolean, retval, CORBA::B_TRUE);
  req.result (any, env);
}

