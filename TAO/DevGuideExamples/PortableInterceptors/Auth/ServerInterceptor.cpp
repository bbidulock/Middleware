#include "ServerInterceptor.h"
#include <tao/PI_Server/ServerRequestInfoA.h>
#include <ace/OS_NS_string.h>
#if defined (ACE_HAS_STANDARD_CPP_LIBRARY) && (ACE_HAS_STANDARD_CPP_LIBRARY == 1)
#include <iostream>
#else
#include <iostream.h>
#endif

const IOP::ServiceId service_id = 0xdeed;
const unsigned int num_allowed_users = 4;
static const char* allowed_users[num_allowed_users+1] = 
  {"Ron Klein", "Scott Case", "Mark Hodge", "Greg Black", 0};
const char* restricted_interfaces[1] = {"IDL:Messenger:1.0"};

ServerInterceptor::ServerInterceptor (void)
  : myname_ ("Server_Authentication_Interceptor")
{
  std::cout << "Calling ServerInterceptor constructor." << std::endl;
}

ServerInterceptor::~ServerInterceptor ()
{
}

char *
ServerInterceptor::name ()
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  std::cout << "Calling ServerInterceptor name() method" << std::endl;
  return CORBA::string_dup (this->myname_);
}

void
ServerInterceptor::destroy ()
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  std::cout << "Calling destroy()." << std::endl;
}

void
ServerInterceptor::receive_request_service_contexts (
                                                     PortableInterceptor::ServerRequestInfo_ptr ri)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  ACE_UNUSED_ARG(ri);
  std::cout << "Calling receive_request_service_contexts()." << std::endl;
}

void
ServerInterceptor::receive_request (
                                    PortableInterceptor::ServerRequestInfo_ptr ri)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  bool permission_granted = false;
  std::cout << "Calling receive_request()." << std::endl;
  
  if (ri->target_is_a(restricted_interfaces[0])){
    IOP::ServiceId id = service_id;
    // Check that the request service context can be retrieved.
    IOP::ServiceContext_var sc =
      ri->get_request_service_context (id);

    CORBA::OctetSeq ocSeq = sc->context_data;

    const char * buf =
      reinterpret_cast<const char *> (ocSeq.get_buffer ());
  
    for (unsigned int i=0; i<num_allowed_users; ++i) {
      if (ACE_OS::strcmp (buf, allowed_users[i]) == 0)
        {
          permission_granted = true;
        }
    }
  }
  
  if (permission_granted == true) {
    std::cout << "Permission Granted " << std::endl;
  }
  else {
    std::cout << "Permission Denied " << std::endl;
    throw CORBA::NO_PERMISSION();
  }
}

void
ServerInterceptor::send_reply (
                               PortableInterceptor::ServerRequestInfo_ptr ri)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_UNUSED_ARG(ri);
  std::cout << "Calling send_reply()." << std::endl;
}

void
ServerInterceptor::send_exception (
                                   PortableInterceptor::ServerRequestInfo_ptr ri)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  ACE_UNUSED_ARG(ri);
  std::cout << "Calling send_exception()." << std::endl;
}

void
ServerInterceptor::send_other (
                               PortableInterceptor::ServerRequestInfo_ptr ri)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableInterceptor::ForwardRequest))
{
  ACE_UNUSED_ARG(ri);
  std::cout << "Calling send_other()." << std::endl;
}

