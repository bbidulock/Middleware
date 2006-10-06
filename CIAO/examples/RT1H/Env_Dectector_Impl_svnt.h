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
//    http://www.dre.vanderbilt.edu/CIAO

#ifndef CIAO_GLUE_SESSION_ENV_DECTECTOR_IMPL_SVNT_H
#define CIAO_GLUE_SESSION_ENV_DECTECTOR_IMPL_SVNT_H

#include /**/ "ace/pre.h"

#include "Env_Dectector_ImplEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "Env_DetectorS.h"

namespace CIDL_MonolithicImplementation
{
  class Env_Detector_Servant;

  class ENV_DECTECTOR_IMPL_SVNT_Export Env_Detector_Context
    : public virtual CIAO::Context_Impl<
        ::TSCE::CCM_Env_Detector_Context,
        Env_Detector_Servant,
        ::TSCE::Env_Detector,
        ::TSCE::Env_Detector_var
      >
  {
    public:
    // We will allow the servant glue code we generate to access our state.
    friend class Env_Detector_Servant;

    Env_Detector_Context (
      ::Components::CCMHome_ptr h,
      ::CIAO::Session_Container *c,
      Env_Detector_Servant *sv);

    virtual ~Env_Detector_Context (void);

    // Operations for Env_Detector receptacles and event sources,
    // defined in ::TSCE::CCM_Env_Detector_Context.

    virtual void
    push_track (
      ::TSCE::Track_Event *ev
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    virtual ::CUTS::Testing_Service_ptr
    get_connection_cuts_testing_service (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // CIAO-specific.

    static Env_Detector_Context *
    _narrow (
      ::Components::SessionContext_ptr p
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    protected:
    // Methods that manage this component's connections and consumers.

    virtual ::Components::Cookie *
    subscribe_track (
      ::TSCE::Track_EventConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::ExceededConnectionLimit));

    // CIAO-specific.
    ::Components::Cookie *
    subscribe_track_generic (
      ::Components::EventConsumerBase_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::ExceededConnectionLimit));

    virtual ::TSCE::Track_EventConsumer_ptr
    unsubscribe_track (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidConnection));

    virtual void
    connect_cuts_testing_service (
      ::CUTS::Testing_Service_ptr
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::AlreadyConnected,
                     ::Components::InvalidConnection));

    virtual ::CUTS::Testing_Service_ptr
    disconnect_cuts_testing_service (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::NoConnection));

    protected:
    ACE_Active_Map_Manager<
    ::TSCE::Track_EventConsumer_var>
    ciao_publishes_track_map_;

    ACE_Active_Map_Manager<
    ::Components::EventConsumerBase_var>
    ciao_publishes_track_generic_map_;

    // Simplex cuts_testing_service connection.
    ::CUTS::Testing_Service_var
    ciao_uses_cuts_testing_service_;
  };

  class ENV_DECTECTOR_IMPL_SVNT_Export Env_Detector_Servant
    : public virtual CIAO::Servant_Impl<
        POA_TSCE::Env_Detector,
        ::TSCE::CCM_Env_Detector,
        Env_Detector_Context
      >
  {
    public:

    typedef ::TSCE::CCM_Env_Detector _exec_type;

    Env_Detector_Servant (
      ::TSCE::CCM_Env_Detector_ptr executor,
      ::Components::CCMHome_ptr h,
      const char *ins_name,
      ::CIAO::Home_Servant_Impl_Base *hs,
      ::CIAO::Session_Container *c,
      ::CIAO::REC_POL_MAP &rec_pol_map);

    virtual ~Env_Detector_Servant (void);

    virtual void
    set_attributes (
      const ::Components::ConfigValues &descr
      ACE_ENV_ARG_DECL);

    // Supported operations.

    // Public port operations.

    // Servant class for the command consumer.
    class ENV_DECTECTOR_IMPL_SVNT_Export Command_EventConsumer_command_Servant
    : public virtual POA_TSCE::Command_EventConsumer
    {
      public:
      Command_EventConsumer_command_Servant (
        ::TSCE::CCM_Env_Detector_ptr executor,
        ::TSCE::CCM_Env_Detector_Context_ptr c);

      virtual ~Command_EventConsumer_command_Servant (void);

      virtual void
      push_Command_Event (
        ::TSCE::Command_Event *evt
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      // Inherited from ::Components::EventConsumerBase.
      virtual void
      push_event ( ::Components::EventBase *ev
                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::BadEventType));

      // CIAO-specific in ::Components::EventConsumerBase.
      virtual CORBA::Boolean
      ciao_is_substitutable (
        const char *event_repo_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      // Get component implementation.
      virtual CORBA::Object_ptr
      _get_component (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      protected:
      ::TSCE::CCM_Env_Detector_var
      executor_;

      ::TSCE::CCM_Env_Detector_Context_var
      ctx_;
    };

    virtual ::TSCE::Command_EventConsumer_ptr
    get_consumer_command (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    virtual ::Components::Cookie *
    subscribe_track (
      ::TSCE::Track_EventConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::ExceededConnectionLimit));

    // CIAO-specific.
    ::Components::Cookie *
    subscribe_track_generic (
      ::Components::EventConsumerBase_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::ExceededConnectionLimit));

    virtual ::TSCE::Track_EventConsumer_ptr
    unsubscribe_track (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidConnection));

    virtual void
    connect_cuts_testing_service (
      ::CUTS::Testing_Service_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::AlreadyConnected,
                     ::Components::InvalidConnection));

    virtual ::CUTS::Testing_Service_ptr
    disconnect_cuts_testing_service (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::NoConnection));

    virtual ::CUTS::Testing_Service_ptr
    get_connection_cuts_testing_service (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Component attribute operations.

    // Operations for Receptacles interface.

    virtual ::Components::Cookie *
    connect (
      const char *name,
      CORBA::Object_ptr connection
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidName,
                     ::Components::InvalidConnection,
                     ::Components::AlreadyConnected,
                     ::Components::ExceededConnectionLimit));

    virtual CORBA::Object_ptr
    disconnect (
      const char *name,
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidName,
                     ::Components::InvalidConnection,
                     ::Components::CookieRequired,
                     ::Components::NoConnection));

    virtual ::Components::ReceptacleDescriptions *
    get_all_receptacles (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Operations for Events interface.

    virtual ::Components::Cookie *
    subscribe (
      const char *publisher_name,
      ::Components::EventConsumerBase_ptr subscriber
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidName,
                     ::Components::InvalidConnection,
                     ::Components::ExceededConnectionLimit));

    virtual ::Components::EventConsumerBase_ptr
    unsubscribe (
      const char *publisher_name,
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidName,
                     ::Components::InvalidConnection));

    virtual void
    connect_consumer (
      const char *emitter_name,
      ::Components::EventConsumerBase_ptr consumer
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidName,
                     ::Components::AlreadyConnected,
                     ::Components::InvalidConnection));

    virtual ::Components::EventConsumerBase_ptr
    disconnect_consumer (
      const char *source_name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidName,
                     ::Components::NoConnection));

    virtual ::Components::PublisherDescriptions *
    get_all_publishers (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    virtual ::Components::EmitterDescriptions *
    get_all_emitters (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // CIAO specific operations on the servant. 
    CORBA::Object_ptr
    get_facet_executor (
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    private:

    ::TSCE::Command_EventConsumer_var
    consumes_command_;

    const char *ins_name_;

    private:

    void
    populate_port_tables (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    ::Components::EventConsumerBase_ptr
    get_consumer_command_i (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));
  };

  class ENV_DECTECTOR_IMPL_SVNT_Export Env_Detector_Factory_Servant
    : public virtual
        ::CIAO::Home_Servant_Impl<
            ::POA_TSCE::Env_Detector_Factory,
            ::TSCE::CCM_Env_Detector_Factory,
            Env_Detector_Servant
          >
  {
    public:

    Env_Detector_Factory_Servant (
      ::TSCE::CCM_Env_Detector_Factory_ptr exe,
      const char *ins_name,
      ::CIAO::Session_Container *c,
      ::CIAO::REC_POL_MAP &rec_pol_map);

    virtual ~Env_Detector_Factory_Servant (void);

    // Home operations.
    // Home factory and finder operations.

    // Attribute operations.
  };

  extern "C" ENV_DECTECTOR_IMPL_SVNT_Export ::PortableServer::Servant
  create_TSCE_Env_Detector_Factory_Servant (
    ::Components::HomeExecutorBase_ptr p,
    CIAO::Session_Container *c,
    const char *ins_name,
    ::CIAO::REC_POL_MAP &rec_pol_map
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_ENV_DECTECTOR_IMPL_SVNT_H */

