//
// $Id$
//

#ifndef CALLBACK_CALLBACK_H
#define CALLBACK_CALLBACK_H
#include /**/ "ace/pre.h"

#include "TestS.h"

/// Implement the Test::Callback interface
class Callback
  : public virtual POA_Test::Callback
{
public:
  /// Constructor
  Callback (CORBA::ORB_ptr orb);

  // = The skeleton methods
  virtual CORBA::Boolean are_you_there (CORBA::String_out answer)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void test_oneway (void)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void shutdown (void)
    ACE_THROW_SPEC ((CORBA::SystemException));
private:
  /// Use an ORB reference to shutdown the application.
  CORBA::ORB_var orb_;
};

#include /**/ "ace/post.h"
#endif /* CALLBACK_CALLBACK_H */
