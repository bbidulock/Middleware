// -*- C++ -*-

//=============================================================================
/**
 *  @file    ServantRetentionStrategyNonRetain.cpp
 *
 *  $Id$
 *
 */
//=============================================================================

#include "tao/PortableServer/ServantRetentionStrategyNonRetain.h"
#include "tao/PortableServer/Non_Servant_Upcall.h"
#include "tao/PortableServer/Servant_Upcall.h"
#include "tao/PortableServer/POA_Current_Impl.h"
#include "tao/PortableServer/POA.h"
#include "tao/PortableServer/Servant_Base.h"
#include "tao/debug.h"

ACE_RCSID (PortableServer,
           Servant_Retention_Strategy,
           "$Id$")

namespace TAO
{
  namespace Portable_Server
  {
    ServantRetentionStrategyNonRetain::ServantRetentionStrategyNonRetain (void) :
      poa_ (0)
    {
    }

    ServantRetentionStrategyNonRetain::~ServantRetentionStrategyNonRetain (void)
    {
    }

    void
    ServantRetentionStrategyNonRetain::strategy_init (
      TAO_Root_POA *poa
      ACE_ENV_ARG_DECL_NOT_USED)
    {
      poa_ = poa;
    }

    void
    ServantRetentionStrategyNonRetain::strategy_cleanup (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    {
      poa_ = 0;
    }

    void
    ServantRetentionStrategyNonRetain::deactivate_object (
      const PortableServer::ObjectId &/*id*/
      ACE_ENV_ARG_DECL)
    {
      // When using Non_Retain we don't have an active object map and we just
      // can't deactivate any object
      ACE_THROW (PortableServer::POA::WrongPolicy ());
    }

    PortableServer::Servant
    ServantRetentionStrategyNonRetain::find_servant (
      const PortableServer::ObjectId &/*system_id*/
      ACE_ENV_ARG_DECL)
    {
      ACE_THROW_RETURN (PortableServer::POA::WrongPolicy (),
                        0);
    }

    PortableServer::ObjectId *
    ServantRetentionStrategyNonRetain::system_id_to_object_id (
      const PortableServer::ObjectId &system_id
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::WrongAdapter,
                         PortableServer::POA::WrongPolicy))
    {
      // The system id is the id (and no conversion/transformation is
      // needed).
      CORBA::OctetSeq *id = 0;
      ACE_NEW_THROW_EX (id,
                        PortableServer::ObjectId (system_id),
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (0);

      return id;
    }

    PortableServer::Servant
    ServantRetentionStrategyNonRetain::id_to_servant (
      const PortableServer::ObjectId &/*id*/
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::ObjectNotActive,
                         PortableServer::POA::WrongPolicy))
    {
      // Get the default servant, in case we have a not correct request_processing
      // strategy we will get an exception
      PortableServer::Servant servant = 0;

      servant = this->poa_->get_servant_i (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (servant != 0)
        {
          // ATTENTION: Trick locking here, see class header for details
          Non_Servant_Upcall non_servant_upcall (*this->poa_);
          ACE_UNUSED_ARG (non_servant_upcall);

          // The POA invokes _add_ref once on the Servant before returning
          // it. If the application uses reference counting, the caller of
          // id_to_servant is responsible for invoking _remove_ref once on
          // the returned Servant when it is finished with it. A
          // conforming caller need not invoke _remove_ref on the returned
          // Servant if the type of the Servant uses the default reference
          // counting inherited from ServantBase.
          servant->_add_ref (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_CHECK_RETURN (0);

          return servant;
        }
      else
        {
          /*
           * If using default servant request processing strategy but
           * no default servant is available, we will raise the
           * ObjectNotActive system exception.
           */
          ACE_THROW_RETURN (PortableServer::POA::ObjectNotActive (),
                            0);
        }
    }

    CORBA::Object_ptr
    ServantRetentionStrategyNonRetain::id_to_reference (
      const PortableServer::ObjectId &/*id*/
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::ObjectNotActive,
                         PortableServer::POA::WrongPolicy))
    {
      ACE_THROW_RETURN (PortableServer::POA::WrongPolicy (),
                        CORBA::Object::_nil ());
    }

    TAO_SERVANT_LOCATION
    ServantRetentionStrategyNonRetain::servant_present (
      const PortableServer::ObjectId &/*system_id*/,
      PortableServer::Servant &/*servant*/
      ACE_ENV_ARG_DECL_NOT_USED)
    {
      return TAO_SERVANT_NOT_FOUND;
    }

    PortableServer::Servant
    ServantRetentionStrategyNonRetain::find_servant (
      const PortableServer::ObjectId &system_id,
      TAO::Portable_Server::Servant_Upcall &servant_upcall,
      TAO::Portable_Server::POA_Current_Impl &poa_current_impl
      ACE_ENV_ARG_DECL_NOT_USED)
    {
      // We have the NON_RETAIN policy, user id is the system id.

      // Smartly copy all the data; <poa_current_impl.object_id_> does
      // not own the data.
      poa_current_impl.replace_object_id (system_id);

      servant_upcall.user_id (&system_id);

      return 0;
    }

    int
    ServantRetentionStrategyNonRetain::is_servant_in_map (
      PortableServer::Servant /*servant*/,
      int &/*wait_occurred_restart_call*/)
    {
      return 0;
    }

    CORBA::ULong
    ServantRetentionStrategyNonRetain::waiting_servant_deactivation (void) const
    {
      return 0;
    }

    void
    ServantRetentionStrategyNonRetain::deactivate_all_objects (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::WrongPolicy))
    {
    }

    PortableServer::ObjectId *
    ServantRetentionStrategyNonRetain::servant_to_user_id (
      PortableServer::Servant /*servant*/
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::ServantNotActive,
                         PortableServer::POA::WrongPolicy))
    {
      ACE_THROW_RETURN (PortableServer::POA::WrongPolicy (),
                        0);
    }

    CORBA::Object_ptr
    ServantRetentionStrategyNonRetain::servant_to_reference (
      PortableServer::Servant /*servant*/
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                      PortableServer::POA::ServantNotActive,
                      PortableServer::POA::WrongPolicy))
    {
      ACE_THROW_RETURN (PortableServer::POA::WrongPolicy (),
                        CORBA::Object::_nil ());
    }

    PortableServer::ObjectId *
    ServantRetentionStrategyNonRetain::activate_object (
      PortableServer::Servant /*servant*/,
      CORBA::Short /*priority*/,
      int &/*wait_occurred_restart_call*/
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::ServantAlreadyActive,
                         PortableServer::POA::WrongPolicy))
    {
      ACE_THROW_RETURN (PortableServer::POA::WrongPolicy (),
                        0);
    }

    void
    ServantRetentionStrategyNonRetain::activate_object_with_id (
      const PortableServer::ObjectId &/*id*/,
      PortableServer::Servant /*servant*/,
      CORBA::Short /*priority*/,
      int &/*wait_occurred_restart_call*/
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                   PortableServer::POA::ServantAlreadyActive,
                   PortableServer::POA::ObjectAlreadyActive,
                   PortableServer::POA::WrongPolicy))
    {
      ACE_THROW (PortableServer::POA::WrongPolicy ());
    }

    CORBA::Object_ptr
    ServantRetentionStrategyNonRetain::create_reference (
      const char *intf,
      CORBA::Short priority
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::WrongPolicy))
    {
      // This operation creates an object reference that encapsulates a
      // POA-generated Object Id value and the specified interface
      // repository id. This operation does not cause an activation to
      // take place. The resulting reference may be passed to clients, so
      // that subsequent requests on those references will cause the
      // appropriate servant manager to be invoked, if one is
      // available. The generated Object Id value may be obtained by
      // invoking POA::reference_to_id with the created reference.

      PortableServer::ObjectId_var system_id;
      PortableServer::ObjectId user_id;

      // Otherwise, it is the NON_RETAIN policy.  Therefore, any ol'
      // object id will do (even an empty one).
      PortableServer::ObjectId *sys_id;
      ACE_NEW_THROW_EX (sys_id,
                        PortableServer::ObjectId,
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (CORBA::Object::_nil ());

      system_id = sys_id;

      // User id is the same as system id.
      user_id = system_id.in ();

      // Remember params for potentially invoking <key_to_object> later.
      this->poa_->key_to_object_params_.set (system_id,
                                             intf,
                                             0,
                                             1,
                                             priority);

      return this->poa_->invoke_key_to_object_helper_i (intf,
                                                  user_id
                                                  ACE_ENV_ARG_PARAMETER);
    }

    CORBA::Object_ptr
    ServantRetentionStrategyNonRetain::create_reference_with_id (
      const PortableServer::ObjectId &oid,
      const char *intf,
      CORBA::Short priority
      ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::WrongPolicy))
    {
      // This operation creates an object reference that encapsulates the
      // specified Object Id and interface repository Id values. This
      // operation does not cause an activation to take place.  The
      // resulting reference may be passed to clients, so that subsequent
      // requests on those references will cause the object to be
      // activated if necessary, or the default servant used, depending on
      // the applicable policies.

      PortableServer::Servant servant = 0;
      PortableServer::ObjectId_var system_id;

      // Otherwise, it is the NON_RETAIN policy.  Therefore, user id
      // is the same as system id.
      PortableServer::ObjectId *sys_id;
      ACE_NEW_THROW_EX (sys_id,
                        PortableServer::ObjectId (oid),
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (CORBA::Object::_nil ());

      system_id = sys_id;

      // Remember params for potentially invoking <key_to_object> later.
      this->poa_->key_to_object_params_.set (system_id,
                                       intf,
                                       servant,
                                       1,
                                       priority);

      return this->poa_->invoke_key_to_object_helper_i (intf,
                                                  oid
                                                  ACE_ENV_ARG_PARAMETER);
    }

    int
    ServantRetentionStrategyNonRetain::rebind_using_user_id_and_system_id (
      PortableServer::Servant /*servant*/,
      const PortableServer::ObjectId &/*user_id*/,
      const PortableServer::ObjectId &/*system_id*/,
      TAO::Portable_Server::Servant_Upcall &/*servant_upcall*/)
    {
      return -1;
    }

    CORBA::Boolean
    ServantRetentionStrategyNonRetain::servant_has_remaining_activations (
      PortableServer::Servant /*servant*/)
    {
      return false;
    }

    int
    ServantRetentionStrategyNonRetain::unbind_using_user_id (
      const PortableServer::ObjectId &/*user_id*/)
    {
      return 0;
    }
  }
}

