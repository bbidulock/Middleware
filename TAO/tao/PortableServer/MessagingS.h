/* -*- C++ -*- $Id$ */


// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_ORIG_MESSAGINGS_H_
#define _TAO_IDL_ORIG_MESSAGINGS_H_

#include "ace/pre.h"
#include "tao/orbconf.h"
#include "tao/ORB_Core.h"

#if (TAO_HAS_CORBA_MESSAGING == 1)

#include "PortableServerC.h"
#include "Servant_Base.h"
#include "Collocated_Object.h"
#include "tao/TimeBaseS.h"
#include "tao/MessagingC.h"
#include "tao/PortableServer/ThruPOA_Object_Proxy_Impl.h"
#include "tao/PortableServer/Direct_Object_Proxy_Impl.h"
#include "tao/PortableServer/ServerRequestInfo.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

TAO_NAMESPACE  POA_Messaging
{

#if (TAO_HAS_AMI_CALLBACK == 1)

  // Forward Classes Declaration
  class _TAO_ReplyHandler_ThruPOA_Proxy_Impl;
  class _TAO_ReplyHandler_Direct_Proxy_Impl;
  class _TAO_ReplyHandler_Strategized_Proxy_Broker;
  class ReplyHandler;
  typedef ReplyHandler *ReplyHandler_ptr;
  class TAO_PortableServer_Export ReplyHandler :  public virtual PortableServer::ServantBase
  {
  protected:
    ReplyHandler (void);

  public:
    ReplyHandler (const ReplyHandler& rhs);
    virtual ~ReplyHandler (void);


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

    virtual void _dispatch (
        TAO_ServerRequest &_tao_req,
        void *_tao_context,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    ::Messaging::ReplyHandler *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;


  };


  ///////////////////////////////////////////////////////////////////////
  //               Strategized Proxy Broker Declaration
  //

  class TAO_PortableServer_Export _TAO_ReplyHandler_Strategized_Proxy_Broker : public virtual ::Messaging::_TAO_ReplyHandler_Proxy_Broker
  {
  public:
    _TAO_ReplyHandler_Strategized_Proxy_Broker (void);

    virtual ~_TAO_ReplyHandler_Strategized_Proxy_Broker (void);

    virtual ::Messaging::_TAO_ReplyHandler_Proxy_Impl &select_proxy (
      ::Messaging::ReplyHandler *object,
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
    ::Messaging::_TAO_ReplyHandler_Proxy_Impl
     *proxy_cache_[TAO_Collocation_Strategies::CS_LAST];

    TAO_SYNCH_MUTEX mutex_;

  public:
    // This funxtion is used to get an handle to the unique instance
    // of the Strategized Proxy Broker that is available for a given
    // interface.

    static _TAO_ReplyHandler_Strategized_Proxy_Broker *the_TAO_ReplyHandler_Strategized_Proxy_Broker (void);
  };

  //
  //            End Strategized Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    ThruPOA  Impl. Declaration
//

class TAO_PortableServer_Export _TAO_ReplyHandler_ThruPOA_Proxy_Impl :
  public virtual ::Messaging::_TAO_ReplyHandler_Proxy_Impl,
  public virtual TAO_ThruPOA_Object_Proxy_Impl
{
public:
  ~_TAO_ReplyHandler_ThruPOA_Proxy_Impl (void);

  };


//
//                ThruPOA  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                    Direct  Impl. Declaration
//

 class TAO_PortableServer_Export _TAO_ReplyHandler_Direct_Proxy_Impl :
  public virtual Messaging::_TAO_ReplyHandler_Proxy_Impl,
  public virtual TAO_Direct_Object_Proxy_Impl
 {
 public:
   ~_TAO_ReplyHandler_Direct_Proxy_Impl (void);

 };

//
//                Direct  Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////



#if defined (ACE_HAS_USING_KEYWORD)
  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class TAO_PortableServer_Export ReplyHandler_tie : public ReplyHandler
  {
  public:
    ReplyHandler_tie (T &t);
    // the T& ctor
    ReplyHandler_tie (T &t, PortableServer::POA_ptr poa);
    // ctor taking a POA
    ReplyHandler_tie (T *tp, CORBA::Boolean release=1);
    // ctor taking pointer and an ownership flag
    ReplyHandler_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
    // ctor with T*, ownership flag and a POA
    ~ReplyHandler_tie (void);
    // dtor

    // TIE specific functions
    T *_tied_object (void);
    // return the underlying object
    void _tied_object (T &obj);
    // set the underlying object
    void _tied_object (T *obj, CORBA::Boolean release=1);
    // set the underlying object and the ownership flag
    CORBA::Boolean _is_owner (void);
    // do we own it
    void _is_owner (CORBA::Boolean b);
    // set the ownership

    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );
private:
    T *ptr_;
    PortableServer::POA_var poa_;
    CORBA::Boolean rel_;

    // copy and assignment are not allowed
    ReplyHandler_tie (const ReplyHandler_tie &);
    void operator= (const ReplyHandler_tie &);
  };

#endif /* ACE_HAS_USING_KEYWORD */

#endif /* TAO_HAS_AMI_CALLBACK == 1 */

}
TAO_NAMESPACE_CLOSE

#include "MessagingS_T.h"

#if defined (__ACE_INLINE__)
#include "MessagingS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#endif /* TAO_HAS_CORBA_MESSAGING == 1 */

#include "ace/post.h"
#endif /* ifndef */
