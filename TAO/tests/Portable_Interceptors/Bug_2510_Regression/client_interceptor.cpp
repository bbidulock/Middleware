// $Id$

#include "client_interceptor.h"
#include "tao/OctetSeqC.h"
#include "ace/Log_Msg.h"
#include "tao/ORB_Constants.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (Bug_2510_Regression,
           client_interceptor,
           "$Id$")

const IOP::ServiceId service_id = 0x08154711;
const char * const request_msg = "TEST 0123456789 TEST";

Echo_Client_Request_Interceptor::
Echo_Client_Request_Interceptor ()
  : myname_ ("Echo_Client_Interceptor")
{
}

Echo_Client_Request_Interceptor::~Echo_Client_Request_Interceptor (void)
{
}

char *
Echo_Client_Request_Interceptor::name (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::string_dup (this->myname_);
}

void
Echo_Client_Request_Interceptor::destroy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
Echo_Client_Request_Interceptor::send_poll (
    PortableInterceptor::ClientRequestInfo_ptr
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Do Nothing
}

void
Echo_Client_Request_Interceptor::send_request (
    PortableInterceptor::ClientRequestInfo_ptr ri
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  CORBA::String_var operation =
    ri->operation ();

  CORBA::Object_var target =
    ri->target ();

  ACE_DEBUG ((LM_DEBUG,"%s.send_request from %s\n", this->myname_, operation.in ()));

  // Make the context to send to the target
  IOP::ServiceContext sc;
  sc.context_id = ::service_id;

  CORBA::ULong string_len = ACE_OS::strlen (request_msg) + 1;
  CORBA::Octet *buf = CORBA::OctetSeq::allocbuf (string_len);
  ACE_OS::strcpy (reinterpret_cast<char *> (buf), request_msg);

  sc.context_data.replace (string_len, string_len, buf, 1);

  // Add this context to the service context list.
  ri->add_request_service_context (sc, 0 ACE_ENV_ARG_PARAMETER);
}

void
Echo_Client_Request_Interceptor::receive_reply (
    PortableInterceptor::ClientRequestInfo_ptr ri
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::String_var operation =
    ri->operation ();

  CORBA::Object_var target =
    ri->target ();

  ACE_DEBUG ((LM_DEBUG,"%s.receive_reply from %s\n", this->myname_, operation.in ()));
}

void
Echo_Client_Request_Interceptor::receive_other (
    PortableInterceptor::ClientRequestInfo_ptr ri
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  CORBA::String_var operation = ri->operation ();

  CORBA::Object_var target = ri->target ();

  ACE_DEBUG ((LM_DEBUG,"%s.receive_other from %s\n", this->myname_, operation.in ()));
}

void
Echo_Client_Request_Interceptor::receive_exception (
    PortableInterceptor::ClientRequestInfo_ptr ri
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  CORBA::String_var operation = ri->operation ();

  CORBA::Object_var target = ri->target ();

  ACE_DEBUG ((LM_DEBUG,"%s.receive_exception from %s\n", this->myname_, operation.in ()));
}

