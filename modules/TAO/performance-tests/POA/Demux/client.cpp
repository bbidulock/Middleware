// $Id$
// ============================================================================
//
// = LIBRARY
//    TAO/performance-tests/Demux
//
// = FILENAME
//    client.cpp
//
//    client side main program
//
// = AUTHOR
//
//    Aniruddha Gokhale
//
// ============================================================================


#include "demux_test_client.h"
#include "tao/debug.h"

ACE_RCSID(CodeGen, client, "$Id$")

int
main (int argc, char *argv [])
{

  // Set TAO_debug_level to 0 to ensure silent running unless
  // debugging is explicitly invoked
  TAO_debug_level = 0;

  Demux_Test_Client demux_test_client;

  try
    {
      int r = demux_test_client.init (argc, argv);
      if (r == -1)
        return -1;

      demux_test_client.run ();
    }
  catch (const CORBA::SystemException& sysex)
    {
      sysex._tao_print_exception ("System Exception");
      return -1;
    }
  catch (const CORBA::UserException& userex)
    {
      userex._tao_print_exception ("User Exception");
      return -1;
    }

  return 0;

}
