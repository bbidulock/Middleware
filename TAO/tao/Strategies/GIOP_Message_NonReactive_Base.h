// -*- C++ -*-
//
// ===================================================================
/**
 *  @file GIOP_Message_NonReactive_Base.h
 *
 *  $Id$
 *
 *  @author  Balachandran Natarajan <bala@cs.wustl.edu>
 */
// ===================================================================

#ifndef TAO_GIOP_MESSAGE_NONREACTIVE_BASE_H
#define TAO_GIOP_MESSAGE_NONREACTIVE_BASE_H
#include "ace/pre.h"
#include "strategies_export.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "GIOP_Message_NonReactive_Handler.h"
#include "tao/GIOP_Message_Base.h"


class TAO_Pluggable_Reply_Params;

/**
 * @class TAO_GIOP_Message_NonReactive_Base
 *
 * @brief Uses the NonReactive mechanism to read and process
 *  messages.
 *
 *  Some protocols based on shared memory cannot make use of the
 *  reactor as other protocols based on TCP/IP. This class is a relief
 *  for such protocols. This effectively does the following
 *    - reads the GIOP header out of the transport
 *    - processes the header to determine the length of the message
 *      and other details.
 *    - reads the body of the message from the transport
 *    - passes the data to the base class for making the upcall.
 */

class TAO_Strategies_Export TAO_GIOP_Message_NonReactive_Base :public TAO_GIOP_Message_Base
{
public:

  /// Constructor
  TAO_GIOP_Message_NonReactive_Base (TAO_ORB_Core *orb_core,
                                     size_t cdr_size = ACE_CDR::DEFAULT_BUFSIZE);


  /// This method reads the message on the connection. Returns 0 when
  /// there is short read on the connection. Returns 1 when the full
  /// message is read and handled. Returns -1 on errors. <block> is
  /// not used.
  virtual int read_message (TAO_Transport *transport,
                            int block = 0,
                            ACE_Time_Value *max_wait_time = 0);


  /// Get the message type. The return value would be one of the
  /// following:
  /// TAO_PLUGGABLE_MESSAGE_REQUEST,
  /// TAO_PLUGGABLE_MESSAGE_REPLY,
  /// TAO_PLUGGABLE_MESSAGE_CLOSECONNECTION,
  /// TAO_PLUGGABLE_MESSAGE_MESSAGE_ERROR.
  virtual TAO_Pluggable_Message_Type message_type (void);

  /// Process the request message that we have received on the
  /// connection
  virtual int process_request_message (TAO_Transport *transport,
                                       TAO_ORB_Core *orb_core);

  /// Parse the reply message that we received and return the reply
  /// information though <reply_info>
  virtual int process_reply_message (
      TAO_Pluggable_Reply_Params &reply_info
    );

  /// Are there any more pieces that needs to be read to make a full
  /// message?
  virtual int more_messages (void);

private:

  /// The input cdr stream in which the incoming data is stored.
  TAO_InputCDR input_cdr_;
};

#if defined (__ACE_INLINE__)
# include "GIOP_Message_NonReactive_Base.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /*TAO_GIOP_MESSAGE_NONREACTIVE_BASE_H*/
