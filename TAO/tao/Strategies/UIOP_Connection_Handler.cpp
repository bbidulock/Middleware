// $Id$

#include "UIOP_Connection_Handler.h"

#if TAO_HAS_UIOP == 1

#include "UIOP_Transport.h"
#include "UIOP_Endpoint.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/ORB.h"
#include "tao/CDR.h"
#include "tao/Timeprobe.h"
#include "tao/Server_Strategy_Factory.h"
#include "tao/Base_Transport_Property.h"
#include "tao/GIOP_Message_Lite.h"
#include "tao/Transport_Cache_Manager.h"
#include "tao/Resume_Handle.h"
#include "tao/Thread_Lane_Resources.h"

#if !defined (__ACE_INLINE__)
# include "UIOP_Connection_Handler.inl"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(Strategies, UIOP_Connection_Handler, "$Id$")

TAO_UIOP_Connection_Handler::TAO_UIOP_Connection_Handler (ACE_Thread_Manager *t)
  : TAO_UIOP_SVC_HANDLER (t, 0 , 0),
    TAO_Connection_Handler (0),
    uiop_properties_ (0)
{
  // This constructor should *never* get called, it is just here to
  // make the compiler happy: the default implementation of the
  // Creation_Strategy requires a constructor with that signature, we
  // don't use that implementation, but some (most?) compilers
  // instantiate it anyway.
  ACE_ASSERT (this->orb_core () != 0);
}


TAO_UIOP_Connection_Handler::TAO_UIOP_Connection_Handler (TAO_ORB_Core *orb_core,
                                                          CORBA::Boolean flag,
                                                          void *arg)
  : TAO_UIOP_SVC_HANDLER (orb_core->thr_mgr (), 0, 0),
    TAO_Connection_Handler (orb_core),
    uiop_properties_ (ACE_static_cast
                     (TAO_UIOP_Properties *, arg))
{
  TAO_UIOP_Transport* specific_transport = 0;
  ACE_NEW(specific_transport,
          TAO_UIOP_Transport(this, orb_core, flag));

  // store this pointer (indirectly increment ref count)
  this->transport(specific_transport);
  TAO_Transport::release (specific_transport);
}


TAO_UIOP_Connection_Handler::~TAO_UIOP_Connection_Handler (void)
{
}

int
TAO_UIOP_Connection_Handler::open (void*)
{
  if (this->set_socket_option (this->peer (),
                               this->uiop_properties_->send_buffer_size,
                               this->uiop_properties_->recv_buffer_size) == -1)
    return -1;

  if (this->transport ()->wait_strategy ()->non_blocking ())
    {
      if (this->peer ().enable (ACE_NONBLOCK) == -1)
        return -1;
    }

  // Called by the <Strategy_Acceptor> when the handler is completely
  // connected.
  ACE_UNIX_Addr addr;

  if (this->peer ().get_remote_addr (addr) == -1)
    return -1;

  if (TAO_debug_level > 0)
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("TAO (%P|%t) UIOP connection to server ")
                ACE_TEXT ("<%s> on %d\n"),
                addr.get_path_name (), this->peer ().get_handle ()));

  // Set the id in the transport now that we're active.
  this->transport ()->id ((size_t) this->get_handle ());

  this->state_changed (TAO_LF_Event::LFS_SUCCESS);

  return 0;
}

int
TAO_UIOP_Connection_Handler::activate (long flags,
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
  if (TAO_debug_level)
    ACE_DEBUG  ((LM_DEBUG,
                 ACE_TEXT ("TAO (%P|%t) UIOP_Connection_Handler::activate %d ")
                 ACE_TEXT ("threads, flags = %d\n"),
                 n_threads,
                 flags,
                 THR_BOUND));

  // Set the id in the transport now that we're active.
  this->transport ()->id ((size_t) this->get_handle ());

  return TAO_UIOP_SVC_HANDLER::activate (flags,
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
TAO_UIOP_Connection_Handler::svc (void)
{
  // This method is called when an instance is "activated", i.e.,
  // turned into an active object.  Presumably, activation spawns a
  // thread with this method as the "worker function".

  // Clear the non-blocking mode here
  ACE_Flag_Manip::clr_flags (this->get_handle (),
                             ACE_NONBLOCK);

  // Call the implementation here
  return this->svc_i ();
}

int
TAO_UIOP_Connection_Handler::resume_handler (void)
{
  return ACE_Event_Handler::ACE_APPLICATION_RESUMES_HANDLER;
}

int
TAO_UIOP_Connection_Handler::close_connection (void)
{
  return this->close_connection_eh (this);
}

int
TAO_UIOP_Connection_Handler::handle_input (ACE_HANDLE h)
{
  return this->handle_input_eh (h, this);
}

int
TAO_UIOP_Connection_Handler::handle_output (ACE_HANDLE handle)
{
  return this->handle_output_eh (handle, this);
}

int
TAO_UIOP_Connection_Handler::handle_close (ACE_HANDLE handle,
                                           ACE_Reactor_Mask rm)
{
  return this->handle_close_eh (handle, rm, this);
}

int
TAO_UIOP_Connection_Handler::release_os_resources (void)
{
  return this->peer().close ();
}

int
TAO_UIOP_Connection_Handler::add_transport_to_cache (void)
{
  ACE_UNIX_Addr addr;

  // Get the peername.
  if (this->peer ().get_remote_addr (addr) == -1)
    return -1;

  // Construct an  UIOP_Endpoint object
  TAO_UIOP_Endpoint endpoint (addr);

  // Construct a property object
  TAO_Base_Transport_Property prop (&endpoint);

  TAO_Transport_Cache_Manager &cache =
    this->orb_core ()->lane_resources ().transport_cache ();

  // Add the handler to Cache
  return cache.cache_idle_transport (&prop,
                                     this->transport ());
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class ACE_Svc_Handler<ACE_LSOCK_STREAM, ACE_NULL_SYNCH>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate ACE_Svc_Handler<ACE_LSOCK_STREAM, ACE_NULL_SYNCH>

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

#endif /*TAO_HAS_UIOP == 1*/
