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

#include "PS_CurrentC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/Struct_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:34

static TAO::TypeCode::Struct_Field<char const *> const _tao_fields_PortableServer_Current_NoContext[] =
  {
    
  };

static TAO::TypeCode::Struct<char const *,
                             TAO::TypeCode::Struct_Field<char const *> const *,
                             CORBA::tk_except,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_Current_NoContext (
    "IDL:omg.org/PortableServer/Current/NoContext:2.3",
    "NoContext",
    _tao_fields_PortableServer_Current_NoContext,
    0);
  
::CORBA::TypeCode_ptr const PortableServer::Current::_tc_NoContext =
  &_tao_tc_PortableServer_Current_NoContext;

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:73

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableServer_Current (
    "IDL:omg.org/PortableServer/Current:2.3",
    "Current");
  
namespace PortableServer
{
  ::CORBA::TypeCode_ptr const _tc_Current =
    &_tao_tc_PortableServer_Current;
}



// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::Current>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::Current>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableServer::Current>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::Current_ptr _tao_elem
  )
{
  PortableServer::Current_ptr _tao_objptr =
    PortableServer::Current::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::Current_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableServer::Current>::insert (
      _tao_any,
      PortableServer::Current::_tao_any_destructor,
      PortableServer::_tc_Current,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::Current_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableServer::Current>::extract (
        _tao_any,
        PortableServer::Current::_tao_any_destructor,
        PortableServer::_tc_Current,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::Current::NoContext>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableServer::Current::NoContext>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableServer::Current::NoContext &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::Current::NoContext>::insert_copy (
      _tao_any,
      PortableServer::Current::NoContext::_tao_any_destructor,
      PortableServer::Current::_tc_NoContext,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableServer::Current::NoContext *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableServer::Current::NoContext>::insert (
      _tao_any,
      PortableServer::Current::NoContext::_tao_any_destructor,
      PortableServer::Current::_tc_NoContext,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableServer::Current::NoContext *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableServer::Current::NoContext *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableServer::Current::NoContext *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableServer::Current::NoContext>::extract (
        _tao_any,
        PortableServer::Current::NoContext::_tao_any_destructor,
        PortableServer::Current::_tc_NoContext,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Dual_Impl_T<
        PortableServer::Current::NoContext
      >;

  template class
    TAO::Any_Impl_T<
        PortableServer::Current
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableServer::Current::NoContext \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableServer::Current \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
