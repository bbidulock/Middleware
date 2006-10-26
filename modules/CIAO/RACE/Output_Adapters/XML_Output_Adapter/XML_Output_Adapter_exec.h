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

#ifndef CIAO_XML_OUTPUT_ADAPTER_EXEC_H
#define CIAO_XML_OUTPUT_ADAPTER_EXEC_H

#include /**/ "ace/pre.h"

#include "XML_Output_Adapter_svnt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "XML_Output_Adapter_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_XML_Output_Adapter_Impl
    {
      class XML_OUTPUT_ADAPTER_EXEC_Export PlanEgress_exec_i
      : public virtual ::CIAO::RACE::CCM_PlanEgress,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        PlanEgress_exec_i (void);
        virtual ~PlanEgress_exec_i (void);

        // Operations from ::CIAO::RACE::PlanEgress

        virtual ::CORBA::Boolean
        output_plan (
        const ::Deployment::DeploymentPlan & plan
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));
      };

      class XML_OUTPUT_ADAPTER_EXEC_Export XML_Output_Adapter_exec_i
      : public virtual XML_Output_Adapter_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        XML_Output_Adapter_exec_i (void);
        virtual ~XML_Output_Adapter_exec_i (void);

        // Supported or inherited operations.

        // Attribute operations.

        // Port operations.

        virtual ::CIAO::RACE::CCM_PlanEgress_ptr
        get_plan_egress (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
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
        XML_Output_Adapter_Context *context_;
      };

      class XML_OUTPUT_ADAPTER_EXEC_Export XML_Output_Adapter_Home_exec_i
      : public virtual XML_Output_Adapter_Home_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        XML_Output_Adapter_Home_exec_i (void);
        virtual ~XML_Output_Adapter_Home_exec_i (void);

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

      extern "C" XML_OUTPUT_ADAPTER_EXEC_Export ::Components::HomeExecutorBase_ptr
      createXML_Output_Adapter_Home_Impl (void);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_XML_OUTPUT_ADAPTER_EXEC_H */

