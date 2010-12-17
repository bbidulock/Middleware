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

#include "MultiTopic_Receiver_exec.h"
#include "tao/ORB_Core.h"
#include "ace/OS_NS_time.h"
#include "ace/Reactor.h"

#define TIME_OUT_SEC 1

namespace CIAO_Shapes_Receiver_Impl
{

  //============================================================
  // read_action_Generator
  //============================================================
  read_action_Generator::read_action_Generator (Receiver_exec_i &callback)
    : pulse_callback_ (callback)
  {
  }

  read_action_Generator::~read_action_Generator ()
  {
  }

  int
  read_action_Generator::handle_timeout (const ACE_Time_Value &,
                                         const void *)
  {
    this->pulse_callback_.get_one ();
    return 0;
  }

  /**
   * Facet Executor Implementation Class: info_out_data_listener_exec_i
  */
  info_out_data_listener_exec_i::info_out_data_listener_exec_i (
        ::Shapes::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::Shapes::CCM_Receiver_Context::_duplicate (ctx))
  {
  }

  info_out_data_listener_exec_i::~info_out_data_listener_exec_i (void)
  {
  }

  // Operations from ::Shapes::Listener

  void
  info_out_data_listener_exec_i::on_one_data (const ::ShapeType & datum,
  const ::CCM_DDS::ReadInfo & /* info */)
  {
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("<CIRCLE Listener> : ")
            ACE_TEXT ("received CIRCLE for <%C> at %u:%u:%u\n"),
            datum.color.in (),
            datum.x,
            datum.y,
            datum.shapesize));
  }

  void
  info_out_data_listener_exec_i::on_many_data (const ::ShapeTypeSeq & /* data */,
  const ::CCM_DDS::ReadInfoSeq & /* infos */)
  {
    /* Your code here. */
  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void)
    : ticker_ (0),
      rate_ (0)
  {
    ACE_NEW_THROW_EX (this->ticker_,
                      read_action_Generator (*this),
                      ::CORBA::NO_MEMORY ());
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.

  void
  Receiver_exec_i::get_one (void)
  {
    ShapeType_var shape_info;
    ::CCM_DDS::ReadInfo_var readinfo;

    try
      {
        ::Shapes::DDS_Typed::Getter_var getter_sq =
          this-> ciao_context_->get_connection_info_get_sq_fresh_data ();
        if (!::CORBA::is_nil (getter_sq.in ()))
          {
            if (getter_sq->get_one (shape_info.out (), readinfo.out ()))
              {
                time_t tim = readinfo->source_timestamp.sec;
                tm * time = ACE_OS::localtime(&tim);
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("<GET_ONE - SQUARE> ReadInfo -> ")
                                      ACE_TEXT ("date = %02d:%02d:%02d.%d\n"),
                                      time->tm_hour,
                                      time->tm_min,
                                      time->tm_sec,
                                      readinfo->source_timestamp.nanosec));
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("<GET_ONE - SQUARE> : ")
                                      ACE_TEXT ("received shape_info for <%C> at %u:%u:%u\n"),
                                      shape_info->color.in (),
                                      shape_info->x,
                                      shape_info->y,
                                      shape_info->shapesize));
              }
            else
              {
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("<GET_ONE - SQUARE> No data available for <%C>\n"),
                         shape_info->color.in ()));
              }
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Receiver_exec_i::get_one - "
                      "ERROR: Getter for <SQUARE> seems to be nil\n"));
          }

        ::Shapes::DDS_Typed::Getter_var getter_tr =
          this-> ciao_context_->get_connection_info_get_tr_fresh_data ();
        if (!::CORBA::is_nil (getter_tr.in ()))
          {
            if (getter_tr->get_one (shape_info.out (), readinfo.out ()))
              {
                time_t tim = readinfo->source_timestamp.sec;
                tm * time = ACE_OS::localtime(&tim);
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("<GET_ONE - TRIANGLE> ReadInfo -> ")
                                      ACE_TEXT ("date = %02d:%02d:%02d.%d\n"),
                                      time->tm_hour,
                                      time->tm_min,
                                      time->tm_sec,
                                      readinfo->source_timestamp.nanosec));
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("<GET_ONE - TRIANGLE> : ")
                                      ACE_TEXT ("received shape_info for <%C> at %u:%u:%u\n"),
                                      shape_info->color.in (),
                                      shape_info->x,
                                      shape_info->y,
                                      shape_info->shapesize));
              }
            else
              {
                ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("<GET_ONE - TRIANGLE> : No data available for <%C>\n"),
                            shape_info->color.in ()));
              }
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Receiver_exec_i::get_one - "
                      "ERROR: Getter for TRIANGLE seems to be nil\n"));
          }
        //Circle is retrieved by the listener functionality
      }
    catch(const CCM_DDS::NonExistent& )
       {
         ACE_ERROR ((LM_ERROR, ACE_TEXT ("ShapeType_Read_One: no shape_info receieved\n")));
       }
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
  Receiver_exec_i::start (void)
  {
    // calculate the interval time
    long const usec = 1000000 / this->rate_;

    if (this->reactor ()->schedule_timer (
                this->ticker_,
                0,
                ACE_Time_Value (1, usec),
                ACE_Time_Value (2*TIME_OUT_SEC, usec)) == -1)
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Sender_exec_i::start : ")
                              ACE_TEXT ("Error scheduling timer")));
      }
  }

  void
  Receiver_exec_i::stop (void)
  {
    this->reactor ()->cancel_timer (this->ticker_);
    delete this->ticker_;
  }
  // Component attributes and port operations.

  ::Shapes::DDS_Typed::CCM_Listener_ptr
  Receiver_exec_i::get_info_out_sq_data_listener (void)
  {
    return ::Shapes::DDS_Typed::CCM_Listener::_nil ();
  }

  ::Shapes::DDS_Typed::CCM_Listener_ptr
  Receiver_exec_i::get_info_out_tr_data_listener (void)
  {
    return ::Shapes::DDS_Typed::CCM_Listener::_nil ();
  }

  ::Shapes::DDS_Typed::CCM_Listener_ptr
   Receiver_exec_i::get_info_out_cl_data_listener (void)
   {
     if ( ::CORBA::is_nil (this->ciao_info_out_cl_data_listener_.in ()))
       {
         info_out_data_listener_exec_i *tmp = 0;
         ACE_NEW_RETURN (
           tmp,
           info_out_data_listener_exec_i (
             this->ciao_context_.in ()),
             ::Shapes::DDS_Typed::CCM_Listener::_nil ());

           this->ciao_info_out_cl_data_listener_ = tmp;
       }

     return
       ::Shapes::DDS_Typed::CCM_Listener::_duplicate (
         this->ciao_info_out_cl_data_listener_.in ());
   }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_out_sq_status (void)
  {
    return ::CCM_DDS::CCM_PortStatusListener::_nil ();
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_out_tr_status (void)
  {
    return ::CCM_DDS::CCM_PortStatusListener::_nil ();
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_out_cl_status (void)
  {
    return ::CCM_DDS::CCM_PortStatusListener::_nil ();
  }


  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_get_sq_status (void)
  {
    return ::CCM_DDS::CCM_PortStatusListener::_nil ();
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_get_tr_status (void)
  {
    return ::CCM_DDS::CCM_PortStatusListener::_nil ();
  }

  ::CCM_DDS::CCM_PortStatusListener_ptr
  Receiver_exec_i::get_info_get_cl_status (void)
  {
    return ::CCM_DDS::CCM_PortStatusListener::_nil ();
  }

  ::CORBA::ULong
  Receiver_exec_i::rate (void)
  {
    return this->rate_;
  }

  void
  Receiver_exec_i::rate (
    const ::CORBA::ULong rate)
  {
    this->rate_ = rate;
  }

  // Operations from Components::SessionComponent.
  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Shapes::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Receiver_exec_i::configuration_complete (void)
  {
  }

  void
  Receiver_exec_i::ccm_activate (void)
  {
    ::CCM_DDS::DataListenerControl_var lc_cl =
    this->ciao_context_->get_connection_info_out_cl_data_control ();
    if (::CORBA::is_nil (lc_cl.in ()))
      {
        ACE_ERROR ((LM_INFO,
            ACE_TEXT ("Error:  Listener control receptacle cl is null!\n")));
        throw ::CORBA::INTERNAL ();
      }
    lc_cl->mode (::CCM_DDS::ONE_BY_ONE);

    ::DDS::Duration_t to;
    to.sec = TIME_OUT_SEC;
    to.nanosec = 0;

    ::Shapes::DDS_Typed::Getter_var getter_sq =
      this-> ciao_context_->get_connection_info_get_sq_fresh_data ();
    if (CORBA::is_nil (getter_sq.in ()))
      {
        ACE_ERROR ((LM_INFO,
            ACE_TEXT ("Error: Getter of SQUARE seems to be nil!\n")));
        throw ::CORBA::INTERNAL ();
      }
    getter_sq->time_out (to);

    ::Shapes::DDS_Typed::Getter_var getter_tr =
      this-> ciao_context_->get_connection_info_get_tr_fresh_data ();
    if (CORBA::is_nil (getter_tr.in ()))
      {
        ACE_ERROR ((LM_INFO,
            ACE_TEXT ("Error: Getter of TRIANGLE seems to be nil!\n")));
        throw ::CORBA::INTERNAL ();
      }
    getter_tr->time_out (to);
    this->start ();
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    this->stop();
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" RECEIVER_EXEC_Export  ::Components::EnterpriseComponent_ptr
  create_Shape_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
