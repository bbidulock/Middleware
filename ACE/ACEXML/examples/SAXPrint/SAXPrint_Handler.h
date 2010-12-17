// $Id$

//=============================================================================
/**
 *  @file    SAXPrint_Handler.h
 *
 *  $Id$
 *
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACEXML_SAXPRINT_HANDLER_H
#define ACEXML_SAXPRINT_HANDLER_H

#include "ACEXML/common/DefaultHandler.h"

/**
 * @class ACEXML_SAXPrint_Handler
 *
 * @brief ACEXML_SAXPrint_Handler is an example SAX event handler.
 *
 * This SAX event handler try to regenerate the XML document it
 * reads with correct indentation.
 */
class ACEXML_SAXPrint_Handler : public ACEXML_DefaultHandler
{
public:
  /*
   * Default constructor.
   */
  ACEXML_SAXPrint_Handler (const ACEXML_Char* name);

  /*
   * Default destructor.
   */
  virtual ~ACEXML_SAXPrint_Handler (void);

  // Methods inherit from ACEXML_ContentHandler.

  /*
   * Receive notification of character data.
   */
  virtual void characters (const ACEXML_Char *ch,
                           size_t start,
                           size_t length)
    ;

  /*
   * Receive notification of the end of a document.
   */
  virtual void endDocument (void)
    ;

  /*
   * Receive notification of the end of an element.
   */
  virtual void endElement (const ACEXML_Char *namespaceURI,
                           const ACEXML_Char *localName,
                           const ACEXML_Char *qName);

  /*
   * End the scope of a prefix-URI mapping.
   */
  virtual void endPrefixMapping (const ACEXML_Char *prefix);

  /*
   * Receive notification of ignorable whitespace in element content.
   */
  virtual void ignorableWhitespace (const ACEXML_Char *ch,
                                    int start,
                                    int length);

  /*
   * Receive notification of a processing instruction.
   */
  virtual void processingInstruction (const ACEXML_Char *target,
                                      const ACEXML_Char *data);

  /*
   * Receive an object for locating the origin of SAX document events.
   */
  virtual void setDocumentLocator (ACEXML_Locator *locator);

  /*
   * Receive notification of a skipped entity.
   */
  virtual void skippedEntity (const ACEXML_Char *name);

  /*
   * Receive notification of the beginning of a document.
   */
  virtual void startDocument (void);

  /*
   * Receive notification of the beginning of an element.
   */
  virtual void startElement (const ACEXML_Char *namespaceURI,
                             const ACEXML_Char *localName,
                             const ACEXML_Char *qName,
                             ACEXML_Attributes *atts);

  /*
   * Begin the scope of a prefix-URI Namespace mapping.
   */
  virtual void startPrefixMapping (const ACEXML_Char *prefix,
                                   const ACEXML_Char *uri);

  // *** Methods inherit from ACEXML_DTDHandler.

  /*
   * Receive notification of a notation declaration event.
   */
  virtual void notationDecl (const ACEXML_Char *name,
                             const ACEXML_Char *publicId,
                             const ACEXML_Char *systemId);

  /*
   * Receive notification of an unparsed entity declaration event.
   */
  virtual void unparsedEntityDecl (const ACEXML_Char *name,
                                   const ACEXML_Char *publicId,
                                   const ACEXML_Char *systemId,
                                   const ACEXML_Char *notationName);

  // Methods inherit from ACEXML_EnitityResolver.

  /*
   * Allow the application to resolve external entities.
   */
  virtual ACEXML_InputSource *resolveEntity (const ACEXML_Char *publicId,
                                             const ACEXML_Char *systemId);

  // Methods inherit from ACEXML_ErrorHandler.

  /*
   * Receive notification of a recoverable error.
   */
  virtual void error (ACEXML_SAXParseException &exception);

  /*
   * Receive notification of a non-recoverable error.
   */
  virtual void fatalError (ACEXML_SAXParseException &exception);

  /*
   * Receive notification of a warning.
   */
  virtual void warning (ACEXML_SAXParseException &exception);

  void inc_indent ();
  void dec_indent ();
  void print_indent ();

private:

  size_t indent_;
  ACEXML_Char* fileName_;
  ACEXML_Locator* locator_;
};

#if defined (__ACEXML_INLINE__)
# include "SAXPrint_Handler.inl"
#endif /* __ACEXML_INLINE__ */
#endif /* ACEXML_SAXPRINT_HANDLER_H */
