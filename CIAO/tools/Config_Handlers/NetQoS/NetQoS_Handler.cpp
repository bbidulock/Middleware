// $Id$
#include "Utils/XML_Helper.h"
#include "NetQoS_Handler.h"
#include "NetQoSRequirements.hpp"
#include "ciao/NetQoSC.h"

namespace CIAO
{
  namespace Config_Handlers
  {
    NetQoS_Handler::NetQoS_Handler (const ACE_TCHAR *file) :
      idl_netqos_(0),
      netqos_ (0),
      retval_ (false)
    {
      XML_Helper helper;

      XERCES_CPP_NAMESPACE::DOMDocument *dom =
        helper.create_dom (file);

      if (!dom)
        throw NetQoS_Handler::NoNetQoS ();

      this->netqos_.reset (new NetQoSRequirementsDef
                        (NetQoSRequirements (dom)));

      if (!this->build_netqos ())
        throw NoNetQoS ();
    }

    NetQoS_Handler::NetQoS_Handler (NetQoSRequirementsDef *netqos):
      idl_netqos_(0),
      netqos_(netqos),
      retval_(false)
    {
      if(!this->build_netqos())
        throw NoNetQoS ();
    }

    NetQoS_Handler::NetQoS_Handler (::CIAO::DAnCE::NetQoSRequirement *netqos):
      idl_netqos_(netqos),
      netqos_(0),
      retval_(false)
    {
      if(!this->build_xsc())
        throw NoNetQoS ();
    }


    NetQoS_Handler::~NetQoS_Handler (void)
    {
    }

    bool
    NetQoS_Handler::build_netqos ()
    {

      this->idl_netqos_.reset ( new ::CIAO::DAnCE::NetQoSRequirement );

      if (true == this->netqos_->id_p ())
        this->idl_netqos_->Id = CORBA::string_dup (this->netqos_->id().c_str());
      else
        return false;

      for (NetQoSRequirementsDef::connectionQoS_iterator conn_iter = this->netqos_->begin_connectionQoS ();
           conn_iter != this->netqos_->end_connectionQoS ();
           ++conn_iter)
        {
          CIAO::Config_Handlers::ConnectionQoS conn_qos = *conn_iter;
          CIAO::DAnCE::ConnectionQoS idl_conn_qos;

          idl_conn_qos.fwdBWD = conn_qos.fwdBW ();
          idl_conn_qos.revBWD = conn_qos.revBW ();

          if (conn_qos.qos () == CIAO::Config_Handlers::NetworkQoS::HIGH_PRIORITY)
            idl_conn_qos.data_qos = CIAO::DAnCE::HIGH_PRIORITY;
          else if (conn_qos.qos () == CIAO::Config_Handlers::NetworkQoS::HIGH_RELIABILITY)
            idl_conn_qos.data_qos = CIAO::DAnCE::HIGH_RELIABILITY;
          else if (conn_qos.qos () == CIAO::Config_Handlers::NetworkQoS::VOICE)
            idl_conn_qos.data_qos = CIAO::DAnCE::VOICE;
          else if (conn_qos.qos () == CIAO::Config_Handlers::NetworkQoS::VIDEO)
            idl_conn_qos.data_qos = CIAO::DAnCE::VIDEO;
          else if (conn_qos.qos () == CIAO::Config_Handlers::NetworkQoS::BEST_EFFORT)
            idl_conn_qos.data_qos = CIAO::DAnCE::BEST_EFFORT;
          else
            return false;

          if (true == conn_qos.admissionPriority_p ())
          {
            if (CIAO::Config_Handlers::AdmissionPriority::NORMAL == conn_qos.admissionPriority())
              idl_conn_qos.priority = CIAO::DAnCE::NORMAL;
            else if (CIAO::Config_Handlers::AdmissionPriority::HIGH == conn_qos.admissionPriority())
              idl_conn_qos.priority = CIAO::DAnCE::HIGH;
            else if (CIAO::Config_Handlers::AdmissionPriority::LOW == conn_qos.admissionPriority())
              idl_conn_qos.priority = CIAO::DAnCE::LOW;
            else
              return false;
          }
          else
            idl_conn_qos.priority = CIAO::DAnCE::NORMAL;

          for (CIAO::Config_Handlers::ConnectionQoS::connectionInfo_iterator iter = conn_qos.begin_connectionInfo ();
               iter != conn_qos.end_connectionInfo ();
               ++iter)
            {
              CORBA::ULong len = idl_conn_qos.connections.length ();
              idl_conn_qos.connections.length (len + 1);
              idl_conn_qos.connections [len].connection_name = CORBA::string_dup (iter->connectionName().c_str ());
              idl_conn_qos.connections [len].client = CORBA::string_dup (iter->client().c_str ());
              idl_conn_qos.connections [len].client_port_name = CORBA::string_dup (iter->clientPortName().c_str ());
              idl_conn_qos.connections [len].server = CORBA::string_dup (iter->server().c_str ());
              idl_conn_qos.connections [len].server_port_name = CORBA::string_dup (iter->serverPortName().c_str ());
            }

          CORBA::ULong len = this->idl_netqos_->conn_qos_set.length ();
          this->idl_netqos_->conn_qos_set.length (len + 1);
          this->idl_netqos_->conn_qos_set [len] = idl_conn_qos;
        }

        return true;
    }

    bool
    NetQoS_Handler::build_xsc ()
    {
      // Load the ORBConfigs and create the XSC structure for NetQoS
      this->netqos_.reset (new NetQoSRequirementsDef ());

      this->netqos_->id (this->idl_netqos_->Id.in());

      size_t len = this->idl_netqos_->conn_qos_set.length ();
      for (size_t i = 0; i < len; ++i)
      {
        const CIAO::DAnCE::ConnectionQoS & idl_conn_qos = this->idl_netqos_->conn_qos_set [i];
        CIAO::Config_Handlers::ConnectionQoS xsc_conn_qos (idl_conn_qos.fwdBWD,
                                                           idl_conn_qos.revBWD,
                                                           this->get_idl_net_qos (idl_conn_qos.data_qos));

        if (CIAO::DAnCE::NORMAL == idl_conn_qos.priority)
          xsc_conn_qos.admissionPriority (::CIAO::Config_Handlers::AdmissionPriority::NORMAL);
        else if (CIAO::DAnCE::HIGH == idl_conn_qos.priority)
          xsc_conn_qos.admissionPriority (::CIAO::Config_Handlers::AdmissionPriority::HIGH);
        else if (CIAO::DAnCE::LOW == idl_conn_qos.priority)
          xsc_conn_qos.admissionPriority (::CIAO::Config_Handlers::AdmissionPriority::LOW);
        else
          return false;

        size_t num_conn = idl_conn_qos.connections.length ();
        for (size_t j = 0; j < num_conn; ++j)
        {
          CIAO::Config_Handlers::Connection conn (idl_conn_qos.connections[j].connection_name.in(),
                                                  idl_conn_qos.connections[j].client.in(),
                                                  idl_conn_qos.connections[j].client_port_name.in(),
                                                  idl_conn_qos.connections[j].server.in(),
                                                  idl_conn_qos.connections[j].server_port_name.in());
          xsc_conn_qos.add_connectionInfo (conn);
        }

        this->netqos_->add_connectionQoS (xsc_conn_qos);
      }

      return true;
    }

    ::CIAO::Config_Handlers::NetworkQoS
    NetQoS_Handler::get_idl_net_qos (::CIAO::DAnCE::DataTrafficQoS data_qos)
    {
      if (CIAO::DAnCE::HIGH_PRIORITY == data_qos)
        return CIAO::Config_Handlers::NetworkQoS::HIGH_PRIORITY;
      else if (CIAO::DAnCE::HIGH_RELIABILITY == data_qos)
        return CIAO::Config_Handlers::NetworkQoS::HIGH_RELIABILITY;
      else if (CIAO::DAnCE::VIDEO == data_qos)
        return CIAO::Config_Handlers::NetworkQoS::VIDEO;
      else if (CIAO::DAnCE::VOICE == data_qos)
        return CIAO::Config_Handlers::NetworkQoS::VOICE;
      else if (CIAO::DAnCE::BEST_EFFORT == data_qos)
        return CIAO::Config_Handlers::NetworkQoS::BEST_EFFORT;
      //TODO else
        //TODO: What to return here? Can't be false.
    }

    ::CIAO::DAnCE::NetQoSRequirement const *
    NetQoS_Handler::netqos_idl () const
      throw (NetQoS_Handler::NoNetQoS)
    {
      if(!this->idl_netqos_.get())
        throw NoNetQoS ();

      //else
      return this->idl_netqos_.get();
    }

    ::CIAO::DAnCE::NetQoSRequirement *
    NetQoS_Handler::netqos_idl ()
      throw (NetQoS_Handler::NoNetQoS)
    {
      if(!this->idl_netqos_.get())
        throw NoNetQoS();

      //else
      return this->idl_netqos_.release();
    }

    NetQoSRequirementsDef const *
    NetQoS_Handler::netqos_xsc () const
      throw (NetQoS_Handler::NoNetQoS)
    {
      if(!this->netqos_.get())
        throw NoNetQoS ();

      //else
      return this->netqos_.get();
    }

    NetQoSRequirementsDef *
    NetQoS_Handler::netqos_xsc ()
      throw (NetQoS_Handler::NoNetQoS)
    {
      if(!this->netqos_.get())
        throw NoNetQoS ();

      //else
      return this->netqos_.release();
    }
  }
}


