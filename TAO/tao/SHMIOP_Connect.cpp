// $Id$

#include "tao/SHMIOP_Connect.h"

#if defined (TAO_HAS_SHMIOP) && (TAO_HAS_SHMIOP != 0)

#include "tao/Timeprobe.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/ORB.h"
#include "tao/CDR.h"
#include "tao/GIOP_Message_Connectors.h"
#include "tao/GIOP_Message_Acceptors.h"
#include "tao/GIOP_Message_Lite.h"

#if !defined (__ACE_INLINE__)
# include "tao/SHMIOP_Connect.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(tao, SHMIOP_Connect, "$Id$")

#if defined (ACE_ENABLE_TIMEPROBES)

static const char *TAO_SHMIOP_Connect_Timeprobe_Description[] =
{
  "SHMIOP_Server_Connection_Handler::handle_input - start",
  "SHMIOP_Server_Connection_Handler::handle_input - end",

  "SHMIOP_Server_Connection_Handler::handle_locate - start",
  "SHMIOP_Server_Connection_Handler::handle_locate - end",

  "SHMIOP_Server_Connection_Handler::receive_request - end",

  "SHMIOP_Client_Connection_Handler::send_request - start",
  "SHMIOP_Client_Connection_Handler::send_request - end"};

enum
{
  // Timeprobe description table start key
  TAO_SHMIOP_SERVER_CONNECTION_HANDLER_HANDLE_INPUT_START = 300,
  TAO_SHMIOP_SERVER_CONNECTION_HANDLER_HANDLE_INPUT_END,

  TAO_SHMIOP_SERVER_CONNECTION_HANDLER_HANDLE_LOCATE_START,
  TAO_SHMIOP_SERVER_CONNECTION_HANDLER_HANDLE_LOCATE_END,

  TAO_SHMIOP_SERVER_CONNECTION_HANDLER_RECEIVE_REQUEST_END,

  TAO_SHMIOP_CLIENT_CONNECTION_HANDLER_SEND_REQUEST_START,
  TAO_SHMIOP_CLIENT_CONNECTION_HANDLER_SEND_REQUEST_END
};

// Setup Timeprobes
ACE_TIMEPROBE_EVENT_DESCRIPTIONS (TAO_SHMIOP_Connect_Timeprobe_Description,
                                  TAO_SHMIOP_SERVER_CONNECTION_HANDLER_HANDLE_INPUT_START);

#endif /* ACE_ENABLE_TIMEPROBES */

TAO_SHMIOP_Handler_Base::TAO_SHMIOP_Handler_Base (TAO_ORB_Core *orb_core)
  : TAO_SHMIOP_SVC_HANDLER (orb_core->thr_mgr (), 0, 0)
{
}

TAO_SHMIOP_Handler_Base::TAO_SHMIOP_Handler_Base (ACE_Thread_Manager *t)
  : TAO_SHMIOP_SVC_HANDLER (t, 0, 0)
{
}

// ****************************************************************

TAO_SHMIOP_Server_Connection_Handler::TAO_SHMIOP_Server_Connection_Handler (ACE_Thread_Manager *t)
  : TAO_SHMIOP_Handler_Base (t),
    transport_ (this, 0),
    acceptor_factory_ (0),
    orb_core_ (0),
    tss_resources_ (0),
    refcount_ (1)

{
  // This constructor should *never* get called, it is just here to
  // make the compiler happy: the default implementation of the
  // Creation_Strategy requires a constructor with that signature, we
  // don't use that implementation, but some (most?) compilers
  // instantiate it anyway.
  ACE_ASSERT (this->orb_core_ != 0);
}

TAO_SHMIOP_Server_Connection_Handler::TAO_SHMIOP_Server_Connection_Handler (TAO_ORB_Core *orb_core,
                                                                            CORBA::Boolean flag)
  : TAO_SHMIOP_Handler_Base (orb_core),
    transport_ (this, orb_core),
    acceptor_factory_ (0),
    orb_core_ (orb_core),
    tss_resources_ (orb_core->get_tss_resources ()),
    refcount_ (1),
    lite_flag_ (flag)
{
    if (lite_flag_)
    {
      ACE_NEW (this->acceptor_factory_,
               TAO_GIOP_Message_Lite);
    }
  else
    {
      ACE_NEW (this->acceptor_factory_,
               TAO_GIOP_Message_Acceptors);
    }
    
    // OK, Here is a small twist. By now the all the objecs cached in
  // this class would have been constructed. But we would like to make
  // the one of the objects, precisely the transport object a pointer
  // to the Messaging object. So, we set this up properly by calling
  // the messaging_init method on the transport. 
  this->transport_.messaging_init (this->acceptor_factory_);
}

TAO_SHMIOP_Server_Connection_Handler::~TAO_SHMIOP_Server_Connection_Handler (void)
{
}

int
TAO_SHMIOP_Server_Connection_Handler::open (void*)
{
#if !defined (ACE_LACKS_SOCKET_BUFSIZ)
  int sndbufsize =
    this->orb_core_->orb_params ()->sock_sndbuf_size ();
  int rcvbufsize =
    this->orb_core_->orb_params ()->sock_rcvbuf_size ();

  if (this->peer ().set_option (SOL_SOCKET,
                                SO_SNDBUF,
                                (void *) &sndbufsize,
                                sizeof (sndbufsize)) == -1
      && errno != ENOTSUP)
    return -1;
  else if (this->peer ().set_option (SOL_SOCKET,
                                     SO_RCVBUF,
                                     (void *) &rcvbufsize,
                                     sizeof (rcvbufsize)) == -1
           && errno != ENOTSUP)
    return -1;
#endif /* !ACE_LACKS_SOCKET_BUFSIZ */

#if defined (TCP_NODELAY)
  int nodelay =
    this->orb_core_->orb_params ()->nodelay ();

  if (this->peer ().set_option (ACE_IPPROTO_TCP,
                                TCP_NODELAY,
                                (void *) &nodelay,
                                sizeof (nodelay)) == -1)
    return -1;
#endif /* TCP_NODELAY */

  (void) this->peer ().enable (ACE_CLOEXEC);
  // Set the close-on-exec flag for that file descriptor. If the
  // operation fails we are out of luck (some platforms do not support
  // it and return -1).

  // Called by the <Strategy_Acceptor> when the handler is completely
  // connected.
  ACE_INET_Addr addr;

  if (this->peer ().get_remote_addr (addr) == -1)
    return -1;

  char client[MAXHOSTNAMELEN + 16];
  (void) addr.addr_to_string (client, sizeof (client));

  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("TAO (%P|%t) SHMIOP connection from client <%s> on %d\n"),
                client, this->peer ().get_handle ()));

  return 0;
}

int
TAO_SHMIOP_Server_Connection_Handler::activate (long flags,
                                                int n_threads,
                                                int force_active,
                                                long priority,
                                                int grp_id,
                                                ACE_Task_Base *task,
                                                ACE_hthread_t thread_handles[],
                                                void *stack[],
                                                size_t stack_size[],
                                                ACE_thread_t  thread_names[])
{
  if (TAO_orbdebug)
    ACE_DEBUG  ((LM_DEBUG,
                 ASYS_TEXT ("TAO (%P|%t) SHMIOP_Server_Connection_Handler::activate %d ")
                 ASYS_TEXT ("threads, flags = %d\n"),
                 n_threads,
                 flags,
                 THR_BOUND));

  return TAO_SHMIOP_SVC_HANDLER::activate (flags,
                                    n_threads,
                                    force_active,
                                    priority,
                                    grp_id,
                                    task,
                                    thread_handles,
                                    stack,
                                    stack_size,
                                    thread_names);
}

int
TAO_SHMIOP_Server_Connection_Handler::handle_close (ACE_HANDLE handle,
                                                    ACE_Reactor_Mask rm)
{
  if (TAO_orbdebug)
    ACE_DEBUG  ((LM_DEBUG,
                 ASYS_TEXT ("TAO (%P|%t) SHMIOP_Server_Connection_Handler::handle_close ")
                 ASYS_TEXT ("(%d, %d)\n"),
                 handle,
                 rm));

  --this->refcount_;
  if (this->refcount_ == 0)
    {
      this->peer().remove ();
      return TAO_SHMIOP_SVC_HANDLER::handle_close (handle, rm);
    }

  return 0;
}

int
TAO_SHMIOP_Server_Connection_Handler::svc (void)
{
  // This method is called when an instance is "activated", i.e.,
  // turned into an active object.  Presumably, activation spawns a
  // thread with this method as the "worker function".
  int result = 0;

  // Inheriting the ORB_Core tss stuff from the parent thread.
  this->orb_core_->inherit_from_parent_thread (this->tss_resources_);

  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("TAO (%P|%t) SHMIOP_Server_Connection_Handler::svc begin\n")));

  // Here we simply synthesize the "typical" event loop one might find
  // in a reactive handler, except that this can simply block waiting
  // for input.

  ACE_Time_Value *max_wait_time = 0;
  ACE_Time_Value timeout;
  ACE_Time_Value current_timeout;
  if (this->orb_core_->thread_per_connection_timeout (timeout))
    {
      current_timeout = timeout;
      max_wait_time = &current_timeout;
    }

  while (!this->orb_core_->has_shutdown ()
         && result >= 0)
    {
      result = handle_input_i (ACE_INVALID_HANDLE, max_wait_time);
      if (result == -1 && errno == ETIME)
        {
          // Ignore timeouts, they are only used to wake up and
          // shutdown.
          result = 0;
        }
      current_timeout = timeout;
      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG,
                    ASYS_TEXT ("TAO (%P|%t) SHMIOP_Server_Connection_Handler::svc - ")
                    ASYS_TEXT ("loop <%d>\n"), current_timeout.msec ()));
    }

  if (TAO_debug_level > 0)
    ACE_DEBUG  ((LM_DEBUG,
                 ASYS_TEXT ("TAO (%P|%t) SHMIOP_Server_Connection_Handler::svc end\n")));

  return result;
}

int
TAO_SHMIOP_Server_Connection_Handler::handle_input (ACE_HANDLE h)
{
  return this->handle_input_i (h);
}

int
TAO_SHMIOP_Server_Connection_Handler::handle_input_i (ACE_HANDLE,
                                                      ACE_Time_Value *max_wait_time)
{
  this->refcount_++;

  int result = this->acceptor_factory_->handle_input (this->transport (),
                                                      this->orb_core_,
                                                      this->transport_.message_state_,
                                                      max_wait_time);

  if (result == -1 && TAO_debug_level > 0)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ASYS_TEXT ("TAO (%P|%t) - %p\n"),
                  ASYS_TEXT ("SHMIOP_Server_Connection_Handler::handle_input, ")
                  ASYS_TEXT ("handle_input")));
    }

  if (result == 0 || result == -1)
    {
      --this->refcount_;
      if (this->refcount_ == 0)
        this->TAO_SHMIOP_SVC_HANDLER::handle_close ();
      return result;
    }

  //
  // Take out all the information from the <message_state> and reset
  // it so that nested upcall on the same transport can be handled.
  //

  // Notice that the message_state is only modified in one thread at a
  // time because the reactor does not call handle_input() for the
  // same Event_Handler in two threads at the same time.

  // Copy message type.
  TAO_GIOP_Message_State &ms = this->transport_.message_state_;
  CORBA::Octet message_type = ms.message_type;

  // Copy version.
  TAO_GIOP_Version giop_version = ms.giop_version;

  // Steal the input CDR from the message state.
  TAO_InputCDR input_cdr (ACE_InputCDR::Transfer_Contents (ms.cdr),
                          this->orb_core_);

  // Reset the message state.
  this->transport_.message_state_.reset (0);

  result = 
    this->acceptor_factory_->process_connector_messages (this->transport (),
                                                         this->orb_core_,
                                                         input_cdr,
                                                         message_type);
  if (result != -1)
    result = 0;

  --this->refcount_;
  if (this->refcount_ == 0)
    this->TAO_SHMIOP_SVC_HANDLER::handle_close ();

  return result;
}

// ****************************************************************

//    transport obj.
TAO_SHMIOP_Client_Connection_Handler::
TAO_SHMIOP_Client_Connection_Handler (ACE_Thread_Manager *t,
                                      TAO_ORB_Core* orb_core)
  : TAO_SHMIOP_Handler_Base (t),
    transport_ (this, orb_core),
    orb_core_ (orb_core)
{
}

TAO_SHMIOP_Client_Connection_Handler::~TAO_SHMIOP_Client_Connection_Handler (void)
{
}

int
TAO_SHMIOP_Client_Connection_Handler::open (void *)
{
  // @@ TODO: This flags should be set using the RT CORBA policies...

  // Here is where we could enable all sorts of things such as
  // nonblock I/O, sock buf sizes, TCP no-delay, etc.

#if !defined (ACE_LACKS_SOCKET_BUFSIZ)
  int sndbufsize =
    this->orb_core_->orb_params ()->sock_sndbuf_size ();
  int rcvbufsize =
    this->orb_core_->orb_params ()->sock_rcvbuf_size ();

  if (this->peer ().set_option (SOL_SOCKET,
                                SO_SNDBUF,
                                ACE_reinterpret_cast (void *, &sndbufsize),
                                sizeof (sndbufsize)) == -1
      && errno != ENOTSUP)
    return -1;
  else if (this->peer ().set_option (SOL_SOCKET,
                                     SO_RCVBUF,
                                     ACE_reinterpret_cast (void *, &rcvbufsize),
                                     sizeof (rcvbufsize)) == -1
           && errno != ENOTSUP)
    return -1;
#endif /* ACE_LACKS_SOCKET_BUFSIZ */

#if defined (TCP_NODELAY)
  int nodelay =
    this->orb_core_->orb_params ()->nodelay ();
  if (this->peer ().set_option (ACE_IPPROTO_TCP,
                                TCP_NODELAY,
                                (void *) &nodelay,
                                sizeof (nodelay)) == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ASYS_TEXT ("NODELAY failed\n")),
                      -1);
#endif /* TCP_NODELAY */

  (void) this->peer ().enable (ACE_CLOEXEC);
  // Set the close-on-exec flag for that file descriptor. If the
  // operation fails we are out of luck (some platforms do not support
  // it and return -1).

  // Called by the <Strategy_Acceptor> when the handler is completely
  // connected.
  ACE_INET_Addr addr;

  if (this->peer ().get_remote_addr (addr) == -1)
    return -1;

  char server[MAXHOSTNAMELEN + 16];

  (void) addr.addr_to_string (server, sizeof (server));

  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG,
                ASYS_TEXT ("TAO (%P|%t) SHMIOP connection to server <%s> on %d\n"),
                server, this->peer ().get_handle ()));

  // Register the handler with the Reactor if necessary.
  return this->transport ()->wait_strategy ()->register_handler ();
}

int
TAO_SHMIOP_Client_Connection_Handler::close (u_long)
{
  this->destroy ();

  return 0;
}

int
TAO_SHMIOP_Client_Connection_Handler::handle_input (ACE_HANDLE)
{
  // Call the waiter to handle the input.
  return this->transport ()->wait_strategy ()->handle_input ();
}

int
TAO_SHMIOP_Client_Connection_Handler::handle_timeout (const ACE_Time_Value &,
                                                    const void *)
{
  //
  // This method is called when buffering timer expires.
  //

  // Cannot deal with errors, and therefore they are ignored.
  this->transport ()->send_buffered_messages ();

  return 0;
}

int
TAO_SHMIOP_Client_Connection_Handler::handle_close (ACE_HANDLE handle,
                                                    ACE_Reactor_Mask rm)
{
  // @@ Alex: we need to figure out if the transport decides to close
  //    us or something else.  If it is something else (for example
  //    the cached connector trying to make room for other
  //    connections) then we should let the transport know, so it can
  //    in turn take appropiate action (such as sending exceptions to
  //    all waiting reply handlers).

  if (TAO_debug_level > 0)
    ACE_DEBUG  ((LM_DEBUG,
                 ASYS_TEXT ("TAO (%P|%t) SHMIOP_Client_Connection_Handler::")
                 ASYS_TEXT ("handle_close (%d, %d)\n"), handle, rm));

  if (this->recycler ())
    this->recycler ()->mark_as_closed (this->recycling_act ());

  // Deregister this handler with the ACE_Reactor.
  return this->handle_cleanup ();
}

int
TAO_SHMIOP_Client_Connection_Handler::handle_close_i (ACE_HANDLE handle,
                                                      ACE_Reactor_Mask rm)
{
  // @@ Alex: we need to figure out if the transport decides to close
  //    us or something else.  If it is something else (for example
  //    the cached connector trying to make room for other
  //    connections) then we should let the transport know, so it can
  //    in turn take appropiate action (such as sending exceptions to
  //    all waiting reply handlers).

  if (TAO_debug_level > 0)
    ACE_DEBUG  ((LM_DEBUG,
                 ASYS_TEXT ("TAO (%P|%t) SHMIOP_Client_Connection_Handler::")
                 ASYS_TEXT ("handle_close_i (%d, %d)\n"), handle, rm));

  if (this->recycler ())
    this->recycler ()->mark_as_closed_i (this->recycling_act ());

  return this->handle_cleanup ();
}

int
TAO_SHMIOP_Client_Connection_Handler::handle_cleanup (void)
{
  // Deregister this handler with the ACE_Reactor.
  if (this->reactor ())
    {
      ACE_Reactor_Mask mask =
        ACE_Event_Handler::ALL_EVENTS_MASK | ACE_Event_Handler::DONT_CALL;

      // Make sure there are no timers.
      this->reactor ()->cancel_timer (this);

      // Remove self from reactor.
      this->reactor ()->remove_handler (this, mask);
    }

  this->peer ().close ();

  return 0;
}

int
TAO_SHMIOP_Client_Connection_Handler::
  init_mesg_protocol (CORBA::Octet major, 
                      CORBA::Octet minor) 
{
  if (major == TAO_DEF_GIOP_LITE_MAJOR &&
      minor == TAO_DEF_GIOP_LITE_MINOR)
    {
      ACE_NEW_RETURN  (this->mesg_factory_,
                       TAO_GIOP_Message_Lite,
                       -1);
    }
  else if (major == TAO_DEF_GIOP_MAJOR)
    {
      if (minor > TAO_DEF_GIOP_MINOR)
        minor = TAO_DEF_GIOP_MINOR;
      switch (minor)
        {
        case 0:
          ACE_NEW_RETURN  (this->mesg_factory_,
                           TAO_GIOP_Message_Connector_10,
                           0);
          break;
        case 1:
          ACE_NEW_RETURN  (this->mesg_factory_,
                           TAO_GIOP_Message_Connector_11,
                           0);
          break;
        default:
          if (TAO_debug_level > 0)
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 ASYS_TEXT ("(%N|%l|%p|%t) No matching minor version number \n")),
                                0);
            }
        }
    }
  else
    {
      if (TAO_debug_level > 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ASYS_TEXT ("(%N|%l|%p|%t) No matching major version number \n")), 
                            0);
        }
    }

  // Make the transport know 
  this->transport_.messaging_init (this->mesg_factory_);

  return 1;
}

// ****************************************************************

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /* TAO_HAS_SHMIOP && TAO_HAS_SHMIOP != 0 */
