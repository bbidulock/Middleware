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


#include "StringSeqC.h"
#include "tao/CDR.h"
#include "tao/unbounded_value_sequence_cdr.hpp"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_STRINGSEQ_CS_)
#define _CORBA_STRINGSEQ_CS_

CORBA::StringSeq::StringSeq (void)
{}

CORBA::StringSeq::StringSeq (
    CORBA::ULong max
  )
  : TAO::unbounded_string_sequence
    (max)
{}

CORBA::StringSeq::StringSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    char * * buffer,
    CORBA::Boolean release
  )
  : TAO::unbounded_string_sequence
    (max, length, buffer, release)
{}

CORBA::StringSeq::StringSeq (
    const StringSeq &seq
  )
  : TAO::unbounded_string_sequence
    (seq)
{}

CORBA::StringSeq::~StringSeq (void)
{}

void CORBA::StringSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  StringSeq * _tao_tmp_pointer =
    static_cast<StringSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_StringSeq_CPP_
#define _TAO_CDR_OP_CORBA_StringSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::StringSeq &_tao_sequence
  )
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::StringSeq &_tao_sequence
  )
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}

#endif /* _TAO_CDR_OP_CORBA_StringSeq_CPP_ */
