// -*- C++ -*-

//=============================================================================
/**
 *  @file     OBV_Constants.h
 *
 *  $Id$
 *
 *  Constants related to valuetypes, but also used by type codes.
 *
 *  @author Jeff Parsons
 */
//=============================================================================

#ifndef TAO_OBV_CONSTANTS_H
#define TAO_OBV_CONSTANTS_H

#include /**/ "ace/pre.h"

#include "tao/orb_typesC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace CORBA
{
  const Visibility PRIVATE_MEMBER = 0;
  const Visibility PUBLIC_MEMBER  = 1;

  const ValueModifier VM_NONE        = 0;
  const ValueModifier VM_CUSTOM      = 1;
  const ValueModifier VM_ABSTRACT    = 2;
  const ValueModifier VM_TRUNCATABLE = 3;
}

#include /**/ "ace/post.h"

#endif  /* TAO_OBV_CONSTANTS_H */
