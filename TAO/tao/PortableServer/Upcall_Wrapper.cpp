// $Id$

#include "Upcall_Wrapper.h"

#ifndef __ACE_INLINE__
# include "Upcall_Wrapper.inl"
#endif  /* __ACE_INLINE_*/

#if TAO_HAS_INTERCEPTORS == 1
# include "PICurrent_Guard.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */

#include "tao/TAO_Server_Request.h"
#include "tao/CDR.h"


ACE_RCSID (PortableServer,
           Upcall_Wrapper,
           "$Id$")


bool
TAO::Upcall_Wrapper::pre_upcall (void)
{
  TAO_InputCDR & cdr = this->server_request_.incoming ();

  // Demarshal the operation "in" and "inout" arguments, if any.

  TAO::Argument ** const begin = this->args_;
  TAO::Argument ** const end   = this->args_ + this->nargs_;

  ACE_DECLARE_NEW_CORBA_ENV;

  for (TAO::Argument ** i = begin; i != end; ++i)
    {
      if (!(*i)->demarshal (cdr))
        {
          TAO_InputCDR::throw_skel_exception (errno
                                              ACE_ENV_ARG_PARAMETER);
          ACE_CHECK_RETURN (false);
        }
    }

#if TAO_HAS_INTERCEPTORS == 1

  // Invoke intermediate server side interception points.

  ACE_TRY
    {
      TAO::PICurrent_Guard pi_guard (this->server_request_,
                                     true  /* Copy TSC to RSC */);

      this->interceptor_adapter_.receive_request (&this->request_info_
                                                  ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      // @@ TODO:  FILL IN THE BLANKS!
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (false);
#endif  /* TAO_HAS_INTERCEPTORS == 1 */

  return true;
}

bool
TAO::Upcall_Wrapper::post_upcall (void)
{
  this->server_request_.init_reply ();

#if TAO_HAS_INTERCEPTORS == 1
  if (!this->interceptor_adapter_.location_forwarded ())
    {
#endif /* TAO_HAS_INTERCEPTORS */

      TAO_OutputCDR & cdr = this->server_request_.outgoing ();

      // Demarshal the operation "inout" and "out" arguments and
      // return value, if any.

      TAO::Argument ** const begin = this->args_;
      TAO::Argument ** const end   = this->args_ + this->nargs_;

      ACE_DECLARE_NEW_CORBA_ENV;

      for (TAO::Argument ** i = begin; i != end; ++i)
        {
          if (!(*i)->marshal (cdr))
            {
              TAO_OutputCDR::throw_skel_exception (errno
                                                   ACE_ENV_ARG_PARAMETER);
              ACE_CHECK_RETURN (false);
            }
        }

#if TAO_HAS_INTERCEPTORS == 1
    }
#endif /* TAO_HAS_INTERCEPTORS */

  return true;
}
