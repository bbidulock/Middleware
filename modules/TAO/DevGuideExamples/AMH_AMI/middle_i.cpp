#include "amh_ami_pch.h"
/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "middle_i.h"
#include "inner_cb.h"

#include <iostream>
// Implementation skeleton constructor
Asynch_Middle_i::Asynch_Middle_i (PortableServer::POA_ptr poa,
                    Inner_ptr inner)
  : poa_ (PortableServer::POA::_duplicate(poa)),
    inner_ (Inner::_duplicate(inner))
{
}

void
Asynch_Middle_i::get_the_answer (AMH_MiddleResponseHandler_ptr _tao_rh,
                                 const char * question)
{
  // The callback handler servant instance holds on to a reference to the
  // AMH response handler. That way, it can forward the reply back to the
  // originial client after getting the reply from the inner server.
  PortableServer::ServantBase_var servant = new Inner_callback_i(this->poa_.in(),
                                                                 _tao_rh);
  PortableServer::ObjectId_var objid =
    this->poa_->activate_object(servant.in());
  CORBA::Object_var obj = this->poa_->id_to_reference (objid.in());

  AMI_InnerHandler_var cb =  AMI_InnerHandler::_narrow(obj.in());

  // forward the request on to the inner server, with the callback handler
  // reference.
  this->inner_->sendc_answer (cb.in(),question);

  // nothing else to do. Our client will block until the callback handler
  // forwards the reply.
}


//------------------------------------------------------------------------

// Implementation skeleton constructor
Middle_i::Middle_i (Inner_ptr inner)
  : inner_ (Inner::_duplicate(inner))
{
}

char *
Middle_i::get_the_answer ( const char * question )
{
  return inner_->answer (question);
}
