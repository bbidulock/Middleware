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
// be\be_codegen.cpp:390

#ifndef _TAO_IDL_ORIG_IMPLREPOS_H_
#define _TAO_IDL_ORIG_IMPLREPOS_H_

#include /**/ "ace/pre.h"

#include "tao/ImR_Client/ServerObjectS.h"
#include "ImplRepoC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_sh.cpp:49

namespace POA_ImplementationRepository
{
  
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_sh.cpp:87
  
  class ServerInformationIterator;
  typedef ServerInformationIterator *ServerInformationIterator_ptr;
  
  class _TAO_ServerInformationIterator_ThruPOA_Proxy_Impl;
  class _TAO_ServerInformationIterator_Direct_Proxy_Impl;
  class _TAO_ServerInformationIterator_Strategized_Proxy_Broker;
  
  class TAO_IMR_Client_Export ServerInformationIterator
    : public virtual PortableServer::ServantBase
  {
  protected:
    ServerInformationIterator (void);
  
  public:
    // Useful for template programming.
    typedef ::ImplementationRepository::ServerInformationIterator _stub_type;
    typedef ::ImplementationRepository::ServerInformationIterator_ptr _stub_ptr_type;
    typedef ::ImplementationRepository::ServerInformationIterator_var _stub_var_type;
    
    ServerInformationIterator (const ServerInformationIterator& rhs);
    virtual ~ServerInformationIterator (void);
    
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
    
    ::ImplementationRepository::ServerInformationIterator *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual CORBA::Boolean next_n (
        ::CORBA::ULong how_many,
        ::ImplementationRepository::ServerInformationList_out servers
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    static void next_n_skel (
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
  
  class TAO_IMR_Client_Export _TAO_ServerInformationIterator_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public: 
    _TAO_ServerInformationIterator_Strategized_Proxy_Broker (void);
    
    virtual ~_TAO_ServerInformationIterator_Strategized_Proxy_Broker (void);
    
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
    
    static _TAO_ServerInformationIterator_Strategized_Proxy_Broker *
    the_TAO_ServerInformationIterator_Strategized_Proxy_Broker (void);
  };
  
  //
  //            End Strategized Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////
  
  
  ///////////////////////////////////////////////////////////////////////
  //                    ThruPOA Proxy Impl. Declaration
  //
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/thru_poa_proxy_impl_sh.cpp:37
  
  class TAO_IMR_Client_Export _TAO_ServerInformationIterator_ThruPOA_Proxy_Impl
  {
  public:
    _TAO_ServerInformationIterator_ThruPOA_Proxy_Impl (void);
    
    virtual ~_TAO_ServerInformationIterator_ThruPOA_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    next_n (
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
  
  class TAO_IMR_Client_Export _TAO_ServerInformationIterator_Direct_Proxy_Impl
  {
  public:
    _TAO_ServerInformationIterator_Direct_Proxy_Impl (void);
    
    virtual ~_TAO_ServerInformationIterator_Direct_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    next_n (
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
  // be\be_visitor_interface/interface_sh.cpp:87
  
  class Administration;
  typedef Administration *Administration_ptr;
  
  class _TAO_Administration_ThruPOA_Proxy_Impl;
  class _TAO_Administration_Direct_Proxy_Impl;
  class _TAO_Administration_Strategized_Proxy_Broker;
  
  class TAO_IMR_Client_Export Administration
    : public virtual PortableServer::ServantBase
  {
  protected:
    Administration (void);
  
  public:
    // Useful for template programming.
    typedef ::ImplementationRepository::Administration _stub_type;
    typedef ::ImplementationRepository::Administration_ptr _stub_ptr_type;
    typedef ::ImplementationRepository::Administration_var _stub_var_type;
    
    Administration (const Administration& rhs);
    virtual ~Administration (void);
    
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
    
    ::ImplementationRepository::Administration *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void activate_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound,
        ::ImplementationRepository::CannotActivate
      )) = 0;
    
    static void activate_server_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void register_server (
        const char * server,
        const ::ImplementationRepository::StartupOptions & options
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::AlreadyRegistered,
        ::ImplementationRepository::NotFound
      )) = 0;
    
    static void register_server_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void reregister_server (
        const char * server,
        const ::ImplementationRepository::StartupOptions & options
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::AlreadyRegistered,
        ::ImplementationRepository::NotFound
      )) = 0;
    
    static void reregister_server_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void remove_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      )) = 0;
    
    static void remove_server_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void shutdown_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      )) = 0;
    
    static void shutdown_server_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void server_is_running (
        const char * server,
        const char * partial_ior,
        ::ImplementationRepository::ServerObject_ptr server_object
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      )) = 0;
    
    static void server_is_running_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void server_is_shutting_down (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      )) = 0;
    
    static void server_is_shutting_down_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void find (
        const char * server,
        ::ImplementationRepository::ServerInformation_out info
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      )) = 0;
    
    static void find_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_sh.cpp:45
    
    virtual void list (
        ::CORBA::ULong how_many,
        ::ImplementationRepository::ServerInformationList_out server_list,
        ::ImplementationRepository::ServerInformationIterator_out server_iterator
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    static void list_skel (
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
  
  class TAO_IMR_Client_Export _TAO_Administration_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public: 
    _TAO_Administration_Strategized_Proxy_Broker (void);
    
    virtual ~_TAO_Administration_Strategized_Proxy_Broker (void);
    
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
    
    static _TAO_Administration_Strategized_Proxy_Broker *
    the_TAO_Administration_Strategized_Proxy_Broker (void);
  };
  
  //
  //            End Strategized Proxy Broker Declaration 
  ///////////////////////////////////////////////////////////////////////
  
  
  ///////////////////////////////////////////////////////////////////////
  //                    ThruPOA Proxy Impl. Declaration
  //
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/thru_poa_proxy_impl_sh.cpp:37
  
  class TAO_IMR_Client_Export _TAO_Administration_ThruPOA_Proxy_Impl
  {
  public:
    _TAO_Administration_ThruPOA_Proxy_Impl (void);
    
    virtual ~_TAO_Administration_ThruPOA_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    activate_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound,
        ::ImplementationRepository::CannotActivate
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    register_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::AlreadyRegistered,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    reregister_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::AlreadyRegistered,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    remove_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    shutdown_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    server_is_running (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    server_is_shutting_down (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    find (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    list (
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
  
  class TAO_IMR_Client_Export _TAO_Administration_Direct_Proxy_Impl
  {
  public:
    _TAO_Administration_Direct_Proxy_Impl (void);
    
    virtual ~_TAO_Administration_Direct_Proxy_Impl (void) {}
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    activate_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound,
        ::ImplementationRepository::CannotActivate
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    register_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::AlreadyRegistered,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    reregister_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::AlreadyRegistered,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    remove_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    shutdown_server (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    server_is_running (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    server_is_shutting_down (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    find (
        TAO_Abstract_ServantBase *servant,
        TAO::Argument ** args,
        int num_args
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/proxy_impl_xh.cpp:24
    
    static void
    list (
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

} // module ImplementationRepository

// TAO_IDL - Generated from 
// be\be_codegen.cpp:997


#if defined (__ACE_INLINE__)
#include "ImplRepoS.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */

