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

#ifndef _TAO_IDL_ORIG_MESSAGINGC_H_
#define _TAO_IDL_ORIG_MESSAGINGC_H_

#include "ace/pre.h"
#include "Messaging_SyncScope_PolicyC.h"

#ifndef TAO_MESSAGING_SAFE_INCLUDE 
#error "You should not include MessagingC.h directly, use Messaging.h"
#endif /* !TAO_MESSAGING_SAFE_INCLUDE */


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "messaging_export.h"
#include "Messaging_RT_PolicyC.h"
#include "Messaging_No_ImplC.h"
#include "tao/OctetSeqC.h"
#include "tao/Valuetype/Value_VarOut_T.h"
#include "tao/Valuetype/ValueBase.h"
#include "tao/Valuetype/ValueFactory.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Messaging_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Messaging_Export
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

TAO_NAMESPACE  Messaging
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:307
  
  class ExceptionHolder;
  struct tao_ExceptionHolder_life;
  
  typedef
    TAO_Value_Var_T<
        ExceptionHolder
      >
    ExceptionHolder_var;
  
  typedef
    TAO_Value_Out_T<
        ExceptionHolder
      >
    ExceptionHolder_out;
  
  struct TAO_Messaging_Export tao_ExceptionHolder_life
  {
    static void tao_add_ref (ExceptionHolder *);
    static void tao_remove_ref (ExceptionHolder *);
  };
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:56

#if !defined (_MESSAGING_EXCEPTIONHOLDER_CH_)
#define _MESSAGING_EXCEPTIONHOLDER_CH_
  
  class TAO_Messaging_Export ExceptionHolder
    : public virtual CORBA::ValueBase
  {
  public:
    typedef ExceptionHolder_var _var_type;
    static ExceptionHolder* _downcast (CORBA::ValueBase* );
    // The address of static _downcast is implicit used as type id

    // (TAO extensions or internals)
    static CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        ExceptionHolder *&
      );
    virtual const char* _tao_obv_repository_id (void) const;
    static const char* _tao_obv_static_repository_id (void);
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/field_ch.cpp:412
    
    virtual void is_system_exception (CORBA::Boolean) = 0;
    virtual CORBA::Boolean is_system_exception (void) const = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/field_ch.cpp:412
    
    virtual void byte_order (CORBA::Boolean) = 0;
    virtual CORBA::Boolean byte_order (void) const = 0;virtual void marshaled_exception (const CORBA::OctetSeq &) = 0;
    virtual const CORBA::OctetSeq &marshaled_exception (void) const = 0;
    virtual CORBA::OctetSeq &marshaled_exception (void) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:272
  
  protected:
    ExceptionHolder (void);
    virtual ~ExceptionHolder (void);
    
    virtual void *_tao_obv_narrow (ptrdiff_t);
#if defined (_MSC_VER)
    virtual void *Messaging_ExceptionHolder_tao_obv_narrow (ptrdiff_t);
#endif /* _MSC_VER */
    virtual CORBA::Boolean _tao_marshal_v (TAO_OutputCDR &);
    virtual CORBA::Boolean _tao_unmarshal_v (TAO_InputCDR &);
    
  private:
    ExceptionHolder (const ExceptionHolder &);
    void operator= (const ExceptionHolder &);
    
  protected:
    virtual CORBA::Boolean _tao_marshal__Messaging_ExceptionHolder (TAO_OutputCDR &) = 0;
    virtual CORBA::Boolean _tao_unmarshal__Messaging_ExceptionHolder (TAO_InputCDR &) = 0;
  };

#endif /* end #if !defined */

#if !defined (_MESSAGING_EXCEPTIONHOLDER___INIT_CH_)
#define _MESSAGING_EXCEPTIONHOLDER___INIT_CH_
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_init_ch.cpp:71
  
  class TAO_Messaging_Export ExceptionHolder_init : public virtual CORBA::ValueFactoryBase
  {
  public:
    ExceptionHolder_init (void);
    virtual ~ExceptionHolder_init (void);
    
    
    
    static ExceptionHolder_init* _downcast (CORBA::ValueFactoryBase* );
    
    virtual CORBA::ValueBase *create_for_unmarshal (void);
    
    // TAO-specific extensions
  public:
    virtual const char* tao_repository_id (void);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ExceptionHolder;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:567

#if !defined (_MESSAGING_REPLYHANDLER__ODDS_N_ENDS_CH_)
#define _MESSAGING_REPLYHANDLER__ODDS_N_ENDS_CH_
  
  class ReplyHandler;
  typedef ReplyHandler *ReplyHandler_ptr;
  struct tao_ReplyHandler_life;
  
  typedef
    TAO_Objref_Var_T<
        ReplyHandler,
        tao_ReplyHandler_life
      >
    ReplyHandler_var;
  
  typedef
    TAO_Objref_Out_T<
        ReplyHandler,
        tao_ReplyHandler_life
      >
    ReplyHandler_out;
  
  struct TAO_Messaging_Export tao_ReplyHandler_life
  {
    static ReplyHandler_ptr tao_duplicate (ReplyHandler_ptr);
    static void tao_release (ReplyHandler_ptr);
    static ReplyHandler_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        ReplyHandler_ptr,
        TAO_OutputCDR &
      );
  };
  
  struct TAO_Messaging_Export tao_ReplyHandler_cast
  {
    static ReplyHandler_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_MESSAGING_REPLYHANDLER_CH_)
#define _MESSAGING_REPLYHANDLER_CH_
  
  class _TAO_ReplyHandler_Proxy_Impl;
  class _TAO_ReplyHandler_Remote_Proxy_Impl;
  class _TAO_ReplyHandler_Proxy_Broker;
  class _TAO_ReplyHandler_Remote_Proxy_Broker;
  
  class TAO_Messaging_Export ReplyHandler
    : public virtual CORBA::Object
  {
  public:
    typedef ReplyHandler_ptr _ptr_type;
    typedef ReplyHandler_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static ReplyHandler_ptr _duplicate (ReplyHandler_ptr obj);
    
    static ReplyHandler_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ReplyHandler_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ReplyHandler_ptr _nil (void)
      {
        return (ReplyHandler_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:211
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual void *_tao_QueryInterface (ptrdiff_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    _TAO_ReplyHandler_Proxy_Broker *the_TAO_ReplyHandler_Proxy_Broker_;
  
  protected:
    ReplyHandler (int collocated = 0);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void Messaging_ReplyHandler_setup_collocation (int collocated);
    
    ReplyHandler (
        TAO_Stub *objref, 
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0
      );
    virtual ~ReplyHandler (void);
    
    friend class _TAO_ReplyHandler_Remote_Proxy_Impl;
    friend class _TAO_ReplyHandler_ThruPOA_Proxy_Impl;
    friend class _TAO_ReplyHandler_Direct_Proxy_Impl;
  
  private:
    ReplyHandler (const ReplyHandler &);
    void operator= (const ReplyHandler &);
  };
  
  // The Proxy Implementations are used by each interface to
  // perform a call. Each different implementation encapsulates
  // an invocation logic.
  
  
  ///////////////////////////////////////////////////////////////////////
  //                    Base Proxy Impl. Declaration
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/base_proxy_impl_ch.cpp:35
  
  class TAO_Messaging_Export _TAO_ReplyHandler_Proxy_Impl
    : public virtual TAO_Object_Proxy_Impl
  {
  public:
    virtual ~_TAO_ReplyHandler_Proxy_Impl (void) {}
  
  protected:
    _TAO_ReplyHandler_Proxy_Impl (void);
  };
  
  //
  //               End Base Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////
  
  
  ///////////////////////////////////////////////////////////////////////
  //                Remote Proxy Impl. Declaration
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/remote_proxy_impl_ch.cpp:37
  
  class TAO_Messaging_Export _TAO_ReplyHandler_Remote_Proxy_Impl
    : public virtual _TAO_ReplyHandler_Proxy_Impl,
      public virtual TAO_Remote_Object_Proxy_Impl
  {
  public:
    _TAO_ReplyHandler_Remote_Proxy_Impl (void);
    
    virtual ~_TAO_ReplyHandler_Remote_Proxy_Impl (void) {}
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
  
  class TAO_Messaging_Export _TAO_ReplyHandler_Proxy_Broker
  {
  public:
    virtual ~_TAO_ReplyHandler_Proxy_Broker (void);
    virtual _TAO_ReplyHandler_Proxy_Impl &select_proxy (
        ReplyHandler *object
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
  protected:
    _TAO_ReplyHandler_Proxy_Broker (void);
    
  };
  
  //
  //              End Base Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////
  
    
  ///////////////////////////////////////////////////////////////////////
  //                 Remote Proxy Broker Declaration 
  //
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/remote_proxy_broker_ch.cpp:40
  
  class TAO_Messaging_Export _TAO_ReplyHandler_Remote_Proxy_Broker
    : public virtual _TAO_ReplyHandler_Proxy_Broker
  {
  public: 
    _TAO_ReplyHandler_Remote_Proxy_Broker (void);
    
    virtual ~_TAO_ReplyHandler_Remote_Proxy_Broker (void);
    
    virtual _TAO_ReplyHandler_Proxy_Impl &select_proxy (
        ReplyHandler *object
        ACE_ENV_ARG_DECL
      );
    
  private:
    _TAO_ReplyHandler_Remote_Proxy_Impl remote_proxy_impl_;
  
  public:
    // This member function is used to get an handle to the unique instance
    // of the Remote Proxy Broker that is available for a given
    // interface.
    static _TAO_ReplyHandler_Remote_Proxy_Broker *the_TAO_ReplyHandler_Remote_Proxy_Broker (void);
  };
  
  //
  //              End Remote Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ReplyHandler;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module Messaging

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:80

extern TAO_Messaging_Export
Messaging::_TAO_ReplyHandler_Proxy_Broker *
(*Messaging__TAO_ReplyHandler_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/obv_module.cpp:55

TAO_NAMESPACE  OBV_Messaging
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_obv_ch.cpp:58

#if !defined (_MESSAGING_EXCEPTIONHOLDER___OBV_CH_)
#define _MESSAGING_EXCEPTIONHOLDER___OBV_CH_
  
  // OBV_ class
  class TAO_Messaging_Export ExceptionHolder
    : public virtual Messaging::ExceptionHolder,
      public virtual CORBA::DefaultValueRefCountBase
  {
  public:
    virtual ~ExceptionHolder (void);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/field_ch.cpp:412
    
    virtual void is_system_exception (CORBA::Boolean);
    virtual CORBA::Boolean is_system_exception (void) const;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/field_ch.cpp:412
    
    virtual void byte_order (CORBA::Boolean);
    virtual CORBA::Boolean byte_order (void) const;virtual void marshaled_exception (const CORBA::OctetSeq &);
    virtual const CORBA::OctetSeq &marshaled_exception (void) const;
    virtual CORBA::OctetSeq &marshaled_exception (void);
    
  protected:
    virtual CORBA::Boolean _tao_marshal__Messaging_ExceptionHolder (TAO_OutputCDR &);
    virtual CORBA::Boolean _tao_unmarshal__Messaging_ExceptionHolder (TAO_InputCDR &);
    CORBA::Boolean _tao_marshal_state (TAO_OutputCDR &);
    CORBA::Boolean _tao_unmarshal_state (TAO_InputCDR &);
  
  private:
    CORBA::Boolean _pd_is_system_exception;
    CORBA::Boolean _pd_byte_order;
    CORBA::OctetSeq _pd_marshaled_exception;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/obv_module.cpp:85

}TAO_NAMESPACE_CLOSE

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/any_op_ch.cpp:54

TAO_Messaging_Export void operator<<= (CORBA::Any &, Messaging::ExceptionHolder *); // copying
TAO_Messaging_Export void operator<<= (CORBA::Any &, Messaging::ExceptionHolder **); // non-copying
TAO_Messaging_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::ExceptionHolder *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

TAO_Messaging_Export void operator<<= (CORBA::Any &, Messaging::ReplyHandler_ptr); // copying
TAO_Messaging_Export void operator<<= (CORBA::Any &, Messaging::ReplyHandler_ptr *); // non-copying
TAO_Messaging_Export CORBA::Boolean operator>>= (const CORBA::Any &, Messaging::ReplyHandler_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:212

TAO_NAMESPACE CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (Messaging::ExceptionHolder *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (Messaging::ExceptionHolder *);
}
TAO_NAMESPACE_CLOSE

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_ch.cpp:61

TAO_Messaging_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Messaging::ExceptionHolder *);
TAO_Messaging_Export CORBA::Boolean operator>> (TAO_InputCDR &, Messaging::ExceptionHolder *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ch.cpp:55

TAO_Messaging_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Messaging::ReplyHandler_ptr );
TAO_Messaging_Export CORBA::Boolean operator>> (TAO_InputCDR &, Messaging::ReplyHandler_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "MessagingC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */

