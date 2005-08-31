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


#include "CharSeqC.h"
#include "tao/CDR.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_CHARSEQ_CS_)
#define _CORBA_CHARSEQ_CS_

CORBA::CharSeq::CharSeq (void)
{}

CORBA::CharSeq::CharSeq (
    ::CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::Char
      >
    (max)
{}

CORBA::CharSeq::CharSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::Char * buffer,
    ::CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::Char
      >
    (max, length, buffer, release)
{}

CORBA::CharSeq::CharSeq (
    const CharSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::Char
      >
    (seq)
{}

CORBA::CharSeq::~CharSeq (void)
{}

void CORBA::CharSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  CharSeq * _tao_tmp_pointer =
    static_cast<CharSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_CharSeq_CPP_
#define _TAO_CDR_OP_CORBA_CharSeq_CPP_

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::CharSeq &_tao_sequence
  )
{
  const ::CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      return strm.write_char_array ((const char *)_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return false;
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::CharSeq &_tao_sequence
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
      return strm.read_char_array ((char *)_tao_sequence.get_buffer (), _tao_sequence.length ());
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_CORBA_CharSeq_CPP_ */
