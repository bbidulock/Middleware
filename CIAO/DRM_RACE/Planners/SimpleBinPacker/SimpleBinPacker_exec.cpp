// SimpleBinPacker_exec.cpp,v 1.1 2005/09/06 19:57:22 wotte Exp
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

#include "SimpleBinPacker_exec.h"

#include "ace/Mutex.h"
#include "ace/Condition_Thread_Mutex.h"
//#include "ciao/CIAO_common.h"

#include "sbp.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_SimpleBinPacker_Impl
    {
      //==================================================================
      // Facet Executor Implementation Class:   Planner_I_exec_i
      //==================================================================

      Planner_I_exec_i::Planner_I_exec_i (SimpleBinPacker_exec_i &exec)
        : exec_ (exec)
      {
      }

      Planner_I_exec_i::~Planner_I_exec_i (void)
      {
      }

      // Operations from ::CIAO::RACE::Planner_I

      ::CORBA::Boolean
      Planner_I_exec_i::process_plan (::CIAO::RACE::Plan_Actions & plan_seq)
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        /// @TODO I am not sure whether it should return true or false when
        /// sequence length is zero.
        if (plan_seq.length () == 0)
          return true;

        ::Deployment::DeploymentPlan plan = plan_seq [0].plan;

  //        CIAO_DEBUG (8, "RACE::Ensemble Planner - Querying TargetManager\n");
        // Obtain domain information
        ::Deployment::TargetManager_var tgt_mgr = exec_.context_->get_connection_target_mgr ();
        tgt_mgr->getAvailableResources ();
        ::Deployment::Domain_var domain (tgt_mgr->getAvailableResources ());


        std::pair <int, int> state (-1, 1); // -1 = no algoritm successful yet, 3 = number of planners.
        ACE_Thread_Mutex mutex, cond_mutex;

        ACE_Condition_Thread_Mutex condition (cond_mutex);


        typedef std::vector <SBP::SBP_Converter> converters;
        typedef std::vector <SBP::SBP_Task *> tasks;

        converters conv;
        conv.reserve (1);
        conv.push_back (SBP::SBP_Converter (&domain.in (), &plan.instance, &plan.implementation));
        //conv.push_back (SBP::SBP_Converter (&domain.in (), &plan.instance, &plan.implementation));
        //conv.push_back (SBP::SBP_Converter (&domain.in (), &plan.instance, &plan.implementation));

        tasks taskv;

        int j = 0;
        for (converters::iterator i = conv.begin ();
             i != conv.end ();
             ++i, ++j)
          {
            taskv.push_back (new SBP::SBP_Task (conv[j].get_bins (),
                                                conv[j].get_items (),
                                                mutex, condition, j, state));
          }

        for (tasks::iterator i = taskv.begin ();
             i != taskv.end ();
             ++i)
          {
            (*i)->activate ();
          }

        //        CIAO_DEBUG (8, "RACE::Ensemble Planner - Waiting on condition\n");
        condition.wait ();

        //        CIAO_DEBUG (8, "Woke up from condition, state is %i\n",
        //                    state.first);

        bool retv (false);

        if (state.first != -1)
          {
            //            CIAO_DEBUG (8, "RACE::Ensemble Planner - Committing Allocation \n");

            conv[state.first].commit_allocation (taskv[state.first]->get_items ());
            // Commit allocation to TargetManager

            try
              {
                tgt_mgr->commitResources (plan);
              }
            catch (::Deployment::ResourceNotAvailable &ex)
              {
                ACE_ERROR ((LM_ERROR, "ResourceNotAvailable exception caught:\n"
                            "\tName: %s\n"
                            "\tType: %s\n"
                            "\tProperty Name: %s\n"
                            "\tElementName: %s\n"
                            "\tResourceName: %s\n",
                            ex.name.in (), ex.resourceType.in (),
                            ex.propertyName.in (), ex.elementName.in (),
                            ex.resourceName.in ()));
                throw;
              }
          }

        else
          ACE_ERROR ((LM_ERROR, "RACE::Planner::Ensemble: No successful allocation\n"));

        // Cancel and delete all threads....
#if 0
        for (tasks::iterator i = taskv.begin ();
             i != taskv.end ();
             ++i)
          {
            (*i)->thr_mgr_->cancel_task (*i, 1); // @@WARNING:  asynch thread cancelation not supported on Windows!
            delete *i;
          }
#endif /* if 0 */

        if (state.first == -1)
          {
            ACE_ERROR ((LM_ERROR, "RACE::Planner::Ensemble: No successful allocation"));
            return false; // No successful allocation...
          }



        return retv;
      }

      ::CORBA::Boolean
      Planner_I_exec_i::process_domain_change
      (const ::CIAO::RACE::Planner_I::Domain_Changes & /*changes*/,
       ::CIAO::RACE::Plan_Actions_out plans
       ACE_ENV_ARG_DECL_NOT_USED)
        ACE_THROW_SPEC ((CORBA::SystemException))
      {
         ::CIAO::RACE::Plan_Actions::_var_type plans_out( new ::CIAO::RACE::Plan_Actions(0) );
         plans_out->length(0);

         plans = plans_out._retn();

         return true;
      }

      char *
      Planner_I_exec_i::name (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        return this->exec_.name ();
      }

      //==================================================================
      // Component Executor Implementation Class:   SimpleBinPacker_exec_i
      //==================================================================

      SimpleBinPacker_exec_i::SimpleBinPacker_exec_i (void)
      {
      }

      SimpleBinPacker_exec_i::~SimpleBinPacker_exec_i (void)
      {
      }

      // Supported or inherited operations.

      // Attribute operations.

      char *
      SimpleBinPacker_exec_i::name (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        ACE_DEBUG ((LM_DEBUG, "SimpleBinPacker_exec_i::name()\n"));
        return CORBA::string_dup ("EnsemblePlanner");
      }

      void
      SimpleBinPacker_exec_i::name (
      const char * /* name */
      ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        // Your code here.
      }

      char *
      SimpleBinPacker_exec_i::type (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        ACE_DEBUG ((LM_DEBUG, "SimpleBinPacker_exec_i::type()\n"));
        return CORBA::string_dup ("Component Allocation Planner");
      }

      void
      SimpleBinPacker_exec_i::type (
      const char * /* type */
      ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        // Your code here.
      }

      // Port operations.

      ::CIAO::RACE::CCM_Planner_I_ptr
      SimpleBinPacker_exec_i::get_planner_i (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
      {
        // Your code here.
        return new Planner_I_exec_i (*this);
      }

      // Operations from Components::SessionComponent

      void
      SimpleBinPacker_exec_i::set_session_context (
      ::Components::SessionContext_ptr ctx
      ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        this->context_ =
        SimpleBinPacker_Context::_narrow (
        ctx
        ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (this->context_ == 0)
        {
          ACE_THROW (CORBA::INTERNAL ());
        }
      }

      void
      SimpleBinPacker_exec_i::ciao_preactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      SimpleBinPacker_exec_i::ciao_postactivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      SimpleBinPacker_exec_i::ccm_activate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      SimpleBinPacker_exec_i::ccm_passivate (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      void
      SimpleBinPacker_exec_i::ccm_remove (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        // Your code here.
      }

      //==================================================================
      // Home Executor Implementation Class:   SimpleBinPacker_Home_exec_i
      //==================================================================

      SimpleBinPacker_Home_exec_i::SimpleBinPacker_Home_exec_i (void)
      {
      }

      SimpleBinPacker_Home_exec_i::~SimpleBinPacker_Home_exec_i (void)
      {
      }

      // Supported or inherited operations.

      // Home operations.

      // Factory and finder operations.

      // Attribute operations.

      // Implicit operations.

      ::Components::EnterpriseComponent_ptr
      SimpleBinPacker_Home_exec_i::create (
      ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CCMException))
      {
        ::Components::EnterpriseComponent_ptr retval =
        ::Components::EnterpriseComponent::_nil ();

        ACE_NEW_THROW_EX (
        retval,
        SimpleBinPacker_exec_i,
        CORBA::NO_MEMORY ());
        ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());

        return retval;
      }

      extern "C" SIMPLEBINPACKER_EXEC_Export ::Components::HomeExecutorBase_ptr
      create_CIAO_RACE_SimpleBinPacker_Home_Impl (void)
      {
        ::Components::HomeExecutorBase_ptr retval =
        ::Components::HomeExecutorBase::_nil ();

        ACE_NEW_RETURN (
        retval,
        SimpleBinPacker_Home_exec_i,
        ::Components::HomeExecutorBase::_nil ());

        return retval;
      }
    }
  }
}
