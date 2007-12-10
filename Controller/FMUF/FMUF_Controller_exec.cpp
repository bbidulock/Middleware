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

#include "FMUF_Controller_exec.h"
#include "ciao/CIAO_common.h"

namespace CIAO
{
  namespace RACE
  {
    namespace Controller
    {
      namespace CIDL_FMUF_Controller_Impl
      {
        //==================================================================
        // Facet Executor Implementation Class:   Control_Operations_exec_i
        //==================================================================

        Control_Operations_exec_i::Control_Operations_exec_i (void)
        {
        }

        Control_Operations_exec_i::~Control_Operations_exec_i (void)
        {
        }

        // Operations from ::CIAO::RACE::Controller::Control_Operations

        ::CORBA::Boolean
        Control_Operations_exec_i::register_string (
          const ::CIAO::RACE::OperationalString & /* opstring */,
          ::CORBA::String_out /* ID */)
        {
          // Your code here.
          return false;
        }

        ::CORBA::Boolean
        Control_Operations_exec_i::unregister_string (
          const char * /* ID */)
        {
          // Your code here.
          return false;
        }

        //==================================================================
        // Facet Executor Implementation Class:   Admin_exec_i
        //==================================================================

        Admin_exec_i::Admin_exec_i (void)
        {
        }

        Admin_exec_i::~Admin_exec_i (void)
        {
        }

        // Operations from ::CIAO::RACE::Controller::Admin

        ::CORBA::Boolean
        Admin_exec_i::start_controller ()
        {
          // Your code here.
          return false;
        }

        ::CORBA::Boolean
        Admin_exec_i::stop_controller ()
        {
          // Your code here.
          return false;
        }

        //==================================================================
        // Component Executor Implementation Class:   FMUF_Controller_exec_i
        //==================================================================

        FMUF_Controller_exec_i::FMUF_Controller_exec_i (void)
        {
        }

        FMUF_Controller_exec_i::~FMUF_Controller_exec_i (void)
        {
        }

        // Supported or inherited operations.

        // Attribute operations.

        ::CORBA::Long
        FMUF_Controller_exec_i::sampling_period ()
        {
          // Your code here.
          return 0;
        }

        void
        FMUF_Controller_exec_i::sampling_period (::CORBA::Long /* sampling_period */)
        {
          // Your code here.
        }

        // Port operations.

        ::CIAO::RACE::Controller::CCM_Control_Operations_ptr
        FMUF_Controller_exec_i::get_operations ()
        {
          // Your code here.
          return ::CIAO::RACE::Controller::CCM_Control_Operations::_nil ();
        }

        ::CIAO::RACE::Controller::CCM_Admin_ptr
        FMUF_Controller_exec_i::get_admin ()
        {
          // Your code here.
          return ::CIAO::RACE::Controller::CCM_Admin::_nil ();
        }

        // Operations from Components::SessionComponent

        void
        FMUF_Controller_exec_i::set_session_context (
          ::Components::SessionContext_ptr ctx)
        {
          this->context_ =
            ::CIAO::RACE::Controller::CCM_FMUF_Controller_Context::_narrow (ctx);

          if (CORBA::is_nil (this->context_.in ()))
          {
            throw ::CORBA::INTERNAL ();
          }
        }

        void
        FMUF_Controller_exec_i::ciao_preactivate ()
        {
          // Your code here.
        }

        void
        FMUF_Controller_exec_i::ciao_postactivate ()
        {
          // Your code here.
        }

        void
        FMUF_Controller_exec_i::ccm_activate ()
        {
          // Your code here.
        }

        void
        FMUF_Controller_exec_i::ccm_passivate ()
        {
          // Your code here.
        }

        void
        FMUF_Controller_exec_i::ccm_remove ()
        {
          // Your code here.
        }

        //==================================================================
        // Home Executor Implementation Class:   FMUF_Controller_Home_exec_i
        //==================================================================

        FMUF_Controller_Home_exec_i::FMUF_Controller_Home_exec_i (void)
        {
        }

        FMUF_Controller_Home_exec_i::~FMUF_Controller_Home_exec_i (void)
        {
        }

        // Supported or inherited operations.

        // Home operations.

        // Factory and finder operations.

        // Attribute operations.

        // Implicit operations.

        ::Components::EnterpriseComponent_ptr
        FMUF_Controller_Home_exec_i::create ()
        {
          ::Components::EnterpriseComponent_ptr retval =
            ::Components::EnterpriseComponent::_nil ();

          ACE_NEW_THROW_EX (
            retval,
            FMUF_Controller_exec_i,
            ::CORBA::NO_MEMORY ());

          return retval;
        }

        extern "C" FMUF_CONTROLLER_EXEC_Export ::Components::HomeExecutorBase_ptr
        create_CIAO_RACE_Controller_FMUF_Controller_Home_Impl (void)
        {
          ::Components::HomeExecutorBase_ptr retval =
            ::Components::HomeExecutorBase::_nil ();

          ACE_NEW_RETURN (
            retval,
            FMUF_Controller_Home_exec_i,
            ::Components::HomeExecutorBase::_nil ());

          return retval;
        }
      }
    }
  }
}

