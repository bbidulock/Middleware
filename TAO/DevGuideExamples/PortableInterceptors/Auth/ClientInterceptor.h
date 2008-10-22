// $Id$

#ifndef CLIENTINTERCEPTOR_H
#define CLIENTINTERCEPTOR_H

#include "tao/PortableInterceptorC.h"
#include "tao/LocalObject.h"
#include "tao/PI/PI.h"

class ClientInterceptor
: public virtual PortableInterceptor::ClientRequestInterceptor,
  public virtual TAO_Local_RefCounted_Object
{

 public:
  ClientInterceptor (void);

  virtual ~ClientInterceptor ();

  virtual char * name ();

  virtual void destroy ();

  virtual void send_poll (PortableInterceptor::ClientRequestInfo_ptr ri);

  virtual void send_request (PortableInterceptor::ClientRequestInfo_ptr ri);

  virtual void receive_reply (PortableInterceptor::ClientRequestInfo_ptr ri);

  virtual void receive_other (PortableInterceptor::ClientRequestInfo_ptr ri);

  virtual void receive_exception (PortableInterceptor::ClientRequestInfo_ptr ri);

 private:
  const char *myname_;
};

#endif
