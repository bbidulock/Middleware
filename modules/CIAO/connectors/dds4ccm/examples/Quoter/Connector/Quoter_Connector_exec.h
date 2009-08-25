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
// .\be\be_codegen.cpp:1217

#ifndef CIAO_QUOTER_CONNECTOR_EXEC_H_
#define CIAO_QUOTER_CONNECTOR_EXEC_H_

#include /**/ "ace/pre.h"

#include "Quoter_ConnectorEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Quoter_Connector_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Quoter_Quoter_Connector_Impl
{
  class QUOTER_CONNECTOR_EXEC_Export Stock_Info_Writer_exec_i
    : public virtual ::CCM_DDS::CCM_Stock_Info_Writer,
      public virtual ::CORBA::LocalObject
  {
  public:
    Stock_Info_Writer_exec_i (void);
    virtual ~Stock_Info_Writer_exec_i (void);
    
    // Operations and attributes from ::CCM_DDS::Stock_Info_Writer
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    write (
      const ::Quoter::Stock_Info & an_instance);
  };
  
  class QUOTER_CONNECTOR_EXEC_Export DataWriter_exec_i
    : public virtual ::DDS::CCM_DataWriter,
      public virtual ::CORBA::LocalObject
  {
  public:
    DataWriter_exec_i (void);
    virtual ~DataWriter_exec_i (void);
    
    // Operations and attributes from ::DDS::DataWriter
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    enable (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::StatusCondition_ptr
    get_statuscondition (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::StatusMask
    get_status_changes (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::InstanceHandle_t
    get_instance_handle (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    set_qos (
      const ::DDS::DataWriterQos & qos);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_qos (
      ::DDS::DataWriterQos & qos);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    set_listener (
      ::DDS::DataWriterListener_ptr a_listener,
      ::DDS::StatusMask mask);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::DataWriterListener_ptr
    get_listener (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::Topic_ptr
    get_topic (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::Publisher_ptr
    get_publisher (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    wait_for_acknowledgments (
      const ::DDS::Duration_t & max_wait);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_liveliness_lost_status (
      ::DDS::LivelinessLostStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_offered_deadline_missed_status (
      ::DDS::OfferedDeadlineMissedStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_offered_incompatible_qos_status (
      ::DDS::OfferedIncompatibleQosStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_publication_matched_status (
      ::DDS::PublicationMatchedStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    assert_liveliness (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_matched_subscriptions (
      ::DDS::InstanceHandleSeq & subscription_handles);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_matched_subscription_data (
      ::DDS::SubscriptionBuiltinTopicData & subscription_data,
      const ::DDS::InstanceHandle_t & subscription_handle);
  };
  
  class QUOTER_CONNECTOR_EXEC_Export Stock_Info_Reader_exec_i
    : public virtual ::CCM_DDS::CCM_Stock_Info_Reader,
      public virtual ::CORBA::LocalObject
  {
  public:
    Stock_Info_Reader_exec_i (void);
    virtual ~Stock_Info_Reader_exec_i (void);
    
    // Operations and attributes from ::CCM_DDS::Stock_Info_Reader
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    read_all (
      ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    read_all_history (
      ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    read_one (
      ::Quoter::Stock_Info & an_instance,
      ::CCM_DDS::ReadInfo_out info);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    read_one_history (
      const ::Quoter::Stock_Info & an_instance,
      ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CCM_DDS::QueryFilter *
    filter (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    filter (
      const ::CCM_DDS::QueryFilter & filter);
  };
  
  class QUOTER_CONNECTOR_EXEC_Export ListenerControl_exec_i
    : public virtual ::CCM_DDS::CCM_ListenerControl,
      public virtual ::CORBA::LocalObject
  {
  public:
    ListenerControl_exec_i (void);
    virtual ~ListenerControl_exec_i (void);
    
    // Operations and attributes from ::CCM_DDS::ListenerControl
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Boolean
    enabled (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    enabled (
      ::CORBA::Boolean enabled);
  };
  
  class QUOTER_CONNECTOR_EXEC_Export DataReader_exec_i
    : public virtual ::DDS::CCM_DataReader,
      public virtual ::CORBA::LocalObject
  {
  public:
    DataReader_exec_i (void);
    virtual ~DataReader_exec_i (void);
    
    // Operations and attributes from ::DDS::DataReader
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    enable (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::StatusCondition_ptr
    get_statuscondition (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::StatusMask
    get_status_changes (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::InstanceHandle_t
    get_instance_handle (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReadCondition_ptr
    create_readcondition (
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::QueryCondition_ptr
    create_querycondition (
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states,
      const char * query_expression,
      const ::DDS::StringSeq & query_parameters);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    delete_readcondition (
      ::DDS::ReadCondition_ptr a_condition);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    delete_contained_entities (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    set_qos (
      const ::DDS::DataReaderQos & qos);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_qos (
      ::DDS::DataReaderQos & qos);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    set_listener (
      ::DDS::DataReaderListener_ptr a_listener,
      ::DDS::StatusMask mask);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::DataReaderListener_ptr
    get_listener (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::TopicDescription_ptr
    get_topicdescription (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::Subscriber_ptr
    get_subscriber (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_sample_rejected_status (
      ::DDS::SampleRejectedStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_liveliness_changed_status (
      ::DDS::LivelinessChangedStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_requested_deadline_missed_status (
      ::DDS::RequestedDeadlineMissedStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_requested_incompatible_qos_status (
      ::DDS::RequestedIncompatibleQosStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_subscription_matched_status (
      ::DDS::SubscriptionMatchedStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_sample_lost_status (
      ::DDS::SampleLostStatus & status);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    wait_for_historical_data (
      const ::DDS::Duration_t & max_wait);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_matched_publications (
      ::DDS::InstanceHandleSeq & publication_handles);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::ReturnCode_t
    get_matched_publication_data (
      ::DDS::PublicationBuiltinTopicData & publication_data,
      const ::DDS::InstanceHandle_t & publication_handle);
  };
  
  class QUOTER_CONNECTOR_EXEC_Export Quoter_Connector_exec_i
    : public virtual Quoter_Connector_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Quoter_Connector_exec_i (void);
    virtual ~Quoter_Connector_exec_i (void);
    
    // Supported operations and attributes.
    
    // Component attributes.
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char *
    topic_name (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::StringSeq *
    key_fields (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::DomainId_t
    domain_id (void);
    
    // TAO_IDL - Generated from
    // w:\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char *
    qos_provile (void);
    
    // Port operations.
    
    virtual ::CCM_DDS::CCM_Stock_Info_Writer_ptr
    get_info_in_data (void);
    
    virtual ::DDS::CCM_DataWriter_ptr
    get_info_in_dds_entity (void);
    
    virtual ::CCM_DDS::CCM_Stock_Info_Reader_ptr
    get_info_out_data (void);
    
    virtual ::CCM_DDS::CCM_ListenerControl_ptr
    get_info_out_control (void);
    
    virtual ::DDS::CCM_DataReader_ptr
    get_info_out_dds_entity (void);
    
    // Operations from Components::SessionComponent.
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
  
  private:
    ::Quoter::CCM_Quoter_Connector_Context_var context_;
  };
  
  extern "C" QUOTER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Quoter_Connector_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

