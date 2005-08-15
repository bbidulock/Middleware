/* -*- C++ -*- */

// =================================================================
/**
 * @file PICurrent_Loader.cpp
 *
 * $Id$
 *
 * @author Johnny Willemsen  <jwillemsen@remedy.nl>
 *
 */
// =================================================================

#include "PICurrent_Loader.h"

#if TAO_HAS_INTERCEPTORS == 1

#include "PICurrent.h"

#include "tao/ORB.h"
#include "tao/ORB_Core.h"
#include "tao/debug.h"


ACE_RCSID (tao,
           PICurrent_Loader,
           "$Id$")


CORBA::Object_ptr
TAO_PICurrent_Loader::create_object (
  CORBA::ORB_ptr orb,
  int,
  ACE_TCHAR *[]
  ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Object_ptr obj = CORBA::Object::_nil ();
  ACE_NEW_RETURN (obj,
                  TAO::PICurrent (*orb->orb_core ()),
                  CORBA::Object::_nil ());
  return obj;
}

int
TAO_PICurrent_Loader::Initializer (void)
{
  return ACE_Service_Config::process_directive (ace_svc_desc_TAO_PICurrent_Loader);
}

ACE_STATIC_SVC_DEFINE (TAO_PICurrent_Loader,
                       ACE_TEXT ("PICurrent_Loader"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_PICurrent_Loader),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO_PI, TAO_PICurrent_Loader)

#endif  /* TAO_HAS_INTERCEPTORS == 1 */
