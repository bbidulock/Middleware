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

#ifndef CIAO_DANCE_OUTPUT_ADAPTER_EXEC_H
#define CIAO_DANCE_OUTPUT_ADAPTER_EXEC_H

#include /**/ "ace/pre.h"

#include "DAnCE_Output_Adapter_svnt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Plan_Launcher/Plan_Launcher_Impl.h"

#include "DAnCE_Output_Adapter_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_DAnCE_Output_Adapter_Impl
    {
      class DAnCE_Output_Adapter_exec_i;

      class DANCE_OUTPUT_ADAPTER_EXEC_Export PlanEgress_exec_i
      : public virtual ::CIAO::RACE::CCM_PlanEgress,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        PlanEgress_exec_i (CORBA::ORB_ptr orb,
                           DAnCE_Output_Adapter_exec_i &comp);
        virtual ~PlanEgress_exec_i (void);

        // Operations from ::CIAO::RACE::PlanEgress

        virtual ::CORBA::Boolean
        output_plan (const ::CIAO::RACE::Plan_Actions &plan_seq
                     ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));
      private:
        //::CORBA::Boolean launch_helper (const ::Deployment::DeploymentPlan &plan,
        //                                const ::Deployment::PackageConfiguration &package);
        ::CORBA::Boolean launch_helper (const ::CIAO::RACE::Plan_Action& plan_action );
        ::CORBA::Boolean teardown_helper (const ::CIAO::RACE::Plan_Action& plan_action );

      private:
        CORBA::ORB_var orb_;
        DAnCE_Output_Adapter_exec_i &comp_;
      };

      class DANCE_OUTPUT_ADAPTER_EXEC_Export Plan_Status_exec_i
      : public virtual ::CIAO::RACE::CCM_Plan_Status,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        Plan_Status_exec_i (DAnCE_Output_Adapter_exec_i &comp);
        virtual ~Plan_Status_exec_i (void);

        // Operations from ::CIAO::RACE::Plan_Status

        virtual ::CORBA::Boolean
        teardown (const char * uuid
                  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

        DAnCE_Output_Adapter_exec_i &comp_;
      };

      class DANCE_OUTPUT_ADAPTER_EXEC_Export DAnCE_Output_Adapter_exec_i
      : public virtual DAnCE_Output_Adapter_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        DAnCE_Output_Adapter_exec_i (void);
        virtual ~DAnCE_Output_Adapter_exec_i (void);

        // Supported or inherited operations.

        // Attribute operations.

        // Port operations.

        virtual ::CIAO::RACE::CCM_PlanEgress_ptr
        get_plan_egress (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

        virtual ::CIAO::RACE::CCM_Plan_Status_ptr
        get_plan_status (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC ((CORBA::SystemException));

        // Operations from Components::SessionComponent

        virtual void
        set_session_context (
          ::Components::SessionContext_ptr ctx
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ciao_preactivate (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ciao_postactivate (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ccm_activate (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ccm_passivate (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ccm_remove (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        protected:
        DAnCE_Output_Adapter_Context *context_;

        Plan_Launcher::Plan_Launcher_i launcher_;

        friend class PlanEgress_exec_i;

        friend class Plan_Status_exec_i;

      };

      class DANCE_OUTPUT_ADAPTER_EXEC_Export DAnCE_Output_Adapter_Home_exec_i
      : public virtual DAnCE_Output_Adapter_Home_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        DAnCE_Output_Adapter_Home_exec_i (void);
        virtual ~DAnCE_Output_Adapter_Home_exec_i (void);

        // Supported or inherited operations.

        // Home operations.

        // Factory and finder operations.

        // Attribute operations.

        // Implicit operations.

        virtual ::Components::EnterpriseComponent_ptr
        create (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));
      };

      extern "C" DANCE_OUTPUT_ADAPTER_EXEC_Export ::Components::HomeExecutorBase_ptr
      create_CIAO_RACE_DAnCE_Output_Adapter_Home_Impl (void);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_DANCE_OUTPUT_ADAPTER_EXEC_H */

