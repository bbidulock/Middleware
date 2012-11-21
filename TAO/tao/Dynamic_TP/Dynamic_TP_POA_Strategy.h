// -*- C++ -*-

//=============================================================================
/**
 *  @file    Dynamic_TP_POA_Strategy.h
 *
 *  $Id$
 *
 *  @author  Marc Neeley <neeleym@ociweb.com>
 */
//=============================================================================



#ifndef TAO_DYNAMIC_TP_POA_STRATEGY_H
#define TAO_DYNAMIC_TP_POA_STRATEGY_H

#include /**/ "ace/pre.h"
#include "tao/Dynamic_TP/dynamic_tp_export.h"
#include "tao/Dynamic_TP/Dynamic_TP_Config.h"
#include "tao/Dynamic_TP/Dynamic_TP_Task.h"
#include "tao/CSD_ThreadPool/CSD_TP_Servant_State_Map.h"
#include "tao/Dynamic_TP/Dynamic_TP_POA_StrategyImpl.h"
#include "tao/CSD_ThreadPool/CSD_TP_Custom_Request_Operation.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/CSD_Framework/CSD_Strategy_Base.h"
#include "tao/Intrusive_Ref_Count_Handle_T.h"
#include "ace/OS_NS_strings.h"


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


class TAO_Dynamic_TP_POA_Strategy;
typedef TAO_Intrusive_Ref_Count_Handle<TAO_Dynamic_TP_POA_Strategy> TAO_Dynamic_TP_POA_Strategy_Handle;

class TAO::CSD::TP_Custom_Request_Operation;

/**
 * @class TAO_Dynamic_TP_POA_Strategy
 *
 * @brief
 *
 */
class TAO_Dynamic_TP_Export TAO_Dynamic_TP_POA_Strategy: public TAO::CSD::Strategy_Base
{
 public:

  /// Constructor.
  TAO_Dynamic_TP_POA_Strategy(ACE_CString tp_config_name,
                              TAO_Dynamic_TP_POA_StrategyImpl * dynamic_strategy,
                              bool     serialize_servants = true);

  TAO_Dynamic_TP_POA_Strategy(TAO_DTP_Definition * tp_config_name,
                              bool     serialize_servants = true);

  /// Virtual Destructor.
  virtual ~TAO_Dynamic_TP_POA_Strategy();

  /// Set the number of threads in the pool (must be > 0).
  void set_num_threads(Thread_Counter num_threads);

  /// Turn on/off serialization of servants.
  void set_servant_serialization(bool serialize_servants);

  /// Return codes for the custom dispatch_request() methods.
  enum CustomRequestOutcome
  {
    /// The request was successfully put on the request queue.
    REQUEST_DISPATCHED,
    /// The request has been executed/completed by a worker thread.
    REQUEST_EXECUTED,
    /// The request was removed from the queue and cancelled.
    REQUEST_CANCELLED,
    /// The request queue rejected the request
    REQUEST_REJECTED
  };

  /// Inject a synchronous, custom request into the request queue.
  /// This will block the calling thread until the request is handled
  /// (dispatched or cancelled) or rejected.
  /// Will return REQUEST_EXECUTED, REQUEST_CANCELLED, or REQUEST_REJECTED.
  CustomRequestOutcome custom_synch_request
    (TAO::CSD::TP_Custom_Request_Operation* op);

  /// Inject an asynchronous, custom request into the request queue.
  /// This will return control to the calling thread once the request
  /// has been placed into the queue (or rejected).
  /// Will return REQUEST_DISPATCHED or REQUEST_REJECTED.
  CustomRequestOutcome custom_asynch_request
    (TAO::CSD::TP_Custom_Request_Operation* op);

  /// Cancel all requests that are targeted for the provided servant.
  /// This is requested on the user application level.
  void cancel_requests(PortableServer::Servant servant);

  ACE_CString get_tp_config();

 protected:

  /// Handle the dispatching of a remote request.
  ///
  /// This will cause a new "request" object to be created and pushed
  /// on to a "request queue".  The worker threads are responsible for
  /// servicing the queue, and performing the actual dispatch logic.
  virtual Strategy_Base::DispatchResult dispatch_remote_request_i
    (TAO_ServerRequest&              server_request,
     const PortableServer::ObjectId& object_id,
     PortableServer::POA_ptr         poa,
     const char*                     operation,
     PortableServer::Servant         servant);

  /// Handle the dispatching of a collocated request.
  ///
  /// This will cause a new "request" object to be created and pushed
  /// on to a "request queue".  The worker threads are responsible for
  /// servicing the queue, and performing the actual dispatch logic.
  virtual Strategy_Base::DispatchResult dispatch_collocated_request_i
    (TAO_ServerRequest&              server_request,
     const PortableServer::ObjectId& object_id,
     PortableServer::POA_ptr         poa,
     const char*                     operation,
     PortableServer::Servant         servant);

  /// Event - The POA has been activated.
  /// This will activate the worker thread(s).
  /// Returns true if the worker threads were activated successfully.
  /// Otherwise, returns false.
  virtual bool poa_activated_event_i(TAO_ORB_Core& orb_core);

  /// Event - The POA has been deactivated.
  /// This will shutdown the worker thread(s).
  virtual void poa_deactivated_event_i();

  /// Event - A servant has been activated
  virtual void servant_activated_event_i
    (PortableServer::Servant servant,
     const PortableServer::ObjectId& oid);

  /// Event - A servant has been deactivated
  virtual void servant_deactivated_event_i
    (PortableServer::Servant servant,
     const PortableServer::ObjectId& oid);

 private:


  /**
   * Helper method that is responsible for looking up the servant
   * state object in the servant state map *if* the "serialize
   * servants" flag is set to true.  In the case where the
   * "serialize servants" flag is set to false, then a "nil"
   * servant state handle object is returned.
   *
   * @param servant - input - a pointer to the servant object.
   *
   * @returns a handle to a servant state object.
   *
   * @throw PortableServer::POA::ServantNotActive if the servant
   *        state cannot be determined.
   */
  TAO::CSD::TP_Servant_State::HandleType get_servant_state
    (PortableServer::Servant servant);

  /// This is the active object used by the worker threads.
  /// The request queue is owned/managed by the task object.
  /// The strategy object puts requests into the task's request
  /// queue, and the worker threads service the queued requests
  /// by performing the actual servant request dispatching logic.
  //TAO_Dynamic_TP_Task task_;

  /// The number of worker threads to use for the task.
  TAO::CSD::Thread_Counter num_threads_;

  /// The "serialize servants" flag.
  bool serialize_servants_;

  /// The map of servant state objects - only used when the
  /// "serialize servants" flag is set to true.
  TAO::CSD::TP_Servant_State_Map servant_state_map_;

  /// This holds the name of a configuration that have been loaded
  /// into a Dynamic_TP_Config_Registry.  This is the key to the RB
  /// Tree entry.

  ACE_CString dynamic_tp_config_name_;

  /// Pointer to the delagated implementation of the strategy
  /// This will be initialized to null with the expectation that this will
  /// allow for lazy loading of a strategy instance when an apply_to method is called
  /// or dynamically when the POA is activated.

  TAO_Dynamic_TP_POA_StrategyImpl * dtp_strategy_impl_;
};



TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "tao/Dynamic_TP/Dynamic_TP_POA_Strategy.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_DYNAMIC_TP_POA_STRATEGY_H */
