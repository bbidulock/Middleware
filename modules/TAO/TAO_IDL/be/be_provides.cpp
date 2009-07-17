// $Id$

#include "be_provides.h"
#include "be_interface.h"
#include "be_visitor.h"

be_provides::be_provides (UTL_ScopedName *n,
                          be_interface *provides_type)
  : COMMON_Base (),
    AST_Decl (AST_Decl::NT_provides,
              n),
    AST_Field (AST_Decl::NT_provides,
               provides_type,
               n),
    AST_Provides (n,
                  provides_type),
    be_decl (AST_Decl::NT_provides,
             n)
{
}

be_provides::~be_provides (void)
{
}

int
be_provides::accept (be_visitor *visitor)
{
  return visitor->visit_provides (this);
}

void
be_provides::destroy (void)
{
  this->AST_Provides::destroy ();
  this->be_decl::destroy ();
}

IMPL_NARROW_FROM_DECL(be_provides)
