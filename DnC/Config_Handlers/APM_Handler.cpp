// $Id$

#ifndef APM_HANDLER_C
#define APM_HANDLER_C

#include "APM_Handler.h"
#include "tao/Exception.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"

#include "SPR_Handler.h"
#include "APM_Handler.h"

#include <iostream>

using std::cerr;
using std::endl;


namespace CIAO
{
  namespace Config_Handler
  {
    APM_Handler::APM_Handler (DOMDocument* doc, unsigned long filter)
      : traverse_ (doc),
        root_ (doc->getDocumentElement()),
        filter_ (filter),
        iter_ (traverse_->createNodeIterator (this->root_,
                                              this->filter_,
                                              0,
                                              true)),
        release_ (true)
    {}

    APM_Handler::APM_Handler (DOMNodeIterator* iter, bool release)
      : traverse_ (0), root_ (0), filter_ (0), iter_ (iter), release_ (release)
    {}


    APM_Handler::~APM_Handler()
    {
      if (this->release_)
        this->iter_->release();
    }

    void APM_Handler::process_AssemblyPropertyMapping
    (::Deployment::AssemblyPropertyMapping &apm)
    {
      for (DOMNode* node = this->iter_->nextNode();
           node != 0;
           node = this->iter_->nextNode())
        {
          XStr name (node->getNodeName());
          if (name == XStr (ACE_TEXT ("name")))
            {
              // Fetch the text node which contains the value
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_name (text->getNodeValue(), apm);
            }
          else if (name == XStr (ACE_TEXT ("externalName")))
            {
              // Fetch the text node which contains the value
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_externalName (text->getNodeValue(), apm);
            }
          else if (name == XStr (ACE_TEXT ("delegatesTo")))
            {
              // increment sequence length
              CORBA::ULong i (apm.delegatesTo.length ());
              apm.delegatesTo.length (i + 1);

              // delegate to SPR handler
              SPR_Handler handler (iter_, false); // SubcomponentPropertyReference
              handler.process_SubcomponentPropertyReference (apm.delegatesTo[i]);
            }
          else
            {
              // ??? How did we get here ???
              ACE_THROW (CORBA::INTERNAL());
            }
        }
      return;
    }

    void APM_Handler::process_name (const XMLCh* name, ::Deployment::AssemblyPropertyMapping &apm)
    {
      if (name)
        {
          apm.name = XMLString::transcode (name);
        }
    }

    void APM_Handler::process_externalName (const XMLCh* name, ::Deployment::AssemblyPropertyMapping &apm)
    {
      if (name)
        {
          apm.externalName = XMLString::transcode (name);
        }
    }
  }
}

#endif /* APM_HANDLER_C */

