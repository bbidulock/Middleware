//==============================================================
/**
 *  @file  DP_Handler.h
 *
 *  $Id$
 *
 *  @author Bala Natarajan <bala@dre.vanderbilt.edu>
 */
//================================================================

#ifndef CIAO_CONFIG_XML_FILE_INTF_H
#define CIAO_CONFIG_XML_FILE_INTF_H
#include /**/ "ace/pre.h"

#include "Config_Handlers/Config_Handlers_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Auto_Ptr.h"


namespace Deployment
{
  struct DeploymentPlan ;
}

namespace CIAO
{
  namespace Config_Handlers
  {
    class Config_Handlers_Export XML_File_Intf
    {
    public:
      XML_File_Intf (const char *file);

      ::Deployment::DeploymentPlan const *get_plan (void) const;
      ::Deployment::DeploymentPlan *get_plan (void);

    protected:

      bool read_process_file (const char *file);

    private:
      auto_ptr< ::Deployment::DeploymentPlan> idl_dp_;
    };
  }
}
#include /**/ "ace/post.h"
#endif /*CIAO_CONFIG_XML_FILE_INTF_H*/
