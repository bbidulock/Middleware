// -*- C++ -*-

//=============================================================================
/**
 *  @file Request_Processing_Strategy.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_REQUESTPROCESSINGSTRATEGYSERVANTACTIVATOR_H
#define TAO_REQUESTPROCESSINGSTRATEGYSERVANTACTIVATOR_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "RequestProcessingStrategyServantManager.h"

#include "Servant_Location.h"

#define TAO_PORTABLESERVER_SAFE_INCLUDE
#include "PortableServerC.h"
#undef TAO_PORTABLESERVER_SAFE_INCLUDE

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_MINIMUM_POA == 0)

namespace PortableServer
{
  class ServantActivator;

  typedef ServantActivator *ServantActivator_ptr;
  typedef TAO_Objref_Var_T<ServantActivator> ServantActivator_var;
}

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export Servant_Activator_Request_Processing_Strategy :
       public virtual Servant_Manager_Request_Processing_Strategy
    {
    public:
      Servant_Activator_Request_Processing_Strategy (void);

      virtual ~Servant_Activator_Request_Processing_Strategy (void);

      virtual
      void strategy_init(
        TAO_POA *poa,
        TAO_Active_Object_Map* map,
        ServantRetentionStrategy* strategy);

      PortableServer::ServantManager_ptr
      get_servant_manager (ACE_ENV_SINGLE_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::WrongPolicy));

      void
      set_servant_manager (PortableServer::ServantManager_ptr imgr
                           ACE_ENV_ARG_DECL)
        ACE_THROW_SPEC ((CORBA::SystemException,
                         PortableServer::POA::WrongPolicy));

      virtual
      TAO_SERVANT_LOCATION
      locate_servant (const PortableServer::ObjectId &system_id,
                        PortableServer::Servant &servant
                        ACE_ENV_ARG_DECL);

      virtual
      PortableServer::Servant
      locate_servant (const char *operation,
                        const PortableServer::ObjectId &system_id,
                        TAO::Portable_Server::Servant_Upcall &servant_upcall,
                        TAO::Portable_Server::POA_Current_Impl &poa_current_impl,
                        int &wait_occurred_restart_call
                        ACE_ENV_ARG_DECL);

    private:
      PortableServer::Servant
      incarnate_servant (
        const PortableServer::ObjectId& object_id
        ACE_ENV_ARG_DECL);

      void
      etherealize_servant (
        const PortableServer::ObjectId& object_id,
        PortableServer::Servant servant
        ACE_ENV_ARG_DECL);


    private:
      TAO_POA* poa_;
      TAO_Active_Object_Map* active_object_map_;
      ServantRetentionStrategy* servant_retention_strategy_;
      PortableServer::ServantActivator_var servant_activator_;
    };
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_REQUESTPROCESSINGSTRATEGYSERVANTACTIVATOR_H */
