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
// be\be_codegen.cpp:411

#ifndef _TAO_IDL_ORIG_POLICYS_H_
#define _TAO_IDL_ORIG_POLICYS_H_

#include /**/ "ace/pre.h"

#include "tao/PolicyC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

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
// be\be_visitor_module/module_sh.cpp:49

namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:90

  class Policy;
  typedef Policy *Policy_ptr;

  class _TAO_Policy_ThruPOA_Proxy_Impl;
  class _TAO_Policy_Direct_Proxy_Impl;
  class _TAO_Policy_Strategized_Proxy_Broker;

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
        const char* logical_type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    static void _is_a_skel (
        TAO_ServerRequest &req,
        void *servant,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );

    static void _non_existent_skel (
        TAO_ServerRequest &req,
        void *servant,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );

    static void _interface_skel (
        TAO_ServerRequest &req,
        void *servant,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );

    static void _component_skel (
        TAO_ServerRequest &req,
        void *obj,
        void *servant_upcall
        ACE_ENV_ARG_DECL
      );

    virtual void _dispatch (
        TAO_ServerRequest &req,
        void *_servant_upcall
        ACE_ENV_ARG_DECL
      );

    ::CORBA::Policy *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual CORBA::PolicyType policy_type (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void _get_policy_type_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual ::CORBA::Policy_ptr copy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void copy_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45

    virtual void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void destroy_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
  };

  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration
  //

  // TAO_IDL - Generated from
  // be\be_visitor_interface/strategized_proxy_broker_sh.cpp:36

  class TAO_PortableServer_Export _TAO_Policy_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public:
    _TAO_Policy_Strategized_Proxy_Broker (void);

    virtual ~_TAO_Policy_Strategized_Proxy_Broker (void);

    TAO::Collocation_Strategy
    get_strategy (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::SystemException));

    void
    dispatch (
        CORBA::Object_ptr obj,
        CORBA::Object_out forward_obj,
        TAO::Argument ** args,
        int num_args,
        const char * op,
        size_t op_len,
        TAO::Collocation_Strategy strategy
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((CORBA::Exception));

    static _TAO_Policy_Strategized_Proxy_Broker *
    the_TAO_Policy_Strategized_Proxy_Broker (void);
  };

  //
  //            End Strategized Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////


  ///////////////////////////////////////////////////////////////////////
  //                    ThruPOA Proxy Impl. Declaration
  //

  // TAO_IDL - Generated from
  // be\be_visitor_interface/thru_poa_proxy_impl_sh.cpp:37

  class TAO_PortableServer_Export _TAO_Policy_ThruPOA_Proxy_Impl
  {
  public:
    _TAO_Policy_ThruPOA_Proxy_Impl (void);

    virtual ~_TAO_Policy_ThruPOA_Proxy_Impl (void) {}

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    _get_policy_type (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    copy (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    destroy (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  };

  //
  //                ThruPOA  Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////

  // TAO_IDL - Generated from
  // be\be_visitor_interface/direct_proxy_impl_sh.cpp:31

  ///////////////////////////////////////////////////////////////////////
  //                    Direct  Impl. Declaration
  //

class TAO_PortableServer_Export _TAO_Policy_Direct_Proxy_Impl
  {
  public:
    _TAO_Policy_Direct_Proxy_Impl (void);

    virtual ~_TAO_Policy_Direct_Proxy_Impl (void) {}

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    _get_policy_type (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    copy (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24

    static void
    destroy (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
  };

  //
  //                Direct  Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////



// TAO_IDL - Generated from
// be\be_visitor_module/module_sh.cpp:80

} // module CORBA

// TAO_IDL - Generated from
// be\be_codegen.cpp:1014

#include "PolicyS_T.h"

#if defined (__ACE_INLINE__)
#include "PolicyS.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */
