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

#ifndef CIAO_SIMPLEPROVIDER_EXEC_H
#define CIAO_SIMPLEPROVIDER_EXEC_H

#include /**/ "ace/pre.h"

#include "SimpleProviderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "SimpleProvider_exec_export.h"
#include "tao/LocalObject.h"

namespace CIDL_SimpleProvider_Impl
{
  class SIMPLEPROVIDER_EXEC_Export Trigger_exec_i
    : public virtual ::Simple::CCM_Trigger,
      public virtual ::CORBA::LocalObject
  {
    public:
    Trigger_exec_i (void);
    virtual ~Trigger_exec_i (void);

    // Operations from ::Simple::Trigger

    virtual void
    hello (
      const char * hello);
  };

  class SIMPLEPROVIDER_EXEC_Export SimpleProvider_exec_i
    : public virtual SimpleProvider_Exec,
      public virtual ::CORBA::LocalObject
  {
    public:
    SimpleProvider_exec_i (void);
    virtual ~SimpleProvider_exec_i (void);

    // Supported or inherited operations.

    // Attribute operations.

    // Port operations.

    virtual ::Simple::CCM_Trigger_ptr
    get_trig ();

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);

    virtual void configuration_complete ();

    virtual void ccm_activate ();

    virtual void ccm_passivate ();

    virtual void ccm_remove ();

    private:
    ::Simple::CCM_SimpleProvider_Context_var context_;
  };

  class SIMPLEPROVIDER_EXEC_Export SimpleProviderHome_exec_i
    : public virtual SimpleProviderHome_Exec,
      public virtual ::CORBA::LocalObject
  {
    public:
    SimpleProviderHome_exec_i (void);
    virtual ~SimpleProviderHome_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" SIMPLEPROVIDER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Simple_SimpleProviderHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_SIMPLEPROVIDER_EXEC_H */

