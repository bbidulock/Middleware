// -*- C++ -*-
// $Id$

#include "Filter.h"

int
main (int argc, char *argv [])
{
  FilterClient client;

  try
    {
      client.init (argc, argv); //Init the Client

      client.run ();
    }
  catch (const CORBA::UserException& ue)
    {
      ue._tao_print_exception ("TLS_Client user error: ");
      return 1;
    }
  catch (const CORBA::SystemException& se)
    {
      se._tao_print_exception ("Filter system error: ");
      return 1;
    }

  return 0;
}
