// $Id$

//**************************************************************************
//
// NAME :   tpr_server.cpp 
// DESCRIPTION:  
//
// Server mainline
//
//****************************************************************************
#define IT_EX_MACROS

#include "cubit_impl.h"		// server header file
#include "tpool.h"

int 
main (int argc, char** argv)
{


#ifdef Cubit_USE_BOA
  Cubit_var cb = new Cubit_Impl;
  cout << "Using BOA approach" << endl;
#else
  Cubit_var cb = new TIE_Cubit (Cubit_Impl) (new Cubit_Impl);
  cout << "Using TIE approach" << endl;
#endif /* Cubit_USE_BOA */

  // Register our thread-pool dispatcher
  int n_threads = argc > 1 ? ACE_OS::atoi (argv[1]) : ACE_DEFAULT_THREADS;
  Thread_Pool tpool_dispatcher (n_threads);
 
  //
  // Go get some work to do....
  //
  IT_TRY {
      CORBA::Orbix.impl_is_ready("Cubit", IT_X);
  }
  IT_CATCHANY {
     cout << IT_X << endl;
  }
  IT_ENDTRY;

  cout << "Cubit server is exiting." << endl;


  return 0;
}
