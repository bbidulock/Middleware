// -*- C++ -*-

//=============================================================================
/**
 * @file Server_Request_Interceptor.h
 *
 * $Id$
 *
 */
//=============================================================================

#ifndef BUG_2248_REGRESSION_SERVER_REQUEST_INTERCEPTOR_H
#define BUG_2248_REGRESSION_SERVER_REQUEST_INTERCEPTOR_H

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"
#include "testsC.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

/**
 * @class Server_Request_Interceptor
 *
 * @brief Simple concrete server request interceptor.
 *
 *
 */
class Server_Request_Interceptor
  : public virtual Simple_ServerRequestInterceptor,
    public virtual TAO_Local_RefCounted_Object
{
public:

  /// Constructor.
  Server_Request_Interceptor (void);

  /// Destructor.
  ~Server_Request_Interceptor (void);

  /// Set the references to which requests will be forwarded.
  virtual void forward_reference (const char* iorstr)
      ACE_THROW_SPEC ((CORBA::SystemException));

  /**
   * @name Methods Required by the Server Request Interceptor
   * Interface
   *
   * These are methods that must be implemented since they are pure
   * virtual in the abstract base class.  They are the canonical
   * methods required for all server request interceptors.
   */
  //@{
  /// Return the name of this ServerRequestinterceptor.
  virtual char * name (void)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void destroy (void)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void receive_request_service_contexts (
      PortableInterceptor::ServerRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  virtual void receive_request (
      PortableInterceptor::ServerRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  virtual void send_reply (
      PortableInterceptor::ServerRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void send_exception (
      PortableInterceptor::ServerRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));

  virtual void send_other (
      PortableInterceptor::ServerRequestInfo_ptr ri)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableInterceptor::ForwardRequest));
  //@}

private:

  /// References to the two objects used in this test.
  CORBA::String_var iorstr_;
    int request_forwarded_;
};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif  /* BUG_2248_REGRESSION_SERVER_REQUEST_INTERCEPTOR_H */
