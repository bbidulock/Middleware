// This may look like C, but it's really -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    except.h
//
// = DESCRIPTION
//     This file defines way in which CORBA exceptions are reported.
//
// = AUTHOR
//     Copyright 1994-1995 by Sun Microsystems Inc.
//
// ============================================================================

#ifndef TAO_EXCEPTION_H
#define TAO_EXCEPTION_H

#include "tao/corbafwd.h"

class CORBA_Any;

class TAO_Export CORBA_Exception
{
  // = TITLE
  //   CORBA_Exception
  //
  // = DESCRIPTION
  //   CORBA2-specified exception hierarchy.  All exceptions have a
  //   type (represented by a TypeCode) and a widely scoped type ID
  //   (in the TypeCode) that generated by any OMG-IDL compiler and
  //   available through the Interface Repositories.  Think of it as a
  //   "globally scoped" name distinguishing each exception.
public:
  // = Initialization and termination methods.
  CORBA_Exception (const CORBA_Exception &src);
  // Copy constructor.

  CORBA_Exception &operator = (const CORBA_Exception &src);
  // Assignment operator.

  virtual ~CORBA_Exception (void);
  // Destructor.

  // = These are TAO-specific extensions.

  // @@ Nanbor, can you please rearrange these methods so that all the
  // TAO-specific stuff comes in one place, e.g., at the end of the
  // public part?
  CORBA_Exception (CORBA::TypeCode_ptr type);
  // Constructor from a TypeCode.

  const char *_id (void) const;
  // Return the repository ID of the Exception.

  TAO_CONST CORBA::TypeCode_ptr _type (void) const;
  // Return the TypeCode corresponding to the currently stored.

  // = To implement the narrow method.
  virtual int _is_a (const char* repository_id) const;

  // = To throw the exception (when using the standard mapping).
  virtual void _raise (void) = 0;

  // = TAO extension.  It makes it easier to write generic code.
  static CORBA_Exception *_narrow (CORBA_Exception *x);

  void print_exception (const char *info,
                        FILE *f = stdout) const;
  // Print the exception <ex> to output determined by <f>.  This
  // function is not CORBA compliant.

  // = Methods required for memory management support.
  CORBA::ULong _incr_refcnt (void);
  CORBA::ULong _decr_refcnt (void);

protected:
  CORBA_Exception (void);
  // Default constructor is protected.

  CORBA::TypeCode_ptr type_;
  // Type of the Exception.

private:
  CORBA::ULong refcount_;
  // Reference count to avoid copying overhead.

  ACE_SYNCH_MUTEX refcount_lock_;
  // Mutex to protect the reference count; though in most cases this
  // class is used only in one thread adding a mutex here is *not*
  // expensive, because uses of this class should never be on the
  // critical path.
};

class TAO_Export CORBA_UserException : public CORBA_Exception
{
  // = TITLE
  //   User exceptions are those defined by application developers
  //   using OMG-IDL.
public:
  // @@ Nanbor, can you please rearrange these methods so that all the
  // TAO-specific stuff comes in one place, e.g., at the end of the
  // public part?

  // = Initialization and termination methods.
  CORBA_UserException (const CORBA_UserException &src);
  // Copy ctor.

  CORBA_UserException (CORBA::TypeCode_ptr tc);
  // Constructor from a TypeCode.

  ~CORBA_UserException (void);
  // Destructor.

  CORBA_UserException &operator= (const CORBA_UserException &src);
  // Assignment operator.

  static CORBA_UserException *_narrow (CORBA_Exception *exception);
  // The narrow operation.

  // = extension

  virtual int _is_a (const char *interface_id) const;
  // Used for narrowing

protected:
  CORBA_UserException (void);
  // Default constructor.
};

class TAO_Export CORBA_SystemException : public CORBA_Exception
{
  // = TITLE
  //   CORBA_SystemException
  //
  // = DESCRIPTION
  //   System exceptions are those defined in the CORBA spec; OMG-IDL
  //   defines these.
public:
  // = Initialization and termination methods.

  // @@ Nanbor, can you please rearrange these methods so that all the
  // TAO-specific stuff comes in one place, e.g., at the end of the
  // public part?

  CORBA_SystemException (const CORBA_SystemException &src);
  // Copy ctor.

  ~CORBA_SystemException (void);
  // Destructor.

  CORBA_SystemException &operator= (const CORBA_SystemException &src);
  // Assignment operator.

  CORBA::ULong minor (void) const;
  // Get the minor status.

  void minor (CORBA::ULong m);
  // Set the minor status.

  CORBA::CompletionStatus completed (void) const;
  // Get the completion status.

  void completed (CORBA::CompletionStatus c);
  // Set the operation completion status.

  static CORBA_SystemException *_narrow (CORBA_Exception *exception);
  // Narrow to a SystemException.

  // = TAO-specific extension.

  virtual int _is_a (const char *type_id) const;
  // Helper for the _narrow operation.

  virtual void _raise (void);
  // @@ Nanbor, please document!

  void print_exception_tao_ (FILE *f = stdout) const;
  // Print the system exception <ex> to output determined by f.  This
  // function is not CORBA compliant.

  static CORBA::ULong minor_code_tao_ (u_int location,
                                       int errno_value);
  // Helper to create a minor status value.

  static CORBA::ULong errno_tao_ (int errno_value);
  // Helper to translate a platform-specific errno to a TAO errno
  // value.

protected:
  CORBA_SystemException (CORBA::TypeCode_ptr tc,
                         CORBA::ULong code,
                         CORBA::CompletionStatus completed);
  // Ctor using a TypeCode.

private:
  CORBA::ULong minor_;
  // Minor code.

  CORBA::CompletionStatus completed_;
  // Completion status.
};

// Declarations for all of the CORBA standard exceptions.
//
// @@ - shouldn't have a default minor code, at least for code that's
// inside the ORB.  All minor codes should be symbolically catalogued.

#define TAO_SYSTEM_EXCEPTION(name) \
class TAO_Export CORBA_ ## name : public CORBA_SystemException { \
public: \
  CORBA_ ## name (void); \
  CORBA_ ## name (CORBA::ULong code, \
                  CORBA::CompletionStatus completed) \
    : CORBA_SystemException (CORBA::_tc_ ## name, code, completed) \
    { } \
  virtual void _raise (void); \
  static CORBA_##name * _narrow (CORBA_Exception* exception); \
  virtual int _is_a (const char* type_id) const; \
}

TAO_SYSTEM_EXCEPTION(UNKNOWN);
TAO_SYSTEM_EXCEPTION(BAD_PARAM);
TAO_SYSTEM_EXCEPTION(NO_MEMORY);
TAO_SYSTEM_EXCEPTION(IMP_LIMIT);
TAO_SYSTEM_EXCEPTION(COMM_FAILURE);
TAO_SYSTEM_EXCEPTION(INV_OBJREF);
TAO_SYSTEM_EXCEPTION(OBJECT_NOT_EXIST);
TAO_SYSTEM_EXCEPTION(NO_PERMISSION);
TAO_SYSTEM_EXCEPTION(INTERNAL);
TAO_SYSTEM_EXCEPTION(MARSHAL);
TAO_SYSTEM_EXCEPTION(INITIALIZE);
TAO_SYSTEM_EXCEPTION(NO_IMPLEMENT);
TAO_SYSTEM_EXCEPTION(BAD_TYPECODE);
TAO_SYSTEM_EXCEPTION(BAD_OPERATION);
TAO_SYSTEM_EXCEPTION(NO_RESOURCES);
TAO_SYSTEM_EXCEPTION(NO_RESPONSE);
TAO_SYSTEM_EXCEPTION(PERSIST_STORE);
TAO_SYSTEM_EXCEPTION(BAD_INV_ORDER);
TAO_SYSTEM_EXCEPTION(TRANSIENT);
TAO_SYSTEM_EXCEPTION(FREE_MEM);
TAO_SYSTEM_EXCEPTION(INV_IDENT);
TAO_SYSTEM_EXCEPTION(INV_FLAG);
TAO_SYSTEM_EXCEPTION(INTF_REPOS);
TAO_SYSTEM_EXCEPTION(BAD_CONTEXT);
TAO_SYSTEM_EXCEPTION(OBJ_ADAPTER);
TAO_SYSTEM_EXCEPTION(DATA_CONVERSION);
TAO_SYSTEM_EXCEPTION(INV_POLICY);
TAO_SYSTEM_EXCEPTION(REBIND);
TAO_SYSTEM_EXCEPTION(TIMEOUT);
TAO_SYSTEM_EXCEPTION(TRANSACTION_UNAVAILABLE);
TAO_SYSTEM_EXCEPTION(TRANSACTION_MODE);
TAO_SYSTEM_EXCEPTION(TRANSACTION_REQUIRED);
TAO_SYSTEM_EXCEPTION(TRANSACTION_ROLLEDBACK);
TAO_SYSTEM_EXCEPTION(INVALID_TRANSACTION);

#undef TAO_SYSTEM_EXCEPTION

class TAO_Export CORBA_UnknownUserException : public CORBA_UserException
{
  // = TITLE
  //   CORBA_UnknownUserException
  //
  // = DESCRIPTION
  //   When user exceptions are received by a DII invocation the ORB
  //   is unable to create the exception with the right dynamic type;
  //   to workaround this problem it throws a
  //   <CORBA::UnknownUserException> that contains the exception inside
  //   an Any.
public:
  // = Initialization and termination methods.
  CORBA_UnknownUserException (void);
  // Constructor.

  CORBA_UnknownUserException (CORBA_Any& exception);
  // Destructor.

  virtual ~CORBA_UnknownUserException (void);
  // Constructor.

  CORBA_Any& exception (void);
  // Return the any containing the user exception.

  // @@ Nanbor, please document these methods.
  static CORBA_UnknownUserException *_narrow (CORBA_Exception *ex);
  virtual int _is_a (const char *type_id) const;
  virtual void _raise (void);

private:
  CORBA_Any *exception_;
  // @@ Nanbor, please document this.
};

class TAO_Export TAO_Exceptions
{
  // = TITLE
  //   This class is a namespace for exception-related static data and
  //   methods.
public:
  static void make_standard_typecode (CORBA::TypeCode_ptr &tcp,
                                      const char *name,
                                      char *buf,
                                      size_t buflen,
                                      CORBA_Environment &ACE_TRY_ENV =
                                      TAO_default_environment ());
  // Make the TypeCode for a standard exception.  When used correctly,
  // initializing system exceptions is only an exercise in CPU time;
  // it allocates no new memory.

  static void make_unknown_user_typecode (CORBA::TypeCode_ptr &tcp,
                                          CORBA_Environment &ACE_TRY_ENV =
                                          TAO_default_environment ());
  // Make the TypeCode for the CORBA::UnknownUserException standard
  // exception.

  static void init (CORBA_Environment &TAO_IN_ENV =
                    TAO_default_environment ());
  // Runtime initialization of all standard exception typecodes.
  // Called from <CORBA::ORB_init>.

  static void fini (void);
  // Runtime finalization of all standard exception typecodes.

  static CORBA_Exception *create_system_exception (const char *id,
                                                   CORBA_Environment &TAO_IN_ENV = TAO_default_environment ());
  // Create a CORBA::SystemException given the interface repository
  // ID.

  static CORBA::ExceptionList *system_exceptions;
  // List of system exceptions.

private:
  static ACE_Allocator *global_allocator_;
  // This global allocator is used to initialize system exception
  // typecodes.  Since at the time, the ORB is mostly still not
  // available.  Using a separate allocator prevent CDR routine from
  // accessing the optimized allocators from the ORB.
};

class CORBA_ExceptionList;
typedef CORBA_ExceptionList *CORBA_ExceptionList_ptr;

class CORBA_ExceptionList
{
  // = TITLE
  //   ExceptionList definition taken from CORBA v2.2 Feb 1998
  //
  // = DESCRIPTION
  //   Maintains a list of TypeCodes for Exceptions.
public:
  // = Intialization and termination methods.

  CORBA_ExceptionList (void);
  // constructor

  CORBA_ExceptionList (CORBA::ULong len,
                       CORBA::TypeCode_ptr *tc_list);
  // Constructor - initialize given a length and an array of
  // TypeCodes.

  ~CORBA_ExceptionList (void);
  // Destructor.

  CORBA::ULong count ();
  // Return the number of elements.

  // @@ Nanbor, can you please document these?
  CORBA_ExceptionList_ptr _duplicate (void);

  void _destroy (void);

  static CORBA_ExceptionList_ptr _nil (void);

  void add (CORBA::TypeCode_ptr tc);
  // Add a TypeCode to the list

  void add_consume (CORBA::TypeCode_ptr tc);
  // Add and consume a TypeCode to the list

  CORBA::TypeCode_ptr item (CORBA::ULong slot,
                            CORBA_Environment &TAO_IN_ENV =
                            TAO_default_environment ());
  // Return the typecode at slot i. Raises the "Bounds" exception.

  void remove (CORBA::ULong slot,
               CORBA_Environment &TAO_IN_ENV =
               TAO_default_environment ());
  // Remove the typecode at slot i. Raises the "Bounds" exception.

#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA::ExceptionList_ptr _ptr_type;
  typedef CORBA::ExceptionList_var _var_type;
#endif /* __GNUC__ */
  // Useful for template programming.

private:
  // = Not allowed.
  CORBA_ExceptionList (const CORBA_ExceptionList &);
  CORBA_ExceptionList &operator= (const CORBA_ExceptionList &);

  ACE_Atomic_Op<ACE_SYNCH_MUTEX, CORBA::ULong> ref_count_;
  // Reference counter.

  ACE_Unbounded_Queue<CORBA::TypeCode_ptr> tc_list_;
  // internal list of typecodes
};

class TAO_Export CORBA_ExceptionList_var
{
  // = TITLE
  //  @@ Nanbor, please document.
public:
  CORBA_ExceptionList_var (void);
  // default constructor
  CORBA_ExceptionList_var (CORBA_ExceptionList_ptr);
  CORBA_ExceptionList_var (const CORBA_ExceptionList_var &);
  // copy constructor
  ~CORBA_ExceptionList_var (void);
  // destructor

  CORBA_ExceptionList_var &operator= (CORBA_ExceptionList_ptr);
  CORBA_ExceptionList_var &operator= (const CORBA_ExceptionList_var &);
  CORBA_ExceptionList_ptr operator-> (void) const;

  operator const CORBA_ExceptionList_ptr &() const;
  operator CORBA_ExceptionList_ptr &();
  // in, inout, out, _retn
  CORBA_ExceptionList_ptr in (void) const;
  CORBA_ExceptionList_ptr &inout (void);
  CORBA_ExceptionList_ptr &out (void);
  CORBA_ExceptionList_ptr _retn (void);
  CORBA_ExceptionList_ptr ptr (void) const;

private:
  CORBA_ExceptionList_ptr ptr_;
};

#if defined (TAO_DONT_CATCH_DOT_DOT_DOT)
class TAO_Export TAO_DONT_CATCH
{
  // = TITLE
  //   This class is only used internally in TAO as an exception
  //   that never gets thrown.  Never use this class anywhere.
public:
  TAO_DONT_CATCH (void);
};
#endif /* TAO_DONT_CATCH_DOT_DOT_DOT */

#if defined (__ACE_INLINE__)
# include "tao/Exception.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_EXCEPTION_H */
