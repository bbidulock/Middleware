// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.9 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:1278

#include "Hello_Sender_Connector_exec.h"
#include "ciao/CIAO_common.h"

#include "dds4ccm/impl/ndds/ParticipantFactory.h"

namespace CIAO_Hello_DDS_Hello_sender_Connector_Impl
{
  //============================================================
  // Facet Executor Implementation Class: string_Writer_exec_i
  //============================================================

  string_Writer_exec_i::string_Writer_exec_i (String_Writer sw)
    : writer_ (sw)
  {
  }

  string_Writer_exec_i::~string_Writer_exec_i (void)
  {
  }

  void
  string_Writer_exec_i::write (const char *an_instance)
  {
    writer_.write (an_instance);
  }

  //============================================================
  // Component Executor Implementation Class: Hello_sender_Connector_exec_i
  //============================================================

  Hello_sender_Connector_exec_i::Hello_sender_Connector_exec_i (void)
    : dds_configured_ (false)
  {
  }

  Hello_sender_Connector_exec_i::~Hello_sender_Connector_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes.

  // Port operations.

  ::CCM_DDS::CCM_string_Writer_ptr
  Hello_sender_Connector_exec_i::get_sender_data (void)
  {
    this->configure_dds ();
    return ::CCM_DDS::CCM_string_Writer::_duplicate (this->sw_.in ());
  }

  ::DDS::CCM_DataWriter_ptr
  Hello_sender_Connector_exec_i::get_sender_dds_entity (void)
  {
    this->configure_dds ();
    return ::DDS::CCM_DataWriter::_duplicate (this->dw_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Hello_sender_Connector_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_DDS::CCM_Hello_sender_Connector_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Hello_sender_Connector_exec_i::configure_dds (void)
  {
    if (this->dds_configured_)
      return;

    try
      {
        //NDDSConfigLogger::get_instance()->set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API,
        //                                                          NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL );

        dpf_ = new CIAO::DDS4CCM::RTI::RTI_DomainParticipantFactory_i ();
        ::DDS::DomainParticipantQos qos;
        dp_ = dpf_->create_participant (0, qos, 0, 0);

        ::DDS::TopicQos tqos;
        t_ = dp_->create_topic ("Hello, World",
                                CIAO::DDS4CCM::RTI::String_Traits::type_support::get_type_name (),
                                tqos,
                                0,
                                0);

        ::DDS::PublisherQos pqos;
        pub_ = dp_->create_publisher (pqos,
                                      0,
                                      0);

        ::DDS::DataWriterQos dwqos;
        DDS::DataWriter_var dwv_tmp = pub_->create_datawriter (t_.in (),
                                                               dwqos,
                                                               0,
                                                               0);

        dw_ = DDS::CCM_DataWriter::_narrow (dwv_tmp);


        String_Writer sw (dw_.in ());

        sw_ = new string_Writer_exec_i (sw);

      }
    catch (const CORBA::Exception &ex)
      {
        CIAO_ERROR ((LM_ERROR, CLINFO "Hello_sender_Connector_exec_i::configure_dds - "
                     "Caught CORBA exception %C\n",
                     ex._info ().c_str ()));
      }
    catch (...)
      {
        CIAO_ERROR ((LM_ERROR, CLINFO "Hello_sender_Connector_exec_i::configure_dds - "
                     "Error: caught unknown C++ exception while configuring DDS\n"));
      }

    this->dds_configured_ = true;
  }


  void
  Hello_sender_Connector_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Hello_sender_Connector_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Hello_sender_Connector_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Hello_sender_Connector_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" HELLO_SENDER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_DDS_Hello_sender_Connector_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_RETURN (
      retval,
      Hello_sender_Connector_exec_i,
      ::Components::EnterpriseComponent::_nil ());

    return retval;
  }
}

namespace CIAO_Hello_DDS_Hello_sender_Connector_Impl
{
  //============================================================
  // Home Executor Implementation Class: SenderConnectorHome_exec_i
  //============================================================

  SenderConnectorHome_exec_i::SenderConnectorHome_exec_i (void)
  {
  }

  SenderConnectorHome_exec_i::~SenderConnectorHome_exec_i (void)
  {
  }

  // All operations and attributes.

  // Factory operations.

  // Finder operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  SenderConnectorHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      Hello_sender_Connector_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" HELLO_SENDER_CONNECTOR_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_DDS_SenderConnectorHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      SenderConnectorHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

