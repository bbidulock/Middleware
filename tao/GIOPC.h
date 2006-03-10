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

#ifndef _TAO_IDL_GIOPC_H_
#define _TAO_IDL_GIOPC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/VarOut_T.h"

#include "tao/IOP_IORC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

namespace GIOP
{

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::Short AddressingDisposition;
  typedef CORBA::Short_out AddressingDisposition_out;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const CORBA::Short KeyAddr = 0;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const CORBA::Short ProfileAddr = 1;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const CORBA::Short ReferenceAddr = 2;

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct Version;

  typedef
    TAO_Fixed_Var_T<
        Version
      >
    Version_var;

  typedef
    Version &
    Version_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:57

  struct TAO_Export Version
  {
    typedef Version_var _var_type;

    static void _tao_any_destructor (void *);
    CORBA::Octet major;
    CORBA::Octet minor;
  };

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct IORAddressingInfo;

  typedef
    TAO_Var_Var_T<
        IORAddressingInfo
      >
    IORAddressingInfo_var;

  typedef
    TAO_Out_T<
        IORAddressingInfo,
        IORAddressingInfo_var
      >
    IORAddressingInfo_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:57

  struct TAO_Export IORAddressingInfo
  {
    typedef IORAddressingInfo_var _var_type;

    static void _tao_any_destructor (void *);
    CORBA::ULong selected_profile_index;
    IOP::IOR ior;
  };

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  class TargetAddress;

  typedef
    TAO_Var_Var_T<
        TargetAddress
      >
    TargetAddress_var;

  typedef
    TAO_Out_T<
        TargetAddress,
        TargetAddress_var
      >
    TargetAddress_out;

#if !defined (_GIOP_TARGETADDRESS_CH_)
#define _GIOP_TARGETADDRESS_CH_

  class TAO_Export TargetAddress
  {
  public:
    TargetAddress (void);
    TargetAddress (const TargetAddress &);
    ~TargetAddress (void);
    static void _tao_any_destructor (void*);

    TargetAddress &operator= (const TargetAddress &);

    // TAO_IDL - Generated from
    // be\be_visitor_union/discriminant_ch.cpp:114

    void _d (CORBA::Short);
    CORBA::Short _d (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_union/union_ch.cpp:113

    typedef TargetAddress_var _var_type;

    // TAO_IDL - Generated from
    // be\be_visitor_union_branch/public_ch.cpp:557

    void object_key (const CORBA::OctetSeq &);
    const CORBA::OctetSeq &object_key (void) const;
    CORBA::OctetSeq &object_key (void);

    // TAO_IDL - Generated from
    // be\be_visitor_union_branch/public_ch.cpp:665

    void profile (const IOP::TaggedProfile &);
    const IOP::TaggedProfile &profile (void) const;
    IOP::TaggedProfile &profile (void);

    // TAO_IDL - Generated from
    // be\be_visitor_union_branch/public_ch.cpp:665

    void ior (const ACE_NESTED_CLASS (GIOP, IORAddressingInfo) &);
    const ACE_NESTED_CLASS (GIOP, IORAddressingInfo) &ior (void) const;
    ACE_NESTED_CLASS (GIOP, IORAddressingInfo) &ior (void);

    // TAO_IDL - Generated from
    // be\be_visitor_union/union_ch.cpp:147

    void _default (void);
  private:
    CORBA::Short disc_;
    CORBA::Short holder_;

    union
    {
      // TAO_IDL - Generated from
      // be\be_visitor_union_branch/private_ch.cpp:451
      CORBA::OctetSeq *object_key_;
      // TAO_IDL - Generated from
      // be\be_visitor_union_branch/private_ch.cpp:526
      IOP::TaggedProfile *profile_;
      // TAO_IDL - Generated from
      // be\be_visitor_union_branch/private_ch.cpp:526
      ACE_NESTED_CLASS (GIOP, IORAddressingInfo) *ior_;
    } u_;

    // TAO extension - frees any allocated storage.
    void _reset (CORBA::Short, CORBA::Boolean /* finalize */);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module GIOP

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::Version &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::Version &);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::IORAddressingInfo &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::IORAddressingInfo &);

// TAO_IDL - Generated from
// be\be_visitor_union/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const GIOP::TargetAddress &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, GIOP::TargetAddress &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:1062

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "tao/GIOPC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif /* ifndef */


