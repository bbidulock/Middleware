// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/Object_KeyC.h"
#include "tao/Typecode.h"

#if !defined (__ACE_INLINE__)
#include "Object_KeyC.i"
#endif // !defined INLINE

ACE_RCSID(tao, Object_KeyC, "$Id$")

const CORBA::Long _oc_TAO__tao_seq_Octet[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

  0,
};
CORBA::TypeCode _tc_TAO_tc_TAO__tao_seq_Octet (CORBA::tk_sequence, sizeof
                                            (_oc_TAO__tao_seq_Octet), (char *)
                                            &_oc_TAO__tao_seq_Octet, 0,
                                            sizeof (TAO_ObjectKey));
CORBA::TypeCode_ptr TAO_tc__tao_seq_Octet = &_tc_TAO_tc_TAO__tao_seq_Octet;

const CORBA::Long _oc_TAO_ObjectKey[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  22, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f2f), ACE_NTOHL (0x4f626a65), ACE_NTOHL (0x63744b65), ACE_NTOHL (0x793a312e), ACE_NTOHL (0x3000fdfd),  // repository ID = IDL:TAO/ObjectKey:1.0
  10, ACE_NTOHL (0x4f626a65), ACE_NTOHL (0x63744b65), ACE_NTOHL (0x7900fdfd),  // name = ObjectKey
  CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

  0,
};
CORBA::TypeCode _tc_TAO_tc_TAO_ObjectKey (CORBA::tk_alias, sizeof
                                       (_oc_TAO_ObjectKey), (char *)
                                       &_oc_TAO_ObjectKey, 0,
                                       sizeof (TAO_ObjectKey));
CORBA::TypeCode_ptr TAO_tc_ObjectKey = &_tc_TAO_tc_TAO_ObjectKey;


// ****************************************************************

int
operator== (const TAO_ObjectKey &lhs,
            const TAO_ObjectKey &rhs)
{
  if (rhs.length () != lhs.length ())
    return 0;

  for (CORBA::ULong i = 0;
       i < rhs.length ();
       ++i)
    if (rhs[i] != lhs[i])
      return 0;

  return 1;
}

