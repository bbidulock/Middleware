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

#include "PortableInterceptorC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode.h"
#include "tao/Objref_TypeCode.h"
#include "tao/String_TypeCode.h"
#include "tao/Struct_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_Interceptor (
    "IDL:omg.org/PortableInterceptor/Interceptor:1.0",
    "Interceptor");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_Interceptor =
    &_tao_tc_PortableInterceptor_Interceptor;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_PortableInterceptor_ForwardRequest[] =
  {
    { "forward", &CORBA::_tc_Object },
    { "permanent", &CORBA::_tc_boolean }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ForwardRequest (
    CORBA::tk_except,
    "IDL:omg.org/PortableInterceptor/ForwardRequest:1.0",
    "ForwardRequest",
    _tao_fields_PortableInterceptor_ForwardRequest,
    2);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ForwardRequest =
    &_tao_tc_PortableInterceptor_ForwardRequest;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            CORBA::tk_alias,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ReplyStatus (
    "IDL:omg.org/PortableInterceptor/ReplyStatus:1.0",
    "ReplyStatus",
    &CORBA::_tc_short);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ReplyStatus =
    &_tao_tc_PortableInterceptor_ReplyStatus;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            CORBA::tk_alias,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_SlotId (
    "IDL:omg.org/PortableInterceptor/SlotId:1.0",
    "SlotId",
    &CORBA::_tc_ulong);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_SlotId =
    &_tao_tc_PortableInterceptor_SlotId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableInterceptor_InvalidSlot = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_InvalidSlot (
    CORBA::tk_except,
    "IDL:omg.org/PortableInterceptor/InvalidSlot:1.0",
    "InvalidSlot",
    _tao_fields_PortableInterceptor_InvalidSlot,
    0);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_InvalidSlot =
    &_tao_tc_PortableInterceptor_InvalidSlot;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_Current (
    "IDL:omg.org/PortableInterceptor/Current:1.0",
    "Current");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_Current =
    &_tao_tc_PortableInterceptor_Current;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_RequestInfo (
    "IDL:omg.org/PortableInterceptor/RequestInfo:1.0",
    "RequestInfo");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_RequestInfo =
    &_tao_tc_PortableInterceptor_RequestInfo;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ClientRequestInfo (
    "IDL:omg.org/PortableInterceptor/ClientRequestInfo:1.0",
    "ClientRequestInfo");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ClientRequestInfo =
    &_tao_tc_PortableInterceptor_ClientRequestInfo;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ServerRequestInfo (
    "IDL:omg.org/PortableInterceptor/ServerRequestInfo:1.0",
    "ServerRequestInfo");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ServerRequestInfo =
    &_tao_tc_PortableInterceptor_ServerRequestInfo;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ClientRequestInterceptor (
    "IDL:omg.org/PortableInterceptor/ClientRequestInterceptor:1.0",
    "ClientRequestInterceptor");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ClientRequestInterceptor =
    &_tao_tc_PortableInterceptor_ClientRequestInterceptor;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ServerRequestInterceptor (
    "IDL:omg.org/PortableInterceptor/ServerRequestInterceptor:1.0",
    "ServerRequestInterceptor");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ServerRequestInterceptor =
    &_tao_tc_PortableInterceptor_ServerRequestInterceptor;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_PolicyFactory (
    "IDL:omg.org/PortableInterceptor/PolicyFactory:1.0",
    "PolicyFactory");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_PolicyFactory =
    &_tao_tc_PortableInterceptor_PolicyFactory;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:31

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            CORBA::tk_alias,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo_ObjectId (
    "IDL:omg.org/PortableInterceptor/ORBInitInfo/ObjectId:1.0",
    "ObjectId",
    &CORBA::_tc_string);
  
::CORBA::TypeCode_ptr const PortableInterceptor::ORBInitInfo::_tc_ObjectId =
  &_tao_tc_PortableInterceptor_ORBInitInfo_ObjectId;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_PortableInterceptor_ORBInitInfo_DuplicateName[] =
  {
    { "name", &CORBA::_tc_string }
    
  };
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo_DuplicateName (
    CORBA::tk_except,
    "IDL:omg.org/PortableInterceptor/ORBInitInfo/DuplicateName:1.0",
    "DuplicateName",
    _tao_fields_PortableInterceptor_ORBInitInfo_DuplicateName,
    1);
  
::CORBA::TypeCode_ptr const PortableInterceptor::ORBInitInfo::_tc_DuplicateName =
  &_tao_tc_PortableInterceptor_ORBInitInfo_DuplicateName;

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:70

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const * const _tao_fields_PortableInterceptor_ORBInitInfo_InvalidName = 0;
static TAO::TypeCode::Struct<char const *,
                             CORBA::TypeCode_ptr const *,
                             TAO::TypeCode::Struct_Field<char const *,
                                                         CORBA::TypeCode_ptr const *> const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo_InvalidName (
    CORBA::tk_except,
    "IDL:omg.org/PortableInterceptor/ORBInitInfo/InvalidName:1.0",
    "InvalidName",
    _tao_fields_PortableInterceptor_ORBInitInfo_InvalidName,
    0);
  
::CORBA::TypeCode_ptr const PortableInterceptor::ORBInitInfo::_tc_InvalidName =
  &_tao_tc_PortableInterceptor_ORBInitInfo_InvalidName;

// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitInfo (
    "IDL:omg.org/PortableInterceptor/ORBInitInfo:1.0",
    "ORBInitInfo");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ORBInitInfo =
    &_tao_tc_PortableInterceptor_ORBInitInfo;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/objref_typecode.cpp:76

static TAO::TypeCode::Objref<char const *,
                             CORBA::tk_local_interface,
                             TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBInitializer (
    "IDL:omg.org/PortableInterceptor/ORBInitializer:1.0",
    "ORBInitializer");
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ORBInitializer =
    &_tao_tc_PortableInterceptor_ORBInitializer;
}



// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Interceptor>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Interceptor>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Interceptor>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::Interceptor_ptr _tao_elem
  )
{
  PortableInterceptor::Interceptor_ptr _tao_objptr =
    PortableInterceptor::Interceptor::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::Interceptor_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::Interceptor>::insert (
      _tao_any,
      PortableInterceptor::Interceptor::_tao_any_destructor,
      PortableInterceptor::_tc_Interceptor,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::Interceptor_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::Interceptor>::extract (
        _tao_any,
        PortableInterceptor::Interceptor::_tao_any_destructor,
        PortableInterceptor::_tc_Interceptor,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if (!(cdr >> id.out ()))
    {
      return false;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;
  
  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableInterceptor::ForwardRequest &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::insert_copy (
      _tao_any,
      PortableInterceptor::ForwardRequest::_tao_any_destructor,
      PortableInterceptor::_tc_ForwardRequest,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ForwardRequest *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::insert (
      _tao_any,
      PortableInterceptor::ForwardRequest::_tao_any_destructor,
      PortableInterceptor::_tc_ForwardRequest,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ForwardRequest *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableInterceptor::ForwardRequest *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableInterceptor::ForwardRequest *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::extract (
        _tao_any,
        PortableInterceptor::ForwardRequest::_tao_any_destructor,
        PortableInterceptor::_tc_ForwardRequest,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::InvalidSlot>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if (!(cdr >> id.out ()))
    {
      return false;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;
  
  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableInterceptor::InvalidSlot &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::InvalidSlot>::insert_copy (
      _tao_any,
      PortableInterceptor::InvalidSlot::_tao_any_destructor,
      PortableInterceptor::_tc_InvalidSlot,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::InvalidSlot *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::InvalidSlot>::insert (
      _tao_any,
      PortableInterceptor::InvalidSlot::_tao_any_destructor,
      PortableInterceptor::_tc_InvalidSlot,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::InvalidSlot *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableInterceptor::InvalidSlot *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableInterceptor::InvalidSlot *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableInterceptor::InvalidSlot>::extract (
        _tao_any,
        PortableInterceptor::InvalidSlot::_tao_any_destructor,
        PortableInterceptor::_tc_InvalidSlot,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Current>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Current>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Current>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::Current_ptr _tao_elem
  )
{
  PortableInterceptor::Current_ptr _tao_objptr =
    PortableInterceptor::Current::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::Current_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::Current>::insert (
      _tao_any,
      PortableInterceptor::Current::_tao_any_destructor,
      PortableInterceptor::_tc_Current,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::Current_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::Current>::extract (
        _tao_any,
        PortableInterceptor::Current::_tao_any_destructor,
        PortableInterceptor::_tc_Current,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::RequestInfo>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::RequestInfo>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::RequestInfo>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::RequestInfo_ptr _tao_elem
  )
{
  PortableInterceptor::RequestInfo_ptr _tao_objptr =
    PortableInterceptor::RequestInfo::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::RequestInfo_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::RequestInfo>::insert (
      _tao_any,
      PortableInterceptor::RequestInfo::_tao_any_destructor,
      PortableInterceptor::_tc_RequestInfo,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::RequestInfo_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::RequestInfo>::extract (
        _tao_any,
        PortableInterceptor::RequestInfo::_tao_any_destructor,
        PortableInterceptor::_tc_RequestInfo,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInfo>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInfo>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInfo>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInfo_ptr _tao_elem
  )
{
  PortableInterceptor::ClientRequestInfo_ptr _tao_objptr =
    PortableInterceptor::ClientRequestInfo::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInfo_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ClientRequestInfo>::insert (
      _tao_any,
      PortableInterceptor::ClientRequestInfo::_tao_any_destructor,
      PortableInterceptor::_tc_ClientRequestInfo,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInfo_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ClientRequestInfo>::extract (
        _tao_any,
        PortableInterceptor::ClientRequestInfo::_tao_any_destructor,
        PortableInterceptor::_tc_ClientRequestInfo,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInfo>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInfo>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInfo>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInfo_ptr _tao_elem
  )
{
  PortableInterceptor::ServerRequestInfo_ptr _tao_objptr =
    PortableInterceptor::ServerRequestInfo::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInfo_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ServerRequestInfo>::insert (
      _tao_any,
      PortableInterceptor::ServerRequestInfo::_tao_any_destructor,
      PortableInterceptor::_tc_ServerRequestInfo,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInfo_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ServerRequestInfo>::extract (
        _tao_any,
        PortableInterceptor::ServerRequestInfo::_tao_any_destructor,
        PortableInterceptor::_tc_ServerRequestInfo,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInterceptor_ptr _tao_elem
  )
{
  PortableInterceptor::ClientRequestInterceptor_ptr _tao_objptr =
    PortableInterceptor::ClientRequestInterceptor::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInterceptor_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::insert (
      _tao_any,
      PortableInterceptor::ClientRequestInterceptor::_tao_any_destructor,
      PortableInterceptor::_tc_ClientRequestInterceptor,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ClientRequestInterceptor_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::extract (
        _tao_any,
        PortableInterceptor::ClientRequestInterceptor::_tao_any_destructor,
        PortableInterceptor::_tc_ClientRequestInterceptor,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInterceptor_ptr _tao_elem
  )
{
  PortableInterceptor::ServerRequestInterceptor_ptr _tao_objptr =
    PortableInterceptor::ServerRequestInterceptor::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInterceptor_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::insert (
      _tao_any,
      PortableInterceptor::ServerRequestInterceptor::_tao_any_destructor,
      PortableInterceptor::_tc_ServerRequestInterceptor,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ServerRequestInterceptor_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::extract (
        _tao_any,
        PortableInterceptor::ServerRequestInterceptor::_tao_any_destructor,
        PortableInterceptor::_tc_ServerRequestInterceptor,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::PolicyFactory>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::PolicyFactory>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::PolicyFactory>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::PolicyFactory_ptr _tao_elem
  )
{
  PortableInterceptor::PolicyFactory_ptr _tao_objptr =
    PortableInterceptor::PolicyFactory::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::PolicyFactory_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::PolicyFactory>::insert (
      _tao_any,
      PortableInterceptor::PolicyFactory::_tao_any_destructor,
      PortableInterceptor::_tc_PolicyFactory,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::PolicyFactory_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::PolicyFactory>::extract (
        _tao_any,
        PortableInterceptor::PolicyFactory::_tao_any_destructor,
        PortableInterceptor::_tc_PolicyFactory,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitInfo>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitInfo>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitInfo>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitInfo_ptr _tao_elem
  )
{
  PortableInterceptor::ORBInitInfo_ptr _tao_objptr =
    PortableInterceptor::ORBInitInfo::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitInfo_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ORBInitInfo>::insert (
      _tao_any,
      PortableInterceptor::ORBInitInfo::_tao_any_destructor,
      PortableInterceptor::_tc_ORBInitInfo,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitInfo_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ORBInitInfo>::extract (
        _tao_any,
        PortableInterceptor::ORBInitInfo::_tao_any_destructor,
        PortableInterceptor::_tc_ORBInitInfo,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::DuplicateName>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::DuplicateName>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableInterceptor::ORBInitInfo::DuplicateName &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::DuplicateName>::insert_copy (
      _tao_any,
      PortableInterceptor::ORBInitInfo::DuplicateName::_tao_any_destructor,
      PortableInterceptor::ORBInitInfo::_tc_DuplicateName,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitInfo::DuplicateName *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::DuplicateName>::insert (
      _tao_any,
      PortableInterceptor::ORBInitInfo::DuplicateName::_tao_any_destructor,
      PortableInterceptor::ORBInitInfo::_tc_DuplicateName,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitInfo::DuplicateName *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableInterceptor::ORBInitInfo::DuplicateName *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableInterceptor::ORBInitInfo::DuplicateName *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::DuplicateName>::extract (
        _tao_any,
        PortableInterceptor::ORBInitInfo::DuplicateName::_tao_any_destructor,
        PortableInterceptor::ORBInitInfo::_tc_DuplicateName,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::InvalidName>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::InvalidName>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const PortableInterceptor::ORBInitInfo::InvalidName &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::InvalidName>::insert_copy (
      _tao_any,
      PortableInterceptor::ORBInitInfo::InvalidName::_tao_any_destructor,
      PortableInterceptor::ORBInitInfo::_tc_InvalidName,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitInfo::InvalidName *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::InvalidName>::insert (
      _tao_any,
      PortableInterceptor::ORBInitInfo::InvalidName::_tao_any_destructor,
      PortableInterceptor::ORBInitInfo::_tc_InvalidName,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitInfo::InvalidName *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const PortableInterceptor::ORBInitInfo::InvalidName *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const PortableInterceptor::ORBInitInfo::InvalidName *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::InvalidName>::extract (
        _tao_any,
        PortableInterceptor::ORBInitInfo::InvalidName::_tao_any_destructor,
        PortableInterceptor::ORBInitInfo::_tc_InvalidName,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitializer>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return true;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitializer>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

template<>
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitializer>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitializer_ptr _tao_elem
  )
{
  PortableInterceptor::ORBInitializer_ptr _tao_objptr =
    PortableInterceptor::ORBInitializer::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitializer_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<PortableInterceptor::ORBInitializer>::insert (
      _tao_any,
      PortableInterceptor::ORBInitializer::_tao_any_destructor,
      PortableInterceptor::_tc_ORBInitializer,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    PortableInterceptor::ORBInitializer_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<PortableInterceptor::ORBInitializer>::extract (
        _tao_any,
        PortableInterceptor::ORBInitializer::_tao_any_destructor,
        PortableInterceptor::_tc_ORBInitializer,
        _tao_elem
      );
}
