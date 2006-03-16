// -*- C++ -*-

//=============================================================================
/**
 *  @file    True_Fragmentation_Strategy.h
 *
 *  $Id$
 *
 *  @author  Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_TRUE_FRAGMENTATION_STRATEGY_H
#define TAO_TRUE_FRAGMENTATION_STRATEGY_H

#include /**/ "ace/pre.h"

#include "tao/GIOP_Fragmentation_Strategy.h"
#include "ace/CDR_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_OutputCDR;
class TAO_Transport;


/**
 * @class TAO_True_Fragmenation_Strategy
 *
 * @brief True GIOP message fragmentation strategy.
 *
 * GIOP message fragmentation strategy that performs fragmentation
 * when the size of the CDR stream will exceed the user configured
 * threshold when marshaling the next/pending set of data.
 *
 * @see TAO_GIOP_Fragmentation_Strategy
 */
class TAO_True_Fragmentation_Strategy
  : public TAO_GIOP_Fragmentation_Strategy
{
public:

  /// Constructor.
  TAO_True_Fragmentation_Strategy (TAO_Transport * transport,
                                   ACE_CDR::ULong max_message_size);

  virtual ~TAO_True_Fragmentation_Strategy (void);
  virtual void fragment (TAO_OutputCDR & cdr,
                         ACE_CDR::ULong pending_alignment,
                         ACE_CDR::ULong pending_length);

private:

  // Disallow copying and assignment.
  TAO_True_Fragmentation_Strategy (TAO_True_Fragmentation_Strategy const &);
  void operator= (TAO_True_Fragmentation_Strategy const &);

private:

  /// Pointer to the underying transport object.
  TAO_Transport * const transport_;

  /// Size of GIOP message at which fragmentation will occur.
  ACE_CDR::ULong const max_message_size_;

};

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif  /* TAO_TRUE_FRAGMENTATION_STRATEGY_H */
