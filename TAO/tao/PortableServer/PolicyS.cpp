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
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef _TAO_IDL_ORIG_POLICYS_CPP_
#define _TAO_IDL_ORIG_POLICYS_CPP_

#include "PolicyS.h"

#include "tao/PortableServer/Object_Adapter.h"
#include "tao/PortableServer/Operation_Table.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/PICurrent.h"
#include "tao/PortableServer/ServerRequestInfo.h"
#include "tao/PortableServer/ServerInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */

#include "ace/Dynamic_Service.h"
#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "PolicyS.i"
#endif /* !defined INLINE */

class TAO_CORBA_Policy_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 19:31:31 */
/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: /project/sirion/coryan/amh/ACE_wrappers/build/Linux/bin/gperf -m -M -J -c -C -D -E -T -f 0 -F 0 -a -o -t -p -K opname_ -L C++ -Z TAO_CORBA_Policy_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CORBA_Policy_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17,  0,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17,  0,
     17,  0,  0,  0, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17,  0, 17, 17, 17, 17,  0, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17,
#else
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17,  0, 17,  0, 17,  0,
      0,  0, 17, 17, 17, 17, 17, 17, 17, 17,
     17, 17, 17, 17, 17, 17,  0, 17, 17, 17,
     17,  0, 17, 17, 17, 17, 17, 17,
#endif /* ACE_MVS */
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_CORBA_Policy_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 6,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 16,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 16,
      HASH_VALUE_RANGE = 13,
      DUPLICATES = 0,
      WORDLIST_SIZE = 10
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0},{"",0},{"",0},{"",0},
      {"copy",  &POA_CORBA::Policy::copy_skel},
      {"_is_a",  &POA_CORBA::Policy::_is_a_skel},
      {"",0},
      {"destroy",       &POA_CORBA::Policy::destroy_skel},
      {"",0},{"",0},
      {"_interface",  &POA_CORBA::Policy::_interface_skel},
      {"",0},{"",0},
      {"_non_existent",  &POA_CORBA::Policy::_non_existent_skel},
      {"",0},{"",0},
      {"_get_policy_type",      &POA_CORBA::Policy::_get_policy_type_skel},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname_;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}
/* ending time is 19:31:31 */
static TAO_CORBA_Policy_Perfect_Hash_OpTable tao_CORBA_Policy_optable;

#if (TAO_HAS_INTERCEPTORS == 1)
class TAO_ServerRequestInfo_CORBA_Policy_policy_type_get : public TAO_ServerRequestInfo
{
public:
  TAO_ServerRequestInfo_CORBA_Policy_policy_type_get (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *tao_servant_upcall,POA_CORBA::Policy *tao_impl
     ACE_ENV_ARG_DECL_WITH_DEFAULTS
  );

  virtual Dynamic::ParameterList * arguments (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual Dynamic::ExceptionList * exceptions (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::Any * result (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual char * target_most_derived_interface (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::Boolean target_is_a (
      const char * id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void result (CORBA::PolicyType result);

private:
  TAO_ServerRequestInfo_CORBA_Policy_policy_type_get (const TAO_ServerRequestInfo_CORBA_Policy_policy_type_get &);
  void operator= (const TAO_ServerRequestInfo_CORBA_Policy_policy_type_get &);

private:
  POA_CORBA::Policy *_tao_impl;
  CORBA::PolicyType _result;
};

TAO_ServerRequestInfo_CORBA_Policy_policy_type_get::TAO_ServerRequestInfo_CORBA_Policy_policy_type_get (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *_tao_servant_upcall,
    POA_CORBA::Policy *tao_impl ACE_ENV_ARG_DECL_NOT_USED
  )
  : TAO_ServerRequestInfo (_tao_server_request, _tao_servant_upcall),
    _tao_impl (tao_impl)
{}

Dynamic::ParameterList *
TAO_ServerRequestInfo_CORBA_Policy_policy_type_get::arguments (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the argument list on demand.
  Dynamic::ParameterList *parameter_list =
    TAO_RequestInfo_Util::make_parameter_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return parameter_list;
}

Dynamic::ExceptionList *
TAO_ServerRequestInfo_CORBA_Policy_policy_type_get::exceptions (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the exception list on demand.
  Dynamic::ExceptionList *exception_list =
    TAO_RequestInfo_Util::make_exception_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return exception_list;
}


CORBA::Any *
TAO_ServerRequestInfo_CORBA_Policy_policy_type_get::result (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the result on demand.
  CORBA::Boolean tk_void_any = 0;
  CORBA::Any *result_any =
    TAO_RequestInfo_Util::make_any (tk_void_any ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Any_var safe_result_any = result_any;

  (*result_any) <<= this->_result;

  return safe_result_any._retn ();
}

char *
TAO_ServerRequestInfo_CORBA_Policy_policy_type_get::target_most_derived_interface (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return
    CORBA::string_dup (this->_tao_impl->_interface_repository_id ());
}

CORBA::Boolean
TAO_ServerRequestInfo_CORBA_Policy_policy_type_get::target_is_a (
    const char * id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->_tao_impl->_is_a (id ACE_ENV_ARG_PARAMETER);
}

void
TAO_ServerRequestInfo_CORBA_Policy_policy_type_get::result (CORBA::PolicyType result)
{
  // Update the result.
   this->_result = result;
}

class TAO_ServerRequestInfo_CORBA_Policy_copy : public TAO_ServerRequestInfo
{
public:
  TAO_ServerRequestInfo_CORBA_Policy_copy (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *tao_servant_upcall,POA_CORBA::Policy *tao_impl
     ACE_ENV_ARG_DECL_WITH_DEFAULTS
  );

  virtual Dynamic::ParameterList * arguments (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual Dynamic::ExceptionList * exceptions (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::Any * result (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual char * target_most_derived_interface (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::Boolean target_is_a (
      const char * id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  void result (::CORBA::Policy_ptr result);

private:
  TAO_ServerRequestInfo_CORBA_Policy_copy (const TAO_ServerRequestInfo_CORBA_Policy_copy &);
  void operator= (const TAO_ServerRequestInfo_CORBA_Policy_copy &);

private:
  POA_CORBA::Policy *_tao_impl;
  ::CORBA::Policy_ptr _result;
};

TAO_ServerRequestInfo_CORBA_Policy_copy::TAO_ServerRequestInfo_CORBA_Policy_copy (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *_tao_servant_upcall,
    POA_CORBA::Policy *tao_impl ACE_ENV_ARG_DECL_NOT_USED
  )
  : TAO_ServerRequestInfo (_tao_server_request, _tao_servant_upcall),
    _tao_impl (tao_impl)
{}

Dynamic::ParameterList *
TAO_ServerRequestInfo_CORBA_Policy_copy::arguments (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the argument list on demand.
  Dynamic::ParameterList *parameter_list =
    TAO_RequestInfo_Util::make_parameter_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return parameter_list;
}

Dynamic::ExceptionList *
TAO_ServerRequestInfo_CORBA_Policy_copy::exceptions (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the exception list on demand.
  Dynamic::ExceptionList *exception_list =
    TAO_RequestInfo_Util::make_exception_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return exception_list;
}


CORBA::Any *
TAO_ServerRequestInfo_CORBA_Policy_copy::result (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the result on demand.
  CORBA::Boolean tk_void_any = 0;
  CORBA::Any *result_any =
    TAO_RequestInfo_Util::make_any (tk_void_any ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Any_var safe_result_any = result_any;

  (*result_any) <<= this->_result;

  return safe_result_any._retn ();
}

char *
TAO_ServerRequestInfo_CORBA_Policy_copy::target_most_derived_interface (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return
    CORBA::string_dup (this->_tao_impl->_interface_repository_id ());
}

CORBA::Boolean
TAO_ServerRequestInfo_CORBA_Policy_copy::target_is_a (
    const char * id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->_tao_impl->_is_a (id ACE_ENV_ARG_PARAMETER);
}

void
TAO_ServerRequestInfo_CORBA_Policy_copy::result (::CORBA::Policy_ptr result)
{
  // Update the result.
   this->_result = result;
}

class TAO_ServerRequestInfo_CORBA_Policy_destroy : public TAO_ServerRequestInfo
{
public:
  TAO_ServerRequestInfo_CORBA_Policy_destroy (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *tao_servant_upcall,POA_CORBA::Policy *tao_impl
     ACE_ENV_ARG_DECL_WITH_DEFAULTS
  );

  virtual Dynamic::ParameterList * arguments (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual Dynamic::ExceptionList * exceptions (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::Any * result (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual char * target_most_derived_interface (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual CORBA::Boolean target_is_a (
      const char * id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));


private:
  TAO_ServerRequestInfo_CORBA_Policy_destroy (const TAO_ServerRequestInfo_CORBA_Policy_destroy &);
  void operator= (const TAO_ServerRequestInfo_CORBA_Policy_destroy &);

private:
  POA_CORBA::Policy *_tao_impl;

};

TAO_ServerRequestInfo_CORBA_Policy_destroy::TAO_ServerRequestInfo_CORBA_Policy_destroy (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *_tao_servant_upcall,
    POA_CORBA::Policy *tao_impl ACE_ENV_ARG_DECL_NOT_USED
  )
  : TAO_ServerRequestInfo (_tao_server_request, _tao_servant_upcall),
    _tao_impl (tao_impl)
{}

Dynamic::ParameterList *
TAO_ServerRequestInfo_CORBA_Policy_destroy::arguments (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the argument list on demand.
  Dynamic::ParameterList *parameter_list =
    TAO_RequestInfo_Util::make_parameter_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return parameter_list;
}

Dynamic::ExceptionList *
TAO_ServerRequestInfo_CORBA_Policy_destroy::exceptions (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the exception list on demand.
  Dynamic::ExceptionList *exception_list =
    TAO_RequestInfo_Util::make_exception_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return exception_list;
}


CORBA::Any *
TAO_ServerRequestInfo_CORBA_Policy_destroy::result (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the result on demand.
  CORBA::Boolean tk_void_any = 1;
  CORBA::Any *result_any =
    TAO_RequestInfo_Util::make_any (tk_void_any ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return result_any;
}

char *
TAO_ServerRequestInfo_CORBA_Policy_destroy::target_most_derived_interface (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return
    CORBA::string_dup (this->_tao_impl->_interface_repository_id ());
}

CORBA::Boolean
TAO_ServerRequestInfo_CORBA_Policy_destroy::target_is_a (
    const char * id
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->_tao_impl->_is_a (id ACE_ENV_ARG_PARAMETER);
}

#endif /* TAO_HAS_INTERCEPTORS */

///////////////////////////////////////////////////////////////////////
//            Strategized Proxy Broker Implementation
//

// Factory function Implementation.
POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker *POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::the_TAO_Policy_Strategized_Proxy_Broker (void)
{
  static POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker strategized_proxy_broker;
  return &strategized_proxy_broker;
}

POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::_TAO_Policy_Strategized_Proxy_Broker (void)
{
  for (int i = 0; i < TAO_Collocation_Strategies::CS_LAST; ++i)
    this->proxy_cache_[i] = 0;

}

POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::~_TAO_Policy_Strategized_Proxy_Broker (void)
{
  for (int i = 0; i < TAO_Collocation_Strategies::CS_LAST; ++i)
    delete this->proxy_cache_[i];

}

CORBA::_TAO_Policy_Proxy_Impl&
POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::select_proxy (
    ::CORBA::Policy *object
    ACE_ENV_ARG_DECL
  )
{
  int strategy =
    TAO_ORB_Core::collocation_strategy (object ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN (*this->proxy_cache_[strategy]);

  if (this->proxy_cache_[strategy] != 0)
    return *this->proxy_cache_[strategy];

  this->create_proxy (strategy ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (*this->proxy_cache_[strategy]);

  return *this->proxy_cache_[strategy];

}

void
POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::create_proxy (
    int strategy
    ACE_ENV_ARG_DECL
  )
{
  ACE_GUARD (TAO_SYNCH_MUTEX, guard, this->mutex_);

  if (this->proxy_cache_[strategy] == 0)
    {
      switch (strategy)
        {
        case TAO_Collocation_Strategies::CS_THRU_POA_STRATEGY:
          ACE_NEW_THROW_EX (
              this->proxy_cache_[strategy],
              POA_CORBA::_TAO_Policy_ThruPOA_Proxy_Impl,
              CORBA::NO_MEMORY ()
          );
          ACE_CHECK;
          break;

        case TAO_Collocation_Strategies::CS_DIRECT_STRATEGY:
          ACE_NEW_THROW_EX (
              this->proxy_cache_[strategy],
              POA_CORBA::_TAO_Policy_Direct_Proxy_Impl,
              CORBA::NO_MEMORY ()
          );
          ACE_CHECK;
          break;

        case TAO_Collocation_Strategies::CS_REMOTE_STRATEGY:
        default:
          ACE_NEW_THROW_EX (
              this->proxy_cache_[strategy],
              ::CORBA::_TAO_Policy_Remote_Proxy_Impl,
              CORBA::NO_MEMORY ()
          );
          ACE_CHECK;
          break;

      }

  }
}


//
//        End Strategized Proxy Broker Implementation
///////////////////////////////////////////////////////////////////////


CORBA::_TAO_Policy_Proxy_Broker *
CORBA__TAO_Policy_Proxy_Broker_Factory_function (CORBA::Object_ptr obj)
{
  ACE_UNUSED_ARG (obj);
  return ::POA_CORBA::_TAO_Policy_Strategized_Proxy_Broker::the_TAO_Policy_Strategized_Proxy_Broker();
}

int
CORBA__TAO_Policy_Proxy_Broker_Factory_Initializer (long)
{
  CORBA__TAO_Policy_Proxy_Broker_Factory_function_pointer =
    CORBA__TAO_Policy_Proxy_Broker_Factory_function;

  return 0;
}

static int CORBA__TAO_Policy_Proxy_Broker_Stub_Factory_Initializer_Scarecrow =
  CORBA__TAO_Policy_Proxy_Broker_Factory_Initializer (ACE_reinterpret_cast (long, CORBA__TAO_Policy_Proxy_Broker_Factory_Initializer));


///////////////////////////////////////////////////////////////////////
//                 ThruPOA Proxy  Implementation
//

POA_CORBA::_TAO_Policy_ThruPOA_Proxy_Impl::_TAO_Policy_ThruPOA_Proxy_Impl (void)
{}

// ThruPOA Implementation of the IDL interface methods

CORBA::PolicyType POA_CORBA::_TAO_Policy_ThruPOA_Proxy_Impl::policy_type (
    CORBA_Object *_collocated_tao_target_
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  CORBA::PolicyType _tao_retval = 0;
  ACE_UNUSED_ARG (_tao_retval);
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      _collocated_tao_target_->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  CORBA::Object_var forward_to;
  servant_upcall.prepare_for_upcall (
      _collocated_tao_target_->_object_key (),
      "policy_type",
      forward_to.out ()
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK_RETURN (_tao_retval);
  servant_upcall.pre_invoke_collocated_request (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (_tao_retval);
  return ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/CORBA/Policy:1.0"
        )
    )->policy_type (
        ACE_ENV_SINGLE_ARG_PARAMETER
      );
}

::CORBA::Policy_ptr POA_CORBA::_TAO_Policy_ThruPOA_Proxy_Impl::copy (
    CORBA_Object *_collocated_tao_target_
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  ::CORBA::Policy_var _tao_retval;
  ACE_UNUSED_ARG (_tao_retval);
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      _collocated_tao_target_->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  CORBA::Object_var forward_to;
  servant_upcall.prepare_for_upcall (
      _collocated_tao_target_->_object_key (),
      "copy",
      forward_to.out ()
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK_RETURN (_tao_retval._retn ());
  servant_upcall.pre_invoke_collocated_request (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (_tao_retval._retn ());
  return ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/CORBA/Policy:1.0"
        )
    )->copy (
        ACE_ENV_SINGLE_ARG_PARAMETER
      );
}

void POA_CORBA::_TAO_Policy_ThruPOA_Proxy_Impl::destroy (
    CORBA_Object *_collocated_tao_target_
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      _collocated_tao_target_->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  CORBA::Object_var forward_to;
  servant_upcall.prepare_for_upcall (
      _collocated_tao_target_->_object_key (),
      "destroy",
      forward_to.out ()
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK;
  servant_upcall.pre_invoke_collocated_request (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/CORBA/Policy:1.0"
        )
    )->destroy (
        ACE_ENV_SINGLE_ARG_PARAMETER
      );
  return;
}

//
//           End ThruPOA Proxy Implementation
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                 Direct Proxy  Implementation
//

POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::_TAO_Policy_Direct_Proxy_Impl (void)
{}

CORBA::PolicyType POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::policy_type  (
    CORBA_Object *_collocated_tao_target_
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      _collocated_tao_target_->_servant ()->_downcast ("IDL:omg.org/CORBA/Policy:1.0")
    )->policy_type (
          ACE_ENV_SINGLE_ARG_PARAMETER
        );

}

::CORBA::Policy_ptr POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::copy  (
    CORBA_Object *_collocated_tao_target_
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      _collocated_tao_target_->_servant ()->_downcast ("IDL:omg.org/CORBA/Policy:1.0")
    )->copy (
          ACE_ENV_SINGLE_ARG_PARAMETER
        );

}

void POA_CORBA::_TAO_Policy_Direct_Proxy_Impl::destroy  (
    CORBA_Object *_collocated_tao_target_
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      _collocated_tao_target_->_servant ()->_downcast ("IDL:omg.org/CORBA/Policy:1.0")
    )->destroy (
          ACE_ENV_SINGLE_ARG_PARAMETER
        );

}


//
//           End Direct Proxy Implementation
///////////////////////////////////////////////////////////////////////
// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:100
POA_CORBA::Policy::Policy (void)
{
  this->optable_ = &tao_CORBA_Policy_optable;
}

POA_CORBA::Policy::Policy (const Policy& rhs)
  :  TAO_ServantBase (rhs)
{}

POA_CORBA::Policy::~Policy (void)
{
}

void POA_CORBA::Policy::_get_policy_type_skel (
    TAO_ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void *_tao_servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Policy *_tao_impl =
    ACE_static_cast (
        POA_CORBA::Policy *,
        _tao_object_reference
      );
  CORBA::PolicyType _tao_retval = 0;

#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_Object_Adapter::Servant_Upcall *_tao_upcall =
    ACE_static_cast (TAO_Object_Adapter::Servant_Upcall *, _tao_servant_upcall);

  TAO_ServerRequestInterceptor_Adapter _tao_vfr (
      _tao_server_request.orb_core ()->server_request_interceptors (),
      _tao_server_request.interceptor_count ()
    );

  TAO_ServerRequestInfo_CORBA_Policy_policy_type_get _tao_ri (
      _tao_server_request,
      _tao_upcall,
      _tao_impl ACE_ENV_ARG_PARAMETER
    );

  ACE_TRY
    {
      {
        TAO_PICurrent_Guard _tao_pi_guard (_tao_ri.server_request (),
                                           1  /* Copy TSC to RSC */);

        _tao_vfr.receive_request (&_tao_ri ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;

#endif /* TAO_HAS_INTERCEPTORS */
        _tao_retval =
        _tao_impl->policy_type (
            ACE_ENV_SINGLE_ARG_PARAMETER
          );
        TAO_INTERCEPTOR_CHECK;

#if (TAO_HAS_INTERCEPTORS == 1)
        }

      CORBA::PolicyType _tao_retval_info = _tao_retval;
      _tao_ri.result (_tao_retval_info);
      _tao_ri.reply_status (PortableInterceptor::SUCCESSFUL);
      _tao_vfr.send_reply (&_tao_ri ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      _tao_ri.exception (&ACE_ANY_EXCEPTION);
      _tao_vfr.send_exception (
          &_tao_ri
          ACE_ENV_ARG_PARAMETER
        );
      ACE_TRY_CHECK;

      PortableInterceptor::ReplyStatus _tao_status =
        _tao_ri.reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (_tao_status == PortableInterceptor::SYSTEM_EXCEPTION
          || _tao_status == PortableInterceptor::USER_EXCEPTION)
        ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

  _tao_server_request.init_reply ();

  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();

  if (!(
      (_tao_out << _tao_retval)
    ))
ACE_THROW (CORBA::MARSHAL ());

  // In case _tao_servant_upcall is not used in this function
  ACE_UNUSED_ARG (_tao_servant_upcall);

  }

void POA_CORBA::Policy::copy_skel (
    TAO_ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void *_tao_servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Policy *_tao_impl =
    ACE_static_cast (
        POA_CORBA::Policy *,
        _tao_object_reference
      );
  ::CORBA::Policy_var _tao_retval;

#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_Object_Adapter::Servant_Upcall *_tao_upcall =
    ACE_static_cast (TAO_Object_Adapter::Servant_Upcall *, _tao_servant_upcall);

  TAO_ServerRequestInterceptor_Adapter _tao_vfr (
      _tao_server_request.orb_core ()->server_request_interceptors (),
      _tao_server_request.interceptor_count ()
    );

  TAO_ServerRequestInfo_CORBA_Policy_copy _tao_ri (
      _tao_server_request,
      _tao_upcall,
      _tao_impl ACE_ENV_ARG_PARAMETER
    );

  ACE_TRY
    {
      {
        TAO_PICurrent_Guard _tao_pi_guard (_tao_ri.server_request (),
                                           1  /* Copy TSC to RSC */);

        _tao_vfr.receive_request (&_tao_ri ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;

#endif /* TAO_HAS_INTERCEPTORS */
        _tao_retval =
        _tao_impl->copy (
            ACE_ENV_SINGLE_ARG_PARAMETER
          );
        TAO_INTERCEPTOR_CHECK;

#if (TAO_HAS_INTERCEPTORS == 1)
        }

      ::CORBA::Policy_ptr _tao_retval_info = _tao_retval._retn ();
      _tao_ri.result (_tao_retval_info);
      _tao_retval = _tao_retval_info;
      _tao_ri.reply_status (PortableInterceptor::SUCCESSFUL);
      _tao_vfr.send_reply (&_tao_ri ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      _tao_ri.exception (&ACE_ANY_EXCEPTION);
      _tao_vfr.send_exception (
          &_tao_ri
          ACE_ENV_ARG_PARAMETER
        );
      ACE_TRY_CHECK;

      PortableInterceptor::ReplyStatus _tao_status =
        _tao_ri.reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (_tao_status == PortableInterceptor::SYSTEM_EXCEPTION
          || _tao_status == PortableInterceptor::USER_EXCEPTION)
        ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

  _tao_server_request.init_reply ();

  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();

  if (!(
      (_tao_out << _tao_retval.in ())
    ))
ACE_THROW (CORBA::MARSHAL ());

  // In case _tao_servant_upcall is not used in this function
  ACE_UNUSED_ARG (_tao_servant_upcall);

  }

void POA_CORBA::Policy::destroy_skel (
    TAO_ServerRequest &_tao_server_request,
    void *_tao_object_reference,
    void *_tao_servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Policy *_tao_impl =
    ACE_static_cast (
        POA_CORBA::Policy *,
        _tao_object_reference
      );
  _tao_server_request.argument_flag (0);

#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_Object_Adapter::Servant_Upcall *_tao_upcall =
    ACE_static_cast (TAO_Object_Adapter::Servant_Upcall *, _tao_servant_upcall);

  TAO_ServerRequestInterceptor_Adapter _tao_vfr (
      _tao_server_request.orb_core ()->server_request_interceptors (),
      _tao_server_request.interceptor_count ()
    );

  TAO_ServerRequestInfo_CORBA_Policy_destroy _tao_ri (
      _tao_server_request,
      _tao_upcall,
      _tao_impl ACE_ENV_ARG_PARAMETER
    );

  ACE_TRY
    {
      {
        TAO_PICurrent_Guard _tao_pi_guard (_tao_ri.server_request (),
                                           1  /* Copy TSC to RSC */);

        _tao_vfr.receive_request (&_tao_ri ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;

#endif /* TAO_HAS_INTERCEPTORS */

        _tao_impl->destroy (
            ACE_ENV_SINGLE_ARG_PARAMETER
          );
        TAO_INTERCEPTOR_CHECK;

#if (TAO_HAS_INTERCEPTORS == 1)
        }

      _tao_ri.reply_status (PortableInterceptor::SUCCESSFUL);
      _tao_vfr.send_reply (&_tao_ri ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      _tao_ri.exception (&ACE_ANY_EXCEPTION);
      _tao_vfr.send_exception (
          &_tao_ri
          ACE_ENV_ARG_PARAMETER
        );
      ACE_TRY_CHECK;

      PortableInterceptor::ReplyStatus _tao_status =
        _tao_ri.reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (_tao_status == PortableInterceptor::SYSTEM_EXCEPTION
          || _tao_status == PortableInterceptor::USER_EXCEPTION)
        ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

  _tao_server_request.init_reply ();

  // In case _tao_servant_upcall is not used in this function
  ACE_UNUSED_ARG (_tao_servant_upcall);

  }

void POA_CORBA::Policy::_is_a_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *) _tao_object_reference;
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;
  if (!(_tao_in >> value.out ()))
    ACE_THROW (CORBA::MARSHAL ());

  _tao_retval = _tao_impl->_is_a (value.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_CORBA::Policy::_non_existent_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *) _tao_object_reference;
  CORBA::Boolean _tao_retval =
    _tao_impl->_non_existent (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_CORBA::Policy::_interface_skel (
    TAO_ServerRequest &_tao_server_request,
    void * _tao_object_reference,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *) _tao_object_reference;
  CORBA_InterfaceDef_ptr _tao_retval = 0;
  CORBA::Boolean _tao_result = 0;

  TAO_IFR_Client_Adapter *_tao_adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );

  if (_tao_adapter == 0)
    {
      ACE_THROW (CORBA::INTF_REPOS ());
    }

  ACE_TRY
    {
      _tao_retval =
        _tao_impl->_get_interface (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      _tao_server_request.init_reply ();

      TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();

      _tao_result =
        _tao_adapter->interfacedef_cdr_insert (
            _tao_out,
            _tao_retval
          );
    }
  ACE_CATCHALL
    {
      _tao_adapter->dispose (_tao_retval);
    }
  ACE_ENDTRY;

  if (_tao_result == 0)
    {
      ACE_THROW (CORBA::MARSHAL ());
    }
}

CORBA::Boolean POA_CORBA::Policy::_is_a (
    const char* value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  const char *base_id = "IDL:org.omg/CORBA/Object:1.0";
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, base_id)))
      return 1;
    else
      return 0;
}

void* POA_CORBA::Policy::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Policy:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Policy_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

const char* POA_CORBA::Policy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Policy:1.0";
}

void POA_CORBA::Policy::_dispatch (
    TAO_ServerRequest &req,
    void *servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  this->synchronous_upcall_dispatch (req,
                                     servant_upcall,
                                     this
                                     ACE_ENV_ARG_PARAMETER);
}


CORBA::Policy*
POA_CORBA::Policy::_this (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Stub *stub = this->_create_stub (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  TAO_Stub_Auto_Ptr safe_stub (stub);

  CORBA::Object_ptr tmp = CORBA::Object::_nil ();

  if (stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ())
    ACE_NEW_RETURN (tmp, CORBA::Object (stub, 1, this), 0);
  else
    ACE_NEW_RETURN (tmp, CORBA::Object (stub, 0, this), 0);

  CORBA::Object_var obj = tmp;

  (void) safe_stub.release ();

  return ::CORBA::Policy::_unchecked_narrow (obj.in ());
}



#endif /* ifndef */
