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
// be/be_codegen.cpp:186

#ifndef _TAO_IDL_ORIG_DOMAINC_H_
#define _TAO_IDL_ORIG_DOMAINC_H_

#include /**/ "ace/pre.h"

#include "tao/ORB.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/CDR.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

#include "PolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
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
// be/be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;
  
  template<typename T> class Narrow_Utils;
  template<typename T> class AbstractBase_Narrow_Utils;
}

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:48

namespace CORBA
{
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:612

#if !defined (_CORBA_DOMAINMANAGER__VAR_OUT_CH_)
#define _CORBA_DOMAINMANAGER__VAR_OUT_CH_
  
  class DomainManager;
  typedef DomainManager *DomainManager_ptr;
  
  typedef
    TAO_Objref_Var_T<
        DomainManager
      >
    DomainManager_var;
  
  typedef
    TAO_Objref_Out_T<
        DomainManager
      >
    DomainManager_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_DOMAINMANAGER_CH_)
#define _CORBA_DOMAINMANAGER_CH_
  
  class TAO_Export DomainManager
    : public virtual CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<DomainManager>;
    typedef DomainManager_ptr _ptr_type;
    typedef DomainManager_var _var_type;
    
    // The static operations.
    static DomainManager_ptr _duplicate (DomainManager_ptr obj);
    
    static DomainManager_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DomainManager_ptr _nil (void)
    {
      return (DomainManager_ptr)0;
    }
    
    
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr get_domain_policy (
        CORBA::PolicyType policy_type
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:185
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_DomainManager_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    DomainManager (int collocated = 0);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void CORBA_DomainManager_setup_collocation (int collocated);
    
    // Concrete non-local interface only.
    DomainManager (
        IOP::IOR *ior,
        TAO_ORB_Core *orb_core = 0
      );
    
    // Non-local interface only.
    DomainManager (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0
      );
    
    virtual ~DomainManager (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DomainManager (const DomainManager &);
    
    void operator= (const DomainManager &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52
  
  const CORBA::PolicyType SecConstruction = 11U;
  
  // TAO_IDL - Generated from
  // be/be_interface.cpp:612

#if !defined (_CORBA_CONSTRUCTIONPOLICY__VAR_OUT_CH_)
#define _CORBA_CONSTRUCTIONPOLICY__VAR_OUT_CH_
  
  class ConstructionPolicy;
  typedef ConstructionPolicy *ConstructionPolicy_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ConstructionPolicy
      >
    ConstructionPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        ConstructionPolicy
      >
    ConstructionPolicy_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_CONSTRUCTIONPOLICY_CH_)
#define _CORBA_CONSTRUCTIONPOLICY_CH_
  
  class TAO_Export ConstructionPolicy
    : public virtual CORBA::Policy
  {
  public:
    friend class TAO::Narrow_Utils<ConstructionPolicy>;
    typedef ConstructionPolicy_ptr _ptr_type;
    typedef ConstructionPolicy_var _var_type;
    
    // The static operations.
    static ConstructionPolicy_ptr _duplicate (ConstructionPolicy_ptr obj);
    
    static ConstructionPolicy_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ConstructionPolicy_ptr _nil (void)
    {
      return (ConstructionPolicy_ptr)0;
    }
    
    
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void make_domain_manager (
        CORBA::InterfaceDef_ptr object_type,
        CORBA::Boolean constr_policy
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
    
    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:185
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_ConstructionPolicy_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    ConstructionPolicy (int collocated = 0);
    
    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void CORBA_ConstructionPolicy_setup_collocation (int collocated);
    
    // Concrete non-local interface only.
    ConstructionPolicy (
        IOP::IOR *ior,
        TAO_ORB_Core *orb_core = 0
      );
    
    // Non-local interface only.
    ConstructionPolicy (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0
      );
    
    virtual ~ConstructionPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ConstructionPolicy (const ConstructionPolicy &);
    
    void operator= (const ConstructionPolicy &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_CORBA_DOMAINMANAGERLIST_CH_)
#define _CORBA_DOMAINMANAGERLIST_CH_
  
  class DomainManagerList;
  
  typedef
    TAO_MngSeq_Var_T<
        DomainManagerList,
        TAO_Object_Manager<
            DomainManager,
            DomainManager_var
          >
      >
    DomainManagerList_var;
  
  typedef
    TAO_MngSeq_Out_T<
        DomainManagerList,
        DomainManagerList_var,
        TAO_Object_Manager<
            DomainManager,
            DomainManager_var
          >
      >
    DomainManagerList_out;
  
  class TAO_Export DomainManagerList
    : public
        TAO_Unbounded_Object_Sequence<
            DomainManager,
            DomainManager_var
          >
  {
  public:
    DomainManagerList (void);
    DomainManagerList (CORBA::ULong max);
    DomainManagerList (
        CORBA::ULong max,
        CORBA::ULong length,
        DomainManager_ptr* buffer, 
        CORBA::Boolean release = 0
      );
    DomainManagerList (const DomainManagerList &);
    ~DomainManagerList (void);
    
    typedef DomainManagerList_var _var_type;
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:66

} // module CORBA

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:120

extern TAO_Export
TAO::Collocation_Proxy_Broker *
(*CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

extern TAO_Export
TAO::Collocation_Proxy_Broker *
(*CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:50

// Traits specializations.
namespace TAO
{

#if !defined (_CORBA_DOMAINMANAGER__TRAITS_CH_)
#define _CORBA_DOMAINMANAGER__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_Export Objref_Traits<CORBA::DomainManager>
  {
    static CORBA::DomainManager_ptr tao_duplicate (
        CORBA::DomainManager_ptr
      );
    static void tao_release (
        CORBA::DomainManager_ptr
      );
    static CORBA::DomainManager_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        CORBA::DomainManager_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_CORBA_CONSTRUCTIONPOLICY__TRAITS_CH_)
#define _CORBA_CONSTRUCTIONPOLICY__TRAITS_CH_
  
  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_Export Objref_Traits<CORBA::ConstructionPolicy>
  {
    static CORBA::ConstructionPolicy_ptr tao_duplicate (
        CORBA::ConstructionPolicy_ptr
      );
    static void tao_release (
        CORBA::ConstructionPolicy_ptr
      );
    static CORBA::ConstructionPolicy_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        CORBA::ConstructionPolicy_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:55

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::DomainManager_ptr );
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::DomainManager_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:55

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const CORBA::ConstructionPolicy_ptr );
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, CORBA::ConstructionPolicy_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_CORBA_DomainManagerList_H_
#define _TAO_CDR_OP_CORBA_DomainManagerList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::DomainManagerList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::DomainManagerList &
  );

#endif /* _TAO_CDR_OP_CORBA_DomainManagerList_H_ */

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:1050

#if defined (__ACE_INLINE__)
#include "DomainC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */

