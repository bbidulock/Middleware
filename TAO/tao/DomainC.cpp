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
// be/be_codegen.cpp:338


#include "DomainC.h"
#include "IFR_Client_Adapter.h"
#include "Exception_Data.h"
#include "Invocation_Adapter.h"
#include "Object_T.h"
#include "Basic_Arguments.h"
#include "Object_Argument_T.h"
#include "Special_Basic_Arguments.h"
#include "ORB_Core.h"
#include "Typecode.h"
#include "ace/Dynamic_Service.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "DomainC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:62

// TAO specific stuff.
namespace CORBA
{
  class InterfaceDef;
  typedef InterfaceDef *InterfaceDef_ptr;
  typedef TAO_Objref_Var_T<InterfaceDef> InterfaceDef_var;
  typedef TAO_Objref_Out_T<InterfaceDef> InterfaceDef_out;
}

ACE_TEMPLATE_SPECIALIZATION
void
TAO::In_Object_Argument_T<CORBA::InterfaceDef_ptr>::interceptor_param (Dynamic::Parameter & p)
{
  TAO_IFR_Client_Adapter *adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );

  adapter->interfacedef_any_insert (p.argument, this->x_);
  p.mode = CORBA::PARAM_IN;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::In_Object_Argument_T<CORBA::InterfaceDef_ptr>::marshal (TAO_OutputCDR & cdr)
{
  TAO_IFR_Client_Adapter *adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );

  return adapter->interfacedef_cdr_insert (cdr, this->x_);
}

// Arg traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLICY__ARG_TRAITS_CS_)
#define _CORBA_POLICY__ARG_TRAITS_CS_

  ACE_TEMPLATE_SPECIALIZATION
  class TAO_Export Arg_Traits<CORBA::Policy>
    : public
        Object_Arg_Traits_T<
            CORBA::Policy_ptr,
            CORBA::Policy_var,
            CORBA::Policy_out,
            TAO::Objref_Traits<CORBA::Policy>
          >
  {
  };

#endif /* end #if !defined */

#if !defined (_CORBA_INTERFACEDEF__ARG_TRAITS_CS_)
#define _CORBA_INTERFACEDEF__ARG_TRAITS_CS_

  ACE_TEMPLATE_SPECIALIZATION
  class TAO_Export Arg_Traits<CORBA::InterfaceDef>
    : public
        Object_Arg_Traits_T<
            CORBA::InterfaceDef_ptr,
            CORBA::InterfaceDef_var,
            CORBA::InterfaceDef_out,
            TAO::Objref_Traits<CORBA::InterfaceDef>
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::DomainManager.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::DomainManager_ptr
TAO::Objref_Traits<CORBA::DomainManager>::tao_duplicate (
    CORBA::DomainManager_ptr p
  )
{
  return CORBA::DomainManager::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<CORBA::DomainManager>::tao_release (
    CORBA::DomainManager_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::DomainManager_ptr
TAO::Objref_Traits<CORBA::DomainManager>::tao_nil (void)
{
  return CORBA::DomainManager::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<CORBA::DomainManager>::tao_marshal (
    CORBA::DomainManager_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:78

::CORBA::Policy_ptr CORBA::DomainManager::get_domain_policy (
    CORBA::PolicyType policy_type
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }

  if (this->the_TAO_DomainManager_Proxy_Broker_ == 0)
    {
      CORBA_DomainManager_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }

  TAO::Arg_Traits<CORBA::Policy>::ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::PolicyType>::in_arg_val _tao_policy_type (policy_type);

  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval,
      &_tao_policy_type
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      2,
      "get_domain_policy",
      17,
      this->the_TAO_DomainManager_Proxy_Broker_
    );

  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (_tao_retval.excp ());

  return _tao_retval.retn ();
}

CORBA::DomainManager::DomainManager (int collocated)
 : the_TAO_DomainManager_Proxy_Broker_ (0)
{
  this->CORBA_DomainManager_setup_collocation (collocated);
}

void
CORBA::DomainManager::CORBA_DomainManager_setup_collocation (int collocated)
{
  if (collocated)
    {
      this->the_TAO_DomainManager_Proxy_Broker_ =
        ::CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer (this);
    }
}

CORBA::DomainManager::~DomainManager (void)
{}

void
CORBA::DomainManager::_tao_any_destructor (void *_tao_void_pointer)
{
  DomainManager *_tao_tmp_pointer =
    ACE_static_cast (DomainManager *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::DomainManager_ptr
CORBA::DomainManager::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<DomainManager>::narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/DomainManager:1.0",
        CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::DomainManager_ptr
CORBA::DomainManager::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<DomainManager>::unchecked_narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/DomainManager:1.0",
        CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::DomainManager_ptr
CORBA::DomainManager::_duplicate (DomainManager_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
CORBA::DomainManager::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/DomainManager:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return this->ACE_NESTED_CLASS (CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

const char* CORBA::DomainManager::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/DomainManager:1.0";
}

CORBA::Boolean
CORBA::DomainManager::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_DomainManager[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f446f),
  ACE_NTOHL (0x6d61696e),
  ACE_NTOHL (0x4d616e61),
  ACE_NTOHL (0x6765723a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/DomainManager:1.0
    14,
  ACE_NTOHL (0x446f6d61),
  ACE_NTOHL (0x696e4d61),
  ACE_NTOHL (0x6e616765),
  ACE_NTOHL (0x72000000),  // name = DomainManager
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_DomainManager (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_DomainManager),
    (char *) &_oc_CORBA_DomainManager,
    0,
    sizeof (CORBA::DomainManager)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_DomainManager =
    &_tc_TAO_tc_CORBA_DomainManager;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::ConstructionPolicy.

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::ConstructionPolicy_ptr
TAO::Objref_Traits<CORBA::ConstructionPolicy>::tao_duplicate (
    CORBA::ConstructionPolicy_ptr p
  )
{
  return CORBA::ConstructionPolicy::_duplicate (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
void
TAO::Objref_Traits<CORBA::ConstructionPolicy>::tao_release (
    CORBA::ConstructionPolicy_ptr p
  )
{
  CORBA::release (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::ConstructionPolicy_ptr
TAO::Objref_Traits<CORBA::ConstructionPolicy>::tao_nil (void)
{
  return CORBA::ConstructionPolicy::_nil ();
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION
CORBA::Boolean
TAO::Objref_Traits<CORBA::ConstructionPolicy>::tao_marshal (
    CORBA::ConstructionPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:78

void CORBA::ConstructionPolicy::make_domain_manager (
    CORBA::InterfaceDef_ptr object_type,
    CORBA::Boolean constr_policy
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  if (!this->is_evaluated ())
    {
      ACE_NESTED_CLASS (CORBA, Object)::tao_object_initialize (this);
    }

  if (this->the_TAO_ConstructionPolicy_Proxy_Broker_ == 0)
    {
      CORBA_ConstructionPolicy_setup_collocation (
          this->ACE_NESTED_CLASS (CORBA, Object)::_is_collocated ()
        );
    }

  TAO::Arg_Traits<void>::ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::InterfaceDef>::in_arg_val _tao_object_type (object_type);
  TAO::Arg_Traits<ACE_InputCDR::to_boolean>::in_arg_val _tao_constr_policy (constr_policy);

  TAO::Argument *_tao_signature [] =
    {
      &_tao_retval,
      &_tao_object_type,
      &_tao_constr_policy
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _tao_signature,
      3,
      "make_domain_manager",
      19,
      this->the_TAO_ConstructionPolicy_Proxy_Broker_
    );

  _tao_call.invoke (0, 0 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

CORBA::ConstructionPolicy::ConstructionPolicy (int collocated)
 : the_TAO_ConstructionPolicy_Proxy_Broker_ (0)
{
  this->CORBA_ConstructionPolicy_setup_collocation (collocated);
}

void
CORBA::ConstructionPolicy::CORBA_ConstructionPolicy_setup_collocation (int collocated)
{
  if (collocated)
    {
      this->the_TAO_ConstructionPolicy_Proxy_Broker_ =
        ::CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer (this);
    }

  this->CORBA_Policy_setup_collocation (collocated);
}

CORBA::ConstructionPolicy::~ConstructionPolicy (void)
{}

void
CORBA::ConstructionPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  ConstructionPolicy *_tao_tmp_pointer =
    ACE_static_cast (ConstructionPolicy *, _tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<ConstructionPolicy>::narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/ConstructionPolicy:1.0",
        CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_unchecked_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL
  )
{
  return
    TAO::Narrow_Utils<ConstructionPolicy>::unchecked_narrow (
        _tao_objref,
        "IDL:omg.org/CORBA/ConstructionPolicy:1.0",
        CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer
        ACE_ENV_ARG_PARAMETER
      );
}

CORBA::ConstructionPolicy_ptr
CORBA::ConstructionPolicy::_duplicate (ConstructionPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
CORBA::ConstructionPolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/ConstructionPolicy:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return this->ACE_NESTED_CLASS (CORBA, Object)::_is_a (
          value
          ACE_ENV_ARG_PARAMETER
        );
    }
}

const char* CORBA::ConstructionPolicy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/ConstructionPolicy:1.0";
}

CORBA::Boolean
CORBA::ConstructionPolicy::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_ConstructionPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  41,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f436f),
  ACE_NTOHL (0x6e737472),
  ACE_NTOHL (0x75637469),
  ACE_NTOHL (0x6f6e506f),
  ACE_NTOHL (0x6c696379),
  ACE_NTOHL (0x3a312e30),
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/ConstructionPolicy:1.0
    19,
  ACE_NTOHL (0x436f6e73),
  ACE_NTOHL (0x74727563),
  ACE_NTOHL (0x74696f6e),
  ACE_NTOHL (0x506f6c69),
  ACE_NTOHL (0x63790000),  // name = ConstructionPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_ConstructionPolicy (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_ConstructionPolicy),
    (char *) &_oc_CORBA_ConstructionPolicy,
    0,
    sizeof (CORBA::ConstructionPolicy)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_ConstructionPolicy =
    &_tc_TAO_tc_CORBA_ConstructionPolicy;
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_DOMAINMANAGERLIST_CS_)
#define _CORBA_DOMAINMANAGERLIST_CS_

CORBA::DomainManagerList::DomainManagerList (void)
{}

CORBA::DomainManagerList::DomainManagerList (
    CORBA::ULong max
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::DomainManager,
        CORBA::DomainManager_var
      >
    (max)
{}

CORBA::DomainManagerList::DomainManagerList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::DomainManager_ptr * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::DomainManager,
        CORBA::DomainManager_var
      >
    (max, length, buffer, release)
{}

CORBA::DomainManagerList::DomainManagerList (
    const DomainManagerList &seq
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::DomainManager,
        CORBA::DomainManager_var
      >
    (seq)
{}

CORBA::DomainManagerList::~DomainManagerList (void)
{}

void CORBA::DomainManagerList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  DomainManagerList * _tao_tmp_pointer =
    ACE_static_cast (DomainManagerList *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_CORBA_DomainManagerList[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  40,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x6f6d672e),
  ACE_NTOHL (0x6f72672f),
  ACE_NTOHL (0x434f5242),
  ACE_NTOHL (0x412f446f),
  ACE_NTOHL (0x6d61696e),
  ACE_NTOHL (0x4d616e61),
  ACE_NTOHL (0x6765724c),
  ACE_NTOHL (0x6973743a),
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/DomainManagerList:1.0
    18,
  ACE_NTOHL (0x446f6d61),
  ACE_NTOHL (0x696e4d61),
  ACE_NTOHL (0x6e616765),
  ACE_NTOHL (0x724c6973),
  ACE_NTOHL (0x74000000),  // name = DomainManagerList
    CORBA::tk_sequence, // typecode kind
  80, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_objref, // typecode kind
    64, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      36,
      ACE_NTOHL (0x49444c3a),
      ACE_NTOHL (0x6f6d672e),
      ACE_NTOHL (0x6f72672f),
      ACE_NTOHL (0x434f5242),
      ACE_NTOHL (0x412f446f),
      ACE_NTOHL (0x6d61696e),
      ACE_NTOHL (0x4d616e61),
      ACE_NTOHL (0x6765723a),
      ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/DomainManager:1.0
            14,
      ACE_NTOHL (0x446f6d61),
      ACE_NTOHL (0x696e4d61),
      ACE_NTOHL (0x6e616765),
      ACE_NTOHL (0x72000000),  // name = DomainManager

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_DomainManagerList (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_DomainManagerList),
    (char *) &_oc_CORBA_DomainManagerList,
    0,
    sizeof (CORBA::DomainManagerList)
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_DomainManagerList =
    &_tc_TAO_tc_CORBA_DomainManagerList;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:63

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::DomainManager_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::DomainManager_ptr &_tao_objref
  )
{
  CORBA::Object_var obj;

  if ((strm >> obj.inout ()) == 0)
    {
      return 0;
    }

  typedef ::CORBA::DomainManager RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        CORBA__TAO_DomainManager_Proxy_Broker_Factory_function_pointer
      );

  return 1;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:63

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ConstructionPolicy_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ConstructionPolicy_ptr &_tao_objref
  )
{
  CORBA::Object_var obj;

  if ((strm >> obj.inout ()) == 0)
    {
      return 0;
    }

  typedef ::CORBA::ConstructionPolicy RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        CORBA__TAO_ConstructionPolicy_Proxy_Broker_Factory_function_pointer
      );

  return 1;
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_cs.cpp:95

#if !defined _TAO_CDR_OP_CORBA_DomainManagerList_CPP_
#define _TAO_CDR_OP_CORBA_DomainManagerList_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::DomainManagerList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();

  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = 1;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag =
            _tao_sequence[i].in ()->marshal (strm);
        }

      return _tao_marshal_flag;
    }

  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::DomainManagerList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;

  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return 0;
        }

      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);

      // If length is 0 we return true.
      if (0 >= _tao_seq_len)
        {
          return 1;
        }

      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = 1;

      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
        }

      return _tao_marshal_flag;

    }

  return 0;
}

#endif /* _TAO_CDR_OP_CORBA_DomainManagerList_CPP_ */

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1725

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (_CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_

  template class
    TAO::Arg_Traits<
        CORBA::Policy
      >;

  template class
    TAO::Object_Arg_Traits_T<
        CORBA::Policy_ptr,
        CORBA::Policy_var,
        CORBA::Policy_out,
        TAO::Objref_Traits<CORBA::Policy>
      >;

#endif /* end #if !defined */

#if !defined (_CORBA_INTERFACEDEF__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_INTERFACEDEF__ARG_TRAITS_TMPLINST_CS_

  template class
    TAO::Arg_Traits<
        CORBA::InterfaceDef
      >;

  template class
    TAO::Object_Arg_Traits_T<
        CORBA::InterfaceDef_ptr,
        CORBA::InterfaceDef_var,
        CORBA::InterfaceDef_out,
        TAO::Objref_Traits<CORBA::InterfaceDef>
      >;

#endif /* end #if !defined */

  template class
    TAO::Ret_Object_Argument_T<
        CORBA::Policy_ptr,
        CORBA::Policy_var
      >;

  template class
    TAO::Objref_Traits<
        CORBA::DomainManager
      >;

  template class
    TAO_Objref_Var_T<
        CORBA::DomainManager
      >;

  template class
    TAO_Objref_Out_T<
        CORBA::DomainManager
      >;

  template class
    TAO::Narrow_Utils<
        CORBA::DomainManager
      >;

  template class
    TAO::In_Object_Argument_T<
        CORBA::InterfaceDef_ptr
      >;

  template class
    TAO::Objref_Traits<
        CORBA::ConstructionPolicy
      >;

  template class
    TAO_Objref_Var_T<
        CORBA::ConstructionPolicy
      >;

  template class
    TAO_Objref_Out_T<
        CORBA::ConstructionPolicy
      >;

  template class
    TAO::Narrow_Utils<
        CORBA::ConstructionPolicy
      >;

  template class
    TAO_Object_Manager<
        CORBA::DomainManager,
        CORBA::DomainManager_var
      >;

  template class
    TAO_MngSeq_Var_T<
        CORBA::DomainManagerList,
        TAO_Object_Manager<
            CORBA::DomainManager,
            CORBA::DomainManager_var
          >
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::DomainManagerList,
        TAO_Object_Manager<
            CORBA::DomainManager,
            CORBA::DomainManager_var
          >
      >;

  template class
    TAO_MngSeq_Out_T<
        CORBA::DomainManagerList,
        CORBA::DomainManagerList_var,
        TAO_Object_Manager<
            CORBA::DomainManager,
            CORBA::DomainManager_var
          >
      >;

#if !defined (_CORBA_DOMAINMANAGER__EXPLICIT_CS_)
#define _CORBA_DOMAINMANAGER__EXPLICIT_CS_

  template class
    TAO_Unbounded_Object_Sequence<
        CORBA::DomainManager,
        CORBA::DomainManager_var
      >;

#endif /* end #if !defined */

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (_CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLICY__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate \
    TAO::Arg_Traits< \
        CORBA::Policy \
      >

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        CORBA::Policy_ptr, \
        CORBA::Policy_var, \
        CORBA::Policy_out, \
        TAO::Objref_Traits<CORBA::Policy> \
      >

#endif /* end #if !defined */

#if !defined (_CORBA_INTERFACEDEF__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_INTERFACEDEF__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate \
    TAO::Arg_Traits< \
        CORBA::InterfaceDef \
      >

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        CORBA::InterfaceDef_ptr, \
        CORBA::InterfaceDef_var, \
        CORBA::InterfaceDef_out, \
        TAO::Objref_Traits<CORBA::InterfaceDef> \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::Objref_Traits< \
        CORBA::DomainManager \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::DomainManager
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::DomainManager
      >

# pragma instantiate \
    TAO::Narrow_Utils< \
        CORBA::DomainManager \
      >

# pragma instantiate \
    TAO::In_Object_Argument_T< \
        CORBA::InterfaceDef_ptr \
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        CORBA::ConstructionPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::ConstructionPolicy
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::ConstructionPolicy
      >

# pragma instantiate \
    TAO::Narrow_Utils< \
        CORBA::ConstructionPolicy \
      >

# pragma instantiate \
    TAO_MngSeq_Var_T< \
        CORBA::DomainManagerList, \
        TAO_Object_Manager< \
            CORBA::DomainManager, \
            CORBA::DomainManager_var \
          > \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::DomainManagerList, \
        TAO_Object_Manager< \
            CORBA::DomainManager, \
            CORBA::DomainManager_var \
          > \
      >

# pragma instantiate \
    TAO_MngSeq_Out_T< \
        CORBA::DomainManagerList, \
        CORBA::DomainManagerList_var, \
        TAO_Object_Manager< \
            CORBA::DomainManager, \
            CORBA::DomainManager_var \
          > \
      >

#if !defined (_CORBA_DOMAINMANAGER__EXPLICIT_CS_)
#define _CORBA_DOMAINMANAGER__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Object_Sequence< \
        CORBA::DomainManager, \
        CORBA::DomainManager_var \
      >

#endif /* end #if !defined */

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
