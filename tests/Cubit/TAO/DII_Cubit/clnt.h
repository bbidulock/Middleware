// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/DII_Cubit
//
// = FILENAME
//    clnt.h
//
// = DESCRIPTION
//      This class implements a simple wrapper around the "cube" CORBA 
//      client for the Cubit example using stubs generated by the TAO 
//      ORB IDL compiler.
//
// = AUTHORS
//      Sergio Flores-Gaitan
//
// ============================================================================

#include "ace/Get_Opt.h"
#include "tao/corba.h"
#include "cubitC.h"

class ACE_winsock_proper_shutdown
// @@ We need this helper class to properly shutdown
// WinSock before we figure out how to do this properly.
{
public:
  ~ACE_winsock_proper_shutdown (void)
  {
    ACE_OS::socket_fini ();
  }
};

class Cubit_Client 
  // = TITLE
  //    Defines a class that encapsulates behaviour of the Cubit client
  //    example.  Provides a better understanding of the logic in an 
  //    object oriented way.
  //
  // = DESCRIPTION
  //    This class declares an interface to run the example client for
  //    Cubit CORBA server.  All the complexity for initializing the 
  //    server is hidden in the class.  Just the run() interface is needed.
{
public:
  // = Constructor and destructor.
  Cubit_Client (void);
  ~Cubit_Client (void);

  int run (void);
  // Execute client example code.

  int init (int argc, char **argv);
  // Initialize the client communication endpoint with server.

private:
  int func (u_int i);
  // simple function that returns the substraction of 117 from the parameter.

  int parse_args (void);
  // Parses the arguments passed on the command line.

  void print_stats (const char *call_name, ACE_Profile_Timer::ACE_Elapsed_Time &elapsed_time);
  // prints the time stats

  void cube_union_stub (void);
  // Exercise the union.  Cube a union.
  
  void cube_union_dii (void);
  // Exercise the union using dii.

  void cube_struct (int i);
  // calculate the cube from a struct.

  void cube_long (int i);
  // calculate the cube from a long

  void cube_octet (int i);
  // Cube an octet

  void cube_short (int i);
  // Cube a short.

  void cube_struct_dii (void);
  // Cube the numbers in a struct

  // private member variables.

  int argc_;
  // # of arguments on the command line.

  char **argv_;
  // arguments from command line.

  u_int loop_count_;
  // Number of times to do the cube operations.

  int exit_later_;
  // Flag to tell server to not exit immediately

  CORBA::Object_ptr objref_;
  // storage of the factory objref
  
  CORBA::Environment env_;
  // Environment variable

  Cubit_ptr cubit_;
  // Cubit obj ref

  CORBA::ORB_ptr orb_ptr_;
  // Remember our orb

  u_int call_count_;
  // # of calls made to functions

  u_int error_count_;
  // #  of errors incurred in the lifetime of the application.

  ACE_winsock_proper_shutdown shutdown_object;
  // Winsock shutdown object.  

  const char *TAO_arg_ior_;
  // pointer to object reference string.

  char *cubit_key_;
  // Key of the obj ref to be retrieved via the factory.

  char *hostname_;
  // Hostname of server.

  CORBA::ULong portnum_;
  // default port number of server.

  char buf_[BUFSIZ];
  // buffer for temporary use
};
