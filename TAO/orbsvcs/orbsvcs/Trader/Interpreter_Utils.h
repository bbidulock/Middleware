// -*- C++ -*-

//=============================================================================
/**
 * @file   Interpreter_Utils.h
 *
 * $Id$
 */
//=============================================================================

#ifndef TAO_INTERPRETER_UTILS_H
#define TAO_INTERPRETER_UTILS_H

#include /**/ "ace/pre.h"

#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"

#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/CORBA_String.h"
#include "tao/SystemException.h"

#include "orbsvcs/Trader/trading_serv_export.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// =  Classes to deal with the ACE_Hash_Map_Manager.

/**
 * Key for the Hash Table. The EXT_ID of the
 * ACE_Hash_Map_Manager.
 */
class TAO_Trading_Serv_Export TAO_String_Hash_Key : public CORBA::String_var
{
public:
  // = Initialization and termination methods.
  TAO_String_Hash_Key (void);
  // Default constructor.

  TAO_String_Hash_Key (char * name);
  // Constructor from a const string.

  TAO_String_Hash_Key (const char * name);
  // Constructor from a const string.

  TAO_String_Hash_Key (const CORBA::String_var &hash_key);
  // Copy constructor.

  bool operator == (const TAO_String_Hash_Key &hash_key) const;
  // The operator for hash binding and "find"ing.

  friend bool operator < (const TAO_String_Hash_Key &left,
                          const TAO_String_Hash_Key &right);
  // The operator for hash binding and "find"ing.

  u_long hash (void) const;
  // The function that computes a hash value.
};

#if defined ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT
  template class TAO_Trading_Serv_Export TAO::String_var <char>;
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT */

typedef ACE_Hash_Map_Manager_Ex<TAO_String_Hash_Key,
                                int,
                                ACE_Hash<TAO_String_Hash_Key>,
                                ACE_Equal_To<TAO_String_Hash_Key>,
                                ACE_Null_Mutex>
  TAO_Lookup_Table;
typedef ACE_Hash_Map_Manager_Ex<TAO_String_Hash_Key,
                                CORBA::TypeCode_ptr,
                                ACE_Hash<TAO_String_Hash_Key>,
                                ACE_Equal_To<TAO_String_Hash_Key>,
                                ACE_Null_Mutex>
  TAO_Typecode_Table;


// *************************************************************
// TAO_Sequence_Extracter_Base
// *************************************************************

class TAO_Sequence_Extracter_Base
// = TITLE
//   Static methods used by the TAO_Sequence_Extracter class.
{
public:

  static CORBA::TCKind sequence_type (CORBA::TypeCode* code
                                      ACE_ENV_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException));
  // Return the sequence element type for the sequence whose typecode
  // is <code>.
};

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* TAO_INTERPRETER_UTILS_H */
