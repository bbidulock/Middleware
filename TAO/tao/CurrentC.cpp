/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/CurrentC.h"
#include "tao/Stub.h"
#include "tao/Servant_Base.h"
#include "tao/Typecode.h"
#include "tao/Any.h"
#include "tao/POA_CORBA.h"
#include "tao/Environment.h"

#if !defined (__ACE_INLINE__)
#include "tao/CurrentC.i"
#endif /* !defined INLINE */


ACE_RCSID(tao, CurrentC, "$Id$")

CORBA_Current_ptr CORBA_Current::_duplicate (CORBA_Current_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();

  return obj;
} // end of _duplicate

CORBA_Current_ptr CORBA_Current::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_Current::_nil ();
  CORBA::Boolean check =
    !obj->_is_a ("IDL:omg.org/CORBA/Current:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_Current::_nil ());
  if (check)
    return CORBA_Current::_nil ();
  void *servant = 0;
  if (!obj->_is_collocated ()
         || !obj->_servant()
         || (servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/Current:1.0")) == 0
      )
    ACE_THROW_RETURN (CORBA::MARSHAL (), CORBA_Current::_nil ());
  CORBA_Current_ptr retval = CORBA_Current::_nil ();
  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_Current (
          ACE_reinterpret_cast (POA_CORBA::Current_ptr,
                                servant),
          0
        ),
      CORBA_Current::_nil ()
    );
  return retval;
}

CORBA_Current_ptr CORBA_Current::_nil (void)
{
  return (CORBA_Current_ptr)NULL;
} // end of _nil

void
CORBA_Current::_tao_any_destructor (void* x)
{
  CORBA_Current *tmp = ACE_static_cast (CORBA_Current*,x);
  CORBA::release (tmp);
}

CORBA::Boolean CORBA_Current::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Current:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV); // remote call
}

const char* CORBA_Current::_remote_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Current:1.0";
}

void operator<<= (CORBA::Any &_tao_any, CORBA::Current_ptr _tao_elem)
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          CORBA::_tc_Current,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::Current_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA::Current::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (CORBA::_tc_Current, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    TAO_InputCDR stream (
        _tao_any._tao_get_cdr (),
        _tao_any._tao_byte_order ()
      );
    CORBA::Object_var _tao_obj_var;
    if (stream >> _tao_obj_var.out ())
    {
      _tao_elem = CORBA::Current::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      ((CORBA::Any *)&_tao_any)->_tao_replace (
          CORBA::_tc_Current,
          1,
          _tao_elem,
          CORBA::Current::_tao_any_destructor
        );
      return 1;
    }
  }
  ACE_CATCHANY
  {
    _tao_elem = CORBA::Current::_nil ();
    return 0;
  }
  ACE_ENDTRY;
  _tao_elem = CORBA::Current::_nil ();
  return 0;
}
