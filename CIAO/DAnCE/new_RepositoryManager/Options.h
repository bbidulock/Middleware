// $Id$

/* -*- C++ -*- */
// Options.h, Stoyan

//============================================================================
//
// = LIBRARY
//    JAWS
//
// = FILENAME
//    Options.h
//
// = DESCRIPTION
//     Options is an Singleton for blobby
//
// = AUTHOR
//    Stoyan Paunov
//
//============================================================================

#ifndef RM_OPTIONS_H
#define RM_OPTIONS_H

#include "ace/Get_Opt.h"
#include "ace/SString.h"		//for ACE_CString 			

class Options
{
public:
  /// Returns the singleton instance
  static Options *instance (void);

  /// parses commandline arguments
  void parse_args (int argc, ACE_TCHAR *argv[]);

  /// Name of package
  ACE_CString name_;

  /// Name of package
  ACE_CString uuid_;

  /// specifies the local path for install
  ACE_CString path_;

  /// delete the package_ name
  bool delete_;

  /// installs the package_ name
  bool install_;

  /// installs the package_ name
  bool find_;

  /// shutdown the RepositoryManagerDemon
  bool shutdown_;


protected:
  /// protected constructor, singleton
  Options (void);

  /// the singleton
  static Options *instance_;


  void usage (void);
};

#endif /* RM_OPTIONS_H */
