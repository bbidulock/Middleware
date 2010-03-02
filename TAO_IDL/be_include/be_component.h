/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    be_component.h
 *
 *  $Id$
 *
 *  Extension of class AST_Component that provides additional means for C++
 *  mapping of an interface.
 *
 *
 *  @author Jeff Parsons
 */
//=============================================================================


#ifndef TAO_BE_COMPONENT_H
#define TAO_BE_COMPONENT_H

#include "be_interface.h"
#include "ast_component.h"

class be_component : public virtual AST_Component,
                     public virtual be_interface
{
  // = TITLE
  //   The back end extension of the AST_Component class
  //
  // = DESCRIPTION
  //
public:
  be_component (UTL_ScopedName *n,
                AST_Component *base_component,
                AST_Type **supports,
                long n_supports,
                AST_Interface **supports_flat,
                long n_supports_flat);

  ~be_component (void);
  
  /// Override of the AST method to eliminate narrowing of
  /// the return value. Non-virtual.
  be_component *base_component (void) const;

  /// Catch BE-specific members before delegating to the base class.
  virtual void redefine (AST_Interface *from);

  /// Cleanup function.
  virtual void destroy (void);

  /// Visiting.
  virtual int accept (be_visitor *visitor);

  // Need for public access to fe_add_structure and fe_add_typedef,
  // used to add implied IDL nodes created for 'uses multiple' declarations.
  AST_Structure *be_add_structure (AST_Structure *t);
  AST_Typedef *be_add_typedef (AST_Typedef *t);

  // Narrowing.

  DEF_NARROW_FROM_DECL (be_component);
  DEF_NARROW_FROM_SCOPE (be_component);
};

#endif  // if !defined
