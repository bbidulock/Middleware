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
// be/be_codegen.cpp:292


#include "ORBInitInfoC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "ace/OS_NS_string.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableInterceptor::ORBInitInfo.

PortableInterceptor::ORBInitInfo_ptr
TAO::Objref_Traits<PortableInterceptor::ORBInitInfo>::duplicate (
    PortableInterceptor::ORBInitInfo_ptr p
  )
{
  return PortableInterceptor::ORBInitInfo::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::ORBInitInfo>::release (
    PortableInterceptor::ORBInitInfo_ptr p
  )
{
  ::CORBA::release (p);
}

PortableInterceptor::ORBInitInfo_ptr
TAO::Objref_Traits<PortableInterceptor::ORBInitInfo>::nil (void)
{
  return PortableInterceptor::ORBInitInfo::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::ORBInitInfo>::marshal (
    const PortableInterceptor::ORBInitInfo_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo_ObjectId (
    ::CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/ORBInitInfo/ObjectId:1.0",
    "ObjectId",
    &CORBA::_tc_string);

::CORBA::TypeCode_ptr const PortableInterceptor::ORBInitInfo::_tc_ObjectId =
  &_tao_tc_PortableInterceptor_ORBInitInfo_ObjectId;

// TAO_IDL - Generated from
// be/be_visitor_exception/exception_cs.cpp:63

PortableInterceptor::ORBInitInfo::DuplicateName::DuplicateName (void)
  : ::CORBA::UserException (
        "IDL:omg.org/PortableInterceptor/ORBInitInfo/DuplicateName:1.0",
        "DuplicateName"
      )
{
}

PortableInterceptor::ORBInitInfo::DuplicateName::~DuplicateName (void)
{
}

PortableInterceptor::ORBInitInfo::DuplicateName::DuplicateName (const ::PortableInterceptor::ORBInitInfo::DuplicateName &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
  this->name = ::CORBA::string_dup (_tao_excp.name.in ());
}

PortableInterceptor::ORBInitInfo::DuplicateName&
PortableInterceptor::ORBInitInfo::DuplicateName::operator= (const ::PortableInterceptor::ORBInitInfo::DuplicateName &_tao_excp)
{
  this->::CORBA::UserException::operator= (_tao_excp);
  this->name = ::CORBA::string_dup (_tao_excp.name.in ());
  return *this;
}

void PortableInterceptor::ORBInitInfo::DuplicateName::_tao_any_destructor (void *_tao_void_pointer)
{
  DuplicateName *_tao_tmp_pointer =
    static_cast<DuplicateName *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableInterceptor::ORBInitInfo::DuplicateName *
PortableInterceptor::ORBInitInfo::DuplicateName::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<DuplicateName *> (_tao_excp);
}

const PortableInterceptor::ORBInitInfo::DuplicateName *
PortableInterceptor::ORBInitInfo::DuplicateName::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const DuplicateName *> (_tao_excp);
}

::CORBA::Exception *PortableInterceptor::ORBInitInfo::DuplicateName::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableInterceptor::ORBInitInfo::DuplicateName, 0);
  return retval;
}

::CORBA::Exception *
PortableInterceptor::ORBInitInfo::DuplicateName::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableInterceptor::ORBInitInfo::DuplicateName (*this),
      0
    );
  return result;
}

void PortableInterceptor::ORBInitInfo::DuplicateName::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableInterceptor::ORBInitInfo::DuplicateName::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void PortableInterceptor::ORBInitInfo::DuplicateName::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// be/be_visitor_exception/exception_ctor.cpp:66

PortableInterceptor::ORBInitInfo::DuplicateName::DuplicateName (
    const char * _tao_name
  )
  : ::CORBA::UserException (
        "IDL:omg.org/PortableInterceptor/ORBInitInfo/DuplicateName:1.0",
        "DuplicateName"
      )
{
  this->name = ::CORBA::string_dup (_tao_name);
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr PortableInterceptor::ORBInitInfo::DuplicateName::_tao_type (void) const
{
  return ::PortableInterceptor::ORBInitInfo::_tc_DuplicateName;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const _tao_fields_PortableInterceptor_ORBInitInfo_DuplicateName[] =
  {
    { "name", &CORBA::_tc_string }

  };
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo_DuplicateName (
    ::CORBA::tk_except,
    "IDL:omg.org/PortableInterceptor/ORBInitInfo/DuplicateName:1.0",
    "DuplicateName",
    _tao_fields_PortableInterceptor_ORBInitInfo_DuplicateName,
    1);

::CORBA::TypeCode_ptr const PortableInterceptor::ORBInitInfo::_tc_DuplicateName =
  &_tao_tc_PortableInterceptor_ORBInitInfo_DuplicateName;

// TAO_IDL - Generated from
// be/be_visitor_exception/exception_cs.cpp:63

PortableInterceptor::ORBInitInfo::InvalidName::InvalidName (void)
  : ::CORBA::UserException (
        "IDL:omg.org/PortableInterceptor/ORBInitInfo/InvalidName:1.0",
        "InvalidName"
      )
{
}

PortableInterceptor::ORBInitInfo::InvalidName::~InvalidName (void)
{
}

PortableInterceptor::ORBInitInfo::InvalidName::InvalidName (const ::PortableInterceptor::ORBInitInfo::InvalidName &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

PortableInterceptor::ORBInitInfo::InvalidName&
PortableInterceptor::ORBInitInfo::InvalidName::operator= (const ::PortableInterceptor::ORBInitInfo::InvalidName &_tao_excp)
{
  this->::CORBA::UserException::operator= (_tao_excp);
  return *this;
}

void PortableInterceptor::ORBInitInfo::InvalidName::_tao_any_destructor (void *_tao_void_pointer)
{
  InvalidName *_tao_tmp_pointer =
    static_cast<InvalidName *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

PortableInterceptor::ORBInitInfo::InvalidName *
PortableInterceptor::ORBInitInfo::InvalidName::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<InvalidName *> (_tao_excp);
}

const PortableInterceptor::ORBInitInfo::InvalidName *
PortableInterceptor::ORBInitInfo::InvalidName::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const InvalidName *> (_tao_excp);
}

::CORBA::Exception *PortableInterceptor::ORBInitInfo::InvalidName::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::PortableInterceptor::ORBInitInfo::InvalidName, 0);
  return retval;
}

::CORBA::Exception *
PortableInterceptor::ORBInitInfo::InvalidName::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::PortableInterceptor::ORBInitInfo::InvalidName (*this),
      0
    );
  return result;
}

void PortableInterceptor::ORBInitInfo::InvalidName::_raise (void) const
{
  TAO_RAISE (*this);
}

void PortableInterceptor::ORBInitInfo::InvalidName::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

void PortableInterceptor::ORBInitInfo::InvalidName::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW ( ::CORBA::MARSHAL ());
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr PortableInterceptor::ORBInitInfo::InvalidName::_tao_type (void) const
{
  return ::PortableInterceptor::ORBInitInfo::_tc_InvalidName;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:89

static TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableInterceptor_ORBInitInfo_InvalidName = 0;
static TAO::TypeCode::Struct<char const *,
                      ::CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, ::CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo_InvalidName (
    ::CORBA::tk_except,
    "IDL:omg.org/PortableInterceptor/ORBInitInfo/InvalidName:1.0",
    "InvalidName",
    _tao_fields_PortableInterceptor_ORBInitInfo_InvalidName,
    0);

::CORBA::TypeCode_ptr const PortableInterceptor::ORBInitInfo::_tc_InvalidName =
  &_tao_tc_PortableInterceptor_ORBInitInfo_InvalidName;

PortableInterceptor::ORBInitInfo::ORBInitInfo (void)
{}

PortableInterceptor::ORBInitInfo::~ORBInitInfo (void)
{}

PortableInterceptor::ORBInitInfo_ptr
PortableInterceptor::ORBInitInfo::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ORBInitInfo::_duplicate (
      dynamic_cast<ORBInitInfo_ptr> (_tao_objref)
    );
}

PortableInterceptor::ORBInitInfo_ptr
PortableInterceptor::ORBInitInfo::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ORBInitInfo::_duplicate (
      dynamic_cast<ORBInitInfo_ptr> (_tao_objref)
    );
}

PortableInterceptor::ORBInitInfo_ptr
PortableInterceptor::ORBInitInfo::_duplicate (ORBInitInfo_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
PortableInterceptor::ORBInitInfo::_tao_release (ORBInitInfo_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
PortableInterceptor::ORBInitInfo::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/ORBInitInfo:1.0"
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

const char* PortableInterceptor::ORBInitInfo::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/ORBInitInfo:1.0";
}

::CORBA::Boolean
PortableInterceptor::ORBInitInfo::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/PortableInterceptor/ORBInitInfo:1.0",
    "ORBInitInfo");

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ORBInitInfo =
    &_tao_tc_PortableInterceptor_ORBInitInfo;
}



// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for PortableInterceptor::ORBInitInfo_3_1.

PortableInterceptor::ORBInitInfo_3_1_ptr
TAO::Objref_Traits<PortableInterceptor::ORBInitInfo_3_1>::duplicate (
    PortableInterceptor::ORBInitInfo_3_1_ptr p
  )
{
  return PortableInterceptor::ORBInitInfo_3_1::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::ORBInitInfo_3_1>::release (
    PortableInterceptor::ORBInitInfo_3_1_ptr p
  )
{
  ::CORBA::release (p);
}

PortableInterceptor::ORBInitInfo_3_1_ptr
TAO::Objref_Traits<PortableInterceptor::ORBInitInfo_3_1>::nil (void)
{
  return PortableInterceptor::ORBInitInfo_3_1::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::ORBInitInfo_3_1>::marshal (
    const PortableInterceptor::ORBInitInfo_3_1_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::ORBInitInfo_3_1::ORBInitInfo_3_1 (void)
{}

PortableInterceptor::ORBInitInfo_3_1::~ORBInitInfo_3_1 (void)
{}

PortableInterceptor::ORBInitInfo_3_1_ptr
PortableInterceptor::ORBInitInfo_3_1::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ORBInitInfo_3_1::_duplicate (
      dynamic_cast<ORBInitInfo_3_1_ptr> (_tao_objref)
    );
}

PortableInterceptor::ORBInitInfo_3_1_ptr
PortableInterceptor::ORBInitInfo_3_1::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return ORBInitInfo_3_1::_duplicate (
      dynamic_cast<ORBInitInfo_3_1_ptr> (_tao_objref)
    );
}

PortableInterceptor::ORBInitInfo_3_1_ptr
PortableInterceptor::ORBInitInfo_3_1::_duplicate (ORBInitInfo_3_1_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
PortableInterceptor::ORBInitInfo_3_1::_tao_release (ORBInitInfo_3_1_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
PortableInterceptor::ORBInitInfo_3_1::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/ORBInitInfo:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableInterceptor/ORBInitInfo_3_1:1.0"
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

const char* PortableInterceptor::ORBInitInfo_3_1::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableInterceptor/ORBInitInfo_3_1:1.0";
}

::CORBA::Boolean
PortableInterceptor::ORBInitInfo_3_1::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo_3_1 (
    ::CORBA::tk_local_interface,
    "IDL:omg.org/PortableInterceptor/ORBInitInfo_3_1:1.0",
    "ORBInitInfo_3_1");

namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ORBInitInfo_3_1 =
    &_tao_tc_PortableInterceptor_ORBInitInfo_3_1;
}




TAO_END_VERSIONED_NAMESPACE_DECL


