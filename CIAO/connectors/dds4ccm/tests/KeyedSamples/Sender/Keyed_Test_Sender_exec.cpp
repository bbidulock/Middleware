// -*- C++ -*-
// $Id$

#include "Keyed_Test_Sender_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

namespace CIAO_Keyed_Test_Sender_Impl
{

  /**
   * ConnectorStatusListener_exec_i
   */
  ConnectorStatusListener_exec_i::ConnectorStatusListener_exec_i (
    Sender_exec_i &callback)
    : callback_ (callback)
  {
  }

  ConnectorStatusListener_exec_i::~ConnectorStatusListener_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::ConnectorStatusListener
  void ConnectorStatusListener_exec_i::on_inconsistent_topic (
    ::DDS::Topic_ptr /*the_topic*/,
    const DDS::InconsistentTopicStatus & /*status*/)
  {
  }

  void ConnectorStatusListener_exec_i::on_requested_incompatible_qos (
    ::DDS::DataReader_ptr /*the_reader*/,
    const DDS::RequestedIncompatibleQosStatus & /*status*/)
  {
  }

  void ConnectorStatusListener_exec_i::on_sample_rejected (
    ::DDS::DataReader_ptr /*the_reader*/,
    const DDS::SampleRejectedStatus & /*status*/)
  {
  }

  void ConnectorStatusListener_exec_i::on_offered_deadline_missed(
    ::DDS::DataWriter_ptr /*the_writer*/,
    const DDS::OfferedDeadlineMissedStatus & /*status*/)
  {
  }

  void ConnectorStatusListener_exec_i::on_offered_incompatible_qos(
    ::DDS::DataWriter_ptr /*the_writer*/,
    const DDS::OfferedIncompatibleQosStatus & /*status*/)
  {
  }

  void ConnectorStatusListener_exec_i::on_unexpected_status(
    ::DDS::Entity_ptr /*the_entity*/,
    ::DDS::StatusKind status_kind)
  {
    if (status_kind == ::DDS::PUBLICATION_MATCHED_STATUS)
      {
        ACE_DEBUG ((LM_DEBUG, "ConnectorStatusListener_exec_i::on_unexpected_status - "
          "Publication matched received: starting the test\n"));

        this->callback_.get_started ();
      }
  }

  /**
   * Write action generator
   */

  pulse_Generator::pulse_Generator (Sender_exec_i &callback)
    : pulse_callback_ (callback)
  {
  }

  int
  pulse_Generator::handle_timeout (const ACE_Time_Value &, const void *)
  {
    this->pulse_callback_.tick ();
    return 0;
  }

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
    : rate_ (1)
      , keys_ (5)
      , iterations_ (10)
      , ready_to_start_ (false)
  {
    ACE_NEW_THROW_EX (this->ticker_,
                      pulse_Generator (*this),
                      ::CORBA::NO_MEMORY ());
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
    delete this->ticker_;
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
  Sender_exec_i::tick (void)
  {
    if (this->last_key_ != this->ktests_.end ())
      {
        try
          {
            KeyedTestConnector::Writer_var writer =
              this->ciao_context_->get_connection_info_write_data ();
            ++this->last_key_->second->iteration;
            writer->write_one (this->last_key_->second, ::DDS::HANDLE_NIL);
            ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Written key <%C> with <%d>\n"),
                    this->last_key_->first.c_str (),
                    this->last_key_->second->iteration));
          }
        catch (const CCM_DDS::InternalError& )
          {
            ACE_ERROR ((LM_ERROR, "ERROR: Internal Error while writing KeyedTest info for <%C>.\n",
                        this->last_key_->first.c_str ()));
          }
        ++this->last_key_;
      }
    else
      {
        // Onto the next iteration
        this->last_key_ = this->ktests_.begin ();
        while (this->last_key_ != this->ktests_.end ())
          {
            if (this->last_key_->second->iteration == this->iterations_)
              {
                ++this->last_key_;
              }
            else
              {
                break;
              }
          }
      }
  }

  void
  Sender_exec_i::start (void)
  {
    long const usec = 1000000 / this->rate_;
    if (this->reactor ()->schedule_timer (
                this->ticker_,
                0,
                ACE_Time_Value (0, usec),
                ACE_Time_Value (0, usec)) == -1)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Sender_exec_i::start : ")
                              ACE_TEXT ("Error scheduling timer")));
      }
  }

  void
  Sender_exec_i::get_started (void)
  {
    this->ready_to_start_ = true;
    this->start ();

    ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->mutex_, CORBA::INTERNAL ());

    for (CORBA::UShort i = 1; i < this->keys_ + 1; ++i)
      {
        char key[7];
        KeyedTest *new_key = new KeyedTest;
        ACE_OS::sprintf (key, "KEY_%d", i);
        new_key->key = CORBA::string_dup(key);
        new_key->iteration = 0;

        this->ktests_[key] = new_key;
      }
     this->last_key_ = this->ktests_.begin ();
}

  void
  Sender_exec_i::stop (void)
  {
    this->reactor ()->cancel_timer (this->ticker_);

    if (!this->ready_to_start_.value())
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Sender_exec_i::stop - ")
                              ACE_TEXT ("ERROR Sender never got ready to start\n")));
      }
  }

  // Component attributes and port operations.
  ::CCM_DDS::CCM_ConnectorStatusListener_ptr
  Sender_exec_i::get_connector_status (void)
  {
    return new ConnectorStatusListener_exec_i  (*this);
  }

  ::CORBA::ULong
  Sender_exec_i::rate (void)
  {
    return this->rate_;
  }

  void
  Sender_exec_i::rate (
    const ::CORBA::ULong rate)
  {
    this->rate_ = rate;
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
      ::Keyed_Test::CCM_Sender_Context::_narrow (ctx);

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
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    this->stop ();
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Keyed_Test_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
