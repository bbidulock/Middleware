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

#include "Reader_Test_Sender_exec.h"

namespace CIAO_Reader_Test_Sender_Impl
{

  /**
   * Facet Executor Implementation Class: info_out_connector_status_exec_i
   */

  info_out_connector_status_exec_i::info_out_connector_status_exec_i (
        ::Reader_Test::CCM_Sender_Context_ptr ctx,
        Sender_exec_i &callback)
    : ciao_context_ (
        ::Reader_Test::CCM_Sender_Context::_duplicate (ctx))
      , callback_ (callback)
  {
  }

  info_out_connector_status_exec_i::~info_out_connector_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::ConnectorStatusListener

  void
  info_out_connector_status_exec_i::on_inconsistent_topic (::DDS::Topic_ptr /* the_topic */,
  const ::DDS::InconsistentTopicStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_requested_incompatible_qos (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedIncompatibleQosStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_sample_rejected (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleRejectedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_offered_deadline_missed (::DDS::DataWriter_ptr /* the_writer */,
  const ::DDS::OfferedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_offered_incompatible_qos (::DDS::DataWriter_ptr /* the_writer */,
  const ::DDS::OfferedIncompatibleQosStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_connector_status_exec_i::on_unexpected_status (::DDS::Entity_ptr /* the_entity */,
  ::DDS::StatusKind status_kind)
  {
    if (status_kind == ::DDS::PUBLICATION_MATCHED_STATUS)
        this->callback_.start ();
  }

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
    : keys_ (5)
      , iterations_ (10)
      , done_ (false)
      , ccm_activated_ (false)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported operations and attributes.
void
  Sender_exec_i::start (void)
  {
    ::Reader_Test::ReaderTestConnector::Writer_var writer =
      this->ciao_context_->get_connection_info_write_data ();
    ReaderStarter_var starter =
      this->ciao_context_->get_connection_start_reader ();

    //start can be called more than once...
    if (!this->done_ && this->ccm_activated_)
      {
        this->done_ = true;
        if (! ::CORBA::is_nil (starter.in ()))
          {
            starter->set_reader_properties (this->keys_, this->iterations_);
            starter->read_no_data ();
          }
        else
          {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: Unable to start the sender\n")));
            return;
          }
        for (CORBA::UShort iter_key = 1; iter_key < this->keys_ + 1; ++iter_key)
          {
            char key[7];
            ReaderTest *new_key = new ReaderTest;
            ACE_OS::sprintf (key, "KEY_%d", iter_key);
            new_key->key = CORBA::string_dup(key);
            for (CORBA::UShort iter = 1; iter < this->iterations_ + 1; ++iter)
              {
                new_key->iteration = iter;
                writer->write_one (*new_key, ::DDS::HANDLE_NIL);
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Written key <%C> with <%d>\n"),
                            key, iter));
              }
            delete new_key;
          }
        starter->start_read ();
      }
  }

  // Component attributes and port operations.

  ::CCM_DDS::CCM_ConnectorStatusListener_ptr
  Sender_exec_i::get_info_out_connector_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_connector_status_.in ()))
      {
        info_out_connector_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_connector_status_exec_i (
            this->ciao_context_.in (),
            *this),
            ::CCM_DDS::CCM_ConnectorStatusListener::_nil ());

          this->ciao_info_out_connector_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_ConnectorStatusListener::_duplicate (
        this->ciao_info_out_connector_status_.in ());
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

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Reader_Test::CCM_Sender_Context::_narrow (ctx);

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
    this->ccm_activated_ = true;
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Reader_Test_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
