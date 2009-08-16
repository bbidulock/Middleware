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
Messenger_i::Messenger_i (CORBA::ORB_ptr orb,
                          CosEventChannelAdmin::ProxyPushSupplier_ptr supplier,
                          int event_limit)
  : orb_(CORBA::ORB::_duplicate(orb))
  , supplier_(CosEventChannelAdmin::ProxyPushSupplier::_duplicate(supplier))
  , event_limit_(event_limit)
{
}

// Implementation skeleton destructor
Messenger_i::~Messenger_i (void)
{
}

void Messenger_i::send_message (const char * user_name,
                                const char * subject,
                                const char * message)
{
  std::cout << "Message from: " << user_name << std::endl;
  std::cout << "Subject:      " << subject << std::endl;
  std::cout << "Message:      " << message << std::endl;

  if (--event_limit_ <= 0) {
    supplier_->disconnect_push_supplier();
    orb_->shutdown(0);
  }
}
