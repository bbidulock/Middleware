// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/bin/Naming_Service/TAO
//
// = FILENAME
//    clnt.cpp
//
// = DESCRIPTION
//      This class implements a simple "cube" CORBA client for the CosNaming 
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//      Sergio Flores-Gaitan <sergio@cs.wustl.edu>
//
// ============================================================================

#include "clnt.h"

// constructor

CosNaming_Client::CosNaming_Client (void)
  : argc_ (0),
    argv_ (0),
    exit_later_ (0)
{
}

// Parses the command line arguments and returns an error status.

int
CosNaming_Client::parse_args (void)
{
  ACE_Get_Opt get_opts (argc_, argv_, "dx");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag
	TAO_debug_level++;
	break;
      case 'x':
	this->exit_later_++;
	break;
      case '?':
      default:
	ACE_ERROR_RETURN ((LM_ERROR,
			   "usage:  %s"
			   " [-d]"
			   " [-x]"
			   "\n",
                           this->argv_ [0]), 
                          -1);
      }

  // Indicates successful parsing of command line.
  return 0;  
}

// Execute client example code.

int
CosNaming_Client::run (void)
{
  // @@ TODO, add some interesting test here, maybe creating some
  // nested naming contexts and registering a number of objreferences
  // in there.
  // We could even use the iterators.
  return 0;
}

CosNaming_Client::~CosNaming_Client (void)
{
}

int
CosNaming_Client::init (int argc, char **argv)
{
  this->argc_ = argc;
  this->argv_ = argv;

  TAO_TRY
    {
      // Initialize ORB.
      CORBA::ORB_var orb = 
	CORBA::ORB_init (argc, argv, "internet", TAO_TRY_ENV);
      TAO_CHECK_ENV;

      CORBA::Object_var naming_obj =
	orb->resolve_initial_references ("NameService");
      if (CORBA::is_nil (naming_obj.in ()))
	ACE_ERROR_RETURN ((LM_ERROR,
			   " (%P|%t) Unable to initialize the POA.\n"),
			  -1);

      CosNaming::NamingContext_var naming_context = 
        CosNaming::NamingContext::_narrow (naming_obj.in (), TAO_TRY_ENV);
      TAO_CHECK_ENV;
      
      // Parse command line and verify parameters.
      if (this->parse_args () == -1)
	return -1;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("init");
      return -1;
    }
  TAO_ENDTRY;

  return 0;
}

// This function runs the test.

int
main (int argc, char **argv)
{
  CosNaming_Client cosnaming_client;
  
  if (cosnaming_client.init (argc, argv) == -1)
    return 1;

  return cosnaming_client.run ();
}
