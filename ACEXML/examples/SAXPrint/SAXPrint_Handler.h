// $Id$

#ifndef ACEXML_SAXPRINT_HANDLER_H
#define ACEXML_SAXPRINT_HANDLER_H

#include "common/DefaultHandler.h"

class ACEXML_SAXPrint_Handler : public ACEXML_DefaultHandler
{
public:
  /*
   * Default constructor.
   */
  ACEXML_SAXPrint_Handler (void);

  /*
   * Default destructor.
   */
  virtual ~ACEXML_SAXPrint_Handler (void);

  // Methods inherit from ACEXML_ContentHandler.

  /*
   * Receive notification of character data.
   */
  virtual void characters (const ACEXML_Char *ch,
                           int start,
                           int length,
                           ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of the end of a document.
   */
  virtual void endDocument (ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of the end of an element.
   */
  virtual void endElement (const ACEXML_Char *namespaceURI,
                           const ACEXML_Char *localName,
                           const ACEXML_Char *qName,
                           ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * End the scope of a prefix-URI mapping.
   */
  virtual void endPrefixMapping (const ACEXML_Char *prefix,
                                 ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of ignorable whitespace in element content.
   */
  virtual void ignorableWhitespace (const ACEXML_Char *ch,
                                    int start,
                                    int length,
                                    ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of a processing instruction.
   */
  virtual void processingInstruction (const ACEXML_Char *target,
                                      const ACEXML_Char *data,
                                      ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive an object for locating the origin of SAX document events.
   */
  virtual void setDocumentLocator (ACEXML_Locator *locator,
                                   ACEXML_Env &xmlenv) ;

  /*
   * Receive notification of a skipped entity.
   */
  virtual void skippedEntity (const ACEXML_Char *name,
                              ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of the beginning of a document.
   */
  virtual void startDocument (ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of the beginning of an element.
   */
  virtual void startElement (const ACEXML_Char *namespaceURI,
                             const ACEXML_Char *localName,
                             const ACEXML_Char *qName,
                             ACEXML_Attributes *atts,
                             ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Begin the scope of a prefix-URI Namespace mapping.
   */
  virtual void startPrefixMapping (const ACEXML_Char *prefix,
                                   const ACEXML_Char *uri,
                                   ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  // *** Methods inherit from ACEXML_DTDHandler.

  /*
   * Receive notification of a notation declaration event.
   */
  virtual void notationDecl (const ACEXML_Char *name,
                             const ACEXML_Char *publicId,
                             const ACEXML_Char *systemId,
                             ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of an unparsed entity declaration event.
   */
  virtual void unparsedEntityDecl (const ACEXML_Char *name,
                                   const ACEXML_Char *publicId,
                                   const ACEXML_Char *systemId,
                                   const ACEXML_Char *notationName,
                                   ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  // Methods inherit from ACEXML_EnitityResolver.

  /*
   * Allow the application to resolve external entities.
   */
  virtual ACEXML_InputSource *resolveEntity (const ACEXML_Char *publicId,
                                             const ACEXML_Char *systemId,
                                             ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  // Methods inherit from ACEXML_ErrorHandler.

  /*
   * Receive notification of a recoverable error.
   */
  virtual void error (ACEXML_SAXParseException &exception,
                      ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of a non-recoverable error.
   */
  virtual void fatalError (ACEXML_SAXParseException &exception,
                           ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  /*
   * Receive notification of a warning.
   */
  virtual void warning (ACEXML_SAXParseException &exception,
                        ACEXML_Env &xmlenv)
    //    ACE_THROW_SPEC ((ACEXML_SAXException))
    ;

  void inc_indent ();
  void dec_indent ();
  void print_indent ();

private:
  size_t indent_;

};

#if defined (__ACEXML_INLINE__)
# include "SAXPrint_Handler.i"
#endif /* __ACEXML_INLINE__ */
#endif /* ACEXML_SAXPRINT_HANDLER_H */
