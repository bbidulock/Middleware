// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2.3
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
#ifndef CIAO__________TUTORIAL_CODE_SHAPES_SENDER_COMP_SHAPES_SENDER_COMP_EXEC_V6KYIS_H_
#define CIAO__________TUTORIAL_CODE_SHAPES_SENDER_COMP_SHAPES_SENDER_COMP_EXEC_V6KYIS_H_

#include /**/ "ace/pre.h"

#include "Shapes_Sender_compEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Shapes_Sender_comp_exec_export.h"
#include "tao/LocalObject.h"

/// Namespace for implementation of Shapes::Sender_comp component
namespace CIAO_Shapes_Sender_comp_Impl
{

  ///  Executor implementation class for control facet
  class control_exec_i
    : public virtual ::Shapes::CCM_Control_obj,
      public virtual ::CORBA::LocalObject
  {
  public:
    /// Constructor
    /// @param[in] ctx - Container context
    control_exec_i (
      ::Shapes::CCM_Sender_comp_Context_ptr ctx);
    /// Destructor
    virtual ~control_exec_i (void);

    /** @name Operations and attributes from Shapes::Control_obj */
    //@{

    virtual
    ::Shapes::ReturnStatus setSize (
      ::CORBA::UShort size);

    virtual
    ::Shapes::ReturnStatus setLocation (
      ::CORBA::UShort x,
      ::CORBA::UShort y);
    //@}

  private:
    /// Context for component instance. Used for all middleware communication.
    ::Shapes::CCM_Sender_comp_Context_var ciao_context_;
  };

  /// Component Executor Implementation Class: Sender_comp_exec_i
  class Sender_comp_exec_i
    : public virtual Sender_comp_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    /// Constructor
    Sender_comp_exec_i (void);
    /// Destructor
    virtual ~Sender_comp_exec_i (void);

    /** @name Supported operations and attributes. */
    //@{

    //@}

    /** @name Component attributes and port operations. */
    //@{

    /// Factory method and getter for control facet
    /// @return existing instance of facet if one exists, else creates one
    virtual ::Shapes::CCM_Control_obj_ptr
    get_control (void);
    //@}

    /** @name Session component operations */
    //@{

    /// Setter for container context for this component
    /// @param[in] ctx - Container context
    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    /// Component state change method to configuration_complete state
    virtual void configuration_complete (void);

    /// Component state change method to activated state
    virtual void ccm_activate (void);

    /// Component state change method to passivated state
    virtual void ccm_passivate (void);

    /// Component state change method to removed state
    virtual void ccm_remove (void);
    //@}

    /** @name User defined public operations. */
    //@{

    //@}

  private:
    /// Context for component instance. Used for all middleware communication
    ::Shapes::CCM_Sender_comp_Context_var ciao_context_;

    /** @name Component attributes. */
    //@{
    //@}

    /** @name Component facets. */
    //@{

    /// Object reference to control facet
    ::Shapes::CCM_Control_obj_var ciao_control_;
    //@}

    /** @name User defined members. */
    //@{

    //@}

    /** @name User defined private operations. */
    //@{

    //@}
  };

  /// Factory method and library entry point used by the middleware
  /// @return new component instance
  extern "C" SHAPES_SENDER_COMP_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shapes_Sender_comp_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
