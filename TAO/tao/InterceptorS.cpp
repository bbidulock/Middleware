/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "InterceptorS.h"

// skeleton constructor
POA_PortableInterceptor::Cookie::Cookie (void)
{

}

// skeleton destructor
POA_PortableInterceptor::Cookie::~Cookie (void)
{
}

CORBA::Boolean POA_PortableInterceptor::Cookie::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/Cookie:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_PortableInterceptor::Cookie::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/PortableInterceptor/Cookie:1.0") == 0)
    return ACE_static_cast (POA_PortableInterceptor::Cookie_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_PortableInterceptor::Cookie::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/Cookie:1.0";
}

PortableInterceptor::Cookie*
POA_PortableInterceptor::Cookie::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  return new POA_PortableInterceptor::_tao_direct_collocated_Cookie (this, stub);
}

POA_PortableInterceptor::_tao_direct_collocated_Cookie::_tao_direct_collocated_Cookie (
    POA_PortableInterceptor::Cookie_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (PortableInterceptor,Cookie) (),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_Cookie::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}


POA_PortableInterceptor::Cookie_ptr POA_PortableInterceptor::_tao_direct_collocated_Cookie::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_Cookie::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}


char * POA_PortableInterceptor::_tao_direct_collocated_Cookie::myname  (

  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->myname (

    );

}



// skeleton constructor
POA_PortableInterceptor::RequestInfo::RequestInfo (void)
{

}

// skeleton destructor
POA_PortableInterceptor::RequestInfo::~RequestInfo (void)
{
}

CORBA::Boolean POA_PortableInterceptor::RequestInfo::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/RequestInfo:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_PortableInterceptor::RequestInfo::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/PortableInterceptor/RequestInfo:1.0") == 0)
    return ACE_static_cast (POA_PortableInterceptor::RequestInfo_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_PortableInterceptor::RequestInfo::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/RequestInfo:1.0";
}

PortableInterceptor::RequestInfo*
POA_PortableInterceptor::RequestInfo::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  return new POA_PortableInterceptor::_tao_direct_collocated_RequestInfo (this, stub);
}

POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::_tao_direct_collocated_RequestInfo (
    POA_PortableInterceptor::RequestInfo_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (PortableInterceptor,RequestInfo) (),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}


POA_PortableInterceptor::RequestInfo_ptr POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}


CORBA::ULong POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::get_request_id  (

  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->get_request_id (

    );

}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::response_expected  (

  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->response_expected (

    );

}

IOP::ServiceContextList * POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::get_service_contexts  (

  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->get_service_contexts (

    );

}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::set_service_contexts  (
    const IOP::ServiceContextList & sc
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->set_service_contexts (
      sc
    );

}

CORBA::Object_ptr POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::get_object  (

  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->get_object (

    );

}

char * POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::get_operation  (

  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->get_operation (

    );

}

CORBA::NVList_ptr POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::get_arguments  (

  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->get_arguments (

    );

}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_RequestInfo::set_arguments  (
    CORBA::NVList_ptr args
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->set_arguments (
      args
    );

}



// skeleton constructor
POA_PortableInterceptor::Interceptor::Interceptor (void)
{

}

// skeleton destructor
POA_PortableInterceptor::Interceptor::~Interceptor (void)
{
}

CORBA::Boolean POA_PortableInterceptor::Interceptor::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/Interceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_PortableInterceptor::Interceptor::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/PortableInterceptor/Interceptor:1.0") == 0)
    return ACE_static_cast (POA_PortableInterceptor::Interceptor_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_PortableInterceptor::Interceptor::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/Interceptor:1.0";
}

PortableInterceptor::Interceptor*
POA_PortableInterceptor::Interceptor::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  return new POA_PortableInterceptor::_tao_direct_collocated_Interceptor (this, stub);
}

POA_PortableInterceptor::_tao_direct_collocated_Interceptor::_tao_direct_collocated_Interceptor (
    POA_PortableInterceptor::Interceptor_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (PortableInterceptor,Interceptor) (),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_Interceptor::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}


POA_PortableInterceptor::Interceptor_ptr POA_PortableInterceptor::_tao_direct_collocated_Interceptor::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_Interceptor::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}


char * POA_PortableInterceptor::_tao_direct_collocated_Interceptor::name  (

  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return this->servant_->name (

    );

}



// skeleton constructor
POA_PortableInterceptor::ServerRequestInterceptor::ServerRequestInterceptor (void)
{

}

// skeleton destructor
POA_PortableInterceptor::ServerRequestInterceptor::~ServerRequestInterceptor (void)
{
}

CORBA::Boolean POA_PortableInterceptor::ServerRequestInterceptor::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/Interceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_PortableInterceptor::ServerRequestInterceptor::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0") == 0)
    return ACE_static_cast (POA_PortableInterceptor::ServerRequestInterceptor_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/PortableInterceptor/Interceptor:1.0") == 0)
    return ACE_static_cast (POA_PortableInterceptor::Interceptor_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_PortableInterceptor::ServerRequestInterceptor::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0";
}

PortableInterceptor::ServerRequestInterceptor*
POA_PortableInterceptor::ServerRequestInterceptor::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  return new POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor (this, stub);
}

POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor::_tao_direct_collocated_ServerRequestInterceptor (
    POA_PortableInterceptor::ServerRequestInterceptor_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (PortableInterceptor,ServerRequestInterceptor) (),
    ACE_NESTED_CLASS (POA_PortableInterceptor,_tao_direct_collocated_Interceptor) (servant, stub),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}


POA_PortableInterceptor::ServerRequestInterceptor_ptr POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}


void POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor::preinvoke  (
    PortableInterceptor::RequestInfo_ptr & ri,
    PortableInterceptor::Cookies & ck
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->servant_->preinvoke (
      ri,
      ck
    );

}

void POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor::postinvoke  (
    PortableInterceptor::RequestInfo_ptr & ri,
    PortableInterceptor::Cookies & ck
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->servant_->postinvoke (
      ri,
      ck
    );

}

void POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor::exception_occurred  (
    PortableInterceptor::RequestInfo_ptr & ri,
    PortableInterceptor::Cookies & ck
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->servant_->exception_occurred (
      ri,
      ck
    );

}



// skeleton constructor
POA_PortableInterceptor::ClientRequestInterceptor::ClientRequestInterceptor (void)
{

}

// skeleton destructor
POA_PortableInterceptor::ClientRequestInterceptor::~ClientRequestInterceptor (void)
{
}

CORBA::Boolean POA_PortableInterceptor::ClientRequestInterceptor::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/Interceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_PortableInterceptor::ClientRequestInterceptor::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0") == 0)
    return ACE_static_cast (POA_PortableInterceptor::ClientRequestInterceptor_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:TAO/PortableInterceptor/Interceptor:1.0") == 0)
    return ACE_static_cast (POA_PortableInterceptor::Interceptor_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_PortableInterceptor::ClientRequestInterceptor::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0";
}

PortableInterceptor::ClientRequestInterceptor*
POA_PortableInterceptor::ClientRequestInterceptor::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  return new POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor (this, stub);
}

POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor::_tao_direct_collocated_ClientRequestInterceptor (
    POA_PortableInterceptor::ClientRequestInterceptor_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_NESTED_CLASS (PortableInterceptor,ClientRequestInterceptor) (),
    ACE_NESTED_CLASS (POA_PortableInterceptor,_tao_direct_collocated_Interceptor) (servant, stub),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}


POA_PortableInterceptor::ClientRequestInterceptor_ptr POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  return this->servant_->_non_existent (ACE_TRY_ENV);
}


void POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor::preinvoke  (
    PortableInterceptor::RequestInfo_ptr & ri,
    PortableInterceptor::Cookies & ck
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->servant_->preinvoke (
      ri,
      ck
    );

}

void POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor::postinvoke  (
    PortableInterceptor::RequestInfo_ptr & ri,
    PortableInterceptor::Cookies & ck
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->servant_->postinvoke (
      ri,
      ck
    );

}

void POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor::exception_occurred  (
    PortableInterceptor::RequestInfo_ptr & ri,
    PortableInterceptor::Cookies & ck
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  this->servant_->exception_occurred (
      ri,
      ck
    );

}
