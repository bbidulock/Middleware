// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     Transport_Mux_Strategy.h
//
// = DESCRIPTION
//     IIOP Transport Mux Strategies.
//
// = AUTHOR
//     Alexander Babu Arulanthu <alex@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_TRANSPORT_MUX_STRATEGY_H
#define TAO_TRANSPORT_MUX_STRATEGY_H

#include "tao/GIOP.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Functor.h"
#include "ace/Hash_Map_Manager.h"

class TAO_Reply_Dispatcher;

class TAO_Export TAO_Transport_Mux_Strategy
{
  // = TITLE
  //
  //     Strategy to determine whether the connection should be
  //     multiplexed for multiple requests or it is exclusive for a
  //     single request at a time.
  //
  // = DESCRIPTION
  //
  
public:
  TAO_Transport_Mux_Strategy (void);
  // Base class constructor.

  virtual ~TAO_Transport_Mux_Strategy (void);
  // Base class destructor.

  virtual CORBA::ULong request_id (void)  = 0;
  // Generate and return an unique request id for the current
  // invocation.

  // = Bind and Find methods for the <Request ID, ReplyDispatcher>
  //   pairs.

  virtual int bind_dispatcher (CORBA::ULong request_id,
                               TAO_Reply_Dispatcher *rd) = 0;
  // Bind the dispatcher with the request id.
  
  virtual int dispatch_reply (CORBA::ULong request_id,
                              CORBA::ULong reply_status,
                              const TAO_GIOP_Version& version,
                              TAO_GIOP_ServiceContextList& reply_ctx,
                              TAO_GIOP_Message_State* message_state) = 0;
  // Dispatch the reply for <request_id>, cleanup any resources
  // allocated for that request.

  // = "Factory methods" to obtain the CDR stream, in the Muxed case
  //    the factory simply allocates a new one, in the Exclusive case
  //    the factory returns a pointer to the pre-allocated CDR.

  virtual TAO_GIOP_Message_State *get_message_state (void) = 0;
  // Get a CDR stream.

  virtual void destroy_message_state (TAO_GIOP_Message_State *) = 0;
  // Destroy a CDR stream.
};

// *********************************************************************

class TAO_Export TAO_Exclusive_TMS : public TAO_Transport_Mux_Strategy
{
  // = TITLE
  //
  //    Connection exclusive for the request.
  //
  // = DESCRIPTION
  //

public:
  TAO_Exclusive_TMS (void);
  // Constructor.

  virtual ~TAO_Exclusive_TMS (void);
  // Destructor.

  virtual CORBA::ULong request_id (void);
  // Generate and return an unique request id for the current
  // invocation.

  virtual int bind_dispatcher (CORBA::ULong request_id,
                               TAO_Reply_Dispatcher *rh);
  // Bind the dispatcher with the request id.

  virtual int dispatch_reply (CORBA::ULong request_id,
                              CORBA::ULong reply_status,
                              const TAO_GIOP_Version& version,
                              TAO_GIOP_ServiceContextList& reply_ctx,
                              TAO_GIOP_Message_State* message_state);
  // Dispatch the reply for <request_id>, cleanup any resources
  // allocated for that request.

  virtual TAO_GIOP_Message_State *get_message_state (void);
  // Return the message state.

  virtual void destroy_message_state (TAO_GIOP_Message_State *);
  // No op in this strategy.

protected:
  CORBA::ULong request_id_generator_;
  // Used to generate a different request_id on each call to
  // request_id().

  CORBA::ULong request_id_;
  // Request id for the current request.

  TAO_Reply_Dispatcher *rd_;
  // Reply Dispatcher corresponding to the request.
};

// *********************************************************************

class TAO_Export TAO_Muxed_TMS : public  TAO_Transport_Mux_Strategy
{
  // = TITLE
  //
  //    Connection is multiplexed for many requests.
  //
  // = DESCRIPTION
  //

public:
  TAO_Muxed_TMS (void);
  // Constructor.

  virtual ~TAO_Muxed_TMS (void);
  // Destructor.

  virtual CORBA::ULong request_id (void);
  // Generate and return an unique request id for the current
  // invocation.
  
  virtual int bind_dispatcher (CORBA::ULong request_id,
                               TAO_Reply_Dispatcher *rh);
  // Bind the dispatcher with the request id.

  virtual int dispatch_reply (CORBA::ULong request_id,
                              CORBA::ULong reply_status,
                              const TAO_GIOP_Version& version,
                              TAO_GIOP_ServiceContextList& reply_ctx,
                              TAO_GIOP_Message_State* message_state);
  // Dispatch the reply for <request_id>, cleanup any resources
  // allocated for that request.

  virtual TAO_GIOP_Message_State *get_message_state (void);
  // Return the message state.

  virtual void destroy_message_state (TAO_GIOP_Message_State *);
  // No op in this strategy.

protected:
  CORBA::ULong request_id_generator_;
  // Used to generate a different request_id on each call to
  // request_id().

  typedef ACE_Hash_Map_Manager_Ex <CORBA::ULong,
                                   TAO_Reply_Dispatcher *,
                                   ACE_Hash <CORBA::ULong>,
                                   ACE_Equal_To <CORBA::ULong>,
                                   ACE_Null_Mutex> REQUEST_DISPATCHER_TABLE;

  REQUEST_DISPATCHER_TABLE dispatcher_table_;
  // Table of <Request ID, Reply Dispatcher> pairs.
};

// *********************************************************************

#endif /* TRANSPORT_MUX_STRATEGY_H */
