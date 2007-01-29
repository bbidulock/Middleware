// $Id$

#include "Hello.h"


ACE_RCSID (Recursive,
           Hello,
           "$Id$")


Hello::Hello (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

CORBA::Any *
Hello::get_any (CORBA::Any const & the_any)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  CORBA::Any * retval = 0;

  ACE_NEW_THROW_EX (retval,
                    CORBA::Any (the_any),
                    CORBA::NO_MEMORY ());

  return retval;
}


void
Hello::shutdown (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->orb_->shutdown (0);
}
