// -*- C++ -*-
// $Id$

#include "Quoter_Connector_exec.h"

namespace CIAO_Quoter_Quoter_Connector_Impl
{
  Quoter_Connector_exec_i::Quoter_Connector_exec_i (void)
  {
  }

  Quoter_Connector_exec_i::~Quoter_Connector_exec_i (void)
  {
  }

  extern "C" QUOTER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Quoter_Connector_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Quoter_Connector_exec_i);

    return retval;
  }
}

