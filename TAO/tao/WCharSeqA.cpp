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

#include "WCharSeqC.h"
#include "tao/Typecode.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_CORBA_WCharSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  31,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5743), 
  ACE_NTOHL (0x68617253), 
  ACE_NTOHL (0x65713a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/WCharSeq:1.0
    9,
  ACE_NTOHL (0x57436861), 
  ACE_NTOHL (0x72536571), 
  ACE_NTOHL (0x0),  // name = WCharSeq
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_wchar,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_WCharSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_WCharSeq),
    (char *) &_oc_CORBA_WCharSeq,
    0,
    sizeof (CORBA::WCharSeq)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_WCharSeq =
    &_tc_TAO_tc_CORBA_WCharSeq;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::WCharSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::WCharSeq>::insert_copy (
      _tao_any,
      CORBA::WCharSeq::_tao_any_destructor,
      CORBA::_tc_WCharSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::WCharSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::WCharSeq>::insert (
      _tao_any,
      CORBA::WCharSeq::_tao_any_destructor,
      CORBA::_tc_WCharSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::WCharSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::WCharSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::WCharSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::WCharSeq>::extract (
        _tao_any,
        CORBA::WCharSeq::_tao_any_destructor,
        CORBA::_tc_WCharSeq,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::WCharSeq
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::WCharSeq \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
