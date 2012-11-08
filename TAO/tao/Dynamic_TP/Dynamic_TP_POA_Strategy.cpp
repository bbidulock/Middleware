// $Id$

//#include "tao/CSD_Threadpool/CSD_TP_Strategy.h"
#include "tao/Dynamic_TP/Dynamic_TP_POA_Strategy.h"
#include "tao/CSD_ThreadPool/CSD_TP_Remote_Request.h"
#include "tao/CSD_ThreadPool/CSD_TP_Collocated_Synch_Request.h"
#include "tao/CSD_ThreadPool/CSD_TP_Collocated_Asynch_Request.h"

#include "tao/CSD_ThreadPool/CSD_TP_Custom_Synch_Request.h"
#include "tao/CSD_ThreadPool/CSD_TP_Custom_Asynch_Request.h"
#include "tao/CSD_ThreadPool/CSD_TP_Collocated_Synch_With_Server_Request.h"
#include "ace/Trace.h"
#include "tao/ORB_Core.h"

#if !defined (__ACE_INLINE__)
#include "tao/Dynamic_TP/Dynamic_TP_POA_Strategy.inl"
#endif /* ! __ACE_INLINE__ */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Dynamic_TP_POA_Strategy::~TAO_Dynamic_TP_POA_Strategy()
{
}



TAO_Dynamic_TP_POA_Strategy::CustomRequestOutcome
TAO_Dynamic_TP_POA_Strategy::custom_synch_request(TAO::CSD::TP_Custom_Request_Operation* op)
{
  TAO::CSD::TP_Servant_State::HandleType servant_state =
                        this->get_servant_state(op->servant());

  TAO::CSD::TP_Custom_Synch_Request_Handle request = new
                          TAO::CSD::TP_Custom_Synch_Request(op, servant_state.in());

  if (!this->task_.add_request(request.in()))
    {
      // The request was rejected by the task.
      return REQUEST_REJECTED;
    }

  // Now we wait until the request is handled (executed or cancelled).
  return (request->wait()) ? REQUEST_EXECUTED : REQUEST_CANCELLED;
}


TAO_Dynamic_TP_POA_Strategy::CustomRequestOutcome
TAO_Dynamic_TP_POA_Strategy::custom_asynch_request(TAO::CSD::TP_Custom_Request_Operation* op)
{
  TAO::CSD::TP_Servant_State::HandleType servant_state =
                        this->get_servant_state(op->servant());

  TAO::CSD::TP_Custom_Asynch_Request_Handle request = new
                          TAO::CSD::TP_Custom_Asynch_Request(op, servant_state.in());

  return (this->task_.add_request(request.in()))
         ? REQUEST_DISPATCHED : REQUEST_REJECTED;
}


bool
TAO_Dynamic_TP_POA_Strategy::poa_activated_event_i(TAO_ORB_Core& orb_core)
{
  this->task_.thr_mgr(orb_core.thr_mgr());
  // Activates the worker threads, and waits until all have been started.
  return (this->task_.open(&(this->num_threads_)) == 0);
}


void
TAO_Dynamic_TP_POA_Strategy::poa_deactivated_event_i()
{
  // Passing in a value of 1 means that we want to shutdown the task, which
  // equates to causing all worker threads to shutdown.  The worker threads
  // themselves will also invoke the close() method, but the passed-in value
  // will be 0.  So, a 1 means "shutdown", and a 0 means "a single worker
  // thread is going away".
  this->task_.close(1);
}


TAO::CSD::Strategy_Base::DispatchResult
TAO_Dynamic_TP_POA_Strategy::dispatch_remote_request_i
                             (TAO_ServerRequest&              server_request,
                              const PortableServer::ObjectId& object_id,
                              PortableServer::POA_ptr         poa,
                              const char*                     operation,
                              PortableServer::Servant         servant)
{
  TAO::CSD::TP_Servant_State::HandleType servant_state =
                        this->get_servant_state(servant);

  // Now we can create the TP_Remote_Request object, and then add it to our
  // task_'s "request queue".
  //
  // TBD-CSD: Need to use a Cached Allocator to "create" the
  //          TP_Remote_Request objects.  For now, use the heap.
  TAO::CSD::TP_Remote_Request_Handle request =
                            new TAO::CSD::TP_Remote_Request(server_request,
                                                  object_id,
                                                  poa,
                                                  operation,
                                                  servant,
                                                  servant_state.in());

  // Hand the request object to our task so that it can add the request
  // to its "request queue".
  if (!this->task_.add_request(request.in()))
    {
      // Return the DISPATCH_REJECTED return code so that the caller (our
      // base class' dispatch_request() method) knows that we did
      // not handle the request, and that it should be rejected.
      return TAO::CSD::Strategy_Base::DISPATCH_REJECTED;
    }

    return TAO::CSD::Strategy_Base::DISPATCH_HANDLED;
}


TAO::CSD::Strategy_Base::DispatchResult
TAO_Dynamic_TP_POA_Strategy::dispatch_collocated_request_i
                             (TAO_ServerRequest&              server_request,
                              const PortableServer::ObjectId& object_id,
                              PortableServer::POA_ptr         poa,
                              const char*                     operation,
                              PortableServer::Servant         servant)
{
  TAO::CSD::TP_Servant_State::HandleType servant_state =
                        this->get_servant_state(servant);

  bool is_sync_with_server = server_request.sync_with_server();
  bool is_synchronous      = server_request.response_expected();

  TAO::CSD::TP_Collocated_Synch_Request_Handle             synch_request;
  TAO::CSD::TP_Collocated_Synch_With_Server_Request_Handle synch_with_server_request;
  TAO::CSD::TP_Request_Handle                              request;

  // Create the request object using the appropriate concrete type.
  if (is_sync_with_server)
    {
      synch_with_server_request =
                        new TAO::CSD::TP_Collocated_Synch_With_Server_Request
                                                     (server_request,
                                                      object_id,
                                                      poa,
                                                      operation,
                                                      servant,
                                                      servant_state.in());

      // Give the request handle its own "copy".
      synch_with_server_request->_add_ref();
      request = synch_with_server_request.in();
    }
  else if (is_synchronous)
    {
      synch_request = new TAO::CSD::TP_Collocated_Synch_Request(server_request,
                                                      object_id,
                                                      poa,
                                                      operation,
                                                      servant,
                                                      servant_state.in());

      // Give the request handle its own "copy".
      synch_request->_add_ref();
      request = synch_request.in();
    }
  else
    {
      // Just use the (base) request handle to hold the request object.
      request = new TAO::CSD::TP_Collocated_Asynch_Request(server_request,
                                                 object_id,
                                                 poa,
                                                 operation,
                                                 servant,
                                                 servant_state.in());
    }

  // Hand the request object to our task so that it can add the request
  // to its "request queue".
  if (!this->task_.add_request(request.in()))
    {
      // Return the DISPATCH_REJECTED return code so that the caller (our
      // base class' dispatch_request() method) knows that we did
      // not handle the request, and that it should be rejected.
      return DISPATCH_REJECTED;
    }

  // We need to wait on the request object if the request type is a
  // synchronous request.
  if (!synch_request.is_nil())
    {
      int srw = synch_request->wait();
      if (srw == false)
        {
          // Raise exception when request was cancelled.
          throw ::CORBA::NO_IMPLEMENT();
        }
    }
  else if (!synch_with_server_request.is_nil())
    {
      bool swsr = synch_with_server_request->wait();
      if (swsr == false)
        {
          // Raise exception when request was cancelled.
          throw ::CORBA::NO_IMPLEMENT();
        }
    }

  return DISPATCH_HANDLED;
}


void
TAO_Dynamic_TP_POA_Strategy::servant_activated_event_i
                                (PortableServer::Servant servant,
                                 const PortableServer::ObjectId&)
{
  if (this->serialize_servants_)
    {
      // Add the servant to the servant state map.
      this->servant_state_map_.insert(servant);
    }
}


void
TAO_Dynamic_TP_POA_Strategy::servant_deactivated_event_i
                                (PortableServer::Servant servant,
                                 const PortableServer::ObjectId&)
{
  // Cancel all requests stuck in the queue for the specified servant.
  this->task_.cancel_servant(servant);

  if (this->serialize_servants_)
    {
      // Remove the servant from the servant state map.
      this->servant_state_map_.remove(servant);
    }
}


void
TAO_Dynamic_TP_POA_Strategy::cancel_requests(PortableServer::Servant servant)
{
  // Cancel all requests stuck in the queue for the specified servant.
  this->task_.cancel_servant(servant);
}


TAO::CSD::TP_Servant_State::HandleType
TAO_Dynamic_TP_POA_Strategy::get_servant_state(PortableServer::Servant servant)
{
  TAO::CSD::TP_Servant_State::HandleType servant_state;

  if (this->serialize_servants_)
    {
      servant_state = this->servant_state_map_.find(servant);
    }

  return servant_state;
}
TAO_END_VERSIONED_NAMESPACE_DECL