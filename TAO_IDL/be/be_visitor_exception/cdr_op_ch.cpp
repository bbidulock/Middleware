//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    cdr_op_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for CDR operators for exceptions. This uses
//    compiled marshaling.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include	"idl.h"
#include	"idl_extern.h"
#include	"be.h"

#include "be_visitor_exception.h"

ACE_RCSID(be_visitor_exception, cdr_op_ch, "$Id$")

// ***************************************************************************
// Exception visitor for generating CDR operator declarations in the client header
// ***************************************************************************

be_visitor_exception_cdr_op_ch::be_visitor_exception_cdr_op_ch
(be_visitor_context *ctx)
  : be_visitor_exception (ctx)
{
}

be_visitor_exception_cdr_op_ch::~be_visitor_exception_cdr_op_ch (void)
{
}

int
be_visitor_exception_cdr_op_ch::visit_exception (be_exception *node)
{
  if (node->cli_hdr_cdr_op_gen () || node->imported ())
    return 0;

  TAO_OutStream *os = this->ctx_->stream ();

  // generate the CDR << and >> operator declarations
  os->indent ();
  *os << idl_global->stub_export_macro () << " CORBA::Boolean"
      << " operator<< (TAO_OutputCDR &, const " << node->name ()
      << " &);" << be_nl;
  *os << idl_global->stub_export_macro () << " CORBA::Boolean"
      << " operator>> (TAO_InputCDR &, "
      << node->name () << " &);\n";


  // set the substate as generating code for the types defined in our scope
  this->ctx_->sub_state(TAO_CodeGen::TAO_CDR_SCOPE);
  // all we have to do is to visit the scope and generate code
  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_exception_cdr_op_ch::"
                         "visit_exception - "
                         "codegen for scope failed\n"), -1);
    }

  *os << be_nl;

  // Generate the iostream operator overload for this exception.
  node->gen_iostream_op_hdr (os);

  node->cli_hdr_cdr_op_gen (1);
  return 0;
}
