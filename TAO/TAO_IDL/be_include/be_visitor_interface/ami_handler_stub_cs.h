//
// $Id$
//
/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    ami_handler_cs.h
//
// = DESCRIPTION
//    Concrete visitor for the Interface node.
//    This one provides code generation for interfaces in the client stubs.
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#ifndef _BE_INTERFACE_AMI_HANDLER_CS_H_
#define _BE_INTERFACE_AMI_HANDLER_CS_H_

class be_visitor_interface_ami_handler_stub_cs : public be_visitor_interface
{
  //
  // = TITLE
  //   be_visitor_interface_ami_handler_stub_cs
  //
  // = DESCRIPTION
  //   This is a concrete visitor to generate the AMI Handler
  //   skeletons for interface.  
  //
public:
  be_visitor_interface_ami_handler_stub_cs (be_visitor_context *ctx);
  // constructor

  ~be_visitor_interface_ami_handler_stub_cs (void);
  // destructor

  virtual int visit_interface (be_interface *node);
  // set the right context and make a visitor
};

#endif /* _BE_INTERFACE_AMI_HANDLER_CS_H_ */
