//================================================
/**
 *  @file  CID_Handler.h
 *
 *  $Id$
 *
 *  @author Jules White <jules@dre.vanderbilt.edu>
 */
//================================================

#ifndef CIAO_CONFIG_HANDLERS_CCD_HANDLER_H
#define CIAO_CONFIG_HANDLERS_CCD_HANDLER_H
#include /**/ "ace/pre.h"

#include "Config_Handlers/Config_Handlers_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Config_Handlers/cid.hpp"

namespace Deployment
{
  class ComponentInterfaceDescription;
}

namespace CIAO
{
  namespace Config_Handlers
  {
   /*
    * @class CCD_Handler
    *
    * @brief Handler class for <ComponentInterfaceDescription> types.
    *
    * This class is named CCD_Handler but actually fills
    * <ComponentInterfaceDescription>. Why is this confusion? We
    * want to maintain the correlation between the XSD file and the
    * actual datatype. The file name corresponds to the XSD file but
    * the data type being filled in is of type
    * <ComponentInterfaceDescription>
    */
    class Config_Handlers_Export CCD_Handler
    {
      public:
       static bool component_interface_descr (
          Deployment::ComponentInterfaceDescription& toconfig,
          ComponentInterfaceDescription& desc);
    };
  }
}

#include /**/ "ace/post.h"
#endif /* CID_HANDLER_H */
