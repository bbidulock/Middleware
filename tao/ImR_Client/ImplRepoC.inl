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
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR___CI_)
#define _IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR___CI_

ACE_INLINE
ImplementationRepository::ServerInformationIterator::ServerInformationIterator (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_ServerInformationIterator_Proxy_Broker_ (0)
{
  this->ImplementationRepository_ServerInformationIterator_setup_collocation ();
}

ACE_INLINE
ImplementationRepository::ServerInformationIterator::ServerInformationIterator (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_ServerInformationIterator_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// c:\cvsdoc\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_IMPLEMENTATIONREPOSITORY_ADMINISTRATION___CI_)
#define _IMPLEMENTATIONREPOSITORY_ADMINISTRATION___CI_

ACE_INLINE
ImplementationRepository::Administration::Administration (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_Administration_Proxy_Broker_ (0)
{
  this->ImplementationRepository_Administration_setup_collocation ();
}

ACE_INLINE
ImplementationRepository::Administration::Administration (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_Administration_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */
