//
// $Id$
//

#ifndef HELLO_H
#define HELLO_H

#include /**/ "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

class Hello
  : public virtual POA_Test::Hello
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  Hello(CORBA::ORB_ptr orb, bool simulate_crashes);

  virtual void short_sleep (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  CORBA::ORB_var orb_;

  bool simulate_crashes_;

  ACE_Atomic_Op<TAO_SYNCH_MUTEX,long> atomic_counter_;
};

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* HELLO_H */
