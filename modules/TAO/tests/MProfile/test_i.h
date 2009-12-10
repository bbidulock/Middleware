// $Id$

// ============================================================================
//
// = LIBRARY
//   TAO/tests/Mprofile
//
// = FILENAME
//   test_i.h
//
// = AUTHOR
//   Carlos O'Ryan <coryan@uci.edu>
//
// ============================================================================

#ifndef TAO_MPROFILE_TEST_I_H
#define TAO_MPROFILE_TEST_I_H

#include "testS.h"

class Simple_Server_i : public POA_Simple_Server
{
  // = TITLE
  //   Simpler Server implementation
  //
  // = DESCRIPTION
  //   Implements the Simple_Server interface in test.idl
  //
public:
  Simple_Server_i (CORBA::ORB_ptr orb);
  // ctor

  Simple_Server_i (void);
  // ctor

  // = The Simple_Server methods.
  CORBA::Long remote_call (void);

  void shutdown (void);

private:
  CORBA::ORB_var orb_;

  CORBA::Long val_;

};

#endif /* TAO_MPROFILE_TEST_I_H */
