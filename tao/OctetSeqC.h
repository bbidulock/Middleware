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

#ifndef _TAO_IDL_OCTETSEQC_H_
#define _TAO_IDL_OCTETSEQC_H_

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

#if !defined (_CORBA_OCTETSEQ_CH_)
#define _CORBA_OCTETSEQ_CH_

  class OctetSeq;

  typedef
    TAO_FixedSeq_Var_T<
        OctetSeq,
        CORBA::Octet
      >
    OctetSeq_var;

  typedef
    TAO_Seq_Out_T<
        OctetSeq,
        OctetSeq_var,
        CORBA::Octet
      >
    OctetSeq_out;

  class TAO_Export OctetSeq
    : public
        TAO_Unbounded_Sequence<
            CORBA::Octet
          >
  {
  public:
    OctetSeq (void);
    OctetSeq (CORBA::ULong max);
    OctetSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        CORBA::Octet* buffer,
        CORBA::Boolean release = 0
      );
    OctetSeq (const OctetSeq &);
    ~OctetSeq (void);

    static void _tao_any_destructor (void *);

    typedef OctetSeq_var _var_type;

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
    OctetSeq (
        CORBA::ULong length,
        const ACE_Message_Block* mb
      )
      : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
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

// Workaround for a Visual Studio .NET bug where this class is not
// properly imported by an application if typedef'd or subclassed,
// resulting in 'multiply defined' link errors. The export macro
// here forces an explicit import by the application. Please see
// http://support.microsoft.com/default.aspx?scid=kb;en-us;309801
// The problem stems from use of the type below in PortableServer,
// but we put the instantiation here because the application will
// need to see it in *C.h to avoid the error.
#if defined ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT
  template class TAO_Export TAO_Unbounded_Sequence<CORBA::OctetSeq>;
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT */


// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_CORBA_OctetSeq_H_
#define _TAO_CDR_OP_CORBA_OctetSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::OctetSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::OctetSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_OctetSeq_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:1062

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif /* ifndef */


