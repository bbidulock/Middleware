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


#include "StringSeqC.h"
#include "Any_T.h"
#include "CDR.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "StringSeqC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:50

CORBA::StringSeq::StringSeq (void)
{}

CORBA::StringSeq::StringSeq (CORBA::ULong max)
  : TAO_Unbounded_String_Sequence
    (max)
{}

CORBA::StringSeq::StringSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    char ** buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_String_Sequence
    (max, length, buffer, release)
{}

CORBA::StringSeq::StringSeq (const StringSeq &seq)
  : TAO_Unbounded_String_Sequence
    (seq)
{}

CORBA::StringSeq::~StringSeq (void)
{}

void CORBA::StringSeq::_tao_any_destructor (void *_tao_void_pointer)
{
  StringSeq *tmp = ACE_static_cast (StringSeq*, _tao_void_pointer);
  delete tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_MngSeq_Var_T<
      CORBA::StringSeq,
      TAO_SeqElem_String_Manager
    >;

template class
  TAO_Seq_Out_T<
      CORBA::StringSeq,
      CORBA::StringSeq_var,
      TAO_SeqElem_String_Manager
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_MngSeq_Var_T< \
      CORBA::StringSeq, \
      TAO_SeqElem_String_Manager \
    >

# pragma instantiate \
  TAO_Seq_Out_T< \
      CORBA::StringSeq, \
      CORBA::StringSeq_var, \
      TAO_SeqElem_String_Manager \
    >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_StringSeq[] =
{
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

static CORBA::TypeCode _tc_TAO_tc_CORBA_StringSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_StringSeq),
    (char *) &_oc_CORBA_StringSeq,
    0,
    sizeof (CORBA::StringSeq)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_StringSeq,
    &_tc_TAO_tc_CORBA_StringSeq
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_cs.cpp:50

CORBA::WStringSeq::WStringSeq (void)
{}

CORBA::WStringSeq::WStringSeq (CORBA::ULong max)
  : TAO_Unbounded_WString_Sequence
    (max)
{}

CORBA::WStringSeq::WStringSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::WChar ** buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_WString_Sequence
    (max, length, buffer, release)
{}

CORBA::WStringSeq::WStringSeq (const WStringSeq &seq)
  : TAO_Unbounded_WString_Sequence
    (seq)
{}

CORBA::WStringSeq::~WStringSeq (void)
{}

void CORBA::WStringSeq::_tao_any_destructor (void *_tao_void_pointer)
{
  WStringSeq *tmp = ACE_static_cast (WStringSeq*, _tao_void_pointer);
  delete tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_MngSeq_Var_T<
      CORBA::WStringSeq,
      TAO_SeqElem_WString_Manager
    >;

template class
  TAO_Seq_Out_T<
      CORBA::WStringSeq,
      CORBA::WStringSeq_var,
      TAO_SeqElem_WString_Manager
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_MngSeq_Var_T< \
      CORBA::WStringSeq, \
      TAO_SeqElem_WString_Manager \
    >

# pragma instantiate \
  TAO_Seq_Out_T< \
      CORBA::WStringSeq, \
      CORBA::WStringSeq_var, \
      TAO_SeqElem_WString_Manager \
    >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_WStringSeq[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  33,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f5753), 
  ACE_NTOHL (0x7472696e), 
  ACE_NTOHL (0x67536571), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/WStringSeq:1.0
    11,
  ACE_NTOHL (0x57537472), 
  ACE_NTOHL (0x696e6753), 
  ACE_NTOHL (0x65710000),  // name = WStringSeq
    CORBA::tk_sequence, // typecode kind
  16, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_wstring, 
    0U, // string length
    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_WStringSeq (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_WStringSeq),
    (char *) &_oc_CORBA_WStringSeq,
    0,
    sizeof (CORBA::WStringSeq)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (CORBA)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_WStringSeq,
    &_tc_TAO_tc_CORBA_WStringSeq
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::StringSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::StringSeq>::insert_copy (
      _tao_any,
      CORBA::StringSeq::_tao_any_destructor,
      CORBA::_tc_StringSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::StringSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::StringSeq>::insert (
      _tao_any,
      CORBA::StringSeq::_tao_any_destructor,
      CORBA::_tc_StringSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::StringSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::StringSeq *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::StringSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::StringSeq>::extract (
        _tao_any,
        CORBA::StringSeq::_tao_any_destructor,
        CORBA::_tc_StringSeq,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<CORBA::StringSeq>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<CORBA::StringSeq>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::WStringSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::WStringSeq>::insert_copy (
      _tao_any,
      CORBA::WStringSeq::_tao_any_destructor,
      CORBA::_tc_WStringSeq,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::WStringSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::WStringSeq>::insert (
      _tao_any,
      CORBA::WStringSeq::_tao_any_destructor,
      CORBA::_tc_WStringSeq,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::WStringSeq *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const CORBA::WStringSeq *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::WStringSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::WStringSeq>::extract (
        _tao_any,
        CORBA::WStringSeq::_tao_any_destructor,
        CORBA::_tc_WStringSeq,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<CORBA::WStringSeq>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<CORBA::WStringSeq>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:93

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::StringSeq &_tao_sequence
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
    CORBA::StringSeq &_tao_sequence
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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_cs.cpp:93

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::WStringSeq &_tao_sequence
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
    CORBA::WStringSeq &_tao_sequence
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

