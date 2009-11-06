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
#include "dds4ccm/impl/ndds/Writer_T.h"
#include "dds4ccm/impl/ndds/DataReaderListener.h"
#include "dds4ccm/impl/ndds/NDDS_Traits.h"

#include <ndds/ndds_cpp.h>

namespace CIAO_Hello_DDS_Hello_receiver_Connector_Impl
{
  class HELLO_RECEIVER_CONNECTOR_EXEC_Export string_Reader_exec_i
    : public virtual ::CCM_DDS::CCM_string_Reader,
      public virtual ::CORBA::LocalObject
  {
  public:
    string_Reader_exec_i (DDSStringDataReader *reader);
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
    private:
      DDSStringDataReader *reader_;
      DDSQueryCondition* condition_;
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
    ::DDS::DataReaderListener_var listener_;
    ::DDS::CCM_DataReader_var dr_;
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

