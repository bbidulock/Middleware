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

#ifndef CIAO_NULL_COMPONENT_EXEC_H
#define CIAO_NULL_COMPONENT_EXEC_H

#include /**/ "ace/pre.h"

#include "Null_Component_svnt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Null_Component_exec_export.h"
#include "tao/LocalObject.h"

namespace CIDL_Null_Component_Impl
{
  class NULL_COMPONENT_EXEC_Export Null_Interface_exec_i
    : public virtual ::CCM_Null_Interface,
      public virtual TAO_Local_RefCounted_Object
  {
    public:
    Null_Interface_exec_i (void);
    virtual ~Null_Interface_exec_i (void);

    // Operations from ::Null_Interface

    virtual void
    null_operation ();
  };

  class NULL_COMPONENT_EXEC_Export Null_Component_exec_i
    : public virtual Null_Component_Exec,
      public virtual TAO_Local_RefCounted_Object
  {
    public:
    Null_Component_exec_i (void);
    virtual ~Null_Component_exec_i (void);

    // Supported or inherited operations.

    // Attribute operations.

    // Port operations.

    virtual ::CCM_Null_Interface_ptr get_null_facet ();

    // Operations from Components::SessionComponent

    virtual void
    set_session_context (::Components::SessionContext_ptr ctx);

    virtual void
    ciao_preactivate ();

    virtual void
    ciao_postactivate ();

    virtual void
    ccm_activate ();

    virtual void
    ccm_passivate ();

    virtual void
    ccm_remove ();

    protected:
    Null_Component_Context *context_;
  };

  class NULL_COMPONENT_EXEC_Export Null_Component_Home_exec_i
    : public virtual Null_Component_Home_Exec,
      public virtual TAO_Local_RefCounted_Object
  {
    public:
    Null_Component_Home_exec_i (void);
    virtual ~Null_Component_Home_exec_i (void);

    // Supported or inherited operations.

    // Home operations.

    // Factory and finder operations.

    // Attribute operations.

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create ();
  };

  extern "C" NULL_COMPONENT_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Null_Component_Home_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* CIAO_NULL_COMPONENT_EXEC_H */

