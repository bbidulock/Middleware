//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    arglist.cpp
//
// = DESCRIPTION
//    Visitor generating the parameter list of operations
//    in the Valuetype class.
//
// = AUTHOR
//    Torsten Kuepper  <kuepper2@lfa.uni-wuppertal.de>
//    based on code from Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_valuetype,
           arglist,
           "$Id$")

// ************************************************************
//   Operation visitor to generate the argument list.
//   We have separated code generation for this from the 4 main
//   visitors to avoid code duplication and tight coupling.
// ************************************************************

be_visitor_obv_operation_arglist::be_visitor_obv_operation_arglist (
    be_visitor_context *ctx
  )
  : be_visitor_scope (ctx)
{
}

be_visitor_obv_operation_arglist::~be_visitor_obv_operation_arglist (void)
{
}

bool
be_visitor_obv_operation_arglist::is_amh_exception_holder (be_operation *node)
{
  UTL_Scope *scope = node->defined_in ();
  be_interface *iface = be_interface::narrow_from_scope (scope);

  if (iface != 0)
    {
      if (ACE_OS::strncmp (iface->local_name (), "AMH_", 4) == 0)
        {
          const char *last_E = ACE_OS::strrchr (iface->full_name (), 'E');

          if (last_E != 0
              && ACE_OS::strcmp (last_E, "ExceptionHolder") == 0)
            {
              return true;
            }
        }
    }

  return false;
}

int
be_visitor_obv_operation_arglist::visit_operation (be_operation *node)
{
  bool amh_valuetype = this->is_amh_exception_holder (node);
  TAO_OutStream *os = this->ctx_->stream ();

  *os << " (";

  if (!be_global->exception_support () || node->nmembers () > 0)
    {
      *os << be_idt << be_idt_nl;

      // All we do is hand over code generation to our scope.
      if (this->visit_scope (node) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                            "(%N:%l) be_visitor_obv_operation_arglist::"
                            "visit_operation - "
                            "codegen for scope failed\n"),
                            -1);
        }

      // Generate the ACE_ENV_ARG_DECL parameter for the alternative mapping.
      if (!be_global->exception_support ())
        {
          /***********************************************************/
          // If it ian an AMHExceptionHolder we are going to generate the
          // function definition "in-place" right here.  Also all
          // AMHExceptionHolder 'raise' methods do not take any
          // parameters.  So always declare
          // ACE_ENV_SINGLE_ARG_DECL_NOT_USED when generating argument
          // list for AMHExceptioHolders
          /***********************************************************/
          if (amh_valuetype)
            {
              *os << (be_global->use_raw_throw ()
                        ? ""
                        : "ACE_ENV_SINGLE_ARG_DECL");
            }
          /***********************************************************/
          else
            {
              // Use ACE_ENV_SINGLE_ARG_DECL or ACE_ENV_ARG_DECL
              // depending on whether the operation node has parameters.

              if (node->argument_count () == 0)
                {
                  *os << (be_global->use_raw_throw ()
                            ? ""
                            : " ACE_ENV_SINGLE_ARG_DECL");
                }
              else
                {
                  *os << (be_global->use_raw_throw ()
                            ? ""
                            : " ACE_ENV_ARG_DECL");
                }
            }

          if (!amh_valuetype)
            {
              switch (this->ctx_->state ())
                {
                case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_CH:
                  // Last argument - is always ACE_ENV_ARG_DECL.
                  *os << (be_global->use_raw_throw ()
                            ? ""
                            : "_WITH_DEFAULTS");
                  break;
                default:
                  break;
                }
            }
        }

      *os << be_uidt_nl
          << ")";
    }
  else
    {
      *os << "void)";
    }

  be_visitor_context ctx = *this->ctx_;
  be_visitor_operation operation_visitor (&ctx);

  if (operation_visitor.gen_throw_spec (node) == -1)
    {
      return -1;
    }

  switch (this->ctx_->state ())
    {
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_CH:
      // Each method is pure virtual in the Valuetype class.
      // BUT, not if it is an AMH ExceptionHolder!
      if (amh_valuetype)
        {
          *os << ";" << be_uidt;
        }
      else
        {
          *os << " = 0;" << be_uidt;
        }
      break;
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_CS:
      *os << be_uidt;
      break;
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_IH:
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_IS:
    default:
       break;
    }

  return 0;
}

int
be_visitor_obv_operation_arglist::visit_argument (be_argument *node)
{
  be_visitor_context ctx (*this->ctx_);

  // First grab the interface definition inside which this operation is
  // defined. We need this since argument types may very well be declared
  // inside the scope of the interface node. In such cases, we would like to
  // generate the appropriate relative scoped names.
  be_operation *op = this->ctx_->be_scope_as_operation ();

  if (!op)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_arglist::"
                         "visit_argument - "
                         "Bad operation\n"),
                        -1);
    }

  // We need the interface node in which this operation was defined. However,
  // if this operation node was an attribute node in disguise, we get this
  // information from the context.
  // %! use AST_Interface
  be_interface *intf = this->ctx_->attribute ()
    ? be_interface::narrow_from_scope (this->ctx_->attribute ()->defined_in ())
    : be_interface::narrow_from_scope (op->defined_in ());

  if (!intf)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_arglist::"
                         "visit_argument - "
                         "Bad interface\n"),
                        -1);
    }

  ctx.scope (intf);
  ctx.node (node); // save the argument node

  // Retrieve the type.
  be_type *bt = be_type::narrow_from_decl (node->field_type ());

  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_args_arglist::"
                         "visit_argument - "
                         "Bad argument type\n"),
                        -1);
    }

  int status = 0;

  switch (this->ctx_->state ())
    {
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_CH:
      {
        be_visitor_args_arglist visitor (&ctx);
        status = bt->accept (&visitor);
        break;
      }
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_SH:
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_IH:
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_IS:
      {
        be_visitor_args_arglist visitor (&ctx);
        status = bt->accept (&visitor);
        break;
      }
    default:
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                           "(%N:%l) be_visitor_arglist::"
                           "visit_argument - "
                           "Bad context\n"),
                          -1);
      }
    }

  if (status == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_arglist::"
                         "visit_argument - "
                         "codegen for argument failed\n"),
                        -1);
    }

  return 0;
}

int
be_visitor_obv_operation_arglist::post_process (be_decl *bd)
// derived from be_visitor_operation_argument::post_process (be_decl *bd)
{
  TAO_OutStream *os = this->ctx_->stream ();

  switch (this->ctx_->state ())
    {
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_CH:
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_SH:
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_IH:
    case TAO_CodeGen::TAO_OBV_OPERATION_ARGLIST_IS:
      if (!this->last_node (bd))
        {
          *os << ", ";
        }
      else
        {
          *os << "";
        }

      break;
    default:
      break;
    }

  return 0;
}
