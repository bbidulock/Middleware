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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:314


#include "DynamicC.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "DynamicC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Dynamic_Parameter[] =
{
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

};

static CORBA::TypeCode _tc_TAO_tc_Dynamic_Parameter (
    CORBA::tk_struct,
    sizeof (_oc_Dynamic_Parameter),
    (char *) &_oc_Dynamic_Parameter,
    0,
    sizeof (Dynamic::Parameter)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_Parameter,
    &_tc_TAO_tc_Dynamic_Parameter
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_cs.cpp:66

void Dynamic::Parameter::_tao_any_destructor (void *_tao_void_pointer)
{
  Parameter *tmp = ACE_static_cast (Parameter*, _tao_void_pointer);
  delete tmp;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:274

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_Var_Var_T<
      Parameter
    >;

template class
  TAO_Out_T<
      Parameter,
      Parameter_var
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_Var_Var_T< \
      Parameter \
    >

# pragma instantiate \
  TAO_Out_T< \
      Parameter, \
      Parameter_var \
    >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:50

Dynamic::ParameterList::ParameterList (void)
{}

Dynamic::ParameterList::ParameterList (CORBA::ULong max)
  : TAO_Unbounded_Sequence<
        Dynamic::Parameter
      >
    (max)
{}

Dynamic::ParameterList::ParameterList (
    CORBA::ULong max,
    CORBA::ULong length,
    Dynamic::Parameter *buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        Dynamic::Parameter
      >
    (max, length, buffer, release)
{}

Dynamic::ParameterList::ParameterList (const ParameterList &seq)
  : TAO_Unbounded_Sequence<
        Dynamic::Parameter
      >
    (seq)
{}

Dynamic::ParameterList::~ParameterList (void)
{}

void Dynamic::ParameterList::_tao_any_destructor (void *_tao_void_pointer)
{
  ParameterList *tmp = ACE_static_cast (ParameterList*, _tao_void_pointer);
  delete tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_VarSeq_Var_T<
      ParameterList,
      Dynamic::Parameter
    >;

template class
  TAO_Seq_Out_T<
      ParameterList,
      ParameterList_var,
      Dynamic::Parameter
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_VarSeq_Var_T< \
      ParameterList, \
      Dynamic::Parameter \
    >

# pragma instantiate \
  TAO_Seq_Out_T< \
      ParameterList, \
      ParameterList_var, \
      Dynamic::Parameter \
    >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ParameterList,
    &_tc_TAO_tc_Dynamic_ParameterList
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ContextList,
    &_tc_TAO_tc_Dynamic_ContextList
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_Dynamic_TypeCode[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  33,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x44796e61),
  ACE_NTOHL (0x6d69632f),
  ACE_NTOHL (0x54797065),
  ACE_NTOHL (0x436f6465),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/Dynamic/TypeCode:1.0
    9,
  ACE_NTOHL (0x54797065),
  ACE_NTOHL (0x436f6465),
  ACE_NTOHL (0x0),  // name = TypeCode
    CORBA::tk_TypeCode,

};

static CORBA::TypeCode _tc_TAO_tc_Dynamic_TypeCode (
    CORBA::tk_alias,
    sizeof (_oc_Dynamic_TypeCode),
    (char *) &_oc_Dynamic_TypeCode,
    0,
    sizeof (Dynamic::TypeCode)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_TypeCode,
    &_tc_TAO_tc_Dynamic_TypeCode
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:50

Dynamic::ExceptionList::ExceptionList (void)
{}

Dynamic::ExceptionList::ExceptionList (CORBA::ULong max)
  : TAO_Unbounded_Pseudo_Sequence<
        Dynamic::TypeCode,
        Dynamic::TypeCode_var
      >
    (max)
{}

Dynamic::ExceptionList::ExceptionList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::TypeCode_ptr *buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Pseudo_Sequence<
        Dynamic::TypeCode,
        Dynamic::TypeCode_var
      >
    (max, length, buffer, release)
{}

Dynamic::ExceptionList::ExceptionList (const ExceptionList &seq)
  : TAO_Unbounded_Pseudo_Sequence<
        Dynamic::TypeCode,
        Dynamic::TypeCode_var
      >
    (seq)
{}

Dynamic::ExceptionList::~ExceptionList (void)
{}

void Dynamic::ExceptionList::_tao_any_destructor (void *_tao_void_pointer)
{
  ExceptionList *tmp = ACE_static_cast (ExceptionList*, _tao_void_pointer);
  delete tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_VarSeq_Var_T<
      Dynamic::ExceptionList,
      TAO_Pseudo_Object_Manager<
          Dynamic::TypeCode,
          Dynamic::TypeCode_var
        >
    >;

template class
  TAO_Seq_Out_T<
      Dynamic::ExceptionList,
      Dynamic::ExceptionList_var,
      TAO_Pseudo_Object_Manager<
          Dynamic::TypeCode,
          Dynamic::TypeCode_var
        >
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_VarSeq_Var_T< \
      Dynamic::ExceptionList, \
      TAO_Pseudo_Object_Manager< \
          Dynamic::TypeCode, \
          Dynamic::TypeCode_var \
        > \
    >

# pragma instantiate \
  TAO_Seq_Out_T< \
      Dynamic::ExceptionList, \
      Dynamic::ExceptionList_var, \
      TAO_Pseudo_Object_Manager< \
          Dynamic::TypeCode, \
          Dynamic::TypeCode_var \
        > \
    >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

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
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_alias, // typecode kind for typedefs
    64, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      33,
      ACE_NTOHL (0x49444c3a),
      ACE_NTOHL (0x6f6d672e),
      ACE_NTOHL (0x6f72672f),
      ACE_NTOHL (0x44796e61),
      ACE_NTOHL (0x6d69632f),
      ACE_NTOHL (0x54797065),
      ACE_NTOHL (0x436f6465),
      ACE_NTOHL (0x3a312e30),
      ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/Dynamic/TypeCode:1.0
            9,
      ACE_NTOHL (0x54797065),
      ACE_NTOHL (0x436f6465),
      ACE_NTOHL (0x0),  // name = TypeCode
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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ExceptionList,
    &_tc_TAO_tc_Dynamic_ExceptionList
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

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

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_RequestContext,
    &_tc_TAO_tc_Dynamic_RequestContext
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Dynamic::Parameter &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Dynamic::Parameter>::insert_copy (
      _tao_any,
      Dynamic::Parameter::_tao_any_destructor,
      Dynamic::_tc_Parameter,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Dynamic::Parameter *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Dynamic::Parameter>::insert (
      _tao_any,
      Dynamic::Parameter::_tao_any_destructor,
      Dynamic::_tc_Parameter,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Dynamic::Parameter *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const Dynamic::Parameter *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Dynamic::Parameter *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Dynamic::Parameter>::extract (
        _tao_any,
        Dynamic::Parameter::_tao_any_destructor,
        Dynamic::_tc_Parameter,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<Dynamic::Parameter>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<Dynamic::Parameter>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

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
  return _tao_any >>= ACE_const_cast (
      const Dynamic::ParameterList *&,
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

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<Dynamic::ParameterList>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<Dynamic::ParameterList>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

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
  return _tao_any >>= ACE_const_cast (
      const Dynamic::ExceptionList *&,
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

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<Dynamic::ExceptionList>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<Dynamic::ExceptionList>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:93

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Dynamic::ParameterList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();

  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = 1;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }

      return _tao_marshal_flag;
    }

  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Dynamic::ParameterList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;

  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return 0;
        }

      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);

      // If length is 0 we return true.
      if (0 >= _tao_seq_len)
        {
          return 1;
        }

      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = 1;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }

      return _tao_marshal_flag;
    }

  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:93

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Dynamic::ExceptionList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();

  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = 1;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i].in ());
        }

      return _tao_marshal_flag;
    }

  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Dynamic::ExceptionList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;

  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return 0;
        }

      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);

      // If length is 0 we return true.
      if (0 >= _tao_seq_len)
        {
          return 1;
        }

      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = 1;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
        }

      return _tao_marshal_flag;
    }

  return 0;
}
