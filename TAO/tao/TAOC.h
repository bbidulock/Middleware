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

#ifndef _TAO_IDL_ORIG_TAOC_H_
#define _TAO_IDL_ORIG_TAOC_H_

#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "PolicyC.h"
#include "TimeBaseC.h"

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

TAO_NAMESPACE  TAO
{
#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:334
  
  typedef CORBA::UShort BufferingConstraintMode;
  typedef CORBA::UShort_out BufferingConstraintMode_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_BufferingConstraintMode;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::UShort BUFFER_FLUSH = 0U;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::UShort BUFFER_TIMEOUT = 1U;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::UShort BUFFER_MESSAGE_COUNT = 2U;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::UShort BUFFER_MESSAGE_BYTES = 4U;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:49
  
  class BufferingConstraint_var;
  
  struct TAO_Export BufferingConstraint
  {
    typedef BufferingConstraint_var _var_type;
    
    static void _tao_any_destructor (void *);
    TAO::BufferingConstraintMode mode;
    TimeBase::TimeT timeout;
    CORBA::ULong message_count;
    CORBA::ULong message_bytes;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:71
  
  class TAO_Export BufferingConstraint_var
  {
  public:
    BufferingConstraint_var (void);
    BufferingConstraint_var (BufferingConstraint *);
    BufferingConstraint_var (const BufferingConstraint_var &);
    // Fixed-size types only.
    BufferingConstraint_var (const BufferingConstraint &);
    ~BufferingConstraint_var (void);
    
    BufferingConstraint_var &operator= (BufferingConstraint *);
    BufferingConstraint_var &operator= (const BufferingConstraint_var &);
    
    // Fixed-size types only.
    BufferingConstraint_var &operator= (const BufferingConstraint &);
    
    BufferingConstraint *operator-> (void);
    const BufferingConstraint *operator-> (void) const;
    
    operator const BufferingConstraint &() const;
    operator BufferingConstraint &();
    operator BufferingConstraint &() const;
    
    // in, inout, out, _retn 
    const BufferingConstraint &in (void) const;
    BufferingConstraint &inout (void);
    BufferingConstraint &out (void);
    BufferingConstraint _retn (void);
    BufferingConstraint *ptr (void) const;
  
  private:
    BufferingConstraint *ptr_;
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:105
  
  typedef BufferingConstraint &BufferingConstraint_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_BufferingConstraint;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::ULong BUFFERING_CONSTRAINT_POLICY_TYPE = 1413545985U;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:52

#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___PTR_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___PTR_CH_
  
  class BufferingConstraintPolicy;
  typedef BufferingConstraintPolicy *BufferingConstraintPolicy_ptr;

#endif /* end #if !defined */

#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___VAR_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___VAR_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:571
  
  class TAO_Export BufferingConstraintPolicy_var : public TAO_Base_var
  {
  public:
    BufferingConstraintPolicy_var (void); // default constructor
    BufferingConstraintPolicy_var (BufferingConstraintPolicy_ptr p) : ptr_ (p) {} 
    BufferingConstraintPolicy_var (const BufferingConstraintPolicy_var &); // copy constructor
    ~BufferingConstraintPolicy_var (void); // destructor
    
    BufferingConstraintPolicy_var &operator= (BufferingConstraintPolicy_ptr);
    BufferingConstraintPolicy_var &operator= (const BufferingConstraintPolicy_var &);
    BufferingConstraintPolicy_ptr operator-> (void) const;
    
    operator const BufferingConstraintPolicy_ptr &() const;
    operator BufferingConstraintPolicy_ptr &();
    // in, inout, out, _retn 
    BufferingConstraintPolicy_ptr in (void) const;
    BufferingConstraintPolicy_ptr &inout (void);
    BufferingConstraintPolicy_ptr &out (void);
    BufferingConstraintPolicy_ptr _retn (void);
    BufferingConstraintPolicy_ptr ptr (void) const;
    
    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static BufferingConstraintPolicy_ptr tao_duplicate (BufferingConstraintPolicy_ptr);
    static void tao_release (BufferingConstraintPolicy_ptr);
    static BufferingConstraintPolicy_ptr tao_nil (void);
    static BufferingConstraintPolicy_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);
  
  private:
    BufferingConstraintPolicy_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    BufferingConstraintPolicy_var (const TAO_Base_var &rhs);
    BufferingConstraintPolicy_var &operator= (const TAO_Base_var &rhs);
  };

#endif /* end #if !defined */

#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___OUT_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___OUT_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:946
  
  class TAO_Export BufferingConstraintPolicy_out
  {
  public:
    BufferingConstraintPolicy_out (BufferingConstraintPolicy_ptr &);
    BufferingConstraintPolicy_out (BufferingConstraintPolicy_var &);
    BufferingConstraintPolicy_out (const BufferingConstraintPolicy_out &);
    BufferingConstraintPolicy_out &operator= (const BufferingConstraintPolicy_out &);
    BufferingConstraintPolicy_out &operator= (const BufferingConstraintPolicy_var &);
    BufferingConstraintPolicy_out &operator= (BufferingConstraintPolicy_ptr);
    operator BufferingConstraintPolicy_ptr &();
    BufferingConstraintPolicy_ptr &ptr (void);
    BufferingConstraintPolicy_ptr operator-> (void);
  
  private:
    BufferingConstraintPolicy_ptr &ptr_;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:110

#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY_CH_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY_CH_
  
  class TAO_Export BufferingConstraintPolicy
    : public virtual CORBA::Policy
  {
  public:
    typedef BufferingConstraintPolicy_ptr _ptr_type;
    typedef BufferingConstraintPolicy_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static BufferingConstraintPolicy_ptr _duplicate (BufferingConstraintPolicy_ptr obj);
    
    static BufferingConstraintPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static BufferingConstraintPolicy_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static BufferingConstraintPolicy_ptr _nil (void)
      {
        return (BufferingConstraintPolicy_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::TAO::BufferingConstraint buffering_constraint (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:267
    
    virtual void *_tao_QueryInterface (ptr_arith_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    BufferingConstraintPolicy (void);
    virtual ~BufferingConstraintPolicy (void);
    
    friend class _TAO_BufferingConstraintPolicy_Remote_Proxy_Impl;
    friend class _TAO_BufferingConstraintPolicy_ThruPOA_Proxy_Impl;
    friend class _TAO_BufferingConstraintPolicy_Direct_Proxy_Impl;
  
  private:
    BufferingConstraintPolicy (const BufferingConstraintPolicy &);
    void operator= (const BufferingConstraintPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_BufferingConstraintPolicy;
  
#endif  /* TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1 */

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short SYNC_EAGER_BUFFERING = 0;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::Short SYNC_DELAYED_BUFFERING = -2;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module TAO

#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const TAO::BufferingConstraint &); // copying version
TAO_Export void operator<<= (CORBA::Any &, TAO::BufferingConstraint*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO::BufferingConstraint *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO::BufferingConstraint *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, TAO::BufferingConstraintPolicy_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, TAO::BufferingConstraintPolicy_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO::BufferingConstraintPolicy_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO::BufferingConstraint &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO::BufferingConstraint &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1009

#if defined (__ACE_INLINE__)
#include "TAOC.i"
#endif /* defined INLINE */

#endif  /* TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1 */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */

