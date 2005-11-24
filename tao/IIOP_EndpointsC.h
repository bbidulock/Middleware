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

#ifndef _TAO_IDL_ORIG_IIOP_ENDPOINTSC_H_
#define _TAO_IDL_ORIG_IIOP_ENDPOINTSC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct IIOP_Endpoint_Info;

  typedef
    TAO_Var_Var_T<
        IIOP_Endpoint_Info
      >
    IIOP_Endpoint_Info_var;

  typedef
    TAO_Out_T<
        IIOP_Endpoint_Info,
        IIOP_Endpoint_Info_var
      >
    IIOP_Endpoint_Info_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export IIOP_Endpoint_Info
  {
    typedef IIOP_Endpoint_Info_var _var_type;

    static void _tao_any_destructor (void *);
    TAO_String_Manager host;
    CORBA::Short port;
    CORBA::Short priority;
  };

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_TAO_IIOPENDPOINTSEQUENCE_CH_)
#define _TAO_IIOPENDPOINTSEQUENCE_CH_

  class IIOPEndpointSequence;

  typedef
    TAO_VarSeq_Var_T<
        IIOPEndpointSequence,
        IIOP_Endpoint_Info
      >
    IIOPEndpointSequence_var;

  typedef
    TAO_Seq_Out_T<
        IIOPEndpointSequence,
        IIOPEndpointSequence_var,
        IIOP_Endpoint_Info
      >
    IIOPEndpointSequence_out;

  class TAO_Export IIOPEndpointSequence
    : public
        TAO_Unbounded_Sequence<
            IIOP_Endpoint_Info
          >
  {
  public:
    IIOPEndpointSequence (void);
    IIOPEndpointSequence (CORBA::ULong max);
    IIOPEndpointSequence (
        CORBA::ULong max,
        CORBA::ULong length,
        IIOP_Endpoint_Info* buffer,
        CORBA::Boolean release = 0
      );
    IIOPEndpointSequence (const IIOPEndpointSequence &);
    ~IIOPEndpointSequence (void);

    static void _tao_any_destructor (void *);

    typedef IIOPEndpointSequence_var _var_type;
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module TAO

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO::IIOP_Endpoint_Info &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO::IIOP_Endpoint_Info &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_TAO_IIOPEndpointSequence_H_
#define _TAO_CDR_OP_TAO_IIOPEndpointSequence_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const TAO::IIOPEndpointSequence &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    TAO::IIOPEndpointSequence &
  );

#endif /* _TAO_CDR_OP_TAO_IIOPEndpointSequence_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


