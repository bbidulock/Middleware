// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.2
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

#include "Receiver_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_Hello_Receiver_Impl
{

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
    : iterations_ (10)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  void
  Receiver_exec_i::push_click_in (
    ::Hello::TimeOut * ev)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG,
          ACE_TEXT ("Receiver - Informed by the Sender with message [%C]\n"),
          ev->data ()));
    Hello::ReadMessage_var rev = this->ciao_context_->get_connection_read_message ();
    if (CORBA::is_nil (rev.in ()))
      throw CORBA::BAD_INV_ORDER ();
    for (CORBA::Short i = 0; i < this->iterations_; ++i)
      {
        CORBA::String_var str = rev->get_message ();
        ACE_DEBUG ((LM_DEBUG,
                  "Receiver - Got message from the sender [%C].\n",
                  str.in ()));
        ACE_Time_Value tv (1, 0);
        ACE_OS::sleep (tv);
      }
  }

  ::CORBA::Short
  Receiver_exec_i::iterations (void)
  {
    return this->iterations_;
  }

  void
  Receiver_exec_i::iterations (
    const ::CORBA::Short iterations)
  {
    this->iterations_ = iterations;
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Hello::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG,
                "Receiver_exec_i::configuration_complete\n"));
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_activate\n"));
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_passivate\n"));
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_remove\n"));
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
