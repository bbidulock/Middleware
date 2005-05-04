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

#include "IIOP_EndpointsC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode_Static.h"
#include "tao/Sequence_TypeCode_Static.h"
#include "tao/String_TypeCode_Static.h"
#include "tao/Struct_TypeCode_Static.h"
#include "tao/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_TAO_IIOP_Endpoint_Info[] =
  {
    { "host", &CORBA::_tc_string },
    { "port", &CORBA::_tc_short },
    { "priority", &CORBA::_tc_short }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_TAO_IIOP_Endpoint_Info (
    CORBA::tk_struct,
    "IDL:TAO/IIOP_Endpoint_Info:1.0",
    "IIOP_Endpoint_Info",
    _tao_fields_TAO_IIOP_Endpoint_Info,
    3);
  
namespace TAO
{
  ::CORBA::TypeCode_ptr const _tc_IIOP_Endpoint_Info =
    &_tao_tc_TAO_IIOP_Endpoint_Info;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:925


#ifndef _TAO_TYPECODE_TAO_IIOPEndpointSequence_GUARD
#define _TAO_TYPECODE_TAO_IIOPEndpointSequence_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      TAO_IIOPEndpointSequence_0 (
        CORBA::tk_sequence,
        &TAO::_tc_IIOP_Endpoint_Info,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_TAO_IIOPEndpointSequence_0 =
      &TAO_IIOPEndpointSequence_0;
    
  }
}


#endif /* _TAO_TYPECODE_TAO_IIOPEndpointSequence_GUARD */
static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_TAO_IIOPEndpointSequence (
    CORBA::tk_alias,
    "IDL:TAO/IIOPEndpointSequence:1.0",
    "IIOPEndpointSequence",
    &TAO::TypeCode::tc_TAO_IIOPEndpointSequence_0);
  
namespace TAO
{
  ::CORBA::TypeCode_ptr const _tc_IIOPEndpointSequence =
    &_tao_tc_TAO_IIOPEndpointSequence;
}



// TAO_IDL - Generated from 
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO::IIOP_Endpoint_Info &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::IIOP_Endpoint_Info>::insert_copy (
      _tao_any,
      TAO::IIOP_Endpoint_Info::_tao_any_destructor,
      TAO::_tc_IIOP_Endpoint_Info,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO::IIOP_Endpoint_Info *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::IIOP_Endpoint_Info>::insert (
      _tao_any,
      TAO::IIOP_Endpoint_Info::_tao_any_destructor,
      TAO::_tc_IIOP_Endpoint_Info,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO::IIOP_Endpoint_Info *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TAO::IIOP_Endpoint_Info *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO::IIOP_Endpoint_Info *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO::IIOP_Endpoint_Info>::extract (
        _tao_any,
        TAO::IIOP_Endpoint_Info::_tao_any_destructor,
        TAO::_tc_IIOP_Endpoint_Info,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO::IIOPEndpointSequence &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::IIOPEndpointSequence>::insert_copy (
      _tao_any,
      TAO::IIOPEndpointSequence::_tao_any_destructor,
      TAO::TypeCode::tc_TAO_IIOPEndpointSequence_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO::IIOPEndpointSequence *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::IIOPEndpointSequence>::insert (
      _tao_any,
      TAO::IIOPEndpointSequence::_tao_any_destructor,
      TAO::TypeCode::tc_TAO_IIOPEndpointSequence_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO::IIOPEndpointSequence *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const TAO::IIOPEndpointSequence *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO::IIOPEndpointSequence *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO::IIOPEndpointSequence>::extract (
        _tao_any,
        TAO::IIOPEndpointSequence::_tao_any_destructor,
        TAO::TypeCode::tc_TAO_IIOPEndpointSequence_0,
        _tao_elem
      );
}
