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
// be\be_codegen.cpp:323


#include "ShortSeqC.h"
#include "tao/Typecode.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ShortSeqC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_SHORTSEQ_CS_)
#define _CORBA_SHORTSEQ_CS_

CORBA::ShortSeq::ShortSeq (void)
{}

CORBA::ShortSeq::ShortSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::Short
      >
    (max)
{}

CORBA::ShortSeq::ShortSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Short * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::Short
      >
    (max, length, buffer, release)
{}

CORBA::ShortSeq::ShortSeq (
    const ShortSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::Short
      >
    (seq)
{}

CORBA::ShortSeq::~ShortSeq (void)
{}

void CORBA::ShortSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ShortSeq * _tao_tmp_pointer =
    ACE_static_cast (ShortSeq *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_ShortSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  31,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5368), 
  ACE_NTOHL (0x6f727453), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/ShortSeq:1.0
    9,
  ACE_NTOHL (0x53686f72), 
  ACE_NTOHL (0x74536571), 
  ACE_NTOHL (0x0),  // name = ShortSeq
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_short,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ShortSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ShortSeq),
    (char *) &_oc_CORBA_ShortSeq,
    0,
    sizeof (CORBA::ShortSeq)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ShortSeq =
    &_tc_TAO_tc_CORBA_ShortSeq;
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_ShortSeq_CPP_
#define _TAO_CDR_OP_CORBA_ShortSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ShortSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      return strm.write_short_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ShortSeq &_tao_sequence
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
          return 0;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      return strm.read_short_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
    }
  
  return 0;
}

#endif /* _TAO_CDR_OP_CORBA_ShortSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1633

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_FixedSeq_Var_T<
        CORBA::ShortSeq,
        CORBA::Short
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::ShortSeq,
        CORBA::Short
      >;

  template class
    TAO_Seq_Out_T<
        CORBA::ShortSeq,
        CORBA::ShortSeq_var,
        CORBA::Short
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_FixedSeq_Var_T< \
        CORBA::ShortSeq, \
        CORBA::Short \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::ShortSeq, \
        CORBA::Short \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        CORBA::ShortSeq, \
        CORBA::ShortSeq_var, \
        CORBA::Short \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

