
// $Id$

#include "AMH_Servant.h"
#include "Base_Server.h"


void
usage (char *message)
{
  // @@ Mayur, what use is there in placing a space before a newline
  //    character?
  //
  // @@ Mayur, have you considered using string concatenation to make
  //    the following usage message more readable?  For example:
  //
  //      static const char * usage =
  //        "invoke as: mt_server -o <ior_output_file>\n"
  //        "-n <num_threads>\n"
  //        "-s <sleep_time (in microseconds)>\n";

  static const char * usage =
    "invoke as: st_server -o <ior_output_file> \n -s <sleep_time (in microseconds)> \n";

  // @@ Mayur, why don't you just place the usage message directly in
  //    the below ACE_ERROR macro?  It's not a big deal.  It's just
  //    something we normally do.
  ACE_ERROR ((LM_ERROR, "%s : %s", message, usage));
}

int
main (int argc, char *argv[])
{
  Base_Server amh_server (&argc, argv);
  amh_server.try_RT_scheduling();
  amh_server.start_orb_and_poa ();

  if (amh_server.parse_args () != 1)
    {
      usage (ACE_const_cast (char *, "IOR file missing \n"));
      ACE_OS::exit (1);
    }

  AMH_Servant servant (amh_server.orb ());

  if (servant.parse_args (&argc, argv) != 1)
    {
      // @@ Mayur, what use is there in placing a space before a newline
      //    character?
      //
      // @@ Mayur, why are you casting away the const-ness?  Just make
      //    your usage() function accept "const char *".
      usage (ACE_const_cast (char *, "Sleep time unspecified \n"));
      ACE_OS::exit (1);
    }

  amh_server.register_servant (&servant);
  amh_server.run_event_loop ();

  return 0;
}
