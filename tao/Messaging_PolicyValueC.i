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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_I_
#define _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const Messaging::PolicyValue::_tao_seq_Octet &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    Messaging::PolicyValue::_tao_seq_Octet &
  );

#endif /* _TAO_CDR_OP_Messaging_PolicyValue__tao_seq_Octet_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Messaging::PolicyValue &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.ptype) &&
    (strm << _tao_aggregate.pvalue)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Messaging::PolicyValue &_tao_aggregate
  )
{
  if (
    (strm >> _tao_aggregate.ptype) &&
    (strm >> _tao_aggregate.pvalue)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

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

