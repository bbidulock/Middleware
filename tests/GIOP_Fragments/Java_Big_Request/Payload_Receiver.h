//
// $Id$
//

#ifndef JAVA_BIG_REQUEST_PAYLOAD_RECEIVER_H
#define JAVA_BIG_REQUEST_PAYLOAD_RECEIVER_H
#include /**/ "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::Payload_Receiver interface
/**
 * Simply print count how many bytes were received.
 */
class Payload_Receiver
  : public virtual POA_Test::Payload_Receiver
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  Payload_Receiver (CORBA::ORB_ptr orb);

  // = The skeleton methods
  virtual void more_data (const Test::Payload &payload
                          ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Test::Payload_Receiver::Invalid_Payload));

  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  int get_count (void) const;

public:
  int count_;
  CORBA::ORB_var orb_;
};

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* JAVA_BIG_REQUEST_PAYLOAD_RECEIVER_H */
