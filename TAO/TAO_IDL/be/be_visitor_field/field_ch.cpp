
//=============================================================================
/**
 *  @file    field_ch.cpp
 *
 *  $Id$
 *
 *  Visitor generating code for Field node in the client header
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================

#include "be_visitor_enum/enum_ch.h"
#include "be_visitor_sequence/sequence_ch.h"
#include "nr_extern.h"

// **********************************************
//  Visitor for field in the client header file.
// **********************************************

be_visitor_field_ch::be_visitor_field_ch (be_visitor_context *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_field_ch::~be_visitor_field_ch (void)
{
}

int
be_visitor_field_ch::visit_field (be_field *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt = be_type::narrow_from_decl (node->field_type ());

  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_field_ch::"
                         "visit_field - "
                         "Bad field type\n"),
                        -1);
    }

  this->ctx_->node (node);

  *os << be_nl;

  if (bt->accept (this) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_field_ch::"
                         "visit_field - "
                         "codegen for field type failed\n"),
                        -1);
    }

  // Now output the field name.
  *os << " " << node->local_name () << ";";

  return 0;
}

// Visit operations on all possible data types  that a field can be.

int
be_visitor_field_ch::visit_array (be_array *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt = 0;

  if (this->ctx_->alias ())
    {
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  // If not a typedef and we are defined in the use scope, we must be defined.
  if (!this->ctx_->alias ()
      && node->is_child (this->ctx_->scope ()->decl ()))
    {
      // This is the case for anonymous arrays.

      // Instantiate a visitor context with a copy of our context. This info
      // will be modified based on what type of node we are visiting
      be_visitor_context ctx (*this->ctx_);
      ctx.node (node); // set the node to be the node being visited. The scope
                       // is still the same

      // First generate the array declaration
      ctx.state (TAO_CodeGen::TAO_ARRAY_CH);
      be_visitor_array_ch visitor (&ctx);

      if (node->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_field_ch::"
                             "visit_array - "
                             "codegen failed\n"),
                            -1);
        }

      ctx.state (TAO_CodeGen::TAO_ROOT_CH);

      // Having defined all array type and its supporting operations, now
      // generate the actual variable that is a field of the structure.
      *os << be_nl_2 << "_" << bt->local_name ();
    }
  else
    {
      // This was a typedefed array.
      // ACE_NESTED_CLASS macro generated by nested_type_name
      // is necessary if the struct, union, or valuetype containing this
      // field was not defined inside a module. In such a case, VC++
      // complains that the non-module scope is not yet fully defined.
      UTL_Scope *holds_container =
        this->ctx_->scope ()->decl ()->defined_in ();
      AST_Decl *hc_decl = ScopeAsDecl (holds_container);

      if (hc_decl->node_type () != AST_Decl::NT_module)
        {
          *os << bt->nested_type_name (this->ctx_->scope ()->decl ());
        }
      else
        {
          *os << bt->name ();
        }
    }

  return 0;
}

int
be_visitor_field_ch::visit_enum (be_enum *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt = 0;

  if (this->ctx_->alias ())
    {
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  // If not a typedef and we are defined in the use scope, we must be defined.
  if (!this->ctx_->alias () // not a typedef
      && node->is_child (this->ctx_->scope ()->decl ()))
    {
      // Instantiate a visitor context with a copy of our context. This info
      // will be modified based on what type of node we are visiting.
      be_visitor_context ctx (*this->ctx_);
      ctx.node (node);

      // First generate the enum declaration.
      be_visitor_enum_ch visitor (&ctx);

      if (node->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_field_ch::"
                             "visit_enum - "
                             "codegen failed\n"),
                            -1);
        }
    }

  // This was a typedefed array.
  // ACE_NESTED_CLASS macro generated by nested_type_name
  // is necessary if the struct, union, or valuetype containing this
  // field was not defined inside a module. In such a case, VC++
  // complains that the non-module scope is not yet fully defined.
  UTL_Scope *holds_container =
    this->ctx_->scope ()->decl ()->defined_in ();
  AST_Decl *hc_decl = ScopeAsDecl (holds_container);

  if (hc_decl->node_type () != AST_Decl::NT_module)
    {
      *os << bt->nested_type_name (this->ctx_->scope ()->decl ());
    }
  else
    {
      *os << bt->name ();
    }

  return 0;
}

int
be_visitor_field_ch::visit_interface (be_interface *node)
{
  return this->emit_common (node);
}

int
be_visitor_field_ch::visit_interface_fwd (be_interface_fwd *node)
{
  return this->emit_common (node);
}

int
be_visitor_field_ch::visit_valuebox (be_valuebox *node)
{
  return this->emit_common (node);
}

int
be_visitor_field_ch::visit_valuetype (be_valuetype *node)
{
  return this->emit_common (node);
}

int
be_visitor_field_ch::visit_valuetype_fwd (be_valuetype_fwd *node)
{
  return this->emit_common (node);
}


int
be_visitor_field_ch::emit_common (be_type *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt = 0;

  if (this->ctx_->alias ())
    {
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  // ACE_NESTED_CLASS macro generated by nested_type_name
  // is necessary if the struct, union, or valuetype containing this
  // field was not defined inside a module. In such a case, VC++
  // complains that the non-module scope is not yet fully defined.
  UTL_Scope *holds_container =
    this->ctx_->scope ()->decl ()->defined_in ();
  AST_Decl *hc_decl = ScopeAsDecl (holds_container);

  if (hc_decl->node_type () != AST_Decl::NT_module)
    {
      *os << bt->nested_type_name (this->ctx_->scope ()->decl (), "_var");
    }
  else
    {
      *os << bt->name () << "_var";
    }

  return 0;
}

int
be_visitor_field_ch::visit_predefined_type (be_predefined_type *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt = 0;
  be_typedef *td = this->ctx_->alias ();

  if (td != 0)
    {
      bt = td;
    }
  else
    {
      bt = node;
    }

  *os << bt->nested_type_name (this->ctx_->scope ()->decl ());

  switch (node->pt ())
    {
      case AST_PredefinedType::PT_object:
      case AST_PredefinedType::PT_abstract:
      case AST_PredefinedType::PT_pseudo:
        *os << "_var";
        break;
      case AST_PredefinedType::PT_value:
        *os << " *";
        break;
      default:
        break;
    }

  return 0;
}

int
be_visitor_field_ch::visit_sequence (be_sequence *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt = 0;

  if (this->ctx_->alias ())
    {
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  if (!this->ctx_->alias ()
      && node->is_child (this->ctx_->scope ()->decl ()))
    {
      // Put the field node into the (anonymous) sequence node, to be
      // used later for unique name generation.
      be_field *member_node =
        be_field::narrow_from_decl (this->ctx_->node ());
      node->field_node (member_node);

      // This was already generated in the corresponding valuetype class.
      if (this->ctx_->state () != TAO_CodeGen::TAO_VALUETYPE_OBV_CH)
        {
          be_visitor_context ctx (*this->ctx_);
          ctx.node (node);

          // First generate the sequence declaration.
          be_visitor_sequence_ch visitor (&ctx);

          if (node->accept (&visitor) == -1)
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                "(%N:%l) be_visitor_field_ch::"
                                "visit_sequence - "
                                "codegen failed\n"),
                                -1);
            }
        }

      // If we are being reused by valutype, this would get generated
      // in the private section of the OBV_xx class, so we must
      // generate the typedef for that case elsewhere.
      AST_Decl::NodeType snt =
        this->ctx_->scope ()->decl ()->node_type ();

      if (snt != AST_Decl::NT_valuetype && snt != AST_Decl::NT_eventtype)
        {
          // Generate the anonymous sequence member typedef.
          be_decl *bs = this->ctx_->scope ()->decl ();

          *os << be_nl_2 << "// TAO_IDL - Generated from" << be_nl
              << "// " << __FILE__ << ":" << __LINE__ << be_nl_2;

          *os << "typedef " << bt->nested_type_name (bs)
              << " _" << this->ctx_->node ()->local_name ()
              << "_seq;" << be_nl;
        }
    }

  // ACE_NESTED_CLASS macro generated by nested_type_name
  // is not necessary in all cases.
  be_typedef *tdef = be_typedef::narrow_from_decl (bt);

  // This was a typedefed array.
  // ACE_NESTED_CLASS macro generated by nested_type_name
  // is necessary if the struct, union, or valuetype containing this
  // field was not defined inside a module. In such a case, VC++
  // complains that the non-module scope is not yet fully defined.
  UTL_Scope *holds_container =
    this->ctx_->scope ()->decl ()->defined_in ();
  AST_Decl *hc_decl = ScopeAsDecl (holds_container);

  if (hc_decl->node_type () != AST_Decl::NT_module
      || !tdef)
    {
      *os << bt->nested_type_name (this->ctx_->scope ()->decl ());
    }
  else
    {
      *os << bt->name ();
    }

  return 0;
}

int
be_visitor_field_ch::visit_string (be_string *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  if (node->width () == (long) sizeof (char))
    {
      *os << "::TAO::String_Manager";
    }
  else
    {
      *os << "::TAO::WString_Manager";
    }

  return 0;
}

int
be_visitor_field_ch::visit_structure (be_structure *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt = 0;

  if (this->ctx_->alias ())
    {
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  if (!this->ctx_->alias () // not a typedef
      && node->is_child (this->ctx_->scope ()->decl ()))
    {
      be_visitor_context ctx (*this->ctx_);
      ctx.node (node);

      be_visitor_structure_ch visitor (&ctx);

      if (node->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_field_ch::"
                             "visit_struct - "
                             "codegen failed\n"),
                            -1);
        }
    }

  // This was a typedefed array.
  // ACE_NESTED_CLASS macro generated by nested_type_name
  // is necessary if the struct, union, or valuetype containing this
  // field was not defined inside a module. In such a case, VC++
  // complains that the non-module scope is not yet fully defined.
  UTL_Scope *holds_container =
    this->ctx_->scope ()->decl ()->defined_in ();
  AST_Decl *hc_decl = ScopeAsDecl (holds_container);

  if (hc_decl->node_type () != AST_Decl::NT_module)
    {
      *os << bt->nested_type_name (this->ctx_->scope ()->decl ());
    }
  else
    {
      *os << bt->name ();
    }

  return 0;
}

int
be_visitor_field_ch::visit_structure_fwd (be_structure_fwd *node)
{
  be_structure *s =
    be_structure::narrow_from_decl (node->full_definition ());

  return this->visit_structure (s);
}

int
be_visitor_field_ch::visit_typedef (be_typedef *node)
{
  this->ctx_->alias (node);

  // Make a decision based on the primitive base type.
  be_type *bt = node->primitive_base_type ();

  if (!bt || (bt->accept (this) == -1))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_field_ch::"
                         "visit_typedef - "
                         "Bad primitive type\n"),
                        -1);
    }

  // Reset the alias.
  this->ctx_->alias (0);
  return 0;
}

int
be_visitor_field_ch::visit_union (be_union *node)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt = 0;

  if (this->ctx_->alias ())
    {
      bt = this->ctx_->alias ();
    }
  else
    {
      bt = node;
    }

  if (!this->ctx_->alias ()
      && node->is_child (this->ctx_->scope ()->decl ()))
    {
      be_visitor_context ctx (*this->ctx_);
      ctx.node (node);

      be_visitor_union_ch visitor (&ctx);

      if (node->accept (&visitor) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_field_ch::"
                             "visit_union - "
                             "codegen failed\n"),
                            -1);
        }
    }

  *os << be_nl_2;

  // This was a typedefed array.
  // ACE_NESTED_CLASS macro generated by nested_type_name
  // is necessary if the struct, union, or valuetype containing this
  // field was not defined inside a module. In such a case, VC++
  // complains that the non-module scope is not yet fully defined.
  UTL_Scope *holds_container =\
    this->ctx_->scope ()->decl ()->defined_in ();
  AST_Decl *hc_decl = ScopeAsDecl (holds_container);

  if (hc_decl->node_type () != AST_Decl::NT_module)
    {
      *os << bt->nested_type_name (this->ctx_->scope ()->decl ());
    }
  else
    {
      *os << bt->name ();
    }

  return 0;
}

int
be_visitor_field_ch::visit_union_fwd (be_union_fwd *node)
{
  be_union *u =
    be_union::narrow_from_decl (node->full_definition ());

  return this->visit_union (u);
}

int
be_visitor_field_ch::visit_component (
    be_component *node
  )
{
  return this->visit_interface (node);
}

int
be_visitor_field_ch::visit_component_fwd (
    be_component_fwd *node
  )
{
  return this->visit_interface_fwd (node);
}

int
be_visitor_field_ch::visit_eventtype (
    be_eventtype *node
  )
{
  return this->visit_valuetype (node);
}

int
be_visitor_field_ch::visit_eventtype_fwd (
    be_eventtype_fwd *node
  )
{
  return this->visit_valuetype_fwd (node);
}


