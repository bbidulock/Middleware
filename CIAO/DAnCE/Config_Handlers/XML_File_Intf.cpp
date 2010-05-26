// $Id$

#include "XML_File_Intf.h"
#include "XML_Typedefs.h"
#include "Deployment.hpp"
#include "DP_Handler.h"
#include "Common.h"

#include "DAnCE/Deployment/Deployment_DataC.h"
#include "DAnCE/Logger/Log_Macros.h"

namespace CIAO
{
  namespace Config_Handlers
  {
    XML_File_Intf::XML_File_Intf (const ACE_TCHAR *file)
      : file_ (file),
        idl_dp_ (0)
    {
    }

    bool
    XML_File_Intf::read_process_file (const ACE_TCHAR *file)
    {
      DANCE_TRACE("XML_File_Intf::read_process_file");

      try
        {
          if (!XML_Helper::XML_HELPER.is_initialized ())
            return false;

          DANCE_DEBUG (6, (LM_TRACE, DLINFO "XML_File_Intf::read_process_file - "
                       "Constructing DOM\n"));
          XERCES_CPP_NAMESPACE::DOMDocument *dom =
            XML_Helper::XML_HELPER.create_dom ((file));

          if (dom == 0)
            {
              DANCE_ERROR (1, (LM_ERROR, DLINFO "XML_File_Intf::read_process_file - "
                           "Failed to open file %s\n", file));
              return false;
            }

          XERCES_CPP_NAMESPACE::DOMElement *foo = dom->getDocumentElement ();
          DANCE_DEBUG (6, (LM_TRACE, DLINFO "XML_File_Intf::read_process_file - "
                       "DOMElement pointer: %u\n", foo));

          DANCE_DEBUG (6, (LM_TRACE, DLINFO "XML_File_Intf::read_process_file - "
                       "Parsing XML file with XSC\n"));
          deploymentPlan dp =
            CIAO::Config_Handlers::reader::DeploymentPlan (dom);

          DANCE_DEBUG (6, (LM_TRACE, DLINFO "XML_File_Intf::read_process_file - "
                       "Processing using config handlers\n"));
          DP_Handler dp_handler (dp);

          this->idl_dp_.reset (dp_handler.plan ());

          if (this->idl_dp_.get ())
            return true;
        }
      catch (const Config_Error &ex)
        {
          DANCE_ERROR (1, (LM_ERROR, DLINFO "XML_File_Intf::error at %C: %C\n",
                      ex.name_.c_str (), ex.error_.c_str ()));
        }
      catch (...)
        {
          DANCE_ERROR (1, (LM_ERROR, DLINFO "XML_File_Intf::caught - "
                      "Unexpected exception whilst parsing XML into IDL.\n"));
        }

      return false;
    }

    ::Deployment::DeploymentPlan const *
    XML_File_Intf::get_plan (void)
    {
      DANCE_TRACE("get_plan");
      if (this->idl_dp_.get () == 0 && !this->read_process_file (this->file_.c_str ()))
        return 0;

      return this->idl_dp_.get ();
    }

    ::Deployment::DeploymentPlan *
    XML_File_Intf::release_plan (void)
    {
      DANCE_TRACE("XML_File_Intf::get_plan");
      if (this->idl_dp_.get () == 0 && !this->read_process_file (this->file_.c_str ()))
        return 0;
      return this->idl_dp_.release ();
    }

    void
    XML_File_Intf::add_search_path (const ACE_TCHAR *environment,
                                    const ACE_TCHAR *relpath)
    {
      XML_Helper::_path_resolver.add_path (environment, relpath);
    }

  }
}