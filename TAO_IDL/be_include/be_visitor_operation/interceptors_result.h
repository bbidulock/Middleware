//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    interceptors_result.h
//
// = DESCRIPTION
//    Visitors for generation of code for building Dynamic::Result
//
// = AUTHOR
//    Kirthika Parameswaran  <kirthika@cs.wustl.edu>
//
// ============================================================================

#ifndef _BE_VISITOR_OPERATION_INTERCEPTORS_RESULT_H_
#define _BE_VISITOR_OPERATION_INTERCEPTORS_RESULT_H_

class be_visitor_operation_interceptors_result : public be_visitor_decl
{
  //
  // = TITLE
  //   Generates the code for request info result output.
  //
  // = DESCRIPTION
  //   At several stages in the code generation a node of type
  //   "be_operation" is visited, and the code for its arguments must
  //   be generated. Here the generationis to build the ParameterList
  //   on demand.

public:
  be_visitor_operation_interceptors_result (be_visitor_context *ctx);
  // constructor

  virtual ~be_visitor_operation_interceptors_result (void);
  // destructor

  // =visit all the nodes that can be the types for the result

  virtual int visit_array (be_array *node);
  // visit array type

  virtual int visit_enum (be_enum *node);
  // visit the enum node

  virtual int visit_interface (be_interface *node);
  // visit interface

  virtual int visit_interface_fwd (be_interface_fwd *node);
  // visit interface forward

#ifdef IDL_HAS_VALUETYPE
  virtual int visit_valuetype (be_valuetype *node);
  // visit valuetype

  virtual int visit_valuetype_fwd (be_valuetype_fwd *node);
  // visit valuetype forward
#endif /* IDL_HAS_VALUETYPE */

  virtual int visit_predefined_type (be_predefined_type *node);
  // visit predefined type

  virtual int visit_sequence (be_sequence *node);
  // visit sequence type

  virtual int visit_string (be_string *node);
  // visit string type

  virtual int visit_structure (be_structure *node);
  // visit structure type

  virtual int visit_union (be_union *node);
  // visit union type

  virtual int visit_typedef (be_typedef *node);
  // visit the typedef type
};

#endif /* _BE_VISITOR_OPERATION_INTERCEPTORS_RESULT_H_ */
