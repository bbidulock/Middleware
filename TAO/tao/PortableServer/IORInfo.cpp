// -*- C++ -*-
//
// $Id$


#include "tao/PortableServer/IORInfo.h"
#include "tao/PortableServer/PortableServerC.h"

#include "tao/PolicyC.h"
#include "tao/IOPC.h"
#include "tao/MProfile.h"
#include "tao/ORB_Core.h"

ACE_RCSID (PortableServer, IORInfo, "$Id$")

TAO_IORInfo::TAO_IORInfo (TAO_ORB_Core *orb_core,
                          TAO_POA *poa)
  : orb_core_ (orb_core),
    poa_ (poa)
{
}

TAO_IORInfo::~TAO_IORInfo (void)
{
}

CORBA::Policy_ptr
TAO_IORInfo::get_effective_policy (CORBA::PolicyType type
                                   TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::PolicyList *policy_list
    = this->poa_->get_policy_list ();

  // Check the policy list supplied by the POA.
  CORBA::ULong policy_count = policy_list->length ();

  for (CORBA::ULong i = 0; i < policy_count; ++i)
    {
      CORBA::PolicyType pt =
        (*policy_list)[i]->policy_type (
          TAO_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (CORBA::Policy::_nil ());

      if (pt == type)
        return CORBA::Policy::_duplicate ((*policy_list)[i]);
    }

  // TODO: Now check the global ORB policies.
  // ........

  ACE_THROW_RETURN (CORBA::INV_POLICY (TAO_OMG_VMCID | 2,
                                       CORBA::COMPLETED_NO),
                    CORBA::Policy::_nil ());
}

void
TAO_IORInfo::add_ior_component (const IOP::TaggedComponent &component
                                TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Add the given tagged component to all profiles.
  this->poa_->save_ior_component (component
                                  TAO_ENV_ARG_DECL);
  ACE_CHECK;
}

void
TAO_IORInfo::add_ior_component_to_profile (
    const IOP::TaggedComponent &component,
    IOP::ProfileId profile_id
    TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Add the given tagged component to all profiles matching the given
  // ProfileId.

  this->poa_->save_ior_component_and_profile_id (component,
                                                 profile_id
                                                 TAO_ENV_ARG_DECL);
  ACE_CHECK;
}

PortableInterceptor::AdapterManagerId
TAO_IORInfo::manager_id ( TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  /// This method is used to provide a handle to the manager of the
  /// adapter.
  return this->poa_->get_manager_id (TAO_ENV_SINGLE_ARG_DECL);

  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (TAO_OMG_VMCID | 14,
                                          CORBA::COMPLETED_NO),
                    0);
}

PortableInterceptor::AdapterState
TAO_IORInfo::state (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->poa_->get_adapter_state (TAO_ENV_SINGLE_ARG_DECL);

  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (TAO_OMG_VMCID | 14,
                                          CORBA::COMPLETED_NO),
                    0);
}

PortableInterceptor::ObjectReferenceTemplate *
TAO_IORInfo::adapter_template (TAO_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  /* Returns Object Reference Template whenever an IOR Interceptor is
     invoked. Its value is the template created for the adapter
     policies and the IOR Interceptor calls to add_ior_component and
     add_ior_component_to_profile. Its a const value and its value
     never changes in its life.
  */

  this->poa_->get_adapter_template ();

  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (TAO_OMG_VMCID | 14,
                                          CORBA::COMPLETED_NO),
                    0);
}

PortableInterceptor::ObjectReferenceFactory *
TAO_IORInfo::current_factory (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  /* Returns the current_factory that is used to create the object
     references by the adapter. Though initially, its value is the
     same as the adapter_template, unlike adapter_template, its value can
     be changed. The value of the current_factory can be changed only
     during the call to components_established method.
  */
  return this->poa_->get_obj_ref_factory ();

  ACE_THROW_RETURN (CORBA::BAD_INV_ORDER (TAO_OMG_VMCID | 14,
                                          CORBA::COMPLETED_NO),
                    0);
}

void
TAO_IORInfo::
current_factory (PortableInterceptor::ObjectReferenceFactory * current_factory
                 TAO_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->poa_->set_obj_ref_factory (current_factory
                                          TAO_ENV_ARG_DECL);

  ACE_THROW (CORBA::BAD_INV_ORDER (TAO_OMG_VMCID | 14,
                                   CORBA::COMPLETED_NO));
}
