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

#include "PolicyC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/Struct_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyErrorCode (
    "IDL:omg.org/CORBA/PolicyErrorCode:1.0",
    "PolicyErrorCode",
    &::_tao_tc_CORBA::_tc_short);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyErrorCode =
    &_tao_tc_CORBA_PolicyErrorCode;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *> const _tao_fields_CORBA_PolicyError[] =
  {
    { "reason", &CORBA::_tc_PolicyErrorCode }
    
  };

static TAO::TypeCode::Struct<char const *,
                             TAO::TypeCode::Struct_Field<char const *> const *,
                             CORBA::tk_except,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyError (
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
// be\be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *> const _tao_fields_CORBA_InvalidPolicies[] =
  {
    { "indices", &CORBA::_tc_UShortSeq }
    
  };

static TAO::TypeCode::Struct<char const *,
                             TAO::TypeCode::Struct_Field<char const *> const *,
                             CORBA::tk_except,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_InvalidPolicies (
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
// be\be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_objref,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_Policy (
    "IDL:omg.org/CORBA/Policy:1.0",
    "Policy");
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_Policy =
    &_tao_tc_CORBA_Policy;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyManager (
    "IDL:omg.org/CORBA/PolicyManager:1.0",
    "PolicyManager");
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyManager =
    &_tao_tc_CORBA_PolicyManager;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_PolicyCurrent (
    "IDL:omg.org/CORBA/PolicyCurrent:1.0",
    "PolicyCurrent");
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_PolicyCurrent =
    &_tao_tc_CORBA_PolicyCurrent;
}



// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<CORBA::PolicyError>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if (!(cdr >> id.out ()))
    {
      return false;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;
  
  return true;
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

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<CORBA::InvalidPolicies>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if (!(cdr >> id.out ()))
    {
      return false;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;
  
  return true;
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

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::Policy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
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

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyManager>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyManager>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyManager>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyManager_ptr _tao_elem
  )
{
  CORBA::PolicyManager_ptr _tao_objptr =
    CORBA::PolicyManager::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyManager_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::PolicyManager>::insert (
      _tao_any,
      CORBA::PolicyManager::_tao_any_destructor,
      CORBA::_tc_PolicyManager,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyManager_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::PolicyManager>::extract (
        _tao_any,
        CORBA::PolicyManager::_tao_any_destructor,
        CORBA::_tc_PolicyManager,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyCurrent>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyCurrent>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyCurrent>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyCurrent_ptr _tao_elem
  )
{
  CORBA::PolicyCurrent_ptr _tao_objptr =
    CORBA::PolicyCurrent::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyCurrent_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::PolicyCurrent>::insert (
      _tao_any,
      CORBA::PolicyCurrent::_tao_any_destructor,
      CORBA::_tc_PolicyCurrent,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyCurrent_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::PolicyCurrent>::extract (
        _tao_any,
        CORBA::PolicyCurrent::_tao_any_destructor,
        CORBA::_tc_PolicyCurrent,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        CORBA::Policy
      >;

  template class
    TAO::Any_Impl_T<
        CORBA::PolicyCurrent
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::PolicyError
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::InvalidPolicies
      >;

  template class
    TAO::Any_Impl_T<
        CORBA::PolicyManager
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::Policy \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::PolicyCurrent \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::PolicyError \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::InvalidPolicies \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::PolicyManager \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
