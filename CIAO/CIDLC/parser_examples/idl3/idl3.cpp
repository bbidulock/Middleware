// $Id$

#if defined(_DEBUG)
//#define SPIRIT_DEBUG
#endif // defined(_DEBUG)

#include "idl3_grammar.h"

int
main (int argc, char* argv[])
{
// Start grammar definition
  cerr << "IDL3 Grammar checker implemented with Spirit ..." << endl;

// main driver code
idl3_grammar g;

  if (2 == argc)
    {
      parse (g, 
             argv[1]);
    }
  else
    {
      cerr << "No filename given" << endl;
    }
   
  return 0;
}
