//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    valuetype_ss.cpp
//
// = DESCRIPTION
//    Visitor generating code for Interfaces in the server skeletons file.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_valuetype, 
           valuetype_ss, 
           "$Id$")


// ************************************************************
// Interface visitor for server skeletons.
// ************************************************************

be_visitor_valuetype_ss::be_visitor_valuetype_ss (be_visitor_context *ctx)
  : be_visitor_valuetype (ctx)
{
}

be_visitor_valuetype_ss::~be_visitor_valuetype_ss (void)
{
}

int
be_visitor_valuetype_ss::visit_valuetype (be_valuetype *node)
{
  if (node->srv_skel_gen () || node->imported () || node->is_abstract ())
    {
      return 0;
    }

  AST_Interface *concrete = node->supports_concrete ();

  // We generate a skeleton class only if the valuetype supports a
  // non-abstract interface.
  if (concrete == 0)
    {
      return 0;
    }

  // Generate the normal skeleton as usual.

  TAO_OutStream *os = this->ctx_->stream ();

  os->indent ();

  ACE_CString full_skel_name_holder =
    this->generate_full_skel_name (node);

  const char *full_skel_name = full_skel_name_holder.c_str ();

  ACE_CString flat_name_holder =
    this->generate_flat_name (node);

  const char *flat_name = flat_name_holder.c_str ();

  if (node->gen_operation_table (flat_name, full_skel_name) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_valuetype_ss::"
                         "visit_valuetype - "
                         "codegen for operation table failed\n"),
                        -1);
    }

  *os << be_nl << "// TAO_IDL - Generated from " << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  // Find if we are at the top scope or inside some module,
  // pre-compute the prefix that must be added to the local name in
  // each case.
  const char *local_name_prefix = "";

  if (!node->is_nested ())
    {
      local_name_prefix = "POA_";
    }

  ACE_CString node_local_name_holder =
    this->generate_local_name (node);

  const char *node_local_name = node_local_name_holder.c_str ();

  *os << full_skel_name << "::"
      << local_name_prefix << node_local_name
      << " (void)\n";

  // Generate optable
  *os << "{" << be_idt_nl
      << "this->optable_ = &tao_" << flat_name
      << "_optable;" << be_uidt_nl
      << "}\n\n";

  // find if we are at the top scope or inside some module
  *os << full_skel_name << "::"
      << local_name_prefix << node_local_name << " ("
      << "const " << local_name_prefix << node_local_name << "& rhs)";

  *os << be_idt_nl
      << ":";

  if (this->generate_copy_ctor (node, os) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_valuetype_ss::visit_valuetype - "
                         " copy ctor generation failed\n"),
                        -1);
    }



  *os << "  TAO_ServantBase (rhs)" << be_uidt_nl
      << "{}" << be_nl << be_nl;

  *os << full_skel_name << "::~"
      << local_name_prefix << node_local_name
      << " (void)" << be_nl;
  *os << "{" << be_nl;
  *os << "}\n\n";

  *os << "// TAO_IDL - Generated from " << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  // Generate code for the _is_a skeleton.
  os->indent ();
  *os << "void " << full_skel_name
      << "::_is_a_skel (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &_tao_server_request, " << be_nl
      << "void * _tao_object_reference," << be_nl
      << "void * /* Servant_Upcall */" << be_nl
      << "ACE_ENV_ARG_DECL" << be_uidt_nl
      << ")" << be_uidt_nl;
  *os << "{" << be_idt_nl;
  *os << "TAO_InputCDR &_tao_in = _tao_server_request.incoming ();" << be_nl;
  *os << full_skel_name << " *_tao_impl = ("
      << full_skel_name << " *) _tao_object_reference;" << be_nl;
  *os << "CORBA::Boolean _tao_retval = 0;" << be_nl;
  *os << "CORBA::String_var value;" << be_nl;
  *os << "if (!(_tao_in >> value.out ()))" << be_idt_nl;

  if (be_global->use_raw_throw ())
    {
      *os << "throw CORBA::MARSHAL ();" << be_uidt_nl << be_nl;
    }
  else
    {
      *os << "ACE_THROW (CORBA::MARSHAL ());" << be_uidt_nl << be_nl;
    }

  *os << "_tao_retval = _tao_impl->_is_a (value.in () ACE_ENV_ARG_PARAMETER);"
      << be_nl;
  *os << "ACE_CHECK;" << be_nl << be_nl;
  *os << "_tao_server_request.init_reply ();" << be_nl;
  *os << "TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();"
      << be_nl;
  *os << "if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))"
      << be_idt_nl;

  if (be_global->use_raw_throw ())
    {
      *os << "throw CORBA::MARSHAL ();" << be_uidt << be_uidt_nl;
    }
  else
    {
      *os << "ACE_THROW (CORBA::MARSHAL ());" << be_uidt << be_uidt_nl;
    }

  *os << "}" << be_nl << be_nl;


  // Generate code for the _non_existent skeleton.
  *os << "void " << full_skel_name
      << "::_non_existent_skel (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &_tao_server_request, " << be_nl
      << "void * _tao_object_reference," << be_nl
      << "void * /* Servant_Upcall */" << be_nl
      << "ACE_ENV_ARG_DECL" << be_uidt_nl
      << ")" << be_uidt_nl;
  *os << "{" << be_idt_nl;
  *os << full_skel_name << " *_tao_impl = ("
      << full_skel_name << " *) _tao_object_reference;" << be_nl;
  *os << "CORBA::Boolean _tao_retval =" << be_idt_nl
      << "_tao_impl->_non_existent (ACE_ENV_SINGLE_ARG_PARAMETER);"
      << be_uidt_nl;
  *os << "ACE_CHECK;" << be_nl << be_nl;
  *os << "_tao_server_request.init_reply ();" << be_nl;
  *os << "TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();"
      << be_nl;
  *os << "if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))"
      << be_idt_nl;

  if (be_global->use_raw_throw ())
    {
      *os << "throw CORBA::MARSHAL ();" << be_uidt << be_uidt_nl;
    }
  else
    {
      *os << "ACE_THROW (CORBA::MARSHAL ());" << be_uidt << be_uidt_nl;
    }

  *os << "}\n\n";

  // Generate code for the _interface skeleton.
  *os << "void " << full_skel_name
      << "::_interface_skel (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &_tao_server_request, " << be_nl
      << "void * _tao_object_reference," << be_nl
      << "void * /* Servant_Upcall */" << be_nl
      << "ACE_ENV_ARG_DECL" << be_uidt_nl
      << ")" << be_uidt_nl;
  *os << "{" << be_idt_nl;
  *os << full_skel_name << " *_tao_impl = ("
      << full_skel_name << " *) _tao_object_reference;" << be_nl
      << "CORBA_InterfaceDef_ptr _tao_retval = 0;" << be_nl
      << "CORBA::Boolean _tao_result = 0;" << be_nl << be_nl;
  *os << "TAO_IFR_Client_Adapter *_tao_adapter =" << be_idt_nl
      << "ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance ("
      << be_idt << be_idt_nl
      << "TAO_ORB_Core::ifr_client_adapter_name ()" << be_uidt_nl
      << ");" << be_uidt_nl << be_uidt_nl;
  *os << "if (_tao_adapter == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "ACE_THROW (CORBA::INTF_REPOS ());" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl;
  *os << "ACE_TRY" << be_idt_nl
      << "{" << be_idt_nl
      << "_tao_retval = " << be_idt_nl
      << "_tao_impl->_get_interface (ACE_ENV_SINGLE_ARG_PARAMETER);"
      << be_uidt_nl
      << "ACE_TRY_CHECK;" << be_nl << be_nl
      << "_tao_server_request.init_reply ();" << be_nl << be_nl
      << "TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();"
      << be_nl << be_nl
      << "_tao_result =" << be_idt_nl
      << "_tao_adapter->interfacedef_cdr_insert (" << be_idt << be_idt_nl
      << "_tao_out," << be_nl
      << "_tao_retval" << be_uidt_nl
      << ");" << be_uidt << be_uidt << be_uidt_nl
      << "}" << be_uidt_nl
      << "ACE_CATCHALL" << be_idt_nl
      << "{" << be_idt_nl
      << "_tao_adapter->dispose (_tao_retval);" << be_uidt_nl
      << "}" << be_uidt_nl
      << "ACE_ENDTRY;" << be_nl << be_nl;
  *os << "if (_tao_result == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "ACE_THROW (CORBA::MARSHAL ());" << be_uidt_nl
      << "}" << be_uidt << be_uidt_nl;
  *os << "}\n\n";

  // Generate code for the _is_a override.
  os->indent ();

  *os << "CORBA::Boolean " << full_skel_name
      << "::_is_a (" << be_idt << be_idt_nl
      << "const char* value" << be_nl
      << "ACE_ENV_ARG_DECL_NOT_USED" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl
      << "if (" << be_idt << be_idt_nl;

  if (node->traverse_inheritance_graph (be_interface::is_a_helper, os) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_valuetype_ss::"
                         "visit_valuetype - "
                         "traversal of inhertance graph failed\n"),
                        -1);
    }

  *os << "!ACE_OS::strcmp (" << be_idt << be_idt_nl
      << "(char *)value," << be_nl
      << "\"IDL:org.omg/CORBA/ValueBase:1.0\"" << be_uidt_nl
      << ")";

  *os << be_uidt << be_uidt_nl
      << " )" << be_nl
      << "{" << be_idt_nl
      << "return 1;" << be_uidt_nl
      << "}" << be_uidt_nl
      << "else" << be_idt_nl
      << "{" << be_idt_nl
      << "return 0;" << be_uidt_nl
      << "}" << be_uidt << be_uidt_nl
      << "}" << be_nl << be_nl;

  // the downcast method.
  *os << "void* " << full_skel_name
      << "::_downcast (" << be_idt << be_idt_nl
      << "const char* logical_type_id" << be_uidt_nl
      << ")" << be_uidt_nl
      << "{" << be_idt_nl;

  if (this->generate_downcast_implementation (node, os) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_valuetype_ss::"
                         "visit_valuetype - "
                         "traverse for downcast implementation failed\n"),
                        -1);
    }

  *os << "if (ACE_OS::strcmp (logical_type_id," << be_nl
      << "                    \"IDL:omg.org/CORBA/ValueBase:1.0\") == 0)" 
      << be_idt_nl
      << "{" << be_idt_nl
      << "return ACE_static_cast(PortableServer::Servant, this);"
      << be_uidt_nl
      << "}" << be_uidt_nl << be_nl;

  *os << "return 0;" << be_uidt_nl
      << "}" << be_nl << be_nl;

  *os << "const char* " << full_skel_name
      << "::_interface_repository_id (void) const"
      << be_nl;
  *os << "{" << be_idt_nl;
  *os << "return \"" << node->repoID () << "\";" << be_uidt_nl;
  *os << "}" << be_nl << be_nl;

  // Print out dispatch method.
  this->dispatch_method (node);

  *os << be_nl;

  this->this_method (node);

  *os << "\n\n";

  return 0;
}

void
be_visitor_valuetype_ss::this_method (be_valuetype *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  // the _this () operation.
  *os << node->full_name () << " *" << be_nl
      << node->full_skel_name ()
      << "::_this (ACE_ENV_SINGLE_ARG_DECL)" << be_nl
      << "{" << be_idt_nl
      << "TAO_Stub *stub = this->_create_stub (ACE_ENV_SINGLE_ARG_PARAMETER);"
      << be_nl
      << "ACE_CHECK_RETURN (0);" << be_nl << be_nl
      << "TAO_Stub_Auto_Ptr safe_stub (stub);" << be_nl;

  *os << "CORBA::Object_ptr tmp = CORBA::Object::_nil ();" << be_nl
      << be_nl
      << "if (stub->servant_orb_var ()->orb_core ()->"
      << "optimize_collocation_objects ())" << be_idt_nl
      << "{" << be_idt_nl
      << "ACE_NEW_RETURN (" << be_idt << be_idt_nl
      << "tmp," << be_nl
      << "CORBA::Object (" << be_idt << be_idt_nl
      << "stub," << be_nl
      << "1," << be_nl
      << "this" << be_uidt_nl
      << ")," << be_uidt_nl
      << "0" << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "}" << be_uidt_nl
      << "else" << be_idt_nl
      << "{" << be_idt_nl
      << "ACE_NEW_RETURN (" << be_idt << be_idt_nl
      << "tmp," << be_nl
      << "CORBA::Object (" << be_idt << be_idt_nl
      << "stub," << be_nl
      << "0," << be_nl
      << "this" << be_uidt_nl
      << ")," << be_uidt_nl
      << "0" << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "}" << be_uidt_nl << be_nl;

  *os << "CORBA::Object_var obj = tmp;" << be_nl
      << "(void) safe_stub.release ();" << be_nl
      << "return " << "::" << node->full_name ()
      << "::_unchecked_narrow (obj.in ());"
      << be_uidt_nl
      << "}" << be_nl;
}

void
be_visitor_valuetype_ss::dispatch_method (be_valuetype *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__ << be_nl << be_nl;

  *os << "void " << node->full_skel_name ()
      << "::_dispatch (" << be_idt << be_idt_nl
      << "TAO_ServerRequest &req," << be_nl
      << "void *servant_upcall" << be_nl
      << "ACE_ENV_ARG_DECL" << be_uidt_nl
      << ")" << be_uidt_nl;
  *os << "{" << be_idt_nl;
  *os << "this->synchronous_upcall_dispatch (req," << be_nl
      << "                                   servant_upcall," << be_nl
      << "                                   this" << be_nl
      << "                                   ACE_ENV_ARG_PARAMETER);"
      << be_uidt_nl;
  *os << "}" << be_nl;
}

int
be_visitor_valuetype_ss::generate_downcast_implementation (be_valuetype *node,
                                                           TAO_OutStream *os)
{
  return node->traverse_inheritance_graph (be_interface::downcast_helper,
                                           os);
}

int
be_visitor_valuetype_ss::generate_copy_ctor (be_valuetype *node,
                                             TAO_OutStream *os)
{
  return node->traverse_inheritance_graph (be_interface::copy_ctor_helper,
                                           os);
}

ACE_CString
be_visitor_valuetype_ss::generate_flat_name (be_valuetype *node)
{
  return ACE_CString (node->flat_name ());
}

ACE_CString
be_visitor_valuetype_ss::generate_local_name (be_valuetype *node)
{
  return ACE_CString (node->local_name ());
}

ACE_CString
be_visitor_valuetype_ss::generate_full_skel_name (be_valuetype *node)
{
  return ACE_CString (node->full_skel_name ());
}
