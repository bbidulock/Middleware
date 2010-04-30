
//=============================================================================
/**
 *  @file    cdr_op_cs.cpp
 *
 *  $Id$
 *
 *  Visitor generating code for CDR operators for components
 *
 *
 *  @author Jeff Parsons
 */
//=============================================================================

be_visitor_component_cdr_op_cs::be_visitor_component_cdr_op_cs (
    be_visitor_context *ctx
  )
  : be_visitor_component (ctx)
{
}

be_visitor_component_cdr_op_cs::~be_visitor_component_cdr_op_cs (void)
{
}

int
be_visitor_component_cdr_op_cs::visit_component (be_component *node)
{
  be_visitor_context ctx (*this->ctx_);
  be_visitor_interface_cdr_op_cs visitor (&ctx);
  return visitor.visit_interface (node);
}

int
be_visitor_component_cdr_op_cs::visit_connector (be_connector *node)
{
  return this->visit_component (node);
}