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


#include "tao/Messaging_PolicyValueC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
Messaging::PolicyValue::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  PolicyValue *_tao_tmp_pointer =
    static_cast<PolicyValue *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_MESSAGING_POLICYVALUESEQ_CS_)
#define _MESSAGING_POLICYVALUESEQ_CS_

Messaging::PolicyValueSeq::PolicyValueSeq (void)
{}

Messaging::PolicyValueSeq::PolicyValueSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        Messaging::PolicyValue
      >
    (max)
{}

Messaging::PolicyValueSeq::PolicyValueSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    Messaging::PolicyValue * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        Messaging::PolicyValue
      >
    (max, length, buffer, release)
{}

Messaging::PolicyValueSeq::PolicyValueSeq (
    const PolicyValueSeq &seq
  )
  : TAO_Unbounded_Sequence<
        Messaging::PolicyValue
      >
    (seq)
{}

Messaging::PolicyValueSeq::~PolicyValueSeq (void)
{}

void Messaging::PolicyValueSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  PolicyValueSeq * _tao_tmp_pointer =
    static_cast<PolicyValueSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::PolicyValue &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.ptype) &&
    (strm << _tao_aggregate.pvalue);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::PolicyValue &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.ptype) &&
    (strm >> _tao_aggregate.pvalue);
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_Messaging_PolicyValueSeq_CPP_
#define _TAO_CDR_OP_Messaging_PolicyValueSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::PolicyValueSeq &_tao_sequence
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
    Messaging::PolicyValueSeq &_tao_sequence
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

#endif /* _TAO_CDR_OP_Messaging_PolicyValueSeq_CPP_ */

TAO_END_VERSIONED_NAMESPACE_DECL
