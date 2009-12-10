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
//    Visitor generating code for CDR operators for interfaces. This uses
//    compiled marshaling.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_interface,
           cdr_op_ch,
           "$Id$")

// ***************************************************************************
// Interface visitor for generating CDR operator declarations in the client header
// ***************************************************************************

be_visitor_interface_cdr_op_ch::be_visitor_interface_cdr_op_ch (
    be_visitor_context *ctx
  )
  : be_visitor_interface (ctx)
{
}

be_visitor_interface_cdr_op_ch::~be_visitor_interface_cdr_op_ch (void)
{
}

int
be_visitor_interface_cdr_op_ch::visit_interface (be_interface *node)
{
  // No CDR operations for locality constraint interfaces.
  if (node->cli_hdr_cdr_op_gen ()
      || node->imported ()
      || node->is_local ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl;

  *os << be_global->core_versioning_begin () << be_nl;

  // Generate the CDR << and >> operator declarations.
  *os << be_global->stub_export_macro () << " ::CORBA::Boolean "
      << "operator<< (TAO_OutputCDR &, const " << node->full_name ()
      << "_ptr );" << be_nl;
  *os << be_global->stub_export_macro () << " ::CORBA::Boolean "
      << "operator>> (TAO_InputCDR &, "
      << node->full_name () << "_ptr &);" << be_nl;

  if (be_global->gen_ostream_operators ())
    {
      *os << be_global->stub_export_macro () << " std::ostream&"
          << " operator<< (std::ostream &strm, const "
          << node->full_name () << "_ptr);" << be_nl;
    }

  *os << be_global->core_versioning_end () << be_nl;

  // Set the substate as generating code for the types defined in our scope.
  this->ctx_->sub_state (TAO_CodeGen::TAO_CDR_SCOPE);

  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_interface_cdr_op_ch::"
                         "visit_interface - "
                         "codegen for scope failed\n"),
                        -1);
    }

  this->ctx_->sub_state (TAO_CodeGen::TAO_SUB_STATE_UNKNOWN);
  node->cli_hdr_cdr_op_gen (1);
  return 0;
}
