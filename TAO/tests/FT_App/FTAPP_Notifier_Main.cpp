/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    FTAPP_Notifier_Main.cpp
 *
 *  $Id$
 *
 *  This file is part of Fault Tolerant CORBA.
 *  This file provides the main routine for a stub implementation
 *  of the FaultNotifier interface.
 *
 *  @author Dale Wilson <wilson_d@ociweb.com>
 */
//=============================================================================

#include "ace/pre.h"
#include "StubFaultNotifier.h"

#include "tao/PortableServer/ORB_Manager.h"

int main (int argc, ACE_TCHAR * argv[] )
{
  int result = 0;
  ACE_TRY_NEW_ENV
  {
    // Create an object that manages all the
    // details of being a server.
    // give it a shot at the command line.
    TAO_ORB_Manager orbManager;

    result = orbManager.init (argc, argv
        ACE_ENV_ARG_PARAMETER);
    if(result == 0)
    {
      ACE_TRY_CHECK;
    // create an instance of the stub.
    // it too gets to see the command line.
    StubFaultNotifier stub;
    int result = stub.parse_args (argc, argv);
    if (result == 0)
    {



        result = stub.self_register(orbManager ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
        if (result == 0)
        {
          ACE_ERROR ((LM_INFO,
            "%T %n: Ready %s\n", stub.identity()
            ));

          // Initial run to initialize the orb
          ACE_Time_Value tv(1,0);
          result = orbManager.run (tv
            ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
          // now run event loop
          CORBA::ORB_ptr orb = orbManager.orb();
          int quit = 0;
          while (result == 0 && ! quit )
          {
            ACE_Time_Value work_tv(1,0);
            orb->perform_work(work_tv
              ACE_ENV_ARG_PARAMETER);
            ACE_TRY_CHECK;
            quit = stub.idle(result);
          }
          orb->shutdown (0 ACE_ENV_ARG_PARAMETER);

          ACE_ERROR ((LM_INFO,
            "%T %n: Terminated normally. %s\n", stub.identity()
            ));
        }
        else
        {
          ACE_ERROR ((LM_ERROR,
            "%T %n: Stub registration failed: %p\n"
            ));
          result = -1;
        }
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
          "%T %n: orb manager init failed\n"
        ));
        result = -1;
      }
    }
  }
  ACE_CATCHANY
  {
    ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
      "FTAPP_Notifier_Main\t\n");
    result = -1;
  }
  ACE_ENDTRY;

  return result;
}
