// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO_SSLIOP
//
// = FILENAME
//   SSLIOP_Connect.h
//
// = AUTHOR
//    Carlos O'Ryan <coryan@ece.uci.edu>
//    Ossama Othman <ossama@ece.uci.edu>
//
// ============================================================================

#ifndef TAO_SSLIOP_CONNECT_H
#define TAO_SSLIOP_CONNECT_H

#include "ace/pre.h"

#include "ace/config-all.h"

#if defined (ACE_HAS_SSL) && ACE_HAS_SSL == 1

#include "ace/Reactor.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SSL/SSL_SOCK_Stream.h"
#include "ace/Synch.h"
#include "ace/Svc_Handler.h"

#include "tao/corbafwd.h"
#include "tao/Wait_Strategy.h"
#include "tao/GIOP_Message_Acceptors.h"
#include "tao/IIOP_Connect.h"

#include "SSLIOP_Transport.h"

// Forward Decls
class TAO_ORB_Core;
class TAO_ORB_Core_TSS_Resources;

typedef ACE_Svc_Handler<ACE_SSL_SOCK_STREAM, ACE_NULL_SYNCH>
        TAO_SSL_SVC_HANDLER;

// ****************************************************************

class TAO_SSLIOP_Handler_Base : public TAO_SSL_SVC_HANDLER
{
public:
  TAO_SSLIOP_Handler_Base (ACE_Thread_Manager *t);
  TAO_SSLIOP_Handler_Base (TAO_ORB_Core *orb_core);

};

class TAO_SSLIOP_Export TAO_SSLIOP_Client_Connection_Handler : public TAO_SSLIOP_Handler_Base
{
  // = TITLE
  //      <Svc_Handler> used on the client side and returned by the
  //      <TAO_CONNECTOR>.
public:
  // = Initialization methods.

  TAO_SSLIOP_Client_Connection_Handler (ACE_Thread_Manager* t = 0);
  // This constructor should *never* get called, it is just here to
  // make the compiler happy: the default implementation of the
  // Creation_Strategy requires a constructor with that signature, we
  // don't use that implementation, but some (most?) compilers
  // instantiate it anyway.

  TAO_SSLIOP_Client_Connection_Handler (ACE_Thread_Manager *t,
                                        TAO_ORB_Core* orb_core,
                                        CORBA::Boolean flag,
                                        void *arg);
  // Constructor. <arg> parameter is used by the Connector to pass the
  // protocol configuration properties for this connection.

  virtual ~TAO_SSLIOP_Client_Connection_Handler (void);

  // = <Connector> hook.
  virtual int open (void *);
  // Activation template method.

  // = Event Handler overloads

  virtual int handle_input (ACE_HANDLE = ACE_INVALID_HANDLE);
  // Called when a response from a twoway invocation is available.

  virtual int handle_timeout (const ACE_Time_Value &tv,
                              const void *arg = 0);
  // Called when buffering timer expires.

  virtual int handle_close (ACE_HANDLE = ACE_INVALID_HANDLE,
                            ACE_Reactor_Mask = ACE_Event_Handler::NULL_MASK);
  // Perform appropriate closing.

  virtual int handle_close_i (ACE_HANDLE = ACE_INVALID_HANDLE,
                              ACE_Reactor_Mask = ACE_Event_Handler::NULL_MASK);
  // Perform appropriate closing but without grabbing any locks.

  virtual int close (u_long flags = 0);
  // Object termination hook.

  virtual TAO_Transport *transport (void);
  // Return the transport objects

protected:
  int handle_cleanup (void);
  // This method deregisters the handler from the reactor and closes it.

  TAO_SSLIOP_Client_Transport transport_;
  // Reference to the transport object, it is owned by this class.

  TAO_ORB_Core *orb_core_;
  // Cached ORB Core.

  TAO_IIOP_Handler_Base::TCP_Properties *tcp_properties_;
  // TCP configuration for this connection.
};

// ****************************************************************

class TAO_SSLIOP_Export TAO_SSLIOP_Server_Connection_Handler : public TAO_SSLIOP_Handler_Base
{
  // = TITLE
  //   Handles requests on a single connection in a server.

public:
  TAO_SSLIOP_Server_Connection_Handler (ACE_Thread_Manager* t = 0);
  TAO_SSLIOP_Server_Connection_Handler (TAO_ORB_Core *orb_core,
                                        CORBA::Boolean flag,
                                        void *arg);
  // Constructor.
  // <flag> parameter is normally used to enable the GIOPlite
  // messaging protocol.  However, it is disabled in SSLIOP since it
  // introduces security holes.
  // <arg> parameter is used by the Acceptor to pass the protocol
  // configuration properties for this connection.

  ~TAO_SSLIOP_Server_Connection_Handler (void);
  // Destructor.

  virtual int open (void *);
  // Called by the <Strategy_Acceptor> when the handler is completely
  // connected.  Argument is unused.

  // = Active object activation method.
  virtual int activate (long flags = THR_NEW_LWP,
                        int n_threads = 1,
                        int force_active = 0,
                        long priority = ACE_DEFAULT_THREAD_PRIORITY,
                        int grp_id = -1,
                        ACE_Task_Base *task = 0,
                        ACE_hthread_t thread_handles[] = 0,
                        void *stack[] = 0,
                        size_t stack_size[] = 0,
                        ACE_thread_t  thread_names[] = 0);

  virtual int svc (void);
  // Only used when the handler is turned into an active object by
  // calling <activate>.  This serves as the event loop in such cases.

  // = Template Methods Called by <handle_input>

  TAO_Transport *transport (void);

protected:

  // = Event Handler overloads

  virtual int handle_input (ACE_HANDLE = ACE_INVALID_HANDLE);
  virtual int handle_input_i (ACE_HANDLE = ACE_INVALID_HANDLE,
                              ACE_Time_Value *max_wait_time = 0);
  // Reads a message from the <peer()>, dispatching and servicing it
  // appropriately.
  // handle_input() just delegates on handle_input_i() which timeouts
  // after <max_wait_time>, this is used in thread-per-connection to
  // ensure that server threads eventually exit.

  virtual int handle_close (ACE_HANDLE = ACE_INVALID_HANDLE,
                            ACE_Reactor_Mask = ACE_Event_Handler::NULL_MASK);
  // Perform appropriate closing.

protected:
  TAO_SSLIOP_Server_Transport transport_;
  // @@ New transport object reference.

  TAO_GIOP_Message_Acceptors acceptor_factory_;
  // Messaging acceptor factory

  TAO_ORB_Core *orb_core_;
  // Cached ORB Core.

  TAO_ORB_Core_TSS_Resources *tss_resources_;
  // Cached tss resources of the ORB that activated this object.

  u_long refcount_;
  // Reference count, to avoid early deletes...

  TAO_IIOP_Handler_Base::TCP_Properties *tcp_properties_;
  // TCP configuration for this connection.
};

#if defined (__ACE_INLINE__)
#include "SSLIOP_Connect.i"
#endif /* __ACE_INLINE__ */

#endif  /* ACE_HAS_SSL */

#include "ace/post.h"

#endif /* TAO_SSLIOP_CONNECT_H */
