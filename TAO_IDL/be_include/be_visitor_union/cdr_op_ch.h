/* -*- c++ -*- */
//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    cdr_op_ch.h
//
// = DESCRIPTION
//    Concrete visitor for the Union class
//    This one provides code generation for the CDR operators for the union
//    in the client header.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#if !defined (_BE_VISITOR_UNION_CDR_OP_CH_H_)
#define _BE_VISITOR_UNION_CDR_OP_CH_H_

class be_visitor_union_cdr_op_ch : public be_visitor_union
{
  //
  // = TITLE
  //   be_visitor_union_cdr_op_ch
  //
  // = DESCRIPTION
  //   This is a concrete visitor for union that generates the CDR operator
  //   declarations
  //

public:
  be_visitor_union_cdr_op_ch (be_visitor_context *ctx);
  // constructor

  ~be_visitor_union_cdr_op_ch (void);
  // destructor

  virtual int visit_union (be_union *node);
  // visit union

};

#endif /* _BE_VISITOR_UNION_CDR_OP_CH_H_ */
