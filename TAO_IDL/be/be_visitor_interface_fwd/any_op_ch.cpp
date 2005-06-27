//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    any_op_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for Any operators for a forward declared interface
//    in the client header.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

ACE_RCSID (be_visitor_interface_fwd, 
           any_op_ch, 
           "$Id$")

// ***************************************************************************
// Generates Any operator declarations in the client header
// ***************************************************************************

be_visitor_interface_fwd_any_op_ch::be_visitor_interface_fwd_any_op_ch (
    be_visitor_context *ctx
  )
  : be_visitor_decl (ctx)
{
}

be_visitor_interface_fwd_any_op_ch::~be_visitor_interface_fwd_any_op_ch (void)
{
}

int
be_visitor_interface_fwd_any_op_ch::visit_interface_fwd (be_interface_fwd *node)
{
  AST_Interface *fd = node->full_definition ();

  // Only a forward declared interface that is not defined in the same file
  // needs to have this generated here. The Any operators are needed by
  // portable interceptor code if the interface is a parameter of an operation.
  if (fd->is_defined () != 0 || node->is_local ())
    {
      return 0;
    }

  if (node->cli_hdr_any_op_gen ()
      || node->imported ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  be_module *module = 0;
 
  if (node->is_nested () &&
      node->defined_in ()->scope_node_type () == AST_Decl::NT_module)
    {
      module = be_module::narrow_from_scope (node->defined_in ());

      if (!module)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "be_visitor_interface_fwd_any_op_ch::"
                             "visit_interface_fwd - "
                             "Error parsing nested name\n"),
                            -1);
        }
      be_util::gen_nested_namespace_begin (os, module);
    }

  *os << be_global->stub_export_macro () << " void"
      << " operator<<= (CORBA::Any &, " << node->local_name ()
      << "_ptr); // copying" << be_nl;
  *os << be_global->stub_export_macro () << " void"
      << " operator<<= (CORBA::Any &, " << node->local_name ()
      << "_ptr *); // non-copying" << be_nl;
  *os << be_global->stub_export_macro () << " CORBA::Boolean"
      << " operator>>= (const CORBA::Any &, "
      << node->local_name () << " *&);";

  if (module != 0)
    {
      be_util::gen_nested_namespace_end (os, module);
    }

  node->cli_hdr_any_op_gen (1);
  return 0;
}
