//$Id$

#ifndef REQUEST_INTERCEPTOR_H
#define REQUEST_INTERCEPTOR_H

#include "rtscheduler_export.h"
#include "tao/PortableInterceptorC.h"
#include "RTSchedulerC.h"

class TAO_RTScheduler_Export Client_Interceptor:
public  PortableInterceptor::ClientRequestInterceptor
{
public:
  Client_Interceptor (RTScheduling::Current_ptr current);
  virtual void send_request (PortableInterceptor::ClientRequestInfo_ptr ri
			     ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException, 
		     PortableInterceptor::ForwardRequest));
  
  virtual void send_poll (PortableInterceptor::ClientRequestInfo_ptr ri
			  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual void receive_reply (PortableInterceptor::ClientRequestInfo_ptr ri
			      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual void receive_exception (PortableInterceptor::ClientRequestInfo_ptr ri
				  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException, 
		     PortableInterceptor::ForwardRequest));
  
  virtual void receive_other (PortableInterceptor::ClientRequestInfo_ptr ri
			      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException, 
		     PortableInterceptor::ForwardRequest));
private:
	RTScheduling::Current_var current_;
};

class TAO_RTScheduler_Export Server_Interceptor:
public PortableInterceptor::ServerRequestInterceptor
{
  virtual void receive_request_service_contexts (PortableInterceptor::ServerRequestInfo_ptr ri
						 ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException, 
		     PortableInterceptor::ForwardRequest));
  
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
  
  virtual void send_other (PortableInterceptor::ServerRequestInfo_ptr ri
			   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
		     PortableInterceptor::ForwardRequest));
};

#endif /*REQUEST_INTERCEPTOR_H*/


