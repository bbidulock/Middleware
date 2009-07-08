// $Id$

#include "be_porttype.h"
#include "be_visitor.h"

ACE_RCSID (be,
           be_porttype,
           "$Id$")

be_porttype::be_porttype (
      UTL_ScopedName *n,
      const FE_Utils::T_PARAMLIST_INFO *template_params)
  : COMMON_Base (false,
                 false),
    AST_Decl (AST_Decl::NT_porttype,
              n),
    AST_PortType (n,
                  template_params)
{
}

be_porttype::~be_porttype (void)
{
}

void
be_porttype::destroy (void)
{
  this->AST_PortType::destroy ();
}

int
be_porttype::accept (be_visitor *visitor)
{
  return visitor->visit_porttype (this);
}
