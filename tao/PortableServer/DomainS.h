/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_ORIG_DOMAINS_H_
#define _TAO_IDL_ORIG_DOMAINS_H_

#include "ace/pre.h"

#include "PortableServerC.h"
#include "POA_CORBA.h"
#include "Servant_Base.h"
#include "Collocated_Object.h"
#include "tao/DomainC.h"
#include "tao/Request_Info.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

  class POA_CORBA_DomainManager;
  typedef POA_CORBA_DomainManager *POA_CORBA_DomainManager_ptr;
  class TAO_PortableServer_Export POA_CORBA_DomainManager :  public virtual PortableServer::ServantBase
  {
  protected:
    POA_CORBA_DomainManager (void);

  public:
    POA_CORBA_DomainManager (const POA_CORBA_DomainManager& rhs);
    virtual ~POA_CORBA_DomainManager (void);


    virtual CORBA::Boolean _is_a (
        const char* logical_type_id,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void* _downcast (
        const char* logical_type_id
      );

    static void _is_a_skel (
        CORBA::ServerRequest &req,
        void *obj,
        void *context,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    static void _non_existent_skel (
        CORBA::ServerRequest &req,
        void *obj,
        void *context,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual void _dispatch (
        CORBA::ServerRequest &_tao_req,
        void *_tao_context,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    ::CORBA::DomainManager *_this (
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );

    virtual const char* _interface_repository_id (void) const;

    virtual CORBA::Policy_ptr get_domain_policy (
        CORBA::PolicyType policy_type,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    static void get_domain_policy_skel (
        CORBA::ServerRequest &_tao_req,
        void *_tao_obj,
        void *_tao_context,
        CORBA::Environment &ACE_TRY_ENV =
          TAO_default_environment ()
      );


#if (TAO_HAS_INTERCEPTORS == 1)
        // Generation of interceptors related RequestInfo classes per operation.
    // This needed to be able to store the arguments, exceptiosn, constexts
    // and build the lists dynamically on demand so that unnecessary time overhead
    // of building these lists when they arent used is avoided.
            class TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy : public TAO_ServerRequest_Info
    {
    public:
      friend class POA_CORBA_DomainManager;
      TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy (
        const char *  _tao_operation,
        IOP::ServiceContextList &_tao_service_context_list            ,      CORBA::PolicyType policy_type      ,
            CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
      );

       virtual Dynamic::ParameterList * arguments (
        CORBA::Environment &ACE_TRY_ENV =
           TAO_default_environment ())
       ACE_THROW_SPEC ((CORBA::SystemException));

        virtual Dynamic::ExceptionList * exceptions (
      CORBA::Environment &ACE_TRY_ENV =
         TAO_default_environment ())
     ACE_THROW_SPEC ((CORBA::SystemException));

    virtual CORBA::Any * result (
    CORBA::Environment &ACE_TRY_ENV =
       TAO_default_environment ())
   ACE_THROW_SPEC ((CORBA::SystemException));


private:
TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy (const TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy &);
void operator= (const TAO_ServerRequest_Info_CORBA_DomainManager_get_domain_policy &);
CORBA::PolicyType & policy_type_;
void result (CORBA::Policy_ptr  result);
 // update the result
CORBA::Policy_ptr  result_;
};

#endif /* TAO_HAS_INTERCEPTORS */

};


#if !defined (_CORBA_DOMAINMANAGER___THRU_POA_COLLOCATED_SH_)
#define _CORBA_DOMAINMANAGER___THRU_POA_COLLOCATED_SH_

class TAO_PortableServer_Export POA_CORBA__tao_thru_poa_collocated_DomainManager   : public virtual ::CORBA::DomainManager
{
public:
  POA_CORBA__tao_thru_poa_collocated_DomainManager (
      TAO_Stub *stub
    );
  virtual CORBA::Boolean _is_a(
      const CORBA::Char *logical_type_id,
      CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
    );

  virtual CORBA::Boolean _non_existent(
      CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
    );

    virtual CORBA::Policy_ptr get_domain_policy (
      CORBA::PolicyType policy_type,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

};


#endif /* end #if !defined */


#if !defined (_CORBA_DOMAINMANAGER___DIRECT_COLLOCATED_SH_)
#define _CORBA_DOMAINMANAGER___DIRECT_COLLOCATED_SH_

class TAO_PortableServer_Export POA_CORBA__tao_direct_collocated_DomainManager   :  public virtual CORBA::DomainManager, public virtual TAO_Collocated_Object
{
public:
  POA_CORBA__tao_direct_collocated_DomainManager (
      POA_CORBA_DomainManager_ptr  servant,
      TAO_Stub *stub
    );
  virtual CORBA::Boolean _is_a(
      const CORBA::Char *logical_type_id,
      CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
    );
  virtual void *_tao_QueryInterface (ptr_arith_t type);

  POA_CORBA_DomainManager_ptr _get_servant (void) const;

  virtual CORBA::Boolean _non_existent(
      CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
    );

    virtual CORBA::Policy_ptr get_domain_policy (
      CORBA::PolicyType policy_type,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));


private:
  POA_CORBA_DomainManager_ptr servant_;
};


#endif /* end #if !defined */


#if defined (ACE_HAS_USING_KEYWORD)
// TIE class: Refer to CORBA v2.2, Section 20.34.4
template <class T>
class TAO_PortableServer_Export POA_CORBA_DomainManager_tie : public POA_CORBA_DomainManager
{
public:
  POA_CORBA_DomainManager_tie (T &t);
  // the T& ctor
  POA_CORBA_DomainManager_tie (T &t, PortableServer::POA_ptr poa);
  // ctor taking a POA
  POA_CORBA_DomainManager_tie (T *tp, CORBA::Boolean release=1);
  // ctor taking pointer and an ownership flag
  POA_CORBA_DomainManager_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
  // ctor with T*, ownership flag and a POA
  ~POA_CORBA_DomainManager_tie (void);
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
  CORBA::Policy_ptr get_domain_policy (
      CORBA::PolicyType policy_type,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

private:
  T *ptr_;
  PortableServer::POA_var poa_;
  CORBA::Boolean rel_;

  // copy and assignment are not allowed
  POA_CORBA_DomainManager_tie (const POA_CORBA_DomainManager_tie &);
  void operator= (const POA_CORBA_DomainManager_tie &);
};

#endif /* ACE_HAS_USING_KEYWORD */

#if (TAO_HAS_MINIMUM_CORBA == 0)

class POA_CORBA_ConstructionPolicy;
typedef POA_CORBA_ConstructionPolicy *POA_CORBA_ConstructionPolicy_ptr;
class TAO_PortableServer_Export POA_CORBA_ConstructionPolicy : public virtual POA_CORBA::Policy
{
protected:
  POA_CORBA_ConstructionPolicy (void);

public:
  POA_CORBA_ConstructionPolicy (const POA_CORBA_ConstructionPolicy& rhs);
  virtual ~POA_CORBA_ConstructionPolicy (void);


  virtual CORBA::Boolean _is_a (
      const char* logical_type_id,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  virtual void* _downcast (
      const char* logical_type_id
    );

  static void _is_a_skel (
      CORBA::ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  static void _non_existent_skel (
      CORBA::ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  virtual void _dispatch (
      CORBA::ServerRequest &_tao_req,
      void *_tao_context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  ::CORBA::ConstructionPolicy *_this (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  virtual const char* _interface_repository_id (void) const;

  virtual void make_domain_manager (
      IR_InterfaceDef* object_type,
      CORBA::Boolean constr_policy,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  static void make_domain_manager_skel (
      CORBA::ServerRequest &_tao_req,
      void *_tao_obj,
      void *_tao_context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  static void _get_policy_type_skel (
      CORBA::ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  static void copy_skel (
      CORBA::ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );

  static void destroy_skel (
      CORBA::ServerRequest &req,
      void *obj,
      void *context,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    );


#if (TAO_HAS_INTERCEPTORS == 1)
    // Generation of interceptors related RequestInfo classes per operation.
  // This needed to be able to store the arguments, exceptiosn, constexts
  // and build the lists dynamically on demand so that unnecessary time overhead
  // of building these lists when they arent used is avoided.
      class TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager : public TAO_ServerRequest_Info
  {
  public:
    friend class POA_CORBA_ConstructionPolicy;
    TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager (
      const char *  _tao_operation,
      IOP::ServiceContextList &_tao_service_context_list        ,    IR_InterfaceDef* object_type        ,    CORBA::Boolean constr_policy    ,
        CORBA::Environment &ACE_TRY_ENV =
      TAO_default_environment ()
    );

     virtual Dynamic::ParameterList * arguments (
      CORBA::Environment &ACE_TRY_ENV =
         TAO_default_environment ())
     ACE_THROW_SPEC ((CORBA::SystemException));

    virtual Dynamic::ExceptionList * exceptions (
    CORBA::Environment &ACE_TRY_ENV =
       TAO_default_environment ())
   ACE_THROW_SPEC ((CORBA::SystemException));

virtual CORBA::Any * result (
  CORBA::Environment &ACE_TRY_ENV =
     TAO_default_environment ())
 ACE_THROW_SPEC ((CORBA::SystemException));


private:
TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager (const TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager &);
void operator= (const TAO_ServerRequest_Info_CORBA_ConstructionPolicy_make_domain_manager &);
IR_InterfaceDef* & object_type_;
CORBA::Boolean & constr_policy_;
};

#endif /* TAO_HAS_INTERCEPTORS */

};


#if !defined (_CORBA_CONSTRUCTIONPOLICY___THRU_POA_COLLOCATED_SH_)
#define _CORBA_CONSTRUCTIONPOLICY___THRU_POA_COLLOCATED_SH_

class TAO_PortableServer_Export POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy   : public virtual ::CORBA::ConstructionPolicy,
    public virtual POA_CORBA::_tao_thru_poa_collocated_Policy
{
public:
  POA_CORBA__tao_thru_poa_collocated_ConstructionPolicy (
      TAO_Stub *stub
    );
  virtual CORBA::Boolean _is_a(
      const CORBA::Char *logical_type_id,
      CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
    );

  virtual CORBA::Boolean _non_existent(
      CORBA_Environment &ACE_TRY_ENV = TAO_default_environment ()
    );

    virtual void make_domain_manager (
      IR_InterfaceDef* object_type,
      CORBA::Boolean constr_policy,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

};


#endif /* end #if !defined */


#if defined (ACE_HAS_USING_KEYWORD)
// TIE class: Refer to CORBA v2.2, Section 20.34.4
template <class T>
class TAO_PortableServer_Export POA_CORBA_ConstructionPolicy_tie : public POA_CORBA_ConstructionPolicy
{
public:
  POA_CORBA_ConstructionPolicy_tie (T &t);
  // the T& ctor
  POA_CORBA_ConstructionPolicy_tie (T &t, PortableServer::POA_ptr poa);
  // ctor taking a POA
  POA_CORBA_ConstructionPolicy_tie (T *tp, CORBA::Boolean release=1);
  // ctor taking pointer and an ownership flag
  POA_CORBA_ConstructionPolicy_tie (T *tp, PortableServer::POA_ptr poa, CORBA::Boolean release=1);
  // ctor with T*, ownership flag and a POA
  ~POA_CORBA_ConstructionPolicy_tie (void);
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
  void make_domain_manager (
      IR_InterfaceDef* object_type,
      CORBA::Boolean constr_policy,
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CORBA::PolicyType policy_type (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  CORBA::Policy_ptr copy (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  void destroy (
      CORBA::Environment &ACE_TRY_ENV =
        TAO_default_environment ()
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

private:
  T *ptr_;
  PortableServer::POA_var poa_;
  CORBA::Boolean rel_;

  // copy and assignment are not allowed
  POA_CORBA_ConstructionPolicy_tie (const POA_CORBA_ConstructionPolicy_tie &);
  void operator= (const POA_CORBA_ConstructionPolicy_tie &);
};

#endif /* ACE_HAS_USING_KEYWORD */

#endif /* TAO_HAS_MINIMUM_CORBA */

#include "DomainS_T.h"

#if defined (__ACE_INLINE__)
#include "DomainS.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* ifndef */
