//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    operation_cs.cpp
//
// = DESCRIPTION
//    Visitor generating code for Operation in the stubs file.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include	"idl.h"
#include	"idl_extern.h"
#include	"be.h"

#include "be_visitor_operation.h"

ACE_RCSID(be_visitor_operation, operation_cs, "$Id$")


// ************************************************************
// Operation visitor for client stubs
// ************************************************************

be_visitor_operation_cs::be_visitor_operation_cs (be_visitor_context *ctx)
  : be_visitor_operation (ctx)
{
}

be_visitor_operation_cs::~be_visitor_operation_cs (void)
{
}

// processing to be done after every element in the scope is processed
int
be_visitor_operation_cs::post_process (be_decl *bd)
{
  // all we do here is to insert a comma and a newline
  TAO_OutStream *os = this->ctx_->stream ();
  if (!this->last_node (bd))
    *os << ",\n";
  return 0;
}

int
be_visitor_operation_cs::visit_operation (be_operation *node)
{
  TAO_OutStream *os; // output stream
  be_type *bt;       // type node
  be_visitor_context ctx;  // visitor context
  be_visitor *visitor; // visitor

  os = this->ctx_->stream ();
  this->ctx_->node (node); // save the node for future use

  os->indent (); // start with the current indentation level

  // retrieve the operation return type
  bt = be_type::narrow_from_decl (node->return_type ());
  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_cs::"
                         "visit_operation - "
                         "Bad return type\n"),
                        -1);
    }

  // Generate the return type mapping (same as in the header file)
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_RETTYPE_OTHERS);
  visitor = tao_cg->make_visitor (&ctx);

  if ((!visitor) || (bt->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_cs::"
                         "visit_operation - "
                         "codegen for return type failed\n"),
                        -1);
    }
  delete visitor;

  // Generate the operation name
  *os << " " << node->name ();

  // Generate the argument list with the appropriate mapping (same as
  // in the header file)
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_ARGLIST_OTHERS);
  visitor = tao_cg->make_visitor (&ctx);
  if ((!visitor) || (node->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_cs::"
                         "visit_operation - "
                         "codegen for argument list failed\n"),
                        -1);
    }
  delete visitor;

  // Generate the actual code for the stub. However, if any of the argument
  // types is "native", we flag a MARSHAL exception.
  // last argument - is always CORBA::Environment
  *os << "{" << be_idt_nl;

  // generate any pre stub info if and only if none of our parameters is of the
  // native type
  if (!node->has_native ())
    {
      // native type does not exist.

      // Generate any "pre" stub information such as tables or declarations
      // This is a template method and the actual work will be done by the
      // derived class
      if (this->gen_pre_stub_info (node, bt) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "gen_pre_stub_info failed\n"),
                            -1);
        }
    }

  // Declare a return type
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_DECL_CS);
  visitor = tao_cg->make_visitor (&ctx);
  if (!visitor || (bt->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_cs::"
                         "visit_operation - "
                         "codegen for return var decl failed\n"),
                        -1);
    }

  if (node->has_native ()) // native exists => no stub
    {
      if (this->gen_raise_exception (bt, "CORBA::MARSHAL",
                                     "CORBA::COMPLETED_NO") == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for return var failed\n"),
                            -1);
        }
    }
  else
    {
      // Generate code that retrieves the underlying stub object and then
      // invokes do_static_call on it.
      *os << be_nl
          << "STUB_Object *istub = this->_stubobj ();" << be_nl
          << "if (istub == 0)" << be_idt_nl;

      // if the stub object was bad, then we raise a system exception
      if (this->gen_raise_exception (bt, "CORBA::INV_OBJREF",
                                     "CORBA::COMPLETED_NO") == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for checking exception failed\n"),
                            -1);

        }
      *os << be_uidt_nl << "\n";

      // do any pre marshal and invoke processing with return type. This
      // includes allocating memory, initialization.
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_PRE_INVOKE_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (bt->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for retval pre invoke failed\n"),
                            -1);
        }

      // do any pre marshal and invoke stuff with arguments
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_PRE_INVOKE_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for argument pre invoke failed\n"),
                            -1);
        }

      // generate the code for marshaling in the parameters and transmitting
      // them
      if (this->gen_marshal_and_invoke (node, bt) == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for marshal and invoke failed\n"),
                            -1);

        }

      // do any post processing for the retval
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_POST_INVOKE_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (bt->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for return type post do_static_call failed\n"),
                            -1);
        }

      // This was putting post_invoke code in the wrong place (after
      // demarshaling). See line 807++ for this block's replacement.
#if 0
      // do any post processing for the arguments
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_POST_INVOKE_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for args in post do_static_call failed\n"),
                            -1);
        }
#endif
      // now generate the normal successful return statement
      os->indent ();
      *os << "return ";
      // return the appropriate return value
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_RETURN_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (bt->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "visit_operation - "
                             "codegen for return var failed\n"),
                            -1);
        }
      *os << ";" << be_uidt_nl;

    } // end of if (!native)

  *os << "}\n\n";

  return 0;
}

int
be_visitor_operation_cs::visit_argument (be_argument *node)
{
  // this method is used to generate the ParamData table entry

  TAO_OutStream *os = this->ctx_->stream ();
  be_type *bt; // argument type

  // retrieve the type for this argument
  bt = be_type::narrow_from_decl (node->field_type ());
  if (!bt)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_cs::"
                         "visit_argument - "
                         "Bad argument type\n"),
                        -1);
    }

  os->indent ();
  *os << "{" << bt->tc_name () << ", ";
  switch (node->direction ())
    {
    case AST_Argument::dir_IN:
      *os << "PARAM_IN, ";
      break;
    case AST_Argument::dir_INOUT:
      *os << "PARAM_INOUT, ";
      break;
    case AST_Argument::dir_OUT:
      *os << "PARAM_OUT, ";
      break;
    }
  *os << "0}";

  return 0;
}

int
be_visitor_operation_cs::gen_raise_exception (be_type *bt,
                                              const char *excep,
                                              const char *completion_status)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_visitor *visitor;
  be_visitor_context ctx;

  if (this->void_return_type (bt))
    {
      *os << "ACE_THROW ("
          << excep << " (" << completion_status << "));\n";
    }
  else
    {
      *os << "ACE_THROW_RETURN ("
          << excep << " (" << completion_status << "), ";

      // return the appropriate return value
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_RETURN_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (bt->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "gen_raise_exception - "
                             "codegen for return var failed\n"),
                            -1);
        }
      *os << ");\n";
    }
  return 0;
}

int
be_visitor_operation_cs::gen_check_exception (be_type *bt)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_visitor *visitor;
  be_visitor_context ctx;

  os->indent ();
  // check if there is an exception
  if (this->void_return_type (bt))
    {
      *os << "ACE_CHECK;\n";
      //<< "_tao_environment);\n";
    }
  else
    {
      *os << "ACE_CHECK_RETURN (";
      // << "_tao_environment, ";

      // return the appropriate return value
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_RETURN_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (bt->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_visitor_operation_cs::"
                             "gen_check_exception - "
                             "codegen failed\n"),
                            -1);
        }
      *os << ");\n";
    }

  return 0;
}

// ************************************************************
// Operation visitor for interpretive client stubs
// ************************************************************

be_interpretive_visitor_operation_cs::
be_interpretive_visitor_operation_cs (be_visitor_context *ctx)
  : be_visitor_operation_cs (ctx)
{
}

be_interpretive_visitor_operation_cs::~be_interpretive_visitor_operation_cs (void)
{
}

// concrete implementation of the template methods

int
be_interpretive_visitor_operation_cs::gen_pre_stub_info (be_operation *node,
                                                         be_type *bt)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_visitor *visitor;
  be_visitor_context ctx;

  // Generate the TAO_Param_Data table
  os->indent ();
  *os << "static const TAO_Param_Data ";
  // check if we are an attribute node in disguise
  if (this->ctx_->attribute ())
    {
      // now check if we are a "get" or "set" operation
      if (node->nmembers () == 1) // set
        *os << "_set_";
      else
        *os << "_get_";
    }
  *os << node->flatname () <<
    "_paramdata [] = " << be_nl;
  *os << "{\n";
  os->incr_indent ();

  // entry for the return type
  *os << "{" << bt->tc_name () << ", PARAM_RETURN, 0}";
  if (node->nmembers () > 0)
    *os << ",\n";

      // generate entries for the param data table for arguments
  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_interpretive_visitor_operation_cs::"
                         "gen_pre_stub_info - "
                         "visit scope failed\n"),
                        -1);
    }
  *os << "\n";
  os->decr_indent ();
  *os << "}; // " << node->flatname () << "_paramdata\n\n";

  // Check if this operation raises any exceptions. In that case, we must
  // generate a list of exception typecodes. This is not valid for
  // attributes
  if (!this->ctx_->attribute ())
    {
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_EXCEPTLIST_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) "
                             "be_interpretive_visitor_operation_cs::"
                             "gen_pre_stub_info - "
                             "Exceptionlist generation error\n"),
                            -1);
        }
    }

  // now generate the calldata table
  os->indent ();
  *os << "static const TAO_Call_Data ";
  // check if we are an attribute node in disguise
  if (this->ctx_->attribute ())
    {
      // now check if we are a "get" or "set" operation
      if (node->nmembers () == 1) // set
        *os << "_set_";
      else
        *os << "_get_";
    }
  *os << node->flatname ()
      << "_calldata = " << be_nl
      << "{"
      << "\"";
  // check if we are an attribute node in disguise
  if (this->ctx_->attribute ())
    {
      // now check if we are a "get" or "set" operation
      if (node->nmembers () == 1) // set
        *os << "_set_";
      else
        *os << "_get_";
    }
  *os << node->local_name () << "\", ";

      // are we oneway or two operation?
  if (node->flags () == AST_Operation::OP_oneway)
    {
      *os << "0, "; // for false
    }
  else
    {
      *os << "1, "; // for true
    }
  // insert the size of the paramdata table i.e., number of arguments + 1
  // for return type
  *os << (node->argument_count () + 1) << ", ";

      // insert the address of the paramdata table
      // first check if we are an attribute node in disguise
  if (this->ctx_->attribute ())
    {
      // now check if we are a "get" or "set" operation
      if (node->nmembers () == 1) // set
        *os << "_set_";
      else
        *os << "_get_";
    }
  *os << node->flatname () << "_paramdata, ";

      // insert exception list (if any) - node for attributes
  if (this->ctx_->attribute ())
    *os << "0, 0};\n\n";
  else
    {
      if (node->exceptions ())
        {
          *os << node->exceptions ()->length ()
              << ", _tao_" << node->flatname () << "_exceptiondata};\n\n";
        }
      else
        *os << "0, 0};\n\n";
    }
  return 0;
}

int
be_interpretive_visitor_operation_cs::gen_marshal_and_invoke (be_operation
                                                              *node,
                                                              be_type *bt)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_visitor *visitor;
  be_visitor_context ctx;

  os->indent ();
  *os << "void* _tao_arguments["
      << node->argument_count () + 1 << "];" << be_nl
      << "const void** _tao_arg = ACE_const_cast (const void**,_tao_arguments);" << be_nl
      << "*_tao_arg = ";

  // pass the appropriate return value to docall
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_INVOKE_CS);
  visitor = tao_cg->make_visitor (&ctx);
  if (!visitor || (bt->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_interpretive_visitor_operation_cs::"
                         "gen_marshal_and_invoke - "
                         "codegen for return var in do_static_call failed\n"),
                        -1);
    }
  *os << "; _tao_arg++;\n";

  // pass each argument to do_static_call
  ctx = *this->ctx_;
  ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_INVOKE_CS);
  visitor = tao_cg->make_visitor (&ctx);
  if (!visitor || (node->accept (visitor) == -1))
    {
      delete visitor;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_interpretive_visitor_operation_cs::"
                         "gen_marshal_and_invoke - "
                         "codegen for return var in do_static_call failed\n"),
                        -1);
    }

  // call do_static_call with appropriate number of arguments
  os->indent ();
  *os << "istub->do_static_call (" << be_idt_nl
      << "ACE_TRY_ENV, " << be_nl
      << "&";
  // check if we are an attribute node in disguise
  if (this->ctx_->attribute ())
    {
      // now check if we are a "get" or "set" operation
      if (node->nmembers () == 1) // set
        *os << "_set_";
      else
        *os << "_get_";
    }
  *os << node->flatname () << "_calldata," << be_nl
      << "_tao_arguments" << be_uidt_nl
      << ");\n";

  os->indent ();
  // check if there is an exception
  if (this->gen_check_exception (bt) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_interpretive_visitor_operation_cs::"
                         "gen_marshal_and_invoke - "
                         "codegen for checking exception failed\n"),
                            -1);

    }

  return 0;
}

// ************************************************************
// Operation visitor for compiled client stubs
// ************************************************************

be_compiled_visitor_operation_cs::
be_compiled_visitor_operation_cs (be_visitor_context *ctx)
  : be_visitor_operation_cs (ctx)
{
}

be_compiled_visitor_operation_cs::~be_compiled_visitor_operation_cs (void)
{
}

// concrete implementation of the template methods

int
be_compiled_visitor_operation_cs::gen_pre_stub_info (be_operation *node,
                                                     be_type *)
{
  be_visitor *visitor;
  be_visitor_context ctx;

  // Check if this operation raises any exceptions. In that case, we must
  // generate a list of exception typecodes. This is not valid for
  // attributes
  if (!this->ctx_->attribute ())
    {
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_EXCEPTLIST_CS);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) "
                             "be_compiled_visitor_operation_cs::"
                             "gen_pre_stub_info - "
                             "Exceptionlist generation error\n"),
                            -1);
        }
    }

  return 0;
}

int
be_compiled_visitor_operation_cs::gen_marshal_and_invoke (be_operation
                                                          *node,
                                                          be_type *bt)
{
  TAO_OutStream *os = this->ctx_->stream ();
  be_visitor *visitor;
  be_visitor_context ctx;

  os->indent ();

  // create the GIOP_Invocation and grab the outgoing CDR stream
  switch (node->flags ())
    {
    case AST_Operation::OP_oneway:
      *os << "TAO_GIOP_Oneway_Invocation _tao_call ";
      break;
    default:
      *os << "TAO_GIOP_Twoway_Invocation _tao_call ";
    }
  *os << "(" << be_idt << be_idt_nl
      << "istub," << be_nl;

  if (this->ctx_->attribute ())
    {
      // now check if we are a "get" or "set" operation
      if (node->nmembers () == 1) // set
        *os << "\"_set_\"";
      else
        *os << "\"_get_\"";
    }
  *os << "\"" << node->local_name ()
      << "\"," << be_nl
      << "TAO_ORB_Core_instance ()" << be_uidt_nl
      << ");" << be_uidt_nl;

  *os << "\n" << be_nl
      << "// If we get forwarded we have to return to this point:"
      << be_uidt_nl
      << "_tao_start_again:\n" << be_idt_nl;

  *os << "ACE_TRY_EX (_tao_START_FAILED)" << be_idt_nl
      << "{" << be_idt_nl
      << "_tao_call.start (ACE_TRY_ENV);" << be_nl
      << "ACE_TRY_CHECK_EX (_tao_START_FAILED);" << be_uidt_nl
      << "}" << be_uidt_nl
      << "ACE_CATCH (CORBA_SystemException, ex)" << be_idt_nl
      << "{" << be_idt_nl
      << "if (istub->next_profile_retry ())" << be_nl
      << "{" << be_idt_nl
      << "ACE_TRY_ENV.clear ();" << be_nl
      << "goto _tao_start_again;" << be_uidt_nl
      << "}" << be_nl
      << "ACE_RETHROW;" << be_uidt_nl
      << "}" << be_uidt_nl
      << "ACE_ENDTRY;\n";

  // check if there is an exception
  if (this->gen_check_exception (bt) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_operation_cs::"
                         "gen_marshal_and_invoke - "
                         "codegen for checking exception failed\n"),
                        -1);

    }

  // now make sure that we have some in and inout parameters. Otherwise, there
  // is nothing to be marshaled in
  if (this->has_param_type (node, AST_Argument::dir_IN) ||
      this->has_param_type (node, AST_Argument::dir_INOUT))
    {
      *os << be_nl
          << "TAO_OutputCDR &_tao_out = _tao_call.out_stream ();"
          << be_nl
          << "if (!(\n" << be_idt << be_idt << be_idt;

      // marshal each in and inout argument
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_INVOKE_CS);
      ctx.sub_state (TAO_CodeGen::TAO_CDR_OUTPUT);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_cs::"
                             "gen_marshal_and_invoke - "
                             "codegen for return var in do_static_call failed\n"),
                            -1);
        }
      *os << be_uidt << be_uidt_nl
          << "))" << be_nl;

      // if marshaling fails, raise exception
      if (this->gen_raise_exception (bt, "CORBA::MARSHAL",
                                     "CORBA::COMPLETED_NO") == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_cs::"
                             "gen_marshal_and invoke - "
                             "codegen for return var failed\n"),
                            -1);
        }
      *os << be_uidt;
    }

  *os << be_nl
      << "TAO_GIOP_ReplyStatusType _invoke_status;" << be_nl
      << "ACE_TRY_EX (_tao_INVOKE_FAILED)" << be_idt_nl
      << "{" << be_idt_nl;

  *os << "_invoke_status =" << be_idt_nl;

  if (node->flags () == AST_Operation::OP_oneway)
    {
      // oneway operation
      *os << "_tao_call.invoke (ACE_TRY_ENV);";
    }
  else
    {
      if (node->exceptions ())
        {
          *os << "_tao_call.invoke (_tao_" << node->flatname ()
              << "_exceptiondata, "
              << node->exceptions ()->length ()
              << ", ACE_TRY_ENV);";
        }
      else
        {
          *os << "_tao_call.invoke (0, 0, ACE_TRY_ENV);";
        }
    }

  *os << be_uidt_nl
      << "ACE_TRY_CHECK_EX (_tao_INVOKE_FAILED);" << be_uidt_nl
      << "}" << be_uidt_nl
      << "ACE_CATCH (CORBA_SystemException, ex)" << be_idt_nl
      << "{" << be_idt_nl
      << "if (istub->next_profile_retry ())" << be_nl
      << "{" << be_idt_nl
      << "ACE_TRY_ENV.clear ();" << be_nl
      << "goto _tao_start_again;" << be_uidt_nl
      << "}" << be_nl
      << "ACE_RETHROW;" << be_uidt_nl
      << "}" << be_uidt_nl
      << "ACE_ENDTRY;\n";

  // check if there is an exception
  if (this->gen_check_exception (bt) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_compiled_visitor_operation_cs::"
                         "gen_marshal_and_invoke - "
                         "codegen for checking exception failed\n"),
                        -1);
    }

  // the code below this is for 2way operations only

  if (!this->void_return_type (bt) ||
      this->has_param_type (node, AST_Argument::dir_INOUT) ||
      this->has_param_type (node, AST_Argument::dir_OUT))
    {
      // Do any post_invoke stuff that might be necessary.
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_POST_INVOKE_CS);
      ctx.sub_state (TAO_CodeGen::TAO_CDR_INPUT);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_cs::"
                             "gen_marshal_and_invoke - "
                             "codegen for args in post do_static_call\n"),
                            -1);
        }
      // check if there was a user exception, else demarshal the
      // return val (if any) and parameters (if any) that came with
      // the response message
      *os << be_nl
          << "if (_invoke_status == TAO_GIOP_NO_EXCEPTION)" << be_nl
          << "{" << be_idt_nl
          << "istub->set_valid_profile ();" << be_nl
          << "TAO_InputCDR &_tao_in = _tao_call.inp_stream ();" << be_nl
          << "if (!(\n" << be_idt << be_idt << be_idt;
    }

  if (!this->void_return_type (bt))
    {
      // demarshal the return val and each inout and out argument
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_RETVAL_INVOKE_CS);
      ctx.sub_state (TAO_CodeGen::TAO_CDR_INPUT);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_cs::"
                             "gen_marshal_and_invoke - "
                             "codegen for return var failed\n"),
                            -1);
        }
      if (this->has_param_type (node, AST_Argument::dir_INOUT) ||
          this->has_param_type (node, AST_Argument::dir_OUT))
        {
          // there are more to follow
          *os << " &&\n";
        }
    }

  if (this->has_param_type (node, AST_Argument::dir_INOUT) ||
      this->has_param_type (node, AST_Argument::dir_OUT))
    {
      // demarshal each out and inout argument
      ctx = *this->ctx_;
      ctx.state (TAO_CodeGen::TAO_OPERATION_ARG_INVOKE_CS);
      ctx.sub_state (TAO_CodeGen::TAO_CDR_INPUT);
      visitor = tao_cg->make_visitor (&ctx);
      if (!visitor || (node->accept (visitor) == -1))
        {
          delete visitor;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_cs::"
                             "gen_marshal_and_invoke - "
                             "codegen for return var failed\n"),
                            -1);
        }
    }

  if (!this->void_return_type (bt) ||
      this->has_param_type (node, AST_Argument::dir_INOUT) ||
      this->has_param_type (node, AST_Argument::dir_OUT))
    {

      *os << be_uidt << be_uidt << be_nl
          << "))" << be_nl;
      // if marshaling fails, raise exception
      if (this->gen_raise_exception (bt, "CORBA::MARSHAL",
                                     "CORBA::COMPLETED_NO") == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_cs::"
                             "gen_marshal_and invoke - "
                             "codegen for return var failed\n"),
                            -1);
        }
      *os << be_uidt << be_uidt_nl
          << "}" << be_nl
          << "else if (_invoke_status == TAO_GIOP_LOCATION_FORWARD)"
          << be_nl
          << "{" << be_idt_nl
          << "if (istub->next_profile ())" << be_nl
          << "{" << be_idt_nl
          << "ACE_TRY_ENV.clear ();" << be_nl
          << "goto _tao_start_again;" << be_uidt_nl
          << "}" << be_nl;
      if (this->gen_raise_exception (bt, "CORBA::TRANSIENT",
                                     "CORBA::COMPLETED_NO") == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_cs::"
                             "gen_marshal_and_invoke\n"),
                            -1);
        }
      *os << be_uidt_nl << "}" << be_nl
          << "else" << be_nl
          << "{" << be_idt_nl;

      // if this operation is not supposed to raise a user defined
      // exception, then flag an UNKNOWN exception error
      if (this->gen_raise_exception (bt, "CORBA::UNKNOWN",
                                     "CORBA::COMPLETED_MAYBE") == -1)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "(%N:%l) be_compiled_visitor_operation_cs::"
                             "gen_marshal_and invoke - "
                             "codegen for return var failed\n"),
                            -1);
        }
      *os << be_uidt_nl << "}\n";
    }

  return 0;
}
