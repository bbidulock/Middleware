// -*- C++ -*-

// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO/orbsvcs/orbsvcs/IFRService
//
// = FILENAME
//    ModuleDef_i.h
//
// = DESCRIPTION
//    ModuleDef servant class.
//
// = AUTHOR
//    Jeff Parsons <parsons@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_MODULEDEF_I_H
#define TAO_MODULEDEF_I_H

//#include "Container_i.h"
#include "orbsvcs/IFRService/Contained_i.h"
#include "orbsvcs/IFRService/ComponentModuleDef_i.h"
#include "orbsvcs/IFRService/ifr_service_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_IFRService_Export TAO_ModuleDef_i
  : public virtual TAO_Contained_i,
    public virtual TAO_ComponentModuleDef_i
{
  // = TITLE
  //    TAO_ModuleDef_i
  //
  // = DESCRIPTION
  //    Represents a module definition.
  //
public:
  TAO_ModuleDef_i (TAO_Repository_i *repo);
  // Constructor

  virtual ~TAO_ModuleDef_i (void);
  // Destructor

  virtual CORBA::DefinitionKind def_kind ()
;
  // Return our definition kind.

  virtual void destroy ()
;
  // Remove the repository entry.

  virtual void destroy_i ()
;
  // Remove the repository entry.

  virtual CORBA::Contained::Description *describe ()
;
  // From Contained_i's pure virtual function.

  virtual CORBA::Contained::Description *describe_i ()
;
  // From Contained_i's pure virtual function.
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_MODULEDEF_I_H */
