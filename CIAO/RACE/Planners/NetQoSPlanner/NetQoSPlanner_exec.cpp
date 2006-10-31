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
       : current_pm_ (0),
         node_map_filename_ ("NodeDetails.dat"),
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
            std::string dep_plan_uuid (plans[i].plan.UUID.in());
            if (CIAO::RACE::DEPLOY == plans[i].command)
              {
                if (this->dep_plan_map_.find (dep_plan_uuid) ==
                    this->dep_plan_map_.end())
                {
                  PlanManager *plan_man = 0;
                  retval = this->deploy_plan (plans[i].plan, plan_man);
                  if (retval) 
                    this->dep_plan_map_.insert (std::make_pair(dep_plan_uuid, plan_man));
                }
                else
                  ACE_DEBUG((LM_ERROR,"This plan has already been deployed. UUID = %s",dep_plan_uuid.c_str()));
              }
            else if (CIAO::RACE::TEARDOWN == plans[i].command)
              {
                std::map <std::string, PlanManager *>::iterator plan_iter = 
                  this->dep_plan_map_.find (dep_plan_uuid);
                if (plan_iter != this->dep_plan_map_.end())
                {
                   ACE_DEBUG ((LM_DEBUG,"Tearing down plan.\n"));
                   retval = this->teardown_plan (dep_plan_uuid);
                   
                   if (!retval)  
                     ACE_DEBUG((LM_ERROR,"teardown of the plan failed somewhere. UUID = %s\n",dep_plan_uuid.c_str()));
                   
                   delete plan_iter->second;
                   this->dep_plan_map_.erase (plan_iter);
                }
                else
                  ACE_DEBUG((LM_ERROR,"This plan has NOT been deployed. UUID = %s",dep_plan_uuid.c_str()));
              }
            else
              {
                ACE_DEBUG ((LM_ERROR,"Unknown command.\n"));
                retval = false;
              }
          }
        return retval;
      }
      
      bool NetQoSPlanner_exec_i::teardown_plan (std::string const &dep_plan_uuid)
      {
         return this->dep_plan_map_.find (dep_plan_uuid)->second->teardown();
      }
      
      bool NetQoSPlanner_exec_i::deploy_plan (::Deployment::DeploymentPlan &dep_plan,
                                              PlanManager *&plan_man_ptr)
      {
          bool flag_netqos_present = false;
          bool retval = true;

          for (size_t j = 0; j < dep_plan.infoProperty.length(); ++j)
            {
              if (ACE_OS::strcmp (dep_plan.infoProperty[j].name.in (),
                                  "CIAONetworkQoS") == 0)
               {
                 flag_netqos_present = true;
                 try
                 {
                    std::auto_ptr<PlanManager> plan_man 
                      (new PlanManager(dep_plan, j, this->node_map_filename_));
                    this->current_pm_ = plan_man.get();
                    
                    if (this->process_netqos_req ())
                      {
                        plan_man->add_network_priorities ();
                        plan_man->remove_netqos ();
                        //this->dump_policies (dep_plan);
                        //this->dump_deployed_resources (dep_plan);
                        //@TODO 
                        plan_man_ptr = plan_man.release ();
                        retval = true;
                      }
                    else
                      {
                        ACE_DEBUG ((LM_ERROR, "(%N:%l): process_netqos_req failed.\n"));
                        retval = false;
                      }
                  }
                  catch (PlanManager::Invalid_NetQoS &ex)
                  {
                    ACE_DEBUG ((LM_ERROR, "(%N:%l)Conversion to Any failed for NetworkQoS.\n"));
                    retval = false;
                  }
                  catch (...)
                  {
                    ACE_DEBUG ((LM_ERROR, "(%N:%l)An unknown exception was raised.\n"));
                    retval = false;
                  }
               }
             }
           if (!flag_netqos_present)
             {
               ACE_DEBUG ((LM_DEBUG, "No CIANetworkQoS info-property defined in this deployment plan.\n"));
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

      bool NetQoSPlanner_exec_i::process_netqos_req ()
      {
        ::CIAO::DAnCE::NetworkQoS::NetQoSRequirement const *
          net_qos_req = this->current_pm_->getNetQoS();
        
        size_t set_len = net_qos_req->conn_qos_set.length();
        if (set_len != 0)
          {
            if (! this->resolve_BB ())
              {
                ACE_DEBUG ((LM_ERROR, "(%N:%l): Can't contact BandwidthBroker.\n"));
                return false;
              }
            this->BB_proxy_.set_plan_manager (this->current_pm_);
            
            bool rollback = false;
            //ACE_DEBUG ((LM_DEBUG,"In NetQoSPlanner_exec_i::process_netqos_req: set_len = %u\n",set_len));

            NAMED(outer)
            for (size_t k = 0; k < set_len; ++k)
              {
                const ::CIAO::DAnCE::NetworkQoS::ConnectionQoS & conn_qos =
                  net_qos_req->conn_qos_set[k];
                /*ACE_DEBUG ((LM_DEBUG,
                              "In NetQoSPlanner_exec_i::process_netqos_req: conn_qos.connections.length () = %u\n",
                                conn_qos.connections.length ()));*/
                for (size_t conn_num = 0;
                     conn_num < conn_qos.connection_names.length ();
                     ++conn_num)
                  {
                    ::Deployment::DiffservInfo endpoint;
                    if (this->current_pm_->get_endpoints (
                                   endpoint, 
                                   std::string (conn_qos.connection_names[conn_num])))
                    {
                      CommonDef::IPAddress srcIP;
                      if (-1 == this->current_pm_->get_ip_address (srcIP,
                                                      endpoint.client_instance_name.in()))
                      {
                        ACE_DEBUG ((LM_ERROR,
                                    "In NetQoSPlanner_exec_i::process_netqos_req: Can't find source IP\n"));
                        rollback = true;
                        BREAK(outer);
                      }
                      ACE_DEBUG ((LM_DEBUG,
                                  "In NetQoSPlanner_exec_i::process_netqos_req: srcIP = %s\n",
                                  srcIP.dottedDecimal.in()));
                      CommonDef::IPAddress destIP;
                      if (-1 == this->current_pm_->get_ip_address(destIP,
                                                     endpoint.server_instance_name.in()))
                      {
                        ACE_DEBUG ((LM_ERROR,
                                    "In NetQoSPlanner_exec_i::process_netqos_req: Can't find destination IP\n"));
                        rollback = true;
                        BREAK(outer);
                      }
                      ACE_DEBUG ((LM_DEBUG,
                                  "In NetQoSPlanner_exec_i::process_netqos_req: destIP = %s\n",
                                  destIP.dottedDecimal.in()));
                      CommonDef::QOSRequired qos_req;
                      this->get_traffic_qos (qos_req, conn_qos);
                      long fwd_dscp = 0, rev_dscp = 0;

                      if (conn_qos.fwdBWD > 0)
                        {
                          if (-1 == this->make_flow_request 
                                      (srcIP, destIP, conn_qos.fwdBWD, qos_req, fwd_dscp))
                            {
                              rollback = true;
                              BREAK(outer);
                            }
                            endpoint.request_dscp = fwd_dscp;
                            
                            ACE_DEBUG ((LM_DEBUG,
                                        "In NetQoSPlanner_exec_i::process_netqos_req: fwd_dscp = %d\n",
                                        fwd_dscp));

                            if (conn_qos.revBWD > 0)
                            {
                              if (-1 == this->make_flow_request 
                                          (destIP, srcIP, conn_qos.revBWD, qos_req, rev_dscp))
                              {
                                rollback = true;
                                BREAK(outer);
                              }
                              ACE_DEBUG ((LM_DEBUG,
                                          "In NetQoSPlanner_exec_i::process_netqos_req: rev_dscp = %d\n",
                                          rev_dscp));
                            }

                            endpoint.reply_dscp = rev_dscp;
                            this->current_pm_->push_dscp_info(endpoint);
                        }
                      else
                        {
                          ACE_DEBUG((LM_ERROR,"Invalid forward bandwidth = %d\n",conn_qos.fwdBWD));
                        }
                    }
                  else
                    {
                      ACE_DEBUG((LM_DEBUG,
                                 "Extra connection found in the NetQoS requirements structure.\n"));
                    }  
                  }
              }

              if (rollback)
                {
                  ACE_DEBUG ((LM_DEBUG,"Starting Rollback...\n"));
                  this->BB_proxy_.rollback ();
                  ACE_DEBUG ((LM_DEBUG,"Finished Rollback.\n"));
                  return false;
                }
              else
                {
                  ACE_DEBUG ((LM_DEBUG,"Starting Commit..\n"));
                  this->BB_proxy_.commit ();
                  ACE_DEBUG ((LM_DEBUG,"Finished Commit.\n"));
                  return true;
                }
          }
        else
          {
             ACE_DEBUG((LM_ERROR, "Connection set is empty in the NetQoS schema.\n"));
             return true;
          }
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

          ACE_DEBUG ((LM_DEBUG,
                "In NetQoSPlanner_exec_i::make_flow_request: Requesting flow.\n"));
          int result = this->BB_proxy_.flow_request 
                                         (flowinfo, qos_req, dscp, this->current_pm_);

          if (-1 == result)
              ACE_DEBUG ((LM_ERROR,
                    "In NetQoSPlanner_exec_i::make_flow_request: Requested flow was not admitted.\n"));
          else
              ACE_DEBUG ((LM_DEBUG,
                    "In NetQoSPlanner_exec_i::make_flow_request: Flow Accepted.\n"));

          return result;
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

