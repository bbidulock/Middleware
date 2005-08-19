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

#include "PIForwardRequestC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_PortableInterceptor_ForwardRequest[] =
  {
    { "forward", &CORBA::_tc_Object }

  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ForwardRequest (
    CORBA::tk_except,
    "IDL:omg.org/PortableInterceptor/ForwardRequest:1.0",
    "ForwardRequest",
    _tao_fields_PortableInterceptor_ForwardRequest,
    1);

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ForwardRequest =
    &_tao_tc_PortableInterceptor_ForwardRequest;
}



// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::demarshal_value (
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
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableInterceptor::ForwardRequest &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::insert_copy (
      _tao_any,
      PortableInterceptor::ForwardRequest::_tao_any_destructor,
      PortableInterceptor::_tc_ForwardRequest,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ForwardRequest *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::insert (
      _tao_any,
      PortableInterceptor::ForwardRequest::_tao_any_destructor,
      PortableInterceptor::_tc_ForwardRequest,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ForwardRequest *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableInterceptor::ForwardRequest *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableInterceptor::ForwardRequest *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::extract (
        _tao_any,
        PortableInterceptor::ForwardRequest::_tao_any_destructor,
        PortableInterceptor::_tc_ForwardRequest,
        _tao_elem
      );
}
