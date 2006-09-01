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

#ifndef CIAO_GLUE_SESSION_RECEIVER_SVNT_H
#define CIAO_GLUE_SESSION_RECEIVER_SVNT_H

#include /**/ "ace/pre.h"

#include "ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "ReceiverS.h"

namespace CIDL_Receiver_Impl
{
  class Receiver_Servant;

  class RECEIVER_SVNT_Export Receiver_Context
    : public virtual CIAO::Context_Impl<
        ::Hello::CCM_Receiver_Context,
        Receiver_Servant,
        ::Hello::Receiver,
        ::Hello::Receiver_var
      >
  {
    public:
    // We will allow the servant glue code we generate to access our state.
    friend class Receiver_Servant;

    Receiver_Context (
      ::Components::CCMHome_ptr h,
      ::CIAO::Session_Container *c,
      Receiver_Servant *sv);

    virtual ~Receiver_Context (void);

    // Operations for Receiver receptacles and event sources,
    // defined in ::Hello::CCM_Receiver_Context.

    virtual ::Hello::ReadMessage_ptr
    get_connection_read_message (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // CIAO-specific.

    static Receiver_Context *
    _narrow (
      ::Components::SessionContext_ptr p
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    protected:
    // Methods that manage this component's connections and consumers.

    virtual void
    connect_read_message (
      ::Hello::ReadMessage_ptr
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::AlreadyConnected,
                     ::Components::InvalidConnection));

    virtual ::Hello::ReadMessage_ptr
    disconnect_read_message (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::NoConnection));

    protected:
    // Simplex read_message connection.
    ::Hello::ReadMessage_var
    ciao_uses_read_message_;
  };

  class RECEIVER_SVNT_Export Receiver_Servant
    : public virtual CIAO::Servant_Impl<
        POA_Hello::Receiver,
        ::Hello::CCM_Receiver,
        Receiver_Context
      >
  {
    public:

    typedef ::Hello::CCM_Receiver _exec_type;

    Receiver_Servant (
      ::Hello::CCM_Receiver_ptr executor,
      ::Components::CCMHome_ptr h,
      const char *ins_name,
      ::CIAO::Home_Servant_Impl_Base *hs,
      ::CIAO::Session_Container *c,
      ::CIAO::REC_POL_MAP &rec_pol_map);

    virtual ~Receiver_Servant (void);

    virtual void
    set_attributes (
      const ::Components::ConfigValues &descr
      ACE_ENV_ARG_DECL);

    // Supported operations.

    // Public port operations.

    virtual void
    connect_read_message (
      ::Hello::ReadMessage_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::AlreadyConnected,
                     ::Components::InvalidConnection));

    virtual ::Hello::ReadMessage_ptr
    disconnect_read_message (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::NoConnection));

    virtual ::Hello::ReadMessage_ptr
    get_connection_read_message (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Servant class for the click_in consumer.
    class RECEIVER_SVNT_Export TimeOutConsumer_click_in_Servant
    : public virtual POA_Hello::TimeOutConsumer
    {
      public:
      TimeOutConsumer_click_in_Servant (
        ::Hello::CCM_Receiver_ptr executor,
        ::Hello::CCM_Receiver_Context_ptr c);

      virtual ~TimeOutConsumer_click_in_Servant (void);

      virtual void
      push_TimeOut (
        ::Hello::TimeOut *evt
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
      ::Hello::CCM_Receiver_var
      executor_;

      ::Hello::CCM_Receiver_Context_var
      ctx_;
    };

    virtual ::Hello::TimeOutConsumer_ptr
    get_consumer_click_in (
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

    ::Hello::TimeOutConsumer_var
    consumes_click_in_;

    const char *ins_name_;

    private:

    void
    populate_port_tables (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    ::Components::EventConsumerBase_ptr
    get_consumer_click_in_i (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));
  };

  class RECEIVER_SVNT_Export ReceiverHome_Servant
    : public virtual
        ::CIAO::Home_Servant_Impl<
            ::POA_Hello::ReceiverHome,
            ::Hello::CCM_ReceiverHome,
            Receiver_Servant
          >
  {
    public:

    ReceiverHome_Servant (
      ::Hello::CCM_ReceiverHome_ptr exe,
      const char *ins_name,
      ::CIAO::Session_Container *c,
      ::CIAO::REC_POL_MAP &rec_pol_map);

    virtual ~ReceiverHome_Servant (void);

    // Home operations.
    // Home factory and finder operations.

    // Attribute operations.
  };

  extern "C" RECEIVER_SVNT_Export ::PortableServer::Servant
  create_Hello_ReceiverHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    CIAO::Session_Container *c,
    const char *ins_name,
    CIAO::REC_POL_MAP &rec_pol_map
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_RECEIVER_SVNT_H */

