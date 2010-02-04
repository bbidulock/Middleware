/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    root_si.h
 *
 *  $Id$
 *
 *  Concrete visitor for the Root class
 *  This one provides code generation for elements of the Root node in the
 *  server inline.
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


#ifndef _BE_VISITOR_ROOT_ROOT_SI_H_
#define _BE_VISITOR_ROOT_ROOT_SI_H_

/**
 * @class be_visitor_root_si
 *
 * @brief be_visitor_root_si
 *
 * This is a concrete visitor to generate the server inline for root
 */
class be_visitor_root_si : public be_visitor_root
{
public:
  /// constructor
  be_visitor_root_si (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_root_si (void);

  /// set the right context and make a visitor
  virtual int init (void);
};

#endif /* _BE_VISITOR_ROOT_ROOT_SI_H_ */
