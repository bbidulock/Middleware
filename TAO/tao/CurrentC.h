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
// be\be_codegen.cpp:171

#ifndef _TAO_IDL_ORIG_CURRENTC_H_
#define _TAO_IDL_ORIG_CURRENTC_H_

#include /**/ "ace/pre.h"

#include "tao/Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/Environment.h"
#include "tao/Objref_VarOut_T.h"

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
// be\be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;

  template<typename T> class Narrow_Utils;
  template<typename T> class AbstractBase_Narrow_Utils;
}

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace CORBA
{

  // TAO_IDL - Generated from
  // be\be_interface.cpp:611

#if !defined (_CORBA_CURRENT__VAR_OUT_CH_)
#define _CORBA_CURRENT__VAR_OUT_CH_

  class Current;
  typedef Current *Current_ptr;

  typedef
    TAO_Objref_Var_T<
        Current
      >
    Current_var;

  typedef
    TAO_Objref_Out_T<
        Current
      >
    Current_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_CORBA_CURRENT_CH_)
#define _CORBA_CURRENT_CH_

  class TAO_Export Current
    : public virtual CORBA::Object
  {
  public:
    typedef Current_ptr _ptr_type;
    typedef Current_var _var_type;

    // The static operations.
    static Current_ptr _duplicate (Current_ptr obj);

    static Current_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static Current_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static Current_ptr _nil (void)
    {
      return (Current_ptr)0;
    }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:208

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    // Abstract or local interface only.
    Current (void);

    virtual ~Current (void);

  private:
    // Private and unimplemented for concrete interfaces.
    Current (const Current &);

    void operator= (const Current &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr const _tc_Current;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_CORBA_CURRENT__TRAITS_CH_)
#define _CORBA_CURRENT__TRAITS_CH_

  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_Export Objref_Traits<CORBA::Current>
  {
    static CORBA::Current_ptr duplicate (
        CORBA::Current_ptr
      );
    static void release (
        CORBA::Current_ptr
      );
    static CORBA::Current_ptr nil (void);
    static CORBA::Boolean marshal (
        CORBA::Current_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, CORBA::Current_ptr); // copying
TAO_Export void operator<<= (CORBA::Any &, CORBA::Current_ptr *); // non-copying
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, CORBA::Current_ptr &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:978

#if defined (__ACE_INLINE__)
#include "CurrentC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */
