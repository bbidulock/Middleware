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

#include "Launch_Failure_exec.h"

namespace CIAO_Launch_Failure_Impl
{

  /**
   * Facet Executor Implementation Class: remote_out_exec_i
   */

  remote_out_exec_i::remote_out_exec_i (
        ::CCM_Launch_Failure_Context_ptr ctx)
    : ciao_context_ (
        ::CCM_Launch_Failure_Context::_duplicate (ctx))
  {
  }

  remote_out_exec_i::~remote_out_exec_i (void)
  {
  }

  // Operations from ::Remote_Interface

  /**
   * Facet Executor Implementation Class: local_out_exec_i
   */

  local_out_exec_i::local_out_exec_i (
        ::CCM_Launch_Failure_Context_ptr ctx)
    : ciao_context_ (
        ::CCM_Launch_Failure_Context::_duplicate (ctx))
  {
  }

  local_out_exec_i::~local_out_exec_i (void)
  {
  }

  // Operations from ::Local_Interface

  /**
   * Facet Executor Implementation Class: local_in_exec_i
   */

  local_in_exec_i::local_in_exec_i (
        ::CCM_Launch_Failure_Context_ptr ctx)
    : ciao_context_ (
        ::CCM_Launch_Failure_Context::_duplicate (ctx))
  {
  }

  local_in_exec_i::~local_in_exec_i (void)
  {
  }

  // Operations from ::Local_Interface

  /**
   * Component Executor Implementation Class: Launch_Failure_exec_i
   */

  Launch_Failure_exec_i::Launch_Failure_exec_i (void)
    : failure_reason_ (::NO_LAUNCH_ERROR)
  {
  }

  Launch_Failure_exec_i::~Launch_Failure_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  ::CCM_Remote_Interface_ptr
  Launch_Failure_exec_i::get_remote_out (void)
  {
    if (this->failure_reason_ == ::FACET_REFERENCE_EXCEPTION)
      {
        throw 1;
      }

    if (this->failure_reason_ == ::NIL_FACET_REFERENCE)
      {
        return 0;
      }

    if ( ::CORBA::is_nil (this->ciao_remote_out_.in ()))
      {
        remote_out_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          remote_out_exec_i (
            this->ciao_context_.in ()),
            ::CCM_Remote_Interface::_nil ());

          this->ciao_remote_out_ = tmp;
      }

    return
      ::CCM_Remote_Interface::_duplicate (
        this->ciao_remote_out_.in ());
  }

  ::CCM_Local_Interface_ptr
  Launch_Failure_exec_i::get_local_out (void)
  {
    if (this->failure_reason_ == ::FACET_REFERENCE_EXCEPTION)
      {
        throw 1;
      }

    if (this->failure_reason_ == ::NIL_FACET_REFERENCE)
      {
        return 0;
      }

    if ( ::CORBA::is_nil (this->ciao_local_out_.in ()))
      {
        local_out_exec_i *tmp = 0;
        ACE_NEW_RETURN (
          tmp,
          local_out_exec_i (
            this->ciao_context_.in ()),
            ::CCM_Local_Interface::_nil ());

          this->ciao_local_out_ = tmp;
      }

    return
      ::CCM_Local_Interface::_duplicate (
        this->ciao_local_out_.in ());
  }

  ::Failure_Reason
  Launch_Failure_exec_i::failure_reason (void)
  {
    return this->failure_reason_;
  }

  void
  Launch_Failure_exec_i::failure_reason (
    const ::Failure_Reason failure_reason)
  {
    if (failure_reason == ATTRIBUTE_EXCEPTION)
      throw 1;

    this->failure_reason_ = failure_reason;
  }

  // Operations from Components::SessionComponent.

  void
  Launch_Failure_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::CCM_Launch_Failure_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Launch_Failure_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }

  void
  Launch_Failure_exec_i::ccm_activate (void)
  {
    /* Your code here. */
  }

  void
  Launch_Failure_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Launch_Failure_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }

  extern "C" LAUNCH_FAILURE_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Launch_Failure_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Launch_Failure_exec_i);

    return retval;
  }

  extern "C" LAUNCH_FAILURE_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Launch_Failure_Nil (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    // Intentionally return nil.
    return retval;
  }

  extern "C" LAUNCH_FAILURE_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Launch_Failure_Exception (void)
  {
    // Throw an exception
    throw 1;
  }
}

namespace CIAO_Launch_Failure_Impl
{
  /**
   * Home Executor Implementation Class: Launch_Failure_Home_exec_i
   */

  Launch_Failure_Home_exec_i::Launch_Failure_Home_exec_i (void)
  {
  }

  Launch_Failure_Home_exec_i::~Launch_Failure_Home_exec_i (void)
  {
  }

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  Launch_Failure_Home_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      Launch_Failure_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" LAUNCH_FAILURE_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Launch_Failure_Home_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Launch_Failure_Home_exec_i);

    return retval;
  }
}
