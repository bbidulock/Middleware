// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.cs.wustl.edu/~nanbor/projects/CIAO-src/docs/index.html

#ifndef CIAO_GLUE_SESSION_UAV_SVNT_H
#define CIAO_GLUE_SESSION_UAV_SVNT_H

#include /**/ "ace/pre.h"

#include "UAVEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "tao/LocalObject.h"
#include "tao/PortableServer/Key_Adapters.h"
#include "ace/Active_Map_Manager_T.h"

#include "UAVS.h"

namespace UAV_Impl
{
  namespace CIAO_GLUE_BBN_UAV
  {
    class UAV_SVNT_Export UAV_Context
    : public virtual ::BBN_UAV::CCM_UAV_Context,
    public virtual TAO_Local_RefCounted_Object
    {
      public:
      // We will allow the servant glue code we generate to access our state.
      friend class UAV_Servant;

      UAV_Context (
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c,
      UAV_Servant *sv);

      virtual ~UAV_Context (void);

      // Operations from ::Components::CCMContext.

      virtual ::Components::Principal_ptr
      get_caller_principal (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::CCMHome_ptr
      get_CCM_home (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CORBA::Boolean
      get_rollback_only (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::IllegalState));

      virtual ::Components::Transaction::UserTransaction_ptr
      get_user_transaction (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::IllegalState));

      virtual CORBA::Boolean
      is_caller_in_role (
      const char *role
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      set_rollback_only (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::IllegalState));

      // Operations from ::Components::SessionContext interface.

      virtual CORBA::Object_ptr
      get_CCM_object (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::IllegalState));

      // Operations for UAV receptacles and event sources,
      // defined in ::BBN_UAV::CCM_UAV_Context.

      virtual void
      push_uav_ready (
      ::BBN_UAV::UAVReady *ev
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // CIAO-specific.

      ::CIAO::Session_Container *
      _ciao_the_Container (void) const;

      static UAV_Context *
      _narrow (
      ::Components::SessionContext_ptr p
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

      protected:
      // Methods that manage this component's connections and consumers.

      virtual ::Components::Cookie *
      subscribe_uav_ready (
      ::BBN_UAV::UAVReadyConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::ExceededConnectionLimit));

      virtual ::BBN_UAV::UAVReadyConsumer_ptr
      unsubscribe_uav_ready (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidConnection));

      protected:
      ACE_Active_Map_Manager<
      ::BBN_UAV::UAVReadyConsumer_var>
      ciao_publishes_uav_ready_map_;

      ::Components::CCMHome_var home_;

      ::CIAO::Session_Container *container_;

      UAV_Servant *servant_;

      ::BBN_UAV::UAV_var component_;
    };
  }

  namespace CIAO_GLUE_BBN_UAV
  {
    class UAV_SVNT_Export UAV_Servant
    : public virtual POA_BBN_UAV::UAV,
    public virtual PortableServer::RefCountServantBase
    {
      public:
      UAV_Servant (
      ::BBN_UAV::CCM_UAV_ptr executor,
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c);

      virtual ~UAV_Servant (void);

      // Supported operations.

      // Public port operations.

      virtual ::Components::Cookie *
      subscribe_uav_ready (
      ::BBN_UAV::UAVReadyConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::ExceededConnectionLimit));

      virtual ::BBN_UAV::UAVReadyConsumer_ptr
      unsubscribe_uav_ready (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidConnection));

      // Servant class for the start_capture consumer.
      class UAV_SVNT_Export StartCaptureConsumer_start_capture_Servant
      : public virtual POA_BBN_UAV::StartCaptureConsumer,
      public virtual PortableServer::RefCountServantBase
      {
        public:
        StartCaptureConsumer_start_capture_Servant (
        ::BBN_UAV::CCM_UAV_ptr executor,
        ::BBN_UAV::CCM_UAV_Context_ptr c);

        virtual ~StartCaptureConsumer_start_capture_Servant (void);

        virtual void
        push_StartCapture (
        ::BBN_UAV::StartCapture *evt
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

        // Inherited from ::Components::EventConsumerBase.
        virtual void
        push_event (::Components::EventBase *ev
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
        ::CORBA::SystemException,
        ::Components::BadEventType));

        // Get component implementation.
        virtual CORBA::Object_ptr
        _get_component (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((CORBA::SystemException));

        protected:
        ::BBN_UAV::CCM_UAV_var
        executor_;

        ::BBN_UAV::CCM_UAV_Context_var
        ctx_;
      };

      virtual ::BBN_UAV::StartCaptureConsumer_ptr
      get_consumer_start_capture (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Component attribute operations.

      // Operations for Navigation interface.

      virtual CORBA::Object_ptr
      provide_facet (
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::FacetDescriptions *
      get_all_facets (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::FacetDescriptions *
      get_named_facets (
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual CORBA::Boolean
      same_component (
      CORBA::Object_ptr object_ref
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Operations for Receptacles interface.

      virtual ::Components::Cookie *
      connect (
      const char *name,
      CORBA::Object_ptr connection
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::InvalidConnection,
      ::Components::AlreadyConnected,
      ::Components::ExceededConnectionLimit));

      virtual CORBA::Object_ptr
      disconnect (
      const char *name,
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::InvalidConnection,
      ::Components::CookieRequired,
      ::Components::NoConnection));

      virtual ::Components::ConnectionDescriptions *
      get_connections (
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::ReceptacleDescriptions *
      get_all_receptacles (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::ReceptacleDescriptions *
      get_named_receptacles (
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      // Operations for Events interface.

      virtual ::Components::EventConsumerBase_ptr
      get_consumer (
      const char *sink_name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::Cookie *
      subscribe (
      const char *publisher_name,
      ::Components::EventConsumerBase_ptr subscriber
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::InvalidConnection,
      ::Components::ExceededConnectionLimit));

      virtual ::Components::EventConsumerBase_ptr
      unsubscribe (
      const char *publisher_name,
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::InvalidConnection));

      virtual void
      connect_consumer (
      const char *emitter_name,
      ::Components::EventConsumerBase_ptr consumer
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::AlreadyConnected,
      ::Components::InvalidConnection));

      virtual ::Components::EventConsumerBase_ptr
      disconnect_consumer (
      const char *source_name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName,
      ::Components::NoConnection));

      virtual ::Components::ConsumerDescriptions *
      get_all_consumers (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::ConsumerDescriptions *
      get_named_consumers (
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::EmitterDescriptions *
      get_all_emitters (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::EmitterDescriptions *
      get_named_emitters(
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      virtual ::Components::PublisherDescriptions *
      get_all_publishers (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::PublisherDescriptions *
      get_named_publishers(
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

      // Operations for CCMObject interface.

      virtual void
      component_UUID (
      const char * new_component_UUID
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CIAO::CONNECTION_ID
      component_UUID (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual CORBA::IRObject_ptr
      get_component_def (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::CCMHome_ptr
      get_ccm_home (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::PrimaryKeyBase *
      get_primary_key (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::NoKeyAvailable));

      virtual void
      configuration_complete (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidConfiguration));

      virtual void
      remove (
      ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::RemoveFailure));

      virtual ::Components::ComponentPortDescription *
      get_all_ports(
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Get component implementation.
      virtual CORBA::Object_ptr
      _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // CIAO-specific operations.

      void
      _ciao_activate (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      void
      _ciao_passivate (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      protected:
      ::BBN_UAV::CCM_UAV_var
      executor_;

      UAV_Context *
      context_;

      ::CIAO::Session_Container *
      container_;
      ::BBN_UAV::StartCaptureConsumer_var
      consumes_start_capture_;

      ACE_CString component_UUID_;
    };
  }

  namespace CIAO_GLUE_BBN_UAV
  {
    class UAV_SVNT_Export UAVHome_Servant
    : public virtual POA_BBN_UAV::UAVHome,
    public virtual PortableServer::RefCountServantBase
    {
      public:
      UAVHome_Servant (
      ::BBN_UAV::CCM_UAVHome_ptr exe,
      ::CIAO::Session_Container *c);

      virtual ~UAVHome_Servant (void);

      // Home factory and other operations.

      // Attribute operations.

      // Operations for keyless home interface.

      virtual ::Components::CCMObject_ptr
      create_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CreateFailure));

      // Operations for implicit home interface.

      virtual ::BBN_UAV::UAV_ptr
      create (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CreateFailure));

      // Operations for CCMHome interface.

      virtual ::CORBA::IRObject_ptr
      get_component_def (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::CORBA::IRObject_ptr
      get_home_def (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      remove_component (
      ::Components::CCMObject_ptr comp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::RemoveFailure));

      // Supported operations.

      protected:
      // CIAO-specific operations.

      ::BBN_UAV::UAV_ptr
      _ciao_activate_component (
      ::BBN_UAV::CCM_UAV_ptr exe
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      void
      _ciao_passivate_component (
      ::BBN_UAV::UAV_ptr comp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      protected:
      ::BBN_UAV::CCM_UAVHome_var
      executor_;

      ::CIAO::Session_Container *
      container_;

      ACE_Hash_Map_Manager_Ex<
      PortableServer::ObjectId,
      UAV_Servant *,
      TAO_ObjectId_Hash,
      ACE_Equal_To<PortableServer::ObjectId>,
      ACE_SYNCH_MUTEX>
      component_map_;
    };

    extern "C" UAV_SVNT_Export ::PortableServer::Servant
    createUAVHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    CIAO::Session_Container *c
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_UAV_SVNT_H */

