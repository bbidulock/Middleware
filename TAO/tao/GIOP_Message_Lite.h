// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     GIOP_Message_Lite.h
//
// = DESCRIPTION
//     Interface for the GIOP Lite messaging protocol
//
// = AUTHOR
//     Balachandran Natarajan <bala@cs.wustl.edu>
//
// ============================================================================
#ifndef _TAO_GIOP_MESSAGE_LITE_H_
#define _TAO_GIOP_MESSAGE_LITE_H_

#include "tao/GIOP_Server_Request.h"
#include "tao/GIOP_Assorted_Headers.h"

class TAO_Export TAO_GIOP_Message_Lite :
  public TAO_Pluggable_Messaging_Interface
{
  // = TITLE
  //   Definitions got the GIOP lite
  //
  // = DESCRIPTION
  //   The interface is quite a replica of the GIOP Base
  //   interface. Implmenetation may not vary much too. But we are
  //   having a seperate interface to have seperation of concerns.
public:  
  TAO_GIOP_Message_Lite (void);
  //Ctor

  virtual ~TAO_GIOP_Message_Lite (void);
  // Dtor

  virtual CORBA::Boolean write_protocol_header (TAO_Pluggable_Message_Type t,
                                                TAO_OutputCDR &msg);
  // Writes the GIOPLite header in to <msg>

  int handle_input (TAO_Transport *transport,
                    TAO_ORB_Core *orb_core,
                    TAO_Message_State_Factory &mesg_state,
                    ACE_Time_Value *max_time_value = 0);
  // Reads input from the transport layer to the cdr stream in <mesg_state>
  
  virtual CORBA::Boolean 
  write_message_header (const TAO_Operation_Details &opdetails,
                        TAO_Pluggable_Header_Type header_type,
                        TAO_Target_Specification &spec,
                        TAO_OutputCDR &msg);
  // Write the  header defined by <header_type> in to <msg>

  int send_message (TAO_Transport *transport,
                    TAO_OutputCDR &stream,
                    ACE_Time_Value *max_wait_time = 0,
                    TAO_Stub *stub = 0,
                    int two_way = 1);
  // Sends the encapsulated stream in <stream> on to the transport 
  
  int parse_reply (TAO_Message_State_Factory &mesg_state,
                   TAO_Pluggable_Connector_Params &params,
                   CORBA::ULong &reply_status);
  // Parse the reply message from the server
  
  int process_connector_messages (TAO_Transport *transport,
                                  TAO_ORB_Core *orb_core,
                                  TAO_InputCDR &input,
                                  CORBA::Octet message_type);
  // Processes the messages from the connectors so that they can be
  // passed on to the appropriate states.
private:
  CORBA::Boolean 
  write_request_header (const TAO_Operation_Details &details,
                        TAO_Target_Specification &spec,
                        TAO_OutputCDR &msg);
  // Write the GIOP lite request header in to <msg>
  
  CORBA::Boolean 
  write_locate_request_header (CORBA::ULong request_id,
                               TAO_Target_Specification &spec,
                               TAO_OutputCDR &msg);
  // Write the GIOP lite locate request header in to <msg>
  
  int parse_header (TAO_GIOP_Message_State *state);
  // Parse the header

  
  int process_connector_request (TAO_Transport *transport,
                                 TAO_ORB_Core* orb_core,
                                 TAO_InputCDR &input,
                                 TAO_OutputCDR &output);
  // A request was received on the server side. <transport> is the
  // source of the message (and thus where the  replies should be
  // sent). <orb_core> is the ORB that received the message <input>
  // contains the message <output> can be used to store any responses
  // <request_id> and <response_required> are set as part of the
  // message processing.


  int process_connector_locate (TAO_Transport *transport,
                                TAO_ORB_Core* orb_core,
                                TAO_InputCDR &input,
                                TAO_OutputCDR &output);
  // A LocateRequest was received on the server side. <transport> is
  // the source of the message (and thus where the replies should be
  // sent). <orb_core> is the ORB that received the message <input>
  // contains the message <output> can be used to store any responses
  // <request_id> and <response_required> are set as part of the
  // message processing.

  int parse_request_header (TAO_GIOP_ServerRequest &request);
  // Parse the Request Message header 

  int parse_locate_header (TAO_GIOP_Locate_Request_Header &request);
  // Parse the Locate Request header
  
  CORBA::Boolean make_reply (CORBA::ULong request_id,
                             TAO_OutputCDR &output);
  // Make a reply message including the protocol header

  int send_reply_exception (TAO_Transport *transport,
                            TAO_ORB_Core* orb_core,
                            CORBA::ULong request_id,
                            CORBA::Exception *x);
  // We must send a LocateReply through <transport>, this request
  // resulted in some kind of exception.

  int make_locate_reply (TAO_Transport *transport,
                         TAO_OutputCDR & output,
                         TAO_GIOP_Locate_Request_Header &request,
                         TAO_GIOP_Locate_Status_Msg &status_info);
  // Making replies for LocateRequest messages.
  
  int  send_error (TAO_Transport *transport);
  // Send error messages
  
  void dump_msg (const char *label,
                 const u_char *ptr,
                 size_t len);
  // Print out the contents of the buffer.
  

};


// The IIOP Lite header length and the offset of the message size
// field in it.
const size_t TAO_GIOP_LITE_HEADER_LEN = 5;
const size_t TAO_GIOP_LITE_MESSAGE_SIZE_OFFSET = 0;
const size_t TAO_GIOP_LITE_MESSAGE_TYPE_OFFSET = 4;



#if defined (__ACE_INLINE__)
# include "tao/GIOP_Message_Lite.i"
#endif /* __ACE_INLINE__ */

#endif /*_TAO_GIOP_MESSAGE_LITE_H_*/
