/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "DomainC.h"
#include "Stub.h"
#include "Invocation.h"
#include "Exception.h"
#include "tao/IFR_Client_Adapter.h"
#include "ORB_Core.h"
#include "ace/Dynamic_Service.h"

#if !defined (__ACE_INLINE__)
#include "DomainC.i"
#endif /* !defined INLINE */

#include "PortableInterceptor.h"
#include "RequestInfo_Util.h"

// default constructor
CORBA_DomainManager::CORBA_DomainManager (void)
{}

// destructor
CORBA_DomainManager::~CORBA_DomainManager (void)
{}

void CORBA_DomainManager::_tao_any_destructor (void *x)
{
  CORBA_DomainManager *tmp = ACE_static_cast (CORBA_DomainManager*,x);
  CORBA::release (tmp);
}

CORBA_DomainManager_ptr CORBA_DomainManager::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_DomainManager::_nil ();
  if (! obj->_is_local ())
    {
      CORBA::Boolean is_a = obj->_is_a ("IDL:CORBA/DomainManager:1.0", ACE_TRY_ENV);
      ACE_CHECK_RETURN (CORBA_DomainManager::_nil ());
      if (is_a == 0)
        return CORBA_DomainManager::_nil ();
    }
  return CORBA_DomainManager::_unchecked_narrow (obj, ACE_TRY_ENV);
}

CORBA_DomainManager_ptr CORBA_DomainManager::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_DomainManager::_nil ();
  if (! obj->_is_local ())
    {
      TAO_Stub* stub = obj->_stubobj ();
      if (stub)
        stub->_incr_refcnt ();
      CORBA_DomainManager_ptr default_proxy = CORBA_DomainManager::_nil ();

      if (obj->_is_collocated () && _TAO_collocation_CORBA_DomainManager_Stub_Factory_function_pointer != 0)
        {
          default_proxy = _TAO_collocation_CORBA_DomainManager_Stub_Factory_function_pointer (obj);
        }
      if (CORBA::is_nil (default_proxy))
        ACE_NEW_RETURN (default_proxy, ::CORBA_DomainManager (stub), CORBA_DomainManager::_nil ());
      return default_proxy;
    }
  else
    return
      ACE_reinterpret_cast
        (
          CORBA_DomainManager_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &CORBA_DomainManager::_narrow
                  )
              )
        );
}

CORBA_DomainManager_ptr
CORBA_DomainManager::_duplicate (CORBA_DomainManager_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

CORBA::Policy_ptr CORBA_DomainManager::get_domain_policy (
    CORBA::PolicyType policy_type,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{

  CORBA::Policy_ptr _tao_retval = CORBA::Policy::_nil ();
  CORBA::Policy_var _tao_safe_retval (_tao_retval);


  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), 0);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "get_domain_policy",
      17,
      1,
      istub->orb_core ()
    );

#if (TAO_HAS_INTERCEPTORS == 1)
    TAO_ClientRequestInterceptor_Adapter
      _tao_vfr (istub->orb_core ()->client_request_interceptors ());

    CORBA_DomainManager::TAO_ClientRequest_Info_CORBA_DomainManager_get_domain_policy
      ri (&_tao_call,
          this,
          policy_type);

  ACE_TRY
    {
#endif /* TAO_HAS_INTERCEPTORS */

    for (;;)
    {
      _tao_call.start (ACE_TRY_ENV);
      TAO_INTERCEPTOR_CHECK_RETURN (0);

      TAO_INTERCEPTOR (
           _tao_vfr.send_request (
              &ri,
              ACE_TRY_ENV
            )
        );
      TAO_INTERCEPTOR_CHECK_RETURN (0);
      CORBA::Short _tao_response_flag = TAO_TWOWAY_RESPONSE_FLAG;

      _tao_call.prepare_header (
          ACE_static_cast (CORBA::Octet, _tao_response_flag), ACE_TRY_ENV
        );
      TAO_INTERCEPTOR_CHECK_RETURN (0);

      TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
      if (!(
            (_tao_out << policy_type)
        ))
      TAO_INTERCEPTOR_THROW_RETURN (CORBA::MARSHAL (), 0);

      int _invoke_status =
        _tao_call.invoke (0, 0, ACE_TRY_ENV);
            TAO_INTERCEPTOR_CHECK_RETURN (0);

      if (_invoke_status == TAO_INVOKE_RESTART)
        continue;
      if (_invoke_status != TAO_INVOKE_OK)
      {
        TAO_INTERCEPTOR_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), 0);

      }
      TAO_InputCDR &_tao_in = _tao_call.inp_stream ();
      if (!(
            (_tao_in >> _tao_safe_retval.inout ())
        ))
      TAO_INTERCEPTOR_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), 0);
    TAO_INTERCEPTOR (
        CORBA::Policy_ptr  _tao_retval_info = _tao_safe_retval._retn ();

         ri.result (_tao_retval_info);
        _tao_safe_retval = _tao_retval_info;

    );

    TAO_INTERCEPTOR (
        _tao_vfr.receive_reply (
          &ri,
          ACE_TRY_ENV
        )
    );
    TAO_INTERCEPTOR_CHECK_RETURN (0);
    break;

  }
#if (TAO_HAS_INTERCEPTORS == 1)

}
ACE_CATCHANY
  {
    ri.exception (&ACE_ANY_EXCEPTION);
    _tao_vfr.receive_exception (
        &ri,
        ACE_TRY_ENV
      );
    ACE_RE_THROW;
  }
ACE_ENDTRY;
ACE_CHECK_RETURN (0);
#endif /* TAO_HAS_INTERCEPTORS */
return _tao_safe_retval._retn ();
}

CORBA::Boolean CORBA_DomainManager::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:CORBA/DomainManager:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

void *CORBA_DomainManager::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &CORBA_DomainManager::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (
               void *,
               ACE_static_cast (CORBA::Object_ptr, this)
             );

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* CORBA_DomainManager::_interface_repository_id (void) const
{
  return "IDL:CORBA/DomainManager:1.0";
}


#if (TAO_HAS_INTERCEPTORS == 1)

CORBA_DomainManager::TAO_ClientRequest_Info_CORBA_DomainManager_get_domain_policy::TAO_ClientRequest_Info_CORBA_DomainManager_get_domain_policy (
    TAO_GIOP_Invocation *_tao_invocation,
    CORBA::Object *_tao_target,
    CORBA::PolicyType &policy_type)
  : TAO_ClientRequestInfo (_tao_invocation, _tao_target),
    policy_type_ (policy_type)
{}

Dynamic::ParameterList *
CORBA_DomainManager::TAO_ClientRequest_Info_CORBA_DomainManager_get_domain_policy::arguments (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Dynamic::ParameterList *parameter_list =
    TAO_RequestInfo_Util::make_parameter_list (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  Dynamic::ParameterList_var safe_parameter_list = parameter_list;

  // Generate the arg list on demand
  CORBA::ULong len = parameter_list->length ();
  parameter_list->length (len + 1);
  (*parameter_list)[len].argument <<=  this->policy_type_;

  (*parameter_list)[len].mode = Dynamic::PARAM_IN;

  return safe_parameter_list._retn ();
}

Dynamic::ExceptionList *
CORBA_DomainManager::TAO_ClientRequest_Info_CORBA_DomainManager_get_domain_policy::exceptions (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the exception list on demand.
  Dynamic::ExceptionList *exception_list =
    TAO_RequestInfo_Util::make_exception_list (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  return exception_list;
}


CORBA::Any *
CORBA_DomainManager::TAO_ClientRequest_Info_CORBA_DomainManager_get_domain_policy::result (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the result on demand.
  CORBA::Boolean tk_void_any = 0;
  CORBA::Any *result_any =
    TAO_RequestInfo_Util::make_any (tk_void_any, ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  CORBA::Any_var safe_result_any = result_any;

  (*result_any) <<= this->_result;

  return safe_result_any._retn ();
}

void
CORBA_DomainManager::TAO_ClientRequest_Info_CORBA_DomainManager_get_domain_policy::result (CORBA::Policy_ptr  result)
{
  // update the result
  this->_result = result;
}

#endif /* TAO_HAS_INTERCEPTORS */

#if (TAO_HAS_MINIMUM_CORBA == 0)

// default constructor
CORBA_ConstructionPolicy::CORBA_ConstructionPolicy (void)
{}

// destructor
CORBA_ConstructionPolicy::~CORBA_ConstructionPolicy (void)
{}

void CORBA_ConstructionPolicy::_tao_any_destructor (void *x)
{
  CORBA_ConstructionPolicy *tmp = ACE_static_cast (CORBA_ConstructionPolicy*,x);
  CORBA::release (tmp);
}

CORBA_ConstructionPolicy_ptr CORBA_ConstructionPolicy::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_ConstructionPolicy::_nil ();
  if (! obj->_is_local ())
    {
      CORBA::Boolean is_a = obj->_is_a ("IDL:CORBA/ConstructionPolicy:1.0", ACE_TRY_ENV);
      ACE_CHECK_RETURN (CORBA_ConstructionPolicy::_nil ());
      if (is_a == 0)
        return CORBA_ConstructionPolicy::_nil ();
    }
  return CORBA_ConstructionPolicy::_unchecked_narrow (obj, ACE_TRY_ENV);
}

CORBA_ConstructionPolicy_ptr CORBA_ConstructionPolicy::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_ConstructionPolicy::_nil ();
  if (! obj->_is_local ())
    {
      TAO_Stub* stub = obj->_stubobj ();
      if (stub)
        stub->_incr_refcnt ();
      CORBA_ConstructionPolicy_ptr default_proxy = CORBA_ConstructionPolicy::_nil ();

      if (obj->_is_collocated () && _TAO_collocation_CORBA_ConstructionPolicy_Stub_Factory_function_pointer != 0)
        {
          default_proxy = _TAO_collocation_CORBA_ConstructionPolicy_Stub_Factory_function_pointer (obj);
        }
      if (CORBA::is_nil (default_proxy))
        ACE_NEW_RETURN (default_proxy, ::CORBA_ConstructionPolicy (stub), CORBA_ConstructionPolicy::_nil ());
      return default_proxy;
    }
  else
    return
      ACE_reinterpret_cast
        (
          CORBA_ConstructionPolicy_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &CORBA_ConstructionPolicy::_narrow
                  )
              )
        );
}

CORBA_ConstructionPolicy_ptr
CORBA_ConstructionPolicy::_duplicate (CORBA_ConstructionPolicy_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void CORBA_ConstructionPolicy::make_domain_manager (
    IR_InterfaceDef *object_type,
    CORBA::Boolean constr_policy,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW (CORBA::INTERNAL ());


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "make_domain_manager",
      19,
      1,
      istub->orb_core ()
    );

#if (TAO_HAS_INTERCEPTORS == 1)

  TAO_ClientRequestInterceptor_Adapter _tao_vfr (
      istub->orb_core ()->client_request_interceptors ()
    );

  CORBA_ConstructionPolicy::TAO_ClientRequest_Info_CORBA_ConstructionPolicy_make_domain_manager ri (
      &_tao_call,
      this,
      object_type,
      constr_policy,
      ACE_TRY_ENV
    );
  ACE_CHECK;
  ACE_TRY
    {
#endif /* TAO_HAS_INTERCEPTORS */

      TAO_IFR_Client_Adapter *adapter =
        ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
            TAO_ORB_Core::ifr_client_adapter_name ()
          );

      for (;;)
        {
          _tao_call.start (ACE_TRY_ENV);
          TAO_INTERCEPTOR_CHECK;

          TAO_INTERCEPTOR (
               _tao_vfr.send_request (
                  &ri,
                  ACE_TRY_ENV
                )
            );
          TAO_INTERCEPTOR_CHECK;
          CORBA::Short _tao_response_flag = TAO_TWOWAY_RESPONSE_FLAG;

          _tao_call.prepare_header (
              ACE_static_cast (CORBA::Octet, _tao_response_flag), ACE_TRY_ENV
            );
          TAO_INTERCEPTOR_CHECK;

          TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
          if (!(
                (adapter->interfacedef_cdr_insert (_tao_out, object_type)) &&
                (_tao_out << CORBA::Any::from_boolean (constr_policy))
            ))
          TAO_INTERCEPTOR_THROW (CORBA::MARSHAL());
          int _invoke_status =
            _tao_call.invoke (0, 0, ACE_TRY_ENV);
                TAO_INTERCEPTOR_CHECK;

          if (_invoke_status == TAO_INVOKE_RESTART)
            continue;
          if (_invoke_status != TAO_INVOKE_OK)
          {
            TAO_INTERCEPTOR_THROW (CORBA::UNKNOWN(TAO_DEFAULT_MINOR_CODE,
                                   CORBA::COMPLETED_YES));
          }

          TAO_INTERCEPTOR (
              _tao_vfr.receive_reply (
                &ri,
                ACE_TRY_ENV
              )
          );
          TAO_INTERCEPTOR_CHECK;
          break;
        }

#if (TAO_HAS_INTERCEPTORS == 1)

    }
  ACE_CATCHANY
    {
      ri.exception (&ACE_ANY_EXCEPTION);
      _tao_vfr.receive_exception (
          &ri,
          ACE_TRY_ENV
        );
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;

#endif /* TAO_HAS_INTERCEPTORS */
}

CORBA::Boolean CORBA_ConstructionPolicy::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:CORBA/ConstructionPolicy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

void *CORBA_ConstructionPolicy::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &CORBA_ConstructionPolicy::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &::CORBA::Policy::_narrow))
    retv = ACE_reinterpret_cast
      (
        void *,
        ACE_static_cast
          (
            CORBA::Policy_ptr,
            this
          )
      );
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));

  if (retv)
    this->_add_ref ();
  return retv;
}

const char* CORBA_ConstructionPolicy::_interface_repository_id (void) const
{
  return "IDL:CORBA/ConstructionPolicy:1.0";
}


#if (TAO_HAS_INTERCEPTORS == 1)

CORBA_ConstructionPolicy::TAO_ClientRequest_Info_CORBA_ConstructionPolicy_make_domain_manager::TAO_ClientRequest_Info_CORBA_ConstructionPolicy_make_domain_manager (
    TAO_GIOP_Invocation *_tao_invocation,
    CORBA::Object *_tao_target,
    IR_InterfaceDef *object_type,
    CORBA::Boolean &constr_policy,
    CORBA::Environment &
  )
  : TAO_ClientRequestInfo (_tao_invocation, _tao_target),
    object_type_ (object_type),
    constr_policy_ (constr_policy)
{}

Dynamic::ParameterList *
CORBA_ConstructionPolicy::TAO_ClientRequest_Info_CORBA_ConstructionPolicy_make_domain_manager::arguments (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the arg list on demand.
  Dynamic::ParameterList *parameter_list =
    TAO_RequestInfo_Util::make_parameter_list (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  Dynamic::ParameterList_var safe_parameter_list = parameter_list;

  CORBA::ULong len = parameter_list->length ();
  parameter_list->length (len + 1);

  TAO_IFR_Client_Adapter *adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );

  adapter->interfacedef_any_insert ((*parameter_list)[len].argument,
                                    this->object_type_);
    
  (*parameter_list)[len].mode = Dynamic::PARAM_IN;
  len = parameter_list->length ();
  parameter_list->length (len + 1);
  (*parameter_list)[len].argument <<= CORBA::Any::from_boolean (this->constr_policy_ );
  (*parameter_list)[len].mode = Dynamic::PARAM_IN;

  return safe_parameter_list._retn ();
}

Dynamic::ExceptionList *
CORBA_ConstructionPolicy::TAO_ClientRequest_Info_CORBA_ConstructionPolicy_make_domain_manager::exceptions (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the exception list on demand.
  Dynamic::ExceptionList *exception_list =
    TAO_RequestInfo_Util::make_exception_list (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  return exception_list;
}


CORBA::Any *
CORBA_ConstructionPolicy::TAO_ClientRequest_Info_CORBA_ConstructionPolicy_make_domain_manager::result (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the result on demand.
  CORBA::Boolean tk_void_any = 1;
  CORBA::Any *result_any =
    TAO_RequestInfo_Util::make_any (tk_void_any, ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  return result_any;
}

#endif /* TAO_HAS_INTERCEPTORS */

CORBA_ConstructionPolicy_ptr (*_TAO_collocation_CORBA_ConstructionPolicy_Stub_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

void operator<<= (CORBA::Any &_tao_any, CORBA_ConstructionPolicy_ptr _tao_elem)
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_ConstructionPolicy,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin (),
          1,
          CORBA_ConstructionPolicy::_duplicate (_tao_elem),
          CORBA_ConstructionPolicy::_tao_any_destructor
        );
    }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_ConstructionPolicy_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
    {
      _tao_elem = CORBA_ConstructionPolicy::_nil ();
      CORBA::TypeCode_var type = _tao_any.type ();
      CORBA::Boolean result =
        type->equivalent (CORBA::_tc_ConstructionPolicy, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (!result)
        {
          return 0;
        }

      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      if (stream >> _tao_elem)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            CORBA::_tc_ConstructionPolicy,
            1,
            _tao_elem,
            CORBA_ConstructionPolicy::_tao_any_destructor
          );
        return 1;
      }
    }
  ACE_CATCHANY
    {
      _tao_elem = CORBA_ConstructionPolicy::_nil ();
      return 0;
    }
  ACE_ENDTRY;
  _tao_elem = CORBA_ConstructionPolicy::_nil ();
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
      defined (ACE_HAS_GNU_REPO)
template class TAO_Object_Manager<CORBA_ConstructionPolicy,CORBA_ConstructionPolicy_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Manager<CORBA_ConstructionPolicy,CORBA_ConstructionPolicy_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_MINIMUM_CORBA */

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_DOMAINMANAGERLIST_CS_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_DOMAINMANAGERLIST_CS_

// The Base_Sequence functions, please see tao/Sequence.h
void
_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_allocate_buffer (CORBA::ULong length)
{
  CORBA_DomainManager **tmp = 0;
  tmp = _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::allocbuf (length);

  if (this->buffer_ != 0)
    {
      CORBA_DomainManager **old = ACE_reinterpret_cast (CORBA_DomainManager**, this->buffer_);
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        if (!this->release_)
          tmp[i] = CORBA_DomainManager::_duplicate (old[i]);
        else
          tmp[i] = old[i];

      if (this->release_)
        delete[] old;

    }
  this->buffer_ = tmp;
}

void
_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_deallocate_buffer (void)
{
  if (this->buffer_ == 0 || this->release_ == 0)
    return;
  CORBA_DomainManager **tmp = ACE_reinterpret_cast (CORBA_DomainManager**, this->buffer_);
  for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = CORBA_DomainManager::_nil ();
    }
  _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::freebuf (tmp);
  this->buffer_ = 0;
}

_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::~_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList (void)
{
  this->_deallocate_buffer ();
}

void
_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_shrink_buffer (CORBA::ULong nl, CORBA::ULong ol)
{
  CORBA_DomainManager **tmp = ACE_reinterpret_cast (CORBA_DomainManager**, this->buffer_);

  for (CORBA::ULong i = nl; i < ol; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = CORBA_DomainManager::_nil ();
    }
}

void
_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_downcast (
    void* target,
    CORBA_Object *src,
    CORBA_Environment &ACE_TRY_ENV
  )
{
  CORBA_DomainManager **tmp = ACE_static_cast (CORBA_DomainManager**, target);
  *tmp = CORBA_DomainManager::_narrow (src, ACE_TRY_ENV);
}

CORBA_Object*
_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_upcast (void *src) const
{
  CORBA_DomainManager **tmp = ACE_static_cast (CORBA_DomainManager**, src);
  return *tmp;
}

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_DOMAINMANAGERLIST_CS_)
#define _CORBA_DOMAINMANAGERLIST_CS_

// *************************************************************
// CORBA_DomainManagerList
// *************************************************************

CORBA_DomainManagerList::CORBA_DomainManagerList (void)
{}

CORBA_DomainManagerList::CORBA_DomainManagerList (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
  (max)
{}

CORBA_DomainManagerList::CORBA_DomainManagerList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA_DomainManager_ptr *buffer,
    CORBA::Boolean release
  )
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
  (max, length, buffer, release)
{}

CORBA_DomainManagerList::CORBA_DomainManagerList (
    const CORBA_DomainManagerList &seq
  ) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
  (seq)
{}

CORBA_DomainManagerList::~CORBA_DomainManagerList (void) // dtor
{}

void CORBA_DomainManagerList::_tao_any_destructor (void *x)
{
  CORBA_DomainManagerList *tmp = ACE_static_cast (CORBA_DomainManagerList*,x);
  delete tmp;
}

#endif /* end #if !defined */

CORBA_DomainManager_ptr (*_TAO_collocation_CORBA_DomainManager_Stub_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

void operator<<= (CORBA::Any &_tao_any, CORBA_DomainManager_ptr _tao_elem)
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_DomainManager,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin (),
          1,
          CORBA_DomainManager::_duplicate (_tao_elem),
          CORBA_DomainManager::_tao_any_destructor
        );
    }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_DomainManager_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
    {
      _tao_elem = CORBA_DomainManager::_nil ();
      CORBA::TypeCode_var type = _tao_any.type ();
      CORBA::Boolean result =
        type->equivalent (CORBA::_tc_DomainManager, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (!result)
        {
          return 0;
        }

      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      if (stream >> _tao_elem)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            CORBA::_tc_DomainManager,
            1,
            _tao_elem,
            CORBA_DomainManager::_tao_any_destructor
          );
        return 1;
      }
    }
  ACE_CATCHANY
    {
      _tao_elem = CORBA_DomainManager::_nil ();
      return 0;
    }
  ACE_ENDTRY;
  _tao_elem = CORBA_DomainManager::_nil ();
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
      defined (ACE_HAS_GNU_REPO)
  template class TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA_DomainManagerList &_tao_elem
  ) // copying
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_DomainManagerList,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

void operator<<= (CORBA::Any &_tao_any, CORBA_DomainManagerList *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      CORBA::_tc_DomainManagerList,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      CORBA_DomainManagerList::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_DomainManagerList *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const CORBA_DomainManagerList*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const CORBA_DomainManagerList *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
    {
      CORBA::TypeCode_var type = _tao_any.type ();
      CORBA::Boolean result =
        type->equivalent (CORBA::_tc_DomainManagerList, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (!result)
        {
          return 0;
        }

      if (_tao_any.any_owns_data ())
      {
        _tao_elem = ACE_static_cast(
            const CORBA_DomainManagerList*,
            _tao_any.value ()
          );
        return 1;
      }
      else
      {
        CORBA_DomainManagerList *tmp;
        ACE_NEW_RETURN (tmp, CORBA_DomainManagerList, 0);
        TAO_InputCDR stream (
            _tao_any._tao_get_cdr (),
            _tao_any._tao_byte_order ()
          );
        if (stream >> *tmp)
        {
          ((CORBA::Any *)&_tao_any)->_tao_replace (
              CORBA::_tc_DomainManagerList,
              1,
              ACE_static_cast (void *, tmp),
              CORBA_DomainManagerList::_tao_any_destructor
            );
          _tao_elem = tmp;
          return 1;
        }
        else
        {
          delete tmp;
        }
      }
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA_DomainManagerList &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
    {
      // encode all elements
      CORBA::Boolean _tao_marshal_flag = 1;
      for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      {
        _tao_marshal_flag = (strm << _tao_sequence[i].in ());
      }
      return _tao_marshal_flag;
    }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA_DomainManagerList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
    {
      // set the length of the sequence
      _tao_sequence.length (_tao_seq_len);
      // If length is 0 we return true.
      if (0 >= _tao_seq_len)
        return 1;
      // retrieve all the elements
      CORBA::Boolean _tao_marshal_flag = 1;
      for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      {
        _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
      }
      return _tao_marshal_flag;
    }
  return 0; // error
}
