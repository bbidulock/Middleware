/* -*- C++ -*- */
// $Id$

// ****** Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef TAO_IDL_POLICYC_H
#define TAO_IDL_POLICYC_H

#include "tao/CurrentC.h"
#include "tao/CDR.h"
#include "tao/Sequence.h"

class TAO_Export CORBA_PolicyError : public CORBA::UserException
{
public:
  CORBA::PolicyErrorCode reason;

  CORBA_PolicyError (void); // default ctor
  CORBA_PolicyError (const CORBA::PolicyError &); // copy ctor
  ~CORBA_PolicyError (void); // dtor
  CORBA_PolicyError &operator= (const CORBA_PolicyError &);

  virtual void _raise (void);

  static CORBA_PolicyError *_narrow (CORBA::Exception *);

  CORBA_PolicyError(
    CORBA::PolicyErrorCode _tao_reason);

  // = TAO extension
  static CORBA::Exception *_alloc (void);
}; // exception CORBA::PolicyError

// ****************************************************************

class CORBA_InvalidPolicies;
typedef CORBA_InvalidPolicies *CORBA_InvalidPolicies_ptr;

class TAO_Export CORBA_InvalidPolicies : public CORBA::UserException
{
public:
  class TAO_Export _tao_seq_UShort : public TAO_Unbounded_Sequence<CORBA::UShort>
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
    ~_tao_seq_UShort (void); // dtor
  };
  typedef _tao_seq_UShort *_tao_seq_UShort_ptr;
  static CORBA::TypeCode_ptr _tc__tao_seq_UShort;

  _tao_seq_UShort indices;

  CORBA_InvalidPolicies (void); // default ctor
  CORBA_InvalidPolicies (const CORBA_InvalidPolicies &); // copy ctor
  ~CORBA_InvalidPolicies (void); // dtor
  CORBA_InvalidPolicies &operator= (const CORBA_InvalidPolicies &);

  virtual void _raise (void);

  static CORBA_InvalidPolicies *_narrow (CORBA::Exception *);

  CORBA_InvalidPolicies(
      const _tao_seq_UShort & _tao_indices);

  // = TAO extension
  static CORBA::Exception *_alloc (void);
}; // exception CORBA::InvalidPolicies

// ****************************************************************

class CORBA_Policy;
typedef CORBA_Policy *CORBA_Policy_ptr;

class TAO_Export  CORBA_Policy_var
{
public:
  CORBA_Policy_var (void); // default constructor
  CORBA_Policy_var (CORBA_Policy_ptr);
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
};

class TAO_Export  CORBA_Policy_out
{
public:
  CORBA_Policy_out (CORBA_Policy_ptr &);
  CORBA_Policy_out (CORBA_Policy_var &);
  CORBA_Policy_out (CORBA_Policy_out &);
  CORBA_Policy_out &operator= (CORBA_Policy_out &);
  CORBA_Policy_out &operator= (const CORBA_Policy_var &);
  CORBA_Policy_out &operator= (CORBA_Policy_ptr);
  operator CORBA_Policy_ptr &();
  CORBA_Policy_ptr &ptr (void);
  CORBA_Policy_ptr operator-> (void);

private:
  CORBA_Policy_ptr &ptr_;
};

class TAO_Export  CORBA_Policy : public virtual CORBA_Object
{
public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_Policy_ptr _ptr_type;
  typedef CORBA_Policy_var _var_type;
#endif /* __GNUC__ */

  // the static operations
  static CORBA_Policy_ptr _duplicate (CORBA_Policy_ptr obj);
  static CORBA_Policy_ptr _narrow (
      CORBA::Object_ptr obj,
      CORBA_Environment &TAO_IN_ENV =
        TAO_default_environment ()
    );
  static CORBA_Policy_ptr _unchecked_narrow (
      CORBA::Object_ptr obj,
      CORBA_Environment &TAO_IN_ENV =
        TAO_default_environment ()
    );
  static CORBA_Policy_ptr _nil (void);

  virtual CORBA::PolicyType policy_type (
      CORBA_Environment &TAO_IN_ENV =
        TAO_default_environment ()
    );
  virtual CORBA_Policy_ptr copy (
      CORBA_Environment &TAO_IN_ENV =
        TAO_default_environment ()
    );
  virtual void destroy (
      CORBA_Environment &TAO_IN_ENV =
        TAO_default_environment ()
    );
  virtual CORBA::Boolean _is_a (
      const CORBA::Char *type_id,
      CORBA_Environment &TAO_IN_ENV =
        TAO_default_environment ()
    );
  virtual const char* _interface_repository_id (void) const;
protected:
  CORBA_Policy (void); // default constructor
  CORBA_Policy (TAO_Stub *objref,
                TAO_ServantBase *_tao_servant = 0,
                CORBA::Boolean _tao_collocated = 0
                );
  virtual ~CORBA_Policy (void);
private:
  CORBA_Policy (const CORBA_Policy &);
  void operator= (const CORBA_Policy &);
};

// *************************************************************
// CORBA_PolicyList
// *************************************************************

class TAO_Export  CORBA_PolicyList : public TAO_Unbounded_Object_Sequence<CORBA_Policy>
{
public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_PolicyList_ptr _ptr_type;
  typedef CORBA_PolicyList_var _var_type;
#endif /* __GNUC__ */

  CORBA_PolicyList (void); // default ctor
  CORBA_PolicyList (CORBA::ULong max); // uses max size
  CORBA_PolicyList (
      CORBA::ULong max,
      CORBA::ULong length,
      CORBA_Policy_ptr *buffer,
      CORBA::Boolean release=0
    );
  CORBA_PolicyList (const CORBA_PolicyList &); // copy ctor
  ~CORBA_PolicyList (void); // dtor
};
typedef CORBA_PolicyList *CORBA_PolicyList_ptr;

// *************************************************************
// class CORBA::PolicyList_var
// *************************************************************

class TAO_Export  CORBA_PolicyList_var
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
  TAO_Object_Manager <CORBA_Policy > operator[] (CORBA::ULong index);
  // in, inout, out, _retn
  const CORBA_PolicyList &in (void) const;
  CORBA_PolicyList &inout (void);
  CORBA_PolicyList *&out (void);
  CORBA_PolicyList *_retn (void);
  CORBA_PolicyList *ptr (void) const;

private:
  CORBA_PolicyList *ptr_;
};

class TAO_Export  CORBA_PolicyList_out
{
public:
  CORBA_PolicyList_out (CORBA_PolicyList *&);
  CORBA_PolicyList_out (CORBA_PolicyList_var &);
  CORBA_PolicyList_out (CORBA_PolicyList_out &);
  CORBA_PolicyList_out &operator= (CORBA_PolicyList_out &);
  CORBA_PolicyList_out &operator= (CORBA_PolicyList *);
  operator CORBA_PolicyList *&();
  CORBA_PolicyList *&ptr (void);
  CORBA_PolicyList *operator-> (void);
  TAO_Object_Manager <CORBA_Policy > operator[] (CORBA::ULong index);

private:
  CORBA_PolicyList *&ptr_;
  // assignment from T_var not allowed
  void operator= (const CORBA_PolicyList_var &);
};

// *************************************************************
// PolicyTypeSeq
// *************************************************************

class TAO_Export CORBA_PolicyTypeSeq : public TAO_Unbounded_Sequence<CORBA::ULong>
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
  ~CORBA_PolicyTypeSeq (void); // dtor
};
typedef CORBA_PolicyTypeSeq *CORBA_PolicyTypeSeq_ptr;

// *************************************************************
// class CORBA::PolicyTypeSeq_var
// *************************************************************

class TAO_Export CORBA_PolicyTypeSeq_var
{
public:
  CORBA_PolicyTypeSeq_var (void); // default constructor
  CORBA_PolicyTypeSeq_var (CORBA_PolicyTypeSeq *);
  CORBA_PolicyTypeSeq_var (const CORBA_PolicyTypeSeq_var &);
  ~CORBA_PolicyTypeSeq_var (void); // destructor

  CORBA_PolicyTypeSeq_var &operator= (CORBA_PolicyTypeSeq *);
  CORBA_PolicyTypeSeq_var &operator= (const CORBA_PolicyTypeSeq_var &);
  CORBA_PolicyTypeSeq *operator-> (void);
  const CORBA_PolicyTypeSeq *operator-> (void) const;

  operator const CORBA_PolicyTypeSeq &() const;
  operator CORBA_PolicyTypeSeq &();
  operator CORBA_PolicyTypeSeq &() const;
  CORBA::PolicyType &operator[] (CORBA::ULong slot);
  // in, inout, out, _retn
  const CORBA_PolicyTypeSeq &in (void) const;
  CORBA_PolicyTypeSeq &inout (void);
  CORBA_PolicyTypeSeq *&out (void);
  CORBA_PolicyTypeSeq *_retn (void);
  CORBA_PolicyTypeSeq *ptr (void) const;

private:
  CORBA_PolicyTypeSeq *ptr_;
};

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
  CORBA::PolicyType &operator[] (CORBA::ULong slot);

private:
  CORBA_PolicyTypeSeq *&ptr_;
  // assignment from T_var not allowed
  void operator= (const CORBA_PolicyTypeSeq_var &);
};

class TAO_Export CORBA_PolicyManager_var
{
public:
  CORBA_PolicyManager_var (void); // default constructor
  CORBA_PolicyManager_var (CORBA_PolicyManager_ptr);
  CORBA_PolicyManager_var (const CORBA_PolicyManager_var &);
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
};

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

class TAO_Export CORBA_PolicyManager : public virtual CORBA_Object
{
public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_PolicyManager_ptr _ptr_type;
  typedef CORBA_PolicyManager_var _var_type;
#endif /* __GNUC__ */

  // the static operations
  static CORBA_PolicyManager_ptr _duplicate (CORBA_PolicyManager_ptr obj);
  static CORBA_PolicyManager_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
  static CORBA_PolicyManager_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
  static CORBA_PolicyManager_ptr _nil (void);

  virtual CORBA_PolicyList * get_policy_overrides (
        const CORBA_PolicyTypeSeq & ts,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
  virtual void set_policy_overrides (
        const CORBA_PolicyList & policies,
        CORBA::SetOverrideType set_add,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
  virtual CORBA::Boolean _is_a (
        const CORBA::Char *type_id,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
  virtual const char* _interface_repository_id (void) const;
protected:
  CORBA_PolicyManager (void); // default constructor
  CORBA_PolicyManager (TAO_Stub *objref,
        TAO_ServantBase *_tao_servant = 0,
        CORBA::Boolean _tao_collocated = 0
      );
  virtual ~CORBA_PolicyManager (void);
private:
  CORBA_PolicyManager (const CORBA_PolicyManager &);
  void operator= (const CORBA_PolicyManager &);
};

// ****************************************************************

class TAO_Export CORBA_PolicyCurrent_var
{
public:
  CORBA_PolicyCurrent_var (void); // default constructor
  CORBA_PolicyCurrent_var (CORBA_PolicyCurrent_ptr);
  CORBA_PolicyCurrent_var (const CORBA_PolicyCurrent_var &);
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
};

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

class TAO_Export CORBA_PolicyCurrent: public virtual CORBA_PolicyManager, public virtual CORBA_Current
{
public:
#if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
  typedef CORBA_PolicyCurrent_ptr _ptr_type;
  typedef CORBA_PolicyCurrent_var _var_type;
#endif /* __GNUC__ */

  // the static operations
  static CORBA_PolicyCurrent_ptr _duplicate (CORBA_PolicyCurrent_ptr obj);
  static CORBA_PolicyCurrent_ptr _narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
  static CORBA_PolicyCurrent_ptr _unchecked_narrow (
        CORBA::Object_ptr obj,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
  static CORBA_PolicyCurrent_ptr _nil (void);

  virtual CORBA::Boolean _is_a (
        const CORBA::Char *type_id,
        CORBA::Environment &env =
          TAO_default_environment ()
      );
  virtual const char* _interface_repository_id (void) const;
protected:
  CORBA_PolicyCurrent (void); // default constructor
  CORBA_PolicyCurrent (TAO_Stub *objref,
        TAO_ServantBase *_tao_servant = 0,
        CORBA::Boolean _tao_collocated = 0
      );
  virtual ~CORBA_PolicyCurrent (void);
private:
  CORBA_PolicyCurrent (const CORBA_PolicyCurrent &);
  void operator= (const CORBA_PolicyCurrent &);
};

// ****************************************************************

void TAO_Export operator<<= (CORBA::Any &,
                             const CORBA::PolicyError &);
void TAO_Export operator<<= (CORBA::Any &, CORBA::PolicyError*);
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &,
                                       CORBA::PolicyError *&);
void TAO_Export operator<<= (CORBA::Any &,
                             const CORBA::InvalidPolicies &);
void TAO_Export operator<<= (CORBA::Any &,
                             CORBA::InvalidPolicies*);
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &,
                                       CORBA::InvalidPolicies *&);

// Any operators for interface CORBA::Policy
void TAO_Export operator<<= (CORBA::Any &,
                             CORBA::Policy_ptr);
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &,
                                       CORBA::Policy *&);
void TAO_Export operator<<= (CORBA::Any &,
                             const CORBA::PolicyList &);
void TAO_Export operator<<= (CORBA::Any &,
                             CORBA::PolicyList*);
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &,
                                       CORBA::PolicyList *&);
void TAO_Export operator<<= (CORBA::Any &,
                             const CORBA::PolicyTypeSeq &);
void TAO_Export operator<<= (CORBA::Any &,
                             CORBA::PolicyTypeSeq*);
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &,
                                       CORBA::PolicyTypeSeq *&);
void TAO_Export operator<<= (CORBA::Any &,
                             CORBA::SetOverrideType);
CORBA::Boolean TAO_Export operator>>= (const CORBA::Any &,
                                       CORBA::SetOverrideType &);

// ****************************************************************

#if defined (__ACE_INLINE__)
#include "PolicyC.i"
#else

CORBA::Boolean TAO_Export
operator<< (TAO_OutputCDR &, const CORBA::PolicyError &);
CORBA::Boolean TAO_Export
operator>> (TAO_InputCDR &, CORBA::PolicyError &);
CORBA::Boolean TAO_Export
operator<< (TAO_OutputCDR &, const CORBA::InvalidPolicies &);
CORBA::Boolean TAO_Export
operator>> (TAO_InputCDR &, CORBA::InvalidPolicies &);
CORBA::Boolean TAO_Export
operator<< (TAO_OutputCDR &, const CORBA::InvalidPolicies::_tao_seq_UShort &);
CORBA::Boolean TAO_Export
operator>> (TAO_InputCDR &, CORBA::InvalidPolicies::_tao_seq_UShort &);
CORBA::Boolean TAO_Export
operator<< (TAO_OutputCDR &, const CORBA::Policy_ptr );
CORBA::Boolean TAO_Export
operator>> (TAO_InputCDR &, CORBA::Policy_ptr &);
CORBA::Boolean TAO_Export
operator<< (TAO_OutputCDR &, const CORBA::PolicyList &);
CORBA::Boolean TAO_Export
operator>> (TAO_InputCDR &, CORBA::PolicyList &);
CORBA::Boolean TAO_Export
operator<< (TAO_OutputCDR &, const CORBA::PolicyTypeSeq &);
CORBA::Boolean TAO_Export
operator>> (TAO_InputCDR &, CORBA::PolicyTypeSeq &);
CORBA::Boolean TAO_Export
operator<< (TAO_OutputCDR &, const CORBA::SetOverrideType &);
CORBA::Boolean TAO_Export
operator>> (TAO_InputCDR &, CORBA::SetOverrideType &);

#endif /* defined INLINE */

#endif /* TAO_IDL_POLICYC_H */
