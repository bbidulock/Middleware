/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
// 
// = FILENAME
//    Log_Record.h
//
// = AUTHOR
//    Doug Schmidt 
// 
// ============================================================================

// These need to go outside of the #ifdef to avoid problems with
// circular dependencies...
#include "ace/ACE.h"
#include "ace/Log_Priority.h"

#if !defined (ACE_LOG_RECORD_H)
#define ACE_LOG_RECORD_H

// In case ace/stdcpp.h is not #included before this header . . .
#if !defined(ACE_STDCPP_H)
  class ostream;
#endif

class ACE_Export ACE_Log_Record
{
  // = TITLE
  //     Defines the structure of an ACE logging record.
public:
  enum 
  {
    MAXLOGMSGLEN = ACE_MAXLOGMSGLEN,
    // Maximum size of a logging message. 

    ALIGN_WORDB	 = 8,
    // Most restrictive alignment. 

    VERBOSE_LEN = 128
    // Size used by verbose mode.
    // 20 (date) + 15 (host_name) + 10 (pid) + 10 (type) + 4 (@) ... +
    // ? (progname)
  };

  // = Initialization
  ACE_Log_Record (void);
  ACE_Log_Record (ACE_Log_Priority lp, 
		  long time_stamp,
		  long pid);
  // Create a <Log_Record> and set its priority, time stamp, and
  // process id.
  ACE_Log_Record (ACE_Log_Priority lp, 
		  const ACE_Time_Value &time_stamp,
		  long pid);
  // Create a <Log_Record> and set its priority, time stamp, and
  // process id.

  int print (const char host_name[], 
	     int verbose = 1, 
	     FILE *fp = stderr);
  // Write the contents of the logging record to the appropriate
  // <FILE>.

  int print (const char host_name[], 
	     int verbose, 
	     ostream &stream);
  // Write the contents of the logging record to the appropriate
  // <ostream>.

  // = Marshall/demarshall
  void encode (void);
  // Encode the <Log_Record> for transmission on the network.

  void decode (void);
  // Decode the <Log_Record> received from the network.

  // = Set/get methods

  long type (void) const;
  // Get the type of the <Log_Record>.

  void type (long);
  // Set the type of the <Log_Record>.

  long length (void) const;
  // Get the length of the <Log_Record>.

  void length (long);
  // Set the length of the <Log_Record>.

  const ACE_Time_Value &time_stamp (void) const;
  // Get the time stamp of the <Log_Record>.

  void time_stamp (const ACE_Time_Value &);
  // Set the time stamp of the <Log_Record>.

  long pid (void) const;
  // Get the process id of the <Log_Record>.

  void pid (long);
  // Set the process id of the <Log_Record>.

  char *msg_data (void);
  // Get the message data of the <Log_Record>.

  void msg_data (const char *data);
  // Set the message data of the <Log_Record>.

  void msg_data_len (size_t len);
  // Set the size of the message data of the <Log_Record>.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  void round_up (void);
  // Round up to the alignment restrictions.

  long type_;
  // Type of logging record.

  long length_;      
  // Total length of the logging record in bytes.

  ACE_Time_Value time_stamp_;  
  // Time that the logging record was generated.

  long pid_;         
  // Id of process that generated the logging record.

  char msg_data_[MAXLOGMSGLEN]; 
  // Logging record data 
};

#include "ace/Log_Record.i"
#endif /* ACE_LOG_RECORD_H */
