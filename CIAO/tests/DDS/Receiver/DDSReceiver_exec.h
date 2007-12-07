// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#ifndef CIAO_DDSRECEIVER_EXEC_H
#define CIAO_DDSRECEIVER_EXEC_H

#include /**/ "ace/pre.h"

#include "DDSReceiver_svnt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "DDSReceiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIDL_DDSReceiverImpl
{
  class DDSRECEIVER_EXEC_Export DDSReceiver_exec_i
    : public virtual DDSReceiver_Exec,
      public virtual TAO_Local_RefCounted_Object
  {
    public:
    DDSReceiver_exec_i (void);
    virtual ~DDSReceiver_exec_i (void);

    // Supported or inherited operations.

    // Attribute operations.

    // Port operations.

    virtual void
    push_dds_input (
      ::DDSTest::DDSTopic_event *ev);

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void ciao_preactivate ();

    virtual void ciao_postactivate ();

    virtual void ccm_activate ();

    virtual void ccm_passivate ();

    virtual void ccm_remove ();

    protected:
    DDSReceiver_Context *context_;
  };

  class DDSRECEIVER_EXEC_Export DDSReceiverHome_exec_i
    : public virtual DDSReceiverHome_Exec,
      public virtual TAO_Local_RefCounted_Object
  {
    public:
    DDSReceiverHome_exec_i (void);
    virtual ~DDSReceiverHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" DDSRECEIVER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_DDSTest_DDSReceiverHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_DDSRECEIVER_EXEC_H */

