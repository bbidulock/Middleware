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

#include "DynamicC.h"

#if !defined (__ACE_INLINE__)
#include "DynamicC.i"
#endif /* !defined INLINE */

#include "tao/StringSeqC.h"

static const CORBA::Long _oc_Dynamic_ParameterMode[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  30, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x724d6f64), ACE_NTOHL (0x653a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:Dynamic/ParameterMode:1.0
  14, ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x724d6f64), ACE_NTOHL (0x65000000),  // name = ParameterMode
  3, // member count
  9, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f494e), ACE_NTOHL (0x0),  // name = PARAM_IN
  10, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f4f55), ACE_NTOHL (0x54000000),  // name = PARAM_OUT
  12, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f494e), ACE_NTOHL (0x4f555400),  // name = PARAM_INOUT
};
static CORBA::TypeCode _tc_TAO_tc_Dynamic_ParameterMode (CORBA::tk_enum, sizeof (_oc_Dynamic_ParameterMode), (char *) &_oc_Dynamic_ParameterMode, 0, sizeof (Dynamic::ParameterMode));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ParameterMode, &_tc_TAO_tc_Dynamic_ParameterMode)
TAO_NAMESPACE_END
static const CORBA::Long _oc_Dynamic_Parameter[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  26, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x723a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:Dynamic/Parameter:1.0
  10, ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x72000000),  // name = Parameter
  2, // member count
  9, ACE_NTOHL (0x61726775), ACE_NTOHL (0x6d656e74), ACE_NTOHL (0x0),  // name = argument
  CORBA::tk_any,

  5, ACE_NTOHL (0x6d6f6465), ACE_NTOHL (0x0),  // name = mode
  CORBA::tk_enum, // typecode kind
  112, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    30, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x724d6f64), ACE_NTOHL (0x653a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:Dynamic/ParameterMode:1.0
    14, ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x724d6f64), ACE_NTOHL (0x65000000),  // name = ParameterMode
    3, // member count
    9, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f494e), ACE_NTOHL (0x0),  // name = PARAM_IN
    10, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f4f55), ACE_NTOHL (0x54000000),  // name = PARAM_OUT
    12, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f494e), ACE_NTOHL (0x4f555400),  // name = PARAM_INOUT

};
static CORBA::TypeCode _tc_TAO_tc_Dynamic_Parameter (CORBA::tk_struct, sizeof (_oc_Dynamic_Parameter), (char *) &_oc_Dynamic_Parameter, 0, sizeof (Dynamic::Parameter));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Parameter, &_tc_TAO_tc_Dynamic_Parameter)
TAO_NAMESPACE_END
void Dynamic::Parameter::_tao_any_destructor (void *x)
{
  Parameter *tmp = ACE_static_cast (Parameter*,x);
  delete tmp;
}


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_DYNAMIC_PARAMETERLIST_CS_)
#define __TAO_UNBOUNDED_SEQUENCE_DYNAMIC_PARAMETERLIST_CS_

  void
  Dynamic::_TAO_Unbounded_Sequence_Dynamic_ParameterList::_allocate_buffer (CORBA::ULong length)
  {
    Dynamic::Parameter* tmp = 0;
    tmp = _TAO_Unbounded_Sequence_Dynamic_ParameterList::allocbuf (length);

    if (this->buffer_ != 0)
    {
      Dynamic::Parameter *old = ACE_reinterpret_cast (Dynamic::Parameter *,this->buffer_);

      for (CORBA::ULong i = 0; i < this->length_; ++i)
        tmp[i] = old[i];

      if (this->release_)
        _TAO_Unbounded_Sequence_Dynamic_ParameterList::freebuf (old);

    }
    this->buffer_ = tmp;
  }

  void
  Dynamic::_TAO_Unbounded_Sequence_Dynamic_ParameterList::_deallocate_buffer (void)
  {
    if (this->buffer_ == 0 || this->release_ == 0)
      return;

    Dynamic::Parameter *tmp = ACE_reinterpret_cast (Dynamic::Parameter *,this->buffer_);

    _TAO_Unbounded_Sequence_Dynamic_ParameterList::freebuf (tmp);
    this->buffer_ = 0;
  }

  Dynamic::_TAO_Unbounded_Sequence_Dynamic_ParameterList::~_TAO_Unbounded_Sequence_Dynamic_ParameterList (void) // Dtor.
  {
    this->_deallocate_buffer ();
  }


#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_DYNAMIC_PARAMETERLIST_CS_)
#define _DYNAMIC_PARAMETERLIST_CS_

// *************************************************************
// Dynamic::ParameterList
// *************************************************************

Dynamic::ParameterList::ParameterList (void)
{}
Dynamic::ParameterList::ParameterList (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_Dynamic_ParameterList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<Dynamic::Parameter>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
Dynamic::ParameterList::ParameterList (CORBA::ULong max, CORBA::ULong length, Dynamic::Parameter *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_Dynamic_ParameterList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<Dynamic::Parameter>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
Dynamic::ParameterList::ParameterList (const ParameterList &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_Dynamic_ParameterList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<Dynamic::Parameter>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
Dynamic::ParameterList::~ParameterList (void) // dtor
{}
void Dynamic::ParameterList::_tao_any_destructor (void *x)
{
  ParameterList *tmp = ACE_static_cast (ParameterList*,x);
  delete tmp;
}


#endif /* end #if !defined */

static const CORBA::Long _oc_Dynamic_ParameterList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  30, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x724c6973), ACE_NTOHL (0x743a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:Dynamic/ParameterList:1.0
  14, ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x724c6973), ACE_NTOHL (0x74000000),  // name = ParameterList
  CORBA::tk_sequence, // typecode kind
  224, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
    208, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      26, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x723a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:Dynamic/Parameter:1.0
      10, ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x72000000),  // name = Parameter
      2, // member count
      9, ACE_NTOHL (0x61726775), ACE_NTOHL (0x6d656e74), ACE_NTOHL (0x0),  // name = argument
      CORBA::tk_any,

      5, ACE_NTOHL (0x6d6f6465), ACE_NTOHL (0x0),  // name = mode
      CORBA::tk_enum, // typecode kind
      112, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        30, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x724d6f64), ACE_NTOHL (0x653a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:Dynamic/ParameterMode:1.0
        14, ACE_NTOHL (0x50617261), ACE_NTOHL (0x6d657465), ACE_NTOHL (0x724d6f64), ACE_NTOHL (0x65000000),  // name = ParameterMode
        3, // member count
        9, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f494e), ACE_NTOHL (0x0),  // name = PARAM_IN
        10, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f4f55), ACE_NTOHL (0x54000000),  // name = PARAM_OUT
        12, ACE_NTOHL (0x50415241), ACE_NTOHL (0x4d5f494e), ACE_NTOHL (0x4f555400),  // name = PARAM_INOUT


    0U,

};
static CORBA::TypeCode _tc_TAO_tc_Dynamic_ParameterList (CORBA::tk_alias, sizeof (_oc_Dynamic_ParameterList), (char *) &_oc_Dynamic_ParameterList, 0, sizeof (Dynamic::ParameterList));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ParameterList, &_tc_TAO_tc_Dynamic_ParameterList)
TAO_NAMESPACE_END
static const CORBA::Long _oc_Dynamic_ContextList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  28, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x436f6e74), ACE_NTOHL (0x6578744c), ACE_NTOHL (0x6973743a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:Dynamic/ContextList:1.0
  12, ACE_NTOHL (0x436f6e74), ACE_NTOHL (0x6578744c), ACE_NTOHL (0x69737400),  // name = ContextList
  CORBA::tk_alias, // typecode kind for typedefs
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    32, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x434f5242), ACE_NTOHL (0x412f5374), ACE_NTOHL (0x72696e67), ACE_NTOHL (0x5365713a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/StringSeq:1.0
    10, ACE_NTOHL (0x53747269), ACE_NTOHL (0x6e675365), ACE_NTOHL (0x71000000),  // name = StringSeq
    CORBA::tk_sequence, // typecode kind
    16, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_string,
      0U, // string length
      0U,


};
static CORBA::TypeCode _tc_TAO_tc_Dynamic_ContextList (CORBA::tk_alias, sizeof (_oc_Dynamic_ContextList), (char *) &_oc_Dynamic_ContextList, 0, sizeof (Dynamic::ContextList));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ContextList, &_tc_TAO_tc_Dynamic_ContextList)
TAO_NAMESPACE_END
static const CORBA::Long _oc_Dynamic_TypeCode[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  25, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x54797065), ACE_NTOHL (0x436f6465), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:Dynamic/TypeCode:1.0
  9, ACE_NTOHL (0x54797065), ACE_NTOHL (0x436f6465), ACE_NTOHL (0x0),  // name = TypeCode
  CORBA::tk_TypeCode,

};
static CORBA::TypeCode _tc_TAO_tc_Dynamic_TypeCode (CORBA::tk_alias, sizeof (_oc_Dynamic_TypeCode), (char *) &_oc_Dynamic_TypeCode, 0, sizeof (Dynamic::TypeCode));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_TypeCode, &_tc_TAO_tc_Dynamic_TypeCode)
TAO_NAMESPACE_END

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_DYNAMIC_EXCEPTIONLIST_CS_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_DYNAMIC_EXCEPTIONLIST_CS_

  // The Base_Sequence functions, please see tao/Sequence.h
  void
  Dynamic::_TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList::_allocate_buffer (CORBA::ULong length)
  {
    CORBA::TypeCode **tmp = 0;
    tmp = _TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList::allocbuf (length);

    if (this->buffer_ != 0)
    {
      CORBA::TypeCode **old = ACE_reinterpret_cast (CORBA::TypeCode**, this->buffer_);
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        if (!this->release_)
          tmp[i] = CORBA::TypeCode::_duplicate (old[i]);
        else
          tmp[i] = old[i];

      if (this->release_)
        delete[] old;

    }
    this->buffer_ = tmp;
  }

  void
  Dynamic::_TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList::_deallocate_buffer (void)
  {
    if (this->buffer_ == 0 || this->release_ == 0)
      return;
    CORBA::TypeCode **tmp = ACE_reinterpret_cast (CORBA::TypeCode**, this->buffer_);
    for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = CORBA::TypeCode::_nil ();
    }
    _TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList::freebuf (tmp);
    this->buffer_ = 0;
  }

  Dynamic::_TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList::~_TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList (void)
  {
    this->_deallocate_buffer ();
  }

  void
  Dynamic::_TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList::_shrink_buffer (CORBA::ULong nl, CORBA::ULong ol)
  {
    CORBA::TypeCode **tmp = ACE_reinterpret_cast (CORBA::TypeCode**, this->buffer_);

    for (CORBA::ULong i = nl; i < ol; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = CORBA::TypeCode::_nil ();
    }
  }

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_DYNAMIC_EXCEPTIONLIST_CS_)
#define _DYNAMIC_EXCEPTIONLIST_CS_

// *************************************************************
// Dynamic::ExceptionList
// *************************************************************

Dynamic::ExceptionList::ExceptionList (void)
{}
Dynamic::ExceptionList::ExceptionList (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Pseudo_Sequence<CORBA::TypeCode,CORBA::TypeCode_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
Dynamic::ExceptionList::ExceptionList (CORBA::ULong max, CORBA::ULong length, CORBA::TypeCode_ptr *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Pseudo_Sequence<CORBA::TypeCode,CORBA::TypeCode_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
Dynamic::ExceptionList::ExceptionList (const ExceptionList &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_Dynamic_ExceptionList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Pseudo_Sequence<CORBA::TypeCode,CORBA::TypeCode_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
Dynamic::ExceptionList::~ExceptionList (void) // dtor
{}
void Dynamic::ExceptionList::_tao_any_destructor (void *x)
{
  ExceptionList *tmp = ACE_static_cast (ExceptionList*,x);
  delete tmp;
}


#endif /* end #if !defined */

static const CORBA::Long _oc_Dynamic_ExceptionList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  30, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x45786365), ACE_NTOHL (0x7074696f), ACE_NTOHL (0x6e4c6973), ACE_NTOHL (0x743a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:Dynamic/ExceptionList:1.0
  14, ACE_NTOHL (0x45786365), ACE_NTOHL (0x7074696f), ACE_NTOHL (0x6e4c6973), ACE_NTOHL (0x74000000),  // name = ExceptionList
  CORBA::tk_sequence, // typecode kind
  72, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_alias, // typecode kind for typedefs
    56, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      25, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x54797065), ACE_NTOHL (0x436f6465), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:Dynamic/TypeCode:1.0
      9, ACE_NTOHL (0x54797065), ACE_NTOHL (0x436f6465), ACE_NTOHL (0x0),  // name = TypeCode
      CORBA::tk_TypeCode,


    0U,

};
static CORBA::TypeCode _tc_TAO_tc_Dynamic_ExceptionList (CORBA::tk_alias, sizeof (_oc_Dynamic_ExceptionList), (char *) &_oc_Dynamic_ExceptionList, 0, sizeof (Dynamic::ExceptionList));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ExceptionList, &_tc_TAO_tc_Dynamic_ExceptionList)
TAO_NAMESPACE_END
static const CORBA::Long _oc_Dynamic_RequestContext[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  31, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x44796e61), ACE_NTOHL (0x6d69632f), ACE_NTOHL (0x52657175), ACE_NTOHL (0x65737443), ACE_NTOHL (0x6f6e7465), ACE_NTOHL (0x78743a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:Dynamic/RequestContext:1.0
  15, ACE_NTOHL (0x52657175), ACE_NTOHL (0x65737443), ACE_NTOHL (0x6f6e7465), ACE_NTOHL (0x78740000),  // name = RequestContext
  CORBA::tk_alias, // typecode kind for typedefs
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    32, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x434f5242), ACE_NTOHL (0x412f5374), ACE_NTOHL (0x72696e67), ACE_NTOHL (0x5365713a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/StringSeq:1.0
    10, ACE_NTOHL (0x53747269), ACE_NTOHL (0x6e675365), ACE_NTOHL (0x71000000),  // name = StringSeq
    CORBA::tk_sequence, // typecode kind
    16, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      CORBA::tk_string,
      0U, // string length
      0U,


};
static CORBA::TypeCode _tc_TAO_tc_Dynamic_RequestContext (CORBA::tk_alias, sizeof (_oc_Dynamic_RequestContext), (char *) &_oc_Dynamic_RequestContext, 0, sizeof (Dynamic::RequestContext));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (Dynamic)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_RequestContext, &_tc_TAO_tc_Dynamic_RequestContext)
TAO_NAMESPACE_END
void operator<<= (CORBA::Any &_tao_any, Dynamic::ParameterMode _tao_elem)
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (
      Dynamic::_tc_ParameterMode,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin ()
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, Dynamic::ParameterMode &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    CORBA::Boolean result =
      type->equivalent (Dynamic::_tc_ParameterMode, ACE_TRY_ENV);
    ACE_TRY_CHECK;

    if (!result)
      {
        return 0;
      }

    TAO_InputCDR stream (
        _tao_any._tao_get_cdr (),
        _tao_any._tao_byte_order ()
      );
    if (stream >> _tao_elem)
    {
      return 1;
    }
  }
  ACE_CATCHANY
  {
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

void operator<<= (CORBA::Any &_tao_any, const Dynamic::Parameter &_tao_elem) // copying
{
  TAO_OutputCDR stream;
  stream << _tao_elem;
  _tao_any._tao_replace (
      Dynamic::_tc_Parameter,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin ()
    );
}

void operator<<= (CORBA::Any &_tao_any, Dynamic::Parameter *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      Dynamic::_tc_Parameter,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      Dynamic::Parameter::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, Dynamic::Parameter *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(const Dynamic::Parameter*&,_tao_elem);
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const Dynamic::Parameter *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    CORBA::Boolean result =
      type->equivalent (Dynamic::_tc_Parameter, ACE_TRY_ENV);
    ACE_TRY_CHECK;

    if (!result)
      {
        return 0;
      }

    if (_tao_any.any_owns_data ())
    {
      _tao_elem = ACE_static_cast(
          const Dynamic::Parameter*,
          _tao_any.value ()
        );
      return 1;
    }
    else
    {
      Dynamic::Parameter *tmp;
      ACE_NEW_RETURN (tmp, Dynamic::Parameter, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            Dynamic::_tc_Parameter,
            1,
            ACE_static_cast (void *, tmp),
            Dynamic::Parameter::_tao_any_destructor
          );
        _tao_elem = tmp;
        return 1;
      }
      else
      {
        delete tmp;
      }
    }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  return 0;
}

void operator<<= (
    CORBA::Any &_tao_any,
    const Dynamic::ParameterList &_tao_elem
  ) // copying
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
  {
    _tao_any._tao_replace (
        Dynamic::_tc_ParameterList,
        TAO_ENCAP_BYTE_ORDER,
        stream.begin ()
      );
  }
}

void operator<<= (CORBA::Any &_tao_any, Dynamic::ParameterList *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      Dynamic::_tc_ParameterList,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      Dynamic::ParameterList::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, Dynamic::ParameterList *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const Dynamic::ParameterList*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const Dynamic::ParameterList *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    CORBA::Boolean result =
      type->equivalent (Dynamic::_tc_ParameterList, ACE_TRY_ENV);
    ACE_TRY_CHECK;

    if (!result)
      {
        return 0;
      }

    if (_tao_any.any_owns_data ())
    {
      _tao_elem = ACE_static_cast(
          const Dynamic::ParameterList*,
          _tao_any.value ()
        );
      return 1;
    }
    else
    {
      Dynamic::ParameterList *tmp;
      ACE_NEW_RETURN (tmp, Dynamic::ParameterList, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            Dynamic::_tc_ParameterList,
            1,
            ACE_static_cast (void *, tmp),
            Dynamic::ParameterList::_tao_any_destructor
          );
        _tao_elem = tmp;
        return 1;
      }
      else
      {
        delete tmp;
      }
    }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  return 0;
}

void operator<<= (
    CORBA::Any &_tao_any,
    const Dynamic::ExceptionList &_tao_elem
  ) // copying
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
  {
    _tao_any._tao_replace (
        Dynamic::_tc_ExceptionList,
        TAO_ENCAP_BYTE_ORDER,
        stream.begin ()
      );
  }
}

void operator<<= (CORBA::Any &_tao_any, Dynamic::ExceptionList *_tao_elem) // non copying
{
  TAO_OutputCDR stream;
  stream << *_tao_elem;
  _tao_any._tao_replace (
      Dynamic::_tc_ExceptionList,
      TAO_ENCAP_BYTE_ORDER,
      stream.begin (),
      1,
      _tao_elem,
      Dynamic::ExceptionList::_tao_any_destructor
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, Dynamic::ExceptionList *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(
      const Dynamic::ExceptionList*&,
      _tao_elem
    );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const Dynamic::ExceptionList *&_tao_elem)
{
  _tao_elem = 0;
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    CORBA::Boolean result =
      type->equivalent (Dynamic::_tc_ExceptionList, ACE_TRY_ENV);
    ACE_TRY_CHECK;

    if (!result)
      {
        return 0;
      }

    if (_tao_any.any_owns_data ())
    {
      _tao_elem = ACE_static_cast(
          const Dynamic::ExceptionList*,
          _tao_any.value ()
        );
      return 1;
    }
    else
    {
      Dynamic::ExceptionList *tmp;
      ACE_NEW_RETURN (tmp, Dynamic::ExceptionList, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      if (stream >> *tmp)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            Dynamic::_tc_ExceptionList,
            1,
            ACE_static_cast (void *, tmp),
            Dynamic::ExceptionList::_tao_any_destructor
          );
        _tao_elem = tmp;
        return 1;
      }
      else
      {
        delete tmp;
      }
    }
  }
  ACE_CATCHANY
  {
  }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Dynamic::ParameterList &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm << _tao_sequence[i]);
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Dynamic::ParameterList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // If length is 0 we return true.
    if (0 >= _tao_seq_len)
      return 1;
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm >> _tao_sequence[i]);
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Dynamic::ExceptionList &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm << _tao_sequence[i].in ());
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Dynamic::ExceptionList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // If length is 0 we return true.
    if (0 >= _tao_seq_len)
      return 1;
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

