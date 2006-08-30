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

#ifndef CIAO_GLUE_SESSION_WEB_OUTPUT_ADAPTER_SVNT_H
#define CIAO_GLUE_SESSION_WEB_OUTPUT_ADAPTER_SVNT_H

#include /**/ "ace/pre.h"

#include "Web_Output_AdapterEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "Web_Output_AdapterS.h"

namespace CIAO_FACET_CIAO_RACE
{
  template <typename T>
  class PlanEgress_Servant_T
  : public virtual POA_CIAO::RACE::PlanEgress
  {
    public:
    PlanEgress_Servant_T (
      ::CIAO::RACE::CCM_PlanEgress_ptr executor,
      ::Components::CCMContext_ptr ctx);

    virtual ~PlanEgress_Servant_T (void);

    virtual ::CORBA::Boolean
    output_plan (
      const ::CIAO::RACE::Plan_Actions & plans
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    protected:
    // Facet executor.
    ::CIAO::RACE::CCM_PlanEgress_var executor_;

    // Context object.
    ::Components::CCMContext_var ctx_;
  };

  typedef PlanEgress_Servant_T<int> PlanEgress_Servant;
}

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_Web_Output_Adapter_Impl
    {
      class Web_Output_Adapter_Servant;

      class WEB_OUTPUT_ADAPTER_SVNT_Export Web_Output_Adapter_Context
        : public virtual CIAO::Context_Impl<
            ::CIAO::RACE::CCM_Web_Output_Adapter_Context,
            Web_Output_Adapter_Servant,
            ::CIAO::RACE::Web_Output_Adapter,
            ::CIAO::RACE::Web_Output_Adapter_var
          >
      {
        public:
        // We will allow the servant glue code we generate to access our state.
        friend class Web_Output_Adapter_Servant;

        Web_Output_Adapter_Context (
          ::Components::CCMHome_ptr h,
          ::CIAO::Session_Container *c,
          Web_Output_Adapter_Servant *sv);

        virtual ~Web_Output_Adapter_Context (void);

        // Operations for Web_Output_Adapter receptacles and event sources,
        // defined in ::CIAO::RACE::CCM_Web_Output_Adapter_Context.

        virtual ::CIAO::RACE::Descriptors_ptr
        get_connection_control_output (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual void
        push_dance_depment (
          ::CIAO::RACE::Web_Deployment *ev
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // CIAO-specific.

        static Web_Output_Adapter_Context *
        _narrow (
          ::Components::SessionContext_ptr p
          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

        protected:
        // Methods that manage this component's connections and consumers.

        virtual void
        connect_control_output (
          ::CIAO::RACE::Descriptors_ptr
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::Descriptors_ptr
        disconnect_control_output (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        virtual ::Components::Cookie *
        subscribe_dance_depment (
          ::CIAO::RACE::Web_DeploymentConsumer_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::ExceededConnectionLimit));

        // CIAO-specific.
        ::Components::Cookie *
        subscribe_dance_depment_generic (
          ::Components::EventConsumerBase_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::ExceededConnectionLimit));

        virtual ::CIAO::RACE::Web_DeploymentConsumer_ptr
        unsubscribe_dance_depment (
          ::Components::Cookie *ck
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidConnection));

        protected:
        // Simplex control_output connection.
        ::CIAO::RACE::Descriptors_var
        ciao_uses_control_output_;

        ACE_Active_Map_Manager<
        ::CIAO::RACE::Web_DeploymentConsumer_var>
        ciao_publishes_dance_depment_map_;

        ACE_Active_Map_Manager<
        ::Components::EventConsumerBase_var>
        ciao_publishes_dance_depment_generic_map_;
      };

      class WEB_OUTPUT_ADAPTER_SVNT_Export Web_Output_Adapter_Servant
        : public virtual CIAO::Servant_Impl<
            POA_CIAO::RACE::Web_Output_Adapter,
            ::CIAO::RACE::CCM_Web_Output_Adapter,
            Web_Output_Adapter_Context
          >
      {
        public:

        typedef ::CIAO::RACE::CCM_Web_Output_Adapter _exec_type;

        Web_Output_Adapter_Servant (
          ::CIAO::RACE::CCM_Web_Output_Adapter_ptr executor,
          ::Components::CCMHome_ptr h,
          const char *ins_name,
          ::CIAO::Home_Servant_Impl_Base *hs,
          ::CIAO::Session_Container *c,
          CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~Web_Output_Adapter_Servant (void);

        virtual void
        set_attributes (
          const ::Components::ConfigValues &descr
          ACE_ENV_ARG_DECL);

        // Supported operations.

        // Public port operations.

        virtual ::CIAO::RACE::PlanEgress_ptr
        provide_plan_egress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual void
        connect_control_output (
          ::CIAO::RACE::Descriptors_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::Descriptors_ptr
        disconnect_control_output (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        virtual ::CIAO::RACE::Descriptors_ptr
        get_connection_control_output (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual ::Components::Cookie *
        subscribe_dance_depment (
          ::CIAO::RACE::Web_DeploymentConsumer_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::ExceededConnectionLimit));

        // CIAO-specific.
        ::Components::Cookie *
        subscribe_dance_depment_generic (
          ::Components::EventConsumerBase_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::ExceededConnectionLimit));

        virtual ::CIAO::RACE::Web_DeploymentConsumer_ptr
        unsubscribe_dance_depment (
          ::Components::Cookie *ck
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidConnection));

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

        ::CIAO::RACE::PlanEgress_var
        provide_plan_egress_;

        const char *ins_name_;

        private:

        void
        populate_port_tables (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        ::CORBA::Object_ptr
        provide_plan_egress_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));
      };

      class WEB_OUTPUT_ADAPTER_SVNT_Export Web_Output_Adapter_Home_Servant
        : public virtual
            ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::Web_Output_Adapter_Home,
                ::CIAO::RACE::CCM_Web_Output_Adapter_Home,
                Web_Output_Adapter_Servant
              >
      {
        public:

        Web_Output_Adapter_Home_Servant (
          ::CIAO::RACE::CCM_Web_Output_Adapter_Home_ptr exe,
          const char *ins_name,
          ::CIAO::Session_Container *c,
          CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~Web_Output_Adapter_Home_Servant (void);

        // Home operations.
        // Home factory and finder operations.

        // Attribute operations.
      };


      extern "C" WEB_OUTPUT_ADAPTER_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_Web_Output_Adapter_Home_Servant (
        ::Components::HomeExecutorBase_ptr p,
        CIAO::Session_Container *c,
        const char *ins_name,
        CIAO::REC_POL_MAP &rec_pol_map
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_WEB_OUTPUT_ADAPTER_SVNT_H */

