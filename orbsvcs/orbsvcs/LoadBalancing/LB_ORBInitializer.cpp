#include "LB_ORBInitializer.h"
#include "LB_LoadManager.h"

#include "tao/debug.h"


ACE_RCSID (LoadBalancing,
           LB_ORBInitializer,
           "$Id$")


TAO_LB_ORBInitializer::TAO_LB_ORBInitializer (
  const CORBA::StringSeq & object_groups,
  const CORBA::StringSeq & repository_ids,
  const char * location)
  : object_groups_ (object_groups),
    repository_ids_ (repository_ids),
    location_ (location)
{
}

void
TAO_LB_ORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr
    ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
TAO_LB_ORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr info
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Object_var obj =
    info->resolve_initial_references ("LoadManager"
                                      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CosLoadBalancing::LoadManager_var lm =
    CosLoadBalancing::LoadManager::_narrow (obj.in ()
                                            ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  CORBA::String_var orbid = info->orb_id (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  PortableInterceptor::IORInterceptor_ptr tmp;
  ACE_NEW_THROW_EX (foo,
                    TAO_LB_IORInterceptor (this->object_groups_,
                                           this->repository_ids_,
                                           this->location_,
                                           lm.in (),
                                           orb_id.in ()),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK;

  PortableInterceptor::IORInterceptor_var ior_interceptor = tmp;

  info->add_ior_interceptor (ior_interceptor.in ()
                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}
