//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    interceptors_result.cpp
//
// = DESCRIPTION
//    Visitor that generates the Dyanmic::ParameterList
//
// = AUTHOR
//    Kirthika Parameswaran  <kirthika@cs.wustl.edu>
//
// ============================================================================

#include "idl.h"
#include "be.h"
#include "be_visitor_operation.h"

ACE_RCSID(be_visitor_argument, interceptors_result, "$Id$")


// ************************************************************
// be_visitor_operation_interceptors_result for generating the result as
// stored in the request info for interceptors
// ************************************************************

be_visitor_operation_interceptors_result::be_visitor_operation_interceptors_result (be_visitor_context *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_operation_interceptors_result::~be_visitor_operation_interceptors_result (void)
{
}

int be_visitor_operation_interceptors_result::visit_array (be_array *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream

  // if the current type is an alias, use that
  be_type *bt;
  if (this->ctx_->alias ())
    bt = this->ctx_->alias ();
  else
    bt = node;

  os->indent ();
  *os << bt->name () <<  "_forany _tao_forany_result" 
      << " (this->result_);" << be_nl
      << "this->result_val_ <<= _tao_forany_result;"<< be_nl;
  return 0;
}

int be_visitor_operation_interceptors_result::visit_enum (be_enum *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  os->indent ();
  *os << "this->result_val_ <<= this->result_;";

  return 0;
}

int be_visitor_operation_interceptors_result::visit_interface (be_interface *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream

  os->indent ();
  *os << "this->result_val_ <<= this->result_;";

  return 0;
}
int be_visitor_operation_interceptors_result::visit_interface_fwd (be_interface_fwd *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  os->indent ();
  *os << "this->result_val_ <<= this->result_;";

  return 0;

}
#ifdef IDL_HAS_VALUETYPE

int be_visitor_operation_interceptors_result::visit_valuetype (be_valuetype *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  os->indent ();

  // Not supported since TAO doesnt support Any operators for valuetype yet.
  //  *os << "this->result_val_ <<= this->result_;";

  return 0;

}

int be_visitor_operation_interceptors_result::visit_valuetype_fwd (be_valuetype_fwd *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  os->indent ();
  // Not supported since TAO doesnt support Any operators for valuetype yet.
  //  *os << "this->result_val_ <<= this->result_;";

  return 0;

}

#endif /* IDL_HAS_VALUETYPE */

int 
be_visitor_operation_interceptors_result::visit_predefined_type (be_predefined_type *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  os->indent ();
  *os << "this->result_val_ <<= ";
  switch (node->pt ())
    {
    case AST_PredefinedType::PT_boolean:
      *os << "CORBA::Any::from_boolean (this->result_);" << be_nl;
      break;
    case AST_PredefinedType::PT_char:
      *os << "CORBA::Any::from_char (this->result_);"<<be_nl;
      break;
    case AST_PredefinedType::PT_wchar:
      *os << "CORBA::Any::from_wchar (this->result_);"<<be_nl;
      break;
    case AST_PredefinedType::PT_octet:
      *os << "CORBA::Any::from_octet (this->result_);"<<be_nl;
      break;
    case AST_PredefinedType::PT_pseudo:            
    case AST_PredefinedType::PT_any:
    case AST_PredefinedType::PT_long:
    case AST_PredefinedType::PT_ulong:
    case AST_PredefinedType::PT_longlong:
    case AST_PredefinedType::PT_ulonglong:
    case AST_PredefinedType::PT_short:
    case AST_PredefinedType::PT_ushort:
    case AST_PredefinedType::PT_float:
    case AST_PredefinedType::PT_double:
    case AST_PredefinedType::PT_longdouble:
      *os << "this->result_;"<<be_nl; 
      break;
    default:
      ACE_ERROR_RETURN ((LM_ERROR,
                         "be_visitor_operation_interceptors_result::"
                         "visit_predefined_type - "
                         "Bad predefined type\n"),
                        -1);
      
    }
  return 0;

}

int be_visitor_operation_interceptors_result::visit_sequence (be_sequence *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream
  os->indent ();
  *os << "this->result_val_ <<= this->result_;";

  return 0;

}

int 
be_visitor_operation_interceptors_result::visit_string (be_string *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream

  os->indent ();
  *os << "this->result_val_ <<= ";
  // we need to make a distinction between bounded and unbounded strings
  if (node->max_size ()->ev ()->u.ulval != 0)
    {
      // bounded strings
      if (node->width () == (long) sizeof (char))
        {
          *os << "CORBA::Any::from_string ((char *)";
        }
      else
        {
          *os << "CORBA::Any::from_wstring ((CORBA::WChar *)";
        }
      *os <<"this->result_, "
          << node->max_size ()->ev ()->u.ulval
          << ");";
    }
  else
      *os << "this->result_; ";
return 0;
}
 
int be_visitor_operation_interceptors_result::visit_structure (be_structure *node)
{
  TAO_OutStream *os = this->ctx_->stream (); // get output stream

  os->indent ();
  *os << "this->result_val_ <<= this->result_;";

  return 0;

}

int be_visitor_operation_interceptors_result::visit_union (be_union *node)
{
 TAO_OutStream *os = this->ctx_->stream (); // get output stream

  os->indent ();
  *os << "this->result_val_ <<= this->result_;";

  return 0;

}

int be_visitor_operation_interceptors_result::visit_typedef (be_typedef *node)
{
 TAO_OutStream *os = this->ctx_->stream (); // get output stream

  os->indent ();
  *os << "this->result_val_ <<= this->result_;";

  return 0;

}
