//$Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/Simple
//
// = FILENAME
//    Simple_Util.h
//
// = DESCRIPTION
//    The classe define the templates for the client and server.
//
// = AUTHOR
//   Balachandran Natarajan <bala@cs.wustl.edu> 
//
// ============================================================================

#ifndef TAO_UTIL_H
#define TAO_UTIL_H

#include "tao/TAO.h"
#include "orbsvcs/Naming/Naming_Utils.h"
#include "ace/Get_Opt.h"
#include "ace/Read_Buffer.h"

template <class Servant>
class Server
{
  // = TITLE
  //   A set of useful class Templates for using the TAO CORBA implementation.
  //
  // = DESCRIPTION
  //   A template server definition. This template can be used by 
  //   single server/client projects for defintion of their server/
  //   clients. Pl. see the directories time, bank, echo for further
  //   details of implemenatation.
public:
  // = Initialization and termination methods.

  Server (void);
  // Constructor.

  ~Server (void);
  // Destructor.

  int init (const char *servant_name, 
            int argc, 
            char *argv[], 
            CORBA::Environment &env);
  // Initialize the Server state - parsing arguments and waiting.
  // interface_name is the name used to register the Servant.

  void register_name (void);
  // after calling init(), this method will register the server with
  // the TAO Naming Service using the servant_name passed to init().

  int run (CORBA::Environment &env);
  // Run the orb.

protected:
  Servant servant_;
  // Servant class

  const char *name;
  // name of the servant to be used for TAO Naming Service

  int parse_args (void);
  // Parses the commandline arguments.

  TAO_ORB_Manager orb_manager_;
  // The ORB manager - a helper class for accessing the POA and
  // registering objects.

  TAO_Naming_Client namingClient;
  // helper class for getting access to Naming Service.

  FILE *ior_output_file_;
  // File where the IOR of the server object is stored.

  int argc_;
  // Number of command line arguments.

  char **argv_;
  // The command line arguments.
};

template <class InterfaceObj, class Var>
class Client
{
  // = TITLE
  //   Template Client class
  //
  // = DESCRIPTION
  //   A template client implementation for a single server/client
  //   model. The example usage of these usage can be found in the 
  //   sub-directories below
public:

  // = Initialization and termination methods.
  Client (void);
  // Constructor.

  ~Client (void);
  // Destructor.

  int init (int argc, char *argv[]);
  // Initialize the client communication endpoint with server.

  InterfaceObj *operator-> () { return server_.in ();};
  // Return the interface object pointer.

  int shutdown (void );
  // Returns the shutdown flag.
  
  void shutdown (int);
  // Fills in the shutdwon flag.

protected:
  int read_ior (char *filename);
  // Function to read the server IOR from a file.

  int parse_args (void);
  // Parses the arguments passed on the command line.

  int argc_;
  // # of arguments on the command line.

  char **argv_;
  // arguments from command line.

  char *ior_;
  // IOR of the obj ref of the server.

  CORBA::Environment env_;
  // Environment variable.

  Var server_;
  // Server object

  int shutdown_;
  // Flag for shutting down the server
  
  CORBA::ORB_var orb_;
  // Remember our orb.
};

#endif /* TAO_UTIL_H */
