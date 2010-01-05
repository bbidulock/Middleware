// $Id$

#include "Sender_exec.h"

namespace CIAO_Minimum_Sender_Impl
{
  //==================================================================
  // Component Executor Implementation Class:   Sender_exec_i
  //==================================================================

  Sender_exec_i::Sender_exec_i (void)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported or inherited operations.

  void
  Sender_exec_i::bar ()
  {
    // Your code here.
  }

  // Attribute operations.

  // Port operations.

  // Operations from Components::SessionComponent

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Minimum::CCM_Sender_Context::_narrow (ctx);

    if (CORBA::is_nil (this->context_.in ()))
    {
      throw ::CORBA::INTERNAL ();
    }
  }

  void
  Sender_exec_i::configuration_complete ()
  {
    // Your code here.
  }

  void
  Sender_exec_i::ccm_activate ()
  {
    // Your code here.
  }

  void
  Sender_exec_i::ccm_passivate ()
  {
    // Your code here.
  }

  void
  Sender_exec_i::ccm_remove ()
  {
    // Your code here.
  }

  //==================================================================
  // Home Executor Implementation Class:   SenderHome_exec_i
  //==================================================================

  SenderHome_exec_i::SenderHome_exec_i (void)
  {
  }

  SenderHome_exec_i::~SenderHome_exec_i (void)
  {
  }

  // Supported or inherited operations.

  // Home operations.

  // Factory and finder operations.

  // Attribute operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  SenderHome_exec_i::create ()
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      Sender_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" SENDER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Minimum_SenderHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      SenderHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

