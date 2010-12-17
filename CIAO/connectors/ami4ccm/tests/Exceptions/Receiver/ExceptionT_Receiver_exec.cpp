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

#include "ExceptionT_Receiver_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_ExceptionT_Receiver_Impl
{

  /**
   * Facet Executor Implementation Class: do_my_foo_exec_i
   */

  do_my_foo_exec_i::do_my_foo_exec_i (
        ::ExceptionT::CCM_Receiver_Context_ptr ctx)
    : ciao_context_ (
        ::ExceptionT::CCM_Receiver_Context::_duplicate (ctx)),
        get_rw_ (true),
        get_ro_ (true)
  {
  }

  do_my_foo_exec_i::~do_my_foo_exec_i (void)
  {
  }

  // Operations from ::ExceptionT::MyFoo

  ::CORBA::Long
  do_my_foo_exec_i::foo (const char * in_str,
  ::CORBA::String_out answer)
  {
    if (ACE_OS::strlen (in_str) == 0)
      {
        ExceptionT::InternalError ex  (42, "Rec.Exc.foo",
                                       "thrown by receiver");
        throw ex;
      }
    else
      {
        ACE_OS::sleep (ACE_OS::rand () % 2);
        answer = CORBA::string_dup ("This is my answer : Hi");
        return ACE_OS::rand () % 100;
      }
  }

  void
  do_my_foo_exec_i::hello (::CORBA::Long_out answer)
  {
    ACE_OS::sleep (ACE_OS::rand () % 2);
    answer = ACE_OS::rand () % 100;
    //always an exception is thrown
    ExceptionT::InternalError ex (42, "Rec.Exc.hello",
                                  "thrown by receiver");
    throw ex;
  }

  ::CORBA::Short
  do_my_foo_exec_i::rw_attrib (void)
  {
    // this->get_rw_ is always true, so always an exception is thrown.
    if (this->get_rw_)
      {
         ExceptionT::InternalError ex (42, "Rec.Exc.get_rw_attrib",
                                           "thrown by receiver");
         throw ex;
      }
    else
      {
        return ACE_OS::rand () % 100;
      }
  }

  void
  do_my_foo_exec_i::rw_attrib(::CORBA::Short new_value)
  {
    if (new_value == 0)
      {
        //throw internal excep
        ExceptionT::InternalError ex (42, "Rec.Exc.set_rw_attrib",
                                          "thrown by receiver");
        throw ex;
      }
    else
      {
        ACE_OS::sleep (ACE_OS::rand () % 2);
      }
  }

  ::CORBA::Short
  do_my_foo_exec_i::ro_attrib (void)
  {
    // this->get_ro_ is always true, so always an exception is thrown.
    if (this->get_ro_)
      {
        ExceptionT::InternalError ex (42, "Rec.Exc.ro_attrib",
                                          "thrown by receiver");
        throw ex;
      }
    else
      {
        ACE_OS::sleep (ACE_OS::rand () % 2);
      }
    return ACE_OS::rand () % 100;
  }

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  Receiver_exec_i::Receiver_exec_i (void){
  }

  Receiver_exec_i::~Receiver_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::ExceptionT::CCM_MyFoo_ptr
  Receiver_exec_i::get_do_my_foo (void)
  {
    if ( ::CORBA::is_nil (this->ciao_do_my_foo_.in ()))
      {
        do_my_foo_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          do_my_foo_exec_i (
            this->ciao_context_.in ()),
            ::ExceptionT::CCM_MyFoo::_nil ());

          this->ciao_do_my_foo_ = tmp;
      }

    return
      ::ExceptionT::CCM_MyFoo::_duplicate (
        this->ciao_do_my_foo_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Receiver_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::ExceptionT::CCM_Receiver_Context::_narrow (ctx);

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
  create_ExceptionT_Receiver_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Receiver_exec_i);

    return retval;
  }
}
