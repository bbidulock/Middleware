// This may look like C, but it's really -*- C++ -*-

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

#if !defined (TAO_EXCEPTION_H)
#  define TAO_EXCEPTION_H

class TAO_Export CORBA_Exception
{
  // = TITLE
  //   CORBA_Exception
  //
  // = DESCRIPTION
  //   CORBA2-specified exception hierarchy.
  //   All exceptions have a type (represented by a TypeCode) and a
  //   widely scoped type ID (in the TypeCode) that generated by any
  //   OMG-IDL compiler and available through the Interface
  //   Repositories.  Think of it as a "globally scoped" name
  //   distinguishing each exception.
public:
  CORBA_Exception (const CORBA_Exception &src);
  // copy constructor

  CORBA_Exception &operator = (const CORBA_Exception &src);
  // assignment operator

  virtual ~CORBA_Exception (void);
  // destructor

  // = Memory allocators.
  void *operator new (size_t, const void *p);
  void *operator new (size_t s);
  void operator delete (void *p);

  // these are extensions

  CORBA_Exception (CORBA::TypeCode_ptr type);
  // constructor from a TypeCode

  const char *_id (void) const;
  // return the repository ID of the Exception

  TAO_CONST CORBA::TypeCode_ptr _type (void) const;
  // return the TypeCode corresponding to the currently stored

  // = To implement the narrow method.
  virtual int _is_a (const char* repository_id) const;

  // = Methods required for memory management support.
  CORBA::ULong AddRef (void);
  CORBA::ULong Release (void);

protected:
  CORBA_Exception (void);
  // default constructor is protected

  CORBA::TypeCode_ptr type_;
  // Type of the Exception.

private:
  CORBA::ULong refcount_;
  // Reference count to avoid copying overhead.
};

class TAO_Export CORBA_UserException : public CORBA_Exception
{
  // = TITLE
  //   User exceptions are those defined by application developers
  //   using OMG-IDL.
public:
  CORBA_UserException (void);
  // default constructor

  CORBA_UserException (const CORBA_UserException &src);
  // copy ctor

  CORBA_UserException (CORBA::TypeCode_ptr tc);
  // constructor from a TypeCode

  ~CORBA_UserException (void);
  // destructor

  CORBA_UserException &operator= (const CORBA_UserException &src);
  // assignment operator

  static CORBA_UserException *_narrow (CORBA_Exception *exception);
  // the narrow operation

  // extension

  virtual int _is_a (const char *interface_id) const;
  // used for narrowing
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

  CORBA_SystemException (void);
  // default ctor

  CORBA_SystemException (const CORBA_SystemException &src);
  // copy ctor

  ~CORBA_SystemException (void);
  // destructor

  CORBA_SystemException &operator= (const CORBA_SystemException &src);
  // assignment operator

  CORBA::ULong minor (void) const;
  // get the minor status

  void minor (CORBA::ULong m);
  // set the minor status

  CORBA::CompletionStatus completion (void) const;
  // get the completion status

  void completion (CORBA::CompletionStatus c);
  // set the operation completion status

  static CORBA_SystemException *_narrow (CORBA_Exception* exception);
  // narrow to a SystemException

  // extension

  CORBA_SystemException (CORBA::TypeCode_ptr tc,
			 CORBA::ULong code,
			 CORBA::CompletionStatus completed);
  // ctor using a TypeCode

  virtual int _is_a (const char *type_id) const;
  // helper for the _narrow operation
private:
  CORBA::ULong minor_;
  // minor code

  CORBA::CompletionStatus completed_;
  // completion status

};

// Declarations for all of the CORBA standard exceptions.
//
// @@ - shouldn't have a default minor code, at least for code that's
// inside the ORB.  All minor codes should be symbolically catalogued.

#define TAO_SYSTEM_EXCEPTION(name) \
class TAO_Export CORBA_ ## name : public CORBA_SystemException { \
public: \
  CORBA_ ## name (CORBA::CompletionStatus completed, \
                  CORBA::ULong code = 0xffff0000L) \
    : CORBA_SystemException (CORBA::_tc_ ## name, code, completed) \
    { } \
  virtual int _is_a (const char* type_id) const; \
  static CORBA_##name * _narrow (CORBA_Exception* exception); \
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

#undef TAO_SYSTEM_EXCEPTION

class TAO_Export CORBA_Environment
{
  // = TITLE
  //   CORBA_Environment
  //
  // = DESCRIPTION
  // A CORBA_Environment is a way to automagically ensure that
  // exception data is freed -- the "var" class for Exceptions.  It
  // adds just a bit of convenience function support, helping classify
  // exceptions as well as reducing memory leakage.
public:
  // = Initialization and termination methods.
  CORBA_Environment (void);
  // ctor

  ~CORBA_Environment (void);
  // dtor

  CORBA::Exception_ptr exception (void) const;
  // Return the exception.  Caller must call AddRef() in order to keep
  // the ptr.

  void exception (CORBA::Exception *ex);
  // Set the exception to <ex>, taking a reference on it.

  CORBA::ExceptionType exception_type (void) const;
  // return the typecode for the exception

  TAO_CONST CORBA::String exception_id (void) const;
  // return the repository ID for the exception

  void clear (void);
  // Clear the exception.

  void print_exception (const char *info,
                        FILE *f=stdout) const;
  // print the exception to output determined by f

private:
  CORBA::Exception_ptr exception_;
  // Pointer to the exception object contained in the environment.

  // = These are not provided.
  CORBA_Environment (const CORBA_Environment &src);
  CORBA_Environment &operator = (const CORBA_Environment &src);
};

class TAO_Export TAO_Exceptions
{
  // = TITLE
  //   This class is a namespace for exception-related static data and
  //   methods.
public:

  static void make_standard_typecode (CORBA::TypeCode_ptr tcp,
                                      const char *name,
                                      char *buffer,
                                      size_t buflen,
                                      CORBA::Environment &env);
  // Make the TypeCode for a standard exception.  When used
  // correctly, initializing system exceptions is only an exercise
  // in CPU time; it allocates no new memory.

  static void init_standard_exceptions (CORBA::Environment &env);
  // Runtime initialization of all standard exception typecodes.
  // Called from CORBA::ORB::init ().

  enum
  {
    NUM_SYS_EXCEPTIONS = 26,
    // Number of exceptions (make sure to update correctly).

    TC_BUFLEN = 160
    // Preallocated tc buffer.
  };

  static CORBA::TypeCode_ptr sys_exceptions[NUM_SYS_EXCEPTIONS];

  static CORBA::ExceptionList system_exceptions;
};

#endif /* TAO_EXCEPTION_H */
