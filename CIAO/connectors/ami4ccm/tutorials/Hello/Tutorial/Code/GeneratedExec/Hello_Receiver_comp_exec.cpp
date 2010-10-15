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

#include "Hello_Receiver_comp_exec.h"

namespace CIAO_Hello_Receiver_comp_Impl
{
  //============================================================
  // Facet Executor Implementation Class: do_my_foo_exec_i
  //============================================================
  
  do_my_foo_exec_i::do_my_foo_exec_i (
        ::Hello::CCM_Receiver_comp_Context_ptr ctx)
    : ciao_context_ (
        ::Hello::CCM_Receiver_comp_Context::_duplicate (ctx))
  {
  }
  
  do_my_foo_exec_i::~do_my_foo_exec_i (void)
  {
  }
  
  // Operations from ::Hello::MyFoo_obj
  
  ::CORBA::Long
  do_my_foo_exec_i::foo (
    const char * /* in_str */,
    ::CORBA::String_out /* answer */)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  do_my_foo_exec_i::hello (
    ::CORBA::Long_out /* answer */)
  {
    /* Your code here. */
  }
  
  ::CORBA::Short
  do_my_foo_exec_i::rw_attrib (void)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  do_my_foo_exec_i::rw_attrib (
    ::CORBA::Short /* rw_attrib */)
  {
    /* Your code here. */
  }
  
  ::CORBA::Short
  do_my_foo_exec_i::ro_attrib (void)
  {
    /* Your code here. */
    return 0;
  }
  
  //============================================================
  // Component Executor Implementation Class: Receiver_comp_exec_i
  //============================================================
  
  Receiver_comp_exec_i::Receiver_comp_exec_i (void)
  {
  }
  
  Receiver_comp_exec_i::~Receiver_comp_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  ::Hello::CCM_MyFoo_obj_ptr
  Receiver_comp_exec_i::get_do_my_foo (void)
  {
    if ( ::CORBA::is_nil (this->ciao_do_my_foo_.in ()))
      {
        do_my_foo_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          do_my_foo_exec_i (
            this->ciao_context_.in ()),
          ::Hello::CCM_MyFoo_obj::_nil ());
        
        this->ciao_do_my_foo_ = tmp;
      }
    
    return
      ::Hello::CCM_MyFoo_obj::_duplicate (
        this->ciao_do_my_foo_.in ());
  }
  
  // Operations from Components::SessionComponent.
  
  void
  Receiver_comp_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Hello::CCM_Receiver_comp_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  Receiver_comp_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  Receiver_comp_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  Receiver_comp_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Receiver_comp_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_Receiver_comp_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Receiver_comp_exec_i);
    
    return retval;
  }
}
