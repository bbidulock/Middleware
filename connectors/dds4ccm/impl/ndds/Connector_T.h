/**
 * @author Marcel Smit <msmit@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */
#ifndef CONNECTOR_T_H_
#define CONNECTOR_T_H_

#include "dds4ccm/idl/dds_rtf2_dcpsC.h"
#include "ace/Copy_Disabled.h"

template <typename DDS_TYPE, typename CCM_TYPE>
class Connector_T
  : public virtual CCM_TYPE::base_type,
    public virtual ::CORBA::LocalObject,
    private virtual ACE_Copy_Disabled
{
public:
  Connector_T (const char * topic_name);
  virtual ~Connector_T (void);

  virtual char *topic_name (void);

  virtual void topic_name (const char * topic_name);

  virtual ::DDS::StringSeq *key_fields (void);

  virtual void key_fields (const ::DDS::StringSeq & key_fields);

  virtual ::DDS::DomainId_t domain_id (void);

  virtual void domain_id (::DDS::DomainId_t domain_id);

  virtual char *qos_profile (void);

  virtual void qos_profile (const char * qos_profile);

  virtual typename CCM_TYPE::writer_type::_ptr_type get_supplier_data (void);

  virtual ::DDS::CCM_DataWriter_ptr get_supplier_dds_entity (void);

  virtual ::DDS::CCM_DataWriter_ptr get_info_update_dds_entity (void);

  virtual typename CCM_TYPE::updater_type::_ptr_type get_update_data (void);

  virtual typename CCM_TYPE::reader_type::_ptr_type get_pull_consumer_data (void);

  virtual typename CCM_TYPE::getter_type::_ptr_type get_pull_consumer_fresh_data (void);

  virtual typename CCM_TYPE::reader_type::_ptr_type get_push_consumer_data (void);

  virtual ::CCM_DDS::CCM_DataListenerControl_ptr get_push_consumer_data_control (void);

  virtual ::DDS::CCM_DataReader_ptr get_pull_consumer_dds_entity (void);

  virtual ::DDS::CCM_DataReader_ptr get_push_consumer_dds_entity (void);

  virtual void set_session_context (::Components::SessionContext_ptr ctx);

  virtual void configuration_complete (void);

  virtual void ccm_activate (void);
  virtual void ccm_passivate (void);
  virtual void ccm_remove (void);

private:
  typename CCM_TYPE::context_type::_var_type context_;

  // Default stuff
  void configure_default_domain_ (void);
  bool default_domain_configured_;
  ::DDS::DomainParticipantFactory_var domain_factory_;
  ::DDS::DomainParticipant_var domain_;

  // @from DDS_Base
  DDS::DomainId_t domain_id_;
  CORBA::String_var qos_profile_;

  // @from DDS_TopicBase
  void configure_default_topic_ (void);
  bool default_topic_configured_;
  ::DDS::Topic_var topic_;
  CORBA::String_var topic_name_;
  DDS::StringSeq key_fields_;

  // @from DDS_Write for
  void configure_port_info_in_ (void);
  bool __info_in_configured_;
  ::DDS::Publisher_var __info_in_publisher_;
  ::DDS::CCM_DataWriter_var __info_in_datawriter_;
  typename CCM_TYPE::writer_type::_var_type __info_in_writer_;

  // @from DDS_RawListen
  void configure_port_listen_ (bool create_getter);
  bool __listen_configured_;
  ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CCM_DDS::ListenerMode> __listen_datalistener_mode_;
  ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CCM_DDS::DataNumber_t> __listen_datalistener_max_delivered_data_;
  ::DDS::Subscriber_var __listen_subscriber_;
  ::DDS::DataReader_var __listen_datareader_;
  ::DDS::DataReaderListener_var __listen_datareaderlistener;
  ::DDS::DataWriterListener_var __listen_datawriterlistener;

  // @from DDS_Getter
  bool __info_get_configured_;
  ::DDS::DataReader_var __info_get_datareader_;
};

  template <typename BASE_TYPE,
            typename SEQ_TYPE,
            typename WRITER_TYPE,
            typename UPDATER_TYPE,
            typename GETTER_TYPE,
            typename READER_TYPE,
            typename CONTEXT_TYPE,
            typename LISTENER_TYPE,
            typename STATELISTENER_TYPE,
            typename CONNECTORSTATUSLISTENER_TYPE
  >

  struct Connector_Traits
  {
    typedef BASE_TYPE base_type;
    typedef SEQ_TYPE seq_type;
    typedef WRITER_TYPE writer_type;
    typedef UPDATER_TYPE updater_type;
    typedef GETTER_TYPE getter_type;
    typedef READER_TYPE reader_type;
    typedef CONTEXT_TYPE context_type;
    typedef LISTENER_TYPE listener_type;
    typedef STATELISTENER_TYPE statelistener_type;
    typedef CONNECTORSTATUSLISTENER_TYPE connectorstatuslistener_type;
  };


#include "dds4ccm/impl/ndds/Connector_T.cpp"

#endif /* CONNECTOR_T_H_ */
