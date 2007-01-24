// -*- C++ -*-

//=============================================================================
/**
 *  @file   NotifyLog_i.h
 *
 *  $Id$
 *
 *  Implementation of the DsNotifyLogAdmin::NotifyLog interface.
 *  File also conatins TAO_Notify_LogConsumer which is used
 *  to write events to the Log.
 *
 *  @author David A. Hanvey <d.hanvey@qub.ac.uk>
 */
//=============================================================================

#ifndef TAO_TLS_NOTIFYLOG_I_H
#define TAO_TLS_NOTIFYLOG_I_H

#include /**/ "ace/pre.h"

#include "orbsvcs/DsLogAdminS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/DsNotifyLogAdminS.h"
#include "orbsvcs/Log/Log_i.h"
#include "orbsvcs/Log/NotifyLogConsumer.h"

#include "orbsvcs/Log/notifylog_serv_export.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_LogMgr_i;
class TAO_NotifyLog_i;
class TAO_NotifyLogFactory_i;

/**
 * @class TAO_NotifyLog_i
 *
 * @brief The NotifyLog is an EventChannel and a Log.
 *
 * It is used to log events that pass through the EventChannel.
 * The class supports the @c destroy> method to destroy the Log.
 */
class TAO_NotifyLog_Serv_Export TAO_NotifyLog_i :
  public TAO_Log_i,
  public POA_DsNotifyLogAdmin::NotifyLog
{
public:
  // = Initialization and Termination.

  /// Constructor.
  TAO_NotifyLog_i (CORBA::ORB_ptr orb,
		   PortableServer::POA_ptr poa,
                   TAO_LogMgr_i &logmgr_i,
                   DsLogAdmin::LogMgr_ptr factory,
                   CosNotifyChannelAdmin::EventChannelFactory_ptr ecf,
                   TAO_LogNotification *log_notifier,
                   DsLogAdmin::LogId id);

  /// Destructor.
  ~TAO_NotifyLog_i ();

  /// Duplicate the log.
  virtual DsLogAdmin::Log_ptr copy (DsLogAdmin::LogId &id ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  /// Duplicate the log specifying an id.
  virtual DsLogAdmin::Log_ptr copy_with_id (DsLogAdmin::LogId id ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  /// Destroy the log object and all contained records.
  void
  destroy (void)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Activate the NotifyLog.
  void
  activate (void);

  // = Methods from CosNotifyChannelAdmin::EventChannel.
  CosNotifyFilter::Filter_ptr
  get_filter (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void set_filter (CosNotifyFilter::Filter_ptr filter ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::EventChannelFactory_ptr
  MyFactory (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::ConsumerAdmin_ptr
  default_consumer_admin (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::SupplierAdmin_ptr
  default_supplier_admin (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotifyFilter::FilterFactory_ptr
  default_filter_factory (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::ConsumerAdmin_ptr
  new_for_consumers (CosNotifyChannelAdmin::InterFilterGroupOperator op,
    CosNotifyChannelAdmin::AdminID& id ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::SupplierAdmin_ptr
  new_for_suppliers (CosNotifyChannelAdmin::InterFilterGroupOperator op,
    CosNotifyChannelAdmin::AdminID& id ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::ConsumerAdmin_ptr
  get_consumeradmin (CosNotifyChannelAdmin::AdminID id ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CosNotifyChannelAdmin::AdminNotFound,
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::SupplierAdmin_ptr
  get_supplieradmin (CosNotifyChannelAdmin::AdminID id ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CosNotifyChannelAdmin::AdminNotFound,
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::AdminIDSeq*
  get_all_consumeradmins (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotifyChannelAdmin::AdminIDSeq*
  get_all_supplieradmins (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosNotification::AdminProperties*
  get_admin (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void set_admin (const CosNotification::AdminProperties& admin ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CosNotification::UnsupportedAdmin,
      CORBA::SystemException
    ));

  CosNotification::QoSProperties*
  get_qos (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void set_qos (const CosNotification::QoSProperties& ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CosNotification::UnsupportedQoS,
      CORBA::SystemException
    ));

  void validate_qos (const CosNotification::QoSProperties&,
    CosNotification::NamedPropertyRangeSeq_out ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((
      CosNotification::UnsupportedQoS,
      CORBA::SystemException
    ));

  // = Methods from DsEventLogAdmin::EventLog.
  CosEventChannelAdmin::ConsumerAdmin_ptr
  for_consumers (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CosEventChannelAdmin::SupplierAdmin_ptr
  for_suppliers (void)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

private:
  /// The PushConsumer that consumes the events and stores them
  /// in the log.
  TAO_Notify_LogConsumer *my_log_consumer_;

  /// The Event Channel that the log uses.
  CosNotifyChannelAdmin::EventChannel_var event_channel_;

  /// The Event Channel ID that the log uses.
  CosNotifyChannelAdmin::ChannelID channelID_;

  /// The EventChannelFactory used to create the EventChannel above.
  CosNotifyChannelAdmin::EventChannelFactory_var notify_factory_;

  /// The ConsumerAdmin that the log uses.
  CosNotifyChannelAdmin::ConsumerAdmin_var consumer_admin_;

  PortableServer::POA_var	poa_;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* TAO_TLS_NOTIFYLOG_I_H */
