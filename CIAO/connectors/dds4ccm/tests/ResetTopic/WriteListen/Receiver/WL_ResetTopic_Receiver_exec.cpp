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

#include "WL_ResetTopic_Receiver_exec.h"
#include "dds4ccm/impl/logger/Log_Macros.h"

namespace CIAO_WL_ResetTopic_Receiver_Impl
{

  /**
   * Facet Executor Implementation Class: info_out_event_data_listener_exec_i
   */

  info_out_event_data_listener_exec_i::info_out_event_data_listener_exec_i (
        ::WL_ResetTopic::CCM_Receiver_Context_ptr ctx,
        Atomic_Boolean &samples_received)
    : ciao_context_ (
        ::WL_ResetTopic::CCM_Receiver_Context::_duplicate (ctx))
    , samples_received_(samples_received)
  {
  }

  info_out_event_data_listener_exec_i::~info_out_event_data_listener_exec_i (void)
  {
  }

  // Operations from ::WL_ResetTopic::WL_ResetTopicTestConnector::Listener

  void
  info_out_event_data_listener_exec_i::on_one_data (const ::WL_ResetTopicTest & datum,
  const ::CCM_DDS::ReadInfo & /* info */)
  {
    this->samples_received_ = true;
    ACE_DEBUG ((LM_ERROR, ACE_TEXT ("info_out_event_data_listener_exec_i::on_one_data - ")
            ACE_TEXT ("received data for <%C> at %u\n"),
            datum.key.in (),
            datum.iteration));
  }

  void
  info_out_event_data_listener_exec_i::on_many_data (const ::WL_ResetTopicTestSeq & /* data */,
  const ::CCM_DDS::ReadInfoSeq & /* infos */)
  {
    ACE_ERROR ((LM_ERROR, "info_out_event_data_listener_exec_i::on_many_data : "
                          "Error: No callback to this method expected.\n"));
  }

  /**
   * Facet Executor Implementation Class: info_out_event_status_exec_i
   */

  info_out_event_status_exec_i::info_out_event_status_exec_i (
        ::WL_ResetTopic::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::WL_ResetTopic::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_out_event_status_exec_i::~info_out_event_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_out_event_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_out_event_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & /* status */)
  {
    /* Your code here. */
  }



  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
    : iterations_ (0)
    , samples_received_(0)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.
  void
  Receiver_exec_i::set_new_topic (::CORBA::Object_ptr cmp,
                                  const char * topic_name)
  {
    if (::CORBA::is_nil (cmp))
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Receiver_exec_i::set_topic_name_writer - "
                              "Unable to get component interface\n"));
        throw ::CORBA::INTERNAL ();
      }
    ::WL_ResetTopic::WL_ResetTopicTestConnector::CCM_DDS_Event_var conn =
      ::WL_ResetTopic::WL_ResetTopicTestConnector::CCM_DDS_Event::_narrow (cmp);
    if (::CORBA::is_nil (conn.in ()))
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Receiver_exec_i::set_topic_name_writer - "
                              "Unable to narrow connector interface\n"));
        throw ::CORBA::INTERNAL ();
      }
    conn->topic_name (topic_name);

//     ::CCM_DDS::DataListenerControl_var dlc =
//       this->ciao_context_->get_connection_info_out_event_data_control ();
//     dlc->mode (::CCM_DDS::ONE_BY_ONE);
  }

  void
  Receiver_exec_i::set_new_topic (const char * topic_name)
  {

    if (this->samples_received_.value())
      ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::set_new_topic - "
                  "OK, samples received during last run\n"));
    else
      ACE_ERROR ((LM_ERROR, "Receiver_exec_i::set_new_topic - "
                  "ERROR: No samples received during last run\n"));

    this->samples_received_ = false;

    ::CORBA::Object_var cmp;
    try
      {
        ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::set_new_topic - "
                  "Setting topic to <%C>\n",
                  topic_name));
        //First listener
        ::WL_ResetTopic::WL_ResetTopicTestConnector::Reader_var reader =
          this->ciao_context_->get_connection_info_out_event_data();

        if (::CORBA::is_nil (reader.in ()))
          {
            ACE_ERROR ((LM_ERROR, "ERROR: Receiver_exec_i::set_new_topic - "
                                  "ciao_info_out_event_data_listener_ seems nil\n"));
            throw ::CORBA::INTERNAL ();
          }
        cmp = reader->_get_component ();
        this->set_new_topic (cmp.in (), topic_name);

        //next listener
        if (::CORBA::is_nil (this->ciao_info_out_event_status_.in ()))
          {
            ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::set_new_topic - "
                                  "ciao_info_out_event_status_ seems nil\n"));
          }
        else
          {
            cmp = this->ciao_info_out_event_status_->_get_component ();
            this->set_new_topic (cmp.in (), topic_name);
          }
      }
    catch (const ::CCM_DDS::NonChangeable &)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Receiver_exec_i::set_topic_name_writer - "
                    "Caught NonChangeable exception.\n"));
      }
  }

  // Component attributes and port operations.

  ::WL_ResetTopic::WL_ResetTopicTestConnector::CCM_Listener_ptr
  Receiver_exec_i::get_info_out_event_data_listener (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_event_data_listener_.in ()))
      {
        info_out_event_data_listener_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_event_data_listener_exec_i (
            this->ciao_context_.in (),
            this->samples_received_),
            ::WL_ResetTopic::WL_ResetTopicTestConnector::CCM_Listener::_nil ());

          this->ciao_info_out_event_data_listener_ = tmp;
      }

    return
      ::WL_ResetTopic::WL_ResetTopicTestConnector::CCM_Listener::_duplicate (
        this->ciao_info_out_event_data_listener_.in ());
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_out_event_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_event_status_.in ()))
      {
        info_out_event_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_event_status_exec_i (
            this->ciao_context_.in ()),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_out_event_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_out_event_status_.in ());
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

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::WL_ResetTopic::CCM_Receiver_Context::_narrow (ctx);

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
    ::CCM_DDS::DataListenerControl_var dlc =
      this->ciao_context_->get_connection_info_out_event_data_control ();
    dlc->mode (::CCM_DDS::ONE_BY_ONE);
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    if (this->samples_received_.value())
      ACE_DEBUG ((LM_DEBUG, "Receiver_exec_i::ccm_remove - "
                  "OK, samples received during last run\n"));
    else
      ACE_ERROR ((LM_ERROR, "Receiver_exec_i::ccm_remove - "
                  "ERROR: No samples received during last run\n"));
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_WL_ResetTopic_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
