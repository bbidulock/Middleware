/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "Messenger_i.h"
#include <iostream>
// Implementation skeleton constructor
Messenger_i::Messenger_i (CORBA::ORB_ptr orb)
  : orb_(CORBA::ORB::_duplicate(orb))
{
}
  
// Implementation skeleton destructor
Messenger_i::~Messenger_i (void)
{
}
  
CORBA::Boolean Messenger_i::send_message (
    const char * user_name,
    const char * subject,
    char *& message
  )
{
  std::cout << "Message from: " << user_name << std::endl;
  std::cout << "Subject:      " << subject << std::endl;
  std::cout << "Message:      " << message << std::endl;
  CORBA::string_free(message);
  message = CORBA::string_dup("Thanks for the message.");
  return 1;
}

void Messenger_i::shutdown ()
{
  orb_->shutdown(0);
}
