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
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:171

#ifndef _TAO_IDL_IMR_LOCATORC_H_
#define _TAO_IDL_IMR_LOCATORC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "portableserver_export.h"
#include "tao/ORB.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

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
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;

  template<typename T> class Narrow_Utils;
  template<typename T> class AbstractBase_Narrow_Utils;
}

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

namespace ImplementationRepository
{

  // TAO_IDL - Generated from
  // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:611

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR__VAR_OUT_CH_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR__VAR_OUT_CH_

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
  // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR_CH_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR_CH_

  class TAO_PortableServer_Export Locator
    : public virtual ::ImplementationRepository::Administration
  {
  public:
    friend class TAO::Narrow_Utils<Locator>;
    typedef Locator_ptr _ptr_type;
    typedef Locator_var _var_type;

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
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR_SERVERNAMELIST_CH_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR_SERVERNAMELIST_CH_

    class ServerNameList;

    typedef
      TAO_MngSeq_Var_T<
          ServerNameList,
          TAO_SeqElem_String_Manager
        >
      ServerNameList_var;

    typedef
      TAO_MngSeq_Out_T<
          ServerNameList,
          ServerNameList_var,
          TAO_SeqElem_String_Manager
        >
      ServerNameList_out;

    class TAO_PortableServer_Export ServerNameList
      : public
          TAO_Unbounded_String_Sequence
    {
    public:
      ServerNameList (void);
      ServerNameList (CORBA::ULong max);
      ServerNameList (
          CORBA::ULong max,
          CORBA::ULong length,
          char ** buffer,
          CORBA::Boolean release = 0
        );
      ServerNameList (const ServerNameList &);
      ~ServerNameList (void);

      static void _tao_any_destructor (void *);

      typedef ServerNameList_var _var_type;
    };

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

    static ::CORBA::TypeCode_ptr _tc_ServerNameList;

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

    virtual void activate_server_in_activator (
        const char * server,
        const char * activator
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound,
        ::ImplementationRepository::CannotActivate
      ));

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

    virtual void remove_server_in_activator (
        const char * server,
        const char * activator
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

    virtual void shutdown_server_in_activator (
        const char * server,
        const char * activator
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

    virtual void server_is_shutting_down_in_activator (
        const char * server,
        const char * activator
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Long register_activator (
        const char * activator,
        ::ImplementationRepository::Administration_ptr admin,
        const ::ImplementationRepository::Locator::ServerNameList & servers
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

    virtual void unregister_activator (
        const char * activator,
        ::CORBA::Long token
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

    virtual void server_is_running_in_activator (
        const char * server,
        const char * activator,
        const char * addr,
        ::ImplementationRepository::ServerObject_ptr server_object
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

    virtual void find_in_activator (
        const char * server,
        const char * activator,
        ::ImplementationRepository::ServerInformation_out info
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::ImplementationRepository::NotFound
      ));

    // TAO_IDL - Generated from
    // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:208

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_Locator_Proxy_Broker_;

  protected:
    // Concrete interface only.
    Locator (void);

    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void ImplementationRepository_Locator_setup_collocation (void);

    // Concrete non-local interface only.
    Locator (
        IOP::IOR *ior,
        TAO_ORB_Core *orb_core = 0
      );

    // Non-local interface only.
    Locator (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0
      );

    virtual ~Locator (void);

  private:
    // Private and unimplemented for concrete interfaces.
    Locator (const Locator &);

    void operator= (const Locator &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Locator;

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:66

} // module ImplementationRepository

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:120

extern TAO_PortableServer_Export
TAO::Collocation_Proxy_Broker *
(*ImplementationRepository__TAO_Locator_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR__TRAITS_CH_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR__TRAITS_CH_

  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_PortableServer_Export Objref_Traits<ImplementationRepository::Locator>
  {
    static ImplementationRepository::Locator_ptr duplicate (
        ImplementationRepository::Locator_ptr
      );
    static void release (
        ImplementationRepository::Locator_ptr
      );
    static ImplementationRepository::Locator_ptr nil (void);
    static CORBA::Boolean marshal (
        ImplementationRepository::Locator_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, ImplementationRepository::Locator_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, ImplementationRepository::Locator_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::Locator_ptr &);

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, const ImplementationRepository::Locator::ServerNameList &); // copying version
TAO_PortableServer_Export void operator<<= (CORBA::Any &, ImplementationRepository::Locator::ServerNameList*); // noncopying version
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::Locator::ServerNameList *&); // deprecated
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, const ImplementationRepository::Locator::ServerNameList *&);

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ch.cpp:55

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::Locator_ptr );
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::Locator_ptr &);

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_ImplementationRepository_Locator_ServerNameList_H_
#define _TAO_CDR_OP_ImplementationRepository_Locator_ServerNameList_H_

TAO_PortableServer_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::Locator::ServerNameList &
  );
TAO_PortableServer_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::Locator::ServerNameList &
  );

#endif /* _TAO_CDR_OP_ImplementationRepository_Locator_ServerNameList_H_ */

// TAO_IDL - Generated from
// E:\doc_cvs\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:976

#if defined (__ACE_INLINE__)
#include "ImR_LocatorC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */
