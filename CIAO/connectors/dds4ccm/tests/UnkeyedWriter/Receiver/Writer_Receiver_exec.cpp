// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
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

#include "Writer_Receiver_exec.h"

namespace CIAO_Writer_Receiver_Impl
{

  /**
   * Facet Executor Implementation Class: info_out_data_listener_exec_i
   */

  info_out_data_listener_exec_i::info_out_data_listener_exec_i (
        ::Writer::CCM_Receiver_Context_ptr ctx,
        const ::CORBA::UShort iterations,
        Atomic_ULong &samples_received)
    : ciao_context_ (
        ::Writer::CCM_Receiver_Context::_duplicate (ctx))
      , iterations_ (iterations)
      , samples_received_ (samples_received)
  {
  }

  info_out_data_listener_exec_i::~info_out_data_listener_exec_i (void)
  {
  }

  // Operations from ::Writer::WriterTestConnector::Listener

  void
  info_out_data_listener_exec_i::on_one_data (const ::WriterTest & datum,
  const ::CCM_DDS::ReadInfo & /* info */)
  {
    ++this->samples_received_;
    ACE_DEBUG ((LM_ERROR, ACE_TEXT ("WriterTest_Listener::on_one_data ")
            ACE_TEXT ("received writer info for <%C> at %u\n"),
            datum.key.in (),
            datum.iteration));
    if (datum.iteration > this->iterations_)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: received iteration ")
                        ACE_TEXT ("greater than expected : ")
                        ACE_TEXT ("expected <%u> - received <%u>\n"),
                        this->iterations_, datum.iteration));
      }
    if (datum.iteration == 0)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: received iteration ")
                        ACE_TEXT ("is zero\n")));
      }
  }

  void
  info_out_data_listener_exec_i::on_many_data (const ::WriterTestSeq & /* data */,
  const ::CCM_DDS::ReadInfoSeq & /* infos */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: info_out_status_exec_i
   */

  info_out_status_exec_i::info_out_status_exec_i (
        ::Writer::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::Writer::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_out_status_exec_i::~info_out_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_out_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
    : iterations_ (10)
      , keys_ (5)
      , samples_received_ (0)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::Writer::WriterTestConnector::CCM_Listener_ptr
  Receiver_exec_i::get_info_out_data_listener (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_data_listener_.in ()))
      {
        info_out_data_listener_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_data_listener_exec_i (
            this->ciao_context_.in (),
            this->iterations () * this->keys (),
            this->samples_received_),
            ::Writer::WriterTestConnector::CCM_Listener::_nil ());

          this->ciao_info_out_data_listener_ = tmp;
      }

    return
      ::Writer::WriterTestConnector::CCM_Listener::_duplicate (
        this->ciao_info_out_data_listener_.in ());
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_out_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_status_.in ()))
      {
        info_out_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_out_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_out_status_.in ());
  }

  ::CORBA::UShort
  Receiver_exec_i::iterations (void)
  {
    return this->iterations_;
  }

  void
  Receiver_exec_i::iterations (
    const ::CORBA::UShort iterations)
  {
    this->iterations_ = iterations;
  }

  ::CORBA::UShort
  Receiver_exec_i::keys (void)
  {
    return this->keys_;
  }

  void
  Receiver_exec_i::keys (
    const ::CORBA::UShort keys)
  {
    this->keys_ = keys;
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Writer::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    ::CCM_DDS::DataListenerControl_var lc =
    this->ciao_context_->get_connection_info_out_data_control ();

    if (::CORBA::is_nil (lc.in ()))
      {
        ACE_ERROR ((LM_INFO, ACE_TEXT ("Error:  Listener control receptacle is null!\n")));
        throw ::CORBA::INTERNAL ();
      }
    lc->mode (::CCM_DDS::ONE_BY_ONE);
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    if (this->samples_received_ != 2 * this->keys_ * this->iterations_)
      {
        ACE_ERROR ((LM_ERROR, "Receiver_exec_i::ccm_remove - "
                  "ERROR: Did not receive the expected number of samples: "
                  "expected <%u> - received <%u>\n",
                  2 * this->keys_ * this->iterations_,
                  this->samples_received_.value ()));
      }
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Writer_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
