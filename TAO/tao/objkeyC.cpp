// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/corba.h"

#if !defined (__ACE_INLINE__)
#include "objkeyC.i"
#endif // !defined INLINE


#if !defined (_TAO__TAO_SEQ_OCTET_CS_)
#define _TAO__TAO_SEQ_OCTET_CS_

static const CORBA::Long _oc_TAO__tao_seq_Octet[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

  0,
};
static CORBA::TypeCode _tc__tc_TAO__tao_seq_Octet (CORBA::tk_sequence, sizeof (_oc_TAO__tao_seq_Octet), (unsigned char *) &_oc_TAO__tao_seq_Octet, CORBA::B_FALSE);
CORBA::TypeCode_ptr TAO::_tc__tao_seq_Octet = &_tc__tc_TAO__tao_seq_Octet;


#endif // end #if !defined

static const CORBA::Long _oc_TAO_ObjectKey[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  22, 0x49444c3a, 0x54414f2f, 0x4f626a65, 0x63744b65, 0x793a312e, 0x30000000,  // repository ID = IDL:TAO/ObjectKey:1.0
  10, 0x4f626a65, 0x63744b65, 0x79000000,  // name = ObjectKey
  CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

  0,
};
static CORBA::TypeCode _tc__tc_TAO_ObjectKey (CORBA::tk_alias, sizeof (_oc_TAO_ObjectKey), (unsigned char *) &_oc_TAO_ObjectKey, CORBA::B_FALSE);
CORBA::TypeCode_ptr TAO::_tc_ObjectKey = &_tc__tc_TAO_ObjectKey;

