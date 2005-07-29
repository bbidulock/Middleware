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

#include "IFR_ExtendedC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "tao/AnyTypeCode/orb_typesA.h"
#include "tao/AnyTypeCode/ParameterModeA.h"
#include "tao/AnyTypeCode/VisibilityA.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_FixedDef (
    CORBA::tk_objref,
    "IDL:omg.org/CORBA/FixedDef:1.0",
    "FixedDef");

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_FixedDef =
    &_tao_tc_CORBA_FixedDef;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_CORBA_ValueMember[] =
  {
    { "name", &CORBA::_tc_Identifier },
    { "id", &CORBA::_tc_RepositoryId },
    { "defined_in", &CORBA::_tc_RepositoryId },
    { "version", &CORBA::_tc_VersionSpec },
    { "type", &CORBA::_tc_TypeCode },
    { "type_def", &CORBA::_tc_IDLType },
    { "access", &CORBA::_tc_Visibility }

  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ValueMember (
    CORBA::tk_struct,
    "IDL:omg.org/CORBA/ValueMember:1.0",
    "ValueMember",
    _tao_fields_CORBA_ValueMember,
    7);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ValueMember =
    &_tao_tc_CORBA_ValueMember;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:925


#ifndef _TAO_TYPECODE_CORBA_ValueMemberSeq_GUARD
#define _TAO_TYPECODE_CORBA_ValueMemberSeq_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      CORBA_ValueMemberSeq_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_ValueMember,
        0U);

    ::CORBA::TypeCode_ptr const tc_CORBA_ValueMemberSeq_0 =
      &CORBA_ValueMemberSeq_0;

  }
}


#endif /* _TAO_TYPECODE_CORBA_ValueMemberSeq_GUARD */
static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ValueMemberSeq (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ValueMemberSeq:1.0",
    "ValueMemberSeq",
    &TAO::TypeCode::tc_CORBA_ValueMemberSeq_0);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ValueMemberSeq =
    &_tao_tc_CORBA_ValueMemberSeq;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ValueMemberDef (
    CORBA::tk_objref,
    "IDL:omg.org/CORBA/ValueMemberDef:1.0",
    "ValueMemberDef");

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ValueMemberDef =
    &_tao_tc_CORBA_ValueMemberDef;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_CORBA_ValueDef_FullValueDescription[] =
  {
    { "name", &CORBA::_tc_Identifier },
    { "id", &CORBA::_tc_RepositoryId },
    { "is_abstract", &CORBA::_tc_boolean },
    { "is_custom", &CORBA::_tc_boolean },
    { "defined_in", &CORBA::_tc_RepositoryId },
    { "version", &CORBA::_tc_VersionSpec },
    { "operations", &CORBA::_tc_OpDescriptionSeq },
    { "attributes", &CORBA::_tc_AttrDescriptionSeq },
    { "members", &CORBA::_tc_ValueMemberSeq },
    { "initializers", &CORBA::_tc_InitializerSeq },
    { "supported_interfaces", &CORBA::_tc_RepositoryIdSeq },
    { "abstract_base_values", &CORBA::_tc_RepositoryIdSeq },
    { "is_truncatable", &CORBA::_tc_boolean },
    { "base_value", &CORBA::_tc_RepositoryId },
    { "type", &CORBA::_tc_TypeCode }

  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ValueDef_FullValueDescription (
    CORBA::tk_struct,
    "IDL:omg.org/CORBA/ValueDef/FullValueDescription:1.0",
    "FullValueDescription",
    _tao_fields_CORBA_ValueDef_FullValueDescription,
    15);

::CORBA::TypeCode_ptr const CORBA::ValueDef::_tc_FullValueDescription =
  &_tao_tc_CORBA_ValueDef_FullValueDescription;

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ValueDef (
    CORBA::tk_objref,
    "IDL:omg.org/CORBA/ValueDef:1.0",
    "ValueDef");

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ValueDef =
    &_tao_tc_CORBA_ValueDef;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_CORBA_ValueDescription[] =
  {
    { "name", &CORBA::_tc_Identifier },
    { "id", &CORBA::_tc_RepositoryId },
    { "is_abstract", &CORBA::_tc_boolean },
    { "is_custom", &CORBA::_tc_boolean },
    { "defined_in", &CORBA::_tc_RepositoryId },
    { "version", &CORBA::_tc_VersionSpec },
    { "supported_interfaces", &CORBA::_tc_RepositoryIdSeq },
    { "abstract_base_values", &CORBA::_tc_RepositoryIdSeq },
    { "is_truncatable", &CORBA::_tc_boolean },
    { "base_value", &CORBA::_tc_RepositoryId }

  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ValueDescription (
    CORBA::tk_struct,
    "IDL:omg.org/CORBA/ValueDescription:1.0",
    "ValueDescription",
    _tao_fields_CORBA_ValueDescription,
    10);

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ValueDescription =
    &_tao_tc_CORBA_ValueDescription;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_CORBA_ExtValueDef_ExtFullValueDescription[] =
  {
    { "name", &CORBA::_tc_Identifier },
    { "id", &CORBA::_tc_RepositoryId },
    { "is_abstract", &CORBA::_tc_boolean },
    { "is_custom", &CORBA::_tc_boolean },
    { "defined_in", &CORBA::_tc_RepositoryId },
    { "version", &CORBA::_tc_VersionSpec },
    { "operations", &CORBA::_tc_OpDescriptionSeq },
    { "attributes", &CORBA::_tc_ExtAttrDescriptionSeq },
    { "members", &CORBA::_tc_ValueMemberSeq },
    { "initializers", &CORBA::_tc_ExtInitializerSeq },
    { "supported_interfaces", &CORBA::_tc_RepositoryIdSeq },
    { "abstract_base_values", &CORBA::_tc_RepositoryIdSeq },
    { "is_truncatable", &CORBA::_tc_boolean },
    { "base_value", &CORBA::_tc_RepositoryId },
    { "type", &CORBA::_tc_TypeCode }

  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ExtValueDef_ExtFullValueDescription (
    CORBA::tk_struct,
    "IDL:omg.org/CORBA/ExtValueDef/ExtFullValueDescription:1.0",
    "ExtFullValueDescription",
    _tao_fields_CORBA_ExtValueDef_ExtFullValueDescription,
    15);

::CORBA::TypeCode_ptr const CORBA::ExtValueDef::_tc_ExtFullValueDescription =
  &_tao_tc_CORBA_ExtValueDef_ExtFullValueDescription;

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ExtValueDef (
    CORBA::tk_objref,
    "IDL:omg.org/CORBA/ExtValueDef:1.0",
    "ExtValueDef");

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ExtValueDef =
    &_tao_tc_CORBA_ExtValueDef;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ValueBoxDef (
    CORBA::tk_objref,
    "IDL:omg.org/CORBA/ValueBoxDef:1.0",
    "ValueBoxDef");

namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ValueBoxDef =
    &_tao_tc_CORBA_ValueBoxDef;
}



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<CORBA::FixedDef>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::FixedDef_ptr _tao_elem
  )
{
  CORBA::FixedDef_ptr _tao_objptr =
    CORBA::FixedDef::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::FixedDef_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::FixedDef>::insert (
      _tao_any,
      CORBA::FixedDef::_tao_any_destructor,
      CORBA::_tc_FixedDef,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::FixedDef_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::FixedDef>::extract (
        _tao_any,
        CORBA::FixedDef::_tao_any_destructor,
        CORBA::_tc_FixedDef,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ValueMember &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ValueMember>::insert_copy (
      _tao_any,
      CORBA::ValueMember::_tao_any_destructor,
      CORBA::_tc_ValueMember,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueMember *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ValueMember>::insert (
      _tao_any,
      CORBA::ValueMember::_tao_any_destructor,
      CORBA::_tc_ValueMember,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ValueMember *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ValueMember *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ValueMember *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ValueMember>::extract (
        _tao_any,
        CORBA::ValueMember::_tao_any_destructor,
        CORBA::_tc_ValueMember,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ValueMemberSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ValueMemberSeq>::insert_copy (
      _tao_any,
      CORBA::ValueMemberSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_ValueMemberSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueMemberSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ValueMemberSeq>::insert (
      _tao_any,
      CORBA::ValueMemberSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_ValueMemberSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ValueMemberSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ValueMemberSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ValueMemberSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ValueMemberSeq>::extract (
        _tao_any,
        CORBA::ValueMemberSeq::_tao_any_destructor,
        TAO::TypeCode::tc_CORBA_ValueMemberSeq_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<CORBA::ValueMemberDef>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueMemberDef_ptr _tao_elem
  )
{
  CORBA::ValueMemberDef_ptr _tao_objptr =
    CORBA::ValueMemberDef::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueMemberDef_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::ValueMemberDef>::insert (
      _tao_any,
      CORBA::ValueMemberDef::_tao_any_destructor,
      CORBA::_tc_ValueMemberDef,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ValueMemberDef_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::ValueMemberDef>::extract (
        _tao_any,
        CORBA::ValueMemberDef::_tao_any_destructor,
        CORBA::_tc_ValueMemberDef,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<CORBA::ValueDef>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueDef_ptr _tao_elem
  )
{
  CORBA::ValueDef_ptr _tao_objptr =
    CORBA::ValueDef::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueDef_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::ValueDef>::insert (
      _tao_any,
      CORBA::ValueDef::_tao_any_destructor,
      CORBA::_tc_ValueDef,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ValueDef_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::ValueDef>::extract (
        _tao_any,
        CORBA::ValueDef::_tao_any_destructor,
        CORBA::_tc_ValueDef,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ValueDef::FullValueDescription &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ValueDef::FullValueDescription>::insert_copy (
      _tao_any,
      CORBA::ValueDef::FullValueDescription::_tao_any_destructor,
      CORBA::ValueDef::_tc_FullValueDescription,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueDef::FullValueDescription *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ValueDef::FullValueDescription>::insert (
      _tao_any,
      CORBA::ValueDef::FullValueDescription::_tao_any_destructor,
      CORBA::ValueDef::_tc_FullValueDescription,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ValueDef::FullValueDescription *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ValueDef::FullValueDescription *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ValueDef::FullValueDescription *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ValueDef::FullValueDescription>::extract (
        _tao_any,
        CORBA::ValueDef::FullValueDescription::_tao_any_destructor,
        CORBA::ValueDef::_tc_FullValueDescription,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ValueDescription &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ValueDescription>::insert_copy (
      _tao_any,
      CORBA::ValueDescription::_tao_any_destructor,
      CORBA::_tc_ValueDescription,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueDescription *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ValueDescription>::insert (
      _tao_any,
      CORBA::ValueDescription::_tao_any_destructor,
      CORBA::_tc_ValueDescription,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ValueDescription *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ValueDescription *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ValueDescription *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ValueDescription>::extract (
        _tao_any,
        CORBA::ValueDescription::_tao_any_destructor,
        CORBA::_tc_ValueDescription,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<CORBA::ExtValueDef>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ExtValueDef_ptr _tao_elem
  )
{
  CORBA::ExtValueDef_ptr _tao_objptr =
    CORBA::ExtValueDef::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ExtValueDef_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::ExtValueDef>::insert (
      _tao_any,
      CORBA::ExtValueDef::_tao_any_destructor,
      CORBA::_tc_ExtValueDef,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ExtValueDef_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::ExtValueDef>::extract (
        _tao_any,
        CORBA::ExtValueDef::_tao_any_destructor,
        CORBA::_tc_ExtValueDef,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ExtValueDef::ExtFullValueDescription &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ExtValueDef::ExtFullValueDescription>::insert_copy (
      _tao_any,
      CORBA::ExtValueDef::ExtFullValueDescription::_tao_any_destructor,
      CORBA::ExtValueDef::_tc_ExtFullValueDescription,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ExtValueDef::ExtFullValueDescription *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ExtValueDef::ExtFullValueDescription>::insert (
      _tao_any,
      CORBA::ExtValueDef::ExtFullValueDescription::_tao_any_destructor,
      CORBA::ExtValueDef::_tc_ExtFullValueDescription,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ExtValueDef::ExtFullValueDescription *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ExtValueDef::ExtFullValueDescription *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ExtValueDef::ExtFullValueDescription *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ExtValueDef::ExtFullValueDescription>::extract (
        _tao_any,
        CORBA::ExtValueDef::ExtFullValueDescription::_tao_any_destructor,
        CORBA::ExtValueDef::_tc_ExtFullValueDescription,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

namespace TAO
{
  template<>
  CORBA::Boolean
  Any_Impl_T<CORBA::ValueBoxDef>::to_object (
      CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = CORBA::Object::_duplicate (this->value_);
    return true;
  }
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueBoxDef_ptr _tao_elem
  )
{
  CORBA::ValueBoxDef_ptr _tao_objptr =
    CORBA::ValueBoxDef::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ValueBoxDef_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::ValueBoxDef>::insert (
      _tao_any,
      CORBA::ValueBoxDef::_tao_any_destructor,
      CORBA::_tc_ValueBoxDef,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ValueBoxDef_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::ValueBoxDef>::extract (
        _tao_any,
        CORBA::ValueBoxDef::_tao_any_destructor,
        CORBA::_tc_ValueBoxDef,
        _tao_elem
      );
}
