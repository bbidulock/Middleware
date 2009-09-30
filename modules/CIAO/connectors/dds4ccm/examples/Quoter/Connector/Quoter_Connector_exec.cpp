// -*- C++ -*-
//
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.2
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 *       http://doc.ece.uci.edu/
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1278

#include "Quoter_Connector_exec.h"
#include "ciao/CIAO_common.h"

#include "dds4ccm/impl/ndds/NDDS_Traits.h"
#include "dds4ccm/impl/ndds/DomainParticipantFactory.h"

// should be removed after lem fix
#include "../Broker/BrokerEC.h"

// should be removed after we refactor stuff back into ndds impl.
#include "dds4ccm/impl/ndds/DataReader.h"


namespace CIAO_Quoter_Quoter_Connector_Impl
{
  //============================================================
  // Facet Executor Implementation Class: Stock_Info_Reader_exec_i
  //============================================================
  
  Stock_Info_Reader_exec_i::Stock_Info_Reader_exec_i (void)
  {
  }
  
  Stock_Info_Reader_exec_i::~Stock_Info_Reader_exec_i (void)
  {
  }
  
  // Operations from ::CCM_DDS::Stock_Info_Reader
  
  void
  Stock_Info_Reader_exec_i::read_all (
    ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    /* Your code here. */
  }
  
  void
  Stock_Info_Reader_exec_i::read_all_history (
    ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    /* Your code here. */
  }
  
  void
  Stock_Info_Reader_exec_i::read_one (
    ::Quoter::Stock_Info & /* an_instance */,
    ::CCM_DDS::ReadInfo_out /* info */)
  {
    /* Your code here. */
  }
  
  void
  Stock_Info_Reader_exec_i::read_one_history (
    const ::Quoter::Stock_Info & /* an_instance */,
    ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out /* instances */,
    ::CCM_DDS::ReadInfoSeq_out /* infos */)
  {
    /* Your code here. */
  }
  
  ::CCM_DDS::QueryFilter *
  Stock_Info_Reader_exec_i::filter (void)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  Stock_Info_Reader_exec_i::filter (
    const ::CCM_DDS::QueryFilter & /* filter */)
  {
    /* Your code here. */
  }
  
  //============================================================
  // Component Executor Implementation Class: Quoter_Connector_exec_i
  //============================================================
  
  Quoter_Connector_exec_i::Quoter_Connector_exec_i (void)
  {
  }
  
  Quoter_Connector_exec_i::~Quoter_Connector_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes.
  
  char *
  Quoter_Connector_exec_i::topic_name (void)
  {
    // @from DDS_TopicBase
    return CORBA::string_dup (this->topic_name_.in ());
  }
  
  void
  Quoter_Connector_exec_i::topic_name (
    const char * topic_name)
  {
    // @from DDS_TopicBase
    this->topic_name_ = topic_name;
  }
  
  ::DDS::StringSeq *
  Quoter_Connector_exec_i::key_fields (void)
  {
    // @from DDS_TopicBase
    ::DDS::StringSeq *retval = 
      new ::DDS::StringSeq (this->key_fields_.length ());
    
    for (CORBA::ULong i = 0; i < this->key_fields_.length (); ++i)
      (*retval)[i] = CORBA::string_dup (this->key_fields_[i]);
    
    return retval;
  }
  
  void
  Quoter_Connector_exec_i::key_fields (
    const ::DDS::StringSeq & key_fields)
  {
    // @from DDS_TopicBase
    this->key_fields_.length (key_fields.length ());
    
    for (CORBA::ULong i = 0; i < this->key_fields_.length (); ++i)
      this->key_fields_[i] = CORBA::string_dup (key_fields[i]);
  }
  
  ::DDS::DomainId_t
  Quoter_Connector_exec_i::domain_id (void)
  {
    // @from DDS_Base
    return this->domain_id_;
  }
  
  void
  Quoter_Connector_exec_i::domain_id (
    ::DDS::DomainId_t domain_id)
  {
    // @from DDS_Base
    this->domain_id_ = domain_id;
  }
  
  char *
  Quoter_Connector_exec_i::qos_profile (void)
  {
    // @from DDS_Base
    return CORBA::string_dup (this->qos_profile_.in ());
  }
  
  void
  Quoter_Connector_exec_i::qos_profile (
    const char * qos_profile)
  {
    // @from DDS_Base
    this->qos_profile_ = qos_profile;
  }
  
  // Port operations.

  void
  Quoter_Connector_exec_i::configure_default_domain_ (void)
  {
    if (this->default_domain_configured_) return;

    try
      {
        // Generic code
        this->domain_factory_ = new ::CIAO::DDS4CCM::RTI::RTI_DomainParticipantFactory_i ();
        
        ::DDS::DomainParticipantQos qos;
        this->domain_ = 
          this->domain_factory_->create_participant (this->domain_id_,
                                                     qos,
                                                     0,
                                                     0);
      }
    catch (...)
      {
        CIAO_ERROR ((LM_ERROR, "Caught unknown C++ exception whilst configuring default domain\n"));
        throw CORBA::INTERNAL ();
      }
  }

  void 
  Quoter_Connector_exec_i::configure_default_topic_ (void)
  {
    if (this->default_topic_configured_) return;
    
    this->configure_default_domain_ ();
    
    try
      {
        if (CORBA::is_nil (this->topic_))
          {
            ::DDS::TopicQos tqos;
            this->topic_ = 
              this->domain_->create_topic (this->topic_name_.in (),
                                           Stock_Info_Traits::type_support::get_type_name (),
                                           tqos,
                                           0,
                                           0);
          }
      }
    catch (...)
      {
        CIAO_ERROR ((LM_ERROR, "Caught unknown error while configuring default topic\n"));
        throw CORBA::INTERNAL ();
      }
  } 
  
  void 
  Quoter_Connector_exec_i::configure_port_info_in_ (void)
  {
    if (this->__info_in_configured_)
      return;
    
    this->configure_default_topic_ ();
    
    try
      {
        if (CORBA::is_nil (this->__info_in_publisher_.in ()))
          {
            ::DDS::PublisherQos pqos;
            this->__info_in_publisher_ = this->domain_->create_publisher (pqos,
                                                                          0,
                                                                          0);
          }
        
        if (CORBA::is_nil  (this->__info_in_datawriter_.in ()))
          {
            ::DDS::DataWriterQos dwqos;
            ::DDS::DataWriter_var dwv_tmp = this->__info_in_publisher_->create_datawriter (this->topic_.in (),
                                                                                           dwqos,
                                                                                           0,
                                                                                           0);
            this->__info_in_datawriter_ = ::DDS::CCM_DataWriter::_narrow (dwv_tmp);
          }    
      }
    catch (...)
      {
        CIAO_ERROR ((LM_ERROR, "Caught unknown C++ exception while configuring port info_in_\n"));
        throw CORBA::INTERNAL ();
      }
  }
  
  
  class info_out_Listener :
    public virtual ::DDS::DataReaderListener
  {
  public:
    info_out_Listener (::CCM_DDS::Stock_Info_RawListener_ptr listen,
                   ::CCM_DDS::PortStatusListener_ptr psl)
      : enable_ (false),
        listener_ (::CCM_DDS::Stock_Info_RawListener::_duplicate (listen)),
        portlistener_ (::CCM_DDS::PortStatusListener::_duplicate (psl))
    {
    };

    // from DataReaderListener
    virtual void on_data_available( ::DDS::DataReader *rdr)
    {
      if (!this->enable_.value ())
        return;

      ::CIAO::DDS4CCM::RTI::RTI_DataReader_i* rd = dynamic_cast < ::CIAO::DDS4CCM::RTI::RTI_DataReader_i*>(rdr);
      ::Quoter::Stock_InfoDataReader * reader = dynamic_cast< ::Quoter::Stock_InfoDataReader * > ((rd->get_datareader ()));

      if (!reader) {
        /* In this specific case, this will never fail */
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Stock_InfoDataReader::narrow failed.\n")));
        return;
      }
      
      /* Loop until there are messages available in the queue */
      for(;;) {
        ::Quoter::Stock_Info instance;
        ::DDS_SampleInfo sampleinfo;
        ::DDS::ReturnCode_t result  = reader->take_next_sample(instance,
                                                               sampleinfo);
        if (result == DDS_RETCODE_NO_DATA) {
            /* No more samples */
            break;
        } else if (result != DDS_RETCODE_OK) {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("Unable to take data from data reader, error %d.\n"), result));
            return;
        }
        if (sampleinfo.valid_data) {
            ::CCM_DDS::ReadInfo empty;
            listener_->on_data (instance, empty);
        }
        
      }
      
    };
    
    virtual void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
                                               const ::DDS::RequestedDeadlineMissedStatus & status)
    {
      this->portlistener_->on_requested_deadline_missed (the_reader, status);
    };
    
    
    virtual void on_sample_lost (::DDS::DataReader_ptr the_reader,
                                 const ::DDS::SampleLostStatus & status)
    {
      this->portlistener_->on_sample_lost (the_reader, status);
    };
    
    
    
    // From ListenerControl
    bool enabled () const;
    void enabled (bool enable);
    
  private:
    ::CCM_DDS::Stock_Info_RawListener_var listener_;
    ::CCM_DDS::PortStatusListener_var portlistener_;
    ACE_Atomic_Op <TAO_SYNCH_MUTEX, bool> enable_;;
  };
  
  void
  Quoter_Connector_exec_i::configure_port_info_out_ (void)
  {
    if (this->__info_out_configured_)
      return;
    
    this->configure_default_topic_ ();
    
    try
      {
        if (CORBA::is_nil (this->__info_out_subscriber_.in ()))
          {
            ::DDS::SubscriberQos sqos;
            this->__info_out_subscriber_ = this->domain_->create_subscriber (sqos,
                                                                              0,
                                                                              0);
          }
        
        if (CORBA::is_nil (this->__info_out_datareader_.in ()))
          {
            this->__info_out_portstatus_ = this->context_->get_connection_info_out_status ();
            
            this->__info_out_datareaderlistener = new info_out_Listener (this->context_->get_connection_info_out_listener (),
                                                                         this->context_->get_connection_info_out_status ());
            
            ::DDS::DataReaderQos drqos;
            this->__info_out_datareaderlistener = 
              this->__info_out_subscriber_->create_datareader (this->topic_.in (),
                                                               drqos,
                                                               this->__info_out_datareaderlistener.in (),
                                                               DDS_DATA_AVAILABLE_STATUS);
          }
        
      }
    catch (...)
      {
        CIAO_ERROR ((LM_EMERGENCY, "Caught unknown c++ exception while creating subscriber entities\n"));
        throw CORBA::INTERNAL ();
      }
  }
  
  ::CCM_DDS::CCM_Stock_Info_Writer_ptr
  Quoter_Connector_exec_i::get_info_in_data (void)
  {
    this->configure_port_info_in_ ();
    
    return new CIAO::DDS4CCM::RTI::Writer_T<Stock_Info_Traits,
      ::CCM_DDS::CCM_Stock_Info_Writer> (this->__info_in_datawriter_.in ());
  }
  
  ::DDS::CCM_DataWriter_ptr
  Quoter_Connector_exec_i::get_info_in_dds_entity (void)
  {
    this->configure_port_info_in_ ();
    
    return this->__info_in_datawriter_.in ();
  }
  
  ::CCM_DDS::CCM_Stock_Info_Reader_ptr
  Quoter_Connector_exec_i::get_info_out_data (void)
  {
    /* Your code here. */
    return ::CCM_DDS::CCM_Stock_Info_Reader::_nil ();
  }
  
  ::CCM_DDS::CCM_ListenerControl_ptr
  Quoter_Connector_exec_i::get_info_out_control (void)
  {
    /* Your code here. */
    return ::CCM_DDS::CCM_ListenerControl::_nil ();
  }
  
  ::DDS::CCM_DataReader_ptr
  Quoter_Connector_exec_i::get_info_out_dds_entity (void)
  {
    /* Your code here. */
    return ::DDS::CCM_DataReader::_nil ();
  }
  
  // Operations from Components::SessionComponent.
  
  void
  Quoter_Connector_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    ::Quoter::CCM_Quoter_Connector_Context_var lctx = 
      ::Quoter::CCM_Quoter_Connector_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (lctx.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
    
    this->context_ = lctx;
  }
  
  void
  Quoter_Connector_exec_i::configuration_complete (void)
  {
  }
  
  void
  Quoter_Connector_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  Quoter_Connector_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Quoter_Connector_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C" QUOTER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Quoter_Connector_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Quoter_Connector_exec_i);
    
    return retval;
  }
}

