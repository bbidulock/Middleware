// $Id$

// Copyright 1994-1995 by Sun Microsystems Inc.
// All Rights Reserved
//
// ORB:         Exception handling support
//
// THREADING NOTE:  calling thread handles mutual exclusion policy
// on all of these data structures.

#include "tao/corba.h"

#if !defined (__ACE_INLINE__)
# include "tao/Exception.i"
#endif /* __ACE_INLINE__ */

// Static initializers.

CORBA::ExceptionList *TAO_Exceptions::system_exceptions;

// TAO specific typecode
extern CORBA::TypeCode_ptr TC_completion_status;

void
CORBA_Environment::exception (CORBA::Exception *ex)
{
  if (ex != this->exception_)
    {
      this->clear ();
      this->exception_ = ex;
      this->exception_->_incr_refcnt ();
    }
}

CORBA_Environment::~CORBA_Environment (void)
{
  this->clear ();
}

void
CORBA_Environment::clear (void)
{
  if (this->exception_)
    this->exception_->_decr_refcnt ();

  this->exception_ = 0;
}

void
CORBA_Exception::operator delete (void *p)
{
  ::operator delete (p);
}

CORBA_Environment::CORBA_Environment (void)
  : exception_ (0)
{
}

void *
CORBA_Exception::operator new (size_t s)
{
  return ::operator new (s);
}

CORBA_Exception::CORBA_Exception (CORBA::TypeCode_ptr tc)
  : type_ (CORBA::TypeCode::_duplicate (tc)),
    refcount_ (0)
{
  assert (this->type_ != 0);
}

CORBA_Exception::CORBA_Exception (const CORBA_Exception &src)
  : type_ (CORBA::TypeCode::_duplicate (src.type_)),
    refcount_ (0)
{
  assert (this->type_ != 0);
}

// NOTE:  It's this code, not anything defined in a subclass, which
// is responsible for releasing any storage owned by the exception.
// It can do this because it's got the typecode.

CORBA_Exception::~CORBA_Exception (void)
{
  assert (this->refcount_ == 0);
  assert (this->type_ != 0);
}

CORBA_Exception &
CORBA_Exception::operator = (const CORBA_Exception &src)
{
  if (this->type_)
    CORBA::release (this->type_);
  this->type_ = CORBA::TypeCode::_duplicate (src.type_);
  assert (this->type_ != 0);

  return *this;
}

const char *
CORBA_Exception::_id (void) const
{
  CORBA::Environment env;

  if (this->type_)
    return this->type_->id (env);
  else
    return 0;
}

TAO_CONST CORBA::TypeCode_ptr
CORBA_Exception::_type (void) const
{
  return this->type_;
}

int
CORBA_Exception::_is_a (const char* repository_id) const
{
  return (ACE_OS::strcmp (repository_id, "IDL:CORBA/Exception:1.0")==0);
}

CORBA::ULong
CORBA_Exception::_incr_refcnt (void)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->refcount_lock_, 0);
  return ++this->refcount_;
}

CORBA::ULong
CORBA_Exception::_decr_refcnt (void)
{
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->refcount_lock_, 0);
    this->refcount_--;
    if (this->refcount_ != 0)
      return this->refcount_;

    // release the lock before destroying the object.
  }
  
  delete this;
  return 0;
}

// Avoid zillions of not-quite-inlined copies of utilities.

CORBA_UserException::CORBA_UserException (CORBA::TypeCode_ptr tc)
  : CORBA_Exception (tc)
{
}

CORBA_UserException::~CORBA_UserException (void)
{
}

CORBA_UserException &
CORBA_UserException::operator = (const CORBA_UserException &src)
{
  if (this->type_)
    CORBA::release (this->type_);
  this->type_ = CORBA::TypeCode::_duplicate (src.type_);
  assert (this->type_ != 0);

  return *this;
}

int
CORBA_UserException::_is_a (const char* interface_id) const
{
  return ACE_OS::strcmp (interface_id,
                         "IDL:CORBA/UserException:1.0") == 0
    || CORBA_Exception::_is_a (interface_id);
}

CORBA_UserException*
CORBA_UserException::_narrow (CORBA_Exception* exception)
{
  if (exception->_is_a ("IDL:CORBA/UserException:1.0"))
    return ACE_dynamic_cast (CORBA_UserException *, exception);
  return 0;
}

CORBA_SystemException::CORBA_SystemException (CORBA::TypeCode_ptr tc,
                                              CORBA::ULong code,
                                              CORBA::CompletionStatus completed)
  : CORBA_Exception (tc),
    minor_ (code),
    completed_ (completed)
{
}

CORBA_SystemException::CORBA_SystemException (const CORBA_SystemException &src)
  : CORBA_Exception (src),
    minor_ (src.minor_),
    completed_ (src.completed_)
{
}

CORBA_SystemException::~CORBA_SystemException (void)
{
}

CORBA_SystemException &
CORBA_SystemException::operator = (const CORBA_SystemException &src)
{
  if (this->type_)
    CORBA::release (this->type_);
  this->type_ = CORBA::TypeCode::_duplicate (src.type_);

  this->minor_ = src.minor_;
  this->completed_ = src.completed_;

  assert (this->type_ != 0);

  return *this;
}

int
CORBA_SystemException::_is_a (const char* interface_id) const
{
  return ACE_OS::strcmp (interface_id,
                         "IDL:CORBA/SystemException:1.0") == 0
    || CORBA_Exception::_is_a (interface_id);
}

CORBA_SystemException*
CORBA_SystemException::_narrow (CORBA_Exception* exception)
{
  if (exception->_is_a ("IDL:CORBA/SystemException:1.0"))
    return ACE_dynamic_cast (CORBA_SystemException*,exception);
  return 0;
}

// Note that "buffer" holds the (unscoped) name originally, and is
// then overwritten.

void
TAO_Exceptions::make_standard_typecode (CORBA::TypeCode_ptr &tcp,
                                       const char *name,
                                       char *buffer,
                                       size_t buflen,
                                       CORBA::Environment &env)
{
  // This function must only be called ONCE, and with a global lock
  // held!  The <CORBA::ORB_init> method is responsible for ensuring
  // this.
  static const char *minor = "minor";
  static const char *completion = "completion";

  // Create a CDR stream ... juggle the alignment here a bit, we know
  // it's good enough for the typecode.

  TAO_OutputCDR stream (buffer, buflen);

  // into CDR stream, stuff (in order):
  //    - byte order flag [4 bytes]
  //    - exception ID [27 + N bytes]
  //    - exception name [4 + N bytes ]
  //    - number of members (2) [4 bytes ]
  //    - foreach member, { name string, typecode } [~40 bytes]

  char full_id[100];
  char *strptr = full_id;

  (void) ACE_OS::sprintf (full_id,
                         "IDL:omg.org/CORBA/%s:1.0",
                         name);
  // @@ Should this really be an assert or should we deal with it via
  // exceptions?
  assert (ACE_OS::strlen (full_id) <= sizeof full_id);

  if (stream.write_octet (TAO_ENCAP_BYTE_ORDER) != CORBA::B_TRUE
      || stream.encode (CORBA::_tc_string,
                       &strptr, 0,
                       env) != CORBA::TypeCode::TRAVERSE_CONTINUE
      || stream.encode (CORBA::_tc_string,
                       &name, 0,
                       env) != CORBA::TypeCode::TRAVERSE_CONTINUE
      || stream.write_ulong (2L) != CORBA::B_TRUE
      || stream.encode (CORBA::_tc_string,
                       &minor, 0,
                       env) != CORBA::TypeCode::TRAVERSE_CONTINUE
      || stream.encode (CORBA::_tc_TypeCode,
                       &CORBA::_tc_ulong, 0,
                       env) != CORBA::TypeCode::TRAVERSE_CONTINUE
      || stream.encode (CORBA::_tc_string,
                       &completion, 0,
                       env) != CORBA::TypeCode::TRAVERSE_CONTINUE
      || stream.encode (CORBA::_tc_TypeCode,
                       &TC_completion_status, 0,
                       env) != CORBA::TypeCode::TRAVERSE_CONTINUE) {
    env.exception (new CORBA_INITIALIZE (CORBA::COMPLETED_NO));
    return;
  }

  // OK, we stuffed the buffer we were given (or grew a bigger one;
  // hope to avoid that during initialization).  Now build and return
  // a TypeCode, saving it away in the list of ones that the ORB will
  // always accept as part of any operation response!

  tcp = new CORBA::TypeCode (CORBA::tk_except,
                             stream.length (),
                             stream.buffer (),
                             CORBA::B_TRUE);
  
  TAO_Exceptions::system_exceptions->add (tcp);
  assert (tcp->length_ <= TAO_Exceptions::TC_BUFLEN);
  return;
}

// List of standard/system exceptions ... used to create static
// storage for their typecodes, then later to initialize that storage
// using the routine above. (It's just too painful to init these
// typecodes statically in all cases!)

#define STANDARD_EXCEPTION_LIST \
    TAO_SYSTEM_EXCEPTION (UNKNOWN) \
    TAO_SYSTEM_EXCEPTION (BAD_PARAM) \
    TAO_SYSTEM_EXCEPTION (NO_MEMORY) \
    TAO_SYSTEM_EXCEPTION (IMP_LIMIT) \
    TAO_SYSTEM_EXCEPTION (COMM_FAILURE) \
    TAO_SYSTEM_EXCEPTION (INV_OBJREF) \
    TAO_SYSTEM_EXCEPTION (OBJECT_NOT_EXIST) \
    TAO_SYSTEM_EXCEPTION (NO_PERMISSION) \
    TAO_SYSTEM_EXCEPTION (INTERNAL) \
    TAO_SYSTEM_EXCEPTION (MARSHAL) \
    TAO_SYSTEM_EXCEPTION (INITIALIZE) \
    TAO_SYSTEM_EXCEPTION (NO_IMPLEMENT) \
    TAO_SYSTEM_EXCEPTION (BAD_TYPECODE) \
    TAO_SYSTEM_EXCEPTION (BAD_OPERATION) \
    TAO_SYSTEM_EXCEPTION (NO_RESOURCES) \
    TAO_SYSTEM_EXCEPTION (NO_RESPONSE) \
    TAO_SYSTEM_EXCEPTION (PERSIST_STORE) \
    TAO_SYSTEM_EXCEPTION (BAD_INV_ORDER) \
    TAO_SYSTEM_EXCEPTION (TRANSIENT) \
    TAO_SYSTEM_EXCEPTION (FREE_MEM) \
    TAO_SYSTEM_EXCEPTION (INV_IDENT) \
    TAO_SYSTEM_EXCEPTION (INV_FLAG) \
    TAO_SYSTEM_EXCEPTION (INTF_REPOS) \
    TAO_SYSTEM_EXCEPTION (BAD_CONTEXT) \
    TAO_SYSTEM_EXCEPTION (OBJ_ADAPTER) \
    TAO_SYSTEM_EXCEPTION (DATA_CONVERSION)

// Declare static storage for these ... the buffer is "naturally"
// aligned and overwritten.
//
// @@ this actually doesn't guarantee "natural" alignment, but
// it works that way in most systems.

#define TAO_SYSTEM_EXCEPTION(name) \
    static CORBA::Long tc_buf_ ## name [TAO_Exceptions::TC_BUFLEN / sizeof (long)]; \
    CORBA::TypeCode_ptr CORBA::_tc_ ## name;
STANDARD_EXCEPTION_LIST
#undef  TAO_SYSTEM_EXCEPTION

//    static CORBA::TypeCode tc_std_ ## name (CORBA::tk_except);
//    CORBA::TypeCode_ptr CORBA::_tc_ ## name = &tc_std_ ## name;

void
TAO_Exceptions::init (CORBA::Environment &env)
{
  // Initialize the list of system exceptions, used when unmarshaling.
  ACE_NEW (TAO_Exceptions::system_exceptions,
           CORBA::ExceptionList);

#define TAO_SYSTEM_EXCEPTION(name) \
  if (env.exception () == 0) \
    TAO_Exceptions::make_standard_typecode (CORBA::_tc_ ## name, #name, \
                                           (char *) tc_buf_ ## name, \
                                           sizeof tc_buf_ ## name, env);
  STANDARD_EXCEPTION_LIST
#undef  TAO_SYSTEM_EXCEPTION

  // Register POA exceptions as system exceptions
  TAO_Exceptions::system_exceptions->add (PortableServer::_tc_ForwardRequest);
  TAO_Exceptions::system_exceptions->add (PortableServer::POAManager::_tc_AdapterInactive);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_AdapterAlreadyExists);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_AdapterInactive);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_AdapterNonExistent);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_InvalidPolicy);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_NoServant);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_ObjectAlreadyActive);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_ObjectNotActive);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_ServantAlreadyActive);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_ServantNotActive);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_WrongAdapter);
  TAO_Exceptions::system_exceptions->add (PortableServer::POA::_tc_WrongPolicy );
  TAO_Exceptions::system_exceptions->add (PortableServer::Current::_tc_NoContext);
}

void
TAO_Exceptions::fini (void)
{
  delete TAO_Exceptions::system_exceptions;
}

#define TAO_SYSTEM_EXCEPTION(name) \
int \
CORBA_##name ::_is_a (const char* interface_id) const \
{ \
  return ((ACE_OS::strcmp (interface_id, "IDL:CORBA/" #name "1.0")==0) \
          || CORBA_SystemException::_is_a (interface_id)); \
}
STANDARD_EXCEPTION_LIST
#undef TAO_SYSTEM_EXCEPTION

#define TAO_SYSTEM_EXCEPTION(name) \
CORBA_##name * \
CORBA_##name ::_narrow (CORBA_Exception* exception) \
{ \
  if (exception->_is_a ("IDL:CORBA/" #name "1.0")) \
    return ACE_dynamic_cast (CORBA_##name *, exception); \
  return 0; \
}
STANDARD_EXCEPTION_LIST
#undef TAO_SYSTEM_EXCEPTION

#undef  STANDARD_EXCEPTION_LIST

// Convenience -- say if the exception is a system exception or not.

CORBA::ExceptionType
CORBA::Environment::exception_type (void) const
{
  static char sysex_prefix [] = "IDL:omg.org/CORBA/";
  static char typecode_extra [] = "TypeCode/";
  static char poa_prefix [] = "IDL:PortableServer/";

  if (!this->exception_)
    return CORBA::NO_EXCEPTION;

  // All exceptions currently (CORBA 2.0) defined in the CORBA
  // scope are system exceptions ... except for a couple that
  // are related to TypeCodes.

  const char *id = this->exception_->_id ();

  if ((ACE_OS::strncmp (id, sysex_prefix, sizeof sysex_prefix - 1) == 0
       && ACE_OS::strncmp (id + sizeof sysex_prefix - 1,
                           typecode_extra, sizeof typecode_extra - 1) != 0)
      || ACE_OS::strncmp (id, poa_prefix, sizeof poa_prefix - 1) == 0)
    return CORBA::SYSTEM_EXCEPTION;
  
  return CORBA::USER_EXCEPTION;
}

// Diagnostic utility routine: describe the exception onto the
// standard I/O stream passed as a parameter.

void
CORBA::Environment::print_exception (const char *info,
                                     FILE *) const
{
  const char *id = this->exception_->_id ();

  ACE_DEBUG ((LM_ERROR, "(%P|%t) EXCEPTION, %s\n", info));

  // @@ get rid of this logic, and rely on some member function on
  // Exception to say if it's user or system exception.

  if (this->exception_type () == CORBA::SYSTEM_EXCEPTION)
    {
      CORBA::SystemException *x2 =
	CORBA_SystemException::_narrow (this->exception_);

      // @@ there are a other few "user exceptions" in the CORBA
      // scope, they're not all standard/system exceptions ... really
      // need to either compare exhaustively against all those IDs
      // (yeech) or (preferably) to represent the exception type
      // directly in the exception value so it can be queried.

      ACE_DEBUG ((LM_ERROR,
                  "(%P|%t) system exception, ID '%s'\n",
                  id));
      ACE_DEBUG ((LM_ERROR,
                  "(%P|%t) minor code = %x, completed = %s\n",
                  x2->minor (),
                  (x2->completion () == CORBA::COMPLETED_YES) ? "YES" :
                  (x2->completion () == CORBA::COMPLETED_NO) ? "NO" :
                  (x2->completion () == CORBA::COMPLETED_MAYBE) ? "MAYBE" :
                  "garbage"));
    }
  else
    // @@ we can use the exception's typecode to dump all the data
    // held within it ...

    ACE_DEBUG ((LM_ERROR,
                "(%P|%t) user exception, ID '%s'\n",
                id));
}

CORBA_ExceptionList::CORBA_ExceptionList (CORBA::ULong len,
                                          CORBA::TypeCode_ptr *tc_list)
{
  for (CORBA::ULong i=0; i < len; i++)
    this->add (tc_list [i]);
}

void
CORBA_ExceptionList::add (CORBA::TypeCode_ptr tc)
{
  this->tc_list_.enqueue_tail (CORBA::TypeCode::_duplicate (tc));
}

void
CORBA_ExceptionList::add_consume (CORBA::TypeCode_ptr tc)
{
  this->tc_list_.enqueue_tail (tc);
}

CORBA::TypeCode_ptr
CORBA_ExceptionList::item (CORBA::ULong index,
                           CORBA::Environment &env)
{
  CORBA::TypeCode_ptr *tc;
  env.clear ();
  if (this->tc_list_.get (tc, index) == -1)
    {
      env.exception (new CORBA::TypeCode::Bounds);
      return 0;
    }
  else
    {
      return CORBA::TypeCode::_duplicate (*tc);
    }
}
void
CORBA_ExceptionList::remove (CORBA::ULong index, CORBA::Environment &env)
{
  // unimplemented
  env.clear ();
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Node<CORBA::TypeCode_ptr>;
template class ACE_Unbounded_Queue<CORBA::TypeCode_ptr>;
template class ACE_Unbounded_Queue_Iterator<CORBA::TypeCode_ptr>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Node<CORBA::TypeCode_ptr>
#pragma instantiate ACE_Unbounded_Queue<CORBA::TypeCode_ptr>
#pragma instantiate ACE_Unbounded_Queue_Iterator<CORBA::TypeCode_ptr>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
