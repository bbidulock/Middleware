// -*- C++ -*-
//
// $Id$

#ifndef ROUNDTRIP_H
#define ROUNDTRIP_H
#include /**/ "ace/pre.h"

#include "TestS.h"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <functional>
#include <fstream>
#include <sys/types.h>
#include <regex.h>

#if defined (_MSC_VER)
# if (_MSC_VER >= 1200)
#  pragma warning(push)
# endif /* _MSC_VER >= 1200 */
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::Roundtrip interface
class Roundtrip
  : public virtual POA_Test::Roundtrip
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  Roundtrip (CORBA::ORB_ptr orb);

  // = The skeleton methods
  virtual Test::Timestamp test_method (Test::Timestamp send_time,
		                       Test::number cl_number,
		                       Test::number it_number
                                       ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual Test::Timestamp test_method_2 (Test::Timestamp send_time,
		                       Test::number cl_number,
		                       Test::number it_number
                                       ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  /// Use an ORB reference to conver strings to objects and shutdown
  /// the application.
  CORBA::ORB_var orb_;

  int count_;
};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* ROUNDTRIP_H */
