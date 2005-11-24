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
// be\be_codegen.cpp:277


#include "WStringSeqC.h"
#include "tao/CDR.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_WSTRINGSEQ_CS_)
#define _CORBA_WSTRINGSEQ_CS_

CORBA::WStringSeq::WStringSeq (void)
{}

CORBA::WStringSeq::WStringSeq (
    ::CORBA::ULong max
  )
  : TAO_Unbounded_WString_Sequence
    (max)
{}

CORBA::WStringSeq::WStringSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::WChar * * buffer,
    ::CORBA::Boolean release
  )
  : TAO_Unbounded_WString_Sequence
    (max, length, buffer, release)
{}

CORBA::WStringSeq::WStringSeq (
    const WStringSeq &seq
  )
  : TAO_Unbounded_WString_Sequence
    (seq)
{}

CORBA::WStringSeq::~WStringSeq (void)
{}

void CORBA::WStringSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  WStringSeq * _tao_tmp_pointer =
    static_cast<WStringSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_WStringSeq_CPP_
#define _TAO_CDR_OP_CORBA_WStringSeq_CPP_

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::WStringSeq &_tao_sequence
  )
{
  const ::CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      ::CORBA::Boolean _tao_marshal_flag = true;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i].in ());
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::WStringSeq &_tao_sequence
  )
{
  ::CORBA::ULong _tao_seq_len;
  
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
      ::CORBA::Boolean _tao_marshal_flag = true;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
        
      }
    
    return _tao_marshal_flag;
  
  }

return false;
}

#endif /* _TAO_CDR_OP_CORBA_WStringSeq_CPP_ */

TAO_END_VERSIONED_NAMESPACE_DECL
