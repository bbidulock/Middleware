// $Id$

/* -*- C++ -*- */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/PolicyC.h"
#include "tao/Stub.h"
#include "tao/Servant_Base.h"
#include "tao/POA_CORBA.h"
#include "tao/Invocation.h"

#if !defined (__ACE_INLINE__)
#include "PolicyC.i"
#endif /* !defined INLINE */

ACE_RCSID(tao, PolicyC, "$Id$")

// ****************************************************************

TAO_NAMESPACE_TYPE (const CORBA::PolicyErrorCode)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::PolicyErrorCode, BAD_POLICY, 0)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::PolicyErrorCode)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::PolicyErrorCode, UNSUPPORTED_POLICY, 1)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::PolicyErrorCode)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::PolicyErrorCode, BAD_POLICY_TYPE, 2)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::PolicyErrorCode)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::PolicyErrorCode, BAD_POLICY_VALUE, 3)
TAO_NAMESPACE_END
TAO_NAMESPACE_TYPE (const CORBA::PolicyErrorCode)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (const CORBA::PolicyErrorCode, UNSUPPORTED_POLICY_VALUE, 4)
TAO_NAMESPACE_END

// ****************************************************************

// default constructor
CORBA_PolicyError::CORBA_PolicyError (void)
  : CORBA_UserException (CORBA::_tc_PolicyError)
{
}

// destructor - all members are of self managing types
CORBA_PolicyError::~CORBA_PolicyError (void)
{
}

// copy constructor
CORBA_PolicyError::CORBA_PolicyError (const CORBA_PolicyError &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
    this->reason = _tao_excp.reason;
}

// assignment operator
CORBA_PolicyError&
CORBA_PolicyError::operator= (const CORBA_PolicyError &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  this->reason = _tao_excp.reason;
  return *this;
}

// narrow
CORBA_PolicyError_ptr
CORBA_PolicyError::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/PolicyError:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_PolicyError_ptr, exc);
  else
    return 0;
}

void CORBA_PolicyError::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_PolicyError::_alloc (void)
{
  return new CORBA_PolicyError;
}

CORBA_PolicyError::CORBA_PolicyError(
  CORBA::PolicyErrorCode _tao_reason)

  : CORBA_UserException  (CORBA::TypeCode::_duplicate (CORBA::_tc_PolicyError))
{
    this->reason = _tao_reason;
}

// ****************************************************************

// default constructor
CORBA_InvalidPolicies::CORBA_InvalidPolicies (void)
  : CORBA_UserException (CORBA::_tc_InvalidPolicies)
{
}

// destructor - all members are of self managing types
CORBA_InvalidPolicies::~CORBA_InvalidPolicies (void)
{
}

// copy constructor
CORBA_InvalidPolicies::CORBA_InvalidPolicies (const CORBA_InvalidPolicies &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
    this->indices = _tao_excp.indices;
}

// assignment operator
CORBA_InvalidPolicies&
CORBA_InvalidPolicies::operator= (const CORBA_InvalidPolicies &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  this->indices = _tao_excp.indices;
  return *this;
}

// narrow
CORBA_InvalidPolicies_ptr
CORBA_InvalidPolicies::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/InvalidPolicies:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_InvalidPolicies_ptr, exc);
  else
    return 0;
}

void CORBA_InvalidPolicies::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_InvalidPolicies::_alloc (void)
{
  return new CORBA_InvalidPolicies;
}

CORBA_InvalidPolicies::CORBA_InvalidPolicies(
  const CORBA_InvalidPolicies::_tao_seq_UShort & _tao_indices)

  : CORBA_UserException  (CORBA::TypeCode::_duplicate (CORBA::_tc_InvalidPolicies))
{
    this->indices = _tao_indices;
}

// ****************************************************************

CORBA_Policy_ptr CORBA_Policy::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_Policy::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:omg.org/CORBA/Policy:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_Policy::_nil ());
  if (is_a == 0)
    return CORBA_Policy::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/Policy:1.0");
  if (servant == 0)
#if defined (TAO_HAS_LOCALITY_CONSTRAINT_POLICIES)
    ACE_THROW_RETURN (CORBA::MARSHAL (), CORBA::Policy::_nil ());
#else
    return new CORBA_Policy(stub);
#endif /* TAO_HAS_LOCALITY_CONSTRAINT_POLICIES */
  return new POA_CORBA::_tao_collocated_Policy(
      ACE_reinterpret_cast(POA_CORBA::Policy_ptr, servant),
      stub
    );
}

CORBA_Policy_ptr CORBA_Policy::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_Policy::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/Policy:1.0");
  if (servant == 0)
#if defined (TAO_HAS_LOCALITY_CONSTRAINT_POLICIES)
    ACE_THROW_RETURN (CORBA::MARSHAL (), CORBA::Policy::_nil ());
#else
    return new CORBA_Policy(stub);
#endif /* TAO_HAS_LOCALITY_CONSTRAINT_POLICIES */
  return new POA_CORBA::_tao_collocated_Policy(
      ACE_reinterpret_cast(POA_CORBA::Policy_ptr, servant),
      stub
    );
}

#if !defined (TAO_HAS_LOCALITY_CONSTRAINT_POLICIES)
CORBA::PolicyType CORBA_Policy::policy_type (
    CORBA::Environment &ACE_TRY_ENV
  )
{
    CORBA::PolicyType _tao_retval = 0;

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "_get_""policy_type",
      istub->orb_core ()
    );


  for (;;)
  {
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

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

CORBA_Policy_ptr CORBA_Policy::copy (
    CORBA::Environment &ACE_TRY_ENV
  )
{
    CORBA_Policy_ptr _tao_retval = CORBA_Policy::_nil ();

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "copy",
      istub->orb_core ()
    );


  for (;;)
  {
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

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

void CORBA_Policy::destroy (
    CORBA::Environment &ACE_TRY_ENV
  )
{

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW (CORBA::INTERNAL ());


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "destroy",
      istub->orb_core ()
    );


  for (;;)
  {
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK;

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
#endif /* !TAO_HAS_LOCALITY_CONSTRAINT_POLICIES */

CORBA::Boolean CORBA_Policy::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV); // remote call
}

const char* CORBA_Policy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Policy:1.0";
}

CORBA_Policy_ptr
CORBA_Policy::_duplicate (CORBA_Policy_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  return obj;
}

CORBA_Policy_ptr
CORBA_Policy::_nil (void)
{
  return (CORBA_Policy_ptr)0;
}

// *************************************************************
// CORBA_PolicyList
// *************************************************************

CORBA_PolicyList::CORBA_PolicyList (void)
{}
CORBA_PolicyList::CORBA_PolicyList (CORBA::ULong max) // uses max size
  : TAO_Unbounded_Object_Sequence<CORBA_Policy,CORBA_Policy_var> (max)
{}
CORBA_PolicyList::CORBA_PolicyList (CORBA::ULong max, CORBA::ULong length, CORBA_Policy_ptr *buffer, CORBA::Boolean release)
  : TAO_Unbounded_Object_Sequence<CORBA_Policy,CORBA_Policy_var> (max, length, buffer, release)
{}
CORBA_PolicyList::CORBA_PolicyList (const CORBA_PolicyList &seq) // copy ctor
  : TAO_Unbounded_Object_Sequence<CORBA_Policy,CORBA_Policy_var> (seq)
{}
CORBA_PolicyList::~CORBA_PolicyList (void) // dtor
{}

// *************************************************************
// CORBA_PolicyTypeSeq
// *************************************************************

CORBA_PolicyTypeSeq::CORBA_PolicyTypeSeq (void)
{}
CORBA_PolicyTypeSeq::CORBA_PolicyTypeSeq (CORBA::ULong max) // uses max size
  : TAO_Unbounded_Sequence<CORBA::ULong>
 (max)
{}
CORBA_PolicyTypeSeq::CORBA_PolicyTypeSeq (CORBA::ULong max, CORBA::ULong length, CORBA::ULong *buffer, CORBA::Boolean release)
  : TAO_Unbounded_Sequence<CORBA::ULong> (max, length, buffer, release)
{}
CORBA_PolicyTypeSeq::CORBA_PolicyTypeSeq (const CORBA_PolicyTypeSeq &seq)
  : TAO_Unbounded_Sequence<CORBA::ULong> (seq)
{}
CORBA_PolicyTypeSeq::~CORBA_PolicyTypeSeq (void)
{}

// ****************************************************************

CORBA::PolicyManager_ptr CORBA_PolicyManager::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_PolicyManager::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:omg.org/CORBA/PolicyManager:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_PolicyManager::_nil ());
  if (is_a == 0)
    return CORBA_PolicyManager::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/PolicyManager:1.0");
  if (servant == 0)
    return new CORBA_PolicyManager(stub);
  return new POA_CORBA::_tao_collocated_PolicyManager(
      ACE_reinterpret_cast(POA_CORBA::PolicyManager_ptr, servant),
      stub
    );
}

CORBA_PolicyManager_ptr CORBA_PolicyManager::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_PolicyManager::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/PolicyManager:1.0");
  if (servant == 0)
    return new CORBA_PolicyManager(stub);
  return new POA_CORBA::_tao_collocated_PolicyManager(
      ACE_reinterpret_cast(POA_CORBA::PolicyManager_ptr, servant),
      stub
    );
}

CORBA_PolicyList * CORBA_PolicyManager::get_policy_overrides (
    const CORBA_PolicyTypeSeq & ts,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  CORBA_PolicyList* _tao_retval = 0;
  ACE_UNUSED_ARG (_tao_retval);
  ACE_UNUSED_ARG (ts);
  ACE_THROW_RETURN (CORBA::MARSHAL (), _tao_retval);
}

void CORBA_PolicyManager::set_policy_overrides (
    const CORBA_PolicyList & policies,
    CORBA::SetOverrideType set_add,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  ACE_UNUSED_ARG (policies);
  ACE_UNUSED_ARG (set_add);

  ACE_THROW (CORBA::MARSHAL ());
}

CORBA::Boolean CORBA_PolicyManager::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/PolicyManager:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV); // remote call
}

const char* CORBA_PolicyManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PolicyManager:1.0";
}

// ****************************************************************


CORBA_PolicyCurrent_ptr CORBA_PolicyCurrent::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_PolicyCurrent::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:omg.org/CORBA/PolicyCurrent:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_PolicyCurrent::_nil ());
  if (is_a == 0)
    return CORBA_PolicyCurrent::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/PolicyCurrent:1.0");
  if (servant == 0)
    return new CORBA_PolicyCurrent(stub);
  return new POA_CORBA::_tao_collocated_PolicyCurrent(
      ACE_reinterpret_cast(POA_CORBA::PolicyCurrent_ptr, servant),
      stub
    );
}

CORBA_PolicyCurrent_ptr CORBA_PolicyCurrent::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_PolicyCurrent::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/PolicyCurrent:1.0");
  if (servant == 0)
    return new CORBA_PolicyCurrent(stub);
  return new POA_CORBA::_tao_collocated_PolicyCurrent(
      ACE_reinterpret_cast(POA_CORBA::PolicyCurrent_ptr, servant),
      stub
    );
}

CORBA::Boolean CORBA_PolicyCurrent::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/PolicyCurrent:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/PolicyManager:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Current:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV); // remote call
}

const char* CORBA_PolicyCurrent::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PolicyCurrent:1.0";
}

// ****************************************************************


void operator<<= (CORBA::Any &_tao_any, const CORBA_PolicyError &_tao_elem) // copying
{
  CORBA_PolicyError *_tao_any_val = new CORBA_PolicyError (_tao_elem);
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_PolicyError, _tao_any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, CORBA_PolicyError *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_PolicyError, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_PolicyError *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_PolicyError, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA_PolicyError *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA_PolicyError, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (CORBA::_tc_PolicyError, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_PolicyError, _tao_elem, 1, ACE_TRY_ENV);
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

void operator<<= (CORBA::Any &_tao_any, const CORBA_InvalidPolicies &_tao_elem) // copying
{
  CORBA_InvalidPolicies *_tao_any_val = new CORBA_InvalidPolicies (_tao_elem);
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_InvalidPolicies, _tao_any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, CORBA_InvalidPolicies *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_InvalidPolicies, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_InvalidPolicies *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_InvalidPolicies, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA_InvalidPolicies *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA_InvalidPolicies, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (CORBA::_tc_InvalidPolicies, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_InvalidPolicies, _tao_elem, 1, ACE_TRY_ENV);
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

void operator<<= (CORBA::Any &_tao_any, CORBA_Policy_ptr _tao_elem)
{
  CORBA::Object_ptr *_tao_obj_ptr = 0;
  ACE_TRY_NEW_ENV
  {
    ACE_NEW (_tao_obj_ptr, CORBA::Object_ptr);
    *_tao_obj_ptr = CORBA_Policy::_duplicate (_tao_elem);
    _tao_any.replace (CORBA::_tc_Policy, _tao_obj_ptr, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_obj_ptr;
  }
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_Policy_ptr &_tao_elem)
{
  CORBA::Object_ptr *tmp = 0;
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA_Policy::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_Policy, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    TAO_InputCDR stream (_tao_any._tao_get_cdr ());
    CORBA::Object_var _tao_obj_var;
    ACE_NEW_RETURN (tmp, CORBA::Object_ptr, 0);
    if (stream.decode (CORBA::_tc_Policy, &_tao_obj_var.out (), 0, ACE_TRY_ENV)
       == CORBA::TypeCode::TRAVERSE_CONTINUE)
    {
      _tao_elem = CORBA_Policy::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      *tmp = (CORBA::Object_ptr) _tao_elem;  // any owns the object
      ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_Policy, tmp, 1, ACE_TRY_ENV);
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

// ****************************************************************

void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA_PolicyList &_tao_elem
  ) // copying
{
  CORBA_PolicyList *_tao_any_val;
  ACE_NEW (_tao_any_val, CORBA_PolicyList (_tao_elem));
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_PolicyList, _tao_any_val, 1, ACE_TRY_ENV); // copy the value
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, CORBA_PolicyList *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_PolicyList, _tao_elem, 0, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_PolicyList *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_PolicyList, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA_PolicyList *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA_PolicyList, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (CORBA::_tc_PolicyList, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_PolicyList, _tao_elem, 1, ACE_TRY_ENV);
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

void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA_PolicyTypeSeq &_tao_elem
  ) // copying
{
  CORBA_PolicyTypeSeq *_tao_any_val;
  ACE_NEW (_tao_any_val, CORBA_PolicyTypeSeq (_tao_elem));
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_PolicyTypeSeq, _tao_any_val, 1, ACE_TRY_ENV); // copy the value
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, CORBA_PolicyTypeSeq *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_PolicyTypeSeq, _tao_elem, 0, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_PolicyTypeSeq *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_PolicyTypeSeq, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA_PolicyTypeSeq *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA_PolicyTypeSeq, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (CORBA::_tc_PolicyTypeSeq, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_PolicyTypeSeq, _tao_elem, 1, ACE_TRY_ENV);
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

void operator<<= (CORBA::Any &_tao_any, CORBA::SetOverrideType _tao_elem)
{
  CORBA::SetOverrideType *_any_val;
  ACE_NEW (_any_val, CORBA::SetOverrideType (_tao_elem));
  if (!_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA::_tc_SetOverrideType, _any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    // free allocated storage
    delete _any_val;
  }
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::SetOverrideType &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_SetOverrideType, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    TAO_InputCDR stream (_tao_any._tao_get_cdr ());
    if (stream.decode (CORBA::_tc_SetOverrideType, &_tao_elem, 0, ACE_TRY_ENV)
      == CORBA::TypeCode::TRAVERSE_CONTINUE)
      return 1;
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

// ****************************************************************

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA_Policy_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA_Policy_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      CORBA_Policy::_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

// ****************************************************************

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO_Unbounded_Sequence<CORBA::UShort>;
template class TAO_Unbounded_Sequence<CORBA::ULong>;
template class TAO_Unbounded_Object_Sequence<CORBA_Policy,CORBA_Policy_var>;
template class TAO_Object_Manager<CORBA_Policy,CORBA_Policy_var>;

//  template class TAO_Object_Field_T<CORBA_Policy,CORBA_Policy_var>;
//  template class TAO_Object_Field_T<CORBA_PolicyManager,CORBA_PolicyManager_var>;
//  template class TAO_Object_Field_T<CORBA_PolicyCurrent,CORBA_PolicyCurrent_var>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate TAO_Unbounded_Sequence<CORBA::UShort>
#pragma instantiate TAO_Unbounded_Sequence<CORBA::ULong>
#pragma instantiate TAO_Unbounded_Object_Sequence<CORBA_Policy,CORBA_Policy_var>
#pragma instantiate TAO_Object_Manager<CORBA_Policy,CORBA_Policy_var>

//#  pragma instantiate TAO_Object_Field_T<CORBA_Policy,CORBA_Policy_var>
//#  pragma instantiate TAO_Object_Field_T<CORBA_PolicyManager,CORBA_PolicyManager_var>
//#  pragma instantiate TAO_Object_Field_T<CORBA_PolicyCurrent,CORBA_PolicyCurrent_var>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
