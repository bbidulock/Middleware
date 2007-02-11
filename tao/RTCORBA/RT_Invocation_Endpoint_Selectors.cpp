#include "tao/RTCORBA/RT_Invocation_Endpoint_Selectors.h"

#if defined (TAO_HAS_CORBA_MESSAGING) && TAO_HAS_CORBA_MESSAGING != 0

#include "tao/RTCORBA/RT_Policy_i.h"
#include "tao/RTCORBA/RT_Stub.h"
#include "tao/RTCORBA/RT_Transport_Descriptor.h"
#include "tao/RTCORBA/RT_Transport_Descriptor_Property.h"
#include "tao/RTCORBA/RT_Endpoint_Utils.h"
#include "tao/RTCORBA/RT_Protocols_Hooks.h"
#include "tao/Stub.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Endpoint.h"
#include "tao/debug.h"
#include "tao/Profile.h"
#include "tao/Endpoint.h"
#include "tao/Profile_Transport_Resolver.h"
#include "tao/ORB_Core.h"
#include "tao/SystemException.h"

ACE_RCSID (RTCORBA,
           RT_Invocation_Endpoint_Selectors,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

void
TAO_RT_Invocation_Endpoint_Selector::select_endpoint (
    TAO::Profile_Transport_Resolver *r,
    ACE_Time_Value *val)
{
  if (r == 0)
    throw ::CORBA::INTERNAL ();

  CORBA::Policy_var client_protocol_policy_base =
    TAO_RT_Endpoint_Utils::policy (TAO_CACHED_POLICY_RT_CLIENT_PROTOCOL, *r);

  if (client_protocol_policy_base.ptr () == 0)
    {
      do
        {
          r->profile (r->stub ()->profile_in_use ());

          int const status = this->endpoint_from_profile (*r, val);

          if (status == 1)
            return;
        }
      while (r->stub ()->next_profile_retry () != 0);

      // If we get here, we completely failed to find an endpoint selector
      // that we know how to use, so throw an exception.
      throw ::CORBA::TRANSIENT (CORBA::OMGVMCID | 2, CORBA::COMPLETED_NO);
    }
  else
    {
      RTCORBA::ClientProtocolPolicy_var client_protocol_policy =
        RTCORBA::ClientProtocolPolicy::_narrow (
          client_protocol_policy_base.in ());

      /// Cast to TAO_ClientProtocolPolicy
      TAO_ClientProtocolPolicy *tao_client_protocol_policy =
        static_cast<TAO_ClientProtocolPolicy *> (client_protocol_policy.in ());

      /// Get the ProtocolList
      RTCORBA::ProtocolList &client_protocols =
        tao_client_protocol_policy->protocols_rep ();

      this->select_endpoint_based_on_client_protocol_policy (
        *r,
        client_protocol_policy.in (),
        client_protocols,
        val
       );
    }
}

void
TAO_RT_Invocation_Endpoint_Selector::select_endpoint_based_on_client_protocol_policy (
    TAO::Profile_Transport_Resolver &r,
    RTCORBA::ClientProtocolPolicy_ptr client_protocol_policy,
    RTCORBA::ProtocolList &client_protocols,
    ACE_Time_Value *val)
{
  CORBA::Boolean valid_profile_found = false;

  // Even though cycling through all the protocols is the correct
  // things to do to find a match, starting from the start of the
  // profile list is not.  In addition, this code is also ignoring the
  // forwarded reference (if it exists).  This behavior is caused by
  // problems with the profile management in TAO which are documented
  // in bugzilla bugs 1237, 1238, and 1239.  Once the above problems
  // are fixed, this behavior should be fixed to do the right thing.
  for (CORBA::ULong protocol_index = 0;
       protocol_index < client_protocols.length ();
       ++protocol_index)
    {
      // Find the profiles that match the current protocol.
      TAO_Profile *profile = 0;
      TAO_MProfile &mprofile = r.stub ()->base_profiles ();

      for (TAO_PHandle i = 0;
           i < mprofile.profile_count ();
           ++i)
        {
          profile = mprofile.get_profile (i);

          if (profile->tag () == client_protocols[protocol_index].protocol_type)
            {
              valid_profile_found = true;

              r.profile (profile);

              int const status = this->endpoint_from_profile (r, val);

              if (status == 1)
                return;
              // @@ Else we should check for potential forwarding here.
            }
        }
    }

  // We have tried all the profiles specified in the client protocol
  // policy with no success.  Throw exception.
  if (!valid_profile_found)
    {
      if (r.inconsistent_policies ())
        {
          CORBA::PolicyList *p = r.inconsistent_policies ();

          p->length (1);
          (*p)[0u] = CORBA::Policy::_duplicate (client_protocol_policy);
        }
      throw ::CORBA::INV_POLICY ();
    }

  // If we get here, we found at least one pertinent profile, but no
  // usable endpoints.
  throw ::CORBA::TRANSIENT (CORBA::OMGVMCID | 2, CORBA::COMPLETED_NO);

}

int
TAO_RT_Invocation_Endpoint_Selector::endpoint_from_profile (
    TAO::Profile_Transport_Resolver &r,
    ACE_Time_Value *val)
{
  // Narrow to the RT Stub.
  TAO_RT_Stub *rt_stub = dynamic_cast <TAO_RT_Stub *> (r.stub ());

  // Get the priority model policy.
  CORBA::Policy_var priority_model_policy =
    rt_stub->get_cached_policy (TAO_CACHED_POLICY_PRIORITY_MODEL);

  // Get the bands policy.
  CORBA::Policy_var bands_policy =
    TAO_RT_Endpoint_Utils::policy (
      TAO_CACHED_POLICY_RT_PRIORITY_BANDED_CONNECTION, r);

  int all_endpoints_are_valid = 0;
  int match_priority = 0;
  int match_bands = 0;
  CORBA::Short client_thread_priority = 0;
  CORBA::Short min_priority = 0;
  CORBA::Short max_priority = 0;

  // If the priority model policy is not set.
  if (priority_model_policy.ptr () == 0)
    {
      // Bands without priority model do not make sense.
      if (bands_policy.ptr () != 0)
        {
          if (r.inconsistent_policies ())
            {
              CORBA::PolicyList *p = r.inconsistent_policies ();

              p->length (1);
              (*p)[0u] = CORBA::Policy::_duplicate (bands_policy.in ());
            }
          // Indicate error.
          throw ::CORBA::INV_POLICY ();
        }

      // No priority model policy (and no bands policy): all endpoints
      // are fair game.
      all_endpoints_are_valid = 1;
    }
  // If the priority model policy is set.
  else
    {
      // Get the protocol hooks.
      TAO_Protocols_Hooks *protocol_hooks =
        r.stub ()->orb_core ()->get_protocols_hooks ();

      CORBA::Short server_priority = 0;
      CORBA::Boolean is_client_propagated = false;

      // Check the priority model policy to see if it is client
      // propagated.
      protocol_hooks->get_selector_hook (priority_model_policy.in (),
                                         is_client_propagated,
                                         server_priority);

      if (!is_client_propagated)
        {
          // Server declared: all endpoints are fair game.
          all_endpoints_are_valid = 1;
        }
      // Client propagated.
      else
        {
          // Get client thread priority.
          int status =
            protocol_hooks->get_thread_CORBA_priority (
              client_thread_priority  // side effect
             );
          if (status == -1)
            {
              throw ::CORBA::DATA_CONVERSION (
                CORBA::OMGVMCID | 1,
                CORBA::COMPLETED_NO);
            }

          // If there are no bands.
          if (bands_policy.ptr () == 0)
            {

              // Match the priority of the client thread with the
              // endpoint.
              match_priority = 1;
            }
          // There are bands.
          else
            {

              // Check which band range we fall in.
              bool in_range = false;
              protocol_hooks->get_selector_bands_policy_hook (
                bands_policy.in (),
                client_thread_priority,
                min_priority,
                max_priority,
                in_range);

              // If priority doesn't fall into any of the bands.
              if (!in_range)
                {
                  if (r.inconsistent_policies ())
                    {

                      CORBA::PolicyList *p = r.inconsistent_policies ();
                      p->length (2);
                      (*p)[0u] = CORBA::Policy::_duplicate (bands_policy.in ());
                      (*p)[1u] =
                        CORBA::Policy::_duplicate (
                          priority_model_policy.in ());
                    }

                  // Indicate error.
                  throw ::CORBA::INV_POLICY ();
                }

              // Match the priority of the band with the endpoint.
              match_bands = 1;
            }
        }
    }

  TAO_Endpoint *ep =
    r.profile ()->endpoint ();

  while (ep != 0)
    {
      // Get the priority of the endpoint.
      CORBA::Short endpoint_priority = ep->priority ();

      // If <all_endpoints_are_valid> or match the priority of the
      // client thread or match the priority of the band or
      // profile contains just one endpoint.  This happens when:
      //    a) we are talking to a nonTAO server (which doesn't have
      //       the concept of multiple endpoints per profile)
      //    or
      //    b) we have TAO server with a non-lane threadpool, in which
      //    case there is only one acceptor
      // In both cases we should use the endpoint regardless of its priority.

      if (all_endpoints_are_valid ||
          (match_priority &&
           client_thread_priority == endpoint_priority) ||
          (match_bands &&
           endpoint_priority <= max_priority &&
           endpoint_priority >= min_priority) ||
          r.profile ()->endpoint_count () == 1 &&
          endpoint_priority == TAO_INVALID_PRIORITY)
        {
          TAO_RT_Transport_Descriptor_Private_Connection_Property
            private_connection_descriptor_property;

          TAO_RT_Transport_Descriptor_Banded_Connection_Property
            banded_connection_descriptor_property;

          TAO_RT_Transport_Descriptor
            rt_transport_descriptor (ep);

          CORBA::Policy_var private_connection_policy =
            rt_stub->get_cached_policy (TAO_CACHED_POLICY_RT_PRIVATE_CONNECTION
                                       );

          if (!CORBA::is_nil (private_connection_policy.in ()))
            {
              private_connection_descriptor_property.init
                (static_cast<long> (reinterpret_cast<ptrdiff_t> (r.stub ())));
              rt_transport_descriptor.insert
                (&private_connection_descriptor_property);
            }

          if (match_bands)
            {
              banded_connection_descriptor_property.init
                (min_priority, max_priority);

              rt_transport_descriptor.insert
                (&banded_connection_descriptor_property);
            }

          bool status =
            r.try_connect (&rt_transport_descriptor,
                           val
                          );

          // Check if the invocation has completed.
          if (status == true)
            return 1;
        }

      // Go to the next endpoint in this profile.
      ep = ep->next();
    }

  return 0;
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_HAS_CORBA_MESSAGING != 0 */
