// $Id$
#ifndef TAO_OBJECT_T_C
#define TAO_OBJECT_T_C

#include "Object_T.h"
#include "Stub.h"

ACE_RCSID (tao,
           Object_T,
           "$Id$")

namespace TAO
{
  template<typename T>
  T *
  Narrow_Utils<T>::narrow (CORBA::Object_ptr obj,
                           const char *repo_id,
                           Proxy_Broker_Factory pbf
                           ACE_ENV_ARG_DECL)
  {
    if (CORBA::is_nil (obj))
      {
        return T::_nil ();
      }

    CORBA::Boolean is_it = obj->_is_a (repo_id
                                       ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (T::_nil ());

    if (is_it == 0)
      {
        return T::_nil ();
      }

    return TAO::Narrow_Utils<T>::unchecked_narrow (obj, pbf);
  }


  template<typename T>
  T *
  Narrow_Utils<T>::unchecked_narrow (CORBA::Object_ptr obj,
                                     Proxy_Broker_Factory pbf)
  {
    if (CORBA::is_nil (obj))
      {
        return T::_nil ();
      }

    T_ptr proxy = Narrow_Utils<T>::lazy_evaluation (obj);

    if (!CORBA::is_nil (proxy))
      {
        return proxy;
      }

    TAO_Stub* stub = obj->_stubobj ();

    if (stub != 0)
      {
        stub->_incr_refcnt ();
      }

    bool collocated =
      !CORBA::is_nil (stub->servant_orb_var ().ptr ())
      && stub->optimize_collocation_objects ()
      && obj->_is_collocated ()
      && pbf != 0;

    ACE_NEW_RETURN (proxy,
                    T (stub,
                       collocated ? 1 : 0,
                       obj->_servant ()),
                    T::_nil ());

    return proxy;
  }

  template<typename T>
  T *
  Narrow_Utils<T>::lazy_evaluation (CORBA::Object_ptr obj)
  {
    T_ptr default_proxy = T::_nil ();

    // Code for lazily evaluated IORs.
    if (!obj->is_evaluated ())
      {
        ACE_NEW_RETURN (default_proxy,
                        T (obj->steal_ior (),
                           obj->orb_core ()),
                        T::_nil ());
      }

    return default_proxy;
  }
}

#endif /* TAO_OBJECT_T_C */
