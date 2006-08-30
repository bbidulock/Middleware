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

#ifndef CIAO_GLUE_SESSION_SIMPLEBINPACKER_SVNT_H
#define CIAO_GLUE_SESSION_SIMPLEBINPACKER_SVNT_H

#include /**/ "ace/pre.h"

#include "SimpleBinPackerEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "SimpleBinPackerS.h"

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
    namespace CIDL_SimpleBinPacker_Impl
    {
      class SimpleBinPacker_Servant;

      class SIMPLEBINPACKER_SVNT_Export SimpleBinPacker_Context
        : public virtual CIAO::Context_Impl<
            ::CIAO::RACE::CCM_SimpleBinPacker_Context,
            SimpleBinPacker_Servant,
            ::CIAO::RACE::SimpleBinPacker,
            ::CIAO::RACE::SimpleBinPacker_var
          >
      {
        public:
        // We will allow the servant glue code we generate to access our state.
        friend class SimpleBinPacker_Servant;

        SimpleBinPacker_Context (
          ::Components::CCMHome_ptr h,
          ::CIAO::Session_Container *c,
          SimpleBinPacker_Servant *sv);

        virtual ~SimpleBinPacker_Context (void);

        // Operations for SimpleBinPacker receptacles and event sources,
        // defined in ::CIAO::RACE::CCM_SimpleBinPacker_Context.

        virtual ::Deployment::TargetManager_ptr
        get_connection_target_mgr (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // CIAO-specific.

        static SimpleBinPacker_Context *
        _narrow (
          ::Components::SessionContext_ptr p
          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

        protected:
        // Methods that manage this component's connections and consumers.

        virtual void
        connect_target_mgr (
          ::Deployment::TargetManager_ptr
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::Deployment::TargetManager_ptr
        disconnect_target_mgr (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        protected:
        // Simplex target_mgr connection.
        ::Deployment::TargetManager_var
        ciao_uses_target_mgr_;
      };

      class SIMPLEBINPACKER_SVNT_Export SimpleBinPacker_Servant
        : public virtual CIAO::Servant_Impl<
            POA_CIAO::RACE::SimpleBinPacker,
            ::CIAO::RACE::CCM_SimpleBinPacker,
            SimpleBinPacker_Context
          >
      {
        public:

        typedef ::CIAO::RACE::CCM_SimpleBinPacker _exec_type;

        SimpleBinPacker_Servant (
          ::CIAO::RACE::CCM_SimpleBinPacker_ptr executor,
          ::Components::CCMHome_ptr h,
          const char *ins_name,
          ::CIAO::Home_Servant_Impl_Base *hs,
          ::CIAO::Session_Container *c,
          CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~SimpleBinPacker_Servant (void);

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

        virtual void
        connect_target_mgr (
          ::Deployment::TargetManager_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::Deployment::TargetManager_ptr
        disconnect_target_mgr (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        virtual ::Deployment::TargetManager_ptr
        get_connection_target_mgr (
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

      class SIMPLEBINPACKER_SVNT_Export SimpleBinPacker_Home_Servant
        : public virtual
            ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::SimpleBinPacker_Home,
                ::CIAO::RACE::CCM_SimpleBinPacker_Home,
                SimpleBinPacker_Servant
              >
      {
        public:

        SimpleBinPacker_Home_Servant (
          ::CIAO::RACE::CCM_SimpleBinPacker_Home_ptr exe,
          const char *ins_name,
          ::CIAO::Session_Container *c,
          CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~SimpleBinPacker_Home_Servant (void);

        // Home operations.
        // Home factory and finder operations.

        // Attribute operations.
      };

      extern "C" SIMPLEBINPACKER_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_SimpleBinPacker_Home_Servant (
        ::Components::HomeExecutorBase_ptr p,
        CIAO::Session_Container *c,
        const char *ins_name,
        CIAO::REC_POL_MAP &rec_pol_map
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_SIMPLEBINPACKER_SVNT_H */

