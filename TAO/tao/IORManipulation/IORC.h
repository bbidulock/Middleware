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
// be/be_codegen.cpp:150

#ifndef _TAO_IDL_ORIG_IORC_H_
#define _TAO_IDL_ORIG_IORC_H_

#include /**/ "ace/pre.h"

#include "tao/ORB.h"

#ifndef TAO_IORMANIP_SAFE_INCLUDE
#error "You should not include IORC.h directly, use IORManip_Loader.h"
#endif /* !TAO_IORMANIP_SAFE_INCLUDE */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ior_manip_export.h"
#include "tao/CDR.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IORManip_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_IORManip_Export
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

namespace TAO_IOP
{

  // TAO_IDL - Generated from
  // be/be_visitor_exception/exception_ch.cpp:51

#if !defined (_TAO_IOP_EMPTYPROFILELIST_CH_)
#define _TAO_IOP_EMPTYPROFILELIST_CH_

  class TAO_IORManip_Export EmptyProfileList : public CORBA::UserException
  {
  public:

    EmptyProfileList (void);
    EmptyProfileList (const EmptyProfileList &);
    ~EmptyProfileList (void);

    EmptyProfileList &operator= (const EmptyProfileList &);

    static void _tao_any_destructor (void *);

    static EmptyProfileList *_downcast (CORBA::Exception *);
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
    // be/be_visitor_exception/exception_ch.cpp:125

    virtual CORBA::TypeCode_ptr _type (void) const;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_EmptyProfileList;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_exception/exception_ch.cpp:51

#if !defined (_TAO_IOP_NOTFOUND_CH_)
#define _TAO_IOP_NOTFOUND_CH_

  class TAO_IORManip_Export NotFound : public CORBA::UserException
  {
  public:

    NotFound (void);
    NotFound (const NotFound &);
    ~NotFound (void);

    NotFound &operator= (const NotFound &);

    static void _tao_any_destructor (void *);

    static NotFound *_downcast (CORBA::Exception *);
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
    // be/be_visitor_exception/exception_ch.cpp:125

    virtual CORBA::TypeCode_ptr _type (void) const;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_NotFound;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_exception/exception_ch.cpp:51

#if !defined (_TAO_IOP_DUPLICATE_CH_)
#define _TAO_IOP_DUPLICATE_CH_

  class TAO_IORManip_Export Duplicate : public CORBA::UserException
  {
  public:

    Duplicate (void);
    Duplicate (const Duplicate &);
    ~Duplicate (void);

    Duplicate &operator= (const Duplicate &);

    static void _tao_any_destructor (void *);

    static Duplicate *_downcast (CORBA::Exception *);
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
    // be/be_visitor_exception/exception_ch.cpp:125

    virtual CORBA::TypeCode_ptr _type (void) const;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Duplicate;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_exception/exception_ch.cpp:51

#if !defined (_TAO_IOP_INVALID_IOR_CH_)
#define _TAO_IOP_INVALID_IOR_CH_

  class TAO_IORManip_Export Invalid_IOR : public CORBA::UserException
  {
  public:

    Invalid_IOR (void);
    Invalid_IOR (const Invalid_IOR &);
    ~Invalid_IOR (void);

    Invalid_IOR &operator= (const Invalid_IOR &);

    static void _tao_any_destructor (void *);

    static Invalid_IOR *_downcast (CORBA::Exception *);
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
    // be/be_visitor_exception/exception_ch.cpp:125

    virtual CORBA::TypeCode_ptr _type (void) const;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Invalid_IOR;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_exception/exception_ch.cpp:51

#if !defined (_TAO_IOP_MULTIPROFILELIST_CH_)
#define _TAO_IOP_MULTIPROFILELIST_CH_

  class TAO_IORManip_Export MultiProfileList : public CORBA::UserException
  {
  public:

    MultiProfileList (void);
    MultiProfileList (const MultiProfileList &);
    ~MultiProfileList (void);

    MultiProfileList &operator= (const MultiProfileList &);

    static void _tao_any_destructor (void *);

    static MultiProfileList *_downcast (CORBA::Exception *);
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
    // be/be_visitor_exception/exception_ch.cpp:125

    virtual CORBA::TypeCode_ptr _type (void) const;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_MultiProfileList;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_interface.cpp:610

#if !defined (_TAO_IOP_TAO_IOR_PROPERTY__VAR_OUT_CH_)
#define _TAO_IOP_TAO_IOR_PROPERTY__VAR_OUT_CH_

  class TAO_IOR_Property;
  typedef TAO_IOR_Property *TAO_IOR_Property_ptr;

  typedef
    TAO_Objref_Var_T<
        TAO_IOR_Property
      >
    TAO_IOR_Property_var;

  typedef
    TAO_Objref_Out_T<
        TAO_IOR_Property
      >
    TAO_IOR_Property_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_TAO_IOP_TAO_IOR_PROPERTY_CH_)
#define _TAO_IOP_TAO_IOR_PROPERTY_CH_

  class TAO_IORManip_Export TAO_IOR_Property
    : public virtual CORBA::Object
  {
  public:
    typedef TAO_IOR_Property_ptr _ptr_type;
    typedef TAO_IOR_Property_var _var_type;

    // The static operations.
    static TAO_IOR_Property_ptr _duplicate (TAO_IOR_Property_ptr obj);

    static TAO_IOR_Property_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static TAO_IOR_Property_ptr _nil (void)
    {
      return (TAO_IOR_Property_ptr)0;
    }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Boolean set_property (
        CORBA::Object_ptr & ior
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::Invalid_IOR
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Boolean set_primary (
        CORBA::Object_ptr & ior1,
        CORBA::Object_ptr ior2
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::Duplicate
        , TAO_IOP::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Object_ptr get_primary (
        CORBA::Object_ptr ior
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Boolean is_primary_set (
        CORBA::Object_ptr ior
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Boolean remove_primary_tag (
        CORBA::Object_ptr & iogr
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:192

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    // Abstract or local interface only.
    TAO_IOR_Property (void);

    virtual ~TAO_IOR_Property (void);

  private:
    // Private and unimplemented for concrete interfaces.
    TAO_IOR_Property (const TAO_IOR_Property &);

    void operator= (const TAO_IOR_Property &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TAO_IOR_Property;

  // TAO_IDL - Generated from
  // be/be_interface.cpp:610

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION__VAR_OUT_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION__VAR_OUT_CH_

  class TAO_IOR_Manipulation;
  typedef TAO_IOR_Manipulation *TAO_IOR_Manipulation_ptr;

  typedef
    TAO_Objref_Var_T<
        TAO_IOR_Manipulation
      >
    TAO_IOR_Manipulation_var;

  typedef
    TAO_Objref_Out_T<
        TAO_IOR_Manipulation
      >
    TAO_IOR_Manipulation_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_CH_

  class TAO_IORManip_Export TAO_IOR_Manipulation
    : public virtual CORBA::Object
  {
  public:
    typedef TAO_IOR_Manipulation_ptr _ptr_type;
    typedef TAO_IOR_Manipulation_var _var_type;

    // The static operations.
    static TAO_IOR_Manipulation_ptr _duplicate (TAO_IOR_Manipulation_ptr obj);

    static TAO_IOR_Manipulation_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static TAO_IOR_Manipulation_ptr _nil (void)
    {
      return (TAO_IOR_Manipulation_ptr)0;
    }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CH_

    class IORList;

    typedef
      TAO_MngSeq_Var_T<
          IORList,
          TAO_Pseudo_Object_Manager<
              CORBA::Object
            >
        >
      IORList_var;

    typedef
      TAO_MngSeq_Out_T<
          IORList,
          IORList_var,
          TAO_Pseudo_Object_Manager<
              CORBA::Object
            >
        >
      IORList_out;

    class TAO_IORManip_Export IORList
      : public
          TAO_Unbounded_Pseudo_Sequence<
              CORBA::Object
            >
    {
    public:
      IORList (void);
      IORList (CORBA::ULong max);
      IORList (
          CORBA::ULong max,
          CORBA::ULong length,
          CORBA::Object_ptr* buffer,
          CORBA::Boolean release = 0
        );
      IORList (const IORList &);
      ~IORList (void);

      static void _tao_any_destructor (void *);

      typedef IORList_var _var_type;
    };

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be/be_visitor_typecode/typecode_decl.cpp:44

    static ::CORBA::TypeCode_ptr _tc_IORList;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Object_ptr merge_iors (
        const TAO_IOP::TAO_IOR_Manipulation::IORList & iors
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::EmptyProfileList
        , TAO_IOP::Duplicate
        , TAO_IOP::Invalid_IOR
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Object_ptr add_profiles (
        CORBA::Object_ptr ior1,
        CORBA::Object_ptr ior2
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::EmptyProfileList
        , TAO_IOP::Duplicate
        , TAO_IOP::Invalid_IOR
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Object_ptr remove_profiles (
        CORBA::Object_ptr ior1,
        CORBA::Object_ptr ior2
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::Invalid_IOR
        , TAO_IOP::EmptyProfileList
        , TAO_IOP::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Boolean set_property (
        TAO_IOP::TAO_IOR_Property_ptr prop,
        CORBA::Object_ptr ior
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::Invalid_IOR
        , TAO_IOP::Duplicate
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Boolean set_primary (
        TAO_IOP::TAO_IOR_Property_ptr prop,
        CORBA::Object_ptr ior1,
        CORBA::Object_ptr ior2
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::Invalid_IOR
        , TAO_IOP::Duplicate
        , TAO_IOP::MultiProfileList
        , TAO_IOP::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Boolean remove_primary_tag (
        TAO_IOP::TAO_IOR_Property_ptr prop,
        CORBA::Object_ptr ior
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Object_ptr get_primary (
        TAO_IOP::TAO_IOR_Property_ptr prop,
        CORBA::Object_ptr ior
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Boolean is_primary_set (
        TAO_IOP::TAO_IOR_Property_ptr prop,
        CORBA::Object_ptr ior
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::ULong is_in_ior (
        CORBA::Object_ptr ior1,
        CORBA::Object_ptr ior2
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::NotFound
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::ULong get_profile_count (
        CORBA::Object_ptr ior
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , TAO_IOP::EmptyProfileList
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:192

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    // Abstract or local interface only.
    TAO_IOR_Manipulation (void);

    virtual ~TAO_IOR_Manipulation (void);

  private:
    // Private and unimplemented for concrete interfaces.
    TAO_IOR_Manipulation (const TAO_IOR_Manipulation &);

    void operator= (const TAO_IOR_Manipulation &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TAO_IOR_Manipulation;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:66

} // module TAO_IOP

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{

#if !defined (_TAO_IOP_TAO_IOR_PROPERTY__TRAITS_CH_)
#define _TAO_IOP_TAO_IOR_PROPERTY__TRAITS_CH_

  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_IORManip_Export Objref_Traits<TAO_IOP::TAO_IOR_Property>
  {
    static TAO_IOP::TAO_IOR_Property_ptr tao_duplicate (
        TAO_IOP::TAO_IOR_Property_ptr
      );
    static void tao_release (
        TAO_IOP::TAO_IOR_Property_ptr
      );
    static TAO_IOP::TAO_IOR_Property_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        TAO_IOP::TAO_IOR_Property_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION__TRAITS_CH_)
#define _TAO_IOP_TAO_IOR_MANIPULATION__TRAITS_CH_

  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_IORManip_Export Objref_Traits<TAO_IOP::TAO_IOR_Manipulation>
  {
    static TAO_IOP::TAO_IOR_Manipulation_ptr tao_duplicate (
        TAO_IOP::TAO_IOR_Manipulation_ptr
      );
    static void tao_release (
        TAO_IOP::TAO_IOR_Manipulation_ptr
      );
    static TAO_IOP::TAO_IOR_Manipulation_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        TAO_IOP::TAO_IOR_Manipulation_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_IORManip_Export void operator<<= (CORBA::Any &, const TAO_IOP::EmptyProfileList &); // copying version
TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::EmptyProfileList*); // noncopying version
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::EmptyProfileList *&); // deprecated
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::EmptyProfileList *&);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_IORManip_Export void operator<<= (CORBA::Any &, const TAO_IOP::NotFound &); // copying version
TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::NotFound*); // noncopying version
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::NotFound *&); // deprecated
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::NotFound *&);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_IORManip_Export void operator<<= (CORBA::Any &, const TAO_IOP::Duplicate &); // copying version
TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::Duplicate*); // noncopying version
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::Duplicate *&); // deprecated
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::Duplicate *&);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_IORManip_Export void operator<<= (CORBA::Any &, const TAO_IOP::Invalid_IOR &); // copying version
TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::Invalid_IOR*); // noncopying version
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::Invalid_IOR *&); // deprecated
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::Invalid_IOR *&);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_IORManip_Export void operator<<= (CORBA::Any &, const TAO_IOP::MultiProfileList &); // copying version
TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::MultiProfileList*); // noncopying version
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::MultiProfileList *&); // deprecated
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::MultiProfileList *&);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Property_ptr); // copying
TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Property_ptr *); // non-copying
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Property_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation_ptr); // copying
TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation_ptr *); // non-copying
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_IORManip_Export void operator<<= (CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::IORList &); // copying version
TAO_IORManip_Export void operator<<= (CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::IORList*); // noncopying version
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, TAO_IOP::TAO_IOR_Manipulation::IORList *&); // deprecated
TAO_IORManip_Export CORBA::Boolean operator>>= (const CORBA::Any &, const TAO_IOP::TAO_IOR_Manipulation::IORList *&);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ch.cpp:52

TAO_IORManip_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::EmptyProfileList &);
TAO_IORManip_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::EmptyProfileList &);

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ch.cpp:52

TAO_IORManip_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::NotFound &);
TAO_IORManip_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::NotFound &);

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ch.cpp:52

TAO_IORManip_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::Duplicate &);
TAO_IORManip_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::Duplicate &);

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ch.cpp:52

TAO_IORManip_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::Invalid_IOR &);
TAO_IORManip_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::Invalid_IOR &);

// TAO_IDL - Generated from
// be/be_visitor_exception/cdr_op_ch.cpp:52

TAO_IORManip_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const TAO_IOP::MultiProfileList &);
TAO_IORManip_Export CORBA::Boolean operator>> (TAO_InputCDR &, TAO_IOP::MultiProfileList &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:911

#if defined (__ACE_INLINE__)
#include "IORC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */
