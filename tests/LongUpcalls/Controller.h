// $Id$

#ifndef LONGUPCALLS_CONTROLLER_H
#define LONGUPCALLS_CONTROLLER_H

#include "TestS.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

class Controller
  : public virtual POA_Test::Controller,
    public virtual PortableServer::RefCountServantBase
{
public:
  Controller (void);
  // Constructor

  void dump_results (void);
  // Print out the results and any errors

  // = The skeleton methods
  virtual void worker_started (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual void worker_finished (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));

private:
  TAO_SYNCH_MUTEX mutex_;
  CORBA::ULong start_count_;
  CORBA::ULong finish_count_;
};

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#endif /* LONGUPCALLS_CONTROLLER_H */
