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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:301


#include "OctetSeqC.h"
#include "ORB_Core.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "OctetSeqC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_arg_traits.cpp:59

// Arg traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:66

#if !defined (_CORBA_OCTETSEQ_CS_)
#define _CORBA_OCTETSEQ_CS_

CORBA::OctetSeq::OctetSeq (void)
{}

CORBA::OctetSeq::OctetSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max)
{}

CORBA::OctetSeq::OctetSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Octet * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max, length, buffer, release)
{}

CORBA::OctetSeq::OctetSeq (
    const OctetSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (seq)
{}

CORBA::OctetSeq::~OctetSeq (void)
{}

void CORBA::OctetSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  OctetSeq * _tao_tmp_pointer =
    ACE_static_cast (OctetSeq *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_OctetSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  31,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f4f63), 
  ACE_NTOHL (0x74657453), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
    9,
  ACE_NTOHL (0x4f637465), 
  ACE_NTOHL (0x74536571), 
  ACE_NTOHL (0x0),  // name = OctetSeq
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_OctetSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_OctetSeq),
    (char *) &_oc_CORBA_OctetSeq,
    0,
    sizeof (CORBA::OctetSeq)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_OctetSeq =
    &_tc_TAO_tc_CORBA_OctetSeq;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::OctetSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::OctetSeq>::insert_copy (
      _tao_any,
      CORBA::OctetSeq::_tao_any_destructor,
      CORBA::_tc_OctetSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::OctetSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::OctetSeq>::insert (
      _tao_any,
      CORBA::OctetSeq::_tao_any_destructor,
      CORBA::_tc_OctetSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::OctetSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::OctetSeq *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::OctetSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::OctetSeq>::extract (
        _tao_any,
        CORBA::OctetSeq::_tao_any_destructor,
        CORBA::_tc_OctetSeq,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:95

#if !defined _TAO_CDR_OP_CORBA_OctetSeq_CPP_
#define _TAO_CDR_OP_CORBA_OctetSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::OctetSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      {
        TAO_Unbounded_Sequence<CORBA::Octet> *oseq = 
          ACE_static_cast (TAO_Unbounded_Sequence<CORBA::Octet>*, (CORBA::OctetSeq *)&_tao_sequence);
        if (oseq->mb ())
          return strm.write_octet_array_mb (oseq->mb ());
        else
          return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
      }
      
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::OctetSeq &_tao_sequence
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
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      if (ACE_BIT_DISABLED (strm.start ()->flags (),
      ACE_Message_Block::DONT_DELETE))
      {
        TAO_ORB_Core* orb_core = strm.orb_core ();
        if (orb_core != 0 &&
        strm.orb_core ()->resource_factory ()->
        input_cdr_allocator_type_locked () == 1)
        {
          TAO_Unbounded_Sequence<CORBA::Octet> *oseq = 
            ACE_static_cast(TAO_Unbounded_Sequence<CORBA::Octet>*, &_tao_sequence);
          oseq->replace (_tao_seq_len, strm.start ());
          oseq->mb ()->wr_ptr (oseq->mb()->rd_ptr () + _tao_seq_len);
          strm.skip_bytes (_tao_seq_len);
          return 1;
        }
      }
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_seq_len);
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    
    }
  
  return 0;
}

#endif /* _TAO_CDR_OP_CORBA_OctetSeq_CPP_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:1703

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_FixedSeq_Var_T<
        CORBA::OctetSeq,
        CORBA::Octet
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::OctetSeq,
        CORBA::Octet
      >;

  template class
    TAO_Seq_Out_T<
        CORBA::OctetSeq,
        CORBA::OctetSeq_var,
        CORBA::Octet
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::OctetSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_FixedSeq_Var_T< \
        CORBA::OctetSeq, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::OctetSeq, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        CORBA::OctetSeq, \
        CORBA::OctetSeq_var, \
        CORBA::Octet \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::OctetSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

