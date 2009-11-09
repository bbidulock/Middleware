// -*- C++ -*-
// $Id$

#ifndef HELLO_CONNECTOR_EXEC_H_
#define HELLO_CONNECTOR_EXEC_H_

#include /**/ "ace/pre.h"

#include "Hello_ConnectorEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Hello_Connector_exec_export.h"
#include "tao/LocalObject.h"

#include "dds4ccm/impl/ndds/NDDS_Traits.h"
#include "dds4ccm/impl/ndds/Connector_T.h"

#include "Base/Hello_BaseSupport.h"

namespace CIAO_Hello_Hello_Connector_Impl
{

  // @from use of DDSHello as a parameter
  typedef CIAO::DDS4CCM::RTI::Type_Traits < 
    DDSHello,
    DDSHello_Seq,
    DDSHelloSeq,
    DDSHelloTypeSupport,
    DDSHelloDataWriter,
    DDSHelloDataReader > DDSHello_DDS_Traits;

  typedef Connector_Traits <
    ::CIAO_Hello_Hello_Connector_Impl::Hello_Connector_Exec,
    ::CCM_DDS::CCM_DDSHello_Writer,
    ::CCM_DDS::CCM_DDSHello_Updater,
    ::CCM_DDS::CCM_DDSHello_Getter,
    ::CCM_DDS::CCM_DDSHello_Reader,
    ::Hello::CCM_Hello_Connector_Context,
    ::CCM_DDS::DDSHello_RawListener,
    ::CCM_DDS::ConnectorStatusListener> DDSHello_Connector_Traits;

  class HELLO_CONNECTOR_EXEC_Export Hello_Connector_exec_i :
    public Connector_T <DDSHello_DDS_Traits, DDSHello_Connector_Traits>
  {
  public:
    Hello_Connector_exec_i (const char * topic_name);
    virtual ~Hello_Connector_exec_i (void);
  };

  extern "C" HELLO_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_Hello_Connector_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

