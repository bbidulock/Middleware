//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    post_upcall_ss.h
//
// = DESCRIPTION
//    Visitors for generation of code for Arguments. This generates the
//    code for post upcall processing of the arguments
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================


#ifndef _BE_VISITOR_ARGUMENT_POST_UPCALL_SS_H_
#define _BE_VISITOR_ARGUMENT_POST_UPCALL_SS_H_

// ************************************************************
// class be_visitor_args_post_upcall_ss
// ************************************************************
class be_visitor_args_post_upcall_ss : public be_visitor_args
{
  //
  // = TITLE
  //   be_visitor_args_post_upcall_ss
  //
  // = DESCRIPTION
  //   Visitor for post processing after upcall
  //
public:
  be_visitor_args_post_upcall_ss (be_visitor_context *ctx);
  // constructor

  virtual ~be_visitor_args_post_upcall_ss (void);
  // destructor

  virtual int visit_argument (be_argument *node);
  // visit the argument node

  // =visit all the nodes that can be the types for the argument

  virtual int visit_array (be_array *node);
  // visit array type

  virtual int visit_enum (be_enum *node);
  // visit the enum node

  virtual int visit_interface (be_interface *node);
  // visit interface

  virtual int visit_interface_fwd (be_interface_fwd *node);
  // visit interface forward

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

// ****************************************************************

// ************************************************************
// class be_visitor_compiled_args_post_upcall
// ************************************************************

class be_visitor_compiled_args_post_upcall : public be_visitor_scope
{
  //
  // = TITLE
  //   be_visitor_compiled_args_post_upcall
  //
  // = DESCRIPTION
  //   Visitor for post processing after upcall
  //
public:
  be_visitor_compiled_args_post_upcall (be_visitor_context *ctx);
  // constructor

  virtual ~be_visitor_compiled_args_post_upcall (void);
  // destructor

  virtual int visit_argument (be_argument *node);
  // visit the argument node

  // =visit all the nodes that can be the types for the argument

  virtual int visit_operation (be_operation *node);
  virtual int visit_array (be_array *node);
  virtual int visit_typedef (be_typedef *node);
};

#endif  /* _BE_VISITOR_ARGUMENT_POST_UPCALL_SS_H_ */
