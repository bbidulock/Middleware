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

#ifndef CIAO_SIMPLEBINPACKER_EXEC_H
#define CIAO_SIMPLEBINPACKER_EXEC_H

#include /**/ "ace/pre.h"

#include "SimpleBinPacker_svnt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "SimpleBinPacker_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_SimpleBinPacker_Impl
    {
      class SIMPLEBINPACKER_EXEC_Export Planner_I_exec_i
      : public virtual ::CIAO::RACE::CCM_Planner_I,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        Planner_I_exec_i (void);
        virtual ~Planner_I_exec_i (void);

        // Operations from ::CIAO::RACE::Planner_I

        virtual ::CORBA::Boolean
        process_plan (
        ::Deployment::DeploymentPlan & plan
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));
      };

      class SIMPLEBINPACKER_EXEC_Export SimpleBinPacker_exec_i
      : public virtual SimpleBinPacker_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        SimpleBinPacker_exec_i (void);
        virtual ~SimpleBinPacker_exec_i (void);

        // Supported or inherited operations.

        // Attribute operations.

        virtual char *
        name (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

        virtual void
        name (
        const char *
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

        virtual char *
        type (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

        virtual void
        type (
        const char *
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

        // Port operations.

        virtual ::CIAO::RACE::CCM_Planner_I_ptr
        get_planner_i (
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
        SimpleBinPacker_Context *context_;
      };

      class SIMPLEBINPACKER_EXEC_Export SimpleBinPacker_Home_exec_i
      : public virtual SimpleBinPacker_Home_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        SimpleBinPacker_Home_exec_i (void);
        virtual ~SimpleBinPacker_Home_exec_i (void);

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

      extern "C" SIMPLEBINPACKER_EXEC_Export ::Components::HomeExecutorBase_ptr
      createSimpleBinPacker_Home_Impl (void);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_SIMPLEBINPACKER_EXEC_H */

