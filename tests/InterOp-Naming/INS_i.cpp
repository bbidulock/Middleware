// $Id$

#include "INS_i.h"

// Constructor

INS_i::INS_i (void)
{
  // no-op
}

// Destructor

INS_i::~INS_i (void)
{
}

// Set the ORB pointer.

void
INS_i::orb (CORBA::ORB_ptr o)
{
  this->orb_ = CORBA::ORB::_duplicate (o);
}

char * 
INS_i::test_ins (CORBA::Environment &env)
{
  ACE_DEBUG ((LM_DEBUG,
              "Inside Operation\n"));
  return ("Success");
}
