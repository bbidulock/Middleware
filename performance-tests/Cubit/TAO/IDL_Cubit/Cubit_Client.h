// -*- c++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/tests/IDL_Cubit
//
// = FILENAME
//    Cubit_Client.h
//
// = DESCRIPTION
//      This class implements a simple "cube" CORBA client for the Cubit
//      example using stubs generated by the TAO ORB IDL compiler.
//
// = AUTHORS
//    Aniruddha Gokhale, Sumedh Mungee, and Sergio Flores-Gaitan
//
// ============================================================================

#ifndef _CUBIT_CLIENT_H
#define _CUBIT_CLIENT_H

#include "ace/Get_Opt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

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
  Cubit_Client (int testing_collocation = 1, int shutdown = 0);
  // Use <testing_collocation> to control some client's behaviors.

  ~Cubit_Client (void);

  int run (void);
  // Execute client example code.

  int init (int argc, char **argv, char *collocation_test_ior = 0);
  // Initialize the client communication endpoint with server.
  // <collocation_test_ior> is used to pass in the ior file name.

private:
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

  void cube_oneway (int i);
  // Oneway operation test.

  void cube_void (int i);
  // Twoway operation test.

  void cube_octet (int i);
  // Cube an octet.

  void cube_short (int i);
  // Cube a short.

  void cube_long_sequence (int i, int l);
  // Cube a sequence <l> is the length of the sequence.

  void cube_octet_sequence (int i, int l);
  // Cube a sequence of octets, <l> is the length of the sequence.

  void cube_many_sequence (int i, int l);
  // Cube a sequence of manys, <l> is the length of the sequence.

  void cube_rti_data (int i, int numUpdates, int numAttrs);
  // Cube a sequence <l> is the length of the sequence.

  int run_void (void);
  // This method runs only the cube_void() test.

  int run_oneway (void);
  // This method runs only the cube_oneway() test.

  int shutdown_server (int do_shutdown);
  // Invoke the method with <do_shutdown> != 0 to shutdown the server.
  // When testing collocation, <do_shutdown> has no effect (it always
  // shuts the server down.

  int argc_;
  // # of arguments on the command line.

  char **argv_;
  // arguments from command line.

  char *cubit_factory_key_;
  // Key of factory obj ref.

  u_int loop_count_;
  // Number of times to do the cube operations.

  int shutdown_;
  // Flag to tell server to shutdown.

  Cubit_Factory_var factory_;
  // factory pointer for cubit.

  CORBA::Environment env_;
  // Environment variable.

  Cubit_var cubit_;
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

  int only_void_;
  // Run only the cube_void() test.

  int only_oneway_;
  // Run only the cube_oneway() test.

  int testing_collocation_;
  // We are running the collocation test.
};

#endif /* _CUBIT_CLIENT_H */
