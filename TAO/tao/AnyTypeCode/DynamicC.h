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

#include "tao/AnyTypeCode/TAO_AnyTypeCode_Export.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Dynamic_ParameterC.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

#include "tao/StringSeqC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_AnyTypeCode_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace CORBA
{

  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module CORBA

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
        ParameterList
      >
    ParameterList_var;

  typedef
    TAO_Seq_Out_T<
        ParameterList,
        ParameterList_var
      >
    ParameterList_out;

  class TAO_AnyTypeCode_Export ParameterList
    : public
        TAO::unbounded_value_sequence<
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
  // be\be_visitor_typedef/typedef_ch.cpp:472

  typedef CORBA::StringSeq ContextList;
  typedef CORBA::StringSeq_var ContextList_var;
  typedef CORBA::StringSeq_out ContextList_out;

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_DYNAMIC_EXCEPTIONLIST_CH_)
#define _DYNAMIC_EXCEPTIONLIST_CH_

  class ExceptionList;

  typedef
    TAO_VarSeq_Var_T<
        ExceptionList
      >
    ExceptionList_var;

  typedef
    TAO_Seq_Out_T<
        ExceptionList,
        ExceptionList_var
      >
    ExceptionList_out;

  class TAO_AnyTypeCode_Export ExceptionList
    : public
        TAO::unbounded_object_reference_sequence<
            CORBA::TypeCode,
            CORBA::TypeCode_var
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
  // be\be_visitor_typedef/typedef_ch.cpp:472

  typedef CORBA::StringSeq RequestContext;
  typedef CORBA::StringSeq_var RequestContext_var;
  typedef CORBA::StringSeq_out RequestContext_out;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module Dynamic

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_Dynamic_ParameterList_H_
#define _TAO_CDR_OP_Dynamic_ParameterList_H_

TAO_AnyTypeCode_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Dynamic::ParameterList &
  );
TAO_AnyTypeCode_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Dynamic::ParameterList &
  );

#endif /* _TAO_CDR_OP_Dynamic_ParameterList_H_ */


// Traits specializations.
// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_Dynamic_ExceptionList_H_
#define _TAO_CDR_OP_Dynamic_ExceptionList_H_

TAO_AnyTypeCode_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const Dynamic::ExceptionList &
  );
TAO_AnyTypeCode_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    Dynamic::ExceptionList &
  );

#endif /* _TAO_CDR_OP_Dynamic_ExceptionList_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


