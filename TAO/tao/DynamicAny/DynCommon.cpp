/* -*- C++ -*- */
// $Id$

#include "DynCommon.h"
#include "DynAnyFactory.h"
#include "DynAny_i.h"
#include "DynArray_i.h"
#include "DynEnum_i.h"
#include "DynSequence_i.h"
#include "DynStruct_i.h"
#include "DynUnion_i.h"

ACE_RCSID(DynamicAny, DynCommon, "$Id$")

// Constructor.
TAO_DynCommon::TAO_DynCommon (void)
{
}

// Destructor.
TAO_DynCommon::~TAO_DynCommon (void)
{
}

// *****************************************************************

CORBA::TypeCode_ptr
TAO_DynCommon::type (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        CORBA::TypeCode::_nil ());
    }

  return CORBA::TypeCode::_duplicate (this->type_.in ());
}

void
TAO_DynCommon::assign (DynamicAny::DynAny_ptr dyn_any
                       TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  CORBA_TypeCode_var tc = dyn_any->type (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::Boolean equivalent = this->type_.in ()->equivalent (tc.in ()
                                                             TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (equivalent)
    {
      CORBA_Any_var any = dyn_any->to_any (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      this->from_any (*any
                      TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      ACE_THROW (DynamicAny::DynAny::TypeMismatch ());
    }
}

void
TAO_DynCommon::insert_boolean (CORBA::Boolean value
                               TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_boolean (value
                          TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_boolean
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= CORBA::Any::from_boolean (value);
    }
}

void
TAO_DynCommon::insert_octet (CORBA::Octet value
                             TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_octet (value
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_octet
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= CORBA::Any::from_octet (value);
    }
}

void
TAO_DynCommon::insert_char (CORBA::Char value
                            TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_char (value
                       TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_char
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= CORBA::Any::from_char (value);
    }
}

void
TAO_DynCommon::insert_short (CORBA::Short value
                             TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_short (value
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_short
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_ushort (CORBA::UShort value
                              TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_ushort (value
                         TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_ushort
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_long (CORBA::Long value
                            TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_long (value
                       TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_long
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_ulong (CORBA::ULong value
                             TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_ulong (value
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_ulong
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_float (CORBA::Float value
                             TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_float (value
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_float
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_double (CORBA::Double value
                              TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_double (value
                         TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_double
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_string (const char * value
                              TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_string (value
                         TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      CORBA::TypeCode_var unaliased_tc =
        TAO_DynAnyFactory::strip_alias (this->type_.in ()
                                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      CORBA::TCKind kind = unaliased_tc->kind (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      if (kind != CORBA::tk_string)
        {
          ACE_THROW (DynamicAny::DynAny::TypeMismatch ());
        }

      CORBA::ULong bound = unaliased_tc->length (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      if (bound > 0 && bound < ACE_OS::strlen (value))
        {
          ACE_THROW (DynamicAny::DynAny::InvalidValue ());
        }

      this->any_ <<= CORBA::Any::from_string (ACE_const_cast (char *,
                                                              value),
                                              bound);
    }
}

void
TAO_DynCommon::insert_reference (CORBA::Object_ptr value
                                 TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_reference (value
                            TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      CORBA::Boolean good_type = 1;
      CORBA::TCKind kind = TAO_DynAnyFactory::unalias (this->type_.in ()
                                                       TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      if (kind != CORBA::tk_objref)
        {
          good_type = 0;
        }
      else if (!CORBA::is_nil (value))
        {
          const char *value_id = value->_interface_repository_id ();

          if (ACE_OS::strcmp (value_id, "IDL:omg.org/CORBA/Object:1.0") != 0)
            {
              const char *my_id = this->type_->id (TAO_ENV_SINGLE_ARG_PARAMETER);
              ACE_CHECK;

              if (ACE_OS::strcmp (value_id, my_id) != 0)
                {
                  good_type = value->_is_a (my_id
                                            TAO_ENV_ARG_PARAMETER);
                  ACE_CHECK;
                }
            }
        }

      if (good_type)
        {
          this->any_ <<= value;
        }
      else
        {
          ACE_THROW (DynamicAny::DynAny::TypeMismatch ());
        }
    }
}

void
TAO_DynCommon::insert_typecode (CORBA::TypeCode_ptr value
                                TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_typecode (value
                           TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_TypeCode
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_longlong (CORBA::LongLong value
                                TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_longlong (value
                           TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_longlong
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_ulonglong (CORBA::ULongLong value
                                 TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_ulonglong (value
                            TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_ulonglong
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_longdouble (CORBA::LongDouble value
                                  TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_longdouble (value
                             TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_longdouble
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

void
TAO_DynCommon::insert_wchar (CORBA::WChar value
                             TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_wchar (value
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_wchar
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= CORBA::Any::from_wchar (value);
    }
}

void
TAO_DynCommon::insert_wstring (const CORBA::WChar * value
                               TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_wstring (value
                          TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      CORBA::TypeCode_var unaliased_tc =
        this->check_type_and_unalias (CORBA::_tc_wstring
                                      TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      CORBA::ULong bound = unaliased_tc->length (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      if (bound > 0 && bound < ACE_OS::wslen (value))
        {
          ACE_THROW (DynamicAny::DynAny::InvalidValue ());
        }

      this->any_ <<= CORBA::Any::from_wstring (ACE_const_cast (CORBA::WChar *,
                                                               value),
                                               bound);
    }
}

void
TAO_DynCommon::insert_any (const CORBA::Any &value
                           TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK;

      cc->insert_any (value
                      TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      this->check_type (CORBA::_tc_any
                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK;

      this->any_ <<= value;
    }
}

// @@@ (JP) TODO - optimize - this version was intended by the OMG to
// have fewer Any/DynAny conversions than insert_any, not more.
void
TAO_DynCommon::insert_dyn_any (DynamicAny::DynAny_ptr value
                               TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  CORBA_Any_var any = value->to_any (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->insert_any (any.in ()
                    TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

#ifdef TAO_HAS_VALUETYPE
void
TAO_DynCommon::insert_val (CORBA::ValueBase_ptr
                           TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  ACE_THROW (CORBA::NO_IMPLEMENT ());
}
#endif /* TAO_HAS_VALUETYPE */

// ****************************************************************

CORBA::Boolean
TAO_DynCommon::get_boolean (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_boolean (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::Boolean retval;

      if ((this->any_ >>= CORBA::Any::to_boolean (retval)) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::Octet
TAO_DynCommon::get_octet (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_octet (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::Octet retval;

      if ((this->any_ >>= CORBA::Any::to_octet (retval)) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::Char
TAO_DynCommon::get_char (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_char (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::Char retval;

      if ((this->any_ >>= CORBA::Any::to_char (retval)) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::Short
TAO_DynCommon::get_short (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_short (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::Short retval;

      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::UShort
TAO_DynCommon::get_ushort (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_ushort (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::UShort retval;

      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::Long
TAO_DynCommon::get_long (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_long (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::Long retval;

      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::ULong
TAO_DynCommon::get_ulong (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_ulong (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::ULong retval;

      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::Float
TAO_DynCommon::get_float (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_float (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::Float retval;

      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::Double
TAO_DynCommon::get_double (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_double (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::Double retval;

      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

char *
TAO_DynCommon::get_string (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_string (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::TypeCode_var unaliased_tc =
        TAO_DynAnyFactory::strip_alias (this->type_.in ()
                                        TAO_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      CORBA::TCKind kind = unaliased_tc->kind (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (kind != CORBA::tk_string)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      char *retval = 0;

      CORBA::ULong bound = unaliased_tc->length (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      // We will have caught a type mismatch above, so if this fails,
      // it must be for some other reason.
      if ((this->any_ >>= CORBA::Any::to_string (retval, bound)) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::InvalidValue (),
                            0);
        }

      return CORBA::string_dup (retval);
    }
}

CORBA::Object_ptr
TAO_DynCommon::get_reference (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        CORBA::Object::_nil ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_reference (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::Object_ptr retval;

      if ((this->any_ >>= CORBA::Any::to_object (retval)) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            CORBA::Object::_nil ());
        }

      return CORBA::Object::_duplicate (retval);
    }
}

CORBA::TypeCode_ptr
TAO_DynCommon::get_typecode (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        CORBA::TypeCode::_nil ());
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_typecode (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::TypeCode_ptr retval;

      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            CORBA::TypeCode::_nil ());
        }

      return CORBA::TypeCode::_duplicate (retval);
    }
}

CORBA::LongLong
TAO_DynCommon::get_longlong (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  CORBA::LongLong retval = ACE_CDR_LONGLONG_INITIALIZER;

  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        retval);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (retval);

      return cc->get_longlong (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            retval);
        }

      return retval;
    }
}

CORBA::ULongLong
TAO_DynCommon::get_ulonglong (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  CORBA::ULongLong retval;

  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        retval);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (retval);

      return cc->get_ulonglong (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            retval);
        }

      return retval;
    }
}

CORBA::LongDouble
TAO_DynCommon::get_longdouble (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  CORBA::LongDouble retval = ACE_CDR_LONG_DOUBLE_INITIALIZER;

  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        retval);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (retval);

      return cc->get_longdouble (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      if ((this->any_ >>= retval) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            retval);
        }

      return retval;
    }
}

CORBA::WChar
TAO_DynCommon::get_wchar (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_wchar (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA::WChar retval;

      if ((this->any_ >>= CORBA::Any::to_wchar (retval)) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return retval;
    }
}

CORBA::WChar *
TAO_DynCommon::get_wstring (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_wstring (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      // @@@ (JP) Someday try to find a way to avoid checking for
      // type code equivalence twice without risking a throw of
      // BadKind.
      CORBA::TypeCode_var unaliased_tc =
        this->check_type_and_unalias (CORBA::_tc_wstring
                                      TAO_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      CORBA::WChar *retval = 0;

      CORBA::ULong bound = unaliased_tc->length (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      (void) (this->any_ >>= CORBA::Any::to_wstring (retval,
                                                     bound));

      return CORBA::wstring_dup (retval);
    }
}

CORBA::Any_ptr
TAO_DynCommon::get_any (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_)
    {
      DynamicAny::DynAny_var cc = this->check_component (TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      return cc->get_any (TAO_ENV_SINGLE_ARG_PARAMETER);
    }
  else
    {
      CORBA_Any_ptr tmp = 0;

      ACE_NEW_THROW_EX (tmp,
                        CORBA_Any,
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (0);

      CORBA_Any_var val = tmp;

      if ((this->any_ >>= *tmp) == 0)
        {
          ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                            0);
        }

      return val._retn ();
    }
}

// @@@ (JP) TODO - optimize - this version was intended by the OMG to
// have fewer Any/DynAny conversions than get_any, not more.
DynamicAny::DynAny_ptr
TAO_DynCommon::get_dyn_any (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  CORBA_Any_var any = this->get_any (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return TAO_DynAnyFactory::make_dyn_any (any.in ()
                                          TAO_ENV_ARG_PARAMETER);
}

#ifdef TAO_HAS_VALUETYPE
CORBA::ValueBase_ptr
TAO_DynCommon::get_val (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (),
                    0);
}
#endif /* TAO_HAS_VALUETYPE */

// ****************************************************************

CORBA::Boolean
TAO_DynCommon::seek (CORBA::Long slot
                     TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_ == 0)
    {
      ACE_UNUSED_ARG (slot);
      this->current_position_ = -1;
      return 0;
    }
  else if (slot < 0 || slot >= ACE_static_cast (CORBA::Long,
                                                this->component_count_))
    {
      this->current_position_ = -1;
      return 0;
    }
  else
    {
      this->current_position_ = slot;
      return 1;
    }
}

void
TAO_DynCommon::rewind (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW (CORBA::OBJECT_NOT_EXIST ());
    }

  (void) this->seek (0
                     TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

CORBA::Boolean
TAO_DynCommon::next (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  if (this->has_components_ == 0
      || this->current_position_ + 1 >= ACE_static_cast (
                                            CORBA::Long,
                                            this->component_count_
                                          ))
    {
      this->current_position_ = -1;
      return 0;
    }
  else
    {
      ++this->current_position_;
      return 1;
    }
}

DynamicAny::DynAny_ptr
TAO_DynCommon::copy (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        DynamicAny::DynAny::_nil ());
    }

  CORBA_Any_var any = this->to_any (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());

  DynamicAny::DynAny_ptr retval =
    TAO_DynAnyFactory::make_dyn_any (any.in ()
                                     TAO_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());

  return retval;
}

CORBA::ULong
TAO_DynCommon::component_count (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  if (this->destroyed_)
    {
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

  return this->component_count_;
}

void
TAO_DynCommon::set_flag (DynamicAny::DynAny_ptr component,
                         CORBA::Boolean destroying
                         TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ))
{
  CORBA::TypeCode_var tc = component->type (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::TCKind tk = TAO_DynAnyFactory::unalias (tc.in ()
                                                 TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  switch (tk)
  {
    case CORBA::tk_array:
      {
        TAO_DynArray_i *tmp = TAO_DynArray_i::_narrow (component
                                                       TAO_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (destroying)
          {
            tmp->container_is_destroying_ = 1;
          }
        else
          {
            tmp->ref_to_component_ = 1;
          }

        tmp->_remove_ref ();
        break;
      }
    case CORBA::tk_enum:
      {
        TAO_DynEnum_i *tmp = TAO_DynEnum_i::_narrow (component
                                                     TAO_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (destroying)
          {
            tmp->container_is_destroying_ = 1;
          }
        else
          {
            tmp->ref_to_component_ = 1;
          }

        tmp->_remove_ref ();
        break;
      }
    case CORBA::tk_sequence:
      {
        TAO_DynSequence_i *tmp = TAO_DynSequence_i::_narrow (component
                                                             TAO_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (destroying)
          {
            tmp->container_is_destroying_ = 1;
          }
        else
          {
            tmp->ref_to_component_ = 1;
          }

        tmp->_remove_ref ();
        break;
      }
    case CORBA::tk_struct:
      {
        TAO_DynStruct_i *tmp = TAO_DynStruct_i::_narrow (component
                                                         TAO_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (destroying)
          {
            tmp->container_is_destroying_ = 1;
          }
        else
          {
            tmp->ref_to_component_ = 1;
          }

        tmp->_remove_ref ();
        break;
      }
    case CORBA::tk_union:
      {
        TAO_DynUnion_i *tmp = TAO_DynUnion_i::_narrow (component
                                                       TAO_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (destroying)
          {
            tmp->container_is_destroying_ = 1;
          }
        else
          {
            tmp->ref_to_component_ = 1;
          }

        tmp->_remove_ref ();
        break;
      }
    case CORBA::tk_fixed:
    case CORBA::tk_value:
    case CORBA::tk_value_box:
      ACE_THROW (CORBA::NO_IMPLEMENT ());
    default:
      {
        TAO_DynAny_i *tmp = TAO_DynAny_i::_narrow (component
                                                   TAO_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (destroying)
          {
            tmp->container_is_destroying_ = 1;
          }
        else
          {
            tmp->ref_to_component_ = 1;
          }

        tmp->_remove_ref ();
        break;
      }
  }
}

DynamicAny::DynAny_ptr
TAO_DynCommon::check_component (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch,
      DynamicAny::DynAny::InvalidValue
    ))
{
  if (this->current_position_ == -1)
    {
      ACE_THROW_RETURN (DynamicAny::DynAny::InvalidValue (),
                        DynamicAny::DynAny::_nil ());
    }

  DynamicAny::DynAny_var cc = this->current_component (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());

  CORBA::TypeCode_var tc = cc->type (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());

  CORBA::TCKind kind = TAO_DynAnyFactory::unalias (tc.in ()
                                                   TAO_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (DynamicAny::DynAny::_nil ());

  // We are here because we are a component that is the target of
  // an insert_*() call on our container. It is
  // illegal to insert anything into a component that itself has
  // components.
  switch (kind)
  {
    case CORBA::tk_array:
    case CORBA::tk_except:
    case CORBA::tk_sequence:
    case CORBA::tk_struct:
    case CORBA::tk_union:
      ACE_THROW_RETURN (DynamicAny::DynAny::TypeMismatch (),
                        DynamicAny::DynAny::_nil ());
    default:
      return cc._retn ();
  }
}

void
TAO_DynCommon::check_type (CORBA::TypeCode_ptr tc
                           TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch
    ))
{
  CORBA::Boolean equivalent = this->type_->equivalent (tc
                                                       TAO_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (!equivalent)
    {
      ACE_THROW (DynamicAny::DynAny::TypeMismatch ());
    }
}

CORBA::TypeCode_ptr
TAO_DynCommon::check_type_and_unalias (CORBA::TypeCode_ptr tc
                                       TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((
      CORBA::SystemException,
      DynamicAny::DynAny::TypeMismatch
    ))
{
  this->check_type (tc
                    TAO_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (CORBA::TypeCode::_nil ());

  return TAO_DynAnyFactory::strip_alias (tc
                                         TAO_ENV_ARG_PARAMETER);
}

