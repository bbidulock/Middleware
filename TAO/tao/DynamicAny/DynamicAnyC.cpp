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
// be\be_codegen.cpp:291


#include "DynamicAny.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynAny.

DynamicAny::DynAny_ptr
TAO::Objref_Traits<DynamicAny::DynAny>::duplicate (
    DynamicAny::DynAny_ptr p
  )
{
  return DynamicAny::DynAny::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynAny>::release (
    DynamicAny::DynAny_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynAny_ptr
TAO::Objref_Traits<DynamicAny::DynAny>::nil (void)
{
  return DynamicAny::DynAny::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynAny>::marshal (
    DynamicAny::DynAny_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from
// be\be_visitor_exception/exception_cs.cpp:63

DynamicAny::DynAny::InvalidValue::InvalidValue (void)
  : CORBA::UserException (
        "IDL:omg.org/DynamicAny/DynAny/InvalidValue:1.0",
        "InvalidValue"
      )
{
}

DynamicAny::DynAny::InvalidValue::~InvalidValue (void)
{
}

DynamicAny::DynAny::InvalidValue::InvalidValue (const ::DynamicAny::DynAny::InvalidValue &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

DynamicAny::DynAny::InvalidValue&
DynamicAny::DynAny::InvalidValue::operator= (const ::DynamicAny::DynAny::InvalidValue &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

DynamicAny::DynAny::InvalidValue *
DynamicAny::DynAny::InvalidValue::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<InvalidValue *> (_tao_excp);
}

const DynamicAny::DynAny::InvalidValue *
DynamicAny::DynAny::InvalidValue::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const InvalidValue *> (_tao_excp);
}

CORBA::Exception *DynamicAny::DynAny::InvalidValue::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::DynamicAny::DynAny::InvalidValue, 0);
  return retval;
}

CORBA::Exception *
DynamicAny::DynAny::InvalidValue::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::DynamicAny::DynAny::InvalidValue (*this),
      0
    );
  return result;
}

void DynamicAny::DynAny::InvalidValue::_raise (void) const
{
  TAO_RAISE (*this);
}

void DynamicAny::DynAny::InvalidValue::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void DynamicAny::DynAny::InvalidValue::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// be\be_visitor_exception/exception_cs.cpp:63

DynamicAny::DynAny::TypeMismatch::TypeMismatch (void)
  : CORBA::UserException (
        "IDL:omg.org/DynamicAny/DynAny/TypeMismatch:1.0",
        "TypeMismatch"
      )
{
}

DynamicAny::DynAny::TypeMismatch::~TypeMismatch (void)
{
}

DynamicAny::DynAny::TypeMismatch::TypeMismatch (const ::DynamicAny::DynAny::TypeMismatch &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

DynamicAny::DynAny::TypeMismatch&
DynamicAny::DynAny::TypeMismatch::operator= (const ::DynamicAny::DynAny::TypeMismatch &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

DynamicAny::DynAny::TypeMismatch *
DynamicAny::DynAny::TypeMismatch::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<TypeMismatch *> (_tao_excp);
}

const DynamicAny::DynAny::TypeMismatch *
DynamicAny::DynAny::TypeMismatch::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const TypeMismatch *> (_tao_excp);
}

CORBA::Exception *DynamicAny::DynAny::TypeMismatch::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::DynamicAny::DynAny::TypeMismatch, 0);
  return retval;
}

CORBA::Exception *
DynamicAny::DynAny::TypeMismatch::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::DynamicAny::DynAny::TypeMismatch (*this),
      0
    );
  return result;
}

void DynamicAny::DynAny::TypeMismatch::_raise (void) const
{
  TAO_RAISE (*this);
}

void DynamicAny::DynAny::TypeMismatch::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void DynamicAny::DynAny::TypeMismatch::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}



DynamicAny::DynAny::DynAny (void)
{}

DynamicAny::DynAny::~DynAny (void)
{}

DynamicAny::DynAny_ptr
DynamicAny::DynAny::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynAny::_nil ();
    }

  DynAny_ptr proxy =
    dynamic_cast<DynAny_ptr> (_tao_objref);

  return DynAny::_duplicate (proxy);
}

DynamicAny::DynAny_ptr
DynamicAny::DynAny::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynAny::_nil ();
    }

  DynAny_ptr proxy =
    dynamic_cast<DynAny_ptr> (_tao_objref);

  return DynAny::_duplicate (proxy);
}

DynamicAny::DynAny_ptr
DynamicAny::DynAny::_duplicate (DynAny_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
DynamicAny::DynAny::_tao_release (DynAny_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynAny::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAny:1.0"
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

const char* DynamicAny::DynAny::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynAny:1.0";
}

CORBA::Boolean
DynamicAny::DynAny::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynFixed.

DynamicAny::DynFixed_ptr
TAO::Objref_Traits<DynamicAny::DynFixed>::duplicate (
    DynamicAny::DynFixed_ptr p
  )
{
  return DynamicAny::DynFixed::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynFixed>::release (
    DynamicAny::DynFixed_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynFixed_ptr
TAO::Objref_Traits<DynamicAny::DynFixed>::nil (void)
{
  return DynamicAny::DynFixed::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynFixed>::marshal (
    DynamicAny::DynFixed_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

DynamicAny::DynFixed::DynFixed (void)
{}

DynamicAny::DynFixed::~DynFixed (void)
{}

DynamicAny::DynFixed_ptr
DynamicAny::DynFixed::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynFixed::_nil ();
    }

  DynFixed_ptr proxy =
    dynamic_cast<DynFixed_ptr> (_tao_objref);

  return DynFixed::_duplicate (proxy);
}

DynamicAny::DynFixed_ptr
DynamicAny::DynFixed::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynFixed::_nil ();
    }

  DynFixed_ptr proxy =
    dynamic_cast<DynFixed_ptr> (_tao_objref);

  return DynFixed::_duplicate (proxy);
}

DynamicAny::DynFixed_ptr
DynamicAny::DynFixed::_duplicate (DynFixed_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
DynamicAny::DynFixed::_tao_release (DynFixed_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynFixed::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAny:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynFixed:1.0"
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

const char* DynamicAny::DynFixed::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynFixed:1.0";
}

CORBA::Boolean
DynamicAny::DynFixed::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynEnum.

DynamicAny::DynEnum_ptr
TAO::Objref_Traits<DynamicAny::DynEnum>::duplicate (
    DynamicAny::DynEnum_ptr p
  )
{
  return DynamicAny::DynEnum::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynEnum>::release (
    DynamicAny::DynEnum_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynEnum_ptr
TAO::Objref_Traits<DynamicAny::DynEnum>::nil (void)
{
  return DynamicAny::DynEnum::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynEnum>::marshal (
    DynamicAny::DynEnum_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

DynamicAny::DynEnum::DynEnum (void)
{}

DynamicAny::DynEnum::~DynEnum (void)
{}

DynamicAny::DynEnum_ptr
DynamicAny::DynEnum::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynEnum::_nil ();
    }

  DynEnum_ptr proxy =
    dynamic_cast<DynEnum_ptr> (_tao_objref);

  return DynEnum::_duplicate (proxy);
}

DynamicAny::DynEnum_ptr
DynamicAny::DynEnum::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynEnum::_nil ();
    }

  DynEnum_ptr proxy =
    dynamic_cast<DynEnum_ptr> (_tao_objref);

  return DynEnum::_duplicate (proxy);
}

DynamicAny::DynEnum_ptr
DynamicAny::DynEnum::_duplicate (DynEnum_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
DynamicAny::DynEnum::_tao_release (DynEnum_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynEnum::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAny:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynEnum:1.0"
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

const char* DynamicAny::DynEnum::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynEnum:1.0";
}

CORBA::Boolean
DynamicAny::DynEnum::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_DYNAMICANY_NAMEVALUEPAIRSEQ_CS_)
#define _DYNAMICANY_NAMEVALUEPAIRSEQ_CS_

DynamicAny::NameValuePairSeq::NameValuePairSeq (void)
{}

DynamicAny::NameValuePairSeq::NameValuePairSeq (
    CORBA::ULong max
  )
  : TAO::unbounded_value_sequence<
        DynamicAny::NameValuePair
      >
    (max)
{}

DynamicAny::NameValuePairSeq::NameValuePairSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    DynamicAny::NameValuePair * buffer,
    CORBA::Boolean release
  )
  : TAO::unbounded_value_sequence<
        DynamicAny::NameValuePair
      >
    (max, length, buffer, release)
{}

DynamicAny::NameValuePairSeq::NameValuePairSeq (
    const NameValuePairSeq &seq
  )
  : TAO::unbounded_value_sequence<
        DynamicAny::NameValuePair
      >
    (seq)
{}

DynamicAny::NameValuePairSeq::~NameValuePairSeq (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_DYNAMICANY_NAMEDYNANYPAIRSEQ_CS_)
#define _DYNAMICANY_NAMEDYNANYPAIRSEQ_CS_

DynamicAny::NameDynAnyPairSeq::NameDynAnyPairSeq (void)
{}

DynamicAny::NameDynAnyPairSeq::NameDynAnyPairSeq (
    CORBA::ULong max
  )
  : TAO::unbounded_value_sequence<
        DynamicAny::NameDynAnyPair
      >
    (max)
{}

DynamicAny::NameDynAnyPairSeq::NameDynAnyPairSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    DynamicAny::NameDynAnyPair * buffer,
    CORBA::Boolean release
  )
  : TAO::unbounded_value_sequence<
        DynamicAny::NameDynAnyPair
      >
    (max, length, buffer, release)
{}

DynamicAny::NameDynAnyPairSeq::NameDynAnyPairSeq (
    const NameDynAnyPairSeq &seq
  )
  : TAO::unbounded_value_sequence<
        DynamicAny::NameDynAnyPair
      >
    (seq)
{}

DynamicAny::NameDynAnyPairSeq::~NameDynAnyPairSeq (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynStruct.

DynamicAny::DynStruct_ptr
TAO::Objref_Traits<DynamicAny::DynStruct>::duplicate (
    DynamicAny::DynStruct_ptr p
  )
{
  return DynamicAny::DynStruct::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynStruct>::release (
    DynamicAny::DynStruct_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynStruct_ptr
TAO::Objref_Traits<DynamicAny::DynStruct>::nil (void)
{
  return DynamicAny::DynStruct::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynStruct>::marshal (
    DynamicAny::DynStruct_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

DynamicAny::DynStruct::DynStruct (void)
{}

DynamicAny::DynStruct::~DynStruct (void)
{}

DynamicAny::DynStruct_ptr
DynamicAny::DynStruct::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynStruct::_nil ();
    }

  DynStruct_ptr proxy =
    dynamic_cast<DynStruct_ptr> (_tao_objref);

  return DynStruct::_duplicate (proxy);
}

DynamicAny::DynStruct_ptr
DynamicAny::DynStruct::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynStruct::_nil ();
    }

  DynStruct_ptr proxy =
    dynamic_cast<DynStruct_ptr> (_tao_objref);

  return DynStruct::_duplicate (proxy);
}

DynamicAny::DynStruct_ptr
DynamicAny::DynStruct::_duplicate (DynStruct_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
DynamicAny::DynStruct::_tao_release (DynStruct_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynStruct::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAny:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynStruct:1.0"
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

const char* DynamicAny::DynStruct::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynStruct:1.0";
}

CORBA::Boolean
DynamicAny::DynStruct::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynUnion.

DynamicAny::DynUnion_ptr
TAO::Objref_Traits<DynamicAny::DynUnion>::duplicate (
    DynamicAny::DynUnion_ptr p
  )
{
  return DynamicAny::DynUnion::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynUnion>::release (
    DynamicAny::DynUnion_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynUnion_ptr
TAO::Objref_Traits<DynamicAny::DynUnion>::nil (void)
{
  return DynamicAny::DynUnion::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynUnion>::marshal (
    DynamicAny::DynUnion_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

DynamicAny::DynUnion::DynUnion (void)
{}

DynamicAny::DynUnion::~DynUnion (void)
{}

DynamicAny::DynUnion_ptr
DynamicAny::DynUnion::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynUnion::_nil ();
    }

  DynUnion_ptr proxy =
    dynamic_cast<DynUnion_ptr> (_tao_objref);

  return DynUnion::_duplicate (proxy);
}

DynamicAny::DynUnion_ptr
DynamicAny::DynUnion::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynUnion::_nil ();
    }

  DynUnion_ptr proxy =
    dynamic_cast<DynUnion_ptr> (_tao_objref);

  return DynUnion::_duplicate (proxy);
}

DynamicAny::DynUnion_ptr
DynamicAny::DynUnion::_duplicate (DynUnion_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
DynamicAny::DynUnion::_tao_release (DynUnion_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynUnion::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAny:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynUnion:1.0"
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

const char* DynamicAny::DynUnion::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynUnion:1.0";
}

CORBA::Boolean
DynamicAny::DynUnion::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_DYNAMICANY_ANYSEQ_CS_)
#define _DYNAMICANY_ANYSEQ_CS_

DynamicAny::AnySeq::AnySeq (void)
{}

DynamicAny::AnySeq::AnySeq (
    CORBA::ULong max
  )
  : TAO::unbounded_value_sequence<
        CORBA::Any
      >
    (max)
{}

DynamicAny::AnySeq::AnySeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Any * buffer,
    CORBA::Boolean release
  )
  : TAO::unbounded_value_sequence<
        CORBA::Any
      >
    (max, length, buffer, release)
{}

DynamicAny::AnySeq::AnySeq (
    const AnySeq &seq
  )
  : TAO::unbounded_value_sequence<
        CORBA::Any
      >
    (seq)
{}

DynamicAny::AnySeq::~AnySeq (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_DYNAMICANY_DYNANYSEQ_CS_)
#define _DYNAMICANY_DYNANYSEQ_CS_

DynamicAny::DynAnySeq::DynAnySeq (void)
{}

DynamicAny::DynAnySeq::DynAnySeq (
    CORBA::ULong max
  )
  : TAO::unbounded_object_reference_sequence<
        DynamicAny::DynAny,
        DynamicAny::DynAny_var
      >
    (max)
{}

DynamicAny::DynAnySeq::DynAnySeq (
    CORBA::ULong max,
    CORBA::ULong length,
    DynamicAny::DynAny_ptr * buffer,
    CORBA::Boolean release
  )
  : TAO::unbounded_object_reference_sequence<
        DynamicAny::DynAny,
        DynamicAny::DynAny_var
      >
    (max, length, buffer, release)
{}

DynamicAny::DynAnySeq::DynAnySeq (
    const DynAnySeq &seq
  )
  : TAO::unbounded_object_reference_sequence<
        DynamicAny::DynAny,
        DynamicAny::DynAny_var
      >
    (seq)
{}

DynamicAny::DynAnySeq::~DynAnySeq (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynSequence.

DynamicAny::DynSequence_ptr
TAO::Objref_Traits<DynamicAny::DynSequence>::duplicate (
    DynamicAny::DynSequence_ptr p
  )
{
  return DynamicAny::DynSequence::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynSequence>::release (
    DynamicAny::DynSequence_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynSequence_ptr
TAO::Objref_Traits<DynamicAny::DynSequence>::nil (void)
{
  return DynamicAny::DynSequence::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynSequence>::marshal (
    DynamicAny::DynSequence_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

DynamicAny::DynSequence::DynSequence (void)
{}

DynamicAny::DynSequence::~DynSequence (void)
{}

DynamicAny::DynSequence_ptr
DynamicAny::DynSequence::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynSequence::_nil ();
    }

  DynSequence_ptr proxy =
    dynamic_cast<DynSequence_ptr> (_tao_objref);
  
  return DynSequence::_duplicate (proxy);
}

DynamicAny::DynSequence_ptr
DynamicAny::DynSequence::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynSequence::_nil ();
    }
  
  DynSequence_ptr proxy =
    dynamic_cast<DynSequence_ptr> (_tao_objref);
  
  return DynSequence::_duplicate (proxy);
}

DynamicAny::DynSequence_ptr
DynamicAny::DynSequence::_duplicate (DynSequence_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
DynamicAny::DynSequence::_tao_release (DynSequence_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynSequence::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAny:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynSequence:1.0"
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

const char* DynamicAny::DynSequence::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynSequence:1.0";
}

CORBA::Boolean
DynamicAny::DynSequence::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynArray.

DynamicAny::DynArray_ptr
TAO::Objref_Traits<DynamicAny::DynArray>::duplicate (
    DynamicAny::DynArray_ptr p
  )
{
  return DynamicAny::DynArray::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynArray>::release (
    DynamicAny::DynArray_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynArray_ptr
TAO::Objref_Traits<DynamicAny::DynArray>::nil (void)
{
  return DynamicAny::DynArray::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynArray>::marshal (
    DynamicAny::DynArray_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

DynamicAny::DynArray::DynArray (void)
{}

DynamicAny::DynArray::~DynArray (void)
{}

DynamicAny::DynArray_ptr
DynamicAny::DynArray::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynArray::_nil ();
    }
  
  DynArray_ptr proxy =
    dynamic_cast<DynArray_ptr> (_tao_objref);
  
  return DynArray::_duplicate (proxy);
}

DynamicAny::DynArray_ptr
DynamicAny::DynArray::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynArray::_nil ();
    }
  
  DynArray_ptr proxy =
    dynamic_cast<DynArray_ptr> (_tao_objref);
  
  return DynArray::_duplicate (proxy);
}

DynamicAny::DynArray_ptr
DynamicAny::DynArray::_duplicate (DynArray_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
DynamicAny::DynArray::_tao_release (DynArray_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynArray::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAny:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynArray:1.0"
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

const char* DynamicAny::DynArray::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynArray:1.0";
}

CORBA::Boolean
DynamicAny::DynArray::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynValue.

DynamicAny::DynValue_ptr
TAO::Objref_Traits<DynamicAny::DynValue>::duplicate (
    DynamicAny::DynValue_ptr p
  )
{
  return DynamicAny::DynValue::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynValue>::release (
    DynamicAny::DynValue_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynValue_ptr
TAO::Objref_Traits<DynamicAny::DynValue>::nil (void)
{
  return DynamicAny::DynValue::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynValue>::marshal (
    DynamicAny::DynValue_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

DynamicAny::DynValue::DynValue (void)
{}

DynamicAny::DynValue::~DynValue (void)
{}

DynamicAny::DynValue_ptr
DynamicAny::DynValue::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynValue::_nil ();
    }
  
  DynValue_ptr proxy =
    dynamic_cast<DynValue_ptr> (_tao_objref);
  
  return DynValue::_duplicate (proxy);
}

DynamicAny::DynValue_ptr
DynamicAny::DynValue::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynValue::_nil ();
    }
  
  DynValue_ptr proxy =
    dynamic_cast<DynValue_ptr> (_tao_objref);
  
  return DynValue::_duplicate (proxy);
}

DynamicAny::DynValue_ptr
DynamicAny::DynValue::_duplicate (DynValue_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
DynamicAny::DynValue::_tao_release (DynValue_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynValue::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAny:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynValue:1.0"
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

const char* DynamicAny::DynValue::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynValue:1.0";
}

CORBA::Boolean
DynamicAny::DynValue::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for DynamicAny::DynAnyFactory.

DynamicAny::DynAnyFactory_ptr
TAO::Objref_Traits<DynamicAny::DynAnyFactory>::duplicate (
    DynamicAny::DynAnyFactory_ptr p
  )
{
  return DynamicAny::DynAnyFactory::_duplicate (p);
}

void
TAO::Objref_Traits<DynamicAny::DynAnyFactory>::release (
    DynamicAny::DynAnyFactory_ptr p
  )
{
  CORBA::release (p);
}

DynamicAny::DynAnyFactory_ptr
TAO::Objref_Traits<DynamicAny::DynAnyFactory>::nil (void)
{
  return DynamicAny::DynAnyFactory::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<DynamicAny::DynAnyFactory>::marshal (
    DynamicAny::DynAnyFactory_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return CORBA::Object::marshal (p, cdr);
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/exception_cs.cpp:63

DynamicAny::DynAnyFactory::InconsistentTypeCode::InconsistentTypeCode (void)
  : CORBA::UserException (
        "IDL:omg.org/DynamicAny/DynAnyFactory/InconsistentTypeCode:1.0",
        "InconsistentTypeCode"
      )
{
}

DynamicAny::DynAnyFactory::InconsistentTypeCode::~InconsistentTypeCode (void)
{
}

DynamicAny::DynAnyFactory::InconsistentTypeCode::InconsistentTypeCode (const ::DynamicAny::DynAnyFactory::InconsistentTypeCode &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

DynamicAny::DynAnyFactory::InconsistentTypeCode&
DynamicAny::DynAnyFactory::InconsistentTypeCode::operator= (const ::DynamicAny::DynAnyFactory::InconsistentTypeCode &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

DynamicAny::DynAnyFactory::InconsistentTypeCode *
DynamicAny::DynAnyFactory::InconsistentTypeCode::_downcast (CORBA::Exception *_tao_excp)
{
  return dynamic_cast<InconsistentTypeCode *> (_tao_excp);
}

const DynamicAny::DynAnyFactory::InconsistentTypeCode *
DynamicAny::DynAnyFactory::InconsistentTypeCode::_downcast (CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const InconsistentTypeCode *> (_tao_excp);
}

CORBA::Exception *DynamicAny::DynAnyFactory::InconsistentTypeCode::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::DynamicAny::DynAnyFactory::InconsistentTypeCode, 0);
  return retval;
}

CORBA::Exception *
DynamicAny::DynAnyFactory::InconsistentTypeCode::_tao_duplicate (void) const
{
  CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::DynamicAny::DynAnyFactory::InconsistentTypeCode (*this),
      0
    );
  return result;
}

void DynamicAny::DynAnyFactory::InconsistentTypeCode::_raise (void) const
{
  TAO_RAISE (*this);
}

void DynamicAny::DynAnyFactory::InconsistentTypeCode::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void DynamicAny::DynAnyFactory::InconsistentTypeCode::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}



DynamicAny::DynAnyFactory::DynAnyFactory (void)
{}

DynamicAny::DynAnyFactory::~DynAnyFactory (void)
{}

DynamicAny::DynAnyFactory_ptr
DynamicAny::DynAnyFactory::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynAnyFactory::_nil ();
    }
  
  DynAnyFactory_ptr proxy =
    dynamic_cast<DynAnyFactory_ptr> (_tao_objref);
  
  return DynAnyFactory::_duplicate (proxy);
}

DynamicAny::DynAnyFactory_ptr
DynamicAny::DynAnyFactory::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DynAnyFactory::_nil ();
    }
  
  DynAnyFactory_ptr proxy =
    dynamic_cast<DynAnyFactory_ptr> (_tao_objref);
  
  return DynAnyFactory::_duplicate (proxy);
}

DynamicAny::DynAnyFactory_ptr
DynamicAny::DynAnyFactory::_duplicate (DynAnyFactory_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
DynamicAny::DynAnyFactory::_tao_release (DynAnyFactory_ptr obj)
{
  CORBA::release (obj);
}

CORBA::Boolean
DynamicAny::DynAnyFactory::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/DynamicAny/DynAnyFactory:1.0"
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

const char* DynamicAny::DynAnyFactory::_interface_repository_id (void) const
{
  return "IDL:omg.org/DynamicAny/DynAnyFactory:1.0";
}

CORBA::Boolean
DynamicAny::DynAnyFactory::marshal (TAO_OutputCDR &)
{
  return false;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DynamicAny::NameValuePair &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.id.in ()) &&
    (strm << _tao_aggregate.value);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DynamicAny::NameValuePair &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.id.out ()) &&
    (strm >> _tao_aggregate.value);
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_DynamicAny_NameValuePairSeq_CPP_
#define _TAO_CDR_OP_DynamicAny_NameValuePairSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DynamicAny::NameValuePairSeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DynamicAny::NameValuePairSeq &_tao_sequence
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
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_DynamicAny_NameValuePairSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_DynamicAny_AnySeq_CPP_
#define _TAO_CDR_OP_DynamicAny_AnySeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DynamicAny::AnySeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DynamicAny::AnySeq &_tao_sequence
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
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_DynamicAny_AnySeq_CPP_ */
