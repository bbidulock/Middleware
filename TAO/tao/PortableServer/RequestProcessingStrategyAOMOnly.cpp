// -*- C++ -*-

//=============================================================================
/**
 *  @file    RequestProcessingStrategy.cpp
 *
 *  $Id$
 *
 */
//=============================================================================

#include "tao/PortableServer/RequestProcessingStrategyAOMOnly.h"
#include "tao/PortableServer/ServantManagerC.h"
#include "tao/PortableServer/POA.h"

ACE_RCSID (PortableServer,
           Request_Processing,
           "$Id$")

#if (TAO_HAS_MINIMUM_POA == 0)

namespace TAO
{
  namespace Portable_Server
  {
    AOM_Only_Request_Processing_Strategy::AOM_Only_Request_Processing_Strategy() :
      poa_ (0)
    {
    }

    AOM_Only_Request_Processing_Strategy::~AOM_Only_Request_Processing_Strategy()
    {
    }

    void
    AOM_Only_Request_Processing_Strategy::strategy_init(TAO_POA * poa)
    {
      poa_ = poa;
    }

    PortableServer::ServantManager_ptr
    AOM_Only_Request_Processing_Strategy::get_servant_manager (ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       PortableServer::POA::WrongPolicy))
    {
      ACE_THROW_RETURN (PortableServer::POA::WrongPolicy (),
                        PortableServer::ServantManager::_nil ());
    }

    void
    AOM_Only_Request_Processing_Strategy::set_servant_manager (
      PortableServer::ServantManager_ptr /*imgr*/
                         ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       PortableServer::POA::WrongPolicy))
    {
      ACE_THROW (PortableServer::POA::WrongPolicy ());
    }

    PortableServer::Servant
    AOM_Only_Request_Processing_Strategy::get_servant (ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       PortableServer::POA::WrongPolicy))
    {
      ACE_THROW_RETURN (PortableServer::POA::WrongPolicy (),
                        0);
    }

    void
    AOM_Only_Request_Processing_Strategy::set_servant (
      PortableServer::Servant /*servant*/
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::WrongPolicy))
    {
      ACE_THROW (PortableServer::POA::WrongPolicy ());
    }

    TAO_SERVANT_LOCATION
    AOM_Only_Request_Processing_Strategy::locate_servant (
      const PortableServer::ObjectId & /*system_id*/,
      PortableServer::Servant & /*servant*/)
    {
      return TAO_SERVANT_NOT_FOUND;
    }

    PortableServer::Servant
    AOM_Only_Request_Processing_Strategy::locate_servant (
      const char * /*operation*/,
      const PortableServer::ObjectId & /*system_id*/,
      TAO::Portable_Server::Servant_Upcall & /*servant_upcall*/,
      TAO::Portable_Server::POA_Current_Impl & /*poa_current_impl*/,
      int & /*wait_occurred_restart_call*/
      ACE_ENV_ARG_DECL)
    {
      // If the USE_ACTIVE_OBJECT_MAP_ONLY policy is in effect, the POA raises
      // the OBJECT_NOT_EXIST system exception.
      ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                        0);
    }

    PortableServer::Servant
    AOM_Only_Request_Processing_Strategy::reference_to_servant (
      CORBA::Object_ptr /*reference*/,
      PortableServer::ObjectId system_id
      ACE_ENV_ARG_DECL)
    {
      return this->poa_->find_servant (system_id
                                       ACE_ENV_ARG_PARAMETER);
    }

    void
    AOM_Only_Request_Processing_Strategy::cleanup_servant (
      const PortableServer::ObjectId& /*object_id*/,
      PortableServer::Servant /*servant*/,
      CORBA::Boolean /*cleanup_in_progress*/
      ACE_ENV_ARG_DECL_NOT_USED)
    {
      // Just do nothing
    }

  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

