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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ci.cpp:56

ACE_INLINE
TAO_Default_ORT::ObjectReferenceTemplate::ObjectReferenceTemplate (void)
{}

ACE_INLINE
TAO_Default_ORT::ObjectReferenceTemplate::~ObjectReferenceTemplate (void)
{}

ACE_INLINE const char* 
TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_static_repository_id ()
{
  return "IDL:TAO_Default_ORT/ObjectReferenceTemplate:1.0";
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:236

#if defined (__ACE_INLINE__)

namespace CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (TAO_Default_ORT::ObjectReferenceTemplate *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (TAO_Default_ORT::ObjectReferenceTemplate *);
}

#endif /*__ACE_INLINE__*/

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_ci.cpp:60

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_Default_ORT::ObjectReferenceTemplate *);
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_Default_ORT::ObjectReferenceTemplate *&);

