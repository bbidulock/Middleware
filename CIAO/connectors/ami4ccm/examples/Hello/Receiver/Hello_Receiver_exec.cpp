// -*- C++ -*-
//
// $Id$

#include "Hello_Receiver_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_Hello_AMI_Receiver_Impl
{
  //============================================================
  // Facet Executor Implementation Class: MyFoo_exec_i
  //============================================================

  MyFoo_exec_i::MyFoo_exec_i (void)
  {
  }

  MyFoo_exec_i::~MyFoo_exec_i (void)
  {
  }

  // Operations from ::CCM_AMI::MyFoo

  ::CORBA::Long
  MyFoo_exec_i::foo (
    const char * in_str,
    ::CORBA::String_out answer)
  {
    if (ACE_OS::strlen (in_str) == 0)
      {
        printf ("Receiver (FOO) :\tEMPTY string received -> throw internal excep with id <42> and errorstring <Hello World>\n");
        Hello::InternalError ex;
        ex.id = 42;
        ex.error_string = "Hello world";
        throw ex;
      }
    else
      {
        printf ("Receiver (FOO) :\tReceived string <%s>\n", in_str);
        ACE_OS::sleep (ACE_OS::rand () % 2);
        answer = CORBA::string_dup ("This is my answer : Hi");
        return ACE_OS::rand () % 100;
      }
  }

  void
  MyFoo_exec_i::hello (
    CORBA::Long_out answer)
  {
    printf ("Receiver (HELLO) :\tReceived request\n");
    ACE_OS::sleep (ACE_OS::rand () % 2);
    answer = ACE_OS::rand () % 100;
  }

  CORBA::Short
  MyFoo_exec_i::rw_attrib ()
  {
    printf ("Receiver (RW_ATTRIB) :\tReceived request\n");
    ACE_OS::sleep (ACE_OS::rand () % 2);
    return ACE_OS::rand () % 100;
  }

  void
  MyFoo_exec_i::rw_attrib (
    CORBA::Short new_value)
  {
    if (new_value == 0)
    {
      printf ("Receiver (RW_ATTRIB) :\tnew_value == 0 -> THROW empty exception\n");
      Hello::InternalError ex;
      throw ex;
    }
    else
    {
      printf ("Receiver (RW_ATTRIB) :\tSet <%d>\n", new_value);
      ACE_OS::sleep (ACE_OS::rand () % 2);
    }
  }

  CORBA::Short
  MyFoo_exec_i::ro_attrib ()
  {
    printf ("Receiver (RO_ATTRIB) :\tReceived request\n");
    ACE_OS::sleep (ACE_OS::rand () % 2);
    return ACE_OS::rand () % 100;
  }

  //============================================================
  // Component Executor Implementation Class: Receiver_exec_i
  //============================================================

  Receiver_exec_i::Receiver_exec_i (void)
  {
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes.

  // Port operations.

  ::Hello::CCM_MyFoo_ptr
  Receiver_exec_i::get_do_my_foo (void)
  {
    return new MyFoo_exec_i ();
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_AMI::CCM_Receiver_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->context_.in ()))
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
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Receiver_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_AMI_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_RETURN (
      retval,
      Receiver_exec_i,
      ::Components::EnterpriseComponent::_nil ());

    return retval;
  }
}

namespace CIAO_Hello_AMI_Receiver_Impl
{
  //============================================================
  // Home Executor Implementation Class: ReceiverHome_exec_i
  //============================================================

  ReceiverHome_exec_i::ReceiverHome_exec_i (void)
  {
  }

  ReceiverHome_exec_i::~ReceiverHome_exec_i (void)
  {
  }

  // All operations and attributes.

  // Factory operations.

  // Finder operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  ReceiverHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      Receiver_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C"  ::Components::HomeExecutorBase_ptr
  create_Hello_AMI_ReceiverHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      ReceiverHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

