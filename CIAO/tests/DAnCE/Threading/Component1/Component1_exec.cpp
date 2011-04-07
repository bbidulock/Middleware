// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.1
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

#include "Component1_exec.h"

namespace CIAO_Threading_Component1_Impl
{

  /**
   * Facet Executor Implementation Class: prov_interface_1_exec_i
   */

  prov_interface_1_exec_i::prov_interface_1_exec_i (
        ::Threading::CCM_Component1_Context_ptr ctx)
    : ciao_context_ (
        ::Threading::CCM_Component1_Context::_duplicate (ctx))
  {
  }

  prov_interface_1_exec_i::~prov_interface_1_exec_i (void)
  {
  }

  // Operations from ::Threading::interface_1

  void
  prov_interface_1_exec_i::invoke_on_interface_1 (void)
  {
    ACE_DEBUG ((LM_DEBUG, "prov_interface_1_exec_i::invoke_on_interface_1\n"));
  }

  /**
   * Component Executor Implementation Class: Component1_exec_i
   */

  Component1_exec_i::Component1_exec_i (void){
  }

  Component1_exec_i::~Component1_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::Threading::CCM_interface_1_ptr
  Component1_exec_i::get_prov_interface_1 (void)
  {
    if ( ::CORBA::is_nil (this->ciao_prov_interface_1_.in ()))
      {
        prov_interface_1_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          prov_interface_1_exec_i (
            this->ciao_context_.in ()),
            ::Threading::CCM_interface_1::_nil ());

          this->ciao_prov_interface_1_ = tmp;
      }

    return
      ::Threading::CCM_interface_1::_duplicate (
        this->ciao_prov_interface_1_.in ());
  }

  // Operations from Components::SessionComponent.

  void
  Component1_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::Threading::CCM_Component1_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Component1_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Component1_exec_i::ccm_activate (void)
  {
    ::Threading::interface_2_var interface_2 =
      this->ciao_context_->get_connection_use_interface_2 ();
    interface_2->invoke_on_interface_2 ();
    ACE_DEBUG ((LM_DEBUG, "prov_interface_1_exec_i::invoke_on_interface_1 - "
                          "Is not blocking!!\n"));
  }

  void
  Component1_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Component1_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" COMPONENT1_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Threading_Component1_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Component1_exec_i);

    return retval;
  }
}
