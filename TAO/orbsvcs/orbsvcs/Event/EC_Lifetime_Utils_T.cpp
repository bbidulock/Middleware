// $Id$

#ifndef TAO_EC_LIFETIME_UTILS_T_CPP
#define TAO_EC_LIFETIME_UTILS_T_CPP

#include "EC_Lifetime_Utils_T.h"

#if ! defined (__ACE_INLINE__)
#include "EC_Lifetime_Utils_T.i"
#endif /* __ACE_INLINE__ */

template <typename T>
void
activate (T & obj_ref,
          PortableServer::POA_ptr poa,
          PortableServer::ServantBase * servant,
          TAO_EC_Object_Deactivator & suggested_object_deactivator
          ACE_ENV_ARG_DECL)
{
  // Activate the servant into the POA.
  PortableServer::ObjectId_var obj_id =
    poa->activate_object (servant
                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  suggested_object_deactivator.set_values (poa, obj_id.in ());

  // Get the object reference of the activated object.
  CORBA::Object_var obj =
    poa->id_to_reference (obj_id.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  obj_ref =
    T::_obj_type::_narrow (obj.in() ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  if (CORBA::is_nil (obj_ref.in ()))
  {
    ACE_THROW (CORBA::INTERNAL ());
  }
}


#endif /* TAO_EC_LIFETIME_UTILS_T_CPP */
