// -*- C++ -*-

//=============================================================================
/**
 *  @file    Server_Main.cpp
 *
 *  $Id$
 *
 *  Implements a generic object that acts as "main" for a CORBA server.
 *
 *  @author Dale Wilson <wilson_d@ociweb.com>
 */
//=============================================================================

#ifndef TAO_UTILS_SERVER_MAIN_T_CPP
#define TAO_UTILS_SERVER_MAIN_T_CPP

#include "tao/Utils/Server_Main.h"

#include "tao/ORB.h"

#include "ace/Argv_Type_Converter.h"
#include "ace/Log_Msg.h"
#include "ace/Time_Value.h"


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename SERVANT>
TAO::Utils::Server_Main<SERVANT>::Server_Main (const char * name)
  : name_(name)
{
}

template <typename SERVANT>
TAO::Utils::Server_Main<SERVANT>::~Server_Main ()
{
}

template <typename SERVANT>
int
TAO::Utils::Server_Main<SERVANT>::run (int argc, ACE_TCHAR *argv[])
{
  int result = 0;
  // hide unicode if necessary.
  ACE_Argv_Type_Converter command_line (argc, argv);

  char ** asciiArgv = command_line.get_ASCII_argv ();

  try
  {
    // Initialize the orb

    CORBA::ORB_var orb =
      CORBA::ORB_init (argc, asciiArgv, name_);

    if (! ::CORBA::is_nil(orb.in ()))
    {
      // create an instance of the servant object and give it a
      // chance at the arguments.
      SERVANT servant;
      result = servant.parse_args (argc, asciiArgv);
      if (result == 0)
      {
        //////////////////////////////////
        // let the servant register itself
        result = servant.init (orb.in ());

        if (result == 0)
        {
          ACE_ERROR ((LM_INFO,
            "%T %s (%P|%t) Ready %s\n", name_, servant.identity ()
            ));

          //////////////////////////////////
          // Run the event loop for the ORB.
          // Initial run to initialize the orb
          ACE_Time_Value tv (1,0);
          orb->run (tv);

          // now run event loop
          int quit = 0;
          while (result == 0 && ! quit )
          {
            ACE_Time_Value work_tv (1,0);
            orb->perform_work(work_tv);
            quit = servant.idle (result);
          }
          servant.fini ();

          orb->shutdown (1);

          ACE_ERROR ((LM_INFO,
                      "%T %s (%P|%t) Terminated normally. %s\n",
                      name_,
                      servant.identity ()
            ));
        }
        else
        {
          ACE_ERROR ((LM_ERROR,
            "%T %s (%P|%t) Registration failed: %m\n", name_
            ));
          result = -1;
        }
      }
      else
      {
        ACE_ERROR ((LM_ERROR,
          "%T %s (%P|%t) ORB manager init failed\n", name_
        ));
        result = -1;
      }
    }
  }
  catch ( ::CORBA::Exception& ex)
  {
    ex._tao_print_exception (name_);
    result = -1;
  }
  return result;
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif //TAO_UTILS_SERVER_MAIN_T_CPP
