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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_ORIG_POLICYS_H_
#define _TAO_IDL_ORIG_POLICYS_H_

#include "ace/pre.h"
#include "tao/PolicyC.h"


#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"
#include "tao/PortableServer/Collocated_Object.h"
#include "tao/PortableServer/ThruPOA_Object_Proxy_Impl.h"
#include "tao/PortableServer/Direct_Object_Proxy_Impl.h"
#include "tao/PortableInterceptor.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

class POA_CORBA_Policy;
typedef POA_CORBA_Policy *POA_CORBA_Policy_ptr;
// Forward Classes Declaration
class _TAO_CORBA_Policy_ThruPOA_Proxy_Impl;
class _TAO_CORBA_Policy_Direct_Proxy_Impl;
class _TAO_CORBA_Policy_Strategized_Proxy_Broker;

class TAO_PortableServer_Export POA_CORBA_Policy :  public virtual PortableServer::ServantBase
{
protected:
  POA_CORBA_Policy (void);

public:
  POA_CORBA_Policy (const POA_CORBA_Policy& rhs);
  virtual ~POA_CORBA_Policy (void);


  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  virtual void* _downcast (
      const char* logical_type_id
    );

  static void _is_a_skel (
      TAO_ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  static void _non_existent_skel (
      TAO_ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  static void _interface_skel (
      TAO_ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  virtual void _dispatch (
      TAO_ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  ::CORBA_Policy *_this (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  virtual const char* _interface_repository_id (void) const;

  virtual CORBA::PolicyType policy_type (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void _get_policy_type_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_obj,
      void *_tao_context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  virtual CORBA_Policy_ptr copy (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void copy_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_obj,
      void *_tao_context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  virtual void destroy (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void destroy_skel (
      TAO_ServerRequest &_tao_req,
      void *_tao_obj,
      void *_tao_context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );


};


///////////////////////////////////////////////////////////////////////
//               Strategized Proxy Broker Declaration
//

class TAO_PortableServer_Export _TAO_CORBA_Policy_Strategized_Proxy_Broker : public virtual ::_TAO_CORBA_Policy_Proxy_Broker
{
public:
  _TAO_CORBA_Policy_Strategized_Proxy_Broker (void);

  virtual ~_TAO_CORBA_Policy_Strategized_Proxy_Broker (void);

  virtual ::_TAO_CORBA_Policy_Proxy_Impl &select_proxy (
    ::CORBA_Policy *object,
    CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
  );

private:

// Helper methods that takes care to create the proxy
// as soon as their use is necessary.
  void create_proxy (
    int collocation_strategy,
    CORBA::Environment &ACE_TRY_ENV
  );

private:

  // Caches the proxy implementations. The proxy implementation
  // are totally stateless, and those can be shared by all the
  // instances of a given IDL interface type.
  ::_TAO_CORBA_Policy_Proxy_Impl
   *proxy_cache_[TAO_Collocation_Strategies::CS_LAST];

  TAO_SYNCH_MUTEX mutex_;
// This funxtion is used to get an handle to the unique instance
// of the Strategized Proxy Broker that is available for a given
// interface.

public:
  static _TAO_CORBA_Policy_Strategized_Proxy_Broker *the_TAO_CORBA_Policy_Strategized_Proxy_Broker (void);
};


//
//            End Strategized Proxy Broker Declaration
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    ThruPOA  Impl. Declaration
//

class TAO_PortableServer_Export _TAO_CORBA_Policy_ThruPOA_Proxy_Impl :
  public virtual ::_TAO_CORBA_Policy_Proxy_Impl,
  public virtual TAO_ThruPOA_Object_Proxy_Impl
{
public:
  _TAO_CORBA_Policy_ThruPOA_Proxy_Impl (void);

  virtual ~_TAO_CORBA_Policy_ThruPOA_Proxy_Impl (void) { }

    virtual CORBA::PolicyType policy_type (
      CORBA_Object *_collocated_tao_target_,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual CORBA_Policy_ptr copy (
      CORBA_Object *_collocated_tao_target_,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void destroy (
      CORBA_Object *_collocated_tao_target_,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

};


//
//                ThruPOA  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    Direct  Impl. Declaration
//

class TAO_PortableServer_Export _TAO_CORBA_Policy_Direct_Proxy_Impl :
  public virtual _TAO_CORBA_Policy_Proxy_Impl,
  public virtual TAO_Direct_Object_Proxy_Impl
{
public:
  _TAO_CORBA_Policy_Direct_Proxy_Impl (void);

  virtual ~_TAO_CORBA_Policy_Direct_Proxy_Impl (void) { }

    virtual CORBA::PolicyType policy_type (
      CORBA_Object *_collocated_tao_target_,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual CORBA_Policy_ptr copy (
      CORBA_Object *_collocated_tao_target_,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void destroy (
      CORBA_Object *_collocated_tao_target_,
      CORBA::Environment &ACE_TRY_ENV
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

};


//
//                Direct  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////


#include "PolicyS_T.h"

#if defined (__ACE_INLINE__)
#include "PolicyS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include "ace/post.h"
#endif /* ifndef */
