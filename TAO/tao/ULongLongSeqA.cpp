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

#include "ULongLongSeqC.h"
#include "tao/Typecode.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_ULongLongSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  35,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f554c), 
  ACE_NTOHL (0x6f6e674c), 
  ACE_NTOHL (0x6f6e6753), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/ULongLongSeq:1.0
    13,
  ACE_NTOHL (0x554c6f6e), 
  ACE_NTOHL (0x674c6f6e), 
  ACE_NTOHL (0x67536571), 
  ACE_NTOHL (0x0),  // name = ULongLongSeq
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_ulonglong,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_ULongLongSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_ULongLongSeq),
    (char *) &_oc_CORBA_ULongLongSeq,
    0,
    sizeof (CORBA::ULongLongSeq)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ULongLongSeq =
    &_tc_TAO_tc_CORBA_ULongLongSeq;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ULongLongSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ULongLongSeq>::insert_copy (
      _tao_any,
      CORBA::ULongLongSeq::_tao_any_destructor,
      CORBA::_tc_ULongLongSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ULongLongSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ULongLongSeq>::insert (
      _tao_any,
      CORBA::ULongLongSeq::_tao_any_destructor,
      CORBA::_tc_ULongLongSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ULongLongSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ULongLongSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ULongLongSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ULongLongSeq>::extract (
        _tao_any,
        CORBA::ULongLongSeq::_tao_any_destructor,
        CORBA::_tc_ULongLongSeq,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::ULongLongSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::ULongLongSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
