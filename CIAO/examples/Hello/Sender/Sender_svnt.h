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

#ifndef CIAO_GLUE_SESSION_SENDER_SVNT_H
#define CIAO_GLUE_SESSION_SENDER_SVNT_H

#include /**/ "ace/pre.h"

#include "SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "SenderS.h"

namespace CIAO_FACET_Hello
{
  template <typename T>
  class ReadMessage_Servant_T
  : public virtual POA_Hello::ReadMessage
  {
    public:
    ReadMessage_Servant_T (
      ::Hello::CCM_ReadMessage_ptr executor,
      ::Components::CCMContext_ptr ctx);

    virtual ~ReadMessage_Servant_T (void);

    virtual char *
    get_message (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    protected:
    // Facet executor.
    ::Hello::CCM_ReadMessage_var executor_;

    // Context object.
    ::Components::CCMContext_var ctx_;
  };

  typedef ReadMessage_Servant_T<int> ReadMessage_Servant;
}

namespace CIDL_Sender_Impl
{
  class Sender_Servant;

  class SENDER_SVNT_Export Sender_Context
    : public virtual CIAO::Context_Impl<
        ::Hello::CCM_Sender_Context,
        Sender_Servant,
        ::Hello::Sender,
        ::Hello::Sender_var
      >
  {
    public:
    // We will allow the servant glue code we generate to access our state.
    friend class Sender_Servant;

    Sender_Context (
      ::Components::CCMHome_ptr h,
      ::CIAO::Session_Container *c,
      Sender_Servant *sv);

    virtual ~Sender_Context (void);

    // Operations for Sender receptacles and event sources,
    // defined in ::Hello::CCM_Sender_Context.

    virtual void
    push_click_out (
      ::Hello::TimeOut *ev
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // CIAO-specific.

    static Sender_Context *
    _narrow (
      ::Components::SessionContext_ptr p
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    protected:
    // Methods that manage this component's connections and consumers.

    virtual ::Components::Cookie *
    subscribe_click_out (
      ::Hello::TimeOutConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::ExceededConnectionLimit));

    // CIAO-specific.
    ::Components::Cookie *
    subscribe_click_out_generic (
      ::Components::EventConsumerBase_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::ExceededConnectionLimit));

    virtual ::Hello::TimeOutConsumer_ptr
    unsubscribe_click_out (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidConnection));

    protected:
    ACE_Active_Map_Manager<
    ::Hello::TimeOutConsumer_var>
    ciao_publishes_click_out_map_;

    ACE_Active_Map_Manager<
    ::Components::EventConsumerBase_var>
    ciao_publishes_click_out_generic_map_;
  };

  class SENDER_SVNT_Export Sender_Servant
    : public virtual CIAO::Servant_Impl<
        POA_Hello::Sender,
        ::Hello::CCM_Sender,
        Sender_Context
      >
  {
    public:

    typedef ::Hello::CCM_Sender _exec_type;

    Sender_Servant (
      ::Hello::CCM_Sender_ptr executor,
      ::Components::CCMHome_ptr h,
      const char *ins_name,
      ::CIAO::Home_Servant_Impl_Base *hs,
      ::CIAO::Session_Container *c,
      ::CIAO::REC_POL_MAP &rec_pol_map);

    virtual ~Sender_Servant (void);

    virtual void
    set_attributes (
      const ::Components::ConfigValues &descr
      ACE_ENV_ARG_DECL);

    // Supported operations.

    virtual void
    start (
      ::CORBA::Long payload,
      ::CORBA::Long iterations
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Public port operations.

    virtual ::Hello::ReadMessage_ptr
    provide_push_message (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    virtual ::Components::Cookie *
    subscribe_click_out (
      ::Hello::TimeOutConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::ExceededConnectionLimit));

    // CIAO-specific.
    ::Components::Cookie *
    subscribe_click_out_generic (
      ::Components::EventConsumerBase_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::ExceededConnectionLimit));

    virtual ::Hello::TimeOutConsumer_ptr
    unsubscribe_click_out (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::Components::InvalidConnection));

    // Component attribute operations.

    virtual char *
    local_message (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    void
    local_message (
      const char * local_message
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    virtual ::CORBA::Long
    hertz (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    void
    hertz (
      ::CORBA::Long hertz
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    virtual ::Hello::COLOR_SELECTION
    color (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    void
    color (
      ::Hello::COLOR_SELECTION color
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

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

    ::Hello::ReadMessage_var
    provide_push_message_;

    const char *ins_name_;

    private:

    void
    populate_port_tables (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    ::CORBA::Object_ptr
    provide_push_message_i (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));
  };

  class SENDER_SVNT_Export SenderHome_Servant
    : public virtual
        ::CIAO::Home_Servant_Impl<
            ::POA_Hello::SenderHome,
            ::Hello::CCM_SenderHome,
            Sender_Servant
          >
  {
    public:

    SenderHome_Servant (
      ::Hello::CCM_SenderHome_ptr exe,
      const char *ins_name,
      ::CIAO::Session_Container *c,
      ::CIAO::REC_POL_MAP &rec_pol_map);

    virtual ~SenderHome_Servant (void);

    // Home operations.
    // Home factory and finder operations.

    // Attribute operations.
  };

  extern "C" SENDER_SVNT_Export ::PortableServer::Servant
  create_Hello_SenderHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    CIAO::Session_Container *c,
    const char *ins_name,
    CIAO::REC_POL_MAP &rec_pol_map
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_SENDER_SVNT_H */

