//$Id$

#include "Counter_i.h"

ACE_RCSID(tao, Counter_Servant, "$Id$")

// Dtor-Ctor Implementation.

Counter_Servant::Counter_Servant (Policy_Tester *policy_tester)
  : count_ (0),
    policy_tester_ (policy_tester)
{
  // No-Op.
}

Counter_Servant::~Counter_Servant (void)
{
  // No-Op.
}

// Counter Interface Methods Implementation.

void
Counter_Servant::increment (TAO_ENV_SINGLE_ARG_DECL_NOT_USED/*TAO_ENV_SINGLE_ARG_PARAMETER*/)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ++this->count_;
}

CORBA::Long
Counter_Servant::get_count (TAO_ENV_SINGLE_ARG_DECL_NOT_USED/*TAO_ENV_SINGLE_ARG_PARAMETER*/)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->count_;
}

void
Counter_Servant::reset (TAO_ENV_SINGLE_ARG_DECL_NOT_USED/*TAO_ENV_SINGLE_ARG_PARAMETER*/)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->count_ = 0;
}

void
Counter_Servant::shutdown (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->policy_tester_->shutdown (TAO_ENV_SINGLE_ARG_PARAMETER);
  ACE_TRY_CHECK;
}
