// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_OBJECTREFERENCETEMPLATEC_H_
#define _TAO_IDL_OBJECTREFERENCETEMPLATEC_H_

#include "ace/pre.h"
#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "OctetSeqC.h"
#include "StringSeqC.h"
#include "ValueBase.h"
#include "Exception.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

TAO_NAMESPACE  PortableInterceptor
{
  typedef char * ServerId;
  typedef CORBA::String_var ServerId_var;
  typedef CORBA::String_out ServerId_out;
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServerId;
  
  typedef char * ORBId;
  typedef CORBA::String_var ORBId_var;
  typedef CORBA::String_out ORBId_out;
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ORBId;
  
  typedef CORBA::StringSeq AdapterName;
  typedef CORBA::StringSeq_var AdapterName_var;
  typedef CORBA::StringSeq_out AdapterName_out;
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_AdapterName;
  
  typedef CORBA::OctetSeq ObjectId;
  typedef CORBA::OctetSeq_var ObjectId_var;
  typedef CORBA::OctetSeq_out ObjectId_out;
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectId;
  
  // Valuetype class
  class ObjectReferenceFactory;
  
#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY___PTR_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY___PTR_CH_
  
  typedef ObjectReferenceFactory *ObjectReferenceFactory_ptr;
  
#endif /* end #if !defined */
  
  
#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY___VAR_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY___VAR_CH_
  
  class TAO_Export ObjectReferenceFactory_var
  {
  public:
    ObjectReferenceFactory_var (void); // default constructor
    ObjectReferenceFactory_var (ObjectReferenceFactory*);
    ObjectReferenceFactory_var (const ObjectReferenceFactory*); // (TAO extension)
    ObjectReferenceFactory_var (const ObjectReferenceFactory_var &); // copy constructor
    ~ObjectReferenceFactory_var (void); // destructor
    
    ObjectReferenceFactory_var &operator= (ObjectReferenceFactory*);
    ObjectReferenceFactory_var &operator= (const ObjectReferenceFactory_var &);
    ObjectReferenceFactory* operator-> (void) const;
    
    operator const ObjectReferenceFactory* () const;
    operator ObjectReferenceFactory* ();
    // in, inout, out, _retn 
    ObjectReferenceFactory* in (void) const;
    ObjectReferenceFactory* &inout (void);
    ObjectReferenceFactory* &out (void);
    ObjectReferenceFactory* _retn (void);
    ObjectReferenceFactory* ptr (void) const;
  
  private:
    ObjectReferenceFactory* ptr_;
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY___OUT_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY___OUT_CH_
  
  class TAO_Export ObjectReferenceFactory_out
  {
  public:
    ObjectReferenceFactory_out (ObjectReferenceFactory* &);
    ObjectReferenceFactory_out (ObjectReferenceFactory_var &);
    ObjectReferenceFactory_out (const ObjectReferenceFactory_out &);
    ObjectReferenceFactory_out &operator= (const ObjectReferenceFactory_out &);
    ObjectReferenceFactory_out &operator= (const ObjectReferenceFactory_var &);
    ObjectReferenceFactory_out &operator= (ObjectReferenceFactory*);
    operator ObjectReferenceFactory* &();
    ObjectReferenceFactory* &ptr (void);
    ObjectReferenceFactory* operator-> (void);
    
  private:
    ObjectReferenceFactory* &ptr_;
  };
  
  
#endif /* end #if !defined */
  
  
#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY_CH_
  
  class TAO_Export ObjectReferenceFactory
    : public virtual CORBA_ValueBase
  {
  public:
    
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
    typedef ObjectReferenceFactory* _ptr_type;
    typedef ObjectReferenceFactory_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */
    
    static ObjectReferenceFactory* _downcast (CORBA::ValueBase* );
    // The address of static _downcast is implicit used as type id

    // (TAO extensions or internals)
    static CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        ObjectReferenceFactory *&
      );
    virtual const char* _tao_obv_repository_id () const;
    static const char* _tao_obv_static_repository_id ();
    
    static void _tao_any_destructor (void *);
    
    virtual CORBA::Object_ptr make_object (
        const char *, const PortableInterceptor::ObjectId & ACE_ENV_ARG_DECL_WITH_DEFAULTS
      ) = 0;
  
protected:
  ObjectReferenceFactory ();
  virtual ~ObjectReferenceFactory ();

  // TAO internals
  virtual void *_tao_obv_narrow (ptr_arith_t);
  
private:
  ObjectReferenceFactory (const ObjectReferenceFactory &);
  void operator= (const ObjectReferenceFactory &);
  
};

#endif /* end #if !defined */

TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectReferenceFactory;

// Valuetype class
class ObjectReferenceTemplate;

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE___PTR_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE___PTR_CH_

typedef ObjectReferenceTemplate *ObjectReferenceTemplate_ptr;

#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE___VAR_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE___VAR_CH_

class TAO_Export ObjectReferenceTemplate_var
{
public:
  ObjectReferenceTemplate_var (void); // default constructor
  ObjectReferenceTemplate_var (ObjectReferenceTemplate*);
  ObjectReferenceTemplate_var (const ObjectReferenceTemplate*); // (TAO extension)
  ObjectReferenceTemplate_var (const ObjectReferenceTemplate_var &); // copy constructor
  ~ObjectReferenceTemplate_var (void); // destructor
  
  ObjectReferenceTemplate_var &operator= (ObjectReferenceTemplate*);
  ObjectReferenceTemplate_var &operator= (const ObjectReferenceTemplate_var &);
  ObjectReferenceTemplate* operator-> (void) const;
  
  operator const ObjectReferenceTemplate* () const;
  operator ObjectReferenceTemplate* ();
  // in, inout, out, _retn 
  ObjectReferenceTemplate* in (void) const;
  ObjectReferenceTemplate* &inout (void);
  ObjectReferenceTemplate* &out (void);
  ObjectReferenceTemplate* _retn (void);
  ObjectReferenceTemplate* ptr (void) const;
  
  // Hooks used by template sequence and valuetype manager classes
  // for non-defined forward declared valuetypes.
  static void tao_add_ref (ObjectReferenceTemplate *);
  static void tao_remove_ref (ObjectReferenceTemplate *);

private:
  ObjectReferenceTemplate* ptr_;
};


#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE___OUT_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE___OUT_CH_

class TAO_Export ObjectReferenceTemplate_out
{
public:
  ObjectReferenceTemplate_out (ObjectReferenceTemplate* &);
  ObjectReferenceTemplate_out (ObjectReferenceTemplate_var &);
  ObjectReferenceTemplate_out (const ObjectReferenceTemplate_out &);
  ObjectReferenceTemplate_out &operator= (const ObjectReferenceTemplate_out &);
  ObjectReferenceTemplate_out &operator= (const ObjectReferenceTemplate_var &);
  ObjectReferenceTemplate_out &operator= (ObjectReferenceTemplate*);
  operator ObjectReferenceTemplate* &();
  ObjectReferenceTemplate* &ptr (void);
  ObjectReferenceTemplate* operator-> (void);
  
private:
  ObjectReferenceTemplate* &ptr_;
};


#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE_CH_

class TAO_Export ObjectReferenceTemplate
  : public virtual ObjectReferenceFactory
{
public:
  
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef ObjectReferenceTemplate* _ptr_type;
  typedef ObjectReferenceTemplate_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */
  
  static ObjectReferenceTemplate* _downcast (CORBA::ValueBase* );
  // The address of static _downcast is implicit used as type id

  // (TAO extensions or internals)
  static CORBA::Boolean _tao_unmarshal (
      TAO_InputCDR &,
      ObjectReferenceTemplate *&
    );
  virtual const char* _tao_obv_repository_id () const;
  static const char* _tao_obv_static_repository_id ();
  
  static void _tao_any_destructor (void *);
  
  virtual char * server_id (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    ) = 0;
virtual char * orb_id (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
  ) = 0;
virtual ::PortableInterceptor::AdapterName * adapter_name (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
  ) = 0;

protected:
  ObjectReferenceTemplate ();
  virtual ~ObjectReferenceTemplate ();

  // TAO internals
  virtual void *_tao_obv_narrow (ptr_arith_t);
  
private:
  ObjectReferenceTemplate (const ObjectReferenceTemplate &);
  void operator= (const ObjectReferenceTemplate &);
  
};

#endif /* end #if !defined */

TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplate;


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_VALUETYPE_SEQUENCE_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CH_)
#define __TAO_UNBOUNDED_VALUETYPE_SEQUENCE_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CH_

class TAO_EXPORT_MACRO _TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq
  : public TAO_Unbounded_Base_Sequence
{
public:
  // = Initialization and termination methods.
  _TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq (void);
  _TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq (CORBA::ULong maximum);
  _TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq (
      CORBA::ULong maximum,
      CORBA::ULong length,
      ObjectReferenceTemplate* *value,
      CORBA::Boolean release = 0
    );
  _TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq (
      const _TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq &rhs
    );
  _TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq &operator= (
      const _TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq &rhs
    );
  virtual ~_TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq (void);
  
  // = Accessors.
  TAO_Valuetype_Manager<PortableInterceptor::ObjectReferenceTemplate,PortableInterceptor::ObjectReferenceTemplate_var> operator[] (CORBA::ULong index) const;
  
  // = Static operations.
  static ObjectReferenceTemplate **allocbuf (CORBA::ULong nelems);
  static void freebuf (ObjectReferenceTemplate **buffer);
  
  // Implement the TAO_Base_Sequence methods (see Sequence.h)
  virtual void _allocate_buffer (CORBA::ULong length);
  virtual void _deallocate_buffer (void);
  ObjectReferenceTemplate* *get_buffer (CORBA::Boolean orphan = 0);
  const ObjectReferenceTemplate* *get_buffer (void) const;
  virtual void _shrink_buffer (
      CORBA::ULong nl,
      CORBA::ULong ol
    );
  
  
};

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CH_

class ObjectReferenceTemplateSeq;
class ObjectReferenceTemplateSeq_var;

// *************************************************************
// ObjectReferenceTemplateSeq
// *************************************************************

class TAO_Export ObjectReferenceTemplateSeq : public 
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
_TAO_Unbounded_Valuetype_Sequence_PortableInterceptor_ObjectReferenceTemplateSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
TAO_Unbounded_Valuetype_Sequence<ObjectReferenceTemplate,ObjectReferenceTemplate_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
{
public:
  ObjectReferenceTemplateSeq (void); // default ctor
  ObjectReferenceTemplateSeq (CORBA::ULong max); // uses max size
  ObjectReferenceTemplateSeq (
      CORBA::ULong max, 
      CORBA::ULong length, 
      ObjectReferenceTemplate_ptr *buffer, 
      CORBA::Boolean release = 0
    );
  ObjectReferenceTemplateSeq (const ObjectReferenceTemplateSeq &); // copy ctor
  ~ObjectReferenceTemplateSeq (void);
  static void _tao_any_destructor (void*);
  
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef ObjectReferenceTemplateSeq_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */
  
  
};

#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ___VAR_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ___VAR_CH_

// *************************************************************
// class PortableInterceptor::ObjectReferenceTemplateSeq_var
// *************************************************************

class TAO_Export ObjectReferenceTemplateSeq_var
{
public:
  ObjectReferenceTemplateSeq_var (void);
  ObjectReferenceTemplateSeq_var (ObjectReferenceTemplateSeq *);
  ObjectReferenceTemplateSeq_var (const ObjectReferenceTemplateSeq_var &);
  ~ObjectReferenceTemplateSeq_var (void);
  
  ObjectReferenceTemplateSeq_var &operator= (ObjectReferenceTemplateSeq *);
  ObjectReferenceTemplateSeq_var &operator= (const ObjectReferenceTemplateSeq_var &);
  ObjectReferenceTemplateSeq *operator-> (void);
  const ObjectReferenceTemplateSeq *operator-> (void) const;
  
  operator const ObjectReferenceTemplateSeq &() const;
  operator ObjectReferenceTemplateSeq &();
  operator ObjectReferenceTemplateSeq &() const;
  operator ObjectReferenceTemplateSeq *&(); // variable-size base types only
  
  TAO_Valuetype_Manager<ObjectReferenceTemplate, ObjectReferenceTemplate_var> operator[] (CORBA::ULong index);
  
  // in, inout, out, _retn 
  const ObjectReferenceTemplateSeq &in (void) const;
  ObjectReferenceTemplateSeq &inout (void);
  ObjectReferenceTemplateSeq *&out (void);
  ObjectReferenceTemplateSeq *_retn (void);
  ObjectReferenceTemplateSeq *ptr (void) const;

private:
  ObjectReferenceTemplateSeq *ptr_;
};


#endif /* end #if !defined */


#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ___OUT_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ___OUT_CH_

class TAO_Export ObjectReferenceTemplateSeq_out
{
public:
  ObjectReferenceTemplateSeq_out (ObjectReferenceTemplateSeq *&);
  ObjectReferenceTemplateSeq_out (ObjectReferenceTemplateSeq_var &);
  ObjectReferenceTemplateSeq_out (const ObjectReferenceTemplateSeq_out &);
  ObjectReferenceTemplateSeq_out &operator= (const ObjectReferenceTemplateSeq_out &);
  ObjectReferenceTemplateSeq_out &operator= (ObjectReferenceTemplateSeq *);
  operator ObjectReferenceTemplateSeq *&();
  ObjectReferenceTemplateSeq *&ptr (void);
  ObjectReferenceTemplateSeq *operator-> (void);
  TAO_Valuetype_Manager<ObjectReferenceTemplate, ObjectReferenceTemplate_var> operator[] (CORBA::ULong index);

private:
  ObjectReferenceTemplateSeq *&ptr_;
  // Assignment from T_var not allowed.
  void operator= (const ObjectReferenceTemplateSeq_var &);
};


#endif /* end #if !defined */

TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplateSeq;

typedef CORBA::Long AdapterManagerId;
typedef CORBA::Long_out AdapterManagerId_out;
TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_AdapterManagerId;

typedef CORBA::Short AdapterState;
typedef CORBA::Short_out AdapterState_out;
TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_AdapterState;

TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short HOLDING;

TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short ACTIVE;

TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short DISCARDING;

TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short INACTIVE;

TAO_NAMESPACE_STORAGE_CLASS const CORBA::Short NON_EXISTENT;


}
TAO_NAMESPACE_CLOSE // module PortableInterceptor

TAO_NAMESPACE  OBV_PortableInterceptor
{
}
TAO_NAMESPACE_CLOSE

// Any operators for valuetype PortableInterceptor::ObjectReferenceFactory
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceFactory *); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceFactory **); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceFactory *&);
// Any operators for valuetype PortableInterceptor::ObjectReferenceTemplate
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate *); // copying
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate **); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate *&);
TAO_Export void operator<<= (CORBA::Any &, const PortableInterceptor::ObjectReferenceTemplateSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplateSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceTemplateSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const PortableInterceptor::ObjectReferenceTemplateSeq *&);

#ifndef __ACE_INLINE__

//@@ Boris: begin experimental
TAO_NAMESPACE CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (PortableInterceptor::ObjectReferenceFactory *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (PortableInterceptor::ObjectReferenceFactory *);
}
TAO_NAMESPACE_CLOSE
//@@ Boris: end experimental

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableInterceptor::ObjectReferenceFactory *);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableInterceptor::ObjectReferenceFactory *&);
//@@ Boris: begin experimental
TAO_NAMESPACE CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (PortableInterceptor::ObjectReferenceTemplate *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (PortableInterceptor::ObjectReferenceTemplate *);
}
TAO_NAMESPACE_CLOSE
//@@ Boris: end experimental

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableInterceptor::ObjectReferenceTemplate *);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableInterceptor::ObjectReferenceTemplate *&);

#if !defined _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_
#define _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const PortableInterceptor::ObjectReferenceTemplateSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    PortableInterceptor::ObjectReferenceTemplateSeq &
  );

#endif /* _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_ */


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "ObjectReferenceTemplateC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */
