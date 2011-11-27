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
// be\be_codegen.cpp:391

#ifndef _TAO_IDL_ORIG_POLICYS_H_
#define _TAO_IDL_ORIG_POLICYS_H_

#include /**/ "ace/pre.h"

#include "tao/PolicyC.h"
#include "tao/UShortSeqS.h"
#include "tao/CurrentS.h"
#include "tao/Policy_ForwardS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#include "tao/PortableServer/portableserver_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

// TAO_IDL - Generated from
// be\be_visitor_module/module_sh.cpp:49

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87

  class Policy;
  typedef Policy *Policy_ptr;

  class TAO_PortableServer_Export Policy
    : public virtual PortableServer::ServantBase
  {
  protected:
    Policy (void);

  public:
    // Useful for template programming.
    typedef ::CORBA::Policy _stub_type;
    typedef ::CORBA::Policy_ptr _stub_ptr_type;
    typedef ::CORBA::Policy_var _stub_var_type;

    Policy (const Policy& rhs);
    virtual ~Policy (void);

    virtual CORBA::Boolean _is_a (
        const char* logical_type_id);

    virtual void _dispatch (
        TAO_ServerRequest & req,
        TAO::Portable_Server::Servant_Upcall *servant_upcall);

    ::CORBA::Policy *_this (void);

    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual CORBA::PolicyType policy_type (void) = 0;

    static void _get_policy_type_skel (
        TAO_ServerRequest & server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase* servant);

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::Policy_ptr copy (void) = 0;

    static void copy_skel (
        TAO_ServerRequest & server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase* servant);

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual void destroy (void) = 0;

    static void destroy_skel (
        TAO_ServerRequest & server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase* servant);
  };

  // TAO_IDL - Generated from
  // be\be_visitor_interface/direct_proxy_impl_sh.cpp:31

  ///////////////////////////////////////////////////////////////////////
  //                    Direct  Impl. Declaration
  //

  class TAO_PortableServer_Export _TAO_Policy_Direct_Proxy_Impl
  {
  public:
    _TAO_Policy_Direct_Proxy_Impl (void);

    virtual ~_TAO_Policy_Direct_Proxy_Impl (void);

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    _get_policy_type (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args);

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    copy (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args);

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    destroy (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args);
  };

  //
  //                Direct  Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////



// TAO_IDL - Generated from
// be\be_visitor_module/module_sh.cpp:80

} // module CORBA

// TAO_IDL - Generated from
// be\be_codegen.cpp:995

TAO_END_VERSIONED_NAMESPACE_DECL

#include "tao/PortableServer/PolicyS_T.h"


#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* ifndef */

