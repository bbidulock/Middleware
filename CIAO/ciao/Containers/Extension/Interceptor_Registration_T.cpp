// $Id$

#include "ciao/Valuetype_Factories/Cookies.h"

namespace CIAO
{
  template <typename BASE, typename COPITYPE>
  Interceptor_Registration_T<BASE, COPITYPE>::Interceptor_Registration_T (void)
  {
  }

  template <typename BASE, typename COPITYPE>
  ::Components::Cookie *
  Interceptor_Registration_T<BASE, COPITYPE>::register_interceptor (
    InterceptorType_ptr_type ict)
  {
    Components::Cookie_var key_cookie;
    ACE_NEW_THROW_EX (key_cookie,
                      Cookie_Impl (reinterpret_cast<ptrdiff_t> (ict)),
                      CORBA::NO_MEMORY ());
    this->interceptors_[key_cookie] = ict;
    return key_cookie.in ();
  }

  template <typename BASE, typename COPITYPE>
  typename Interceptor_Registration_T<BASE, COPITYPE>::InterceptorType_ptr_type
  Interceptor_Registration_T<BASE, COPITYPE>::unregister_interceptor (
    ::Components::Cookie *ck)
  {
    typename RegisteredInterceptors::iterator it = this->interceptors_.find (ck);

    if (it != this->interceptors_.end ())
      {
        InterceptorType_ptr_type interceptor = it->second;
        this->interceptors_.erase (it);
        return COPITYPE::_duplicate (interceptor);
      }
    throw ::Components::ContainerPortableInterceptor::InvalidRegistration ();
  }
}
