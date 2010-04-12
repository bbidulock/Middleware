
//=============================================================================
/**
 *  @file    ami_exception_holder_cs.cpp
 *
 *  $Id$
 *
 *  Visitor generating code for excpetion holders.
 *
 *
 *  @author Michael Kircher
 */
//=============================================================================


// ************************************************************
// Interface visitor for client stubs
// ************************************************************

be_visitor_valuetype_ami_exception_holder_cs::
be_visitor_valuetype_ami_exception_holder_cs (be_visitor_context *ctx)
  : be_visitor_valuetype (ctx)
{
}

be_visitor_valuetype_ami_exception_holder_cs::
~be_visitor_valuetype_ami_exception_holder_cs (void)
{
}

int
be_visitor_valuetype_ami_exception_holder_cs::visit_valuetype (
    be_valuetype *node
  )
{
  ACE_UNUSED_ARG (node);
  return 0;
}


int
be_visitor_valuetype_ami_exception_holder_cs::visit_operation (be_operation *node)
{
  be_visitor_context ctx (*this->ctx_);
  ctx.state (TAO_CodeGen::TAO_AMI_EXCEPTION_HOLDER_RAISE_OPERATION_CS);
  be_visitor_operation_ami_exception_holder_operation_cs visitor (&ctx);

  if (node->accept (&visitor) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_valuetype_ami_exception_holder_ch::"
                         "visit_operation - "
                         "codegen for argument list failed\n"),
                        -1);
    }

  return 0;
}
