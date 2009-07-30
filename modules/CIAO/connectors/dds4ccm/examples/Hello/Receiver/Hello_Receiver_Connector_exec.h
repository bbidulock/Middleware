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
// be/be_codegen.cpp:1217

#ifndef CIAO_HELLO_RECEIVER_CONNECTOR_EXEC_H_
#define CIAO_HELLO_RECEIVER_CONNECTOR_EXEC_H_

#include /**/ "ace/pre.h"

#include "Hello_Receiver_ConnectorEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Hello_Receiver_Connector_exec_export.h"
#include "tao/LocalObject.h"

#include "dds4ccm/impl/ndds/DataReader.h"
#include "dds4ccm/impl/ndds/Writer.h"
#include "dds4ccm/impl/ndds/DataReaderListener.h"
#include "dds4ccm/impl/ndds/NDDS_Traits.h"

#include <ndds/ndds_cpp.h>

/* The listener of events and data from the middleware */
class HelloListener : public ::DDS::DataReaderListener
{ 
  public:
    HelloListener ( ::CCM_DDS::string_RawListener_ptr listener,
                    ::CCM_DDS::PortStatusListener_ptr statuslistener);
    virtual void on_data_available( ::DDS::DataReader *reader);
    virtual void
    on_requested_deadline_missed (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::RequestedDeadlineMissedStatus & status);
    virtual void
    on_sample_lost (
      ::DDS::DataReader_ptr the_reader,
      const ::DDS::SampleLostStatus & status);
  private:      
    ::CCM_DDS::string_RawListener_var listener_;        
    ::CCM_DDS::PortStatusListener_var statuslistener_;
};




namespace CIAO_Hello_DDS_Hello_receiver_Connector_Impl
{
  class HELLO_RECEIVER_CONNECTOR_EXEC_Export string_Reader_exec_i
    : public virtual ::CCM_DDS::CCM_string_Reader,
      public virtual ::CORBA::LocalObject
  {
  public:
    string_Reader_exec_i (void);
    virtual ~string_Reader_exec_i (void);

    // Operations and attributes from ::CCM_DDS::string_Reader

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    read_all (
      ::CCM_DDS::string_Reader::stringSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    read_all_history (
      ::CCM_DDS::string_Reader::stringSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    read_one (
      char *& an_instance,
      ::CCM_DDS::ReadInfo_out info);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    read_one_history (
      const char * an_instance,
      ::CCM_DDS::string_Reader::stringSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::CCM_DDS::QueryFilter *
    filter (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    filter (
      const ::CCM_DDS::QueryFilter & filter);
  };

  class HELLO_RECEIVER_CONNECTOR_EXEC_Export ListenerControl_exec_i
    : public virtual ::CCM_DDS::CCM_ListenerControl,
      public virtual ::CORBA::LocalObject
  {
  public:
    ListenerControl_exec_i (void);
    virtual ~ListenerControl_exec_i (void);

    // Operations and attributes from ::CCM_DDS::ListenerControl

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::CORBA::Boolean
    enabled (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void
    enabled (
      ::CORBA::Boolean enabled);
  };

  class HELLO_RECEIVER_CONNECTOR_EXEC_Export DataReader_exec_i
    : public virtual ::DDS::CCM_DataReader,
      public virtual ::CORBA::LocalObject
  {
  public:
    DataReader_exec_i (::DDS::DataReader_ptr dr);
    virtual ~DataReader_exec_i (void);

    // Operations and attributes from ::DDS::DataReader

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    enable (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::StatusCondition_ptr
    get_statuscondition (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::StatusMask
    get_status_changes (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::InstanceHandle_t
    get_instance_handle (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReadCondition_ptr
    create_readcondition (
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::QueryCondition_ptr
    create_querycondition (
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states,
      const char * query_expression,
      const ::DDS::StringSeq & query_parameters);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    delete_readcondition (
      ::DDS::ReadCondition_ptr a_condition);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    delete_contained_entities (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    set_qos (
      const ::DDS::DataReaderQos & qos);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_qos (
      ::DDS::DataReaderQos & qos);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    set_listener (
      ::DDS::DataReaderListener_ptr a_listener,
      ::DDS::StatusMask mask);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::DataReaderListener_ptr
    get_listener (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::TopicDescription_ptr
    get_topicdescription (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::Subscriber_ptr
    get_subscriber (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_sample_rejected_status (
      ::DDS::SampleRejectedStatus & status);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_liveliness_changed_status (
      ::DDS::LivelinessChangedStatus & status);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_requested_deadline_missed_status (
      ::DDS::RequestedDeadlineMissedStatus & status);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_requested_incompatible_qos_status (
      ::DDS::RequestedIncompatibleQosStatus & status);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_subscription_matched_status (
      ::DDS::SubscriptionMatchedStatus & status);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_sample_lost_status (
      ::DDS::SampleLostStatus & status);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    wait_for_historical_data (
      const ::DDS::Duration_t & max_wait);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_matched_publications (
      ::DDS::InstanceHandleSeq & publication_handles);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::DDS::ReturnCode_t
    get_matched_publication_data (
      ::DDS::PublicationBuiltinTopicData & publication_data,
      const ::DDS::InstanceHandle_t & publication_handle);
  private:
    ::DDS::DataReader_var dr_;
  };

  class HELLO_RECEIVER_CONNECTOR_EXEC_Export Hello_receiver_Connector_exec_i
    : public virtual Hello_receiver_Connector_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Hello_receiver_Connector_exec_i (void);
    virtual ~Hello_receiver_Connector_exec_i (void);

    // Supported operations and attributes.

    // Component attributes.

    // Port operations.

    virtual ::CCM_DDS::CCM_string_Reader_ptr
    get_receiver_data (void);

    virtual ::CCM_DDS::CCM_ListenerControl_ptr
    get_receiver_control (void);

    virtual ::DDS::CCM_DataReader_ptr
    get_receiver_dds_entity (void);

    // Operations from Components::SessionComponent.

    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);

  private:
    void configure_dds (void);

    ::Hello_DDS::CCM_Hello_receiver_Connector_Context_var context_;

    bool dds_configured_;
    ::DDS::DomainParticipantFactory_var dpf_;
    ::DDS::DomainParticipant_var dp_;
    ::DDS::Topic_var t_;
    ::DDS::Subscriber_var sub_;
    ::DDS::DataReader_var dr_;
    ::DDS::DataReaderListener_var listener_;
  };

  extern "C" HELLO_RECEIVER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_DDS_Hello_receiver_Connector_Impl (void);
}

namespace CIAO_Hello_DDS_Hello_receiver_Connector_Impl
{
  class HELLO_RECEIVER_CONNECTOR_EXEC_Export ReceiverConnectorHome_exec_i
    : public virtual ReceiverConnectorHome_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    ReceiverConnectorHome_exec_i (void);

    virtual ~ReceiverConnectorHome_exec_i (void);

    // All operations and attributes.

    // Factory operations.

    // Finder operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };

  extern "C" HELLO_RECEIVER_CONNECTOR_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_DDS_ReceiverConnectorHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

