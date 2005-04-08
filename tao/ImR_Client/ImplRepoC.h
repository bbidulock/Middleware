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
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_IMPLREPOC_H_
#define _TAO_IDL_ORIG_IMPLREPOC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "imr_client_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#include "tao/ImR_Client/ServerObjectC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IMR_Client_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// be\be_visitor_root/root_ch.cpp:62

namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace ImplementationRepository
{
  
  // TAO_IDL - Generated from
  // be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_IMPLEMENTATIONREPOSITORY_ALREADYREGISTERED_CH_)
#define _IMPLEMENTATIONREPOSITORY_ALREADYREGISTERED_CH_
  
  class TAO_IMR_Client_Export AlreadyRegistered : public CORBA::UserException
  {
  public:
    
    AlreadyRegistered (void);
    AlreadyRegistered (const AlreadyRegistered &);
    ~AlreadyRegistered (void);

    AlreadyRegistered &operator= (const AlreadyRegistered &);
    
    static void _tao_any_destructor (void *);
    
    static AlreadyRegistered *_downcast (CORBA::Exception *);
    static const AlreadyRegistered *_downcast (CORBA::Exception const *);
    
    static CORBA::Exception *_alloc (void);
    
    virtual CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (
        TAO_OutputCDR &
        ACE_ENV_ARG_DECL
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ch.cpp:127
    
    virtual CORBA::TypeCode_ptr _tao_type (void) const;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_AlreadyRegistered;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_IMPLEMENTATIONREPOSITORY_CANNOTACTIVATE_CH_)
#define _IMPLEMENTATIONREPOSITORY_CANNOTACTIVATE_CH_
  
  class TAO_IMR_Client_Export CannotActivate : public CORBA::UserException
  {
  public:
    
    TAO_String_Manager reason;
    CannotActivate (void);
    CannotActivate (const CannotActivate &);
    ~CannotActivate (void);

    CannotActivate &operator= (const CannotActivate &);
    
    static void _tao_any_destructor (void *);
    
    static CannotActivate *_downcast (CORBA::Exception *);
    static const CannotActivate *_downcast (CORBA::Exception const *);
    
    static CORBA::Exception *_alloc (void);
    
    virtual CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (
        TAO_OutputCDR &
        ACE_ENV_ARG_DECL
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ctor.cpp:66
    
    CannotActivate (
        const char * _tao_reason
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ch.cpp:127
    
    virtual CORBA::TypeCode_ptr _tao_type (void) const;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_CannotActivate;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_IMPLEMENTATIONREPOSITORY_NOTFOUND_CH_)
#define _IMPLEMENTATIONREPOSITORY_NOTFOUND_CH_
  
  class TAO_IMR_Client_Export NotFound : public CORBA::UserException
  {
  public:
    
    NotFound (void);
    NotFound (const NotFound &);
    ~NotFound (void);

    NotFound &operator= (const NotFound &);
    
    static void _tao_any_destructor (void *);
    
    static NotFound *_downcast (CORBA::Exception *);
    static const NotFound *_downcast (CORBA::Exception const *);
    
    static CORBA::Exception *_alloc (void);
    
    virtual CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (
        TAO_OutputCDR &
        ACE_ENV_ARG_DECL
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &
        ACE_ENV_ARG_DECL
      );
    
    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ch.cpp:127
    
    virtual CORBA::TypeCode_ptr _tao_type (void) const;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_NotFound;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:258
  
  struct EnvironmentVariable;
  
  typedef
    TAO_Var_Var_T<
        EnvironmentVariable
      >
    EnvironmentVariable_var;
  
  typedef
    TAO_Out_T<
        EnvironmentVariable,
        EnvironmentVariable_var
      >
    EnvironmentVariable_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_IMR_Client_Export EnvironmentVariable
  {
    typedef EnvironmentVariable_var _var_type;
    
    static void _tao_any_destructor (void *);
    TAO_String_Manager name;
    TAO_String_Manager value;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_EnvironmentVariable;
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_IMPLEMENTATIONREPOSITORY_ENVIRONMENTLIST_CH_)
#define _IMPLEMENTATIONREPOSITORY_ENVIRONMENTLIST_CH_
  
  class EnvironmentList;
  
  typedef
    TAO_VarSeq_Var_T<
        EnvironmentList,
        EnvironmentVariable
      >
    EnvironmentList_var;
  
  typedef
    TAO_Seq_Out_T<
        EnvironmentList,
        EnvironmentList_var,
        EnvironmentVariable
      >
    EnvironmentList_out;
  
  class TAO_IMR_Client_Export EnvironmentList
    : public
        TAO_Unbounded_Sequence<
            EnvironmentVariable
          >
  {
  public:
    EnvironmentList (void);
    EnvironmentList (CORBA::ULong max);
    EnvironmentList (
        CORBA::ULong max,
        CORBA::ULong length,
        EnvironmentVariable* buffer, 
        CORBA::Boolean release = 0
      );
    EnvironmentList (const EnvironmentList &);
    ~EnvironmentList (void);
    
    static void _tao_any_destructor (void *);
    
    typedef EnvironmentList_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_EnvironmentList;
  
  // TAO_IDL - Generated from
  // be\be_visitor_enum/enum_ch.cpp:57
  
  enum ActivationMode
  {
    NORMAL,
    MANUAL,
    PER_CLIENT,
    AUTO_START
  };
  
  typedef ActivationMode &ActivationMode_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_ActivationMode;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:258
  
  struct StartupOptions;
  
  typedef
    TAO_Var_Var_T<
        StartupOptions
      >
    StartupOptions_var;
  
  typedef
    TAO_Out_T<
        StartupOptions,
        StartupOptions_var
      >
    StartupOptions_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_IMR_Client_Export StartupOptions
  {
    typedef StartupOptions_var _var_type;
    
    static void _tao_any_destructor (void *);
    TAO_String_Manager command_line;
    ImplementationRepository::EnvironmentList environment;
    TAO_String_Manager working_directory;
    ImplementationRepository::ActivationMode activation;
    TAO_String_Manager activator;
    CORBA::Long start_limit;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_StartupOptions;
  
  // TAO_IDL - Generated from
  // be\be_type.cpp:258
  
  struct ServerInformation;
  
  typedef
    TAO_Var_Var_T<
        ServerInformation
      >
    ServerInformation_var;
  
  typedef
    TAO_Out_T<
        ServerInformation,
        ServerInformation_var
      >
    ServerInformation_out;
  
  // TAO_IDL - Generated from
  // be\be_visitor_structure/structure_ch.cpp:52
  
  struct TAO_IMR_Client_Export ServerInformation
  {
    typedef ServerInformation_var _var_type;
    
    static void _tao_any_destructor (void *);
    TAO_String_Manager server;
    ImplementationRepository::StartupOptions startup;
    TAO_String_Manager partial_ior;
  };
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_ServerInformation;
  
  // TAO_IDL - Generated from
  // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONLIST_CH_)
#define _IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONLIST_CH_
  
  class ServerInformationList;
  
  typedef
    TAO_VarSeq_Var_T<
        ServerInformationList,
        ServerInformation
      >
    ServerInformationList_var;
  
  typedef
    TAO_Seq_Out_T<
        ServerInformationList,
        ServerInformationList_var,
        ServerInformation
      >
    ServerInformationList_out;
  
  class TAO_IMR_Client_Export ServerInformationList
    : public
        TAO_Unbounded_Sequence<
            ServerInformation
          >
  {
  public:
    ServerInformationList (void);
    ServerInformationList (CORBA::ULong max);
    ServerInformationList (
        CORBA::ULong max,
        CORBA::ULong length,
        ServerInformation* buffer, 
        CORBA::Boolean release = 0
      );
    ServerInformationList (const ServerInformationList &);
    ~ServerInformationList (void);
    
    static void _tao_any_destructor (void *);
    
    typedef ServerInformationList_var _var_type;
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_ServerInformationList;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR__VAR_OUT_CH_)
#define _IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR__VAR_OUT_CH_
  
  class ServerInformationIterator;
  typedef ServerInformationIterator *ServerInformationIterator_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ServerInformationIterator
      >
    ServerInformationIterator_var;
  
  typedef
    TAO_Objref_Out_T<
        ServerInformationIterator
      >
    ServerInformationIterator_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR_CH_)
#define _IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR_CH_
  
  class TAO_IMR_Client_Export ServerInformationIterator
    : public virtual CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<ServerInformationIterator>;
    typedef ServerInformationIterator_ptr _ptr_type;
    typedef ServerInformationIterator_var _var_type;
    
    // The static operations.
    static ServerInformationIterator_ptr _duplicate (ServerInformationIterator_ptr obj);
    
    static void _tao_release (ServerInformationIterator_ptr obj);
    
    static ServerInformationIterator_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ServerInformationIterator_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ServerInformationIterator_ptr _nil (void)
    {
      return static_cast<ServerInformationIterator_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual CORBA::Boolean next_n (
        ::CORBA::ULong how_many,
        ::ImplementationRepository::ServerInformationList_out servers
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void destroy (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_ServerInformationIterator_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    ServerInformationIterator (void);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void ImplementationRepository_ServerInformationIterator_setup_collocation (void);
    
    // Concrete non-local interface only.
    ServerInformationIterator (
        IOP::IOR *ior,
        TAO_ORB_Core *orb_core = 0
      );
    
    // Non-local interface only.
    ServerInformationIterator (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0
      );
    
    virtual ~ServerInformationIterator (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ServerInformationIterator (const ServerInformationIterator &);
    
    void operator= (const ServerInformationIterator &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_ServerInformationIterator;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_IMPLEMENTATIONREPOSITORY_ADMINISTRATION__VAR_OUT_CH_)
#define _IMPLEMENTATIONREPOSITORY_ADMINISTRATION__VAR_OUT_CH_
  
  class Administration;
  typedef Administration *Administration_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Administration
      >
    Administration_var;
  
  typedef
    TAO_Objref_Out_T<
        Administration
      >
    Administration_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_IMPLEMENTATIONREPOSITORY_ADMINISTRATION_CH_)
#define _IMPLEMENTATIONREPOSITORY_ADMINISTRATION_CH_
  
  class TAO_IMR_Client_Export Administration
    : public virtual CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<Administration>;
    typedef Administration_ptr _ptr_type;
    typedef Administration_var _var_type;
    
    // The static operations.
    static Administration_ptr _duplicate (Administration_ptr obj);
    
    static void _tao_release (Administration_ptr obj);
    
    static Administration_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Administration_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Administration_ptr _nil (void)
    {
      return static_cast<Administration_ptr> (0);
    }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void activate_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound,
        ::ImplementationRepository::CannotActivate
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void register_server (
        const char * server,
        const ::ImplementationRepository::StartupOptions & options
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::AlreadyRegistered,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void reregister_server (
        const char * server,
        const ::ImplementationRepository::StartupOptions & options
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::AlreadyRegistered,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void remove_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void shutdown_server (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void server_is_running (
        const char * server,
        const char * partial_ior,
        ::ImplementationRepository::ServerObject_ptr server_object
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void server_is_shutting_down (
        const char * server
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void find (
        const char * server,
        ::ImplementationRepository::ServerInformation_out info
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void list (
        ::CORBA::ULong how_many,
        ::ImplementationRepository::ServerInformationList_out server_list,
        ::ImplementationRepository::ServerInformationIterator_out server_iterator
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_Administration_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    Administration (void);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void ImplementationRepository_Administration_setup_collocation (void);
    
    // Concrete non-local interface only.
    Administration (
        IOP::IOR *ior,
        TAO_ORB_Core *orb_core = 0
      );
    
    // Non-local interface only.
    Administration (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0
      );
    
    virtual ~Administration (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Administration (const Administration &);
    
    void operator= (const Administration &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_IMR_Client_Export ::CORBA::TypeCode_ptr const _tc_Administration;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module ImplementationRepository

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:139

extern TAO_IMR_Client_Export
TAO::Collocation_Proxy_Broker *
(*ImplementationRepository__TAO_ServerInformationIterator_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

extern TAO_IMR_Client_Export
TAO::Collocation_Proxy_Broker *
(*ImplementationRepository__TAO_Administration_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR__TRAITS_CH_)
#define _IMPLEMENTATIONREPOSITORY_SERVERINFORMATIONITERATOR__TRAITS_CH_
  
  template<>
  struct TAO_IMR_Client_Export Objref_Traits< ::ImplementationRepository::ServerInformationIterator>
  {
    static ::ImplementationRepository::ServerInformationIterator_ptr duplicate (
        ::ImplementationRepository::ServerInformationIterator_ptr
      );
    static void release (
        ::ImplementationRepository::ServerInformationIterator_ptr
      );
    static ::ImplementationRepository::ServerInformationIterator_ptr nil (void);
    static CORBA::Boolean marshal (
        ::ImplementationRepository::ServerInformationIterator_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_IMPLEMENTATIONREPOSITORY_ADMINISTRATION__TRAITS_CH_)
#define _IMPLEMENTATIONREPOSITORY_ADMINISTRATION__TRAITS_CH_
  
  template<>
  struct TAO_IMR_Client_Export Objref_Traits< ::ImplementationRepository::Administration>
  {
    static ::ImplementationRepository::Administration_ptr duplicate (
        ::ImplementationRepository::Administration_ptr
      );
    static void release (
        ::ImplementationRepository::Administration_ptr
      );
    static ::ImplementationRepository::Administration_ptr nil (void);
    static CORBA::Boolean marshal (
        ::ImplementationRepository::Administration_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, const ImplementationRepository::AlreadyRegistered &); // copying version
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::AlreadyRegistered*); // noncopying version
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::AlreadyRegistered *&); // deprecated
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::AlreadyRegistered *&);

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, const ImplementationRepository::CannotActivate &); // copying version
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::CannotActivate*); // noncopying version
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::CannotActivate *&); // deprecated
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::CannotActivate *&);

// TAO_IDL - Generated from
// be\be_visitor_exception/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, const ImplementationRepository::NotFound &); // copying version
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::NotFound*); // noncopying version
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::NotFound *&); // deprecated
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::NotFound *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, const ImplementationRepository::EnvironmentVariable &); // copying version
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::EnvironmentVariable*); // noncopying version
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::EnvironmentVariable *&); // deprecated
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::EnvironmentVariable *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, const ImplementationRepository::EnvironmentList &); // copying version
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::EnvironmentList*); // noncopying version
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::EnvironmentList *&); // deprecated
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::EnvironmentList *&);

// TAO_IDL - Generated from
// be\be_visitor_enum/any_op_ch.cpp:51

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::ActivationMode);
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::ActivationMode &);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, const ImplementationRepository::StartupOptions &); // copying version
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::StartupOptions*); // noncopying version
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::StartupOptions *&); // deprecated
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::StartupOptions *&);

// TAO_IDL - Generated from
// be\be_visitor_structure/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, const ImplementationRepository::ServerInformation &); // copying version
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::ServerInformation*); // noncopying version
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::ServerInformation *&); // deprecated
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::ServerInformation *&);

// TAO_IDL - Generated from
// be\be_visitor_sequence/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, const ImplementationRepository::ServerInformationList &); // copying version
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::ServerInformationList*); // noncopying version
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::ServerInformationList *&); // deprecated
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::ServerInformationList *&);

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::ServerInformationIterator_ptr); // copying
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::ServerInformationIterator_ptr *); // non-copying
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::ServerInformationIterator_ptr &);

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::Administration_ptr); // copying
TAO_IMR_Client_Export void operator<<= (CORBA::Any &, ImplementationRepository::Administration_ptr *); // non-copying
TAO_IMR_Client_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::Administration_ptr &);

// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::AlreadyRegistered &);
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::AlreadyRegistered &);

// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::CannotActivate &);
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::CannotActivate &);

// TAO_IDL - Generated from
// be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::NotFound &);
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::NotFound &);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::EnvironmentVariable &);
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::EnvironmentVariable &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_ImplementationRepository_EnvironmentList_H_
#define _TAO_CDR_OP_ImplementationRepository_EnvironmentList_H_

TAO_IMR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::EnvironmentList &
  );
TAO_IMR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::EnvironmentList &
  );

#endif /* _TAO_CDR_OP_ImplementationRepository_EnvironmentList_H_ */

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_ch.cpp:50

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, ImplementationRepository::ActivationMode);
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::ActivationMode &);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::StartupOptions &);
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::StartupOptions &);

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_ch.cpp:54

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::ServerInformation &);
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::ServerInformation &);

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_ImplementationRepository_ServerInformationList_H_
#define _TAO_CDR_OP_ImplementationRepository_ServerInformationList_H_

TAO_IMR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::ServerInformationList &
  );
TAO_IMR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::ServerInformationList &
  );

#endif /* _TAO_CDR_OP_ImplementationRepository_ServerInformationList_H_ */

// TAO_IDL - Generated from
// be\be_visitor_interface/cdr_op_ch.cpp:55

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::ServerInformationIterator_ptr );
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::ServerInformationIterator_ptr &);

// TAO_IDL - Generated from
// be\be_visitor_interface/cdr_op_ch.cpp:55

TAO_IMR_Client_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::Administration_ptr );
TAO_IMR_Client_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::Administration_ptr &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

#if defined (__ACE_INLINE__)
#include "ImplRepoC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


