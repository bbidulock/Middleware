// This may look like C, but it's really -*- C++ -*-

// ============================================================================
//
// = LIBRARY
//    TAO
// 
// = FILENAME
//    orbobj.h
//
// = DESCRIPTION
//     Header file for Win32 interface to CORBA's "ORB" type.
//
//     The "ORB" pseudo-object is used in bootstrapping, such as to
//     create object references from strings.  It's also used to
//     create strings from object references.
//
// = AUTHOR
//     Copyright 1994-1995 by Sun Microsystems Inc.
// 
// ============================================================================

#if !defined (TAO_ORBOBJ_H)
#  define TAO_ORBOBJ_H

#if 0
#  include "ace/OS.h"

#  include "tao/factories.h"
#  include "tao/params.h"
#endif /* 0 */

#include "tao/corba.h"
#include "tao/connect.h"
#include "tao/orb.h"

class ACE_Svc_Export CORBA_ORB : public IUnknown
  // = TITLE
  // ORB pseudo-objref.
{
public:
  CORBA::POA_ptr POA_init (int &argc, 
                           char **argv, 
                           const char *poa_identifier = 0);
  // Initialize the Portable Object Adapter (POA).

  static CORBA::ORB_ptr _duplicate (CORBA::ORB_ptr orb);
  static CORBA::ORB_ptr _nil (void);

  virtual CORBA::Object_ptr string_to_object (CORBA::String str,
					      CORBA::Environment &env) = 0;
  virtual CORBA::String object_to_string (CORBA::Object_ptr obj,
					  CORBA::Environment &env) = 0;

  // similar for TypeCodes and Anys ... to/from octet sequences

  void create_list (CORBA::Long count,
                    CORBA::NVList_ptr &retval);

  // = New Things from the POA Specification
  //
  // Of all of these operations, only <run> is currently implemented.
  // Others require clarification of design or more implementation
  // than is currently available.
  
  CORBA::Boolean work_pending (void);
  // Returns an indication of whether the ORB needs the <{main thread}> to
  // perform some work.
  
  int perform_work (ACE_Time_Value * = 0);
  // If called by the <{main thread}>, this operation performs an
  // implementation-defined unit of work. Otherwise, it does nothing.
  //
  // It is platform-specific how the application and ORB arrange to
  // use compatible threading primitives.
  
  int run (ACE_Time_Value *tv = 0);
  // Instructs the ORB to initialize itself and run its event loop in
  // the current thread, not returning until the ORB has shut down.
  // If an error occurs during initialization or a run-time this
  // method will return -1.  If <tv> is non-NULL then if no requests
  // arrive at this thread before the timeout elapses we return to the
  // caller with a value of 0 (this allows timeouts).  Otherwise, if
  // we've returned since we've been asked to shut down the value of 1
  // is returned.
  //
  // <{Note that this interface differs from the POA specification,
  // which is reproduced below:}> 
  //
  // Returns when the ORB has shut down.  If called by the main
  // thread, it enables the ORB to perform work using the main
  // thread. Otherwise, it simply waits until the ORB has shut down.
  //
  // This operation can be used instead of perform_work() to give the
  // main thread to the ORB if there are no other activities that need
  // to share the main thread. Even in a pure multi-threaded server,
  // calling run() in the main thread is useful to ensure that the
  // process does not exit until the ORB has been shut down.

  void shutdown (CORBA::Boolean wait_for_completion = CORBA::B_FALSE);
  // This operation instructs the ORB to shut down. Shutting down the
  // ORB causes all Object Adapters to be shut down. If
  // <wait_for_completion> parameter is TRUE, this operation blocks
  // until all ORB processing (including request processing and object
  // deactivation or other operations associated with object adapters)
  // has completed.  <[NOTE]> <wait_for_completion>=TRUE is not
  // currently supported.

  // = <IUnknown> Support
  //
  // Stuff required for COM IUnknown support ... this class is
  // intended to be inherited by others, which will provide some more
  // of the CORBA/COM support.  Implementations of this "CORBA::ORB"
  // class must know how to create stringify/destringify their
  // objrefs, as well as how to marshal and unmarshal them ... as well
  // as provide their own QueryInterface.

  ULONG __stdcall AddRef (void);
  ULONG __stdcall Release (void);

  CORBA_Object_ptr resolve_initial_references (CORBA::String name);
  // This method acts as a miniature name service provided by the ORB
  // for certain well-known object references.  TAO will shortly
  // support the "NameService" and "RootPOA" via this method.

  // = TAO-specific methods.
  TAO_Client_Strategy_Factory *client_factory (void);
  // Returns pointer to the client factory.
  TAO_Server_Strategy_Factory *server_factory (void);
  // Returns pointer to the server factory.

  int open (void);
  // Set up the ORB Core's acceptor to listen on the
  // previously-specified port for requests.  Returns -1 on failure,
  // else 0.

protected:
  // We must be created via the <ORB_init> call.
  CORBA_ORB (void);
  virtual ~CORBA_ORB (void);

private:
  CORBA_Object_ptr resolve_name_service (void);
  // Resolve the name service object reference.

  CORBA_Object_ptr resolve_poa (void);
  // Resolve the POA.

  ACE_SYNCH_MUTEX lock_;
  u_int refcount_;
  ACE_Atomic_Op<ACE_SYNCH_MUTEX, CORBA::Boolean> open_called_;

  // @@ Quite possibly everything btw ORB_CORE_STUFF should go into
  // the TAO_ORB_Core class...

  // @@ Please document all these fields.

  // = ORB_CORE_STUFF
  TAO_Client_Strategy_Factory *client_factory_;

  CORBA::Boolean client_factory_from_service_config_;

  TAO_Server_Strategy_Factory *server_factory_;

  CORBA::Boolean server_factory_from_service_config_;

  ACE_Atomic_Op<ACE_SYNCH_MUTEX, CORBA::Boolean> should_shutdown_;
  // Flag which denotes that the ORB should shut down and <run> should
  // return.

  CORBA_Object_ptr name_service_;
  // If this is non-_nil(), then this is the object reference to our
  // configured Naming Context.

  // = NON-PROVIDED METHODS
  CORBA_ORB (const CORBA_ORB &);
  CORBA_ORB &operator= (const CORBA_ORB &);
};

#endif /* TAO_ORBOBJ_H */
