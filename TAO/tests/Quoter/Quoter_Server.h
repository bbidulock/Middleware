// $Id$
// -*- C++ -*-

// ============================================================================
//
// = LIBRARY
//    TAO/tests/Quoter
//
// = FILENAME
//    quoter_server.h
//
// = DESCRIPTION
//    @@@ Working on it
//
// = AUTHORS
//    Darrell Brunsch 
//
// ============================================================================

#if !defined (QUOTER_SERVER_H)
#define QUOTER_SERVER_H

#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"
#include "orbsvcs/CosNamingC.h"
#include "quoter_impl.h"
#include "quoterC.h"
#include "orbsvcs/Naming/Naming_Utils.h"
#include "tao/tao.h"



class Quoter_Server : public TAO_ORB_Manager
{
  // =TITLE
  //   Defines a Quoter Server class that implements the functionality
  //   of a server process as an object.
  //
  // =DESCRIPTION
  //   The interface is quite simple. A server program has to call
  //   init to initialize the quoter_server's state and then call run
  //   to run the orb.
public:

  Quoter_Server (void);
  // Default constructor

  ~Quoter_Server (void);
  // Destructor

  int init (int argc, char **argv, CORBA::Environment& env);
  // Initialize the Quoter_Server state - parsing arguments and ...

  int run (CORBA::Environment& env);
  // Run the orb 

private:
  int parse_args (void);
  // Parses the commandline arguments.

  int init_naming_service (CORBA::Environment &env);
  // Initialises the name server and registers cubit factory with the
  // name server.

  int num_of_objs_;
  // Number of cubit objects we export.

  int use_naming_service_;
  //Flag to tell server not to use the TAO Naming Service to register
  //the cubit factory.

  FILE* ior_output_file_;
  // File to output the cubit factory IOR.

  TAO_Naming_Server my_name_server_;
  // An instance of the name server used for registering the factory
  // objects.

  Quoter_Factory_Impl factory_impl_;
  // Implementation object of the cubit factory.
       
  Stock::Quoter_Factory_var factory;
  // Factory_var to register with NamingService.

  CosNaming::NamingContext_var quoter_context_;
  // Naming context for the cubit_factory.

  CosNaming::NamingContext_var naming_context_;
  // Naming context for the Naming Service.

  int argc_;
  // Number of commandline arguments.

  char **argv_;
  // commandline arguments.
};

#endif /* QUOTER_SERVER_H */
