// $Id$

#include "simple_object_impl.h"
#include "tao/corba.h"

ACE_RCSID(Simple, simple_object_impl, "$Id$")

// Constructor

Simple_Impl::Simple_Impl (const char *)
{
}


// Destructor

Simple_Impl::~Simple_Impl (void)
{
}

// Cube a long

CORBA::Long
Simple_Impl::simple_method (CORBA::Long l, CORBA::Environment &env)
{
  ACE_UNUSED_ARG (env);
  return l * l * l;
}

// Shutdown.

void Simple_Impl::shutdown (CORBA::Environment &env)
{
  ACE_UNUSED_ARG (env);

  ACE_DEBUG ((LM_DEBUG, "%s\n", "Simple_Impl is shutting down"));

  TAO_ORB_Core_instance ()->orb ()->shutdown ();
}

