// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.6
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
 *       http://doc.ece.uci.edu/
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

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1278

#include "Sender_exec.h"
#include "ace/OS_NS_time.h"

namespace CIAO_Hello_Sender_Impl
{
  //============================================================
  // Facet Executor Implementation Class: ReadMessage_exec_i
  //============================================================

  ReadMessage_exec_i::ReadMessage_exec_i (Sender_exec_i& component)
    : component_ (component)
  {
  }

  ReadMessage_exec_i::~ReadMessage_exec_i ()
  {
  }

  // Operations from ::Hello::ReadMessage

  char *
  ReadMessage_exec_i::get_message (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_EMERGENCY, "Sender returning message: [%C]\n", component_.message_.in ()));
    return CORBA::string_dup (component_.message_.in ());
  }

  //============================================================
  // Component Executor Implementation Class: Sender_exec_i
  //============================================================

  Sender_exec_i::Sender_exec_i (void)
    : message_(CORBA::string_dup ("Default Message")),
      color_ (::Hello::empty)
  {
  }

  Sender_exec_i::Sender_exec_i (const char* local_message)
    : message_(CORBA::string_dup (local_message)),
      color_ (::Hello::empty)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported operations and attributes.

  void
  Sender_exec_i::start (void)
  {
    /* Your code here. */
    Hello::TimeOut_var event = new OBV_Hello::TimeOut;
    event->data ("ACE/TAO/CIAO");
    ACE_DEBUG ((LM_EMERGENCY, "Sender initiates the process.\n"));
    this->context_->push_click_out (event.in ());

    ACE_DEBUG ((LM_EMERGENCY, "My current color is:"));

    switch (this->color_)
      {
      case ::Hello::empty:
        ACE_DEBUG ((LM_EMERGENCY, "ERROR: Enum attribute initialization failed.\n"));
        break;

      case ::Hello::white:
        ACE_DEBUG ((LM_EMERGENCY, "white\n"));
        break;

      case ::Hello::red:
        ACE_DEBUG ((LM_EMERGENCY, "red\n"));
        break;

      case ::Hello::yellow:
        ACE_DEBUG ((LM_EMERGENCY, "yellow\n"));
        break;

      default:
        ACE_DEBUG ((LM_EMERGENCY, "Unknown color!\n"));

      }

    // check color sequence
    ACE_DEBUG ((LM_DEBUG, "Checking color sequence\n"));
    if (this->colors_.length () == 3)
      {
        if ((this->colors_[0] != ::Hello::white) &&
            (this->colors_[1] != ::Hello::red) &&
            (this->colors_[2] != ::Hello::yellow))
          {
            ACE_ERROR ((LM_EMERGENCY, "error: Unexpected color in color sequence\n"));
          }
      }
    else
      ACE_ERROR ((LM_EMERGENCY, "error: color sequence is wrong length!\n"));

    ACE_DEBUG ((LM_DEBUG, "Checking string sequence\n"));
    if (this->strings_.length () == 3)
      {
        if ((ACE_OS::strcmp ("Hello", this->strings_[0]) != 0) &&
            (ACE_OS::strcmp ("World", this->strings_[1]) != 0) &&
            (ACE_OS::strcmp ("!", this->strings_[2]) != 0))
          {
            ACE_ERROR ((LM_EMERGENCY, "error: string in sequence\n"));
          }
      }
    else
      ACE_ERROR ((LM_EMERGENCY, "error: string sequence is wrong length!\n"));

    ACE_DEBUG ((LM_DEBUG, "Checking color struct\n"));
    if ((ACE_OS::strcmp ("Yellow!", this->color_struct_.color_name) != 0) &&
        this->color_struct_.color_id != 42 &&
        this->color_struct_.color != Hello::yellow)
      {
        ACE_ERROR ((LM_EMERGENCY, "error: members of the color struct are wrong\n"));
      }

  }

  // Component attributes and port operations.

  ::Hello::CCM_ReadMessage_ptr
  Sender_exec_i::get_push_message (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_EMERGENCY,
                "Sender_exec.i::get_push_message called\n"));
    return ( new ReadMessage_exec_i (*this) );
  }

  char *
  Sender_exec_i::local_message (void)
  {
    /* Your code here. */
    return CORBA::string_dup (message_.in ());
  }

  void
  Sender_exec_i::local_message (
    const char * local_message)
  {
    /* Your code here. */
    message_ = CORBA::string_dup (local_message);
  }

  ::Hello::COLOR_SELECTION
  Sender_exec_i::color (void)
  {
    /* Your code here. */
    return this->color_;
  }

  void
  Sender_exec_i::color (
    ::Hello::COLOR_SELECTION color)
  {
    /* Your code here. */
    this->color_ = color;
  }

  ::Hello::COLORS *
  Sender_exec_i::the_colors (void)
  {
    /* Your code here. */
    return 0;
  }

  void
  Sender_exec_i::the_colors (
    const ::Hello::COLORS & the_colors)
  {
    this->colors_.length (the_colors.length ());
    for (CORBA::ULong i = 0; i < the_colors.length (); ++i)
      {
        this->colors_[i] = the_colors[i];
      }
  }

  ::CORBA::StringSeq *
  Sender_exec_i::str_seq (void)
  {
    return 0;
  }

  void
  Sender_exec_i::str_seq (
    const ::CORBA::StringSeq & strings)
  {
    this->strings_.length (strings.length ());
    for (CORBA::ULong i = 0; i < strings.length (); ++i)
      {
        this->strings_[i] = strings[i];
      }
  }

  ::Hello::COLOR_STRUCT *
  Sender_exec_i::color_st (void)
  {
    return 0;
  }

  void
  Sender_exec_i::color_st (
    const ::Hello::COLOR_STRUCT &col_struct)
  {
    this->color_struct_ = col_struct;
  }

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    ACE_DEBUG ((LM_EMERGENCY, "Sender_exec_i::set_session_context\n"));
    this->context_ =
      ::Hello::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::configuration_complete (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_EMERGENCY,
                "Sender_exec_i::configuration_complete\n"));
  }

  void
  Sender_exec_i::ccm_activate (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_EMERGENCY,
                "Sender_exec_i::ccm_activate\n"));
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_EMERGENCY, "Sender_exec_i::ccm_passivate\n"));
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    /* Your code here. */
    ACE_DEBUG ((LM_EMERGENCY, "Sender_exec_i::ccm_remove\n"));
  }

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}

namespace CIAO_Hello_Sender_Impl
{
  //============================================================
  // Home Executor Implementation Class: SenderHome_exec_i
  //============================================================

  SenderHome_exec_i::SenderHome_exec_i (void)
  {
  }

  SenderHome_exec_i::~SenderHome_exec_i (void)
  {
  }

  // All operations and attributes.

  // Factory operations.

  // Finder operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  SenderHome_exec_i::create (void)
  {
    ACE_DEBUG ((LM_EMERGENCY, "(%P|%t) creating SenderHome\n"));
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      Sender_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" SENDER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_SenderHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_NORETURN (
      retval,
      SenderHome_exec_i);

    return retval;
  }
}
