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

#include "tao/AnyTypeCode/PolicyA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"

#include "tao/AnyTypeCode/UShortSeqA.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyErrorCode (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/PolicyErrorCode:1.0",
    "PolicyErrorCode",
    &CORBA::_tc_short);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyErrorCode =
    &_tao_tc_CORBA_PolicyErrorCode;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_CORBA_PolicyError[] =
  {
    { "reason", &CORBA::_tc_PolicyErrorCode }

  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyError (
    CORBA::tk_except,
    "IDL:omg.org/CORBA/PolicyError:1.0",
    "PolicyError",
    _tao_fields_CORBA_PolicyError,
    1);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyError =
    &_tao_tc_CORBA_PolicyError;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_CORBA_InvalidPolicies[] =
  {
    { "indices", &CORBA::_tc_UShortSeq }

  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_InvalidPolicies (
    CORBA::tk_except,
    "IDL:omg.org/CORBA/InvalidPolicies:1.0",
    "InvalidPolicies",
    _tao_fields_CORBA_InvalidPolicies,
    1);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_InvalidPolicies =
    &_tao_tc_CORBA_InvalidPolicies;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_Policy (
    CORBA::tk_objref,
    "IDL:omg.org/CORBA/Policy:1.0",
    "Policy");

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_Policy =
    &_tao_tc_CORBA_Policy;
}



// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Dual_Impl_T<CORBA::PolicyError>::demarshal_value (
      TAO_InputCDR & cdr
    )
  {
    CORBA::String_var id;

    if (!(cdr >> id.out ()))
      {
        return false;
      }

    try
      {
        this->value_->_tao_decode (cdr);
      }
    catch (const ::CORBA::Exception&)
      {
        return false;
      }

    return true;
  }
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::PolicyError &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::PolicyError>::insert_copy (
      _tao_any,
      CORBA::PolicyError::_tao_any_destructor,
      CORBA::_tc_PolicyError,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyError *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::PolicyError>::insert (
      _tao_any,
      CORBA::PolicyError::_tao_any_destructor,
      CORBA::_tc_PolicyError,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyError *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::PolicyError *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::PolicyError *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::PolicyError>::extract (
        _tao_any,
        CORBA::PolicyError::_tao_any_destructor,
        CORBA::_tc_PolicyError,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Dual_Impl_T<CORBA::InvalidPolicies>::demarshal_value (
      TAO_InputCDR & cdr
    )
  {
    CORBA::String_var id;

    if (!(cdr >> id.out ()))
      {
        return false;
      }

    try
      {
        this->value_->_tao_decode (cdr);
      }
    catch (const ::CORBA::Exception&)
      {
        return false;
      }

    return true;
  }
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::InvalidPolicies &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::InvalidPolicies>::insert_copy (
      _tao_any,
      CORBA::InvalidPolicies::_tao_any_destructor,
      CORBA::_tc_InvalidPolicies,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::InvalidPolicies *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::InvalidPolicies>::insert (
      _tao_any,
      CORBA::InvalidPolicies::_tao_any_destructor,
      CORBA::_tc_InvalidPolicies,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::InvalidPolicies *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::InvalidPolicies *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::InvalidPolicies *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::InvalidPolicies>::extract (
        _tao_any,
        CORBA::InvalidPolicies::_tao_any_destructor,
        CORBA::_tc_InvalidPolicies,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<CORBA::Policy>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Policy_ptr _tao_elem
  )
{
  CORBA::Policy_ptr _tao_objptr =
    CORBA::Policy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Policy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::Policy>::insert (
      _tao_any,
      CORBA::Policy::_tao_any_destructor,
      CORBA::_tc_Policy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::Policy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::Policy>::extract (
        _tao_any,
        CORBA::Policy::_tao_any_destructor,
        CORBA::_tc_Policy,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

TAO_END_VERSIONED_NAMESPACE_DECL
