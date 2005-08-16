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
// be\be_codegen.cpp:154

#ifndef _TAO_IDL_WSTRINGSEQC_H_
#define _TAO_IDL_WSTRINGSEQC_H_

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

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_WSTRINGSEQ_CH_)
#define _CORBA_WSTRINGSEQ_CH_
  
  class WStringSeq;
  
  typedef
    TAO_MngSeq_Var_T<
        WStringSeq,
        TAO_SeqElem_WString_Manager
      >
    WStringSeq_var;
  
  typedef
    TAO_MngSeq_Out_T<
        WStringSeq,
        WStringSeq_var,
        TAO_SeqElem_WString_Manager
      >
    WStringSeq_out;
  
  class TAO_Export WStringSeq
    : public
        TAO_Unbounded_WString_Sequence
  {
  public:
    WStringSeq (void);
    WStringSeq (CORBA::ULong max);
    WStringSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::WChar ** buffer, 
        CORBA::Boolean release = 0
      );
    WStringSeq (const WStringSeq &);
    ~WStringSeq (void);
    
    static void _tao_any_destructor (void *);
    
    typedef WStringSeq_var _var_type;
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_WStringSeq_H_
#define _TAO_CDR_OP_CORBA_WStringSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::WStringSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::WStringSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_WStringSeq_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:1062

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif /* ifndef */


