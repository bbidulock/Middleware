// -*- C++ -*-

#include "Server_ORBInitializer.h"

ACE_RCSID (Redirection,
           Server_ORBInitializer,
           "$Id$")

#if TAO_HAS_INTERCEPTORS == 1

#include "Server_Request_Interceptor.h"
#include "tao/ORB_Constants.h"

Server_ORBInitializer::Server_ORBInitializer (void)
{
}

void
Server_ORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
Server_ORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr info)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  PortableInterceptor::ServerRequestInterceptor_ptr interceptor;
  ACE_NEW_THROW_EX (interceptor,
                    Server_Request_Interceptor,
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO::VMCID,
                        ENOMEM),
                      CORBA::COMPLETED_NO));

  info->add_server_request_interceptor (interceptor);
}

#endif  /* TAO_HAS_INTERCEPTORS == 1 */
