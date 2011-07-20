
//=============================================================================
/**
 *  @file    any_op_cs.cpp
 *
 *  $Id$
 *
 *  Visitor generating code for Any operator for the Sequence node
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================

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
      || node->imported ()
      || (node->is_local ()
          && !be_global->gen_local_iface_anyops ()))
    {
      return 0;
    }

  AST_Type *bt = node->base_type ()->unaliased_type ();
  AST_String *str = AST_String::narrow_from_decl (bt);
  
  // Generating sequences as typedefs of std::vector classes
  // means that unbounded sequences with the same element type
  // are not unique types to the C++ compiler. String sequences
  // are a common problem, so we check for an inclusion and skip
  // the operator definition if found.
  if (str != 0 && str->width () == 1 && idl_global->imported_string_seq_seen_)
    {
      return 0;
    }

  TAO_OutStream *os = this->ctx_->stream ();

  *os << be_nl_2
      << "// TAO_IDL - Generated from " << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl_2;

  *os << be_global->core_versioning_begin () << be_nl;

  // These are no-ops for now, so we just generate them and return
  if (be_global->alt_mapping () && node->max_size ()->ev ()->u.ulval == 0)
    {
      enum type_category
      {
        ANY_VALUE,
        ANY_OBJREF,
        ANY_ARRAY,
        ANY_STRING
      };

      type_category tc = ANY_VALUE;
      AST_Decl::NodeType nt = bt->node_type ();
      
      if (nt == AST_Decl::NT_array)
        {
          tc = ANY_ARRAY;
        }
      else if ((be_interface::narrow_from_decl (bt) != 0
                && be_valuetype::narrow_from_decl (bt) == 0)
               || (be_interface_fwd::narrow_from_decl (bt) != 0
                   && be_valuetype_fwd::narrow_from_decl (bt) == 0))
        {
          tc = ANY_OBJREF;
        }
      else if (nt == AST_Decl::NT_string)
        {
          tc = ANY_STRING;
        }
        
      if (bt->node_type () == AST_Decl::NT_pre_defined)
        {
          AST_PredefinedType *pdt =
            AST_PredefinedType::narrow_from_decl (bt);
            
          if (pdt->pt () == AST_PredefinedType::PT_pseudo)
            {
              ACE_CString lname (
                bt->local_name ()->get_string ());
                
              if (lname == "TypeCode")
                {
                  tc = ANY_OBJREF;
                }
            }
        }
        
      // The guard should be generated to prevent multiple declarations,
      // since a sequence of a given element type may be typedef'd
      // more than once.

      os->gen_ifdef_macro (bt->flat_name (), "seq_any_op_cs", false);

      *os << be_nl_2
          << "void operator<<= (" << be_idt_nl
          << "::CORBA::Any &_tao_any," << be_nl
          << "const " << node->name  ()
          << " &_tao_elem)" << be_uidt_nl
          << "{" << be_idt_nl
          << "TAO::";

      switch (tc)
        {
        case ANY_OBJREF:
          *os << "insert_objref_vector<"
              << bt->full_name () << "_ptr> (";
 
          break;
        case ANY_ARRAY:
          *os << "insert_array_vector<"
              << bt->full_name () << "_forany> (";

          break;
        case ANY_STRING:
          *os << "insert_value_vector<std::string> (";
          break;
        default:
          *os << "insert_value_vector<"
              << bt->full_name () << "> (";
 
          break;
        }

      *os << be_idt_nl
          << "_tao_any," << be_nl
          << "_tao_elem);" << be_uidt << be_uidt_nl
          << "}";

      *os << be_nl_2
          << "::CORBA::Boolean operator>>= (" << be_idt_nl
          << "const ::CORBA::Any &_tao_any," << be_nl
          << node->name () << " &_tao_elem)" << be_uidt_nl
          << "{" << be_idt_nl
          << "return" << be_idt_nl
          << "TAO::";

      switch (tc)
        {
        case ANY_OBJREF:
          *os << "extract_objref_vector<"
              << bt->full_name () << "_ptr> (";

          break;
        case ANY_ARRAY:
          *os << "extract_array_vector<"
              << bt->full_name () << "_forany> (";

          break;
        case ANY_STRING:
          *os << "extract_value_vector<std::string> (";
          break;
        default:
          *os << "extract_value_vector<"
              << bt->full_name () << "> (";

          break;
        }

      *os << be_idt_nl
          << "_tao_any," << be_nl
          << "_tao_elem);" << be_uidt << be_uidt << be_uidt_nl
          << "}";

      os->gen_endif ();

      *os << be_nl
          << be_global->core_versioning_end () << be_nl;

      node->cli_stub_any_op_gen (true);
      return 0;
    }

  // Since we don't generate CDR stream operators for types that
  // explicitly contain a local interface (at some level), we
  // must override these Any template class methods to avoid
  // calling the non-existent operators. The zero return value
  // will eventually cause CORBA::MARSHAL to be raised if this
  // type is inserted into an Any and then marshaled.
  if (node->is_local ())
    {
      *os << "namespace TAO" << be_nl
          << "{" << be_idt_nl
          << "template<>" << be_nl
          << "::CORBA::Boolean" << be_nl
          << "Any_Dual_Impl_T<" << node->name ()
          << ">::marshal_value (TAO_OutputCDR &)" << be_nl
          << "{" << be_idt_nl
          << "return false;" << be_uidt_nl
          << "}";

      *os << be_nl_2
          << "template<>" << be_nl
          << "::CORBA::Boolean" << be_nl
          << "Any_Dual_Impl_T<" << node->name ()
          << ">::demarshal_value (TAO_InputCDR &)" << be_nl
          << "{" << be_idt_nl
          << "return false;" << be_uidt_nl
          << "}" << be_uidt_nl
          << "}" << be_nl;
    }

  *os << be_global->core_versioning_end () << be_nl;

  // If this is non-zero, we want to call its tc_name()
  // for the TypeCode to pass to the Any operator impls.
  be_typedef *td = this->ctx_->tdef ();

  be_module *module = 0;

  if (node->is_nested ())
    {
      AST_Decl *d = node;
      AST_Decl::NodeType nt = d->node_type ();

      while (nt != AST_Decl::NT_root)
        {
          if (nt == AST_Decl::NT_module)
            {
              module = be_module::narrow_from_decl (d);
              break;
            }
          else
            {
              d = ScopeAsDecl (d->defined_in ());
              nt = d->node_type ();
            }
        }

      if (module != 0)
        {
          // Some compilers handle "any" operators in a namespace
          // corresponding to their module, others do not.
          *os << "\n\n#if defined (ACE_ANY_OPS_USE_NAMESPACE)\n";

          be_util::gen_nested_namespace_begin (os, module);

          // The guard should be generated to prevent multiple declarations,
          // since a sequence of a given element type may be typedef'd
          // more than once.

          os->gen_ifdef_macro (bt->flat_name (), "any_op_cs", false);

          // Copying insertion.
          *os << be_nl_2
              << "// Copying insertion." << be_nl
              << "void operator<<= (" << be_idt << be_idt_nl
              << "::CORBA::Any &_tao_any," << be_nl
              << "const ::" << node->name () << " &_tao_elem" << be_uidt_nl
              << ")" << be_uidt_nl
              << "{" << be_idt_nl

              << "if (0 == &_tao_elem) // Trying to de-reference NULL object"
              << be_idt_nl
              << "_tao_any <<= static_cast< ::" << node->name ()
              << " *>( 0 ); // Use non-copying insertion of a NULL" << be_uidt_nl
              << "else" << be_idt_nl

              << "TAO::Any_Dual_Impl_T< ::" << node->name () << ">::insert_copy ("
              << be_idt << be_idt_nl
              << "_tao_any," << be_nl
              << "::" << node->name () << "::_tao_any_destructor," << be_nl
              << "::" << (td != 0 ? td->tc_name () : node->tc_name ()) << "," << be_nl
              << "_tao_elem" << be_uidt_nl
              << ");" << be_uidt << be_uidt << be_uidt_nl
              << "}" << be_nl_2;

          // Non-copying insertion.
          *os << "// Non-copying insertion." << be_nl
              << "void operator<<= (" << be_idt << be_idt_nl
              << "::CORBA::Any &_tao_any," << be_nl
              << "::" << node->name () << " *_tao_elem" << be_uidt_nl
              << ")" << be_uidt_nl
              << "{" << be_idt_nl
              << "TAO::Any_Dual_Impl_T< ::" << node->name () << ">::insert ("
              << be_idt << be_idt_nl
              << "_tao_any," << be_nl
              << "::" << node->name () << "::_tao_any_destructor," << be_nl
              << "::" << (td != 0 ? td->tc_name () : node->tc_name ()) << "," << be_nl
              << "_tao_elem" << be_uidt_nl
              << ");" << be_uidt << be_uidt_nl
              << "}" << be_nl_2;

          // Extraction to non-const pointer (deprecated, just calls the other).
          *os << "// Extraction to non-const pointer (deprecated)." << be_nl
              << "::CORBA::Boolean operator>>= (" << be_idt << be_idt_nl
              << "const ::CORBA::Any &_tao_any," << be_nl
              << "::" << node->name () << " *&_tao_elem" << be_uidt_nl
              << ")" << be_uidt_nl
              << "{" << be_idt_nl
              << "return _tao_any >>= const_cast<" << be_idt << be_idt_nl
              << "const ::" << node->name () << " *&> (" << be_nl
              << "_tao_elem" << be_uidt_nl
              << ");" << be_uidt << be_uidt_nl
              << "}" << be_nl_2;

          // Extraction to const pointer.
          *os << "// Extraction to const pointer." << be_nl
              << "::CORBA::Boolean operator>>= (" << be_idt << be_idt_nl
              << "const ::CORBA::Any &_tao_any," << be_nl
              << "const ::" << node->name () << " *&_tao_elem" << be_uidt_nl
              << ")" << be_uidt_nl
              << "{" << be_idt_nl
              << "return" << be_idt_nl
              << "TAO::Any_Dual_Impl_T< ::" << node->name () << ">::extract ("
              << be_idt << be_idt_nl
              << "_tao_any," << be_nl
              << "::"  <<  node->name () << "::_tao_any_destructor," << be_nl
              << "::" << (td != 0 ? td->tc_name () : node->tc_name ()) << "," << be_nl
              << "_tao_elem" << be_uidt_nl
              << ");" << be_uidt << be_uidt << be_uidt_nl
              << "}";

          os->gen_endif ();

          be_util::gen_nested_namespace_end (os, module);

          // Emit #else.
          *os << be_nl_2
              << "#else\n\n";
        }
    }

  *os << be_global->core_versioning_begin () << be_nl;

  // The guard should be generated to prevent multiple declarations,
  // since a sequence of a given element type may be typedef'd
  // more than once.

  os->gen_ifdef_macro (bt->flat_name (), "any_op_cs", false);

  // Copying insertion.
  *os << be_nl_2
      << "// Copying insertion." << be_nl
      << "void operator<<= (" << be_idt << be_idt_nl
      << "::CORBA::Any &_tao_any," << be_nl
      << "const " << node->name () << " &_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl

      << "if (0 == &_tao_elem) // Trying to de-reference NULL object"
      << be_idt_nl
      << "_tao_any <<= static_cast<" << node->name ()
      << " *>( 0 ); // Use non-copying insertion of a NULL" << be_uidt_nl
      << "else" << be_idt_nl

      << "TAO::Any_Dual_Impl_T<" << node->name () << ">::insert_copy ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->name () << "::_tao_any_destructor," << be_nl
      << (td != 0 ? td->tc_name () : node->tc_name ()) << "," << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt << be_uidt_nl
      << "}" << be_nl_2;

  // Non-copying insertion.
  *os << "// Non-copying insertion." << be_nl
      << "void operator<<= (" << be_idt << be_idt_nl
      << "::CORBA::Any &_tao_any," << be_nl
      << node->name () << " *_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "TAO::Any_Dual_Impl_T<" << node->name () << ">::insert ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->name () << "::_tao_any_destructor," << be_nl
      << (td != 0 ? td->tc_name () : node->tc_name ()) << "," << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "}" << be_nl_2;

  // Extraction to non-const pointer (deprecated, just calls the other).
  *os << "// Extraction to non-const pointer (deprecated)." << be_nl
      << "::CORBA::Boolean operator>>= (" << be_idt << be_idt_nl
      << "const ::CORBA::Any &_tao_any," << be_nl
      << node->name () << " *&_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "return _tao_any >>= const_cast<" << be_idt << be_idt_nl
      << "const " << node->name () << " *&> (" << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "}" << be_nl_2;

  // Extraction to const pointer.
  *os << "// Extraction to const pointer." << be_nl
      << "::CORBA::Boolean operator>>= (" << be_idt << be_idt_nl
      << "const ::CORBA::Any &_tao_any," << be_nl
      << "const " << node->name () << " *&_tao_elem" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "return" << be_idt_nl
      << "TAO::Any_Dual_Impl_T<" << node->name () << ">::extract ("
      << be_idt << be_idt_nl
      << "_tao_any," << be_nl
      << node->name () << "::_tao_any_destructor," << be_nl
      << (td != 0 ? td->tc_name () : node->tc_name ()) << "," << be_nl
      << "_tao_elem" << be_uidt_nl
      << ");" << be_uidt << be_uidt << be_uidt_nl
      << "}";

  os->gen_endif ();

  *os << be_global->core_versioning_end () << be_nl;

  if (module != 0)
    {
      *os << "\n\n#endif";
    }

  node->cli_stub_any_op_gen (true);
  return 0;
}
