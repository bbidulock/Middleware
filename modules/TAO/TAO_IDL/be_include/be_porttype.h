//
// $Id$
//

/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO_IDL_BE
//
// = FILENAME
//    be_porttype.h
//
// = DESCRIPTION
//    Extension of class AST_PortType for C++ code generation.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

#ifndef BE_PORTTYPE_H
#define BE_PORTTYPE_H

#include "ast_porttype.h"

#include "be_scope.h"
#include "be_type.h"

class be_visitor;

class be_porttype : public virtual AST_PortType,
                    public virtual be_scope,
                    public virtual be_type
{
  //
  // = TITLE
  //   be_porttype
  //
  // = DESCRIPTION
  //   Extension of class AST_PortType for C++ code generation.
  //
public:
  be_porttype (UTL_ScopedName *n);
    
  virtual ~be_porttype (void);
  
  virtual void destroy (void);
  
  virtual int accept (be_visitor *visitor);

  DEF_NARROW_FROM_DECL (be_porttype);
  DEF_NARROW_FROM_SCOPE (be_porttype);
};

#endif // BE_PORTTYPE_H
