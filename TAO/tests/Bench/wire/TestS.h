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
// be/be_codegen.cpp:390

#ifndef _TAO_IDL_TESTS_H_
#define _TAO_IDL_TESTS_H_


#include "TestC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"
#include "tao/PortableServer/Collocated_Object.h"
#include "tao/PortableServer/ThruPOA_Object_Proxy_Impl.h"
#include "tao/PortableServer/Direct_Object_Proxy_Impl.h"

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
// be/be_visitor_module/module_sh.cpp:49

namespace POA_Test
{
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_sh.cpp:87
  
  class Hello;
  typedef Hello *Hello_ptr;
  
  class _TAO_Hello_ThruPOA_Proxy_Impl;
  class _TAO_Hello_Strategized_Proxy_Broker;
  
  class  Hello
    : public virtual PortableServer::ServantBase
  {
  protected:
    Hello (void);
  
  public:
    // Useful for template programming.
    typedef ::Test::Hello _stub_type;
    typedef ::Test::Hello_ptr _stub_ptr_type;
    typedef ::Test::Hello_var _stub_var_type;
    
    Hello (const Hello& rhs);
    virtual ~Hello (void);
    
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
    
    ::Test::Hello *_this (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_sh.cpp:45
    
    virtual char * get_string (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    static void get_string_skel (
        TAO_ServerRequest &_tao_req,
        void *_tao_servant,
        void *_tao_servant_upcall
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_sh.cpp:45
    
    virtual void shutdown (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    static void shutdown_skel (
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
  // be/be_visitor_interface/strategized_proxy_broker_sh.cpp:37
  
  class  _TAO_Hello_Strategized_Proxy_Broker
    : public virtual TAO::Collocation_Proxy_Broker
  {
  public: 
    _TAO_Hello_Strategized_Proxy_Broker (void);
    
    virtual ~_TAO_Hello_Strategized_Proxy_Broker (void);
    
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
  
  static
  _TAO_Hello_Strategized_Proxy_Broker *
  the_TAO_Hello_Strategized_Proxy_Broker (void);
};

//
//            End Strategized Proxy Broker Declaration 
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    ThruPOA Proxy Impl. Declaration
//

// TAO_IDL - Generated from
// be/be_visitor_interface/thru_poa_proxy_impl_sh.cpp:37

class  _TAO_Hello_ThruPOA_Proxy_Impl
  : public virtual TAO_ThruPOA_Object_Proxy_Impl
{
public:
  _TAO_Hello_ThruPOA_Proxy_Impl (void);
  
  virtual ~_TAO_Hello_ThruPOA_Proxy_Impl (void) {}
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/proxy_impl_xh.cpp:24
  
  static void
  get_string (
      CORBA::Object_ptr obj,
      CORBA::Object_out obj_forward,
      TAO::Argument ** args,
      int num_args
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/proxy_impl_xh.cpp:24
  
  static void
  shutdown (
      CORBA::Object_ptr obj,
      CORBA::Object_out obj_forward,
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
// be/be_visitor_module/module_sh.cpp:80

} // module Test

// TAO_IDL - Generated from 
// be/be_codegen.cpp:998

#include "TestS_T.h"

#if defined (__ACE_INLINE__)
#include "TestS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#endif /* ifndef */
