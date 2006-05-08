// $Id$

# include "Grid_Client_i.h"
#include "ace/Argv_Type_Converter.h"

// The client program for the application.

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  ACE_Argv_Type_Converter convert (argc, argv);
  Grid_Client_i client;

  ACE_DEBUG ((LM_DEBUG,
              "\nGrid client\n\n"));
  
  if (client.run ("Grid", convert.get_argc(), convert.get_ASCII_argv()) == -1)
    return -1; 
  else
    return 0;
   
}

                                 
