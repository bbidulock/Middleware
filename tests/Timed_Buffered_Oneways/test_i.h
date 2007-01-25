// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//   TAO/tests/Timed_Buffered_Oneways/
//
// = FILENAME
//   test_i.h
//
// = AUTHOR
//   Irfan Pyarali
//
// ============================================================================

#ifndef TAO_TIMED_BUFFERED_ONEWAYS_TEST_I_H
#define TAO_TIMED_BUFFERED_ONEWAYS_TEST_I_H

#include "testS.h"

class test_i : public POA_test
{
  // = TITLE
  //   Simple implementation.
  //
public:
  test_i (CORBA::ORB_ptr orb);
  // ctor.

  // = The test interface methods.
  void method (CORBA::ULong request_number,
               CORBA::Long start_time,
               const test::data &,
               CORBA::ULong work)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void flush (void)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void shutdown (CORBA::Long start_time)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  CORBA::ORB_var orb_;
  // The ORB.
};

#endif /* TAO_TIMED_BUFFERED_ONEWAYS_TEST_I_H */
