// -*- C++ -*-

// ===================================================================
/**
 *  @file   GIOP_Message_Generator_Parser_11.h
 *
 *  $Id$
 *
 *  @author Balachandran Natarajan <bala@cs.wustl.edu>
 */
// ===================================================================

#ifndef TAO_GIOP_MESSAGE_GENERATOR_PARSER_11_H
#define TAO_GIOP_MESSAGE_GENERATOR_PARSER_11_H
#include /**/ "ace/pre.h"
#include "tao/GIOP_Message_Generator_Parser_10.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


/**
 * @class TAO_GIOP_Message_Generator_Parser_11
 *
 * @brief Implementation for GIOP v1.1
 *
 *  This just derives from v1.0 class. It uses most of the methods in
 *  the 1.0 class.
 *
 */

class TAO_Export TAO_GIOP_Message_Generator_Parser_11:
  public TAO_GIOP_Message_Generator_Parser_10
{
public:

  /// Our minor version
  virtual CORBA::Octet minor_version (void);

};


#if defined (__ACE_INLINE__)
# include "tao/GIOP_Message_Generator_Parser_11.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /*TAO_GIOP_MESSAGE_GENERATOR_PARSER_11_H*/
