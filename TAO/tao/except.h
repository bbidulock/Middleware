// This may look like C, but it's really -*- C++ -*-

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    except.h
//
// = DESCRTION
//     This file defines way in which CORBA exceptions are reported.
//
// = AUTHOR
//     Copyright 1994-1995 by Sun Microsystems Inc.
//
// ============================================================================

#if !defined (TAO_EXCEPT_H)
#  define TAO_EXCEPT_H

class TAO_Export CORBA_Exception : public TAO_IUnknown
  // = TITLE
  //   CORBA2-specified exception hierarchy.
  //
  // = DESCRIPTION
  //   All exceptions have a type (represented by a TypeCode) and a
  //   widely scoped type ID (in the TypeCode) that generated by any
  //   OMG-IDL compiler and available through the Interface
  //   Repositories.  Think of it as a "globally scoped" name
  //   distinguishing each exception.
{
 public:
  CORBA_Exception (const CORBA_Exception &src);
  CORBA_Exception &operator = (const CORBA_Exception &src);

  // @@ All these inline methods should be split off into a *.i file.
  void *operator new (size_t, const void *p)
  { return (void *) p; }
  void *operator new (size_t s)
  { return ::operator new (s); }
  void operator delete (void *p)
  { ::operator delete (p); }

  const char *id (void) const;
  TAO_CONST CORBA::TypeCode_ptr type (void) const;

  // = To implement the narrow method.
  virtual int _is_a (const char* repository_id) const;

  // = Methods required for COM IUnknown support

  ULONG  AddRef (void);
  ULONG  Release (void);
  TAO_HRESULT  QueryInterface (REFIID riid,
                               void **ppv);

  CORBA_Exception (CORBA::TypeCode_ptr type);
  virtual ~CORBA_Exception (void);

 protected:
  CORBA::TypeCode_ptr type_;
  // Type of the Exception.

 private:
  u_int refcount_;
  // Reference count to avoid copying overhead.

  ACE_SYNCH_MUTEX lock_;
  // Serialize access to reference count.
};

class TAO_Export CORBA_UserException : public CORBA_Exception
  // = TITLE
  //   User exceptions are those defined by application developers
  //   using OMG-IDL.
{
public:
  CORBA_UserException (CORBA::TypeCode_ptr tc);
  ~CORBA_UserException (void);

  virtual int _is_a (const char* interface_id) const;
  static CORBA_UserException* _narrow (CORBA_Exception* exception);

protected:
  // Copy and assignment operators.
};

class TAO_Export CORBA_SystemException : public CORBA_Exception
  // = TITLE
  //   System exceptions are those defined in the CORBA spec; OMG-IDL
  //   defines these.
{
public:
  // 94-9-14 also sez:  public copy constructor
  // and assignment operator.

  CORBA_SystemException (CORBA::TypeCode_ptr tc,
			 CORBA::ULong code,
			 CORBA::CompletionStatus completed);

  ~CORBA_SystemException (void);

  CORBA::ULong minor (void) const { return _minor; }
  void minor (CORBA::ULong m) { _minor = m; }

  CORBA::CompletionStatus completion (void) const { return _completed; }

  void completion (CORBA::CompletionStatus c)
  { _completed = c; }

  virtual int _is_a (const char* type_id) const;
  static CORBA_SystemException * _narrow (CORBA_Exception* exception);

private:
  CORBA::ULong _minor;
  CORBA::CompletionStatus _completed;
};

// Declarations for all of the CORBA standard exceptions.
//
// XXX shouldn't have a default minor code, at least for code that's
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

#undef	TAO_SYSTEM_EXCEPTION

class TAO_Export CORBA_Environment
{
  // = TITLE
  // A CORBA_Environment is a way to automagically ensure that
  // exception data is freed -- the "var" class for Exceptions.  It
  // adds just a bit of convenience function support, helping classify
  // exceptions as well as reducing memory leakage.
public:
  CORBA_Environment (void) : _exception (0) { }
  ~CORBA_Environment (void) { clear (); }

  CORBA::Exception_ptr exception (void) const { return _exception; }
  // Return the exception.  Caller must call AddRef() in order to keep
  // the ptr.

  void exception (CORBA::Exception *ex)
    // Set the exception to <ex>, taking a reference on it.
  {
    if (ex != _exception)
      {
        clear ();
        _exception = ex;
        _exception->AddRef ();
      }
  }

  CORBA::ExceptionType exception_type (void) const;
  TAO_CONST CORBA::String exception_id (void) const;

  void clear (void)
  {
    if (_exception)
      {
	_exception->Release ();
	_exception = 0;	// XXX
      }
  }

  void print_exception (const char *info,
                        FILE *f=stdout) const;
  // print the exception to output determined by f

private:
  CORBA::Exception_ptr _exception;

  // = These are not provided.
  CORBA_Environment (const CORBA_Environment &src);
  CORBA_Environment &operator = (const CORBA_Environment &src);
};

#endif /* TAO_EXCEPT_H */
