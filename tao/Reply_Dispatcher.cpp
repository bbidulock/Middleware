// $Id$

#include "tao/Reply_Dispatcher.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"

#if !defined (__ACE_INLINE__)
#include "tao/Reply_Dispatcher.i"
#endif /* __ACE_INLINE__ */

// Constructor.
TAO_Reply_Dispatcher::TAO_Reply_Dispatcher (void)
  : reply_service_info_ ()
  //  : reply_received_ (0)
{
}

// Destructor.
TAO_Reply_Dispatcher::~TAO_Reply_Dispatcher (void)
{
}

TAO_GIOP_Message_State *
TAO_Reply_Dispatcher::message_state (void)
{
  return 0;
}

int
TAO_Reply_Dispatcher::leader_follower_condition_variable (TAO_Transport *)
{
  // no-op.
  return 0;
}

// *********************************************************************

// Constructor.
TAO_Synch_Reply_Dispatcher::TAO_Synch_Reply_Dispatcher (TAO_ORB_Core *orb_core)
  : message_state_ (orb_core),
    reply_received_ (0),
    leader_follower_condition_variable_ (0),
    orb_core_ (orb_core)
{
}

// Destructor.
TAO_Synch_Reply_Dispatcher::~TAO_Synch_Reply_Dispatcher (void)
{
}

// Dispatch the reply.
int
TAO_Synch_Reply_Dispatcher::dispatch_reply (CORBA::ULong reply_status,
                                            const TAO_GIOP_Version &version,
                                            IOP::ServiceContextList &reply_ctx,
                                            TAO_GIOP_Message_State *message_state)
{
  this->reply_received_ = 1;

  this->reply_status_ = reply_status;
  this->version_ = version;

  // Steal the buffer, that way we don't do any unnecesary copies of
  // this data.
  CORBA::ULong max = reply_ctx.maximum ();
  CORBA::ULong len = reply_ctx.length ();
  IOP::ServiceContext* context_list = reply_ctx.get_buffer (1);
  this->reply_service_info_.replace (max, len, context_list, 1);

  if (&this->message_state_ != message_state)
    {
      // The Transport Mux Strategy did not use our Message_State to
      // receive the event, possibly because it is muxing multiple
      // requests over the same connection.

      // Steal the buffer so that no copying is done.
      this->message_state_.cdr.steal_from (message_state->cdr);

      // There is no need to copy the other fields!
    }

  // If condition variable is present, then we are doing leader
  // follower model. Do all the nessary things.
  if (this->leader_follower_condition_variable_ != 0)
    {
      TAO_Leader_Follower& leader_follower =
        this->orb_core_->leader_follower ();

      // We *must* remove it when we signal it so the same condition
      // is not signalled for both wake up as a follower and as the
      // next leader.
      // The follower may not be there if the reply is received while
      // the consumer is not yet waiting for it (i.e. it send the
      // request but has not blocked to receive the reply yet).
      // Ignore errors.
      (void) leader_follower.remove_follower (this->leader_follower_condition_variable_);

      (void) this->leader_follower_condition_variable_->signal ();
    }

  return 1;
}

TAO_GIOP_Message_State *
TAO_Synch_Reply_Dispatcher::message_state (void)
{
  return &this->message_state_;
}

TAO_InputCDR &
TAO_Synch_Reply_Dispatcher::reply_cdr (void)
{
  return this->message_state_.cdr;
}

int &
TAO_Synch_Reply_Dispatcher::reply_received (void)
{
  return this->reply_received_;
}

int
TAO_Synch_Reply_Dispatcher::leader_follower_condition_variable (TAO_Transport *transport)
{
  this->leader_follower_condition_variable_ =
    transport->leader_follower_condition_variable ();
  return 0;
}

// *********************************************************************
#if defined (TAO_HAS_CORBA_MESSAGING) && defined (TAO_POLLER)
// Constructor.
TAO_Asynch_Reply_Dispatcher::TAO_Asynch_Reply_Dispatcher (const TAO_Reply_Handler_Skeleton &reply_handler_skel,
                                                          Messaging::ReplyHandler_ptr reply_handler_ptr)
  : reply_handler_skel_ (reply_handler_skel),
    reply_handler_ (reply_handler_ptr)
{
}

// Destructor.
TAO_Asynch_Reply_Dispatcher::~TAO_Asynch_Reply_Dispatcher (void)
{
}

// Dispatch the reply.
int
TAO_Asynch_Reply_Dispatcher::dispatch_reply (CORBA::ULong reply_status,
                                             const TAO_GIOP_Version &version,
                                             IOP::ServiceContextList &reply_ctx,
                                             TAO_GIOP_Message_State *message_state)
{
  // this->reply_received_ = 1;

  this->reply_status_ = reply_status;
  this->version_ = version;
  this->message_state_ = message_state;

  // Steal the buffer, that way we don't do any unnecesary copies of
  // this data.
  CORBA::ULong max = reply_ctx.maximum ();
  CORBA::ULong len = reply_ctx.length ();
  IOP::ServiceContext* context_list = reply_ctx.get_buffer (1);
  this->reply_service_info_.replace (max, len, context_list, 1);

  if (TAO_debug_level >= 4)
    {
      ACE_DEBUG ((LM_DEBUG,
                  "(%P | %t):TAO_Asynch_Reply_Dispatcher::dispatch_reply:\n"));
    }

  CORBA::Environment &ACE_TRY_ENV = TAO_default_environment ();
  ACE_TRY
    {
      // Call the Reply Handler's skeleton.
      reply_handler_skel_ (message_state_->cdr,
                           reply_handler_,
                           ACE_TRY_ENV);
    }
  ACE_CATCHANY
    {
      if (TAO_debug_level >= 4)
        ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                             "Exception during reply handler");
    }
  ACE_ENDTRY;

  // This was dynamically allocated. Now the job is done. Commit
  // suicide here.
  delete this;

  return 1;
}

TAO_GIOP_Message_State *
TAO_Asynch_Reply_Dispatcher::message_state (void)
{
  return this->message_state_;
}

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_POLLER */
