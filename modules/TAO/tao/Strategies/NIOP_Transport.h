// -*- C++ -*-

//=============================================================================
/**
 *  @file   NIOP_Transport.h
 *
 *  $Id: NIOP_Transport.h,v 1.18 2006/07/20 10:24:45 jwillemsen Exp $
 *
 *  @author  Johnny Willemsen <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_NIOP_TRANSPORT_H
#define TAO_NIOP_TRANSPORT_H

#include /**/ "ace/pre.h"

#include "tao/orbconf.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (TAO_HAS_NIOP) && (TAO_HAS_NIOP != 0)

#include "tao/Strategies/strategies_export.h"
#include "tao/Transport.h"
#include "ace/SOCK_Stream.h"
#include "ace/Svc_Handler.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls.
class TAO_NIOP_Connection_Handler;
class TAO_ORB_Core;
class TAO_Operation_Details;
class TAO_Pluggable_Messaging;
class TAO_Acceptor;

// Service Handler for this transport
typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
        TAO_NIOP_SVC_HANDLER;

/**
 * @class TAO_NIOP_Transport
 *
 * @brief Specialization of the base TAO_Transport class to handle the
 *  NIOP protocol.
 */
class TAO_Strategies_Export TAO_NIOP_Transport : public TAO_Transport
{
public:

  /// Constructor.
  TAO_NIOP_Transport (TAO_NIOP_Connection_Handler *handler,
                      TAO_ORB_Core *orb_core,
                      CORBA::Boolean flag);

  /// Default destructor.
  ~TAO_NIOP_Transport (void);

  /// Look for the documentation in Transport.h.
  virtual int handle_input (TAO_Resume_Handle &rh,
                            ACE_Time_Value *max_wait_time = 0,
                            int block = 0);
protected:
  /** @name Overridden Template Methods
   *
   * These are implementations of template methods declared by TAO_Transport.
   */
  //@{

  virtual ACE_Event_Handler * event_handler_i (void);
  virtual TAO_Connection_Handler *connection_handler_i (void);
  virtual TAO_Pluggable_Messaging *messaging_object (void);

  /// Write the complete Message_Block chain to the connection.
  virtual ssize_t send (iovec *iov, int iovcnt,
                        size_t &bytes_transferred,
                        const ACE_Time_Value *max_wait_time);

  /// Read len bytes from into buf.
  virtual ssize_t recv (char *buf,
                        size_t len,
                        const ACE_Time_Value *s = 0);

  virtual int send_message_shared (TAO_Stub *stub,
                                   int message_semantics,
                                   const ACE_Message_Block *message_block,
                                   ACE_Time_Value *max_wait_time);

  virtual int register_handler (void);

  ///@}
public:
  /// @todo These methods IMHO should have more meaningful names.
  /// The names seem to indicate nothing.
  virtual int send_request (TAO_Stub *stub,
                            TAO_ORB_Core *orb_core,
                            TAO_OutputCDR &stream,
                            int message_semantics,
                            ACE_Time_Value *max_wait_time);

  virtual int send_message (TAO_OutputCDR &stream,
                            TAO_Stub *stub = 0,
                            int message_semantics = TAO_Transport::TAO_TWOWAY_REQUEST,
                            ACE_Time_Value *max_time_wait = 0);

  /// Initialising the messaging object
  virtual int messaging_init (CORBA::Octet major,
                              CORBA::Octet minor);

private:

  /// The connection service handler used for accessing lower layer
  /// communication protocols.
  TAO_NIOP_Connection_Handler *connection_handler_;

  /// Our messaging object.
  TAO_Pluggable_Messaging *messaging_object_;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_HAS_NIOP && TAO_HAS_NIOP != 0 */

#include /**/ "ace/post.h"

#endif  /* TAO_NIOP_TRANSPORT_H */
