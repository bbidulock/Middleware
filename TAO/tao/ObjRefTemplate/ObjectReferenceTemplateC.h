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
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_OBJECTREFERENCETEMPLATEC_H_
#define _TAO_IDL_ORIG_OBJECTREFERENCETEMPLATEC_H_

#include /**/ "ace/pre.h"
#include "ort_export.h"
#include "tao/PI_ForwardC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Exception.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/Valuetype/ValueBase.h"
#include "tao/Valuetype/ValueFactory.h"
#include "tao/Valuetype/Value_VarOut_T.h"
#include "tao/Valuetype/Sequence_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_ORT_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_ORT_Export
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

TAO_NAMESPACE  PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:285
  
  

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ODDS_N_ENDS_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY__ODDS_N_ENDS_CH_
  
  class ObjectReferenceFactory;
  struct tao_ObjectReferenceFactory_life;
  
  typedef
    TAO_Value_Var_T<
        ObjectReferenceFactory
      >
    ObjectReferenceFactory_var;
  
  typedef
    TAO_Value_Out_T<
        ObjectReferenceFactory
      >
    ObjectReferenceFactory_out;
  
#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:56

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCEFACTORY_CH_
  
  class TAO_ORT_Export ObjectReferenceFactory
    : public virtual CORBA::ValueBase
  {
  public:
    typedef ObjectReferenceFactory_var _var_type;
    static ObjectReferenceFactory* _downcast (CORBA::ValueBase* );
    // The address of static _downcast is implicit used as type id

    // (TAO extensions or internals)
    static CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        ObjectReferenceFactory *&
      );
    virtual const char* _tao_obv_repository_id (void) const;
    static const char* _tao_obv_static_repository_id (void);
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:427
    
    virtual CORBA::Object_ptr make_object (
        const char *, const PortableInterceptor::ObjectId & ACE_ENV_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:272
  
  protected:
    ObjectReferenceFactory (void);
    virtual ~ObjectReferenceFactory (void);
    
    virtual void *_tao_obv_narrow (ptrdiff_t);
#if defined (_MSC_VER)
    virtual void *PortableInterceptor_ObjectReferenceFactory_tao_obv_narrow (ptrdiff_t);
#endif /* _MSC_VER */
    
  private:
    ObjectReferenceFactory (const ObjectReferenceFactory &);
    void operator= (const ObjectReferenceFactory &);
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectReferenceFactory;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:285
  
  

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__ODDS_N_ENDS_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE__ODDS_N_ENDS_CH_
  
  class ObjectReferenceTemplate;
  struct tao_ObjectReferenceTemplate_life;
  
  typedef
    TAO_Value_Var_T<
        ObjectReferenceTemplate
      >
    ObjectReferenceTemplate_var;
  
  typedef
    TAO_Value_Out_T<
        ObjectReferenceTemplate
      >
    ObjectReferenceTemplate_out;
  

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:56

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATE_CH_
  
  class TAO_ORT_Export ObjectReferenceTemplate
    : public virtual ObjectReferenceFactory
  {
  public:
    typedef ObjectReferenceTemplate_var _var_type;
    static ObjectReferenceTemplate* _downcast (CORBA::ValueBase* );
    // The address of static _downcast is implicit used as type id

    // (TAO extensions or internals)
    static CORBA::Boolean _tao_unmarshal (
        TAO_InputCDR &,
        ObjectReferenceTemplate *&
      );
    virtual const char* _tao_obv_repository_id (void) const;
    static const char* _tao_obv_static_repository_id (void);
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:427
    
    virtual char * server_id (
         ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:427
    
    virtual char * orb_id (
         ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:427
    
    virtual ::PortableInterceptor::AdapterName * adapter_name (
         ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      ) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ch.cpp:272
  
  protected:
    ObjectReferenceTemplate (void);
    virtual ~ObjectReferenceTemplate (void);
    
    virtual void *_tao_obv_narrow (ptrdiff_t);
#if defined (_MSC_VER)
    virtual void *PortableInterceptor_ObjectReferenceTemplate_tao_obv_narrow (ptrdiff_t);
#endif /* _MSC_VER */
    
  private:
    ObjectReferenceTemplate (const ObjectReferenceTemplate &);
    void operator= (const ObjectReferenceTemplate &);
    
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplate;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:91

#if !defined (_PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CH_)
#define _PORTABLEINTERCEPTOR_OBJECTREFERENCETEMPLATESEQ_CH_
  
  class ObjectReferenceTemplateSeq;
  
  typedef
    TAO_MngSeq_Var_T<
        ObjectReferenceTemplateSeq,
        TAO_Valuetype_Manager<
            ObjectReferenceTemplate,
            ObjectReferenceTemplate_var
          >
      >
    ObjectReferenceTemplateSeq_var;
  
  typedef
    TAO_MngSeq_Out_T<
        ObjectReferenceTemplateSeq,
        ObjectReferenceTemplateSeq_var,
        TAO_Valuetype_Manager<
            ObjectReferenceTemplate,
            ObjectReferenceTemplate_var
          >
      >
    ObjectReferenceTemplateSeq_out;
  
  class TAO_ORT_Export ObjectReferenceTemplateSeq
    : public
        TAO_Unbounded_Valuetype_Sequence<
            ObjectReferenceTemplate,
            ObjectReferenceTemplate_var
          >
  {
  public:
    ObjectReferenceTemplateSeq (void);
    ObjectReferenceTemplateSeq (CORBA::ULong max);
    ObjectReferenceTemplateSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        ObjectReferenceTemplate ** buffer, 
        CORBA::Boolean release = 0
      );
    ObjectReferenceTemplateSeq (const ObjectReferenceTemplateSeq &);
    ~ObjectReferenceTemplateSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ObjectReferenceTemplateSeq_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ObjectReferenceTemplateSeq;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:343
  
  typedef CORBA::Long AdapterManagerId;
  typedef CORBA::Long_out AdapterManagerId_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_AdapterManagerId;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:343
  
  typedef CORBA::Short AdapterState;
  typedef CORBA::Short_out AdapterState_out;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_AdapterState;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const PortableInterceptor::AdapterState HOLDING = 0;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const PortableInterceptor::AdapterState ACTIVE = 1;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const PortableInterceptor::AdapterState DISCARDING = 2;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const PortableInterceptor::AdapterState INACTIVE = 3;
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_constant/constant_ch.cpp:52
  
  const PortableInterceptor::AdapterState NON_EXISTENT = 4;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module PortableInterceptor

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/obv_module.cpp:55

TAO_NAMESPACE  OBV_PortableInterceptor
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/obv_module.cpp:85

}TAO_NAMESPACE_CLOSE

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/any_op_ch.cpp:54

TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceFactory *); // copying
TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceFactory **); // non-copying
TAO_ORT_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceFactory *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/any_op_ch.cpp:54

TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate *); // copying
TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate **); // non-copying
TAO_ORT_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceTemplate *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_ch.cpp:52

TAO_ORT_Export void operator<<= (CORBA::Any &, const PortableInterceptor::ObjectReferenceTemplateSeq &); // copying version
TAO_ORT_Export void operator<<= (CORBA::Any &, PortableInterceptor::ObjectReferenceTemplateSeq*); // noncopying version
TAO_ORT_Export CORBA::Boolean operator>>= (const CORBA::Any &, PortableInterceptor::ObjectReferenceTemplateSeq *&); // deprecated
TAO_ORT_Export CORBA::Boolean operator>>= (const CORBA::Any &, const PortableInterceptor::ObjectReferenceTemplateSeq *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:190

TAO_NAMESPACE CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (PortableInterceptor::ObjectReferenceFactory *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (PortableInterceptor::ObjectReferenceFactory *);
}
TAO_NAMESPACE_CLOSE

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_ch.cpp:61

TAO_ORT_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableInterceptor::ObjectReferenceFactory *);
TAO_ORT_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableInterceptor::ObjectReferenceFactory *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:190

TAO_NAMESPACE CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (PortableInterceptor::ObjectReferenceTemplate *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (PortableInterceptor::ObjectReferenceTemplate *);
}
TAO_NAMESPACE_CLOSE

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_ch.cpp:61

TAO_ORT_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const PortableInterceptor::ObjectReferenceTemplate *);
TAO_ORT_Export CORBA::Boolean operator>> (TAO_InputCDR &, PortableInterceptor::ObjectReferenceTemplate *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_
#define _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_

TAO_ORT_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const PortableInterceptor::ObjectReferenceTemplateSeq &
  );
TAO_ORT_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    PortableInterceptor::ObjectReferenceTemplateSeq &
  );

#endif /* _TAO_CDR_OP_PortableInterceptor_ObjectReferenceTemplateSeq_H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1048

#if defined (__ACE_INLINE__)
#include "ObjectReferenceTemplateC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */

