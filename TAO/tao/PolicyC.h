/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_POLICYC_H_
#define _TAO_IDL_POLICYC_H_

#include "ace/pre.h"
#include "tao/CurrentC.h"

#if defined (ACE_HAS_MINIMUM_IOSTREAMH_INCLUSION)
#include "ace/streams.h"
#endif /* ACE_HAS_MINIMUM_IOSTREAMH_INCLUSION */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Encodable.h"
#include "tao/Exception.h"
#include "tao/Sequence.h"
#include "tao/CDR.h"
#include "tao/Typecode.h"
#include "tao/Environment.h"

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

#if !defined (_CORBA_POLICYERROR_CH_)
#define _CORBA_POLICYERROR_CH_

class TAO_Export CORBA_PolicyError : public CORBA::UserException
{
public:

CORBA::PolicyErrorCode reason;

CORBA_PolicyError (void); // default ctor
CORBA_PolicyError (const CORBA_PolicyError &); // copy ctor
~CORBA_PolicyError (void);
static void _tao_any_destructor (void*);
CORBA_PolicyError &operator= (const CORBA_PolicyError &);


virtual void _raise (void);

virtual void _tao_encode (
    TAO_OutputCDR &,
    CORBA::Environment &) const;
virtual void _tao_decode (
    TAO_InputCDR &,
    CORBA::Environment &);

static CORBA_PolicyError *_downcast (CORBA::Exception *);

CORBA_PolicyError (
  CORBA::PolicyErrorCode _tao_reason
);

// = TAO extension
static CORBA::Exception *_alloc (void);
virtual CORBA::TypeCode_ptr _type (void) const;

}; // exception CORBA_PolicyError

extern TAO_Export CORBA::TypeCode_ptr  _tc_CORBA_PolicyError;


#endif /* end #if !defined */


#if !defined (_CORBA_INVALIDPOLICIES_CH_)
#define _CORBA_INVALIDPOLICIES_CH_

class TAO_Export CORBA_InvalidPolicies : public CORBA::UserException
{
public:


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT_CH_

  class TAO_EXPORT_NESTED_MACRO _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort : public TAO_Unbounded_Base_Sequence
  {
  public:
    // = Initialization and termination methods.

    _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (void); // Default constructor.
    _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (CORBA::ULong maximum);
    _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (CORBA::ULong maximum,
      CORBA::ULong length,
      CORBA::UShort *data,
      CORBA::Boolean release = 0);
    _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (const _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort &rhs);
    _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort &operator= (const _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort &rhs);
    virtual ~_TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (void); // Dtor.
    // = Accessors.
    CORBA::UShort &operator[] (CORBA::ULong i);
    const CORBA::UShort &operator[] (CORBA::ULong i) const;
    // = Static operations.
    static CORBA::UShort *allocbuf (CORBA::ULong size);
    static void freebuf (CORBA::UShort *buffer);
    virtual void _allocate_buffer (CORBA::ULong length);
    virtual void _deallocate_buffer (void);
    // Implement the TAO_Base_Sequence methods (see Sequence.h)

    CORBA::UShort *get_buffer (CORBA::Boolean orphan = 0);
    const CORBA::UShort *get_buffer (void) const;
    void replace (CORBA::ULong max,
      CORBA::ULong length,
      CORBA::UShort *data,
      CORBA::Boolean release);
  };

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT_CH_)
#define _CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT_CH_

class _tao_seq_UShort;
class _tao_seq_UShort_var;

// *************************************************************
// _tao_seq_UShort
// *************************************************************

class TAO_Export _tao_seq_UShort : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::UShort>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
{
public:
  _tao_seq_UShort (void); // default ctor
  _tao_seq_UShort (CORBA::ULong max); // uses max size
  _tao_seq_UShort (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::UShort *buffer,
    CORBA::Boolean release=0
  );
  _tao_seq_UShort (const _tao_seq_UShort &); // copy ctor
  ~_tao_seq_UShort (void);
  static void _tao_any_destructor (void*);

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef _tao_seq_UShort_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

};

#endif /* end #if !defined */


#if !defined (_CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT___VAR_CH_)
#define _CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT___VAR_CH_

// *************************************************************
// class CORBA_InvalidPolicies::_tao_seq_UShort_var
// *************************************************************

class TAO_Export _tao_seq_UShort_var
{
public:
  _tao_seq_UShort_var (void); // default constructor
  _tao_seq_UShort_var (_tao_seq_UShort *);
  _tao_seq_UShort_var (const _tao_seq_UShort_var &); // copy constructor
  _tao_seq_UShort_var (const _tao_seq_UShort &); // fixed-size base types only
  ~_tao_seq_UShort_var (void); // destructor

  _tao_seq_UShort_var &operator= (_tao_seq_UShort *);
  _tao_seq_UShort_var &operator= (const _tao_seq_UShort_var &);
  _tao_seq_UShort_var &operator= (const _tao_seq_UShort &); // fixed-size base types only
  _tao_seq_UShort *operator-> (void);
  const _tao_seq_UShort *operator-> (void) const;

  operator const _tao_seq_UShort &() const;
  operator _tao_seq_UShort &();
  operator _tao_seq_UShort &() const;

  CORBA::UShort &operator[] (CORBA::ULong index);
  // in, inout, out, _retn
  const _tao_seq_UShort &in (void) const;
  _tao_seq_UShort &inout (void);
  _tao_seq_UShort *&out (void);
  _tao_seq_UShort *_retn (void);
  _tao_seq_UShort *ptr (void) const;

private:
  _tao_seq_UShort *ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT___OUT_CH_)
#define _CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT___OUT_CH_

class TAO_Export _tao_seq_UShort_out
{
public:
  _tao_seq_UShort_out (_tao_seq_UShort *&);
  _tao_seq_UShort_out (_tao_seq_UShort_var &);
  _tao_seq_UShort_out (const _tao_seq_UShort_out &);
  _tao_seq_UShort_out &operator= (const _tao_seq_UShort_out &);
  _tao_seq_UShort_out &operator= (_tao_seq_UShort *);
  operator _tao_seq_UShort *&();
  _tao_seq_UShort *&ptr (void);
  _tao_seq_UShort *operator-> (void);
  CORBA::UShort &operator[] (CORBA::ULong index);

private:
  _tao_seq_UShort *&ptr_;
  // assignment from T_var not allowed
  void operator= (const _tao_seq_UShort_var &);
};


#endif /* end #if !defined */

#if !defined (__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef _tao_seq_UShort _indices_seq;
#endif /* ! __GNUC__ || ACE_HAS_GNUG_PRE_2_8 */

    _tao_seq_UShort indices;

  CORBA_InvalidPolicies (void); // default ctor
  CORBA_InvalidPolicies (const CORBA_InvalidPolicies &); // copy ctor
  ~CORBA_InvalidPolicies (void);
  static void _tao_any_destructor (void*);
  CORBA_InvalidPolicies &operator= (const CORBA_InvalidPolicies &);


  virtual void _raise (void);

  virtual void _tao_encode (
      TAO_OutputCDR &,
      CORBA::Environment &) const;
  virtual void _tao_decode (
      TAO_InputCDR &,
      CORBA::Environment &);

  static CORBA_InvalidPolicies *_downcast (CORBA::Exception *);

  CORBA_InvalidPolicies (
    const _tao_seq_UShort & _tao_indices
  );

  // = TAO extension
  static CORBA::Exception *_alloc (void);
  virtual CORBA::TypeCode_ptr _type (void) const;

}; // exception CORBA_InvalidPolicies

extern TAO_Export CORBA::TypeCode_ptr  _tc_CORBA_InvalidPolicies;


#endif /* end #if !defined */


#if !defined (_CORBA_POLICY___PTR_CH_)
#define _CORBA_POLICY___PTR_CH_

class CORBA_Policy;
typedef CORBA_Policy *CORBA_Policy_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_POLICY___VAR_CH_)
#define _CORBA_POLICY___VAR_CH_

class TAO_Export CORBA_Policy_var : public TAO_Base_var
{
public:
  CORBA_Policy_var (void); // default constructor
  CORBA_Policy_var (CORBA_Policy_ptr p) : ptr_ (p) {}
  CORBA_Policy_var (const CORBA_Policy_var &); // copy constructor
  ~CORBA_Policy_var (void); // destructor

  CORBA_Policy_var &operator= (CORBA_Policy_ptr);
  CORBA_Policy_var &operator= (const CORBA_Policy_var &);
  CORBA_Policy_ptr operator-> (void) const;

  operator const CORBA_Policy_ptr &() const;
  operator CORBA_Policy_ptr &();
  // in, inout, out, _retn
  CORBA_Policy_ptr in (void) const;
  CORBA_Policy_ptr &inout (void);
  CORBA_Policy_ptr &out (void);
  CORBA_Policy_ptr _retn (void);
  CORBA_Policy_ptr ptr (void) const;

private:
  CORBA_Policy_ptr ptr_;
  // Unimplemented - prevents widening assignment.
  CORBA_Policy_var (const TAO_Base_var &rhs);
  CORBA_Policy_var &operator= (const TAO_Base_var &rhs);
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICY___OUT_CH_)
#define _CORBA_POLICY___OUT_CH_

class TAO_Export CORBA_Policy_out
{
public:
  CORBA_Policy_out (CORBA_Policy_ptr &);
  CORBA_Policy_out (CORBA_Policy_var &);
  CORBA_Policy_out (const CORBA_Policy_out &);
  CORBA_Policy_out &operator= (const CORBA_Policy_out &);
  CORBA_Policy_out &operator= (const CORBA_Policy_var &);
  CORBA_Policy_out &operator= (CORBA_Policy_ptr);
  operator CORBA_Policy_ptr &();
  CORBA_Policy_ptr &ptr (void);
  CORBA_Policy_ptr operator-> (void);

private:
  CORBA_Policy_ptr &ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICY_CH_)
#define _CORBA_POLICY_CH_

class TAO_Export CORBA_Policy : public virtual CORBA_Object
{
public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_Policy_ptr _ptr_type;
  typedef CORBA_Policy_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static CORBA_Policy_ptr _duplicate (CORBA_Policy_ptr obj);
  static CORBA_Policy_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_Policy_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_Policy_ptr _nil (void)
    {
      return (CORBA_Policy_ptr)0;
    }

  static void _tao_any_destructor (void*);

  virtual CORBA::PolicyType policy_type (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual CORBA_Policy_ptr copy (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void destroy (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual CORBA::Boolean _is_a (
      const CORBA::Char *type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  virtual void *_tao_QueryInterface (ptr_arith_t type);

  virtual const char* _interface_repository_id (void) const;

  virtual CORBA::Boolean _tao_encode (TAO_OutputCDR &out_cdr);
  // Encode the Policy into a CDR representation.  Returns true
  // on success and false on failure.

  virtual CORBA::Boolean _tao_decode (TAO_InputCDR &in_cdr);
  // Decode the Policy from a CDR representation.  Returns true
  // on success and false on failure.

protected:
  CORBA_Policy (void);
  CORBA_Policy (TAO_Stub *objref,
      CORBA::Boolean _tao_collocated = 0
    );
  virtual ~CORBA_Policy (void);
private:
  CORBA_Policy (const CORBA_Policy &);
  void operator= (const CORBA_Policy &);
};


#endif /* end #if !defined */

extern TAO_Export CORBA::TypeCode_ptr  _tc_CORBA_Policy;


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_POLICYLIST_CH_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_POLICYLIST_CH_

  class _TAO_Unbounded_Object_Sequence_CORBA_PolicyList : public TAO_Unbounded_Base_Sequence
  {
  public:
    // = Initialization and termination methods.

    _TAO_Unbounded_Object_Sequence_CORBA_PolicyList (void);
    _TAO_Unbounded_Object_Sequence_CORBA_PolicyList (CORBA::ULong maximum);
    _TAO_Unbounded_Object_Sequence_CORBA_PolicyList (CORBA::ULong maximum,
      CORBA::ULong length,
      CORBA_Policy* *value,
      CORBA::Boolean release = 0);
    _TAO_Unbounded_Object_Sequence_CORBA_PolicyList(const _TAO_Unbounded_Object_Sequence_CORBA_PolicyList &rhs);
    virtual ~_TAO_Unbounded_Object_Sequence_CORBA_PolicyList (void);
    _TAO_Unbounded_Object_Sequence_CORBA_PolicyList &operator= (const _TAO_Unbounded_Object_Sequence_CORBA_PolicyList &rhs);
    TAO_Object_Manager<CORBA_Policy,CORBA_Policy_var> operator[] (CORBA::ULong index) const;
    static CORBA_Policy **allocbuf (CORBA::ULong nelems);
    static void freebuf (CORBA_Policy **buffer);
    // The Base_Sequence functions, please see tao/Sequence.h
    virtual void _allocate_buffer (CORBA::ULong length);
    virtual void _deallocate_buffer (void);
    CORBA_Policy* *get_buffer (CORBA::Boolean orphan = 0);
    const CORBA_Policy* *get_buffer (void) const;
    virtual void _shrink_buffer (CORBA::ULong nl, CORBA::ULong ol);
    virtual void _downcast (
        void* target,
        CORBA_Object *src,
        CORBA_Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
    virtual CORBA_Object* _upcast (void *src) const;

  };

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_POLICYLIST_CH_)
#define _CORBA_POLICYLIST_CH_

class CORBA_PolicyList;
class CORBA_PolicyList_var;

// *************************************************************
// CORBA_PolicyList
// *************************************************************

class TAO_Export CORBA_PolicyList : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_CORBA_PolicyList
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<CORBA_Policy,CORBA_Policy_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
{
public:
  CORBA_PolicyList (void); // default ctor
  CORBA_PolicyList (CORBA::ULong max); // uses max size
  CORBA_PolicyList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA_Policy_ptr *buffer,
    CORBA::Boolean release=0
  );
  CORBA_PolicyList (const CORBA_PolicyList &); // copy ctor
  ~CORBA_PolicyList (void);
  static void _tao_any_destructor (void*);

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_PolicyList_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

};

#endif /* end #if !defined */


#if !defined (_CORBA_POLICYLIST___VAR_CH_)
#define _CORBA_POLICYLIST___VAR_CH_

// *************************************************************
// class CORBA_PolicyList_var
// *************************************************************

class TAO_Export CORBA_PolicyList_var
{
public:
  CORBA_PolicyList_var (void); // default constructor
  CORBA_PolicyList_var (CORBA_PolicyList *);
  CORBA_PolicyList_var (const CORBA_PolicyList_var &); // copy constructor
  ~CORBA_PolicyList_var (void); // destructor

  CORBA_PolicyList_var &operator= (CORBA_PolicyList *);
  CORBA_PolicyList_var &operator= (const CORBA_PolicyList_var &);
  CORBA_PolicyList *operator-> (void);
  const CORBA_PolicyList *operator-> (void) const;

  operator const CORBA_PolicyList &() const;
  operator CORBA_PolicyList &();
  operator CORBA_PolicyList &() const;
  operator CORBA_PolicyList *&(); // variable-size base types only

  TAO_Object_Manager<CORBA_Policy, CORBA_Policy_var> operator[] (CORBA::ULong index);
  // in, inout, out, _retn
  const CORBA_PolicyList &in (void) const;
  CORBA_PolicyList &inout (void);
  CORBA_PolicyList *&out (void);
  CORBA_PolicyList *_retn (void);
  CORBA_PolicyList *ptr (void) const;

private:
  CORBA_PolicyList *ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICYLIST___OUT_CH_)
#define _CORBA_POLICYLIST___OUT_CH_

class TAO_Export CORBA_PolicyList_out
{
public:
  CORBA_PolicyList_out (CORBA_PolicyList *&);
  CORBA_PolicyList_out (CORBA_PolicyList_var &);
  CORBA_PolicyList_out (const CORBA_PolicyList_out &);
  CORBA_PolicyList_out &operator= (const CORBA_PolicyList_out &);
  CORBA_PolicyList_out &operator= (CORBA_PolicyList *);
  operator CORBA_PolicyList *&();
  CORBA_PolicyList *&ptr (void);
  CORBA_PolicyList *operator-> (void);
  TAO_Object_Manager<CORBA_Policy, CORBA_Policy_var> operator[] (CORBA::ULong index);

private:
  CORBA_PolicyList *&ptr_;
  // assignment from T_var not allowed
  void operator= (const CORBA_PolicyList_var &);
};


#endif /* end #if !defined */

extern TAO_Export CORBA::TypeCode_ptr  _tc_CORBA_PolicyList;


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_POLICYTYPESEQ_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_POLICYTYPESEQ_CH_

  class TAO_EXPORT_NESTED_MACRO _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq : public TAO_Unbounded_Base_Sequence
  {
  public:
    // = Initialization and termination methods.

    _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq (void); // Default constructor.
    _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq (CORBA::ULong maximum);
    _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq (CORBA::ULong maximum,
      CORBA::ULong length,
      CORBA::ULong *data,
      CORBA::Boolean release = 0);
    _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq (const _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq &rhs);
    _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq &operator= (const _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq &rhs);
    virtual ~_TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq (void); // Dtor.
    // = Accessors.
    CORBA::ULong &operator[] (CORBA::ULong i);
    const CORBA::ULong &operator[] (CORBA::ULong i) const;
    // = Static operations.
    static CORBA::ULong *allocbuf (CORBA::ULong size);
    static void freebuf (CORBA::ULong *buffer);
    virtual void _allocate_buffer (CORBA::ULong length);
    virtual void _deallocate_buffer (void);
    // Implement the TAO_Base_Sequence methods (see Sequence.h)

    CORBA::ULong *get_buffer (CORBA::Boolean orphan = 0);
    const CORBA::ULong *get_buffer (void) const;
    void replace (CORBA::ULong max,
      CORBA::ULong length,
      CORBA::ULong *data,
      CORBA::Boolean release);
  };

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_POLICYTYPESEQ_CH_)
#define _CORBA_POLICYTYPESEQ_CH_

class CORBA_PolicyTypeSeq;
class CORBA_PolicyTypeSeq_var;

// *************************************************************
// CORBA_PolicyTypeSeq
// *************************************************************

class TAO_Export CORBA_PolicyTypeSeq : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_PolicyTypeSeq
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
{
public:
  CORBA_PolicyTypeSeq (void); // default ctor
  CORBA_PolicyTypeSeq (CORBA::ULong max); // uses max size
  CORBA_PolicyTypeSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ULong *buffer,
    CORBA::Boolean release=0
  );
  CORBA_PolicyTypeSeq (const CORBA_PolicyTypeSeq &); // copy ctor
  ~CORBA_PolicyTypeSeq (void);
  static void _tao_any_destructor (void*);

#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_PolicyTypeSeq_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

};

#endif /* end #if !defined */


#if !defined (_CORBA_POLICYTYPESEQ___VAR_CH_)
#define _CORBA_POLICYTYPESEQ___VAR_CH_

// *************************************************************
// class CORBA_PolicyTypeSeq_var
// *************************************************************

class TAO_Export CORBA_PolicyTypeSeq_var
{
public:
  CORBA_PolicyTypeSeq_var (void); // default constructor
  CORBA_PolicyTypeSeq_var (CORBA_PolicyTypeSeq *);
  CORBA_PolicyTypeSeq_var (const CORBA_PolicyTypeSeq_var &); // copy constructor
  CORBA_PolicyTypeSeq_var (const CORBA_PolicyTypeSeq &); // fixed-size base types only
  ~CORBA_PolicyTypeSeq_var (void); // destructor

  CORBA_PolicyTypeSeq_var &operator= (CORBA_PolicyTypeSeq *);
  CORBA_PolicyTypeSeq_var &operator= (const CORBA_PolicyTypeSeq_var &);
  CORBA_PolicyTypeSeq_var &operator= (const CORBA_PolicyTypeSeq &); // fixed-size base types only
  CORBA_PolicyTypeSeq *operator-> (void);
  const CORBA_PolicyTypeSeq *operator-> (void) const;

  operator const CORBA_PolicyTypeSeq &() const;
  operator CORBA_PolicyTypeSeq &();
  operator CORBA_PolicyTypeSeq &() const;

  CORBA::PolicyType &operator[] (CORBA::ULong index);
  // in, inout, out, _retn
  const CORBA_PolicyTypeSeq &in (void) const;
  CORBA_PolicyTypeSeq &inout (void);
  CORBA_PolicyTypeSeq *&out (void);
  CORBA_PolicyTypeSeq *_retn (void);
  CORBA_PolicyTypeSeq *ptr (void) const;

private:
  CORBA_PolicyTypeSeq *ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICYTYPESEQ___OUT_CH_)
#define _CORBA_POLICYTYPESEQ___OUT_CH_

class TAO_Export CORBA_PolicyTypeSeq_out
{
public:
  CORBA_PolicyTypeSeq_out (CORBA_PolicyTypeSeq *&);
  CORBA_PolicyTypeSeq_out (CORBA_PolicyTypeSeq_var &);
  CORBA_PolicyTypeSeq_out (const CORBA_PolicyTypeSeq_out &);
  CORBA_PolicyTypeSeq_out &operator= (const CORBA_PolicyTypeSeq_out &);
  CORBA_PolicyTypeSeq_out &operator= (CORBA_PolicyTypeSeq *);
  operator CORBA_PolicyTypeSeq *&();
  CORBA_PolicyTypeSeq *&ptr (void);
  CORBA_PolicyTypeSeq *operator-> (void);
  CORBA::PolicyType &operator[] (CORBA::ULong index);

private:
  CORBA_PolicyTypeSeq *&ptr_;
  // assignment from T_var not allowed
  void operator= (const CORBA_PolicyTypeSeq_var &);
};


#endif /* end #if !defined */

extern TAO_Export CORBA::TypeCode_ptr  _tc_CORBA_PolicyTypeSeq;


#if !defined (_CORBA_POLICYMANAGER___PTR_CH_)
#define _CORBA_POLICYMANAGER___PTR_CH_

class CORBA_PolicyManager;
typedef CORBA_PolicyManager *CORBA_PolicyManager_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_POLICYMANAGER___VAR_CH_)
#define _CORBA_POLICYMANAGER___VAR_CH_

class TAO_Export CORBA_PolicyManager_var : public TAO_Base_var
{
public:
  CORBA_PolicyManager_var (void); // default constructor
  CORBA_PolicyManager_var (CORBA_PolicyManager_ptr p) : ptr_ (p) {}
  CORBA_PolicyManager_var (const CORBA_PolicyManager_var &); // copy constructor
  ~CORBA_PolicyManager_var (void); // destructor

  CORBA_PolicyManager_var &operator= (CORBA_PolicyManager_ptr);
  CORBA_PolicyManager_var &operator= (const CORBA_PolicyManager_var &);
  CORBA_PolicyManager_ptr operator-> (void) const;

  operator const CORBA_PolicyManager_ptr &() const;
  operator CORBA_PolicyManager_ptr &();
  // in, inout, out, _retn
  CORBA_PolicyManager_ptr in (void) const;
  CORBA_PolicyManager_ptr &inout (void);
  CORBA_PolicyManager_ptr &out (void);
  CORBA_PolicyManager_ptr _retn (void);
  CORBA_PolicyManager_ptr ptr (void) const;

private:
  CORBA_PolicyManager_ptr ptr_;
  // Unimplemented - prevents widening assignment.
  CORBA_PolicyManager_var (const TAO_Base_var &rhs);
  CORBA_PolicyManager_var &operator= (const TAO_Base_var &rhs);
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICYMANAGER___OUT_CH_)
#define _CORBA_POLICYMANAGER___OUT_CH_

class TAO_Export CORBA_PolicyManager_out
{
public:
  CORBA_PolicyManager_out (CORBA_PolicyManager_ptr &);
  CORBA_PolicyManager_out (CORBA_PolicyManager_var &);
  CORBA_PolicyManager_out (const CORBA_PolicyManager_out &);
  CORBA_PolicyManager_out &operator= (const CORBA_PolicyManager_out &);
  CORBA_PolicyManager_out &operator= (const CORBA_PolicyManager_var &);
  CORBA_PolicyManager_out &operator= (CORBA_PolicyManager_ptr);
  operator CORBA_PolicyManager_ptr &();
  CORBA_PolicyManager_ptr &ptr (void);
  CORBA_PolicyManager_ptr operator-> (void);

private:
  CORBA_PolicyManager_ptr &ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICYMANAGER_CH_)
#define _CORBA_POLICYMANAGER_CH_

class TAO_Export CORBA_PolicyManager : public virtual CORBA_Object
{
public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_PolicyManager_ptr _ptr_type;
  typedef CORBA_PolicyManager_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static CORBA_PolicyManager_ptr _duplicate (CORBA_PolicyManager_ptr obj);
  static CORBA_PolicyManager_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_PolicyManager_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_PolicyManager_ptr _nil (void)
    {
      return (CORBA_PolicyManager_ptr)0;
    }

  virtual CORBA_PolicyList * get_policy_overrides (
      const CORBA_PolicyTypeSeq & ts,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  virtual void set_policy_overrides (
      const CORBA_PolicyList & policies,
      CORBA::SetOverrideType set_add,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException,
      CORBA_InvalidPolicies
    )) = 0;

  virtual void *_tao_QueryInterface (ptr_arith_t type);

  virtual const char* _interface_repository_id (void) const;

protected:
  CORBA_PolicyManager (void);
  virtual ~CORBA_PolicyManager (void);
private:
  CORBA_PolicyManager (const CORBA_PolicyManager &);
  void operator= (const CORBA_PolicyManager &);
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICYCURRENT___PTR_CH_)
#define _CORBA_POLICYCURRENT___PTR_CH_

class CORBA_PolicyCurrent;
typedef CORBA_PolicyCurrent *CORBA_PolicyCurrent_ptr;

#endif /* end #if !defined */


#if !defined (_CORBA_POLICYCURRENT___VAR_CH_)
#define _CORBA_POLICYCURRENT___VAR_CH_

class TAO_Export CORBA_PolicyCurrent_var : public TAO_Base_var
{
public:
  CORBA_PolicyCurrent_var (void); // default constructor
  CORBA_PolicyCurrent_var (CORBA_PolicyCurrent_ptr p) : ptr_ (p) {}
  CORBA_PolicyCurrent_var (const CORBA_PolicyCurrent_var &); // copy constructor
  ~CORBA_PolicyCurrent_var (void); // destructor

  CORBA_PolicyCurrent_var &operator= (CORBA_PolicyCurrent_ptr);
  CORBA_PolicyCurrent_var &operator= (const CORBA_PolicyCurrent_var &);
  CORBA_PolicyCurrent_ptr operator-> (void) const;

  operator const CORBA_PolicyCurrent_ptr &() const;
  operator CORBA_PolicyCurrent_ptr &();
  // in, inout, out, _retn
  CORBA_PolicyCurrent_ptr in (void) const;
  CORBA_PolicyCurrent_ptr &inout (void);
  CORBA_PolicyCurrent_ptr &out (void);
  CORBA_PolicyCurrent_ptr _retn (void);
  CORBA_PolicyCurrent_ptr ptr (void) const;

private:
  CORBA_PolicyCurrent_ptr ptr_;
  // Unimplemented - prevents widening assignment.
  CORBA_PolicyCurrent_var (const TAO_Base_var &rhs);
  CORBA_PolicyCurrent_var &operator= (const TAO_Base_var &rhs);
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICYCURRENT___OUT_CH_)
#define _CORBA_POLICYCURRENT___OUT_CH_

class TAO_Export CORBA_PolicyCurrent_out
{
public:
  CORBA_PolicyCurrent_out (CORBA_PolicyCurrent_ptr &);
  CORBA_PolicyCurrent_out (CORBA_PolicyCurrent_var &);
  CORBA_PolicyCurrent_out (const CORBA_PolicyCurrent_out &);
  CORBA_PolicyCurrent_out &operator= (const CORBA_PolicyCurrent_out &);
  CORBA_PolicyCurrent_out &operator= (const CORBA_PolicyCurrent_var &);
  CORBA_PolicyCurrent_out &operator= (CORBA_PolicyCurrent_ptr);
  operator CORBA_PolicyCurrent_ptr &();
  CORBA_PolicyCurrent_ptr &ptr (void);
  CORBA_PolicyCurrent_ptr operator-> (void);

private:
  CORBA_PolicyCurrent_ptr &ptr_;
};


#endif /* end #if !defined */


#if !defined (_CORBA_POLICYCURRENT_CH_)
#define _CORBA_POLICYCURRENT_CH_

class TAO_Export CORBA_PolicyCurrent: public virtual CORBA_PolicyManager, public virtual CORBA_Current
{
public:
#if !defined(__GNUC__) || !defined (ACE_HAS_GNUG_PRE_2_8)
  typedef CORBA_PolicyCurrent_ptr _ptr_type;
  typedef CORBA_PolicyCurrent_var _var_type;
#endif /* ! __GNUC__ || g++ >= 2.8 */

  // the static operations
  static CORBA_PolicyCurrent_ptr _duplicate (CORBA_PolicyCurrent_ptr obj);
  static CORBA_PolicyCurrent_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_PolicyCurrent_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );
  static CORBA_PolicyCurrent_ptr _nil (void)
    {
      return (CORBA_PolicyCurrent_ptr)0;
    }

  virtual void *_tao_QueryInterface (ptr_arith_t type);

  virtual const char* _interface_repository_id (void) const;

protected:
  CORBA_PolicyCurrent (void);
  virtual ~CORBA_PolicyCurrent (void);
private:
  CORBA_PolicyCurrent (const CORBA_PolicyCurrent &);
  void operator= (const CORBA_PolicyCurrent &);
};


#endif /* end #if !defined */

TAO_Export void operator<<= (CORBA::Any &, CORBA::SetOverrideType);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::SetOverrideType &);
TAO_Export void operator<<= (CORBA::Any &, const CORBA_PolicyError &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA_PolicyError*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_PolicyError *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA_PolicyError *&);
TAO_Export void operator<<= (CORBA::Any &, const CORBA_InvalidPolicies &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA_InvalidPolicies*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_InvalidPolicies *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA_InvalidPolicies *&);
extern TAO_Export CORBA_Policy_ptr (*_TAO_collocation_CORBA_Policy_Stub_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );
// Any operators for interface CORBA_Policy
TAO_Export void operator<<= (CORBA::Any &, CORBA_Policy_ptr);
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_Policy *&);
TAO_Export void operator<<= (CORBA::Any &, const CORBA_PolicyList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA_PolicyList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_PolicyList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA_PolicyList *&);
TAO_Export void operator<<= (CORBA::Any &, const CORBA_PolicyTypeSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA_PolicyTypeSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA_PolicyTypeSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA_PolicyTypeSeq *&);

#ifndef __ACE_INLINE__

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::SetOverrideType &); //
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::SetOverrideType &);
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA_PolicyError &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA_PolicyError &);

# if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

TAO_Export ostream& operator<< (ostream &, const CORBA_PolicyError &);

# endif /* ACE_LACKS_IOSTREAM_TOTALLY */
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA_InvalidPolicies &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA_InvalidPolicies &);

#if !defined _TAO_CDR_OP_CORBA_InvalidPolicies__tao_seq_UShort_H_
#define _TAO_CDR_OP_CORBA_InvalidPolicies__tao_seq_UShort_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA_InvalidPolicies::_tao_seq_UShort &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA_InvalidPolicies::_tao_seq_UShort &
  );

#endif /* _TAO_CDR_OP_CORBA_InvalidPolicies__tao_seq_UShort_H_ */


# if !defined (ACE_LACKS_IOSTREAM_TOTALLY)

TAO_Export ostream& operator<< (ostream &, const CORBA_InvalidPolicies &);

# endif /* ACE_LACKS_IOSTREAM_TOTALLY */
TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA_Policy_ptr );
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA_Policy_ptr &);

#if !defined _TAO_CDR_OP_CORBA_PolicyList_H_
#define _TAO_CDR_OP_CORBA_PolicyList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA_PolicyList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA_PolicyList &
  );

#endif /* _TAO_CDR_OP_CORBA_PolicyList_H_ */


#if !defined _TAO_CDR_OP_CORBA_PolicyTypeSeq_H_
#define _TAO_CDR_OP_CORBA_PolicyTypeSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA_PolicyTypeSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA_PolicyTypeSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_PolicyTypeSeq_H_ */


#endif /* __ACE_INLINE__ */


#if defined (__ACE_INLINE__)
#include "tao/PolicyC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* ifndef */
