// -*- C++ -*-

#include "Request_Interceptor.h"

ACE_RCSID (Request_Interceptor_Flow,
           Request_Interceptor,
           "$Id$")

Request_Interceptor::Request_Interceptor (const char *name)
  : name_ (name),
    starting_interception_point_count_ (0),
    ending_interception_point_count_ (0)
{
}

char *
Request_Interceptor::name (
    TAO_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CORBA::string_dup (this->name_.in ());
}

void
Request_Interceptor::destroy (TAO_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_ENV_ARG_DEFN;

  CORBA::ULong s_count =
    this->starting_interception_point_count_.value ();

  CORBA::ULong e_count =
    this->ending_interception_point_count_.value ();

  if (s_count != e_count)
    {
      ACE_ERROR ((LM_ERROR,
                  "(%P) ERROR: Interceptor \"%s\"\n"
                  "(%P) The number of starting interception point "
                  "calls (%u)\n"
                  "(%P) did not equal the number of ending "
                  "interception \n"
                  "(%P) point calls (%u).\n\n",
                  this->name_.in (),
                  s_count,
                  e_count));

      ACE_THROW (CORBA::INTERNAL ());
    }
}
