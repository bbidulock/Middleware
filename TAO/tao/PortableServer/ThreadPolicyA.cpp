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

#include "ThreadPolicyC.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

#if (TAO_HAS_MINIMUM_POA == 0)

static const CORBA::Long _oc_PortableServer_ThreadPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  44,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f54), 
  ACE_NTOHL (0x68726561), 
  ACE_NTOHL (0x64506f6c), 
  ACE_NTOHL (0x6963793a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/PortableServer/ThreadPolicy:1.0
    13,
  ACE_NTOHL (0x54687265), 
  ACE_NTOHL (0x6164506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x0),  // name = ThreadPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_ThreadPolicy (
    CORBA::tk_objref,
    sizeof (_oc_PortableServer_ThreadPolicy),
    (char *) &_oc_PortableServer_ThreadPolicy,
    0,
    sizeof (PortableServer::ThreadPolicy)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_ThreadPolicy =
    &_tc_TAO_tc_PortableServer_ThreadPolicy;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ThreadPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ThreadPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ThreadPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ThreadPolicy_ptr _tao_elem
  )
{
  PortableServer::ThreadPolicy_ptr _tao_objptr =
    PortableServer::ThreadPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ThreadPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::ThreadPolicy>::insert (
      _tao_any,
      PortableServer::ThreadPolicy::_tao_any_destructor,
      PortableServer::_tc_ThreadPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::ThreadPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::ThreadPolicy>::extract (
        _tao_any,
        PortableServer::ThreadPolicy::_tao_any_destructor,
        PortableServer::_tc_ThreadPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        PortableServer::ThreadPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::ThreadPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
