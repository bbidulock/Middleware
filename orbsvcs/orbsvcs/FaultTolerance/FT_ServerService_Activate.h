//=============================================================================
/**
 * @file FT_ServerService_Activate.h
 *
 * $Id$
 *
 * A concrete implementation of a service callback
 *
 * @author Bala Natarajan <bala@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_FT_SERVERACTIVATE_H
#define TAO_FT_SERVERACTIVATE_H
#include /**/ "ace/pre.h"

#include "fault_tol_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Services_Activate.h"
#include "ace/Service_Config.h"

class TAO_Service_Callbacks;

// Forward declarations
/**
 * @class TAO_FT_ServerService_Activate
 *
 * @brief A class to dynamically load the FT callback implementations in
 * to the ORB.
 *
 */
class TAO_FT_Export TAO_FT_ServerService_Activate : public ACE_Service_Object
{

public:
  /// Constructor
  TAO_FT_ServerService_Activate (void);

  /// The destructor
  virtual ~TAO_FT_ServerService_Activate (void);

  /// Used to force the initialization.
  static int Initializer (void);

};

ACE_STATIC_SVC_DECLARE (TAO_FT_ServerService_Activate)
ACE_FACTORY_DECLARE (TAO_FT, TAO_FT_ServerService_Activate)

#if defined(ACE_HAS_BROKEN_STATIC_CONSTRUCTORS)

typedef int (*TAO_Module_Initializer) (void);

static TAO_Module_Initializer
TAO_FT_Requires_ServerService_Activate = &TAO_FT_ServerService_Activate::Initializer;

#else

static int
TAO_FT_Requires_ServerService_Activate = TAO_FT_ServerService_Activate::Initializer ();

#endif /* ACE_HAS_BROKEN_STATIC_CONSTRUCTORS */

#include /**/ "ace/post.h"
#endif /*TAO_FT_ACTIVATE_H*/
