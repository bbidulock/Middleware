// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:291


#include "StringValueC.h"
#include "tao/CDR.h"
#include "tao/Valuetype/ValueFactory.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Value_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Value_Field.h"
#include "tao/AnyTypeCode/Recursive_Type_TypeCode.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "StringValueC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_StringValue (
    CORBA::tk_value_box,
    "IDL:omg.org/CORBA/StringValue:1.0",
    "StringValue",
    &CORBA::_tc_string);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_StringValue =
    &_tao_tc_CORBA_StringValue;
}



// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_cs.cpp:63
CORBA::StringValue *
CORBA::StringValue::_downcast (CORBA::ValueBase *v)
{
  if (v == 0)
    {
      return 0;
    }

  return dynamic_cast< ::CORBA::StringValue * > (v);
}


CORBA::ValueBase *
CORBA::StringValue::_copy_value (void)
{
  CORBA::ValueBase *result = 0;
  ACE_NEW_RETURN (
    result,
    StringValue (*this),
    0);

  return result;
}

const char *
CORBA::StringValue::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

CORBA::Boolean
CORBA::StringValue::_tao_unmarshal (
    TAO_InputCDR &strm,
    StringValue *&vb_object
  )
{
  CORBA::Boolean is_null_object;
  if (CORBA::ValueBase::_tao_validate_box_type (
        strm,
        StringValue::_tao_obv_static_repository_id (),
        is_null_object
      ) == 0)
    {
      return 0;
    }

  vb_object = 0;
  if (is_null_object)
    {
      return 1;
    }

  ACE_NEW_RETURN (
    vb_object,
    StringValue,
    0);

  return (strm >> vb_object->_pd_value);
}



// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_WStringValue (
    CORBA::tk_value_box,
    "IDL:omg.org/CORBA/WStringValue:1.0",
    "WStringValue",
    &CORBA::_tc_wstring);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_WStringValue =
    &_tao_tc_CORBA_WStringValue;
}



// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/valuebox_cs.cpp:63
CORBA::WStringValue *
CORBA::WStringValue::_downcast (CORBA::ValueBase *v)
{
  if (v == 0)
    {
      return 0;
    }

  return dynamic_cast< ::CORBA::WStringValue * > (v);
}


CORBA::ValueBase *
CORBA::WStringValue::_copy_value (void)
{
  CORBA::ValueBase *result = 0;
  ACE_NEW_RETURN (
    result,
    WStringValue (*this),
    0);

  return result;
}

const char *
CORBA::WStringValue::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

CORBA::Boolean
CORBA::WStringValue::_tao_unmarshal (
    TAO_InputCDR &strm,
    WStringValue *&vb_object
  )
{
  CORBA::Boolean is_null_object;
  if (CORBA::ValueBase::_tao_validate_box_type (
        strm,
        WStringValue::_tao_obv_static_repository_id (),
        is_null_object
      ) == 0)
    {
      return 0;
    }

  vb_object = 0;
  if (is_null_object)
    {
      return 1;
    }

  ACE_NEW_RETURN (
    vb_object,
    WStringValue,
    0);

  return (strm >> vb_object->_pd_value);
}



// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/any_op_cs.cpp:56

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<CORBA::StringValue>::to_value (
      CORBA::ValueBase *&_tao_elem
    ) const
  {
    CORBA::add_ref (this->value_);
    _tao_elem = this->value_;
    return 1;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::StringValue *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::StringValue **_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::StringValue>::insert (
      _tao_any,
      CORBA::StringValue::_tao_any_destructor,
      CORBA::_tc_StringValue,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::StringValue *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::StringValue>::extract (
        _tao_any,
        CORBA::StringValue::_tao_any_destructor,
        CORBA::_tc_StringValue,
        _tao_elem
      );
}



// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/any_op_cs.cpp:56

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<CORBA::WStringValue>::to_value (
      CORBA::ValueBase *&_tao_elem
    ) const
  {
    CORBA::add_ref (this->value_);
    _tao_elem = this->value_;
    return 1;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::WStringValue *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::WStringValue **_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::WStringValue>::insert (
      _tao_any,
      CORBA::WStringValue::_tao_any_destructor,
      CORBA::_tc_WStringValue,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::WStringValue *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::WStringValue>::extract (
        _tao_any,
        CORBA::WStringValue::_tao_any_destructor,
        CORBA::_tc_WStringValue,
        _tao_elem
      );
}



// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/cdr_op_cs.cpp:52

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA::StringValue *_tao_valuebox
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        _tao_valuebox,
        reinterpret_cast<ptrdiff_t> (&CORBA::StringValue::_downcast)
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA::StringValue *&_tao_valuebox
  )
{
  return CORBA::StringValue::_tao_unmarshal (strm, _tao_valuebox);
}



// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_valuebox/cdr_op_cs.cpp:52

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA::WStringValue *_tao_valuebox
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        _tao_valuebox,
        reinterpret_cast<ptrdiff_t> (&CORBA::WStringValue::_downcast)
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA::WStringValue *&_tao_valuebox
  )
{
  return CORBA::WStringValue::_tao_unmarshal (strm, _tao_valuebox);
}



// TAO_IDL - Generated from
// c:\projects\ace_cvs\ace_wrappers\tao\tao_idl\be\be_visitor_root/root.cpp:1745

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Value_Traits<
        CORBA::StringValue
      >;

  template class
    TAO_Value_Var_T<
        CORBA::StringValue

      >;

  template class
    TAO_Value_Out_T<
        CORBA::StringValue

      >;

  template class
    TAO::Any_Impl_T<
        CORBA::StringValue
      >;

  template class
    TAO::Value_Traits<
        CORBA::WStringValue
      >;

  template class
    TAO_Value_Var_T<
        CORBA::WStringValue

      >;

  template class
    TAO_Value_Out_T<
        CORBA::WStringValue

      >;

  template class
    TAO::Any_Impl_T<
        CORBA::WStringValue
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Value_Traits< \
        CORBA::StringValue \
      >

# pragma instantiate \
    TAO_Value_Var_T< \
        CORBA::StringValue \

      >

# pragma instantiate \
    TAO_Value_Out_T< \
        CORBA::StringValue \

      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::StringValue \
      >

# pragma instantiate \
    TAO::Value_Traits< \
        CORBA::WStringValue \
      >

# pragma instantiate \
    TAO_Value_Var_T< \
        CORBA::WStringValue \

      >

# pragma instantiate \
    TAO_Value_Out_T< \
        CORBA::WStringValue \

      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::WStringValue \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
