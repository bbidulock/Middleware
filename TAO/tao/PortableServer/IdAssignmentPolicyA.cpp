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

#include "IdAssignmentPolicyC.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Basic_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_PortableServer_IdAssignmentPolicyValue[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  55,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f49), 
  ACE_NTOHL (0x64417373), 
  ACE_NTOHL (0x69676e6d), 
  ACE_NTOHL (0x656e7450), 
  ACE_NTOHL (0x6f6c6963), 
  ACE_NTOHL (0x7956616c), 
  ACE_NTOHL (0x75653a32), 
  ACE_NTOHL (0x2e330000),  // repository ID = IDL:omg.org/PortableServer/IdAssignmentPolicyValue:2.3
  24,
  ACE_NTOHL (0x49644173), 
  ACE_NTOHL (0x7369676e), 
  ACE_NTOHL (0x6d656e74), 
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63795661), 
  ACE_NTOHL (0x6c756500),  // name = IdAssignmentPolicyValue
  2, // member count
  8,
  ACE_NTOHL (0x55534552), 
  ACE_NTOHL (0x5f494400),  // name = USER_ID
  10,
  ACE_NTOHL (0x53595354), 
  ACE_NTOHL (0x454d5f49), 
  ACE_NTOHL (0x44000000),  // name = SYSTEM_ID
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_IdAssignmentPolicyValue (
    CORBA::tk_enum,
    sizeof (_oc_PortableServer_IdAssignmentPolicyValue),
    (char *) &_oc_PortableServer_IdAssignmentPolicyValue,
    0,
    sizeof (PortableServer::IdAssignmentPolicyValue)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_IdAssignmentPolicyValue =
    &_tc_TAO_tc_PortableServer_IdAssignmentPolicyValue;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_PortableServer_IdAssignmentPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  50,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f49), 
  ACE_NTOHL (0x64417373), 
  ACE_NTOHL (0x69676e6d), 
  ACE_NTOHL (0x656e7450), 
  ACE_NTOHL (0x6f6c6963), 
  ACE_NTOHL (0x793a322e), 
  ACE_NTOHL (0x33000000),  // repository ID = IDL:omg.org/PortableServer/IdAssignmentPolicy:2.3
    19,
  ACE_NTOHL (0x49644173), 
  ACE_NTOHL (0x7369676e), 
  ACE_NTOHL (0x6d656e74), 
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63790000),  // name = IdAssignmentPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_IdAssignmentPolicy (
    CORBA::tk_objref,
    sizeof (_oc_PortableServer_IdAssignmentPolicy),
    (char *) &_oc_PortableServer_IdAssignmentPolicy,
    0,
    sizeof (PortableServer::IdAssignmentPolicy)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_IdAssignmentPolicy =
    &_tc_TAO_tc_PortableServer_IdAssignmentPolicy;
}

// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_cs.cpp:52

void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicyValue _tao_elem
  )
{
  TAO::Any_Basic_Impl_T<PortableServer::IdAssignmentPolicyValue>::insert (
      _tao_any,
      PortableServer::_tc_IdAssignmentPolicyValue,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicyValue &_tao_elem
  )
{
  return
    TAO::Any_Basic_Impl_T<PortableServer::IdAssignmentPolicyValue>::extract (
        _tao_any,
        PortableServer::_tc_IdAssignmentPolicyValue,
        _tao_elem 
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicy_ptr _tao_elem
  )
{
  PortableServer::IdAssignmentPolicy_ptr _tao_objptr =
    PortableServer::IdAssignmentPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::insert (
      _tao_any,
      PortableServer::IdAssignmentPolicy::_tao_any_destructor,
      PortableServer::_tc_IdAssignmentPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::IdAssignmentPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::IdAssignmentPolicy>::extract (
        _tao_any,
        PortableServer::IdAssignmentPolicy::_tao_any_destructor,
        PortableServer::_tc_IdAssignmentPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Basic_Impl_T<
        PortableServer::IdAssignmentPolicyValue
      >;

  template class
    TAO::Any_Impl_T<
        PortableServer::IdAssignmentPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Basic_Impl_T< \
        PortableServer::IdAssignmentPolicyValue \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::IdAssignmentPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
