//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    cdr_op_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for Enums for the CDR operators
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include	"idl.h"
#include	"idl_extern.h"
#include	"be.h"

#include "be_visitor_enum.h"

ACE_RCSID(be_visitor_enum, cdr_op_ch, "$Id$")


// ***************************************************************************
// Enum visitor for generating Cdr operator declarations in the client header
// ***************************************************************************

be_visitor_enum_cdr_op_ch::be_visitor_enum_cdr_op_ch
(be_visitor_context *ctx)
  : be_visitor_scope (ctx)
{
}

be_visitor_enum_cdr_op_ch::~be_visitor_enum_cdr_op_ch (void)
{
}

int
be_visitor_enum_cdr_op_ch::visit_enum (be_enum *node)
{
  if (node->cli_hdr_cdr_op_gen () || node->imported ())
    return 0;

  TAO_OutStream *os = tao_cg->client_header ();

  // generate the CDR << and >> operators
  os->indent ();
  *os << "CORBA::Boolean " << idl_global->export_macro ()
      << " operator<< (TAO_OutputCDR &, const " << node->name ()
      << " &); // " << be_nl;
  *os << "CORBA::Boolean " << idl_global->export_macro ()
      << " operator>> (TAO_InputCDR &, "
      << node->name () << " &);\n";

  node->cli_hdr_cdr_op_gen (1);
  return 0;
}
