// -*- C++ -*-

#include "Framework_Component_DLL.h"
#include "ace/Service_Config.h"
#include "ace/OS.h"

ACE_RCSID (tests,
           Framework_Component_DLL,
           "$Id$")

/// This is just a simple server that can be loaded via the ACE
/// Service Configuration framework and uses the singleton that 
/// also lives in this library.
template <int>
class Server_T : public ACE_Service_Object
{
public:
  int init (int, ACE_TCHAR *[]) 
  {
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Server_T::init()\n")));

    // Initialize the singleton
    FWCT_DLL_Singleton_Adapter_T <Simple_Service> *ss = SS_SINGLETON::instance ();

    ACE_DEBUG ((LM_DEBUG, 
                ACE_LIB_TEXT ("Server_T::init() dll_name: %s\n"),
                ss->dll_name ()));
    return 0;
  }
  
  int fini (void) 
  {
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Server_T::fini()\n")));
    return 0;
  }
};

typedef Server_T <1> Server_1;
typedef Server_T <2> Server_2;

ACE_FACTORY_DEFINE (Framework_Component_DLL, Server_1)
ACE_FACTORY_DEFINE (Framework_Component_DLL, Server_2)




