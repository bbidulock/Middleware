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

#include "DynamicC.h"
#include "tao/Typecode.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_Dynamic_ParameterList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  38,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x44796e61), 
  ACE_NTOHL (0x6d69632f), 
  ACE_NTOHL (0x50617261), 
  ACE_NTOHL (0x6d657465), 
  ACE_NTOHL (0x724c6973), 
  ACE_NTOHL (0x743a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/Dynamic/ParameterList:1.0
    14,
  ACE_NTOHL (0x50617261), 
  ACE_NTOHL (0x6d657465), 
  ACE_NTOHL (0x724c6973), 
  ACE_NTOHL (0x74000000),  // name = ParameterList
    CORBA::tk_sequence, // typecode kind
  236, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
    220, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      34,
      ACE_NTOHL (0x49444c3a), 
      ACE_NTOHL (0x6f6d672e), 
      ACE_NTOHL (0x6f72672f), 
      ACE_NTOHL (0x44796e61), 
      ACE_NTOHL (0x6d69632f), 
      ACE_NTOHL (0x50617261), 
      ACE_NTOHL (0x6d657465), 
      ACE_NTOHL (0x723a312e), 
      ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/Dynamic/Parameter:1.0
            10,
      ACE_NTOHL (0x50617261), 
      ACE_NTOHL (0x6d657465), 
      ACE_NTOHL (0x72000000),  // name = Parameter
      2, // member count
            9,
      ACE_NTOHL (0x61726775), 
      ACE_NTOHL (0x6d656e74), 
      ACE_NTOHL (0x0),  // name = argument
            CORBA::tk_any,

      5,
      ACE_NTOHL (0x6d6f6465), 
      ACE_NTOHL (0x0),  // name = mode
            CORBA::tk_enum, // typecode kind
      116, // encapsulation length
TAO_ENCAP_BYTE_ORDER, // byte order
        36,
        ACE_NTOHL (0x49444c3a), 
        ACE_NTOHL (0x6f6d672e), 
        ACE_NTOHL (0x6f72672f), 
        ACE_NTOHL (0x434f5242), 
        ACE_NTOHL (0x412f5061), 
        ACE_NTOHL (0x72616d65), 
        ACE_NTOHL (0x7465724d), 
        ACE_NTOHL (0x6f64653a), 
        ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/ParameterMode:1.0
        14,
        ACE_NTOHL (0x50617261), 
        ACE_NTOHL (0x6d657465), 
        ACE_NTOHL (0x724d6f64), 
        ACE_NTOHL (0x65000000),  // name = ParameterMode
        3, // member count
        9,
        ACE_NTOHL (0x50415241), 
        ACE_NTOHL (0x4d5f494e), 
        ACE_NTOHL (0x0),  // name = PARAM_IN
        10,
        ACE_NTOHL (0x50415241), 
        ACE_NTOHL (0x4d5f4f55), 
        ACE_NTOHL (0x54000000),  // name = PARAM_OUT
        12,
        ACE_NTOHL (0x50415241), 
        ACE_NTOHL (0x4d5f494e), 
        ACE_NTOHL (0x4f555400),  // name = PARAM_INOUT
        

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_Dynamic_ParameterList (
    CORBA::tk_alias,
    sizeof (_oc_Dynamic_ParameterList),
    (char *) &_oc_Dynamic_ParameterList,
    0,
    sizeof (Dynamic::ParameterList)
  );

namespace Dynamic
{
  ::CORBA::TypeCode_ptr _tc_ParameterList =
    &_tc_TAO_tc_Dynamic_ParameterList;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_Dynamic_ContextList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x44796e61), 
  ACE_NTOHL (0x6d69632f), 
  ACE_NTOHL (0x436f6e74), 
  ACE_NTOHL (0x6578744c), 
  ACE_NTOHL (0x6973743a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/Dynamic/ContextList:1.0
    12,
  ACE_NTOHL (0x436f6e74), 
  ACE_NTOHL (0x6578744c), 
  ACE_NTOHL (0x69737400),  // name = ContextList
    CORBA::tk_alias, // typecode kind for typedefs
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    32,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f5374), 
    ACE_NTOHL (0x72696e67), 
    ACE_NTOHL (0x5365713a), 
    ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/StringSeq:1.0
        10,
    ACE_NTOHL (0x53747269), 
    ACE_NTOHL (0x6e675365), 
    ACE_NTOHL (0x71000000),  // name = StringSeq
        CORBA::tk_sequence, // typecode kind
    16, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_string, 
      0U, // string length
      0U,


};

static CORBA::TypeCode _tc_TAO_tc_Dynamic_ContextList (
    CORBA::tk_alias,
    sizeof (_oc_Dynamic_ContextList),
    (char *) &_oc_Dynamic_ContextList,
    0,
    sizeof (Dynamic::ContextList)
  );

namespace Dynamic
{
  ::CORBA::TypeCode_ptr _tc_ContextList =
    &_tc_TAO_tc_Dynamic_ContextList;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_Dynamic_ExceptionList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  38,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x44796e61), 
  ACE_NTOHL (0x6d69632f), 
  ACE_NTOHL (0x45786365), 
  ACE_NTOHL (0x7074696f), 
  ACE_NTOHL (0x6e4c6973), 
  ACE_NTOHL (0x743a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/Dynamic/ExceptionList:1.0
    14,
  ACE_NTOHL (0x45786365), 
  ACE_NTOHL (0x7074696f), 
  ACE_NTOHL (0x6e4c6973), 
  ACE_NTOHL (0x74000000),  // name = ExceptionList
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_TypeCode,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_Dynamic_ExceptionList (
    CORBA::tk_alias,
    sizeof (_oc_Dynamic_ExceptionList),
    (char *) &_oc_Dynamic_ExceptionList,
    0,
    sizeof (Dynamic::ExceptionList)
  );

namespace Dynamic
{
  ::CORBA::TypeCode_ptr _tc_ExceptionList =
    &_tc_TAO_tc_Dynamic_ExceptionList;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:290

static const CORBA::Long _oc_Dynamic_RequestContext[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  39,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x44796e61), 
  ACE_NTOHL (0x6d69632f), 
  ACE_NTOHL (0x52657175), 
  ACE_NTOHL (0x65737443), 
  ACE_NTOHL (0x6f6e7465), 
  ACE_NTOHL (0x78743a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:omg.org/Dynamic/RequestContext:1.0
    15,
  ACE_NTOHL (0x52657175), 
  ACE_NTOHL (0x65737443), 
  ACE_NTOHL (0x6f6e7465), 
  ACE_NTOHL (0x78740000),  // name = RequestContext
    CORBA::tk_alias, // typecode kind for typedefs
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    32,
    ACE_NTOHL (0x49444c3a), 
    ACE_NTOHL (0x6f6d672e), 
    ACE_NTOHL (0x6f72672f), 
    ACE_NTOHL (0x434f5242), 
    ACE_NTOHL (0x412f5374), 
    ACE_NTOHL (0x72696e67), 
    ACE_NTOHL (0x5365713a), 
    ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/StringSeq:1.0
        10,
    ACE_NTOHL (0x53747269), 
    ACE_NTOHL (0x6e675365), 
    ACE_NTOHL (0x71000000),  // name = StringSeq
        CORBA::tk_sequence, // typecode kind
    16, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_string, 
      0U, // string length
      0U,


};

static CORBA::TypeCode _tc_TAO_tc_Dynamic_RequestContext (
    CORBA::tk_alias,
    sizeof (_oc_Dynamic_RequestContext),
    (char *) &_oc_Dynamic_RequestContext,
    0,
    sizeof (Dynamic::RequestContext)
  );

namespace Dynamic
{
  ::CORBA::TypeCode_ptr _tc_RequestContext =
    &_tc_TAO_tc_Dynamic_RequestContext;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Dynamic::ParameterList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Dynamic::ParameterList>::insert_copy (
      _tao_any,
      Dynamic::ParameterList::_tao_any_destructor,
      Dynamic::_tc_ParameterList,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Dynamic::ParameterList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Dynamic::ParameterList>::insert (
      _tao_any,
      Dynamic::ParameterList::_tao_any_destructor,
      Dynamic::_tc_ParameterList,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Dynamic::ParameterList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const Dynamic::ParameterList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Dynamic::ParameterList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Dynamic::ParameterList>::extract (
        _tao_any,
        Dynamic::ParameterList::_tao_any_destructor,
        Dynamic::_tc_ParameterList,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Dynamic::ExceptionList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Dynamic::ExceptionList>::insert_copy (
      _tao_any,
      Dynamic::ExceptionList::_tao_any_destructor,
      Dynamic::_tc_ExceptionList,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Dynamic::ExceptionList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Dynamic::ExceptionList>::insert (
      _tao_any,
      Dynamic::ExceptionList::_tao_any_destructor,
      Dynamic::_tc_ExceptionList,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Dynamic::ExceptionList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const Dynamic::ExceptionList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Dynamic::ExceptionList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Dynamic::ExceptionList>::extract (
        _tao_any,
        Dynamic::ExceptionList::_tao_any_destructor,
        Dynamic::_tc_ExceptionList,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        Dynamic::ParameterList
      >;

  template class
    TAO::Any_Dual_Impl_T<
        Dynamic::ExceptionList
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        Dynamic::ParameterList \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        Dynamic::ExceptionList \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
