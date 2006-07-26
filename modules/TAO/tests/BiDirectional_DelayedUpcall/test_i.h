// $Id$

// ============================================================================
//
// = LIBRARY
//   TAO/tests/BiDirectional
//
// = FILENAME
//   test_i.h
//
// = AUTHOR
//   Balachandran Natarajan <bala@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_BIDIRECTIONAL_TEST_I_H
#define TAO_BIDIRECTIONAL_TEST_I_H

#include "testS.h"
#include "ace/Event_Handler.h"

class Callback_i : public virtual POA_Callback
{
  // = TITLE
  //   A callback object to the "client"
  //
  // = DESCRIPTION
  //   To test that the server can call the client on the same
  //   connection that was established by the client
  //
public:
  Callback_i (CORBA::ORB_ptr orb);
  // ctor

  void shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Safe way to shutdown

  void callback_method (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // The callback method

private:
  CORBA::ORB_var orb_;
  // The orb
};

class Simple_Server_i : public virtual POA_Simple_Server, ACE_Event_Handler
{
  // = TITLE
  //   Simpler Server implementation
  //
  // = DESCRIPTION
  //   Implements the Simple_Server interface in test.idl
  //
public:
  Simple_Server_i (CORBA::ORB_ptr orb, int no_iterations);
  // ctor

  // = The Simple_Server methods.
  CORBA::Long test_method (CORBA::Boolean do_callback
                           ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void callback_object (Callback_ptr callback
                        ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void shutdown (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual int handle_timeout (const ACE_Time_Value &current_time,
                              const void *act = 0);

private:
  CORBA::ORB_var orb_;
  // The ORB

  int flag_;
  // Flag to indicate, whether we are ready for a remote call.

  Callback_var callback_;
  // Callback Object

  int no_iterations_;
  // Number of times the callback needs to be called
};

#if defined(__ACE_INLINE__)
#include "test_i.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_BIDIRECTIONAL_TEST_I_H */
