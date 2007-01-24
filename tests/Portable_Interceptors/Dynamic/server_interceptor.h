// -*- C++ -*-
//
// $Id$

#ifndef TAO_SERVER_INTERCEPTOR_H
#define TAO_SERVER_INTERCEPTOR_H

#include "tao/PI_Server/PI_Server.h"
#include "tao/PortableInterceptorC.h"
#include "tao/LocalObject.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class Echo_Server_Request_Interceptor
  : public PortableInterceptor::ServerRequestInterceptor,
    public virtual TAO_Local_RefCounted_Object
{
  // = Server-side echo interceptor.  For checking interceptor visually only.
public:
  Echo_Server_Request_Interceptor (void);
  // cotr.

  virtual char * name (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Canonical name of the interceptor.

  virtual void destroy (void)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void receive_request_service_contexts (
        PortableInterceptor::ServerRequestInfo_ptr
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
        )
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      PortableInterceptor::ForwardRequest
      ));

  virtual void receive_request (PortableInterceptor::ServerRequestInfo_ptr ri
                                ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  virtual void send_reply (PortableInterceptor::ServerRequestInfo_ptr ri
                           ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void send_exception (PortableInterceptor::ServerRequestInfo_ptr ri
                               ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  virtual void send_other (
        PortableInterceptor::ServerRequestInfo_ptr
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
        )
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      PortableInterceptor::ForwardRequest
      ));

protected:

  virtual ~Echo_Server_Request_Interceptor (void);
  // dotr.

private:
  const char *myname_;

};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_SERVER_INTERCEPTOR_H */
