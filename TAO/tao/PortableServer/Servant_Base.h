// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Servant_Base.h
//
// = AUTHOR
//     Irfan Pyarali
//
// ============================================================================

#ifndef TAO_SERVANT_BASE_H
#define TAO_SERVANT_BASE_H
#include "ace/pre.h"

#include "PortableServerC.h"
#include "tao/Abstract_Servant_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_Operation_Table;

class TAO_PortableServer_Export TAO_ServantBase 
  : public virtual TAO_Abstract_ServantBase
{
  // = TITLE
  //     Base class for skeletons and servants.
  //
  // = DESCRIPTION
  //     The POA spec requires that all servants inherit from this
  //     class.
public:
  friend class TAO_POA;
  friend class TAO_Object_Adapter;
  friend class CORBA_Object;
  friend class TAO_Local_ServantBase;

  virtual ~TAO_ServantBase (void);
  // Destructor.

  virtual PortableServer::POA_ptr _default_POA (
      CORBA_Environment &ACE_TRY_ENV = 
        TAO_default_environment ()
    );
  // Returns the default POA for this servant.

  virtual CORBA::Boolean _is_a (const char* logical_type_id,
                                CORBA_Environment &ACE_TRY_ENV = 
                                  TAO_default_environment ());
  // Local implementation of the CORBA::Object::_is_a method.

  virtual CORBA::Boolean _non_existent (CORBA_Environment &ACE_TRY_ENV = 
                                          TAO_default_environment ());
  // Default <_non_existent>: always returns false.

  virtual void *_downcast (const char *repository_id) = 0;
  // Get the correct vtable.

  virtual TAO_Stub *_create_stub (CORBA_Environment &ACE_TRY_ENV = 
                                    TAO_default_environment ());
  // This is an auxiliar method for _this() and _narrow().

protected:
  TAO_ServantBase (void);
  // Default constructor, only derived classes can be created.

  TAO_ServantBase (const TAO_ServantBase &);
  // Copy constructor, protected so no instances can be created.

  TAO_ServantBase &operator= (const TAO_ServantBase &);
  // assignment operator.

  virtual void _dispatch (TAO_ServerRequest &request,
                          void *context,
                          CORBA_Environment &ACE_TRY_ENV = 
                            TAO_default_environment ()) = 0;
  // Dispatches a request to the object: find the operation, cast the
  // type to the most derived type, demarshall all the parameters from
  // the request and finally invokes the operation, storing the
  // results and out parameters (if any) or the exceptions thrown into
  // <request>.

  virtual void synchronous_upcall_dispatch (TAO_ServerRequest &req,
                                            void *context,
                                            void *derived_this,
                                            CORBA::Environment &ACE_TRY_ENV);

  virtual int _find (const char *opname,
                     TAO_Skeleton &skelfunc,
                     const unsigned int length = 0);
  // Find an operation in the operation table.

  virtual int _bind (const char *opname,
                     const TAO_Skeleton skel_ptr);
  // Register a CORBA IDL operation name.

  virtual const char *_interface_repository_id (void) const = 0;
  // Get this interface's repository id (TAO specific).

  // = Should be protected/private, but a nested class needs it.
public:
  ACE_SYNCH_MUTEX &_single_threaded_poa_lock (void);
  // Access to the single threaded poa lock.

protected:
  void _increment_single_threaded_poa_lock_count (void);
  // New single threaded POA wants to use this lock.

  void _decrement_single_threaded_poa_lock_count (void);
  // Single threaded POA is no longer interested in this lock.

  TAO_Operation_Table *optable_;
  // The operation table for this servant, it is initialized by the
  // most derived class.

  ACE_SYNCH_MUTEX *single_threaded_poa_lock_;
  // Lock for single threaded POAs.

  u_long single_threaded_poa_lock_count_;
  // Reference count for lock.
};

class TAO_PortableServer_Export TAO_RefCountServantBase 
  : public virtual TAO_ServantBase
{
  // = TITLE
  //     Reference counting mix-in class.
  //
  // = DESCRIPTION
  //     The RefCountServantBase mix-in class overrides the inherited
  //     _add_ref and _remove_ref functions it inherits from
  //     ServantBase, implementing them to provide true reference
  //     counting. An instance of a servant class derived from
  //     RefCountServantBase initially has a reference count of
  //     one. Invoking _add_ref on the servant instance increases its
  //     reference count by one. Invoking _remove_ref on the servant
  //     instance decreases its reference count by one; if the
  //     resulting reference count equals zero, _remove_ref invokes
  //     delete on its this pointer in order to destroy the
  //     servant. For ORBs that operate in multi-threaded
  //     environments, the implementations of _add_ref and _remove_ref
  //     that the RefCountServantBase class provides shall be
  //     thread-safe.
  //
  //     Like ServantBase, RefCountServantBase supports copy
  //     construction and the default assignment operation. Copy
  //     construction always sets the reference count of the new
  //     servant instance to one. The default assignment
  //     implementation merely returns *this and does not affect the
  //     reference count.

public:

  ~TAO_RefCountServantBase (void);
  // Destructor.

  virtual void _add_ref (CORBA_Environment &ACE_TRY_ENV = 
                           TAO_default_environment ());
  // Increase reference count by one.

  virtual void _remove_ref (CORBA_Environment &ACE_TRY_ENV = 
                              TAO_default_environment ());
  // Decreases reference count by one; if the resulting reference
  // count equals zero, _remove_ref invokes delete on its this pointer
  // in order to destroy the servant.

protected:

  TAO_RefCountServantBase (void);
  // Constructor: initial reference count is one.

  TAO_RefCountServantBase (const TAO_RefCountServantBase &);
  // Copy Constructor: Always sets the reference count of the new
  // servant instance to one.

  TAO_RefCountServantBase &operator= (const TAO_RefCountServantBase &);
  // The default assignment implementation merely returns *this and
  // does not affect the reference count.

private:

  ACE_Atomic_Op<ACE_SYNCH_MUTEX, long> ref_count_;
  // Reference counter.
};

class TAO_PortableServer_Export TAO_ServantBase_var
{
  // = TITLE
  //     Auto pointer for reference counting servants.
  //
  // = DESCRIPTION
  //     For the convenience of automatically managing servant
  //     reference counts, the PortableServer namespace also provides
  //     the ServantBase_var class. This class behaves similarly to
  //     _var classes for object references (see Section 20.3.1).

public:
  TAO_ServantBase_var (void);

  TAO_ServantBase_var (TAO_ServantBase *p);

  TAO_ServantBase_var (const TAO_ServantBase_var &b);

  ~TAO_ServantBase_var (void);

  TAO_ServantBase_var &operator= (TAO_ServantBase *p);

  TAO_ServantBase_var &operator= (const TAO_ServantBase_var &b);

  TAO_ServantBase *operator-> () const;

  TAO_ServantBase *in (void) const;

  TAO_ServantBase *&inout (void);

  TAO_ServantBase *&out (void);

  TAO_ServantBase *_retn (void);

private:

  TAO_ServantBase *ptr_;
};

class TAO_PortableServer_Export TAO_Servant_Hash
{
public:
  u_long operator () (PortableServer::Servant servant) const;
  // Returns hash value.
};

class TAO_PortableServer_Export TAO_Local_ServantBase 
  : public virtual TAO_ServantBase
{
  // = TITLE
  //     Base class for local servants.
  //
  // = DESCRIPTION
  //     This servant does not register with the POA and does not
  //     produce a valid stub, i.e., object references of this servant
  //     cannot be exported.  The (collocated) stubs of these servants
  //     will always be direct, i.e., call directly to the servant and
  //     don't call through the POA since this servant is not
  //     registered with the POA.
  //
protected:
  TAO_Stub *_create_stub (CORBA_Environment &ACE_TRY_ENV = 
                            TAO_default_environment ());
  // This is an auxiliar method for _this().  Make sure *not* to
  // register with the default POA.

  void _dispatch (TAO_ServerRequest &request,
                  void *context,
                  CORBA_Environment &ACE_TRY_ENV = 
                    TAO_default_environment ());
  // Throws CORBA::BAD_OPERATION exception.
};

#if defined (__ACE_INLINE__)
# include "Servant_Base.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_SERVANT_BASE_H */
