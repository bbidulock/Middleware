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

#if !defined (_A_AMI_TEST___CI_)
#define _A_AMI_TEST___CI_

ACE_INLINE
A::AMI_Test::AMI_Test (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (objref, _tao_collocated, servant, oc),
    the_TAO_AMI_Test_Proxy_Broker_ (0)

{
  this->A_AMI_Test_setup_collocation (_tao_collocated);
}

template<>
ACE_INLINE
CORBA::Boolean
TAO::Any_Impl_T<A::AMI_Test>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_INLINE
A::AMI_Test::AMI_Test (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_AMI_Test_Proxy_Broker_ (0)

{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const A::DidTheRightThing &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      // Now marshal the members (if any).
      if (
        (strm << _tao_aggregate.id) &&
        (strm << _tao_aggregate.whatDidTheRightThing.in ())
       )
        {
          return 1;
        }
      else
        {
          return 0;
        }
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    A::DidTheRightThing &_tao_aggregate
  )
{
  // Demarshal the members.
  if (
    (strm >> _tao_aggregate.id) &&
    (strm >> _tao_aggregate.whatDidTheRightThing.out ())
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
A::AMI_AMI_TestExceptionHolder::AMI_AMI_TestExceptionHolder (void)
{}

ACE_INLINE
A::AMI_AMI_TestExceptionHolder::~AMI_AMI_TestExceptionHolder (void)
{}

ACE_INLINE const char*
A::AMI_AMI_TestExceptionHolder::_tao_obv_static_repository_id ()
{
  return "IDL:A/AMI_AMI_TestExceptionHolder:1.0";
}

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ci.cpp:72

 CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const A::AMI_Test_ptr
  );

 CORBA::Boolean operator>> (
    TAO_InputCDR &,
    A::AMI_Test_ptr &
  );
