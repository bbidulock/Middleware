/* -*- C++ -*- */
// $Id$
// ==========================================================================
//
// = LIBRARY
//   orbsvcs
//
// = FILENAME
//   Notify_EventChannel_i.h
//
// = DESCRIPTION
//
//
// = AUTHOR
//    Pradeep Gore <pradeep@cs.wustl.edu>
//
// ==========================================================================

#ifndef NOTIFY_EVENTCHANNEL_I_H_
#define NOTIFY_EVENTCHANNEL_I_H_

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Hash_Map_Manager.h"
#include "orbsvcs/orbsvcs/CosNotifyChannelAdminS.h"
#include "orbsvcs/orbsvcs/Notify/Notify_QoSAdmin_i.h"
#include "orbsvcs/orbsvcs/Notify/ID_Pool_T.h"

#include "ace/Auto_Ptr.h"
#include "Notify_Dispatcher.h"

class TAO_Notify_EventChannelFactory_i;
class TAO_Notify_ConsumerAdmin_i;
class TAO_Notify_SupplierAdmin_i;

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class TAO_ORBSVCS_Export TAO_Notify_EventChannel_i :
public virtual POA_CosNotifyChannelAdmin::EventChannel,
public virtual TAO_Notify_QoSAdmin_i
{
  // = TITLE
  //   TAO_Notify_EventChannel_i
  // = DESCRIPTION
  //
  //
 public:
  TAO_Notify_EventChannel_i (TAO_Notify_EventChannelFactory_i& my_factory);
  // Constructor

  virtual ~TAO_Notify_EventChannel_i (void);
  // Destructor

  void init (const CosNotification::QoSProperties& initial_qos,
             const CosNotification::AdminProperties& initial_admin,
             CORBA::Environment &ACE_TRY_ENV);
  //

  TAO_Notify_Dispatcher& get_dispatcher (void);
  //

  CosNotifyChannelAdmin::EventChannel_ptr
  get_ref (CORBA::Environment &ACE_TRY_ENV);
  // Activate with the default POA

  // = EventChannel methods.
  virtual CosNotifyChannelAdmin::EventChannelFactory_ptr MyFactory (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual CosNotifyChannelAdmin::ConsumerAdmin_ptr default_consumer_admin (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual CosNotifyChannelAdmin::SupplierAdmin_ptr default_supplier_admin (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual CosNotifyFilter::FilterFactory_ptr default_filter_factory (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual CosNotifyChannelAdmin::ConsumerAdmin_ptr new_for_consumers (
    CosNotifyChannelAdmin::InterFilterGroupOperator op,
    CosNotifyChannelAdmin::AdminID_out id,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual CosNotifyChannelAdmin::SupplierAdmin_ptr new_for_suppliers (
    CosNotifyChannelAdmin::InterFilterGroupOperator op,
    CosNotifyChannelAdmin::AdminID_out id,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual CosNotifyChannelAdmin::ConsumerAdmin_ptr get_consumeradmin (
    CosNotifyChannelAdmin::AdminID id,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CosNotifyChannelAdmin::AdminNotFound
  ));

virtual CosNotifyChannelAdmin::SupplierAdmin_ptr get_supplieradmin (
    CosNotifyChannelAdmin::AdminID id,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CosNotifyChannelAdmin::AdminNotFound
  ));

virtual CosNotifyChannelAdmin::AdminIDSeq * get_all_consumeradmins (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual CosNotifyChannelAdmin::AdminIDSeq * get_all_supplieradmins (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual CosNotification::AdminProperties * get_admin (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

virtual void set_admin (
    const CosNotification::AdminProperties & admin,
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CosNotification::UnsupportedAdmin
  ));

  virtual CosEventChannelAdmin::ConsumerAdmin_ptr for_consumers (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

  virtual CosEventChannelAdmin::SupplierAdmin_ptr for_suppliers (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

  virtual void destroy (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

 protected:
  TAO_Notify_EventChannelFactory_i& my_factory_;
  // The factory that created us.

  typedef ID_Pool<CosNotifyChannelAdmin::AdminID> IDGEN;

  IDGEN consumer_admin_ids;
  // Id generator for consumer admins.

  IDGEN supplier_admin_ids;
  // Id generator for supplier admins.

  typedef
  ACE_Hash_Map_Manager <CosNotifyChannelAdmin::AdminID,
                                               TAO_Notify_ConsumerAdmin_i*,
                                               ACE_SYNCH_MUTEX>
  CONSUMERADMIN_MAP;

  CONSUMERADMIN_MAP consumer_admin_map_;
  //

  typedef
  ACE_Hash_Map_Manager <CosNotifyChannelAdmin::AdminID,
                                               TAO_Notify_SupplierAdmin_i*,
                                               ACE_SYNCH_MUTEX>
  SUPPLIERADMIN_MAP;

  SUPPLIERADMIN_MAP supplier_admin_map_;
  //

  TAO_Notify_Dispatcher *dispatcher_;
  //

  CosNotifyFilter::FilterFactory_var filter_factory_;
  // The default filter factory

  CosNotifyChannelAdmin::ConsumerAdmin_var default_consumeradmin_;
  // The default Consumer Admin

  CosNotifyChannelAdmin::SupplierAdmin_var default_supplieradmin_;
  // The default Supplier Admin

  const CosNotifyChannelAdmin::InterFilterGroupOperator default_op_;
  // Default InterFilterGroupOperator operator used when creating
  // the default ConsumerAdmin and SupplierAdmin.

  const CosNotifyChannelAdmin::AdminID default_id_;
  // Default id's to CosEventChannelAdmin::ConsumerAdmin, SupplierAdmin.

  // = Admin. properties
  CORBA::Long max_queue_length_;
  // The maximum number of events that will be queued by the channel before
  // the channel begins discarding events or rejecting new events upon
  // receipt of each new event.

  CORBA::Long max_consumers_;
  // The maximum number of consumers that can be connected to the channel at
  // any given time.

  CORBA::Long max_suppliers_;
  // The maximum number of suppliers that can be connected to the channel at
  // any given time.

};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* NOTIFY_EVENTCHANNEL_I_H_ */
