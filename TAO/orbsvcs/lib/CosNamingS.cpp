// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "CosNamingS.h"

#if !defined (__ACE_INLINE__)
#include "CosNamingS.i"
#endif // !defined INLINE

static const TAO_operation_db_entry NamingContext_operations [] = {
  {"bind", &POA_CosNaming::NamingContext::bind_skel},
  {"rebind", &POA_CosNaming::NamingContext::rebind_skel},
  {"bind_context", &POA_CosNaming::NamingContext::bind_context_skel},
  {"rebind_context", &POA_CosNaming::NamingContext::rebind_context_skel},
  {"resolve", &POA_CosNaming::NamingContext::resolve_skel},
  {"unbind", &POA_CosNaming::NamingContext::unbind_skel},
  {"new_context", &POA_CosNaming::NamingContext::new_context_skel},
  {"bind_new_context", &POA_CosNaming::NamingContext::bind_new_context_skel},
  {"destroy", &POA_CosNaming::NamingContext::destroy_skel},
  {"list", &POA_CosNaming::NamingContext::list_skel},
  {"_is_a", &POA_CosNaming::NamingContext::_is_a_skel}
};

TAO_Dynamic_Hash_OpTable tao_NamingContext_optable (NamingContext_operations, 11, 22);
// skeleton constructor
POA_CosNaming::NamingContext::NamingContext (const char *obj_name)
{
  const CORBA::String repoID = "IDL:CosNaming/NamingContext:1.0"; // repository ID
  IIOP_Object *data; // Actual object reference
  TAO_ORB_Core *ocp = TAO_ORB_Core_instance (); // underlying ORB core instance
  CORBA::POA_ptr oa = TAO_ORB_Core_instance ()->root_poa (); // underlying OA
  const ACE_INET_Addr &addr = ocp->orb_params ()->addr ();
  this->optable_ = &tao_NamingContext_optable;
  
  // set up an IIOP object
  data = new IIOP_Object (CORBA::string_dup (repoID), addr, obj_name);
  this->set_parent (data); // store the IIOP obj ref with us
  this->sub_ = this; // set the most derived type to be us
  if (oa) oa->bind (data->profile.object_key, this); // register ourselves
}

void POA_CosNaming::NamingContext::bind_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CosNaming::Name n;
  CORBA::NamedValue_ptr nv_n;
  CORBA::Any 	 any_n (CosNaming::_tc_Name, &n); // ORB does not own
  CORBA::Object_ptr obj;
  CORBA::NamedValue_ptr nv_obj;
  CORBA::Any 	 any_obj (CORBA::_tc_Object, &obj); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_n = nvlist->add_value ("n", any_n, CORBA::ARG_IN, _tao_environment);
  nv_obj = nvlist->add_value ("obj", any_obj, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  impl->bind(n, obj, _tao_environment);
  
}

void POA_CosNaming::NamingContext::rebind_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CosNaming::Name n;
  CORBA::NamedValue_ptr nv_n;
  CORBA::Any 	 any_n (CosNaming::_tc_Name, &n); // ORB does not own
  CORBA::Object_ptr obj;
  CORBA::NamedValue_ptr nv_obj;
  CORBA::Any 	 any_obj (CORBA::_tc_Object, &obj); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_n = nvlist->add_value ("n", any_n, CORBA::ARG_IN, _tao_environment);
  nv_obj = nvlist->add_value ("obj", any_obj, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  impl->rebind(n, obj, _tao_environment);
  
}

void POA_CosNaming::NamingContext::bind_context_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CosNaming::Name n;
  CORBA::NamedValue_ptr nv_n;
  CORBA::Any 	 any_n (CosNaming::_tc_Name, &n); // ORB does not own
  CosNaming::NamingContext_ptr nc;
  CORBA::NamedValue_ptr nv_nc;
  CORBA::Any 	 any_nc (CosNaming::_tc_NamingContext, &nc); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_n = nvlist->add_value ("n", any_n, CORBA::ARG_IN, _tao_environment);
  nv_nc = nvlist->add_value ("nc", any_nc, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  impl->bind_context(n, nc, _tao_environment);
  
}

void POA_CosNaming::NamingContext::rebind_context_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CosNaming::Name n;
  CORBA::NamedValue_ptr nv_n;
  CORBA::Any 	 any_n (CosNaming::_tc_Name, &n); // ORB does not own
  CosNaming::NamingContext_ptr nc;
  CORBA::NamedValue_ptr nv_nc;
  CORBA::Any 	 any_nc (CosNaming::_tc_NamingContext, &nc); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_n = nvlist->add_value ("n", any_n, CORBA::ARG_IN, _tao_environment);
  nv_nc = nvlist->add_value ("nc", any_nc, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  impl->rebind_context(n, nc, _tao_environment);
  
}

void POA_CosNaming::NamingContext::resolve_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CORBA::Any *result;
  CORBA::Object_ptr retval;
  CosNaming::Name n;
  CORBA::NamedValue_ptr nv_n;
  CORBA::Any 	 any_n (CosNaming::_tc_Name, &n); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_n = nvlist->add_value ("n", any_n, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  retval = impl->resolve(n, _tao_environment);
  result = new CORBA::Any (CORBA::_tc_Object, retval, 1); // ORB owns
  _tao_server_request.result (result, _tao_environment);
  
}

void POA_CosNaming::NamingContext::unbind_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CosNaming::Name n;
  CORBA::NamedValue_ptr nv_n;
  CORBA::Any 	 any_n (CosNaming::_tc_Name, &n); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_n = nvlist->add_value ("n", any_n, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  impl->unbind(n, _tao_environment);
  
}

void POA_CosNaming::NamingContext::new_context_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CORBA::Any *result;
  CORBA::Object_ptr *retval = new CORBA::Object_ptr;
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  *retval = impl->new_context(_tao_environment);
  result = new CORBA::Any (CosNaming::_tc_NamingContext, retval, 1); // ORB owns
  _tao_server_request.result (result, _tao_environment);
  
}

void POA_CosNaming::NamingContext::bind_new_context_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CORBA::Any *result;
  CORBA::Object_ptr *retval = new CORBA::Object_ptr;
  CosNaming::Name n;
  CORBA::NamedValue_ptr nv_n;
  CORBA::Any 	 any_n (CosNaming::_tc_Name, &n); // ORB does not own
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_n = nvlist->add_value ("n", any_n, CORBA::ARG_IN, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  *retval = impl->bind_new_context(n, _tao_environment);
  result = new CORBA::Any (CosNaming::_tc_NamingContext, retval, 1); // ORB owns
  _tao_server_request.result (result, _tao_environment);
  
}

void POA_CosNaming::NamingContext::destroy_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  impl->destroy(_tao_environment);
  
}

void POA_CosNaming::NamingContext::list_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::NamingContext_ptr 	 impl;
  CORBA::ULong how_many;
  CORBA::NamedValue_ptr nv_how_many;
  CORBA::Any 	 any_how_many (CORBA::_tc_ulong, &how_many); // ORB does not own
  CosNaming::BindingList *bl;
  CosNaming::BindingList_out bl_out (bl);
  CORBA::NamedValue_ptr nv_bl;
  CORBA::Any 	 any_bl (CosNaming::_tc_BindingList, bl, 1); // ORB owns
  CosNaming::BindingIterator_ptr bi;
  CosNaming::BindingIterator_out bi_out (bi);
  CORBA::NamedValue_ptr nv_bi;
  CORBA::Any 	 any_bi (CosNaming::_tc_BindingIterator, &bi, 1); // ORB owns
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_how_many = nvlist->add_value ("how_many", any_how_many, CORBA::ARG_IN, _tao_environment);
  nv_bl = nvlist->add_value ("bl", any_bl, CORBA::ARG_OUT, _tao_environment);
  nv_bi = nvlist->add_value ("bi", any_bi, CORBA::ARG_OUT, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::NamingContext_ptr) _tao_object_reference->get_subclass ();
  impl->list(how_many, bl_out, bi_out, _tao_environment);
  
}

void POA_CosNaming::NamingContext::_is_a_skel (CORBA::ServerRequest &req, CORBA::Object_ptr /* obj */, CORBA::Environment &env)
{
  const CORBA::String type_id = "IDL:CosNaming/NamingContext:1.0"; // repository ID
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

static const TAO_operation_db_entry BindingIterator_operations [] = {
  {"next_one", &POA_CosNaming::BindingIterator::next_one_skel},
  {"next_n", &POA_CosNaming::BindingIterator::next_n_skel},
  {"destroy", &POA_CosNaming::BindingIterator::destroy_skel},
  {"_is_a", &POA_CosNaming::BindingIterator::_is_a_skel}
};

TAO_Dynamic_Hash_OpTable tao_BindingIterator_optable (BindingIterator_operations, 4, 8);
// skeleton constructor
POA_CosNaming::BindingIterator::BindingIterator (const char *obj_name)
{
  const CORBA::String repoID = "IDL:CosNaming/BindingIterator:1.0"; // repository ID
  IIOP_Object *data; // Actual object reference
  TAO_ORB_Core *ocp = TAO_ORB_Core_instance (); // underlying ORB core instance
  CORBA::POA_ptr oa = TAO_ORB_Core_instance ()->root_poa (); // underlying OA
  const ACE_INET_Addr &addr = ocp->orb_params ()->addr ();
  this->optable_ = &tao_BindingIterator_optable;
  
  // set up an IIOP object
  data = new IIOP_Object (CORBA::string_dup (repoID), addr, obj_name);
  this->set_parent (data); // store the IIOP obj ref with us
  this->sub_ = this; // set the most derived type to be us
  if (oa) oa->bind (data->profile.object_key, this); // register ourselves
}

void POA_CosNaming::BindingIterator::next_one_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::BindingIterator_ptr 	 impl;
  CORBA::Any *result;
  CORBA::Boolean *retval = new CORBA::Boolean;
  CosNaming::Binding *b;
  CosNaming::Binding_out b_out (b);
  CORBA::NamedValue_ptr nv_b;
  CORBA::Any 	 any_b (CosNaming::_tc_Binding, b, 1); // ORB owns
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_b = nvlist->add_value ("b", any_b, CORBA::ARG_OUT, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::BindingIterator_ptr) _tao_object_reference->get_subclass ();
   *retval = impl->next_one(b_out, _tao_environment);
  result = new CORBA::Any (CORBA::_tc_boolean, retval, 1); // ORB owns
  _tao_server_request.result (result, _tao_environment);
  
}

void POA_CosNaming::BindingIterator::next_n_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::BindingIterator_ptr 	 impl;
  CORBA::Any *result;
  CORBA::Boolean *retval = new CORBA::Boolean;
  CORBA::ULong how_many;
  CORBA::NamedValue_ptr nv_how_many;
  CORBA::Any 	 any_how_many (CORBA::_tc_ulong, &how_many); // ORB does not own
  CosNaming::BindingList *bl;
  CosNaming::BindingList_out bl_out (bl);
  CORBA::NamedValue_ptr nv_bl;
  CORBA::Any 	 any_bl (CosNaming::_tc_BindingList, bl, 1); // ORB owns
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  nv_how_many = nvlist->add_value ("how_many", any_how_many, CORBA::ARG_IN, _tao_environment);
  nv_bl = nvlist->add_value ("bl", any_bl, CORBA::ARG_OUT, _tao_environment);
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::BindingIterator_ptr) _tao_object_reference->get_subclass ();
   *retval = impl->next_n(how_many, bl_out, _tao_environment);
  result = new CORBA::Any (CORBA::_tc_boolean, retval, 1); // ORB owns
  _tao_server_request.result (result, _tao_environment);
  
}

void POA_CosNaming::BindingIterator::destroy_skel (CORBA::ServerRequest &_tao_server_request, CORBA::Object_ptr _tao_object_reference, CORBA::Environment &_tao_environment)
{
  CORBA::NVList_ptr 	 nvlist;
  POA_CosNaming::BindingIterator_ptr 	 impl;
  
  // create an NV list and populate it with typecodes
  _tao_server_request.orb ()->create_list (0, nvlist); // initialize a list
  // add each argument according to the in, out, inout semantics
  // parse the arguments
  _tao_server_request.params (nvlist, _tao_environment);
  if (_tao_environment.exception ()) return;
  impl = (POA_CosNaming::BindingIterator_ptr) _tao_object_reference->get_subclass ();
  impl->destroy(_tao_environment);
  
}

void POA_CosNaming::BindingIterator::_is_a_skel (CORBA::ServerRequest &req, CORBA::Object_ptr /* obj */, CORBA::Environment &env)
{
  const CORBA::String type_id = "IDL:CosNaming/BindingIterator:1.0"; // repository ID
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

