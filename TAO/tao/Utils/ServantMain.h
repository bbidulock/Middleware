/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    ServantMain.h
 *
 *  $Id$
 *
 *  Declares a generic object that acts as "main" for a CORBA server.
 *  @author Dale Wilson <wilson_d@ociweb.com>
 *
 *  This object supports creation of a relatively simple CORBA server.
 *  The object implements "main" for a process.
 *  A single servant is created and initialized as the process begins
 *  execution.  The lifetime of this initial servant is the lifetime of
 *  the process.
 *  The servant is free to create other servants as necessary.
 *  The servant can capture command line options.
 *  A callback method in the ORB event loop allows the servant to act
 *  asynchronously if necessary.
 *  The callback method allows the servant to request process termination
 *  and specify the status to be returned from the process.
 *
 *  The application should create a C/C++ main that looks something like:
 *    #include <tao/Utils/ServantMain.h>
 *    #include "Xyzzy_i.h"
 *    int ACE_TMAIN (int argc, ACE_TCHAR *argv[])
 *    {
 *      ServantMain<Xyzzy_i> servant ("Xyzzy");
 *      return servant.Main(argc, argv);
 *    }
 *
 *  The servant implementation (Xyzzy_i in this case) must implement
 *  the following methods:
 *      Xyzzy_i (); // null constructor
 *      ~Xyzzy_i (); // destructor
 *      int parse_args (int argc, char * argv[]);
 *      int init (TAO_ORB_Manager & orbManager ACE_ENV_ARG_DECL_WITH_DEFAULTS);
 *      int idle(int &result);
 *      int fini (ACE_ENV_SINGLE_ARG_DECL);
 *      const char * identity () const;
 *
 *      parse_args, self_register, self_unregister return 0 if ok, nonzero for error.
 *      idle returns 0 to continue execution; nonzero to exit -- returning "result" from the process
 *      identity provides a string to identify this servant in log messages.
 *
 */
//=============================================================================

#ifndef TAO_UTILS_SERVANTMAIN_H
#define TAO_UTILS_SERVANTMAIN_H

#include <ace/ACE.h>
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ <ace/pre.h>
namespace TAO
{
  namespace Utils
  {
    template <typename SERVANT>
    class ServantMain
    {
    public:
      ServantMain(const char * name);
      ~ServantMain();

      int Main (int argc, ACE_TCHAR *argv[]);

    private:
      ServantMain( const ServantMain &);
      ServantMain & operator = (const ServantMain &);

    private:
      const char * name_;
    };
  } // namespace UTILS
} // namespace TAO

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
# include "ServantMain.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
# pragma implementation "ServantMain.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ <ace/post.h>

#endif //TAO_UTILS_SERVANTMAIN_H
