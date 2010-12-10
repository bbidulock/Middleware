// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
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

#include "RG_LateBinding_Sender_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

namespace CIAO_RG_LateBinding_Sender_Impl
{

  /**
   * Timeout_Handler
   */

  Timeout_Handler::Timeout_Handler (Sender_exec_i &callback)
    : callback_ (callback)
  {
  }

  int
  Timeout_Handler::handle_timeout (const ACE_Time_Value &, const void *)
  {
    this->callback_.start_write ();
    return 0;
  }

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
    : iterations_ (0)
      , keys_ (0)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported operations and attributes.
  ACE_Reactor*
  Sender_exec_i::reactor (void)
  {
    ACE_Reactor* reactor = 0;
    ::CORBA::Object_var ccm_object =
      this->ciao_context_->get_CCM_object();
    if (! ::CORBA::is_nil (ccm_object.in ()))
      {
        ::CORBA::ORB_var orb = ccm_object->_get_orb ();
        if (! ::CORBA::is_nil (orb.in ()))
          {
            reactor = orb->orb_core ()->reactor ();
          }
      }
    if (reactor == 0)
      {
        throw ::CORBA::INTERNAL ();
      }
    return reactor;
  }

  void
  Sender_exec_i::start_write (void)
  {
    try
      {
        ::RG_LateBinding::RG_LateBindingTestConnector:: Writer_var writer =
          this->ciao_context_->get_connection_info_write_data ();
        for (::CORBA::UShort key = 1; key < this->keys_ + 1; ++key)
          {
            RG_LateBindingTest sample;
            char tmp[7];
            ACE_OS::sprintf (tmp, "KEY_%d", key);
            sample.key = CORBA::string_dup(tmp);

            for (::CORBA::UShort iter = 1; iter < this->iterations_ + 1; ++iter)
              {
                sample.iteration = iter;
                writer->write_one (sample, ::DDS::HANDLE_NIL);
                ACE_DEBUG ((LM_DEBUG, "Sender_exec_i::start_event_test - "
                            "Sample written : key <%C> - iteration <%d>\n",
                            tmp, iter));
              }
          }
        ACE_Time_Value tv (2, 0);
        ACE_OS::sleep (tv);
        ReaderStarter_var starter =
          this->ciao_context_->get_connection_reader_start ();
        if (!::CORBA::is_nil (starter.in ()))
          {
            ACE_DEBUG ((LM_DEBUG, "Sender_exec_i::start_event_test - "
                      "Inform the receiver that all samples were written\n"));
            starter->set_reader_properties (this->keys (), this->iterations ());
            starter->start_read ();
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::start_event_test - "
                      "ERROR: unable to get connection to the ReaderStarter\n"));
          }
      }
    catch (const ::CCM_DDS::NonChangeable &)
      {
        ACE_ERROR ((LM_ERROR, "Sender_exec_i::start_event_test - "
                              "ERROR: Caught NonChangeable exception.\n"));
      }
    catch (...)
      {
        ACE_ERROR ((LM_ERROR, "Sender_exec_i::start_event_test - "
                    "ERROR: Unexpected and unknown exception caught.\n"));
      }
  }


  // Component attributes and port operations.

  ::CORBA::UShort
  Sender_exec_i::iterations (void)
  {
    return this->iterations_;
  }

  void
  Sender_exec_i::iterations (
    const ::CORBA::UShort iterations)
  {
    this->iterations_ = iterations;
  }

  ::CORBA::UShort
  Sender_exec_i::keys (void)
  {
    return this->keys_;
  }

  void
  Sender_exec_i::keys (
    const ::CORBA::UShort keys)
  {
    this->keys_ = keys;
  }

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::RG_LateBinding::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_activate (void)
  {
     ACE_NEW_THROW_EX (this->to_handler_,
                       Timeout_Handler (*this),
                       ::CORBA::INTERNAL ());
     if (this->reactor ()->schedule_timer (
                 this->to_handler_,
                 0,
                 ACE_Time_Value (1, 0)) == -1)
       {
         ACE_ERROR ((LM_ERROR, ACE_TEXT ("Sender_exec_i::start : ")
                               ACE_TEXT ("Error scheduling timer")));
       }
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    delete this->to_handler_;
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_RG_LateBinding_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
