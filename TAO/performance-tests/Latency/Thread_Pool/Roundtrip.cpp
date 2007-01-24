//
// $Id$
//
#include "Roundtrip.h"

ACE_RCSID(Thread_Pool_Latency, Roundtrip, "$Id$")

Roundtrip::Roundtrip (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

Test::Timestamp
Roundtrip::test_method (Test::Timestamp send_time
                        ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return send_time;
}

void
Roundtrip::shutdown (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0 ACE_ENV_ARG_PARAMETER);
}
