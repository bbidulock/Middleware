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

#ifndef CIAO_GLUE_SESSION_EC_SVNT_H
#define CIAO_GLUE_SESSION_EC_SVNT_H

#include /**/ "ace/pre.h"

#include "ECEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"
#include "ace/Active_Map_Manager_T.h"

#include "ECS.h"

namespace EC_Impl
{
  namespace CIAO_GLUE_BasicSP
  {
    class EC_Servant;

    class EC_SVNT_Export EC_Context
      : public virtual CIAO::Context_Impl<
          ::BasicSP::CCM_EC_Context,
          EC_Servant,
          ::BasicSP::EC,
          ::BasicSP::EC_var
        >
    {
      public:
      // We will allow the servant glue code we generate to access our state.
      friend class EC_Servant;

      /// Hack for VC6.
      typedef CIAO::Context_Impl<
          ::BasicSP::CCM_EC_Context,
          EC_Servant,
          ::BasicSP::EC,
          ::BasicSP::EC_var
        > ctx_svnt_base;

      EC_Context (
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c,
      EC_Servant *sv);

      virtual ~EC_Context (void);

      // Operations for EC receptacles and event sources,
      // defined in ::BasicSP::CCM_EC_Context.

      virtual void
      push_timeout (
      ::BasicSP::TimeOut *ev
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // CIAO-specific.

      static EC_Context *
      _narrow (
      ::Components::SessionContext_ptr p
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

      protected:
      // Methods that manage this component's connections and consumers.

      virtual ::Components::Cookie *
      subscribe_timeout (
      ::BasicSP::TimeOutConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::ExceededConnectionLimit));

      virtual ::BasicSP::TimeOutConsumer_ptr
      unsubscribe_timeout (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidConnection));

      protected:
      ACE_Active_Map_Manager<
      ::BasicSP::TimeOutConsumer_var>
      ciao_publishes_timeout_map_;
    };
  }

  namespace CIAO_GLUE_BasicSP
  {
    class EC_SVNT_Export EC_Servant
      : public virtual CIAO::Servant_Impl<
          POA_BasicSP::EC,
          ::BasicSP::CCM_EC,
          ::BasicSP::CCM_EC_var,
          EC_Context
        >
    {
      public:
      /// Hack for VC6.
      typedef CIAO::Servant_Impl<
          POA_BasicSP::EC,
          ::BasicSP::CCM_EC,
          ::BasicSP::CCM_EC_var,
          EC_Context
        > comp_svnt_base;

      EC_Servant (
      ::BasicSP::CCM_EC_ptr executor,
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c);

      virtual ~EC_Servant (void);

      virtual void
      set_attributes (
      const ::Components::ConfigValues &descr
      ACE_ENV_ARG_DECL);

      // Supported operations.
      virtual void
      component_UUID (
      const char * new_component_UUID
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CIAO::CONNECTION_ID
      component_UUID (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      start (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
      virtual void
      stop (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
      // Public port operations.

      virtual ::Components::Cookie *
      subscribe_timeout (
      ::BasicSP::TimeOutConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::ExceededConnectionLimit));

      virtual ::BasicSP::TimeOutConsumer_ptr
      unsubscribe_timeout (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidConnection));

      // Component attribute operations.

      virtual ::CORBA::Long
      hertz (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      hertz (
      ::CORBA::Long
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

      // Operations for Events interface.

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

      // CIAO specific operations on the servant 
      CORBA::Object_ptr
      get_facet_executor (const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException));

      private:
      ACE_CString component_UUID_;

      private:

      void
      populate_port_tables (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));
    };
  }

  namespace CIAO_GLUE_BasicSP
  {
    class EC_SVNT_Export ECHome_Servant
      : public virtual CIAO::Home_Servant_Impl<
          POA_BasicSP::ECHome,
          ::BasicSP::CCM_ECHome,
          ::BasicSP::CCM_ECHome_var,
          ::BasicSP::EC,
          ::BasicSP::EC_var,
          ::BasicSP::CCM_EC,
          ::BasicSP::CCM_EC_var,
          EC_Servant
        >
    {
      public:
      /// Hack for VC6.
      typedef CIAO::Home_Servant_Impl<
          POA_BasicSP::ECHome,
          ::BasicSP::CCM_ECHome,
          ::BasicSP::CCM_ECHome_var,
          ::BasicSP::EC,
          ::BasicSP::EC_var,
          ::BasicSP::CCM_EC,
          ::BasicSP::CCM_EC_var,
          EC_Servant
        > home_svnt_base;

      ECHome_Servant (
      ::BasicSP::CCM_ECHome_ptr exe,
      ::CIAO::Session_Container *c);

      virtual ~ECHome_Servant (void);

      // Home operations.

      // Home factory and finder operations.

      virtual ::BasicSP::EC_ptr
      new_EC (
      ::CORBA::Long hertz
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Attribute operations.
    };

    extern "C" EC_SVNT_Export ::PortableServer::Servant
    createECHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    CIAO::Session_Container *c
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_EC_SVNT_H */

