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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:714

#ifndef _TAO_IDL_TESTS_CPP_
#define _TAO_IDL_TESTS_CPP_


#include "testS.h"
#include "tao/PortableServer/Object_Adapter.h"
#include "tao/PortableServer/Operation_Table.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
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
#include "tao/UB_String_ARguments.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:1241

class TAO_foo_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: gperf -m -M -J -c -C -D -E -T -f 0 -F 0 -a -o -t -p -K opname_ -L C++ -Z TAO_foo_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_foo_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
#if defined (ACE_MVS)
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16,  0,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16,  0,
     16, 16, 16,  5, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16,  0, 16, 16, 16, 16, 16, 16,
     16, 16, 16,  0, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16,
#else
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16, 16,  0, 16,  0, 16, 16,
     16,  5, 16, 16, 16, 16, 16, 16, 16, 16,
     16, 16, 16, 16,  0, 16,  0, 16, 16, 16,
     16, 16, 16, 16, 16, 16, 16, 16,
#endif /* ACE_MVS */
    };
  return len + asso_values[str[len - 1]] + asso_values[str[0]];
}

const class TAO_operation_db_entry *
TAO_foo_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 5,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 13,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 15,
      HASH_VALUE_RANGE = 11,
      DUPLICATES = 0,
      WORDLIST_SIZE = 10
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0},{"",0},{"",0},{"",0},{"",0},
      {"_is_a",  &POA_foo::_is_a_skel},
      {"",0},
      {"all_str", 	&POA_foo::all_str_skel},
      {"",0},{"",0},
      {"_component",  &POA_foo::_component_skel},
      {"",0},{"",0},
      {"_non_existent",  &POA_foo::_non_existent_skel},
      {"",0},
      {"_interface",  &POA_foo::_interface_skel},
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
static TAO_foo_Perfect_Hash_OpTable tao_foo_optable;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interceptors_ss.cpp:52

#if (TAO_HAS_INTERCEPTORS == 1)

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/interceptors_ss.cpp:74

class TAO_ServerRequestInfo_foo_all_str : public TAO_ServerRequestInfo
{
public:
  TAO_ServerRequestInfo_foo_all_str (
      TAO_ServerRequest &_tao_server_request,
      TAO_Object_Adapter::Servant_Upcall *tao_servant_upcall,
      POA_foo *tao_impl,
      const char * inarg,
      char *& inoutarg
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
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  virtual CORBA::Boolean target_is_a (
      const char * id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException));
  
  void result (char * result);

private:
  TAO_ServerRequestInfo_foo_all_str (
      const TAO_ServerRequestInfo_foo_all_str &
    );
  
  void operator= (
      const TAO_ServerRequestInfo_foo_all_str &
    );
  
private:
  POA_foo *_tao_impl;
  
  const char * inarg_;
  char *& inoutarg_;
  char * _result;
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/interceptors_ss.cpp:438

TAO_ServerRequestInfo_foo_all_str::TAO_ServerRequestInfo_foo_all_str (
    TAO_ServerRequest &_tao_server_request,
    TAO_Object_Adapter::Servant_Upcall *_tao_servant_upcall,
    POA_foo *tao_impl,
    const char * inarg,
    char *& inoutarg
    ACE_ENV_ARG_DECL_NOT_USED
  )
  : TAO_ServerRequestInfo (_tao_server_request, _tao_servant_upcall),
    _tao_impl (tao_impl),
    inarg_ (inarg),
    inoutarg_ (inoutarg)
{}

Dynamic::ParameterList *
TAO_ServerRequestInfo_foo_all_str::arguments (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the argument list on demand.
  Dynamic::ParameterList *parameter_list =
    TAO_RequestInfo_Util::make_parameter_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  Dynamic::ParameterList_var safe_parameter_list = parameter_list;
  parameter_list->length (2);
  CORBA::ULong len = 0;
  
  (*parameter_list)[len].argument <<= inarg_;
  (*parameter_list)[len].mode = CORBA::PARAM_IN;
  len++;
  
  (*parameter_list)[len].argument <<= inoutarg_;
  (*parameter_list)[len].mode = CORBA::PARAM_INOUT;
  len++;
  
  return safe_parameter_list._retn ();
}

Dynamic::ExceptionList *
TAO_ServerRequestInfo_foo_all_str::exceptions (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Generate the exception list on demand.
  Dynamic::ExceptionList *exception_list =
    TAO_RequestInfo_Util::make_exception_list (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  return exception_list;
}

CORBA::Any * 
TAO_ServerRequestInfo_foo_all_str::result (
    ACE_ENV_SINGLE_ARG_DECL
  )
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
TAO_ServerRequestInfo_foo_all_str::target_most_derived_interface (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return
    CORBA::string_dup (this->_tao_impl->_interface_repository_id ());
}

CORBA::Boolean
TAO_ServerRequestInfo_foo_all_str::target_is_a (
    const char * id
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->_tao_impl->_is_a (id ACE_ENV_ARG_PARAMETER);
}

void 
TAO_ServerRequestInfo_foo_all_str::result (char * result)
{
  // Update the result.
   this->_result = result;
}

#endif /* TAO_HAS_INTERCEPTORS */

///////////////////////////////////////////////////////////////////////
//            Strategized Proxy Broker Implementation
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/strategized_proxy_broker_ss.cpp:40

// Factory function Implementation.
_TAO_foo_Strategized_Proxy_Broker *_TAO_foo_Strategized_Proxy_Broker::the_TAO_foo_Strategized_Proxy_Broker (void)
{
  static _TAO_foo_Strategized_Proxy_Broker strategized_proxy_broker;
  return &strategized_proxy_broker;
}

_TAO_foo_Strategized_Proxy_Broker::_TAO_foo_Strategized_Proxy_Broker (void)
{
  for (int i = 0; i < TAO_Collocation_Strategies::CS_LAST; ++i)
    {
      this->proxy_cache_[i] = 0;
    }
}

_TAO_foo_Strategized_Proxy_Broker::~_TAO_foo_Strategized_Proxy_Broker (void)
{
  for (int i = 0; i < TAO_Collocation_Strategies::CS_LAST; ++i)
    {
      delete this->proxy_cache_[i];
      
      // Hack to prevent bug mentioned in 1204. Refer to 1204
      // for details..
      this->proxy_cache_[i] = 0;
    }
}

_TAO_foo_Proxy_Impl&
_TAO_foo_Strategized_Proxy_Broker::select_proxy (
    ::foo *object
    ACE_ENV_ARG_DECL
  )
{
  int strategy =
    TAO_ORB_Core::collocation_strategy (object ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (*this->proxy_cache_[strategy]);
  
  if (this->proxy_cache_[strategy] != 0)
    {
      return *this->proxy_cache_[strategy];
    }
  
  this->create_proxy (strategy ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (*this->proxy_cache_[strategy]);
  
  return *this->proxy_cache_[strategy];
}

void 
_TAO_foo_Strategized_Proxy_Broker::create_proxy (
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
              _TAO_foo_ThruPOA_Proxy_Impl,
              CORBA::NO_MEMORY ()
          );
          ACE_CHECK;
          break;
          
        case TAO_Collocation_Strategies::CS_REMOTE_STRATEGY:
        default:
          ACE_NEW_THROW_EX (
              this->proxy_cache_[strategy],
              ::_TAO_foo_Remote_Proxy_Impl,
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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ss.cpp:597

_TAO_foo_Proxy_Broker *
_TAO_foo_Proxy_Broker_Factory_function (CORBA::Object_ptr obj)
{
  ACE_UNUSED_ARG (obj);
  return ::_TAO_foo_Strategized_Proxy_Broker::the_TAO_foo_Strategized_Proxy_Broker();
}

int
_TAO_foo_Proxy_Broker_Factory_Initializer (size_t)
{
  _TAO_foo_Proxy_Broker_Factory_function_pointer = 
    _TAO_foo_Proxy_Broker_Factory_function;
  
  return 0;
}

static int _TAO_foo_Proxy_Broker_Stub_Factory_Initializer_Scarecrow = 
  _TAO_foo_Proxy_Broker_Factory_Initializer (ACE_reinterpret_cast (size_t, _TAO_foo_Proxy_Broker_Factory_Initializer));


///////////////////////////////////////////////////////////////////////
//                 ThruPOA Proxy  Implementation
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/thru_poa_proxy_impl_ss.cpp:37

_TAO_foo_ThruPOA_Proxy_Impl::_TAO_foo_ThruPOA_Proxy_Impl (void)
{}

// ThruPOA Implementation of the IDL interface methods

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/thru_poa_proxy_impl_ss.cpp:67

char * _TAO_foo_ThruPOA_Proxy_Impl::all_str (
    CORBA::Object *_collocated_tao_target_,
    const char * inarg,
    char *& inoutarg,
    CORBA::String_out outarg
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  CORBA::String_var _tao_retval;
  ACE_UNUSED_ARG (_tao_retval);
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      _collocated_tao_target_->_stubobj ()->servant_orb_var ()->orb_core ()
    );
  CORBA::Object_var forward_to;
  servant_upcall.prepare_for_upcall (
      _collocated_tao_target_->_stubobj ()->object_key (),
      "all_str",
      forward_to.out ()
      ACE_ENV_ARG_PARAMETER
    );
  ACE_CHECK_RETURN (_tao_retval._retn ());
  
  servant_upcall.pre_invoke_collocated_request (
      ACE_ENV_SINGLE_ARG_PARAMETER
    );
  ACE_CHECK_RETURN (_tao_retval._retn ());
  
  return ACE_reinterpret_cast (
      POA_foo_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:foo:1.0"
        )
    )->all_str (
        
        inarg,
        inoutarg,
        outarg
        ACE_ENV_ARG_PARAMETER
      );
}//
//           End ThruPOA Proxy Implementation
///////////////////////////////////////////////////////////////////////

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ss.cpp:98

POA_foo::POA_foo (void)
{
  this->optable_ = &tao_foo_optable;
}

POA_foo::POA_foo (const POA_foo& rhs)
  :  TAO_Abstract_ServantBase (rhs),
     TAO_ServantBase (rhs)
{}

POA_foo::~POA_foo (void)
{
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ss.cpp:100

void POA_foo::all_str_skel (
    TAO_ServerRequest &_tao_server_request,
    void *_tao_servant,
    void *_tao_servant_upcall
    ACE_ENV_ARG_DECL
  )
{
  TAO::Arg_Traits<CORBA::Char *>::skel_ret_val _tao_retval;
  TAO::Arg_Traits<CORBA::Char *>::in_sarg_val _tao_inarg;
  TAO::Arg_Traits<CORBA::Char *>::inout_sarg_val _tao_inoutarg;
  TAO::Arg_Traits<CORBA::Char *>::out_sarg_val _tao_outarg;

  TAO::Argument *_tao_signature [] = 
    { 
      &_tao_retval,
      &_tao_inarg,
      &_tao_inoutarg,
      &_tao_outarg
    };
  
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_foo *_tao_impl =
    ACE_static_cast (
        POA_foo *,
        _tao_servant
      );

  if (!(
      (_tao_retval.demarshal (_tao_in)) &&
      (_tao_inarg.demarshal (_tao_in)) &&
      (_tao_inoutarg.demarshal (_tao_in)) &&
      (_tao_outarg.demarshal (_tao_in))
      ))
      {
        
        TAO_InputCDR::throw_skel_exception (errno ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }
      

#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_Object_Adapter::Servant_Upcall *_tao_upcall =
    ACE_static_cast (TAO_Object_Adapter::Servant_Upcall *, _tao_servant_upcall);
  
  TAO_ServerRequestInterceptor_Adapter _tao_vfr (
      _tao_server_request.orb_core ()->server_request_interceptors (),
      _tao_server_request.interceptor_count ()
    );

  // @@@ (JP) This constructor will take _tao_signature eventually.
  CORBA::String_var inarg;
  CORBA::String_var inoutarg;
  TAO_ServerRequestInfo_foo_all_str _tao_ri (
      _tao_server_request,
      _tao_upcall,
      _tao_impl,
      
      inarg.in (),
      
      inoutarg.inout ()
      ACE_ENV_ARG_PARAMETER
    );
  
  ACE_TRY
    {
      {
        TAO_PICurrent_Guard _tao_pi_guard (_tao_ri.server_request (),
                                           1  /* Copy TSC to RSC */);
        
        _tao_vfr.receive_request (&_tao_ri ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;
        
        if (!_tao_vfr.location_forwarded ())
          {
            
#endif /* TAO_HAS_INTERCEPTORS */
            _tao_retval.arg () = 
            _tao_impl->all_str (
                
                _tao_inarg.arg (),
                
                _tao_inoutarg.arg (),
                
                _tao_outarg.arg ()
                ACE_ENV_ARG_PARAMETER
              );
            TAO_INTERCEPTOR_CHECK;

#if (TAO_HAS_INTERCEPTORS == 1)
            
          }
      }
      
      if (!_tao_vfr.location_forwarded ())
        {
          // @@@ (JP) This call will take the arg class eventually.
          char * _tao_retval_info = 0;
          _tao_ri.result (_tao_retval_info);

          _tao_ri.reply_status (PortableInterceptor::SUCCESSFUL);
          _tao_vfr.send_reply (&_tao_ri ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
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
        {
          ACE_RE_THROW;
        }
    }
  
# if defined (ACE_HAS_EXCEPTIONS) \
     && defined (ACE_HAS_BROKEN_UNEXPECTED_EXCEPTIONS)
  ACE_CATCHALL
    {
      CORBA::UNKNOWN ex;
      
      _tao_ri.exception (&ex);
      _tao_vfr.send_exception (
          &_tao_ri
          ACE_ENV_ARG_PARAMETER
        );
      ACE_TRY_CHECK;
      
      PortableInterceptor::ReplyStatus _tao_status =
        _tao_ri.reply_status (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (_tao_status == PortableInterceptor::SYSTEM_EXCEPTION)
        ACE_TRY_THROW (ex);
    }
# endif  /* ACE_HAS_EXCEPTIONS && ACE_HAS_BROKEN_UNEXPECTED_EXCEPTIONS */
  
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */
  
  _tao_server_request.init_reply ();
  
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(
      (_tao_retval.marshal (_tao_out)) &&
      (_tao_inarg.marshal (_tao_out)) &&
      (_tao_inoutarg.marshal (_tao_out)) &&
      (_tao_outarg.marshal (_tao_out))
      ))
      {
        
        TAO_OutputCDR::throw_skel_exception (errno ACE_ENV_ARG_PARAMETER);
        ACE_CHECK;
      }
      
  
  // In case _tao_servant_upcall is not used in this function
  ACE_UNUSED_ARG (_tao_servant_upcall);
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ss.cpp:164

void POA_foo::_is_a_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_foo *_tao_impl = (POA_foo *) _tao_servant;
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

void POA_foo::_non_existent_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_foo *_tao_impl = (POA_foo *) _tao_servant;
  CORBA::Boolean _tao_retval =
    _tao_impl->_non_existent (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_foo::_interface_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_servant,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_foo *_tao_impl = (POA_foo *) _tao_servant;
  CORBA::InterfaceDef_ptr _tao_retval = 0;
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

void POA_foo::_component_skel (
    TAO_ServerRequest &_tao_server_request, 
    void * _tao_object_reference,
    void * /* Servant_Upcall */
    ACE_ENV_ARG_DECL
  )
{
  POA_foo *_tao_impl = (POA_foo *) _tao_object_reference;
  CORBA::Object_var _tao_retval =
    _tao_impl->_get_component (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
  
  _tao_server_request.init_reply ();
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  
  if (!(_tao_out << _tao_retval._retn ()))
    ACE_THROW (CORBA::MARSHAL ());
}

CORBA::Boolean POA_foo::_is_a (
    const char* value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:foo:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:org.omg/CORBA/Object:1.0"
        )
     )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

void* POA_foo::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:foo:1.0") == 0)
    {
      return ACE_static_cast (POA_foo_ptr, this);
    }
  
  if (ACE_OS::strcmp (logical_type_id,
                      "IDL:omg.org/CORBA/Object:1.0") == 0)
    {
      return ACE_static_cast(PortableServer::Servant, this);
    }
  
  return 0;
}

const char* POA_foo::_interface_repository_id (void) const
{
  return "IDL:foo:1.0";
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ss.cpp:532

void POA_foo::_dispatch (
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

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ss.cpp:478

foo *
POA_foo::_this (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_Stub *stub = this->_create_stub (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);
  
  TAO_Stub_Auto_Ptr safe_stub (stub);
  CORBA::Object_ptr tmp = CORBA::Object::_nil ();
  
  if (stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ())
    {
      ACE_NEW_RETURN (
          tmp,
          CORBA::Object (
              stub,
              1,
              this
            ),
          0
        );
    }
  else
    {
      ACE_NEW_RETURN (
          tmp,
          CORBA::Object (
              stub,
              0,
              this
            ),
          0
        );
    }
  
  CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();
  return ::foo::_unchecked_narrow (obj.in ());
}
#endif /* ifndef */
