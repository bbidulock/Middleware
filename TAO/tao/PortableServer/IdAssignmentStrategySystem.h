// -*- C++ -*-

//=============================================================================
/**
 *  @file IdAssignmentStrategySystem.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_IDASSIGNMENTSTRATEGYSYSTEM_H
#define TAO_IDASSIGNMENTSTRATEGYSYSTEM_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "IdAssignmentStrategy.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export IdAssignmentStrategySystem
      : public virtual IdAssignmentStrategy
    {
    public:
      virtual ~IdAssignmentStrategySystem (void);

      virtual char id_assignment_key_type (void) const;

      virtual bool has_system_id (void) const;
    };
  }
}

#include /**/ "ace/post.h"
#endif /* TAO_IDASSIGNMENTSTRATEGYSYSTEM_H */
