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

#ifndef _TAO_IDL_IOP_IORC_H_
#define _TAO_IDL_IOP_IORC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/unbounded_value_sequence.hpp"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"
#include "tao/Managed_Types.h"

#include "tao/OctetSeqC.h"

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

namespace IOP
{

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::ULong ProfileId;
  typedef CORBA::ULong_out ProfileId_out;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ProfileId TAG_INTERNET_IOP = 0U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ProfileId TAG_MULTIPLE_COMPONENTS = 1U;

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct TaggedProfile;

  typedef
    TAO_Var_Var_T<
        TaggedProfile
      >
    TaggedProfile_var;

  typedef
    TAO_Out_T<
        TaggedProfile,
        TaggedProfile_var
      >
    TaggedProfile_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:57

  struct TAO_Export TaggedProfile
  {
    typedef TaggedProfile_var _var_type;

    static void _tao_any_destructor (void *);
    IOP::ProfileId tag;
    CORBA::OctetSeq profile_data;
  };

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_IOP_TAGGEDPROFILESEQ_CH_)
#define _IOP_TAGGEDPROFILESEQ_CH_

  class TaggedProfileSeq;

  typedef
    TAO_VarSeq_Var_T<
        TaggedProfileSeq,
        TaggedProfile
      >
    TaggedProfileSeq_var;

  typedef
    TAO_Seq_Out_T<
        TaggedProfileSeq,
        TaggedProfileSeq_var,
        TaggedProfile
      >
    TaggedProfileSeq_out;

  class TAO_Export TaggedProfileSeq
    : public
        TAO::unbounded_value_sequence<
            TaggedProfile
          >
  {
  public:
    TaggedProfileSeq (void);
    TaggedProfileSeq (CORBA::ULong max);
    TaggedProfileSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        TaggedProfile* buffer,
        CORBA::Boolean release = 0
      );
    TaggedProfileSeq (const TaggedProfileSeq &);
    ~TaggedProfileSeq (void);

    static void _tao_any_destructor (void *);

    typedef TaggedProfileSeq_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct IOR;

  typedef
    TAO_Var_Var_T<
        IOR
      >
    IOR_var;

  typedef
    TAO_Out_T<
        IOR,
        IOR_var
      >
    IOR_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:57

  struct TAO_Export IOR
  {
    typedef IOR_var _var_type;

    static void _tao_any_destructor (void *);
    TAO_String_Manager type_id;
    IOP::TaggedProfileSeq profiles;
  };

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::ULong ComponentId;
  typedef CORBA::ULong_out ComponentId_out;

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct TaggedComponent;

  typedef
    TAO_Var_Var_T<
        TaggedComponent
      >
    TaggedComponent_var;

  typedef
    TAO_Out_T<
        TaggedComponent,
        TaggedComponent_var
      >
    TaggedComponent_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:57

  struct TAO_Export TaggedComponent
  {
    typedef TaggedComponent_var _var_type;

    static void _tao_any_destructor (void *);
    IOP::ComponentId tag;
    CORBA::OctetSeq component_data;
  };

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_IOP_MULTIPLECOMPONENTPROFILE_CH_)
#define _IOP_MULTIPLECOMPONENTPROFILE_CH_

  class MultipleComponentProfile;

  typedef
    TAO_VarSeq_Var_T<
        MultipleComponentProfile,
        TaggedComponent
      >
    MultipleComponentProfile_var;

  typedef
    TAO_Seq_Out_T<
        MultipleComponentProfile,
        MultipleComponentProfile_var,
        TaggedComponent
      >
    MultipleComponentProfile_out;

  class TAO_Export MultipleComponentProfile
    : public
        TAO::unbounded_value_sequence<
            TaggedComponent
          >
  {
  public:
    MultipleComponentProfile (void);
    MultipleComponentProfile (CORBA::ULong max);
    MultipleComponentProfile (
        CORBA::ULong max,
        CORBA::ULong length,
        TaggedComponent* buffer,
        CORBA::Boolean release = 0
      );
    MultipleComponentProfile (const MultipleComponentProfile &);
    ~MultipleComponentProfile (void);

    static void _tao_any_destructor (void *);

    typedef MultipleComponentProfile_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_IOP_TAGGEDCOMPONENTLIST_CH_)
#define _IOP_TAGGEDCOMPONENTLIST_CH_

  class TaggedComponentList;

  typedef
    TAO_VarSeq_Var_T<
        TaggedComponentList,
        TaggedComponent
      >
    TaggedComponentList_var;

  typedef
    TAO_Seq_Out_T<
        TaggedComponentList,
        TaggedComponentList_var,
        TaggedComponent
      >
    TaggedComponentList_out;

  class TAO_Export TaggedComponentList
    : public
        TAO::unbounded_value_sequence<
            TaggedComponent
          >
  {
  public:
    TaggedComponentList (void);
    TaggedComponentList (CORBA::ULong max);
    TaggedComponentList (
        CORBA::ULong max,
        CORBA::ULong length,
        TaggedComponent* buffer,
        CORBA::Boolean release = 0
      );
    TaggedComponentList (const TaggedComponentList &);
    ~TaggedComponentList (void);

    static void _tao_any_destructor (void *);

    typedef TaggedComponentList_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_IOP_TAGGEDCOMPONENTSEQ_CH_)
#define _IOP_TAGGEDCOMPONENTSEQ_CH_

  class TaggedComponentSeq;

  typedef
    TAO_VarSeq_Var_T<
        TaggedComponentSeq,
        TaggedComponent
      >
    TaggedComponentSeq_var;

  typedef
    TAO_Seq_Out_T<
        TaggedComponentSeq,
        TaggedComponentSeq_var,
        TaggedComponent
      >
    TaggedComponentSeq_out;

  class TAO_Export TaggedComponentSeq
    : public
        TAO::unbounded_value_sequence<
            TaggedComponent
          >
  {
  public:
    TaggedComponentSeq (void);
    TaggedComponentSeq (CORBA::ULong max);
    TaggedComponentSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        TaggedComponent* buffer,
        CORBA::Boolean release = 0
      );
    TaggedComponentSeq (const TaggedComponentSeq &);
    ~TaggedComponentSeq (void);

    static void _tao_any_destructor (void *);

    typedef TaggedComponentSeq_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_ORB_TYPE = 0U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_CODE_SETS = 1U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_POLICIES = 2U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_ALTERNATE_IIOP_ADDRESS = 3U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_COMPLETE_OBJECT_KEY = 5U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_ENDPOINT_ID_POSITION = 6U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_LOCATION_POLICY = 12U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_DCE_STRING_BINDING = 100U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_DCE_BINDING_NAME = 101U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_DCE_NO_PIPES = 102U;

  // TAO_IDL - Generated from
  // be\be_visitor_typedef/typedef_ch.cpp:379

  typedef CORBA::ULong ServiceId;
  typedef CORBA::ULong_out ServiceId_out;

  // TAO_IDL - Generated from
  // be\be_type.cpp:258

  struct ServiceContext;

  typedef
    TAO_Var_Var_T<
        ServiceContext
      >
    ServiceContext_var;

  typedef
    TAO_Out_T<
        ServiceContext,
        ServiceContext_var
      >
    ServiceContext_out;

  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:57

  struct TAO_Export ServiceContext
  {
    typedef ServiceContext_var _var_type;

    static void _tao_any_destructor (void *);
    IOP::ServiceId context_id;
    CORBA::OctetSeq context_data;
  };

  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_IOP_SERVICECONTEXTLIST_CH_)
#define _IOP_SERVICECONTEXTLIST_CH_

  class ServiceContextList;

  typedef
    TAO_VarSeq_Var_T<
        ServiceContextList,
        ServiceContext
      >
    ServiceContextList_var;

  typedef
    TAO_Seq_Out_T<
        ServiceContextList,
        ServiceContextList_var,
        ServiceContext
      >
    ServiceContextList_out;

  class TAO_Export ServiceContextList
    : public
        TAO::unbounded_value_sequence<
            ServiceContext
          >
  {
  public:
    ServiceContextList (void);
    ServiceContextList (CORBA::ULong max);
    ServiceContextList (
        CORBA::ULong max,
        CORBA::ULong length,
        ServiceContext* buffer,
        CORBA::Boolean release = 0
      );
    ServiceContextList (const ServiceContextList &);
    ~ServiceContextList (void);

    static void _tao_any_destructor (void *);

    typedef ServiceContextList_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId TransactionService = 0U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId CodeSets = 1U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId ChainBypassCheck = 2U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId ChainBypassInfo = 3U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId LogicalThreadId = 4U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId BI_DIR_IIOP = 5U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId SendingContextRunTime = 6U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId INVOCATION_POLICIES = 7U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId UnknownExceptionInfo = 9U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId RTCorbaPriority = 10U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId RTCorbaPriorityRange = 11U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_FT_GROUP = 27U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_FT_PRIMARY = 28U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_FT_HEARTBEAT_ENABLED = 29U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId FT_GROUP_VERSION = 12U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId FT_REQUEST = 13U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ProfileId TAG_UIPMC = 3U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_GROUP = 39U;

  // TAO_IDL - Generated from
  // be\be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_GROUP_IIOP = 40U;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module IOP

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IOP::TaggedProfile &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IOP::TaggedProfile &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_IOP_TaggedProfileSeq_H_
#define _TAO_CDR_OP_IOP_TaggedProfileSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedProfileSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::TaggedProfileSeq &
  );

#endif /* _TAO_CDR_OP_IOP_TaggedProfileSeq_H_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IOP::IOR &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IOP::IOR &);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IOP::TaggedComponent &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IOP::TaggedComponent &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_IOP_MultipleComponentProfile_H_
#define _TAO_CDR_OP_IOP_MultipleComponentProfile_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::MultipleComponentProfile &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::MultipleComponentProfile &
  );

#endif /* _TAO_CDR_OP_IOP_MultipleComponentProfile_H_ */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_IOP_TaggedComponentList_H_
#define _TAO_CDR_OP_IOP_TaggedComponentList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedComponentList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::TaggedComponentList &
  );

#endif /* _TAO_CDR_OP_IOP_TaggedComponentList_H_ */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_IOP_TaggedComponentSeq_H_
#define _TAO_CDR_OP_IOP_TaggedComponentSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedComponentSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::TaggedComponentSeq &
  );

#endif /* _TAO_CDR_OP_IOP_TaggedComponentSeq_H_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IOP::ServiceContext &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IOP::ServiceContext &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_IOP_ServiceContextList_H_
#define _TAO_CDR_OP_IOP_ServiceContextList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::ServiceContextList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::ServiceContextList &
  );

#endif /* _TAO_CDR_OP_IOP_ServiceContextList_H_ */

// TAO_IDL - Generated from
// be\be_codegen.cpp:1062

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"

#endif /* ifndef */


