// -*- C++ -*-
//
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO_IDL_BE
//
// = FILENAME
//    be_template_module.h
//
// = DESCRIPTION
//    Extension of class AST_Template_Module that provides additional means for C++
//    mapping of a module.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

#ifndef TAO_BE_TEMPLATE_MODULE_H
#define TAO_BE_TEMPLATE_MODULE_H

#include "be_scope.h"
#include "be_decl.h"

#include "ast_template_module.h"

class be_template_module : public virtual AST_Template_Module,
                           public virtual be_scope,
                           public virtual be_decl
{
  // = TITLE
  //   The back end extension of the AST_Template_Module class
  //
  // = DESCRIPTION
  //
public:
  be_template_module (
    UTL_ScopedName *n,
    FE_Utils::T_PARAMLIST_INFO *template_params);

  virtual ~be_template_module (void);

  virtual void destroy (void);

  virtual int accept (be_visitor *visitor);

  DEF_NARROW_FROM_DECL (be_template_module);
  DEF_NARROW_FROM_SCOPE (be_template_module);
};

#endif /* TAO_BE_TEMPLATE_MODULE_H */

