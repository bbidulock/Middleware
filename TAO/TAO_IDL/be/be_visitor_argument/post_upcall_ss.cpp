//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    post_upcall_ss.cpp
//
// = DESCRIPTION
//    Visitor generating code to do post-processing of arguments following an
//    upcall.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include "idl.h"
#include "be.h"
#include "be_visitor_argument.h"

ACE_RCSID(be_visitor_argument, post_upcall_ss, "$Id$")


// ************************************************************************
//  visitor for doing any post-processing after the upcall is made
// ************************************************************************

be_visitor_args_post_upcall_ss::be_visitor_args_post_upcall_ss (be_visitor_context *ctx)
  : be_visitor_args (ctx)
{
}

be_visitor_args_post_upcall_ss::~be_visitor_args_post_upcall_ss (void)
{
}

int be_visitor_args_post_upcall_ss::visit_argument (be_argument *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  this->ctx_->node (node); // save the argument node

  // retrieve the type
  be_type *bt = be_type::narrow_from_decl (node->field_type ());
  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_args_post_upcall_ss::"
                         "visit_argument - "
                         "Bad argument type\n"),
                        -1);
    }

  // Different types have different mappings when used as in/out or
  // inout parameters. Let this visitor deal with the type

  if (bt->accept (this) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_args_post_upcall_ss::"
                         "visit_argument - "
                         "cannot accept visitor\n"),
                        -1);
    }

  return 0;
}

int be_visitor_args_post_upcall_ss::visit_array (be_array *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream

  switch (this->direction ())
    {
    case AST_Argument::dir_IN:
      break;
    case AST_Argument::dir_INOUT:
      break;
    case AST_Argument::dir_OUT:
      break;
    }
  return 0;
}

int be_visitor_args_post_upcall_ss::visit_enum (be_enum *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream

  switch (this->direction ())
    {
    case AST_Argument::dir_IN:
      break;
    case AST_Argument::dir_INOUT:
      break;
    case AST_Argument::dir_OUT:
      break;
    }
  return 0;
}

int be_visitor_args_post_upcall_ss::visit_interface (be_interface *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  be_argument *arg = this->ctx_->be_node_as_argument (); // get the argument
                                                         // node
  switch (this->direction ())
    {
    case AST_Argument::dir_IN:
      break;
    case AST_Argument::dir_INOUT: // inout
    case AST_Argument::dir_OUT:
      os->indent ();
      *os << "_tao_base_var_" << arg->local_name ()
	  << " = CORBA::Object::_duplicate ("
	  << arg->local_name () << ".in ());\n";
      break;
    }
  return 0;
}

int be_visitor_args_post_upcall_ss::visit_interface_fwd (be_interface_fwd *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  be_argument *arg = this->ctx_->be_node_as_argument (); // get the argument
                                                         // node
  switch (this->direction ())
    {
    case AST_Argument::dir_IN:
      break;
    case AST_Argument::dir_INOUT: // inout
    case AST_Argument::dir_OUT:
      os->indent ();
      *os << "_tao_base_var_" << arg->local_name ()
	  << " = CORBA::Object::_duplicate ("
	  << arg->local_name () << ".in ());\n";
      break;
    }
  return 0;
}

int be_visitor_args_post_upcall_ss::visit_predefined_type (be_predefined_type *node)
{
  // check if the type is an any
  if (node->pt () == AST_PredefinedType::PT_any)
    {
      switch (this->direction ())
	{
	case AST_Argument::dir_IN:
	  break;
	case AST_Argument::dir_INOUT:
	  break;
	case AST_Argument::dir_OUT:
	  break;
	} // end switch direction
    } // end of if
  else if (node->pt () == AST_PredefinedType::PT_pseudo) // e.g., CORBA::Object
    {
      switch (this->direction ())
	{
	case AST_Argument::dir_IN:
	  break;
	case AST_Argument::dir_INOUT:
	  break;
	case AST_Argument::dir_OUT:
	  break;
	} // end switch direction
    } // end else if
  else // simple predefined types
    {
      switch (this->direction ())
	{
	case AST_Argument::dir_IN:
	  break;
	case AST_Argument::dir_INOUT:
	  break;
	case AST_Argument::dir_OUT:
	  break;
	} // end switch direction
    } // end of else

  return 0;
}

int be_visitor_args_post_upcall_ss::visit_sequence (be_sequence *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get the stream

  switch (this->direction ())
    {
    case AST_Argument::dir_IN:
      break;
    case AST_Argument::dir_INOUT:
      break;
    case AST_Argument::dir_OUT:
      break;
    }
  return 0;
}

int be_visitor_args_post_upcall_ss::visit_string (be_string *)
{
  TAO_OutStream *os = this->ctx_->stream (); // get the stream

  switch (this->direction ())
    {
    case AST_Argument::dir_IN:
      break;
    case AST_Argument::dir_INOUT:
      break;
    case AST_Argument::dir_OUT:
      break;
    }
  return 0;
}

int be_visitor_args_post_upcall_ss::visit_structure (be_structure *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get the stream

  switch (this->direction ())
    {
    case AST_Argument::dir_IN:
      break;
    case AST_Argument::dir_INOUT:
      break;
    case AST_Argument::dir_OUT:
      break;
    }
  return 0;
}

int be_visitor_args_post_upcall_ss::visit_union (be_union *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get the stream

  switch (this->direction ())
    {
    case AST_Argument::dir_IN:
      break;
    case AST_Argument::dir_INOUT:
      break;
    case AST_Argument::dir_OUT:
      break;
    }
  return 0;
}

int be_visitor_args_post_upcall_ss::visit_typedef (be_typedef *node)
{
  this->ctx_->alias (node);
  if (node->primitive_base_type ()->accept (this) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_args_post_upcall_ss::"
                         "visit_typedef - "
                         "accept on primitive type failed\n"),
                        -1);
    }
  this->ctx_->alias (0);
  return 0;
}
