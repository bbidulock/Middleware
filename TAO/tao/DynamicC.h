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
// be/be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_DYNAMICC_H_
#define _TAO_IDL_ORIG_DYNAMICC_H_
#include /**/ "ace/pre.h"
#include "tao/corbafwd.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "StringSeqC.h"
#include "tao/Any_Dual_Impl_T.h"
#include "tao/TAO_Export.h"
#include "tao/Sequence.h"
#include "tao/VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

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
// be/be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  Dynamic
{
  
  // TAO_IDL - Generated from
  // be/be_type.cpp:249
  
  struct Parameter;
  
  typedef
    TAO_Var_Var_T<
        Parameter
      >
    Parameter_var;
  
  typedef
    TAO_Out_T<
        Parameter,
        Parameter_var
      >
    Parameter_out;
  
  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_Export Parameter
  {
    typedef Parameter_var _var_type;
    
    static void _tao_any_destructor (void *);
    CORBA::Any argument;
    CORBA::ParameterMode mode;
  };
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Parameter;
  
  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:89

#if !defined (_DYNAMIC_PARAMETERLIST_CH_)
#define _DYNAMIC_PARAMETERLIST_CH_
  
  class ParameterList;
  
  typedef
    TAO_VarSeq_Var_T<
        ParameterList,
        Parameter
      >
    ParameterList_var;
  
  typedef
    TAO_Seq_Out_T<
        ParameterList,
        ParameterList_var,
        Parameter
      >
    ParameterList_out;
  
  class TAO_Export ParameterList
    : public
        TAO_Unbounded_Sequence<
            Parameter
          >
  {
  public:
    ParameterList (void);
    ParameterList (CORBA::ULong max);
    ParameterList (
        CORBA::ULong max,
        CORBA::ULong length,
        Parameter* buffer, 
        CORBA::Boolean release = 0
      );
    ParameterList (const ParameterList &);
    ~ParameterList (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ParameterList_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ParameterList;
  
  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:426
  
  typedef CORBA::StringSeq ContextList;
  typedef CORBA::StringSeq_var ContextList_var;
  typedef CORBA::StringSeq_out ContextList_out;
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ContextList;
  
  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:333
  
  typedef CORBA::TypeCode TypeCode;
  typedef CORBA::TypeCode_ptr TypeCode_ptr;
  typedef CORBA::TypeCode_var TypeCode_var;
  typedef CORBA::TypeCode_out TypeCode_out;
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TypeCode;
  
  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:89

#if !defined (_DYNAMIC_EXCEPTIONLIST_CH_)
#define _DYNAMIC_EXCEPTIONLIST_CH_
  
  class ExceptionList;
  
  typedef
    TAO_MngSeq_Var_T<
        ExceptionList,
        TAO_Pseudo_Object_Manager<
            TypeCode,
            TypeCode_var
          >
      >
    ExceptionList_var;
  
  typedef
    TAO_MngSeq_Out_T<
        ExceptionList,
        ExceptionList_var,
        TAO_Pseudo_Object_Manager<
            TypeCode,
            TypeCode_var
          >
      >
    ExceptionList_out;
  
  class TAO_Export ExceptionList
    : public
        TAO_Unbounded_Pseudo_Sequence<
            TypeCode,
            Dynamic::TypeCode_var
          >
  {
  public:
    ExceptionList (void);
    ExceptionList (CORBA::ULong max);
    ExceptionList (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::TypeCode_ptr* buffer, 
        CORBA::Boolean release = 0
      );
    ExceptionList (const ExceptionList &);
    ~ExceptionList (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ExceptionList_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ExceptionList;
  
  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:426
  
  typedef CORBA::StringSeq RequestContext;
  typedef CORBA::StringSeq_var RequestContext_var;
  typedef CORBA::StringSeq_out RequestContext_out;
  
  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_RequestContext;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module Dynamic

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Dynamic::Parameter &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Dynamic::Parameter*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Dynamic::Parameter *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Dynamic::Parameter *&);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Dynamic::ParameterList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Dynamic::ParameterList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Dynamic::ParameterList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Dynamic::ParameterList *&);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Dynamic::ExceptionList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Dynamic::ExceptionList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Dynamic::ExceptionList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Dynamic::ExceptionList *&);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Dynamic::Parameter &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, Dynamic::Parameter &);

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_Dynamic_ParameterList_H_
#define _TAO_CDR_OP_Dynamic_ParameterList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Dynamic::ParameterList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Dynamic::ParameterList &
  );

#endif /* _TAO_CDR_OP_Dynamic_ParameterList_H_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_Dynamic_ExceptionList_H_
#define _TAO_CDR_OP_Dynamic_ExceptionList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Dynamic::ExceptionList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Dynamic::ExceptionList &
  );

#endif /* _TAO_CDR_OP_Dynamic_ExceptionList_H_ */

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "DynamicC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */

