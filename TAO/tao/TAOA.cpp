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

#include "TAOC.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_TAO_BufferingConstraintMode[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  40,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x74616f2f),
  ACE_NTOHL (0x54414f2f),
  ACE_NTOHL (0x42756666),
  ACE_NTOHL (0x6572696e),
  ACE_NTOHL (0x67436f6e),
  ACE_NTOHL (0x73747261),
  ACE_NTOHL (0x696e744d),
  ACE_NTOHL (0x6f64653a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:tao/TAO/BufferingConstraintMode:1.0
    24,
  ACE_NTOHL (0x42756666),
  ACE_NTOHL (0x6572696e),
  ACE_NTOHL (0x67436f6e),
  ACE_NTOHL (0x73747261),
  ACE_NTOHL (0x696e744d),
  ACE_NTOHL (0x6f646500),  // name = BufferingConstraintMode
    CORBA::tk_ushort,

};

static CORBA::TypeCode _tc_TAO_tc_TAO_BufferingConstraintMode (
    CORBA::tk_alias,
    sizeof (_oc_TAO_BufferingConstraintMode),
    (char *) &_oc_TAO_BufferingConstraintMode,
    0,
    sizeof (TAO::BufferingConstraintMode)
  );

namespace TAO
{
  ::CORBA::TypeCode_ptr _tc_BufferingConstraintMode =
    &_tc_TAO_tc_TAO_BufferingConstraintMode;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_TAO_BufferingConstraint[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x74616f2f),
  ACE_NTOHL (0x54414f2f),
  ACE_NTOHL (0x42756666),
  ACE_NTOHL (0x6572696e),
  ACE_NTOHL (0x67436f6e),
  ACE_NTOHL (0x73747261),
  ACE_NTOHL (0x696e743a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:tao/TAO/BufferingConstraint:1.0
    20,
  ACE_NTOHL (0x42756666),
  ACE_NTOHL (0x6572696e),
  ACE_NTOHL (0x67436f6e),
  ACE_NTOHL (0x73747261),
  ACE_NTOHL (0x696e7400),  // name = BufferingConstraint
  4, // member count
    5,
  ACE_NTOHL (0x6d6f6465),
  ACE_NTOHL (0x0),  // name = mode
    CORBA::tk_alias, // typecode kind for typedefs
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    40,
    ACE_NTOHL (0x49444c3a),
    ACE_NTOHL (0x74616f2f),
    ACE_NTOHL (0x54414f2f),
    ACE_NTOHL (0x42756666),
    ACE_NTOHL (0x6572696e),
    ACE_NTOHL (0x67436f6e),
    ACE_NTOHL (0x73747261),
    ACE_NTOHL (0x696e744d),
    ACE_NTOHL (0x6f64653a),
    ACE_NTOHL (0x312e3000),  // repository ID = IDL:tao/TAO/BufferingConstraintMode:1.0
        24,
    ACE_NTOHL (0x42756666),
    ACE_NTOHL (0x6572696e),
    ACE_NTOHL (0x67436f6e),
    ACE_NTOHL (0x73747261),
    ACE_NTOHL (0x696e744d),
    ACE_NTOHL (0x6f646500),  // name = BufferingConstraintMode
        CORBA::tk_ushort,


  8,
  ACE_NTOHL (0x74696d65),
  ACE_NTOHL (0x6f757400),  // name = timeout
    CORBA::tk_alias, // typecode kind for typedefs
  56, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    31,
    ACE_NTOHL (0x49444c3a),
    ACE_NTOHL (0x6f6d672e),
    ACE_NTOHL (0x6f72672f),
    ACE_NTOHL (0x54696d65),
    ACE_NTOHL (0x42617365),
    ACE_NTOHL (0x2f54696d),
    ACE_NTOHL (0x65543a31),
    ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/TimeBase/TimeT:1.0
        6,
    ACE_NTOHL (0x54696d65),
    ACE_NTOHL (0x54000000),  // name = TimeT
        CORBA::tk_ulonglong,


  14,
  ACE_NTOHL (0x6d657373),
  ACE_NTOHL (0x6167655f),
  ACE_NTOHL (0x636f756e),
  ACE_NTOHL (0x74000000),  // name = message_count
    CORBA::tk_ulong,

  14,
  ACE_NTOHL (0x6d657373),
  ACE_NTOHL (0x6167655f),
  ACE_NTOHL (0x62797465),
  ACE_NTOHL (0x73000000),  // name = message_bytes
    CORBA::tk_ulong,

};

static CORBA::TypeCode _tc_TAO_tc_TAO_BufferingConstraint (
    CORBA::tk_struct,
    sizeof (_oc_TAO_BufferingConstraint),
    (char *) &_oc_TAO_BufferingConstraint,
    0,
    sizeof (TAO::BufferingConstraint)
  );

namespace TAO
{
  ::CORBA::TypeCode_ptr _tc_BufferingConstraint =
    &_tc_TAO_tc_TAO_BufferingConstraint;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_TAO_BufferingConstraintPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  42,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x74616f2f),
  ACE_NTOHL (0x54414f2f),
  ACE_NTOHL (0x42756666),
  ACE_NTOHL (0x6572696e),
  ACE_NTOHL (0x67436f6e),
  ACE_NTOHL (0x73747261),
  ACE_NTOHL (0x696e7450),
  ACE_NTOHL (0x6f6c6963),
  ACE_NTOHL (0x793a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:tao/TAO/BufferingConstraintPolicy:1.0
    26,
  ACE_NTOHL (0x42756666),
  ACE_NTOHL (0x6572696e),
  ACE_NTOHL (0x67436f6e),
  ACE_NTOHL (0x73747261),
  ACE_NTOHL (0x696e7450),
  ACE_NTOHL (0x6f6c6963),
  ACE_NTOHL (0x79000000),  // name = BufferingConstraintPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_TAO_BufferingConstraintPolicy (
    CORBA::tk_objref,
    sizeof (_oc_TAO_BufferingConstraintPolicy),
    (char *) &_oc_TAO_BufferingConstraintPolicy,
    0,
    sizeof (TAO::BufferingConstraintPolicy)
  );

namespace TAO
{
  ::CORBA::TypeCode_ptr _tc_BufferingConstraintPolicy =
    &_tc_TAO_tc_TAO_BufferingConstraintPolicy;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO::BufferingConstraint &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::BufferingConstraint>::insert_copy (
      _tao_any,
      TAO::BufferingConstraint::_tao_any_destructor,
      TAO::_tc_BufferingConstraint,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraint *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::BufferingConstraint>::insert (
      _tao_any,
      TAO::BufferingConstraint::_tao_any_destructor,
      TAO::_tc_BufferingConstraint,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO::BufferingConstraint *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const TAO::BufferingConstraint *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO::BufferingConstraint *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO::BufferingConstraint>::extract (
        _tao_any,
        TAO::BufferingConstraint::_tao_any_destructor,
        TAO::_tc_BufferingConstraint,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr _tao_elem
  )
{
  TAO::BufferingConstraintPolicy_ptr _tao_objptr =
    TAO::BufferingConstraintPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::insert (
      _tao_any,
      TAO::BufferingConstraintPolicy::_tao_any_destructor,
      TAO::_tc_BufferingConstraintPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    TAO::BufferingConstraintPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<TAO::BufferingConstraintPolicy>::extract (
        _tao_any,
        TAO::BufferingConstraintPolicy::_tao_any_destructor,
        TAO::_tc_BufferingConstraintPolicy,
        _tao_elem
      );
}



#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        TAO::BufferingConstraint
      >;

  template class
    TAO::Any_Impl_T<
        TAO::BufferingConstraintPolicy
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        TAO::BufferingConstraint \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        TAO::BufferingConstraintPolicy \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

