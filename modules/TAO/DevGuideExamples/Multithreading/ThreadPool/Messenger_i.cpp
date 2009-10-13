/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "Messenger_i.h"
#include "ace/Thread.h"
#include <iostream>

#include <sstream>

// Implementation skeleton constructor
Messenger_i::Messenger_i (void)
{
}

// Implementation skeleton destructor
Messenger_i::~Messenger_i (void)
{
}

CORBA::Boolean Messenger_i::send_message (
    const char* /*user_name*/,
    const char* /*subject*/,
    char *& message
  )
{
  CORBA::string_free(message);

  std::ostringstream ostr;
  ostr << "Message handled on thread " << ACE_Thread::self();
  message = CORBA::string_dup(ostr.str().c_str());
  return true;
}

