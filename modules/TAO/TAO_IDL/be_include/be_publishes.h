// -*- C++ -*-
// $Id$

#ifndef BE_PUBLISHES_H
#define BE_PUBLISHES_H

#include "ast_publishes.h"

#include "be_decl.h"

class be_eventtype;
class be_visitor;

class be_publishes : public virtual AST_Publishes,
                     public virtual be_decl
{
public:
  be_publishes (UTL_ScopedName *n,
                be_eventtype *publishes_type);
            
  virtual ~be_publishes (void);
  
  // Narrowing.
  DEF_NARROW_FROM_DECL(be_publishes);

  // Visiting.
  virtual int accept (be_visitor *visitor);
  
  // Cleanup.
  virtual void destroy (void);
};

#endif // BE_PUBLISHES_H

