//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    valuetype_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for Valuetypes in the client header
//    (see C++ mapping OMG 20.17)
//
// = AUTHOR
//    Torsten Kuepper  <kuepper2@lfa.uni-wuppertal.de>,
//    based on interface_ch.cpp from Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_valuetype, 
           valuetype_ch, 
           "$Id$")

// ******************************************************
// Valuetype visitor for client header
// ******************************************************

be_visitor_valuetype_ch::be_visitor_valuetype_ch (be_visitor_context *ctx)
  : be_visitor_valuetype (ctx)
{
}

be_visitor_valuetype_ch::~be_visitor_valuetype_ch (void)
{
}

int
be_visitor_valuetype_ch::visit_valuetype (be_valuetype *node)
{
  if (node->cli_hdr_gen () || node->imported ())
    {
      return 0;
    }

  // This will be a no-op if it has alread by done by a forward
  // declaration.
  node->gen_var_out_seq_decls ();

  TAO_OutStream *os = this->ctx_->stream ();
  int status = 0;

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__;

  // Now the valuetype definition itself.
  os->gen_ifdef_macro (node->flat_name ());

  // Now generate the class definition.
  *os << be_nl << be_nl << "class " << be_global->stub_export_macro ()
      << " " << node->local_name ();

  // Node valuetype inherits from other valuetypes (OMG 20.17.9)
  // (ordinary (not abstract) interfaces ignored).

  *os << be_idt_nl <<": " << be_idt;

  long i;  // loop index
  be_valuetype *inherited = 0;
  long n_inherits = node->n_inherits ();
  int inherits_eventtype = 0;

  if (n_inherits > 0)
    {
      for (i = 0; i < n_inherits; ++i)
        {
          inherited =
            be_valuetype::narrow_from_decl (node->inherits ()[i]);

          if (inherited->node_type () == AST_Decl::NT_eventtype)
            {
              inherits_eventtype = 1;
            }

          if (i > 0)
            {
              *os << "," << be_nl;
            }

          be_decl *scope = 0;

          if (inherited->is_nested ())
            {
              // Inherited node is used in the scope of "node" node.
              scope =
                be_scope::narrow_from_scope (node->defined_in ())->decl ();
            }

          // Dump the scoped name.
          *os << "public virtual ";
          *os << inherited->nested_type_name (scope);
        }  // end of for loop
    }

  /***********************************************************************
  ** This is where we diverge for an ExceptionHolder ValueType.
  ** This is how we proceed:
  ** 1) Identify it is an AMH_ExceptionHolder class.
  ** 2) Inherit from CORBA::DefaultValueBaseRef i.e. provide a CONCRETE
  **    implementation for this ValueType!  This is because the alternative
  **    design of deriving a concrete-exception-holder class that the IDL
  **    compiler again has to generate is superflous, unnecessary, more
  **    coe bloat and unnecessary information for the app-programmer.  The
  **    changes required for this (n the *C.h file) are:
  **      2.1) Generate the raise_method as non-abstract and provide a
  **           definition in place
  **      2.2) Generate a new constructor that takes in a 
               CORBA::Exception*
  **      2.3) Make the destructor public (instead of protected) 
  **      2.4) Generate a private CORBA::Exception* field.
  **      2.5) Generate the tao_marshal and tao_unmarshal methods as 
  **           non-abstarct. 
  **      2.6) Generate the right throw spec for the AMH ExceptionHolders
  ************************************************************************/

  /****************************************************************/
  // 1) Find out if the ValueType is an AMH_*ExceptionHolder
  idl_bool is_an_amh_exception_holder = this->is_amh_exception_holder (node);

  if (is_an_amh_exception_holder)
    {
      if (n_inherits > 0)
        {
          *os << "," << be_nl;
        }

      *os << "public virtual CORBA::DefaultValueRefCountBase";
    }

  if (node->node_type () == AST_Decl::NT_eventtype)
    {
      if (inherits_eventtype == 0)
        {
          if (n_inherits > 0)
            {
              *os << "," << be_nl;
            }

          *os << "public virtual ::Components::EventBase";
        }
    }
  else if (n_inherits == 0)
    {
      if (is_an_amh_exception_holder)
        {
          *os << "," << be_nl;
        }

      *os << "public virtual CORBA::ValueBase";
    }
    
  // Generate the supported interfaces.  
  for (i = 0; i < node->n_supports (); ++i)
    {
      *os << "," << be_nl
          << "public virtual "
          << node->supports ()[i]->name ();
    }

  // Generate the body.
  *os << be_uidt << be_uidt_nl 
      << "{" << be_nl
      << "public:" << be_idt_nl
      << "typedef " << node->local_name () << "_var _var_type;" 
      << be_nl << be_nl;

  if (is_an_amh_exception_holder)
    {
      // Generate the constructor and destructor.
      *os << node->local_name () << " (CORBA::Exception *ex)" << be_idt_nl
          << ": exception (ex)" << be_uidt_nl
          << "{}" << be_nl << be_nl
          << "virtual ~" << node->local_name () << " (void);" 
          << be_nl << be_nl;
    }

  *os << "static " << node->local_name () << "* "
      << "_downcast (CORBA::ValueBase *);" << be_nl
      << be_nl
      << "// (TAO extensions or internals)" << be_nl
      << "static CORBA::Boolean _tao_unmarshal (" << be_idt << be_idt_nl
      << "TAO_InputCDR &," << be_nl
      << node->local_name () << " *&" << be_uidt_nl
      << ");" << be_uidt_nl << be_nl
      << "virtual const char* "
      << "_tao_obv_repository_id (void) const;"
      << be_nl << be_nl
      << "static const char* "
      << "_tao_obv_static_repository_id (void);" << be_nl << be_nl;

  if (be_global->any_support ())
    {
      *os << "static void _tao_any_destructor (void *);";
    }

  // Generate code for the valuetype definition.
  if (this->visit_valuetype_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_ch::"
                         "visit_valuetype - "
                         "codegen for scope failed\n"),
                        -1);
    }

  // Generate pure virtual declarations of the operations in our
  // supported interfaces.
  status =
    node->traverse_supports_list_graphs (
        be_visitor_valuetype_ch::gen_supported_ops,
        os,
        I_FALSE,
        I_TRUE
      );

  if (status == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_ch::"
                         "visit_valuetype - "
                         "traversal of supported interfaces failed\n"),
                        -1);
    }

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__;

  // If we inherit from CORBA::Object and/or CORBA::AbstractBase
  // (in addition to CORBA::ValueBase) we have to add these 
  // to avoid ambiguity.
  if (node->n_supports () > 0)
    {
      *os << be_uidt_nl << be_nl << "public:" << be_idt_nl;
      *os << be_nl << "virtual void _add_ref (void) = 0;" << be_nl;
      *os << "virtual void _remove_ref (void) = 0;" << be_nl;
      *os << "virtual CORBA::ValueBase *_tao_to_value (void);";
    }

  // Generate the "protected" constructor so that users cannot
  // instantiate us.
  *os << be_uidt_nl << be_nl << "protected:" << be_idt_nl
      << node->local_name ()
      << " (void);" << be_nl << be_nl;

  if (!is_an_amh_exception_holder)
    {
      *os << "virtual ~" << node->local_name () << " (void);" 
          << be_nl << be_nl;
    }

  // Support for marshalling.
  if (!node->is_abstract () && !is_an_amh_exception_holder)
    {
      *os << "virtual CORBA::Boolean "
          << "_tao_marshal_v (TAO_OutputCDR &);" << be_nl;
      *os << "virtual CORBA::Boolean "
          << "_tao_unmarshal_v (TAO_InputCDR &);" << be_nl;
    }

  if (is_an_amh_exception_holder)
    {
      *os << "virtual CORBA::Boolean "
          << "_tao_marshal_v (TAO_OutputCDR &) {return 1;}" << be_nl;
      *os << "virtual CORBA::Boolean "
          << "_tao_unmarshal_v (TAO_InputCDR &) {return 1;}" << be_nl;
    }


  // Private member:

  // Private copy constructor and assignment operator. These are not
  // allowed, hence they are private.
  *os << be_uidt_nl << "private:" << be_idt_nl;
  *os << node->local_name () << " (const " << node->local_name () << " &);"
      << be_nl
      << "void operator= (const " << node->local_name () << " &);"
      << be_nl;
  
  /*********************************************************/
  // 2.4
  if (is_an_amh_exception_holder)
    {
      *os << be_nl
          << "CORBA::Exception *exception;"
          << be_nl;
    }
  /*********************************************************/


  // Map fields to private data (if optimizing).
  if (node->opt_accessor ())
    {
      *os << be_uidt_nl << "protected:" << be_idt_nl;
      *os << "CORBA::Boolean "
          << "_tao_marshal_state (TAO_OutputCDR &);" << be_nl
          << "CORBA::Boolean "
          << "_tao_unmarshal_state (TAO_InputCDR &);"
          << be_uidt_nl << be_nl;
      *os << "private:" << be_idt_nl;

      this->gen_pd (node);
    }
  else // Need a way to access the state of derived OBV_ classes.
    {
      if (!node->is_abstract ())
        {
          *os << be_uidt_nl << "protected:" << be_idt_nl;

          if (is_an_amh_exception_holder)
            {
              *os << "virtual CORBA::Boolean" << be_nl
                  << "_tao_marshal__" << node->flat_name () 
                  << " (TAO_OutputCDR &) {return 1;}"
                  << be_nl << be_nl;
              *os << "virtual CORBA::Boolean" << be_nl
                  << "_tao_unmarshal__" << node->flat_name () 
                  << " (TAO_InputCDR &) {return 1;}";
            }          
          else
            {            
              *os << "virtual CORBA::Boolean" << be_nl
                  << "_tao_marshal__" << node->flat_name () 
                  << " (TAO_OutputCDR &) = 0;"
                  << be_nl << be_nl;
              *os << "virtual CORBA::Boolean" << be_nl
                  << "_tao_unmarshal__" << node->flat_name () 
                  << " (TAO_InputCDR &) = 0;";
            }
        }
    }

  *os << be_uidt_nl 
      << "};";

  os->gen_endif ();

  // Generate the _init -related declarations.
  be_visitor_context ctx (*this->ctx_);
  be_visitor_valuetype_init_ch visitor (&ctx);

  if (visitor.visit_valuetype (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_ch::"
                         "visit_valuetype - "
                         "failed to generate _init construct.\n"),  
                        -1);
    }

  // Step last: generate typecode declaration.
  if (be_global->tc_support ())
    {
      be_visitor_context ctx (*this->ctx_);
      be_visitor_typecode_decl visitor (&ctx);

      if (node->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_valuetype_ch::"
                             "visit_structure - "
                             "TypeCode declaration failed\n"),
                            -1);
        }
    }

  node->cli_hdr_gen (I_TRUE);

  return 0;
}

int
be_visitor_valuetype_ch::visit_eventtype (be_eventtype *node)
{
  return this->visit_valuetype (node);
}

int
be_visitor_valuetype_ch::visit_operation (be_operation *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  this->ctx_->node (node); // save the node

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl;

  // Every operation is declared public and virtual in the client code.
  *os << be_uidt_nl << "public:" << be_idt_nl << "virtual ";

  be_type *bt = be_type::narrow_from_decl (node->return_type ());

  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_ch::"
                         "visit_operation - "
                         "Bad return type\n"),
                        -1);
    }

  be_visitor_context ctx (*this->ctx_);
  be_visitor_operation_rettype or_visitor (&ctx);

  if (bt->accept (&or_visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_ch::"
                         "visit_operation - "
                         "codegen for return type failed\n"),
                        -1);
    }

  *os << " " << node->local_name ();

  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_CH);
  be_visitor_obv_operation_arglist ooa_visitor (&ctx);

  if (node->accept (&ooa_visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_ch::"
                         "visit_operation - "
                         "codegen for argument list failed\n"),
                        -1);
    }

  return 0;
}

int
be_visitor_valuetype_ch::visit_field (be_field *node)
{
  be_valuetype *vt = be_valuetype::narrow_from_scope (node->defined_in ());

  if (!vt)
    {
      return -1;
    }

  be_visitor_context ctx (*this->ctx_);
  be_visitor_valuetype_field_ch visitor (&ctx);

  if (vt->opt_accessor ())
    {
      visitor.setenclosings ("",";");
    }
  else
    {
      visitor.setenclosings ("virtual "," = 0;");
    }

  if (node->accept (&visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_obv_ch::"
                         "visit_field - codegen failed\n"),
                        -1);
    }

  return 0;
}


void
be_visitor_valuetype_ch::begin_public (void)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << "public:" << be_idt_nl;
}

void
be_visitor_valuetype_ch::begin_private (void)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << be_uidt_nl << be_nl << "protected:" << be_idt;
}

int 
be_visitor_valuetype_ch::gen_supported_ops (be_interface *,
                                            be_interface *base,
                                            TAO_OutStream *os)
{

  AST_Decl *d = 0;
  be_visitor_context ctx;
  ctx.stream (os);

  for (UTL_ScopeActiveIterator si (base, UTL_Scope::IK_decls);
       !si.is_done ();
       si.next ())
    {
      d = si.item ();

      if (d == 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_valuetype_ch::"
                             "gen_supported_ops - "
                             "bad node in this scope\n"),
                            -1);
        }

      AST_Decl::NodeType nt = d->node_type ();
      be_visitor_valuetype_ch visitor (&ctx);

      if (nt == AST_Decl::NT_op)
        {
          be_operation *op = be_operation::narrow_from_decl (d);

          if (visitor.visit_operation (op) == -1)
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "(%N:%l) be_visitor_valuetype_ch::"
                                 "gen_supported_ops - "
                                 "failed to accept visitor\n"),
                                -1);
            }
        }
    }

  return 0;
}

