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

ACE_INLINE
TAO_Default_ORT::ObjectReferenceFactory::ObjectReferenceFactory () // default constructor
{}

ACE_INLINE
TAO_Default_ORT::ObjectReferenceFactory::~ObjectReferenceFactory () // destructor
{}

ACE_INLINE const char* 
TAO_Default_ORT::ObjectReferenceFactory::_tao_obv_static_repository_id ()
{
  return "IDL:TAO_Default_ORT/ObjectReferenceFactory:1.0";
}

ACE_INLINE
TAO_Default_ORT::ObjectReferenceTemplate::ObjectReferenceTemplate () // default constructor
{}

ACE_INLINE
TAO_Default_ORT::ObjectReferenceTemplate::~ObjectReferenceTemplate () // destructor
{}

ACE_INLINE const char* 
TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_static_repository_id ()
{
  return "IDL:TAO_Default_ORT/ObjectReferenceTemplate:1.0";
}

//@@ Boris: begin experimental
TAO_NAMESPACE CORBA
{
  void add_ref (TAO_Default_ORT::ObjectReferenceFactory *);
  void remove_ref (TAO_Default_ORT::ObjectReferenceFactory *);
}
TAO_NAMESPACE_CLOSE
//@@ Boris: end experimental

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_Default_ORT::ObjectReferenceFactory *);
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_Default_ORT::ObjectReferenceFactory *&);
//@@ Boris: begin experimental
TAO_NAMESPACE CORBA
{
  void add_ref (TAO_Default_ORT::ObjectReferenceTemplate *);
  void remove_ref (TAO_Default_ORT::ObjectReferenceTemplate *);
}
TAO_NAMESPACE_CLOSE
//@@ Boris: end experimental

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_Default_ORT::ObjectReferenceTemplate *);
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_Default_ORT::ObjectReferenceTemplate *&);
