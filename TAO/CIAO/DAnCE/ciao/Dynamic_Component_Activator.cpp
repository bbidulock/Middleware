#include "Dynamic_Component_Activator.h"
#include "CIAO_common.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (ciao,
           Dynamic_Component_Activator,
           "$Id$")

namespace CIAO
{
  Dynamic_Component_Activator::Dynamic_Component_Activator (CORBA::ORB_ptr o)
    : orb_ (CORBA::ORB::_duplicate (o))
  {
  }

  Dynamic_Component_Activator::~Dynamic_Component_Activator (void)
  {
  }

  PortableServer::Servant
  Dynamic_Component_Activator::incarnate (const PortableServer::ObjectId &oid,
                                PortableServer::POA_ptr
                                ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableServer::ForwardRequest))
  {

    // @@ Jai, where is the implementation?
  }

  void
  Dynamic_Component_Activator::etherealize (
    const PortableServer::ObjectId &,
    PortableServer::POA_ptr ,
    PortableServer::Servant ,
    CORBA::Boolean ,
    CORBA::Boolean
    ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    /// Need to investigate what needs to be handled here..
  }

  // @@ Jai, what is this update map supposed to be doing.
  void update_servant_map (PortableServer::ObjectId &oid,
                           Dynamic_Component_Servant_Base* servant
                           ACE_ENV_ARG_DECL)
  {
  }

}
