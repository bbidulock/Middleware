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

#include "ServantRetentionPolicyC.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

#if (TAO_HAS_MINIMUM_POA == 0)

static const CORBA::Long _oc_PortableServer_ServantRetentionPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  54,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x506f7274),
  ACE_NTOHL (0x61626c65),
  ACE_NTOHL (0x53657276),
  ACE_NTOHL (0x65722f53),
  ACE_NTOHL (0x65727661),
  ACE_NTOHL (0x6e745265),
  ACE_NTOHL (0x74656e74),
  ACE_NTOHL (0x696f6e50),
  ACE_NTOHL (0x6f6c6963),
  ACE_NTOHL (0x793a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/PortableServer/ServantRetentionPolicy:1.0
    23,
  ACE_NTOHL (0x53657276),
  ACE_NTOHL (0x616e7452),
  ACE_NTOHL (0x6574656e),
  ACE_NTOHL (0x74696f6e),
  ACE_NTOHL (0x506f6c69),
  ACE_NTOHL (0x63790000),  // name = ServantRetentionPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_ServantRetentionPolicy (
    CORBA::tk_objref,
    sizeof (_oc_PortableServer_ServantRetentionPolicy),
    (char *) &_oc_PortableServer_ServantRetentionPolicy,
    0,
    sizeof (PortableServer::ServantRetentionPolicy)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_ServantRetentionPolicy =
    &_tc_TAO_tc_PortableServer_ServantRetentionPolicy;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantRetentionPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantRetentionPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::ServantRetentionPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantRetentionPolicy_ptr _tao_elem
  )
{
  PortableServer::ServantRetentionPolicy_ptr _tao_objptr =
    PortableServer::ServantRetentionPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::ServantRetentionPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::ServantRetentionPolicy>::insert (
      _tao_any,
      PortableServer::ServantRetentionPolicy::_tao_any_destructor,
      PortableServer::_tc_ServantRetentionPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::ServantRetentionPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::ServantRetentionPolicy>::extract (
        _tao_any,
        PortableServer::ServantRetentionPolicy::_tao_any_destructor,
        PortableServer::_tc_ServantRetentionPolicy,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        PortableServer::ServantRetentionPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::ServantRetentionPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */
