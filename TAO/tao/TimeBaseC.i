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
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TimeBase::UtcT &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.time) &&
    (strm << _tao_aggregate.inacclo) &&
    (strm << _tao_aggregate.inacchi) &&
    (strm << _tao_aggregate.tdf);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TimeBase::UtcT &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.time) &&
    (strm >> _tao_aggregate.inacclo) &&
    (strm >> _tao_aggregate.inacchi) &&
    (strm >> _tao_aggregate.tdf);
}

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TimeBase::IntervalT &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.lower_bound) &&
    (strm << _tao_aggregate.upper_bound);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TimeBase::IntervalT &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.lower_bound) &&
    (strm >> _tao_aggregate.upper_bound);
}

