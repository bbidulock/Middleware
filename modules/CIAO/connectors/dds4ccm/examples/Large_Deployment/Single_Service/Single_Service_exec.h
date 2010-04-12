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

#ifndef CIAO_SINGLE_SERVICE_EXEC_AZRZEB_H_
#define CIAO_SINGLE_SERVICE_EXEC_AZRZEB_H_

#include /**/ "ace/pre.h"

#include "Single_ServiceEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Single_Service_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Single_Service_Impl
{
  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exh.cpp:53
  
  class SINGLE_SERVICE_EXEC_Export Simple_Service_exec_i
    : public virtual ::CCM_Simple_Service,
      public virtual ::CORBA::LocalObject
  {
  public:
    Simple_Service_exec_i (void);
    virtual ~Simple_Service_exec_i (void);
    
    // Operations and attributes from ::Simple_Service
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:37
    
    virtual void
    ping (void);
  };
  
  class SINGLE_SERVICE_EXEC_Export Single_Service_exec_i
    : public virtual Single_Service_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Single_Service_exec_i (void);
    virtual ~Single_Service_exec_i (void);
    
    //@{
    /** Supported operations and attributes. */
    
    //@}
    
    //@{
    /** Component attributes and port operations. */
    
    
    virtual ::CCM_Simple_Service_ptr
    get_ping_port (void);
    //@}
    
    //@{
    /** Operations from Components::SessionComponent. */
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}
    
  
  private:
    ::CCM_Single_Service_Context_var context_;
  };
  
  extern "C" SINGLE_SERVICE_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Single_Service_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

