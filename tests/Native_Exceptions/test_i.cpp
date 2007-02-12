// $Id$

#include "test_i.h"

#if !defined(__ACE_INLINE__)
#include "test_i.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Native_Exceptions, test_i, "$Id$")

CORBA::Long
Simple_Server_i::test_method (CORBA::Long x)
{
  return x;
}

CORBA::Long
Simple_Server_i::test_raise (CORBA::Long x)
{
  ACE_UNUSED_ARG (x);
  throw Simple_Server::Failure ();

# if defined (WIN32) || defined (__HP_aCC)
  return x;
#endif /*WIN32 & HP */
}

void
Simple_Server_i::shutdown (void)
{
  this->orb_->shutdown ();
}
