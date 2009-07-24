// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.1 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:1278

#include "Hello_Sender_exec.h"
#include "ciao/CIAO_common.h"

namespace CIAO_Hello_AMI_Sender_Impl
{
  //============================================================
  // Facet Executor Implementation Class: AMI_foo_exec_i
  //============================================================
  
  AMI_foo_exec_i::AMI_foo_exec_i (void)
  {
  }
  
  AMI_foo_exec_i::~AMI_foo_exec_i (void)
  {
  }
  
  // Operations from ::CCM_AMI::AMI_foo
  
  ::CORBA::Long
  AMI_foo_exec_i::asynch_foo (
    const char * /* in_str */,
    ::CORBA::String_out /* answer */)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  AMI_foo_exec_i::foo_callback (
    ::CORBA::Long /* result */,
    const char * /* answer */)
  {
    /* Your code here. */
  }
  
  //============================================================
  // Component Executor Implementation Class: Sender_exec_i
  //============================================================
  
  Sender_exec_i::Sender_exec_i (void)
  {
  }
  
  Sender_exec_i::~Sender_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes.
  
  // Port operations.
  
  ::CCM_AMI::CCM_AMI_foo_ptr
  Sender_exec_i::get_callback_foo (void)
  {
    /* Your code here. */
    return ::CCM_AMI::CCM_AMI_foo::_nil ();
  }
  
  // Operations from Components::SessionComponent.
  
  void
  Sender_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_AMI::CCM_Sender_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
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
    /* Your code here. */
    
  }
  
  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Sender_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_AMI_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      Sender_exec_i,
      ::Components::EnterpriseComponent::_nil ());
    
    return retval;
  }
}

namespace CIAO_Hello_AMI_Sender_Impl
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
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      Sender_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C"  ::Components::HomeExecutorBase_ptr
  create_Hello_AMI_SenderHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      SenderHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());
    
    return retval;
  }
}

