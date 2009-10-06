// -*- C++ -*-
// $Id$

#include "Quoter_Connector_exec.h"
#include "ciao/CIAO_common.h"

#include "dds4ccm/impl/ndds/NDDS_Traits.h"
#include "dds4ccm/impl/ndds/DomainParticipantFactory.h"
#include "dds4ccm/impl/ndds/DomainParticipant.h"
#include "dds4ccm/impl/ndds/DataReaderListener_T.h"

// Should be removed after we refactor stuff back into ndds impl.
#include "dds4ccm/impl/ndds/DataReader.h"
#include "dds4ccm/impl/ndds/ListenerControl.h"

namespace CIAO_Quoter_Quoter_Connector_Impl
{
  //============================================================
  // Component Executor Implementation Class: Quoter_Connector_exec_i
  //============================================================

  Quoter_Connector_exec_i::Quoter_Connector_exec_i (void)
    : default_domain_configured_ (false),
      domain_id_ (0),
      default_topic_configured_ (false),
      topic_name_ ("Quoter_Topic"),
      __info_in_configured_ (false),
      __info_out_configured_ (false),
      __info_out_rawlistener_enabled_ (false)

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
    CIAO_DEBUG ((LM_TRACE, CLINFO "Quoter_Connector_exec_i::configure_default_domain_ - "
                 "Configuring default domain\n"));

    if (this->default_domain_configured_) return;

    try
      {
        NDDSConfigLogger::get_instance()->set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API,
                                                                   NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL );

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
    CIAO_DEBUG ((LM_TRACE, CLINFO "Quoter_Connector_exec_i::configure_default_topic_ - "
                 "Configuring default topic\n"));
    if (this->default_topic_configured_) return;

    this->configure_default_domain_ ();

    try
      {
        if (CORBA::is_nil (this->topic_))
          {
            CIAO::DDS4CCM::RTI::RTI_DomainParticipant_i *part = dynamic_cast< CIAO::DDS4CCM::RTI::RTI_DomainParticipant_i * > (this->domain_.in ());
            DDS_ReturnCode_t retcode = Stock_Info_Traits::type_support::register_type(
              part->get_participant (), Stock_Info_Traits::type_support::get_type_name ());
            if (retcode == DDS_RETCODE_OK)
              {
                ::DDS::TopicQos tqos;
                this->topic_ =
                  this->domain_->create_topic (this->topic_name_.in (),
                                               Stock_Info_Traits::type_support::get_type_name (),
                                               tqos,
                                               0,
                                               0);
              }
            else
              {
                throw CORBA::INTERNAL ();
              }
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

            this->__info_out_datareaderlistener = new ::CIAO::DDS4CCM::RTI::DataReaderListener_T<Stock_Info_Traits, ::CCM_DDS::Stock_Info_RawListener, ::CCM_DDS::PortStatusListener> (
              this->context_->get_connection_info_out_listener (),
              this->context_->get_connection_info_out_status (),
              this->__info_out_rawlistener_enabled_);
            ::DDS::DataReaderQos drqos;
            this->__info_out_datareader_ =
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
    std::cerr << "get_info_in_data" << std::endl;

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
    std::cerr << "get_info_out_data" << std::endl;

    //this->configure_port_info_in_ ();

    return new CIAO::DDS4CCM::RTI::Reader_T<Stock_Info_Traits,
      ::CCM_DDS::CCM_Stock_Info_Reader> (this->__info_out_datareader_.in ());
  }

  ::CCM_DDS::CCM_ListenerControl_ptr
  Quoter_Connector_exec_i::get_info_out_control (void)
  {
    /* Your code here. */
    return new CCM_DDS_ListenerControl_i (this->__info_out_rawlistener_enabled_);
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
    if (!CORBA::is_nil (this->context_->get_connection_info_out_listener ()) ||
        !CORBA::is_nil (this->context_->get_connection_info_out_status ()))
      {
        this->configure_port_info_out_ ();
      }
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

