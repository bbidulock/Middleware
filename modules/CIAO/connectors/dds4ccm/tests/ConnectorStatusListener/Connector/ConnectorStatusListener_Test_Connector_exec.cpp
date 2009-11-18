// -*- C++ -*-
// $Id$

#include "ConnectorStatusListener_Test_Connector_exec.h"

namespace CIAO_ConnectorStatusListener_Test_ConnectorStatusListener_Test_Connector_Impl
{
  ConnectorStatusListener_Test_Connector_exec_i::ConnectorStatusListener_Test_Connector_exec_i (const char * topic_name)
    : Connector_T<TestTopic_DDS_Traits, TestTopic_Connector_Traits> (topic_name)
  {
  }

  ConnectorStatusListener_Test_Connector_exec_i::~ConnectorStatusListener_Test_Connector_exec_i (void)
  {
  }

  extern "C" CONNECTORSTATUSLISTENER_TEST_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_ConnectorStatusListener_Test_ConnectorStatusListener_Test_Connector_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      ConnectorStatusListener_Test_Connector_exec_i ("Square")); //should be set by dep. plan.

    return retval;
  }
}

