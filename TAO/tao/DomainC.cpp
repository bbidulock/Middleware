/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
//
// And later modified by Jeff Parsons
//
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html
//
//

#include "tao/DomainC.h"
#include "tao/Stub.h"
#include "tao/Invocation.h"
#include "tao/varout.h"
#include "tao/POA_CORBA.h"
#include "tao/ORB.h"

#if !defined (__ACE_INLINE__)
#include "DomainC.i"
#endif /* !defined INLINE */

const CORBA::PolicyType CORBA::SecConstruction = 11;

CORBA::DomainManager_ptr
CORBA_DomainManager::_nil (void)
{
  return (CORBA::DomainManager_ptr)0;
}

CORBA_DomainManager_ptr CORBA_DomainManager::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_DomainManager::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:omg.org/CORBA/DomainManager:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_DomainManager::_nil ());
  if (is_a == 0)
    return CORBA_DomainManager::_nil ();
  return CORBA_DomainManager::_unchecked_narrow (obj, ACE_TRY_ENV);
}

CORBA_DomainManager_ptr CORBA_DomainManager::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  ACE_UNUSED_ARG (ACE_TRY_ENV);
  if (CORBA::is_nil (obj))
    return CORBA_DomainManager::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/DomainManager:1.0");
  if (servant == 0)
    return new CORBA_DomainManager(stub);
  return new POA_CORBA::_tao_collocated_DomainManager(
      ACE_reinterpret_cast(POA_CORBA::DomainManager_ptr, servant),
      stub
    );
}

CORBA_DomainManager_ptr
CORBA_DomainManager::_duplicate (CORBA_DomainManager_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  return obj;
}

CORBA::Policy_ptr CORBA_DomainManager::get_domain_policy (
    CORBA::PolicyType policy_type,
    CORBA::Environment &ACE_TRY_ENV
  )
{
    CORBA::Policy_ptr _tao_retval = CORBA::Policy::_nil ();

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "get_domain_policy",
      istub->orb_core ()
    );


  for (;;)
  {
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
    if (!(
          (_tao_out << policy_type)
      ))
      ACE_THROW_RETURN (CORBA::MARSHAL (), _tao_retval);

    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);

    }
    break;

  }
  TAO_InputCDR &_tao_in = _tao_call.inp_stream ();
  if (!(
        (_tao_in >> _tao_retval)
    ))
    ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);
  return _tao_retval;
}

CORBA::Boolean CORBA_DomainManager::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/DomainManager:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

const char* CORBA_DomainManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/DomainManager:1.0";
}

#if ! defined (TAO_HAS_MINIMUM_CORBA)

CORBA::ConstructionPolicy_ptr CORBA::ConstructionPolicy::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA::ConstructionPolicy::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:omg.org/CORBA/ConstructionPolicy:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::ConstructionPolicy::_nil ());
  if (is_a == 0)
    return CORBA::ConstructionPolicy::_nil ();
  return CORBA::ConstructionPolicy::_unchecked_narrow (obj, ACE_TRY_ENV);
}

CORBA::ConstructionPolicy_ptr CORBA::ConstructionPolicy::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  ACE_UNUSED_ARG (ACE_TRY_ENV);
  if (CORBA::is_nil (obj))
    return CORBA::ConstructionPolicy::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/ConstructionPolicy:1.0");
  if (servant == 0)
    return new CORBA::ConstructionPolicy(stub);
  return new POA_CORBA::_tao_collocated_ConstructionPolicy(
      ACE_reinterpret_cast(POA_CORBA::ConstructionPolicy_ptr, servant),
      stub
    );
}

CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_duplicate (CORBA::ConstructionPolicy_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  return obj;
}

void CORBA::ConstructionPolicy::make_domain_manager (
    CORBA::InterfaceDef_ptr object_type,
    CORBA::Boolean constr_policy,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  // @@ TODO this method will require some modifications once the
  // interface repository is implemented. The modifications are
  // documented with @@ comments.

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW (CORBA::INTERNAL ());


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "make_domain_manager",
      istub->orb_core ()
    );


  for (;;)
  {
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK;

#if 0
    TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
  // @@ The insertion operation (<<) for InterfaceDef will be
  // defined, and thus this code will work.
    if (!(
          (_tao_out << object_type) &&
          (_tao_out << CORBA::Any::from_boolean (constr_policy))
      ))
      ACE_THROW (CORBA::MARSHAL ());
#else
    ACE_UNUSED_ARG (object_type);
    ACE_UNUSED_ARG (constr_policy);
#endif /* 0 */

    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK;

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES));

    }
    break;

  }

}

CORBA::Boolean CORBA::ConstructionPolicy::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/ConstructionPolicy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

const char* CORBA::ConstructionPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/ConstructionPolicy:1.0";
}

#endif /* ! defined (TAO_HAS_MINIMUM_CORBA) */

// *************************************************************
// CORBA_DomainManagerList
// *************************************************************

CORBA_DomainManagerList::CORBA_DomainManagerList (void)
{}

CORBA_DomainManagerList::CORBA_DomainManagerList (CORBA::ULong max) // uses max size
  : TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var> (max)
{}

CORBA_DomainManagerList::CORBA_DomainManagerList (CORBA::ULong max,
                                                  CORBA::ULong length,
                                                  CORBA_DomainManager_ptr *buffer,
                                                  CORBA::Boolean release)
  : TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var> (max,
                                                        length,
                                                        buffer,
                                                        release)
{}

CORBA_DomainManagerList::CORBA_DomainManagerList (const CORBA_DomainManagerList &seq) // copy ctor
  : TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var> (seq)
{}

CORBA_DomainManagerList::~CORBA_DomainManagerList (void) // dtor
{}

void operator<<= (CORBA::Any &_tao_any, CORBA_DomainManager_ptr _tao_elem)
{
  CORBA::Object_ptr *_tao_obj_ptr = 0;
  ACE_TRY_NEW_ENV
  {
    ACE_NEW (_tao_obj_ptr, CORBA::Object_ptr);
    *_tao_obj_ptr = CORBA_DomainManager::_duplicate (_tao_elem);
    _tao_any.replace (CORBA::_tc_DomainManager, _tao_obj_ptr, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_obj_ptr;
  }
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_DomainManager_ptr &_tao_elem)
{
  CORBA::Object_ptr *tmp = 0;
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA_DomainManager::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_DomainManager, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    TAO_InputCDR stream (_tao_any._tao_get_cdr ());
    CORBA::Object_var _tao_obj_var;
    ACE_NEW_RETURN (tmp, CORBA::Object_ptr, 0);
    if (stream.decode (CORBA::_tc_DomainManager, &_tao_obj_var.out (), 0, ACE_TRY_ENV)
       == CORBA::TypeCode::TRAVERSE_CONTINUE)
    {
      _tao_elem = CORBA_DomainManager::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      *tmp = (CORBA::Object_ptr) _tao_elem;  // any owns the object
      ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_DomainManager, tmp, 1, ACE_TRY_ENV);
      ACE_TRY_CHECK;
      return 1;
    }
    // failure
  }
  ACE_CATCHANY
  {
    delete tmp;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<CORBA_DomainManager,CORBA_DomainManager_var>;
  template class TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>;
  template class TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Object_Field_T<CORBA_DomainManager,CORBA_DomainManager_var>
# pragma instantiate TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>
# pragma instantiate TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#if ! defined (TAO_HAS_MINIMUM_CORBA)

void operator<<= (CORBA::Any &_tao_any, CORBA_ConstructionPolicy_ptr _tao_elem)
{
  CORBA::Object_ptr *_tao_obj_ptr = 0;
  ACE_TRY_NEW_ENV
  {
    ACE_NEW (_tao_obj_ptr, CORBA::Object_ptr);
    *_tao_obj_ptr = CORBA_ConstructionPolicy::_duplicate (_tao_elem);
    _tao_any.replace (CORBA::_tc_ConstructionPolicy, _tao_obj_ptr, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_obj_ptr;
  }
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_ConstructionPolicy_ptr &_tao_elem)
{
  CORBA::Object_ptr *tmp = 0;
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA_ConstructionPolicy::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_ConstructionPolicy, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    TAO_InputCDR stream (_tao_any._tao_get_cdr ());
    CORBA::Object_var _tao_obj_var;
    ACE_NEW_RETURN (tmp, CORBA::Object_ptr, 0);
    if (stream.decode (CORBA::_tc_ConstructionPolicy, &_tao_obj_var.out (), 0, ACE_TRY_ENV)
       == CORBA::TypeCode::TRAVERSE_CONTINUE)
    {
      _tao_elem = CORBA_ConstructionPolicy::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      *tmp = (CORBA::Object_ptr) _tao_elem;  // any owns the object
      ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_ConstructionPolicy, tmp, 1, ACE_TRY_ENV);
      ACE_TRY_CHECK;
      return 1;
    }
    // failure
  }
  ACE_CATCHANY
  {
    delete tmp;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<CORBA_ConstructionPolicy,CORBA_ConstructionPolicy_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Object_Field_T<CORBA_ConstructionPolicy,CORBA_ConstructionPolicy_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* ! defined (TAO_HAS_MINIMUM_CORBA) */

void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA_DomainManagerList &_tao_elem
  ) // copying
{
  CORBA_DomainManagerList *_tao_any_val;
  ACE_NEW (_tao_any_val, CORBA_DomainManagerList (_tao_elem));
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_DomainManagerList, _tao_any_val, 1, ACE_TRY_ENV); // copy the value
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, CORBA_DomainManagerList *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_DomainManagerList, _tao_elem, 0, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_DomainManagerList *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_DomainManagerList, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA_DomainManagerList *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA_DomainManagerList, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (CORBA::_tc_DomainManagerList, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_DomainManagerList, _tao_elem, 1, ACE_TRY_ENV);
        ACE_TRY_CHECK;
        return 1;
      }
      else
      {
        delete _tao_elem;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}
