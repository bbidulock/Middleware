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


#include "FloatSeqC.h"
#include "tao/CDR.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_FLOATSEQ_CS_)
#define _CORBA_FLOATSEQ_CS_

CORBA::FloatSeq::FloatSeq (void)
{}

CORBA::FloatSeq::FloatSeq (
    ::CORBA::ULong max
  )
  : TAO::unbounded_value_sequence<
        CORBA::Float
      >
    (max)
{}

CORBA::FloatSeq::FloatSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::Float * buffer,
    ::CORBA::Boolean release
  )
  : TAO::unbounded_value_sequence<
        CORBA::Float
      >
    (max, length, buffer, release)
{}

CORBA::FloatSeq::FloatSeq (
    const FloatSeq &seq
  )
  : TAO::unbounded_value_sequence<
        CORBA::Float
      >
    (seq)
{}

CORBA::FloatSeq::~FloatSeq (void)
{}

void CORBA::FloatSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  FloatSeq * _tao_tmp_pointer =
    static_cast<FloatSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_FloatSeq_CPP_
#define _TAO_CDR_OP_CORBA_FloatSeq_CPP_

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::FloatSeq &_tao_sequence
  )
{
  return TAO::insert_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::FloatSeq &_tao_sequence
  )
{
  return TAO::extract_sequence(strm, _tao_sequence);
}

#endif /* _TAO_CDR_OP_CORBA_FloatSeq_CPP_ */
