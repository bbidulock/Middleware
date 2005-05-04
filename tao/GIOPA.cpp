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

#include "GIOPC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode_Static.h"
#include "tao/String_TypeCode_Static.h"
#include "tao/Struct_TypeCode_Static.h"
#include "tao/TypeCode_Struct_Field.h"
#include "tao/TypeCode_Non_Default_Case.h"
#include "tao/TypeCode_Default_Case.h"
#include "tao/Union_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_GIOP_AddressingDisposition (
    CORBA::tk_alias,
    "IDL:omg.org/GIOP/AddressingDisposition:1.0",
    "AddressingDisposition",
    &CORBA::_tc_short);
  
namespace GIOP
{
  ::CORBA::TypeCode_ptr const _tc_AddressingDisposition =
    &_tao_tc_GIOP_AddressingDisposition;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_GIOP_Version[] =
  {
    { "major", &CORBA::_tc_octet },
    { "minor", &CORBA::_tc_octet }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_GIOP_Version (
    CORBA::tk_struct,
    "IDL:omg.org/GIOP/Version:1.0",
    "Version",
    _tao_fields_GIOP_Version,
    2);
  
namespace GIOP
{
  ::CORBA::TypeCode_ptr const _tc_Version =
    &_tao_tc_GIOP_Version;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/struct_typecode.cpp:74

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_GIOP_IORAddressingInfo[] =
  {
    { "selected_profile_index", &CORBA::_tc_ulong },
    { "ior", &IOP::_tc_IOR }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_GIOP_IORAddressingInfo (
    CORBA::tk_struct,
    "IDL:omg.org/GIOP/IORAddressingInfo:1.0",
    "IORAddressingInfo",
    _tao_fields_GIOP_IORAddressingInfo,
    2);
  
namespace GIOP
{
  ::CORBA::TypeCode_ptr const _tc_IORAddressingInfo =
    &_tao_tc_GIOP_IORAddressingInfo;
}



// TAO_IDL - Generated from
// be/be_visitor_typecode/union_typecode.cpp:47

static TAO::TypeCode::Non_Default_Case<CORBA::Short, char const *, CORBA::TypeCode_ptr const *> const _tao_cases_GIOP_TargetAddress_0 (0, "object_key", &CORBA::_tc_OctetSeq);
static TAO::TypeCode::Non_Default_Case<CORBA::Short, char const *, CORBA::TypeCode_ptr const *> const _tao_cases_GIOP_TargetAddress_1 (1, "profile", &IOP::_tc_TaggedProfile);
static TAO::TypeCode::Non_Default_Case<CORBA::Short, char const *, CORBA::TypeCode_ptr const *> const _tao_cases_GIOP_TargetAddress_2 (2, "ior", &GIOP::_tc_IORAddressingInfo);

static TAO::TypeCode::Case<char const *, CORBA::TypeCode_ptr const *> const * const _tao_cases_GIOP_TargetAddress[] =
  {
    &_tao_cases_GIOP_TargetAddress_0,
    &_tao_cases_GIOP_TargetAddress_1,
    &_tao_cases_GIOP_TargetAddress_2
    
  };

static TAO::TypeCode::Union<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::TypeCode::Case<char const *,
                                                CORBA::TypeCode_ptr const *> const * const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_GIOP_TargetAddress (
    "IDL:omg.org/GIOP/TargetAddress:1.0",
    "TargetAddress",
    &CORBA::_tc_short,
    _tao_cases_GIOP_TargetAddress,
    3, -1);
  
namespace GIOP
{
  ::CORBA::TypeCode_ptr const _tc_TargetAddress =
    &_tao_tc_GIOP_TargetAddress;
}



// TAO_IDL - Generated from 
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const GIOP::Version &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<GIOP::Version>::insert_copy (
      _tao_any,
      GIOP::Version::_tao_any_destructor,
      GIOP::_tc_Version,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    GIOP::Version *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<GIOP::Version>::insert (
      _tao_any,
      GIOP::Version::_tao_any_destructor,
      GIOP::_tc_Version,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    GIOP::Version *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const GIOP::Version *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const GIOP::Version *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<GIOP::Version>::extract (
        _tao_any,
        GIOP::Version::_tao_any_destructor,
        GIOP::_tc_Version,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const GIOP::IORAddressingInfo &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<GIOP::IORAddressingInfo>::insert_copy (
      _tao_any,
      GIOP::IORAddressingInfo::_tao_any_destructor,
      GIOP::_tc_IORAddressingInfo,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    GIOP::IORAddressingInfo *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<GIOP::IORAddressingInfo>::insert (
      _tao_any,
      GIOP::IORAddressingInfo::_tao_any_destructor,
      GIOP::_tc_IORAddressingInfo,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    GIOP::IORAddressingInfo *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const GIOP::IORAddressingInfo *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const GIOP::IORAddressingInfo *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<GIOP::IORAddressingInfo>::extract (
        _tao_any,
        GIOP::IORAddressingInfo::_tao_any_destructor,
        GIOP::_tc_IORAddressingInfo,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be/be_visitor_union/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const GIOP::TargetAddress &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<GIOP::TargetAddress>::insert_copy (
      _tao_any,
      GIOP::TargetAddress::_tao_any_destructor,
      GIOP::_tc_TargetAddress,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    GIOP::TargetAddress *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<GIOP::TargetAddress>::insert (
      _tao_any,
      GIOP::TargetAddress::_tao_any_destructor,
      GIOP::_tc_TargetAddress,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    GIOP::TargetAddress *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const GIOP::TargetAddress *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const GIOP::TargetAddress *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<GIOP::TargetAddress>::extract (
        _tao_any,
        GIOP::TargetAddress::_tao_any_destructor,
        GIOP::_tc_TargetAddress,
        _tao_elem
      );
}
