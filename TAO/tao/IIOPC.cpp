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


#include "tao/IIOPC.h"
#include "tao/Typecode.h"
#include "tao/Any_T.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "IIOPC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_IIOP_ListenPoint[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  33,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x49494f50),
  ACE_NTOHL (0x2f4c6973),
  ACE_NTOHL (0x74656e50),
  ACE_NTOHL (0x6f696e74),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/IIOP/ListenPoint:1.0
    12,
  ACE_NTOHL (0x4c697374),
  ACE_NTOHL (0x656e506f),
  ACE_NTOHL (0x696e7400),  // name = ListenPoint
  2, // member count
    5,
  ACE_NTOHL (0x686f7374),
  ACE_NTOHL (0x0),  // name = host
    CORBA::tk_string,
  0U, // string length
  5,
  ACE_NTOHL (0x706f7274),
  ACE_NTOHL (0x0),  // name = port
    CORBA::tk_ushort,

};

static CORBA::TypeCode _tc_TAO_tc_IIOP_ListenPoint (
    CORBA::tk_struct,
    sizeof (_oc_IIOP_ListenPoint),
    (char *) &_oc_IIOP_ListenPoint,
    0,
    sizeof (IIOP::ListenPoint)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (IIOP)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ListenPoint,
    &_tc_TAO_tc_IIOP_ListenPoint
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_cs.cpp:66

void IIOP::ListenPoint::_tao_any_destructor (void *_tao_void_pointer)
{
  ListenPoint *tmp = ACE_static_cast (ListenPoint*, _tao_void_pointer);
  delete tmp;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:274

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_Var_Var_T<
      ListenPoint
    >;

template class
  TAO_Out_T<
      ListenPoint,
      ListenPoint_var
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_Var_Var_T< \
      ListenPoint \
    >

# pragma instantiate \
  TAO_Out_T< \
      ListenPoint, \
      ListenPoint_var \
    >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:50

IIOP::ListenPointList::ListenPointList (void)
{}

IIOP::ListenPointList::ListenPointList (CORBA::ULong max)
  : TAO_Unbounded_Sequence<
        IIOP::ListenPoint
      >
    (max)
{}

IIOP::ListenPointList::ListenPointList (
    CORBA::ULong max,
    CORBA::ULong length,
    IIOP::ListenPoint *buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        IIOP::ListenPoint
      >
    (max, length, buffer, release)
{}

IIOP::ListenPointList::ListenPointList (const ListenPointList &seq)
  : TAO_Unbounded_Sequence<
        IIOP::ListenPoint
      >
    (seq)
{}

IIOP::ListenPointList::~ListenPointList (void)
{}

void IIOP::ListenPointList::_tao_any_destructor (void *_tao_void_pointer)
{
  ListenPointList *tmp = ACE_static_cast (ListenPointList*, _tao_void_pointer);
  delete tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_VarSeq_Var_T<
      ListenPointList,
      IIOP::ListenPoint
    >;

template class
  TAO_Seq_Out_T<
      ListenPointList,
      ListenPointList_var,
      IIOP::ListenPoint
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_VarSeq_Var_T< \
      ListenPointList, \
      IIOP::ListenPoint \
    >

# pragma instantiate \
  TAO_Seq_Out_T< \
      ListenPointList, \
      ListenPointList_var, \
      IIOP::ListenPoint \
    >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_IIOP_ListenPointList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  37,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x49494f50),
  ACE_NTOHL (0x2f4c6973),
  ACE_NTOHL (0x74656e50),
  ACE_NTOHL (0x6f696e74),
  ACE_NTOHL (0x4c697374),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/IIOP/ListenPointList:1.0
    16,
  ACE_NTOHL (0x4c697374),
  ACE_NTOHL (0x656e506f),
  ACE_NTOHL (0x696e744c),
  ACE_NTOHL (0x69737400),  // name = ListenPointList
    CORBA::tk_sequence, // typecode kind
  116, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
    100, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      33,
      ACE_NTOHL (0x49444c3a),
      ACE_NTOHL (0x6f6d672e),
      ACE_NTOHL (0x6f72672f),
      ACE_NTOHL (0x49494f50),
      ACE_NTOHL (0x2f4c6973),
      ACE_NTOHL (0x74656e50),
      ACE_NTOHL (0x6f696e74),
      ACE_NTOHL (0x3a312e30),
      ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/IIOP/ListenPoint:1.0
            12,
      ACE_NTOHL (0x4c697374),
      ACE_NTOHL (0x656e506f),
      ACE_NTOHL (0x696e7400),  // name = ListenPoint
      2, // member count
            5,
      ACE_NTOHL (0x686f7374),
      ACE_NTOHL (0x0),  // name = host
            CORBA::tk_string,
      0U, // string length
      5,
      ACE_NTOHL (0x706f7274),
      ACE_NTOHL (0x0),  // name = port
            CORBA::tk_ushort,


    0U,

};

static CORBA::TypeCode _tc_TAO_tc_IIOP_ListenPointList (
    CORBA::tk_alias,
    sizeof (_oc_IIOP_ListenPointList),
    (char *) &_oc_IIOP_ListenPointList,
    0,
    sizeof (IIOP::ListenPointList)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (IIOP)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ListenPointList,
    &_tc_TAO_tc_IIOP_ListenPointList
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_IIOP_BiDirIIOPServiceContext[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  45,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x49494f50),
  ACE_NTOHL (0x2f426944),
  ACE_NTOHL (0x69724949),
  ACE_NTOHL (0x4f505365),
  ACE_NTOHL (0x72766963),
  ACE_NTOHL (0x65436f6e),
  ACE_NTOHL (0x74657874),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/IIOP/BiDirIIOPServiceContext:1.0
    24,
  ACE_NTOHL (0x42694469),
  ACE_NTOHL (0x7249494f),
  ACE_NTOHL (0x50536572),
  ACE_NTOHL (0x76696365),
  ACE_NTOHL (0x436f6e74),
  ACE_NTOHL (0x65787400),  // name = BiDirIIOPServiceContext
  1, // member count
    14,
  ACE_NTOHL (0x6c697374),
  ACE_NTOHL (0x656e5f70),
  ACE_NTOHL (0x6f696e74),
  ACE_NTOHL (0x73000000),  // name = listen_points
    CORBA::tk_alias, // typecode kind for typedefs
  192, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    37,
    ACE_NTOHL (0x49444c3a),
    ACE_NTOHL (0x6f6d672e),
    ACE_NTOHL (0x6f72672f),
    ACE_NTOHL (0x49494f50),
    ACE_NTOHL (0x2f4c6973),
    ACE_NTOHL (0x74656e50),
    ACE_NTOHL (0x6f696e74),
    ACE_NTOHL (0x4c697374),
    ACE_NTOHL (0x3a312e30),
    ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/IIOP/ListenPointList:1.0
        16,
    ACE_NTOHL (0x4c697374),
    ACE_NTOHL (0x656e506f),
    ACE_NTOHL (0x696e744c),
    ACE_NTOHL (0x69737400),  // name = ListenPointList
        CORBA::tk_sequence, // typecode kind
    116, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_struct, // typecode kind
      100, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        33,
        ACE_NTOHL (0x49444c3a),
        ACE_NTOHL (0x6f6d672e),
        ACE_NTOHL (0x6f72672f),
        ACE_NTOHL (0x49494f50),
        ACE_NTOHL (0x2f4c6973),
        ACE_NTOHL (0x74656e50),
        ACE_NTOHL (0x6f696e74),
        ACE_NTOHL (0x3a312e30),
        ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/IIOP/ListenPoint:1.0
                12,
        ACE_NTOHL (0x4c697374),
        ACE_NTOHL (0x656e506f),
        ACE_NTOHL (0x696e7400),  // name = ListenPoint
        2, // member count
                5,
        ACE_NTOHL (0x686f7374),
        ACE_NTOHL (0x0),  // name = host
                CORBA::tk_string,
        0U, // string length
        5,
        ACE_NTOHL (0x706f7274),
        ACE_NTOHL (0x0),  // name = port
                CORBA::tk_ushort,


      0U,


};

static CORBA::TypeCode _tc_TAO_tc_IIOP_BiDirIIOPServiceContext (
    CORBA::tk_struct,
    sizeof (_oc_IIOP_BiDirIIOPServiceContext),
    (char *) &_oc_IIOP_BiDirIIOPServiceContext,
    0,
    sizeof (IIOP::BiDirIIOPServiceContext)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (IIOP)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_BiDirIIOPServiceContext,
    &_tc_TAO_tc_IIOP_BiDirIIOPServiceContext
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_cs.cpp:66

void IIOP::BiDirIIOPServiceContext::_tao_any_destructor (void *_tao_void_pointer)
{
  BiDirIIOPServiceContext *tmp = ACE_static_cast (BiDirIIOPServiceContext*, _tao_void_pointer);
  delete tmp;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:274

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_Var_Var_T<
      BiDirIIOPServiceContext
    >;

template class
  TAO_Out_T<
      BiDirIIOPServiceContext,
      BiDirIIOPServiceContext_var
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_Var_Var_T< \
      BiDirIIOPServiceContext \
    >

# pragma instantiate \
  TAO_Out_T< \
      BiDirIIOPServiceContext, \
      BiDirIIOPServiceContext_var \
    >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IIOP::ListenPoint &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IIOP::ListenPoint>::insert_copy (
      _tao_any,
      IIOP::ListenPoint::_tao_any_destructor,
      IIOP::_tc_ListenPoint,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IIOP::ListenPoint *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IIOP::ListenPoint>::insert (
      _tao_any,
      IIOP::ListenPoint::_tao_any_destructor,
      IIOP::_tc_ListenPoint,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IIOP::ListenPoint *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const IIOP::ListenPoint *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IIOP::ListenPoint *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IIOP::ListenPoint>::extract (
        _tao_any,
        IIOP::ListenPoint::_tao_any_destructor,
        IIOP::_tc_ListenPoint,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<IIOP::ListenPoint>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<IIOP::ListenPoint>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IIOP::ListenPointList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IIOP::ListenPointList>::insert_copy (
      _tao_any,
      IIOP::ListenPointList::_tao_any_destructor,
      IIOP::_tc_ListenPointList,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IIOP::ListenPointList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IIOP::ListenPointList>::insert (
      _tao_any,
      IIOP::ListenPointList::_tao_any_destructor,
      IIOP::_tc_ListenPointList,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IIOP::ListenPointList *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const IIOP::ListenPointList *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IIOP::ListenPointList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IIOP::ListenPointList>::extract (
        _tao_any,
        IIOP::ListenPointList::_tao_any_destructor,
        IIOP::_tc_ListenPointList,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<IIOP::ListenPointList>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<IIOP::ListenPointList>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IIOP::BiDirIIOPServiceContext &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IIOP::BiDirIIOPServiceContext>::insert_copy (
      _tao_any,
      IIOP::BiDirIIOPServiceContext::_tao_any_destructor,
      IIOP::_tc_BiDirIIOPServiceContext,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IIOP::BiDirIIOPServiceContext *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IIOP::BiDirIIOPServiceContext>::insert (
      _tao_any,
      IIOP::BiDirIIOPServiceContext::_tao_any_destructor,
      IIOP::_tc_BiDirIIOPServiceContext,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IIOP::BiDirIIOPServiceContext *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const IIOP::BiDirIIOPServiceContext *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IIOP::BiDirIIOPServiceContext *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IIOP::BiDirIIOPServiceContext>::extract (
        _tao_any,
        IIOP::BiDirIIOPServiceContext::_tao_any_destructor,
        IIOP::_tc_BiDirIIOPServiceContext,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<IIOP::BiDirIIOPServiceContext>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<IIOP::BiDirIIOPServiceContext>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:93

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IIOP::ListenPointList &_tao_sequence
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
    IIOP::ListenPointList &_tao_sequence
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
