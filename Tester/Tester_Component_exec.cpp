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

#include "Tester_Component_exec.h"
#include "ciao/CIAO_common.h"

namespace CIAO
{
  namespace RACE
  {
    namespace SA_POP
    {
      namespace CIDL_Tester_Component_Impl
      {
        //==================================================================
        // Component Executor Implementation Class:   Tester_Component_exec_i
        //==================================================================

        Tester_Component_exec_i::Tester_Component_exec_i (void)
        {
        }

        Tester_Component_exec_i::~Tester_Component_exec_i (void)
        {
        }

        // Supported or inherited operations.

        ::CORBA::Boolean
        Tester_Component_exec_i::init (
          const char * task_net_file,
          const char * task_map_file)
        {
          try {
            ACE_DEBUG ((LM_DEBUG, "In Tester_Component_exec_i::init ()\n"));

            ::CIAO::RACE::SA_POP::Planning_var planner = this->context_->get_connection_SAPOP ();
            ACE_DEBUG ((LM_DEBUG, "In Tester_Component_exec_i::init () after getting the OBJ ref to the planner\n"));
            if (CORBA::is_nil (planner.in ()))
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                "Unable to acquire SA_POP_Planner's objref\n"),
                false);
            }
            return planner->init (task_net_file, task_map_file);
          }
          catch (CORBA::Exception& e) {
            ACE_PRINT_EXCEPTION (e, "Exception caught in Tester_Component_exec_i::init ()");
          }
          catch (...)
          {
            ACE_DEBUG ((LM_ERROR, "Unknown Exception caught in Tester_Component_exec_i::init ()\n"));
          }
            return false;
        }

        ::CORBA::Boolean
        Tester_Component_exec_i::deploy_from_goal (
          const ::CIAO::RACE::GoalStructure & goal,
          ::CORBA::String_out ID)
        {
      
          try {
            CORBA::String_var opstring_id;
            CIAO::RACE::OperationalString_var opstring;
            this->context_->get_connection_SAPOP ()->generate_opstring (goal, opstring.out ());
            this->context_->get_connection_RACE_IA ()->deploy_string (opstring.in (), opstring_id.out ());
            ID = opstring_id.in ();
            return true;
          }
          catch (CORBA::Exception& e) {
            ACE_PRINT_EXCEPTION (e, "Exception caught in Tester_Component_exec_i::deploy_from_goal ()");
            return false;
          }
        }

        ::CORBA::Boolean
        Tester_Component_exec_i::modify_string_from_goal (
          const ::CIAO::RACE::GoalStructure & /* goal */,
          const char * /* ID */)
        {
          // Your code here.
          return false;
        }

        ::CORBA::Boolean
        Tester_Component_exec_i::tear_down_string (
          const char * /* ID */)
        {
          // Your code here.
          return false;
        }

        // Attribute operations.

        // Port operations.

        // Operations from Components::SessionComponent

        void
        Tester_Component_exec_i::set_session_context (
          ::Components::SessionContext_ptr ctx)
        {
          this->context_ =
            Tester_Component_Context::_narrow (ctx);

          if (this->context_ == 0)
          {
            throw ::CORBA::INTERNAL ();
          }
        }

        void
        Tester_Component_exec_i::ciao_preactivate ()
        {
          // Your code here.
        }

        void
        Tester_Component_exec_i::ciao_postactivate ()
        {
          // Your code here.
        }

        void
        Tester_Component_exec_i::ccm_activate ()
        {
          // Your code here.
        }

        void
        Tester_Component_exec_i::ccm_passivate ()
        {
          // Your code here.
        }

        void
        Tester_Component_exec_i::ccm_remove ()
        {
          // Your code here.
        }

        //==================================================================
        // Home Executor Implementation Class:   Tester_Component_Home_exec_i
        //==================================================================

        Tester_Component_Home_exec_i::Tester_Component_Home_exec_i (void)
        {
        }

        Tester_Component_Home_exec_i::~Tester_Component_Home_exec_i (void)
        {
        }

        // Supported or inherited operations.

        // Home operations.

        // Factory and finder operations.

        // Attribute operations.

        // Implicit operations.

        ::Components::EnterpriseComponent_ptr
        Tester_Component_Home_exec_i::create ()
        {
          ::Components::EnterpriseComponent_ptr retval =
            ::Components::EnterpriseComponent::_nil ();

          ACE_NEW_THROW_EX (
            retval,
            Tester_Component_exec_i,
            ::CORBA::NO_MEMORY ());

          return retval;
        }

        extern "C" TESTER_COMPONENT_EXEC_Export ::Components::HomeExecutorBase_ptr
        create_CIAO_RACE_SA_POP_Tester_Component_Home_Impl (void)
        {
          ::Components::HomeExecutorBase_ptr retval =
            ::Components::HomeExecutorBase::_nil ();

          ACE_NEW_RETURN (
            retval,
            Tester_Component_Home_exec_i,
            ::Components::HomeExecutorBase::_nil ());

          return retval;
        }
      }
    }
  }
}

