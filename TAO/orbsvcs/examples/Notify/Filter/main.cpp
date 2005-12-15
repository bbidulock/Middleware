// -*- C++ -*-
// $Id$

#include "Filter.h"
#include "ace/Argv_Type_Converter.h"

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Argv_Type_Converter convert (argc, argv);

  FilterClient client;

  ACE_TRY_NEW_ENV
    {
      client.init (convert.get_argc(), convert.get_ASCII_argv()
                   ACE_ENV_ARG_PARAMETER); //Init the Client
      ACE_TRY_CHECK;

      client.run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCH (CORBA::UserException, ue)
    {
      ACE_PRINT_EXCEPTION (ue,
                           "TLS_Client user error: ");
      return 1;
    }
  ACE_CATCH (CORBA::SystemException, se)
    {
      ACE_PRINT_EXCEPTION (se,
                           "Filter system error: ");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}
