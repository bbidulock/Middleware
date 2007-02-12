//$Id$

#include "Sender_exec.h"

namespace CIDL_Sender_Impl
{
  char*
  Message_Impl::get_message ()
  {
    ACE_DEBUG ((LM_DEBUG, "Sender sending out message: [%s]\n", component_.message_.in ()));
    return CORBA::string_dup (component_.message_.in ());
  }

  Sender_exec_i::~Sender_exec_i ()
  {
  }

  void
  Sender_exec_i::local_message (const char * local_message)
  {
    message_ = CORBA::string_dup (local_message);
  }

  char *
  Sender_exec_i::local_message ()
  {
    return CORBA::string_dup (message_.in ());
  }

  void
  Sender_exec_i::hertz (CORBA::Long hertz)
  {
    this->hertz_ = hertz;
    ACE_DEBUG ((LM_DEBUG, "Sender_exec_i::Hertz:%d\n", this->hertz_));
  }

  CORBA::Long
  Sender_exec_i::hertz ()
  {
    return this->hertz_;
  }

  ::Hello::COLOR_SELECTION
  Sender_exec_i::color ()
  {
    // Your code here.
    return this->color_;
  }

  void
  Sender_exec_i::color (
  ::Hello::COLOR_SELECTION color)
  {
    this->color_ = color;
  }

  Hello::CCM_ReadMessage_ptr
  Sender_exec_i::get_push_message ()
  {
    ACE_DEBUG ((LM_DEBUG,
                "Sender_exec.i::get_push_message called\n "));
    return ( new Message_Impl (*this) );
  }

  void
  Sender_exec_i::start ()
  {
    Hello::TimeOut_var event = new OBV_Hello::TimeOut;
    event->data ("ACE/TAO/CIAO");
    ACE_DEBUG ((LM_DEBUG, "Sender initiates the process.\n"));
    this->context_->push_click_out (event.in ());

    ACE_DEBUG ((LM_DEBUG, "My current color is:"));

    switch (this->color_)
      {
      case ::Hello::empty:
        ACE_DEBUG ((LM_DEBUG, "ERROR: Enum attribute initialization failed.\n"));
        break;

      case ::Hello::white:
        ACE_DEBUG ((LM_DEBUG, "white\n"));
        break;

      case ::Hello::red:
        ACE_DEBUG ((LM_DEBUG, "red\n"));
        break;

      case ::Hello::yellow:
        ACE_DEBUG ((LM_DEBUG, "yellow\n"));
        break;

      default:
        ACE_DEBUG ((LM_DEBUG, "Unknown color!\n"));

      }
  }

  void
  Sender_exec_i::set_session_context (Components::SessionContext_ptr ctx)
  {
    ACE_DEBUG ((LM_DEBUG, "Sender_exec_i::set_session_context\n"));

    this->context_ =
          Sender_Exec_Context::_narrow (ctx);

    if (CORBA::is_nil (this->context_.in ()))
      {
        throw CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::ciao_preactivate ()
  {
    ACE_DEBUG ((LM_DEBUG,
                "Sender_exec_i::ciao_preactivate\n"));
  }

  void
  Sender_exec_i::ccm_activate ()
  {
    ACE_DEBUG ((LM_DEBUG,
                "Sender_exec_i::ccm_activate\n"));
  }

  void
  Sender_exec_i::ciao_postactivate ()
  {
    ACE_DEBUG ((LM_DEBUG,
                "Sender_exec_i::ciao_postactivate\n"));
  }

  void
  Sender_exec_i::ccm_passivate ()
  {
    ACE_DEBUG ((LM_DEBUG, "Sender_exec_i::ccm_passivate\n"));
  }

  void
  Sender_exec_i::ccm_remove ()
  {
    ACE_DEBUG ((LM_DEBUG, "Sender_exec_i::ccm_remove\n"));
  }

  SenderHome_exec_i::SenderHome_exec_i ()
  {
  }

  SenderHome_exec_i::~SenderHome_exec_i ()
  {
  }

  ::Components::EnterpriseComponent_ptr
  SenderHome_exec_i::create ()
  {
    ACE_DEBUG ((LM_DEBUG, "(%P|%t) creating SenderHome \n"));
    return new Sender_exec_i;
  }

  extern "C" SENDER_EXEC_Export ::Components::HomeExecutorBase_ptr
  createSenderHome_Impl (void)
  {
    return new SenderHome_exec_i ();
  }
}

