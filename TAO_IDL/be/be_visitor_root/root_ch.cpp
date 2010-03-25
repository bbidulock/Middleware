
//=============================================================================
/**
 *  @file    root_ch.cpp
 *
 *  $Id$
 *
 *  Visitor generating code for Root in the client header
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================

// ********************************
// Root visitor for client header
// ********************************

be_visitor_root_ch::be_visitor_root_ch (be_visitor_context *ctx)
  : be_visitor_root (ctx)
{
}

be_visitor_root_ch::~be_visitor_root_ch (void)
{
}

int
be_visitor_root_ch::visit_root (be_root *node)
{
  if (this->init () == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root_ch::init - ")
                         ACE_TEXT ("failed to initialize\n")),
                        -1);
    }
    
  this->gen_fwd_decls ();

  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root_ch::visit_root - ")
                         ACE_TEXT ("codegen for scope failed\n")),
                        -1);
    }
    
  this->gen_proxy_broker_factory_pointers ();
  
  this->gen_ref_counting_overrides ();
  
  this->gen_static_corba_overrides ();

  if (this->gen_obv_decls (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root_ch::")
                         ACE_TEXT ("visit_root - ")
                         ACE_TEXT ("failed to generate OBV_ decls\n")),
                        -1);
    }

  if (this->gen_object_traits (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root_ch::")
                         ACE_TEXT ("visit_root - failed to ")
                         ACE_TEXT ("generate object traits\n")),
                        -1);
    }


  if (this->gen_template_exports (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root::")
                         ACE_TEXT ("visit_root - ")
                         ACE_TEXT ("failed to export templates\n")),
                        -1);
    }
    
  if (this->gen_any_ops (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root_ch::")
                         ACE_TEXT ("visit_root - failed to ")
                         ACE_TEXT ("generate Any operators\n")),
                        -1);
    }


  if (this->gen_cdr_ops (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root_ch::")
                         ACE_TEXT ("visit_root - failed to ")
                         ACE_TEXT ("generate CDR operators\n")),
                        -1);
    }


  if (this->gen_dds_serializer_ops (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root_ch::")
                         ACE_TEXT ("visit_root - failed to ")
                         ACE_TEXT ("generate DDS serialization\n")),
                        -1);
    }

  (void) tao_cg->end_client_header ();

  return 0;
}

int
be_visitor_root_ch::init (void)
{
  /// First open the client-side file for writing
  int status =
    tao_cg->start_client_header (
      be_global->be_get_client_hdr_fname ());
  
  if (status == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_root_ch::init - ")
                         ACE_TEXT ("Error opening client header file\n")),
                        -1);
    }

  /// Initialize the stream.
  this->ctx_->stream (tao_cg->client_header ());
  
  return 0;
}

void
be_visitor_root_ch::gen_fwd_decls (void)
{
  TAO_OutStream &os_ = *this->ctx_->stream ();

  // If this IDL file contains an non local interface declaration, generate a
  // forward declaration of the proxy broker for a possible collocated call.
  if (idl_global->non_local_iface_seen_)
    {
      os_ << be_nl << be_nl
          << "// TAO_IDL - Generated from " << be_nl
          << "// " << __FILE__ << ":" << __LINE__;

      os_ << be_global->core_versioning_begin () << be_nl;

      os_ << be_nl << be_nl
          << "namespace TAO" << be_nl
          << "{" << be_idt_nl;

     if (be_global->gen_direct_collocation () || be_global->gen_thru_poa_collocation ())
       {
         os_ << "class Collocation_Proxy_Broker;" << be_nl;
       }

      if (idl_global->abstract_iface_seen_)
        {
          os_ << "template<typename T> class AbstractBase_Narrow_Utils;" << be_nl;
        }

      os_ << "template<typename T> class Narrow_Utils;" << be_uidt_nl
          << "}" ;

      os_ << be_global->core_versioning_end () << be_nl;
    }
}

void
be_visitor_root_ch::gen_proxy_broker_factory_pointers (void)
{
  size_t size = be_global->non_local_interfaces.size ();
  
  if (size == 0)
    {
      return;
    }
    
  size_t index = 0;
  be_interface *i = 0;
  
  TAO_OutStream &os_ = *this->ctx_->stream ();

  os_ << be_nl << be_nl
      << "// Proxy Broker Factory function pointer declarations."
      << be_nl << be_nl
      << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__;

  for (index = 0; index < size; ++index)
    {
      be_global->non_local_interfaces.dequeue_head (i);

      if (be_global->gen_direct_collocation() || be_global->gen_thru_poa_collocation ())
        {
          os_ << be_nl << be_nl
              << "extern " << be_global->stub_export_macro () << be_nl
              << "TAO::Collocation_Proxy_Broker *" << be_nl
              << "(*" << i->flat_client_enclosing_scope ()
              << i->base_proxy_broker_name ()
              << "_Factory_function_pointer) ("
              << be_idt << be_idt_nl
              << "::CORBA::Object_ptr obj);" << be_uidt << be_uidt;
        }
    }
}

void
be_visitor_root_ch::gen_ref_counting_overrides (void)
{
  size_t size = be_global->non_defined_interfaces.size ();
  
  if (size == 0)
    {
      return;
    }
    
  size_t index = 0;
  be_interface_fwd *ifwd = 0;

  TAO_OutStream &os_ = *this->ctx_->stream ();

  os_ << be_nl << be_nl
      << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__;

  for (index = 0; index < size; ++index)
    {
      be_global->non_defined_interfaces.dequeue_head (ifwd);

      os_ << be_nl << be_nl;

      if (ifwd->is_valuetype ())
        {
          os_ << "// External declarations for undefined valuetype"
              << be_nl << be_nl
              << "// " << ifwd->full_name () << be_nl;

          os_ << be_global->stub_export_macro () << be_nl
              << "void" << be_nl
              << "tao_" << ifwd->flat_name ()
              << "_add_ref ("
              << be_idt << be_idt_nl
              << ifwd->full_name () << " *" << be_uidt_nl
              << ");" << be_uidt_nl << be_nl
              << be_global->stub_export_macro () << be_nl
              << "void" << be_nl
              << "tao_" << ifwd->flat_name ()
              << "_remove_ref (" << be_idt << be_idt_nl
              << ifwd->full_name () << " *" << be_uidt_nl
              << ");" << be_uidt;
        }
    }
}

void
be_visitor_root_ch::gen_static_corba_overrides (void)
{
  size_t size = be_global->mixed_parentage_interfaces.size ();
  
  if (size == 0)
    {
      return;
    }
    
  size_t index = 0;
  be_interface *i = 0;

  TAO_OutStream &os_ = *this->ctx_->stream ();

  os_ << be_nl << be_nl
      << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__
      << be_nl;

  os_ << be_global->core_versioning_begin ();

  os_ << be_nl
      << "// Overrides of CORBA::release and CORBA::is_nil for"
      << be_nl
      << "// interfaces that inherit from both CORBA::Object" << be_nl
      << "// and CORBA::AbstractBase." << be_nl << be_nl
      << "namespace CORBA" << be_nl
      << "{" << be_idt;

  for (index = 0; index < size; ++index)
    {
      be_global->mixed_parentage_interfaces.dequeue_head (i);

      os_ << be_nl
          << "TAO_NAMESPACE_STORAGE_CLASS void release ("
          << i->name () << "_ptr);" << be_nl
          << "TAO_NAMESPACE_STORAGE_CLASS ::CORBA::Boolean is_nil ("
          << i->name () << "_ptr);";
    }

  os_ << be_uidt_nl
      << "}";

  os_ << be_global->core_versioning_end ();
}

int
be_visitor_root_ch::gen_obv_decls (be_root *node)
{
  be_visitor_context ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_MODULE_OBV_CH);

  be_visitor_obv_module obv_visitor (&ctx);

  return obv_visitor.visit_scope (node);
}

int
be_visitor_root_ch::gen_object_traits (be_root *node)
{
  be_visitor_context ctx = *this->ctx_;
  be_visitor_traits traits_visitor (&ctx);
  return node->accept (&traits_visitor);
}

int
be_visitor_root_ch::gen_template_exports (be_root *node)
{
  if (! be_global->gen_template_export ())
    {
      return 0;
    }
    
  be_visitor_context ctx = *this->ctx_;  
  be_visitor_template_export export_visitor (&ctx);
  return node->accept (&export_visitor);
}

int
be_visitor_root_ch::gen_any_ops (be_root *node)
{
  int status = 0;

  if (be_global->any_support ())
    {
      be_visitor_context ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_ROOT_ANY_OP_CH);
      be_visitor_root_any_op any_op_visitor (&ctx);
      status = node->accept (&any_op_visitor);
    }

  /// Conditional switch to the *A.h stream is done
  /// in the visitor constructor.
  if (be_global->gen_anyop_files ())
    {
      (void) tao_cg->end_anyop_header ();
    }

  return status;
}

int
be_visitor_root_ch::gen_cdr_ops (be_root *node)
{
  be_visitor_context ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_ROOT_CDR_OP_CH);
  be_visitor_root_cdr_op visitor (&ctx);
  return node->accept (&visitor);
}

int
be_visitor_root_ch::gen_dds_serializer_ops (be_root *node)
{
  if (! be_global->gen_dcps_type_support ())
    {
      return 0;
    }
    
  be_visitor_context ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_ROOT_SERIALIZER_OP_CH);
  be_visitor_root_cdr_op visitor (&ctx);
  return node->accept (&visitor);
}

