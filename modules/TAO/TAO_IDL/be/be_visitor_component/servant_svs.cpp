//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    servant_svs.cpp
//
// = DESCRIPTION
//    Visitor generating code for a servant class in the
//    servant source file.
//
// = AUTHOR
//    Jeff Parsons
//
// ============================================================================

be_visitor_servant_svs::be_visitor_servant_svs (be_visitor_context *ctx)
  : be_visitor_component_scope (ctx),
    op_scope_ (0),
    n_provides_ (0UL),
    n_uses_ (0UL),
    n_publishes_ (0UL),
    n_emits_ (0UL),
    n_consumes_ (0UL)
{
}

be_visitor_servant_svs::~be_visitor_servant_svs (void)
{
}

int
be_visitor_servant_svs::visit_component (be_component *node)
{
  node_ = node;

  n_provides_ = 0UL;
  n_uses_ = 0UL;
  n_publishes_ = 0UL;
  n_emits_ = 0UL;
  n_consumes_ = 0UL;

  this->compute_slots (node_);

  AST_Decl *scope = ScopeAsDecl (node_->defined_in ());
  ACE_CString sname_str (scope->full_name ());
  const char *sname = sname_str.c_str ();
  const char *lname = node->local_name ();
  const char *global = (sname_str == "" ? "" : "::");

  os_ << be_nl << be_nl
      << lname << "_Servant::"
      << lname << "_Servant (" << be_idt << be_idt_nl
      << global << sname << "::CCM_" << lname
      << "_ptr exe," << be_nl
      << "::Components::CCMHome_ptr h," << be_nl
      << "const char * ins_name," << be_nl
      << "::CIAO::Home_Servant_Impl_Base * hs,"
      << be_nl
      << "::CIAO::Container_ptr c)" << be_uidt_nl
      << ": ::CIAO::Servant_Impl_Base (h, hs, c),"
      << be_idt_nl
      << "::CIAO::Servant_Impl<" << be_idt_nl
      << "::" << node_->full_skel_name ()
      << "," << be_nl
      << global << sname << "::CCM_"
      << lname << "," << be_nl
      << lname << "_Context> (exe, h, ins_name, hs, c)"
      << be_uidt << be_uidt << be_uidt_nl
      << "{" << be_idt_nl;

  be_visitor_obv_factory_reg ofr_visitor (this->ctx_);

  if (ofr_visitor.visit_component_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_component_svs::"
                         "visit_component - "
                         "OBV factory registration failed\n"),
                        -1);
    }

  os_ << "try" << be_idt_nl
      << "{" << be_idt_nl
      << "this->populate_port_tables ();" << be_uidt_nl
      << "}" << be_uidt_nl
      << "catch (const ::CORBA::Exception &)" << be_idt_nl
      << "{" << be_nl
      << "}" << be_uidt << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << lname << "_Servant::~"
      << lname << "_Servant (void)" << be_nl
      << "{" << be_nl
      << "}";

  os_ << be_nl << be_nl
      << "void" << be_nl
      << lname << "_Servant::set_attributes (" << be_idt_nl
      << "const ::Components::ConfigValues & descr)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "for ( ::CORBA::ULong i = 0; i < descr.length (); ++i)"
      << be_idt_nl
      << "{" << be_idt_nl
      << "const char * descr_name = descr[i]->name ();" << be_nl
      << "::CORBA::Any & descr_value = descr[i]->value ();";

  be_visitor_attr_set as_visitor (this->ctx_);

  if (as_visitor.visit_component_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_component_svs::"
                         "visit_component - "
                         "attr init visitor failed\n"),
                        -1);
    }

  os_ << be_nl << be_nl
      << "ACE_UNUSED_ARG (descr_name);" << be_nl
      << "ACE_UNUSED_ARG (descr_value);" << be_uidt_nl
      << "}" << be_uidt << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "/// Supported operations and attributes.";

  this->op_scope_ = node;

  /// The overload of traverse_inheritance_graph() used here
  /// doesn't automatically prime the queues.
  node_->get_insert_queue ().reset ();
  node_->get_del_queue ().reset ();
  node_->get_insert_queue ().enqueue_tail (node);

  Component_Op_Attr_Generator op_attr_gen (this);

  int status =
    node->traverse_inheritance_graph (op_attr_gen,
                                      &os_,
                                      false,
                                      false);

  if (status == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_component_svs::"
                         "visit_component - "
                         "inheritance graph traversal failed\n"),
                        -1);
    }

  os_ << be_nl << be_nl
      << "/// All ports and component attributes.";

  // Port operations that require scope traversal to get all the
  // possible string name matches.
  this->gen_provides_top ();
  this->gen_uses_top ();
  this->gen_publishes_top ();
  this->gen_emits_top ();

  // This call will generate all other operations and attributes,
  // including inherited ones.
  if (this->visit_component_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_component_svs::"
                         "visit_component - "
                         "visit_component_scope() failed\n"),
                        -1);
    }

  os_ << be_nl << be_nl
      << "/// Private method to trigger population of the port"
      << be_nl
      << "/// tables (facets and event consumers)." << be_nl
      << "void" << be_nl
      << node_->local_name ()
      << "_Servant::populate_port_tables (void)" << be_nl
      << "{" << be_idt_nl
      << "::CORBA::Object_var obj_var;" << be_nl
      << "::Components::EventConsumerBase_var ecb_var;"
      << be_nl;

  be_visitor_populate_port_tables ppt_visitor (this->ctx_);

  if (ppt_visitor.visit_component_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_component_svs::"
                         "visit_component - "
                         "populate port tables visitor failed\n"),
                        -1);
    }

  os_ << be_uidt_nl
      << "}";

  return 0;
}

int
be_visitor_servant_svs::visit_operation (be_operation *node)
{
  AST_Decl::NodeType nt =
    ScopeAsDecl (node->defined_in ())->node_type ();

  // Components have implied IDL operations added to the AST, but
  // we are interested only in supported interface operations.
  if (nt == AST_Decl::NT_component)
    {
      return 0;
    }

  be_visitor_operation_svs v (this->ctx_);
  v.scope (this->op_scope_);

  return v.visit_operation (node);
}

int
be_visitor_servant_svs::visit_attribute (be_attribute *node)
{
  be_visitor_attribute v (this->ctx_);

  v.for_facets (false);
  v.op_scope (this->op_scope_);

  return v.visit_attribute (node);
}

int
be_visitor_servant_svs::visit_provides (be_provides *node)
{
  ACE_CString prefix (this->port_prefix_);
  prefix += node->local_name ()->get_string ();
  const char *port_name = prefix.c_str ();

  AST_Type *obj = node->provides_type ();
  const char *obj_name = obj->full_name ();
  AST_Decl *scope = ScopeAsDecl (obj->defined_in ());
  ACE_CString sname_str (scope->full_name ());
  const char *sname = sname_str.c_str ();

  if (node->provides_type ()->is_local ())
    {
      return 0;
    }

  // Avoid '_cxx_' prefix.
  const char *lname =
    obj->original_local_name ()->get_string ();

  const char *global = (sname_str == "" ? "" : "::");
  const char *prefix_connector = (sname_str == "" ? "" : "_");

  os_ << be_nl << be_nl
      << "::" << obj_name << "_ptr" << be_nl
      << node_->local_name () << "_Servant::provide_"
      << port_name << " (void)" << be_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "if ( ::CORBA::is_nil (this->provide_"
      << port_name << "_.in ()))" << be_idt_nl
      << "{" << be_idt_nl
      << "::CORBA::Object_var obj =" << be_idt_nl
      << "this->provide_" << port_name << "_i ();"
      << be_uidt_nl << be_nl
      << "::" << obj_name << "_var fo =" << be_idt_nl
      << "::" << obj_name << "::_narrow (obj.in ());"
      << be_uidt_nl << be_nl
      << "this->provide_" << port_name << "_ = fo;" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "return" << be_idt_nl
      <<  "::" << obj_name << "::_duplicate (this->provide_"
      << port_name << "_.in ());" << be_uidt << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::CORBA::Object_ptr" << be_nl
      << node_->local_name () << "_Servant::provide_"
      << port_name << "_i (void)" << be_nl
      << "{" << be_idt_nl
      << "::CORBA::Object_ptr ret =" << be_idt_nl
      << "this->lookup_facet (\"" << port_name << "\");"
      << be_uidt_nl << be_nl
      << "if (! ::CORBA::is_nil (ret))" << be_idt_nl
      << "{" << be_idt_nl
      << "return ret;" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "typedef" << be_idt_nl
      << "::CIAO::Port_Activator_T<" << be_idt_nl
      << "::CIAO_FACET" << prefix_connector
      << scope->flat_name () << "::" << lname
      << "_Servant," << be_nl
      << global << sname << "::CCM_" << lname << "," << be_nl
      << "::Components::CCMContext," << be_nl
      << node_->local_name () << "_Servant>" << be_uidt_nl
      << "MACRO_MADNESS_TYPEDEF;" << be_uidt_nl << be_nl
      << "MACRO_MADNESS_TYPEDEF * tmp = 0;" << be_nl
      << "ACE_CString obj_id (this->ins_name_);" << be_nl
      << "obj_id += \"_" << port_name << "\";" << be_nl << be_nl
      << "ACE_NEW_THROW_EX (" << be_idt_nl
      << "tmp," << be_nl
      << "MACRO_MADNESS_TYPEDEF (" << be_idt_nl
      << "obj_id.c_str ()," << be_nl
      << "\"" << port_name << "\"," << be_nl
      << "::CIAO::Port_Activator_Types::FACET," << be_nl
      << "0," << be_nl
      << "this->context_," << be_nl
      << "this)," << be_uidt_nl
      << "::CORBA::NO_MEMORY ());" << be_uidt_nl << be_nl
      << "::CIAO::Port_Activator_var pa = tmp;" << be_nl << be_nl
      << "::CIAO::Servant_Activator_var sa =" << be_idt_nl
      << "this->container_->ports_servant_activator ();"
      << be_uidt_nl << be_nl
      << "if (! sa->register_port_activator (pa._retn ()))"
      << be_idt_nl
      << "{" << be_idt_nl
      << "return ::" << obj_name << "::_nil ();" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "::CORBA::Object_var obj =" << be_idt_nl
      << "this->container_->generate_reference (" << be_idt_nl
      << "obj_id.c_str ()," << be_nl
      << "\"" << obj->repoID () << "\"," << be_nl
      << "::CIAO::Container_Types::FACET_CONSUMER_t);"
      << be_uidt_nl << be_uidt_nl
      << "this->add_facet (\"" << port_name << "\", obj.in ());"
      << be_nl << be_nl
      << "return obj._retn ();" << be_uidt_nl
      << "}";

  return 0;
}

int
be_visitor_servant_svs::visit_uses (be_uses *node)
{
  ACE_CString prefix (this->port_prefix_);
  prefix += node->local_name ()->get_string ();
  const char *port_name = prefix.c_str ();

  const char *obj_name = node->uses_type ()->full_name ();
  bool is_multiple = node->is_multiple ();

  if (node->uses_type ()->is_local ())
    {
      return 0;
    }

  os_ << be_nl << be_nl
      << (is_multiple ? "::Components::Cookie *" : "void")
      << be_nl
      << node_->local_name () << "_Servant::connect_"
      << port_name << " (" << be_idt_nl
      << "::" << obj_name << "_ptr c)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (is_multiple)
    {
      os_ << "::Components::Cookie * cookie =" << be_idt_nl;
    }

  os_ << "this->context_->connect_" << port_name
      << " (c);" << be_nl;

  if (is_multiple)
    {
      os_ << be_uidt_nl;
    }

  os_ << "this->add_receptacle (\"" << port_name
      << "\", c, " << (is_multiple ? "cookie" : "0")
      << ");";

  if (is_multiple)
    {
      os_ << be_nl << be_nl
          << "return cookie;";
    }

  os_ << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::" << obj_name << "_ptr" << be_nl
      << node_->local_name () << "_Servant::disconnect_"
      << port_name << " (";

  if (is_multiple)
    {
      os_ << be_idt_nl
          << "::Components::Cookie * ck" << be_uidt;
    }
  else
    {
      os_ << "void";
    }

  os_ << ")" << be_nl
      << "{" << be_idt_nl
      << "return this->context_->disconnect_"
      << port_name << " (" << (is_multiple ? "ck" : "")
      << ");" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::";

  if (is_multiple)
    {
      os_ << node_->full_name () << "::" << port_name
          << "Connections *";
    }
  else
    {
      os_ << obj_name << "_ptr";
    }

  os_ << be_nl
      << node_->local_name () << "_Servant::get_connection"
      << (is_multiple ? "s" : "") << "_"
      << port_name << " (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->context_->get_connection"
      << (is_multiple ? "s" : "") << "_"
      << port_name << " ();" << be_uidt_nl
      << "}";

  return 0;
}

int
be_visitor_servant_svs::visit_publishes (be_publishes *node)
{
  const char *obj_name = node->publishes_type ()->full_name ();
  const char *port_name = node->local_name ()->get_string ();

  os_ << be_nl << be_nl
      << "::Components::Cookie *" << be_nl
      << node_->local_name () << "_Servant::subscribe_"
      << port_name << " (" << be_idt_nl
      << "::" << obj_name << "Consumer_ptr c)" << be_uidt_nl
      << "{" << be_idt_nl;

   if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl;
    }

 os_ << "return this->context_->subscribe_" << port_name
      << " (c);" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::Components::Cookie *" << be_nl
      << node_->local_name () << "_Servant::subscribe_"
      << port_name << "_generic (" << be_idt_nl
      << "::Components::EventConsumerBase_ptr c)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl;
    }

  os_ << "return this->context_->subscribe_" << port_name
      << "_generic (c);" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::" << obj_name << "Consumer_ptr" << be_nl
      << node_->local_name () << "_Servant::unsubscribe_"
      << port_name << " (" << be_idt_nl
      << "::Components::Cookie * ck)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl;
    }

  os_ << "return this->context_->unsubscribe_" << port_name
      << " (ck);" << be_uidt_nl
      << "}";

  return 0;
}

int
be_visitor_servant_svs::visit_emits (be_emits *node)
{
  const char *obj_name = node->emits_type ()->full_name ();
  const char *port_name = node->local_name ()->get_string ();

  os_ << be_nl << be_nl
      << "void" << be_nl
      << node_->local_name () << "_Servant::connect_"
      << port_name << " (" << be_idt_nl
      << "::" << obj_name << "Consumer_ptr c)" << be_uidt_nl
      << "{" << be_idt_nl
      << "this->context_->connect_" << port_name
      << " (c);" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::" << obj_name << "Consumer_ptr" << be_nl
      << node_->local_name () << "_Servant::disconnect_"
      << port_name << " (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->context_->disconnect_"
      << port_name << " ();" << be_uidt_nl
      << "}";

  return 0;
}

int
be_visitor_servant_svs::visit_consumes (be_consumes *node)
{
  AST_Type  *obj = node->consumes_type ();
  const char *port_name = node->local_name ()->get_string ();

  const char *comp_lname = node_->local_name ();
  ACE_CString comp_sname_str (
    ScopeAsDecl (node_->defined_in ())->full_name ());
  const char *comp_sname = comp_sname_str.c_str ();
  const char *global = (comp_sname_str == "" ? "" : "::");

  const char *lname = obj->local_name ()->get_string ();
  const char *fname = obj->full_name ();

  os_ << be_nl << be_nl
      << comp_lname << "_Servant::" << lname << "Consumer_"
      << port_name << "_Servant::" << lname << "Consumer_"
      << port_name << "_Servant (" << be_idt << be_idt_nl
      << global << comp_sname << "::CCM_" << comp_lname
      << "_ptr executor," << be_nl
      << global << comp_sname << "::CCM_" << comp_lname
      << "_Context_ptr c)" << be_uidt_nl
      << ": executor_ ( " << global << comp_sname << "::CCM_"
      << comp_lname << "::_duplicate (executor))," << be_idt_nl
      << "ctx_ ( " << global << comp_sname
      << "::CCM_" << comp_lname
      << "_Context::_duplicate (c))" << be_uidt << be_uidt_nl
      << "{" << be_nl
      << "}";

  os_ << be_nl << be_nl
      << comp_lname << "_Servant::" << lname << "Consumer_"
      << port_name << "_Servant::~" << lname << "Consumer_"
      << port_name << "_Servant (void)" << be_nl
      << "{" << be_nl
      << "}";

  os_ << be_nl << be_nl
      << "::CORBA::Object_ptr" << be_nl
      << comp_lname << "_Servant::" << lname << "Consumer_"
      << port_name << "_Servant::_get_component (void)" << be_nl
      << "{" << be_idt_nl
      << "return this->ctx_->get_CCM_object ();" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "void" << be_nl
      << comp_lname << "_Servant::" << lname << "Consumer_"
      << port_name << "_Servant::push_" << lname
      << " (" << be_idt_nl
      << "::" << fname << " * evt)" << be_uidt_nl
      << "{" << be_idt_nl
      << "this->executor_->push_" << port_name
      << " (evt);" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "/// Inherited from ::Components::EventConsumerBase."
      << be_nl
      << "void" << be_nl
      << comp_lname << "_Servant::" << lname << "Consumer_"
      << port_name << "_Servant::push_event (" << be_idt_nl
      << "::Components::EventBase * ev)" << be_uidt_nl
      << "{" << be_idt_nl
      << "::" << fname << " * ev_type =" << be_idt_nl
      << "::" << fname << "::_downcast (ev);"
      << be_uidt_nl << be_nl
      << "if (ev_type != 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "this->push_" << lname << " (ev_type);" << be_nl
      << "return;" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "throw ::Components::BadEventType ();" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "/// CIAO-specific."
      << be_nl
      << "void" << be_nl
      << comp_lname << "_Servant::" << lname << "Consumer_"
      << port_name << "_Servant::ciao_push_event (" << be_idt_nl
      << "::Components::EventBase * ev," << be_nl
      << "const char * /* source_id */," << be_nl
      << "::CORBA::TypeCode_ptr /* tc */)" << be_uidt_nl
      << "{" << be_idt_nl
      << "this->push_event (ev);" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "/// CIAO-specific."
      << be_nl
      << "::CORBA::Boolean" << be_nl
      << comp_lname << "_Servant::" << lname << "Consumer_"
      << port_name << "_Servant::ciao_is_substitutable ("
      << be_idt_nl
      << "const char * event_repo_id)" << be_uidt_nl
      << "{" << be_idt_nl
      << "if (event_repo_id == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::CORBA::BAD_PARAM ();" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "CORBA::ORB_ptr orb = TAO_ORB_Core_instance ()->orb ();"
      << be_nl << be_nl
      << "CORBA::ValueFactory f =" << be_idt_nl
      << "orb->lookup_value_factory (event_repo_id);"
      << be_uidt_nl << be_nl
      << "if (f == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "return false;" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "CORBA::ValueBase_var v = f->create_for_unmarshal ();"
      << be_nl
      << "f->_remove_ref ();" << be_nl << be_nl
      << "if (v.in () == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "return false;" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "return dynamic_cast< ::" << fname
      << " *> (v.in ()) != 0;" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::" << fname << "Consumer_ptr" << be_nl
      << node_->local_name () << "_Servant::get_consumer_"
      << port_name << " (void)" << be_nl
      << "{" << be_idt_nl
      << "if (! ::CORBA::is_nil (this->consumes_" << port_name
      << "_.in ()))" << be_idt_nl
      << "{" << be_idt_nl
      << "return ::" << fname
      << "Consumer::_duplicate (this->consumes_"
      << port_name << "_.in ());" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "::Components::EventConsumerBase_var obj =" << be_idt_nl
      << "this->get_consumer_" << port_name << "_i ();"
      << be_uidt_nl << be_nl
      << "::" << fname << "Consumer_var eco =" << be_idt_nl
      << "::" << fname << "Consumer::_narrow (obj.in ());"
      << be_uidt_nl << be_nl
      << "this->consumes_" << port_name << "_ = eco;" << be_nl
      << "return" << be_idt_nl
      << "::" << fname << "Consumer::_duplicate (" << be_idt_nl
      << "this->consumes_" << port_name << "_.in ());"
      << be_uidt << be_uidt << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::Components::EventConsumerBase_ptr" << be_nl
      << node_->local_name () << "_Servant::get_consumer_"
      << port_name << "_i (void)" << be_nl
      << "{" << be_idt_nl
      << "::Components::EventConsumerBase_ptr ret =" << be_idt_nl
      << "this->lookup_consumer (\"" << port_name << "\");"
      << be_uidt_nl << be_nl
      << "if (! ::CORBA::is_nil (ret))" << be_idt_nl
      << "{" << be_idt_nl
      << "return ret;" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "typedef" << be_idt_nl
      << "::CIAO::Port_Activator_T<" << be_idt_nl
      << node_->local_name () << "_Servant::" << lname
      << "Consumer_" << port_name << "_Servant," << be_nl
      << global << comp_sname << "::CCM_" << comp_lname
      << "," << be_nl
      << global << comp_sname << "::CCM_" << comp_lname
      << "_Context," << be_nl
      << node_->local_name () << "_Servant>" << be_uidt_nl
      << "MACRO_MADNESS_TYPEDEF;" << be_uidt_nl << be_nl
      << "MACRO_MADNESS_TYPEDEF * tmp = 0;" << be_nl
      << "ACE_CString obj_id (this->ins_name_);" << be_nl
      << "obj_id += \"_" << port_name << "\";" << be_nl << be_nl
      << "ACE_NEW_THROW_EX (" << be_idt_nl
      << "tmp," << be_nl
      << "MACRO_MADNESS_TYPEDEF (" << be_idt_nl
      << "obj_id.c_str ()," << be_nl
      << "\"" << port_name << "\"," << be_nl
      << "::CIAO::Port_Activator_Types::SINK," << be_nl
      << "this->executor_.in ()," << be_nl
      << "this->context_," << be_nl
      << "this)," << be_uidt_nl
      << "::CORBA::NO_MEMORY ());" << be_uidt_nl << be_nl
      << "::CIAO::Port_Activator_var pa = tmp;" << be_nl << be_nl
      << "::CIAO::Servant_Activator_var sa =" << be_idt_nl
      << "this->container_->ports_servant_activator ();"
      << be_uidt_nl << be_nl
      << "if (! sa->register_port_activator (pa._retn ()))"
      << be_idt_nl
      << "{" << be_idt_nl
      << "return ::" << fname << "Consumer::_nil ();" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "::CORBA::Object_var obj =" << be_idt_nl
      << "this->container_->generate_reference (" << be_idt_nl
      << "obj_id.c_str ()," << be_nl
      << "\"";

  ACE_CString work (obj->repoID ());
  ACE_CString result (work.substr (0, work.rfind (':')));
  result += "Consumer:1.0";

  os_ << result.c_str ();

  os_ << "\"," << be_nl
      << "::CIAO::Container_Types::FACET_CONSUMER_t);"
      << be_uidt_nl << be_uidt_nl
      << "::Components::EventConsumerBase_var ecb =" << be_idt_nl
      << "::Components::EventConsumerBase::_narrow (obj.in ());"
      << be_uidt_nl << be_nl
      << "this->add_consumer (\"" << port_name << "\", ecb.in ());"
      << be_nl << be_nl
      << "return ecb._retn ();" << be_uidt_nl
      << "}";

  return 0;
}

void
be_visitor_servant_svs::compute_slots (AST_Component *node)
{
  while (node != 0)
    {
      for (UTL_ScopeActiveIterator si (node, UTL_Scope::IK_decls);
           !si.is_done ();
           si.next ())
        {
          AST_Decl *d = si.item ();

          switch (d->node_type ())
            {
              case AST_Decl::NT_provides:
                ++n_provides_;
                break;
              case AST_Decl::NT_uses:
                ++n_uses_;
                break;
              case AST_Decl::NT_publishes:
                ++n_publishes_;
                break;
              case AST_Decl::NT_emits:
                ++n_emits_;
                break;
              case AST_Decl::NT_consumes:
                ++n_consumes_;
                break;
              default:
                break;
            }
        }

      node = node->base_component ();
    }
}

void
be_visitor_servant_svs::gen_provides_top (void)
{
  os_ << be_nl << be_nl
      << "/// CIAO-specific." << be_nl
      << "::CORBA::Object_ptr" << be_nl
      << node_->local_name ()
      << "_Servant::get_facet_executor (" << be_idt_nl
      << "const char * name)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "if (name == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::CORBA::BAD_PARAM ();" << be_uidt_nl
      << "}" << be_uidt;

  be_visitor_facet_executor_block feb_visitor (this->ctx_);

  if (feb_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_provides_top - "
                  "facet executor block visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "return ::CORBA::Object::_nil ();" << be_uidt_nl
      << "}";
}

void
be_visitor_servant_svs::gen_publishes_top (void)
{
  os_ << be_nl << be_nl
      << "::Components::Cookie *" << be_nl
      << node_->local_name () << "_Servant::subscribe ("
      << be_idt_nl
      << "const char * publisher_name," << be_nl
      << "::Components::EventConsumerBase_ptr subscribe)"
      << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "ACE_UNUSED_ARG (subscribe);" << be_nl << be_nl
      << "if (publisher_name == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}" << be_uidt;

  be_visitor_subscribe_block sb_visitor (this->ctx_);

  if (sb_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_publishes_top - "
                  "subscribe block visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::Components::EventConsumerBase_ptr" << be_nl
      << node_->local_name () << "_Servant::unsubscribe ("
      << be_idt_nl
      << "const char * publisher_name," << be_nl
      << "::Components::Cookie * ck)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "ACE_UNUSED_ARG (ck);" << be_nl << be_nl
      << "if (publisher_name == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}" << be_uidt;

  be_visitor_unsubscribe_block ub_visitor (this->ctx_);

  if (ub_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_publishes_top - "
                  "unsubscribe block visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::Components::PublisherDescriptions *" << be_nl
      << node_->local_name ()
      << "_Servant::get_all_publishers (void)" << be_nl
      << "{" << be_idt_nl
      << "::Components::PublisherDescriptions *retval = 0;"
      << be_nl
      << "ACE_NEW_RETURN (retval," << be_nl
      << "                ::Components::PublisherDescriptions,"
      << be_nl
      << "                0);" << be_nl << be_nl
      << "::Components::PublisherDescriptions_var "
      << "safe_retval = retval;" << be_nl
      << "safe_retval->length (" << n_publishes_
      << "UL);";

  be_visitor_event_source_desc esd_visitor (this->ctx_);

  if (esd_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_publishes_top - "
                  "event source description visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "return safe_retval._retn ();" << be_uidt_nl
      << "}";
}

void
be_visitor_servant_svs::gen_uses_top (void)
{
  os_ << be_nl << be_nl
      << "::Components::Cookie *" << be_nl
      << node_->local_name () << "_Servant::connect (" << be_idt_nl
      << "const char * name," << be_nl
      << "::CORBA::Object_ptr connection)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "/// If the component has no receptacles, "
      << "arg will be unused." << be_nl
      << "ACE_UNUSED_ARG (connection);" << be_nl << be_nl
      << "if (name == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}" << be_uidt;

  be_visitor_connect_block cb_visitor (this->ctx_);

  if (cb_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_uses_top - "
                  "connect block visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::CORBA::Object_ptr" << be_nl
      << node_->local_name () << "_Servant::disconnect ("
      << be_idt_nl
      << "const char * name," << be_nl
      << "::Components::Cookie * ck)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "ACE_UNUSED_ARG (ck);" << be_nl << be_nl
      << "if (name == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::CORBA::BAD_PARAM ();" << be_uidt_nl
      << "}" << be_uidt;

  be_visitor_disconnect_block db_visitor (this->ctx_);

  if (db_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_uses_top - "
                  "disconnect block visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::Components::ReceptacleDescriptions *" << be_nl
      << node_->local_name ()
      << "_Servant::get_all_receptacles (void)" << be_nl
      << "{" << be_idt_nl
      << "::Components::ReceptacleDescriptions * retval = 0;"
      << be_nl
      << "ACE_NEW_RETURN (retval," << be_nl
      << "                ::Components::ReceptacleDescriptions,"
      << be_nl
      << "                0);" << be_nl
      << "::Components::ReceptacleDescriptions_var "
      << "safe_retval = retval;" << be_nl
      << "safe_retval->length (" << n_uses_
      << "UL);";

  be_visitor_receptacle_desc rd_visitor (this->ctx_);

  if (rd_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_uses_top - "
                  "receptacle description visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "return safe_retval._retn ();" << be_uidt_nl
      << "}";
}

void
be_visitor_servant_svs::gen_emits_top (void)
{
  os_ << be_nl << be_nl
      << "void" << be_nl
      << node_->local_name () << "_Servant::connect_consumer ("
      << be_idt_nl
      << "const char * emitter_name," << be_nl
      << "::Components::EventConsumerBase_ptr consumer)"
      << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "if (emitter_name == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::CORBA::BAD_PARAM ();" << be_uidt_nl
      << "}" << be_uidt;

  be_visitor_connect_consumer_block ccb_visitor (this->ctx_);

  if (ccb_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_emits_top - "
                  "connect consumer block visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "ACE_UNUSED_ARG (consumer);" << be_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::Components::EventConsumerBase_ptr" << be_nl
      << node_->local_name ()
      << "_Servant::disconnect_consumer (" << be_idt_nl
      << "const char * source_name)" << be_uidt_nl
      << "{" << be_idt_nl;

  if (swapping_)
    {
      os_ << "this->activate_component ();" << be_nl << be_nl;
    }

  os_ << "if (source_name == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::CORBA::BAD_PARAM ();" << be_uidt_nl
      << "}" << be_uidt;

  be_visitor_disconnect_consumer_block dcb_visitor (this->ctx_);

  if (dcb_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_emits_top - "
                  "disconnect consumer block visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "throw ::Components::InvalidName ();" << be_uidt_nl
      << "}";

  os_ << be_nl << be_nl
      << "::Components::EmitterDescriptions *" << be_nl
      << node_->local_name ()
      << "_Servant::get_all_emitters (void)" << be_nl
      << "{" << be_idt_nl
      << "::Components::EmitterDescriptions *retval = 0;"
      << be_nl
      << "ACE_NEW_RETURN (retval," << be_nl
      << "                ::Components::EmitterDescriptions,"
      << be_nl
      << "                0);" << be_nl << be_nl
      << "::Components::EmitterDescriptions_var "
      << "safe_retval = retval;" << be_nl
      << "safe_retval->length (" << n_emits_
      << "UL);";

  be_visitor_emitter_desc ed_visitor (this->ctx_);

  if (ed_visitor.visit_component_scope (node_) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  "be_visitor_component_svs::"
                  "gen_emits_top - "
                  "emitter description visitor failed\n"));

      return;
    }

  os_ << be_nl << be_nl
      << "return safe_retval._retn ();" << be_uidt_nl
      << "}";
}

// ==========================================================

be_visitor_obv_factory_reg::be_visitor_obv_factory_reg (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_obv_factory_reg::~be_visitor_obv_factory_reg (void)
{
}

int
be_visitor_obv_factory_reg::visit_publishes (be_publishes *node)
{
  this->gen_obv_factory_registration (node->field_type ());

  return 0;
}

int
be_visitor_obv_factory_reg::visit_emits (be_emits *node)
{
  this->gen_obv_factory_registration (node->field_type ());

  return 0;
}

int
be_visitor_obv_factory_reg::visit_consumes (be_consumes *node)
{
  this->gen_obv_factory_registration (node->field_type ());

  return 0;
}

void
be_visitor_obv_factory_reg::gen_obv_factory_registration (AST_Type *t)
{
  if (be_global->gen_ciao_valuefactory_reg ())
    {
      const char *fname = t->full_name ();

      os_ << be_nl << be_nl
          << "TAO_OBV_REGISTER_FACTORY (" << be_idt_nl
          << "::" << fname << "_init," << be_nl
          << "::" << fname << ");" << be_uidt;
    }
}

// ==========================================================

be_visitor_attr_set::be_visitor_attr_set (be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_attr_set::~be_visitor_attr_set (void)
{
}

int
be_visitor_attr_set::visit_attribute (be_attribute *node)
{
  be_visitor_attribute_component_init v (this->ctx_);

  if (v.visit_attribute (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_attr_set")
                         ACE_TEXT ("::visit_attribute - ")
                         ACE_TEXT ("component attr init visitor ")
                         ACE_TEXT ("failed\n")),
                        -1);
    }

  return 0;
}

int
be_visitor_attr_set::visit_extended_port (be_extended_port *)
{
  return 0;
}

int
be_visitor_attr_set::visit_mirror_port (be_mirror_port *)
{
  return 0;
}

int
be_visitor_attr_set::visit_porttype (be_porttype *)
{
  return 0;
}

// ==========================================================

be_visitor_facet_executor_block::be_visitor_facet_executor_block (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_facet_executor_block::~be_visitor_facet_executor_block (
  void)
{
}

int
be_visitor_facet_executor_block::visit_provides (
  be_provides *node)
{
  ACE_CString prefix (this->port_prefix_);
  prefix += node->local_name ()->get_string ();
  const char *port_name = prefix.c_str ();

  os_ << be_nl << be_nl
      << "if (ACE_OS::strcmp (name, \"" << port_name
      << "\") == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "return this->executor_->get_" << port_name
      << " ();" << be_uidt_nl
      << "}" << be_uidt;

  return 0;
}

// ======================================================

be_visitor_connect_block::be_visitor_connect_block (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_connect_block::~be_visitor_connect_block (void)
{
}

int
be_visitor_connect_block::visit_uses (be_uses *node)
{
  ACE_CString prefix (this->port_prefix_);
  prefix += node->local_name ()->get_string ();
  const char *port_name = prefix.c_str ();

  const char *obj_name = node->uses_type ()->full_name ();
  bool const is_multiple = node->is_multiple ();

  os_ << be_nl << be_nl
      << "if (ACE_OS::strcmp (name, \"" << port_name
      << "\") == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "::" << obj_name << "_var _ciao_conn =" << be_idt_nl
      << "::" << obj_name << "::_narrow (connection);"
      << be_uidt_nl << be_nl;

  if (node->uses_type ()->is_local ())
    {
      // @@todo: placeholder for connection logic
      os_ << "/// " << (is_multiple ? "Multiplex" : "Simplex")
          << " connect." << be_nl
          << (is_multiple ? "return " : "") << "this->context_->connect_"
          << port_name << " (_ciao_conn.in ());";
    }
  else
    {
      os_ << "if ( ::CORBA::is_nil (_ciao_conn.in ()))" << be_idt_nl
          << "{" << be_idt_nl
          << "throw ::Components::InvalidConnection ();" << be_uidt_nl
          << "}" << be_uidt_nl << be_nl;
      os_ << "/// " << (is_multiple ? "Multiplex" : "Simplex")
          << " connect." << be_nl
          << (is_multiple ? "return " : "") << "this->connect_"
          << port_name << " (_ciao_conn.in ());";

    }

  if (! is_multiple)
    {
      os_ << be_nl << be_nl
          << "return 0;";
    }

  os_ << be_uidt_nl
      << "}" << be_uidt;

  return 0;
}

// ======================================================

be_visitor_disconnect_block::be_visitor_disconnect_block (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_disconnect_block::~be_visitor_disconnect_block (
  void)
{
}

int
be_visitor_disconnect_block::visit_uses (be_uses *node)
{
  ACE_CString prefix (this->port_prefix_);
  prefix += node->local_name ()->get_string ();
  const char *port_name = prefix.c_str ();

  bool is_multiple = node->is_multiple ();

  if (node->uses_type ()->is_local ())
    {
      // @@ placeholder for local interface behavior
    }
  else
    {
      os_ << be_nl << be_nl
          << "if (ACE_OS::strcmp (name, \"" << port_name
          << "\") == 0)" << be_idt_nl
          << "{" << be_idt_nl
          << "/// " << (is_multiple ? "Multiplex" : "Simplex")
          << " disconnect." << be_nl;

      if (is_multiple)
        {
          os_ << "if (ck == 0)" << be_idt_nl
              << "{" << be_idt_nl
              << "throw ::Components::CookieRequired ();" << be_uidt_nl
              << "}" << be_uidt_nl << be_nl;
        }

      os_ << "return this->disconnect_" << port_name
          << " (" << (is_multiple ? "ck" : "") << ");" << be_uidt_nl
          << "}" << be_uidt;
    }

  return 0;
}

// ======================================================

be_visitor_receptacle_desc::be_visitor_receptacle_desc (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx),
    slot_ (0UL)
{
}

be_visitor_receptacle_desc::~be_visitor_receptacle_desc (
  void)
{
}

int
be_visitor_receptacle_desc::visit_uses (be_uses *node)
{
  ACE_CString prefix (this->port_prefix_);
  prefix += node->local_name ()->get_string ();
  const char *port_name = prefix.c_str ();

  AST_Type *obj = node->uses_type ();
  bool is_multiple = node->is_multiple ();

  os_ << be_nl << be_nl;

  bool gen_guard = is_multiple && ! static_config_;

  if (gen_guard)
    {
      os_ << "{" << be_idt_nl
          << "ACE_READ_GUARD_RETURN (TAO_SYNCH_MUTEX," << be_nl
          << "                       mon," << be_nl
          << "                       this->context_->"
          << port_name << "_lock_," << be_nl
          << "                       0);" << be_nl << be_nl;
    }

  os_ << "::CIAO::Servant::describe_"
      << (is_multiple ? "multiplex" : "simplex")
      << "_receptacle<" << be_idt_nl
      << "::" << obj->full_name () << "_var> (" << be_idt_nl
      << "\"" << port_name << "\"," << be_nl
      << "\"" << obj->repoID () << "\"," << be_nl
      << "this->context_->ciao_uses_"
      << port_name << "_," << be_nl
      << "safe_retval," << be_nl
      << slot_++ << "UL);" << be_uidt << be_uidt;

  if (gen_guard)
    {
      os_ << be_uidt_nl
          << "}";
    }

  return 0;
}

// ======================================================

be_visitor_subscribe_block::be_visitor_subscribe_block (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_subscribe_block::~be_visitor_subscribe_block (
  void)
{
}

int
be_visitor_subscribe_block::visit_publishes (
  be_publishes *node)
{
  const char *obj_name =
    node->publishes_type ()->full_name ();
  const char *port_name =
    node->local_name ()->get_string ();

  os_ << be_nl << be_nl
      << "if (ACE_OS::strcmp (publisher_name, \""
      << port_name << "\") == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "::" << obj_name << "Consumer_var sub =" << be_idt_nl
      << "::" << obj_name << "Consumer::_narrow (subscribe);"
      << be_uidt_nl << be_nl
      << "if ( ::CORBA::is_nil (sub.in ()))" << be_idt_nl
      << "{" << be_idt_nl
      << "::CORBA::Boolean const substitutable =" << be_idt_nl
      << "subscribe->ciao_is_substitutable (" << be_idt_nl
      << "::" << obj_name
      << "::_tao_obv_static_repository_id ());"
      << be_uidt << be_uidt_nl << be_nl
      << "if (substitutable)" << be_idt_nl
      << "{" << be_idt_nl
      << "return this->subscribe_" << port_name
      << "_generic (subscribe);" << be_uidt_nl
      << "}" << be_uidt_nl
      << "else" << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::Components::InvalidConnection ();" << be_uidt_nl
      << "}" << be_uidt << be_uidt_nl
      << "}" << be_uidt_nl
      << "else" << be_idt_nl
      << "{" << be_idt_nl
      << "return this->subscribe_" << port_name
      << " (sub.in ());" << be_uidt_nl
      << "}" << be_uidt << be_uidt_nl
      << "}" << be_uidt;

  return 0;
}

// ==========================================================

be_visitor_unsubscribe_block::be_visitor_unsubscribe_block (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_unsubscribe_block::~be_visitor_unsubscribe_block (
  void)
{
}

int
be_visitor_unsubscribe_block::visit_publishes (
  be_publishes *node)
{
  const char *port_name =
    node->local_name ()->get_string ();

  os_ << be_nl << be_nl
      << "if (ACE_OS::strcmp (publisher_name, \""
      << port_name << "\") == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "return this->unsubscribe_" << port_name
      << " (ck);" << be_uidt_nl
      << "}" << be_uidt;

  return 0;
}

// ==========================================================

be_visitor_event_source_desc::be_visitor_event_source_desc (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx),
    slot_ (0UL)
{
}

be_visitor_event_source_desc::~be_visitor_event_source_desc (
  void)
{
}

int
be_visitor_event_source_desc::visit_publishes (
  be_publishes *node)
{
  AST_Type *obj = node->publishes_type ();
  const char *port_name =
    node->local_name ()->get_string ();

  os_ << be_nl << be_nl;

  if (! static_config_)
    {
      os_ << "{" << be_idt_nl
          << "ACE_READ_GUARD_RETURN (TAO_SYNCH_MUTEX," << be_nl
          << "                       mon," << be_nl
          << "                       this->context_->"
          << port_name << "_lock_," << be_nl
          << "                       0);" << be_nl << be_nl;
    }

  os_ << "::CIAO::Servant::describe_pub_event_source<"
      << be_idt_nl
      << "::" << obj->full_name () << "Consumer_var> ("
      << be_idt_nl
      << "\"" << port_name << "\"," << be_nl
      << "\"" << obj->repoID () << "\"," << be_nl
      << "this->context_->ciao_publishes_"
      << port_name << "_," << be_nl
      << "safe_retval," << be_nl
      << slot_++ << "UL);" << be_uidt << be_uidt;

  if (! be_global->gen_ciao_static_config ())
    {
      os_ << be_uidt_nl
          << "}";
    }

  return 0;
}

// ======================================================

be_visitor_connect_consumer_block::be_visitor_connect_consumer_block (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_connect_consumer_block::~be_visitor_connect_consumer_block (void)
{
}

int
be_visitor_connect_consumer_block::visit_emits (
  be_emits *node)
{
  const char *obj_name =
    node->emits_type ()->full_name ();
  const char *port_name =
    node->local_name ()->get_string ();

  os_ << be_nl << be_nl
      << "if (ACE_OS::strcmp (emitter_name, \""
      << port_name << "\") == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "::" << obj_name
      << "Consumer_var _ciao_consumer =" << be_idt_nl
      << "::" << obj_name
      << "Consumer::_narrow (consumer);" << be_uidt_nl << be_nl
      << "if ( ::CORBA::is_nil (_ciao_consumer.in ()))"
      << be_idt_nl
      << "{" << be_idt_nl
      << "throw ::Components::InvalidConnection ();" << be_uidt_nl
      << "}" << be_uidt_nl << be_nl
      << "this->connect_" << port_name
      << " (_ciao_consumer.in ());" << be_nl << be_nl
      << "return;" << be_uidt_nl
      << "}" << be_uidt;

  return 0;
}

// ======================================================

be_visitor_disconnect_consumer_block::be_visitor_disconnect_consumer_block (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_disconnect_consumer_block::~be_visitor_disconnect_consumer_block (
  void)
{
}

int
be_visitor_disconnect_consumer_block::visit_emits (
  be_emits *node)
{
  const char *port_name =
    node->local_name ()->get_string ();

  os_ << be_nl << be_nl
      << "if (ACE_OS::strcmp (source_name, \""
      << port_name << "\") == 0)" << be_idt_nl
      << "{" << be_idt_nl
      << "return this->disconnect_" << port_name
      << " ();" << be_uidt_nl
      << "}" << be_uidt;

  return 0;
}

// ======================================================

be_visitor_emitter_desc::be_visitor_emitter_desc (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx),
    slot_ (0UL)
{
}

be_visitor_emitter_desc::~be_visitor_emitter_desc (
  void)
{
}

int
be_visitor_emitter_desc::visit_emits (be_emits *node)
{
  AST_Type *obj = node->emits_type ();
  const char *port_name =
    node->local_name ()->get_string ();

  os_ << be_nl << be_nl
      << "::CIAO::Servant::describe_emit_event_source<"
      << be_idt_nl
      << "::" << obj->full_name () << "Consumer_var> ("
      << be_idt_nl
      << "\"" << port_name << "\"," << be_nl
      << "\"" << obj->repoID () << "\"," << be_nl
      << "this->context_->ciao_emits_" << port_name
      << "_consumer_," << be_nl
      << "safe_retval," << be_nl
      << slot_++ << "UL);" << be_uidt << be_uidt;

  return 0;
}

// ======================================================

be_visitor_populate_port_tables::be_visitor_populate_port_tables (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_populate_port_tables::~be_visitor_populate_port_tables (
  void)
{
}

int
be_visitor_populate_port_tables::visit_provides (
  be_provides *node)
{
  ACE_CString prefix (this->port_prefix_);
  prefix += node->local_name ()->get_string ();
  const char *port_name = prefix.c_str ();

  if (node->provides_type ()->is_local ())
    {
      // @@ placeholder for local interface behavior.
    }
  else
    {
      os_ << be_nl
          << "obj_var = this->provide_"
          << port_name << "_i ();";
    }

  return 0;
}

int
be_visitor_populate_port_tables::visit_consumes (
  be_consumes *node)
{
  os_ << be_nl
      << "ecb_var = this->get_consumer_"
      << node->local_name ()->get_string () << "_i ();";

  return 0;
}

// ======================================================

Component_Op_Attr_Generator::Component_Op_Attr_Generator (
    be_visitor_scope * visitor)
  : visitor_ (visitor)
{
}

int
Component_Op_Attr_Generator::emit (be_interface * /* derived_interface */,
                                   TAO_OutStream * /* os */,
                                   be_interface * base_interface)
{
  if (base_interface->node_type () == AST_Decl::NT_component)
    {
      return 0;
    }

  return visitor_->visit_scope (base_interface);
}

