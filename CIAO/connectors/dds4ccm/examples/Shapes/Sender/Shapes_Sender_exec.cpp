// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.0
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

#include "Shapes_Sender_exec.h"
#include "tao/ORB_Core.h"
#include "ace/Reactor.h"

namespace CIAO_Shapes_Sender_Impl
{

  /**
   * Write action generator
   */

  pulse_Generator::pulse_Generator (Sender_exec_i &callback)
    : pulse_callback_ (callback)
  {
  }

  pulse_Generator::~pulse_Generator ()
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
      , max_x_ (100)
      , max_y_ (100)
      , max_size_ (25)
      , resize_shape_ (false)
      , color_ ("CYAN")
      , x_increasing_ (false)
      , y_increasing_ (false)
      , size_increasing_ (false)
  {
    ACE_NEW_THROW_EX (this->ticker_,
                      pulse_Generator (*this),
                      ::CORBA::NO_MEMORY ());
    ACE_NEW_THROW_EX (this->square_,
                      ShapeType,
                      ::CORBA::NO_MEMORY ());
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
    delete this->ticker_;
    delete this->square_;
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
  Sender_exec_i::tick ()
  {
    if (this->x_increasing_)
      {
        ++this->square_->x;
        this->x_increasing_ = this->square_->x + 1 <= this->max_x_;
      }
    else
      {
        --this->square_->x;
        this->x_increasing_ = this->square_->x - 1 < 0;
      }
    if (this->y_increasing_)
      {
        ++this->square_->y;
        this->y_increasing_ = this->square_->y + 1 <= this->max_y_;
      }
    else
      {
        --this->square_->y;
        this->y_increasing_ = this->square_->y - 1 < 0;
      }
    if (resize_shape ())
      {
        if (this->size_increasing_)
          {
            ++this->square_->shapesize;
            this->size_increasing_ = this->square_->shapesize + 1 <= this->max_size_;
          }
        else
          {
            --this->square_->shapesize;
            this->size_increasing_ = this->square_->shapesize - 1 < 0;
          }
      }
    try
      {
        Shapes::Writer_var writer =
          this->ciao_context_->get_connection_info_write_data ();
        if (! ::CORBA::is_nil (writer.in ()))
          {
            writer->write_one (*this->square_, this->instance_handle_);
            ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("UPDATED Shape_info for <%C> %u:%u:%u\n"),
                      this->square_->color.in (),
                      this->square_->x,
                      this->square_->y,
                      this->square_->shapesize));
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::tick - "
                      "ERROR: Writer seems nil.\n"));
          }
      }
    catch (const CCM_DDS::NonExistent& )
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("Shape_info for <%C> not updated: <%C> didn't exist.\n"),
                    this->square_->color.in (), this->square_->color.in ()));
      }
    catch (const CCM_DDS::InternalError& )
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("Internal Error while updating Shape_info for <%C>.\n"),
                    this->square_->color.in ()));
      }
  }

  void
  Sender_exec_i::start (void)
  {
    // calculate the interval time
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
  Sender_exec_i::stop (void)
  {
    this->reactor ()->cancel_timer (this->ticker_);
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("Sender_exec_i::stop : Timer canceled.\n")));
    try
      {
        Shapes::Writer_var writer =
          this->ciao_context_->get_connection_info_write_data ();
        if (! ::CORBA::is_nil (writer.in ()))
          {
            writer->unregister_instance (*this->square_,
                                         this->instance_handle_);
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::stop - "
                      "ERROR: Writer seems nil.\n"));
          }
      }
    catch (const CCM_DDS::NonExistent& )
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("Shape_info for <%C> not deleted: <%C> didn't exist.\n"),
                    this->square_->color.in (), this->square_->color.in ()));
      }
    catch (const CCM_DDS::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Internal Error while deleting Shape_info for <%C>.\n"),
                    this->square_->color.in ()));
      }
  }

  // Component attributes and port operations.

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
  Sender_exec_i::max_x (void)
  {
    return this->max_x_;
  }

  void
  Sender_exec_i::max_x (
    const ::CORBA::UShort max_x)
  {
    this->max_x_ = max_x;
  }

  ::CORBA::UShort
  Sender_exec_i::max_y (void)
  {
    return this->max_y_;
  }

  void
  Sender_exec_i::max_y (
    const ::CORBA::UShort max_y)
  {
    this->max_y_ = max_y;
  }

  ::CORBA::UShort
  Sender_exec_i::max_size (void)
  {
    return this->max_size_;
  }

  void
  Sender_exec_i::max_size (
    const ::CORBA::UShort max_size)
  {
    this->max_size_ = max_size;
  }

  ::CORBA::Boolean
  Sender_exec_i::resize_shape (void)
  {
    return this->resize_shape_;
  }

  void
  Sender_exec_i::resize_shape (
    const ::CORBA::Boolean resize_shape)
  {
    this->resize_shape_ = resize_shape;
  }

  char*
  Sender_exec_i::color (void)
  {
    return ::CORBA::string_dup (this->color_);
  }

  void
  Sender_exec_i::color (const char* color)
  {
    this->color_ = ::CORBA::string_dup (color);
  }

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Shapes::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::configuration_complete (void)
  {
    // Set the square properties right now
    this->square_->x = ACE_OS::rand () % this->max_x_;
    this->square_->y = ACE_OS::rand () % this->max_y_;
    this->square_->shapesize = this->max_size_;
    this->square_->color = CORBA::string_dup(this->color_);
  }

  void
  Sender_exec_i::ccm_activate (void)
  {
    this->start ();

    // Register shape with dds.
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("REGISTER Shape_info for <%C> %u:%u:%u\n"),
                  this->square_->color.in (),
                  this->square_->x,
                  this->square_->y,
                  this->square_->shapesize));
    try
      {
        Shapes::Writer_var writer =
          this->ciao_context_->get_connection_info_write_data ();
        if (! ::CORBA::is_nil (writer.in ()))
          {
            this->instance_handle_ =
              writer->register_instance (*this->square_);
          }
        else
          {
            ACE_ERROR ((LM_ERROR, "Sender_exec_i::ccm_activate - "
                      "ERROR: Writer seems nil.\n"));
          }
      }
    catch (const CCM_DDS::AlreadyCreated& )
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Shape_info for <%C> already created.\n"),
                    this->square_->color.in ()));
      }
    catch (const CCM_DDS::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, ACE_TEXT ("Internal Error while creating Shape_info for <%C>.\n"),
                      this->square_->color.in ()));
      }
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
  create_Shapes_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
