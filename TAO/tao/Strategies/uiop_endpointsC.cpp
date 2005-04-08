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
// be\be_codegen.cpp:291


#include "uiop_endpointsC.h"
#include "tao/CDR.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Sequence_TypeCode.h"
#include "tao/String_TypeCode.h"
#include "tao/Struct_TypeCode.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_TAO_UIOP_Endpoint_Info[] =
  {
    { "rendezvous_point", &CORBA::_tc_string },
    { "priority", &CORBA::_tc_short }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_TAO_UIOP_Endpoint_Info (
    CORBA::tk_struct,
    "IDL:TAO_UIOP_Endpoint_Info:1.0",
    "TAO_UIOP_Endpoint_Info",
    _tao_fields_TAO_UIOP_Endpoint_Info,
    2);
  
::CORBA::TypeCode_ptr const _tc_TAO_UIOP_Endpoint_Info =
  &_tao_tc_TAO_UIOP_Endpoint_Info;

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_TAO_UIOPENDPOINTSEQUENCE_CS_)
#define _TAO_UIOPENDPOINTSEQUENCE_CS_

TAO_UIOPEndpointSequence::TAO_UIOPEndpointSequence (void)
{}

TAO_UIOPEndpointSequence::TAO_UIOPEndpointSequence (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        TAO_UIOP_Endpoint_Info
      >
    (max)
{}

TAO_UIOPEndpointSequence::TAO_UIOPEndpointSequence (
    CORBA::ULong max,
    CORBA::ULong length,
    TAO_UIOP_Endpoint_Info * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        TAO_UIOP_Endpoint_Info
      >
    (max, length, buffer, release)
{}

TAO_UIOPEndpointSequence::TAO_UIOPEndpointSequence (
    const TAO_UIOPEndpointSequence &seq
  )
  : TAO_Unbounded_Sequence<
        TAO_UIOP_Endpoint_Info
      >
    (seq)
{}

TAO_UIOPEndpointSequence::~TAO_UIOPEndpointSequence (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:925


#ifndef _TAO_TYPECODE_TAO_UIOPEndpointSequence_GUARD
#define _TAO_TYPECODE_TAO_UIOPEndpointSequence_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence<::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      TAO_UIOPEndpointSequence_0 (
        CORBA::tk_sequence,
        &_tc_TAO_UIOP_Endpoint_Info,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_TAO_UIOPEndpointSequence_0 =
      &TAO_UIOPEndpointSequence_0;
    
  }
}


#endif /* _TAO_TYPECODE_TAO_UIOPEndpointSequence_GUARD */
static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            CORBA::tk_alias,
                            TAO::Null_RefCount_Policy>
  _tao_tc_TAO_UIOPEndpointSequence (
    "IDL:TAO_UIOPEndpointSequence:1.0",
    "TAO_UIOPEndpointSequence",
    &TAO::TypeCode::tc_TAO_UIOPEndpointSequence_0);
  
::CORBA::TypeCode_ptr const _tc_TAO_UIOPEndpointSequence =
  &_tao_tc_TAO_UIOPEndpointSequence;

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_UIOP_Endpoint_Info &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.rendezvous_point.in ()) &&
    (strm << _tao_aggregate.priority);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO_UIOP_Endpoint_Info &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.rendezvous_point.out ()) &&
    (strm >> _tao_aggregate.priority);
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_TAO_UIOPEndpointSequence_CPP_
#define _TAO_CDR_OP_TAO_UIOPEndpointSequence_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_UIOPEndpointSequence &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO_UIOPEndpointSequence &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_TAO_UIOPEndpointSequence_CPP_ */
