// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
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
// be/be_codegen.cpp:1272

#ifndef CIAO_CIF_COMPONENT_EXEC_S44IH2_H_
#define CIAO_CIF_COMPONENT_EXEC_S44IH2_H_

#include "CIF_Component_exec_export.h"
#include "CIF_ComponentEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"

namespace CIAO_CIF_CIF_Provider_Impl
{
  
  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exh.cpp:53
  class  provide_cif_foo_exec_i
    : public virtual ::CIF::CCM_foo,
      public virtual ::CORBA::LocalObject
  {
  public:
    provide_cif_foo_exec_i (
      ::CIF::CCM_CIF_Provider_Context_ptr ctx);
    virtual ~provide_cif_foo_exec_i (void);
    
    // Operations and attributes from ::CIF::foo
    
    virtual
    void do_foo (void);
  
  private:
    ::CIF::CCM_CIF_Provider_Context_var ciao_context_;
  };
  
  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exh.cpp:53
  class  provide_cif_inherited_foo_exec_i
    : public virtual ::CIF::CCM_inherited_foo,
      public virtual ::CORBA::LocalObject
  {
  public:
    provide_cif_inherited_foo_exec_i (
      ::CIF::CCM_CIF_Provider_Context_ptr ctx);
    virtual ~provide_cif_inherited_foo_exec_i (void);
    
    // Operations and attributes from ::CIF::inherited_foo
    
    virtual
    void do_inherited_foo (void);
    
    virtual
    void do_foo (void);
  
  private:
    ::CIF::CCM_CIF_Provider_Context_var ciao_context_;
  };
  
  class  CIF_Provider_exec_i
    : public virtual CIF_Provider_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    CIF_Provider_exec_i (void);
    virtual ~CIF_Provider_exec_i (void);
    
    //@{
    /** Supported operations and attributes. */
    
    //@}
    
    //@{
    /** Component attributes and port operations. */
    
    
    virtual ::CIF::CCM_foo_ptr
    get_provide_cif_foo (void);
    
    virtual ::CIF::CCM_inherited_foo_ptr
    get_provide_cif_inherited_foo (void);
    //@}
    
    //@{
    /** Operations from Components::SessionComponent. */
    
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}
  
  private:
    ::CIF::CCM_CIF_Provider_Context_var ciao_context_;
    ::CIF::CCM_foo_var ciao_provide_cif_foo_;
    ::CIF::CCM_inherited_foo_var ciao_provide_cif_inherited_foo_;
  };
  
  extern "C" CIF_COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CIF_CIF_Provider_Impl (void);
}

namespace CIAO_CIF_CIF_User_Impl
{
  
  class  CIF_User_exec_i
    : public virtual CIF_User_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    CIF_User_exec_i (void);
    virtual ~CIF_User_exec_i (void);
    
    //@{
    /** Supported operations and attributes. */
    
    //@}
    
    //@{
    /** Component attributes and port operations. */
    
    //@}
    
    //@{
    /** Operations from Components::SessionComponent. */
    
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}
  
  private:
    ::CIF::CCM_CIF_User_Context_var ciao_context_;
  };
  
  extern "C" CIF_COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CIF_CIF_User_Impl (void);
}

#endif /* ifndef */
