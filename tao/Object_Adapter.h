/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Object_Adapter.h
//
// = AUTHOR
//    Irfan Pyarali
//
// ============================================================================

#ifndef TAO_OBJECT_ADAPTER_H
#define TAO_OBJECT_ADAPTER_H

#include "tao/Key_Adapters.h"
#include "tao/Server_Strategy_Factory.h"
#include "tao/poa_macros.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

////////////////////////////////////////////////////////////////////////////////

// Forward declaration
class TAO_POA;
class TAO_Temporary_Creation_Time;

class TAO_Object_Adapter
{
  // = TITLE
  //     Defines the Object Adapter abstraction.
  //
  // = DESCRIPTION
  //     This class will be used as a facade for the POAs in a server
public:

  typedef PortableServer::ObjectId poa_name;
  typedef PortableServer::ObjectId_var poa_name_var;
  typedef PortableServer::ObjectId_out poa_name_out;

  TAO_Object_Adapter (const TAO_Server_Strategy_Factory::Active_Object_Map_Creation_Parameters &creation_parameters,
                      TAO_ORB_Core &orb_core);
  // Constructor.

  ~TAO_Object_Adapter (void);
  // Destructor.

  void dispatch_servant (const TAO_ObjectKey &key,
                         CORBA::ServerRequest &req,
                         void *context,
                         CORBA_Environment &ACE_TRY_ENV);

  int locate_servant (const TAO_ObjectKey &key,
                      CORBA_Environment &ACE_TRY_ENV);

  PortableServer::Servant find_servant (const TAO_ObjectKey &key,
                                        CORBA_Environment &ACE_TRY_ENV);

  int find_poa (const poa_name &system_name,
                CORBA::Boolean activate_it,
                CORBA::Boolean root,
                const TAO_Temporary_Creation_Time &poa_creation_time,
                TAO_POA *&poa,
                CORBA_Environment &ACE_TRY_ENV);

  int bind_poa (const poa_name &folded_name,
                TAO_POA *poa,
                poa_name_out system_name);

  int unbind_poa (TAO_POA *poa,
                  const poa_name &folded_name,
                  const poa_name &system_name);

  int activate_poa (const poa_name &folded_name,
                    TAO_POA *&poa,
                    CORBA_Environment &ACE_TRY_ENV);

  ACE_Lock &lock (void);

  ACE_SYNCH_MUTEX &thread_lock (void);

  ACE_Reverse_Lock<ACE_Lock> &reverse_lock (void);

  static CORBA::ULong transient_poa_name_size (void);

protected:

  int locate_servant_i (const TAO_ObjectKey &key,
                        CORBA_Environment &ACE_TRY_ENV);

  PortableServer::Servant find_servant_i (const TAO_ObjectKey &key,
                                          CORBA_Environment &ACE_TRY_ENV);

  void dispatch_servant_i (const TAO_ObjectKey &key,
                           CORBA::ServerRequest &req,
                           void *context,
                           CORBA_Environment &ACE_TRY_ENV);

  void locate_poa (const TAO_ObjectKey &key,
                   PortableServer::ObjectId &id,
                   TAO_POA *&poa,
                   CORBA_Environment &ACE_TRY_ENV);

  int find_transient_poa (const poa_name &system_name,
                          CORBA::Boolean root,
                          const TAO_Temporary_Creation_Time &poa_creation_time,
                          TAO_POA *&poa);

  int find_persistent_poa (const poa_name &system_name,
                           TAO_POA *&poa,
                           CORBA_Environment &ACE_TRY_ENV);

  int bind_transient_poa (TAO_POA *poa,
                          poa_name_out system_name);

  int bind_persistent_poa (const poa_name &folded_name,
                           TAO_POA *poa,
                           poa_name_out system_name);

  int unbind_transient_poa (const poa_name &system_name);

  int unbind_persistent_poa (const poa_name &folded_name,
                             const poa_name &system_name);

  static ACE_Lock *create_lock (int enable_locking,
                                ACE_SYNCH_MUTEX &thread_lock);

  class Hint_Strategy
  {
    // = TITLE
    //     Base class for POA active hint strategy.
    //
    // = DESCRIPTION
    //     This class also provides for common structures used by all
    //     the derived classes.
  public:

    virtual ~Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa,
                                     CORBA_Environment &ACE_TRY_ENV) = 0;

    virtual int bind_persistent_poa (const poa_name &folded_name,
                                     TAO_POA *poa,
                                     poa_name_out system_name) = 0;

    virtual int unbind_persistent_poa (const poa_name &folded_name,
                                       const poa_name &system_name) = 0;

    void object_adapter (TAO_Object_Adapter *oa);

  protected:

    TAO_Object_Adapter *object_adapter_;
  };

  class Active_Hint_Strategy : public Hint_Strategy
  {
    // = TITLE
    //     This class uses active demux hint for POA active hint
    //     strategy.
    //
    // = DESCRIPTION
    //     This class will append an active hint to the POA name,
    //     making the POA lookups fast and predictable.
  public:

    Active_Hint_Strategy (CORBA::ULong map_size);

    virtual ~Active_Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa,
                                     CORBA_Environment &ACE_TRY_ENV);

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

  class No_Hint_Strategy : public Hint_Strategy
  {
    // = TITLE
    //     This class doesn't use any hints for POA active hint
    //     strategy.
    //
    // = DESCRIPTION
    //     This class will simply use the POA names as is. And since
    //     no hint is added, the IORs will be smaller.
  public:

    virtual ~No_Hint_Strategy (void);

    virtual int find_persistent_poa (const poa_name &system_name,
                                     TAO_POA *&poa,
                                     CORBA_Environment &ACE_TRY_ENV);

    virtual int bind_persistent_poa (const poa_name &folded_name,
                                     TAO_POA *poa,
                                     poa_name_out system_name);

    virtual int unbind_persistent_poa (const poa_name &folded_name,
                                       const poa_name &system_name);

  };

  Hint_Strategy *hint_strategy_;

  typedef ACE_Map<
  poa_name,
    TAO_POA *> transient_poa_map;
  // Base class of the id map.

  typedef ACE_Hash_Map_Manager_Ex_Adapter<
  poa_name,
    TAO_POA *,
    TAO_ObjectId_Hash,
    ACE_Equal_To<poa_name>,
    TAO_Incremental_Key_Generator> transient_poa_hash_map;
  // Id hash map.

  typedef ACE_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    TAO_Incremental_Key_Generator> transient_poa_linear_map;
  // Id linear map.

  typedef ACE_Active_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    TAO_Ignore_Original_Key_Adapter> transient_poa_active_map;
  // Id active map.

  typedef ACE_Map<
  poa_name,
    TAO_POA *> persistent_poa_name_map;
  // Base class of the name map.

  typedef ACE_Hash_Map_Manager_Ex_Adapter<
  poa_name,
    TAO_POA *,
    TAO_ObjectId_Hash,
    ACE_Equal_To<PortableServer::ObjectId>,
    ACE_Noop_Key_Generator<poa_name> > persistent_poa_name_hash_map;
  // Id hash map.

  typedef ACE_Map_Manager_Adapter<
  poa_name,
    TAO_POA *,
    ACE_Noop_Key_Generator<poa_name> > persistent_poa_name_linear_map;
  // Id linear map.

public:

  persistent_poa_name_map *persistent_poa_name_map_;
  transient_poa_map *transient_poa_map_;

protected:

  static size_t transient_poa_name_size_;

  static void set_transient_poa_name_size (const TAO_Server_Strategy_Factory::Active_Object_Map_Creation_Parameters &creation_parameters);

  TAO_ORB_Core &orb_core_;

  int enable_locking_;

  ACE_SYNCH_MUTEX thread_lock_;

  ACE_Lock *lock_;

  ACE_Reverse_Lock<ACE_Lock> reverse_lock_;

  ACE_SYNCH_CONDITION non_servant_upcall_condition_;
  // Condition variable for waiting on non-servant upcalls to end.

  CORBA::Boolean non_servant_upcall_in_progress_;
  // Flag for knowing when an non-servant upcall is in progress.

  ACE_thread_t non_servant_upcall_thread_;
  // Id of thread making the non-servant upcall.

public:

  class poa_name_iterator
  {
    // = TITLE
    //     Iterator for a folded poa name.
  public:

    poa_name_iterator (int begin,
                       CORBA::ULong size,
                       const CORBA::Octet *folded_buffer);
    // Constructor.

    int operator== (const poa_name_iterator &rhs) const;
    int operator!= (const poa_name_iterator &rhs) const;
    // Comparison operators.

    ACE_CString operator* () const;
    // Dereference operator.

    poa_name_iterator &operator++ (void);
    // Prefix advance.

  protected:

    CORBA::ULong size_;
    CORBA::ULong position_;
    const CORBA::Octet *folded_buffer_;
    CORBA::ULong last_separator_;
  };

  class iteratable_poa_name
  {
    // = TITLE
    //     This class allows iteration over a folded poa name.
  public:

    typedef poa_name_iterator iterator;

    iteratable_poa_name (const poa_name &folded_name);

    iterator begin (void) const;
    iterator end (void) const;

  protected:

    const poa_name &folded_name_;
  };

  class Non_Servant_Upcall
  {
    // = TITLE
    //     This class helps us with a recursive thread lock without
    //     using a recursive thread lock.  Non_Servant_Upcall has a
    //     magic constructor and destructor.  We unlock the
    //     Object_Adapter lock for the duration of the non-servant
    //     (i.e., adapter activator and servant activator) upcalls;
    //     reacquiring once the upcalls complete.  Even though we are
    //     releasing the lock, other threads will not be able to make
    //     progress since
    //     <Object_Adapter::non_servant_upcall_in_progress_> has been
    //     set.
  public:

    Non_Servant_Upcall (TAO_Object_Adapter &object_adapter);
    // Constructor.

    ~Non_Servant_Upcall (void);
    // Destructor.

  protected:

    TAO_Object_Adapter &object_adapter_;
  };

  friend Non_Servant_Upcall;

  class Outstanding_Requests
  {
    // = TITLE
    //     This class helps us by increasing
    //     <POA::outstanding_requests_> for the duration of the
    //     servant upcall. Outstanding_Requests has a magic
    //     constructor and destructor.  We increment
    //     <POA::outstanding_requests_> in the constructor.  We
    //     decrement <POA::outstanding_requests_> in the destructor.
    //     Note that the lock is released after
    //     <POA::outstanding_requests_> is increased and
    //     <POA::outstanding_requests_> is decreased after the lock
    //     has been reacquired.
  public:

    Outstanding_Requests (TAO_POA &poa,
                          TAO_Object_Adapter &object_adapter);
    // Constructor.

    ~Outstanding_Requests (void);
    // Destructor.

  protected:

    TAO_POA &poa_;
    TAO_Object_Adapter &object_adapter_;
  };

  friend Outstanding_Requests;

  class Single_Threaded_POA_Lock
  {
    // = TITLE
    //     This class helps us by locking servants in a single
    //     threaded POA for the duration of the upcall.
    //     Single_Threaded_POA_Lock has a magic constructor and
    //     destructor.  We acquire the servant lock in the
    //     constructor.  We release the servant lock in the
    //     destructor.
  public:

    Single_Threaded_POA_Lock (TAO_POA &poa,
                              PortableServer::Servant servant);
    // Constructor.

    ~Single_Threaded_POA_Lock (void);
    // Destructor.

  protected:

    TAO_POA &poa_;
    PortableServer::Servant servant_;
  };

  friend Single_Threaded_POA_Lock;

};

////////////////////////////////////////////////////////////////////////////////

#if defined (__ACE_INLINE__)
# include "tao/Object_Adapter.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_OBJECT_ADAPTER_H */
