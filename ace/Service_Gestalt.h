// -*- C++ -*-

//====================================================================
/**
 *  @file    Service_Gestalt.h
 *
 *  $Id$
 *
 *  @author Iliyan Jeliazkov <iliyan@ociweb.com>
 */
//====================================================================

#ifndef ACE_SERVICE_GESTALT_H
#define ACE_SERVICE_GESTALT_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"
#include "ace/Default_Constants.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Auto_Ptr.h"
#include "ace/SString.h"
#include "ace/Unbounded_Queue.h"
#include "ace/Service_Repository.h"
#include "ace/Singleton.h"
#include "ace/OS_NS_signal.h"
#include "ace/Synch_Traits.h"
#include "ace/DLL.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if (ACE_USES_CLASSIC_SVC_CONF == 1)
class ACE_Service_Type_Factory;
class ACE_Location_Node;
#else
class ACE_XML_Svc_Conf;
class ACE_DLL;
#endif /* ACE_USES_CLASSIC_SVC_CONF == 1 */

class ACE_Static_Svc_Descriptor;
class ACE_Svc_Conf_Param;
class ACE_Service_Gestalt;

/**
 * @class ACE_Service_Gestalt
 *
 * @brief Supplies common server operations for dynamic and static
 * configuration of services.
 *
 * The Gestalt embodies the concept of configuration context. On one
 * hand, it is a flat namespace, where names correspond to a Service
 * Object instance. A Gestalt owns the Service Repository instance,
 * which in turn owns the Service Object instances.
 *
 * Another aspect of a Gestalt is its responsibility for
 * record-keeping and accounting for the meta-data, necessary for
 * locating, removing or instantiating a service.
 *
 * A repository underlies an instance of a gestalt and its lifetime
 * may or may not be bounded by the lifetime of the gestalt, that owns
 * it. This feature is important for the derived classes and the
 * Service Config in particular.

 */
class ACE_Export ACE_Service_Gestalt
{
private:
  /**
   * Not implemented to enforce no copying
   */
  ACE_Service_Gestalt(const ACE_Service_Gestalt&);
  ACE_Service_Gestalt& operator=(const ACE_Service_Gestalt&);

public:
  enum
  {
    MAX_SERVICES = ACE_DEFAULT_SERVICE_REPOSITORY_SIZE
  };

  /// Constructor either associates the instance with the process-wide
  /// singleton instance of ACE_Service_Repository, or creates and
  /// manages its own instance of the specified size.
  ACE_Service_Gestalt (size_t size,
                       bool svc_repo_is_owned = true,
                       bool no_static_svcs = true);

  /// Perform user-specified close activities and remove dynamic
  /// memory.
  virtual ~ACE_Service_Gestalt (void);

  /// Dump the state of an object.
  void dump (void) const;

   /**
   * Performs an open without parsing command-line arguments.  The
   * @a logger_key indicates where to write the logging output, which
   * is typically either a STREAM pipe or a socket address.  If
   * @a ignore_static_svcs is 1 then static services are not loaded,
   * otherwise, they are loaded.  If @a ignore_default_svc_conf_file is
   * non-0 then the <svc.conf> configuration file will be ignored.
   * Returns zero upon success, -1 if the file is not found or cannot
   * be opened (errno is set accordingly), otherwise returns the
   * number of errors encountered loading the services in the
   * specified svc.conf configuration file.  If @a ignore_debug_flag is
   * non-0 then the application is responsible for setting the
   * <ACE_Log_Msg::priority_mask> appropriately.
   */
  int open (const ACE_TCHAR program_name[],
            const ACE_TCHAR *logger_key = ACE_DEFAULT_LOGGER_KEY,
            int ignore_static_svcs = 1,
            int ignore_default_svc_conf_file = 0,
            int ignore_debug_flag = 0);

  /**
   * This is the primary entry point into the ACE_Service_Config (the
   * constructor just handles simple initializations).  It parses
   * arguments passed in from @a argc and @a argv parameters.  The
   * arguments that are valid in a call to this method include:
   *
   * - '-b' Option to indicate that we should be a daemon. Note that when
   *        this option is used, the process will be daemonized before the
   *        service configuration file(s) are read. During daemonization,
   *        (on POSIX systems) the current directory will be changed to "/"
   *        so the caller should either fully specify the file names, or
   *        execute a @c chroot() to the appropriate directory.
   *        @sa ACE::daemonize().
   * - '-d' Turn on debugging mode
   * - '-f' Specifies a configuration file name other than the default
   *        svc.conf. Can be specified multiple times to use multiple files.
   * - '-k' Specifies the rendezvous point to use for the ACE distributed
   *        logger.
   * - '-y' Explicitly enables the use of static services. This flag
   *        overrides the @a ignore_static_svcs parameter value.
   * - '-n' Explicitly disables the use of static services. This flag
   *        overrides the @a ignore_static_svcs parameter value.
   * - '-p' Specifies a pathname which is used to store the process id.
   * - '-s' Specifies a signal number other than SIGHUP to trigger reprocessing
   *        of the configuration file(s). Ignored for platforms that do not
   *        have POSIX signals, such as Windows.
   * - '-S' Specifies a service directive string. Enclose the string in quotes
   *        and escape any embedded quotes with a backslash. This option
   *        specifies service directives without the need for a configuration
   *        file.
   *
   * @param argc The number of commandline arguments.
   * @param argv The array with commandline arguments
   * @param logger_key   Indicates where to write the logging output,
   *                     which is typically either a STREAM pipe or a
   *                     socket address.
   * @param ignore_static_svcs   If 1 then static services are not loaded,
   *                             otherwise, they are loaded.
   * @param ignore_default_svc_conf_file  If non-0 then the @c svc.conf
   *                                      configuration file will be ignored.
   * @param ignore_debug_flag If non-0 then the application is responsible
   *                          for setting the @c ACE_Log_Msg::priority_mask
   *                          appropriately.
   *
   * @retval -1   The configuration file is not found or cannot
   *              be opened (errno is set accordingly).
   * @retval  0   Success.
   * @retval  >0  The number of errors encountered while processing
   *              the service configuration file(s).
   */
  int open (int argc,
            ACE_TCHAR *argv[],
            const ACE_TCHAR *logger_key = ACE_DEFAULT_LOGGER_KEY,
            int ignore_static_svcs = 1,
            int ignore_default_svc_conf_file = 0,
            int ignore_debug_flag = 0);

  /// Has it been opened?  Returns the difference between the times
  /// open and close have been called on this instance
  int is_opened (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /// Process one service configuration @a directive, which is passed as
  /// a string.  Returns the number of errors that occurred.
  int process_directive (const ACE_TCHAR directive[]);

  /// Process one static service definition.
  /**
   * Load a new static service.
   *
   * @param ssd Service descriptor, see the document of
   *        ACE_Static_Svc_Descriptor for more details.
   *
   * @param force_replace If set the new service descriptor replaces
   *        any previous instance in the repository.
   *
   * @return Returns -1 if the service cannot be 'loaded'.
   */
  int process_directive (const ACE_Static_Svc_Descriptor &ssd,
                         int force_replace = 0);

  /// Process a file containing a list of service configuration
  /// directives.
  int process_file (const ACE_TCHAR file[]);

  /**
   * Locate an entry with <name> in the table.  If <ignore_suspended>
   * is set then only consider services marked as resumed.  If the
   * caller wants the located entry, pass back a pointer to the
   * located entry via <srp>.  If <name> is not found, -1 is returned.
   * If <name> is found, but it is suspended and the caller wants to
   * ignore suspended services a -2 is returned.
   */
  int find (const ACE_TCHAR name[],
            const ACE_Service_Type **srp = 0,
            int ignore_suspended = 1) const;

  /**
   * Handle the command-line options intended for the
   * <ACE_Service_Gestalt>.  Note that <argv[0]> is assumed to be the
   * program name.
   *
   * The arguments that are valid in a call to this method are
   * - '-d' Turn on debugging mode
   * - '-f' Option to read in the list of svc.conf file names
   * - '-k' Option to read a wide string where in the logger output can
   *        be written
   * - '-y' Turn on the flag for a  repository of statically
   *        linked services
   * - '-n' Need not have a repository of statically linked services
   * - '-S' Option to read in the list of services on the command-line
   *        Please observe the difference between options '-f' that looks
   *        for a list of files and here a list of services.
   */
   int parse_args (int, ACE_TCHAR *argv[]);

  /**
   * Process (or re-process) service configuration requests that are
   * provided in the svc.conf file(s).  Returns the number of errors
   * that occurred.
   */
  int process_directives (void);

  /// Tidy up and perform last rites when ACE_Service_Config is shut
  /// down.  This method calls <close_svcs>.  Returns 0.
  int close (void);


  // Registers a service descriptor for a static service object
  int insert (ACE_Static_Svc_Descriptor *stsd);

  // = Utility methods.

#if (ACE_USES_CLASSIC_SVC_CONF == 1)
  /// Dynamically link the shared object file and retrieve a pointer to
  /// the designated shared object in this file. Also account for the
  /// possiblity to have static services registered when loading the DLL, by
  /// ensuring that the dynamic sevice is registered before any of its
  /// subordibnate static services. Thus avoiding any finalization order
  /// problems.
  int initialize (const ACE_Service_Type_Factory *,
                  const ACE_TCHAR *parameters);
#endif /* (ACE_USES_CLASSIC_SVC_CONF == 1) */

  // Dynamically link the shared object file and retrieve a pointer to
  // the designated shared object in this file.
  // @obsolete
  // @note This is error-prone in the presense of dynamic services,
  // which in turn initialize their own static services. This method
  // will allow those static services to register *before* the dynamic
  // service that owns them.  Upon finalization of the static services
  // the process will typically crash, because the dynamic service's
  // DLL may have been already released, together with the memory in
  // which the static services reside.  It may not crash, for
  // instance, when the first static service to register is the same
  // as the dynamic service being loaded. You should be so lucky!
  int initialize (const ACE_Service_Type *,
                  const ACE_TCHAR *parameters);

  /// Initialize and activate a statically @a svc_name service.
  int initialize (const ACE_TCHAR *svc_name,
                  const ACE_TCHAR *parameters);

  /// Resume a @a svc_name that was previously suspended or has not yet
  /// been resumed (e.g., a static service).
  int resume (const ACE_TCHAR svc_name[]);

  /**
   * Suspend @a svc_name.  Note that this will not unlink the service
   * from the daemon if it was dynamically linked, it will mark it as
   * being suspended in the Service Repository and call the <suspend>
   * member function on the appropriate <ACE_Service_Object>.  A
   * service can be resumed later on by calling the <RESUME> member
   * function...
   */
  int suspend (const ACE_TCHAR svc_name[]);

  /// Totally remove @a svc_name from the daemon by removing it
  /// from the ACE_Reactor, and unlinking it if necessary.
  int remove (const ACE_TCHAR svc_name[]);

  /**
   * Using the supplied name, finds and (if needed) returns a pointer to a
   * static service descriptor. Returns 0 for success and -1 for failure
   */
  int find_static_svc_descriptor (const ACE_TCHAR* name,
                                  ACE_Static_Svc_Descriptor **ssd = 0) const;

  struct Processed_Static_Svc
  {
    Processed_Static_Svc (const ACE_Static_Svc_Descriptor *);
    ~Processed_Static_Svc (void);
    ACE_TCHAR * name_;
    const ACE_Static_Svc_Descriptor *assd_;
  };

protected:

  /**
   *
   */
  virtual int parse_args_i (int, ACE_TCHAR *argv[]);

  /**
   * Performs an open without parsing command-line arguments.  The
   * @a logger_key indicates where to write the logging output, which
   * is typically either a STREAM pipe or a socket address.  If
   * @a ignore_default_svc_conf_file is non-0 then the "svc.conf" file
   * will be ignored.  If @a ignore_debug_flag is non-0 then the
   * application is responsible for setting the
   * @c ACE_Log_Msg::priority_mask() appropriately.  Returns number of
   * errors that occurred on failure and 0 otherwise.
   */
  virtual int open_i (const ACE_TCHAR program_name[],
                      const ACE_TCHAR *logger_key = ACE_DEFAULT_LOGGER_KEY,
                      bool ignore_static_svcs = true,
                      bool ignore_default_svc_conf_file = false,
                      bool ignore_debug_flag = false);

  /// Initialize the <svc_conf_file_queue_> if necessary.
  int init_svc_conf_file_queue (void);

  /// Add the default statically-linked services to the
  /// ACE_Service_Repository.
  int load_static_svcs (void);

  /// Process service configuration requests that were provided on the
  /// command-line.  Returns the number of errors that occurred.
  int process_commandline_directives (void);

  /// Process a static directive without also inserting its descriptor
  /// the global table. This avoids multiple additions when processing
  /// directives in non-global gestalts.
  int process_directive_i (const ACE_Static_Svc_Descriptor &ssd,
                           int force_replace = 0);

#if (ACE_USES_CLASSIC_SVC_CONF == 1)
  /// This is the implementation function that process_directives()
  /// and process_directive() both call.  Returns the number of errors
  /// that occurred.
  int process_directives_i (ACE_Svc_Conf_Param *param);
#else
  /// Helper function to dynamically link in the XML Service Configurator
  /// parser.
  ACE_XML_Svc_Conf* get_xml_svc_conf (ACE_DLL &d);
#endif /* ACE_USES_CLASSIC_SVC_CONF == 1 */

  // Dynamically link the shared object file and retrieve a pointer to
  // the designated shared object in this file.
  int initialize_i (const ACE_Service_Type *sr, const ACE_TCHAR *parameters);

const ACE_Static_Svc_Descriptor*
   find_processed_static_svc (const ACE_TCHAR* );

void add_processed_static_svc (const ACE_Static_Svc_Descriptor *);

protected:

  // Maintain a queue of services to be configured from the
  // command-line.
  typedef ACE_Unbounded_Queue<ACE_TString> ACE_SVC_QUEUE;
  typedef ACE_Unbounded_Queue_Iterator<ACE_TString> ACE_SVC_QUEUE_ITERATOR;

  // Maintain a set of the statically linked service descriptors.
  typedef ACE_Unbounded_Set<ACE_Static_Svc_Descriptor *>
    ACE_STATIC_SVCS;

  typedef ACE_Unbounded_Set_Iterator<ACE_Static_Svc_Descriptor *>
    ACE_STATIC_SVCS_ITERATOR;

  typedef ACE_Unbounded_Set<Processed_Static_Svc *>
    ACE_PROCESSED_STATIC_SVCS;

  typedef ACE_Unbounded_Set_Iterator<Processed_Static_Svc *>
    ACE_PROCESSED_STATIC_SVCS_ITERATOR;

  friend class ACE_Dynamic_Service_Base;
  friend class ACE_Service_Object;
  friend class ACE_Service_Config_Guard;

protected:

  /// Do we own the service repository instance or have only been given a ptr
  /// to the singleton one?
  bool svc_repo_is_owned_;

  /// Keep track of the number of times the instance has been
  /// initialized (opened). "If so, we can't allow <yyparse> to be called since
  /// it's not reentrant" is the original motivation, but that does not seem
  /// to be the case anymore. This variable is incremented by the
  /// <ACE_Service_Gestalt::open> method and decremented by the
  /// <ACE_Service_Gestalt::close> method.
  int is_opened_;

  /// Indicates where to write the logging output.  This is typically
  /// either a STREAM pipe or a socket
  const ACE_TCHAR *logger_key_;

  /// Should we avoid loading the static services?
  int no_static_svcs_;

  /// Queue of services specified on the command-line.
  ACE_SVC_QUEUE* svc_queue_;

  /** Queue of svc.conf files specified on the command-line.
   * @@ This should probably be made to handle unicode filenames...
   */
  ACE_SVC_QUEUE* svc_conf_file_queue_;

  /// The service repository to hold the services.
  ACE_Service_Repository* repo_;

  /// Repository of statically linked services.
  ACE_STATIC_SVCS* static_svcs_;

  /// Repository of statically linked services for which process
  /// directive was called, but the service is not already a member of
  /// the static_svcs_ list.
  ACE_PROCESSED_STATIC_SVCS* processed_static_svcs_;

private:

  friend class ACE_Service_Type_DLL_Guard;

}; /* class ACE_Service_Gestalt */

/**
 * As dynamic service objects are loaded, static service objects that
 * come with the same DLL code, may also be registered. The static
 * services however, have no information about the context in which
 * their registration takes place and their relation with the DLL is
 * lost. A situation can easily arise where the dynamic service object
 * is finalized and its DLL - unmapped, but some of the DLL's static
 * services may still be around. Their finalization would not be
 * possible, if the DLL counting that code is gone.
 *
 * The guard, when instantiated (on the stack) swaps out the current
 * Gestalt and its service repository, and replaces them with a
 * "sandbox" Gestalt, which has lifetime sufficient for just the
 * current service initialization. Note that this mechanism is
 * effective even in the case where a service initialization causes
 * re-entry into the Gestalt to load and initialize another service as
 * part of the initialization.
 *
 * If no action is taken (in case of an error, for instance) the guard
 * destructor will simply finalize all newly initialized service(s)
 * from the sandbox. On the other hand, if initialization is
 * successful the service object descriptors are "relocated" to the
 * original Gestalt.  **During the relocation, all static services are
 * "fixed-up" to hold a reference to the DLL they belong
 * to. Effectively, a static service, initialized via loading of a
 * particular DLL, becomes a dynamic service. Thus the order of
 * service finalization does not matter anymore because the DLL will
 * be help in memory until the last service object it provides is
 * finalized.
 */
class ACE_Service_Type_DLL_Guard
{
public:
  ACE_Service_Type_DLL_Guard (ACE_Service_Gestalt* gestalt);
  ~ACE_Service_Type_DLL_Guard (void);
  int relocate (const ACE_DLL& adll);

protected:
  // Unimplemented copy ctor and assigment to prohibit instance
  // copying.
  ACE_Service_Type_DLL_Guard (const ACE_Service_Type_DLL_Guard&);
  ACE_Service_Type_DLL_Guard& operator= (const ACE_Service_Type_DLL_Guard&);

private:
  ACE_Service_Gestalt* gestalt_;
  ACE_Service_Repository* repo_;
  ACE_Service_Gestalt::ACE_PROCESSED_STATIC_SVCS* processed_static_svcs_;
};


ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Service_Gestalt.inl"
#endif /* __ACE_INLINE__ */


#include /**/ "ace/post.h"

#endif /* ACE_SERVICE_GESTALT_H */
