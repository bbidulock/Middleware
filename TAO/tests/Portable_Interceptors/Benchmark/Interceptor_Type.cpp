// -*- C++ -*-
//
// $Id$
//

#include "Interceptor_Type.h"
#include "ace/OS_String.h"

ACE_RCSID (Benchmark, Interceptor_Type, "$Id$")

void get_interceptor_type (int argc, char *argv[],
                           int &interceptor_type)
{
  interceptor_type = IT_NONE;
  for (int i = 1; i < argc - 1; ++i)
    {
      if (ACE_OS_String::strcmp (argv[i], "-r") == 0)
        {
          if (ACE_OS_String::strcmp (argv[i+1], "none") == 0)
            interceptor_type = IT_NONE;
          if (ACE_OS_String::strcmp (argv[i+1], "noop") == 0)
            interceptor_type = IT_NOOP;
          if (ACE_OS_String::strcmp (argv[i+1], "context") == 0)
            interceptor_type = IT_CONTEXT;
          if (ACE_OS_String::strcmp (argv[i+1], "dynamic") == 0)
            interceptor_type = IT_DYNAMIC;
        }
    }
}
