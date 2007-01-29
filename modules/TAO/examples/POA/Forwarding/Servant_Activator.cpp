// $Id$

#include "Servant_Activator.h"
#include "test_i.h"

ACE_RCSID(Forwarding, Servant_Activator, "$Id$")

  ServantActivator::ServantActivator (CORBA::ORB_ptr orb,
                                      CORBA::Object_ptr forward_to)
    : orb_ (CORBA::ORB::_duplicate (orb)),
      forward_to_ (CORBA::Object::_duplicate (forward_to))
{
}

PortableServer::Servant
ServantActivator::incarnate (const PortableServer::ObjectId &,
                             PortableServer::POA_ptr)
  ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableServer::ForwardRequest))
{
  this->orb_->shutdown (0);

  // Throw forward exception
  ACE_THROW_RETURN (
                    PortableServer::ForwardRequest (
                                                    this->forward_to_.in ()),
                    0);
}

void
ServantActivator::etherealize (const PortableServer::ObjectId &,
                               PortableServer::POA_ptr,
                               PortableServer::Servant servant,
                               CORBA::Boolean,
                               CORBA::Boolean)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  delete servant;
}

void
ServantActivator::forward_requests (void)
{
  if (CORBA::is_nil (this->forward_to_.in ()))
    throw test::Cannot_Forward ();
}
