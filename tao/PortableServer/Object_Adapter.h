// -*- C++ -*-

//=============================================================================
/**
 *  @file    Object_Adapter.h
 *
 *  $Id$
 *
 *  @author Irfan Pyarali
 */
//=============================================================================

#ifndef TAO_OBJECT_ADAPTER_H
#define TAO_OBJECT_ADAPTER_H

#include "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Key_Adapters.h"
#include "poa_macros.h"

// Active Object Table
#include "Active_Object_Map.h"

#include "tao/Adapter.h"
#include "tao/Server_Strategy_Factory.h"

// Local Object
#include "tao/LocalObject.h"

#include "ace/Service_Config.h"

// Policy Validators
#include "Default_Policy_Validator.h"

// Policy Set
#include "POA_Policy_Set.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

// ****************************************************************

enum TAO_SERVANT_LOCATION
{
  TAO_SERVANT_FOUND,
  TAO_DEFAULT_SERVANT,
  TAO_SERVANT_MANAGER,
  TAO_SERVANT_NOT_FOUND
};

// ****************************************************************

// Forward declaration
class TAO_POA;
class TAO_POA_Manager;
class TAO_Temporary_Creation_Time;
class TAO_POA_Current_Impl;
class TAO_TSS_Resources;
class TAO_Transport;
class TAO_Servant_Dispatcher;

class TAO_PortableServer_Export TAO_POA_Current
  : public PortableServer::Current,
    public TAO_Local_RefCounted_Object
{
public:
  /// Constructor
  TAO_POA_Current (void);

  /**
   * Returns the POA on which the current request is being invoked.
   * Can raise the <CORBA::NoContext> exception if this function is
   * not invoked in the context of an upcall.
   */
  PortableServer::POA_ptr get_POA (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableServer::Current::NoContext));

  /**
   * Returns the object id of the current request being invoked.  Can
   * raise the <CORBA::NoContext> exception if this function is not
   * invoked in the context of an upcall.
   */
  PortableServer::ObjectId *get_object_id (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableServer::Current::NoContext));

  /// Returns the class that implements this interface.
  TAO_POA_Current_Impl *implementation (void);

  /// Sets the thread-specific pointer to the new POA Current state,
  /// returning a pointer to the existing POA Current state.
  TAO_POA_Current_Impl *implementation (TAO_POA_Current_Impl *new_current);
};

/**
 * @class TAO_POA_Current_Impl
 *
 * @brief Implementation of the PortableServer::Current object.
 *
 * Objects of this class hold state information regarding the
 * current POA invocation.  Savvy readers will notice that this
 * contains substantially more methods than the POA spec shows;
 * they exist because the ORB either (a) needs them or (b) finds
 * them useful for implementing a more efficient ORB.
 * The intent is that instances of this class are held in
 * Thread-Specific Storage so that upcalls can get context
 * information regarding their invocation.  The POA itself must
 * insure that all <set_*> operations are performed in the
 * execution thread so that the proper <TAO_POA_Current> pointer
 * is obtained from TSS.
 */
class TAO_PortableServer_Export TAO_POA_Current_Impl
{
public:

  friend class TAO_POA;

  /// Return pointer to the invoking POA.  Raises the
  /// <CORBA::NoContext> exception.
  PortableServer::POA_ptr get_POA (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableServer::Current::NoContext));

  /**
   * Return pointer to the object id through which this was invoked.
   * This may be necessary in cases where a <Servant> is serving under
   * the guise of multiple object ids.  This has _out semantics Raises
   * the <CORBA::NoContext> exception.
   */
  PortableServer::ObjectId *get_object_id (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     PortableServer::Current::NoContext));

  /// Set the POA implementation.
  void poa (TAO_POA *);

  /// Get the POA implemantation
  TAO_POA *poa (void) const;

  /// ORB Core for this current.
  TAO_ORB_Core &orb_core (void) const;

  /// Set the object ID.
  void object_id (const PortableServer::ObjectId &id);

  /// Get the object ID.
  const PortableServer::ObjectId &object_id (void) const;

  /// Set the object key.
  void object_key (const TAO::ObjectKey &key);

  /// Get the object key.
  const TAO::ObjectKey &object_key (void) const;

  /// Set the servant for the current upcall.
  void servant (PortableServer::Servant servant);

  /// Get the servant for the current upcall.
  PortableServer::Servant servant (void) const;

  /// Set the priority for the current upcall.
  void priority (CORBA::Short priority);

  /// Get the priority for the current upcall.
  CORBA::Short priority (void) const;

  /// Convenience constructor combining construction & initialization.
  TAO_POA_Current_Impl (void);

  /// Teardown the current for this request.
  void teardown (void);

  /// Setup the current.
  void setup (TAO_POA *impl,
              const TAO::ObjectKey &key);

protected:
  /// The POA implementation invoking an upcall
  TAO_POA *poa_;

  /**
   * The object ID of the current context.  This is the user id and
   * not the id the goes into the IOR.  Note also that unlike the
   * <object_key>, this field is stored by value.
   */
  PortableServer::ObjectId object_id_;

  /// The object key of the current context.
  const TAO::ObjectKey *object_key_;

  /// The servant for the current upcall.
  PortableServer::Servant servant_;

  /// The priority for the current upcall.
  CORBA::Short priority_;

  /// void *previous_current_impl_;
  /// Current previous from <this>.
  TAO_POA_Current_Impl *previous_current_impl_;

  /// Is setup complete?
  int setup_done_;

  /// Pointer to tss resources.
  TAO_TSS_Resources *tss_resources_;

  // = Hidden because we don't allow these
  TAO_POA_Current_Impl (const TAO_POA_Current_Impl &);
  void operator= (const TAO_POA_Current_Impl &);
};

/**
 * @class TAO_Object_Adapter
 *
 * @brief Defines the Object Adapter abstraction.
 *
 * This class will be used as a facade for the POAs in a server
 */
class TAO_PortableServer_Export TAO_Object_Adapter : public TAO_Adapter
{
public:

  friend class TAO_POA;

  typedef PortableServer::ObjectId poa_name;
  typedef PortableServer::ObjectId_var poa_name_var;
  typedef PortableServer::ObjectId_out poa_name_out;

  /// Constructor.
  TAO_Object_Adapter (const TAO_Server_Strategy_Factory::Active_Object_Map_Creation_Parameters &creation_parameters,
                      TAO_ORB_Core &orb_core);

  /// Destructor.
  ~TAO_Object_Adapter (void);

  int dispatch_servant (const TAO::ObjectKey &key,
                        TAO_ServerRequest &req,
                        CORBA::Object_out forward_to
                        ACE_ENV_ARG_DECL);

  int locate_servant (const TAO::ObjectKey &key
                      ACE_ENV_ARG_DECL);

  TAO_SERVANT_LOCATION find_servant (const TAO::ObjectKey &key,
                                     PortableServer::Servant &servant
                                     ACE_ENV_ARG_DECL);

  int find_poa (const poa_name &system_name,
                CORBA::Boolean activate_it,
                CORBA::Boolean root,
                const TAO_Temporary_Creation_Time &poa_creation_time,
                TAO_POA *&poa
                ACE_ENV_ARG_DECL);

  int bind_poa (const poa_name &folded_name,
                TAO_POA *poa,
                poa_name_out system_name);

  int unbind_poa (TAO_POA *poa,
                  const poa_name &folded_name,
                  const poa_name &system_name);

  int activate_poa (const poa_name &folded_name,
                    TAO_POA *&poa
                    ACE_ENV_ARG_DECL);

  ACE_Lock &lock (void);

  TAO_SYNCH_MUTEX &thread_lock (void);

  ACE_Reverse_Lock<ACE_Lock> &reverse_lock (void);

  /// Access the root poa.
  TAO_POA *root_poa (void) const;

  /// Access to ORB Core.
  TAO_ORB_Core &orb_core (void) const;

  /// Wait for non-servant upcalls to complete.
  void wait_for_non_servant_upcalls_to_complete (CORBA::Environment &ACE_TRY_ENV);

  /// Non-exception throwing version.
  void wait_for_non_servant_upcalls_to_complete (void);

  static CORBA::ULong transient_poa_name_size (void);

  /// Return the validator.
  TAO_Policy_Validator &validator (void);

  /// Return the set of default policies.
  TAO_POA_Policy_Set &default_poa_policies (void);

  /// Set the servant dispatcher method.  Ownership is transferred to
  /// this Object Adapter.  Note: This should only be called
  /// at initialization.
  void servant_dispatcher (TAO_Servant_Dispatcher *dispatcher);

  /// Initialize the default set of POA policies.
  void init_default_policies (TAO_POA_Policy_Set &policies
                              ACE_ENV_ARG_DECL);

  // = The TAO_Adapter methods, please check tao/Adapter.h for the
  // documentation
  virtual void open (ACE_ENV_SINGLE_ARG_DECL);
  virtual void close (int wait_for_completion
                      ACE_ENV_ARG_DECL);
  virtual void check_close (int wait_for_completion
                            ACE_ENV_ARG_DECL);
  virtual int priority (void) const;
  virtual int dispatch (TAO::ObjectKey &key,
                        TAO_ServerRequest &request,
                        CORBA::Object_out foward_to
                        ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  virtual const char *name (void) const;
  virtual CORBA::Object_ptr root (void);
  virtual CORBA::Object_ptr create_collocated_object (TAO_Stub *,
                                                      const TAO_MProfile &);

  virtual CORBA::Long initialize_collocated_object (TAO_Stub *,
                                                    CORBA::Object_ptr);

protected:

  int locate_servant_i (const TAO::ObjectKey &key
                        ACE_ENV_ARG_DECL);

  TAO_SERVANT_LOCATION find_servant_i (const TAO::ObjectKey &key,
                                       PortableServer::Servant &servant
                                       ACE_ENV_ARG_DECL);

  void dispatch_servant_i (const TAO::ObjectKey &key,
                           TAO_ServerRequest &req,
                           void *context
                           ACE_ENV_ARG_DECL);

  void locate_poa (const TAO::ObjectKey &key,
                   PortableServer::ObjectId &id,
                   TAO_POA *&poa
                   ACE_ENV_ARG_DECL);

  int find_transient_poa (const poa_name &system_name,
                          CORBA::Boolean root,
                          const TAO_Temporary_Creation_Time &poa_creation_time,
                          TAO_POA *&poa
                          ACE_ENV_ARG_DECL);

  int find_persistent_poa (const poa_name &system_name,
                           TAO_POA *&poa
                           ACE_ENV_ARG_DECL);

  int bind_transient_poa (TAO_POA *poa,
                          poa_name_out system_name);

  int bind_persistent_poa (const poa_name &folded_name,
                           TAO_POA *poa,
                           poa_name_out system_name);

  int unbind_transient_poa (const poa_name &system_name);

  int unbind_persistent_poa (const poa_name &folded_name,
                             const poa_name &system_name);

  void set_default_server_protocol_policy (ACE_ENV_SINGLE_ARG_DECL);

  static ACE_Lock *create_lock (int enable_locking,
                                TAO_SYNCH_MUTEX &thread_lock);

public:

  /**
   * @class Hint_Strategy
   *
   * @brief Base class for POA active hint strategy.
   *
   * This class also provides for common structures used by all
   * the derived classes.
   */
  class TAO_PortableServer_Export Hint_Strategy
  {
  public:

    virtual ~Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa
                                     ACE_ENV_ARG_DECL) = 0;

    virtual int bind_persistent_poa (const poa_name &folded_name,
                                     TAO_POA *poa,
                                     poa_name_out system_name) = 0;

    virtual int unbind_persistent_poa (const poa_name &folded_name,
                                       const poa_name &system_name) = 0;

    void object_adapter (TAO_Object_Adapter *oa);

  protected:

    TAO_Object_Adapter *object_adapter_;
  };

  /**
   * @class Active_Hint_Strategy
   *
   * @brief This class uses active demux hint for POA active hint
   * strategy.
   *
   * This class will append an active hint to the POA name,
   * making the POA lookups fast and predictable.
   */
  class TAO_PortableServer_Export Active_Hint_Strategy : public Hint_Strategy
  {
  public:

    Active_Hint_Strategy (CORBA::ULong map_size);

    virtual ~Active_Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa
                                     ACE_ENV_ARG_DECL);

    virtual int bind_persistent_poa (const poa_name &folded_name,
                                     TAO_POA *poa,
                                     poa_name_out system_name);

    virtual int unbind_persistent_poa (const poa_name &folded_name,
                                       const poa_name &system_name);

  protected:

    typedef ACE_Active_Map_Manager_Adapter<
    poa_name,
      TAO_POA *,
      TAO_Preserve_Original_Key_Adapter> persistent_poa_system_map;

    persistent_poa_system_map persistent_poa_system_map_;
  };

  /**
   * @class No_Hint_Strategy
   *
   * @brief This class doesn't use any hints for POA active hint
   * strategy.
   *
   * This class will simply use the POA names as is. And since
   * no hint is added, the IORs will be smaller.
   */
  class TAO_PortableServer_Export No_Hint_Strategy : public Hint_Strategy
  {
  public:

    virtual ~No_Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa
                                     ACE_ENV_ARG_DECL);

    virtual int bind_persistent_poa (const poa_name &folded_name,
                                     TAO_POA *poa,
                                     poa_name_out system_name);

    virtual int unbind_persistent_poa (const poa_name &folded_name,
                                       const poa_name &system_name);

  };

protected:

  Hint_Strategy *hint_strategy_;

  /// Base class of the id map.
  typedef ACE_Map<
  poa_name,
    TAO_POA *> transient_poa_map;

#if (TAO_HAS_MINIMUM_POA_MAPS == 0)
  /// Id hash map.
  typedef ACE_Hash_Map_Manager_Ex_Adapter<
  poa_name,
    TAO_POA *,
    TAO_ObjectId_Hash,
    ACE_Equal_To<poa_name>,
    TAO_Incremental_Key_Generator> transient_poa_hash_map;
#endif /* TAO_HAS_MINIMUM_POA_MAPS == 0 */

#if (TAO_HAS_MINIMUM_POA_MAPS == 0)
  /// Id linear map.
  typedef ACE_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    TAO_Incremental_Key_Generator> transient_poa_linear_map;
#endif /* TAO_HAS_MINIMUM_POA_MAPS == 0 */

  /// Id active map.
  typedef ACE_Active_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    TAO_Ignore_Original_Key_Adapter> transient_poa_active_map;

  /// Base class of the name map.
  typedef ACE_Map<
  poa_name,
    TAO_POA *> persistent_poa_name_map;

  /// Id hash map.
  typedef ACE_Hash_Map_Manager_Ex_Adapter<
  poa_name,
    TAO_POA *,
    TAO_ObjectId_Hash,
    ACE_Equal_To<PortableServer::ObjectId>,
    ACE_Noop_Key_Generator<poa_name> > persistent_poa_name_hash_map;

#if (TAO_HAS_MINIMUM_POA_MAPS == 0)
  /// Id linear map.
  typedef ACE_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    ACE_Noop_Key_Generator<poa_name> > persistent_poa_name_linear_map;
#endif /* TAO_HAS_MINIMUM_POA_MAPS == 0 */

  /// Strategy for dispatching a request to a servant.
  TAO_Servant_Dispatcher *servant_dispatcher_;

public:

  persistent_poa_name_map *persistent_poa_name_map_;
  transient_poa_map *transient_poa_map_;

protected:

  static size_t transient_poa_name_size_;

  static void set_transient_poa_name_size (const TAO_Server_Strategy_Factory::Active_Object_Map_Creation_Parameters &creation_parameters);

  TAO_ORB_Core &orb_core_;

  int enable_locking_;

  TAO_SYNCH_MUTEX thread_lock_;

  ACE_Lock *lock_;

  ACE_Reverse_Lock<ACE_Lock> reverse_lock_;

public:

  /**
   * @class poa_name_iterator
   *
   * @brief Iterator for a folded poa name.
   */
  class TAO_PortableServer_Export poa_name_iterator
  {
  public:

    /// Constructor.
    poa_name_iterator (int begin,
                       CORBA::ULong size,
                       const CORBA::Octet *folded_buffer);

    /// Comparison operators.
    int operator== (const poa_name_iterator &rhs) const;
    int operator!= (const poa_name_iterator &rhs) const;

    /// Dereference operator.
    ACE_CString operator* () const;

    /// Prefix advance.
    poa_name_iterator &operator++ (void);

  protected:

    CORBA::ULong size_;
    CORBA::ULong position_;
    const CORBA::Octet *folded_buffer_;
    CORBA::ULong last_separator_;
  };

  /**
   * @class iteratable_poa_name
   *
   * @brief This class allows iteration over a folded poa name.
   */
  class TAO_PortableServer_Export iteratable_poa_name
  {
  public:

    typedef poa_name_iterator iterator;

    iteratable_poa_name (const poa_name &folded_name);

    iterator begin (void) const;
    iterator end (void) const;

  protected:

    const poa_name &folded_name_;
  };

  /**
   * @class Non_Servant_Upcall
   *
   * @brief This class helps us with a recursive thread lock without
   * using a recursive thread lock.  Non_Servant_Upcall has a
   * magic constructor and destructor.  We unlock the
   * Object_Adapter lock for the duration of the non-servant
   * (i.e., adapter activator and servant activator) upcalls;
   * reacquiring once the upcalls complete.  Even though we are
   * releasing the lock, other threads will not be able to make
   * progress since
   * <Object_Adapter::non_servant_upcall_in_progress_> has been
   * set.
   */
  class TAO_PortableServer_Export Non_Servant_Upcall
  {
  public:

    /// Constructor.
    Non_Servant_Upcall (TAO_POA &poa);

    /// Destructor.
    ~Non_Servant_Upcall (void);

    TAO_POA &poa (void) const;

  protected:

    TAO_Object_Adapter &object_adapter_;
    TAO_POA &poa_;
    Non_Servant_Upcall *previous_;
  };

  friend class Non_Servant_Upcall;

  /**
   * @class Servant_Upcall
   *
   * @brief This class finds out the POA and the servant to perform an
   * upcall.  It can only be instantiated without the object
   * adapter's lock held.
   */
  class TAO_PortableServer_Export Servant_Upcall
  {
  public:

    friend class TAO_POA;
    friend class TAO_RT_Collocation_Resolver;

    /**
     * @class Pre_Invoke_State
     *
     * @brief This struct keeps track of state related to pre- and
     * post-invoke operations.
     */
    class Pre_Invoke_State
    {
    public:
      // Constructor.
      Pre_Invoke_State (void);

      enum State
      {
        NO_ACTION_REQUIRED,
        PRIORITY_RESET_REQUIRED
      };

      // Indicates whether the priority of the thread needs to be
      // reset back to its original value.
      State state_;

      // Original native priority of the thread.
      CORBA::Short original_native_priority_;

      // Original CORBA priority of the thread.
      CORBA::Short original_CORBA_priority_;
    };

    // @@ PPOA: Servant_Upcall (TAO_Object_Adapter &object_adapter);
    /// Constructor.
    Servant_Upcall (TAO_ORB_Core *orb_core);

    /// Destructor.
    ~Servant_Upcall (void);

    /// Locate POA and servant.
    int prepare_for_upcall (const TAO::ObjectKey &key,
                            const char *operation,
                            CORBA::Object_out forward_to
                            ACE_ENV_ARG_DECL_WITH_DEFAULTS);

    /// Run pre_invoke for a remote request.
    void pre_invoke_remote_request (TAO_ServerRequest &req
                                    ACE_ENV_ARG_DECL);

    /// Run pre_invoke for a collocated request.
    void pre_invoke_collocated_request (ACE_ENV_SINGLE_ARG_DECL);

    /// Run post_invoke for a request.
    void post_invoke (void);

    /// Locate POA.
    TAO_POA *lookup_POA (const TAO::ObjectKey &key
                         ACE_ENV_ARG_DECL);

    /// POA accessor.
    TAO_POA &poa (void) const;

    /// Object Adapter accessor.
    TAO_Object_Adapter &object_adapter (void) const;

    /// System ID accessor.
    const PortableServer::ObjectId &id (void) const;

    /// User ID accessors.  This is the same value returned by
    /// PortableServer::Current::get_object_id().
    void user_id (const PortableServer::ObjectId *);
    const PortableServer::ObjectId &user_id (void) const;

    /// Servant accessor.
    PortableServer::Servant servant (void) const;

#if (TAO_HAS_MINIMUM_POA == 0)

    /// Get the Servant Locator's cookie
    PortableServer::ServantLocator::Cookie locator_cookie (void) const;

    /// Set the Servant Locator's cookie
    void locator_cookie (PortableServer::ServantLocator::Cookie cookie);

    /// Get the operation name.
    const char *operation (void) const;

    /// Set the operation name.
    void operation (const char *);

#endif /* TAO_HAS_MINIMUM_POA == 0 */

    /// Set the <active_object_map_entry>.
    void active_object_map_entry (TAO_Active_Object_Map::Map_Entry *entry);

    /// Get the <active_object_map_entry>.
    TAO_Active_Object_Map::Map_Entry *active_object_map_entry (void) const;

    /// We are using the servant locator for this upcall.
    void using_servant_locator (void);

    /// Get the priority for the current upcall.
    CORBA::Short priority (void) const;

    enum State
    {
      INITIAL_STAGE,
      OBJECT_ADAPTER_LOCK_ACQUIRED,
      POA_CURRENT_SETUP,
      OBJECT_ADAPTER_LOCK_RELEASED,
      SERVANT_LOCK_ACQUIRED
    };

    // State accessors.
    State state (void) const;
    void state (State);

  protected:

    void servant_locator_cleanup (void);
    void single_threaded_poa_setup (ACE_ENV_SINGLE_ARG_DECL);
    void single_threaded_poa_cleanup (void);
    void servant_cleanup (void);
    void poa_cleanup (void);

    TAO_Object_Adapter *object_adapter_;

    TAO_POA *poa_;

    PortableServer::Servant servant_;

    State state_;

    PortableServer::ObjectId system_id_;

    const PortableServer::ObjectId *user_id_;

    TAO_POA_Current_Impl current_context_;

#if (TAO_HAS_MINIMUM_POA == 0)

    /// Servant Locator's cookie
    PortableServer::ServantLocator::Cookie cookie_;

    /// Operation name for this current.
    const char *operation_;

#endif /* TAO_HAS_MINIMUM_POA == 0 */

    /// Pointer to the entry in the TAO_Active_Object_Map corresponding
    /// to the servant for this request.
    TAO_Active_Object_Map::Map_Entry *active_object_map_entry_;

    /// Are we using the servant locator?
    int using_servant_locator_;

    /// Preinvoke data for the upcall.
    Pre_Invoke_State pre_invoke_state_;

  private:
    Servant_Upcall (const Servant_Upcall &);
    void operator= (const Servant_Upcall &);
  };

  friend class Servant_Upcall;

public:

  /// Pointer to the non-servant upcall in progress.  If no non-servant
  /// upcall is in progress, this pointer is zero.
  Non_Servant_Upcall *non_servant_upcall_in_progress (void) const;

private:

  /// Helper method to get collocated servant
  TAO_ServantBase *get_collocated_servant (TAO_Stub *stub,
                                           const TAO_MProfile &mp
                                           ACE_ENV_ARG_DECL);

private:

  /// Condition variable for waiting on non-servant upcalls to end.
  TAO_SYNCH_CONDITION non_servant_upcall_condition_;

  /// Pointer to the non-servant upcall in progress.  If no non-servant
  /// upcall is in progress, this pointer is zero.
  Non_Servant_Upcall *non_servant_upcall_in_progress_;

  /// Current nesting level of non_servant_upcalls.
  unsigned int non_servant_upcall_nesting_level_;

  /// Id of thread making the non-servant upcall.
  ACE_thread_t non_servant_upcall_thread_;

  /// The Root POA
  TAO_POA *root_;

  /// The default validator and the beginning of the chain of
  /// policy validators.
  TAO_POA_Default_Policy_Validator default_validator_;

  /// Save a list of default policies that should be included in
  /// every POA (unless overridden).
  TAO_POA_Policy_Set default_poa_policies_;
};

// ****************************************************************

class TAO_PortableServer_Export TAO_Object_Adapter_Factory : public TAO_Adapter_Factory
{
public:
  /// Constructor
  TAO_Object_Adapter_Factory (void);

  // = The TAO_Adapter_Factory methods, please read tao/Adapter.h for
  // details.
  virtual TAO_Adapter *create (TAO_ORB_Core *orb_core);

  virtual int init (int argc,
                    ACE_TCHAR* argv[]);
};

ACE_STATIC_SVC_DECLARE (TAO_Object_Adapter_Factory)
ACE_FACTORY_DECLARE (TAO_PortableServer, TAO_Object_Adapter_Factory)

// ****************************************************************

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__ACE_INLINE__)
# include "Object_Adapter.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"

#endif /* TAO_OBJECT_ADAPTER_H */
