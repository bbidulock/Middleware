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

#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/Key_Adapters.h"
#include "tao/PortableServer/poa_macros.h"
#include "tao/PortableServer/Servant_Location.h"
#include "tao/PortableServer/Default_Policy_Validator.h"
#include "tao/PortableServer/POA_Policy_Set.h"

#include "tao/Adapter.h"
#include "tao/Server_Strategy_Factory.h"
#include "tao/LocalObject.h"

#include "ace/Reverse_Lock_T.h"
#include "ace/Condition_Thread_Mutex.h"
#include "ace/Map_T.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class TAO_POA;
class TAO_POA_Manager;
class TAO_TSS_Resources;
class TAO_Transport;
class TAO_Servant_Dispatcher;

namespace TAO
{
  namespace Portable_Server
  {
    class Non_Servant_Upcall;
    class Servant_Upcall;
    class POA_Current_Impl;
    class Temporary_Creation_Time;
  }
}

/**
 * @class TAO_Object_Adapter
 *
 * @brief Defines the Object Adapter abstraction.
 *
 * This class will be used as a facade for the POAs in a server
 */
class TAO_PortableServer_Export TAO_Object_Adapter
  : public TAO_Adapter
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
                const TAO::Portable_Server::Temporary_Creation_Time &poa_creation_time,
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

  int enable_locking() const;

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
                          const TAO::Portable_Server::Temporary_Creation_Time &poa_creation_time,
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

  friend class Active_Hint_Strategy;

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

  friend class No_Hint_Strategy;

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

  /// Persistent POA map
  persistent_poa_name_map *persistent_poa_name_map_;

  /// Transient POA map
  transient_poa_map *transient_poa_map_;

protected:

  static CORBA::ULong transient_poa_name_size_;

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
    bool operator== (const poa_name_iterator &rhs) const;
    bool operator!= (const poa_name_iterator &rhs) const;

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

  friend class TAO::Portable_Server::Non_Servant_Upcall;

  friend class TAO::Portable_Server::Servant_Upcall;

public:

  /// Pointer to the non-servant upcall in progress.  If no non-servant
  /// upcall is in progress, this pointer is zero.
  TAO::Portable_Server::Non_Servant_Upcall *non_servant_upcall_in_progress (void) const;

private:

  /// Helper method to get collocated servant
  TAO_ServantBase *get_collocated_servant (const TAO_MProfile &mp
                                           ACE_ENV_ARG_DECL);

private:

  /// Condition variable for waiting on non-servant upcalls to end.
  TAO_SYNCH_CONDITION non_servant_upcall_condition_;

  /// Pointer to the non-servant upcall in progress.  If no non-servant
  /// upcall is in progress, this pointer is zero.
  TAO::Portable_Server::Non_Servant_Upcall *non_servant_upcall_in_progress_;

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

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__ACE_INLINE__)
# include "Object_Adapter.i"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* TAO_OBJECT_ADAPTER_H */
