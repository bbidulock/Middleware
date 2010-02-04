/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    serializer_op.h
 *
 *  $Id$
 *
 *  Concrete visitor for the Root class
 *  This one provides code generation for the TAO::DCPS::Serializer operators
 *  for elements of the Root scope.
 *
 *
 *  @author Scott Harris <harris_s@ociweb.com> based on code by Aniruddha Gokhale
 */
//=============================================================================


#ifndef _BE_VISITOR_ROOT_serializer_op_H_
#define _BE_VISITOR_ROOT_serializer_op_H_

/**
 * @class be_visitor_root_serializer_op
 *
 * @brief be_visitor_root_serializer_op
 *
 * This is a concrete visitor for root that generates the Serializer operator
 * declarations and implementations
 */
class be_visitor_root_serializer_op : public be_visitor_root
{

public:
  /// constructor
  be_visitor_root_serializer_op (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_root_serializer_op (void);

  /// visit root
  virtual int visit_root (be_root *node);
};

#endif /* _BE_VISITOR_ROOT_serializer_op_H_ */
