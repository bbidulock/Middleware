// $Id$

#include "POA_Guard.h"
#include "POA.h"
#include "tao/ORB_Constants.h"

ACE_RCSID(PortableServer, POA_GUARD, "$Id$")

TAO_POA_Guard::TAO_POA_Guard (TAO_POA &poa
                              ACE_ENV_ARG_DECL,
                              int check_for_destruction)
  : guard_ (poa.lock ())
{
  if (!this->guard_.locked ())
    ACE_THROW (
      CORBA::INTERNAL (
        CORBA::SystemException::_tao_minor_code (
          TAO_GUARD_FAILURE,
          0),
        CORBA::COMPLETED_NO));

  // Check if a non-servant upcall is in progress.  If a non-servant
  // upcall is in progress, wait for it to complete.  Unless of
  // course, the thread making the non-servant upcall is this thread.
  poa.object_adapter ().wait_for_non_servant_upcalls_to_complete (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  if (check_for_destruction &&
      poa.cleanup_in_progress ())
    ACE_THROW (
      CORBA::BAD_INV_ORDER (
        CORBA::SystemException::_tao_minor_code (
          TAO_POA_BEING_DESTROYED,
          0),
        CORBA::COMPLETED_NO));
}


