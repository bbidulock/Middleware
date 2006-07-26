// -*- C++ -*-

//=============================================================================
/**
 *  @file   Connection_Handler.h
 *
 *  $Id$
 *
 *  @author Balachandran Natarajan  <bala@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_CONNECTION_HANDLER_H
#define TAO_CONNECTION_HANDLER_H

#include /**/ "ace/pre.h"

#include "tao/LF_CH_Event.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Basic_Types.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_SOCK;
class ACE_Lock;
class ACE_Event_Handler;
ACE_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_ORB_Core;
class TAO_Transport;

/*
 * Hook to specialize the connection handler with the
 * concrete connection handler implementation.
 */
//@@ CONNECTION_HANDLER_SPL_INCLUDE_FORWARD_DECL_ADD_HOOK

/**
 * @class TAO_Connection_Handler
 *
 * @brief TAO_Connection_Handler
 *
 * This class is an abstraction for the connection handlers. The
 * connections handler in every protocol can derive from this
 * class as well as the ACE_Svc_Handler specialised for the
 * right protocol. This way, most of the common code for the
 * different protocols would be in this implementation.
 */
class TAO_Export TAO_Connection_Handler : public TAO_LF_CH_Event
{
public:

  /// Constructor
  TAO_Connection_Handler (void);

  /// Constructor
  TAO_Connection_Handler (TAO_ORB_Core *orb_core);

  /// Destructor
  virtual ~TAO_Connection_Handler (void);

  /// Return the underlying transport object
  TAO_Transport *transport (void);

  /// Set the underlying transport object
  void transport (TAO_Transport* transport);

  /// Is the handler closed?
  bool is_closed (void) const;

  /// Is the handler open?
  bool is_open (void) const;

  /// Is the handler in the process of being connected?
  bool is_connecting (void) const;

  /// Close the underlying connection.
  /**
   * Used by the ORB to actively close connections that are idle,
   * stale or somehow are determined to be broken before the Reactor
   * does.
   *
   * @return Return 0 if the connection was already closed, non-zero
   * otherwise.
   */
  virtual int close_connection (void) = 0;

  /// The event handler calls, here so that other objects who hold a
  /// reference to this object can call the event handler methods.
  virtual int handle_input (ACE_HANDLE fd) = 0;

  /// This method is invoked from the svc () method of the Svc_Handler
  /// Object.
  int svc_i (void);

  /// A open () hook
  /**
   * See Thread_Per_Connection_Handler for a use case
   */
  virtual int open_handler (void *) = 0;

  /// A close() hook, called by the Transport Connector when they want to close
  /// this handler
  virtual int close_handler (void);

  /// Set the Diff-Serv codepoint on outgoing packets.  Only has
  /// effect for remote protocols (e.g., IIOP); no effect for local
  /// protocols (UIOP).  Default implementation is for local
  /// protocols.  Remote protocols must overwrite implementation.
  virtual int set_dscp_codepoint (CORBA::Boolean set_network_priority);

  /// Release the OS resources related to this handler.
  virtual int release_os_resources (void);

  /*
   * Hook to add public methods from concrete connection handler
   * implementation onto the base connection handler.
   */

   //@@ CONNECTION_HANDLER_SPL_PUBLIC_METHODS_ADD_HOOK

protected:

  /// Return our TAO_ORB_Core pointer
  TAO_ORB_Core *orb_core (void);

  /// Set options on the socket
  int set_socket_option (ACE_SOCK &sock,
                         int snd_size,
                         int rcv_size);

  //@{
  /**
   * @name Helper methods for Event_Handler-based derived classes.
   *
   * Many (actually all so far) implementations of
   * TAO_Connection_Handler are a mixin of TAO_Connection_Handler and
   * some form of ACE_Event_Handler.  The following methods simplify
   * such implementations by capturing the common code in a single
   * place.
   */

  /// Implement the handle_output() callback
  int handle_output_eh (ACE_HANDLE h, ACE_Event_Handler * eh);

  /// Implement the handle_input() callback
  // We're actually going to pull the code from the protocol-specific
  // handlers back into this class, because they ALL look exactly the same.
  // If some other protocol comes along and needs to do something different,
  // it is always free to override handle_input() as it sees fit.
  int handle_input_eh (ACE_HANDLE h, ACE_Event_Handler * eh);
  int handle_input_internal (ACE_HANDLE h, ACE_Event_Handler *eh);

  /// Implement close_connection() for Connection_Handlers that are
  /// also Event_Handlers.
  int close_connection_eh (ACE_Event_Handler * eh);

  /// Pre-invocation hook for I/O operations (handle_input() &
  /// handle_output())
  /**
   * See the SSLIOP protocol for an interesting use-case
   */
  virtual void pre_io_hook (int & return_value);

  /// Post-invocation hook for I/O operations (handle_input() &
  /// handle_output())
  /**
   * See the SSLIOP protocol for an interesting use-case
   */
  virtual void pos_io_hook (int & return_value);
  //@}


private:
  /// Pointer to the TAO_ORB_Core
  TAO_ORB_Core * const orb_core_;

  /// Transport object reference
  TAO_Transport* transport_;

  /// Internal state lock, needs to be separate from the reference
  /// count / pending upcalls lock because they interleave.
  ACE_Lock * lock_;

  /*
   * Hook to add instance members from derived class
   * onto base Connection_Handler class. Any further
   * additions to this class should go before this
   * hook.
   */
  //@@ CONNECTION_HANDLER_SPL_PRIVATE_DATA_ADD_HOOK
};

//@@ CONNECTION_HANDLER_SPL_EXTERN_ADD_HOOK

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "tao/Connection_Handler.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /*TAO_CONNECTION_HANDLER_H*/
