// $Id$

#ifndef TAO_ABSTRACT_BASE_T_CPP
#define TAO_ABSTRACT_BASE_T_CPP

#include "tao/Valuetype/AbstractBase_T.h"
#include "tao/Valuetype/AbstractBase.h"
#include "tao/Stub.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  template<typename T> T *
  AbstractBase_Narrow_Utils<T>::narrow (
      CORBA::AbstractBase_ptr obj,
      const char *repo_id,
      int collocation_opportunity)
  {
    if (CORBA::is_nil (obj))
      {
        return T::_nil ();
      }

    if (obj->_is_a (repo_id) == false)
      {
        return T::_nil ();
      }

    return
      AbstractBase_Narrow_Utils<T>::unchecked_narrow (obj, repo_id, collocation_opportunity);
  }

  template<typename T>  T *
  AbstractBase_Narrow_Utils<T>::unchecked_narrow (
      CORBA::AbstractBase_ptr obj,
      int collocation_opportunity)
  {
    T *proxy = 0;

    try
      {
        proxy =
          AbstractBase_Narrow_Utils<T>::unchecked_narrow (obj, 0, collocation_opportunity);
      }
    catch (const ::CORBA::Exception&)
      {
      }

    return proxy;
  }

  template<typename T>  T *
  AbstractBase_Narrow_Utils<T>::unchecked_narrow (
      CORBA::AbstractBase_ptr obj,
      const char *,
      int collocation_opportunity)
  {
    if (CORBA::is_nil (obj))
      {
        return T::_nil ();
      }

    T_ptr proxy = T::_nil ();

    if (obj->_is_objref ())
      {
        TAO_Stub* stub = obj->_stubobj ();

        bool const collocated =
          !CORBA::is_nil (stub->servant_orb_var ().in ())
          && stub->optimize_collocation_objects ()
          && obj->_is_collocated ()
          && collocation_opportunity != TAO::TAO_CO_NONE;

        ACE_NEW_THROW_EX (proxy,
                          T (obj->_stubobj (),
                             collocated,
                             obj->_servant ()),
                          CORBA::NO_MEMORY ());
      }
    else
      {
        proxy = dynamic_cast<T *> (obj);
        if (proxy)
          proxy->_add_ref ();
      }

    return proxy;
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif  /* TAO_ABSTRACT_BASE_T_CPP */
