// -*- c++ -*-
// $Id$
// ============================================================================
//
// = LIBRARY
//    TAO/tests/Concurrency
//
// = FILENAME
//    CC_client.h
//
// = DESCRIPTION
//      This class implements a client used to test the CosConcuurency
//      service.
//
// = AUTHORS
//    Torben Worm <tworm@cs.wustl.edu>
//
// ============================================================================

#include "ace/Get_Opt.h"
#include "tao/corba.h"
#include "orbsvcs/CosConcurrencyControlC.h"
#include "orbsvcs/CosNamingC.h"
#include "CC_tests.h"
#include "CC_naming_service.h"

#if !defined(_CC_CLIENT_H_)
#define _CC_CLIENT_H_

class CC_Client
{
  // = TITLE
  //    Defines a class that encapsulates the behaviour of a clien of the
  //    concurrency service.
  //
  // = DESCRIPTION
  //    This class declares an interface to run the test client for the
  //    concurrency service.
  //
public:
  CC_Client(void);
  // Default constructor

  ~CC_Client(void);

  int run(void);
  // Run the test

  int init(int argc, char **argv);
  // Initialize the test with the parameters from the command line

private:
  int init_naming_service(void);
  // Function to initialize the naming service.

  CC_naming_service *naming_service_;
  // A pointer to the naming service used for this test

  int parse_args(void);
  // Function to parse the command line arguments

  int read_ior(char *filename);
  // Function to read the ior from the given file

  int run_basic_tests(void);
  // Runs the basic tests (on a single lock set). Returns CC_SUCCESS
  // upon success CC_FAIL otherwise

  int run_extended_tests(char lock_set_name);
  // Runs the basic tests (on more lock sets). Returns CC_SUCCESS
  // upon success CC_FAIL otherwise

  FILE *cc_factory_ior_file_;
  // File from which to obtain the IOR.

  char *cc_factory_key_;
  // The factory key for the lock set factory

  ACE_HANDLE f_handle_;
  // File handle to read the IOR.

  int shutdown_;
  // Flag to tell server to shutdown.

  CORBA::ORB_var orb_;
  // Remember our orb.

  //  CosConcurrencyControl::LockSetFactory_var factory_;
  // factory pointer for the lock set. @@TAO maybe to be used when naming
  // service is not used (for simple testing)

  int argc_;
  // The number of arguments passed on the command line

  char **argv_;
  // The arguments from the command line

  int use_naming_service_;
  // Flag to tell the client whether to use the naming service or not
  // to find the concurrency control factory.

  int run_basic_tests_;
  // flag to tell which test should be run

  void print_usage(void);
  // Prints out the options to the program
};
#endif /* !defined(_CC_CLIENT_H_) */
