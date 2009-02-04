// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#include "SimpleUser_exec.h"
#include "ciao/CIAO_common.h"

namespace CIDL_SimpleUser_Impl
{
  //==================================================================
  // Component Executor Implementation Class:   SimpleUser_exec_i
  //==================================================================

  SimpleUser_exec_i::SimpleUser_exec_i (void)
  {
    CIAO_TRACE ("SimpleUser_exec_i::SimpleUser_exec_i (void)");
  }

  SimpleUser_exec_i::~SimpleUser_exec_i (void)
  {
    CIAO_TRACE ("SimpleUser_exec_i::~SimpleUser_exec_i (void)");
  }

  // Supported or inherited operations.

  // Attribute operations.

  // Port operations.

  // Operations from Components::SessionComponent

  void
  SimpleUser_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    CIAO_TRACE ("SimpleUser_exec_i::set_session_context ()");
    this->context_ =
      ::Simple::CCM_SimpleUser_Context::_narrow (ctx);

    if (CORBA::is_nil (this->context_.in ()))
    {
      throw ::CORBA::INTERNAL ();
    }
  }

  void
  SimpleUser_exec_i::configuration_complete ()
  {
    CIAO_TRACE ("SimpleUser_exec_i::configuration_complete ()");
    // Your code here.
  }

  void
  SimpleUser_exec_i::ccm_activate ()
  {
    CIAO_TRACE ("SimpleUser_exec_i::ccm_activate ()");
    
    ::Simple::Trigger_var trig (this->context_->get_connection_trig ());
    
    if (CORBA::is_nil (trig.in ()))
      {
        CIAO_ERROR ((LM_ERROR, "SimpleUser_exec_i::ccm_activate () - "
                     "Error: Reference nil for port trig\n"));
	return;
      }
    
    // Your code here.
    try
      {
        trig->hello ("Test successful; hello from SimpleUser.");
      }
    catch (CORBA::Exception &ex)
      {
        CIAO_ERROR ((LM_ERROR, "SimpleUser_exec_i::ccm_activate () - "
                     "Caught CORBA exception, details follow:\n"));
        ex._tao_print_exception ("SimpleUser_exec_i::ccm_activate () - ");
      }
    catch (...)
      {
        CIAO_ERROR ((LM_ERROR, "SimpleUser_exec_i::ccm_activate () - "
                     "Error: Caught unknown exception whilst invoking reference for port trig.\n"));
      }
  }

  void
  SimpleUser_exec_i::ccm_passivate ()
  {
    CIAO_TRACE ("SimpleUser_exec_i::ccm_passivate ()");
    // Your code here.
  }

  void
  SimpleUser_exec_i::ccm_remove ()
  {
    CIAO_TRACE ("SimpleUser_exec_i::ccm_remove ()");
    // Your code here.
  }

  //==================================================================
  // Home Executor Implementation Class:   SimpleUserHome_exec_i
  //==================================================================

  SimpleUserHome_exec_i::SimpleUserHome_exec_i (void)
  {
    CIAO_TRACE ("SimpleUserHome_exec_i::SimpleUserHome_exec_i (void)");
  }

  SimpleUserHome_exec_i::~SimpleUserHome_exec_i (void)
  {
    CIAO_TRACE ("SimpleUserHome_exec_i::~SimpleUserHome_exec_i (void)");
  }

  // Supported or inherited operations.

  // Home operations.

  // Factory and finder operations.

  // Attribute operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  SimpleUserHome_exec_i::create ()
  {
    CIAO_TRACE ("SimpleUserHome_exec_i::create ()");
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      SimpleUser_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" SIMPLEUSER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Simple_SimpleUserHome_Impl (void)
  {
    CIAO_TRACE ("create_Simple_SimpleUserHome_Impl (void)");
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      SimpleUserHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

