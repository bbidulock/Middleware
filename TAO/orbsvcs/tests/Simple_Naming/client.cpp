// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/Naming_Service/
//
// = FILENAME
//    client.cpp
//
// = DESCRIPTION
//      This class implements a simple CORBA client for the CosNaming
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//      Sergio Flores-Gaitan <sergio@cs.wustl.edu> and 
//      Douglas C. Schmidt <schmidt@cs.wustl.edu>
// ============================================================================

#include "client.h"
#include "ace/Get_Opt.h"
#include "test_objectS.h"

class My_Test_Object : public POA_Test_Object
{
public:
  My_Test_Object (void) {};
  ~My_Test_Object (void) {};
};

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
  TAO_TRY
    {
      My_Test_Object myObject;

      // Dummy object instantiation.
      Test_Object_var myObject_var =
        myObject._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      // Bind an object to the Naming Context.
      CosNaming::Name test_name (1);
      test_name.length (1);
      test_name[0].id =
        CORBA::string_dup ("Foo");

      this->naming_client_->bind (test_name,
                                  myObject_var.in (),
                                  TAO_TRY_ENV);
      TAO_CHECK_ENV;      

      ACE_DEBUG ((LM_DEBUG,
                  "Bound name OK\n"));

      CORBA::Object_var resolvedobj =
        this->naming_client_->resolve (test_name,
                                       TAO_TRY_ENV);
      TAO_CHECK_ENV;

      Test_Object_var resultObject = 
    	Test_Object::_narrow (resolvedobj.in (), 
                              TAO_TRY_ENV);        
      TAO_CHECK_ENV;
      ACE_DEBUG ((LM_DEBUG,
                  "Resolved name OK\n"));

      this->naming_client_->unbind (test_name,
                                    TAO_TRY_ENV);
      TAO_CHECK_ENV;      

      ACE_DEBUG ((LM_DEBUG,
                  "Unbound name OK\n"));
      // @@ TODO, add some more interesting tests here, for instance
      // creating some nested naming contexts and registering a number of
      // objreferences in there.  We could even use the Iterators and the
      // TAO_Client_Naming abstraction to simply this.
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("ns_tree");
      return -1;
    }
  TAO_ENDTRY;
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
      // Parse command line and verify parameters.
      if (this->parse_args () == -1)
	return -1;

      // Initialize ORB.
      this->orbmgr_.init (argc,
                          argv,
                          TAO_TRY_ENV);
      TAO_CHECK_ENV;

      return this->naming_client_.init (this->orbmgr_.orb ());
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
