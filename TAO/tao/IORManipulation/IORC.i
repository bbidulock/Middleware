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
// be/be_visitor_interface/interface_ci.cpp:63

#if !defined (_TAO_IOP_TAO_IOR_PROPERTY___CI_)
#define _TAO_IOP_TAO_IOR_PROPERTY___CI_

template<>
ACE_INLINE
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Property>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
ACE_INLINE
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Property>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

template<>
ACE_INLINE
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Property>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ci.cpp:63

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION___CI_)
#define _TAO_IOP_TAO_IOR_MANIPULATION___CI_

template<>
ACE_INLINE
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Manipulation>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
ACE_INLINE
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Manipulation>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

template<>
ACE_INLINE
CORBA::Boolean
TAO::Any_Impl_T<TAO_IOP::TAO_IOR_Manipulation>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_IOP::EmptyProfileList &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    TAO_IOP::EmptyProfileList&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_IOP::NotFound &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    TAO_IOP::NotFound&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_IOP::Duplicate &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    TAO_IOP::Duplicate&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_IOP::Invalid_IOR &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    TAO_IOP::Invalid_IOR&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_IOP::MultiProfileList &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    TAO_IOP::MultiProfileList&
  )
{
  return 1;
}

