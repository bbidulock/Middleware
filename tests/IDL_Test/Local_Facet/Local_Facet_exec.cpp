// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.4
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
// be/be_codegen.cpp:1278

#include "Local_Facet_exec.h"

namespace CIAO_Bar_Impl
{
  //============================================================
  // Facet Executor Implementation Class: Foo_exec_i
  //============================================================
  
  Foo_exec_i::Foo_exec_i (void)
  {
  }
  
  Foo_exec_i::~Foo_exec_i (void)
  {
  }
  
  // Operations from ::Foo
  
  //============================================================
  // Component Executor Implementation Class: Bar_exec_i
  //============================================================
  
  Bar_exec_i::Bar_exec_i (void)
  {
  }
  
  Bar_exec_i::~Bar_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes and port operations.
  
  ::CCM_Foo_ptr
  Bar_exec_i::get_foo_out (void)
  {
    /* Your code here. */
    return ::CCM_Foo::_nil ();
  }
  
  // Operations from Components::SessionComponent.
  
  void
  Bar_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::CCM_Bar_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  Bar_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  Bar_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  Bar_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Bar_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C" LOCAL_FACET_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Bar_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Bar_exec_i);
    
    return retval;
  }
}

