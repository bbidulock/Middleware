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
#include "PortableInterceptorA.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Interceptor>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Interceptor>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Interceptor>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ForwardRequest>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if ((cdr >> id.out ()) == 0)
    {
      return 0;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return 0;
    }
  ACE_ENDTRY;
  
  return 1;
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
  return _tao_any >>= ACE_const_cast (
      const PortableInterceptor::ForwardRequest *&,
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
// be/be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::InvalidSlot>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if ((cdr >> id.out ()) == 0)
    {
      return 0;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return 0;
    }
  ACE_ENDTRY;
  
  return 1;
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
  return _tao_any >>= ACE_const_cast (
      const PortableInterceptor::InvalidSlot *&,
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Current>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Current>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::Current>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::RequestInfo>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::RequestInfo>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::RequestInfo>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInfo>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInfo>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInfo>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInfo>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInfo>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInfo>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ClientRequestInterceptor>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ServerRequestInterceptor>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::PolicyFactory>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::PolicyFactory>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::PolicyFactory>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitInfo>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitInfo>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitInfo>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
// be/be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::DuplicateName>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::DuplicateName>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
  return _tao_any >>= ACE_const_cast (
      const PortableInterceptor::ORBInitInfo::DuplicateName *&,
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
// be/be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::InvalidName>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<PortableInterceptor::ORBInitInfo::InvalidName>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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
  return _tao_any >>= ACE_const_cast (
      const PortableInterceptor::ORBInitInfo::InvalidName *&,
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
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitializer>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitializer>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<PortableInterceptor::ORBInitializer>::demarshal_value (TAO_InputCDR &)
{
  return 0;
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

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::Interceptor
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableInterceptor::ForwardRequest
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableInterceptor::InvalidSlot
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::Current
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::RequestInfo
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ClientRequestInfo
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ServerRequestInfo
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ClientRequestInterceptor
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ServerRequestInterceptor
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::PolicyFactory
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableInterceptor::ORBInitInfo::DuplicateName
      >;

  template class
    TAO::Any_Dual_Impl_T<
        PortableInterceptor::ORBInitInfo::InvalidName
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ORBInitInfo
      >;

  template class
    TAO::Any_Impl_T<
        PortableInterceptor::ORBInitializer
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::Interceptor \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableInterceptor::ForwardRequest \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableInterceptor::InvalidSlot \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::Current \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::RequestInfo \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ClientRequestInfo \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ServerRequestInfo \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ClientRequestInterceptor \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ServerRequestInterceptor \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::PolicyFactory \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableInterceptor::ORBInitInfo::DuplicateName \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        PortableInterceptor::ORBInitInfo::InvalidName \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ORBInitInfo \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        PortableInterceptor::ORBInitializer \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

