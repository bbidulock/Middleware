// $Id$

#include "Priority_Mapping_Manager.h"

#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0

#if ! defined (__ACE_INLINE__)
#include "Priority_Mapping_Manager.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID (RTCORBA, 
           Priority_Mapping_Manager, 
           "$Id$")

TAO_Priority_Mapping_Manager::~TAO_Priority_Mapping_Manager (void)
{
  delete mapping_;
}

TAO_Priority_Mapping_Manager_ptr
TAO_Priority_Mapping_Manager::_narrow (CORBA::Object_ptr obj
                                       ACE_ENV_ARG_DECL_NOT_USED)
{
  if (CORBA::is_nil (obj))
    {
      return TAO_Priority_Mapping_Manager::_nil ();
    }

  return 
    TAO_Priority_Mapping_Manager::_duplicate (
        dynamic_cast<TAO_Priority_Mapping_Manager_ptr> (obj)
      );
}

TAO_Priority_Mapping_Manager_ptr
TAO_Priority_Mapping_Manager::_duplicate (TAO_Priority_Mapping_Manager_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

const char*
TAO_Priority_Mapping_Manager::_interface_repository_id (void) const
{
  return "IDL:Priority_Mapping_Manager:1.0";
}

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_HAS_CORBA_MESSAGING != 0 */

