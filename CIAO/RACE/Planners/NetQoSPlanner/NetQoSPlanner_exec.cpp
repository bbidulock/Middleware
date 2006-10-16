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

#include "NetQoSPlanner_exec.h"
#include "ciao/CIAO_common.h"
#include "ciao/NetQoSC.h"
#include "ciao/DeploymentS.h"
#include "BandwidthBroker/BandwidthBrokerC.h"
#include "ace/INET_Addr.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/Naming/Naming_Client.h"
//#include "tao/CORBALOC_Parser.h"

#include <iostream>
#include <fstream>

using namespace mil::darpa::arms::mlrm;
using namespace mil::darpa::arms::mlrm::BandwidthBroker;

/*
Named loops idiom
http://www.csse.monash.edu.au/~damian/Idioms/Topics/07.SB.NamedLoops/html/text.html
*/
#define NAMED(blockname) goto blockname; \
 blockname##_skip: if (0) blockname:
#define BREAK(blockname) goto blockname##_skip;

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_NetQoSPlanner_Impl
    {
      //==================================================================
      // Facet Executor Implementation Class:   Planner_I_exec_i
      //==================================================================

      Planner_I_exec_i::Planner_I_exec_i (NetQoSPlanner_exec_i & net_qos)
        : net_qos_planner_exec_(&net_qos)
      {
      }

      Planner_I_exec_i::~Planner_I_exec_i (void)
      {
      }

      // Operations from ::CIAO::RACE::Planner_I

      ::CORBA::Boolean
      Planner_I_exec_i::process_plan (
        ::CIAO::RACE::Plan_Actions &  plans
        ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((::CORBA::SystemException,
                       ::CIAO::RACE::PlannerFailure))
      {
        return this->net_qos_planner_exec_->process_plan (plans);
      }
    
      ::CORBA::Boolean
      Planner_I_exec_i::process_domain_change (
        const ::CIAO::RACE::Planner_I::Domain_Changes & /* changes */,
        ::CIAO::RACE::Plan_Actions_out /* plans */
        ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                      ::CIAO::RACE::PlannerFailure))
      {
        // Your code here.
        return true;
      }

      char *
      Planner_I_exec_i::name (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        // Your code here.
        return this->net_qos_planner_exec_->name ();
      }
      
      char *
      Planner_I_exec_i::type (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        // Your code here.
        return this->net_qos_planner_exec_->type ();
      }

      //==================================================================
      // Component Executor Implementation Class:   NetQoSPlanner_exec_i
      //==================================================================

      NetQoSPlanner_exec_i::NetQoSPlanner_exec_i (void)
       : node_map_filename_ ("NodeDetails.dat"),
         planner_name_ ("NetQoSPlanner"),
         planner_type_ ("Netqork QoS Planner")
      {
      }

      NetQoSPlanner_exec_i::~NetQoSPlanner_exec_i (void)
      {
      }

      // Supported or inherited operations.

      // Attribute operations.

      char *
      NetQoSPlanner_exec_i::name (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ACE_DEBUG ((LM_DEBUG, "(%N:%l): NetQoSPlanner_exec_i::name()\n"));
        return CORBA::string_dup (this->planner_name_.c_str());
      }

      void
      NetQoSPlanner_exec_i::name (
        const char *  name 
        ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        this->planner_name_ = name;// Your code here.
      }

      char *
      NetQoSPlanner_exec_i::type (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ACE_DEBUG ((LM_DEBUG, "(%N:%l): NetQoSPlanner_exec_i::type()\n"));
        return CORBA::string_dup (this->planner_type_.c_str());
      }

      void
      NetQoSPlanner_exec_i::type (
        const char *  type 
        ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        // Your code here.
        this->planner_type_ = type;
      }

      char *
      NetQoSPlanner_exec_i::node_map_file (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        // Your code here.
        return CORBA::string_dup(this->node_map_filename_.c_str());
      }

      void
      NetQoSPlanner_exec_i::node_map_file (
        const char *  node_map_file 
        ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        // Your code here.
        this->node_map_filename_ = node_map_file;
      }

      // Port operations.

      ::CORBA::Boolean
      NetQoSPlanner_exec_i::process_plan (
        ::CIAO::RACE::Plan_Actions &  plans
        ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::CIAO::RACE::PlannerFailure))
      {
        bool retval = true;
        for (size_t i = 0; i < plans.length (); ++i)
          {
            ::Deployment::DeploymentPlan &dep_plan = plans[i].plan;
            bool flag_netqos_present = false;

            for (size_t j = 0;
                 j < dep_plan.infoProperty.length();
                 ++j)
              {
                if (ACE_OS::strcmp (dep_plan.infoProperty[j].name.in (),
                                    "CIAONetworkQoS") == 0)
                 {
                   flag_netqos_present = true;
                   ::Deployment::DiffservInfos dscp_infos;
                   ::CIAO::DAnCE::NetworkQoS::NetQoSRequirement *net_qos_req;

                   if (dep_plan.infoProperty [j].value >>= net_qos_req)
                    {
                        this->build_instance_node_map (dep_plan);
                        if (this->process_netqos_req (net_qos_req, dep_plan, dscp_infos))
                          {
                            // Remove CIAONetworkQoS infoProperty
                            CORBA::ULong length = dep_plan.infoProperty.length();
                            //ACE_DEBUG ((LM_ERROR, "(%N:%l): Length of dep_plan.infoProperty before removal = %u\n",length));
                            if (length > j+1)
                            {
                              for (size_t k = j + 1; k < length; ++k)
                                {
                                  dep_plan.infoProperty[k-1] = dep_plan.infoProperty[k];
                                }
                            }
                            dep_plan.infoProperty.length(length - 1);
                            // Removal code ends
                            this->add_network_priorities (dep_plan, dscp_infos);
                            this->dump_policies (dep_plan);
                            this->dump_deployed_resources (dep_plan);
                            retval = true;
                          }
                        else
                          {
                            ACE_DEBUG ((LM_ERROR, "(%N:%l): process_netqos_req failed.\n"));
                            retval = false;
                          }
                    }
                    else
                    {
                      ACE_DEBUG ((LM_ERROR, "(%N:%l)Conversion to Any failed for NetworkQoS.\n"));
                      retval = false;
                    }
                 }
               }
             if (!flag_netqos_present)
               {
                 ACE_DEBUG ((LM_DEBUG, "No CIANetworkQoS info-property defined in this deployment plan.\n"));
               }
          }
        return retval;
      }
      
      void NetQoSPlanner_exec_i::dump_policies (const ::Deployment::DeploymentPlan &dep_plan)
      {
        ACE_DEBUG((LM_DEBUG,"Dumping policies\n"));
        ::CIAO::DAnCE::ServerResource *sr;
        dep_plan.infoProperty[0].value >>= sr;
        size_t setlen = sr->orb_config.policy_set.length ();
        for (size_t set = 0; set < setlen; ++set)
          {
            ::CIAO::DAnCE::PolicySet & ps = sr->orb_config.policy_set[set];
            ACE_DEBUG((LM_DEBUG, "Set #=%d, Id=%s\n", set, ps.Id.in())); 
            size_t def_len = ps.policies.length();
            for (size_t def = 0; def < def_len; ++def)
              {
                CIAO::DAnCE::PolicyDef &pd = ps.policies[def];
                switch (pd._d()) 
                  {
                     case CIAO::DAnCE::CLIENT_NETWORK_PRIORITY_TYPE:
                        {
                          ACE_DEBUG((LM_DEBUG,"CNWPriorityModelPolicyDef \
request_dscp = %d, reply_dscp = %d\n",pd.CNWPriorityModelDef().request_dscp,
pd.CNWPriorityModelDef().reply_dscp));
                          break;

                        }
                     case CIAO::DAnCE::NETWORK_PRIORITY_TYPE:
                        {
                          ACE_DEBUG((LM_DEBUG,"NWPriorityModelPolicyDef \
request_dscp = %d, reply_dscp = %d\n",pd.NWPriorityModelDef().request_dscp,
pd.NWPriorityModelDef().reply_dscp));
                          break;
                        }
                     default:
                        {
                          ACE_DEBUG((LM_DEBUG,"Unknown union descriminator.\n"));
                          break;
                        }
                  }
              }
          }
      }
      
      void NetQoSPlanner_exec_i::dump_deployed_resources (const ::Deployment::DeploymentPlan &dep_plan)
      {
        ACE_DEBUG ((LM_DEBUG,"Dumping deployed resources\n"));
        size_t instances = dep_plan.instance.length();
        for (size_t i = 0;i < instances; ++i)
          {
            const ::Deployment::InstanceDeploymentDescription &instdd = dep_plan.instance[i];
            ACE_DEBUG((LM_DEBUG,"Instance name = %s\n", instdd.name.in()));
            size_t resources = instdd.deployedResource.length();
            for (size_t j = 0; j < resources; ++j)
              {
                const ::Deployment::InstanceResourceDeploymentDescription &resdd = instdd.deployedResource[j];
                ACE_DEBUG((LM_DEBUG,"requirementName = %s\n",resdd.requirementName.in()));
                ACE_DEBUG((LM_DEBUG,"resourceName = %s\n",resdd.resourceName.in()));
                for (size_t prop = 0; prop < resdd.property.length();++prop)
                  {
                    ACE_DEBUG((LM_DEBUG,"property name = %s\n",resdd.property[prop].name.in()));                   
                    const char * value;
                    resdd.property[prop].value >>= value;
                    ACE_DEBUG((LM_DEBUG,"property value = %s\n",value)); 
                  }
              } 
          }
      }

      void NetQoSPlanner_exec_i::build_instance_node_map (const Deployment::DeploymentPlan & dep_plan)
      {
        for (size_t i = 0;i < dep_plan.instance.length (); ++i)
          {
            const Deployment::InstanceDeploymentDescription &instance = dep_plan.instance[i];
            this->instance_node_map_.insert (std::make_pair (instance.name.in (),instance.node.in()));
          }
      }

      bool NetQoSPlanner_exec_i::process_netqos_req (const ::CIAO::DAnCE::NetworkQoS::NetQoSRequirement *net_qos_req,
                                                     const ::Deployment::DeploymentPlan &dep_plan,
                                                     ::Deployment::DiffservInfos & dscp_infos)
      {
        size_t set_len = net_qos_req->conn_qos_set.length();
        if (set_len != 0)
          {
            // Build an in memory map of logical nodes to the physical hosts.
            this->build_node_map ();

            if (! this->resolve_BB ())
              {
                ACE_DEBUG ((LM_ERROR, "(%N:%l): Can't contact BandwidthBroker.\n"));
                return false;
              }

            bool rollback = false;
            //ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: set_len = %u\n",set_len));

            NAMED(outer)
            for (size_t k = 0; k < set_len; ++k)
              {
                const ::CIAO::DAnCE::NetworkQoS::ConnectionQoS & conn_qos = net_qos_req->conn_qos_set[k];
                //ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: conn_qos.connections.length () = %u\n",conn_qos.connections.length ()));
                for (size_t conn_num = 0;
                     conn_num < conn_qos.connection_names.length ();
                     ++conn_num)
                  {
                    ::Deployment::DiffservInfo endpoint;
                    if (this->get_endpoints(endpoint, dep_plan, std::string (conn_qos.connection_names[conn_num])))
                    {
                      CommonDef::IPAddress srcIP;
                      if (-1 == this->get_ip_address (srcIP, endpoint.client_instance_name.in()))
                      {
                        ACE_DEBUG ((LM_ERROR,"In NetQoSPlanner_exec_i::process_netqos_req: Can't find source IP\n"));
                        rollback = true;
                        BREAK(outer);
                      }
                      ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: srcIP = %s\n",srcIP.dottedDecimal.in()));
                      CommonDef::IPAddress destIP;
                      if (-1 == this->get_ip_address(destIP, endpoint.server_instance_name.in()))
                      {
                        ACE_DEBUG ((LM_ERROR,"In NetQoSPlanner_exec_i::process_netqos_req: Can't find destination IP\n"));
                        rollback = true;
                        BREAK(outer);
                      }
                      ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: destIP = %s\n",destIP.dottedDecimal.in()));
                      CommonDef::QOSRequired qos_req;
                      this->get_traffic_qos (qos_req, conn_qos);
                      long fwd_dscp = 0, rev_dscp = 0;

                      if (-1 == this->make_flow_request (srcIP, destIP, conn_qos.fwdBWD, qos_req, fwd_dscp))
                      {
                        rollback = true;
                        BREAK(outer);
                      }

                      size_t len = dscp_infos.length ();
                      dscp_infos.length (len + 1);
                      dscp_infos [len] = endpoint;
                      dscp_infos [len].request_dscp = fwd_dscp;
                      dscp_infos [len].reply_dscp = rev_dscp; /// Assigning zero here.
                      ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: fwd_dscp = %d\n",fwd_dscp));

                      if (conn_qos.revBWD > 0)
                      {
                        if (-1 == this->make_flow_request (destIP, srcIP, conn_qos.revBWD, qos_req, rev_dscp))
                        {
                          rollback = true;
                          BREAK(outer);
                        }
                        ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: rev_dscp = %d\n",rev_dscp));
                        dscp_infos [len].reply_dscp = rev_dscp;
                      }
                      /*              std::cerr
                                      << "Connection Name = " << conn_qos.connections [conn_num].connection_name   << std::endl
                                      << "client Name = " << conn_qos.connections [conn_num].client                << std::endl
                                      << "client Port Name = " << conn_qos.connections [conn_num].client_port_name << std::endl
                                      << "server Name = " << conn_qos.connections [conn_num].server                << std::endl
                                      << "server Port Name = " << conn_qos.connections [conn_num].server_port_name << std::endl;
                       */
                    }
                  else
                    {
                      ACE_DEBUG((LM_DEBUG,"Connection was not found in the deployment plan.\n"));
                    }  
                    /*
                       std::cerr << "fwdBWD = " << conn_qos.fwdBWD << std::endl;
                       std::cerr << "revBWD = " << conn_qos.revBWD << std::endl;

                       if (::CIAO::DAnCE::NetworkQoS::NORMAL == conn_qos.priority)
                       std::cerr << "Priority = NORMAL\n";
                       else if (::CIAO::DAnCE::NetworkQoS::HIGH == conn_qos.priority)
                       std::cerr << "Priority = HIGH\n";
                       else if (::CIAO::DAnCE::NetworkQoS::LOW == conn_qos.priority)
                       std::cerr << "Priority = LOW\n";
                     */
                  }
              }

              if (rollback)
                {
                  this->BB_proxy_.rollback ();
                  return false;
                }
              else
                {
                  this->BB_proxy_.commit ();
                  return true;
                }
          }
        else
          {
             ACE_DEBUG((LM_ERROR, "Connection set is empty in the NetQoS schema.\n"));
             return true;
          }
      }

      bool NetQoSPlanner_exec_i::get_endpoints (::Deployment::DiffservInfo &diffserv_conn, 
                                                const ::Deployment::DeploymentPlan &dep_plan,
                                                const std::string &conn_name)
      {
        size_t total_connections = dep_plan.connection.length();
        for (size_t num_conn = 0; num_conn < total_connections; ++num_conn)
          {
            if (conn_name == dep_plan.connection[num_conn].name.in())
              {
                const ::Deployment::PlanConnectionDescription & conn_desc =
                      dep_plan.connection [num_conn];
                for (size_t i = 0; i < 2; ++i)
                  {
                    switch (conn_desc.internalEndpoint[i].kind)
                      {
                        case Deployment::Facet:
                        case Deployment::EventConsumer:
                        case Deployment::ecEventConsumer:
                        case Deployment::rtecEventConsumer:
                        case Deployment::nsEventConsumer:
                          {
                            unsigned long index = conn_desc.internalEndpoint[i].instanceRef;
                            diffserv_conn.server_instance_name = dep_plan.instance[index].name;
                            diffserv_conn.server_port_name = conn_desc.internalEndpoint[i].portName;
                            diffserv_conn.server_port_kind = conn_desc.internalEndpoint[i].kind;
                            break;
                          }
                        case Deployment::SimplexReceptacle:
                        case Deployment::MultiplexReceptacle:
                        case Deployment::EventEmitter:
                        case Deployment::EventPublisher:
                        case Deployment::ecEventEmitter:
                        case Deployment::ecEventPublisher:
                        case Deployment::rtecEventEmitter:
                        case Deployment::rtecEventPublisher:
                        case Deployment::nsEventEmitter:
                        case Deployment::nsEventPublisher:
                          {
                            unsigned long index = conn_desc.internalEndpoint[i].instanceRef;
                            diffserv_conn.client_instance_name = dep_plan.instance[index].name;
                            diffserv_conn.client_port_name = conn_desc.internalEndpoint[i].portName;
                            diffserv_conn.client_port_kind = conn_desc.internalEndpoint[i].kind;
                            break;
                          }
                      }
                  }
                return true;
              } 
          }
        return false;
      }

      int NetQoSPlanner_exec_i::get_ip_address (CommonDef::IPAddress & ip, const char *instance_name)
      {
        //const int FAKE_PORT = 20000;
        std::string inst_name (instance_name);
        if (this->instance_node_map_.find (inst_name) != this->instance_node_map_.end ())
        {
          const std::string &logical_node = this->instance_node_map_[inst_name];
          ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: logical_node = %s\n",logical_node.c_str()));
          //const std::string &physical_node = this->get_physical_host (logical_node);
          ip.dottedDecimal = CORBA::string_dup (logical_node.c_str());
          ip.subnetMask = CORBA::string_dup ("255.255.255.255");
          return 0;
/*          ACE_INET_Addr addr (FAKE_PORT, physical_node.c_str (), AF_INET);
          if (const char *ip_addr = addr.get_host_addr ())
            {
              ip.dottedDecimal = CORBA::string_dup (ip_addr);
              ip.subnetMask = CORBA::string_dup ("255.255.255.255");
              return 0;
            }
          else
            return -1;
*/        }
        else
          return -1;
      }

      void
      NetQoSPlanner_exec_i::get_traffic_qos (CommonDef::QOSRequired &qos_req,
                                             const ::CIAO::DAnCE::NetworkQoS::ConnectionQoS & conn_qos)
      {
          if (::CIAO::DAnCE::NetworkQoS::HIGH_PRIORITY == conn_qos.data_qos)
            qos_req = CommonDef::highPriority;
          else if (::CIAO::DAnCE::NetworkQoS::HIGH_RELIABILITY == conn_qos.data_qos)
            qos_req = CommonDef::highReliability;
          else if (::CIAO::DAnCE::NetworkQoS::VIDEO == conn_qos.data_qos)
            qos_req = CommonDef::mmVideo;
          else if (::CIAO::DAnCE::NetworkQoS::VOICE == conn_qos.data_qos)
            qos_req = CommonDef::mmVoice;
          else if (::CIAO::DAnCE::NetworkQoS::BEST_EFFORT == conn_qos.data_qos)
            qos_req = CommonDef::bestEffort;
          /*
          else if (::CIAO::DAnCE::NetworkQoS::HIGH_THROUGHPUT == conn_qos.data_qos)
            qos_req = CommonDef::highThroughput;
          */
          else
            qos_req = CommonDef::raw;
      }

      int NetQoSPlanner_exec_i::make_flow_request (const CommonDef::IPAddress &srcIP,
                                                   const CommonDef::IPAddress &destIP,
                                                   int bandwidth,
                                                   CommonDef::QOSRequired qos_req,
                                                   long &dscp)
      {
          AdmissionControl::FlowInfo flowinfo;

          flowinfo.srcIP = srcIP;
          flowinfo.srcPort.low = -1;
          flowinfo.srcPort.high = -1;

          flowinfo.destIP = destIP;
          flowinfo.destPort.low = -1;
          flowinfo.destPort.high = -1;

          flowinfo.protocol = AdmissionControl::notSpecified;
          flowinfo.fwdRate.requiredBW = CORBA::Long (bandwidth);
          flowinfo.fwdRate.extraBW = CORBA::Long (0);
          flowinfo.revRate.requiredBW = CORBA::Long (0);
          flowinfo.revRate.extraBW = CORBA::Long (0);
          flowinfo.biDirectional = CORBA::Boolean (false);
          flowinfo.flowDuration = CORBA::Long (1000);

          ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: Requesting flow.\n"));
          int result = this->BB_proxy_.flow_request (flowinfo, qos_req, dscp);

          if (-1 == result)
              ACE_DEBUG ((LM_ERROR,"In NetQoSPlanner_exec_i::process_netqos_req: Requested flow was not admitted.\n"));
          else
              ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: Flow Accepted.\n"));

          return result;
      }

      void NetQoSPlanner_exec_i::build_node_map ()
      { 
          //std::cerr << "Node_map Filename: " << this->node_map_file () << std::endl;
          std::ifstream input_file (this->node_map_file ());
          std::istream_iterator <std::string> begin (input_file), end;
          for (; begin != end; )
            {
               std::string logical_node = *begin++;
               if (begin == end)
                break;
               //std::cerr << "Logical node name = " << logical_node << std::endl;
               std::string corbaloc_url = *begin++;
               //std::cerr << "Physical corbaloc URL = " << corbaloc_url << std::endl;
               //TAO_CORBALOC_Parser corbaloc_parser;
               //std:: cerr << "Is it a valid corbaloc URL? = " << corbaloc_parser.match_prefix (corbaloc_url.c_str()) << std::endl;
               if (1/*corbaloc_parser.match_prefix (corbaloc_url.c_str())*/)
                 {
                    size_t first = corbaloc_url.find (':', 0); 
                    size_t second = corbaloc_url.find (':', first + 1);
                    size_t third = corbaloc_url.find (':', second + 1);
                    std::string hostname = corbaloc_url.substr (second + 1, third - second - 1);
                    //std::cerr << "Hostname = " << hostname << std::endl;
                    this->node_map_.insert (make_pair (logical_node, hostname));
                 }
               else
                 {
                    ACE_DEBUG ((LM_ERROR, "In NetQoSPlanner_exec_i::process_netqos_req(): Incorrect corbaloc URL"));
                 }
            }
      }

      std::string NetQoSPlanner_exec_i::get_physical_host (const std::string &logical_node)
      {
        if (this->node_map_.find (logical_node) != this->node_map_.end ())
        {
           return this->node_map_[logical_node];
        }
        else
           return std::string ("");
      }
      
      void NetQoSPlanner_exec_i::build_instance_index_map (
           const ::Deployment::DeploymentPlan &dep_plan)
      {
        CORBA::ULong instance_len = dep_plan.instance.length ();
        for (CORBA::ULong j = 0; j < instance_len; ++j)
          {
            const char *instance_name = dep_plan.instance[j].name.in ();
            this->instance_map_.bind (instance_name, j);
          }
      }
      
      std::string NetQoSPlanner_exec_i::push_policy 
           (CIAO::DAnCE::ServerResource &server_resource, 
            const std::string & instance_name,
            NWPriorityModel model,
            int request_dscp, int reply_dscp)
      {
        static long policy_count = 0;
        CORBA::ULong policy_set_len = server_resource.orb_config.policy_set.length ();
        CORBA::ULong new_policy_set_len = policy_set_len + 1;
        server_resource.orb_config.policy_set.length (new_policy_set_len);
        ::CIAO::DAnCE::PolicySet &policy_set =
            server_resource.orb_config.policy_set[policy_set_len];

        std::ostringstream policy_set_id;
        policy_set_id << "test_policy_set_id" <<  policy_count++ 
                      <<  "_" << instance_name;

        policy_set.Id = CORBA::string_dup (policy_set_id.str().c_str ());

        CORBA::ULong policy_def_len = policy_set.policies.length ();
        CORBA::ULong new_policy_def_len = policy_def_len + 1;
        policy_set.policies.length (new_policy_def_len);

        if (SERVER == model)
          {
            ::CIAO::DAnCE::NWPriorityModelPolicyDef npmd;
            npmd.nw_priority_model = ::CIAO::DAnCE::CLIENT_PROPAGATED_NWPRIORITY;
            npmd.request_dscp = request_dscp;
            npmd.reply_dscp = reply_dscp;
     
            policy_set.policies[policy_def_len].NWPriorityModelDef (npmd); 
          }
        else if (CLIENT == model)
          {
            ::CIAO::DAnCE::CNWPriorityModelPolicyDef cnpmd;
            cnpmd.request_dscp = request_dscp;
            cnpmd.reply_dscp = reply_dscp;

            policy_set.policies[policy_def_len].CNWPriorityModelDef (cnpmd);
          }
        
        return policy_set_id.str();
      } 

      void NetQoSPlanner_exec_i::push_deployed_resource 
             (Deployment::DeploymentPlan &dep_plan,
              size_t server_instance_iter,
              const std::string &policy_set_id)
      {
          static long server_resource_count = 0;
          CORBA::ULong dep_res_len = dep_plan.instance[server_instance_iter].deployedResource.length ();
          CORBA::ULong new_dep_res_len = dep_res_len + 1;
          dep_plan.instance[server_instance_iter].deployedResource.length (new_dep_res_len);

          Deployment::InstanceResourceDeploymentDescription &resource_desc =
            dep_plan.instance[server_instance_iter].deployedResource[dep_res_len]; 

          resource_desc.resourceUsage = Deployment::InstanceUsesResource;
          resource_desc.requirementName = CORBA::string_dup ("CIAO:PolicySet");
          std::ostringstream res_name;
          res_name <<  "test_server_resource_name" << server_resource_count++;
          resource_desc.resourceName = CORBA::string_dup (res_name.str().c_str());

          CORBA::ULong pro_len = resource_desc.property.length ();
          CORBA::ULong new_pro_len = pro_len + 1;
          resource_desc.property.length (new_pro_len);
          resource_desc.property[pro_len].name = CORBA::string_dup ("CIAO:InstancePolicy");
          resource_desc.property[pro_len].value <<= policy_set_id.c_str ();
    }

     void NetQoSPlanner_exec_i::push_deployed_resource(Deployment::DeploymentPlan &dep_plan, 
                                                       size_t client_instance_iter, 
                                                       const std::string & policy_set_id, 
                                                       const std::string & client_port_name,
                                                       Deployment::CCMComponentPortKind client_port_kind)
     { 
          static long client_resource_count = 0;
          CORBA::ULong dep_res_len = dep_plan.instance[client_instance_iter].deployedResource.length ();
          CORBA::ULong new_dep_res_len = dep_res_len + 1;
          dep_plan.instance[client_instance_iter].deployedResource.length (new_dep_res_len);

          Deployment::InstanceResourceDeploymentDescription &resource_desc = 
             dep_plan.instance[client_instance_iter].deployedResource[dep_res_len];

          resource_desc.resourceUsage = Deployment::InstanceUsesResource;
          resource_desc.requirementName = CORBA::string_dup ("CIAO:PolicySet");
          std::ostringstream res_name;
          res_name << "test_client_resource_name" << client_resource_count++;
          resource_desc.resourceName = CORBA::string_dup (res_name.str().c_str());

          CORBA::ULong pro_len = resource_desc.property.length ();
          CORBA::ULong new_pro_len = pro_len + 1;
          resource_desc.property.length (new_pro_len);
          if (Deployment::SimplexReceptacle == client_port_kind ||  
              Deployment::MultiplexReceptacle == client_port_kind)
            {
                resource_desc.property[pro_len].name = CORBA::string_dup ("CIAO:ReceptaclePolicy");
            }
          else if (Deployment::EventPublisher == client_port_kind)
            {
                resource_desc.property[pro_len].name = CORBA::string_dup ("CIAO:PublisherPolicy");
            }
            
          resource_desc.property[pro_len].value <<= policy_set_id.c_str ();

          pro_len = resource_desc.property.length ();
          new_pro_len = pro_len + 1;
          resource_desc.property.length (new_pro_len);
          resource_desc.property[pro_len].name = client_port_name.c_str();
          resource_desc.property[pro_len].value <<= policy_set_id.c_str ();
     }

      // *********************************************************
      // code that creates the deployment plan populating the network
      // priority policies using the diffserv codepoint decisions.

      void
      NetQoSPlanner_exec_i::add_network_priorities (Deployment::DeploymentPlan & dep_plan,
                                                    const Deployment::DiffservInfos & dscp_infos)
      {
        static long server_resource_count = 0;
        this->build_instance_index_map(dep_plan);

        CORBA::ULong len = dscp_infos.length ();
        CIAO::DAnCE::ServerResource server_resource;
        std::ostringstream id;
        id << "test_server_resource_id" << server_resource_count++;
        server_resource.Id = CORBA::string_dup (id.str().c_str());

        for (CORBA::ULong i = 0; i < len; ++i)
          {
            std::string server_instance_name = dscp_infos[i].server_instance_name.in ();
            std::string client_instance_name = dscp_infos[i].client_instance_name.in ();
            std::string client_port_name = dscp_infos[i].client_port_name.in ();
            Deployment::CCMComponentPortKind client_port_kind = dscp_infos[i].client_port_kind; 

            CORBA::Long request_dscp = dscp_infos[i].request_dscp;
            CORBA::Long reply_dscp = dscp_infos[i].reply_dscp;

            int server_instance_iter = 0;
            if (this->instance_map_.find (server_instance_name.c_str(), server_instance_iter) == 0)
              {
                std::string policy_set_id = this->push_policy (server_resource, server_instance_name, SERVER, 0, 0);
                this->push_deployed_resource (dep_plan, server_instance_iter, policy_set_id);    
              }
    
            int client_instance_iter = 0;
            if (this->instance_map_.find (client_instance_name.c_str(), client_instance_iter) == 0)
              {
                std::string policy_set_id = this->push_policy (server_resource, client_instance_name, CLIENT, request_dscp, reply_dscp);
                this->push_deployed_resource (dep_plan, client_instance_iter, policy_set_id, client_port_name, client_port_kind);
              }
          }
    
        CORBA::ULong info_prop_len = dep_plan.infoProperty.length ();
        CORBA::ULong new_info_prop_len = info_prop_len + 1;
        dep_plan.infoProperty.length (new_info_prop_len);
        dep_plan.infoProperty[info_prop_len].name = CORBA::string_dup ("CIAOServerResources");
        dep_plan.infoProperty[info_prop_len].value <<= server_resource;
      }

      bool
      NetQoSPlanner_exec_i::resolve_BB ()
      {
        return this->BB_proxy_.resolve (this->context_->_ciao_the_Container ()->the_ORB ());
      }

      ::CIAO::RACE::CCM_Planner_I_ptr
      NetQoSPlanner_exec_i::get_planner_i (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        // Your code here.
        return new Planner_I_exec_i (*this);
        //return ::CIAO::RACE::CCM_Planner_I::_nil ();
      }

      // Operations from Components::SessionComponent

      void
      NetQoSPlanner_exec_i::set_session_context (
        ::Components::SessionContext_ptr ctx
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::CCMException))
      {
        this->context_ =
          NetQoSPlanner_Context::_narrow (
            ctx
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;

        if (this->context_ == 0)
        {
          ACE_THROW ( ::CORBA::INTERNAL ());
        }
      }

      void
      NetQoSPlanner_exec_i::ciao_preactivate (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::CCMException))
      {
        // Your code here.
      }

      void
      NetQoSPlanner_exec_i::ciao_postactivate (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::CCMException))
      {
        // Your code here.
      }

      void
      NetQoSPlanner_exec_i::ccm_activate (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::CCMException))
      {
        // Your code here.
      }

      void
      NetQoSPlanner_exec_i::ccm_passivate (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::CCMException))
      {
        // Your code here.
      }

      void
      NetQoSPlanner_exec_i::ccm_remove (
        ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::CCMException))
      {
        // Your code here.
      }

      //==================================================================
      // Home Executor Implementation Class:   NetQoSPlanner_Home_exec_i
      //==================================================================

      NetQoSPlanner_Home_exec_i::NetQoSPlanner_Home_exec_i (void)
      {
      }

      NetQoSPlanner_Home_exec_i::~NetQoSPlanner_Home_exec_i (void)
      {
      }

      // Supported or inherited operations.

      // Home operations.

      // Factory and finder operations.

      // Attribute operations.

      // Implicit operations.

      ::Components::EnterpriseComponent_ptr
      NetQoSPlanner_Home_exec_i::create (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::CCMException))
      {
        ::Components::EnterpriseComponent_ptr retval =
          ::Components::EnterpriseComponent::_nil ();

        ACE_NEW_THROW_EX (
          retval,
          NetQoSPlanner_exec_i,
          ::CORBA::NO_MEMORY ());
        ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());

        return retval;
      }

      extern "C" NETQOSPLANNER_EXEC_Export ::Components::HomeExecutorBase_ptr
      create_CIAO_RACE_NetQoSPlanner_Home_Impl (void)
      {
        ::Components::HomeExecutorBase_ptr retval =
          ::Components::HomeExecutorBase::_nil ();

        ACE_NEW_RETURN (
          retval,
          NetQoSPlanner_Home_exec_i,
          ::Components::HomeExecutorBase::_nil ());

        return retval;
      }
    }
  }
}

