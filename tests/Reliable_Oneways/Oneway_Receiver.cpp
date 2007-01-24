//
// $Id$
//
#include "Oneway_Receiver.h"
#include "Shutdown_Helper.h"

ACE_RCSID(Reliable_Oneways, Oneway_Receiver, "$Id$")

Oneway_Receiver::Oneway_Receiver (CORBA::ORB_ptr orb)
  : orb_ (CORBA::ORB::_duplicate (orb))
{
}

void
Oneway_Receiver::raise_no_permission (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  ACE_THROW (CORBA::NO_PERMISSION ());
}

void
Oneway_Receiver::destroy (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  PortableServer::POA_var poa = this->_default_POA ();

  PortableServer::ObjectId_var id =
    poa->servant_to_id (this ACE_ENV_ARG_PARAMETER);

  poa->deactivate_object (id.in () ACE_ENV_ARG_PARAMETER);
}

Test::Shutdown_Helper_ptr
Oneway_Receiver::get_shutdown_helper (void)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Shutdown_Helper *shutdown_helper;
  ACE_NEW_THROW_EX (shutdown_helper,
                    Shutdown_Helper (this->orb_.in ()),
                    CORBA::NO_MEMORY ());

  PortableServer::ServantBase_var transfer_ownership(shutdown_helper);

  return shutdown_helper->_this ();
}
