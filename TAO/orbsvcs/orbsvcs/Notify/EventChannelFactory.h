/* -*- C++ -*- */
/**
 *  @file EventChannelFactory.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_EVENTCHANNELFACTORY_H
#define TAO_Notify_EVENTCHANNELFACTORY_H

#include /**/ "ace/pre.h"

#include "notify_serv_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/CosNotifyChannelAdminS.h"
#include "orbsvcs/NotifyExtS.h"
#include "Topology_Object.h"
#include "Topology_Factory.h"
#include "Reconnection_Registry.h"
//@@todo #include "Routing_Slip.h"

class TAO_Notify_EventChannel;
template <class TYPE> class TAO_Notify_Container_T;

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

/**
 * @class TAO_Notify_EventChannelFactory
 *
 * @brief Implementation of CosNotifyChannelAdmin::EventChannelFactory
 *
 */
class TAO_Notify_Serv_Export TAO_Notify_EventChannelFactory
  : public virtual POA_NotifyExt::EventChannelFactory
  , public TAO_NOTIFY::Topology_Parent

{
  friend class TAO_Notify_Builder;
//@@todo   typedef ACE_Unbounded_Set <TAO_NOTIFY::Routing_Slip_Ptr> Routing_Slip_Set;

public:
  /// Constuctor
  TAO_Notify_EventChannelFactory (void);

  /// Init the factory
  void init (PortableServer::POA_ptr poa ACE_ENV_ARG_DECL);

  /// Destructor
  virtual ~TAO_Notify_EventChannelFactory ();

  /// = ServantBase  Methods
  virtual void _add_ref (ACE_ENV_SINGLE_ARG_DECL);
  virtual void _remove_ref (ACE_ENV_SINGLE_ARG_DECL);

  /// Release this object.
  virtual void release (void);

  /// Remove <channel> from the <ec_container_>
  void remove (TAO_Notify_EventChannel* channel ACE_ENV_ARG_DECL);

  /// Accesor for the default filter factory shared by all EC's.
  virtual CosNotifyFilter::FilterFactory_ptr get_default_filter_factory (
      ACE_ENV_SINGLE_ARG_DECL
    );


  //////////////////////////
  // The following methods are for
  // unit testing and debugging

  /// Use the registered Topology_Factory to create a loader, and
  /// load the topology. If no Topology_Factory is registered
  /// then nothing will be loaded.
  void load_topology (ACE_ENV_SINGLE_ARG_DECL);

  /// Use the passed in saver factory to generate topology saver objects.
  /// Does not take ownership.
  void set_topology_factory(TAO_NOTIFY::Topology_Factory* sf);

  //-- Topology_Parent

  virtual bool is_persistent () const;

  virtual void save_persistent (TAO_NOTIFY::Topology_Saver& saver ACE_ENV_ARG_DECL);
  virtual bool change_to_parent (ACE_ENV_SINGLE_ARG_DECL);
  virtual TAO_NOTIFY::Topology_Object* load_child (const ACE_CString &type,
                                                   CORBA::Long id,
                                                   const TAO_NOTIFY::NVPList& attrs
                                                   ACE_ENV_ARG_DECL);
  virtual void reconnect (ACE_ENV_SINGLE_ARG_DECL);

  /// handle change notifications
  bool handle_change (ACE_ENV_SINGLE_ARG_DECL);

  void load_event_persistence (ACE_ENV_SINGLE_ARG_DECL);

  virtual void save_topology (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

 protected:
  typedef TAO_Notify_Container_T<TAO_Notify_EventChannel>
    TAO_Notify_EventChannel_Container;

  /// = Data Members
  /// Container for Event Channels.
  TAO_Notify_EventChannel_Container *ec_container_;

  /// The default filter factory.
  CosNotifyFilter::FilterFactory_var default_filter_factory_;

  /// = NotifyExt methods
  virtual void destroy (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));

  /// shutdown
  virtual int shutdown (ACE_ENV_SINGLE_ARG_DECL);

  virtual
  NotifyExt::ReconnectionRegistry::ReconnectionID register_callback (
      NotifyExt::ReconnectionCallback_ptr reconnection
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void unregister_callback (
      NotifyExt::ReconnectionRegistry::ReconnectionID id
      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::Boolean is_alive (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// = CosNotifyChannelAdmin Methods

  virtual ::CosNotifyChannelAdmin::EventChannel_ptr create_channel (
      const CosNotification::QoSProperties & initial_qos,
      const CosNotification::AdminProperties & initial_admin,
      CosNotifyChannelAdmin::ChannelID_out id
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException,
                     CosNotification::UnsupportedQoS,
                     CosNotification::UnsupportedAdmin));

  virtual ::CosNotifyChannelAdmin::ChannelIDSeq * get_all_channels (
      ACE_ENV_SINGLE_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual ::CosNotifyChannelAdmin::EventChannel_ptr get_event_channel (
      CosNotifyChannelAdmin::ChannelID id
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException,
                     CosNotifyChannelAdmin::ChannelNotFound));

private:
  TAO_SYNCH_MUTEX topology_save_lock_;
  /// change-in-progress detector to avoid duplicates
  short topology_save_seq_;
  TAO_NOTIFY::Topology_Factory* topology_factory_;
  TAO_NOTIFY::Reconnection_Registry reconnect_registry_;
  bool loading_topology_;

//@@todo   Routing_Slip_Set routing_slip_restart_set_;

};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__ACE_INLINE__)
#include "EventChannelFactory.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_Notify_EVENTCHANNELFACTORY_H */
