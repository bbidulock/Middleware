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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_POLICYC_H_
#define _TAO_IDL_ORIG_POLICYC_H_

#include "ace/pre.h"
#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "CurrentC.h"
#include "Policy_ForwardC.h"
#include "Exception.h"
#include "Remote_Object_Proxy_Impl.h"
#include "Encodable.h"

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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  CORBA
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:334
  
  typedef CORBA::Short PolicyErrorCode;
  typedef CORBA::Short_out PolicyErrorCode_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_PolicyErrorCode;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short BAD_POLICY = 0;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short UNSUPPORTED_POLICY = 1;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short BAD_POLICY_TYPE = 2;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short BAD_POLICY_VALUE = 3;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short UNSUPPORTED_POLICY_VALUE = 4;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_CORBA_POLICYERROR_CH_)
#define _CORBA_POLICYERROR_CH_
  
  class TAO_Export PolicyError : public CORBA::UserException
  {
  public:
    
    CORBA::PolicyErrorCode reason;
    PolicyError (void);
    PolicyError (const PolicyError &);
    ~PolicyError (void);

    PolicyError &operator= (const PolicyError &);
    
    static void _tao_any_destructor (void *);
    
    static PolicyError *_downcast (CORBA::Exception *);
    static CORBA::Exception *_alloc (void);

    virtual CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &
        ACE_ENV_ARG_DECL_NOT_USED
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &
        ACE_ENV_ARG_DECL_NOT_USED
      );
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ctor.cpp:66
    
    PolicyError (
        ACE_NESTED_CLASS (CORBA, PolicyErrorCode) _tao_reason
      );
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:125
    
    virtual CORBA::TypeCode_ptr _type (void) const;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_PolicyError;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_CORBA_INVALIDPOLICIES_CH_)
#define _CORBA_INVALIDPOLICIES_CH_
  
  class TAO_Export InvalidPolicies : public CORBA::UserException
  {
  public:
    
    
    
    // TAO_IDL - Generated from 
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_ch.cpp:65

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT_CH_
    
    class TAO_Export _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort
      : public TAO_Unbounded_Base_Sequence
    {
    public:
      _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (void);
      _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (CORBA::ULong maximum); 
      _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (
          CORBA::ULong maximum,
          CORBA::ULong length,
          CORBA::UShort *data,
          CORBA::Boolean release = 0
        );
      _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (
          const _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort &rhs
        );
      _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort &operator= (
          const _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort &rhs
        );
      virtual ~_TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort (void);
      
      // = Accessors.
      CORBA::UShort &operator[] (CORBA::ULong i);
      const CORBA::UShort &operator[] (CORBA::ULong i) const;
      
      // = Static operations.
      static CORBA::UShort *allocbuf (CORBA::ULong size);
      static void freebuf (CORBA::UShort *buffer);
      
      // Implement the TAO_Base_Sequence methods (see Sequence.h)
      virtual void _allocate_buffer (CORBA::ULong length);
      virtual void _deallocate_buffer (void);
      CORBA::UShort *get_buffer (CORBA::Boolean orphan = 0);
      const CORBA::UShort *get_buffer (void) const;
      void replace (
          CORBA::ULong max,
          CORBA::ULong length,
          CORBA::UShort *data,
          CORBA::Boolean release
        );
    };

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT_CH_)
#define _CORBA_INVALIDPOLICIES__TAO_SEQ_USHORT_CH_
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:371
    
    class _tao_seq_UShort;
    
    // *************************************************************
    // CORBA::InvalidPolicies::_tao_seq_UShort
    // *************************************************************
    
    class TAO_Export _tao_seq_UShort : public 
    
    // TAO_IDL - Generated from 
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:51

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
    _TAO_Unbounded_Sequence_CORBA_InvalidPolicies__tao_seq_UShort
#else /* TAO_USE_SEQUENCE_TEMPLATES */
    TAO_Unbounded_Sequence<CORBA::UShort>

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 
    {
    public:
      _tao_seq_UShort (void);
      _tao_seq_UShort (CORBA::ULong max);
      _tao_seq_UShort (
          CORBA::ULong max, 
          CORBA::ULong length, 
          CORBA::UShort *buffer, 
          CORBA::Boolean release = 0
        );
      _tao_seq_UShort (const _tao_seq_UShort &);
      ~_tao_seq_UShort (void);
      
      static void _tao_any_destructor (void*);
      
      
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_field/field_ch.cpp:447
    
    typedef _tao_seq_UShort _indices_seq;
    _tao_seq_UShort indices;
    InvalidPolicies (void);
    InvalidPolicies (const InvalidPolicies &);
    ~InvalidPolicies (void);

    InvalidPolicies &operator= (const InvalidPolicies &);
    
    static void _tao_any_destructor (void *);
    
    static InvalidPolicies *_downcast (CORBA::Exception *);
    static CORBA::Exception *_alloc (void);

    virtual CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &
        ACE_ENV_ARG_DECL_NOT_USED
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &
        ACE_ENV_ARG_DECL_NOT_USED
      );
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ctor.cpp:66
    
    InvalidPolicies (
        const _tao_seq_UShort & _tao_indices
      );
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:125
    
    virtual CORBA::TypeCode_ptr _type (void) const;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_InvalidPolicies;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:52

#if !defined (_CORBA_POLICY___PTR_CH_)
#define _CORBA_POLICY___PTR_CH_
  
  class Policy;
  typedef Policy *Policy_ptr;

#endif /* end #if !defined */

#if !defined (_CORBA_POLICY___VAR_CH_)
#define _CORBA_POLICY___VAR_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:571
  
  class TAO_Export Policy_var : public TAO_Base_var
  {
  public:
    Policy_var (void); // default constructor
    Policy_var (Policy_ptr p) : ptr_ (p) {} 
    Policy_var (const Policy_var &); // copy constructor
    ~Policy_var (void); // destructor
    
    Policy_var &operator= (Policy_ptr);
    Policy_var &operator= (const Policy_var &);
    Policy_ptr operator-> (void) const;
    
    operator const Policy_ptr &() const;
    operator Policy_ptr &();
    // in, inout, out, _retn 
    Policy_ptr in (void) const;
    Policy_ptr &inout (void);
    Policy_ptr &out (void);
    Policy_ptr _retn (void);
    Policy_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static Policy_ptr tao_duplicate (Policy_ptr);
    static void tao_release (Policy_ptr);
    static Policy_ptr tao_nil (void);
    static Policy_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    Policy_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    Policy_var (const TAO_Base_var &rhs);
    Policy_var &operator= (const TAO_Base_var &rhs);
  };

#endif /* end #if !defined */

#if !defined (_CORBA_POLICY___OUT_CH_)
#define _CORBA_POLICY___OUT_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:946
  
  class TAO_Export Policy_out
  {
  public:
    Policy_out (Policy_ptr &);
    Policy_out (Policy_var &);
    Policy_out (const Policy_out &);
    Policy_out &operator= (const Policy_out &);
    Policy_out &operator= (const Policy_var &);
    Policy_out &operator= (Policy_ptr);
    operator Policy_ptr &();
    Policy_ptr &ptr (void);
    Policy_ptr operator-> (void);
  
  private:
    Policy_ptr &ptr_;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:110

#if !defined (_CORBA_POLICY_CH_)
#define _CORBA_POLICY_CH_
  
  class _TAO_Policy_Proxy_Impl;
  class _TAO_Policy_Remote_Proxy_Impl;
  class _TAO_Policy_Proxy_Broker;
  class _TAO_Policy_Remote_Proxy_Broker;
  
  class TAO_Export Policy
    : public virtual CORBA::Object
    // ****************************************************************
    , public virtual TAO_Encodable
    // ****************************************************************
  {
  public:
    typedef Policy_ptr _ptr_type;
    typedef Policy_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static Policy_ptr _duplicate (Policy_ptr obj);
    
    static Policy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Policy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Policy_ptr _nil (void)
      {
        return (Policy_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::PolicyType policy_type (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr copy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:267
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

    // ****************************************************************
    virtual CORBA::Boolean _tao_encode (TAO_OutputCDR &);
    virtual CORBA::Boolean _tao_decode (TAO_InputCDR &);
    virtual TAO_Cached_Policy_Type _tao_cached_type (void) const;
    virtual TAO_Policy_Scope _tao_scope (void) const;
    // ****************************************************************

  private:
    _TAO_Policy_Proxy_Broker *the_TAO_Policy_Proxy_Broker_;
  
  protected:
    Policy (int collocated = 0);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void CORBA_Policy_setup_collocation (int collocated);
    
    Policy (
        TAO_Stub *objref, 
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0
      );
    virtual ~Policy (void);
    
    friend class _TAO_Policy_Remote_Proxy_Impl;
    friend class _TAO_Policy_ThruPOA_Proxy_Impl;
    friend class _TAO_Policy_Direct_Proxy_Impl;
  
  private:
    Policy (const Policy &);
    void operator= (const Policy &);
  };
  
  // The Proxy Implementations are used by each interface to
  // perform a call. Each different implementation encapsulates
  // an invocation logic.
  
  
  ///////////////////////////////////////////////////////////////////////
  //                    Base Proxy Impl. Declaration
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/base_proxy_impl_ch.cpp:35
  
  class TAO_Export _TAO_Policy_Proxy_Impl
    : public virtual TAO_Object_Proxy_Impl
  {
  public:
    virtual ~_TAO_Policy_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/base_proxy_impl_ch.cpp:24
    
    virtual CORBA::PolicyType policy_type (
        CORBA::Object *_collocated_tao_target_
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/base_proxy_impl_ch.cpp:24
    
    virtual ::CORBA::Policy_ptr copy (
        CORBA::Object *_collocated_tao_target_
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/base_proxy_impl_ch.cpp:24
    
    virtual void destroy (
        CORBA::Object *_collocated_tao_target_
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
  
  protected:
    _TAO_Policy_Proxy_Impl (void);
  };
  
  //
  //               End Base Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////
  
  
  ///////////////////////////////////////////////////////////////////////
  //                Remote Proxy Impl. Declaration
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/remote_proxy_impl_ch.cpp:37
  
  class TAO_Export _TAO_Policy_Remote_Proxy_Impl
    : public virtual _TAO_Policy_Proxy_Impl,
      public virtual TAO_Remote_Object_Proxy_Impl
  {
  public:
    _TAO_Policy_Remote_Proxy_Impl (void);
    
    virtual ~_TAO_Policy_Remote_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    virtual CORBA::PolicyType policy_type (
        CORBA::Object *_collocated_tao_target_
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    virtual ::CORBA::Policy_ptr copy (
        CORBA::Object *_collocated_tao_target_
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    virtual void destroy (
        CORBA::Object *_collocated_tao_target_
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  };
  
  //
  //             End Remote Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////
  
  // The Proxy Brokers are used by each interface to get
  // the right proxy for performing a call. In the new 
  // collocation scheme, the proxy to be used can vary on
  // a call by call basis.
  
  ///////////////////////////////////////////////////////////////////////
  //                 Base Proxy Broker Declaration 
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/base_proxy_broker_ch.cpp:35
  
  class TAO_Export _TAO_Policy_Proxy_Broker
  {
  public:
    virtual ~_TAO_Policy_Proxy_Broker (void);
    virtual _TAO_Policy_Proxy_Impl &select_proxy (
        Policy *object
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
  protected:
    _TAO_Policy_Proxy_Broker (void);
    
  };
  
  //
  //              End Base Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////
  
    
  ///////////////////////////////////////////////////////////////////////
  //                 Remote Proxy Broker Declaration 
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/remote_proxy_broker_ch.cpp:40
  
  class TAO_Export _TAO_Policy_Remote_Proxy_Broker
    : public virtual _TAO_Policy_Proxy_Broker
  {
  public: 
    _TAO_Policy_Remote_Proxy_Broker (void);
    
    virtual ~_TAO_Policy_Remote_Proxy_Broker (void);
    
    virtual _TAO_Policy_Proxy_Impl &select_proxy (
        Policy *object
        ACE_ENV_ARG_DECL
      );
    
  private:
    _TAO_Policy_Remote_Proxy_Impl remote_proxy_impl_;
  
  public:
    // This member function is used to get an handle to the unique instance
    // of the Remote Proxy Broker that is available for a given
    // interface.
    static _TAO_Policy_Remote_Proxy_Broker *the_TAO_Policy_Remote_Proxy_Broker (void);
  };
  
  //
  //              End Remote Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Policy;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:52

#if !defined (_CORBA_POLICYMANAGER___PTR_CH_)
#define _CORBA_POLICYMANAGER___PTR_CH_
  
  class PolicyManager;
  typedef PolicyManager *PolicyManager_ptr;

#endif /* end #if !defined */

#if !defined (_CORBA_POLICYMANAGER___VAR_CH_)
#define _CORBA_POLICYMANAGER___VAR_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:571
  
  class TAO_Export PolicyManager_var : public TAO_Base_var
  {
  public:
    PolicyManager_var (void); // default constructor
    PolicyManager_var (PolicyManager_ptr p) : ptr_ (p) {} 
    PolicyManager_var (const PolicyManager_var &); // copy constructor
    ~PolicyManager_var (void); // destructor
    
    PolicyManager_var &operator= (PolicyManager_ptr);
    PolicyManager_var &operator= (const PolicyManager_var &);
    PolicyManager_ptr operator-> (void) const;
    
    operator const PolicyManager_ptr &() const;
    operator PolicyManager_ptr &();
    // in, inout, out, _retn 
    PolicyManager_ptr in (void) const;
    PolicyManager_ptr &inout (void);
    PolicyManager_ptr &out (void);
    PolicyManager_ptr _retn (void);
    PolicyManager_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static PolicyManager_ptr tao_duplicate (PolicyManager_ptr);
    static void tao_release (PolicyManager_ptr);
    static PolicyManager_ptr tao_nil (void);
    static PolicyManager_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    PolicyManager_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    PolicyManager_var (const TAO_Base_var &rhs);
    PolicyManager_var &operator= (const TAO_Base_var &rhs);
  };

#endif /* end #if !defined */

#if !defined (_CORBA_POLICYMANAGER___OUT_CH_)
#define _CORBA_POLICYMANAGER___OUT_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:946
  
  class TAO_Export PolicyManager_out
  {
  public:
    PolicyManager_out (PolicyManager_ptr &);
    PolicyManager_out (PolicyManager_var &);
    PolicyManager_out (const PolicyManager_out &);
    PolicyManager_out &operator= (const PolicyManager_out &);
    PolicyManager_out &operator= (const PolicyManager_var &);
    PolicyManager_out &operator= (PolicyManager_ptr);
    operator PolicyManager_ptr &();
    PolicyManager_ptr &ptr (void);
    PolicyManager_ptr operator-> (void);
  
  private:
    PolicyManager_ptr &ptr_;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:110

#if !defined (_CORBA_POLICYMANAGER_CH_)
#define _CORBA_POLICYMANAGER_CH_
  
  class TAO_Export PolicyManager
    : public virtual CORBA::Object
  {
  public:
    typedef PolicyManager_ptr _ptr_type;
    typedef PolicyManager_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static PolicyManager_ptr _duplicate (PolicyManager_ptr obj);
    
    static PolicyManager_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PolicyManager_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PolicyManager_ptr _nil (void)
      {
        return (PolicyManager_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::PolicyList * get_policy_overrides (
        const CORBA::PolicyTypeSeq & ts
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void set_policy_overrides (
        const CORBA::PolicyList & policies,
        CORBA::SetOverrideType set_add
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , CORBA::InvalidPolicies
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:267
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    PolicyManager (void);
    virtual ~PolicyManager (void);
    
  private:
    PolicyManager (const PolicyManager &);
    void operator= (const PolicyManager &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_PolicyManager;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:52

#if !defined (_CORBA_POLICYCURRENT___PTR_CH_)
#define _CORBA_POLICYCURRENT___PTR_CH_
  
  class PolicyCurrent;
  typedef PolicyCurrent *PolicyCurrent_ptr;

#endif /* end #if !defined */

#if !defined (_CORBA_POLICYCURRENT___VAR_CH_)
#define _CORBA_POLICYCURRENT___VAR_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:571
  
  class TAO_Export PolicyCurrent_var : public TAO_Base_var
  {
  public:
    PolicyCurrent_var (void); // default constructor
    PolicyCurrent_var (PolicyCurrent_ptr p) : ptr_ (p) {} 
    PolicyCurrent_var (const PolicyCurrent_var &); // copy constructor
    ~PolicyCurrent_var (void); // destructor
    
    PolicyCurrent_var &operator= (PolicyCurrent_ptr);
    PolicyCurrent_var &operator= (const PolicyCurrent_var &);
    PolicyCurrent_ptr operator-> (void) const;
    
    operator const PolicyCurrent_ptr &() const;
    operator PolicyCurrent_ptr &();
    // in, inout, out, _retn 
    PolicyCurrent_ptr in (void) const;
    PolicyCurrent_ptr &inout (void);
    PolicyCurrent_ptr &out (void);
    PolicyCurrent_ptr _retn (void);
    PolicyCurrent_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static PolicyCurrent_ptr tao_duplicate (PolicyCurrent_ptr);
    static void tao_release (PolicyCurrent_ptr);
    static PolicyCurrent_ptr tao_nil (void);
    static PolicyCurrent_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    PolicyCurrent_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    PolicyCurrent_var (const TAO_Base_var &rhs);
    PolicyCurrent_var &operator= (const TAO_Base_var &rhs);
  };

#endif /* end #if !defined */

#if !defined (_CORBA_POLICYCURRENT___OUT_CH_)
#define _CORBA_POLICYCURRENT___OUT_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:946
  
  class TAO_Export PolicyCurrent_out
  {
  public:
    PolicyCurrent_out (PolicyCurrent_ptr &);
    PolicyCurrent_out (PolicyCurrent_var &);
    PolicyCurrent_out (const PolicyCurrent_out &);
    PolicyCurrent_out &operator= (const PolicyCurrent_out &);
    PolicyCurrent_out &operator= (const PolicyCurrent_var &);
    PolicyCurrent_out &operator= (PolicyCurrent_ptr);
    operator PolicyCurrent_ptr &();
    PolicyCurrent_ptr &ptr (void);
    PolicyCurrent_ptr operator-> (void);
  
  private:
    PolicyCurrent_ptr &ptr_;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:110

#if !defined (_CORBA_POLICYCURRENT_CH_)
#define _CORBA_POLICYCURRENT_CH_
  
  class TAO_Export PolicyCurrent
    : public virtual CORBA::PolicyManager,
      public virtual CORBA::Current
  {
  public:
    typedef PolicyCurrent_ptr _ptr_type;
    typedef PolicyCurrent_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static PolicyCurrent_ptr _duplicate (PolicyCurrent_ptr obj);
    
    static PolicyCurrent_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PolicyCurrent_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static PolicyCurrent_ptr _nil (void)
      {
        return (PolicyCurrent_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:267
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    PolicyCurrent (void);
    virtual ~PolicyCurrent (void);
    
  private:
    PolicyCurrent (const PolicyCurrent &);
    void operator= (const PolicyCurrent &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_PolicyCurrent;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module CORBA

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:80

extern TAO_Export
CORBA::_TAO_Policy_Proxy_Broker *
(*CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::PolicyError &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::PolicyError*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::PolicyError *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::PolicyError *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const CORBA::InvalidPolicies &); // copying version
TAO_Export void operator<<= (CORBA::Any &, CORBA::InvalidPolicies*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::InvalidPolicies *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const CORBA::InvalidPolicies *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, CORBA::Policy_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, CORBA::Policy_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::Policy_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, CORBA::PolicyManager_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, CORBA::PolicyManager_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::PolicyManager_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, CORBA::PolicyCurrent_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, CORBA::PolicyCurrent_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::PolicyCurrent_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::PolicyError &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::PolicyError &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::InvalidPolicies &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::InvalidPolicies &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:57

#if !defined _TAO_CDR_OP_CORBA_InvalidPolicies__tao_seq_UShort_H_
#define _TAO_CDR_OP_CORBA_InvalidPolicies__tao_seq_UShort_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::InvalidPolicies::_tao_seq_UShort &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::InvalidPolicies::_tao_seq_UShort &
  );

#endif /* _TAO_CDR_OP_CORBA_InvalidPolicies__tao_seq_UShort_H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ch.cpp:55

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::Policy_ptr );
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::Policy_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1009

#if defined (__ACE_INLINE__)
#include "PolicyC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */

