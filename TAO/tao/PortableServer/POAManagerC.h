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
// be\be_codegen.cpp:154

#ifndef _TAO_IDL_POAMANAGERC_H_
#define _TAO_IDL_POAMANAGERC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "portableserver_export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:49

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace PortableServer
{

  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_PORTABLESERVER_POAMANAGER__VAR_OUT_CH_)
#define _PORTABLESERVER_POAMANAGER__VAR_OUT_CH_

  class POAManager;
  typedef POAManager *POAManager_ptr;

  typedef
    TAO_Objref_Var_T<
        POAManager
      >
    POAManager_var;

  typedef
    TAO_Objref_Out_T<
        POAManager
      >
    POAManager_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_PORTABLESERVER_POAMANAGER_CH_)
#define _PORTABLESERVER_POAMANAGER_CH_

  class TAO_PortableServer_Export POAManager
    : public virtual CORBA::Object
  {
  public:
    typedef POAManager_ptr _ptr_type;
    typedef POAManager_var _var_type;

    // The static operations.
    static POAManager_ptr _duplicate (POAManager_ptr obj);

    static void _tao_release (POAManager_ptr obj);

    static POAManager_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static POAManager_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static POAManager_ptr _nil (void)
    {
      return static_cast<POAManager_ptr> (0);
    }



    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_PORTABLESERVER_POAMANAGER_ADAPTERINACTIVE_CH_)
#define _PORTABLESERVER_POAMANAGER_ADAPTERINACTIVE_CH_

    class TAO_PortableServer_Export AdapterInactive : public CORBA::UserException
    {
    public:

      AdapterInactive (void);
      AdapterInactive (const AdapterInactive &);
      ~AdapterInactive (void);

      AdapterInactive &operator= (const AdapterInactive &);

      static void _tao_any_destructor (void *);

      static AdapterInactive *_downcast (CORBA::Exception *);
      static const AdapterInactive *_downcast (CORBA::Exception const *);

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
      // be\be_visitor_exception/exception_ch.cpp:129

      virtual CORBA::TypeCode_ptr _tao_type (void) const;
    };

    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:49

    static ::CORBA::TypeCode_ptr const _tc_AdapterInactive;

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be\be_visitor_enum/enum_ch.cpp:57

    enum State
    {
      HOLDING,
      ACTIVE,
      DISCARDING,
      INACTIVE
    };

    typedef State &State_out;

    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:49

    static ::CORBA::TypeCode_ptr const _tc_State;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void activate (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableServer::POAManager::AdapterInactive
      )) = 0;

#if (TAO_HAS_MINIMUM_POA == 0)

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void hold_requests (
        ::CORBA::Boolean wait_for_completion
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableServer::POAManager::AdapterInactive
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void discard_requests (
        ::CORBA::Boolean wait_for_completion
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableServer::POAManager::AdapterInactive
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void deactivate (
        ::CORBA::Boolean etherealize_objects,
        ::CORBA::Boolean wait_for_completion
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableServer::POAManager::AdapterInactive
      )) = 0;

#endif /* TAO_HAS_MINIMUM_CORBA == 0 */

    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual ::PortableServer::POAManager::State get_state (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    // Abstract or local interface only.
    POAManager (void);

    virtual ~POAManager (void);

  private:
    // Private and unimplemented for concrete interfaces.
    POAManager (const POAManager &);

    void operator= (const POAManager &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:49

  extern TAO_PortableServer_Export ::CORBA::TypeCode_ptr const _tc_POAManager;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:78

} // module PortableServer

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_POAMANAGER__TRAITS_)
#define _PORTABLESERVER_POAMANAGER__TRAITS_

  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::POAManager>
  {
    static ::PortableServer::POAManager_ptr duplicate (
        ::PortableServer::POAManager_ptr
      );
    static void release (
        ::PortableServer::POAManager_ptr
      );
    static ::PortableServer::POAManager_ptr nil (void);
    static CORBA::Boolean marshal (
        ::PortableServer::POAManager_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_codegen.cpp:1028

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */


