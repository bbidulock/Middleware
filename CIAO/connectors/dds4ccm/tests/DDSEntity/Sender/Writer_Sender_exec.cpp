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

#include "Writer_Sender_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

#include "Base/Writer_BaseSupport.h"
#include "Connector/Writer_Connector_conn.h"

namespace CIAO_Writer_Sender_Impl
{
  /**
   * Pulse Generator
   */

  pulse_Generator::pulse_Generator (Sender_exec_i &callback)
    : pulse_callback_ (callback)
  {
  }

  int
  pulse_Generator::handle_timeout (const ACE_Time_Value &, const void *)
  {
    // Notify the subscribers
    this->pulse_callback_.tick ();
    return 0;
  }

  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
    : rate_ (0)
      , iterations_ (0)
      , keys_ (0)
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
  Sender_exec_i::unregister_handles ()
  {
    for (Writer_Table::iterator i = this->ktests_.begin ();
         i != this->ktests_.end ();
         ++i)
      {
        try
          {
            DDS_InstanceHandle_t hnd = this->handles_[i->first.c_str ()];
            this->writer_->unregister_instance (i->second, hnd);
            ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Unregistered <%C> - iteration <%d> - valid handle <%d>\n"),
                      i->first.c_str (),
                      i->second->iteration,
                      hnd));
          }
        catch (...)
          {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: ")
                    ACE_TEXT ("unknown exception caught during unregister_instance.\n")));
          }
      }
  }

  void
  Sender_exec_i::register_handles()
  {
    Writer_Table::iterator i = this->ktests_.begin ();
    for (i = this->ktests_.begin(); i != this->ktests_.end(); ++i)
      {
        DDS_InstanceHandle_t const hnd = this->writer_->register_instance (i->second);
        if (DDS_INSTANCE_HANDLE_INVALID(hnd))
          {
            ACE_ERROR ((LM_ERROR, ACE_TEXT ("ERROR: Unable to register handle for <%C> - iteration <%d>\n"),
              i->first.c_str (), i->second->iteration));
          }
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Registering instance for <%C>\n"),
                    i->second->key.in ()));
        this->handles_[i->first.c_str ()] = hnd;
     }
  }

  void
  Sender_exec_i::write_keyed ()
  {
    if (this->last_key != this->ktests_.end ())
      {
        ++this->last_key->second->iteration;
        DDS_InstanceHandle_t hnd = this->handles_[this->last_key->first.c_str ()];
        DDS_ReturnCode_t const retval = this->writer_->write (this->last_key->second, hnd);
        if (retval == DDS_RETCODE_OK)
          {
            ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Written keyed <%C> - iteration <%d> - valid handle <%d>\n"),
                    this->last_key->first.c_str (),
                    this->last_key->second->iteration,
                    hnd.isValid));
          }
        else ACE_ERROR ((LM_ERROR, ACE_TEXT ("Error writing key <%C> - retcode %C\n"),
                    CIAO::DDS4CCM::translate_retcode (retval)));

        ++this->last_key;
      }
    else
      {
        //onto the next iteration
        this->last_key = this->ktests_.begin ();
        while (this->last_key != this->ktests_.end ())
          {
            if (this->last_key->second->iteration == this->iterations_)
              {
                // Next key
                ++this->last_key;
              }
            else
              {
                break;
              }
          }
        if (this->last_key == this->ktests_.end ())
          {
            unregister_handles ();
            this->stop ();
          }
      }
  }

  void
  Sender_exec_i::tick ()
  {
    write_keyed ();
  }

  void
  Sender_exec_i::start (void)
  {
    long usec = 1000000 / this->rate_;
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
  Sender_exec_i::stop (void)
  {
    if (this->ticker_)
      {
        this->reactor ()->cancel_timer (this->ticker_);
        ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Sender_exec_i::stop : Timer canceled.\n")));
        delete this->ticker_;
        this->ticker_ = 0;
      }
  }

  // Component attributes and port operations.

  ::CORBA::UShort
  Sender_exec_i::rate (void)
  {
    return this->rate_;
  }

  void
  Sender_exec_i::rate (
    const ::CORBA::UShort rate)
  {
    this->rate_ = rate;
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
      ::Writer::CCM_Sender_Context::_narrow (ctx);

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
    ::DDS::DataWriter_var dds_dw =
      this->ciao_context_->get_connection_info_write_dds_entity ();

    if (::CORBA::is_nil (dds_dw.in ()))
      {
        ACE_ERROR ((LM_ERROR, "ERROR : Sender_exec_i::ccm_activate - "
                    "Datawriter connection is NIL.\n"));
        throw ::CORBA::INTERNAL ();
      }

    ::CIAO::DDS4CCM::CCM_DataWriter * ccm_dw =
      dynamic_cast < ::CIAO::DDS4CCM::CCM_DataWriter * > (dds_dw.in ());

    if (ccm_dw)
      {
        ::DDS::DataWriter_var tmp = ccm_dw->get_dds_entity ();
        if (! ::CORBA::is_nil (tmp.in ()))
          {
            typedef ::CIAO::NDDS::DDS_DataWriter_Base DataWriter_type;
            DataWriter_type * typed_ccm_dw = dynamic_cast <DataWriter_type *> (tmp.in ());
            if (typed_ccm_dw)
              {
                DDSDataWriter* dds_datawriter = typed_ccm_dw->get_rti_entity ();
                if (dds_datawriter)
                  {
                    this->writer_ =
                      ::CIAO_WriterTestConnector_DDS_Event_Impl::WriterTest_DDS_Traits::datawriter_type::narrow (dds_datawriter);
                    if (!this->writer_)
                      {
                        ACE_ERROR ((LM_ERROR, "ERROR : Sender_exec_i::ccm_activate - "
                                    "Error narrowing to a typed "
                                    "DDS DataWriter.\n"));
                        throw ::CORBA::INTERNAL ();
                      }
                  }
                else
                  {
                    ACE_ERROR ((LM_ERROR, "ERROR : Sender_exec_i::ccm_activate - "
                                "Error getting DDS DataWriter.\n"));
                    throw ::CORBA::INTERNAL ();
                  }
              }
            else
              {
                ACE_ERROR ((LM_ERROR, "ERROR : Sender_exec_i::ccm_activate - "
                            "Error casting DataWriter to typed DataWriter\n"));
                throw ::CORBA::INTERNAL ();
              }
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "ERROR : Sender_exec_i::ccm_activate - "
                    "::DDS::DataWriter of CCM DataWriter seems nil\n"));
            throw ::CORBA::INTERNAL ();
          }
      }
    else
      {
        ACE_ERROR ((LM_ERROR, "ERROR : Sender_exec_i::ccm_activate - "
                    "Error casting DataWriter to CCM_DataWriter\n"));
        throw ::CORBA::INTERNAL ();
      }

    this->start ();

    ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->mutex_, CORBA::INTERNAL ());

    for (CORBA::UShort i = 1; i < this->keys_ + 1; ++i)
      {
        char key[7];
        WriterTest *new_key = new WriterTest;
        ACE_OS::sprintf (key, "KEY_%d", i);
        new_key->key = CORBA::string_dup(key);
        new_key->iteration = 0;

        this->ktests_[key] = new_key;
      }
    this->last_key = this->ktests_.begin ();
    register_handles ();
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
  create_Writer_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
