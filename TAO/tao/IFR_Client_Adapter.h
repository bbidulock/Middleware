// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file    IFR_Client_Adapter.h
 *
 *  $Id$
 *
 *  @author  Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_IFR_CLIENT_ADAPTER_H
#define TAO_IFR_CLIENT_ADAPTER_H

#include /**/ "ace/pre.h"
#include "ace/CORBA_macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Object.h"

#include "tao/TAO_Export.h"
#include "tao/Basic_Types.h"

class TAO_OutputCDR;

namespace CORBA
{
  class InterfaceDef;
  typedef InterfaceDef *InterfaceDef_ptr;

  class Any;
  class ORB;
  typedef ORB *ORB_ptr;
  class Object;
  typedef Object *Object_ptr;
};

/**
 * @class TAO_IFR_Client_Adapter
 *
 * @brief TAO_IFR_Client_Adapter.
 *
 * Class that adapts various functions in the CORBA namespace
 * which use the Interface Repository. This is a base class for
 * the actual implementation in the TAO_IFR_Client library.
 */
class TAO_Export TAO_IFR_Client_Adapter : public ACE_Service_Object
{
public:
  virtual ~TAO_IFR_Client_Adapter (void);

  virtual CORBA::Boolean interfacedef_cdr_insert (
      TAO_OutputCDR &cdr,
      CORBA::InterfaceDef_ptr object_type
    ) = 0;

  virtual void interfacedef_any_insert (
      CORBA::Any &any,
      CORBA::InterfaceDef_ptr object_type
    ) = 0;

  virtual void dispose (
      CORBA::InterfaceDef_ptr orphan
    ) = 0;

  virtual CORBA::InterfaceDef_ptr get_interface (
      CORBA::ORB_ptr orb,
      const char *repo_id
      ACE_ENV_ARG_DECL
    ) = 0;

  virtual CORBA::InterfaceDef_ptr get_interface_remote (
      CORBA::Object_ptr target
      ACE_ENV_ARG_DECL
    ) = 0;
};

#include /**/ "ace/post.h"
#endif /* TAO_IFR_CLIENT_ADAPTER_H */
