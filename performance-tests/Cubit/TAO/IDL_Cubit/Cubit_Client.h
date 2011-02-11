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
#include "tao/ORB_Constants.h"
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
  Cubit_Client (int shutdown = 0);

  ~Cubit_Client (void);

  int run ();
  // Execute client example code.

  int init (int argc, ACE_TCHAR **argv);
  // Initialize the client communication endpoint with server.
  // <collocation_test_ior> is used to pass in the ior file name.

private:
  int func (u_int i);
  // Simple function that returns the subtraction of 117 from the
  // parameter.

  int read_ior (const ACE_TCHAR *filename);
  // Function to read the cubit factory ior from a file.

  int parse_args (void);
  // Parses the arguments passed on the command line.

  u_int opt_to_mask (const ACE_TCHAR *opt);
  // Obtain the bit mask representation of the specified test

  void enable_test (u_int mask);
  // Enable the specified test.

  void disable_test (u_int mask);
  // Disable the specified test.

  int check_enabled (u_int mask) const;
  // Check if the specified test has been enabled.

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

  void cube_any_struct (int i);
  // calculate the cube from a struct in an any.

  void cube_any (int i);
  // calculate the cube from a long in an any.

  int shutdown_server (int do_shutdown);
  // Invoke the method with <do_shutdown> != 0 to shutdown the server.

  int argc_;
  // # of arguments on the command line.

  ACE_TCHAR **argv_;
  // arguments from command line.

  ACE_TCHAR *cubit_factory_key_;
  // Key of factory obj ref.

  u_int loop_count_;
  // Number of times to do the cube operations.

  int shutdown_;
  // Flag to tell server to shutdown.

  int quiet_;
  // If set the test goes into quiet mode

  CORBA::ORB_var orb_;
  // Remember our orb, must show up before the other objects to
  // shutdown in the proper order.

  Cubit_Factory_var factory_;
  // factory pointer for cubit.

  Cubit_var cubit_;
  // Cubit obj ref.

  u_int call_count_;
  // # of calls made to functions.

  u_int error_count_;
  // # of errors incurred in the lifetime of the application.

  FILE *cubit_factory_ior_file_;
  // File from which to obtain the IOR.

  ACE_HANDLE f_handle_;
  // File handle to read the IOR.

  u_int bytes_in_octet_sequence_;
  // The number of bytes to send in the octet sequence test.

  u_int test_enable_bitset_;
  // Bitset that determines which tests get run.

  u_int test_disable_bitset_;
  // Bitset that determines which tests do not get run.
};

#endif /* _CUBIT_CLIENT_H */
