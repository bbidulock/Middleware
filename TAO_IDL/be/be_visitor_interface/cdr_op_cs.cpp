//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    cdr_op_cs.cpp
//
// = DESCRIPTION
//    Visitor generating code for CDR operators for interfaces
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include "idl.h"
#include "idl_extern.h"
#include "be.h"

#include "be_visitor_interface.h"

ACE_RCSID(be_visitor_interface, cdr_op_cs, "$Id$")

be_visitor_interface_cdr_op_cs::be_visitor_interface_cdr_op_cs
(be_visitor_context *ctx)
  : be_visitor_interface (ctx)
{
}

be_visitor_interface_cdr_op_cs::~be_visitor_interface_cdr_op_cs (void)
{
}

int
be_visitor_interface_cdr_op_cs::visit_interface (be_interface *node)
{
  // No CDR operations for locality constraint interfaces.
  if (idl_global->gen_locality_constraint ())
    return 0;

  // already generated and/or we are imported. Don't do anything.
  if (node->cli_stub_cdr_op_gen () || node->imported ())
    return 0;

  int i;
  int to_do;

  // Decide how much code to produce
  if (idl_global->ami_call_back () == I_TRUE)
    to_do = 2;
  else
    to_do = 1;
  be_interface_type_strategy *old_strategy = 0;

  for (i = 0; i < to_do; i++)
    {
      switch (i)
        {
        case 0:
          break;
        case 1:
          old_strategy =
            node->set_strategy (new be_interface_ami_handler_strategy (node));
          break;
        default:
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_interface_cdr_op_cs::visit_interface - "
                             "codegen failed - invalid state\n"), -1);
        }

      // set the substate as generating code for the types defined in our scope
      this->ctx_->sub_state(TAO_CodeGen::TAO_CDR_SCOPE);
      // all we have to do is to visit the scope and generate code
      if (this->visit_scope (node) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_interface_cdr_op_cs::"
                             "visit_interface - "
                             "codegen for scope failed\n"), -1);
        }

      node->cli_stub_cdr_op_gen (1);

      switch (i)
        {
        case 0:
          break;
        case 1:
          delete node->set_strategy (old_strategy);
          break;
        default:
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_interface_cdr_op_cs::visit_interface - "
                             "codegen failed - invalid state\n"), -1);
        }
    } // for 

  return 0;
}
