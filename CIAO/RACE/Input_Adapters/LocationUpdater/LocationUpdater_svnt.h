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

#ifndef CIAO_GLUE_SESSION_LOCATIONUPDATER_SVNT_H
#define CIAO_GLUE_SESSION_LOCATIONUPDATER_SVNT_H

#include /**/ "ace/pre.h"

#include "LocationUpdaterEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "LocationUpdaterS.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_LocationUpdater_Impl
    {
      class LocationUpdater_Servant;

      class LOCATIONUPDATER_SVNT_Export LocationUpdater_Context
        : public virtual CIAO::Context_Impl<
            ::CIAO::RACE::CCM_LocationUpdater_Context,
            LocationUpdater_Servant,
            ::CIAO::RACE::LocationUpdater,
            ::CIAO::RACE::LocationUpdater_var
          >
      {
        public:
        // We will allow the servant glue code we generate to access our state.
        friend class LocationUpdater_Servant;

        LocationUpdater_Context (
          ::Components::CCMHome_ptr h,
          ::CIAO::Session_Container *c,
          LocationUpdater_Servant *sv);

        virtual ~LocationUpdater_Context (void);

        // Operations for LocationUpdater receptacles and event sources,
        // defined in ::CIAO::RACE::CCM_LocationUpdater_Context.

        virtual ::CIAO::RACE::PlanIngress_ptr
        get_connection_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // CIAO-specific.

        static LocationUpdater_Context *
        _narrow (
          ::Components::SessionContext_ptr p
          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

        protected:
        // Methods that manage this component's connections and consumers.

        virtual void
        connect_ingress (
          ::CIAO::RACE::PlanIngress_ptr
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::PlanIngress_ptr
        disconnect_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        protected:
        // Simplex ingress connection.
        ::CIAO::RACE::PlanIngress_var
        ciao_uses_ingress_;
      };

      class LOCATIONUPDATER_SVNT_Export LocationUpdater_Servant
        : public virtual CIAO::Servant_Impl<
            POA_CIAO::RACE::LocationUpdater,
            ::CIAO::RACE::CCM_LocationUpdater,
            LocationUpdater_Context
          >
      {
        public:

        typedef ::CIAO::RACE::CCM_LocationUpdater _exec_type;

        LocationUpdater_Servant (
          ::CIAO::RACE::CCM_LocationUpdater_ptr executor,
          ::Components::CCMHome_ptr h,
          const char *ins_name,
          ::CIAO::Home_Servant_Impl_Base *hs,
          ::CIAO::Session_Container *c,
          CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~LocationUpdater_Servant (void);

        virtual void
        set_attributes (
          const ::Components::ConfigValues &descr
          ACE_ENV_ARG_DECL);

        // Supported operations.

        // Public port operations.

        virtual void
        connect_ingress (
          ::CIAO::RACE::PlanIngress_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::PlanIngress_ptr
        disconnect_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        virtual ::CIAO::RACE::PlanIngress_ptr
        get_connection_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // Servant class for the deployment consumer.
        class LOCATIONUPDATER_SVNT_Export Deploy_InputConsumer_deployment_Servant
        : public virtual POA_CIAO::RACE::Deploy_InputConsumer
        {
          public:
          Deploy_InputConsumer_deployment_Servant (
            ::CIAO::RACE::CCM_LocationUpdater_ptr executor,
            ::CIAO::RACE::CCM_LocationUpdater_Context_ptr c);

          virtual ~Deploy_InputConsumer_deployment_Servant (void);

          virtual void
          push_Deploy_Input (
            ::CIAO::RACE::Deploy_Input *evt
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
          ::CIAO::RACE::CCM_LocationUpdater_var
          executor_;

          ::CIAO::RACE::CCM_LocationUpdater_Context_var
          ctx_;
        };

        virtual ::CIAO::RACE::Deploy_InputConsumer_ptr
        get_consumer_deployment (
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

        ::CIAO::RACE::Deploy_InputConsumer_var
        consumes_deployment_;

        const char *ins_name_;

        private:

        void
        populate_port_tables (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        ::Components::EventConsumerBase_ptr
        get_consumer_deployment_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));
      };

      class LOCATIONUPDATER_SVNT_Export LocationUpdater_Home_Servant
        : public virtual
            ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::LocationUpdater_Home,
                ::CIAO::RACE::CCM_LocationUpdater_Home,
                LocationUpdater_Servant
              >
      {
        public:

        LocationUpdater_Home_Servant (
          ::CIAO::RACE::CCM_LocationUpdater_Home_ptr exe,
          const char *ins_name,
          ::CIAO::Session_Container *c,
          CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~LocationUpdater_Home_Servant (void);

        // Home operations.
        // Home factory and finder operations.

        // Attribute operations.
      };

      extern "C" LOCATIONUPDATER_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_LocationUpdater_Home_Servant (
        ::Components::HomeExecutorBase_ptr p,
        CIAO::Session_Container *c,
        const char *ins_name,
        CIAO::REC_POL_MAP &rec_pol_map
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_LOCATIONUPDATER_SVNT_H */

