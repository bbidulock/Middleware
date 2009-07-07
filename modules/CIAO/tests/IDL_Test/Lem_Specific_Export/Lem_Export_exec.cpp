// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.6.9 ****
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

#include "Lem_Export_exec.h"
#include "ciao/CIAO_common.h"

namespace CIAO_Foo_Impl
{
  //============================================================
  // Component Executor Implementation Class: Foo_exec_i
  //============================================================
  
  Foo_exec_i::Foo_exec_i (void)
  {
  }
  
  Foo_exec_i::~Foo_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes.
  
  // Port operations.
  
  // Operations from Components::SessionComponent.
  
  void
  Foo_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::CCM_Foo_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  Foo_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  Foo_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }
  
  void
  Foo_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  Foo_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C" LEM_EXPORT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Foo_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      Foo_exec_i,
      ::Components::EnterpriseComponent::_nil ());
    
    return retval;
  }
}

