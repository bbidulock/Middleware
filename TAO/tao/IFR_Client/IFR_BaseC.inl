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
// be\be_visitor_interface/interface_ci.cpp:70

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

#if !defined (_CORBA_IROBJECT___CI_)
#define _CORBA_IROBJECT___CI_

ACE_INLINE
CORBA::IRObject::IRObject (
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
    the_TAO_IRObject_Proxy_Broker_ (0)
{
  this->CORBA_IRObject_setup_collocation ();
}

ACE_INLINE
CORBA::IRObject::IRObject (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_IRObject_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_CONTAINED___CI_)
#define _CORBA_CONTAINED___CI_

ACE_INLINE
CORBA::Contained::Contained (
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
    the_TAO_Contained_Proxy_Broker_ (0)
{
  this->CORBA_Contained_setup_collocation ();
}

ACE_INLINE
CORBA::Contained::Contained (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_Contained_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_CONTAINER___CI_)
#define _CORBA_CONTAINER___CI_

ACE_INLINE
CORBA::Container::Container (
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
    the_TAO_Container_Proxy_Broker_ (0)
{
  this->CORBA_Container_setup_collocation ();
}

ACE_INLINE
CORBA::Container::Container (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_Container_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_IDLTYPE___CI_)
#define _CORBA_IDLTYPE___CI_

ACE_INLINE
CORBA::IDLType::IDLType (
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
    the_TAO_IDLType_Proxy_Broker_ (0)
{
  this->CORBA_IDLType_setup_collocation ();
}

ACE_INLINE
CORBA::IDLType::IDLType (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_IDLType_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_TYPEDEFDEF___CI_)
#define _CORBA_TYPEDEFDEF___CI_

ACE_INLINE
CORBA::TypedefDef::TypedefDef (
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
    the_TAO_TypedefDef_Proxy_Broker_ (0)
{
  this->CORBA_TypedefDef_setup_collocation ();
}

ACE_INLINE
CORBA::TypedefDef::TypedefDef (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_TypedefDef_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

TAO_END_VERSIONED_NAMESPACE_DECL
