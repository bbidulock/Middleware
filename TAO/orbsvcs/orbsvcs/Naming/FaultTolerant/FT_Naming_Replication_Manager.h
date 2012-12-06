// -*- C++ -*-

//=============================================================================
/**
 * @file   FT_Naming_Replication_Manager.h
 *
 * $Id$
 *
 * @author Kevin Stanley <stanleyk@ociweb.com>
 */
//=============================================================================


#ifndef TAO_FT_NAMING_REPLICATION_MANAGER_H
#define TAO_FT_NAMING_REPLICATION_MANAGER_H

#include /**/ "ace/pre.h"

#include "orbsvcs/Naming/FaultTolerant/ftnaming_export.h"
#include "orbsvcs/Naming/FaultTolerant/FT_NamingReplicationS.h"
#include "ace/Recursive_Thread_Mutex.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "FT_NamingReplicationC.h"

class TAO_FT_Naming_Server;

class TAO_FtNaming_Export TAO_FT_Naming_Replication_Manager
  : public virtual POA_FT_Naming::ReplicationManager
{
public:

 /*
  * Create a Replication Manager and provide it with the naming server
  * to be updated whenever notified by the peer replica
  */
  TAO_FT_Naming_Replication_Manager(TAO_FT_Naming_Server *naming_svr,
                                    const char* repl_mgr_name);

  virtual ~TAO_FT_Naming_Replication_Manager(void);

  /// Initialize the naming manager. This will provide the poa to
  /// the naming manager and underlying components for use in
  /// managing the object groups.
  void initialize (CORBA::ORB_ptr orb,
                   PortableServer::POA_ptr root_poa);

 /*
  * Implementation of the FT_Naming::ReplicationManager interface
  */
  virtual ::FT_Naming::ReplicaInfo * register_replica (::FT_Naming::ReplicationManager_ptr replica,
                                                       const ::FT_Naming::ReplicaInfo & replica_info);

  virtual void notify_updated_object_group (
    const FT_Naming::ObjectGroupUpdate & group_info);

  virtual void notify_updated_context (
    const FT_Naming::NamingContextUpdate & group_info);

  static FT_Naming::ReplicationManager_ptr peer_replica (void);

 /*
  * Utilities for implementing the FT_Naming::ReplicationManager
  */

  /// Stores the peer in the peer_replica_ data member and invokes the
  /// register_replica interface method with the peer. Returns 0 if
  /// successful and -1 if unable to contact the peer.
  int register_with_peer_replica (FT_Naming::ReplicationManager_ptr replica,
                                  CosNaming::NamingContext_ptr nc,
                                  FT::NamingManager_ptr rm);

  /// The object reference for this servant instance
  FT_Naming::ReplicationManager_ptr reference (void);

protected:

  // The object which implements the naming service and the object manager
  TAO_FT_Naming_Server *naming_svr_;

  // Store the reference to the replica object reference
  // For now only a single replica is supported.
  static FT_Naming::ReplicationManager_var peer_replica_;

  PortableServer::POA_var repl_mgr_poa_;

  CORBA::String_var repl_mgr_name_;

  FT_Naming::ReplicationManager_var reference_;

  /// Lock used to serialize access to fault tolerant extensions
  /// to Naming Service.
  TAO_SYNCH_MUTEX lock_;

};
#include /**/ "ace/post.h"

#endif /* TAO_FT_NAMING_REPLICATION_MANAGER_H */
