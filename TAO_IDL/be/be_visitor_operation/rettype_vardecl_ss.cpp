//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    rettype_vardecl_ss.cpp
//
// = DESCRIPTION
//    Visitor generating code for return type variable declaration in the
//    skeleton file.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_operation, 
           rettype_vardecl_ss, 
           "$Id$")

// ************************************************************************
//    be_visitor_operation_rettype_vardecl_ss
//    This visitor generates code for variable declaration and initialization
//    of the return type.
// ************************************************************************

be_visitor_operation_rettype_vardecl_ss::
be_visitor_operation_rettype_vardecl_ss (be_visitor_context *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_operation_rettype_vardecl_ss::
~be_visitor_operation_rettype_vardecl_ss (void)
{
}

int
be_visitor_operation_rettype_vardecl_ss::visit_array (be_array *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << "_var _tao_retval;";

  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::visit_enum (be_enum *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << " _tao_retval;";
  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::visit_interface (be_interface *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << "::" << node->name () << "_var _tao_retval;";
  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::
visit_interface_fwd (be_interface_fwd *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << "::" << node->name () << "_var _tao_retval;";
  return 0;
}

// Like be_visitor_operation_rettype_vardecl_ss.
int
be_visitor_operation_rettype_vardecl_ss::visit_valuetype (be_valuetype *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << "::" << node->name () << "_var _tao_retval;";
  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::
visit_valuetype_fwd (be_valuetype_fwd *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  *os << "::" << node->name () << "_var _tao_retval;";
  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::
visit_predefined_type (be_predefined_type *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  switch (node->pt ())
    {
    case AST_PredefinedType::PT_pseudo:
    case AST_PredefinedType::PT_object:
      *os << bt->name () << "_var _tao_retval;";
      break;
    case AST_PredefinedType::PT_any:
      *os << bt->name () << "_var _tao_retval;";
      break;
    case AST_PredefinedType::PT_void:
      break;
    case AST_PredefinedType::PT_longdouble:
      *os << bt->name ()
          << " _tao_retval = ACE_CDR_LONG_DOUBLE_INITIALIZER;";
      break;
    case AST_PredefinedType::PT_longlong:
      *os << bt->name ()
          << " _tao_retval = ACE_CDR_LONGLONG_INITIALIZER;";
      break;
    default:
      *os << bt->name () << " _tao_retval = 0;";
      break;
    }
  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::visit_sequence (be_sequence *node)
{
  // We should never directly be here because anonymous sequence return types
  // are not allowed.
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  *os << "::" << bt->name () << "_var _tao_retval;";
  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::visit_string (be_string *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  if (node->width () == (long) sizeof (char))
    {
      *os << "CORBA::String_var _tao_retval;";
    }
  else
    {
      *os << "CORBA::WString_var _tao_retval;";
    }

  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::visit_structure (be_structure *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  // Based on whether we are variable or not, we return a pointer or the
  // aggregate type.
  if (node->size_type () == AST_Type::VARIABLE)
    {
      *os << "::" << bt->name () << "_var _tao_retval;";
    }
  else
    {
      *os << "::" << bt->name () << " _tao_retval;";
    }

  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::visit_typedef (be_typedef *node)
{
  this->ctx_->alias (node);

  if (node->primitive_base_type ()->accept (this) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_operation_rettype_vardecl_ss::"
                         "visit_typedef - "
                         "accept on primitive type failed\n"),
                        -1);
    }

  this->ctx_->alias (0);
  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::visit_union (be_union *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt;

  if (this->ctx_->alias ())
    {
      // A typedefed return type.
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  // Based on whether we are variable or not, we return a pointer or the
  // aggregate type.
  if (node->size_type () == AST_Type::VARIABLE)
    {
      *os << "::" << bt->name () << "_var _tao_retval;";
    }
  else
    {
      *os << "::" << bt->name () << " _tao_retval;";
    }

  return 0;
}

int
be_visitor_operation_rettype_vardecl_ss::visit_eventtype (be_eventtype *node)
{
  return this->visit_valuetype (node);
}

int
be_visitor_operation_rettype_vardecl_ss::visit_eventtype_fwd (
    be_eventtype_fwd *node
  )
{
  return this->visit_valuetype_fwd (node);
}

int
be_visitor_operation_rettype_vardecl_ss::visit_component (be_component *node)
{
  return this->visit_interface (node);
}

int
be_visitor_operation_rettype_vardecl_ss::visit_component_fwd (
    be_component_fwd *node
  )
{
  return this->visit_interface_fwd (node);
}

int
be_visitor_operation_rettype_vardecl_ss::visit_home (be_home *node)
{
  return this->visit_interface (node);
}


