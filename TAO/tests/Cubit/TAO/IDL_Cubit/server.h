// -*- c++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/IDL_Cubit
//
// = FILENAME
//    server.h
//
// = DESCRIPTION
//      This class implements a simple "cube" CORBA server for the Cubit
//      example using skeletons generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//    Nagarajan Surendran (naga@cs.wustl.edu)
//
// ============================================================================

#if !defined (_C_SERVER_H)
#define _C_SERVER_H

#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"
#include "tao/tao_util.h"
#include "orbsvcs/CosNamingC.h"
#include "cubit_i.h"
#include "orbsvcs/Naming/Naming_Utils.h"

class Cubit_Server : public TAO_ORB_Manager
{
  // =TITLE
  //   Defines a Cubit Server class that implements the functionality
  //   of a server process as an object.
  //
  // =DESCRIPTION
  //   The interface is quite simple. A server program has to call
  //   init to initialize the cubit_server's state and then call run
  //   to run the orb.
public:

  Cubit_Server (void);
  // Default constructor

  ~Cubit_Server (void);
  // Destructor

  int init (int argc,
            char **argv,
	    CORBA::Environment& env);
  // Initialize the Cubit_Server state - parsing arguments and ...

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

  Cubit_Factory_i factory_impl_;
  // Implementation object of the cubit factory.
       
  Cubit_Factory_var factory;
  // Factory_var to register with NamingService.

  CosNaming::NamingContext_var cubit_context_;
  // Naming context for the cubit_factory.

  CosNaming::NamingContext_var naming_context_;
  // Naming context for the Naming Service.

  int argc_;
  // Number of commandline arguments.

  char **argv_;
  // commandline arguments.
};

#endif /* _C_SERVER_H */
