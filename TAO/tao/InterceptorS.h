/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_INTERCEPTORS_H_
#define _TAO_IDL_INTERCEPTORS_H_

#include "tao/InterceptorC.h"
#include "tao/Servant_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  POA_PortableInterceptor
{
  class Cookie;
  typedef Cookie *Cookie_ptr;
  class TAO_Export Cookie :  public virtual TAO_Local_ServantBase
  {
  protected:
    Cookie (void);

  public:
    virtual ~Cookie (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    PortableInterceptor::Cookie *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;

    virtual char * myname (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;


  };


#if !defined (_PORTABLEINTERCEPTOR_COOKIE___DIRECT_COLLOCATED_SH_)
#define _PORTABLEINTERCEPTOR_COOKIE___DIRECT_COLLOCATED_SH_

  class TAO_Export _tao_direct_collocated_Cookie     : public virtual PortableInterceptor::Cookie
  {
  public:
    _tao_direct_collocated_Cookie (
        Cookie_ptr  servant,
        TAO_Stub *stub
      );
    virtual CORBA::Boolean _is_a(
        const CORBA::Char *logical_type_id,
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

    Cookie_ptr _get_servant (void) const;

    virtual CORBA::Boolean _non_existent(
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

        virtual char * myname (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );


  private:
    Cookie_ptr servant_;
  };


#endif /* end #if !defined */


  class Interceptor;
  typedef Interceptor *Interceptor_ptr;
  class TAO_Export Interceptor :  public virtual TAO_Local_ServantBase
  {
  protected:
    Interceptor (void);

  public:
    virtual ~Interceptor (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    PortableInterceptor::Interceptor *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;

    virtual char * name (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;


  };


#if !defined (_PORTABLEINTERCEPTOR_INTERCEPTOR___DIRECT_COLLOCATED_SH_)
#define _PORTABLEINTERCEPTOR_INTERCEPTOR___DIRECT_COLLOCATED_SH_

  class TAO_Export _tao_direct_collocated_Interceptor     : public virtual PortableInterceptor::Interceptor
  {
  public:
    _tao_direct_collocated_Interceptor (
        Interceptor_ptr  servant,
        TAO_Stub *stub
      );
    virtual CORBA::Boolean _is_a(
        const CORBA::Char *logical_type_id,
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

    Interceptor_ptr _get_servant (void) const;

    virtual CORBA::Boolean _non_existent(
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

        virtual char * name (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );


  private:
    Interceptor_ptr servant_;
  };


#endif /* end #if !defined */


  class ServerRequestInterceptor;
  typedef ServerRequestInterceptor *ServerRequestInterceptor_ptr;
  class TAO_Export ServerRequestInterceptor : public virtual Interceptor
  {
  protected:
    ServerRequestInterceptor (void);

  public:
    virtual ~ServerRequestInterceptor (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    PortableInterceptor::ServerRequestInterceptor *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;

    virtual void preinvoke (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        IOP::ServiceContextList & sc,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;

    virtual void postinvoke (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        IOP::ServiceContextList & sc,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;

    virtual void exception_occurred (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;


  };


#if !defined (_PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR___DIRECT_COLLOCATED_SH_)
#define _PORTABLEINTERCEPTOR_SERVERREQUESTINTERCEPTOR___DIRECT_COLLOCATED_SH_

  class TAO_Export _tao_direct_collocated_ServerRequestInterceptor     : public virtual PortableInterceptor::ServerRequestInterceptor,
      public virtual _tao_direct_collocated_Interceptor
  {
  public:
    _tao_direct_collocated_ServerRequestInterceptor (
        ServerRequestInterceptor_ptr  servant,
        TAO_Stub *stub
      );
    virtual CORBA::Boolean _is_a(
        const CORBA::Char *logical_type_id,
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

    ServerRequestInterceptor_ptr _get_servant (void) const;

    virtual CORBA::Boolean _non_existent(
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

        virtual void preinvoke (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        IOP::ServiceContextList & sc,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void postinvoke (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        IOP::ServiceContextList & sc,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void exception_occurred (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );


  private:
    ServerRequestInterceptor_ptr servant_;
  };


#endif /* end #if !defined */


  class ClientRequestInterceptor;
  typedef ClientRequestInterceptor *ClientRequestInterceptor_ptr;
  class TAO_Export ClientRequestInterceptor : public virtual Interceptor
  {
  protected:
    ClientRequestInterceptor (void);

  public:
    virtual ~ClientRequestInterceptor (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    PortableInterceptor::ClientRequestInterceptor *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;

    virtual void preinvoke (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        IOP::ServiceContextList & sc,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;

    virtual void postinvoke (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        IOP::ServiceContextList & sc,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;

    virtual void exception_occurred (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      ) = 0;


  };


#if !defined (_PORTABLEINTERCEPTOR_CLIENTREQUESTINTERCEPTOR___DIRECT_COLLOCATED_SH_)
#define _PORTABLEINTERCEPTOR_CLIENTREQUESTINTERCEPTOR___DIRECT_COLLOCATED_SH_

  class TAO_Export _tao_direct_collocated_ClientRequestInterceptor     : public virtual PortableInterceptor::ClientRequestInterceptor,
      public virtual _tao_direct_collocated_Interceptor
  {
  public:
    _tao_direct_collocated_ClientRequestInterceptor (
        ClientRequestInterceptor_ptr  servant,
        TAO_Stub *stub
      );
    virtual CORBA::Boolean _is_a(
        const CORBA::Char *logical_type_id,
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

    ClientRequestInterceptor_ptr _get_servant (void) const;

    virtual CORBA::Boolean _non_existent(
        CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
      );

        virtual void preinvoke (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        IOP::ServiceContextList & sc,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void postinvoke (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        IOP::ServiceContextList & sc,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void exception_occurred (
        CORBA::ULong request_id,
        CORBA::Boolean response_expected,
        CORBA::Object_ptr objref,
        const char * operation_name,
        PortableInterceptor::Cookies & ck,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );


  private:
    ClientRequestInterceptor_ptr servant_;
  };


#endif /* end #if !defined */


}
TAO_NAMESPACE_CLOSE

#if defined(_MSC_VER)
#pragma warning(default:4250)
#endif /* _MSC_VER */

#endif /* ifndef */
