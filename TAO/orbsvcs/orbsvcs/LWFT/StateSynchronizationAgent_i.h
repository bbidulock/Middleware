// -*- C++ -*-

//=============================================================================
/**
 *  @file    StateSynchronizationAgent_i.h
 *
 *  $Id$
 *
 *  @author  Friedhelm Wolf (fwolf@dre.vanderbilt.edu)
 */
//=============================================================================

#ifndef STATE_SYNCHRONIZATION_AGENT_I_H_
#define STATE_SYNCHRONIZATION_AGENT_I_H_

#include <list>

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Thread_Mutex.h"
#include "ace/Refcounted_Auto_Ptr.h"

#include "StateSynchronizationAgentS.h"
#include "StatefulObject.h"
#include "ssa_export.h"
#include "SSA_AMI_Handler.h"

#if defined (FLARE_USES_DDS)
# include <ccpp_dds_dcps.h>
# include "DDSFailure.h"
#endif 

class SSA_Export StateSynchronizationAgent_i
  : public POA_StateSynchronizationAgent, 
    public AMI_StateSynchronizationAgentHandler
{
 public:
  StateSynchronizationAgent_i (const std::string & host_id,
                               const std::string & process_id,
                               bool use_corba = true);

  ~StateSynchronizationAgent_i (void);

  /// Implementation of the StateSynchronizationAgent interface.
  virtual void state_changed (const char * object_id);

  /// Called by RM to initiate 2PC.
  virtual CORBA::Boolean precommit_state (const char * object_id);

  /// Persist the state without commiting it by sending it to the
  /// SSA in replica servers.
  virtual void transfer_state (const char * object_id, const ::CORBA::Any & state_value);

  /// Commit the state. Called by RM.
  virtual void commit_state (const char * object_id);

  /// Implementation of the StateSynchronizationAgent interface.
  virtual void update_rank_list (const RankList & rank_list);

  /// Registers application for statesynchronization with CORBA.
  virtual void register_application (const char * object_id,
				     ReplicatedApplication_ptr app);
  
  virtual void state_changed() {}
  virtual void state_changed_excep(Messaging::ExceptionHolder*) {}
    
  virtual void precommit_state(CORBA::Boolean) {}
  virtual void precommit_state_excep(Messaging::ExceptionHolder*) {}
     
  virtual void commit_state() {}
  virtual void commit_state_excep(Messaging::ExceptionHolder*) {}
     
  virtual void transfer_state();
  virtual void transfer_state_excep(Messaging::ExceptionHolder*) {}
     
  virtual void update_rank_list() {}
  virtual void update_rank_list_excep(Messaging::ExceptionHolder*) {}
     
  virtual void register_application() {}
  virtual void register_application_excep(Messaging::ExceptionHolder*) {}

#ifdef FLARE_USES_DDS
  /// Registers application for state synchronization with DDS
  template <typename DATA_TYPE>
  void register_application_with_dds (const char * object_id,
                                      ReplicatedApplication_ptr app);
#endif /* FLARE_USES_DDS */

  typedef
  ACE_Refcounted_Auto_Ptr <StatefulObject,
                           ACE_Null_Mutex>
                           STATEFUL_OBJECT_PTR;

  typedef std::list<STATEFUL_OBJECT_PTR> REPLICA_OBJECT_LIST;

  struct ReplicaGroup 
  {
    REPLICA_OBJECT_LIST replicas;
    bool use_dds;
  };

  typedef ACE_Hash_Map_Manager_Ex<
    ACE_CString,
    ReplicaGroup,
    ACE_Hash<ACE_CString>,
    ACE_Equal_To<ACE_CString>,
    ACE_Thread_Mutex> OBJECTID_REPLICA_MAP;

  typedef ACE_Hash_Map_Manager_Ex<
    ACE_CString,
    ReplicatedApplication_var,
    ACE_Hash<ACE_CString>,
    ACE_Equal_To<ACE_CString>,
    ACE_Null_Mutex> OBJECTID_APPLICATION_MAP;

#ifdef FLARE_USES_DDS

  bool create_participant (void);
  bool delete_participant (void);
  bool create_publisher (void);
  bool delete_publisher (void);
  bool create_subscriber (void);
  bool delete_subscriber (void);

#endif /* FLARE_USES_DDS */

  std::string get_unique_id (const std::string & app_name);
  
private:
  /// host on which the agent is running
  std::string host_id_;

  /// process in which the agent is running
  std::string process_id_;

  /// keeps lists of replicas associated to application ids
  OBJECTID_REPLICA_MAP replica_map_;

  /// keeps references to all applications running in this process
  OBJECTID_APPLICATION_MAP application_map_;
  
  // pre-commit state 
  ::CORBA::Any precommit_state_;

#ifdef FLARE_USES_DDS

  /// id of the DDS domain
  DDS::DomainId_t domain_id_;

  /// DDS Domain Participant
  DDS::DomainParticipant_var domain_participant_;

  /// DDS Publisher for this Domain
  DDS::Publisher_var publisher_;

  /// DDS Subscriber for this Domain
  DDS::Subscriber_var subscriber_;

#endif /* FLARE_USES_DDS */

  /// decides whether replicas should be updated through corba or dds
  bool use_corba_;
  
  StateSynchronizationAgent_var ssa_in_replica_;

  size_t ssa_invoked_;
};

#include "StateSynchronizationAgent_i_T.cpp"

#endif /* STATE_SYNCHRONIZATION_AGENT_I_H_ */
