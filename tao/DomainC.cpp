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
#include "tao/POA_CORBA.h"
#include "tao/ORB.h"

#if (TAO_HAS_INTERFACE_REPOSITORY == 1)
#include "tao/InterfaceC.h"
#endif /* TAO_HAS_INTERFACE_REPOSITORY == 1 */

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

  CORBA_DomainManager_ptr retval = CORBA_DomainManager::_nil ();

  if (servant == 0)
    {
      ACE_NEW_RETURN (retval,
                      CORBA_DomainManager (stub),
                      CORBA_DomainManager::_nil ());
    }
  else
    {
      ACE_NEW_RETURN (
          retval,
          POA_CORBA::_tao_collocated_DomainManager (
              ACE_reinterpret_cast (POA_CORBA::DomainManager_ptr,
                                    servant),
              stub
            ),
          CORBA_DomainManager::_nil ()
        );
    }

  return retval;
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
{
    CORBA::Policy_ptr _tao_retval = CORBA::Policy::_nil ();

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "get_domain_policy",
      17,
      istub->orb_core ()
    );


  for (;;)
  {
    _tao_call.start (ACE_TRY_ENV);
    ACE_CHECK_RETURN (_tao_retval);

    CORBA::Short flag = TAO_TWOWAY_RESPONSE_FLAG;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
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

#if (TAO_HAS_MINIMUM_CORBA == 0)

CORBA_ConstructionPolicy_ptr CORBA_ConstructionPolicy::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_ConstructionPolicy::_nil ();
  if (! obj->_is_local ())
    {
      CORBA::Boolean is_a = obj->_is_a ("IDL:CORBA_ConstructionPolicy:1.0", ACE_TRY_ENV);
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
        ACE_NEW_RETURN (default_proxy, CORBA_ConstructionPolicy (stub), CORBA_ConstructionPolicy::_nil ());
      #if (TAO_HAS_SMART_PROXIES == 1)
        return TAO_CORBA_ConstructionPolicy_PROXY_FACTORY_ADAPTER::instance ()->create_proxy (default_proxy);
      #else 
        return default_proxy;
      #endif /*TAO_HAS_SMART_PROXIES == 1*/
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

CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_duplicate (CORBA::ConstructionPolicy_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void CORBA::ConstructionPolicy::make_domain_manager (
    IR_InterfaceDef *object_type,
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
      19,
      istub->orb_core ()
    );


  for (;;)
  {
    _tao_call.start (ACE_TRY_ENV);
    ACE_CHECK;

    CORBA::Short flag = TAO_TWOWAY_RESPONSE_FLAG;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
    ACE_CHECK;

#if (TAO_HAS_INTERFACE_REPOSITORY == 1)
    TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
  // @@ The insertion operation (<<) for InterfaceDef will be
  // defined, and thus this code will work.
    if (!(
          (_tao_out << object_type) &&
          (_tao_out << CORBA::Any::from_boolean (constr_policy))
      ))
      ACE_THROW (CORBA::MARSHAL ());
#else /* TAO_HAS_INTERFACE_REPOSITORY == 1 */
    ACE_UNUSED_ARG (object_type);
    ACE_UNUSED_ARG (constr_policy);
#endif /* TAO_HAS_INTERFACE_REPOSITORY == 1 */

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

void CORBA_DomainManager::_tao_any_destructor (void* x)
{
  CORBA_DomainManager_ptr tmp = ACE_static_cast (CORBA_DomainManager_ptr,x);
  CORBA::release (tmp);
}

void operator<<= (CORBA::Any &_tao_any, CORBA::DomainManager_ptr _tao_elem)
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_DomainManager,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::DomainManager_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA::DomainManager::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (CORBA::_tc_DomainManager, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA::DomainManager_ptr)_tao_any.value ();
      return 1;
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
          CORBA::DomainManager::_tao_any_destructor
        );
      return 1;
    }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>;
  template class TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Unbounded_Object_Sequence<CORBA_DomainManager,CORBA_DomainManager_var>
# pragma instantiate TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#if (TAO_HAS_MINIMUM_CORBA == 0)

CORBA_ConstructionPolicy_ptr (*_TAO_collocation_CORBA_ConstructionPolicy_Stub_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;
void
CORBA_ConstructionPolicy::_tao_any_destructor (void *x)
{
  CORBA_ConstructionPolicy_ptr tmp = ACE_static_cast(CORBA_ConstructionPolicy_ptr,x);
  CORBA::release (tmp);
}

void operator<<= (CORBA::Any &_tao_any, CORBA::ConstructionPolicy_ptr _tao_elem)
{
    TAO_OutputCDR stream;
    if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_ConstructionPolicy,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::ConstructionPolicy_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA::ConstructionPolicy::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (CORBA::_tc_ConstructionPolicy, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA::ConstructionPolicy_ptr)_tao_any.value ();
      return 1;
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
          CORBA::ConstructionPolicy::_tao_any_destructor
        );
      return 1;
    }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Manager<CORBA_ConstructionPolicy,CORBA_ConstructionPolicy_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO_Object_Manager<CORBA_ConstructionPolicy,CORBA_ConstructionPolicy_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* ! defined (TAO_HAS_MINIMUM_CORBA) */

void
CORBA_DomainManagerList::_tao_any_destructor (void *x)
{
  CORBA_DomainManagerList* tmp = ACE_static_cast (CORBA_DomainManagerList*,x);
  delete tmp;
}

void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::DomainManagerList &_tao_elem
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

void operator<<= (CORBA::Any &_tao_any, CORBA::DomainManagerList *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      CORBA::_tc_DomainManagerList,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      CORBA::DomainManagerList::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::DomainManagerList *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (CORBA::_tc_DomainManagerList, ACE_TRY_ENV)) // not equal
      {
        _tao_elem = 0;
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA::DomainManagerList *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA::DomainManagerList, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      if (stream >> *_tao_elem)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            CORBA::_tc_DomainManagerList,
            1,
            ACE_reinterpret_cast (void *, _tao_elem),
            CORBA::DomainManagerList::_tao_any_destructor
          );
        return 1;
      }
      else
      {
        delete _tao_elem;
        _tao_elem = 0;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    _tao_elem = 0;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const CORBA::DomainManagerList *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(CORBA::DomainManagerList*&,_tao_elem);
}
