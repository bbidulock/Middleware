//
// $Id$
//

#ifndef MCASTHELLO_H
#define MCASTHELLO_H
#include /**/ "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# if (_MSC_VER >= 1200)
#  pragma warning(push)
# endif /* _MSC_VER >= 1200 */
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::McastHello interface
class McastHello
  : public virtual POA_Test::McastHello
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  McastHello (CORBA::ORB_ptr orb,
              int instance,
              CORBA::Boolean &status);

  // = The skeleton methods
  virtual void send_forty_two (CORBA::Long forty_two ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void shutdown (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Return whether all test requests have been received successfully.
  CORBA::Boolean get_status ();
private:
  /// Use an ORB reference to convert strings to objects and shutdown
  /// the application.
  CORBA::ORB_var orb_;

  /// The instance number. (Useful when debugging multiple servants)
  int instance_;

  /// Track the success/failure of the small request.
  CORBA::Boolean small_request_status_;

  /// Track the success/failure of the large request.
  CORBA::Boolean large_request_status_;
};

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* MCASTHELLO_H */
