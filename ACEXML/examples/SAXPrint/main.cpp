// $Id$

#include "common/FileCharStream.h"
#include "parser/parser/Parser.h"
#include "Print_Handler.h"
#include "SAXPrint_Handler.h"


int
main (int argc, char *argv[])
{
  ACEXML_DefaultHandler *handler = 0;
  {
    if (argc < 2)
      {
        cerr << "Usage: SAXPrint <XML filename> [-n]" << endl;
        return 1;
      }

    ACEXML_FileCharStream *fstm = 0;
    ACE_NEW_RETURN (fstm,
                    ACEXML_FileCharStream (),
                    1);

    if (fstm->open (argv [1]) != 0)
      {
        cerr << "Fail to open XML file: " << argv[1] << endl;
        return 1;
      }

    if (argc == 2)              //
      ACE_NEW_RETURN (handler,
                      ACEXML_Print_Handler (),
                      -1);
    else
      ACE_NEW_RETURN (handler,
                      ACEXML_SAXPrint_Handler (),
                      -1);

    ACEXML_Parser parser;
    ACEXML_InputSource input(fstm);

    parser.setContentHandler (handler);
    parser.setDTDHandler (handler);
    parser.setErrorHandler (handler);
    parser.setEntityResolver (handler);

    ACEXML_Env xmlenv;

    parser.parse (&input, xmlenv);
    if (xmlenv.exception ())
      xmlenv.exception ()->print ();

    cout << "\r\r\r";
  }
  delete handler;
  return 0;
}
