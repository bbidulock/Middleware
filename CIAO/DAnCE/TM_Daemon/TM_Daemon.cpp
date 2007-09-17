#include "DomainDataManager.h"
#include "Handler_i.h"
#include "Config_Handlers/XML_File_Intf.h"
#include "Config_Handlers/DnC_Dump.h"
#include "Client_Task.h"
// To set RT Sched params.
#include "ace/Sched_Params.h"
#include "ace/OS_NS_errno.h"

namespace CIAO
{
  namespace TM_Daemon
  {

    int
    run_main (int argc, char *argv[])
    {

      int priority =
        (ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
         + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2;
      priority = ACE_Sched_Params::next_priority (ACE_SCHED_FIFO,
                                                  priority);
      // Enable FIFO scheduling, e.g., RT scheduling class on Solaris.

      if (ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                                  priority,
                                                  ACE_SCOPE_PROCESS)) != 0)
        {
          if (ACE_OS::last_error () == EPERM)
            {
              ACE_DEBUG ((LM_DEBUG,
                          "server (%P|%t): user is not superuser, "
                          "test runs in time-shared class\n"));
            }
          else
            ACE_ERROR ((LM_ERROR,
                        "server (%P|%t): sched_params failed\n"));
        }


      try
        {
          CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

          CORBA::Object_var poa_object =
            orb->resolve_initial_references ("RootPOA");

          PortableServer::POA_var poa =
            PortableServer::POA::_narrow (poa_object.in ());

          PortableServer::POAManager_var poa_manager =
            poa->the_POAManager ();

          poa_manager->activate ();

          // create the Domain data Manager
          DomainDataManager* manager =
            DomainDataManager::create (orb, NULL, argv[2]);

          // Wait for all the monitors to upload their obj. refs
          sleep (10);

          manager->get_monitor_obj_ref ();

          ACE_DEBUG ((LM_DEBUG, "After get_monitor_obj_ref\n"));

          Monitor_Handler_I handler_i (manager);
          Onl_Monitor::AMI_NM_MonitorHandler_var handlerV =
            handler_i._this ();

          ACE_DEBUG ((LM_DEBUG, "Making call to intf \n"));

          CIAO::Config_Handlers::XML_File_Intf intf (argv[1]);

          ::Deployment::DeploymentPlan_var plan = intf.get_plan ();

          ACE_DEBUG ((LM_DEBUG, "After call to get plan \n"));

          manager->start_monitor_qos (handlerV, plan);

          // Now active the threads that run the orb.
          Client_Task client_task (orb.in ());
          // Spawn multiple threads to run the orb event loop.
          // @@ TODO: Need to make this configurable via command line param.
          if (client_task.activate (THR_NEW_LWP | THR_JOINABLE,
                                    4) != 0)
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "Cannot activate client threads\n"), 1);
            }
          while (true)
          {
            // Sampling period.
            // @@ TODO: Need to make this configurable.
            sleep (5);
            ACE_DEBUG ((LM_DEBUG, "Calling get_all_data\n"));
            manager->get_all_data (handlerV);
          }
          // Wait for all the threads to complete execution.
          client_task.thr_mgr ()->wait ();
          // Finally destroy the ORB
          orb->destroy ();
        }
      catch (const CORBA::Exception& ex)
      {
        ex._tao_print_exception ("CIAO_TM_Daemon::main\n");
        return -1;
      }

      ACE_DEBUG ((LM_DEBUG,
            "CIAO_TM_Daemon has closed\n"));
      return 0;
    }
  }
}

int
main (int argc, char *argv[])
{
  return CIAO::TM_Daemon::run_main (argc, argv);
}
