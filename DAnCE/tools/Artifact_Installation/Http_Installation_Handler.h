// $Id$

/**
 * @file Http_Installation_Handler.h
 *
 * @author Martin Corino <mcorino@remedy.nl>
 */

#ifndef DANCE_HTTP_INSTALLATION_HANDLER_H
#define DANCE_HTTP_INSTALLATION_HANDLER_H

#include /**/ "ace/pre.h"

#include "Artifact_Installation_Handler_Svc.h"
#include "Artifact_Installation_Handler_export.h"
#include "ace/Singleton.h"
#include <string>

namespace DAnCE
  {
    class Artifact_Installation_Handler_Export HttpInstallationHandler
      : public ArtifactInstallationHandler
      {
        public:
          static const std::string protocol;

          HttpInstallationHandler ();
          virtual ~HttpInstallationHandler ();

          virtual const std::string& protocol_prefix (void);

          virtual void initialize ();

          virtual void clear ();

          virtual void install (const std::string& plan_uuid,
                                std::string& location,
                                const TPropertyMap& properties);

          virtual void remove (const std::string& plan_uuid,
                               const std::string& location);
      };

    class Artifact_Installation_Handler_Export HttpInstallationHandlerSvc
      : public ArtifactInstallationHandlerSvc
      {
        public:
          HttpInstallationHandlerSvc ();
          virtual ~HttpInstallationHandlerSvc ();

          virtual ArtifactInstallationHandler* handler_instance ();

          static int Initializer (void);
        private:
          typedef ACE_Unmanaged_Singleton<HttpInstallationHandler, ACE_Null_Mutex> THandlerSingleton;
      };

    static int DAnCE_Requires_HttpInstallationHandler_Service_Initializer =
      HttpInstallationHandlerSvc::Initializer ();

    ACE_STATIC_SVC_DECLARE (HttpInstallationHandlerSvc)
    ACE_FACTORY_DECLARE (Artifact_Installation_Handler, HttpInstallationHandlerSvc)

  }

#include /**/ "ace/post.h"
#endif /* DANCE_HTTP_INSTALLATION_HANDLER_H */
