// $Id: test.cpp 1.1	10/18/96

// Tests the generated perfect has function.
// The -v option prints diagnostics as to whether a word is in 
// the set or not.  Without -v the program is useful for timing.
  
#include <stdio.h>
#include <string.h>

ACE_RCSID(tests, test, "$Id$")

static const int MAX_LEN = 80;

char *in_word_set (const char *str, int len);

int 
main (int argc, char *argv[])
{
  int verbose = argc > 1 && strcmp (argv[1], "-v") == 0 ? 1 : 0;
  char buf[MAX_LEN];

  while (fgets (buf, sizeof buf, stdin) != 0) 
    {
      int len = strlen (buf) - 1;
      buf[len] = '\0';
      if (in_word_set (buf, len) && verbose)
        printf ("in word set %s\n", buf);
      else if (verbose) 
        printf ("NOT in word set %s\n", buf);
    }
  return 0;
}
