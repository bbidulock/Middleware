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

#include "PS_ForwardC.h"
#include "tao/Typecode.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_ObjectId[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  40,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x506f7274),
  ACE_NTOHL (0x61626c65),
  ACE_NTOHL (0x53657276),
  ACE_NTOHL (0x65722f4f),
  ACE_NTOHL (0x626a6563),
  ACE_NTOHL (0x7449643a),
  ACE_NTOHL (0x322e3300),  // repository ID = IDL:omg.org/PortableServer/ObjectId:2.3
    9,
  ACE_NTOHL (0x4f626a65),
  ACE_NTOHL (0x63744964),
  ACE_NTOHL (0x0),  // name = ObjectId
    CORBA::tk_alias, // typecode kind for typedefs
  76, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    31,
    ACE_NTOHL (0x49444c3a),
    ACE_NTOHL (0x6f6d672e),
    ACE_NTOHL (0x6f72672f),
    ACE_NTOHL (0x434f5242),
    ACE_NTOHL (0x412f4f63),
    ACE_NTOHL (0x74657453),
    ACE_NTOHL (0x65713a31),
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/CORBA/OctetSeq:1.0
        9,
    ACE_NTOHL (0x4f637465),
    ACE_NTOHL (0x74536571),
    ACE_NTOHL (0x0),  // name = OctetSeq
        CORBA::tk_sequence, // typecode kind
    12, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_octet,

      0U,


};

static CORBA::TypeCode _tc_TAO_tc_PortableServer_ObjectId (
    CORBA::tk_alias,
    sizeof (_oc_PortableServer_ObjectId),
    (char *) &_oc_PortableServer_ObjectId,
    0,
    sizeof (PortableServer::ObjectId)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_ObjectId =
    &_tc_TAO_tc_PortableServer_ObjectId;
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

