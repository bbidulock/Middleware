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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;
  
  template<typename T> class Narrow_Utils;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

namespace ImplementationRepository
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:601

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
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:53

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR_CH_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR_CH_
  
  class TAO_PortableServer_Export Locator
    : public virtual ImplementationRepository::Administration
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
    
    static Locator_ptr _nil (void)
      {
        return (Locator_ptr)0;
      }
    
    static void _tao_any_destructor (void *);
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
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
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
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
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
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
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
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
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
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
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
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
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:185
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_Locator_Proxy_Broker_;
  
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
  
  private:
    Locator (const Locator &);
    void operator= (const Locator &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44
  
  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Locator;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:66

} // module ImplementationRepository

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:121

extern TAO_PortableServer_Export
TAO::Collocation_Proxy_Broker *
(*ImplementationRepository__TAO_Locator_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR__TRAITS_CH_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_PortableServer_Export Objref_Traits<ImplementationRepository::Locator>
  {
    static ImplementationRepository::Locator_ptr tao_duplicate (
        ImplementationRepository::Locator_ptr
      );
    static void tao_release (
        ImplementationRepository::Locator_ptr
      );
    static ImplementationRepository::Locator_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        ImplementationRepository::Locator_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

TAO_PortableServer_Export void operator<<= (CORBA::Any &, ImplementationRepository::Locator_ptr); // copying
TAO_PortableServer_Export void operator<<= (CORBA::Any &, ImplementationRepository::Locator_ptr *); // non-copying
TAO_PortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, ImplementationRepository::Locator_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ch.cpp:55

TAO_PortableServer_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const ImplementationRepository::Locator_ptr );
TAO_PortableServer_Export CORBA::Boolean operator>> (TAO_InputCDR &, ImplementationRepository::Locator_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:926

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

