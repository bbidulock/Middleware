// $Id$

#include "Method_Request_Event.h"

#if ! defined (__ACE_INLINE__)
#include "Method_Request_Event.inl"
#endif /* __ACE_INLINE__ */

#include "Delivery_Request.h"

ACE_RCSID (Notify, TAO_Notify_Method_Request_Event_Queueable, "$Id$")

TAO_Notify_Method_Request_Event::TAO_Notify_Method_Request_Event (
      const TAO_Notify_Event * event)
  : event_ (event)
{
}

TAO_Notify_Method_Request_Event::TAO_Notify_Method_Request_Event (
      const TAO_Notify::Delivery_Request_Ptr & request)
  : event_ (request->event ().get ())
  , delivery_request_ (request)
{
}

TAO_Notify_Method_Request_Event::TAO_Notify_Method_Request_Event (
      const TAO_Notify_Method_Request_Event & rhs,
      const TAO_Notify_Event * event)
  : event_ (event)
  , delivery_request_ (rhs.delivery_request_)
{
}

TAO_Notify_Method_Request_Event::~TAO_Notify_Method_Request_Event()
{
}

void
TAO_Notify_Method_Request_Event::complete ()
{
  if (this->delivery_request_.get () != 0)
  {
    this->delivery_request_->complete ();
  }
}


unsigned long
TAO_Notify_Method_Request_Event::sequence ()
{
  if (this->delivery_request_.get () != 0)
  {
    return this->delivery_request_->sequence ();
  }
  return 0;
}

bool
TAO_Notify_Method_Request_Event::should_retry ()
{
  if (this->delivery_request_.get () != 0)
  {
    return this->delivery_request_->should_retry ();
  }
  return false;
}

/**********************************************************/


TAO_Notify_Method_Request_Event_Queueable::TAO_Notify_Method_Request_Event_Queueable (
      const TAO_Notify_Method_Request_Event & prev_request,
      const TAO_Notify_Event_var & event_var)
  : TAO_Notify_Method_Request_Queueable (event_var.get ())
  , TAO_Notify_Method_Request_Event (prev_request, event_var.get ())
  , event_var_ (event_var)
{
}

TAO_Notify_Method_Request_Event_Queueable::TAO_Notify_Method_Request_Event_Queueable (
    TAO_Notify::Delivery_Request_Ptr & request)
  : TAO_Notify_Method_Request_Queueable (request->event ().get ())
  , TAO_Notify_Method_Request_Event (request, request->event ().get ())
  , event_var_ (request->event ())
{
}

TAO_Notify_Method_Request_Event_Queueable::~TAO_Notify_Method_Request_Event_Queueable ()
{
}

int
TAO_Notify_Method_Request_Event_Queueable::execute (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  ACE_ASSERT (false);
  return -1;
}

