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

#ifndef CIAO_GLUE_SESSION_BENCHMARK_DATA_COLLECTOR_EX_SVNT_H
#define CIAO_GLUE_SESSION_BENCHMARK_DATA_COLLECTOR_EX_SVNT_H

#include /**/ "ace/pre.h"

#include "Benchmark_Data_Collector_ExEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "Benchmark_Data_Collector_ExS.h"

namespace CIAO_FACET_CUTS
{
  template <typename T>
  class Testing_Service_Servant_T
  : public virtual POA_CUTS::Testing_Service
  {
    public:
    Testing_Service_Servant_T (
      ::CUTS::CCM_Testing_Service_ptr executor,
      ::Components::CCMContext_ptr ctx);

    virtual ~Testing_Service_Servant_T (void);

    virtual ::CORBA::Long
    register_component (
      const ::CUTS::Component_Registration & cr
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::CUTS::Registration_Failed,
                     ::CUTS::Registration_Limit));

    virtual void
    unregister_component (
      const ::CUTS::Component_Registration & cr
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::CUTS::ID_Not_Found));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    protected:
    // Facet executor.
    ::CUTS::CCM_Testing_Service_var executor_;

    // Context object.
    ::Components::CCMContext_var ctx_;
  };

  typedef Testing_Service_Servant_T<int> Testing_Service_Servant;
}

namespace CIAO_FACET_CUTS
{
  template <typename T>
  class Path_Measurement_Servant_T
  : public virtual POA_CUTS::Path_Measurement
  {
    public:
    Path_Measurement_Servant_T (
      ::CUTS::CCM_Path_Measurement_ptr executor,
      ::Components::CCMContext_ptr ctx);

    virtual ~Path_Measurement_Servant_T (void);

    virtual ::CORBA::Long
    bind_to_path (
      const ::CUTS::Path_Sequence & path,
      ::CORBA::UShort flags
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::CUTS::Binding_Failed));

    virtual void
    unbind_to_path (
      ::CORBA::Long path_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::CUTS::ID_Not_Found));

    virtual ::CUTS::Event_Time_Info
    execution_time (
      ::CORBA::Long path_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException,
                     ::CUTS::ID_Not_Found,
                     ::CUTS::Operation_Failed));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    protected:
    // Facet executor.
    ::CUTS::CCM_Path_Measurement_var executor_;

    // Context object.
    ::Components::CCMContext_var ctx_;
  };

  typedef Path_Measurement_Servant_T<int> Path_Measurement_Servant;
}

namespace CIAO_FACET_CUTS
{
  template <typename T>
  class BDC_Control_Handle_Servant_T
  : public virtual POA_CUTS::BDC_Control_Handle
  {
    public:
    BDC_Control_Handle_Servant_T (
      ::CUTS::CCM_BDC_Control_Handle_ptr executor,
      ::Components::CCMContext_ptr ctx);

    virtual ~BDC_Control_Handle_Servant_T (void);

    virtual void
    collect_performance_data (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    protected:
    // Facet executor.
    ::CUTS::CCM_BDC_Control_Handle_var executor_;

    // Context object.
    ::Components::CCMContext_var ctx_;
  };

  typedef BDC_Control_Handle_Servant_T<int> BDC_Control_Handle_Servant;
}

namespace CIAO_FACET_CUTS
{
  template <typename T>
  class Database_Service_Servant_T
  : public virtual POA_CUTS::Database_Service
  {
    public:
    Database_Service_Servant_T (
      ::CUTS::CCM_Database_Service_ptr executor,
      ::Components::CCMContext_ptr ctx);

    virtual ~Database_Service_Servant_T (void);

    virtual ::CORBA::Long
    create_new_test (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    virtual void
    stop_current_test (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    virtual ::CORBA::Long
    current_test (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    // Get component implementation.
    virtual CORBA::Object_ptr
    _get_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC (( ::CORBA::SystemException));

    protected:
    // Facet executor.
    ::CUTS::CCM_Database_Service_var executor_;

    // Context object.
    ::Components::CCMContext_var ctx_;
  };

  typedef Database_Service_Servant_T<int> Database_Service_Servant;
}

namespace CUTS
{
  namespace CIDL_Benchmark_Data_Collector_Ex_Impl
  {
    class Benchmark_Data_Collector_Ex_Servant;

    class BENCHMARK_DATA_COLLECTOR_EX_SVNT_Export Benchmark_Data_Collector_Ex_Context
      : public virtual CIAO::Context_Impl<
          ::CUTS::CCM_Benchmark_Data_Collector_Ex_Context,
          Benchmark_Data_Collector_Ex_Servant,
          ::CUTS::Benchmark_Data_Collector_Ex,
          ::CUTS::Benchmark_Data_Collector_Ex_var
        >
    {
      public:
      // We will allow the servant glue code we generate to access our state.
      friend class Benchmark_Data_Collector_Ex_Servant;

      Benchmark_Data_Collector_Ex_Context (
        ::Components::CCMHome_ptr h,
        ::CIAO::Session_Container *c,
        Benchmark_Data_Collector_Ex_Servant *sv);

      virtual ~Benchmark_Data_Collector_Ex_Context (void);

      // Operations for Benchmark_Data_Collector_Ex receptacles and event sources,
      // defined in ::CUTS::CCM_Benchmark_Data_Collector_Ex_Context.

      virtual void
      push_collection_done (
        ::CUTS::Collection_Statistics *ev
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      // CIAO-specific.

      static Benchmark_Data_Collector_Ex_Context *
      _narrow (
        ::Components::SessionContext_ptr p
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);

      protected:
      // Methods that manage this component's connections and consumers.

      virtual ::Components::Cookie *
      subscribe_collection_done (
        ::CUTS::Collection_StatisticsConsumer_ptr c
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::ExceededConnectionLimit));

      // CIAO-specific.
      ::Components::Cookie *
      subscribe_collection_done_generic (
        ::Components::EventConsumerBase_ptr c
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::ExceededConnectionLimit));

      virtual ::CUTS::Collection_StatisticsConsumer_ptr
      unsubscribe_collection_done (
        ::Components::Cookie *ck
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidConnection));

      protected:
      ACE_Active_Map_Manager<
      ::CUTS::Collection_StatisticsConsumer_var>
      ciao_publishes_collection_done_map_;

      ACE_Active_Map_Manager<
      ::Components::EventConsumerBase_var>
      ciao_publishes_collection_done_generic_map_;
    };

    class BENCHMARK_DATA_COLLECTOR_EX_SVNT_Export Benchmark_Data_Collector_Ex_Servant
      : public virtual CIAO::Servant_Impl<
          POA_CUTS::Benchmark_Data_Collector_Ex,
          ::CUTS::CCM_Benchmark_Data_Collector_Ex,
          Benchmark_Data_Collector_Ex_Context
        >
    {
      public:

      typedef ::CUTS::CCM_Benchmark_Data_Collector_Ex _exec_type;

      Benchmark_Data_Collector_Ex_Servant (
        ::CUTS::CCM_Benchmark_Data_Collector_Ex_ptr executor,
        ::Components::CCMHome_ptr h,
        const char *ins_name,
        ::CIAO::Home_Servant_Impl_Base *hs,
        ::CIAO::Session_Container *c,
        ::CIAO::REC_POL_MAP &rec_pol_map);

      virtual ~Benchmark_Data_Collector_Ex_Servant (void);

      virtual void
      set_attributes (
        const ::Components::ConfigValues &descr
        ACE_ENV_ARG_DECL);

      // Supported operations.

      // Public port operations.

      virtual ::CUTS::Testing_Service_ptr
      provide_testing_service (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      virtual ::CUTS::Path_Measurement_ptr
      provide_online_measurements (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      virtual ::CUTS::BDC_Control_Handle_ptr
      provide_controls (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      virtual ::Components::Cookie *
      subscribe_collection_done (
        ::CUTS::Collection_StatisticsConsumer_ptr c
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::ExceededConnectionLimit));

      // CIAO-specific.
      ::Components::Cookie *
      subscribe_collection_done_generic (
        ::Components::EventConsumerBase_ptr c
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::ExceededConnectionLimit));

      virtual ::CUTS::Collection_StatisticsConsumer_ptr
      unsubscribe_collection_done (
        ::Components::Cookie *ck
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidConnection));

      virtual ::CUTS::Database_Service_ptr
      provide_database_service (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      // Component attribute operations.

      virtual ::CORBA::Long
      timeout (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      void
      timeout (
        ::CORBA::Long timeout
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      virtual ::CORBA::Long
      collection_threads (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      void
      collection_threads (
        ::CORBA::Long collection_threads
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      virtual char *
      metrics_outfile (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      void
      metrics_outfile (
        const char * metrics_outfile
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      virtual char *
      server_name (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      void
      server_name (
        const char * server_name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      // Operations for Receptacles interface.

      virtual ::Components::Cookie *
      connect (
        const char *name,
        CORBA::Object_ptr connection
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection,
                       ::Components::AlreadyConnected,
                       ::Components::ExceededConnectionLimit));

      virtual CORBA::Object_ptr
      disconnect (
        const char *name,
        ::Components::Cookie *ck
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection,
                       ::Components::CookieRequired,
                       ::Components::NoConnection));

      virtual ::Components::ReceptacleDescriptions *
      get_all_receptacles (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      // Operations for Events interface.

      virtual ::Components::Cookie *
      subscribe (
        const char *publisher_name,
        ::Components::EventConsumerBase_ptr subscriber
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection,
                       ::Components::ExceededConnectionLimit));

      virtual ::Components::EventConsumerBase_ptr
      unsubscribe (
        const char *publisher_name,
        ::Components::Cookie *ck
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection));

      virtual void
      connect_consumer (
        const char *emitter_name,
        ::Components::EventConsumerBase_ptr consumer
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection));

      virtual ::Components::EventConsumerBase_ptr
      disconnect_consumer (
        const char *source_name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::NoConnection));

      virtual ::Components::PublisherDescriptions *
      get_all_publishers (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      virtual ::Components::EmitterDescriptions *
      get_all_emitters (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      // CIAO specific operations on the servant. 
      CORBA::Object_ptr
      get_facet_executor (
        const char *name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      private:

      ::CUTS::Testing_Service_var
      provide_testing_service_;

      ::CUTS::Path_Measurement_var
      provide_online_measurements_;

      ::CUTS::BDC_Control_Handle_var
      provide_controls_;

      ::CUTS::Database_Service_var
      provide_database_service_;

      const char *ins_name_;

      private:

      void
      populate_port_tables (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      ::CORBA::Object_ptr
      provide_testing_service_i (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      ::CORBA::Object_ptr
      provide_online_measurements_i (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      ::CORBA::Object_ptr
      provide_controls_i (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));

      ::CORBA::Object_ptr
      provide_database_service_i (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC (( ::CORBA::SystemException));
    };

    class BENCHMARK_DATA_COLLECTOR_EX_SVNT_Export Benchmark_Data_Collector_Ex_Home_Servant
      : public virtual
          ::CIAO::Home_Servant_Impl<
              ::POA_CUTS::Benchmark_Data_Collector_Ex_Home,
              ::CUTS::CCM_Benchmark_Data_Collector_Ex_Home,
              Benchmark_Data_Collector_Ex_Servant
            >
    {
      public:

      Benchmark_Data_Collector_Ex_Home_Servant (
        ::CUTS::CCM_Benchmark_Data_Collector_Ex_Home_ptr exe,
        const char *ins_name,
        ::CIAO::Session_Container *c,
        ::CIAO::REC_POL_MAP &rec_pol_map);

      virtual ~Benchmark_Data_Collector_Ex_Home_Servant (void);

      // Home operations.
      // Home factory and finder operations.

      // Attribute operations.
    };

    extern "C" BENCHMARK_DATA_COLLECTOR_EX_SVNT_Export ::PortableServer::Servant
    create_CUTS_Benchmark_Data_Collector_Ex_Home_Servant (
      ::Components::HomeExecutorBase_ptr p,
      CIAO::Session_Container *c,
      const char *ins_name,
      ::CIAO::REC_POL_MAP &rec_pol_map
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_BENCHMARK_DATA_COLLECTOR_EX_SVNT_H */

