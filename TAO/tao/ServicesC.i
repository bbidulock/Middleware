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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceDetail &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.service_detail_type) &&
    (strm << _tao_aggregate.service_detail);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceDetail &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.service_detail_type) &&
    (strm >> _tao_aggregate.service_detail);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__I_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_ &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    CORBA::ServiceInformation::_tao_seq_CORBA_ServiceOption_ &
  );

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceOption__I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__I_
#define _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_ &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    CORBA::ServiceInformation::_tao_seq_CORBA_ServiceDetail_ &
  );

#endif /* _TAO_CDR_OP_CORBA_ServiceInformation__tao_seq_CORBA_ServiceDetail__I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceInformation &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.service_options) &&
    (strm << _tao_aggregate.service_details);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceInformation &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.service_options) &&
    (strm >> _tao_aggregate.service_details);
}

