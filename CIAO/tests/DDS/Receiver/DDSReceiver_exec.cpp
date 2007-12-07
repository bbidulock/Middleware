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

#include "DDSReceiver_exec.h"
#include "ciao/CIAO_common.h"

namespace CIDL_DDSReceiverImpl
{
  //==================================================================
  // Component Executor Implementation Class:   DDSReceiver_exec_i
  //==================================================================

  DDSReceiver_exec_i::DDSReceiver_exec_i (void)
  {
  }

  DDSReceiver_exec_i::~DDSReceiver_exec_i (void)
  {
  }

  // Supported or inherited operations.

  // Attribute operations.

  // Port operations.

  void
  DDSReceiver_exec_i::push_dds_input (
    ::DDSTest::DDSTopic_event * /* ev */)
  {
    // Your code here.
  }

  // Operations from Components::SessionComponent

  void
  DDSReceiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      DDSReceiver_Context::_narrow (ctx);

    if (this->context_ == 0)
    {
      throw ::CORBA::INTERNAL ();
    }
  }

  void
  DDSReceiver_exec_i::ciao_preactivate ()
  {
    // Your code here.
  }

  void
  DDSReceiver_exec_i::ciao_postactivate ()
  {
    // Your code here.
  }

  void
  DDSReceiver_exec_i::ccm_activate ()
  {
    // Your code here.
  }

  void
  DDSReceiver_exec_i::ccm_passivate ()
  {
    // Your code here.
  }

  void
  DDSReceiver_exec_i::ccm_remove ()
  {
    // Your code here.
  }

  //==================================================================
  // Home Executor Implementation Class:   DDSReceiverHome_exec_i
  //==================================================================

  DDSReceiverHome_exec_i::DDSReceiverHome_exec_i (void)
  {
  }

  DDSReceiverHome_exec_i::~DDSReceiverHome_exec_i (void)
  {
  }

  // Supported or inherited operations.

  // Home operations.

  // Factory and finder operations.

  // Attribute operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  DDSReceiverHome_exec_i::create ()
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      DDSReceiver_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" DDSRECEIVER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_DDSTest_DDSReceiverHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      DDSReceiverHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

