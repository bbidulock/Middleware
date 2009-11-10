// $Id$

#include "SimpleNull_exec.h"
#include "ciao/Logger/Log_Macros.h"

namespace CIAO_Simple_SimpleNull_Impl
{
  //==================================================================
  // Component Executor Implementation Class:   SimpleNull_exec_i
  //==================================================================

  SimpleNull_exec_i::SimpleNull_exec_i (void)
  {
    CIAO_TRACE ("SimpleNull_exec_i::SimpleNull_exec_i (void)");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNull_exec_i::SimpleNull_exec_i (void)\n"));
  }

  SimpleNull_exec_i::~SimpleNull_exec_i (void)
  {
    CIAO_TRACE ("SimpleNull_exec_i::~SimpleNull_exec_i");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNull_exec_i::~SimpleNull_exec_i\n"));
  }

  // Supported or inherited operations.

  // Attribute operations.

  // Port operations.

  // Operations from Components::SessionComponent

  void
  SimpleNull_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    CIAO_TRACE ("SimpleNull_exec_i::set_session_context");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNull_exec_i::set_session_context\n"));
    this->context_ =
      ::Simple::CCM_SimpleNull_Context::_narrow (ctx);

    if (CORBA::is_nil (this->context_.in ()))
    {
      throw ::CORBA::INTERNAL ();
    }
  }

  void
  SimpleNull_exec_i::configuration_complete ()
  {
    CIAO_TRACE ("SimpleNull_exec_i::configuration_complete\n");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNull_exec_i::configuration_complete\n"));
    // Your code here.
  }

  void
  SimpleNull_exec_i::ccm_activate ()
  {
    CIAO_TRACE ("SimpleNull_exec_i::ccm_activate");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNull_exec_i::ccm_activate\n"));
    // Your code here.
  }

  void
  SimpleNull_exec_i::ccm_passivate ()
  {
    CIAO_TRACE ("SimpleNull_exec_i::ccm_passivate");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNull_exec_i::ccm_passivate\n"));
    // Your code here.
  }

  void
  SimpleNull_exec_i::ccm_remove ()
  {
    CIAO_TRACE ("SimpleNull_exec_i::ccm_remove");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNull_exec_i::ccm_remove\n"));
    // Your code here.
  }

  extern "C" SIMPLENULL_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Simple_SimpleNull_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_RETURN (retval,
                    SimpleNull_exec_i,
                    ::Components::EnterpriseComponent::_nil ());

    return retval;
  }

  //==================================================================
  // Home Executor Implementation Class:   SimpleNullHome_exec_i
  //==================================================================

  SimpleNullHome_exec_i::SimpleNullHome_exec_i (void)
  {
    CIAO_TRACE ("SimpleNullHome_exec_i::SimpleNullHome_exec_i");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNullHome_exec_i::SimpleNullHome_exec_i\n"));
  }

  SimpleNullHome_exec_i::~SimpleNullHome_exec_i (void)
  {
    CIAO_TRACE ("SimpleNullHome_exec_i::~SimpleNullHome_exec_i");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNullHome_exec_i::~SimpleNullHome_exec_i\n"));
  }

  // Supported or inherited operations.

  // Home operations.

  // Factory and finder operations.

  // Attribute operations.

  // Implicit operations.

  ::Components::EnterpriseComponent_ptr
  SimpleNullHome_exec_i::create ()
  {
    CIAO_TRACE ("SimpleNullHome_exec_i::create");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - SimpleNullHome_exec_i::create\n"));
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_THROW_EX (
      retval,
      SimpleNull_exec_i,
      ::CORBA::NO_MEMORY ());

    return retval;
  }

  extern "C" SIMPLENULL_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Simple_SimpleNullHome_Impl (void)
  {
    CIAO_TRACE ("create_Simple_SimpleNullHome_Impl");
    CIAO_DEBUG ((LM_EMERGENCY, "SimpleNull - Test - Lifecycle event - create_Simple_SimpleNullHome_Impl\n"));
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();

    ACE_NEW_RETURN (
      retval,
      SimpleNullHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());

    return retval;
  }
}

