#include "RT_Servant_Dispatcher.h"
#include "RT_POA.h"
#include "tao/RTCORBA/Thread_Pool.h"
#include "tao/ORB_Core.h"
#include "tao/TAO_Server_Request.h"
#include "tao/Transport.h"
#include "tao/IIOP_Transport.h"
#include "tao/IIOP_Connection_Handler.h"
#include "tao/Service_Context.h"
#include "tao/Protocols_Hooks.h"
#include "tao/debug.h"


ACE_RCSID (RTPortableServer,
           RT_Servant_Dispatcher,
           "$Id$")


TAO_RT_Servant_Dispatcher::~TAO_RT_Servant_Dispatcher (void)
{
}

void
TAO_RT_Servant_Dispatcher::pre_invoke_remote_request (
  TAO_POA &poa,
  CORBA::Short servant_priority,
  TAO_ServerRequest &req,
  TAO_Object_Adapter::Servant_Upcall::Pre_Invoke_State &pre_invoke_state
  ACE_ENV_ARG_DECL)
{
  TAO_Service_Context &request_service_context =
    req.request_service_context ();
  TAO_Service_Context &reply_service_context = req.reply_service_context ();

  TAO_Thread_Pool *thread_pool =
    (TAO_Thread_Pool *) poa.thread_pool ();

  if (thread_pool != 0 &&
      thread_pool->with_lanes ())
    {
      //
      // We don't mess with the priority of threads in lanes.
      //

      if (TAO_debug_level > 0)
        {
          // Get the ORB_Core's TSS resources.
          TAO_ORB_Core_TSS_Resources *tss =
            poa.orb_core ().get_tss_resources ();

          /// Get the lane attribute in TSS.
          TAO_Thread_Lane *lane =
            (TAO_Thread_Lane *) tss->lane_;

          ACE_ASSERT (lane->pool ().id () ==
                      thread_pool->id ());

          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("Using thread pool with lane ")
                      ACE_TEXT ("(%P|%t|%d|%d): original thread ")
                      ACE_TEXT ("CORBA/native priority %d/%d not changed\n"),
                      lane->pool ().id (),
                      lane->id (),
                      lane->lane_priority (),
                      lane->native_priority ()));
        }

      return;
    }

  // Remember current thread's priority.
  TAO_Protocols_Hooks *tph =
    poa.orb_core ().get_protocols_hooks (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;


  if (req.transport ()->tag () == IOP::TAG_INTERNET_IOP)
    {
      /*
	int send_buffer_size;
	int recv_buffer_size;
	int no_delay;
	int enable_network_priority;
      */
      const char protocol [] = "iiop";
      const char *protocol_type = protocol;

      TAO_IIOP_Transport *iiop_transport =
        ACE_dynamic_cast (TAO_IIOP_Transport *,
                          req.transport ());

      CORBA::Policy* policy = poa.server_protocol ();

      int result =
	tph->update_server_protocol_properties (
          policy,
          iiop_transport-> connection_handler_i (),
          protocol_type);

      if (result != 0)
	ACE_ERROR((LM_ERROR,
		   "Error in getting the effective protocol properties\n"));

      /*
	iiop_transport ()->connection_handler ()->update_protocol_properties (send_buffer_size,
	recv_buffer_size,
	no_delay,
	enable_network_priority);
      */
  }

  if (tph->get_thread_CORBA_and_native_priority (
        pre_invoke_state.original_CORBA_priority_,
        pre_invoke_state.original_native_priority_
        ACE_ENV_ARG_PARAMETER) == -1)
    ACE_THROW (CORBA::DATA_CONVERSION (CORBA::OMGVMCID | 2,
                                       CORBA::COMPLETED_NO));

  const char *priority_model;
  RTCORBA::Priority target_priority = TAO_INVALID_PRIORITY;
  TAO_POA_Cached_Policies &cached_policies =
    poa.cached_policies ();

  // NOT_SPECIFIED PriorityModel processing.
  if (cached_policies.priority_model () ==
      TAO_POA_Cached_Policies::NOT_SPECIFIED)
    {
      priority_model = "RTCORBA::NOT_SPECIFIED";
    }

  // CLIENT_PROPAGATED PriorityModel processing.
  else if (cached_policies.priority_model () ==
      TAO_POA_Cached_Policies::CLIENT_PROPAGATED)
    {
      priority_model = "RTCORBA::CLIENT_PROPAGATED";

      // Attempt to extract client-propagated priority from the
      // ServiceContextList of the request.
      const IOP::ServiceContext *context;

      if (request_service_context.get_context (IOP::RTCorbaPriority,
                                               &context) == 1)
        {
          // Extract the target priority
          TAO_InputCDR cdr (ACE_reinterpret_cast
                            (const char*,
                             context->context_data.get_buffer ()),
                            context->context_data.length ());
          CORBA::Boolean byte_order;
          if ((cdr >> ACE_InputCDR::to_boolean (byte_order)) == 0)
            ACE_THROW (CORBA::MARSHAL ());
          cdr.reset_byte_order (ACE_static_cast(int,byte_order));

          if ((cdr >> target_priority) == 0)
            ACE_THROW (CORBA::MARSHAL ());

          // Save the target priority in the response service
          // context to propagate back to the client as specified
          // by the RTCORBA specification.
          reply_service_context.set_context (*context);
        }
      else
        {
          // Use default priority if none came in the request.
          // (Request must have come from a non-RT ORB.)
          target_priority = cached_policies.server_priority ();
        }
    }
  else
    // SERVER_DECLARED PriorityModel processing.
    {
      priority_model = "RTCORBA::SERVER_DECLARED";

      // Use the request associated with the servant.
      target_priority = servant_priority;
    }

  char thread_pool_id[BUFSIZ];
  if (TAO_debug_level > 0)
    {
      if (thread_pool == 0)
        ACE_OS::strcpy (thread_pool_id,
                        "default thread pool");
      else
        ACE_OS::sprintf (thread_pool_id,
                         "thread pool %d",
                         thread_pool->id ());
    }

  // Change the priority of the current thread for the duration of
  // request.
  if (target_priority != TAO_INVALID_PRIORITY &&
      target_priority != pre_invoke_state.original_CORBA_priority_)
    {
      if (tph->set_thread_CORBA_priority (target_priority
                                          ACE_ENV_ARG_PARAMETER)
          == -1)
        ACE_THROW (CORBA::DATA_CONVERSION (CORBA::OMGVMCID | 2,
                                           CORBA::COMPLETED_NO));

      pre_invoke_state.state_ =
        TAO_Object_Adapter::Servant_Upcall::Pre_Invoke_State::PRIORITY_RESET_REQUIRED;

      if (TAO_debug_level > 0)
        {
          CORBA::Short native_priority;
          tph->get_thread_native_priority (native_priority
                                           ACE_ENV_ARG_PARAMETER);

          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("%s processing using %s ")
                      ACE_TEXT ("(%P|%t): original thread CORBA/native priority %d/%d ")
                      ACE_TEXT ("temporarily changed to CORBA/native priority %d/%d\n"),
                      priority_model,
                      thread_pool_id,
                      pre_invoke_state.original_CORBA_priority_,
                      pre_invoke_state.original_native_priority_,
                      target_priority,
                      native_priority));
        }
    }
  // No change in priority required.
  else if (target_priority != TAO_INVALID_PRIORITY &&
           target_priority == pre_invoke_state.original_CORBA_priority_)
    {
      if (TAO_debug_level > 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("%s processing using %s ")
                      ACE_TEXT ("(%P|%t): original thread CORBA/native priority %d/%d ")
                      ACE_TEXT ("is the same as the target priority\n"),
                      priority_model,
                      thread_pool_id,
                      pre_invoke_state.original_CORBA_priority_,
                      pre_invoke_state.original_native_priority_));
        }
    }
  // Target priority is invalid.
  else
    {
      if (TAO_debug_level > 0)
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("%s processing using %s ")
                      ACE_TEXT ("(%P|%t): original thread CORBA/native priority %d/%d ")
                      ACE_TEXT ("not changed\n"),
                      priority_model,
                      thread_pool_id,
                      pre_invoke_state.original_CORBA_priority_,
                      pre_invoke_state.original_native_priority_));
        }
    }
}

void
TAO_RT_Servant_Dispatcher::pre_invoke_collocated_request (TAO_POA &poa,
                                                          CORBA::Short servant_priority,
                                                          TAO_Object_Adapter::Servant_Upcall::Pre_Invoke_State &pre_invoke_state
                                                          ACE_ENV_ARG_DECL)
{
  TAO_Thread_Pool *thread_pool =
    (TAO_Thread_Pool *) poa.thread_pool ();

  if (thread_pool == 0 ||
      thread_pool->with_lanes ())
    {
      //
      // We don't mess with the priority of threads in lanes or for
      // the default thread pool.
      //
      return;
    }

  TAO_POA_Cached_Policies &cached_policies =
    poa.cached_policies ();

  if (cached_policies.priority_model () !=
      TAO_POA_Cached_Policies::SERVER_DECLARED ||
      servant_priority == TAO_INVALID_PRIORITY)
    {
      //
      // We either don't have server declared model or servant
      // priority is invalid.
      //
      return;
    }

  //
  // SERVER_DECLARED PriorityModel processing.
  //

  // Remember current thread's priority.
  TAO_Protocols_Hooks *tph =
    poa.orb_core ().get_protocols_hooks (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  if (tph->get_thread_CORBA_and_native_priority (pre_invoke_state.original_CORBA_priority_,
                                                 pre_invoke_state.original_native_priority_
                                                 ACE_ENV_ARG_PARAMETER)
      == -1)
    ACE_THROW (CORBA::DATA_CONVERSION (CORBA::OMGVMCID | 2,
                                       CORBA::COMPLETED_NO));

  // Change the priority of the current thread for the duration of
  // request.
  if (servant_priority != pre_invoke_state.original_CORBA_priority_)
    {
      if (tph->set_thread_CORBA_priority (servant_priority
                                          ACE_ENV_ARG_PARAMETER)
          == -1)
        ACE_THROW (CORBA::DATA_CONVERSION (CORBA::OMGVMCID | 2,
                                           CORBA::COMPLETED_NO));

      pre_invoke_state.state_ =
        TAO_Object_Adapter::Servant_Upcall::Pre_Invoke_State::PRIORITY_RESET_REQUIRED;
    }
}

void
TAO_RT_Servant_Dispatcher::post_invoke (TAO_POA &poa,
                                        TAO_Object_Adapter::Servant_Upcall::Pre_Invoke_State &pre_invoke_state)

{
  if (pre_invoke_state.state_ ==
      TAO_Object_Adapter::Servant_Upcall::Pre_Invoke_State::PRIORITY_RESET_REQUIRED)
    {
      pre_invoke_state.state_ =
        TAO_Object_Adapter::Servant_Upcall::Pre_Invoke_State::NO_ACTION_REQUIRED;

      ACE_DECLARE_NEW_CORBA_ENV;

      ACE_TRY
        {
          // Reset the priority of the current thread back to its original
          // value.
          TAO_Protocols_Hooks *tph =
            poa.orb_core ().get_protocols_hooks (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;

          if (tph->set_thread_native_priority (
                 pre_invoke_state.original_native_priority_
                                               ACE_ENV_ARG_PARAMETER)
              == -1)
            ACE_THROW (CORBA::DATA_CONVERSION (CORBA::OMGVMCID | 2,
                                               CORBA::COMPLETED_NO));
          ACE_TRY_CHECK;
        }
      ACE_CATCHANY
        {
          // Eat up the exception.
          ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                               "Exception caught: TAO (%P|%t) - "
                               "Priority_Model_Processing::"
                               "~Priority_Model_Processing");
        }
      ACE_ENDTRY;
    }
}

TAO_POA *
TAO_RT_Servant_Dispatcher::create_POA (const ACE_CString &name,
                                       TAO_POA_Manager &poa_manager,
                                       const TAO_POA_Policy_Set &policies,
                                       TAO_POA *parent,
                                       ACE_Lock &lock,
                                       TAO_SYNCH_MUTEX &thread_lock,
                                       TAO_ORB_Core &orb_core,
                                       TAO_Object_Adapter *object_adapter
                                       ACE_ENV_ARG_DECL)
{
  TAO_RT_POA *poa;

  ACE_NEW_THROW_EX (poa,
                    TAO_RT_POA (name,
                                poa_manager,
                                policies,
                                parent,
                                lock,
                                thread_lock,
                                orb_core,
                                object_adapter
                                ACE_ENV_ARG_PARAMETER),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (0);

  return poa;
}
