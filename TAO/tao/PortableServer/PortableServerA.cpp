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

#define TAO_PORTABLESERVER_SAFE_INCLUDE
#include "PortableServerC.h"
#undef TAO_PORTABLESERVER_SAFE_INCLUDE
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POAList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  39,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x506f7274),
  ACE_NTOHL (0x61626c65),
  ACE_NTOHL (0x53657276),
  ACE_NTOHL (0x65722f50),
  ACE_NTOHL (0x4f414c69),
  ACE_NTOHL (0x73743a31),
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/PortableServer/POAList:1.0
    8,
  ACE_NTOHL (0x504f414c),
  ACE_NTOHL (0x69737400),  // name = POAList
    CORBA::tk_sequence, // typecode kind
  8, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    0U,

};

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POAList (
    CORBA::tk_alias,
    sizeof (_oc_PortableServer_POAList),
    (char *) &_oc_PortableServer_POAList,
    0,
    sizeof (PortableServer::POAList)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_POAList =
    &_tc_TAO_tc_PortableServer_POAList;
}

#if (TAO_HAS_MINIMUM_POA == 0)

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_AdapterAlreadyExists[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  56,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x506f7274),
  ACE_NTOHL (0x61626c65),
  ACE_NTOHL (0x53657276),
  ACE_NTOHL (0x65722f50),
  ACE_NTOHL (0x4f412f41),
  ACE_NTOHL (0x64617074),
  ACE_NTOHL (0x6572416c),
  ACE_NTOHL (0x72656164),
  ACE_NTOHL (0x79457869),
  ACE_NTOHL (0x7374733a),
  ACE_NTOHL (0x322e3300),  // repository ID = IDL:omg.org/PortableServer/POA/AdapterAlreadyExists:2.3
    21,
  ACE_NTOHL (0x41646170),
  ACE_NTOHL (0x74657241),
  ACE_NTOHL (0x6c726561),
  ACE_NTOHL (0x64794578),
  ACE_NTOHL (0x69737473),
  ACE_NTOHL (0x0),  // name = AdapterAlreadyExists
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_AdapterAlreadyExists (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_AdapterAlreadyExists),
    (char *) &_oc_PortableServer_POA_AdapterAlreadyExists,
    0,
    sizeof (PortableServer::POA::AdapterAlreadyExists)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_AdapterAlreadyExists =
  &_tc_TAO_tc_PortableServer_POA_AdapterAlreadyExists;

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_AdapterNonExistent[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  54,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x506f7274),
  ACE_NTOHL (0x61626c65),
  ACE_NTOHL (0x53657276),
  ACE_NTOHL (0x65722f50),
  ACE_NTOHL (0x4f412f41),
  ACE_NTOHL (0x64617074),
  ACE_NTOHL (0x65724e6f),
  ACE_NTOHL (0x6e457869),
  ACE_NTOHL (0x7374656e),
  ACE_NTOHL (0x743a322e),
  ACE_NTOHL (0x33000000),  // repository ID = IDL:omg.org/PortableServer/POA/AdapterNonExistent:2.3
    19,
  ACE_NTOHL (0x41646170),
  ACE_NTOHL (0x7465724e),
  ACE_NTOHL (0x6f6e4578),
  ACE_NTOHL (0x69737465),
  ACE_NTOHL (0x6e740000),  // name = AdapterNonExistent
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_AdapterNonExistent (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_AdapterNonExistent),
    (char *) &_oc_PortableServer_POA_AdapterNonExistent,
    0,
    sizeof (PortableServer::POA::AdapterNonExistent)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_AdapterNonExistent =
  &_tc_TAO_tc_PortableServer_POA_AdapterNonExistent;

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_InvalidPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  49,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x506f7274),
  ACE_NTOHL (0x61626c65),
  ACE_NTOHL (0x53657276),
  ACE_NTOHL (0x65722f50),
  ACE_NTOHL (0x4f412f49),
  ACE_NTOHL (0x6e76616c),
  ACE_NTOHL (0x6964506f),
  ACE_NTOHL (0x6c696379),
  ACE_NTOHL (0x3a322e33),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/PortableServer/POA/InvalidPolicy:2.3
    14,
  ACE_NTOHL (0x496e7661),
  ACE_NTOHL (0x6c696450),
  ACE_NTOHL (0x6f6c6963),
  ACE_NTOHL (0x79000000),  // name = InvalidPolicy
  1, // member count
    6,
  ACE_NTOHL (0x696e6465),
  ACE_NTOHL (0x78000000),  // name = index
    CORBA::tk_ushort,

};

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_InvalidPolicy (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_InvalidPolicy),
    (char *) &_oc_PortableServer_POA_InvalidPolicy,
    0,
    sizeof (PortableServer::POA::InvalidPolicy)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_InvalidPolicy =
  &_tc_TAO_tc_PortableServer_POA_InvalidPolicy;

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_NoServant[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  45,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f50), 
  ACE_NTOHL (0x4f412f4e), 
  ACE_NTOHL (0x6f536572), 
  ACE_NTOHL (0x76616e74), 
  ACE_NTOHL (0x3a322e33), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/PortableServer/POA/NoServant:2.3
    10,
  ACE_NTOHL (0x4e6f5365), 
  ACE_NTOHL (0x7276616e), 
  ACE_NTOHL (0x74000000),  // name = NoServant
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_NoServant (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_NoServant),
    (char *) &_oc_PortableServer_POA_NoServant,
    0,
    sizeof (PortableServer::POA::NoServant)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_NoServant =
  &_tc_TAO_tc_PortableServer_POA_NoServant;

#if (TAO_HAS_MINIMUM_POA == 0)

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_ObjectAlreadyActive[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  55,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f50), 
  ACE_NTOHL (0x4f412f4f), 
  ACE_NTOHL (0x626a6563), 
  ACE_NTOHL (0x74416c72), 
  ACE_NTOHL (0x65616479), 
  ACE_NTOHL (0x41637469), 
  ACE_NTOHL (0x76653a32), 
  ACE_NTOHL (0x2e330000),  // repository ID = IDL:omg.org/PortableServer/POA/ObjectAlreadyActive:2.3
    20,
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x6374416c), 
  ACE_NTOHL (0x72656164), 
  ACE_NTOHL (0x79416374), 
  ACE_NTOHL (0x69766500),  // name = ObjectAlreadyActive
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_ObjectAlreadyActive (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_ObjectAlreadyActive),
    (char *) &_oc_PortableServer_POA_ObjectAlreadyActive,
    0,
    sizeof (PortableServer::POA::ObjectAlreadyActive)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_ObjectAlreadyActive =
  &_tc_TAO_tc_PortableServer_POA_ObjectAlreadyActive;

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_ObjectNotActive[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  51,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f50), 
  ACE_NTOHL (0x4f412f4f), 
  ACE_NTOHL (0x626a6563), 
  ACE_NTOHL (0x744e6f74), 
  ACE_NTOHL (0x41637469), 
  ACE_NTOHL (0x76653a32), 
  ACE_NTOHL (0x2e330000),  // repository ID = IDL:omg.org/PortableServer/POA/ObjectNotActive:2.3
    16,
  ACE_NTOHL (0x4f626a65), 
  ACE_NTOHL (0x63744e6f), 
  ACE_NTOHL (0x74416374), 
  ACE_NTOHL (0x69766500),  // name = ObjectNotActive
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_ObjectNotActive (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_ObjectNotActive),
    (char *) &_oc_PortableServer_POA_ObjectNotActive,
    0,
    sizeof (PortableServer::POA::ObjectNotActive)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_ObjectNotActive =
  &_tc_TAO_tc_PortableServer_POA_ObjectNotActive;

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

#if (TAO_HAS_MINIMUM_POA == 0)

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_ServantAlreadyActive[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  56,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f50), 
  ACE_NTOHL (0x4f412f53), 
  ACE_NTOHL (0x65727661), 
  ACE_NTOHL (0x6e74416c), 
  ACE_NTOHL (0x72656164), 
  ACE_NTOHL (0x79416374), 
  ACE_NTOHL (0x6976653a), 
  ACE_NTOHL (0x322e3300),  // repository ID = IDL:omg.org/PortableServer/POA/ServantAlreadyActive:2.3
    21,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x616e7441), 
  ACE_NTOHL (0x6c726561), 
  ACE_NTOHL (0x64794163), 
  ACE_NTOHL (0x74697665), 
  ACE_NTOHL (0x0),  // name = ServantAlreadyActive
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_ServantAlreadyActive (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_ServantAlreadyActive),
    (char *) &_oc_PortableServer_POA_ServantAlreadyActive,
    0,
    sizeof (PortableServer::POA::ServantAlreadyActive)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_ServantAlreadyActive =
  &_tc_TAO_tc_PortableServer_POA_ServantAlreadyActive;

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

#if (TAO_HAS_MINIMUM_POA == 0)

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_ServantNotActive[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  52,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f50), 
  ACE_NTOHL (0x4f412f53), 
  ACE_NTOHL (0x65727661), 
  ACE_NTOHL (0x6e744e6f), 
  ACE_NTOHL (0x74416374), 
  ACE_NTOHL (0x6976653a), 
  ACE_NTOHL (0x322e3300),  // repository ID = IDL:omg.org/PortableServer/POA/ServantNotActive:2.3
    17,
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x616e744e), 
  ACE_NTOHL (0x6f744163), 
  ACE_NTOHL (0x74697665), 
  ACE_NTOHL (0x0),  // name = ServantNotActive
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_ServantNotActive (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_ServantNotActive),
    (char *) &_oc_PortableServer_POA_ServantNotActive,
    0,
    sizeof (PortableServer::POA::ServantNotActive)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_ServantNotActive =
  &_tc_TAO_tc_PortableServer_POA_ServantNotActive;

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_WrongAdapter[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  48,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f50), 
  ACE_NTOHL (0x4f412f57), 
  ACE_NTOHL (0x726f6e67), 
  ACE_NTOHL (0x41646170), 
  ACE_NTOHL (0x7465723a), 
  ACE_NTOHL (0x322e3300),  // repository ID = IDL:omg.org/PortableServer/POA/WrongAdapter:2.3
    13,
  ACE_NTOHL (0x57726f6e), 
  ACE_NTOHL (0x67416461), 
  ACE_NTOHL (0x70746572), 
  ACE_NTOHL (0x0),  // name = WrongAdapter
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_WrongAdapter (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_WrongAdapter),
    (char *) &_oc_PortableServer_POA_WrongAdapter,
    0,
    sizeof (PortableServer::POA::WrongAdapter)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_WrongAdapter =
  &_tc_TAO_tc_PortableServer_POA_WrongAdapter;

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA_WrongPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  47,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f50), 
  ACE_NTOHL (0x4f412f57), 
  ACE_NTOHL (0x726f6e67), 
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63793a32), 
  ACE_NTOHL (0x2e330000),  // repository ID = IDL:omg.org/PortableServer/POA/WrongPolicy:2.3
    12,
  ACE_NTOHL (0x57726f6e), 
  ACE_NTOHL (0x67506f6c), 
  ACE_NTOHL (0x69637900),  // name = WrongPolicy
  0, // member count
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA_WrongPolicy (
    CORBA::tk_except,
    sizeof (_oc_PortableServer_POA_WrongPolicy),
    (char *) &_oc_PortableServer_POA_WrongPolicy,
    0,
    sizeof (PortableServer::POA::WrongPolicy)
  );

::CORBA::TypeCode_ptr PortableServer::POA::_tc_WrongPolicy =
  &_tc_TAO_tc_PortableServer_POA_WrongPolicy;

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_PortableServer_POA[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  35,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x506f7274), 
  ACE_NTOHL (0x61626c65), 
  ACE_NTOHL (0x53657276), 
  ACE_NTOHL (0x65722f50), 
  ACE_NTOHL (0x4f413a32), 
  ACE_NTOHL (0x2e330000),  // repository ID = IDL:omg.org/PortableServer/POA:2.3
    4,
  ACE_NTOHL (0x504f4100),  // name = POA
  };

static CORBA::TypeCode _tc_TAO_tc_PortableServer_POA (
    CORBA::tk_objref,
    sizeof (_oc_PortableServer_POA),
    (char *) &_oc_PortableServer_POA,
    0,
    sizeof (PortableServer::POA)
  );

namespace PortableServer
{
  ::CORBA::TypeCode_ptr _tc_POA =
    &_tc_TAO_tc_PortableServer_POA;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54



ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POAList>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POAList>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POAList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POAList>::insert_copy (
      _tao_any,
      PortableServer::POAList::_tao_any_destructor,
      PortableServer::_tc_POAList,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POAList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POAList>::insert (
      _tao_any,
      PortableServer::POAList::_tao_any_destructor,
      PortableServer::_tc_POAList,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POAList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POAList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POAList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POAList>::extract (
        _tao_any,
        PortableServer::POAList::_tao_any_destructor,
        PortableServer::_tc_POAList,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POA>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POA>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::POA>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA_ptr _tao_elem
  )
{
  PortableServer::POA_ptr _tao_objptr =
    PortableServer::POA::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::POA>::insert (
      _tao_any,
      PortableServer::POA::_tao_any_destructor,
      PortableServer::_tc_POA,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::POA>::extract (
        _tao_any,
        PortableServer::POA::_tao_any_destructor,
        PortableServer::_tc_POA,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::AdapterAlreadyExists &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::insert_copy (
      _tao_any,
      PortableServer::POA::AdapterAlreadyExists::_tao_any_destructor,
      PortableServer::POA::_tc_AdapterAlreadyExists,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::AdapterAlreadyExists *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::insert (
      _tao_any,
      PortableServer::POA::AdapterAlreadyExists::_tao_any_destructor,
      PortableServer::POA::_tc_AdapterAlreadyExists,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::AdapterAlreadyExists *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::AdapterAlreadyExists *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::AdapterAlreadyExists *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterAlreadyExists>::extract (
        _tao_any,
        PortableServer::POA::AdapterAlreadyExists::_tao_any_destructor,
        PortableServer::POA::_tc_AdapterAlreadyExists,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::AdapterNonExistent &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::insert_copy (
      _tao_any,
      PortableServer::POA::AdapterNonExistent::_tao_any_destructor,
      PortableServer::POA::_tc_AdapterNonExistent,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::AdapterNonExistent *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::insert (
      _tao_any,
      PortableServer::POA::AdapterNonExistent::_tao_any_destructor,
      PortableServer::POA::_tc_AdapterNonExistent,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::AdapterNonExistent *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::AdapterNonExistent *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::AdapterNonExistent *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::AdapterNonExistent>::extract (
        _tao_any,
        PortableServer::POA::AdapterNonExistent::_tao_any_destructor,
        PortableServer::POA::_tc_AdapterNonExistent,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::InvalidPolicy &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::insert_copy (
      _tao_any,
      PortableServer::POA::InvalidPolicy::_tao_any_destructor,
      PortableServer::POA::_tc_InvalidPolicy,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::InvalidPolicy *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::insert (
      _tao_any,
      PortableServer::POA::InvalidPolicy::_tao_any_destructor,
      PortableServer::POA::_tc_InvalidPolicy,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::InvalidPolicy *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::InvalidPolicy *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::InvalidPolicy *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::InvalidPolicy>::extract (
        _tao_any,
        PortableServer::POA::InvalidPolicy::_tao_any_destructor,
        PortableServer::POA::_tc_InvalidPolicy,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

#if (TAO_HAS_MINIMUM_POA == 0)

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::NoServant &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::insert_copy (
      _tao_any,
      PortableServer::POA::NoServant::_tao_any_destructor,
      PortableServer::POA::_tc_NoServant,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::NoServant *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::insert (
      _tao_any,
      PortableServer::POA::NoServant::_tao_any_destructor,
      PortableServer::POA::_tc_NoServant,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::NoServant *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::NoServant *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::NoServant *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::NoServant>::extract (
        _tao_any,
        PortableServer::POA::NoServant::_tao_any_destructor,
        PortableServer::POA::_tc_NoServant,
        _tao_elem
      );
}

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::ObjectAlreadyActive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::insert_copy (
      _tao_any,
      PortableServer::POA::ObjectAlreadyActive::_tao_any_destructor,
      PortableServer::POA::_tc_ObjectAlreadyActive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::ObjectAlreadyActive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::insert (
      _tao_any,
      PortableServer::POA::ObjectAlreadyActive::_tao_any_destructor,
      PortableServer::POA::_tc_ObjectAlreadyActive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::ObjectAlreadyActive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::ObjectAlreadyActive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::ObjectAlreadyActive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectAlreadyActive>::extract (
        _tao_any,
        PortableServer::POA::ObjectAlreadyActive::_tao_any_destructor,
        PortableServer::POA::_tc_ObjectAlreadyActive,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::ObjectNotActive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::insert_copy (
      _tao_any,
      PortableServer::POA::ObjectNotActive::_tao_any_destructor,
      PortableServer::POA::_tc_ObjectNotActive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::ObjectNotActive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::insert (
      _tao_any,
      PortableServer::POA::ObjectNotActive::_tao_any_destructor,
      PortableServer::POA::_tc_ObjectNotActive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::ObjectNotActive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::ObjectNotActive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::ObjectNotActive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::ObjectNotActive>::extract (
        _tao_any,
        PortableServer::POA::ObjectNotActive::_tao_any_destructor,
        PortableServer::POA::_tc_ObjectNotActive,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::ServantAlreadyActive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::insert_copy (
      _tao_any,
      PortableServer::POA::ServantAlreadyActive::_tao_any_destructor,
      PortableServer::POA::_tc_ServantAlreadyActive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::ServantAlreadyActive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::insert (
      _tao_any,
      PortableServer::POA::ServantAlreadyActive::_tao_any_destructor,
      PortableServer::POA::_tc_ServantAlreadyActive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::ServantAlreadyActive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::ServantAlreadyActive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::ServantAlreadyActive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::ServantAlreadyActive>::extract (
        _tao_any,
        PortableServer::POA::ServantAlreadyActive::_tao_any_destructor,
        PortableServer::POA::_tc_ServantAlreadyActive,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::ServantNotActive &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::insert_copy (
      _tao_any,
      PortableServer::POA::ServantNotActive::_tao_any_destructor,
      PortableServer::POA::_tc_ServantNotActive,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::ServantNotActive *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::insert (
      _tao_any,
      PortableServer::POA::ServantNotActive::_tao_any_destructor,
      PortableServer::POA::_tc_ServantNotActive,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::ServantNotActive *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::ServantNotActive *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::ServantNotActive *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::ServantNotActive>::extract (
        _tao_any,
        PortableServer::POA::ServantNotActive::_tao_any_destructor,
        PortableServer::POA::_tc_ServantNotActive,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::WrongAdapter &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::insert_copy (
      _tao_any,
      PortableServer::POA::WrongAdapter::_tao_any_destructor,
      PortableServer::POA::_tc_WrongAdapter,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::WrongAdapter *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::insert (
      _tao_any,
      PortableServer::POA::WrongAdapter::_tao_any_destructor,
      PortableServer::POA::_tc_WrongAdapter,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::WrongAdapter *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::WrongAdapter *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::WrongAdapter *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::WrongAdapter>::extract (
        _tao_any,
        PortableServer::POA::WrongAdapter::_tao_any_destructor,
        PortableServer::POA::_tc_WrongAdapter,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::POA::WrongPolicy &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::insert_copy (
      _tao_any,
      PortableServer::POA::WrongPolicy::_tao_any_destructor,
      PortableServer::POA::_tc_WrongPolicy,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::POA::WrongPolicy *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::insert (
      _tao_any,
      PortableServer::POA::WrongPolicy::_tao_any_destructor,
      PortableServer::POA::_tc_WrongPolicy,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::POA::WrongPolicy *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::POA::WrongPolicy *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::POA::WrongPolicy *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::POA::WrongPolicy>::extract (
        _tao_any,
        PortableServer::POA::WrongPolicy::_tao_any_destructor,
        PortableServer::POA::_tc_WrongPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::AdapterAlreadyExists
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::AdapterNonExistent
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::InvalidPolicy
      >;

#if (TAO_HAS_MINIMUM_POA == 0)

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::NoServant
      >;

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::ObjectAlreadyActive
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::ObjectNotActive
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::ServantAlreadyActive
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::ServantNotActive
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::WrongAdapter
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POA::WrongPolicy
      >;

  template class
    TAO::Any_Impl_T<
        PortableServer::POA
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::POAList
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::AdapterAlreadyExists \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::AdapterNonExistent \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::InvalidPolicy \
      >

#if (TAO_HAS_MINIMUM_POA == 0)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::NoServant \
      >

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::ObjectAlreadyActive \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::ObjectNotActive \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::ServantAlreadyActive \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::ServantNotActive \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::WrongAdapter \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POA::WrongPolicy \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::POA \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::POAList \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
