/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/PolicyC.h"
#include "tao/Operation_Table.h"
#include "tao/Server_Request.h"
#include "tao/NVList.h"
#include "tao/Stub.h"
#include "tao/POA_CORBA.h"
#include "tao/Typecode.h"
#include "tao/Object_Adapter.h"
#include "tao/ORB_Core.h"

class TAO_CORBA_Policy_Perfect_Hash_OpTable : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);
public:
 const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};
/* starting time is 6:18:45 */
/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: gperf -m -M -J -c -C -D -E -T -f 0 -F 0 -a -o -t -p -K opname_ -L C++ -Z TAO_CORBA_Policy_Perfect_Hash_OpTable -N lookup  */
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
      TOTAL_KEYWORDS = 5,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 16,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 16,
      HASH_VALUE_RANGE = 13,
      DUPLICATES = 0
    };

  static const class TAO_operation_db_entry  wordlist[] =
    {
      {"",0},{"",0},{"",0},{"",0},
      {"copy",  &POA_CORBA::Policy::copy_skel},
      {"_is_a",  &POA_CORBA::Policy::_is_a_skel},
      {"",0},
      {"destroy",       &POA_CORBA::Policy::destroy_skel},
      {"",0},{"",0},{"",0},{"",0},{"",0},
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
/* ending time is 6:18:45 */
static TAO_CORBA_Policy_Perfect_Hash_OpTable tao_CORBA_Policy_optable;

CORBA_Policy_ptr _TAO_collocation_POA_CORBA_Policy_Stub_Factory (
    CORBA::Object_ptr obj
  )
{
  TAO_Stub *stub = obj->_stubobj ();
  
  switch (stub->servant_orb_var ()->orb_core ()->get_collocation_strategy ())
    {
    case TAO_ORB_Core::THRU_POA:
      {
      CORBA_Policy_ptr retval = 0;
      ACE_NEW_RETURN (
          retval,
          POA_CORBA::_tao_thru_poa_collocated_CORBA_Policy (stub),
          0
        );
      return retval;
      }
    case TAO_ORB_Core::DIRECT:
      break;
    default:
      break;
    }
  return 0;
}

int _TAO_collocation_POA_CORBA_Policy_Stub_Factory_Initializer (long dummy)
{
  ACE_UNUSED_ARG (dummy);
  
  _TAO_collocation_CORBA_Policy_Stub_Factory_function_pointer = 
    _TAO_collocation_POA_CORBA_Policy_Stub_Factory;
  
  return 0;
}

static int _TAO_collocation_POA_CORBA_Policy_Stub_Factory_Initializer_Scarecrow = 
  _TAO_collocation_POA_CORBA_Policy_Stub_Factory_Initializer (ACE_reinterpret_cast (long, _TAO_collocation_POA_CORBA_Policy_Stub_Factory_Initializer));

// skeleton constructor
POA_CORBA::Policy::Policy (void)
{
  this->optable_ = &tao_CORBA_Policy_optable;
}

// copy ctor
POA_CORBA::Policy::Policy (const POA_CORBA::Policy& rhs)
  :   TAO_ServantBase (rhs)
{}

// skeleton destructor
POA_CORBA::Policy::~Policy (void)
{
}

void POA_CORBA::Policy::_get_policy_type_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference, 
    void * /* context */, 
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *)_tao_object_reference;

  CORBA::PolicyType _tao_retval = 0;
#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_ServerRequestInterceptor_Adapter
    _tao_vfr (_tao_server_request.orb ()->_get_server_interceptor (ACE_TRY_ENV));
  ACE_CHECK;
  PortableInterceptor::Cookies _tao_cookies;
  CORBA::NVList_var _tao_interceptor_args;
  CORBA::Object_var _tao_objref;
  if (_tao_vfr.valid ())
    {
      _tao_server_request.orb ()->create_list (0, _tao_interceptor_args.inout (), ACE_TRY_ENV);
      ACE_CHECK;

      _tao_objref = _tao_server_request.objref (ACE_TRY_ENV);
      ACE_CHECK;
    }

  ACE_TRY
    {
      _tao_vfr.preinvoke (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "_get_policy_type",
          _tao_server_request.service_info (),
          _tao_interceptor_args.inout (),
          _tao_cookies,
          ACE_TRY_ENV
        );
      TAO_INTERCEPTOR_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

      _tao_retval = _tao_impl->policy_type (
        ACE_TRY_ENV
      );

      TAO_INTERCEPTOR_CHECK;

#if (TAO_HAS_INTERCEPTORS == 1)
      _tao_vfr.postinvoke (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "_get_policy_type",
          _tao_server_request.service_info (),
          _tao_interceptor_args.inout (),
          _tao_cookies,
          ACE_TRY_ENV
        );
      TAO_INTERCEPTOR_CHECK;
    }
  ACE_CATCHANY
    {
      _tao_vfr.exception_occurred (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "_get_policy_type",
          _tao_cookies,
          ACE_TRY_ENV
        );
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << _tao_retval)
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::Policy::copy_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference, 
    void * /* context */, 
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *)_tao_object_reference;

  CORBA_Policy_var _tao_retval;
#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_ServerRequestInterceptor_Adapter
    _tao_vfr (_tao_server_request.orb ()->_get_server_interceptor (ACE_TRY_ENV));
  ACE_CHECK;
  PortableInterceptor::Cookies _tao_cookies;
  CORBA::NVList_var _tao_interceptor_args;
  CORBA::Object_var _tao_objref;
  if (_tao_vfr.valid ())
    {
      _tao_server_request.orb ()->create_list (0, _tao_interceptor_args.inout (), ACE_TRY_ENV);
      ACE_CHECK;

      _tao_objref = _tao_server_request.objref (ACE_TRY_ENV);
      ACE_CHECK;
    }

  ACE_TRY
    {
      _tao_vfr.preinvoke (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "copy",
          _tao_server_request.service_info (),
          _tao_interceptor_args.inout (),
          _tao_cookies,
          ACE_TRY_ENV
        );
      TAO_INTERCEPTOR_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

      _tao_retval = _tao_impl->copy (
        ACE_TRY_ENV
      );

      TAO_INTERCEPTOR_CHECK;

#if (TAO_HAS_INTERCEPTORS == 1)
      _tao_vfr.postinvoke (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "copy",
          _tao_server_request.service_info (),
          _tao_interceptor_args.inout (),
          _tao_cookies,
          ACE_TRY_ENV
        );
      TAO_INTERCEPTOR_CHECK;
    }
  ACE_CATCHANY
    {
      _tao_vfr.exception_occurred (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "copy",
          _tao_cookies,
          ACE_TRY_ENV
        );
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(
    (_tao_out << _tao_retval.in ())
  ))
    ACE_THROW (CORBA::MARSHAL () );

}

void POA_CORBA::Policy::destroy_skel (
    CORBA::ServerRequest &_tao_server_request,
    void *_tao_object_reference, 
    void * /* context */, 
    CORBA::Environment &ACE_TRY_ENV
)
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *)_tao_object_reference;

#if (TAO_HAS_INTERCEPTORS == 1)
  TAO_ServerRequestInterceptor_Adapter
    _tao_vfr (_tao_server_request.orb ()->_get_server_interceptor (ACE_TRY_ENV));
  ACE_CHECK;
  PortableInterceptor::Cookies _tao_cookies;
  CORBA::NVList_var _tao_interceptor_args;
  CORBA::Object_var _tao_objref;
  if (_tao_vfr.valid ())
    {
      _tao_server_request.orb ()->create_list (0, _tao_interceptor_args.inout (), ACE_TRY_ENV);
      ACE_CHECK;

      _tao_objref = _tao_server_request.objref (ACE_TRY_ENV);
      ACE_CHECK;
    }

  ACE_TRY
    {
      _tao_vfr.preinvoke (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "destroy",
          _tao_server_request.service_info (),
          _tao_interceptor_args.inout (),
          _tao_cookies,
          ACE_TRY_ENV
        );
      TAO_INTERCEPTOR_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

      _tao_impl->destroy (
        ACE_TRY_ENV
      );

      TAO_INTERCEPTOR_CHECK;

#if (TAO_HAS_INTERCEPTORS == 1)
      _tao_vfr.postinvoke (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "destroy",
          _tao_server_request.service_info (),
          _tao_interceptor_args.inout (),
          _tao_cookies,
          ACE_TRY_ENV
        );
      TAO_INTERCEPTOR_CHECK;
    }
  ACE_CATCHANY
    {
      _tao_vfr.exception_occurred (
          _tao_server_request.request_id (),
          1,
          _tao_objref.in (),
          "destroy",
          _tao_cookies,
          ACE_TRY_ENV
        );
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK;
#endif /* TAO_HAS_INTERCEPTORS */

  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  }

void POA_CORBA::Policy::_is_a_skel (
    CORBA::ServerRequest &_tao_server_request, 
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *) _tao_object_reference;
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;
  if (!(_tao_in >> value.out ()))
    ACE_THROW (CORBA::MARSHAL ());
  
  _tao_retval = _tao_impl->_is_a (value.in (), ACE_TRY_ENV);
  ACE_CHECK;
  
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_CORBA::Policy::_non_existent_skel (
    CORBA::ServerRequest &_tao_server_request, 
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_CORBA::Policy *_tao_impl = (POA_CORBA::Policy *) _tao_object_reference;
  CORBA::Boolean _tao_retval = _tao_impl->_non_existent (ACE_TRY_ENV);
  ACE_CHECK;
  
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!(_tao_out << CORBA::Any::from_boolean (_tao_retval)))
    ACE_THROW (CORBA::MARSHAL ());
}

CORBA::Boolean POA_CORBA::Policy::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA_Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_CORBA::Policy::_downcast (
    const char* logical_type_id
  )
{
if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA_Policy:1.0") == 0)
    return ACE_static_cast (POA_CORBA::Policy_ptr, this);
    if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

void POA_CORBA::Policy::_dispatch (CORBA::ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  this->synchronous_upcall_dispatch(req, context, this, ACE_TRY_ENV);
}

const char* POA_CORBA::Policy::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA_Policy:1.0";
}

CORBA_Policy*
POA_CORBA::Policy::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  if (stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ())
    switch (stub->servant_orb_var ()->orb_core ()->get_collocation_strategy ())
      {
      case TAO_ORB_Core::THRU_POA:
        {
          ::CORBA_Policy_ptr retval = 0;
          ACE_NEW_RETURN (
              retval,
              POA_CORBA::_tao_thru_poa_collocated_CORBA_Policy (stub),
              0
            );
          return retval;
        }
      case TAO_ORB_Core::DIRECT:
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      default:
        ACE_THROW_RETURN (CORBA::BAD_PARAM (), 0);
      }
  else
    {
      // stub->_incr_refcnt ();
      CORBA::Object_ptr tmp = CORBA::Object::_nil ();
      ACE_NEW_RETURN (tmp, CORBA::Object (stub), 0);
      CORBA::Object_var obj = tmp;
      return ::CORBA_Policy::_unchecked_narrow (obj.in ());
    }
}

POA_CORBA::_tao_thru_poa_collocated_CORBA_Policy::_tao_thru_poa_collocated_CORBA_Policy (
  TAO_Stub *stub
)
  :  CORBA_Object (stub, 0, 1)
{
}

CORBA::Boolean POA_CORBA::_tao_thru_poa_collocated_CORBA_Policy::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      *this->_stubobj ()->servant_orb_var ()->orb_core ()->object_adapter ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "_is_a",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/CORBA_Policy:1.0"
        )
    )->_is_a (logical_type_id, ACE_TRY_ENV);
}


CORBA::Boolean POA_CORBA::_tao_thru_poa_collocated_CORBA_Policy::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      *this->_stubobj ()->servant_orb_var ()->orb_core ()->object_adapter ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "_non_existent",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/CORBA_Policy:1.0"
        )
    )->_non_existent (ACE_TRY_ENV);
}


CORBA::PolicyType POA_CORBA::_tao_thru_poa_collocated_CORBA_Policy::policy_type  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  CORBA::PolicyType _tao_retval = 0;
  ACE_UNUSED_ARG (_tao_retval);
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      *this->_stubobj ()->servant_orb_var ()->orb_core ()->object_adapter ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "policy_type",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN  (_tao_retval);
  return ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/CORBA_Policy:1.0"
        )
    )->policy_type (
      ACE_TRY_ENV
    );

}

CORBA_Policy_ptr POA_CORBA::_tao_thru_poa_collocated_CORBA_Policy::copy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  CORBA_Policy_var _tao_retval;
  ACE_UNUSED_ARG (_tao_retval);
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      *this->_stubobj ()->servant_orb_var ()->orb_core ()->object_adapter ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "copy",
      ACE_TRY_ENV
    );
  ACE_CHECK_RETURN (0);
  return ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/CORBA_Policy:1.0"
        )
    )->copy (
      ACE_TRY_ENV
    );

}

void POA_CORBA::_tao_thru_poa_collocated_CORBA_Policy::destroy  (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  TAO_Object_Adapter::Servant_Upcall servant_upcall (
      *this->_stubobj ()->servant_orb_var ()->orb_core ()->object_adapter ()
    );
  servant_upcall.prepare_for_upcall (
      this->_object_key (),
      "destroy",
      ACE_TRY_ENV
    );
  ACE_CHECK;
  ACE_reinterpret_cast (
      POA_CORBA::Policy_ptr,
      servant_upcall.servant ()->_downcast (
          "IDL:omg.org/CORBA_Policy:1.0"
        )
    )->destroy (
      ACE_TRY_ENV
    );
  return;
}
