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

#ifndef _TAO_IDL_ORIG_RTPORTABLESERVERC_H_
#define _TAO_IDL_ORIG_RTPORTABLESERVERC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "rtportableserver_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#include "tao/PortableServer/PortableServerC.h"
#include "tao/RTCORBA/RTCORBA.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_RTPortableServer_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_RTPortableServer_Export
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

namespace RTPortableServer
{

  // TAO_IDL - Generated from
  // be\be_interface.cpp:601

#if !defined (_RTPORTABLESERVER_POA__VAR_OUT_CH_)
#define _RTPORTABLESERVER_POA__VAR_OUT_CH_

  class POA;
  typedef POA *POA_ptr;

  typedef
    TAO_Objref_Var_T<
        POA
      >
    POA_var;

  typedef
    TAO_Objref_Out_T<
        POA
      >
    POA_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_RTPORTABLESERVER_POA_CH_)
#define _RTPORTABLESERVER_POA_CH_

  class TAO_RTPortableServer_Export POA
    : public virtual ::PortableServer::POA
  {
  public:
    typedef POA_ptr _ptr_type;
    typedef POA_var _var_type;

    // The static operations.
    static POA_ptr _duplicate (POA_ptr obj);

    static POA_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static POA_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static POA_ptr _nil (void)
    {
      return (POA_ptr)0;
    }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Object_ptr create_reference_with_priority (
        const char * intf,
        ::RTCORBA::Priority priority
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableServer::POA::WrongPolicy
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual CORBA::Object_ptr create_reference_with_id_and_priority (
        const ::PortableServer::ObjectId & oid,
        const char * intf,
        ::RTCORBA::Priority priority
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableServer::POA::WrongPolicy
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual ::PortableServer::ObjectId * activate_object_with_priority (
        ::PortableServer::Servant p_servant,
        ::RTCORBA::Priority priority
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableServer::POA::ServantAlreadyActive,
        ::PortableServer::POA::WrongPolicy
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void activate_object_with_id_and_priority (
        const ::PortableServer::ObjectId & oid,
        ::PortableServer::Servant p_servant,
        ::RTCORBA::Priority priority
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableServer::POA::ServantAlreadyActive,
        ::PortableServer::POA::ObjectAlreadyActive,
        ::PortableServer::POA::WrongPolicy
      )) = 0;

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
    POA (void);

    virtual ~POA (void);

  private:
    // Private and unimplemented for concrete interfaces.
    POA (const POA &);

    void operator= (const POA &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_POA;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module RTPortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:59

// Traits specializations.
namespace TAO
{

#if !defined (_RTPORTABLESERVER_POA__TRAITS_CH_)
#define _RTPORTABLESERVER_POA__TRAITS_CH_

  ACE_TEMPLATE_SPECIALIZATION
  struct TAO_RTPortableServer_Export Objref_Traits< ::RTPortableServer::POA>
  {
    static ::RTPortableServer::POA_ptr duplicate (
        ::RTPortableServer::POA_ptr
      );
    static void release (
        ::RTPortableServer::POA_ptr
      );
    static ::RTPortableServer::POA_ptr nil (void);
    static CORBA::Boolean marshal (
        ::RTPortableServer::POA_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_ch.cpp:52

TAO_RTPortableServer_Export void operator<<= (CORBA::Any &, RTPortableServer::POA_ptr); // copying
TAO_RTPortableServer_Export void operator<<= (CORBA::Any &, RTPortableServer::POA_ptr *); // non-copying
TAO_RTPortableServer_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTPortableServer::POA_ptr &);

// TAO_IDL - Generated from
// be\be_codegen.cpp:964

#if defined (__ACE_INLINE__)
#include "RTPortableServerC.inl"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


