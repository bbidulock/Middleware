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
// be\be_codegen.cpp:599

#ifndef _TAO_IDL_ORIG_POLICYS_CPP_
#define _TAO_IDL_ORIG_POLICYS_CPP_


#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/Any.h"

#include "PolicyS.h"

#include "tao/PortableServer/Operation_Table_Perfect_Hash.h"
#include "tao/PortableServer/Direct_Collocation_Upcall_Wrapper.h"
#include "tao/PortableServer/Upcall_Command.h"
#include "tao/PortableServer/Upcall_Wrapper.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Object_SArgument_T.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/TypeCode_SArg_Traits.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/CDR.h"
#include "tao/operation_details.h"
#include "tao/PortableInterceptor.h"
#include "tao/Basic_Arguments.h"
#include "tao/Object_Argument_T.h"
#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLICY__SARG_TRAITS_SS_)
#define _CORBA_POLICY__SARG_TRAITS_SS_

  template<>
  class  SArg_Traits<CORBA::Policy>
    : public
        Object_SArg_Traits_T<
            CORBA::Policy_ptr,
            CORBA::Policy_var,
            CORBA::Policy_out,
            TAO::Any_Insert_Policy_Stream <CORBA::Policy_ptr>
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLICY__ARG_TRAITS_SS_)
#define _CORBA_POLICY__ARG_TRAITS_SS_

  template<>
  class  Arg_Traits<CORBA::Policy>
    : public
        Object_Arg_Traits_T<
            CORBA::Policy_ptr,
            CORBA::Policy_var,
            CORBA::Policy_out,
            TAO::Objref_Traits<CORBA::Policy>,
            TAO::Any_Insert_Policy_Stream <CORBA::Policy_ptr>
          >
  {
  };

#endif /* end #if !defined */
}


// TAO_IDL - Generated from
// be\be_interface.cpp:1455

class TAO_CORBA_Policy_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: c:\ACE\latest\ACE_wrappers\bin\gperf.exe -m -M -J -c -C -D -E -T -f 0 -F 0,0 -a -o -t -p -K opname -L C++ -Z TAO_CORBA_Policy_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CORBA_Policy_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22,  0,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22,  0,
     22,  0,  0,  5, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22,  0, 22, 22, 22, 22,  0, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22,
#else
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22,  0, 22,  0, 22,  0,
      0,  5, 22, 22, 22, 22, 22, 22, 22, 22,
     22, 22, 22, 22, 22, 22,  0, 22, 22, 22,
     22,  0, 22, 22, 22, 22, 22, 22,
#endif /* ACE_MVS */
    };
  return len + asso_values[(int) str[len - 1]] + asso_values[(int) str[0]];
}

const TAO_operation_db_entry *
TAO_CORBA_Policy_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 7,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 16,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 21,
      HASH_VALUE_RANGE = 18,
      DUPLICATES = 0,
      WORDLIST_SIZE = 11
    };

  static const TAO_operation_db_entry  wordlist[] =
    {
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"copy", &POA_CORBA::Policy::copy_skel, &POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::copy},
      {"_is_a", &POA_CORBA::Policy::_is_a_skel, 0},
      {"",0,0},
      {"destroy", &POA_CORBA::Policy::destroy_skel, &POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::destroy},
      {"",0,0},{"",0,0},
      {"_component", &POA_CORBA::Policy::_component_skel, 0},
      {"",0,0},{"",0,0},
      {"_non_existent", &POA_CORBA::Policy::_non_existent_skel, 0},
      {"",0,0},
      {"_interface", &POA_CORBA::Policy::_interface_skel, 0},
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"_get_policy_type", &POA_CORBA::Policy::_get_policy_type_skel, &POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::_get_policy_type},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}

static TAO_CORBA_Policy_Perfect_Hash_OpTable tao_CORBA_Policy_optable;
///////////////////////////////////////////////////////////////////////
//            Strategized Proxy Broker Implementation
//

// TAO_IDL - Generated from
// be\be_visitor_interface/strategized_proxy_broker_ss.cpp:40

// Factory function Implementation.
POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker *
POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::the_TAO_Policy_Strategized_Proxy_Broker (void)
{
  static POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker
  strategized_proxy_broker;

  return &strategized_proxy_broker;
}

POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::_TAO_Policy_Strategized_Proxy_Broker (void)
{
}

POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::~_TAO_Policy_Strategized_Proxy_Broker (void)
{
}

TAO::Collocation_Strategy
POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::get_strategy (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO::Collocation_Strategy strategy =
    TAO_ORB_Core::collocation_strategy (obj ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (TAO::TAO_CS_REMOTE_STRATEGY);

  return strategy;
}

void
POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::dispatch (
    CORBA::Object_ptr obj,
    CORBA::Object_out forward_obj,
    TAO::Argument ** args,
    int num_args,
    const char * op,
    size_t op_len,
    TAO::Collocation_Strategy strategy
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::Exception))
{
  TAO::Direct_Collocation_Upcall_Wrapper collocation_upcall_wrapper;
  collocation_upcall_wrapper.upcall (
    obj,
    forward_obj,
    args,
    num_args,
    op,
    op_len,
    strategy
    ACE_ENV_ARG_PARAMETER);
}

//
//        End Strategized Proxy Broker Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:999

TAO::Collocation_Proxy_Broker *
CORBA__TAO_Policy_Proxy_Broker_Factory_function (CORBA::Object_ptr)
{
  return
    ::POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::the_TAO_Policy_Strategized_Proxy_Broker ();
}

int
CORBA__TAO_Policy_Proxy_Broker_Factory_Initializer (size_t)
{
  CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer =
    CORBA__TAO_Policy_Proxy_Broker_Factory_function;

  return 0;
}

static int
CORBA__TAO_Policy_Proxy_Broker_Stub_Factory_Initializer_Scarecrow =
  CORBA__TAO_Policy_Proxy_Broker_Factory_Initializer (
      reinterpret_cast<size_t> (CORBA__TAO_Policy_Proxy_Broker_Factory_Initializer)
    );



///////////////////////////////////////////////////////////////////////
//                 Direct Proxy  Implementation
//

POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::_TAO_Policy_Direct_Proxy_Impl (void)
{}

POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::~_TAO_Policy_Direct_Proxy_Impl (void)
{}

// TAO_IDL - Generated from
// be\be_visitor_operation/direct_proxy_impl_ss.cpp:42

void
POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::_get_policy_type (
    TAO_Abstract_ServantBase  *servant,
    TAO::Argument ** args,
    int
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  ((TAO::Arg_Traits< ::CORBA::PolicyType>::ret_val *) args[0])->arg () =
    dynamic_cast<POA_CORBA::Policy_ptr>
      (servant)
    ->policy_type (
          ACE_ENV_SINGLE_ARG_PARAMETER
        );
  ACE_CHECK;
}
// TAO_IDL - Generated from
// be\be_visitor_operation/direct_proxy_impl_ss.cpp:42

void
POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::copy (
    TAO_Abstract_ServantBase  *servant,
    TAO::Argument ** args,
    int
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  ((TAO::Arg_Traits< CORBA::Policy>::ret_val *) args[0])->arg () =
    dynamic_cast<POA_CORBA::Policy_ptr>
      (servant)
    ->copy (
          ACE_ENV_SINGLE_ARG_PARAMETER
        );
  ACE_CHECK;
}
// TAO_IDL - Generated from
// be\be_visitor_operation/direct_proxy_impl_ss.cpp:42

void
POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::destroy (
    TAO_Abstract_ServantBase  *servant,
    TAO::Argument **,
    int
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  dynamic_cast<POA_CORBA::Policy_ptr>
    (servant)
  ->destroy (
        ACE_ENV_SINGLE_ARG_PARAMETER
      );
  ACE_CHECK;
}


//
//           End Direct Proxy Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:103

POA_CORBA::Policy::Policy (void)
  : TAO_ServantBase ()
{
  this->optable_ = &tao_CORBA_Policy_optable;
}

POA_CORBA::Policy::Policy (const Policy& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs)
{
}

POA_CORBA::Policy::~Policy (void)
{
}
namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_operation/upcall_command_ss.cpp:127

  class _get_policy_type_Policy
    : public TAO::Upcall_Command
  {
  public:
    inline _get_policy_type_Policy (
      POA_CORBA::Policy * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
      , operation_details_ (operation_details)
      , args_ (args)
    {
    }

    virtual void execute (ACE_ENV_SINGLE_ARG_DECL)
    {
      TAO::SArg_Traits< ::CORBA::PolicyType>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::CORBA::PolicyType, TAO::SArg_Traits< ::CORBA::PolicyType>::ret_arg_type> (
          this->operation_details_,
          this->args_);


      retval =
        this->servant_->policy_type (
          ACE_ENV_SINGLE_ARG_PARAMETER);

    }

  private:
    POA_CORBA::Policy * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };

}


// TAO_IDL - Generated from
// be\be_visitor_operation/operation_ss.cpp:192

void POA_CORBA::Policy::_get_policy_type_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant
    ACE_ENV_ARG_DECL
  )
{


#if TAO_HAS_INTERCEPTORS == 1
  static CORBA::TypeCode_ptr const * const exceptions = 0;
  static size_t const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::CORBA::PolicyType>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };

  static size_t const nargs = 1;

  POA_CORBA::Policy * const impl =
    static_cast<POA_CORBA::Policy *> (servant);

  _get_policy_type_Policy command (
    impl,
    server_request.operation_details (),
    args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}
namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_operation/upcall_command_ss.cpp:127

  class copy_Policy
    : public TAO::Upcall_Command
  {
  public:
    inline copy_Policy (
      POA_CORBA::Policy * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
      , operation_details_ (operation_details)
      , args_ (args)
    {
    }

    virtual void execute (ACE_ENV_SINGLE_ARG_DECL)
    {
      TAO::SArg_Traits< CORBA::Policy>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< CORBA::Policy, TAO::SArg_Traits< CORBA::Policy>::ret_arg_type> (
          this->operation_details_,
          this->args_);


      retval =
        this->servant_->copy (
          ACE_ENV_SINGLE_ARG_PARAMETER);

    }

  private:
    POA_CORBA::Policy * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };

}


// TAO_IDL - Generated from
// be\be_visitor_operation/operation_ss.cpp:192

void POA_CORBA::Policy::copy_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant
    ACE_ENV_ARG_DECL
  )
{


#if TAO_HAS_INTERCEPTORS == 1
  static CORBA::TypeCode_ptr const * const exceptions = 0;
  static size_t const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< CORBA::Policy>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };

  static size_t const nargs = 1;

  POA_CORBA::Policy * const impl =
    static_cast<POA_CORBA::Policy *> (servant);

  copy_Policy command (
    impl,
    server_request.operation_details (),
    args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}
namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_operation/upcall_command_ss.cpp:127

  class destroy_Policy
    : public TAO::Upcall_Command
  {
  public:
    inline destroy_Policy (
      POA_CORBA::Policy * servant)
      : servant_ (servant)
    {
    }

    virtual void execute (ACE_ENV_SINGLE_ARG_DECL)
    {
      this->servant_->destroy (
        ACE_ENV_SINGLE_ARG_PARAMETER);

    }

  private:
    POA_CORBA::Policy * const servant_;
  };

}


// TAO_IDL - Generated from
// be\be_visitor_operation/operation_ss.cpp:192

void POA_CORBA::Policy::destroy_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant
    ACE_ENV_ARG_DECL
  )
{


#if TAO_HAS_INTERCEPTORS == 1
  static CORBA::TypeCode_ptr const * const exceptions = 0;
  static size_t const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< void>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };

  static size_t const nargs = 1;

  POA_CORBA::Policy * const impl =
    static_cast<POA_CORBA::Policy *> (servant);

  destroy_Policy command (
    impl);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:169

namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_operation/upcall_command_ss.cpp:127

  class _is_a_Policy_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _is_a_Policy_Upcall_Command (
      POA_CORBA::Policy * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
      , operation_details_ (operation_details)
      , args_ (args)
    {
    }

    virtual void execute (ACE_ENV_SINGLE_ARG_DECL)
    {
      TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACE_InputCDR::to_boolean, TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type> (
          this->operation_details_,
          this->args_);

      TAO::SArg_Traits< CORBA::Char *>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< CORBA::Char *, TAO::SArg_Traits< CORBA::Char *>::in_arg_type> (
          this->operation_details_,
          this->args_,
          1);


      retval =
        this->servant_-> _is_a (
          arg_1
          ACE_ENV_ARG_PARAMETER);

    }

  private:
    POA_CORBA::Policy * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };

}
void POA_CORBA::Policy::_is_a_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant
    ACE_ENV_ARG_DECL
  )
{


#if TAO_HAS_INTERCEPTORS == 1
  static CORBA::TypeCode_ptr const * const exceptions = 0;
  static size_t const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_val retval;
  TAO::SArg_Traits< CORBA::Char *>::in_arg_val _tao_repository_id;

  TAO::Argument * const args[] =
    {
      &retval,
      &_tao_repository_id
    };

  static size_t const nargs = 2;

  POA_CORBA::Policy * const impl =
    static_cast<POA_CORBA::Policy *> (servant);

  _is_a_Policy_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}

namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_operation/upcall_command_ss.cpp:127

  class _non_existent_Policy_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _non_existent_Policy_Upcall_Command (
      POA_CORBA::Policy * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
      , operation_details_ (operation_details)
      , args_ (args)
    {
    }

    virtual void execute (ACE_ENV_SINGLE_ARG_DECL)
    {
      TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACE_InputCDR::to_boolean, TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type> (
          this->operation_details_,
          this->args_);


      retval =
        this->servant_-> _non_existent (
          ACE_ENV_SINGLE_ARG_PARAMETER);

    }

  private:
    POA_CORBA::Policy * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };

}
void POA_CORBA::Policy::_non_existent_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant
    ACE_ENV_ARG_DECL
  )
{


#if TAO_HAS_INTERCEPTORS == 1
  static CORBA::TypeCode_ptr const * const exceptions = 0;
  static size_t const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };

  static size_t const nargs = 1;

  POA_CORBA::Policy * const impl =
    static_cast<POA_CORBA::Policy *> (servant);

  _non_existent_Policy_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}



// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:393



void POA_CORBA::Policy::_interface_skel (
    TAO_ServerRequest & server_request,
    void * /* servant_upcall */,
    void * servant
    ACE_ENV_ARG_DECL
  )
{
  TAO_IFR_Client_Adapter *_tao_adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );

  if (_tao_adapter == 0)
    {
      ACE_THROW (CORBA::INTF_REPOS (CORBA::OMGVMCID | 1,
                                    CORBA::COMPLETED_NO));
    }

  POA_CORBA::Policy * const impl =
    static_cast<POA_CORBA::Policy *> (servant);
  CORBA::InterfaceDef_ptr _tao_retval =
    impl->_get_interface (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  server_request.init_reply ();
  TAO_OutputCDR &_tao_out = *server_request.outgoing ();

  CORBA::Boolean const _tao_result =
    _tao_adapter->interfacedef_cdr_insert (
        _tao_out,
        _tao_retval
      );

  _tao_adapter->dispose (_tao_retval);

  if (_tao_result == 0)
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

namespace POA_CORBA
{


  // TAO_IDL - Generated from
  // be\be_visitor_operation/upcall_command_ss.cpp:127

  class _get_component_Policy_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _get_component_Policy_Upcall_Command (
      POA_CORBA::Policy * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
      , operation_details_ (operation_details)
      , args_ (args)
    {
    }

    virtual void execute (ACE_ENV_SINGLE_ARG_DECL)
    {
      TAO::SArg_Traits< ::CORBA::Object>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::CORBA::Object, TAO::SArg_Traits< ::CORBA::Object>::ret_arg_type> (
          this->operation_details_,
          this->args_);


      retval =
        this->servant_-> _get_component (
          ACE_ENV_SINGLE_ARG_PARAMETER);

    }

  private:
    POA_CORBA::Policy * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };

}
void POA_CORBA::Policy::_component_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant
    ACE_ENV_ARG_DECL
  )
{


#if TAO_HAS_INTERCEPTORS == 1
  static CORBA::TypeCode_ptr const * const exceptions = 0;
  static size_t const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::CORBA::Object>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };

  static size_t const nargs = 1;

  POA_CORBA::Policy * const impl =
    static_cast<POA_CORBA::Policy *> (servant);

  _get_component_Policy_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);

  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

}

CORBA::Boolean POA_CORBA::Policy::_is_a (
    const char* value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return
    (
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    );
}

const char* POA_CORBA::Policy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Policy:1.0";
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:940

void POA_CORBA::Policy::_dispatch (
    TAO_ServerRequest & req,
    void * servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  this->synchronous_upcall_dispatch (req,
                                     servant_upcall,
                                     this
                                     ACE_ENV_ARG_PARAMETER);
}

// TAO_IDL - Generated from
// be\be_visitor_interface/interface_ss.cpp:891

CORBA::Policy *
POA_CORBA::Policy::_this (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Stub *stub = this->_create_stub (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  TAO_Stub_Auto_Ptr safe_stub (stub);
  CORBA::Object_ptr tmp = CORBA::Object::_nil ();

  CORBA::Boolean _tao_opt_colloc =
    stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ();

  ACE_NEW_RETURN (
      tmp,
      CORBA::Object (stub, _tao_opt_colloc, this),
      0
    );

  CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();

  typedef ::CORBA::Policy STUB_SCOPED_NAME;
  return
    TAO::Narrow_Utils<STUB_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer
      );
}

#endif /* ifndef */

