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

#include "IIOPC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Sequence_TypeCode.h"
#include "tao/String_TypeCode.h"
#include "tao/Struct_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *> const _tao_fields_IIOP_ListenPoint[] =
  {
    { "host", &CORBA::_tc_string },
    { "port", &CORBA::_tc_ushort }
    
  };
static TAO::TypeCode::Struct<char const *,
                             TAO::TypeCode::Struct_Field<char const *> const *,
                             CORBA::tk_struct,
                             TAO::Null_RefCount_Policy>
  _tao_tc_IIOP_ListenPoint (
    "IDL:omg.org/IIOP/ListenPoint:1.0",
    "ListenPoint",
    _tao_fields_IIOP_ListenPoint,
    2);
  
namespace IIOP
{
  ::CORBA::TypeCode_ptr const _tc_ListenPoint =
    &_tao_tc_IIOP_ListenPoint;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:808

namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence<TAO::Null_RefCount_Policy>
      IIOP_ListenPointList_0 (
        CORBA::tk_sequence,
        &IIOP::_tc_ListenPoint,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_IIOP_ListenPointList_0 =
      &IIOP_ListenPointList_0;
    
  }
}

static TAO::TypeCode::Alias<char const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_IIOP_ListenPointList (
    "IDL:omg.org/IIOP/ListenPointList:1.0",
    "ListenPointList",
    &TAO::TypeCode::tc_IIOP_ListenPointList_0);
  
namespace IIOP
{
  ::CORBA::TypeCode_ptr const _tc_ListenPointList =
    &_tao_tc_IIOP_ListenPointList;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *> const _tao_fields_IIOP_BiDirIIOPServiceContext[] =
  {
    { "listen_points", &IIOP::_tc_ListenPointList }
    
  };
static TAO::TypeCode::Struct<char const *,
                             TAO::TypeCode::Struct_Field<char const *> const *,
                             CORBA::tk_struct,
                             TAO::Null_RefCount_Policy>
  _tao_tc_IIOP_BiDirIIOPServiceContext (
    "IDL:omg.org/IIOP/BiDirIIOPServiceContext:1.0",
    "BiDirIIOPServiceContext",
    _tao_fields_IIOP_BiDirIIOPServiceContext,
    1);
  
namespace IIOP
{
  ::CORBA::TypeCode_ptr const _tc_BiDirIIOPServiceContext =
    &_tao_tc_IIOP_BiDirIIOPServiceContext;
}



// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

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
  return _tao_any >>= const_cast<
      const IIOP::ListenPoint *&> (
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

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const IIOP::ListenPointList &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<IIOP::ListenPointList>::insert_copy (
      _tao_any,
      IIOP::ListenPointList::_tao_any_destructor,
      TAO::TypeCode::tc_IIOP_ListenPointList_0,
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
      TAO::TypeCode::tc_IIOP_ListenPointList_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    IIOP::ListenPointList *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const IIOP::ListenPointList *&> (
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
        TAO::TypeCode::tc_IIOP_ListenPointList_0,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

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
  return _tao_any >>= const_cast<
      const IIOP::BiDirIIOPServiceContext *&> (
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

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        IIOP::ListenPoint
      >;

  template class
    TAO::Any_Dual_Impl_T<
        IIOP::ListenPointList
      >;

  template class
    TAO::Any_Dual_Impl_T<
        IIOP::BiDirIIOPServiceContext
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        IIOP::ListenPoint \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        IIOP::ListenPointList \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        IIOP::BiDirIIOPServiceContext \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
