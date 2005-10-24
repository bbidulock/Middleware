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

// TAO_IDL - Generated from
// be\be_codegen.cpp:277


#include "CodecFactory.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "ace/OS_NS_string.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for IOP::Codec.

IOP::Codec_ptr
TAO::Objref_Traits<IOP::Codec>::duplicate (
    IOP::Codec_ptr p
  )
{
  return IOP::Codec::_duplicate (p);
}

void
TAO::Objref_Traits<IOP::Codec>::release (
    IOP::Codec_ptr p
  )
{
  CORBA::release (p);
}

IOP::Codec_ptr
TAO::Objref_Traits<IOP::Codec>::nil (void)
{
  return IOP::Codec::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<IOP::Codec>::marshal (
    IOP::Codec_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from
// be\be_visitor_exception/exception_cs.cpp:63

IOP::Codec::InvalidTypeForEncoding::InvalidTypeForEncoding (void)
  : ::CORBA::UserException (
        "IDL:omg.org/IOP/Codec/InvalidTypeForEncoding:1.0",
        "InvalidTypeForEncoding"
      )
{
}

IOP::Codec::InvalidTypeForEncoding::~InvalidTypeForEncoding (void)
{
}

IOP::Codec::InvalidTypeForEncoding::InvalidTypeForEncoding (const ::IOP::Codec::InvalidTypeForEncoding &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IOP::Codec::InvalidTypeForEncoding&
IOP::Codec::InvalidTypeForEncoding::operator= (const ::IOP::Codec::InvalidTypeForEncoding &_tao_excp)
{
  this->ACE_NESTED_CLASS ( ::CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void IOP::Codec::InvalidTypeForEncoding::_tao_any_destructor (void *_tao_void_pointer)
{
  InvalidTypeForEncoding *_tao_tmp_pointer =
    static_cast<InvalidTypeForEncoding *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::Codec::InvalidTypeForEncoding *
IOP::Codec::InvalidTypeForEncoding::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<InvalidTypeForEncoding *> (_tao_excp);
}

const IOP::Codec::InvalidTypeForEncoding *
IOP::Codec::InvalidTypeForEncoding::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const InvalidTypeForEncoding *> (_tao_excp);
}

::CORBA::Exception *IOP::Codec::InvalidTypeForEncoding::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::Codec::InvalidTypeForEncoding, 0);
  return retval;
}

::CORBA::Exception *
IOP::Codec::InvalidTypeForEncoding::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::IOP::Codec::InvalidTypeForEncoding (*this),
      0
    );
  return result;
}

void IOP::Codec::InvalidTypeForEncoding::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::Codec::InvalidTypeForEncoding::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void IOP::Codec::InvalidTypeForEncoding::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr IOP::Codec::InvalidTypeForEncoding::_tao_type (void) const
{
  return ::IOP::Codec::_tc_InvalidTypeForEncoding;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const * const _tao_fields_IOP_Codec_InvalidTypeForEncoding = 0;
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_Codec_InvalidTypeForEncoding (
    ::CORBA::tk_except,
    "IDL:omg.org/IOP/Codec/InvalidTypeForEncoding:1.0",
    "InvalidTypeForEncoding",
    _tao_fields_IOP_Codec_InvalidTypeForEncoding,
    0);

::CORBA::TypeCode_ptr const IOP::Codec::_tc_InvalidTypeForEncoding =
  &_tao_tc_IOP_Codec_InvalidTypeForEncoding;

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

IOP::Codec::FormatMismatch::FormatMismatch (void)
  : ::CORBA::UserException (
        "IDL:omg.org/IOP/Codec/FormatMismatch:1.0",
        "FormatMismatch"
      )
{
}

IOP::Codec::FormatMismatch::~FormatMismatch (void)
{
}

IOP::Codec::FormatMismatch::FormatMismatch (const ::IOP::Codec::FormatMismatch &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IOP::Codec::FormatMismatch&
IOP::Codec::FormatMismatch::operator= (const ::IOP::Codec::FormatMismatch &_tao_excp)
{
  this->ACE_NESTED_CLASS ( ::CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void IOP::Codec::FormatMismatch::_tao_any_destructor (void *_tao_void_pointer)
{
  FormatMismatch *_tao_tmp_pointer =
    static_cast<FormatMismatch *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::Codec::FormatMismatch *
IOP::Codec::FormatMismatch::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<FormatMismatch *> (_tao_excp);
}

const IOP::Codec::FormatMismatch *
IOP::Codec::FormatMismatch::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const FormatMismatch *> (_tao_excp);
}

::CORBA::Exception *IOP::Codec::FormatMismatch::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::Codec::FormatMismatch, 0);
  return retval;
}

::CORBA::Exception *
IOP::Codec::FormatMismatch::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::IOP::Codec::FormatMismatch (*this),
      0
    );
  return result;
}

void IOP::Codec::FormatMismatch::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::Codec::FormatMismatch::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void IOP::Codec::FormatMismatch::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr IOP::Codec::FormatMismatch::_tao_type (void) const
{
  return ::IOP::Codec::_tc_FormatMismatch;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const * const _tao_fields_IOP_Codec_FormatMismatch = 0;
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_Codec_FormatMismatch (
    ::CORBA::tk_except,
    "IDL:omg.org/IOP/Codec/FormatMismatch:1.0",
    "FormatMismatch",
    _tao_fields_IOP_Codec_FormatMismatch,
    0);
  
::CORBA::TypeCode_ptr const IOP::Codec::_tc_FormatMismatch =
  &_tao_tc_IOP_Codec_FormatMismatch;

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

IOP::Codec::TypeMismatch::TypeMismatch (void)
  : ::CORBA::UserException (
        "IDL:omg.org/IOP/Codec/TypeMismatch:1.0",
        "TypeMismatch"
      )
{
}

IOP::Codec::TypeMismatch::~TypeMismatch (void)
{
}

IOP::Codec::TypeMismatch::TypeMismatch (const ::IOP::Codec::TypeMismatch &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IOP::Codec::TypeMismatch&
IOP::Codec::TypeMismatch::operator= (const ::IOP::Codec::TypeMismatch &_tao_excp)
{
  this->ACE_NESTED_CLASS ( ::CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void IOP::Codec::TypeMismatch::_tao_any_destructor (void *_tao_void_pointer)
{
  TypeMismatch *_tao_tmp_pointer =
    static_cast<TypeMismatch *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::Codec::TypeMismatch *
IOP::Codec::TypeMismatch::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<TypeMismatch *> (_tao_excp);
}

const IOP::Codec::TypeMismatch *
IOP::Codec::TypeMismatch::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const TypeMismatch *> (_tao_excp);
}

::CORBA::Exception *IOP::Codec::TypeMismatch::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::Codec::TypeMismatch, 0);
  return retval;
}

::CORBA::Exception *
IOP::Codec::TypeMismatch::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::IOP::Codec::TypeMismatch (*this),
      0
    );
  return result;
}

void IOP::Codec::TypeMismatch::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::Codec::TypeMismatch::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void IOP::Codec::TypeMismatch::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr IOP::Codec::TypeMismatch::_tao_type (void) const
{
  return ::IOP::Codec::_tc_TypeMismatch;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const * const _tao_fields_IOP_Codec_TypeMismatch = 0;
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_Codec_TypeMismatch (
    ::CORBA::tk_except,
    "IDL:omg.org/IOP/Codec/TypeMismatch:1.0",
    "TypeMismatch",
    _tao_fields_IOP_Codec_TypeMismatch,
    0);
  
::CORBA::TypeCode_ptr const IOP::Codec::_tc_TypeMismatch =
  &_tao_tc_IOP_Codec_TypeMismatch;

IOP::Codec::Codec (void)
{}

IOP::Codec::~Codec (void)
{}

IOP::Codec_ptr
IOP::Codec::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return Codec::_duplicate (
      dynamic_cast<Codec_ptr> (_tao_objref)
    );
}

IOP::Codec_ptr
IOP::Codec::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return Codec::_duplicate (
      dynamic_cast<Codec_ptr> (_tao_objref)
    );
}

IOP::Codec_ptr
IOP::Codec::_duplicate (Codec_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
IOP::Codec::_tao_release (Codec_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
IOP::Codec::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/IOP/Codec:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* IOP::Codec::_interface_repository_id (void) const
{
  return "IDL:omg.org/IOP/Codec:1.0";
}

::CORBA::Boolean
IOP::Codec::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_IOP_Codec (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/IOP/Codec:1.0",
    "Codec");
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_Codec =
    &_tao_tc_IOP_Codec;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_EncodingFormat (
    ::CORBA::tk_alias,
    "IDL:omg.org/IOP/EncodingFormat:1.0",
    "EncodingFormat",
    &CORBA::_tc_short);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_EncodingFormat =
    &_tao_tc_IOP_EncodingFormat;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const _tao_fields_IOP_Encoding[] =
  {
    { "format", &IOP::_tc_EncodingFormat },
    { "major_version", &CORBA::_tc_octet },
    { "minor_version", &CORBA::_tc_octet }
    
  };
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_Encoding (
    ::CORBA::tk_struct,
    "IDL:omg.org/IOP/Encoding:1.0",
    "Encoding",
    _tao_fields_IOP_Encoding,
    3);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_Encoding =
    &_tao_tc_IOP_Encoding;
}



// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
IOP::Encoding::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  Encoding *_tao_tmp_pointer =
    static_cast<Encoding *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const _tao_fields_IOP_Encoding_1_2[] =
  {
    { "format", &IOP::_tc_EncodingFormat },
    { "major_version", &CORBA::_tc_octet },
    { "minor_version", &CORBA::_tc_octet },
    { "char_codeset", &CONV_FRAME::_tc_CodeSetId },
    { "wchar_codeset", &CONV_FRAME::_tc_CodeSetId }
    
  };
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_Encoding_1_2 (
    ::CORBA::tk_struct,
    "IDL:omg.org/IOP/Encoding_1_2:1.0",
    "Encoding_1_2",
    _tao_fields_IOP_Encoding_1_2,
    5);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_Encoding_1_2 =
    &_tao_tc_IOP_Encoding_1_2;
}



// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
IOP::Encoding_1_2::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  Encoding_1_2 *_tao_tmp_pointer =
    static_cast<Encoding_1_2 *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for IOP::CodecFactory.

IOP::CodecFactory_ptr
TAO::Objref_Traits<IOP::CodecFactory>::duplicate (
    IOP::CodecFactory_ptr p
  )
{
  return IOP::CodecFactory::_duplicate (p);
}

void
TAO::Objref_Traits<IOP::CodecFactory>::release (
    IOP::CodecFactory_ptr p
  )
{
  CORBA::release (p);
}

IOP::CodecFactory_ptr
TAO::Objref_Traits<IOP::CodecFactory>::nil (void)
{
  return IOP::CodecFactory::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<IOP::CodecFactory>::marshal (
    IOP::CodecFactory_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

IOP::CodecFactory::UnknownEncoding::UnknownEncoding (void)
  : ::CORBA::UserException (
        "IDL:omg.org/IOP/CodecFactory/UnknownEncoding:1.0",
        "UnknownEncoding"
      )
{
}

IOP::CodecFactory::UnknownEncoding::~UnknownEncoding (void)
{
}

IOP::CodecFactory::UnknownEncoding::UnknownEncoding (const ::IOP::CodecFactory::UnknownEncoding &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

IOP::CodecFactory::UnknownEncoding&
IOP::CodecFactory::UnknownEncoding::operator= (const ::IOP::CodecFactory::UnknownEncoding &_tao_excp)
{
  this->ACE_NESTED_CLASS ( ::CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

void IOP::CodecFactory::UnknownEncoding::_tao_any_destructor (void *_tao_void_pointer)
{
  UnknownEncoding *_tao_tmp_pointer =
    static_cast<UnknownEncoding *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::CodecFactory::UnknownEncoding *
IOP::CodecFactory::UnknownEncoding::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<UnknownEncoding *> (_tao_excp);
}

const IOP::CodecFactory::UnknownEncoding *
IOP::CodecFactory::UnknownEncoding::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const UnknownEncoding *> (_tao_excp);
}

::CORBA::Exception *IOP::CodecFactory::UnknownEncoding::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::CodecFactory::UnknownEncoding, 0);
  return retval;
}

::CORBA::Exception *
IOP::CodecFactory::UnknownEncoding::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::IOP::CodecFactory::UnknownEncoding (*this),
      0
    );
  return result;
}

void IOP::CodecFactory::UnknownEncoding::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::CodecFactory::UnknownEncoding::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void IOP::CodecFactory::UnknownEncoding::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr IOP::CodecFactory::UnknownEncoding::_tao_type (void) const
{
  return ::IOP::CodecFactory::_tc_UnknownEncoding;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const * const _tao_fields_IOP_CodecFactory_UnknownEncoding = 0;
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_CodecFactory_UnknownEncoding (
    ::CORBA::tk_except,
    "IDL:omg.org/IOP/CodecFactory/UnknownEncoding:1.0",
    "UnknownEncoding",
    _tao_fields_IOP_CodecFactory_UnknownEncoding,
    0);
  
::CORBA::TypeCode_ptr const IOP::CodecFactory::_tc_UnknownEncoding =
  &_tao_tc_IOP_CodecFactory_UnknownEncoding;

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

IOP::CodecFactory::UnsupportedCodeset::UnsupportedCodeset (void)
  : ::CORBA::UserException (
        "IDL:omg.org/IOP/CodecFactory/UnsupportedCodeset:1.0",
        "UnsupportedCodeset"
      )
{
}

IOP::CodecFactory::UnsupportedCodeset::~UnsupportedCodeset (void)
{
}

IOP::CodecFactory::UnsupportedCodeset::UnsupportedCodeset (const ::IOP::CodecFactory::UnsupportedCodeset &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
  this->codeset = _tao_excp.codeset;
}

IOP::CodecFactory::UnsupportedCodeset&
IOP::CodecFactory::UnsupportedCodeset::operator= (const ::IOP::CodecFactory::UnsupportedCodeset &_tao_excp)
{
  this->ACE_NESTED_CLASS ( ::CORBA, UserException)::operator= (_tao_excp);
  this->codeset = _tao_excp.codeset;
  return *this;
}

void IOP::CodecFactory::UnsupportedCodeset::_tao_any_destructor (void *_tao_void_pointer)
{
  UnsupportedCodeset *_tao_tmp_pointer =
    static_cast<UnsupportedCodeset *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

IOP::CodecFactory::UnsupportedCodeset *
IOP::CodecFactory::UnsupportedCodeset::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<UnsupportedCodeset *> (_tao_excp);
}

const IOP::CodecFactory::UnsupportedCodeset *
IOP::CodecFactory::UnsupportedCodeset::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const UnsupportedCodeset *> (_tao_excp);
}

::CORBA::Exception *IOP::CodecFactory::UnsupportedCodeset::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::IOP::CodecFactory::UnsupportedCodeset, 0);
  return retval;
}

::CORBA::Exception *
IOP::CodecFactory::UnsupportedCodeset::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::IOP::CodecFactory::UnsupportedCodeset (*this),
      0
    );
  return result;
}

void IOP::CodecFactory::UnsupportedCodeset::_raise (void) const
{
  TAO_RAISE (*this);
}

void IOP::CodecFactory::UnsupportedCodeset::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void IOP::CodecFactory::UnsupportedCodeset::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// be\be_visitor_exception/exception_ctor.cpp:66

IOP::CodecFactory::UnsupportedCodeset::UnsupportedCodeset (
    ::CONV_FRAME::CodeSetId _tao_codeset
  )
  : ::CORBA::UserException (
        "IDL:omg.org/IOP/CodecFactory/UnsupportedCodeset:1.0",
        "UnsupportedCodeset"
      )
{
  this->codeset = _tao_codeset;
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr IOP::CodecFactory::UnsupportedCodeset::_tao_type (void) const
{
  return ::IOP::CodecFactory::_tc_UnsupportedCodeset;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const _tao_fields_IOP_CodecFactory_UnsupportedCodeset[] =
  {
    { "codeset", &CONV_FRAME::_tc_CodeSetId }
    
  };
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_CodecFactory_UnsupportedCodeset (
    ::CORBA::tk_except,
    "IDL:omg.org/IOP/CodecFactory/UnsupportedCodeset:1.0",
    "UnsupportedCodeset",
    _tao_fields_IOP_CodecFactory_UnsupportedCodeset,
    1);
  
::CORBA::TypeCode_ptr const IOP::CodecFactory::_tc_UnsupportedCodeset =
  &_tao_tc_IOP_CodecFactory_UnsupportedCodeset;

IOP::CodecFactory::CodecFactory (void)
{}

IOP::CodecFactory::~CodecFactory (void)
{}

IOP::CodecFactory_ptr
IOP::CodecFactory::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return CodecFactory::_duplicate (
      dynamic_cast<CodecFactory_ptr> (_tao_objref)
    );
}

IOP::CodecFactory_ptr
IOP::CodecFactory::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return CodecFactory::_duplicate (
      dynamic_cast<CodecFactory_ptr> (_tao_objref)
    );
}

IOP::CodecFactory_ptr
IOP::CodecFactory::_duplicate (CodecFactory_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
IOP::CodecFactory::_tao_release (CodecFactory_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
IOP::CodecFactory::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/IOP/CodecFactory:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* IOP::CodecFactory::_interface_repository_id (void) const
{
  return "IDL:omg.org/IOP/CodecFactory:1.0";
}

::CORBA::Boolean
IOP::CodecFactory::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_IOP_CodecFactory (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/IOP/CodecFactory:1.0",
    "CodecFactory");
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_CodecFactory =
    &_tao_tc_IOP_CodecFactory;
}



// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const IOP::Encoding &_tao_elem
  )
{
  if (0 == &_tao_elem) // Trying to de-reference NULL object
    _tao_any <<= static_cast<IOP::Encoding *>( 0 ); // Use non-copying insertion of a NULL
  else
    TAO::Any_Dual_Impl_T<IOP::Encoding>::insert_copy (
        _tao_any,
        IOP::Encoding::_tao_any_destructor,
        IOP::_tc_Encoding,
        _tao_elem
      );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    IOP::Encoding *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Encoding>::insert (
      _tao_any,
      IOP::Encoding::_tao_any_destructor,
      IOP::_tc_Encoding,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    IOP::Encoding *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::Encoding *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const IOP::Encoding *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::Encoding>::extract (
        _tao_any,
        IOP::Encoding::_tao_any_destructor,
        IOP::_tc_Encoding,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const IOP::Encoding_1_2 &_tao_elem
  )
{
  if (0 == &_tao_elem) // Trying to de-reference NULL object
    _tao_any <<= static_cast<IOP::Encoding_1_2 *>( 0 ); // Use non-copying insertion of a NULL
  else
    TAO::Any_Dual_Impl_T<IOP::Encoding_1_2>::insert_copy (
        _tao_any,
        IOP::Encoding_1_2::_tao_any_destructor,
        IOP::_tc_Encoding_1_2,
        _tao_elem
      );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    IOP::Encoding_1_2 *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::Encoding_1_2>::insert (
      _tao_any,
      IOP::Encoding_1_2::_tao_any_destructor,
      IOP::_tc_Encoding_1_2,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    IOP::Encoding_1_2 *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::Encoding_1_2 *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const IOP::Encoding_1_2 *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::Encoding_1_2>::extract (
        _tao_any,
        IOP::Encoding_1_2::_tao_any_destructor,
        IOP::_tc_Encoding_1_2,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::Encoding &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.format) &&
    (strm << ::ACE_OutputCDR::from_octet (_tao_aggregate.major_version)) &&
    (strm << ::ACE_OutputCDR::from_octet (_tao_aggregate.minor_version));
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::Encoding &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.format) &&
    (strm >> ::ACE_InputCDR::to_octet (_tao_aggregate.major_version)) &&
    (strm >> ::ACE_InputCDR::to_octet (_tao_aggregate.minor_version));
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::Encoding_1_2 &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.format) &&
    (strm << ::ACE_OutputCDR::from_octet (_tao_aggregate.major_version)) &&
    (strm << ::ACE_OutputCDR::from_octet (_tao_aggregate.minor_version)) &&
    (strm << _tao_aggregate.char_codeset) &&
    (strm << _tao_aggregate.wchar_codeset);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::Encoding_1_2 &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.format) &&
    (strm >> ::ACE_InputCDR::to_octet (_tao_aggregate.major_version)) &&
    (strm >> ::ACE_InputCDR::to_octet (_tao_aggregate.minor_version)) &&
    (strm >> _tao_aggregate.char_codeset) &&
    (strm >> _tao_aggregate.wchar_codeset);
}
