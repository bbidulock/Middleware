/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Object_Manager_Base.h
 *
 *  $Id$
 *
 *  @author David L. Levine <levine@cs.wustl.edu>
 *  @author Matthias Kerkhoff
 *  @author and Per Andersson
 */
//=============================================================================

#ifndef ACE_OBJECT_MANAGER_BASE_H
#define ACE_OBJECT_MANAGER_BASE_H
#include "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/types.h"
#include "ace/os_include/signal.h"
#include "ace/OS_Export.h"
#include "ace/Global_Macros.h"

//////////////////////////////////////////////////////////
// This is used by Object Manager and classes scheduled for 
// cleanup.  So you have to see both to use it (i.e. all singletons)

// Signature for registering a cleanup function that is used by the
// <ACE_Object_Manager> and the <ACE_Thread_Manager>.
# if defined (ACE_HAS_SIG_C_FUNC)
extern "C" {
# endif /* ACE_HAS_SIG_C_FUNC */
typedef void (*ACE_CLEANUP_FUNC)(void *object, void *param) /* throw () */;
# if defined (ACE_HAS_SIG_C_FUNC)
}
# endif /* ACE_HAS_SIG_C_FUNC */

/**
 * @class ACE_Cleanup
 *
 * @brief Base class for objects that are cleaned by ACE_Object_Manager.
 */
class ACE_OS_Export ACE_Cleanup
{
public:
  /// No-op constructor.
  ACE_Cleanup (void);

  /// Destructor.
  virtual ~ACE_Cleanup (void);

  /// Cleanup method that, by default, simply deletes itself.
  virtual void cleanup (void *param = 0);
};

// Adapter for cleanup, used by ACE_Object_Manager.
extern "C" ACE_OS_Export
void ace_cleanup_destroyer (ACE_Cleanup *, void *param = 0);

/**
 * @class ACE_Cleanup_Info
 *
 * @brief Hold cleanup information for thread/process
 */
class ACE_OS_Export ACE_Cleanup_Info
{
public:
  /// Default constructor.
  ACE_Cleanup_Info (void);

  /// Equality operator.
  int operator== (const ACE_Cleanup_Info &o) const;

  /// Inequality operator.
  int operator!= (const ACE_Cleanup_Info &o) const;

  /// Point to object that gets passed into the <cleanup_hook_>.
  void *object_;

  /// Cleanup hook that gets called back.
  ACE_CLEANUP_FUNC cleanup_hook_;

  /// Parameter passed to the <cleanup_hook_>.
  void *param_;
};

class ACE_Cleanup_Info_Node;

/**
 * @class ACE_OS_Exit_Info
 *
 * @brief Hold Object Manager cleanup (exit) information.
 *
 * For internal use by the ACE library, only.
 */
class ACE_OS_Export ACE_OS_Exit_Info
{
public:
  /// Default constructor.
  ACE_OS_Exit_Info (void);

  /// Destructor.
  ~ACE_OS_Exit_Info (void);

  /// Use to register a cleanup hook.
  int at_exit_i (void *object, ACE_CLEANUP_FUNC cleanup_hook, void *param);

  /// Look for a registered cleanup hook object.  Returns 1 if already
  /// registered, 0 if not.
  int find (void *object);

  /// Call all registered cleanup hooks, in reverse order of
  /// registration.
  void call_hooks ();

private:
  /**
   * Keeps track of all registered objects.  The last node is only
   * used to terminate the list (it doesn't contain a valid
   * ACE_Cleanup_Info).
   */
  ACE_Cleanup_Info_Node *registered_objects_;
};
//////////////////////////////////////////////////////////////////





/**
 * @class ACE_Object_Manager_Base
 *
 * @brief Base class for ACE_Object_Manager(s).
 *
 * Encapsulates the most useful ACE_Object_Manager data structures.
 */
class ACE_OS_Export ACE_Object_Manager_Base
{
# if (defined (ACE_PSOS) && defined (__DIAB))  || \
     (defined (__DECCXX_VER) && __DECCXX_VER < 60000000)
  // The Diab compiler got confused and complained about access rights
  // if this section was protected (changing this to public makes it happy).
  // Similarly, DEC CXX 5.6 needs the methods to be public.
public:
# else  /* ! (ACE_PSOS && __DIAB)  ||  ! __DECCXX_VER < 60000000 */
protected:
# endif /* ! (ACE_PSOS && __DIAB)  ||  ! __DECCXX_VER < 60000000 */
  /// Default constructor.
  ACE_Object_Manager_Base (void);

  /// Destructor.
  virtual ~ACE_Object_Manager_Base (void);

public:
  /**
   * Explicitly initialize.  Returns 0 on success, -1 on failure due
   * to dynamic allocation failure (in which case errno is set to
   * ENOMEM), or 1 if it had already been called.
   */
  virtual int init (void) = 0;

  /**
   * Explicitly destroy.  Returns 0 on success, -1 on failure because
   * the number of fini () calls hasn't reached the number of init ()
   * calls, or 1 if it had already been called.
   */
  virtual int fini (void) = 0;

  enum Object_Manager_State
    {
      OBJ_MAN_UNINITIALIZED = 0,
      OBJ_MAN_INITIALIZING,
      OBJ_MAN_INITIALIZED,
      OBJ_MAN_SHUTTING_DOWN,
      OBJ_MAN_SHUT_DOWN
    };

protected:
  /**
   * Returns 1 before ACE_Object_Manager_Base has been constructed.
   * This flag can be used to determine if the program is constructing
   * static objects.  If no static object spawns any threads, the
   * program will be single-threaded when this flag returns 1.  (Note
   * that the program still might construct some static objects when
   * this flag returns 0, if ACE_HAS_NONSTATIC_OBJECT_MANAGER is not
   * defined.)
   */
  int starting_up_i (void);

  /**
   * Returns 1 after ACE_Object_Manager_Base has been destroyed.  This
   * flag can be used to determine if the program is in the midst of
   * destroying static objects.  (Note that the program might destroy
   * some static objects before this flag can return 1, if
   * ACE_HAS_NONSTATIC_OBJECT_MANAGER is not defined.)
   */
  int shutting_down_i (void);

  /// State of the Object_Manager;
  Object_Manager_State object_manager_state_;

  /**
   * Flag indicating whether the ACE_Object_Manager was dynamically
   * allocated by ACE.  (If is was dynamically allocated by the
   * application, then the application is responsible for destroying
   * it.)
   */
  u_int dynamically_allocated_;

  /// Link to next Object_Manager, for chaining.
  ACE_Object_Manager_Base *next_;
private:
  // Disallow copying by not implementing the following . . .
  ACE_Object_Manager_Base (const ACE_Object_Manager_Base &);
  ACE_Object_Manager_Base &operator= (const ACE_Object_Manager_Base &);
};


// @@ This forward declaration should go away.
class ACE_Log_Msg;
class ACE_OS;
class ACE_Object_Manager;
class ACE_OS_Object_Manager_Manager;
class ACE_TSS_Cleanup;
class ACE_TSS_Emulation;
class ACE_Log_Msg;
class ACE_Thread_Hook;
//void ACE_OS_Object_Manager_Internal_Exit_Hook ();

extern "C"
void
ACE_OS_Object_Manager_Internal_Exit_Hook (void);



class ACE_OS_Export ACE_OS_Object_Manager : public ACE_Object_Manager_Base
{
public:
  /// Explicitly initialize.
  virtual int init (void);

  /// Explicitly destroy.
  virtual int fini (void);

  /**
   * Returns 1 before the <ACE_OS_Object_Manager> has been
   * constructed.  See <ACE_Object_Manager::starting_up> for more
   * information.
   */
  static int starting_up (void);

  /// Returns 1 after the <ACE_OS_Object_Manager> has been destroyed.
  /// See <ACE_Object_Manager::shutting_down> for more information.
  static int shutting_down (void);

  /// Unique identifiers for preallocated objects.
  enum Preallocated_Object
    {
# if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
      ACE_OS_MONITOR_LOCK,
      ACE_TSS_CLEANUP_LOCK,
      ACE_LOG_MSG_INSTANCE_LOCK,
#   if defined (ACE_HAS_TSS_EMULATION)
      ACE_TSS_KEY_LOCK,
#     if defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)
      ACE_TSS_BASE_LOCK,
#     endif /* ACE_HAS_THREAD_SPECIFIC_STORAGE */
#   endif /* ACE_HAS_TSS_EMULATION */
# else
      // Without ACE_MT_SAFE, There are no preallocated objects.  Make
      // sure that the preallocated_array size is at least one by
      // declaring this dummy . . .
      ACE_OS_EMPTY_PREALLOCATED_OBJECT,
# endif /* ACE_MT_SAFE */

      /// This enum value must be last!
      ACE_OS_PREALLOCATED_OBJECTS
    };

  /// Accesses a default signal set used, for example, in
  /// <ACE_Sig_Guard> methods.
  static sigset_t *default_mask (void);

  /// Returns the current thread hook for the process.
  static ACE_Thread_Hook *thread_hook (void);

  /// Returns the existing thread hook and assign a <new_thread_hook>.
  static ACE_Thread_Hook *thread_hook (ACE_Thread_Hook *new_thread_hook);

# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  /// Get/Set TSS exception action.
  static ACE_SEH_EXCEPT_HANDLER seh_except_selector (void);
  static ACE_SEH_EXCEPT_HANDLER seh_except_selector (ACE_SEH_EXCEPT_HANDLER);

  static ACE_SEH_EXCEPT_HANDLER seh_except_handler (void);
  static ACE_SEH_EXCEPT_HANDLER seh_except_handler (ACE_SEH_EXCEPT_HANDLER);
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

public:
  // = Applications shouldn't use these so they're hidden here.

  // They're public so that the <ACE_Object_Manager> can be
  // constructed/destructed in <main> with
  // <ACE_HAS_NONSTATIC_OBJECT_MANAGER>.
  /// Constructor.
  ACE_OS_Object_Manager (void);

  /// Destructor.
  ~ACE_OS_Object_Manager (void);

private:
  /// Accessor to singleton instance.
  static ACE_OS_Object_Manager *instance (void);

  /// Singleton instance pointer.
  static ACE_OS_Object_Manager *instance_;

  /// Table of preallocated objects.
  static void *preallocated_object[ACE_OS_PREALLOCATED_OBJECTS];

  /// Default signal set used, for example, in ACE_Sig_Guard.
  sigset_t *default_mask_;

  /// Thread hook that's used by this process.
  ACE_Thread_Hook *thread_hook_;

  /// For at_exit support.
  ACE_OS_Exit_Info exit_info_;

# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
  /// These handlers determine how a thread handles win32 structured
  /// exception.
  ACE_SEH_EXCEPT_HANDLER seh_except_selector_;
  ACE_SEH_EXCEPT_HANDLER seh_except_handler_;
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */

  /// For <ACE_OS::atexit> support.
  int at_exit (ACE_EXIT_HOOK func);

  /// For use by init () and fini (), to consolidate error reporting.
  static void print_error_message (u_int line_number, const ACE_TCHAR *message);

  /// This class is for internal use by ACE_OS, etc., only.
  friend class ACE_OS;
  friend class ACE_Object_Manager;
  friend class ACE_OS_Object_Manager_Manager;
  friend class ACE_TSS_Cleanup;
  friend class ACE_TSS_Emulation;
  friend class ACE_Log_Msg;
  friend void ACE_OS_Object_Manager_Internal_Exit_Hook ();
};
////////////////////////////////////////////////////////////////////////////////



#include "ace/post.h"
#endif /* ACE_OBJECT_MANAGER_BASE_H */
