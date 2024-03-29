// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2.3
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

#include "Shapes_Sender_comp_exec.h"

namespace CIAO_Shapes_Sender_comp_Impl
{

  /**
   * Facet Executor Implementation Class: control_exec_i
   */

  control_exec_i::control_exec_i (
        ::Shapes::CCM_Sender_comp_Context_ptr ctx)
    : ciao_context_ (
        ::Shapes::CCM_Sender_comp_Context::_duplicate (ctx))
  {
  }

  control_exec_i::~control_exec_i (void)
  {
  }

  // Operations from ::Shapes::Control_obj

  ::Shapes::ReturnStatus
  control_exec_i::setSize (
    ::CORBA::UShort /* size */)
  {
    /* Your code here. */
    return static_cast< ::Shapes::ReturnStatus> (0UL);
  }

  ::Shapes::ReturnStatus
  control_exec_i::setLocation (
    ::CORBA::UShort /* x */,
    ::CORBA::UShort /* y */)
  {
    /* Your code here. */
    return static_cast< ::Shapes::ReturnStatus> (0UL);
  }

  /**
   * Component Executor Implementation Class: Sender_comp_exec_i
   */

  Sender_comp_exec_i::Sender_comp_exec_i (void)
  {
  }

  Sender_comp_exec_i::~Sender_comp_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::Shapes::CCM_Control_obj_ptr
  Sender_comp_exec_i::get_control (void)
  {
    if ( ::CORBA::is_nil (this->ciao_control_.in ()))
      {
        control_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          control_exec_i (
            this->ciao_context_.in ()),
            ::Shapes::CCM_Control_obj::_nil ());

          this->ciao_control_ = tmp;
      }

    return
      ::Shapes::CCM_Control_obj::_duplicate (
        this->ciao_control_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Sender_comp_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Shapes::CCM_Sender_comp_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_comp_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Sender_comp_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Sender_comp_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_comp_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" SHAPES_SENDER_COMP_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shapes_Sender_comp_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_comp_exec_i);

    return retval;
  }
}
