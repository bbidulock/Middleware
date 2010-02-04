
/* -*- c++ -*- */
//=============================================================================
/**
 *  @file    be_visitor_factory.h
 *
 *  $Id$
 *
 *  Define a visitor Factory which is a singleton.
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


#ifndef TAO_BE_VISITOR_FACTORY_H
#define TAO_BE_VISITOR_FACTORY_H

#include "ace/Singleton.h"
#include "ace/Synch_Traits.h"

class be_visitor;
class be_visitor_context;

/**
 * @class TAO_Visitor_Factory
 =TITLE
 * TAO_Visitor_Factory
 * =DESCRIPTION
 * Visitor factory class
 */
class TAO_Visitor_Factory
{

public:

  TAO_Visitor_Factory (void);

  ~TAO_Visitor_Factory (void);

  /// Make a visitor.
  be_visitor *make_visitor (be_visitor_context *);
};

// Singleton instance of the BE Visitor Factory.
typedef ACE_Singleton<TAO_Visitor_Factory, ACE_SYNCH_RECURSIVE_MUTEX> 
  TAO_VISITOR_FACTORY;

#endif /* if !defined _TAO_BE_VISITOR_FACTORY_H_ */
