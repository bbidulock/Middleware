// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file    ORT_Adapter_Factory.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================


#ifndef TAO_ORT_ADAPTER_FACTORY_H
#define TAO_ORT_ADAPTER_FACTORY_H

#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Object.h"

namespace TAO
{
  class ORT_Adapter;
}

namespace TAO
{
  /**
   * @class ORT_Adapter_Factory
   *
   * @brief ORT_Adapter_Factory
   *
   * Class that creates one instance of TAO::ORT_Adapter per
   * POA on the POA's first usage of its objectreferencetemplate_adapter.
   * This is a base class for the actual implementation in the
   * TAO_ObjectReferenceTemplate library.
   */
  class TAO_PortableServer_Export ORT_Adapter_Factory
    : public ACE_Service_Object
  {
  public:
    virtual ~ORT_Adapter_Factory (void);

    /// Create a new adapter, in case not possible to allocate, returns 0
    virtual TAO::ORT_Adapter * create () = 0;

    virtual void destroy (TAO::ORT_Adapter * adapter) = 0;
  };
}

#include /**/ "ace/post.h"

#endif /* TAO_ORT_ADAPTER_FACTORY_H */
