// -*- c++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/IDL_Cubit
//
// = FILENAME
//    client.h
//
// = DESCRIPTION
//      This class implements a simple "cube" CORBA client for the Cubit
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//    Aniruddha Gokhale, Sumedh Mungee, and Sergio Flores-Gaitan
//
// ============================================================================

#include "ace/Get_Opt.h"
#include "ace/Profile_Timer.h"
#include "tao/corba.h"
#include "cubitC.h"

class Cubit_Client
{
  // = TITLE
  //    Defines a class that encapsulates behaviour of the Cubit client
  //    example.  Provides a better understanding of the logic in an
  //    object oriented way.
  //
  // = DESCRIPTION
  //    This class declares an interface to run the example client for
  //    Cubit CORBA server.  All the complexity for initializing the
  //    server is hidden in the class.  Just the run() interface is needed.
public:
  // = Constructor and destructor.
  Cubit_Client (void);
  ~Cubit_Client (void);

  int run (int testing_collocation = 0);
  // Execute client example code.

  int init (int argc, char **argv);
  // Initialize the client communication endpoint with server.

private:
  int init_naming_service (void);
  // Function to initialize the naming service.

  int func (u_int i);
  // Simple function that returns the substraction of 117 from the
  // parameter.

  int read_ior (char *filename);
  // Function to read the cubit factory ior from a file.

  int parse_args (void);
  // Parses the arguments passed on the command line.

  void print_stats (const char *call_name,
                    ACE_Profile_Timer::ACE_Elapsed_Time &elapsed_time);
  // Prints the time stats.

  void cube_union (void);
  // Exercise the union.  Cube a union.

  void cube_struct (int i);
  // calculate the cube from a struct.

  void cube_long (int i);
  // calculate the cube from a long.

  void cube_octet (int i);
  // Cube an octet.

  void cube_short (int i);
  // Cube a short.

  void cube_long_sequence (int i, int l);
  // Cube a sequence <l> is the length of the sequence.

  void cube_octet_sequence (int i, int l);
  // Cube a sequence of octets, <l> is the length of the sequence.

  int argc_;
  // # of arguments on the command line.

  char **argv_;
  // arguments from command line.

  char *cubit_factory_key_;
  // Key of factory obj ref.

  char *cubit_key_;
  // Key of the obj ref to be retrieved via the factory.

  u_int loop_count_;
  // Number of times to do the cube operations.

  int shutdown_;
  // Flag to tell server to shutdown.

  Cubit_Factory_var factory_;
  // factory pointer for cubit.

  CORBA::Environment env_;
  // Environment variable.

  Cubit_ptr cubit_;
  // Cubit obj ref.

  CORBA::ORB_var orb_;
  // Remember our orb.

  u_int call_count_;
  // # of calls made to functions.

  u_int error_count_;
  // # of errors incurred in the lifetime of the application.

  FILE *cubit_factory_ior_file_;
  // File from which to obtain the IOR.

  ACE_HANDLE f_handle_;
  // File handle to read the IOR.

  int use_naming_service_;
  // Flag to tell client not to use Namingservice to find the cubit
  // Factory.
};
