/* -*- C++ -*- */
// $Id$

#include "ExtLocalInterfaceDef_i.h"
#include "Repository_i.h"

ACE_RCSID (IFRService, 
           ExtLocalInterfaceDef_i, 
           "$Id$")

TAO_ExtLocalInterfaceDef_i::TAO_ExtLocalInterfaceDef_i (
    TAO_Repository_i *repo
  )
  : TAO_IRObject_i (repo),
    TAO_Container_i (repo),
    TAO_Contained_i (repo),
    TAO_IDLType_i (repo),
    TAO_InterfaceDef_i (repo),
    TAO_LocalInterfaceDef_i (repo),
    TAO_InterfaceAttrExtension_i (repo)
{
}

TAO_ExtLocalInterfaceDef_i::~TAO_ExtLocalInterfaceDef_i (void)
{
}

// Just call the base class version, this is here only to
// disambiguate multiple inheritance.
void
TAO_ExtLocalInterfaceDef_i::destroy (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_IFR_WRITE_GUARD;

  this->update_key (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  TAO_LocalInterfaceDef_i::destroy_i (ACE_ENV_SINGLE_ARG_PARAMETER);
}

