/* -*- C++ -*- */

//=============================================================================
/**
 *  @file   Hash_LogStore.h
 *
 *  $Id$
 *
 *  @author Matthew Braun <mjb2@cs.wustl.edu>
 *  @author Pradeep Gore <pradeep@cs.wustl.edu>
 *  @David A. Hanvey <d.hanvey@qub.ac.uk>
 */
//=============================================================================

#ifndef TAO_TLS_HASH_LOGSTORE_H
#define TAO_TLS_HASH_LOGSTORE_H

#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/Log/LogStore.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/RW_Thread_Mutex.h"
#include "log_serv_export.h"

class ACE_Reactor;
class TAO_LogMgr_i;
class TAO_Hash_LogRecordStore;

class TAO_Log_Serv_Export TAO_Hash_LogStore
  : public TAO_LogStore
{
public:
  // = Initialization and Termination Methods

  /// Constructor.
  TAO_Hash_LogStore (CORBA::ORB_ptr orb, TAO_LogMgr_i* mgr);

  /// Destructor.
  virtual ~TAO_Hash_LogStore ();


  /// Lists all logs created by the log factory.
  virtual DsLogAdmin::LogList *
    list_logs (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));

  /// Lists all log ids.
  virtual DsLogAdmin::LogIdList *
    list_logs_by_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));

  /// Returns a reference to the log with the supplied id.
  virtual DsLogAdmin::Log_ptr
    find_log (DsLogAdmin::LogId id
              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));

  /// Returns true if log exists, otherwise false
  virtual bool exists (DsLogAdmin::LogId id);

  /// Remove the given entry from the hash table.
  virtual int remove (DsLogAdmin::LogId id);

  /// @brief Create log
  virtual void
    create (DsLogAdmin::LogFullActionType full_action,
            CORBA::ULongLong max_size,
            const DsLogAdmin::CapacityAlarmThresholdList* thresholds,
            DsLogAdmin::LogId_out id_out
            ACE_ENV_ARG_DECL);

  /// @brief Create log
  virtual void
    create_with_id (DsLogAdmin::LogId id,
                    DsLogAdmin::LogFullActionType full_action,
                    CORBA::ULongLong max_size,
                    const DsLogAdmin::CapacityAlarmThresholdList* thresholds
                    ACE_ENV_ARG_DECL);

  /// @brief Get log record store
  ///
  /// Get/Create a log record store for log channel @a id.
  ///
  /// @param id log id
  ///
  virtual TAO_LogRecordStore*
    get_log_record_store (DsLogAdmin::LogId id
                          ACE_ENV_ARG_DECL);

private:
  ACE_RW_Thread_Mutex lock_;

  /// Define the HASHMAP.
  typedef ACE_Hash_Map_Manager <DsLogAdmin::LogId,
                                TAO_Hash_LogRecordStore*,
                                ACE_Null_Mutex> HASHMAP;

  /// The map of Logs created.
  HASHMAP hash_map_;

  /// The next log id to be assigned (if it hasn't already been
  /// taken by create_with_id().
  DsLogAdmin::LogId     next_id_;

  CORBA::ORB_var        orb_;

  TAO_LogMgr_i*         mgr_;
};

#include /**/ "ace/post.h"

#endif /* TAO_TLS_HASH_LOGSTORE_H */
