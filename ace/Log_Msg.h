// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    ace
//
// = FILENAME
//    Log_Msg.h
//
// = AUTHOR
//    Douglas C. Schmidt <schmidt@cs.wustl.edu>
//
// ============================================================================

#ifndef ACE_LOG_MSG_H
#define ACE_LOG_MSG_H
#include "ace/pre.h"

// This stuff must come first to avoid problems with circular
// headers...

// The following ASSERT macro is courtesy of Alexandre Karev
// <akg@na47sun05.cern.ch>.
#if defined (ACE_NDEBUG)
#define ACE_ASSERT(x)
#else
#define ACE_ASSERT(X) \
  do { if(!(X)) { \
  int __ace_error = ACE_OS::last_error (); \
  ACE_Log_Msg *ace___ = ACE_Log_Msg::instance (); \
  ace___->set (ACE_TEXT_CHAR_TO_TCHAR(__FILE__), __LINE__, -1, __ace_error, ace___->restart (), \
               ace___->msg_ostream (), ace___->msg_callback ()); \
  ace___->log (LM_ERROR, ACE_TEXT ("ACE_ASSERT: file %N, line %l assertion failed for '%s'.%a\n"), #X, -1); \
  } } while (0)
#endif  /* ACE_NDEBUG */

#if defined (ACE_NLOGGING)
#define ACE_HEX_DUMP(X) do {} while (0)
#define ACE_RETURN(Y) do { return (Y); } while (0)
#define ACE_ERROR_RETURN(X, Y) return (Y)
#define ACE_ERROR_BREAK(X) { break; }
#define ACE_ERROR(X) do {} while (0)
#define ACE_DEBUG(X) do {} while (0)
#define ACE_ERROR_INIT(VALUE, FLAGS)
#else
#define ACE_HEX_DUMP(X) \
  do { \
    int __ace_error = ACE_OS::last_error (); \
    ACE_Log_Msg *ace___ = ACE_Log_Msg::instance (); \
    if (ace___->log_priority_enabled X != 0) { \
      ace___->set (ACE_TEXT_CHAR_TO_TCHAR(__FILE__), __LINE__, 0, __ace_error, ace___->restart (), \
                   ace___->msg_ostream (), ace___->msg_callback ()); \
      ace___->log_hexdump X; \
    } \
  } while (0)
#define ACE_RETURN(Y) \
  do { \
    int __ace_error = ACE_OS::last_error (); \
    ACE_Log_Msg::instance ()->set (ACE_TEXT_CHAR_TO_TCHAR (__FILE__), __LINE__, Y, __ace_error); \
    return Y; \
  } while (0)
#define ACE_ERROR_RETURN(X, Y) \
  do { \
    int __ace_error = ACE_OS::last_error (); \
    ACE_Log_Msg *ace___ = ACE_Log_Msg::instance (); \
    if (ace___->log_priority_enabled X != 0) { \
      ace___->set (ACE_TEXT_CHAR_TO_TCHAR (__FILE__), __LINE__, Y, __ace_error, ace___->restart (), \
                   ace___->msg_ostream (), ace___->msg_callback ()); \
      ace___->log X; \
    } \
    return Y; \
  } while (0)
#define ACE_ERROR(X) \
  do { \
    int __ace_error = ACE_OS::last_error (); \
    ACE_Log_Msg *ace___ = ACE_Log_Msg::instance (); \
    if (ace___->log_priority_enabled X != 0) { \
      ace___->set (ACE_TEXT_CHAR_TO_TCHAR (__FILE__), __LINE__, -1, __ace_error, ace___->restart (), \
                   ace___->msg_ostream (), ace___->msg_callback ()); \
      ace___->log X; \
    } \
  } while (0)
#define ACE_DEBUG(X) \
  do { \
    int __ace_error = ACE_OS::last_error (); \
    ACE_Log_Msg *ace___ = ACE_Log_Msg::instance (); \
    if (ace___->log_priority_enabled X != 0) { \
      ace___->set (ACE_TEXT_CHAR_TO_TCHAR(__FILE__), __LINE__, 0, __ace_error, ace___->restart (), \
                   ace___->msg_ostream (), ace___->msg_callback ()); \
      ace___->log X; \
    } \
  } while (0)
#define ACE_ERROR_INIT(VALUE, FLAGS) \
  do { \
    ACE_Log_Msg *ace___ = ACE_Log_Msg::instance (); \
    ace___->set_flags (FLAGS); ace___->op_status (VALUE); \
  } while (0)
#define ACE_ERROR_BREAK(X) { ACE_ERROR (X); break; }
#endif /* ACE_NLOGGING */

#include "ace/Log_Record.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (__Lynx__)
# undef STDERR
#endif /* __Lynx__ */

#if defined (THREAD)
// This workaround is necessary for nasty libraries that #define
// THREAD 1.
#define ACE_THREAD_HACK THREAD
#undef THREAD
#endif /* THREAD */

class ACE_Export ACE_Log_Msg_Callback
{
  // = TITLE
  //     An interface class used to get logging callbacks.
  //
  // = DESCRIPTION
  //     Users who are interested in getting the logging messages
  //     directly, can subclass this interface and override the log()
  //     method. They must then register their subclass with the
  //     Log_Msg class and make sure that they turn on the
  //     ACE_Log_Msg::MSG_CALLBACK flag.
  //
  //     Your <log> routine is called with an instance of
  //     ACE_Log_Record.  From this class, you can get the log
  //     message, the verbose log message, message type, message
  //     priority, and so on.
  //
  //     Remember that there is one Log_Msg object per thread.
  //     Therefore, you may need to register your callback object with
  //     many <ACE_Log_Msg> objects (and have the correct
  //     synchronization in the <log> method) or have a separate
  //     callback object per Log_Msg object.  Moreover,
  //     <ACE_Log_Msg_Callbacks> are not inherited when a new thread
  //     is spawned, so you'll need to reset these in each new thread.
public:
  virtual ~ACE_Log_Msg_Callback (void);
  // No-op virtual destructor.

  virtual void log (ACE_Log_Record &log_record) = 0;
  // Callback routine.  This is called when we want to log a message.
  // Since this routine is pure virtual, it must be overwritten by the
  // subclass.
};

// ****************************************************************

class ACE_Export ACE_Log_Msg_Attributes
{
  // = TITLE
  //   The Log_Msg attributes inherited by newly spawned threads
  //
  // = DESCRIPTION
  //   When a new thread is created the TSS resources for the Log_Msg
  //   class in the new thread may be inherited by the creator thread.
  //   The attributes are encapsulated in this class to simplify their
  //   manipulation and destruction.
public:
  ACE_Log_Msg_Attributes (
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
                          ACE_SEH_EXCEPT_HANDLER selector = 0
                          , ACE_SEH_EXCEPT_HANDLER handler = 0
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
                          );
  // Constructor

  ~ACE_Log_Msg_Attributes (void);
  // Destructor

  static void init_hook (void *&attributes
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
                         , ACE_SEH_EXCEPT_HANDLER selector = 0
                         , ACE_SEH_EXCEPT_HANDLER handler = 0
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
                         );
  // Init hook, create a Log_Msg_Attribute object, initialize its
  // attributes from the TSS Log_Msg and save the object in the
  // <attributes> argument

  static void inherit_hook (ACE_OS_Thread_Descriptor *thr_desc,
                            void *&attributes);
  // Inherit hook, the <attributes> field is a Log_Msg_Attribute
  // object, invoke the <inherit_log_msg> method on it, then destroy
  // it and set the <attribute> argument to 0

private:
  void inherit_log_msg (ACE_OS_Thread_Descriptor *thr_desc);
  // Initialize the TSS Log_Msg from the attributes saved on this
  // object

  ACE_OSTREAM_TYPE *ostream_;
  // Ostream where the new TSS Log_Msg will use.

  u_long priority_mask_;
  // Priority_mask to be used in new TSS Log_Msg.

  int tracing_enabled_;
  // Are we allowing tracing in this thread?

  int restart_;
  // Indicates whether we should restart system calls that are
  // interrupted.

  int trace_depth_;
  // Depth of the nesting for printing traces.

#   if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  ACE_SEH_EXCEPT_HANDLER seh_except_selector_;
  ACE_SEH_EXCEPT_HANDLER seh_except_handler_;
#   endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
};

// ****************************************************************

#define ACE_LOG_MSG ACE_Log_Msg::instance ()

// Forward declaration
class ACE_Thread_Descriptor;

class ACE_Export ACE_Log_Msg
{
  // = TITLE
  //     Provides a variable length argument message logging
  //     abstraction.
  //
  // = DESCRIPTION
  //     This class is very flexible since it allows formatted error
  //     messages to be printed in a thread-safe manner to stderr or a
  //     distributed logger.  Moreover, the message is kept in a
  //     thread-specific storage location (i.e. there is one ACE_Log_Msg
  //     object per thread), which can be used to communicate errors
  //     between framework methods and callers.
  //
  //     A message is logged by the log() method, only if the message
  //     priority is currently enabled.  The ACE_Log_Msg class uses
  //     two priority masks to control its logging behavior.  The
  //     <priority_mask_> object attribute is thread specific and
  //     specifies the priority levels logged by the thread.  The
  //     <process_priority_mask_> class attribute is not thread
  //     specific and specifies the priority levels that will be
  //     logged by all threads in the process.  By default, all
  //     levels are enabled for <priority_mask_> and all levels
  //     are disabled for <process_priority_mask_> (i.e. each thread
  //     determines which priority levels will be logged).  Both
  //     priority masks can be modified using the priority_mask()
  //     method of this class.

public:
  // Logger Flags.
  enum
  {
    STDERR = 1,
    // Write messages to stderr.
    LOGGER = 2,
    // Write messages to the local client logger deamon.
    OSTREAM = 4,
    // Write messages to the ostream * stored in thread-specific
    // storage.
    MSG_CALLBACK = 8,
    // Write messages to the callback object.
    VERBOSE = 16,
    // Display messages in a verbose manner.
    VERBOSE_LITE = 32,
    // Display messages in a less verbose manner (i.e., only print
    // information that can change between calls).
    SILENT = 64
    // Do not print messages at all (just leave in thread-specific
    // storage for later inspection).
 };

  // = Initialization and termination routines.

  static ACE_Log_Msg *instance (void);
  // Returns a pointer to the Singleton.

  static int exists (void);
  // Returns non-null if an ACE_Log_Msg exists for the calling thread.

  static void disable_debug_messages (ACE_Log_Priority priority = LM_DEBUG);
  // Clears the flag from the default priority mask used to
  // initialize ACE_Log_Msg instances.

  static void enable_debug_messages (ACE_Log_Priority priority = LM_DEBUG);
  // Sets the flag in the default priority mask used to initialize
  // ACE_Log_Msg instances.

  ACE_Log_Msg (void);
  // Initialize logger.

  ~ACE_Log_Msg (void);
  // cleanup logger.

  int open (const ACE_TCHAR *prog_name,
            u_long options_flags = ACE_Log_Msg::STDERR,
            const ACE_TCHAR *logger_key = 0);
  // Initialize the ACE error handling facility.  <prog_name> is the
  // name of the executable program.  <flags> are a bitwise-or of
  // options flags passed to the Logger (see the enum above for the valid
  // values).  If the <LOGGER> bit in <flags> is enabled then
  // <logger_key> is the name of ACE_FIFO rendezvous point where the
  // local client logger daemon is listening for logging messages.

  // = Set/get the options flags.

  void set_flags (u_long f);
  // Enable the bits in the logger's options flags.
  void clr_flags (u_long f);
  // Disable the bits in the logger's options flags.
  u_long flags (void);
  // Return the bits in the logger's options flags.

  // = Allow apps to acquire and release internal synchronization lock.

  // This lock is used internally by the <ACE_Log_Msg> implementation.
  // By exporting the lock, applications can hold the lock atomically
  // over a number of calls to <ACE_Log_Msg>.
  int acquire (void);
  // Acquire the internal lock.
  int release (void);
  // Release the internal lock.

  void sync (const ACE_TCHAR *program_name);
  // Call after doing a <fork> to resynchronize the process id and
  // <program_name> variables.

  // = Set/get methods.  Note that these are non-static and thus will
  // be thread-specific.

  void op_status (int status);
  // Set the result of the operation status (by convention, -1 means
  // error).

  int op_status (void);
  // Get the result of the operation status (by convention, -1 means
  // error).

  void errnum (int);
  // Set the value of the errnum (by convention this corresponds to
  // errno).

  int errnum (void);
  // Get the value of the errnum (by convention this corresponds to
  // errno).

  void linenum (int);
  // Set the line number where an error occurred.

  int linenum (void);
  // Get the line number where an error occurred.

  void file (const ACE_TCHAR *);
  // Set the file name where an error occurred.

  const ACE_TCHAR *file (void);
  // Get the file name where an error occurred.

  void msg (const ACE_TCHAR *);
  // Set the message that describes what type of error occurred.

  const ACE_TCHAR *msg (void);
  // Get the message that describes what type of error occurred.

  void restart (int);
  // Set the field that indicates whether interrupted calls should be
  // restarted.

  int restart (void);
  // Get the field that indicates whether interrupted calls should be
  // restarted.

  // = Notice that the following two function is equivalent to
  //   "void msg_ostream (HANDLE)" and "HANDLE msg_ostream (void)"
  //   on Windows CE.  There is no <iostream.h> support on CE.

  void msg_ostream (ACE_OSTREAM_TYPE *);
  // Update the ostream without overwriting the delete_ostream_ flag.

  void msg_ostream (ACE_OSTREAM_TYPE *, int delete_ostream);
  // delete_stream == 1, forces Log_Msg.h to delete the stream in
  // its own ~dtor (assumes control of the stream)
  // use only with proper ostream (eg: fstream), not (cout, cerr)

  ACE_OSTREAM_TYPE *msg_ostream (void) const;
  // Get the ostream that is used to print error messages.

  ACE_Log_Msg_Callback *msg_callback (ACE_Log_Msg_Callback *c);
  ACE_Log_Msg_Callback *msg_callback (void) const;
  // Set a new callback object and return the existing callback to
  // allow "chaining".  Note that <ACE_Log_Msg_Callback>s are not
  // inherited when spawning a new thread, so you'll need to reset
  // them in each thread.

  // = Nesting depth increment and decrement.
  int inc (void);
  int dec (void);

  // = Get/set trace depth.
  int trace_depth (void);
  void trace_depth (int);

  // = Get/set trace active status.
  int trace_active (void);
  void trace_active (int value);

  ACE_Thread_Descriptor *thr_desc (void) const;
  // Get the TSS thread descriptor.

  void thr_desc (ACE_Thread_Descriptor *td);
  // Set the TSS thread descriptor.  This method will call
  // td->acquire_release to block execution until this call
  // return.

#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS) && !defined(ACE_HAS_LASTEST_AND_GREATEST)
  // These functions are disabled with ACE_HAS_LATEST_AND_GREATEST
  // because the *semantics* have changed (they objects are no longer
  // TSS).
  ACE_SEH_EXCEPT_HANDLER seh_except_selector (void);
  ACE_SEH_EXCEPT_HANDLER seh_except_selector (ACE_SEH_EXCEPT_HANDLER);
  // Get/Set TSS exception action.
  // NOTE: The action is no longer TSS, they are global!

  ACE_SEH_EXCEPT_HANDLER seh_except_handler (void);
  ACE_SEH_EXCEPT_HANDLER seh_except_handler (ACE_SEH_EXCEPT_HANDLER);
  // Get/Set TSS exception handler.
  // NOTE: The handler is no longer TSS, they are global!
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS && ! ACE_HAS_GREATES_AND_LATEST*/

  // = Stop/start/query tracing status on a per-thread basis...
  void stop_tracing (void);
  void start_tracing (void);
  int  tracing_enabled (void);

  typedef enum
  {
    PROCESS = 0,
    THREAD = 1
  } MASK_TYPE;

  // = Get/set the priority mask.
  u_long priority_mask (MASK_TYPE = THREAD);
  // Get the current <ACE_Log_Priority> mask.
  u_long priority_mask (u_long, MASK_TYPE = THREAD);
  // Set the <ACE_Log_Priority> mask, returns original mask.

  int log_priority_enabled (ACE_Log_Priority log_priority);
  // Return true if the requested priority is enabled.

  int log_priority_enabled (ACE_Log_Priority log_priority,
                            const char *,
                            ...);
  // Return true if the requested priority is enabled.

#if defined (ACE_USES_WCHAR)
  // We are not using ACE_TCHAR for this since ACE_HEX_DUMP
  // doesn't take in a ACE_TCHAR.  log_hexdump takes in a char
  // string, so this must be able to take in a char string even
  // when using ACE_USES_WCHAR.
  int log_priority_enabled (ACE_Log_Priority log_priority,
                            const wchar_t *,
                            ...);
  // Return true if the requested priority is enabled.
#endif /* ACE_USES_WCHAR */

  pid_t getpid (void) const;
  // Optimize reading of the pid (avoids a system call if the value is
  // cached...).

  // = Set/get the name of the local host.
  const ACE_TCHAR *local_host (void) const;
  void local_host (const ACE_TCHAR *);

  void set (const ACE_TCHAR *file,
            int line,
            int op_status = -1,
            int errnum = 0,
            int restart = 1,
            ACE_OSTREAM_TYPE *os = 0,
            ACE_Log_Msg_Callback *c = 0);
  // Set the line number, file name, operational status, error number,
  // restart flag, ostream, and the callback object.  This combines
  // all the other set methods into a single method.

  ssize_t log (ACE_Log_Priority priority, const ACE_TCHAR *format, ...);
  // Format a message to the thread-safe ACE logging mechanism.  Valid
  // options (prefixed by '%', as in printf format strings) include:
  //  'A': print an ACE_timer_t value (which could be either double or ACE_UINT32.)
  //  'a': exit the program at this point (var-argument is the exit status!)
  //  'c': print a character
  //  'i', 'd': print a decimal number
  //  'I', indent according to nesting depth
  //  'e', 'E', 'f', 'F', 'g', 'G': print a double
  //  'l', print line number where an error occurred.
  //  'm': Return the message corresponding to errno value, e.g., as done by strerror()
  //  'N': print file name where the error occurred.
  //  'n': print the name of the program (or "<unknown>" if not set)
  //  'o': print as an octal number
  //  'P': print out the current process id
  //  'p': print out the appropriate errno message from sys_errlist, e.g., as done by perror()
  //  'Q': print out the uint64 number
  //  'r': call the function pointed to by the corresponding argument
  //  'R': print return status
  //  'S': print out the appropriate _sys_siglist entry corresponding to var-argument.
  //  's': print out a character string
  //  'T': print timestamp in hour:minute:sec:usec format.
  //  'D': print timestamp in month/day/year hour:minute:sec:usec format.
  //  't': print thread id (1 if single-threaded)
  //  'u': print as unsigned int
  //  'W': print out a wide (Unicode) character string (currently Win32 only).
  //  'X', 'x': print as a hex number
  //  '%': print out a single percent sign, '%'

  ssize_t log (const ACE_TCHAR *format,
               ACE_Log_Priority priority,
               va_list argp);
  // An alternative logging mechanism that makes it possible to
  // integrate variable argument lists from other logging mechanisms
  // into the ACE mechanism.

  ssize_t log (ACE_Log_Record &log_record,
               int suppress_stderr = 0);
  // Log a custom built log record to the currently enabled logging
  // sinks.

  int log_hexdump (ACE_Log_Priority log_priority,
                   const char *buffer,
                   int size,
                   const ACE_TCHAR *text = 0);
  // Method to log hex dump.  This is useful for debugging.  Calls
  // <log> to do the actual print, but formats first to make the chars
  // printable.

  void dump (void) const;
  // Dump the state of an object.

  ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

private:
  int status_;
  // Status of operation (-1 means failure, >= 0 means success).

  int errnum_;
  // Type of error that occurred (see <sys/errno.h>).

  int linenum_;
  // Line number where the error occurred.

  ACE_TCHAR file_[MAXPATHLEN + 1];
  // File where the error occurred.

  ACE_TCHAR msg_[ACE_Log_Record::MAXLOGMSGLEN];
  // The error message.

  int restart_;
  // Indicates whether we should restart system calls that are
  // interrupted.

  ACE_OSTREAM_TYPE *ostream_;
  // The ostream where logging messages can be written.

  ACE_Log_Msg_Callback *msg_callback_;
  // The callback object.

  int trace_depth_;
  // Depth of the nesting for printing traces.

  int trace_active_;
  // Are we already within an ACE_Trace constructor call?

  int tracing_enabled_;
  // Are we allowing tracing in this thread?

  int delete_ostream_;
  // Are we deleting this ostream?

  ACE_Thread_Descriptor *thr_desc_;
  // If we're running in the context of an <ACE_Thread_Manager> this
  // will point to the thread descriptor adapter which holds the
  // thread descriptor of the thread.  This can be used to repidly
  // access all thread data kept in <ACE_Thread_Descriptor>.

  u_long priority_mask_;
  // Keeps track of all the per-thread <ACE_Log_Priority> values that
  // are currently enabled.  Default is for all logging priorities to
  // be enabled.

  // = The following fields are *not* kept in thread-specific storage.

  // We only want one instance for the entire process!

  static u_long process_priority_mask_;
  // Keeps track of all the per-process <ACE_Log_Priority> values that
  // are currently enabled.  Default is for all logging priorities to
  // be enabled.

  static const ACE_TCHAR *program_name_;
  // Records the program name.

  static const ACE_TCHAR *local_host_;
  // Name of the local host (used when printing messages).

  static pid_t pid_;
  // Process id of the current process.

  static u_long flags_;
  // Options flags.

  static int msg_off_;
  // Offset of msg_[].

  static int instance_count_;
  // Number of existing Log_Msg instances; when 0, delete program/host
  // names
  static u_long default_priority_mask_;
  // Priority mask to use for each new instance

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  static int key_created_;
# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || \
    defined (ACE_HAS_TSS_EMULATION)
  static ACE_thread_key_t log_msg_tss_key_;
# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
#endif /* ACE_MT_SAFE */

  static void close (void);
  // For cleanup, at program termination.

  static void sync_hook (const ACE_TCHAR *prg_name);
  // Decouple the OS layer from the Log_Msg layer.

  friend void ACE_OS::cleanup_tss (const u_int);

  // = Disallow these operations.
  ACE_Log_Msg &operator= (const ACE_Log_Msg &);
  ACE_Log_Msg (const ACE_Log_Msg &);
};

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
# if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || \
     defined (ACE_HAS_TSS_EMULATION)
/* static */
#  if defined (ACE_HAS_THR_C_DEST)
#   define LOCAL_EXTERN_PREFIX extern "C"
#  else
#   define LOCAL_EXTERN_PREFIX
#  endif /* ACE_HAS_THR_C_DEST */
LOCAL_EXTERN_PREFIX
void
ACE_TSS_cleanup (void *ptr);
# endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE || ACE_HAS_TSS_EMULATION */
#endif /* ACE_MT_SAFE */

#if defined (ACE_THREAD_HACK)
#define THREAD ACE_THREAD_HACK
#undef ACE_THREAD_HACK
#endif /* ACE_THREAD_HACK */
#include "ace/post.h"
#endif /* ACE_LOG_MSG_H */
