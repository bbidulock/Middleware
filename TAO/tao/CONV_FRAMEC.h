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

#ifndef _TAO_IDL_ORIG_CONV_FRAMEC_H_
#define _TAO_IDL_ORIG_CONV_FRAMEC_H_

#include /**/ "ace/pre.h"

#include "tao/CDR.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Sequence.h"
#include "tao/VarOut_T.h"

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

namespace CONV_FRAME
{

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typedef/typedef_ch.cpp:333

  typedef CORBA::ULong CodeSetId;
  typedef CORBA::ULong_out CodeSetId_out;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_CodeSetId;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:258

  struct CodeSetComponent;

  typedef
    TAO_Var_Var_T<
        CodeSetComponent
      >
    CodeSetComponent_var;

  typedef
    TAO_Out_T<
        CodeSetComponent,
        CodeSetComponent_var
      >
    CodeSetComponent_out;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export CodeSetComponent
  {
    typedef CodeSetComponent_var _var_type;


    CONV_FRAME::CodeSetId native_code_set;


    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CONV_FRAME_CODESETID__CH_)
#define _CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CONV_FRAME_CODESETID__CH_

    class TAO_Export _tao_seq_CONV_FRAME_CodeSetId_
      : public
          TAO_Unbounded_Sequence<
              ACE_NESTED_CLASS (CONV_FRAME, CodeSetId)
            >
    {
    public:
      _tao_seq_CONV_FRAME_CodeSetId_ (void);
      _tao_seq_CONV_FRAME_CodeSetId_ (CORBA::ULong max);
      _tao_seq_CONV_FRAME_CodeSetId_ (
          CORBA::ULong max,
          CORBA::ULong length,
          CORBA::ULong* buffer,
          CORBA::Boolean release = 0
        );
      _tao_seq_CONV_FRAME_CodeSetId_ (const _tao_seq_CONV_FRAME_CodeSetId_ &);
      ~_tao_seq_CONV_FRAME_CodeSetId_ (void);


    };

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_field/field_ch.cpp:453

    typedef _tao_seq_CONV_FRAME_CodeSetId_ _conversion_code_sets_seq;
    _tao_seq_CONV_FRAME_CodeSetId_ conversion_code_sets;
  };

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_CodeSetComponent;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:258

  struct CodeSetComponentInfo;

  typedef
    TAO_Var_Var_T<
        CodeSetComponentInfo
      >
    CodeSetComponentInfo_var;

  typedef
    TAO_Out_T<
        CodeSetComponentInfo,
        CodeSetComponentInfo_var
      >
    CodeSetComponentInfo_out;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export CodeSetComponentInfo
  {
    typedef CodeSetComponentInfo_var _var_type;


    CONV_FRAME::CodeSetComponent ForCharData;
    CONV_FRAME::CodeSetComponent ForWcharData;
  };

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_CodeSetComponentInfo;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_type.cpp:258

  struct CodeSetContext;

  typedef
    TAO_Fixed_Var_T<
        CodeSetContext
      >
    CodeSetContext_var;

  typedef
    CodeSetContext &
    CodeSetContext_out;

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export CodeSetContext
  {
    typedef CodeSetContext_var _var_type;


    CONV_FRAME::CodeSetId char_data;
    CONV_FRAME::CodeSetId wchar_data;
  };

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_CodeSetContext;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:66

} // module CONV_FRAME

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetComponent &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetComponent &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_CONV_FRAME_CodeSetComponent__tao_seq_CONV_FRAME_CodeSetId__H_
#define _TAO_CDR_OP_CONV_FRAME_CodeSetComponent__tao_seq_CONV_FRAME_CodeSetId__H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CONV_FRAME::CodeSetComponent::_tao_seq_CONV_FRAME_CodeSetId_ &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CONV_FRAME::CodeSetComponent::_tao_seq_CONV_FRAME_CodeSetId_ &
  );

#endif /* _TAO_CDR_OP_CONV_FRAME_CodeSetComponent__tao_seq_CONV_FRAME_CodeSetId__H_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetComponentInfo &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetComponentInfo &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CONV_FRAME::CodeSetContext &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CONV_FRAME::CodeSetContext &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:969

#if defined (__ACE_INLINE__)
#include "CONV_FRAMEC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */
