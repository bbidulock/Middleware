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
//    http://www.dre.vanderbilt.edu/CIAO

#ifndef CIAO_GLUE_SESSION_BMCLOSEDED_SVNT_H
#define CIAO_GLUE_SESSION_BMCLOSEDED_SVNT_H

#include /**/ "ace/pre.h"

#include "BMClosedEDEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Servant_Impl_T.h"
#include "tao/LocalObject.h"
#include "tao/PortableServer/Key_Adapters.h"
#include "ace/Active_Map_Manager_T.h"

#include "../BasicSPS.h"
#include "BMClosedEDS.h"

namespace BMClosedED_Impl
{
  namespace CIAO_GLUE_BasicSP
  {
    template <typename T>
    class ReadData_Servant_T
    : public virtual POA_BasicSP::ReadData,
    public virtual PortableServer::RefCountServantBase
    {
      public:
      ReadData_Servant_T (
      ::BasicSP::CCM_ReadData_ptr executor,
      ::Components::CCMContext_ptr ctx);

      virtual ~ReadData_Servant_T (void);

      virtual char *
      get_data (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // Get component implementation.
      virtual CORBA::Object_ptr
      _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      protected:
      // Facet executor.
      ::BasicSP::CCM_ReadData_var executor_;

      // Context object.
      ::Components::CCMContext_var ctx_;
    };

    typedef BMCLOSEDED_SVNT_Export ReadData_Servant_T<int> ReadData_Servant;
  }

  namespace CIAO_GLUE_BasicSP
  {
    class BMCLOSEDED_SVNT_Export BMClosedED_Context
    : public virtual ::BasicSP::CCM_BMClosedED_Context,
    public virtual TAO_Local_RefCounted_Object
    {
      public:
      // We will allow the servant glue code we generate to access our state.
      friend class BMClosedED_Servant;

      BMClosedED_Context (
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c,
      BMClosedED_Servant *sv);

      virtual ~BMClosedED_Context (void);

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

      // Operations for BMClosedED receptacles and event sources,
      // defined in ::BasicSP::CCM_BMClosedED_Context.

      virtual ::BasicSP::ReadData_ptr
      get_connection_datain (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      push_out_avail (
      ::BasicSP::DataAvailable *ev
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      // CIAO-specific.

      ::CIAO::Session_Container *
      _ciao_the_Container (void) const;

      static BMClosedED_Context *
      _narrow (
      ::Components::SessionContext_ptr p
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

      protected:
      // Methods that manage this component's connections and consumers.

      virtual void
      connect_datain (
      ::BasicSP::ReadData_ptr
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::AlreadyConnected,
      ::Components::InvalidConnection));

      virtual ::BasicSP::ReadData_ptr
      disconnect_datain (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::NoConnection));

      virtual ::Components::Cookie *
      subscribe_out_avail (
      ::BasicSP::DataAvailableConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::ExceededConnectionLimit));

      virtual ::BasicSP::DataAvailableConsumer_ptr
      unsubscribe_out_avail (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidConnection));

      protected:
      // Simplex datain connection.
      ::BasicSP::ReadData_var
      ciao_uses_datain_;

      ACE_Active_Map_Manager<
      ::BasicSP::DataAvailableConsumer_var>
      ciao_publishes_out_avail_map_;

      ::Components::CCMHome_var home_;
      ::CIAO::Session_Container *container_;

      BMClosedED_Servant *servant_;
      ::BasicSP::BMClosedED_var component_;
    };
  }

  namespace CIAO_GLUE_BasicSP
  {
    class BMCLOSEDED_SVNT_Export BMClosedED_Servant
      : public virtual CIAO::Servant_Impl<
          POA_BasicSP::BMClosedED,
          ::BasicSP::CCM_BMClosedED,
          ::BasicSP::CCM_BMClosedED_var,
          BMClosedED_Context
        >,
        public virtual PortableServer::RefCountServantBase
    {
      public:
      /// Hack for VC6 the most sucky compiler
      typedef CIAO::Servant_Impl<
          POA_BasicSP::BMClosedED,
          ::BasicSP::CCM_BMClosedED,
          ::BasicSP::CCM_BMClosedED_var,
          BMClosedED_Context
        > our_base;

      BMClosedED_Servant (
      ::BasicSP::CCM_BMClosedED_ptr executor,
      ::Components::CCMHome_ptr home,
      ::CIAO::Session_Container *c);

      virtual ~BMClosedED_Servant (void);

      virtual void
      set_attributes (
      const ::Components::ConfigValues &descr
      ACE_ENV_ARG_DECL);

      // Supported operations.

      // Public port operations.

      virtual ::BasicSP::ReadData_ptr
      provide_dataout (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual void
      connect_datain (
      ::BasicSP::ReadData_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::AlreadyConnected,
      ::Components::InvalidConnection));

      virtual ::BasicSP::ReadData_ptr
      disconnect_datain (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::NoConnection));

      virtual ::BasicSP::ReadData_ptr
      get_connection_datain (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      virtual ::Components::Cookie *
      subscribe_out_avail (
      ::BasicSP::DataAvailableConsumer_ptr c
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::ExceededConnectionLimit));

      virtual ::BasicSP::DataAvailableConsumer_ptr
      unsubscribe_out_avail (
      ::Components::Cookie *ck
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidConnection));

      // Servant class for the in_avail consumer.
      class BMCLOSEDED_SVNT_Export DataAvailableConsumer_in_avail_Servant
      : public virtual POA_BasicSP::DataAvailableConsumer,
      public virtual PortableServer::RefCountServantBase
      {
        public:
        DataAvailableConsumer_in_avail_Servant (
        ::BasicSP::CCM_BMClosedED_ptr executor,
        ::BasicSP::CCM_BMClosedED_Context_ptr c);

        virtual ~DataAvailableConsumer_in_avail_Servant (void);

        virtual void
        push_DataAvailable (
        ::BasicSP::DataAvailable *evt
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
        ::BasicSP::CCM_BMClosedED_var
        executor_;

        ::BasicSP::CCM_BMClosedED_Context_var
        ctx_;
      };

      virtual ::BasicSP::DataAvailableConsumer_ptr
      get_consumer_in_avail (
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
      get_named_facets (
      const ::Components::NameList & /* names */
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::InvalidName));

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
      get_named_publishers (
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

      private:

      ::BasicSP::ReadData_var
      provide_dataout_;

      ::BasicSP::DataAvailableConsumer_var
      consumes_in_avail_;

      private:

      void
      populate_port_tables (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      ::CORBA::Object_ptr
      provide_dataout_i (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      ::Components::EventConsumerBase_ptr
      get_consumer_in_avail_i (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      ACE_CString component_UUID_;
    };
  }

  namespace CIAO_GLUE_BasicSP
  {
    class BMCLOSEDED_SVNT_Export BMClosedEDHome_Servant
    : public virtual POA_BasicSP::BMClosedEDHome,
    public virtual PortableServer::RefCountServantBase
    {
      public:
      BMClosedEDHome_Servant (
      ::BasicSP::CCM_BMClosedEDHome_ptr exe,
      ::CIAO::Session_Container *c);
      virtual ~BMClosedEDHome_Servant (void);

      // Home operations.

      // Home factory and finder operations.

      // Attribute operations.

      // Operations for keyless home interface.

      virtual ::Components::CCMObject_ptr
      create_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((
      ::CORBA::SystemException,
      ::Components::CreateFailure));

      // Operations for implicit home interface.

      virtual ::BasicSP::BMClosedED_ptr
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

      ::BasicSP::BMClosedED_ptr
      _ciao_activate_component (
      ::BasicSP::CCM_BMClosedED_ptr exe
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      void
      _ciao_passivate_component (
      ::BasicSP::BMClosedED_ptr comp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

      protected:
      ::BasicSP::CCM_BMClosedEDHome_var
      executor_;

      ::CIAO::Session_Container *
      container_;

      ACE_Hash_Map_Manager_Ex<
      PortableServer::ObjectId,
      BMClosedED_Servant *,
      TAO_ObjectId_Hash,
      ACE_Equal_To<PortableServer::ObjectId>,
      ACE_SYNCH_MUTEX>
      component_map_;
    };

    extern "C" BMCLOSEDED_SVNT_Export ::PortableServer::Servant
    createBMClosedEDHome_Servant (
    ::Components::HomeExecutorBase_ptr p,
    CIAO::Session_Container *c
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_BMCLOSEDED_SVNT_H */

