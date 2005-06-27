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
  static Options *instance (void);
  // Returns the singleton instance

  void parse_args (int argc, ACE_TCHAR *argv[]);
  // parses commandline arguments

  ACE_CString package_;
  // Name of package

  ACE_CString local_path_;
  // specifies the local path for install

  ACE_CString artifact_;
  // Implementation Artifact requested

  bool delete_;
  // delete the package_ name

  bool install_;
  // installs the package_ name

  bool plan_;
  // retrieves the DeploymentPlan specified in the package_ name

  bool shutdown_;
  //shutdown the RepositoryManagerDemon

protected:
  Options (void);
  // protected constructor, singleton

  static Options *instance_;
  // the singleton

  void usage (void);
};

#endif /* RM_OPTIONS_H */
