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

#if !defined _TAO_CDR_OP_Kokyu_GuidType_I_
#define _TAO_CDR_OP_Kokyu_GuidType_I_

CORBA::Boolean  operator<< (
    TAO_OutputCDR &,
    const Kokyu::GuidType &
  );

CORBA::Boolean  operator>> (
    TAO_InputCDR &,
    Kokyu::GuidType &
  );

#endif /* _TAO_CDR_OP_Kokyu_GuidType_I_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Kokyu::Svc_Ctxt_DSRT_QoS &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.guid) &&
    (strm << _tao_aggregate.importance) &&
    (strm << _tao_aggregate.criticality) &&
    (strm << _tao_aggregate.desired_priority) &&
    (strm << _tao_aggregate.deadline) &&
    (strm << _tao_aggregate.estimated_initial_execution_time) &&
    (strm << _tao_aggregate.period) &&
    (strm << _tao_aggregate.task_id);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Kokyu::Svc_Ctxt_DSRT_QoS &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.guid) &&
    (strm >> _tao_aggregate.importance) &&
    (strm >> _tao_aggregate.criticality) &&
    (strm >> _tao_aggregate.desired_priority) &&
    (strm >> _tao_aggregate.deadline) &&
    (strm >> _tao_aggregate.estimated_initial_execution_time) &&
    (strm >> _tao_aggregate.period) &&
    (strm >> _tao_aggregate.task_id);
}

