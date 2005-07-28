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

#include "Default_ORTC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Value_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Value_Field.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/value_typecode.cpp:50

static TAO::TypeCode::Value_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_TAO_Default_ORT_ObjectReferenceTemplate = 0;

static TAO::TypeCode::Value<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::TypeCode::Value_Field<char const *,
                                                       CORBA::TypeCode_ptr const *> const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_TAO_Default_ORT_ObjectReferenceTemplate (
    CORBA::tk_value,
    "IDL:TAO_Default_ORT/ObjectReferenceTemplate:1.0",
    "ObjectReferenceTemplate",
    CORBA::VM_NONE,
    &CORBA::_tc_null,
    _tao_fields_TAO_Default_ORT_ObjectReferenceTemplate,
    0);

namespace TAO_Default_ORT
{
  ::CORBA::TypeCode_ptr const _tc_ObjectReferenceTemplate =
    &_tao_tc_TAO_Default_ORT_ObjectReferenceTemplate;
}



// TAO_IDL - Generated from
// be/be_visitor_valuetype/any_op_cs.cpp:57

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<TAO_Default_ORT::ObjectReferenceTemplate>::to_value (
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
    TAO_Default_ORT::ObjectReferenceTemplate *_tao_elem
  )
{
  CORBA::add_ref (_tao_elem);
  _tao_any <<= &_tao_elem;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO_Default_ORT::ObjectReferenceTemplate **_tao_elem
  )
{
  TAO::Any_Impl_T<TAO_Default_ORT::ObjectReferenceTemplate>::insert (
      _tao_any,
      TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor,
      TAO_Default_ORT::_tc_ObjectReferenceTemplate,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    TAO_Default_ORT::ObjectReferenceTemplate *&_tao_elem
  )
{
  return
    TAO::Any_Impl_T<TAO_Default_ORT::ObjectReferenceTemplate>::extract (
        _tao_any,
        TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor,
        TAO_Default_ORT::_tc_ObjectReferenceTemplate,
        _tao_elem
      );
}


