// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/IDL_Cubit
//
// = FILENAME
//    clnt.h
//
// = DESCRIPTION
//      This class implements a simple "cube" CORBA client for the Cubit
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//    Copyright 1994-1995 by Sun Microsystems Inc.
//    and
//    Aniruddha Gokhale, Sumedh Mungee, and Sergio Flores-Gaitan
//
// ============================================================================

#include "ace/Get_Opt.h"
#include "tao/corba.h"
#include "cubitC.h"

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

  void cube_sequence (int i);
  // Cube a sequence.

  void cube_struct_dii (void);
  // Cube the numbers in a struct

  int argc_;
  // # of arguments on the command line.

  char **argv_;
  // arguments from command line.

  const char *cubit_factory_key_;
  // Key of factory obj ref.

  char *cubit_key_;
  // Key of the obj ref to be retrieved via the factory.

  char *hostname_;
  // Hostname of server.

  CORBA::UShort portnum_;
  // default port number of server.

  u_int loop_count_;
  // Number of times to do the cube operations.

  int exit_later_;
  // Flag to tell server to not exit immediately

  Cubit_Factory_ptr factory_;
  // factory pointer for cubit.

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
};
