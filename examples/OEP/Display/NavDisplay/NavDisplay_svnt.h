// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.cs.wustl.edu/~nanbor/projects/CIAO-src/docs/index.html

#ifndef CIAO_GLUE_SESSION_NAVDISPLAY_SVNT_H
#define CIAO_GLUE_SESSION_NAVDISPLAY_SVNT_H
#include "ace/pre.h"

#include "NavDisplayS.h"
#include "NavDisplayEC.h"

#include "ciao/Container_Base.h"
#include "tao/LocalObject.h"
#include "tao/PortableServer/Key_Adapters.h"
#include "ace/Active_Map_Manager_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace CIAO_GLUE_HUDisplay
{
  class NAVDISPLAY_SVNT_Export NavDisplay_Context
  : public virtual ::HUDisplay::CCM_NavDisplay_Context,
  public virtual TAO_Local_RefCounted_Object
  {
    public:
    // We will allow the servant glue code we generate to access our state.
    friend class NavDisplay_Servant;

    NavDisplay_Context (
    ::Components::CCMHome_ptr home,
    ::CIAO::Session_Container *c,
    NavDisplay_Servant *sv);

    virtual ~NavDisplay_Context (void);

    // Operations from ::Components::CCMContext.

    virtual ::Components::Principal_ptr
    get_caller_principal (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::CCMHome_ptr
    get_CCM_home (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual CORBA::Boolean
    get_rollback_only (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState));

    virtual ::Components::Transaction::UserTransaction_ptr
    get_user_transaction (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState));

    virtual CORBA::Boolean
    is_caller_in_role (
    const char *role
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void
    set_rollback_only (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState));

    // Operations from ::Components::SessionContext interface.

    virtual CORBA::Object_ptr
    get_CCM_object (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::IllegalState));

    // Operations for NavDisplay receptacles and event sources,
    // defined in ::HUDisplay::CCM_NavDisplay_Context.

    virtual ::HUDisplay::position_ptr
    get_connection_GPSLocation (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    protected:
    // Methods that manage this component's connections and consumers.

    virtual void
    connect_GPSLocation (
    ::HUDisplay::position_ptr
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::AlreadyConnected,
    ::Components::InvalidConnection));

    virtual ::HUDisplay::position_ptr
    disconnect_GPSLocation (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::NoConnection));

    protected:
    // Simplex GPSLocation connection.
    ::HUDisplay::position_var
    ciao_uses_GPSLocation_;

    ::Components::CCMHome_var
    home_;

    ::CIAO::Session_Container *
    container_;

    NavDisplay_Servant *
    servant_;

    ::HUDisplay::NavDisplay_var
    component_;
  };

  class NAVDISPLAY_SVNT_Export NavDisplay_Servant
  : public virtual POA_HUDisplay::NavDisplay,
  public virtual PortableServer::RefCountServantBase
  {
    public:
    NavDisplay_Servant (
    ::HUDisplay::CCM_NavDisplay_ptr executor,
    ::Components::CCMHome_ptr home,
    ::CIAO::Session_Container *c);

    virtual ~NavDisplay_Servant (void);

    // Servant class for the Refresh consumer.
    class NAVDISPLAY_SVNT_Export tickConsumer_Refresh_Servant
    : public virtual POA_HUDisplay::tickConsumer,
    public virtual PortableServer::RefCountServantBase
    {
      public:
      tickConsumer_Refresh_Servant (
      ::HUDisplay::CCM_NavDisplay_ptr executor,
      ::HUDisplay::CCM_NavDisplay_Context_ptr c);

      virtual ~tickConsumer_Refresh_Servant (void);

      virtual void
      push_tick (
      ::HUDisplay::tick *evt
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Inherited from ::Components::EventConsumerBase.
      virtual void
      push_event (::Components::EventBase *ev
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::BadEventType));

      // Get component implementation.
      virtual CORBA::Object_ptr
      _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      protected:
      ::HUDisplay::CCM_NavDisplay_var
      executor_;

      ::HUDisplay::CCM_NavDisplay_Context_var
      ctx_;
    };

    virtual ::HUDisplay::tickConsumer_ptr
    get_consumer_Refresh (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void
    connect_GPSLocation (
    ::HUDisplay::position_ptr c
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::AlreadyConnected,
    ::Components::InvalidConnection));

    virtual ::HUDisplay::position_ptr
    disconnect_GPSLocation (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::HUDisplay::position_ptr
    get_connection_GPSLocation (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    // Operations for Navigation interface.

    virtual CORBA::Object_ptr
    provide_facet (
    const char *name
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName));

    virtual ::Components::FacetDescriptions *
    get_all_facets (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::FacetDescriptions *
    get_named_facets (
    const ::Components::NameList &names
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName));

    virtual CORBA::Boolean
    same_component (
    CORBA::Object_ptr object_ref
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    // Operations for Receptacles interface.

    virtual ::Components::Cookie *
    connect (
    const char *name,
    CORBA::Object_ptr connection
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::InvalidConnection,
    ::Components::AlreadyConnected,
    ::Components::ExceededConnectionLimit));

    virtual CORBA::Object_ptr
    disconnect (
    const char *name,
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::InvalidConnection,
    ::Components::CookieRequired,
    ::Components::NoConnection));

    virtual ::Components::ConnectionDescriptions *
    get_connections (
    const char *name
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName));

    virtual ::Components::ReceptacleDescriptions *
    get_all_receptacles (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::ReceptacleDescriptions *
    get_named_receptacles (
    const ::Components::NameList &names
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName));

    // Operations for Events interface.

    virtual ::Components::EventConsumerBase_ptr
    get_consumer (
    const char *sink_name
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName));

    virtual ::Components::Cookie *
    subscribe (
    const char *publisher_name,
    ::Components::EventConsumerBase_ptr subscriber
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::InvalidConnection,
    ::Components::ExceededConnectionLimit));

    virtual ::Components::EventConsumerBase_ptr
    unsubscribe (
    const char *publisher_name,
    ::Components::Cookie *ck
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::InvalidConnection));

    virtual void
    connect_consumer (
    const char *emitter_name,
    ::Components::EventConsumerBase_ptr consumer
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::AlreadyConnected,
    ::Components::InvalidConnection));

    virtual ::Components::EventConsumerBase_ptr
    disconnect_consumer (
    const char *source_name
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName,
    ::Components::NoConnection));

    virtual ::Components::ConsumerDescriptions *
    get_all_consumers (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::ConsumerDescriptions *
    get_named_consumers (
    const ::Components::NameList &names
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName));

    virtual ::Components::EmitterDescriptions *
    get_all_emitters (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::EmitterDescriptions *
    get_named_emitters(
    const ::Components::NameList &names
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName));

    virtual ::Components::PublisherDescriptions *
    get_all_publishers (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::PublisherDescriptions *
    get_named_publishers(
    const ::Components::NameList &names
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidName));

    // Operations for CCMObject interface.

    virtual CORBA::IRObject_ptr
    get_component_def (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::CCMHome_ptr
    get_ccm_home (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::Components::PrimaryKeyBase *
    get_primary_key (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::NoKeyAvailable));

    virtual void
    configuration_complete (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::InvalidConfiguration));

    virtual void
    remove (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::RemoveFailure));

    virtual ::Components::ComponentPortDescription *
    get_all_ports(
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    // CIAO-specific operations.

    void
    _ciao_activate (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    void
    _ciao_passivate (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    protected:
    ::HUDisplay::CCM_NavDisplay_var
    executor_;

    NavDisplay_Context *
    context_;

    ::CIAO::Session_Container *
    container_;

    ::HUDisplay::tickConsumer_var
    consumes_Refresh_;

  };

  class NAVDISPLAY_SVNT_Export NavDisplayHome_Servant
  : public virtual POA_HUDisplay::NavDisplayHome,
  public virtual PortableServer::RefCountServantBase
  {
    public:
    NavDisplayHome_Servant (
    ::HUDisplay::CCM_NavDisplayHome_ptr exe,
    ::CIAO::Session_Container *c);

    virtual ~NavDisplayHome_Servant (void);

    // Home factory and other operations.

    // Operations for keyless home interface.

    virtual ::Components::CCMObject_ptr
    create_component (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::CreateFailure));

    // Operations for implicit home interface.

    virtual ::HUDisplay::NavDisplay_ptr
    create (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::CreateFailure));

    // Operations for CCMHome interface.

    virtual ::CORBA::IRObject_ptr
    get_component_def (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual ::CORBA::IRObject_ptr
    get_home_def (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    virtual void
    remove_component (
    ::Components::CCMObject_ptr comp
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
    ::CORBA::SystemException,
    ::Components::RemoveFailure));

    // Supported operations.

    protected:
    // CIAO-specific operations.

    ::HUDisplay::NavDisplay_ptr
    _ciao_activate_component (
    ::HUDisplay::CCM_NavDisplay_ptr exe
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    void
    _ciao_passivate_component (
    ::HUDisplay::NavDisplay_ptr comp
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

    protected:
    ::HUDisplay::CCM_NavDisplayHome_var
    executor_;

    ::CIAO::Session_Container *
    container_;

    ACE_Hash_Map_Manager_Ex<
    PortableServer::ObjectId,
    NavDisplay_Servant *,
    TAO_ObjectId_Hash,
    ACE_Equal_To<PortableServer::ObjectId>,
    ACE_SYNCH_MUTEX>
    component_map_;
  };

  extern "C" NAVDISPLAY_SVNT_Export ::PortableServer::Servant
  createNavDisplayHome_Servant (
  ::Components::HomeExecutorBase_ptr p,
  CIAO::Session_Container *c
  ACE_ENV_ARG_DECL_WITH_DEFAULTS);

}

#include "ace/post.h"
#endif /* CIAO_GLUE_SESSION_NAVDISPLAY_SVNT_H */

