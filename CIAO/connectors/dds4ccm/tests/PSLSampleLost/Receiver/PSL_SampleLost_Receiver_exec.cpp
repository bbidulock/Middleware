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

#include "PSL_SampleLost_Receiver_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"
#include "dds4ccm/impl/TimeUtilities.h"

#include "dds4ccm/impl/dds4ccm_conf.h"

namespace CIAO_PSL_SampleLost_Receiver_Impl
{
  /**
   * Read action generator
   */

  read_action_Generator::read_action_Generator (Receiver_exec_i &callback)
    : pulse_callback_ (callback)
  {
  }

  read_action_Generator::~read_action_Generator ()
  {
  }

  int
  read_action_Generator::handle_timeout (const ACE_Time_Value &, const void *)
  {
    this->pulse_callback_.read_all();
    return 0;
  }


  /**
   * Facet Executor Implementation Class: info_get_status_exec_i
   */

  info_get_status_exec_i::info_get_status_exec_i (
        ::PSL_SampleLost::CCM_Receiver_Context_ptr ctx,
        Atomic_Boolean &sample_port_get,
        ACE_Thread_ID &thread_id_listener_get)
    : ciao_context_ (
        ::PSL_SampleLost::CCM_Receiver_Context::_duplicate (ctx))
      , sample_port_get_ (sample_port_get)
      , thread_id_listener_get_ (thread_id_listener_get)
  {
  }

  info_get_status_exec_i::~info_get_status_exec_i (void)
  {
  }

  // Operations from ::CCM_DDS::PortStatusListener

  void
  info_get_status_exec_i::on_requested_deadline_missed (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::RequestedDeadlineMissedStatus & /* status */)
  {
    /* Your code here. */
  }

  void
  info_get_status_exec_i::on_sample_lost (::DDS::DataReader_ptr /* the_reader */,
  const ::DDS::SampleLostStatus & status)
  {
    ACE_Thread_ID t_id;
    this->thread_id_listener_get_ = t_id;

    if (status.total_count > 0)
      {
        this->sample_port_get_ = true;
      }
  }

  /**
   * Facet Executor Implementation Class: info_out_data_listener_exec_i
   */

  info_out_data_listener_exec_i::info_out_data_listener_exec_i (
        ::PSL_SampleLost::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::PSL_SampleLost::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_out_data_listener_exec_i::~info_out_data_listener_exec_i (void)
  {
  }

  // Operations from ::PSL_SampleLost::PSL_SampleLostConnector::Listener

  void
  info_out_data_listener_exec_i::on_one_data (const ::TestTopic & datum,
  const ::CCM_DDS::ReadInfo & /* info */)
  {
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("TestTopic_RawListener: ")
            ACE_TEXT ("ERROR: received test_topic_info for <%C> at %u\n"),
            datum.key.in (),
            datum.x));
  }

  void
  info_out_data_listener_exec_i::on_many_data (const ::TestTopicSeq & /* data */,
  const ::CCM_DDS::ReadInfoSeq & /* infos */)
  {
    /* Your code here. */
  }

  /**
   * Facet Executor Implementation Class: info_out_status_exec_i
   */

  info_out_status_exec_i::info_out_status_exec_i (
        ::PSL_SampleLost::CCM_Receiver_Context_ptr ctx,
        Atomic_Boolean &sample_port_listener,
        ACE_Thread_ID &thread_id_listener_listener)
    : ciao_context_ (
        ::PSL_SampleLost::CCM_Receiver_Context::_duplicate (ctx))
      , sample_port_listener_ (sample_port_listener)
      , thread_id_listener_listener_ (thread_id_listener_listener)
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
  const ::DDS::SampleLostStatus & status)
  {
    ACE_Thread_ID t_id;
    this->thread_id_listener_listener_ = t_id;

    if (status.total_count > 0)
      {
        this->sample_port_listener_ = true;
      }
  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
    : sample_port_get_ (false)
      , sample_port_listener_ (false)
      , thread_id_listener_get_ (0, 0)
      , thread_id_listener_listener_ (0, 0)
  {
    ACE_NEW_THROW_EX (this->ticker_,
                      read_action_Generator (*this),
                      ::CORBA::NO_MEMORY ());
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
    delete this->ticker_;
  }

  // Supported operations and attributes.
  ACE_Reactor*
  Receiver_exec_i::reactor (void)
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
  Receiver_exec_i::read_all (void)
  {
    ::PSL_SampleLost::PSL_SampleLostConnector::Reader_var reader =
      this->ciao_context_->get_connection_info_out_data ();

    if (!::CORBA::is_nil (reader.in ()))
      {
        TestTopicSeq TestTopic_infos;
        ::CCM_DDS::ReadInfoSeq readinfoseq;
        try
          {
            reader->read_all(TestTopic_infos, readinfoseq);
            for(CORBA::ULong i = 0; i < readinfoseq.length(); ++i)
              {
                ACE_Time_Value tv;
                tv <<= readinfoseq[i].source_timestamp;
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("READ_ALL ReadInfo ")
                                      ACE_TEXT ("-> UTC date =%#T\n"),
                                      &tv));
              }
            for(CORBA::ULong i = 0; i < TestTopic_infos.length(); ++i)
              {
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("READ_ALL keyed test info : ")
                      ACE_TEXT ("Number <%d> : received TestTopic_info for <%C> at %u\n"),
                    i,
                    TestTopic_infos[i].key.in (),
                    TestTopic_infos[i].x));
              }
          }
        catch (const CCM_DDS::InternalError& )
          {
            ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("internal error or no data\n")));
          }
      }
  }

  // Component attributes and port operations.

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_get_status (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_get_status_.in ()))
      {
        info_get_status_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_get_status_exec_i (
            this->ciao_context_.in (),
            this->sample_port_get_,
            this->thread_id_listener_get_),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_get_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_get_status_.in ());
  }

  ::PSL_SampleLost::PSL_SampleLostConnector::CCM_Listener_ptr
  Receiver_exec_i::get_info_out_data_listener (void)
  {
    if ( ::CORBA::is_nil (this->ciao_info_out_data_listener_.in ()))
      {
        info_out_data_listener_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          info_out_data_listener_exec_i (
            this->ciao_context_.in ()),
            ::PSL_SampleLost::PSL_SampleLostConnector::CCM_Listener::_nil ());

          this->ciao_info_out_data_listener_ = tmp;
      }

    return
      ::PSL_SampleLost::PSL_SampleLostConnector::CCM_Listener::_duplicate (
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
            this->ciao_context_.in (),
            this->sample_port_listener_,
            this->thread_id_listener_listener_),
            ::CCM_DDS::CCM_PortStatusListener::_nil ());

          this->ciao_info_out_status_ = tmp;
      }

    return
      ::CCM_DDS::CCM_PortStatusListener::_duplicate (
        this->ciao_info_out_status_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::PSL_SampleLost::CCM_Receiver_Context::_narrow (ctx);

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
    lc->mode (::CCM_DDS::NOT_ENABLED);

    // calculate the interval time
    long const usec = 100000;
    if (this->reactor ()->schedule_timer (this->ticker_,
                                          0,
                                          ACE_Time_Value(3, usec),
                                          ACE_Time_Value(3, usec)) == -1)
      {
        ACE_ERROR ((LM_ERROR, "Unable to schedule Timer\n"));
      }
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    this->reactor ()->cancel_timer (this->ticker_);
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
     if(!this->sample_port_get_.value ())
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: did not receive the expected ")
                         ACE_TEXT ("error 'on_sample_lost' on DDS_Listen port in Receiver\n")
              ));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("OK : Have received the expected ")
                               ACE_TEXT ("'on_sample_lost' in on DDS_Listen port Receiver\n")
                    ));
      }
    if (!this->sample_port_listener_.value ())
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: did not receive the expected ")
                         ACE_TEXT ("error 'on_sample_lost' on DDS_Get port in Receiver\n")
              ));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("OK : Have received the expected ")
                               ACE_TEXT ("'on_sample_lost' in on DDS_GET port Receiver\n")
                    ));
      }
             //get current thread
    char ccm_buf [65];
    ACE_Thread_ID ccm_thread_id;
    ccm_thread_id.to_string (ccm_buf);

    char list_buf_1 [65];
    this->thread_id_listener_get_.to_string (list_buf_1);

    //check thread switch for listener 1
    if (this->thread_id_listener_get_.id () == 0)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: "
                              "Thread ID for PortStatusListener Get not set!\n"));
      }
    #if (CIAO_DDS4CCM_CONTEXT_SWITCH == 1)
    else if (this->thread_id_listener_get_ == ccm_thread_id)
      {
        ACE_DEBUG ((LM_DEBUG, "OK : "
                              "Thread switch for PortStatusListener Get seems OK. "
                              "(DDS uses the CCM thread for its callback) "
                               "listener <%C> - component <%C>\n",
                              list_buf_1,
                              ccm_buf));
     }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR: "
                              "Thread switch for PortStatusListener Get "
                              "doesn't seem to work! "
                              "listener <%C> - component <%C>\n",
                              list_buf_1,
                              ccm_buf));
      }
    #else
    else if (this->thread_id_listener_get_ == ccm_thread_id)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: PortStatusListener Get: "
                              "DDS seems to use a CCM thread for its callback: "
                              "listener <%C> - component <%C>\n",
                              list_buf_1,
                              ccm_buf));
     }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "OK : PortStatusListener Get: "
                              "DDS seems to use its own thread for its callback: "
                              "listener <%C> - component <%C>\n",
                              list_buf_1,
                              ccm_buf));
      }
    #endif

    //check thread switch for listener 2
    char list_buf_2 [65];
   this->thread_id_listener_listener_.to_string (list_buf_2);
   if (this->thread_id_listener_listener_.id () == 0)
     {
        ACE_ERROR ((LM_ERROR, "ERROR: "
                              "Thread ID for PortStatusListener Listener not set!\n"));
      }
    #if (CIAO_DDS4CCM_CONTEXT_SWITCH == 1)
    else if (this->thread_id_listener_listener_ == ccm_thread_id)
      {
        ACE_DEBUG ((LM_DEBUG, "OK : "
                              "Thread switch for PortStatusListener Listener seems OK. "
                              "(DDS uses the CCM thread for its callback) "
                              "listener <%C> - component <%C>\n",
                              list_buf_2,
                              ccm_buf));
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR: "
                              "Thread switch for PortStatusListener Listener "
                              "doesn't seem to work! "
                              "listener <%C> - component <%C>\n",
                              list_buf_2,
                              ccm_buf));
      }
    #else
    else if (this->thread_id_listener_listener_ == ccm_thread_id)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: PortStatusListener Listener: "
                              "DDS seems to use a CCM thread for its callback: "
                              "listener <%C> - component <%C>\n",
                              list_buf_2,
                              ccm_buf));
      }
    else
      {
        ACE_DEBUG ((LM_DEBUG, "OK : PortStatusListener Listener: "
                              "DDS seems to use its own thread for its callback: "
                              "listener <%C> - component <%C>\n",
                              list_buf_2,
                              ccm_buf));
      }
    #endif
  }

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_PSL_SampleLost_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
