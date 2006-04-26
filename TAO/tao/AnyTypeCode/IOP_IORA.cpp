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

#include "tao/AnyTypeCode/IOP_IORA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_ProfileId (
    CORBA::tk_alias,
    "IDL:omg.org/IOP/ProfileId:1.0",
    "ProfileId",
    &CORBA::_tc_ulong);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_ProfileId =
    &_tao_tc_IOP_ProfileId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_IOP_TaggedProfile[] =
  {
    { "tag", &IOP::_tc_ProfileId },
    { "profile_data", &CORBA::_tc_OctetSeq }
    
  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_TaggedProfile (
    CORBA::tk_struct,
    "IDL:omg.org/IOP/TaggedProfile:1.0",
    "TaggedProfile",
    _tao_fields_IOP_TaggedProfile,
    2);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_TaggedProfile =
    &_tao_tc_IOP_TaggedProfile;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_IOP_TaggedProfileSeq_GUARD
#define _TAO_TYPECODE_IOP_TaggedProfileSeq_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      IOP_TaggedProfileSeq_0 (
        CORBA::tk_sequence,
        &IOP::_tc_TaggedProfile,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_IOP_TaggedProfileSeq_0 =
      &IOP_TaggedProfileSeq_0;
    
  }
}


#endif /* _TAO_TYPECODE_IOP_TaggedProfileSeq_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_TaggedProfileSeq (
    CORBA::tk_alias,
    "IDL:omg.org/IOP/TaggedProfileSeq:1.0",
    "TaggedProfileSeq",
    &TAO::TypeCode::tc_IOP_TaggedProfileSeq_0);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_TaggedProfileSeq =
    &_tao_tc_IOP_TaggedProfileSeq;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_IOP_IOR[] =
  {
    { "type_id", &CORBA::_tc_string },
    { "profiles", &IOP::_tc_TaggedProfileSeq }
    
  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_IOR (
    CORBA::tk_struct,
    "IDL:omg.org/IOP/IOR:1.0",
    "IOR",
    _tao_fields_IOP_IOR,
    2);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_IOR =
    &_tao_tc_IOP_IOR;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_ComponentId (
    CORBA::tk_alias,
    "IDL:omg.org/IOP/ComponentId:1.0",
    "ComponentId",
    &CORBA::_tc_ulong);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_ComponentId =
    &_tao_tc_IOP_ComponentId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_IOP_TaggedComponent[] =
  {
    { "tag", &IOP::_tc_ComponentId },
    { "component_data", &CORBA::_tc_OctetSeq }
    
  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_TaggedComponent (
    CORBA::tk_struct,
    "IDL:omg.org/IOP/TaggedComponent:1.0",
    "TaggedComponent",
    _tao_fields_IOP_TaggedComponent,
    2);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_TaggedComponent =
    &_tao_tc_IOP_TaggedComponent;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_IOP_MultipleComponentProfile_GUARD
#define _TAO_TYPECODE_IOP_MultipleComponentProfile_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      IOP_MultipleComponentProfile_0 (
        CORBA::tk_sequence,
        &IOP::_tc_TaggedComponent,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_IOP_MultipleComponentProfile_0 =
      &IOP_MultipleComponentProfile_0;
    
  }
}


#endif /* _TAO_TYPECODE_IOP_MultipleComponentProfile_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_MultipleComponentProfile (
    CORBA::tk_alias,
    "IDL:omg.org/IOP/MultipleComponentProfile:1.0",
    "MultipleComponentProfile",
    &TAO::TypeCode::tc_IOP_MultipleComponentProfile_0);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_MultipleComponentProfile =
    &_tao_tc_IOP_MultipleComponentProfile;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_IOP_TaggedComponentList_GUARD
#define _TAO_TYPECODE_IOP_TaggedComponentList_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      IOP_TaggedComponentList_0 (
        CORBA::tk_sequence,
        &IOP::_tc_TaggedComponent,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_IOP_TaggedComponentList_0 =
      &IOP_TaggedComponentList_0;
    
  }
}


#endif /* _TAO_TYPECODE_IOP_TaggedComponentList_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_TaggedComponentList (
    CORBA::tk_alias,
    "IDL:omg.org/IOP/TaggedComponentList:1.0",
    "TaggedComponentList",
    &TAO::TypeCode::tc_IOP_TaggedComponentList_0);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_TaggedComponentList =
    &_tao_tc_IOP_TaggedComponentList;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_IOP_TaggedComponentSeq_GUARD
#define _TAO_TYPECODE_IOP_TaggedComponentSeq_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      IOP_TaggedComponentSeq_0 (
        CORBA::tk_sequence,
        &IOP::_tc_TaggedComponent,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_IOP_TaggedComponentSeq_0 =
      &IOP_TaggedComponentSeq_0;
    
  }
}


#endif /* _TAO_TYPECODE_IOP_TaggedComponentSeq_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_TaggedComponentSeq (
    CORBA::tk_alias,
    "IDL:omg.org/IOP/TaggedComponentSeq:1.0",
    "TaggedComponentSeq",
    &TAO::TypeCode::tc_IOP_TaggedComponentSeq_0);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_TaggedComponentSeq =
    &_tao_tc_IOP_TaggedComponentSeq;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_ServiceId (
    CORBA::tk_alias,
    "IDL:omg.org/IOP/ServiceId:1.0",
    "ServiceId",
    &CORBA::_tc_ulong);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_ServiceId =
    &_tao_tc_IOP_ServiceId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_IOP_ServiceContext[] =
  {
    { "context_id", &IOP::_tc_ServiceId },
    { "context_data", &CORBA::_tc_OctetSeq }
    
  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_IOP_ServiceContext (
    CORBA::tk_struct,
    "IDL:omg.org/IOP/ServiceContext:1.0",
    "ServiceContext",
    _tao_fields_IOP_ServiceContext,
    2);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_ServiceContext =
    &_tao_tc_IOP_ServiceContext;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_IOP_ServiceContextList_GUARD
#define _TAO_TYPECODE_IOP_ServiceContextList_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      IOP_ServiceContextList_0 (
        CORBA::tk_sequence,
        &IOP::_tc_ServiceContext,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_IOP_ServiceContextList_0 =
      &IOP_ServiceContextList_0;
    
  }
}


#endif /* _TAO_TYPECODE_IOP_ServiceContextList_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IOP_ServiceContextList (
    CORBA::tk_alias,
    "IDL:omg.org/IOP/ServiceContextList:1.0",
    "ServiceContextList",
    &TAO::TypeCode::tc_IOP_ServiceContextList_0);
  
namespace IOP
{
  ::CORBA::TypeCode_ptr const _tc_ServiceContextList =
    &_tao_tc_IOP_ServiceContextList;
}



// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::TaggedProfile &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedProfile>::insert_copy (
      _tao_any,
      IOP::TaggedProfile::_tao_any_destructor,
      IOP::_tc_TaggedProfile,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::TaggedProfile *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedProfile>::insert (
      _tao_any,
      IOP::TaggedProfile::_tao_any_destructor,
      IOP::_tc_TaggedProfile,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::TaggedProfile *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::TaggedProfile *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::TaggedProfile *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::TaggedProfile>::extract (
        _tao_any,
        IOP::TaggedProfile::_tao_any_destructor,
        IOP::_tc_TaggedProfile,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::TaggedProfileSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedProfileSeq>::insert_copy (
      _tao_any,
      IOP::TaggedProfileSeq::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_TaggedProfileSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::TaggedProfileSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedProfileSeq>::insert (
      _tao_any,
      IOP::TaggedProfileSeq::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_TaggedProfileSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::TaggedProfileSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::TaggedProfileSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::TaggedProfileSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::TaggedProfileSeq>::extract (
        _tao_any,
        IOP::TaggedProfileSeq::_tao_any_destructor,
        TAO::TypeCode::tc_IOP_TaggedProfileSeq_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::IOR &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::IOR>::insert_copy (
      _tao_any,
      IOP::IOR::_tao_any_destructor,
      IOP::_tc_IOR,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::IOR *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::IOR>::insert (
      _tao_any,
      IOP::IOR::_tao_any_destructor,
      IOP::_tc_IOR,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::IOR *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::IOR *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::IOR *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::IOR>::extract (
        _tao_any,
        IOP::IOR::_tao_any_destructor,
        IOP::_tc_IOR,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::TaggedComponent &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedComponent>::insert_copy (
      _tao_any,
      IOP::TaggedComponent::_tao_any_destructor,
      IOP::_tc_TaggedComponent,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::TaggedComponent *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedComponent>::insert (
      _tao_any,
      IOP::TaggedComponent::_tao_any_destructor,
      IOP::_tc_TaggedComponent,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::TaggedComponent *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::TaggedComponent *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::TaggedComponent *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::TaggedComponent>::extract (
        _tao_any,
        IOP::TaggedComponent::_tao_any_destructor,
        IOP::_tc_TaggedComponent,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::MultipleComponentProfile &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::MultipleComponentProfile>::insert_copy (
      _tao_any,
      IOP::MultipleComponentProfile::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_MultipleComponentProfile_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::MultipleComponentProfile *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::MultipleComponentProfile>::insert (
      _tao_any,
      IOP::MultipleComponentProfile::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_MultipleComponentProfile_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::MultipleComponentProfile *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::MultipleComponentProfile *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::MultipleComponentProfile *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::MultipleComponentProfile>::extract (
        _tao_any,
        IOP::MultipleComponentProfile::_tao_any_destructor,
        TAO::TypeCode::tc_IOP_MultipleComponentProfile_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::TaggedComponentList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedComponentList>::insert_copy (
      _tao_any,
      IOP::TaggedComponentList::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_TaggedComponentList_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::TaggedComponentList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedComponentList>::insert (
      _tao_any,
      IOP::TaggedComponentList::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_TaggedComponentList_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::TaggedComponentList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::TaggedComponentList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::TaggedComponentList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::TaggedComponentList>::extract (
        _tao_any,
        IOP::TaggedComponentList::_tao_any_destructor,
        TAO::TypeCode::tc_IOP_TaggedComponentList_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::TaggedComponentSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedComponentSeq>::insert_copy (
      _tao_any,
      IOP::TaggedComponentSeq::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_TaggedComponentSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::TaggedComponentSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::TaggedComponentSeq>::insert (
      _tao_any,
      IOP::TaggedComponentSeq::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_TaggedComponentSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::TaggedComponentSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::TaggedComponentSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::TaggedComponentSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::TaggedComponentSeq>::extract (
        _tao_any,
        IOP::TaggedComponentSeq::_tao_any_destructor,
        TAO::TypeCode::tc_IOP_TaggedComponentSeq_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::ServiceContext &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::ServiceContext>::insert_copy (
      _tao_any,
      IOP::ServiceContext::_tao_any_destructor,
      IOP::_tc_ServiceContext,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::ServiceContext *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::ServiceContext>::insert (
      _tao_any,
      IOP::ServiceContext::_tao_any_destructor,
      IOP::_tc_ServiceContext,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::ServiceContext *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::ServiceContext *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::ServiceContext *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::ServiceContext>::extract (
        _tao_any,
        IOP::ServiceContext::_tao_any_destructor,
        IOP::_tc_ServiceContext,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IOP::ServiceContextList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::ServiceContextList>::insert_copy (
      _tao_any,
      IOP::ServiceContextList::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_ServiceContextList_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    IOP::ServiceContextList *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IOP::ServiceContextList>::insert (
      _tao_any,
      IOP::ServiceContextList::_tao_any_destructor,
      TAO::TypeCode::tc_IOP_ServiceContextList_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IOP::ServiceContextList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IOP::ServiceContextList *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const IOP::ServiceContextList *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<IOP::ServiceContextList>::extract (
        _tao_any,
        IOP::ServiceContextList::_tao_any_destructor,
        TAO::TypeCode::tc_IOP_ServiceContextList_0,
        _tao_elem
      );
}

TAO_END_VERSIONED_NAMESPACE_DECL
