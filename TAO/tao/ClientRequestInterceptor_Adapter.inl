// -*- C++ -*-
//
// $Id$

namespace TAO
{
  ACE_INLINE
  ClientRequestInterceptor_Adapter::ClientRequestInterceptor_Adapter (
    ClientRequestInterceptor_List::TYPE & interceptors,
    Invocation_Base * invocation)
    : interceptors_ (interceptors)
    , invocation_ (invocation)
    , len_ (interceptors.size ())
    , stack_size_ (0)
    , info_ (0)
  {
  }
}
