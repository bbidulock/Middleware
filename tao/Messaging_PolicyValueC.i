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
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_CORBA_Octet__I_
#define _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_CORBA_Octet__I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValue::_tao_seq_CORBA_Octet_ &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValue::_tao_seq_CORBA_Octet_ &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_CORBA_Octet__I_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::PolicyValue &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.ptype) &&
    (strm << _tao_aggregate.pvalue);
}

ACE_INLINE
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
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_Messaging_PolicyValueSeq_I_
#define _TAO_CDR_OP_Messaging_PolicyValueSeq_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValueSeq &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValueSeq &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValueSeq_I_ */

