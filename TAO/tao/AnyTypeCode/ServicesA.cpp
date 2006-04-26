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

#include "tao/AnyTypeCode/ServicesA.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
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
  _tao_tc_CORBA_ServiceType (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ServiceType:1.0",
    "ServiceType",
    &CORBA::_tc_ushort);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ServiceType =
    &_tao_tc_CORBA_ServiceType;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ServiceOption (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ServiceOption:1.0",
    "ServiceOption",
    &CORBA::_tc_ulong);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ServiceOption =
    &_tao_tc_CORBA_ServiceOption;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ServiceDetailType (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ServiceDetailType:1.0",
    "ServiceDetailType",
    &CORBA::_tc_ulong);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ServiceDetailType =
    &_tao_tc_CORBA_ServiceDetailType;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ServiceDetailData (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ServiceDetailData:1.0",
    "ServiceDetailData",
    &CORBA::_tc_OctetSeq);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ServiceDetailData =
    &_tao_tc_CORBA_ServiceDetailData;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_CORBA_ServiceOptionSeq_GUARD
#define _TAO_TYPECODE_CORBA_ServiceOptionSeq_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      CORBA_ServiceOptionSeq_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_ServiceOption,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_CORBA_ServiceOptionSeq_0 =
      &CORBA_ServiceOptionSeq_0;
    
  }
}


#endif /* _TAO_TYPECODE_CORBA_ServiceOptionSeq_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ServiceOptionSeq (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ServiceOptionSeq:1.0",
    "ServiceOptionSeq",
    &TAO::TypeCode::tc_CORBA_ServiceOptionSeq_0);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ServiceOptionSeq =
    &_tao_tc_CORBA_ServiceOptionSeq;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_CORBA_ServiceDetail[] =
  {
    { "service_detail_type", &CORBA::_tc_ServiceDetailType },
    { "service_detail", &CORBA::_tc_ServiceDetailData }
    
  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ServiceDetail (
    CORBA::tk_struct,
    "IDL:omg.org/CORBA/ServiceDetail:1.0",
    "ServiceDetail",
    _tao_fields_CORBA_ServiceDetail,
    2);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ServiceDetail =
    &_tao_tc_CORBA_ServiceDetail;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_CORBA_ServiceDetailSeq_GUARD
#define _TAO_TYPECODE_CORBA_ServiceDetailSeq_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      CORBA_ServiceDetailSeq_0 (
        CORBA::tk_sequence,
        &CORBA::_tc_ServiceDetail,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_CORBA_ServiceDetailSeq_0 =
      &CORBA_ServiceDetailSeq_0;
    
  }
}


#endif /* _TAO_TYPECODE_CORBA_ServiceDetailSeq_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ServiceDetailSeq (
    CORBA::tk_alias,
    "IDL:omg.org/CORBA/ServiceDetailSeq:1.0",
    "ServiceDetailSeq",
    &TAO::TypeCode::tc_CORBA_ServiceDetailSeq_0);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ServiceDetailSeq =
    &_tao_tc_CORBA_ServiceDetailSeq;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_CORBA_ServiceInformation[] =
  {
    { "service_options", &CORBA::_tc_ServiceOptionSeq },
    { "service_details", &CORBA::_tc_ServiceDetailSeq }
    
  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_CORBA_ServiceInformation (
    CORBA::tk_struct,
    "IDL:omg.org/CORBA/ServiceInformation:1.0",
    "ServiceInformation",
    _tao_fields_CORBA_ServiceInformation,
    2);
  
namespace CORBA
{
  ::CORBA::TypeCode_ptr const _tc_ServiceInformation =
    &_tao_tc_CORBA_ServiceInformation;
}



// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceOptionSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceOptionSeq>::insert_copy (
      _tao_any,
      CORBA::ServiceOptionSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_ServiceOptionSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceOptionSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceOptionSeq>::insert (
      _tao_any,
      CORBA::ServiceOptionSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_ServiceOptionSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceOptionSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ServiceOptionSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceOptionSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceOptionSeq>::extract (
        _tao_any,
        CORBA::ServiceOptionSeq::_tao_any_destructor,
        TAO::TypeCode::tc_CORBA_ServiceOptionSeq_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceDetail &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::insert_copy (
      _tao_any,
      CORBA::ServiceDetail::_tao_any_destructor,
      CORBA::_tc_ServiceDetail,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceDetail *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::insert (
      _tao_any,
      CORBA::ServiceDetail::_tao_any_destructor,
      CORBA::_tc_ServiceDetail,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceDetail *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ServiceDetail *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceDetail *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceDetail>::extract (
        _tao_any,
        CORBA::ServiceDetail::_tao_any_destructor,
        CORBA::_tc_ServiceDetail,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceDetailSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetailSeq>::insert_copy (
      _tao_any,
      CORBA::ServiceDetailSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_ServiceDetailSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceDetailSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceDetailSeq>::insert (
      _tao_any,
      CORBA::ServiceDetailSeq::_tao_any_destructor,
      TAO::TypeCode::tc_CORBA_ServiceDetailSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceDetailSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ServiceDetailSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceDetailSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceDetailSeq>::extract (
        _tao_any,
        CORBA::ServiceDetailSeq::_tao_any_destructor,
        TAO::TypeCode::tc_CORBA_ServiceDetailSeq_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::ServiceInformation &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::insert_copy (
      _tao_any,
      CORBA::ServiceInformation::_tao_any_destructor,
      CORBA::_tc_ServiceInformation,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::ServiceInformation *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::insert (
      _tao_any,
      CORBA::ServiceInformation::_tao_any_destructor,
      CORBA::_tc_ServiceInformation,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::ServiceInformation *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::ServiceInformation *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::ServiceInformation *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::ServiceInformation>::extract (
        _tao_any,
        CORBA::ServiceInformation::_tao_any_destructor,
        CORBA::_tc_ServiceInformation,
        _tao_elem
      );
}

TAO_END_VERSIONED_NAMESPACE_DECL
