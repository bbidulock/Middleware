// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.7
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

// TAO_IDL - Generated from
// be/be_codegen.cpp:1216

#ifndef CIAO_PROGRESSIVE_EXEC_0BRVI0_H_
#define CIAO_PROGRESSIVE_EXEC_0BRVI0_H_

#include /**/ "ace/pre.h"

#include "ProgressiveEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Progressive_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Simple_Progressive_Impl
{
  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exh.cpp:53

  class PROGRESSIVE_EXEC_Export Trigger_exec_i
    : public virtual ::Simple::CCM_Trigger,
      public virtual ::CORBA::LocalObject
  {
  public:
    Trigger_exec_i (bool &,
                    ::Simple::CCM_Progressive_Context_ptr);
    virtual ~Trigger_exec_i (void);

    // Operations and attributes from ::Simple::Trigger

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:37

    virtual void
    hello (
      const char * hello);

  private:
    bool &triggered_;
    ::Simple::CCM_Progressive_Context_ptr context_;
  };

  class PROGRESSIVE_EXEC_Export Progressive_exec_i
    : public virtual Progressive_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Progressive_exec_i (void);
    virtual ~Progressive_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */


    virtual ::Simple::CCM_Trigger_ptr
    get_trig_in (void);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void
    set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}


  private:
    ::Simple::CCM_Progressive_Context_var context_;
    bool triggered_;
  };

  extern "C" PROGRESSIVE_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Simple_Progressive_Impl (void);
}

namespace CIAO_Simple_Progressive_Impl
{
  class PROGRESSIVE_EXEC_Export ProgressiveHome_exec_i
    : public virtual ProgressiveHome_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    ProgressiveHome_exec_i (void);

    virtual ~ProgressiveHome_exec_i (void);

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };

  extern "C" PROGRESSIVE_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Simple_ProgressiveHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
