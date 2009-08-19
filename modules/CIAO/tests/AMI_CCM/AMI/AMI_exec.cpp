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

#include "AMI_exec.h"
#include "ciao/CIAO_common.h"

namespace CIAO_Hello_AMI_AMI_Impl
{
  //============================================================
  // Facet Executor Implementation Class: AMI_ami_foo_exec_i
  //============================================================
  
  AMI_ami_foo_exec_i::AMI_ami_foo_exec_i (::CCM_AMI::AMI_foo_ptr foo_receiver) :
      foo_receiver_ (::CCM_AMI::AMI_foo::_duplicate (foo_receiver))
  {
    
  }
  
  AMI_ami_foo_exec_i::~AMI_ami_foo_exec_i (void)
  {
  }
  
  // Operations from ::CCM_AMI::AMI_ami_foo
  
  void
  AMI_ami_foo_exec_i::sendc_asynch_foo (
    const char * in_str,
    ::CCM_AMI::AMI_foo_callback_ptr /* foo_callback */)
  {
    printf ("\n\n\n\n\nAMI: Received string <%s>!!!!\n", in_str);
    printf ("AMI: Try to pass it on to the Receiver component\n");
    char* out_str;
    CORBA::Long   result;
    result = foo_receiver_->asynch_foo (CORBA::string_dup (in_str), out_str);
  }
  
  //============================================================
  // Component Executor Implementation Class: AMI_exec_i
  //============================================================
  
  AMI_exec_i::AMI_exec_i (void)
  {
  }
  
  AMI_exec_i::~AMI_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes.
  
  // Port operations.
  
  ::CCM_AMI::CCM_AMI_ami_foo_ptr
  AMI_exec_i::get_perform_asynch_foo (void)
  {
    ::CCM_AMI::AMI_foo_var receiver_foo =
      this->context_->get_connection_receiver_foo ();
    
    return new AMI_ami_foo_exec_i (receiver_foo);
  }
  
  // Operations from Components::SessionComponent.
  
  void
  AMI_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_AMI::CCM_AMI_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  AMI_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  AMI_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  AMI_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  AMI_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_AMI_AMI_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      AMI_exec_i,
      ::Components::EnterpriseComponent::_nil ());
    
    return retval;
  }
}

namespace CIAO_Hello_AMI_AMI_Impl
{
  //============================================================
  // Home Executor Implementation Class: AMIHome_exec_i
  //============================================================
  
  AMIHome_exec_i::AMIHome_exec_i (void)
  {
  }
  
  AMIHome_exec_i::~AMIHome_exec_i (void)
  {
  }
  
  // All operations and attributes.
  
  // Factory operations.
  
  // Finder operations.
  
  // Implicit operations.
  
  ::Components::EnterpriseComponent_ptr
  AMIHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      AMI_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C"  ::Components::HomeExecutorBase_ptr
  create_Hello_AMI_AMIHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      AMIHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());
    
    return retval;
  }
}

