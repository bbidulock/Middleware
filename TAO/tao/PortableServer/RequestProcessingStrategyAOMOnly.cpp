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
#include "tao/PortableServer/Non_Servant_Upcall.h"
#include "tao/PortableServer/Servant_Base.h"
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
      const PortableServer::ObjectId & system_id,
      PortableServer::Servant & servant
      ACE_ENV_ARG_DECL)
    {
      return this->poa_->servant_present (system_id,
                                          servant
                                          ACE_ENV_ARG_PARAMETER);
    }

    PortableServer::Servant
    AOM_Only_Request_Processing_Strategy::locate_servant (
      const char * /*operation*/,
      const PortableServer::ObjectId &system_id,
      TAO::Portable_Server::Servant_Upcall &servant_upcall,
      TAO::Portable_Server::POA_Current_Impl &poa_current_impl,
      int & /*wait_occurred_restart_call*/
      ACE_ENV_ARG_DECL)
    {
      PortableServer::Servant servant = 0;

      servant = this->poa_->find_servant (system_id,
                                          servant_upcall,
                                          poa_current_impl
                                          ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (servant == 0)
        {
          ACE_THROW_RETURN (CORBA::OBJECT_NOT_EXIST (),
                            0);
        }

      return servant;
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
      PortableServer::Servant servant,
      PortableServer::ObjectId user_id
      ACE_ENV_ARG_DECL)
    {
      if (servant)
        {
          // ATTENTION: Trick locking here, see class header for details
          TAO::Portable_Server::Non_Servant_Upcall non_servant_upcall (*this->poa_);
          ACE_UNUSED_ARG (non_servant_upcall);

          servant->_remove_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_CHECK;
        }

      // This operation causes the association of the Object Id specified
      // by the oid parameter and its servant to be removed from the
      // Active Object Map.
      int result = this->poa_->unbind_using_user_id (user_id);

      if (result != 0)
        {
          ACE_THROW (CORBA::OBJ_ADAPTER ());
        }
    }

    void
    AOM_Only_Request_Processing_Strategy::etherealize_objects (
      CORBA::Boolean /*etherealize_objects*/)
    {
    }

    PortableServer::ObjectId *
    AOM_Only_Request_Processing_Strategy::servant_to_id (
      PortableServer::Servant servant
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::ServantNotActive,
                         PortableServer::POA::WrongPolicy))
    {
      return this->poa_->servant_to_user_id (servant ACE_ENV_ARG_PARAMETER);
    }
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

