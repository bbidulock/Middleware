//==================================================================
/**
 *  @file Process_Element.cpp
 *
 *  $Id$
 *
 *  @author Emre Turkay  <turkaye@dre.vanderbilt.edu>
 */
//=====================================================================

#include "Process_Element.h"

DOMDocument* create_document (const char *url)
{
  xercesc::XMLPlatformUtils::Initialize();
  static const XMLCh gLS[] = { xercesc::chLatin_L,
                               xercesc::chLatin_S,
                               xercesc::chNull };

  DOMImplementation* impl
    = DOMImplementationRegistry::getDOMImplementation(gLS);

  DOMBuilder* parser =
    ((DOMImplementationLS*)impl)->createDOMBuilder
    (DOMImplementationLS::MODE_SYNCHRONOUS, 0);

  // Discard comment nodes in the document
  parser->setFeature (XMLUni::fgDOMComments, false);

  // Disable datatype normalization. The XML 1.0 attribute value
  // normalization always occurs though.
  parser->setFeature (XMLUni::fgDOMDatatypeNormalization, true);

  // Do not create EntityReference nodes in the DOM tree. No
  // EntityReference nodes will be created, only the nodes
  // corresponding to their fully expanded sustitution text will be
  // created.
  parser->setFeature (XMLUni::fgDOMEntities, false);

  // Perform Namespace processing.
  parser->setFeature (XMLUni::fgDOMNamespaces, true);

  // Perform Validation
  parser->setFeature (XMLUni::fgDOMValidation, true);

  // Do not include ignorable whitespace in the DOM tree.
  parser->setFeature (XMLUni::fgDOMWhitespaceInElementContent, false);

  // Enable the parser's schema support.
  parser->setFeature (XMLUni::fgXercesSchema, true);

  // Enable full schema constraint checking, including checking which
  // may be time-consuming or memory intensive. Currently, particle
  // unique attribution constraint checking and particle derivation
  // restriction checking are controlled by this option.
  parser->setFeature (XMLUni::fgXercesSchemaFullChecking, true);

  // The parser will treat validation error as fatal and will exit.
  parser->setFeature (XMLUni::fgXercesValidationErrorAsFatal, true);


  DOMDocument* doc = parser->parseURI (url);
  ACE_TString root_node_name;

  root_node_name = XMLString::transcode
    (doc->getDocumentElement ()->getNodeName ());

  return doc;
}

/*
 *  Process references
 */

void
process_refs(DOMNode*& node,
             CORBA::ULongSeq& seq,
             int& index,
             IDREF_MAP& idref_map)
{
  CORBA::ULong i (seq.length ());
  seq.length (i + 1);
  seq[i] = index;
  if (node->hasAttributes())
    {
      DOMNamedNodeMap* named_node_map = node->getAttributes ();
      
      int length = named_node_map->getLength ();
      
      for (int j = 0; j < length; j++)
        {
          DOMNode* attribute_node = named_node_map->item (j);
          XStr strattrnodename (attribute_node->getNodeName ());
          ACE_TString aceattrnodevalue = XMLString::transcode
            (attribute_node->getNodeValue ());
          if (strattrnodename == XStr (ACE_TEXT ("xmi:idref")))
            {
              //index = index + 1;
              idref_map.bind (index, aceattrnodevalue);
            }
        }
    }
}

void
process_ref(DOMNode*& node,
            CORBA::ULong& ref,
            int& index,
            IDREF_MAP& idref_map)
{
  ref = index;
  if (node->hasAttributes ())
    {
      DOMNamedNodeMap* named_node_map = node->getAttributes ();
      
      int length = named_node_map->getLength ();
      
      for (int j = 0; j < length; j++)
        {
          DOMNode* attribute_node = named_node_map->item (j);
          XStr strattrnodename (attribute_node->getNodeName ());
          ACE_TString aceattrnodevalue = XMLString::transcode
            (attribute_node->getNodeValue ());
          if (strattrnodename == XStr (ACE_TEXT ("xmi:idref")))
            {
              //index = index + 1;
              idref_map.bind (index, aceattrnodevalue);
            }
        }
    }
}
