#include "RT_CCM_Handlers_Export.h"

#ifndef CIAOSERVER_RESOURCES_HPP
#define CIAOSERVER_RESOURCES_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class ServerResourcesDef;
    class ServerCmdlineOptions;
    class ACESvcConf;
    class ORBConfigs;
    class ORBResources;
    class Priority;
    class ThreadpoolDef;
    class ThreadpoolWithLanesDef;
    class ThreadpoolLaneDef;
    class ConnectionBandsDef;
    class PriorityBandDef;
    class PolicySet;
    class PriorityModel;
    class NWPriorityModel;
    class PriorityModelPolicyDef;
    class NWPriorityModelPolicyDef;
    class CNWPriorityModelPolicyDef;
  }
}

#include <memory>
#include <list>
#include "XMLSchema/Types.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class RT_CCM_Handlers_Export ServerResourcesDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // cmdline
      // 
      public:
      bool cmdline_p () const;
      ::CIAO::Config_Handlers::ServerCmdlineOptions const& cmdline () const;
      void cmdline (::CIAO::Config_Handlers::ServerCmdlineOptions const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ServerCmdlineOptions > cmdline_;

      // svcconf
      // 
      public:
      bool svcconf_p () const;
      ::CIAO::Config_Handlers::ACESvcConf const& svcconf () const;
      void svcconf (::CIAO::Config_Handlers::ACESvcConf const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ACESvcConf > svcconf_;

      // orbConfigs
      // 
      public:
      ::CIAO::Config_Handlers::ORBConfigs const& orbConfigs () const;
      void orbConfigs (::CIAO::Config_Handlers::ORBConfigs const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ORBConfigs > orbConfigs_;

      // id
      // 
      public:
      bool id_p () const;
      ::XMLSchema::ID< ACE_TCHAR > const& id () const;
      ::XMLSchema::ID< ACE_TCHAR >& id ();
      void id (::XMLSchema::ID< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

      public:
      ServerResourcesDef (::CIAO::Config_Handlers::ORBConfigs const& orbConfigs__);

      ServerResourcesDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ServerResourcesDef (ServerResourcesDef const& s);

      ServerResourcesDef&
      operator= (ServerResourcesDef const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export ServerCmdlineOptions : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // arg
      // 
      public:
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::iterator arg_iterator;
      typedef ::std::list< ::XMLSchema::string< ACE_TCHAR > >::const_iterator arg_const_iterator;
      arg_iterator begin_arg ();
      arg_iterator end_arg ();
      arg_const_iterator begin_arg () const;
      arg_const_iterator end_arg () const;
      void add_arg (::XMLSchema::string< ACE_TCHAR > const& );
      size_t count_arg (void) const;

      protected:
      ::std::list< ::XMLSchema::string< ACE_TCHAR > > arg_;

      public:
      ServerCmdlineOptions ();

      ServerCmdlineOptions (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ServerCmdlineOptions (ServerCmdlineOptions const& s);

      ServerCmdlineOptions&
      operator= (ServerCmdlineOptions const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export ACESvcConf : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // uri
      // 
      public:
      bool uri_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& uri () const;
      void uri (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > uri_;

      public:
      ACESvcConf ();

      ACESvcConf (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ACESvcConf (ACESvcConf const& s);

      ACESvcConf&
      operator= (ACESvcConf const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export ORBConfigs : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // resources
      // 
      public:
      bool resources_p () const;
      ::CIAO::Config_Handlers::ORBResources const& resources () const;
      void resources (::CIAO::Config_Handlers::ORBResources const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ORBResources > resources_;

      // policySet
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::PolicySet >::iterator policySet_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::PolicySet >::const_iterator policySet_const_iterator;
      policySet_iterator begin_policySet ();
      policySet_iterator end_policySet ();
      policySet_const_iterator begin_policySet () const;
      policySet_const_iterator end_policySet () const;
      void add_policySet (::CIAO::Config_Handlers::PolicySet const& );
      size_t count_policySet (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::PolicySet > policySet_;

      public:
      ORBConfigs ();

      ORBConfigs (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ORBConfigs (ORBConfigs const& s);

      ORBConfigs&
      operator= (ORBConfigs const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export ORBResources : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // threadpool
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::ThreadpoolDef >::iterator threadpool_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::ThreadpoolDef >::const_iterator threadpool_const_iterator;
      threadpool_iterator begin_threadpool ();
      threadpool_iterator end_threadpool ();
      threadpool_const_iterator begin_threadpool () const;
      threadpool_const_iterator end_threadpool () const;
      void add_threadpool (::CIAO::Config_Handlers::ThreadpoolDef const& );
      size_t count_threadpool (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::ThreadpoolDef > threadpool_;

      // threadpoolWithLanes
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::ThreadpoolWithLanesDef >::iterator threadpoolWithLanes_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::ThreadpoolWithLanesDef >::const_iterator threadpoolWithLanes_const_iterator;
      threadpoolWithLanes_iterator begin_threadpoolWithLanes ();
      threadpoolWithLanes_iterator end_threadpoolWithLanes ();
      threadpoolWithLanes_const_iterator begin_threadpoolWithLanes () const;
      threadpoolWithLanes_const_iterator end_threadpoolWithLanes () const;
      void add_threadpoolWithLanes (::CIAO::Config_Handlers::ThreadpoolWithLanesDef const& );
      size_t count_threadpoolWithLanes (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::ThreadpoolWithLanesDef > threadpoolWithLanes_;

      // connectionBands
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::ConnectionBandsDef >::iterator connectionBands_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::ConnectionBandsDef >::const_iterator connectionBands_const_iterator;
      connectionBands_iterator begin_connectionBands ();
      connectionBands_iterator end_connectionBands ();
      connectionBands_const_iterator begin_connectionBands () const;
      connectionBands_const_iterator end_connectionBands () const;
      void add_connectionBands (::CIAO::Config_Handlers::ConnectionBandsDef const& );
      size_t count_connectionBands (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::ConnectionBandsDef > connectionBands_;

      public:
      ORBResources ();

      ORBResources (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ORBResources (ORBResources const& s);

      ORBResources&
      operator= (ORBResources const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export Priority : public ::XMLSchema::int_
    {
      //@@ VC6 anathema
      typedef ::XMLSchema::int_ Base__;

      public:
      Priority (::XMLSchema::int_ const& b__);

      Priority (::XSCRT::XML::Element< ACE_TCHAR > const&);
      Priority (::XSCRT::XML::Attribute< ACE_TCHAR > const&);
      Priority (Priority const& s);

      Priority&
      operator= (Priority const& s);

      private:
      char regulator__;
    };

    class RT_CCM_Handlers_Export ThreadpoolDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // stacksize
      // 
      public:
      ::XMLSchema::unsignedLong const& stacksize () const;
      void stacksize (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > stacksize_;

      // static_threads
      // 
      public:
      ::XMLSchema::unsignedLong const& static_threads () const;
      void static_threads (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > static_threads_;

      // dynamic_threads
      // 
      public:
      ::XMLSchema::unsignedLong const& dynamic_threads () const;
      void dynamic_threads (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > dynamic_threads_;

      // default_priority
      // 
      public:
      ::CIAO::Config_Handlers::Priority const& default_priority () const;
      void default_priority (::CIAO::Config_Handlers::Priority const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Priority > default_priority_;

      // allow_request_buffering
      // 
      public:
      ::XMLSchema::boolean const& allow_request_buffering () const;
      void allow_request_buffering (::XMLSchema::boolean const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::boolean > allow_request_buffering_;

      // max_buffered_requests
      // 
      public:
      ::XMLSchema::unsignedLong const& max_buffered_requests () const;
      void max_buffered_requests (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > max_buffered_requests_;

      // max_request_buffered_size
      // 
      public:
      ::XMLSchema::unsignedLong const& max_request_buffered_size () const;
      void max_request_buffered_size (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > max_request_buffered_size_;

      // id
      // 
      public:
      bool id_p () const;
      ::XMLSchema::ID< ACE_TCHAR > const& id () const;
      ::XMLSchema::ID< ACE_TCHAR >& id ();
      void id (::XMLSchema::ID< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

      public:
      ThreadpoolDef (::XMLSchema::unsignedLong const& stacksize__,
                     ::XMLSchema::unsignedLong const& static_threads__,
                     ::XMLSchema::unsignedLong const& dynamic_threads__,
                     ::CIAO::Config_Handlers::Priority const& default_priority__,
                     ::XMLSchema::boolean const& allow_request_buffering__,
                     ::XMLSchema::unsignedLong const& max_buffered_requests__,
                     ::XMLSchema::unsignedLong const& max_request_buffered_size__);

      ThreadpoolDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ThreadpoolDef (ThreadpoolDef const& s);

      ThreadpoolDef&
      operator= (ThreadpoolDef const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export ThreadpoolWithLanesDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // threadpoolLane
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::ThreadpoolLaneDef >::iterator threadpoolLane_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::ThreadpoolLaneDef >::const_iterator threadpoolLane_const_iterator;
      threadpoolLane_iterator begin_threadpoolLane ();
      threadpoolLane_iterator end_threadpoolLane ();
      threadpoolLane_const_iterator begin_threadpoolLane () const;
      threadpoolLane_const_iterator end_threadpoolLane () const;
      void add_threadpoolLane (::CIAO::Config_Handlers::ThreadpoolLaneDef const& );
      size_t count_threadpoolLane (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::ThreadpoolLaneDef > threadpoolLane_;

      // stacksize
      // 
      public:
      ::XMLSchema::unsignedLong const& stacksize () const;
      void stacksize (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > stacksize_;

      // allow_borrowing
      // 
      public:
      ::XMLSchema::boolean const& allow_borrowing () const;
      void allow_borrowing (::XMLSchema::boolean const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::boolean > allow_borrowing_;

      // allow_request_buffering
      // 
      public:
      ::XMLSchema::boolean const& allow_request_buffering () const;
      void allow_request_buffering (::XMLSchema::boolean const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::boolean > allow_request_buffering_;

      // max_buffered_requests
      // 
      public:
      ::XMLSchema::unsignedLong const& max_buffered_requests () const;
      void max_buffered_requests (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > max_buffered_requests_;

      // max_request_buffered_size
      // 
      public:
      ::XMLSchema::unsignedLong const& max_request_buffered_size () const;
      void max_request_buffered_size (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > max_request_buffered_size_;

      // id
      // 
      public:
      bool id_p () const;
      ::XMLSchema::ID< ACE_TCHAR > const& id () const;
      ::XMLSchema::ID< ACE_TCHAR >& id ();
      void id (::XMLSchema::ID< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

      public:
      ThreadpoolWithLanesDef (::XMLSchema::unsignedLong const& stacksize__,
                              ::XMLSchema::boolean const& allow_borrowing__,
                              ::XMLSchema::boolean const& allow_request_buffering__,
                              ::XMLSchema::unsignedLong const& max_buffered_requests__,
                              ::XMLSchema::unsignedLong const& max_request_buffered_size__);

      ThreadpoolWithLanesDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ThreadpoolWithLanesDef (ThreadpoolWithLanesDef const& s);

      ThreadpoolWithLanesDef&
      operator= (ThreadpoolWithLanesDef const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export ThreadpoolLaneDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // static_threads
      // 
      public:
      ::XMLSchema::unsignedLong const& static_threads () const;
      void static_threads (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > static_threads_;

      // dynamic_threads
      // 
      public:
      ::XMLSchema::unsignedLong const& dynamic_threads () const;
      void dynamic_threads (::XMLSchema::unsignedLong const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::unsignedLong > dynamic_threads_;

      // priority
      // 
      public:
      ::CIAO::Config_Handlers::Priority const& priority () const;
      void priority (::CIAO::Config_Handlers::Priority const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Priority > priority_;

      public:
      ThreadpoolLaneDef (::XMLSchema::unsignedLong const& static_threads__,
                         ::XMLSchema::unsignedLong const& dynamic_threads__,
                         ::CIAO::Config_Handlers::Priority const& priority__);

      ThreadpoolLaneDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ThreadpoolLaneDef (ThreadpoolLaneDef const& s);

      ThreadpoolLaneDef&
      operator= (ThreadpoolLaneDef const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export ConnectionBandsDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // band
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::PriorityBandDef >::iterator band_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::PriorityBandDef >::const_iterator band_const_iterator;
      band_iterator begin_band ();
      band_iterator end_band ();
      band_const_iterator begin_band () const;
      band_const_iterator end_band () const;
      void add_band (::CIAO::Config_Handlers::PriorityBandDef const& );
      size_t count_band (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::PriorityBandDef > band_;

      // id
      // 
      public:
      bool id_p () const;
      ::XMLSchema::ID< ACE_TCHAR > const& id () const;
      ::XMLSchema::ID< ACE_TCHAR >& id ();
      void id (::XMLSchema::ID< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

      public:
      ConnectionBandsDef ();

      ConnectionBandsDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      ConnectionBandsDef (ConnectionBandsDef const& s);

      ConnectionBandsDef&
      operator= (ConnectionBandsDef const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export PriorityBandDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // low
      // 
      public:
      ::XMLSchema::int_ const& low () const;
      void low (::XMLSchema::int_ const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::int_ > low_;

      // high
      // 
      public:
      ::XMLSchema::int_ const& high () const;
      void high (::XMLSchema::int_ const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::int_ > high_;

      public:
      PriorityBandDef (::XMLSchema::int_ const& low__,
                       ::XMLSchema::int_ const& high__);

      PriorityBandDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      PriorityBandDef (PriorityBandDef const& s);

      PriorityBandDef&
      operator= (PriorityBandDef const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export PolicySet : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // priorityModel
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::PriorityModelPolicyDef >::iterator priorityModel_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::PriorityModelPolicyDef >::const_iterator priorityModel_const_iterator;
      priorityModel_iterator begin_priorityModel ();
      priorityModel_iterator end_priorityModel ();
      priorityModel_const_iterator begin_priorityModel () const;
      priorityModel_const_iterator end_priorityModel () const;
      void add_priorityModel (::CIAO::Config_Handlers::PriorityModelPolicyDef const& );
      size_t count_priorityModel (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::PriorityModelPolicyDef > priorityModel_;

      // nwpriorityModel
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::NWPriorityModelPolicyDef >::iterator nwpriorityModel_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::NWPriorityModelPolicyDef >::const_iterator nwpriorityModel_const_iterator;
      nwpriorityModel_iterator begin_nwpriorityModel ();
      nwpriorityModel_iterator end_nwpriorityModel ();
      nwpriorityModel_const_iterator begin_nwpriorityModel () const;
      nwpriorityModel_const_iterator end_nwpriorityModel () const;
      void add_nwpriorityModel (::CIAO::Config_Handlers::NWPriorityModelPolicyDef const& );
      size_t count_nwpriorityModel (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::NWPriorityModelPolicyDef > nwpriorityModel_;

      // cnwpriorityModel
      // 
      public:
      typedef ::std::list< ::CIAO::Config_Handlers::CNWPriorityModelPolicyDef >::iterator cnwpriorityModel_iterator;
      typedef ::std::list< ::CIAO::Config_Handlers::CNWPriorityModelPolicyDef >::const_iterator cnwpriorityModel_const_iterator;
      cnwpriorityModel_iterator begin_cnwpriorityModel ();
      cnwpriorityModel_iterator end_cnwpriorityModel ();
      cnwpriorityModel_const_iterator begin_cnwpriorityModel () const;
      cnwpriorityModel_const_iterator end_cnwpriorityModel () const;
      void add_cnwpriorityModel (::CIAO::Config_Handlers::CNWPriorityModelPolicyDef const& );
      size_t count_cnwpriorityModel (void) const;

      protected:
      ::std::list< ::CIAO::Config_Handlers::CNWPriorityModelPolicyDef > cnwpriorityModel_;

      // threadpool
      // 
      public:
      typedef ::std::list< ::XMLSchema::IDREF< ACE_TCHAR > >::iterator threadpool_iterator;
      typedef ::std::list< ::XMLSchema::IDREF< ACE_TCHAR > >::const_iterator threadpool_const_iterator;
      threadpool_iterator begin_threadpool ();
      threadpool_iterator end_threadpool ();
      threadpool_const_iterator begin_threadpool () const;
      threadpool_const_iterator end_threadpool () const;
      void add_threadpool (::XMLSchema::IDREF< ACE_TCHAR > const& );
      size_t count_threadpool (void) const;

      protected:
      ::std::list< ::XMLSchema::IDREF< ACE_TCHAR > > threadpool_;

      // priorityBandedConnection
      // 
      public:
      typedef ::std::list< ::XMLSchema::IDREF< ACE_TCHAR > >::iterator priorityBandedConnection_iterator;
      typedef ::std::list< ::XMLSchema::IDREF< ACE_TCHAR > >::const_iterator priorityBandedConnection_const_iterator;
      priorityBandedConnection_iterator begin_priorityBandedConnection ();
      priorityBandedConnection_iterator end_priorityBandedConnection ();
      priorityBandedConnection_const_iterator begin_priorityBandedConnection () const;
      priorityBandedConnection_const_iterator end_priorityBandedConnection () const;
      void add_priorityBandedConnection (::XMLSchema::IDREF< ACE_TCHAR > const& );
      size_t count_priorityBandedConnection (void) const;

      protected:
      ::std::list< ::XMLSchema::IDREF< ACE_TCHAR > > priorityBandedConnection_;

      // id
      // 
      public:
      bool id_p () const;
      ::XMLSchema::ID< ACE_TCHAR > const& id () const;
      ::XMLSchema::ID< ACE_TCHAR >& id ();
      void id (::XMLSchema::ID< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::ID< ACE_TCHAR > > id_;

      public:
      PolicySet ();

      PolicySet (::XSCRT::XML::Element< ACE_TCHAR > const&);
      PolicySet (PolicySet const& s);

      PolicySet&
      operator= (PolicySet const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export PriorityModel : public ::XSCRT::Type
    {
      public:
      PriorityModel (::XSCRT::XML::Element< ACE_TCHAR > const&);
      PriorityModel (::XSCRT::XML::Attribute< ACE_TCHAR > const&);

      static PriorityModel const SERVER_DECLARED;
      static PriorityModel const CLIENT_PROPAGATED;

      enum Value
      {
        SERVER_DECLARED_l,CLIENT_PROPAGATED_l,
      };


      Value
      integral () const;

      friend bool RT_CCM_Handlers_Export 
      operator== (PriorityModel const& a, PriorityModel const& b);

      friend bool RT_CCM_Handlers_Export 
      operator!= (PriorityModel const& a, PriorityModel const& b);

      private:
      PriorityModel (Value v);

      Value v_;
    };

    bool RT_CCM_Handlers_Export operator== (PriorityModel const &a, PriorityModel const &b);

    bool RT_CCM_Handlers_Export operator!= (PriorityModel const &a, PriorityModel const &b);


    class RT_CCM_Handlers_Export NWPriorityModel : public ::XSCRT::Type
    {
      public:
      NWPriorityModel (::XSCRT::XML::Element< ACE_TCHAR > const&);
      NWPriorityModel (::XSCRT::XML::Attribute< ACE_TCHAR > const&);

      static NWPriorityModel const SERVER_DECLARED_NWPRIORITY;
      static NWPriorityModel const CLIENT_PROPAGATED_NWPRIORITY;

      enum Value
      {
        SERVER_DECLARED_NWPRIORITY_l,CLIENT_PROPAGATED_NWPRIORITY_l,
      };


      Value
      integral () const;

      friend bool RT_CCM_Handlers_Export 
      operator== (NWPriorityModel const& a, NWPriorityModel const& b);

      friend bool RT_CCM_Handlers_Export 
      operator!= (NWPriorityModel const& a, NWPriorityModel const& b);

      private:
      NWPriorityModel (Value v);

      Value v_;
    };

    bool RT_CCM_Handlers_Export operator== (NWPriorityModel const &a, NWPriorityModel const &b);

    bool RT_CCM_Handlers_Export operator!= (NWPriorityModel const &a, NWPriorityModel const &b);


    class RT_CCM_Handlers_Export PriorityModelPolicyDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // priority_model
      // 
      public:
      ::CIAO::Config_Handlers::PriorityModel const& priority_model () const;
      void priority_model (::CIAO::Config_Handlers::PriorityModel const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::PriorityModel > priority_model_;

      // server_priority
      // 
      public:
      bool server_priority_p () const;
      ::CIAO::Config_Handlers::Priority const& server_priority () const;
      ::CIAO::Config_Handlers::Priority& server_priority ();
      void server_priority (::CIAO::Config_Handlers::Priority const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::Priority > server_priority_;

      public:
      PriorityModelPolicyDef (::CIAO::Config_Handlers::PriorityModel const& priority_model__);

      PriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      PriorityModelPolicyDef (PriorityModelPolicyDef const& s);

      PriorityModelPolicyDef&
      operator= (PriorityModelPolicyDef const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export NWPriorityModelPolicyDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // nw_priority_model
      // 
      public:
      ::CIAO::Config_Handlers::NWPriorityModel const& nw_priority_model () const;
      void nw_priority_model (::CIAO::Config_Handlers::NWPriorityModel const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::NWPriorityModel > nw_priority_model_;

      // request_dscp
      // 
      public:
      ::XMLSchema::long_ const& request_dscp () const;
      void request_dscp (::XMLSchema::long_ const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::long_ > request_dscp_;

      // reply_dscp
      // 
      public:
      ::XMLSchema::long_ const& reply_dscp () const;
      void reply_dscp (::XMLSchema::long_ const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::long_ > reply_dscp_;

      public:
      NWPriorityModelPolicyDef (::CIAO::Config_Handlers::NWPriorityModel const& nw_priority_model__,
                                ::XMLSchema::long_ const& request_dscp__,
                                ::XMLSchema::long_ const& reply_dscp__);

      NWPriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      NWPriorityModelPolicyDef (NWPriorityModelPolicyDef const& s);

      NWPriorityModelPolicyDef&
      operator= (NWPriorityModelPolicyDef const& s);

      private:
      char regulator__;
    };


    class RT_CCM_Handlers_Export CNWPriorityModelPolicyDef : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // request_dscp
      // 
      public:
      ::XMLSchema::long_ const& request_dscp () const;
      void request_dscp (::XMLSchema::long_ const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::long_ > request_dscp_;

      // reply_dscp
      // 
      public:
      ::XMLSchema::long_ const& reply_dscp () const;
      void reply_dscp (::XMLSchema::long_ const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::long_ > reply_dscp_;

      public:
      CNWPriorityModelPolicyDef (::XMLSchema::long_ const& request_dscp__,
                                 ::XMLSchema::long_ const& reply_dscp__);

      CNWPriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR > const&);
      CNWPriorityModelPolicyDef (CNWPriorityModelPolicyDef const& s);

      CNWPriorityModelPolicyDef&
      operator= (CNWPriorityModelPolicyDef const& s);

      private:
      char regulator__;
    };
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    RT_CCM_Handlers_Export
    ::CIAO::Config_Handlers::ServerResourcesDef
    ServerResources (xercesc::DOMDocument const*);
  }
}

#include "XMLSchema/Traversal.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      struct RT_CCM_Handlers_Export ServerResourcesDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ServerResourcesDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        cmdline (Type&);

        virtual void
        cmdline (Type const&);

        virtual void
        cmdline_none (Type&);

        virtual void
        cmdline_none (Type const&);

        virtual void
        svcconf (Type&);

        virtual void
        svcconf (Type const&);

        virtual void
        svcconf_none (Type&);

        virtual void
        svcconf_none (Type const&);

        virtual void
        orbConfigs (Type&);

        virtual void
        orbConfigs (Type const&);

        virtual void
        id (Type&);

        virtual void
        id (Type const&);

        virtual void
        id_none (Type&);

        virtual void
        id_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export ServerCmdlineOptions : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ServerCmdlineOptions >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        arg (Type&);

        virtual void
        arg (Type const&);

        virtual void
        arg_pre (Type&);

        virtual void
        arg_pre (Type const&);

        virtual void
        arg_next (Type&);

        virtual void
        arg_next (Type const&);

        virtual void
        arg_post (Type&);

        virtual void
        arg_post (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export ACESvcConf : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ACESvcConf >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        uri (Type&);

        virtual void
        uri (Type const&);

        virtual void
        uri_none (Type&);

        virtual void
        uri_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export ORBConfigs : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ORBConfigs >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        resources (Type&);

        virtual void
        resources (Type const&);

        virtual void
        resources_none (Type&);

        virtual void
        resources_none (Type const&);

        virtual void
        policySet (Type&);

        virtual void
        policySet (Type const&);

        virtual void
        policySet_pre (Type&);

        virtual void
        policySet_pre (Type const&);

        virtual void
        policySet_next (Type&);

        virtual void
        policySet_next (Type const&);

        virtual void
        policySet_post (Type&);

        virtual void
        policySet_post (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export ORBResources : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ORBResources >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        threadpool (Type&);

        virtual void
        threadpool (Type const&);

        virtual void
        threadpool_pre (Type&);

        virtual void
        threadpool_pre (Type const&);

        virtual void
        threadpool_next (Type&);

        virtual void
        threadpool_next (Type const&);

        virtual void
        threadpool_post (Type&);

        virtual void
        threadpool_post (Type const&);

        virtual void
        threadpool_none (Type&);

        virtual void
        threadpool_none (Type const&);

        virtual void
        threadpoolWithLanes (Type&);

        virtual void
        threadpoolWithLanes (Type const&);

        virtual void
        threadpoolWithLanes_pre (Type&);

        virtual void
        threadpoolWithLanes_pre (Type const&);

        virtual void
        threadpoolWithLanes_next (Type&);

        virtual void
        threadpoolWithLanes_next (Type const&);

        virtual void
        threadpoolWithLanes_post (Type&);

        virtual void
        threadpoolWithLanes_post (Type const&);

        virtual void
        threadpoolWithLanes_none (Type&);

        virtual void
        threadpoolWithLanes_none (Type const&);

        virtual void
        connectionBands (Type&);

        virtual void
        connectionBands (Type const&);

        virtual void
        connectionBands_pre (Type&);

        virtual void
        connectionBands_pre (Type const&);

        virtual void
        connectionBands_next (Type&);

        virtual void
        connectionBands_next (Type const&);

        virtual void
        connectionBands_post (Type&);

        virtual void
        connectionBands_post (Type const&);

        virtual void
        connectionBands_none (Type&);

        virtual void
        connectionBands_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export Priority : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::Priority >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export ThreadpoolDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ThreadpoolDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        stacksize (Type&);

        virtual void
        stacksize (Type const&);

        virtual void
        static_threads (Type&);

        virtual void
        static_threads (Type const&);

        virtual void
        dynamic_threads (Type&);

        virtual void
        dynamic_threads (Type const&);

        virtual void
        default_priority (Type&);

        virtual void
        default_priority (Type const&);

        virtual void
        allow_request_buffering (Type&);

        virtual void
        allow_request_buffering (Type const&);

        virtual void
        max_buffered_requests (Type&);

        virtual void
        max_buffered_requests (Type const&);

        virtual void
        max_request_buffered_size (Type&);

        virtual void
        max_request_buffered_size (Type const&);

        virtual void
        id (Type&);

        virtual void
        id (Type const&);

        virtual void
        id_none (Type&);

        virtual void
        id_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export ThreadpoolWithLanesDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ThreadpoolWithLanesDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        threadpoolLane (Type&);

        virtual void
        threadpoolLane (Type const&);

        virtual void
        threadpoolLane_pre (Type&);

        virtual void
        threadpoolLane_pre (Type const&);

        virtual void
        threadpoolLane_next (Type&);

        virtual void
        threadpoolLane_next (Type const&);

        virtual void
        threadpoolLane_post (Type&);

        virtual void
        threadpoolLane_post (Type const&);

        virtual void
        stacksize (Type&);

        virtual void
        stacksize (Type const&);

        virtual void
        allow_borrowing (Type&);

        virtual void
        allow_borrowing (Type const&);

        virtual void
        allow_request_buffering (Type&);

        virtual void
        allow_request_buffering (Type const&);

        virtual void
        max_buffered_requests (Type&);

        virtual void
        max_buffered_requests (Type const&);

        virtual void
        max_request_buffered_size (Type&);

        virtual void
        max_request_buffered_size (Type const&);

        virtual void
        id (Type&);

        virtual void
        id (Type const&);

        virtual void
        id_none (Type&);

        virtual void
        id_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export ThreadpoolLaneDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ThreadpoolLaneDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        static_threads (Type&);

        virtual void
        static_threads (Type const&);

        virtual void
        dynamic_threads (Type&);

        virtual void
        dynamic_threads (Type const&);

        virtual void
        priority (Type&);

        virtual void
        priority (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export ConnectionBandsDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::ConnectionBandsDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        band (Type&);

        virtual void
        band (Type const&);

        virtual void
        band_pre (Type&);

        virtual void
        band_pre (Type const&);

        virtual void
        band_next (Type&);

        virtual void
        band_next (Type const&);

        virtual void
        band_post (Type&);

        virtual void
        band_post (Type const&);

        virtual void
        id (Type&);

        virtual void
        id (Type const&);

        virtual void
        id_none (Type&);

        virtual void
        id_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export PriorityBandDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::PriorityBandDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        low (Type&);

        virtual void
        low (Type const&);

        virtual void
        high (Type&);

        virtual void
        high (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export PolicySet : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::PolicySet >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        priorityModel (Type&);

        virtual void
        priorityModel (Type const&);

        virtual void
        priorityModel_pre (Type&);

        virtual void
        priorityModel_pre (Type const&);

        virtual void
        priorityModel_next (Type&);

        virtual void
        priorityModel_next (Type const&);

        virtual void
        priorityModel_post (Type&);

        virtual void
        priorityModel_post (Type const&);

        virtual void
        priorityModel_none (Type&);

        virtual void
        priorityModel_none (Type const&);

        virtual void
        nwpriorityModel (Type&);

        virtual void
        nwpriorityModel (Type const&);

        virtual void
        nwpriorityModel_pre (Type&);

        virtual void
        nwpriorityModel_pre (Type const&);

        virtual void
        nwpriorityModel_next (Type&);

        virtual void
        nwpriorityModel_next (Type const&);

        virtual void
        nwpriorityModel_post (Type&);

        virtual void
        nwpriorityModel_post (Type const&);

        virtual void
        nwpriorityModel_none (Type&);

        virtual void
        nwpriorityModel_none (Type const&);

        virtual void
        cnwpriorityModel (Type&);

        virtual void
        cnwpriorityModel (Type const&);

        virtual void
        cnwpriorityModel_pre (Type&);

        virtual void
        cnwpriorityModel_pre (Type const&);

        virtual void
        cnwpriorityModel_next (Type&);

        virtual void
        cnwpriorityModel_next (Type const&);

        virtual void
        cnwpriorityModel_post (Type&);

        virtual void
        cnwpriorityModel_post (Type const&);

        virtual void
        cnwpriorityModel_none (Type&);

        virtual void
        cnwpriorityModel_none (Type const&);

        virtual void
        threadpool (Type&);

        virtual void
        threadpool (Type const&);

        virtual void
        threadpool_pre (Type&);

        virtual void
        threadpool_pre (Type const&);

        virtual void
        threadpool_next (Type&);

        virtual void
        threadpool_next (Type const&);

        virtual void
        threadpool_post (Type&);

        virtual void
        threadpool_post (Type const&);

        virtual void
        threadpool_none (Type&);

        virtual void
        threadpool_none (Type const&);

        virtual void
        priorityBandedConnection (Type&);

        virtual void
        priorityBandedConnection (Type const&);

        virtual void
        priorityBandedConnection_pre (Type&);

        virtual void
        priorityBandedConnection_pre (Type const&);

        virtual void
        priorityBandedConnection_next (Type&);

        virtual void
        priorityBandedConnection_next (Type const&);

        virtual void
        priorityBandedConnection_post (Type&);

        virtual void
        priorityBandedConnection_post (Type const&);

        virtual void
        priorityBandedConnection_none (Type&);

        virtual void
        priorityBandedConnection_none (Type const&);

        virtual void
        id (Type&);

        virtual void
        id (Type const&);

        virtual void
        id_none (Type&);

        virtual void
        id_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      typedef
      ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::PriorityModel >
      PriorityModel;

      typedef
      ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::NWPriorityModel >
      NWPriorityModel;

      struct RT_CCM_Handlers_Export PriorityModelPolicyDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::PriorityModelPolicyDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        priority_model (Type&);

        virtual void
        priority_model (Type const&);

        virtual void
        server_priority (Type&);

        virtual void
        server_priority (Type const&);

        virtual void
        server_priority_none (Type&);

        virtual void
        server_priority_none (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export NWPriorityModelPolicyDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::NWPriorityModelPolicyDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        nw_priority_model (Type&);

        virtual void
        nw_priority_model (Type const&);

        virtual void
        request_dscp (Type&);

        virtual void
        request_dscp (Type const&);

        virtual void
        reply_dscp (Type&);

        virtual void
        reply_dscp (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };

      struct RT_CCM_Handlers_Export CNWPriorityModelPolicyDef : ::XMLSchema::Traversal::Traverser< ::CIAO::Config_Handlers::CNWPriorityModelPolicyDef >
      {
        virtual void
        traverse (Type&);

        virtual void
        traverse (Type const&);

        virtual void
        pre (Type&);

        virtual void
        pre (Type const&);

        virtual void
        request_dscp (Type&);

        virtual void
        request_dscp (Type const&);

        virtual void
        reply_dscp (Type&);

        virtual void
        reply_dscp (Type const&);

        virtual void
        post (Type&);

        virtual void
        post (Type const&);
      };
    }
  }
}

#include "XMLSchema/Writer.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      struct ServerResourcesDef : Traversal::ServerResourcesDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ServerResourcesDef Type;
        ServerResourcesDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        cmdline (Type &o)
        {

          this->cmdline (const_cast <Type const &> (o));
        }


        virtual void
        cmdline (Type const&);

        virtual void 
        svcconf (Type &o)
        {

          this->svcconf (const_cast <Type const &> (o));
        }


        virtual void
        svcconf (Type const&);

        virtual void 
        orbConfigs (Type &o)
        {

          this->orbConfigs (const_cast <Type const &> (o));
        }


        virtual void
        orbConfigs (Type const&);

        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        virtual void
        id (Type const&);

        protected:
        ServerResourcesDef ();
      };

      struct ServerCmdlineOptions : Traversal::ServerCmdlineOptions, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ServerCmdlineOptions Type;
        ServerCmdlineOptions (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        arg_pre (Type &o)
        {

          this->arg_pre (const_cast <Type const &> (o));
        }


        virtual void
        arg_pre (Type const&);

        virtual void 
        arg_next (Type &o)
        {

          this->arg_next (const_cast <Type const &> (o));
        }


        virtual void
        arg_next (Type const&);

        virtual void 
        arg_post (Type &o)
        {

          this->arg_post (const_cast <Type const &> (o));
        }


        virtual void
        arg_post (Type const&);

        protected:
        ServerCmdlineOptions ();
      };

      struct ACESvcConf : Traversal::ACESvcConf, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ACESvcConf Type;
        ACESvcConf (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        uri (Type &o)
        {

          this->uri (const_cast <Type const &> (o));
        }


        virtual void
        uri (Type const&);

        protected:
        ACESvcConf ();
      };

      struct ORBConfigs : Traversal::ORBConfigs, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ORBConfigs Type;
        ORBConfigs (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        resources (Type &o)
        {

          this->resources (const_cast <Type const &> (o));
        }


        virtual void
        resources (Type const&);

        virtual void 
        policySet_pre (Type &o)
        {

          this->policySet_pre (const_cast <Type const &> (o));
        }


        virtual void
        policySet_pre (Type const&);

        virtual void 
        policySet_next (Type &o)
        {

          this->policySet_next (const_cast <Type const &> (o));
        }


        virtual void
        policySet_next (Type const&);

        virtual void 
        policySet_post (Type &o)
        {

          this->policySet_post (const_cast <Type const &> (o));
        }


        virtual void
        policySet_post (Type const&);

        protected:
        ORBConfigs ();
      };

      struct ORBResources : Traversal::ORBResources, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ORBResources Type;
        ORBResources (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        threadpool_pre (Type &o)
        {

          this->threadpool_pre (const_cast <Type const &> (o));
        }


        virtual void
        threadpool_pre (Type const&);

        virtual void 
        threadpool_next (Type &o)
        {

          this->threadpool_next (const_cast <Type const &> (o));
        }


        virtual void
        threadpool_next (Type const&);

        virtual void 
        threadpool_post (Type &o)
        {

          this->threadpool_post (const_cast <Type const &> (o));
        }


        virtual void
        threadpool_post (Type const&);

        virtual void 
        threadpoolWithLanes_pre (Type &o)
        {

          this->threadpoolWithLanes_pre (const_cast <Type const &> (o));
        }


        virtual void
        threadpoolWithLanes_pre (Type const&);

        virtual void 
        threadpoolWithLanes_next (Type &o)
        {

          this->threadpoolWithLanes_next (const_cast <Type const &> (o));
        }


        virtual void
        threadpoolWithLanes_next (Type const&);

        virtual void 
        threadpoolWithLanes_post (Type &o)
        {

          this->threadpoolWithLanes_post (const_cast <Type const &> (o));
        }


        virtual void
        threadpoolWithLanes_post (Type const&);

        virtual void 
        connectionBands_pre (Type &o)
        {

          this->connectionBands_pre (const_cast <Type const &> (o));
        }


        virtual void
        connectionBands_pre (Type const&);

        virtual void 
        connectionBands_next (Type &o)
        {

          this->connectionBands_next (const_cast <Type const &> (o));
        }


        virtual void
        connectionBands_next (Type const&);

        virtual void 
        connectionBands_post (Type &o)
        {

          this->connectionBands_post (const_cast <Type const &> (o));
        }


        virtual void
        connectionBands_post (Type const&);

        protected:
        ORBResources ();
      };

      struct Priority : Traversal::Priority, 
      virtual ::XMLSchema::Writer::FundamentalType< ::XMLSchema::int_, ACE_TCHAR >,
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::Priority Type;
        Priority (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        protected:
        Priority ();
      };

      struct ThreadpoolDef : Traversal::ThreadpoolDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ThreadpoolDef Type;
        ThreadpoolDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        stacksize (Type &o)
        {

          this->stacksize (const_cast <Type const &> (o));
        }


        virtual void
        stacksize (Type const&);

        virtual void 
        static_threads (Type &o)
        {

          this->static_threads (const_cast <Type const &> (o));
        }


        virtual void
        static_threads (Type const&);

        virtual void 
        dynamic_threads (Type &o)
        {

          this->dynamic_threads (const_cast <Type const &> (o));
        }


        virtual void
        dynamic_threads (Type const&);

        virtual void 
        default_priority (Type &o)
        {

          this->default_priority (const_cast <Type const &> (o));
        }


        virtual void
        default_priority (Type const&);

        virtual void 
        allow_request_buffering (Type &o)
        {

          this->allow_request_buffering (const_cast <Type const &> (o));
        }


        virtual void
        allow_request_buffering (Type const&);

        virtual void 
        max_buffered_requests (Type &o)
        {

          this->max_buffered_requests (const_cast <Type const &> (o));
        }


        virtual void
        max_buffered_requests (Type const&);

        virtual void 
        max_request_buffered_size (Type &o)
        {

          this->max_request_buffered_size (const_cast <Type const &> (o));
        }


        virtual void
        max_request_buffered_size (Type const&);

        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        virtual void
        id (Type const&);

        protected:
        ThreadpoolDef ();
      };

      struct ThreadpoolWithLanesDef : Traversal::ThreadpoolWithLanesDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ThreadpoolWithLanesDef Type;
        ThreadpoolWithLanesDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        threadpoolLane_pre (Type &o)
        {

          this->threadpoolLane_pre (const_cast <Type const &> (o));
        }


        virtual void
        threadpoolLane_pre (Type const&);

        virtual void 
        threadpoolLane_next (Type &o)
        {

          this->threadpoolLane_next (const_cast <Type const &> (o));
        }


        virtual void
        threadpoolLane_next (Type const&);

        virtual void 
        threadpoolLane_post (Type &o)
        {

          this->threadpoolLane_post (const_cast <Type const &> (o));
        }


        virtual void
        threadpoolLane_post (Type const&);

        virtual void 
        stacksize (Type &o)
        {

          this->stacksize (const_cast <Type const &> (o));
        }


        virtual void
        stacksize (Type const&);

        virtual void 
        allow_borrowing (Type &o)
        {

          this->allow_borrowing (const_cast <Type const &> (o));
        }


        virtual void
        allow_borrowing (Type const&);

        virtual void 
        allow_request_buffering (Type &o)
        {

          this->allow_request_buffering (const_cast <Type const &> (o));
        }


        virtual void
        allow_request_buffering (Type const&);

        virtual void 
        max_buffered_requests (Type &o)
        {

          this->max_buffered_requests (const_cast <Type const &> (o));
        }


        virtual void
        max_buffered_requests (Type const&);

        virtual void 
        max_request_buffered_size (Type &o)
        {

          this->max_request_buffered_size (const_cast <Type const &> (o));
        }


        virtual void
        max_request_buffered_size (Type const&);

        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        virtual void
        id (Type const&);

        protected:
        ThreadpoolWithLanesDef ();
      };

      struct ThreadpoolLaneDef : Traversal::ThreadpoolLaneDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ThreadpoolLaneDef Type;
        ThreadpoolLaneDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        static_threads (Type &o)
        {

          this->static_threads (const_cast <Type const &> (o));
        }


        virtual void
        static_threads (Type const&);

        virtual void 
        dynamic_threads (Type &o)
        {

          this->dynamic_threads (const_cast <Type const &> (o));
        }


        virtual void
        dynamic_threads (Type const&);

        virtual void 
        priority (Type &o)
        {

          this->priority (const_cast <Type const &> (o));
        }


        virtual void
        priority (Type const&);

        protected:
        ThreadpoolLaneDef ();
      };

      struct ConnectionBandsDef : Traversal::ConnectionBandsDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::ConnectionBandsDef Type;
        ConnectionBandsDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        band_pre (Type &o)
        {

          this->band_pre (const_cast <Type const &> (o));
        }


        virtual void
        band_pre (Type const&);

        virtual void 
        band_next (Type &o)
        {

          this->band_next (const_cast <Type const &> (o));
        }


        virtual void
        band_next (Type const&);

        virtual void 
        band_post (Type &o)
        {

          this->band_post (const_cast <Type const &> (o));
        }


        virtual void
        band_post (Type const&);

        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        virtual void
        id (Type const&);

        protected:
        ConnectionBandsDef ();
      };

      struct PriorityBandDef : Traversal::PriorityBandDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::PriorityBandDef Type;
        PriorityBandDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        low (Type &o)
        {

          this->low (const_cast <Type const &> (o));
        }


        virtual void
        low (Type const&);

        virtual void 
        high (Type &o)
        {

          this->high (const_cast <Type const &> (o));
        }


        virtual void
        high (Type const&);

        protected:
        PriorityBandDef ();
      };

      struct PolicySet : Traversal::PolicySet, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::PolicySet Type;
        PolicySet (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        priorityModel_pre (Type &o)
        {

          this->priorityModel_pre (const_cast <Type const &> (o));
        }


        virtual void
        priorityModel_pre (Type const&);

        virtual void 
        priorityModel_next (Type &o)
        {

          this->priorityModel_next (const_cast <Type const &> (o));
        }


        virtual void
        priorityModel_next (Type const&);

        virtual void 
        priorityModel_post (Type &o)
        {

          this->priorityModel_post (const_cast <Type const &> (o));
        }


        virtual void
        priorityModel_post (Type const&);

        virtual void 
        nwpriorityModel_pre (Type &o)
        {

          this->nwpriorityModel_pre (const_cast <Type const &> (o));
        }


        virtual void
        nwpriorityModel_pre (Type const&);

        virtual void 
        nwpriorityModel_next (Type &o)
        {

          this->nwpriorityModel_next (const_cast <Type const &> (o));
        }


        virtual void
        nwpriorityModel_next (Type const&);

        virtual void 
        nwpriorityModel_post (Type &o)
        {

          this->nwpriorityModel_post (const_cast <Type const &> (o));
        }


        virtual void
        nwpriorityModel_post (Type const&);

        virtual void 
        cnwpriorityModel_pre (Type &o)
        {

          this->cnwpriorityModel_pre (const_cast <Type const &> (o));
        }


        virtual void
        cnwpriorityModel_pre (Type const&);

        virtual void 
        cnwpriorityModel_next (Type &o)
        {

          this->cnwpriorityModel_next (const_cast <Type const &> (o));
        }


        virtual void
        cnwpriorityModel_next (Type const&);

        virtual void 
        cnwpriorityModel_post (Type &o)
        {

          this->cnwpriorityModel_post (const_cast <Type const &> (o));
        }


        virtual void
        cnwpriorityModel_post (Type const&);

        virtual void 
        threadpool_pre (Type &o)
        {

          this->threadpool_pre (const_cast <Type const &> (o));
        }


        virtual void
        threadpool_pre (Type const&);

        virtual void 
        threadpool_next (Type &o)
        {

          this->threadpool_next (const_cast <Type const &> (o));
        }


        virtual void
        threadpool_next (Type const&);

        virtual void 
        threadpool_post (Type &o)
        {

          this->threadpool_post (const_cast <Type const &> (o));
        }


        virtual void
        threadpool_post (Type const&);

        virtual void 
        priorityBandedConnection_pre (Type &o)
        {

          this->priorityBandedConnection_pre (const_cast <Type const &> (o));
        }


        virtual void
        priorityBandedConnection_pre (Type const&);

        virtual void 
        priorityBandedConnection_next (Type &o)
        {

          this->priorityBandedConnection_next (const_cast <Type const &> (o));
        }


        virtual void
        priorityBandedConnection_next (Type const&);

        virtual void 
        priorityBandedConnection_post (Type &o)
        {

          this->priorityBandedConnection_post (const_cast <Type const &> (o));
        }


        virtual void
        priorityBandedConnection_post (Type const&);

        virtual void 
        id (Type &o)
        {

          this->id (const_cast <Type const &> (o));
        }


        virtual void
        id (Type const&);

        protected:
        PolicySet ();
      };

      struct PriorityModel : Traversal::PriorityModel, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        PriorityModel (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        protected:
        PriorityModel ();
      };

      struct NWPriorityModel : Traversal::NWPriorityModel, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        NWPriorityModel (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {
          this->traverse (const_cast <Type const &> (o));
        }

        virtual void
        traverse (Type const&);

        protected:
        NWPriorityModel ();
      };

      struct PriorityModelPolicyDef : Traversal::PriorityModelPolicyDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::PriorityModelPolicyDef Type;
        PriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        priority_model (Type &o)
        {

          this->priority_model (const_cast <Type const &> (o));
        }


        virtual void
        priority_model (Type const&);

        virtual void 
        server_priority (Type &o)
        {

          this->server_priority (const_cast <Type const &> (o));
        }


        virtual void
        server_priority (Type const&);

        protected:
        PriorityModelPolicyDef ();
      };

      struct NWPriorityModelPolicyDef : Traversal::NWPriorityModelPolicyDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::NWPriorityModelPolicyDef Type;
        NWPriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        nw_priority_model (Type &o)
        {

          this->nw_priority_model (const_cast <Type const &> (o));
        }


        virtual void
        nw_priority_model (Type const&);

        virtual void 
        request_dscp (Type &o)
        {

          this->request_dscp (const_cast <Type const &> (o));
        }


        virtual void
        request_dscp (Type const&);

        virtual void 
        reply_dscp (Type &o)
        {

          this->reply_dscp (const_cast <Type const &> (o));
        }


        virtual void
        reply_dscp (Type const&);

        protected:
        NWPriorityModelPolicyDef ();
      };

      struct CNWPriorityModelPolicyDef : Traversal::CNWPriorityModelPolicyDef, 
      virtual ::XSCRT::Writer< ACE_TCHAR >
      {
        typedef ::CIAO::Config_Handlers::CNWPriorityModelPolicyDef Type;
        CNWPriorityModelPolicyDef (::XSCRT::XML::Element< ACE_TCHAR >&);

        virtual void 
        traverse (Type &o)
        {

          this->traverse (const_cast <Type const &> (o));
        }


        virtual void
        traverse (Type const&);

        virtual void 
        request_dscp (Type &o)
        {

          this->request_dscp (const_cast <Type const &> (o));
        }


        virtual void
        request_dscp (Type const&);

        virtual void 
        reply_dscp (Type &o)
        {

          this->reply_dscp (const_cast <Type const &> (o));
        }


        virtual void
        reply_dscp (Type const&);

        protected:
        CNWPriorityModelPolicyDef ();
      };
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    RT_CCM_Handlers_Export
    void
    ServerResources (::CIAO::Config_Handlers::ServerResourcesDef const&, xercesc::DOMDocument*);
  }
}

#endif // CIAOSERVER_RESOURCES_HPP
