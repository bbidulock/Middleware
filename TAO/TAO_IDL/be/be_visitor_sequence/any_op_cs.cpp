//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    any_op_cs.cpp
//
// = DESCRIPTION
//    Visitor generating code for Any operator for the Sequence node
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_sequence, 
           any_op_cs, 
           "$Id$")

// ***************************************************************************
// Sequence visitor for generating Any operator declarations in the client
// stubs file
// ***************************************************************************

be_visitor_sequence_any_op_cs::be_visitor_sequence_any_op_cs (
    be_visitor_context *ctx
  )
  : be_visitor_decl (ctx)
{
}

be_visitor_sequence_any_op_cs::~be_visitor_sequence_any_op_cs (void)
{
}

int
be_visitor_sequence_any_op_cs::visit_sequence (be_sequence *node)
{
  if (node->cli_stub_any_op_gen ()
      || node->imported ())
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  *os << be_nl << be_nl 
      << "// TAO_IDL - Generated from " << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  // Copying insertion.
  *os << "// Copying insertion." << be_nl
      << "void operator<<= (" << be_idt << be_idt_nl
      << "CORBA::Any &_tao_any," << be_nl
      << "const " << node->name () << " &_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "TAO::Any_Dual_Impl_T<" << node->name () << ">::insert_copy ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->name () << "::_tao_any_destructor," << be_nl
      << node->tc_name () << "," << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Non-copying insertion.
  *os << "// Non-copying insertion." << be_nl
      << "void operator<<= (" << be_idt << be_idt_nl
      << "CORBA::Any &_tao_any," << be_nl
      << node->name () << " *_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "TAO::Any_Dual_Impl_T<" << node->name () << ">::insert ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->name () << "::_tao_any_destructor," << be_nl
      << node->tc_name () << "," << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Extraction to non-const pointer (deprecated, just calls the other).
  *os << "// Extraction to non-const pointer (deprecated)." << be_nl
      << "CORBA::Boolean operator>>= (" << be_idt << be_idt_nl
      << "const CORBA::Any &_tao_any," << be_nl
      << node->name () << " *&_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "return _tao_any >>= ACE_const_cast (" << be_idt << be_idt_nl
      << "const " << node->name () << " *&," << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "}" << be_nl << be_nl;

  // Extraction to const pointer.
  *os << "// Extraction to const pointer." << be_nl
      << "CORBA::Boolean operator>>= (" << be_idt << be_idt_nl
      << "const CORBA::Any &_tao_any," << be_nl
      << "const " << node->name () << " *&_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "return" << be_idt_nl
      << "TAO::Any_Dual_Impl_T<" << node->name () << ">::extract ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->name () << "::_tao_any_destructor," << be_nl
      << node->tc_name () << "," << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt << be_uidt_nl
      << "}";

  // Since we don't generate CDR stream operators for types that
  // explicitly contain a local interface (at some level), we 
  // must override these Any template class methods to avoid
  // calling the non-existent operators. The zero return value
  // will eventually cause CORBA::MARSHAL to be raised if this
  // type is inserted into an Any and then marshaled.
  if (node->is_local ())
    {
      TAO_OutStream *os = this->ctx_->stream ();

      *os << be_nl << be_nl
          << "ACE_TEMPLATE_SPECIALIZATION" << be_nl
          << "CORBA::Boolean" << be_nl
          << "TAO::Any_Dual_Impl_T<" << node->name ()
          << ">::marshal_value (TAO_OutputCDR &)" << be_nl
          << "{" << be_idt_nl
          << "return 0;" << be_uidt_nl
          << "}";

      *os << be_nl << be_nl
          << "ACE_TEMPLATE_SPECIALIZATION" << be_nl
          << "CORBA::Boolean" << be_nl
          << "TAO::Any_Dual_Impl_T<" << node->name ()
          << ">::demarshal_value (TAO_InputCDR &)" << be_nl
          << "{" << be_idt_nl
          << "return 0;" << be_uidt_nl
          << "}";
    }

  node->cli_stub_any_op_gen (1);
  return 0;
}
