/* -*- C++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    POA_CORBA.h
//
//    This file is created by merging the PolicyS.h and CurrentS.h files which
//    have been removed.
//
// = AUTHOR
//
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html
//
//
// Modified by Aniruddha Gokhale.
//
// ============================================================================

#ifndef TAO_IDL_POA_CORBA_H
#define TAO_IDL_POA_CORBA_H

#include "PolicyC.h"
#include "CurrentC.h"
#include "DynAnyC.h"

class TAO_Export  POA_CORBA
{
public:
  class Policy;
  typedef Policy *Policy_ptr;
  class TAO_Export  Policy :  public virtual TAO_ServantBase
  {
  protected:
    Policy (void);
  public:
    virtual ~Policy (void);
    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ());
    virtual void* _downcast (
        const char* logical_type_id
      );
    virtual CORBA::PolicyType policy_type (
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
       ) = 0;
    static void _get_policy_type_skel (
        CORBA::ServerRequest &_tao_req,
        void *_tao_obj,
        void *_tao_context,
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
      );

    virtual CORBA::Policy_ptr copy (
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
       ) = 0;
    static void copy_skel (
        CORBA::ServerRequest &_tao_req,
        void *_tao_obj,
        void *_tao_context,
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
      );

    virtual void destroy (
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
       ) = 0;
    static void destroy_skel (
        CORBA::ServerRequest &_tao_req,
        void *_tao_obj,
        void *_tao_context,
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
      );

    static void _is_a_skel (CORBA::ServerRequest &req, void *obj, void *context, CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ());

    virtual void _dispatch (CORBA::ServerRequest &_tao_req, void *_tao_context, CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ());

    ACE_CORBA_1(Policy) *_this (CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ());
    virtual const char* _interface_repository_id (void) const;
  };


#if !defined (_CORBA_POLICY___COLLOCATED_SH_)
#define _CORBA_POLICY___COLLOCATED_SH_

  class TAO_Export  _tao_collocated_Policy     : public virtual CORBA_Policy
  {
  public:
    _tao_collocated_Policy (
        Policy_ptr  servant,
        STUB_Object *stub
      );
    Policy_ptr _get_servant (void) const;
    virtual CORBA::Boolean _is_a (
        const char *logical_type_id,
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
      );
    virtual CORBA::PolicyType policy_type (
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
       );
    virtual CORBA::Policy_ptr copy (
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
       );
    virtual void destroy (
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
       );

  private:
    Policy_ptr servant_;
  };


#endif /* end #if !defined */



#if defined(_MSC_VER)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

  class Current;
  typedef Current *Current_ptr;
  class  Current :  public virtual TAO_ServantBase
  {
  protected:
    Current (void);
  public:
    virtual ~Current (void);
    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ());
    virtual void* _downcast (
        const char* logical_type_id
      );
    static void _is_a_skel (CORBA::ServerRequest &req, void *obj, void *context, CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ());

    virtual void _dispatch (CORBA::ServerRequest &_tao_req, void *_tao_context, CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ());

    ACE_CORBA_1(Current) *_this (CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ());
    virtual const char* _interface_repository_id (void) const;
  };


#if !defined (_CORBA_CURRENT___COLLOCATED_SH_)
#define _CORBA_CURRENT___COLLOCATED_SH_

  class  _tao_collocated_Current     : public virtual CORBA_Current
  {
  public:
    _tao_collocated_Current (
        Current_ptr  servant,
        STUB_Object *stub
      );
    Current_ptr _get_servant (void) const;
    virtual CORBA::Boolean _is_a (
        const char *logical_type_id,
        CORBA_Environment &TAO_IN_ENV = CORBA_Environment::default_environment ()
      );

  private:
    Current_ptr servant_;
  };


#endif /* end #if !defined */


class DynAny;
typedef DynAny *DynAny_ptr;
class TAO_Export DynAny : public virtual TAO_Local_ServantBase
{
protected:
  DynAny (void);
public:
  DynAny (DynAny& rhs);
  virtual ~DynAny (void);
  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual void* _downcast (
      const char* logical_type_id
    );
  virtual CORBA::TypeCode_ptr type (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual void assign (
      CORBA_DynAny_ptr dyn_any,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual void from_any (
      const CORBA::Any & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual CORBA::Any * to_any (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual void destroy (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual CORBA_DynAny_ptr copy (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual void insert_boolean (
      CORBA::Boolean value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual void insert_octet (
      CORBA::Octet value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_char (
      CORBA::Char value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_short (
      CORBA::Short value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_ushort (
      CORBA::UShort value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_long (
      CORBA::Long value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_ulong (
      CORBA::ULong value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_float (
      CORBA::Float value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_double (
      CORBA::Double value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_string (
      const char * value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_reference (
      CORBA::Object_ptr value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_typecode (
      CORBA::TypeCode_ptr value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_longlong (
      CORBA::LongLong value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_ulonglong (
      CORBA::ULongLong value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_wchar (
      CORBA::WChar value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void insert_any (
      const CORBA::Any & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::Boolean get_boolean (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual CORBA::Octet get_octet (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::Char get_char (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::Short get_short (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::UShort get_ushort (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::Long get_long (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::ULong get_ulong (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::Float get_float (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::Double get_double (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual char * get_string (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::Object_ptr get_reference (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::TypeCode_ptr get_typecode (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::LongLong get_longlong (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::ULongLong get_ulonglong (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::WChar get_wchar (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::Any * get_any (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA_DynAny_ptr current_component (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual CORBA::Boolean next (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual CORBA::Boolean seek (
      CORBA::Long index,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual void rewind (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
        ) = 0;

  virtual void _dispatch (
      CORBA::ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &_tao_env =
        CORBA::Environment::default_environment ()
    );

  CORBA_DynAny *_this (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
};


#if !defined (_CORBA_DYNANY___COLLOCATED_SH_)
#define _CORBA_DYNANY___COLLOCATED_SH_

class  _tao_collocated_DynAny : public virtual CORBA_DynAny
{
public:
  _tao_collocated_DynAny (
      DynAny_ptr  servant,
      STUB_Object *stub
    );
  DynAny_ptr _get_servant (void) const;
  virtual CORBA::Boolean _is_a (
      const char *logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual CORBA::TypeCode_ptr type (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void assign (
      CORBA_DynAny_ptr CORBA_Dyn_any,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void from_any (
      const CORBA::Any & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Any * to_any (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void destroy (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA_DynAny_ptr copy (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_boolean (
      CORBA::Boolean value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_octet (
      CORBA::Octet value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_char (
      CORBA::Char value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_short (
      CORBA::Short value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_ushort (
      CORBA::UShort value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_long (
      CORBA::Long value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_ulong (
      CORBA::ULong value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_float (
      CORBA::Float value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_double (
      CORBA::Double value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_string (
      const char * value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_reference (
      CORBA::Object_ptr value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_typecode (
      CORBA::TypeCode_ptr value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_longlong (
      CORBA::LongLong value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_ulonglong (
      CORBA::ULongLong value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_wchar (
      CORBA::WChar value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void insert_any (
      const CORBA::Any & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Boolean get_boolean (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Octet get_octet (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Char get_char (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Short get_short (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::UShort get_ushort (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Long get_long (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::ULong get_ulong (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Float get_float (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Double get_double (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual char * get_string (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Object_ptr get_reference (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::TypeCode_ptr get_typecode (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::LongLong get_longlong (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::ULongLong get_ulonglong (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::WChar get_wchar (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Any * get_any (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA_DynAny_ptr current_component (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Boolean next (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::Boolean seek (
      CORBA::Long index,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void rewind (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );

private:
  DynAny_ptr servant_;
};


#endif /* end #if !defined */



class DynEnum;
typedef DynEnum *DynEnum_ptr;
class TAO_Export DynEnum : public virtual DynAny
{
protected:
  DynEnum (void);
public:
  DynEnum (DynEnum& rhs);
  virtual ~DynEnum (void);
  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual void* _downcast (
      const char* logical_type_id
    );
  virtual char * value_as_string (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void value_as_string (
      const char * value_as_string,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::ULong value_as_ulong (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void value_as_ulong (
      CORBA::ULong value_as_ulong,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void _dispatch (
      CORBA::ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &_tao_env =
        CORBA::Environment::default_environment ()
    );

  CORBA_DynEnum *_this (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
};


#if !defined (_CORBA_DYNENUM___COLLOCATED_SH_)
#define _CORBA_DYNENUM___COLLOCATED_SH_

class  _tao_collocated_DynEnum : public virtual CORBA_DynEnum,
    public virtual _tao_collocated_DynAny
{
public:
  _tao_collocated_DynEnum (
      DynEnum_ptr  servant,
      STUB_Object *stub
    );
  DynEnum_ptr _get_servant (void) const;
  virtual CORBA::Boolean _is_a (
      const char *logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual char * value_as_string (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void value_as_string (
      const char * value_as_string,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::ULong value_as_ulong (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void value_as_ulong (
      CORBA::ULong value_as_ulong,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );

private:
  DynEnum_ptr servant_;
};


#endif /* end #if !defined */


class DynStruct;
typedef DynStruct *DynStruct_ptr;
class TAO_Export DynStruct : public virtual DynAny
{
protected:
  DynStruct (void);
public:
  DynStruct (DynStruct& rhs);
  virtual ~DynStruct (void);
  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual void* _downcast (
      const char* logical_type_id
    );
  virtual char * current_member_name (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::TCKind current_member_kind (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual NameValuePairSeq * get_members (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void set_members (
      const NameValuePairSeq & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void _dispatch (
      CORBA::ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &_tao_env =
        CORBA::Environment::default_environment ()
    );

  CORBA_DynStruct *_this (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
};


#if !defined (_CORBA_DYNSTRUCT___COLLOCATED_SH_)
#define _CORBA_DYNSTRUCT___COLLOCATED_SH_

class  _tao_collocated_DynStruct : public virtual CORBA_DynStruct,
    public virtual _tao_collocated_DynAny
{
public:
  _tao_collocated_DynStruct (
      DynStruct_ptr  servant,
      STUB_Object *stub
    );
  DynStruct_ptr _get_servant (void) const;
  virtual CORBA::Boolean _is_a (
      const char *logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual char * current_member_name (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::TCKind current_member_kind (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual NameValuePairSeq * get_members (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void set_members (
      const NameValuePairSeq & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );

private:
  DynStruct_ptr servant_;
};


#endif /* end #if !defined */


class DynUnion;
typedef DynUnion *DynUnion_ptr;
class TAO_Export DynUnion : public virtual DynAny
{
protected:
  DynUnion (void);
public:
  DynUnion (DynUnion& rhs);
  virtual ~DynUnion (void);
  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual void* _downcast (
      const char* logical_type_id
    );
  virtual CORBA::Boolean set_as_default (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void set_as_default (
      CORBA::Boolean set_as_default,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA_DynAny_ptr discriminator (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::TCKind discriminator_kind (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA_DynAny_ptr member (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual char * member_name (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void member_name (
      const char * member_name,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual CORBA::TCKind member_kind (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void _dispatch (
      CORBA::ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &_tao_env =
        CORBA::Environment::default_environment ()
    );

  CORBA_DynUnion *_this (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
};


#if !defined (_CORBA_DYNUNION___COLLOCATED_SH_)
#define _CORBA_DYNUNION___COLLOCATED_SH_

class  _tao_collocated_DynUnion : public virtual CORBA_DynUnion,
    public virtual _tao_collocated_DynAny
{
public:
  _tao_collocated_DynUnion (
      DynUnion_ptr  servant,
      STUB_Object *stub
    );
  DynUnion_ptr _get_servant (void) const;
  virtual CORBA::Boolean _is_a (
      const char *logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual CORBA::Boolean set_as_default (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void set_as_default (
      CORBA::Boolean set_as_default,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA_DynAny_ptr discriminator (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::TCKind discriminator_kind (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA_DynAny_ptr member (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual char * member_name (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void member_name (
      const char * member_name,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual CORBA::TCKind member_kind (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );

private:
  DynUnion_ptr servant_;
};


#endif /* end #if !defined */


class DynSequence;
typedef DynSequence *DynSequence_ptr;
class TAO_Export DynSequence : public virtual DynAny
{
protected:
  DynSequence (void);
public:
  DynSequence (DynSequence& rhs);
  virtual ~DynSequence (void);
  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual void* _downcast (
      const char* logical_type_id
    );
  virtual CORBA::ULong length (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void length (
      CORBA::ULong length,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual AnySeq * get_elements (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void set_elements (
      const AnySeq & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  static void type_skel (
      CORBA::ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );

  virtual void _dispatch (
      CORBA::ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );

  CORBA_DynSequence *_this (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
};


#if !defined (_CORBA_DYNSEQUENCE___COLLOCATED_SH_)
#define _CORBA_DYNSEQUENCE___COLLOCATED_SH_

class  _tao_collocated_DynSequence : public virtual CORBA_DynSequence,
    public virtual _tao_collocated_DynAny
{
public:
  _tao_collocated_DynSequence (
      DynSequence_ptr  servant,
      STUB_Object *stub
    );
  DynSequence_ptr _get_servant (void) const;
  virtual CORBA::Boolean _is_a (
      const char *logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual CORBA::ULong length (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void length (
      CORBA::ULong length,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual AnySeq * get_elements (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void set_elements (
      const AnySeq & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );

private:
  DynSequence_ptr servant_;
};


#endif /* end #if !defined */


class DynArray;
typedef DynArray *DynArray_ptr;
class TAO_Export DynArray : public virtual DynAny
{
protected:
  DynArray (void);
public:
  DynArray (DynArray& rhs);
  virtual ~DynArray (void);
  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual void* _downcast (
      const char* logical_type_id
    );
  virtual AnySeq * get_elements (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void set_elements (
      const AnySeq & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     ) = 0;

  virtual void _dispatch (
      CORBA::ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &_tao_env =
        CORBA::Environment::default_environment ()
    );

  CORBA_DynArray *_this (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
};


#if !defined (_CORBA_DYNARRAY___COLLOCATED_SH_)
#define _CORBA_DYNARRAY___COLLOCATED_SH_

class  _tao_collocated_DynArray : public virtual CORBA_DynArray,
    public virtual _tao_collocated_DynAny
{
public:
  _tao_collocated_DynArray (
      DynArray_ptr  servant,
      STUB_Object *stub
    );
  DynArray_ptr _get_servant (void) const;
  virtual CORBA::Boolean _is_a (
      const char *logical_type_id,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
    );
  virtual AnySeq * get_elements (
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );
  virtual void set_elements (
      const AnySeq & value,
      CORBA::Environment &TAO_IN_ENV =
        CORBA::Environment::default_environment ()
     );

private:
  DynArray_ptr servant_;
};


#endif /* end #if !defined */


#if defined(_MSC_VER)
#pragma warning(default:4250)
#endif /* _MSC_VER */

};


#if defined(_MSC_VER)
#pragma warning(default:4250)
#endif /* _MSC_VER */

#endif /* TAO_IDL_POA_CORBA_H */
