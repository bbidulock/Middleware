// -*- C++ -*-

//=============================================================================
/**
 *  @file   LogStore.h
 *
 *  $Id$
 *
 *  @author Matthew Braun <mjb2@cs.wustl.edu>
 *  @author Pradeep Gore <pradeep@cs.wustl.edu>
 *  @author David A. Hanvey <d.hanvey@qub.ac.uk>
 */
//=============================================================================

#ifndef TAO_TLS_LOGSTORE_H
#define TAO_TLS_LOGSTORE_H

#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/DsLogAdminC.h"
#include "log_serv_export.h"

class TAO_LogRecordStore;

class TAO_Log_Serv_Export TAO_LogStore
{
public:
  /// Lists all logs created by the log factory.
  virtual DsLogAdmin::LogList *
    list_logs (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ))					= 0;

  /// Lists all log ids.
  virtual DsLogAdmin::LogIdList *
    list_logs_by_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ))					= 0;

  /// Returns a reference to the log with the supplied id.
  virtual DsLogAdmin::Log_ptr
    find_log (DsLogAdmin::LogId id
              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ))					= 0;

  /// Returns true if log exists, otherwise false
  virtual bool exists (DsLogAdmin::LogId id)		= 0;

  /// Remove the given entry from the hash table.
  virtual int remove (DsLogAdmin::LogId id)		= 0;

  /// @brief Create log
  virtual void
    create (DsLogAdmin::LogFullActionType full_action,
	    CORBA::ULongLong max_size,
	    const DsLogAdmin::CapacityAlarmThresholdList* thresholds,
	    DsLogAdmin::LogId_out id_out
	    ACE_ENV_ARG_DECL)				= 0;

  /// @brief Create log
  virtual void 
    create_with_id (DsLogAdmin::LogId id,
		    DsLogAdmin::LogFullActionType full_action,
		    CORBA::ULongLong max_size,
		    const DsLogAdmin::CapacityAlarmThresholdList* thresholds
		    ACE_ENV_ARG_DECL)			= 0;

  /// @brief Get log record store 
  ///
  /// Get/Create a log record store for log channel @a id.
  ///
  /// @param id log id
  ///
  virtual TAO_LogRecordStore*
    get_log_record_store (DsLogAdmin::LogId id
		          ACE_ENV_ARG_DECL)		= 0;
private:
};

#include /**/ "ace/post.h"

#endif /* TAO_TLS_LOGSTORE_H */
