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

#include "tao/AnyTypeCode/Dynamic_ParameterA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/AnyTypeCode/Recursive_Type_TypeCode.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "tao/AnyTypeCode/ParameterModeA.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_Dynamic_Parameter[] =
  {
    { "argument", &CORBA::_tc_any },
    { "mode", &CORBA::_tc_ParameterMode }

  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_Dynamic_Parameter (
    CORBA::tk_struct,
    "IDL:Dynamic/Parameter:1.0",
    "Parameter",
    _tao_fields_Dynamic_Parameter,
    2);

namespace Dynamic
{
  ::CORBA::TypeCode_ptr const _tc_Parameter =
    &_tao_tc_Dynamic_Parameter;
}



// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Dynamic::Parameter &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Dynamic::Parameter>::insert_copy (
      _tao_any,
      Dynamic::Parameter::_tao_any_destructor,
      Dynamic::_tc_Parameter,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Dynamic::Parameter *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Dynamic::Parameter>::insert (
      _tao_any,
      Dynamic::Parameter::_tao_any_destructor,
      Dynamic::_tc_Parameter,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Dynamic::Parameter *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const Dynamic::Parameter *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Dynamic::Parameter *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Dynamic::Parameter>::extract (
        _tao_any,
        Dynamic::Parameter::_tao_any_destructor,
        Dynamic::_tc_Parameter,
        _tao_elem
      );
}

TAO_END_VERSIONED_NAMESPACE_DECL
