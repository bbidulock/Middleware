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

#include "Plan_Analyzer_exec.h"
#include "ciao/CIAO_common.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_Plan_Analyzer_Impl
    {
      //==================================================================
      // Facet Executor Implementation Class:   PlanIngress_exec_i
      //==================================================================

      PlanIngress_exec_i::PlanIngress_exec_i (void)
      {
      }

      PlanIngress_exec_i::~PlanIngress_exec_i (void)
      {
      }

      // Operations from ::CIAO::RACE::PlanIngress

      void
      PlanIngress_exec_i::analyze_plan (
      const ::Deployment::DeploymentPlan & /* plan */)
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        // Your code here.
      }

      //==================================================================
      // Component Executor Implementation Class:   Plan_Analyzer_exec_i
      //==================================================================

      Plan_Analyzer_exec_i::Plan_Analyzer_exec_i (void)
      {
      }

      Plan_Analyzer_exec_i::~Plan_Analyzer_exec_i (void)
      {
      }

      // Supported or inherited operations.

      // Attribute operations.

      ::CIAO::RACE::RACE_Classifications *
      Plan_Analyzer_exec_i::classes ()
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        // Your code here.
        return 0;
      }

      // Port operations.

      ::CIAO::RACE::CCM_PlanIngress_ptr
      Plan_Analyzer_exec_i::get_plan_ingress ()
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        // Your code here.
        return ::CIAO::RACE::CCM_PlanIngress::_nil ();
      }

      // Operations from Components::SessionComponent

      void
      Plan_Analyzer_exec_i::set_session_context (
      ::Components::SessionContext_ptr ctx)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        this->context_ =
        Plan_Analyzer_Context::_narrow (
        ctx);

        if (this->context_ == 0)
        {
          throw CORBA::INTERNAL ();
        }
      }

      void
      Plan_Analyzer_exec_i::ciao_preactivate ()
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      Plan_Analyzer_exec_i::ciao_postactivate ()
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      Plan_Analyzer_exec_i::ccm_activate ()
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      Plan_Analyzer_exec_i::ccm_passivate ()
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      Plan_Analyzer_exec_i::ccm_remove ()
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      //==================================================================
      // Home Executor Implementation Class:   Plan_Analyzer_Home_exec_i
      //==================================================================

      Plan_Analyzer_Home_exec_i::Plan_Analyzer_Home_exec_i (void)
      {
      }

      Plan_Analyzer_Home_exec_i::~Plan_Analyzer_Home_exec_i (void)
      {
      }

      // Supported or inherited operations.

      // Home operations.

      // Factory and finder operations.

      // Attribute operations.

      // Implicit operations.

      ::Components::EnterpriseComponent_ptr
      Plan_Analyzer_Home_exec_i::create ()
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        ::Components::EnterpriseComponent_ptr retval =
        ::Components::EnterpriseComponent::_nil ();

        ACE_NEW_THROW_EX (
        retval,
        Plan_Analyzer_exec_i,
        CORBA::NO_MEMORY ());

        return retval;
      }

      extern "C" PLAN_ANALYZER_EXEC_Export ::Components::HomeExecutorBase_ptr
      createPlan_Analyzer_Home_Impl (void)
      {
        ::Components::HomeExecutorBase_ptr retval =
        ::Components::HomeExecutorBase::_nil ();

        ACE_NEW_RETURN (
        retval,
        Plan_Analyzer_Home_exec_i,
        ::Components::HomeExecutorBase::_nil ());

        return retval;
      }
    }
  }
}

