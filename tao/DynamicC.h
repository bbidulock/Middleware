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
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_DYNAMICC_H_
#define _TAO_IDL_ORIG_DYNAMICC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Typecode.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

#include "tao/Dynamic_ParameterC.h"
#include "tao/StringSeqC.h"

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
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace Dynamic
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

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
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ParameterList;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:435
  
  typedef CORBA::StringSeq ContextList;
  typedef CORBA::StringSeq_var ContextList_var;
  typedef CORBA::StringSeq_out ContextList_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ContextList;
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_DYNAMIC_EXCEPTIONLIST_CH_)
#define _DYNAMIC_EXCEPTIONLIST_CH_
  
  class ExceptionList;
  
  typedef
    TAO_MngSeq_Var_T<
        ExceptionList,
        TAO_Pseudo_Object_Manager<
            CORBA::TypeCode
          >
      >
    ExceptionList_var;
  
  typedef
    TAO_MngSeq_Out_T<
        ExceptionList,
        ExceptionList_var,
        TAO_Pseudo_Object_Manager<
            CORBA::TypeCode
          >
      >
    ExceptionList_out;
  
  class TAO_Export ExceptionList
    : public
        TAO_Unbounded_Pseudo_Sequence<
            CORBA::TypeCode
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
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ExceptionList;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:435
  
  typedef CORBA::StringSeq RequestContext;
  typedef CORBA::StringSeq_var RequestContext_var;
  typedef CORBA::StringSeq_out RequestContext_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_RequestContext;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module Dynamic

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Dynamic::ParameterList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Dynamic::ParameterList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Dynamic::ParameterList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Dynamic::ParameterList *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const Dynamic::ExceptionList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, Dynamic::ExceptionList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, Dynamic::ExceptionList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const Dynamic::ExceptionList *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

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
// be\be_visitor_sequence/cdr_op_ch.cpp:71

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
// be\be_codegen.cpp:963

#if defined (__ACE_INLINE__)
#include "DynamicC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


