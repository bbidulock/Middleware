/* -*- C++ -*- */
//
// $Id$

//
// ================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   PollableS.cpp
//
// = DESCRIPTION
//   Generated from Pollable.pidl
//   The code was generated by the IDL compiler and then hand-crafted
//   to reduce the includes interdependencies.
//
// ================================================================

#include "tao/PollableS.h"

#if (TAO_HAS_CORBA_MESSAGING == 1) && (TAO_HAS_AMI_POLLER == 1)

#include "tao/Operation_Table.h"
#include "tao/Server_Request.h"
#include "tao/ORB.h"
#if !defined (__ACE_INLINE__)
#include "tao/PollableS.i"
#endif /* !defined INLINE */

ACE_RCSID(tao, PollableS, "$Id$")

<<<<<<< PollableS.cpp
ACE_RCSID(tao, PollableS, "$Id$")
=======
>>>>>>> 1.9.2.2

class TAO_CORBA_Pollable_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 15:37:47 */
/* C++ code produced by gperf version 2.7 (GNU C++ version) */
/* Command-line: /project/macarena/coryan/head/ACE_wrappers/bin/gperf -m -M -J -c -C -D -E -T -f 0 -a -o -t -p -K opname_ -L C++ -Z TAO_CORBA_Pollable_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CORBA_Pollable_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20,  0, 20,  0, 20,  0,
     20, 20, 20, 20, 20,  0, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20,  0, 20, 20, 20,
     20,  0, 20, 20, 20, 20, 20, 20,
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_CORBA_Pollable_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 4,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 19,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 19,
      HASH_VALUE_RANGE = 15,
      DUPLICATES = 0
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
      {"_is_a",  &POA_CORBA::Pollable::_is_a_skel},
      {"",0}, {"",0},
      {"is_ready",      &POA_CORBA::Pollable::is_ready_skel},
      {"",0}, {"",0}, {"",0}, {"",0},
      {"_non_existent",  &POA_CORBA::Pollable::_non_existent_skel},
      {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
      {"create_pollable_set",   &POA_CORBA::Pollable::create_pollable_set_skel},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname_;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}
/* ending time is 15:37:47 */
TAO_CORBA_Pollable_Perfect_Hash_OpTable tao_CORBA_Pollable_optable;
// skeleton constructor
POA_CORBA::Pollable::Pollable (void)
{
  this->optable_ = &tao_CORBA_Pollable_optable;
}

// copy ctor
POA_CORBA::Pollable::Pollable (const Pollable& rhs)
  :   TAO_ServantBase (rhs)
{}
// skeleton destructor
POA_CORBA::Pollable::~Pollable (void)
{
}
void POA_CORBA::Pollable::is_ready_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA::Pollable *_tao_impl = (POA_CORBA::Pollable *)_tao_object_reference;
  CORBA::Boolean _tao_retval = 0;
  CORBA::ULong timeout;
  if (!(
    (_tao_in >> timeout)
  ))
    ACE_THROW (CORBA::MARSHAL () );

  _tao_retval = _tao_impl->is_ready (
    timeout,
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << CORBA::Any::from_boolean (_tao_retval))
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::Pollable::create_pollable_set_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::Pollable *_tao_impl = (POA_CORBA::Pollable *)_tao_object_reference;
  CORBA::PollableSet_var _tao_retval;
  _tao_retval = _tao_impl->create_pollable_set (
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << _tao_retval.in ())
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::Pollable::_is_a_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /*context*/,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  static const TAO_Param_Data_Skel CORBA_Pollable_is_a_paramdata [] =
  {
    {CORBA::_tc_boolean, 0, 0},
    {CORBA::_tc_string, CORBA::ARG_IN, 0}
  };
  static const TAO_Call_Data_Skel CORBA_Pollable_is_a_calldata =
  {"_is_a", 1, 2, CORBA_Pollable_is_a_paramdata};
  POA_CORBA::Pollable_ptr  _tao_impl = (POA_CORBA::Pollable_ptr) _tao_object_reference;
  CORBA::Boolean _tao_retval;
  CORBA::String_var _tao_value;
  _tao_server_request.demarshal (
    ACE_TRY_ENV,
    &CORBA_Pollable_is_a_calldata,
    &_tao_retval,
    &_tao_value.inout ()
  );
  ACE_CHECK;
  _tao_retval = _tao_impl->_is_a (_tao_value.in (), ACE_TRY_ENV);
  ACE_CHECK;
  _tao_server_request.marshal (
    ACE_TRY_ENV,
    &CORBA_Pollable_is_a_calldata,
    &_tao_retval,
    &_tao_value.inout ()
  );
}

CORBA::Boolean POA_CORBA::Pollable::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Pollable:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void POA_CORBA::Pollable::_non_existent_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * /* _tao_object_reference */ ,
    void * /*context*/,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  static const TAO_Param_Data_Skel CORBA_Pollable_non_existent_paramdata [] =
  {
    {CORBA::_tc_boolean, 0, 0}
  };
  static const TAO_Call_Data_Skel CORBA_Pollable_non_existent_calldata =
  {"_non_existent", 1, 1, CORBA_Pollable_non_existent_paramdata};
  CORBA::Boolean _tao_retval = 0;
  _tao_server_request.marshal (
    ACE_TRY_ENV,
    &CORBA_Pollable_non_existent_calldata,
    &_tao_retval
  );
}

void* POA_CORBA::Pollable::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Pollable:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Pollable_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

void POA_CORBA::Pollable::_dispatch (CORBA::ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  TAO_Skeleton skel; // pointer to skeleton for operation
  const char *opname = req.operation (); // retrieve operation name
  // find the skeleton corresponding to this opname
  if (this->_find (opname, skel) == -1)
  {
    ACE_ERROR ((LM_ERROR, "Bad operation <%s>\n", opname));
    ACE_THROW (CORBA_BAD_OPERATION ());
  }
  else
    skel (req, this, context, ACE_TRY_ENV);
}

const char* POA_CORBA::Pollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Pollable:1.0";
}

POA_CORBA::_tao_collocated_Pollable::_tao_collocated_Pollable (
    POA_CORBA::Pollable_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_CORBA_1 (Pollable) (),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::Pollable_ptr POA_CORBA::_tao_collocated_Pollable::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_CORBA::_tao_collocated_Pollable::_is_a (
    const char* logical_type_id,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      ACE_TRY_ENV
    );
}

CORBA::Boolean POA_CORBA::_tao_collocated_Pollable::is_ready  (
    CORBA::ULong timeout,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->is_ready (
    timeout,
    ACE_TRY_ENV
  );
}

CORBA::PollableSet_ptr POA_CORBA::_tao_collocated_Pollable::create_pollable_set  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->create_pollable_set (
    ACE_TRY_ENV
  );
}


CORBA::Pollable*
POA_CORBA::Pollable::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  CORBA::Pollable *retval = CORBA::Pollable::_nil ();

  ACE_NEW_RETURN (retval,
                  POA_CORBA::_tao_collocated_Pollable (this,
                                                       stub),
                  CORBA::Pollable::_nil ());

  return retval;
}

class TAO_CORBA_DIIPollable_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 15:37:47 */
/* C++ code produced by gperf version 2.7 (GNU C++ version) */
/* Command-line: /project/macarena/coryan/head/ACE_wrappers/bin/gperf -m -M -J -c -C -D -E -T -f 0 -a -o -t -p -K opname_ -L C++ -Z TAO_CORBA_DIIPollable_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CORBA_DIIPollable_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20,  0, 20,  0, 20,  0,
     20, 20, 20, 20, 20,  0, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20,  0, 20, 20, 20,
     20,  0, 20, 20, 20, 20, 20, 20,
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_CORBA_DIIPollable_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 4,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 19,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 19,
      HASH_VALUE_RANGE = 15,
      DUPLICATES = 0
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
      {"_is_a",  &POA_CORBA::DIIPollable::_is_a_skel},
      {"",0}, {"",0},
      {"is_ready",      &POA_CORBA::DIIPollable::is_ready_skel},
      {"",0}, {"",0}, {"",0}, {"",0},
      {"_non_existent",  &POA_CORBA::DIIPollable::_non_existent_skel},
      {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
      {"create_pollable_set",   &POA_CORBA::DIIPollable::create_pollable_set_skel},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname_;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}
/* ending time is 15:37:47 */
TAO_CORBA_DIIPollable_Perfect_Hash_OpTable tao_CORBA_DIIPollable_optable;
// skeleton constructor
POA_CORBA::DIIPollable::DIIPollable (void)
{
  this->optable_ = &tao_CORBA_DIIPollable_optable;
}

// copy ctor
POA_CORBA::DIIPollable::DIIPollable (const DIIPollable& rhs)
  :   ACE_NESTED_CLASS (POA_CORBA,Pollable) (rhs),
    TAO_ServantBase (rhs)
{}
// skeleton destructor
POA_CORBA::DIIPollable::~DIIPollable (void)
{
}
void POA_CORBA::DIIPollable::_is_a_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /*context*/,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  static const TAO_Param_Data_Skel CORBA_DIIPollable_is_a_paramdata [] =
  {
    {CORBA::_tc_boolean, 0, 0},
    {CORBA::_tc_string, CORBA::ARG_IN, 0}
  };
  static const TAO_Call_Data_Skel CORBA_DIIPollable_is_a_calldata =
  {"_is_a", 1, 2, CORBA_DIIPollable_is_a_paramdata};
  POA_CORBA::DIIPollable_ptr  _tao_impl = (POA_CORBA::DIIPollable_ptr) _tao_object_reference;
  CORBA::Boolean _tao_retval;
  CORBA::String_var _tao_value;
  _tao_server_request.demarshal (
    ACE_TRY_ENV,
    &CORBA_DIIPollable_is_a_calldata,
    &_tao_retval,
    &_tao_value.inout ()
  );
  ACE_CHECK;
  _tao_retval = _tao_impl->_is_a (_tao_value.in (), ACE_TRY_ENV);
  ACE_CHECK;
  _tao_server_request.marshal (
    ACE_TRY_ENV,
    &CORBA_DIIPollable_is_a_calldata,
    &_tao_retval,
    &_tao_value.inout ()
  );
}

CORBA::Boolean POA_CORBA::DIIPollable::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/DIIPollable:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Pollable:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void POA_CORBA::DIIPollable::_non_existent_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * /* _tao_object_reference */ ,
    void * /*context*/,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  static const TAO_Param_Data_Skel CORBA_DIIPollable_non_existent_paramdata [] =
  {
    {CORBA::_tc_boolean, 0, 0}
  };
  static const TAO_Call_Data_Skel CORBA_DIIPollable_non_existent_calldata =
  {"_non_existent", 1, 1, CORBA_DIIPollable_non_existent_paramdata};
  CORBA::Boolean _tao_retval = 0;
  _tao_server_request.marshal (
    ACE_TRY_ENV,
    &CORBA_DIIPollable_non_existent_calldata,
    &_tao_retval
  );
}

void* POA_CORBA::DIIPollable::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/DIIPollable:1.0") == 0)
    return ACE_static_cast (POA_CORBA::DIIPollable_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Pollable:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Pollable_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

void POA_CORBA::DIIPollable::_dispatch (CORBA::ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  TAO_Skeleton skel; // pointer to skeleton for operation
  const char *opname = req.operation (); // retrieve operation name
  // find the skeleton corresponding to this opname
  if (this->_find (opname, skel) == -1)
  {
    ACE_ERROR ((LM_ERROR, "Bad operation <%s>\n", opname));
    ACE_THROW (CORBA_BAD_OPERATION ());
  }
  else
    skel (req, this, context, ACE_TRY_ENV);
}

const char* POA_CORBA::DIIPollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/DIIPollable:1.0";
}

POA_CORBA::_tao_collocated_DIIPollable::_tao_collocated_DIIPollable (
    POA_CORBA::DIIPollable_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_CORBA_1 (DIIPollable) (),
    ACE_NESTED_CLASS (POA_CORBA,_tao_collocated_Pollable) (servant, stub),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::DIIPollable_ptr POA_CORBA::_tao_collocated_DIIPollable::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_CORBA::_tao_collocated_DIIPollable::_is_a (
    const char* logical_type_id,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      ACE_TRY_ENV
    );
}


CORBA::DIIPollable*
POA_CORBA::DIIPollable::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  CORBA::DIIPollable *retval = CORBA::DIIPollable::_nil ();

  ACE_NEW_RETURN (retval,
                  POA_CORBA::_tao_collocated_DIIPollable (this,
                                                          stub),
                  CORBA::DIIPollable::_nil ());

  return retval;
}

class TAO_CORBA_PollableSet_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 15:37:47 */
/* C++ code produced by gperf version 2.7 (GNU C++ version) */
/* Command-line: /project/macarena/coryan/head/ACE_wrappers/bin/gperf -m -M -J -c -C -D -E -T -f 0 -a -o -t -p -K opname_ -L C++ -Z TAO_CORBA_PollableSet_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CORBA_PollableSet_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
     20, 20, 20, 20, 20,  0, 20,  0, 20,  0,
     20,  0, 20, 20, 20, 20, 20, 20,  0, 20,
      0, 20,  0, 20,  0, 20,  0, 20, 20, 20,
     20, 20, 20, 20, 20, 20, 20, 20,
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_CORBA_PollableSet_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 7,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 19,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 19,
      HASH_VALUE_RANGE = 16,
      DUPLICATES = 0
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0}, {"",0}, {"",0}, {"",0},
      {"poll",  &POA_CORBA::PollableSet::poll_skel},
      {"_is_a",  &POA_CORBA::PollableSet::_is_a_skel},
      {"remove",        &POA_CORBA::PollableSet::remove_skel},
      {"",0}, {"",0}, {"",0}, {"",0},
      {"number_left",   &POA_CORBA::PollableSet::number_left_skel},
      {"add_pollable",  &POA_CORBA::PollableSet::add_pollable_skel},
      {"_non_existent",  &POA_CORBA::PollableSet::_non_existent_skel},
      {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
      {"create_dii_pollable",   &POA_CORBA::PollableSet::create_dii_pollable_skel},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname_;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}
/* ending time is 15:37:47 */
TAO_CORBA_PollableSet_Perfect_Hash_OpTable tao_CORBA_PollableSet_optable;
// skeleton constructor
POA_CORBA::PollableSet::PollableSet (void)
{
  this->optable_ = &tao_CORBA_PollableSet_optable;
}

// copy ctor
POA_CORBA::PollableSet::PollableSet (const PollableSet& rhs)
  :   TAO_ServantBase (rhs)
{}
// skeleton destructor
POA_CORBA::PollableSet::~PollableSet (void)
{
}
void POA_CORBA::PollableSet::create_dii_pollable_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::PollableSet *_tao_impl = (POA_CORBA::PollableSet *)_tao_object_reference;
  CORBA::DIIPollable_var _tao_retval;
  _tao_retval = _tao_impl->create_dii_pollable (
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << _tao_retval.in ())
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::PollableSet::add_pollable_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA::PollableSet *_tao_impl = (POA_CORBA::PollableSet *)_tao_object_reference;
  CORBA::Pollable_var potential;
  if (!(
    (_tao_in >> potential.out ())
  ))
    ACE_THROW (CORBA::MARSHAL () );

  _tao_impl->add_pollable (
    potential.in (),
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
}

void POA_CORBA::PollableSet::poll_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA::PollableSet *_tao_impl = (POA_CORBA::PollableSet *)_tao_object_reference;
  CORBA::Pollable_var _tao_retval;
  CORBA::ULong timeout;
  if (!(
    (_tao_in >> timeout)
  ))
    ACE_THROW (CORBA::MARSHAL () );

  _tao_retval = _tao_impl->poll (
    timeout,
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << _tao_retval.in ())
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::PollableSet::remove_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA::PollableSet *_tao_impl = (POA_CORBA::PollableSet *)_tao_object_reference;
  CORBA::Pollable_var potential;
  if (!(
    (_tao_in >> potential.out ())
  ))
    ACE_THROW (CORBA::MARSHAL () );

  _tao_impl->remove (
    potential.in (),
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
}

void POA_CORBA::PollableSet::number_left_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::PollableSet *_tao_impl = (POA_CORBA::PollableSet *)_tao_object_reference;
  CORBA::UShort _tao_retval = 0;
  _tao_retval = _tao_impl->number_left (
    ACE_TRY_ENV
  );
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << _tao_retval)
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::PollableSet::_is_a_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /*context*/,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  static const TAO_Param_Data_Skel CORBA_PollableSet_is_a_paramdata [] =
  {
    {CORBA::_tc_boolean, 0, 0},
    {CORBA::_tc_string, CORBA::ARG_IN, 0}
  };
  static const TAO_Call_Data_Skel CORBA_PollableSet_is_a_calldata =
  {"_is_a", 1, 2, CORBA_PollableSet_is_a_paramdata};
  POA_CORBA::PollableSet_ptr  _tao_impl = (POA_CORBA::PollableSet_ptr) _tao_object_reference;
  CORBA::Boolean _tao_retval;
  CORBA::String_var _tao_value;
  _tao_server_request.demarshal (
    ACE_TRY_ENV,
    &CORBA_PollableSet_is_a_calldata,
    &_tao_retval,
    &_tao_value.inout ()
  );
  ACE_CHECK;
  _tao_retval = _tao_impl->_is_a (_tao_value.in (), ACE_TRY_ENV);
  ACE_CHECK;
  _tao_server_request.marshal (
    ACE_TRY_ENV,
    &CORBA_PollableSet_is_a_calldata,
    &_tao_retval,
    &_tao_value.inout ()
  );
}

CORBA::Boolean POA_CORBA::PollableSet::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/PollableSet:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void POA_CORBA::PollableSet::_non_existent_skel (
    CORBA::ServerRequest &_tao_server_request,
    void * /* _tao_object_reference */ ,
    void * /*context*/,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  static const TAO_Param_Data_Skel CORBA_PollableSet_non_existent_paramdata [] =
  {
    {CORBA::_tc_boolean, 0, 0}
  };
  static const TAO_Call_Data_Skel CORBA_PollableSet_non_existent_calldata =
  {"_non_existent", 1, 1, CORBA_PollableSet_non_existent_paramdata};
  CORBA::Boolean _tao_retval = 0;
  _tao_server_request.marshal (
    ACE_TRY_ENV,
    &CORBA_PollableSet_non_existent_calldata,
    &_tao_retval
  );
}

void* POA_CORBA::PollableSet::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/PollableSet:1.0") == 0)
    return ACE_static_cast (POA_CORBA::PollableSet_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

void POA_CORBA::PollableSet::_dispatch (CORBA::ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  TAO_Skeleton skel; // pointer to skeleton for operation
  const char *opname = req.operation (); // retrieve operation name
  // find the skeleton corresponding to this opname
  if (this->_find (opname, skel) == -1)
  {
    ACE_ERROR ((LM_ERROR, "Bad operation <%s>\n", opname));
    ACE_THROW (CORBA_BAD_OPERATION ());
  }
  else
    skel (req, this, context, ACE_TRY_ENV);
}

const char* POA_CORBA::PollableSet::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PollableSet:1.0";
}

POA_CORBA::_tao_collocated_PollableSet::_tao_collocated_PollableSet (
    POA_CORBA::PollableSet_ptr  servant,
    TAO_Stub *stub
  )
  : ACE_CORBA_1 (PollableSet) (),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

POA_CORBA::PollableSet_ptr POA_CORBA::_tao_collocated_PollableSet::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean POA_CORBA::_tao_collocated_PollableSet::_is_a (
    const char* logical_type_id,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->_is_a (
      logical_type_id,
      ACE_TRY_ENV
    );
}

CORBA::DIIPollable_ptr POA_CORBA::_tao_collocated_PollableSet::create_dii_pollable  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->create_dii_pollable (
    ACE_TRY_ENV
  );
}

void POA_CORBA::_tao_collocated_PollableSet::add_pollable  (
    CORBA::Pollable_ptr potential,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  this->servant_->add_pollable (
    potential,
    ACE_TRY_ENV
  );
}

CORBA::Pollable_ptr POA_CORBA::_tao_collocated_PollableSet::poll  (
    CORBA::ULong timeout,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->poll (
    timeout,
    ACE_TRY_ENV
  );
}

void POA_CORBA::_tao_collocated_PollableSet::remove  (
    CORBA::Pollable_ptr potential,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  this->servant_->remove (
    potential,
    ACE_TRY_ENV
  );
}

CORBA::UShort POA_CORBA::_tao_collocated_PollableSet::number_left  (
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return this->servant_->number_left (
    ACE_TRY_ENV
  );
}


CORBA::PollableSet*
POA_CORBA::PollableSet::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  CORBA::PollableSet *retval = CORBA::PollableSet::_nil ();

  ACE_NEW_RETURN (retval,
                  POA_CORBA::_tao_collocated_PollableSet (this,
                                                          stub),
                  CORBA::PollableSet::_nil ());

  return retval;
}
#endif /* TAO_HAS_CORBA_MESSAGING == 1 && TAO_HAS_AMI_POLLER == 1 */
