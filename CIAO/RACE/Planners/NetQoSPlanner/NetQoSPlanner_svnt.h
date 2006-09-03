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

#ifndef CIAO_GLUE_SESSION_NETQOSPLANNER_SVNT_H
#define CIAO_GLUE_SESSION_NETQOSPLANNER_SVNT_H

#include /**/ "ace/pre.h"

#include "NetQoSPlannerEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "NetQoSPlannerS.h"

namespace CIAO_FACET_CIAO_RACE
{
  template <typename T>
  class Planner_I_Servant_T
  : public virtual POA_CIAO::RACE::Planner_I
  {
    public:
    Planner_I_Servant_T (
      ::CIAO::RACE::CCM_Planner_I_ptr executor,
      ::Components::CCMContext_ptr ctx);

    virtual ~Planner_I_Servant_T (void);

    virtual ::CORBA::Boolean
    process_plan (
      ::CIAO::RACE::Plan_Actions & plan
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::CIAO::RACE::PlannerFailure));

    virtual ::CORBA::Boolean
    process_domain_change (
      const ::CIAO::RACE::Planner_I::Domain_Changes & changes,
      ::CIAO::RACE::Plan_Actions_out plans
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::CIAO::RACE::PlannerFailure));

    virtual char *
    name (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    protected:
    // Facet executor.
    ::CIAO::RACE::CCM_Planner_I_var executor_;

    // Context object.
    ::Components::CCMContext_var ctx_;
  };

  typedef Planner_I_Servant_T<int> Planner_I_Servant;
}

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_NetQoSPlanner_Impl
    {
      class NetQoSPlanner_Servant;

      class NETQOSPLANNER_SVNT_Export NetQoSPlanner_Context
        : public virtual CIAO::Context_Impl<
            ::CIAO::RACE::CCM_NetQoSPlanner_Context,
            NetQoSPlanner_Servant,
            ::CIAO::RACE::NetQoSPlanner,
            ::CIAO::RACE::NetQoSPlanner_var
          >
      {
        public:
        // We will allow the servant glue code we generate to access our state.
        friend class NetQoSPlanner_Servant;

        NetQoSPlanner_Context (
          ::Components::CCMHome_ptr h,
          ::CIAO::Session_Container *c,
          NetQoSPlanner_Servant *sv);

        virtual ~NetQoSPlanner_Context (void);

        // Operations for NetQoSPlanner receptacles and event sources,
        // defined in ::CIAO::RACE::CCM_NetQoSPlanner_Context.

        // CIAO-specific.

        static NetQoSPlanner_Context *
        _narrow (
          ::Components::SessionContext_ptr p
          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

        protected:
        // Methods that manage this component's connections and consumers.

        protected:
      };

      class NETQOSPLANNER_SVNT_Export NetQoSPlanner_Servant
        : public virtual CIAO::Servant_Impl<
            POA_CIAO::RACE::NetQoSPlanner,
            ::CIAO::RACE::CCM_NetQoSPlanner,
            NetQoSPlanner_Context
          >
      {
        public:

        typedef ::CIAO::RACE::CCM_NetQoSPlanner _exec_type;

        NetQoSPlanner_Servant (
          ::CIAO::RACE::CCM_NetQoSPlanner_ptr executor,
          ::Components::CCMHome_ptr h,
          const char *ins_name,
          ::CIAO::Home_Servant_Impl_Base *hs,
          ::CIAO::Session_Container *c,
          ::CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~NetQoSPlanner_Servant (void);

        virtual void
        set_attributes (
          const ::Components::ConfigValues &descr
          ACE_ENV_ARG_DECL);

        // Supported operations.

        // Public port operations.

        virtual ::CIAO::RACE::Planner_I_ptr
        provide_planner_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // Component attribute operations.

        virtual char *
        name (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        void
        name (
          const char * name
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual char *
        type (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        void
        type (
          const char * type
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual char *
        node_map_file (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        void
        node_map_file (
          const char * node_map_file
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

        ::CIAO::RACE::Planner_I_var
        provide_planner_i_;

        const char *ins_name_;

        private:

        void
        populate_port_tables (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        ::CORBA::Object_ptr
        provide_planner_i_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));
      };

      class NETQOSPLANNER_SVNT_Export NetQoSPlanner_Home_Servant
        : public virtual
            ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::NetQoSPlanner_Home,
                ::CIAO::RACE::CCM_NetQoSPlanner_Home,
                NetQoSPlanner_Servant
              >
      {
        public:

        NetQoSPlanner_Home_Servant (
          ::CIAO::RACE::CCM_NetQoSPlanner_Home_ptr exe,
          const char *ins_name,
          ::CIAO::Session_Container *c,
          ::CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~NetQoSPlanner_Home_Servant (void);

        // Home operations.
        // Home factory and finder operations.

        // Attribute operations.
      };

      extern "C" NETQOSPLANNER_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_NetQoSPlanner_Home_Servant (
        ::Components::HomeExecutorBase_ptr p,
        CIAO::Session_Container *c,
        const char *ins_name,
        ::CIAO::REC_POL_MAP &rec_pol_map
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_NETQOSPLANNER_SVNT_H */

