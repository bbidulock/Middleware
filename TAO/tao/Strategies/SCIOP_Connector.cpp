#include "SCIOP_Connector.h"
#include "SCIOP_Profile.h"

#if TAO_HAS_SCIOP == 1

#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/Client_Strategy_Factory.h"
#include "tao/Environment.h"
#include "tao/Base_Transport_Property.h"
#include "tao/Protocols_Hooks.h"
#include "tao/Transport_Cache_Manager.h"
#include "tao/Connect_Strategy.h"
#include "tao/Thread_Lane_Resources.h"
#include "tao/Transport.h"
#include "tao/Wait_Strategy.h"
#include "tao/Profile_Transport_Resolver.h"

#include "ace/OS_NS_strings.h"
#include "ace/Strategies_T.h"


ACE_RCSID (TAO,
           SCIOP_Connector,
           "$Id$")


#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class TAO_Connect_Concurrency_Strategy<TAO_SCIOP_Connection_Handler>;
template class TAO_Connect_Creation_Strategy<TAO_SCIOP_Connection_Handler>;
template class ACE_Strategy_Connector<TAO_SCIOP_Connection_Handler, ACE_SOCK_SEQPACK_CONNECTOR>;
template class ACE_Connect_Strategy<TAO_SCIOP_Connection_Handler, ACE_SOCK_SEQPACK_CONNECTOR>;
template class ACE_Connector_Base<TAO_SCIOP_Connection_Handler>;
template class ACE_Connector<TAO_SCIOP_Connection_Handler, ACE_SOCK_SEQPACK_CONNECTOR>;
template class ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler>;

template class ACE_Map_Manager<ACE_HANDLE, ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler> *, TAO_SYNCH_RW_MUTEX>;
template class ACE_Map_Iterator_Base<ACE_HANDLE, ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler> *, TAO_SYNCH_RW_MUTEX>;
template class ACE_Map_Entry<ACE_HANDLE,ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler>*>;
template class ACE_Map_Iterator<ACE_HANDLE,ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler>*,TAO_SYNCH_RW_MUTEX>;
template class ACE_Map_Reverse_Iterator<ACE_HANDLE,ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler>*,TAO_SYNCH_RW_MUTEX>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate TAO_Connect_Concurrency_Strategy<TAO_SCIOP_Connection_Handler>
#pragma instantiate TAO_Connect_Creation_Strategy<TAO_SCIOP_Connection_Handler>
#pragma instantiate ACE_Strategy_Connector<TAO_SCIOP_Connection_Handler, ACE_SOCK_SEQPACK_CONNECTOR>
#pragma instantiate ACE_Connect_Strategy<TAO_SCIOP_Connection_Handler, ACE_SOCK_SEQPACK_CONNECTOR>
#pragma instantiate ACE_Connector_Base<TAO_SCIOP_Connection_Handler>
#pragma instantiate ACE_Connector<TAO_SCIOP_Connection_Handler, ACE_SOCK_SEQPACK_CONNECTOR>
#pragma instantiate ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler>

#pragma instantiate ACE_Map_Manager<ACE_HANDLE, ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler> *, TAO_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Iterator_Base<ACE_HANDLE, ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler> *, TAO_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Entry<ACE_HANDLE,ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler>*>
#pragma instantiate ACE_Map_Iterator<ACE_HANDLE,ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler>*,TAO_SYNCH_RW_MUTEX>
#pragma instantiate ACE_Map_Reverse_Iterator<ACE_HANDLE,ACE_Svc_Tuple<TAO_SCIOP_Connection_Handler>*,TAO_SYNCH_RW_MUTEX>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */


TAO_SCIOP_Connector::TAO_SCIOP_Connector (CORBA::Boolean flag)
  : TAO_Connector (TAO_TAG_SCIOP_PROFILE),
    lite_flag_ (flag),
    connect_strategy_ (),
    base_connector_ ()
{
}

TAO_SCIOP_Connector::~TAO_SCIOP_Connector (void)
{
}

int
TAO_SCIOP_Connector::open (TAO_ORB_Core *orb_core)
{
  // @@todo: The functionality of the following two statements could
  // be  done in the constructor, but that involves changing the
  // interface of the pluggable transport factory.

  // Set the ORB Core
  this->orb_core (orb_core);

  // Create our connect strategy
  if (this->create_connect_strategy () == -1)
    return -1;

  /// Our connect creation strategy
  TAO_SCIOP_CONNECT_CREATION_STRATEGY *connect_creation_strategy = 0;

  ACE_NEW_RETURN (connect_creation_strategy,
                  TAO_SCIOP_CONNECT_CREATION_STRATEGY
                      (orb_core->thr_mgr (),
                       orb_core,
                       this->lite_flag_),
                  -1);

  /// Our activation strategy
  TAO_SCIOP_CONNECT_CONCURRENCY_STRATEGY *concurrency_strategy = 0;

  ACE_NEW_RETURN (concurrency_strategy,
                  TAO_SCIOP_CONNECT_CONCURRENCY_STRATEGY (orb_core),
                  -1);

  return this->base_connector_.open (this->orb_core ()->reactor (),
                                     connect_creation_strategy,
                                     &this->connect_strategy_,
                                     concurrency_strategy);
}

int
TAO_SCIOP_Connector::close (void)
{
  delete this->base_connector_.concurrency_strategy ();
  delete this->base_connector_.creation_strategy ();
  return this->base_connector_.close ();
}

int
TAO_SCIOP_Connector::set_validate_endpoint (TAO_Endpoint *endpoint)
{
  TAO_SCIOP_Endpoint *sciop_endpoint =
    this->remote_endpoint (endpoint);

  if (sciop_endpoint == 0)
    return -1;

   const ACE_INET_Addr &remote_address =
     sciop_endpoint->object_addr ();

   // Verify that the remote ACE_INET_Addr was initialized properly.
   // Failure can occur if hostname lookup failed when initializing the
   // remote ACE_INET_Addr.
   if (remote_address.get_type () != AF_INET)
     {
       if (TAO_debug_level > 0)
         {
           ACE_DEBUG ((LM_DEBUG,
                       ACE_TEXT ("TAO (%P|%t) SCIOP connection failed.\n")
                       ACE_TEXT ("TAO (%P|%t) This is most likely ")
                       ACE_TEXT ("due to a hostname lookup ")
                       ACE_TEXT ("failure.\n")));
         }

       return -1;
     }

   return 0;
}

TAO_Transport *
TAO_SCIOP_Connector::make_connection (TAO::Profile_Transport_Resolver *r,
                                      TAO_Transport_Descriptor_Interface &desc,
                                      ACE_Time_Value *timeout)
{
  TAO_Endpoint *tao_endpoint = desc.endpoint ();

  TAO_Transport *transport = 0;

  // @@ ATL folks, is this while loop needed?
  // TAO_Default_Endpoint_Selector has this code already, i.e., the
  // loop.
  while (tao_endpoint != 0)
    {
      TAO_SCIOP_Endpoint *sciop_endpoint =
        this->remote_endpoint (tao_endpoint);

      if (sciop_endpoint != 0)
        {
          transport =
            this->make_connection_i (r, desc, timeout, sciop_endpoint);
          if (transport)
            {
              break;
            }
        }
      tao_endpoint = tao_endpoint->next();
    }

  return transport;
}


TAO_Transport *
TAO_SCIOP_Connector::make_connection_i (TAO::Profile_Transport_Resolver *r,
                                        TAO_Transport_Descriptor_Interface &desc,
                                        ACE_Time_Value *timeout,
                                        TAO_SCIOP_Endpoint *sciop_endpoint)
{
  const ACE_INET_Addr &remote_address =
    sciop_endpoint->object_addr ();

  if (TAO_debug_level > 2)
      ACE_DEBUG ((LM_DEBUG,
                  "TAO (%P|%t) - SCIOP_Connector::make_connection_i, "
                  "to <%s:%d> which should %s\n",
                  ACE_TEXT_CHAR_TO_TCHAR(sciop_endpoint->host()),
                  sciop_endpoint->port(),
                  r->blocked_connect () ? ACE_TEXT("block") : ACE_TEXT("nonblock")));

  // Get the right synch options
  ACE_Synch_Options synch_options;

  this->active_connect_strategy_->synch_options (timeout,
                                                 synch_options);

  // If we don't need to block for a transport just set the timeout to
  // be zero.
  ACE_Time_Value tmp_zero (ACE_Time_Value::zero);
  if (!r->blocked_connect())
    {
      synch_options.timeout (ACE_Time_Value::zero);
      timeout = &tmp_zero;
    }

  TAO_SCIOP_Connection_Handler *svc_handler = 0;

  // Connect.
  ACE_Multihomed_INET_Addr multihomed;
  if (multihomed.set(remote_address.get_port_number(),
                     remote_address.get_ip_address()))
    return 0;

  ACE_Multihomed_INET_Addr local_address;

  bool pn =
    sciop_endpoint->is_preferred_network ();

  if (pn)
    local_address.set ((u_short) 0,
                       sciop_endpoint->preferred_network ());

  int result =
    this->base_connector_.connect (svc_handler,
                                   multihomed,
                                   synch_options,
                                   local_address);

  // This call creates the service handler and bumps the #REFCOUNT# up
  // one extra.  There are three possibilities: (a) connection
  // succeeds immediately - in this case, the #REFCOUNT# on the
  // handler is two; (b) connection completion is pending - in this
  // case, the #REFCOUNT# on the handler is also two; (c) connection
  // fails immediately - in this case, the #REFCOUNT# on the handler
  // is one since close() gets called on the handler.
  //
  // The extra reference count in
  // TAO_Connect_Creation_Strategy::make_svc_handler() is needed in
  // the case when connection completion is pending and we are going
  // to wait on a variable in the handler to changes, signifying
  // success or failure.  Note, that this increment cannot be done
  // once the connect() returns since this might be too late if
  // another thread pick up the completion and potentially deletes the
  // handler before we get a chance to increment the reference count.

  // Make sure that we always do a remove_reference
  ACE_Event_Handler_var svc_handler_auto_ptr (svc_handler);

  TAO_Transport *transport =
    svc_handler->transport ();

  if (result == -1)
    {
      // No immediate result, wait for completion
      if (errno == EWOULDBLOCK)
        {
          // Try to wait until connection completion. Incase we block, then we
          // get a connected transport or not. In case of non block we get
          // a connected or not connected transport
          if (!this->wait_for_connection_completion (r,
                                                     transport,
                                                     timeout))
            {
              if (TAO_debug_level > 2)
                ACE_ERROR ((LM_ERROR, "TAO (%P|%t) - SCIOP_Connector::"
                                      "make_connection_i, "
                                      "wait for completion failed\n"));
            }
         }
       else
         {
           // Transport is not usable
           transport = 0;
         }
    }

  // In case of errors transport is zero
  if (transport == 0)
    {
      // Give users a clue to the problem.
      if (TAO_debug_level)
        {
          ACE_DEBUG ((LM_ERROR,
                      "TAO (%P|%t) - SCIOP_Connector::make_connection_i, "
                      "connection to <%s:%d> failed (%p)\n",
                      sciop_endpoint->host (), sciop_endpoint->port (),
                      "errno"));
        }

      return 0;
    }

  // At this point, the connection has be successfully connected.
  // #REFCOUNT# is one.
  if (TAO_debug_level > 2)
    ACE_DEBUG ((LM_DEBUG,
                "TAO (%P|%t) - SCIOP_Connector::make_connection_i, "
                "new %s connection to <%s:%d> on Transport[%d]\n",
                transport->is_connected() ? "connected" : "not connected",
                sciop_endpoint->host (), sciop_endpoint->port (),
                svc_handler->peer ().get_handle ()));

  // Add the handler to Cache
  int retval =
    this->orb_core ()->lane_resources ().transport_cache ().cache_transport (&desc,
                                                                             transport);

  // Failure in adding to cache.
  if (retval != 0)
    {
      // Close the handler.
      svc_handler->close ();

      if (TAO_debug_level > 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "TAO (%P|%t) - SCIOP_Connector::make_connection_i, "
                      "could not add the new connection to cache\n"));
        }

      return 0;
    }

  if (transport->is_connected () &&
      transport->wait_strategy ()->register_handler () != 0)
    {
      // Registration failures.

      // Purge from the connection cache, if we are not in the cache, this
      // just does nothing.
      (void) transport->purge_entry ();

      // Close the handler.
      (void) transport->close_connection ();

      if (TAO_debug_level > 0)
        ACE_ERROR ((LM_ERROR,
                    "TAO (%P|%t) - SCIOP_Connector [%d]::make_connection_i, "
                    "could not register the transport "
                    "in the reactor.\n",
                    transport->id ()));

      return 0;
    }

  return transport;
}

TAO_Profile *
TAO_SCIOP_Connector::create_profile (TAO_InputCDR& cdr)
{
  TAO_Profile *pfile;
  ACE_NEW_RETURN (pfile,
                  TAO_SCIOP_Profile (this->orb_core ()),
                  0);

  int r = pfile->decode (cdr);
  if (r == -1)
    {
      pfile->_decr_refcnt ();
      pfile = 0;
    }

  return pfile;
}

TAO_Profile *
TAO_SCIOP_Connector::make_profile (ACE_ENV_SINGLE_ARG_DECL)
{
  // The endpoint should be of the form:
  //    N.n@host:port/object_key
  // or:
  //    host:port/object_key

  TAO_Profile *profile = 0;
  ACE_NEW_THROW_EX (profile,
                    TAO_SCIOP_Profile (this->orb_core ()),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO::VMCID,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (0);

  return profile;
}

int
TAO_SCIOP_Connector::check_prefix (const char *endpoint)
{
  // Check for a valid string
  if (!endpoint || !*endpoint)
    return -1;  // Failure

  const char *protocol[] = { "sciop", "scioploc" };

  size_t slot = ACE_OS::strchr (endpoint, ':') - endpoint;

  size_t len0 = ACE_OS::strlen (protocol[0]);
  size_t len1 = ACE_OS::strlen (protocol[1]);

  // Check for the proper prefix in the IOR.  If the proper prefix
  // isn't in the IOR then it is not an IOR we can use.
  if (slot == len0
      && ACE_OS::strncasecmp (endpoint, protocol[0], len0) == 0)
    return 0;
  else if (slot == len1
           && ACE_OS::strncasecmp (endpoint, protocol[1], len1) == 0)
    return 0;

  return -1;
  // Failure: not an SCIOP IOR
  // DO NOT throw an exception here.
}

char
TAO_SCIOP_Connector::object_key_delimiter (void) const
{
  return TAO_SCIOP_Profile::object_key_delimiter_;
}

TAO_SCIOP_Endpoint *
TAO_SCIOP_Connector::remote_endpoint (TAO_Endpoint *endpoint)
{
  if (endpoint->tag () != TAO_TAG_SCIOP_PROFILE)
    return 0;

  TAO_SCIOP_Endpoint *sciop_endpoint =
    dynamic_cast<TAO_SCIOP_Endpoint *> (endpoint );
  if (sciop_endpoint == 0)
    return 0;

  return sciop_endpoint;
}

int
TAO_SCIOP_Connector::cancel_svc_handler (
  TAO_Connection_Handler * svc_handler)
{
  TAO_SCIOP_Connection_Handler* handler=
    dynamic_cast<TAO_SCIOP_Connection_Handler*>(svc_handler);

  if (handler)
    // Cancel from the connector
    return this->base_connector_.cancel (handler);

  return -1;
}


#endif /* TAO_HAS_SCIOP == 1 */
