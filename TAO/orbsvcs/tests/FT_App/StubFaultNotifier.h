// -*- C++ -*-
//
// $Id$
#ifndef STUBFAULTNOTIFIER_H_
#define STUBFAULTNOTIFIER_H_
#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include  /**/ <ace/pre.h>

#include <orbsvcs/FT_NotifierS.h>
#include <orbsvcs/FT_FaultDetectorFactoryC.h>
#include <ace/Vector_T.h>

//////////////////////
// Forward references
class TAO_ORB_Manager;


/////////////////////
// Class declarations

/**
 * A stub implementation of the FaultNotifier interface
 */
class  StubFaultNotifier : public virtual POA_FT::FaultNotifier
{
  //////////////////////
  // non-CORBA interface
public:
  /**
   * Default constructor.
   */
  StubFaultNotifier ();

  /**
   * Virtual destructor.
   */
  virtual ~StubFaultNotifier ();

  /**
   * Parse command line arguments.
   */
  int parse_args (int argc, char * argv[]);

  /**
   * Initialize.
   */
  int init (CORBA::ORB_var & orb ACE_ENV_ARG_DECL);

  /**
   * Prepare to exit.
   */
  int fini ();

  /**
   * Return a string to identify this object for logging/console message purposes.
   */
  const char * identity () const;

  /**
   * idle time activity.
   * @param result [out] status code to return from process
   * @returns 0 to continue; nonzero to quit
   */
  int idle(int &result);

  // override virtuals
::PortableServer::POA_ptr _default_POA (ACE_ENV_SINGLE_ARG_DECL);

  PortableServer::ObjectId objectId()const;


  /**
   * Clean house for process shut down.
   */
  void shutdown_i ();

  ////////////////////////////////
  // CORBA interface FaultNotifier


  virtual void push_structured_fault (
      const CosNotification::StructuredEvent & event
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void push_sequence_fault (
    const CosNotification::EventBatch & events
    ACE_ENV_ARG_DECL_WITH_DEFAULTS
  )
  ACE_THROW_SPEC ((CORBA::SystemException));

  virtual ::CosNotifyFilter::Filter_ptr create_subscription_filter (
    const char * constraint_grammar
    ACE_ENV_ARG_DECL_WITH_DEFAULTS
  )
  ACE_THROW_SPEC ((CORBA::SystemException, CosNotifyFilter::InvalidGrammar));

  virtual FT::FaultNotifier::ConsumerId connect_structured_fault_consumer (
    CosNotifyComm::StructuredPushConsumer_ptr push_consumer,
    CosNotifyFilter::Filter_ptr filter
    ACE_ENV_ARG_DECL_WITH_DEFAULTS
  )
  ACE_THROW_SPEC ((CORBA::SystemException));

  virtual FT::FaultNotifier::ConsumerId connect_sequence_fault_consumer (
    CosNotifyComm::SequencePushConsumer_ptr push_consumer,
    CosNotifyFilter::Filter_ptr filter
    ACE_ENV_ARG_DECL_WITH_DEFAULTS
  )
  ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void disconnect_consumer (
    FT::FaultNotifier::ConsumerId connection
    ACE_ENV_ARG_DECL_WITH_DEFAULTS
  )
  ACE_THROW_SPEC ((CORBA::SystemException, CosEventComm::Disconnected));

  //////////////////////////////////////////
  // CORBA interface PullMonitorable methods
  virtual CORBA::Boolean is_alive (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException));

  /////////////////
  // Implementation
private:
  int write_ior_file();
  int read_ior_file(const char * fileName, CORBA::String_var & ior);

  ///////////////
  // Data Members
private:
  /**
   * The orb
   */
  CORBA::ORB_var orb_;

  /**
   * The POA used to activate this object.
   */
  PortableServer::POA_var poa_;

  /**
   * The CORBA object id assigned to this object.
   */
  PortableServer::ObjectId_var object_id_;

  /**
   * IOR of this object as assigned by poa
   */
  CORBA::String_var ior_;

  /**
   * A file to which the factory's IOR should be written.
   */
  const char * ior_output_file_;

  /**
   * A file from which the detecor's IOR should be read.
   */
  const char * detector_ior_file_;

  ::FT::FaultDetectorFactory_var factory_;

  /**
   * A collection of files containing replica IORs
   */
  ACE_Vector < const char * > iorReplicaFiles_;
  char * replica_ior_buffer_;

  ACE_Vector < FT::PullMonitorable_var > replicas_;
  /**
   * A name to be used to register with the name service.
   */
  const char * ns_name_;

  /**
   * A human-readable string to distinguish this from other Notifiers.
   */
  ACE_CString identity_;
};

#include /**/ <ace/post.h>

#endif /* STUBFAULTNOTIFIER_H_  */
