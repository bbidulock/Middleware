// $Id$

#include "Forwarding_Servant.h"

#if (TAO_HAS_MINIMUM_CORBA == 0)

#include "PortableServerC.h"
#include "tao/Object.h"

ACE_RCSID(tao, Forwarding_Servant, "$Id$")

TAO_Forwarding_Servant::TAO_Forwarding_Servant (CORBA::Object_ptr forward_to,
                                                const char *interface_repository_id)
  : forward_to_ (CORBA::Object::_duplicate (forward_to)),
    interface_repository_id_ (CORBA::string_dup (interface_repository_id))
{
}

void
TAO_Forwarding_Servant::invoke (CORBA::ServerRequest_ptr,
                                CORBA::Environment &ACE_TRY_ENV)
{
  ACE_THROW (PortableServer::ForwardRequest (this->forward_to_.in ()));
}

CORBA::RepositoryId
TAO_Forwarding_Servant::_primary_interface (const PortableServer::ObjectId & /* oid */,
                                            PortableServer::POA_ptr /* poa */,
                                            CORBA::Environment & /* ACE_TRY_ENV */)
{
  return CORBA::string_dup (this->interface_repository_id_.in ());
}

#endif /* TAO_HAS_MINIMUM_CORBA */
