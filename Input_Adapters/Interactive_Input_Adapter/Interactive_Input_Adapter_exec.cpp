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

#include "Interactive_Input_Adapter_exec.h"
#include "ciao/CIAO_common.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_Interactive_Input_Adapter_Impl
    {
      //==================================================================
      // Component Executor Implementation Class:   Interactive_Input_Adapter_exec_i
      //==================================================================

      Interactive_Input_Adapter_exec_i::Interactive_Input_Adapter_exec_i (void)
      {
      }

      Interactive_Input_Adapter_exec_i::~Interactive_Input_Adapter_exec_i (void)
      {
      }

      // Supported or inherited operations.

      // Attribute operations.

      // Port operations.

      // Operations from Components::SessionComponent

      void
      Interactive_Input_Adapter_exec_i::set_session_context (
      ::Components::SessionContext_ptr ctx
      ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        this->context_ =
        Interactive_Input_Adapter_Context::_narrow (
        ctx
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (this->context_ == 0)
        {
          ACE_THROW (CORBA::INTERNAL ());
        }
      }

      void
      Interactive_Input_Adapter_exec_i::ciao_preactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      Interactive_Input_Adapter_exec_i::ciao_postactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      Interactive_Input_Adapter_exec_i::ccm_activate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      Interactive_Input_Adapter_exec_i::ccm_passivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      Interactive_Input_Adapter_exec_i::ccm_remove (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      //==================================================================
      // Home Executor Implementation Class:   Interactive_Input_Adapter_Home_exec_i
      //==================================================================

      Interactive_Input_Adapter_Home_exec_i::Interactive_Input_Adapter_Home_exec_i (void)
      {
      }

      Interactive_Input_Adapter_Home_exec_i::~Interactive_Input_Adapter_Home_exec_i (void)
      {
      }

      // Supported or inherited operations.

      // Home operations.

      // Factory and finder operations.

      // Attribute operations.

      // Implicit operations.

      ::Components::EnterpriseComponent_ptr
      Interactive_Input_Adapter_Home_exec_i::create (
      ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        ::Components::EnterpriseComponent_ptr retval =
        ::Components::EnterpriseComponent::_nil ();

        ACE_NEW_THROW_EX (
        retval,
        Interactive_Input_Adapter_exec_i,
        CORBA::NO_MEMORY ());
        ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());

        return retval;
      }

      extern "C" INTERACTIVE_INPUT_ADAPTER_EXEC_Export ::Components::HomeExecutorBase_ptr
      createInteractive_Input_Adapter_Home_Impl (void)
      {
        ::Components::HomeExecutorBase_ptr retval =
        ::Components::HomeExecutorBase::_nil ();

        ACE_NEW_RETURN (
        retval,
        Interactive_Input_Adapter_Home_exec_i,
        ::Components::HomeExecutorBase::_nil ());

        return retval;
      }
    }
  }
}

