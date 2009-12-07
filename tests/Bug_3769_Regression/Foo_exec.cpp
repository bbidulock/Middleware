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
// .\be\be_codegen.cpp:1278

#include "Foo_exec.h"

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
  
  // Component attributes and port operations.
  
  ::CORBA::Short
  Foo_exec_i::my_short (void)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  Foo_exec_i::my_short (
    ::CORBA::Short my_short)
  {
    if(my_short != 22)
      ACE_ERROR ((LM_ERROR, "ERROR: my_short != 22, it is %d\n", my_short));
  }
  
  ::CORBA::Long
  Foo_exec_i::my_long (void)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  Foo_exec_i::my_long (
    ::CORBA::Long my_long)
  {
    if(my_long != 33)
      ACE_ERROR ((LM_ERROR, "ERROR: my_long != 33, it is %d\n", my_long));
  }
  
  ::CORBA::Float
  Foo_exec_i::my_float (void)
  {
    /* Your code here. */
    return 0.0f;
  }
  
  void
  Foo_exec_i::my_float (
    ::CORBA::Float my_float)
  {
    if(my_float != 45.67F)
      ACE_ERROR ((LM_ERROR, "ERROR: my_float != 45.67, it is %f\n", my_float));
  }
  
  ::CORBA::Double
  Foo_exec_i::my_double (void)
  {
    /* Your code here. */
    return 0.0;
  }
  
  void
  Foo_exec_i::my_double (
    ::CORBA::Double my_double)
  {
    if(my_double != 56.78)
      ACE_ERROR ((LM_ERROR, "ERROR: my_double != 56.78, it is %f\n", my_double));
  }
  
  ::short_sequence *
  Foo_exec_i::my_short_sequence (void)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  Foo_exec_i::my_short_sequence (
    const ::short_sequence & my_short_sequence)
  {
    if(my_short_sequence.length() != 3)
    {
      ACE_ERROR ((LM_ERROR, "ERROR: my_short_sequence does not have the correct length\n"));
      return;
    }

    if(my_short_sequence[0] != 11)
      ACE_ERROR ((LM_ERROR, "ERROR: my_short_sequence[0] != 11, it is %d\n", my_short_sequence[0]));

    if(my_short_sequence[1] != 12)
      ACE_ERROR ((LM_ERROR, "ERROR: my_short_sequence[1] != 12, it is %d\n", my_short_sequence[1]));

    if(my_short_sequence[2] != 13)
      ACE_ERROR ((LM_ERROR, "ERROR: my_short_sequence[2] != 13, it is %d\n", my_short_sequence[2]));
  }
  
  ::long_sequence *
  Foo_exec_i::my_long_sequence (void)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  Foo_exec_i::my_long_sequence (
    const ::long_sequence & my_long_sequence)
  {
    if(my_long_sequence.length() != 3)
    {
      ACE_ERROR ((LM_ERROR, "ERROR: my_long_sequence does not have the correct length\n"));
      return;
    }

    if(my_long_sequence[0] != 21)
      ACE_ERROR ((LM_ERROR, "ERROR: my_long_sequence[0] != 21, it is %d\n", my_long_sequence[0]));

    if(my_long_sequence[1] != 22)
      ACE_ERROR ((LM_ERROR, "ERROR: my_long_sequence[1] != 22, it is %d\n", my_long_sequence[1]));

    if(my_long_sequence[2] != 23)
      ACE_ERROR ((LM_ERROR, "ERROR: my_long_sequence[2] != 23, it is %d\n", my_long_sequence[2]));
  }
  
  ::float_sequence *
  Foo_exec_i::my_float_sequence (void)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  Foo_exec_i::my_float_sequence (
    const ::float_sequence & my_float_sequence)
  {
    if(my_float_sequence.length() != 3)
    {
      ACE_ERROR ((LM_ERROR, "ERROR: my_float_sequence does not have the correct length\n"));
      return;
    }

    if(my_float_sequence[0] != 21.12F)
      ACE_ERROR ((LM_ERROR, "ERROR: my_float_sequence[0] != 21.12, it is %f\n", my_float_sequence[0]));

    if(my_float_sequence[1] != 22.22F)
      ACE_ERROR ((LM_ERROR, "ERROR: my_float_sequence[1] != 22.22, it is %f\n", my_float_sequence[1]));

    if(my_float_sequence[2] != 23.32F)
      ACE_ERROR ((LM_ERROR, "ERROR: my_float_sequence[2] != 23.32, it is %f\n", my_float_sequence[2]));
  }
  
  ::double_sequence *
  Foo_exec_i::my_double_sequence (void)
  {
    /* Your code here. */
    return 0;
  }
  
  void
  Foo_exec_i::my_double_sequence (
    const ::double_sequence & my_double_sequence)
  {
    if(my_double_sequence.length() != 3)
    {
      ACE_ERROR ((LM_ERROR, "ERROR: my_double_sequence does not have the correct length\n"));
      return;
    }

    if(my_double_sequence[0] != 621.12)
      ACE_ERROR ((LM_ERROR, "ERROR: my_double_sequence[0] != 621.12, it is %f\n", my_double_sequence[0]));

    if(my_double_sequence[1] != 622.22)
      ACE_ERROR ((LM_ERROR, "ERROR: my_double_sequence[1] != 622.22, it is %f\n", my_double_sequence[1]));

    if(my_double_sequence[2] != 623.32)
      ACE_ERROR ((LM_ERROR, "ERROR: my_double_sequence[2] != 623.32, it is %f\n", my_double_sequence[2]));
  }
  
  ::Bar
  Foo_exec_i::my_bar_struct (void)
  {
    /* Your code here. */
    return ::Bar ();
  }
  
  void
  Foo_exec_i::my_bar_struct (
    const ::Bar & my_bar_struct)
  {
    if(my_bar_struct.s != 3)
      ACE_ERROR ((LM_ERROR, "ERROR: short value != 3, it is %d\n", my_bar_struct.s));

    if(my_bar_struct.l != 4)
      ACE_ERROR ((LM_ERROR, "ERROR: long value != 4, it is %d\n", my_bar_struct.l));

    if(my_bar_struct.f != 5.6F)
      ACE_ERROR ((LM_ERROR, "ERROR: float value != 5.6, it is %f\n", my_bar_struct.f));

    if(my_bar_struct.s != 7.8)
      ACE_ERROR ((LM_ERROR, "ERROR: short value != 7.8, it is %f\n", my_bar_struct.d));
  }
  
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
  
  extern "C" FOO_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Foo_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_NORETURN (
      retval,
      Foo_exec_i);
    
    return retval;
  }
}

