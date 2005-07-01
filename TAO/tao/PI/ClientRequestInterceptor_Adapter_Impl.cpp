#include "ClientRequestInterceptor_Adapter_Impl.h"

#if !defined (__ACE_INLINE__)
#include "ClientRequestInterceptor_Adapter_Impl.inl"
#endif /* defined INLINE */

#include "tao/ClientRequestInfo.h"
#include "tao/Invocation_Base.h"
#include "tao/ORB_Core.h"
#include "tao/ORB_Core_TSS_Resources.h"
#include "tao/PortableInterceptorC.h"

ACE_RCSID (tao,
           ClientInterceptorAdapter,
           "$Id$")

namespace TAO
{
  void
  ClientRequestInterceptor_Adapter_Impl::send_request (
      Invocation_Base &invocation,
      TAO_ClientRequestInfo *ri
      ACE_ENV_ARG_DECL)
  {
    // This method implements one of the "starting" client side
    // interception point.
    ACE_TRY
      {
        for (size_t i = 0 ; i < this->interceptor_list_.size (); ++i)
          {
            this->interceptor_list_.interceptor (i)->send_request (ri
                                                  ACE_ENV_ARG_PARAMETER);
            ACE_TRY_CHECK;

            // The starting interception point completed successfully.
            // Push  the interceptor on to the flow stack.
            ++invocation.stack_size ();
          }
      }
    ACE_CATCH (PortableInterceptor::ForwardRequest, exc)
      {
        this->process_forward_request (invocation,
                                       ri,
                                       exc
                                       ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }
    ACE_ENDTRY;
    ACE_CHECK;
  }

  void
  ClientRequestInterceptor_Adapter_Impl::receive_reply (
    Invocation_Base &invocation,
    TAO_ClientRequestInfo *ri
    ACE_ENV_ARG_DECL)
  {
    // This is an "ending" interception point so we only process the
    // interceptors pushed on to the flow stack.

    // Notice that the interceptors are processed in the opposite order
    // they were pushed onto the stack since this is an "ending"
    // interception point.

    // Unwind the stack.
    const size_t len = invocation.stack_size ();
    for (size_t i = 0; i < len; ++i)
      {
        // Pop the interceptor off of the flow stack before it is
        // invoked.  This is necessary to prevent an interceptor already
        // invoked in this "ending" interception point from being
        // invoked in another "ending" interception point.
        --invocation.stack_size ();

        this->interceptor_list_.interceptor (invocation.stack_size ())->
          receive_reply (
            ri
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }

    // The receive_reply() interception point does not raise a
    // PortableInterceptor::ForwardRequest exception so there is no need
    // to attempt to catch it here.
  }

  void
  ClientRequestInterceptor_Adapter_Impl::receive_exception (
      Invocation_Base &invocation,
      TAO_ClientRequestInfo *ri
      ACE_ENV_ARG_DECL)
  {
    // This is an "ending" interception point so we only process the
    // interceptors pushed on to the flow stack.

    // Notice that the interceptors are processed in the opposite order
    // they were pushed onto the stack since this is an "ending"
    // interception point.

    ACE_TRY
      {
        // Unwind the flow stack.
        const size_t len = invocation.stack_size ();
        for (size_t i = 0; i < len; ++i)
          {
            // Pop the interceptor off of the flow stack before it is
            // invoked.  This is necessary to prevent an interceptor
            // already invoked in this "ending" interception point from
            // being invoked in another "ending" interception point.
            --invocation.stack_size ();

            this->interceptor_list_.interceptor (invocation.stack_size ())->
              receive_exception (
                ri
                ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
          }
      }
    ACE_CATCH (PortableInterceptor::ForwardRequest, exc)
      {
        this->process_forward_request (invocation,
                                       ri,
                                       exc
                                       ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }
    ACE_CATCHANY
      {
        // The receive_exception() interception point in the remaining
        // interceptors must be called so call this method (not the
        // interceptor's corresponding method) recursively.  The call is
        // made recursively since the caught exception must survive
        // until the remaining interceptors have been called.

        // Note that the recursion will stop once the flow stack size
        // drops to zero, i.e., once each interceptor has been invoked.
        // This prevents infinite recursion from occuring.

        ri->exception (&ACE_ANY_EXCEPTION);

        this->receive_exception (invocation, ri ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;

        PortableInterceptor::ReplyStatus status =
          ri->reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_TRY_CHECK;

        // Only re-throw the exception if it hasn't been transformed by
        // the receive_exception() interception point (e.g. to a
        // LOCATION_FORWARD).
        if (status == PortableInterceptor::SYSTEM_EXCEPTION
            || status == PortableInterceptor::USER_EXCEPTION)
          ACE_RE_THROW;
      }
    ACE_ENDTRY;
    ACE_CHECK;
  }

  void
  ClientRequestInterceptor_Adapter_Impl::receive_other (
      Invocation_Base &invocation,
      TAO_ClientRequestInfo *ri
      ACE_ENV_ARG_DECL)
  {
    // This is an "ending" interception point so we only process the
    // interceptors pushed on to the flow stack.

    // Notice that the interceptors are processed in the opposite order
    // they were pushed onto the stack since this is an "ending"
    // interception point.

    ACE_TRY
      {
        // Unwind the stack.
        const size_t len = invocation.stack_size ();
        for (size_t i = 0; i < len; ++i)
        {
          // Pop the interceptor off of the flow stack before it is
          // invoked.  This is necessary to prevent an interceptor
          // already invoked in this "ending" interception point from
          // being invoked in another "ending" interception point.
          --invocation.stack_size ();

          this->interceptor_list_.interceptor (invocation.stack_size ())->
            receive_other (
              ri
              ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      }
    ACE_CATCH (PortableInterceptor::ForwardRequest, exc)
      {
        this->process_forward_request (invocation,
                                       ri,
                                       exc
                                       ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
      }
    ACE_ENDTRY;
    ACE_CHECK;
  }

  void
  ClientRequestInterceptor_Adapter_Impl::process_forward_request (
      Invocation_Base &invocation,
      TAO_ClientRequestInfo *ri,
      PortableInterceptor::ForwardRequest &exc
      ACE_ENV_ARG_DECL)
  {
    ri->forward_reference (exc);

    invocation.forwarded_reference (exc.forward.in ());

    // receive_other() is potentially invoked recursively.
    this->receive_other (invocation,
                         ri
                         ACE_ENV_ARG_PARAMETER);
    ACE_CHECK;
  }

  void
  ClientRequestInterceptor_Adapter_Impl::add_interceptor (
    PortableInterceptor::ClientRequestInterceptor_ptr interceptor
    ACE_ENV_ARG_DECL)
  {
    this->interceptor_list_.add_interceptor (interceptor ACE_ENV_ARG_PARAMETER);
  }

  void
  ClientRequestInterceptor_Adapter_Impl::destroy_interceptors (
    ACE_ENV_SINGLE_ARG_DECL)
  {
    this->interceptor_list_.destroy_interceptors (ACE_ENV_SINGLE_ARG_PARAMETER);
  }
}
