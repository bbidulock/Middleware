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

#ifndef _TAO_IDL_ORIG_HTIOP_ENDPOINTSC_H_
#define _TAO_IDL_ORIG_HTIOP_ENDPOINTSC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "HTIOP_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO HTIOP_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_type.cpp:258

struct HTIOP_Endpoint_Info;

typedef
  TAO_Var_Var_T<
      HTIOP_Endpoint_Info
    >
  HTIOP_Endpoint_Info_var;

typedef
  TAO_Out_T<
      HTIOP_Endpoint_Info,
      HTIOP_Endpoint_Info_var
    >
  HTIOP_Endpoint_Info_out;

// TAO_IDL - Generated from
// be\be_visitor_structure/structure_ch.cpp:52

struct HTIOP_Export HTIOP_Endpoint_Info
{
  typedef HTIOP_Endpoint_Info_var _var_type;
  
  
  TAO_String_Manager host;
  CORBA::Short port;
  TAO_String_Manager htid;
};

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_decl.cpp:44

extern HTIOP_Export ::CORBA::TypeCode_ptr const _tc_HTIOP_Endpoint_Info;

// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_HTIOPENDPOINTSEQUENCE_CH_)
#define _HTIOPENDPOINTSEQUENCE_CH_

class HTIOPEndpointSequence;

typedef
  TAO_VarSeq_Var_T<
      HTIOPEndpointSequence,
      HTIOP_Endpoint_Info
    >
  HTIOPEndpointSequence_var;

typedef
  TAO_Seq_Out_T<
      HTIOPEndpointSequence,
      HTIOPEndpointSequence_var,
      HTIOP_Endpoint_Info
    >
  HTIOPEndpointSequence_out;

class HTIOP_Export HTIOPEndpointSequence
  : public
      TAO_Unbounded_Sequence<
          HTIOP_Endpoint_Info
        >
{
public:
  HTIOPEndpointSequence (void);
  HTIOPEndpointSequence (CORBA::ULong max);
  HTIOPEndpointSequence (
      CORBA::ULong max,
      CORBA::ULong length,
      HTIOP_Endpoint_Info* buffer, 
      CORBA::Boolean release = 0
    );
  HTIOPEndpointSequence (const HTIOPEndpointSequence &);
  ~HTIOPEndpointSequence (void);
  
  typedef HTIOPEndpointSequence_var _var_type;
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_decl.cpp:44

extern HTIOP_Export ::CORBA::TypeCode_ptr const _tc_HTIOPEndpointSequence;

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

HTIOP_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const HTIOP_Endpoint_Info &);
HTIOP_Export CORBA::Boolean operator>> (TAO_InputCDR &, HTIOP_Endpoint_Info &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_HTIOPEndpointSequence_H_
#define _TAO_CDR_OP_HTIOPEndpointSequence_H_

HTIOP_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const HTIOPEndpointSequence &
  );
HTIOP_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    HTIOPEndpointSequence &
  );

#endif /* _TAO_CDR_OP_HTIOPEndpointSequence_H_ */

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


