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

#include "Receiver_exec_i.h"
#include "ciao/CIAO_common.h"

namespace CIDL_Receiver_Impl
{
  //==================================================================
  // Component Executor Implementation Class:   Receiver_exec_i
  //==================================================================

  Receiver_exec_i::Receiver_exec_i (void)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported or inherited operations.

  // Attribute operations.

  // Port operations.

  void
  Receiver_exec_i::push_message_consumer (
  ::Message * ev)
  ACE_THROW_SPEC ((CORBA::SystemException))
  {
    // Your code here.

    // MY CODE

    CORBA::String_var subject = ev->subject();
    CORBA::String_var user = ev->user();
    CORBA::String_var text = ev->text();

    ACE_DEBUG((LM_INFO,
               ACE_TEXT("Received Message:\n   Subject: %s\n   User: %s\n   Text: %s\n"),
               subject.in(),
               user.in(),
               text.in() ));

    // Use the history to (inefficiently) get the total number of messages
    // published on this item so far
    ::History_var history =
      this->context_->get_connection_message_history();
    ::Messages_var messages = history->get_all();
    ACE_DEBUG((LM_INFO,
               ACE_TEXT("   Subject \"%s\" has published %d messages so far\n"),
               subject.in(),
               messages->length() ));
  }

  // Operations from Components::SessionComponent

  void
  Receiver_exec_i::set_session_context (
  ::Components::SessionContext_ptr ctx)
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CCMException))
  {
    this->context_ =
    Receiver_Context::_narrow (
    ctx);

    if (this->context_ == 0)
    {
      throw CORBA::INTERNAL ();
    }
  }

  void
  Receiver_exec_i::ccm_activate ()
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CCMException))
  {
    // Your code here.
    ACE_DEBUG((LM_INFO, ACE_TEXT("Receiver_exec_i::ccm_activate\n")));
  }

  void
  Receiver_exec_i::ccm_passivate ()
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CCMException))
  {
    // Your code here.
    ACE_DEBUG((LM_INFO, ACE_TEXT("Receiver_exec_i::ccm_passivate\n")));
  }

  void
  Receiver_exec_i::ccm_remove ()
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CCMException))
  {
    // Your code here.
    ACE_DEBUG((LM_INFO, ACE_TEXT("Receiver_exec_i::ccm_remove\n")));
  }

  void
  Receiver_exec_i::ciao_preactivate ()
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CCMException))
  {
    // Your code here.
    ACE_DEBUG((LM_INFO, ACE_TEXT("Receiver_exec_i::ciao_preactivate\n")));
  }

  void
  Receiver_exec_i::ciao_postactivate ()
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CCMException))
  {
    // Your code here.
    ACE_DEBUG((LM_INFO, ACE_TEXT("Receiver_exec_i::ciao_postactivate\n")));
  }

  //==================================================================
  // Home Executor Implementation Class:   ReceiverHome_exec_i
  //==================================================================

  ReceiverHome_exec_i::ReceiverHome_exec_i (void)
  {
  }

  ReceiverHome_exec_i::~ReceiverHome_exec_i (void)
  {
  }

  // Supported or inherited operations.

  // Home operations.

  // Factory and finder operations.

  // Attribute operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  ReceiverHome_exec_i::create ()
  ACE_THROW_SPEC ((
  ::CORBA::SystemException,
  ::Components::CCMException))
  {
    ::Components::EnterpriseComponent_ptr retval =
    ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
    retval,
    Receiver_exec_i,
    CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" RECEIVER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_ReceiverHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
    ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
    retval,
    ReceiverHome_exec_i,
    ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

