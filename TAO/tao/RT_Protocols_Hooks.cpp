// $Id$

#include "RT_Protocols_Hooks.h"
#include "RT_Policy_i.h"

#include "tao/Invocation.h"
#include "tao/Stub.h"
#include "tao/MProfile.h"

#include "ace/Dynamic_Service.h"

ACE_RCSID(tao, RT_Protocols_Hooks, "$Id$");

TAO_RT_Protocols_Hooks::Client_Protocols_Hook TAO_RT_Protocols_Hooks::client_protocols_hook_ = 0;
TAO_RT_Protocols_Hooks::Server_Protocols_Hook TAO_RT_Protocols_Hooks::server_protocols_hook_ = 0;

/// constructor
TAO_RT_Protocols_Hooks::TAO_RT_Protocols_Hooks (void)
{
}

/// destructor
TAO_RT_Protocols_Hooks::~TAO_RT_Protocols_Hooks (void)
{
}

int
TAO_RT_Protocols_Hooks::call_client_protocols_hook (
                          TAO_ORB_Core *orb_core,
                          RTCORBA::ProtocolProperties_var &
                          properties,
                          const char *protocol_type)
{
  if (TAO_RT_Protocols_Hooks::client_protocols_hook_ == 0)
    return -1;
  
  (*TAO_RT_Protocols_Hooks::client_protocols_hook_) (orb_core,
                                                     properties,
                                                     protocol_type);
  
  return 0;
}

void
TAO_RT_Protocols_Hooks::set_client_protocols_hook (Client_Protocols_Hook hook)
{
  TAO_RT_Protocols_Hooks::client_protocols_hook_ = hook;
  // Saving the hook pointer so that we can use it later when needed.

  return;
}

int
TAO_RT_Protocols_Hooks::call_server_protocols_hook (
                          TAO_ORB_Core *orb_core,
                          RTCORBA::ProtocolProperties_var &
                          properties,
                          const char *protocol_type)
{
  if (TAO_RT_Protocols_Hooks::server_protocols_hook_ == 0)
    return -1;

  int result_value = 
    (*TAO_RT_Protocols_Hooks::server_protocols_hook_) (orb_core,
                                                       properties,
                                                       protocol_type);
  
  if (result_value != 0)
    return -1;

  return 0;
}

void
TAO_RT_Protocols_Hooks::set_server_protocols_hook (Server_Protocols_Hook hook)
{
  TAO_RT_Protocols_Hooks::server_protocols_hook_ = hook;
  // Saving the hook pointer so that we can use it later when needed.

  return;
}

void
TAO_RT_Protocols_Hooks::call_policy_type_hook (CORBA::PolicyList *&policy_list,
                                               CORBA::ULong &policy_type)
{
  CORBA::ULong length = policy_list->length ();
  //  CORBA::ULong index = 0;

  for (unsigned int i = 0; i < length; ++i)
    {
      if (((*policy_list)[i]->policy_type () == 
           RTCORBA::PRIORITY_MODEL_POLICY_TYPE))
        policy_type = 0;

      else if (((*policy_list)[i]->policy_type () == 
                RTCORBA::PRIORITY_BANDED_CONNECTION_POLICY_TYPE))
        policy_type = 1;

      else if (((*policy_list)[i]->policy_type () == 
                RTCORBA::CLIENT_PROTOCOL_POLICY_TYPE))
        policy_type = 2;
    }
}

void
TAO_RT_Protocols_Hooks::validate_policy_type (CORBA::ULong type,
                                    CORBA::ULong &type_value,
                                    CORBA::Environment &ACE_TRY_ENV)
{
  // Validity check.  Make sure requested policy type is appropriate
  // for this scope.
  if (type == RTCORBA::THREADPOOL_POLICY_TYPE
      || type == RTCORBA::SERVER_PROTOCOL_POLICY_TYPE)
    ACE_THROW (CORBA::INV_POLICY ());

  if (type == RTCORBA::PRIORITY_MODEL_POLICY_TYPE)
    type_value = 0;

  if (type == RTCORBA::PRIORITY_BANDED_CONNECTION_POLICY_TYPE)
    type_value = 1;

  if (type == RTCORBA::CLIENT_PROTOCOL_POLICY_TYPE)
    type_value = 2;
}

CORBA::Policy *
TAO_RT_Protocols_Hooks::effective_priority_banded_connection_hook (CORBA::Policy *override,
                                                         CORBA::Policy *exposed,
                                                         CORBA::Environment &ACE_TRY_ENV)
{
  RTCORBA::PriorityBandedConnectionPolicy_var override_policy_ptr =
    RTCORBA::PriorityBandedConnectionPolicy::_narrow (override,
                                                      ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  TAO_PriorityBandedConnectionPolicy *override_policy =
    ACE_static_cast (TAO_PriorityBandedConnectionPolicy *,
                     override_policy_ptr.in ());

  RTCORBA::PriorityBandedConnectionPolicy_var exposed_policy_ptr =
    RTCORBA::PriorityBandedConnectionPolicy::_narrow (exposed,
                                                      ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  TAO_PriorityBandedConnectionPolicy *exposed_policy =
    ACE_static_cast (TAO_PriorityBandedConnectionPolicy *,
                      exposed_policy_ptr.in ());

  // Both override and exposed have been set.
  // See if either of them has empty priority bands.
  CORBA::Object_var auto_release_exp = exposed_policy;
  CORBA::Object_var auto_release_ov = override_policy;

  if (exposed_policy->priority_bands_rep ().length () == 0)
    {
      auto_release_ov._retn ();
      return override;
    }

  if (override_policy->priority_bands_rep ().length () == 0)
    {
      auto_release_exp._retn ();
      return exposed;
    }

  // Both override and exposed have been set and neither has empty
  // priority bands.  This is illegal (ptc/99-05-03, sec. 4.12.1).
  ACE_THROW_RETURN (CORBA::INV_POLICY (),
                    0);
}

CORBA::Policy *
TAO_RT_Protocols_Hooks::effective_client_protocol_hook (
                           CORBA::Policy_ptr override,
                           CORBA::Policy_ptr exposed,
                           CORBA::Environment &ACE_TRY_ENV)
{  
  RTCORBA::ClientProtocolPolicy_var override_policy_var =
    RTCORBA::ClientProtocolPolicy::_narrow (override,
                                            ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());
  
  TAO_ClientProtocolPolicy *override_policy =
    ACE_static_cast (TAO_ClientProtocolPolicy *,
                     override_policy_var.in ());

  RTCORBA::ClientProtocolPolicy_var exposed_policy_var =
    RTCORBA::ClientProtocolPolicy::_narrow (exposed,
                                            ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());
  
  TAO_ClientProtocolPolicy *exposed_policy =
    ACE_static_cast (TAO_ClientProtocolPolicy *,
                     exposed_policy_var.in ());

  // Both override and exposed have been set.
  // See if either of them has empty priority bands.
  RTCORBA::ProtocolList &protocols_rep_var = 
    exposed_policy->protocols_rep ();

  if (protocols_rep_var.length () == 0)
    {
      return override;
    }

  if (override_policy->protocols_rep ().length () == 0)
    {
      return exposed;
    }

  // Both override and exposed have been set and neither has empty
  // protocols.  This is illegal (ptc/99-05-03, sec. 4.15.4).
  ACE_THROW_RETURN (CORBA::INV_POLICY (),
                    0);
}

void
TAO_RT_Protocols_Hooks::add_rt_service_context_hook (
                           TAO_GIOP_Invocation *invocation,
                           CORBA::Policy *model_policy,
                           CORBA::Short &client_priority,
                           CORBA::Environment &ACE_TRY_ENV)
{

  RTCORBA::PriorityModelPolicy_var model_policy_ptr =
    RTCORBA::PriorityModelPolicy::_narrow (model_policy,
                                           ACE_TRY_ENV);
  ACE_CHECK;

  TAO_PriorityModelPolicy *priority_model =
    ACE_static_cast (TAO_PriorityModelPolicy *,
                     model_policy_ptr.in ());

  if (priority_model->get_priority_model () == RTCORBA::CLIENT_PROPAGATED)
    {
      // Encapsulate the priority of the current thread into
      // a service context.
      TAO_OutputCDR cdr;
      if ((cdr << ACE_OutputCDR::from_boolean (TAO_ENCAP_BYTE_ORDER)
           == 0)
          || (cdr << client_priority)
          == 0)
        ACE_THROW (CORBA::MARSHAL ());
      
      // @@ The piece of code that comes here should go. It should
      // be something like this.
      // IOP::ServiceContext context;
      // context.context_id = IOP::RTCorbaPriority;
      // this->op_details_.service_context ().set_context
      // (context, cdr);
      // RT Folks can you please do these changes consistently
      // wherever you guys are adding service context information
      // - Bala
      IOP::ServiceContextList &context_list = invocation->service_info ();

      CORBA::ULong l = context_list.length ();
      context_list.length (l + 1);
      context_list[l].context_id = IOP::RTCorbaPriority;

      // Make a *copy* of the CDR stream...
      CORBA::ULong length = cdr.total_length ();
      context_list[l].context_data.length (length);
      CORBA::Octet *buf = context_list[l].context_data.get_buffer ();

      for (const ACE_Message_Block *i = cdr.begin ();
           i != 0;
           i = i->cont ())
        {
          ACE_OS::memcpy (buf,
                          i->rd_ptr (),
                           i->length ());
          buf += i->length ();
        }
    }
}

void
TAO_RT_Protocols_Hooks::get_selector_hook (
                           CORBA::Policy *model_policy,
                           CORBA::Boolean &is_client_propagated,
                           CORBA::Short &server_priority)
{

  RTCORBA::PriorityModelPolicy_var model_policy_ptr =
    RTCORBA::PriorityModelPolicy::_narrow (model_policy);

  TAO_PriorityModelPolicy *priority_model_policy =
    ACE_static_cast (TAO_PriorityModelPolicy *,
                     model_policy_ptr.in ());

  if (priority_model_policy->get_priority_model ()
      == RTCORBA::CLIENT_PROPAGATED)
    is_client_propagated = 1;

  if (!is_client_propagated)
    server_priority = priority_model_policy->server_priority ();

  return;
}

void
TAO_RT_Protocols_Hooks::get_selector_bands_policy_hook (
                           CORBA::Policy *bands_policy,
                           CORBA::Short &min_priority,
                           CORBA::Short &max_priority,
                           CORBA::Short &p,
                           int &in_range)
{
  RTCORBA::PriorityBandedConnectionPolicy_var bands_policy_ptr =
    RTCORBA::PriorityBandedConnectionPolicy::_narrow (bands_policy);

  TAO_PriorityBandedConnectionPolicy *priority_bands_policy =
    ACE_static_cast (TAO_PriorityBandedConnectionPolicy *,
                     bands_policy_ptr.in ());

  // Find the band with the range covering our target priority.
  RTCORBA::PriorityBands &bands =
    priority_bands_policy->priority_bands_rep ();

  for (CORBA::ULong i = 0; i < bands.length (); ++i)
    if (bands[i].low <= p && bands[i].high >= p)
      {
        min_priority = bands[i].low;
        max_priority = bands[i].high;

        in_range = 1;
        break;
      }
  return;
}

void
TAO_RT_Protocols_Hooks::select_endpoint_hook (
                          TAO_GIOP_Invocation *invocation,
                          CORBA::Policy *client_protocol_policy,
                          TAO_Profile *& profile,
                          CORBA::Environment &ACE_TRY_ENV)
{
  RTCORBA::ClientProtocolPolicy_var cp_policy = 
    RTCORBA::ClientProtocolPolicy::_narrow (client_protocol_policy,
                                            ACE_TRY_ENV);
  ACE_CHECK;

  TAO_ClientProtocolPolicy *client_protocol =
    ACE_static_cast (TAO_ClientProtocolPolicy *,
                     cp_policy.in ());

  RTCORBA::ProtocolList & protocols =
    client_protocol->protocols_rep ();
  
  CORBA::ULong protocol_index =
    invocation->get_endpoint_selection_state ().client_protocol_index_;
  
  if (protocols.length () == protocol_index)
    // We have tried all the protocols specified in the client
    // protocol policy with no success.  Throw exception.
    {
      // Figure out proper exception.
      if (!invocation->get_endpoint_selection_state ().valid_endpoint_found_)
        {
          if (invocation->get_inconsistent_policies ())
            {
              invocation->get_inconsistent_policies ()->length (1);
              CORBA::PolicyList_var inconsistent_policies = 
                invocation->get_inconsistent_policies ();
              inconsistent_policies [0u] =
                CORBA::Policy::_duplicate (invocation->
                                           get_endpoint_selection_state ().client_protocol_policy_);
            }
          ACE_THROW (CORBA::INV_POLICY ());
        }
      else
        // At least one satisfactory endpoint was found, but
        // connection could not be established.
        ACE_THROW (CORBA::COMM_FAILURE ());
    }
  
  // Find a Profile for the next protocol we would like to try.
  TAO_MProfile& mprofile = invocation->get_stub ()->base_profiles ();

  for (TAO_PHandle i = 0;
       i < mprofile.profile_count ();
       ++i)
    {
      TAO_Profile *pf = mprofile.get_profile (i);
      if (pf->tag ()
          == protocols[protocol_index].protocol_type)
        {
          profile = pf;
          break;
        }
    }

  return;
}

ACE_STATIC_SVC_DEFINE (TAO_RT_Protocols_Hooks,
                       ACE_TEXT ("RT_Protocols_Hooks"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_RT_Protocols_Hooks),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)
ACE_FACTORY_DEFINE (TAO, TAO_RT_Protocols_Hooks)

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Dynamic_Service<TAO_RT_Protocols_Hooks>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Dynamic_Service<TAO_RT_Protocols_Hooks>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
