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
// be/be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_IMR_LOCATORC_H_
#define _TAO_IDL_ORIG_IMR_LOCATORC_H_
#include /**/ "ace/pre.h"
#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ImplRepoC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_PortableServer_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

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
// be/be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  ImplementationRepository
{

  // TAO_IDL - Generated from
  // be/be_interface.cpp:570

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR__ODDS_N_ENDS_CH_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR__ODDS_N_ENDS_CH_

  class Locator;
  typedef Locator *Locator_ptr;

  typedef
    TAO_Objref_Var_T<
        Locator
      >
    Locator_var;

  typedef
    TAO_Objref_Out_T<
        Locator
      >
    Locator_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:50

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR_CH_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR_CH_

  class _TAO_Locator_Proxy_Impl;
  class _TAO_Locator_Remote_Proxy_Impl;
  class _TAO_Locator_Proxy_Broker;
  class _TAO_Locator_Remote_Proxy_Broker;

  class TAO_PortableServer_Export Locator
    : public virtual ImplementationRepository::Administration
  {
  public:
    typedef Locator_ptr _ptr_type;
    typedef Locator_var _var_type;
    static int _tao_class_id;

    // The static operations.
    static Locator_ptr _duplicate (Locator_ptr obj);

    static Locator_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static Locator_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static Locator_ptr _nil (void)
      {
        return (Locator_ptr)0;
      }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void activate_server_in_location (
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
        , ImplementationRepository::CannotActivate
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void remove_server_in_location (
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void shutdown_server_in_location (
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void server_is_shutting_down_in_location (
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::ULong register_activator (
        const char * location,
        CORBA::Object_ptr object_ref
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::AlreadyRegistered
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::ULong unregister_activator (
        const char * location,
        CORBA::Object_ptr object_ref
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:207

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual void *_tao_QueryInterface (ptrdiff_t type);

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    _TAO_Locator_Proxy_Broker *the_TAO_Locator_Proxy_Broker_;

  protected:
    Locator (int collocated = 0);

    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void ImplementationRepository_Locator_setup_collocation (int collocated);

    Locator (IOP::IOR *ior,
      TAO_ORB_Core *orb_core = 0);

    Locator (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0
      );
    virtual ~Locator (void);

    friend class _TAO_Locator_Remote_Proxy_Impl;
    friend class _TAO_Locator_ThruPOA_Proxy_Impl;
    friend class _TAO_Locator_Direct_Proxy_Impl;

  private:
    Locator (const Locator &);
    void operator= (const Locator &);
  };

  // The Proxy Implementations are used by each interface to
  // perform a call. Each different implementation encapsulates
  // an invocation logic.


  ///////////////////////////////////////////////////////////////////////
  //                    Base Proxy Impl. Declaration
  //

  // TAO_IDL - Generated from
  // be/be_visitor_interface/base_proxy_impl_ch.cpp:35

  class TAO_PortableServer_Export _TAO_Locator_Proxy_Impl
    : public virtual ImplementationRepository::_TAO_Administration_Proxy_Impl
  {
  public:
    virtual ~_TAO_Locator_Proxy_Impl (void) {}

    // TAO_IDL - Generated from
    // be/be_visitor_operation/base_proxy_impl_ch.cpp:24

    virtual void activate_server_in_location (
        CORBA::Object *_collocated_tao_target_,
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
        , ImplementationRepository::CannotActivate
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/base_proxy_impl_ch.cpp:24

    virtual void remove_server_in_location (
        CORBA::Object *_collocated_tao_target_,
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/base_proxy_impl_ch.cpp:24

    virtual void shutdown_server_in_location (
        CORBA::Object *_collocated_tao_target_,
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/base_proxy_impl_ch.cpp:24

    virtual void server_is_shutting_down_in_location (
        CORBA::Object *_collocated_tao_target_,
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/base_proxy_impl_ch.cpp:24

    virtual CORBA::ULong register_activator (
        CORBA::Object *_collocated_tao_target_,
        const char * location,
        CORBA::Object_ptr object_ref
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::AlreadyRegistered
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/base_proxy_impl_ch.cpp:24

    virtual CORBA::ULong unregister_activator (
        CORBA::Object *_collocated_tao_target_,
        const char * location,
        CORBA::Object_ptr object_ref
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      )) = 0;

  protected:
    _TAO_Locator_Proxy_Impl (void);
  };

  //
  //               End Base Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////


  ///////////////////////////////////////////////////////////////////////
  //                Remote Proxy Impl. Declaration
  //

  // TAO_IDL - Generated from
  // be/be_visitor_interface/remote_proxy_impl_ch.cpp:37

  class TAO_PortableServer_Export _TAO_Locator_Remote_Proxy_Impl
    : public virtual _TAO_Locator_Proxy_Impl,
      public virtual TAO_Remote_Object_Proxy_Impl,
      public virtual ImplementationRepository::_TAO_Administration_Remote_Proxy_Impl
  {
  public:
    _TAO_Locator_Remote_Proxy_Impl (void);

    virtual ~_TAO_Locator_Remote_Proxy_Impl (void) {}

    // TAO_IDL - Generated from
    // be/be_visitor_operation/proxy_impl_xh.cpp:24

    virtual void activate_server_in_location (
        CORBA::Object *_collocated_tao_target_,
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
        , ImplementationRepository::CannotActivate
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/proxy_impl_xh.cpp:24

    virtual void remove_server_in_location (
        CORBA::Object *_collocated_tao_target_,
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/proxy_impl_xh.cpp:24

    virtual void shutdown_server_in_location (
        CORBA::Object *_collocated_tao_target_,
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/proxy_impl_xh.cpp:24

    virtual void server_is_shutting_down_in_location (
        CORBA::Object *_collocated_tao_target_,
        const char * server,
        const char * location
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/proxy_impl_xh.cpp:24

    virtual CORBA::ULong register_activator (
        CORBA::Object *_collocated_tao_target_,
        const char * location,
        CORBA::Object_ptr object_ref
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::AlreadyRegistered
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/proxy_impl_xh.cpp:24

    virtual CORBA::ULong unregister_activator (
        CORBA::Object *_collocated_tao_target_,
        const char * location,
        CORBA::Object_ptr object_ref
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , ImplementationRepository::NotFound
      ));
  };

  //
  //             End Remote Proxy Impl. Declaration
  ///////////////////////////////////////////////////////////////////////

  // The Proxy Brokers are used by each interface to get
  // the right proxy for performing a call. In the new
  // collocation scheme, the proxy to be used can vary on
  // a call by call basis.

  ///////////////////////////////////////////////////////////////////////
  //                 Base Proxy Broker Declaration
  //

  // TAO_IDL - Generated from
  // be/be_visitor_interface/base_proxy_broker_ch.cpp:35

  class TAO_PortableServer_Export _TAO_Locator_Proxy_Broker
  {
  public:
    virtual ~_TAO_Locator_Proxy_Broker (void);
    virtual _TAO_Locator_Proxy_Impl &select_proxy (
        Locator *object
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      ) = 0;

  protected:
    _TAO_Locator_Proxy_Broker (void);

  };

  //
  //              End Base Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////


  ///////////////////////////////////////////////////////////////////////
  //                 Remote Proxy Broker Declaration
  //

  // TAO_IDL - Generated from
  // be/be_visitor_interface/remote_proxy_broker_ch.cpp:40

  class TAO_PortableServer_Export _TAO_Locator_Remote_Proxy_Broker
    : public virtual _TAO_Locator_Proxy_Broker
  {
  public:
    _TAO_Locator_Remote_Proxy_Broker (void);

    virtual ~_TAO_Locator_Remote_Proxy_Broker (void);

    virtual _TAO_Locator_Proxy_Impl &select_proxy (
        Locator *object
        ACE_ENV_ARG_DECL
      );

  private:
    _TAO_Locator_Remote_Proxy_Impl remote_proxy_impl_;

  public:
    // This member function is used to get an handle to the unique instance
    // of the Remote Proxy Broker that is available for a given
    // interface.
    static _TAO_Locator_Remote_Proxy_Broker *the_TAO_Locator_Remote_Proxy_Broker (void);
  };

  //
  //              End Remote Proxy Broker Declaration
  ///////////////////////////////////////////////////////////////////////

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Locator;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module ImplementationRepository

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:76

extern TAO_PortableServer_Export
ImplementationRepository::_TAO_Locator_Proxy_Broker *
(*ImplementationRepository__TAO_Locator_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, ImplementationRepository::Locator_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, ImplementationRepository::Locator_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::Locator_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:55

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::Locator_ptr );
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::Locator_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "ImR_LocatorC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */
