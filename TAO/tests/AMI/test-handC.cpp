$Id$
/* -*- C++ -*- */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "testC.h"

#if !defined (__ACE_INLINE__)
#include "testC.i"
#endif /* !defined INLINE */

Simple_Server_ptr Simple_Server::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &env
  )
{
  if (CORBA::is_nil (obj))
    return Simple_Server::_nil ();
  if (!obj->_is_a ("IDL:Simple_Server:1.0", env))
    return Simple_Server::_nil ();
  return Simple_Server::_unchecked_narrow (obj, env);
}

Simple_Server_ptr Simple_Server::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  ACE_UNUSED_ARG (ACE_TRY_ENV);
  if (CORBA::is_nil (obj))
    return Simple_Server::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/Object:1.0");
  if (servant != 0)
    {
      Simple_Server_ptr retv = ACE_reinterpret_cast (
          Simple_Server_ptr,
          ACE_reinterpret_cast (
              PortableServer::Servant,
              servant
            )
          ->_create_collocated_objref (
              "IDL:Simple_Server:1.0",
              TAO_ORB_Core::ORB_CONTROL,
              stub
            )
        );
      if (retv != 0)
        return retv;
    }
  return new Simple_Server(stub);
}

Simple_Server_ptr 
Simple_Server::_duplicate (Simple_Server_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  return obj;
}

CORBA::Long Simple_Server::get_number (
    CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  
  CORBA::Long _tao_retval = 0;

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);

  
  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "get_number",
      istub->orb_core ()
    );
  

  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
    ACE_CHECK_RETURN (_tao_retval);

    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);

    }
    break;
    
  }
  TAO_InputCDR &_tao_in = _tao_call.inp_stream ();
  if (!(
        (_tao_in >> _tao_retval)
    ))
    ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);
  return _tao_retval;
}

void
Simple_Server::sendc_get_number (
    AMI_Simple_Server_Handler_ptr _tao_ami_handler,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  
  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW (CORBA::INV_OBJREF ());

  
  TAO_GIOP_Twoway_Asynch_Invocation _tao_call (
      istub,
      "get_number",
      istub->orb_core (),
      &AMI_Simple_Server_Handler::get_number_skel,
      _tao_ami_handler
    );
  

  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
    ACE_CHECK;
    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK;

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES));

    }
    break;
    
  }
  return;
}

CORBA::Boolean Simple_Server::_is_a (const CORBA::Char *value, CORBA::Environment &env)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:Simple_Server:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, env);
}

const char* Simple_Server::_interface_repository_id (void) const
{
  return "IDL:Simple_Server:1.0";
}

static const CORBA::Long _oc_Simple_Server[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  22, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x53696d70), ACE_NTOHL (0x6c655f53), ACE_NTOHL (0x65727665), ACE_NTOHL (0x723a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:Simple_Server:1.0
  14, ACE_NTOHL (0x53696d70), ACE_NTOHL (0x6c655f53), ACE_NTOHL (0x65727665), ACE_NTOHL (0x72000000),  // name = Simple_Server
};
static CORBA::TypeCode _tc_TAO_tc_Simple_Server (CORBA::tk_objref, sizeof (_oc_Simple_Server), (char *) &_oc_Simple_Server, 0, sizeof (Simple_Server));
CORBA::TypeCode_ptr _tc_Simple_Server = &_tc_TAO_tc_Simple_Server;

AMI_Simple_Server_Handler_ptr AMI_Simple_Server_Handler::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &env
  )
{
  if (CORBA::is_nil (obj))
    return AMI_Simple_Server_Handler::_nil ();
  if (!obj->_is_a ("IDL:AMI_Simple_Server_Handler:1.0", env))
    return AMI_Simple_Server_Handler::_nil ();
  return AMI_Simple_Server_Handler::_unchecked_narrow (obj, env);
}

AMI_Simple_Server_Handler_ptr AMI_Simple_Server_Handler::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  ACE_UNUSED_ARG (ACE_TRY_ENV);
  if (CORBA::is_nil (obj))
    return AMI_Simple_Server_Handler::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/Object:1.0");
  if (servant != 0)
    {
      AMI_Simple_Server_Handler_ptr retv = ACE_reinterpret_cast (
          AMI_Simple_Server_Handler_ptr,
          ACE_reinterpret_cast (
              PortableServer::Servant,
              servant
            )
          ->_create_collocated_objref (
              "IDL:AMI_Simple_Server_Handler:1.0",
              TAO_ORB_Core::ORB_CONTROL,
              stub
            )
        );
      if (retv != 0)
        return retv;
    }
  return new AMI_Simple_Server_Handler(stub);
}

AMI_Simple_Server_Handler_ptr 
AMI_Simple_Server_Handler::_duplicate (AMI_Simple_Server_Handler_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  return obj;
}

void 
AMI_Simple_Server_Handler::get_number (
    CORBA::Long _tao_ami_result, 
        CORBA::Environment &ACE_TRY_ENV
  )
  ACE_THROW_SPEC ((CORBA::SystemException))
{
    

    TAO_Stub *istub = this->_stubobj ();
    if (istub == 0)
      ACE_THROW (CORBA::INTERNAL ());
    
        TAO_GIOP_Twoway_Invocation _tao_call (
        istub,
        "get_number",
        istub->orb_core ()
      );
    

    for (;;)
    {
      ACE_TRY_ENV.clear ();
      _tao_call.start (ACE_TRY_ENV);
ACE_CHECK;
      TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
      if (!(
(_tao_out << _tao_ami_result)
            
        ))
        ACE_THROW (CORBA::MARSHAL ());
      int _invoke_status =
        _tao_call.invoke (0, 0, ACE_TRY_ENV);
      ACE_CHECK;
      if (_invoke_status == TAO_INVOKE_RESTART)
        continue;
      // if (_invoke_status == TAO_INVOKE_EXCEPTION)
        // cannot happen
      if (_invoke_status != TAO_INVOKE_OK)
      {
        ACE_THROW (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES));
      }
      break;
      
    }
    
  }

void
AMI_Simple_Server_Handler::get_number_skel (TAO_InputCDR &_tao_reply_cdr,
                                            Messaging::ReplyHandler_ptr _tao_reply_handler,
                                            CORBA::Environment &ACE_TRY_ENV)
{
  // Retrive Reply Handler object.
  AMI_Simple_Server_Handler_var _tao_reply_handler_object = 
    AMI_Simple_Server_Handler::_narrow (_tao_reply_handler,
                                        ACE_TRY_ENV);
  ACE_CHECK_ENV;

  // @@ Error handling.
  
  // Demarshall all the arguments.
  CORBA::Long l;
  _tao_reply_cdr >> l;
  
  // Invoke the call back method.
  _tao_reply_handler_object->get_number (l, ACE_TRY_ENV);
}

  CORBA::Boolean AMI_Simple_Server_Handler::_is_a (const CORBA::Char *value, CORBA::Environment &env)
  {
    if (
(!ACE_OS::strcmp ((char *)value, "IDL:AMI_Simple_Server_Handler:1.0")) ||
      (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/Messaging/ReplyHandler:1.0")) ||
            (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
    else
      return this->CORBA_Object::_is_a (value, env);
  }

  const char* AMI_Simple_Server_Handler::_interface_repository_id (void) const
  {
    return "IDL:AMI_Simple_Server_Handler:1.0";
  }

  static const CORBA::Long _oc_AMI_Simple_Server_Handler[] =
  {
    TAO_ENCAP_BYTE_ORDER, // byte order
    34, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x414d495f), ACE_NTOHL (0x53696d70), ACE_NTOHL (0x6c655f53), ACE_NTOHL (0x65727665), ACE_NTOHL (0x725f4861), ACE_NTOHL (0x6e646c65), ACE_NTOHL (0x723a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:AMI_Simple_Server_Handler:1.0
    26, ACE_NTOHL (0x414d495f), ACE_NTOHL (0x53696d70), ACE_NTOHL (0x6c655f53), ACE_NTOHL (0x65727665), ACE_NTOHL (0x725f4861), ACE_NTOHL (0x6e646c65), ACE_NTOHL (0x72000000),  // name = AMI_Simple_Server_Handler
};
  static CORBA::TypeCode _tc_TAO_tc_AMI_Simple_Server_Handler (CORBA::tk_objref, sizeof (_oc_AMI_Simple_Server_Handler), (char *) &_oc_AMI_Simple_Server_Handler, 0, sizeof (AMI_Simple_Server_Handler));
  CORBA::TypeCode_ptr _tc_AMI_Simple_Server_Handler = &_tc_TAO_tc_AMI_Simple_Server_Handler;

  void operator<<= (CORBA::Any &_tao_any, Simple_Server_ptr _tao_elem)
  {
    CORBA::Object_ptr *_tao_obj_ptr = 0;
    ACE_TRY_NEW_ENV
    {
      ACE_NEW (_tao_obj_ptr, CORBA::Object_ptr);
      *_tao_obj_ptr = Simple_Server::_duplicate (_tao_elem);
      _tao_any.replace (_tc_Simple_Server, _tao_obj_ptr, 1, ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
    ACE_CATCHANY
    {
      delete _tao_obj_ptr;
    }
    ACE_ENDTRY;
  }

  CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, Simple_Server_ptr &_tao_elem)
  {
    CORBA::Object_ptr *tmp = 0;
    ACE_TRY_NEW_ENV
    {
      _tao_elem = Simple_Server::_nil ();
      CORBA::TypeCode_var type = _tao_any.type ();
      if (!type->equal (_tc_Simple_Server, ACE_TRY_ENV)) return 0; // not equal
      ACE_TRY_CHECK;
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      CORBA::Object_var _tao_obj_var;
      ACE_NEW_RETURN (tmp, CORBA::Object_ptr, 0);
      if (stream.decode (_tc_Simple_Server, &_tao_obj_var.out (), 0, ACE_TRY_ENV)
         == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        _tao_elem = Simple_Server::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
        ACE_TRY_CHECK;
        *tmp = (CORBA::Object_ptr) _tao_elem;  // any owns the object
        ((CORBA::Any *)&_tao_any)->replace (_tc_Simple_Server, tmp, 1, ACE_TRY_ENV);
        ACE_TRY_CHECK;
        return 1;
      }
      // failure
    }
    ACE_CATCHANY
    {
      delete tmp;
      return 0;
    }
    ACE_ENDTRY;
    return 0;
  }

// skeleton constructor
POA_AMI_Simple_Server_Handler::POA_AMI_Simple_Server_Handler (void)
{
}

// copy ctor
POA_AMI_Simple_Server_Handler::POA_AMI_Simple_Server_Handler (const POA_AMI_Simple_Server_Handler& rhs)
  :   TAO_ServantBase (rhs)
{}

// skeleton destructor
POA_AMI_Simple_Server_Handler::~POA_AMI_Simple_Server_Handler (void)
{
}

void POA_AMI_Simple_Server_Handler::_is_a_skel (
    CORBA::ServerRequest &_tao_server_request, 
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_AMI_Simple_Server_Handler *_tao_impl = (POA_AMI_Simple_Server_Handler *) _tao_object_reference;
  CORBA::Boolean _tao_retval = 0;
  CORBA::String_var value;
  if (!((_tao_in >> value.out ())))
    ACE_THROW (CORBA::MARSHAL ());
  
  _tao_retval = _tao_impl->_is_a (value.in (), ACE_TRY_ENV);
  ACE_CHECK;
  
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!((_tao_out << CORBA::Any::from_boolean (_tao_retval))))
    ACE_THROW (CORBA::MARSHAL ());
}

void POA_AMI_Simple_Server_Handler::_non_existent_skel (
    CORBA::ServerRequest &_tao_server_request, 
    void * _tao_object_reference,
    void * /* context */,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  POA_AMI_Simple_Server_Handler *_tao_impl = (POA_AMI_Simple_Server_Handler *) _tao_object_reference;
  CORBA::Boolean _tao_retval = _tao_impl->_non_existent (ACE_TRY_ENV);
  ACE_CHECK;
  
  _tao_server_request.init_reply (ACE_TRY_ENV);
  ACE_CHECK;
  TAO_OutputCDR &_tao_out = _tao_server_request.outgoing ();
  if (!((_tao_out << CORBA::Any::from_boolean (_tao_retval))))
    ACE_THROW (CORBA::MARSHAL ());
}

CORBA::Boolean POA_AMI_Simple_Server_Handler::_is_a (
    const char* value,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:AMI_Simple_Server_Handler:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (ACE_TRY_ENV))))
      return 1;
    else
      return 0;
}

void* POA_AMI_Simple_Server_Handler::_downcast (
    const char* logical_type_id
  )
{
  if (ACE_OS::strcmp (logical_type_id, "IDL:AMI_Simple_Server_Handler:1.0") == 0)
    return ACE_static_cast (POA_AMI_Simple_Server_Handler_ptr, this);
  if (ACE_OS::strcmp (logical_type_id, "IDL:omg.org/CORBA/Object:1.0") == 0)
    return ACE_static_cast(PortableServer::Servant, this);
  return 0;
}

void POA_AMI_Simple_Server_Handler::_dispatch (CORBA::ServerRequest &req, void *context, CORBA::Environment &ACE_TRY_ENV)
{
  TAO_Skeleton skel; // pointer to skeleton for operation
  const char *opname = req.operation (); // retrieve operation name
  // find the skeleton corresponding to this opname
  if (this->_find (opname, skel, req.operation_length ()) == -1)
  {
    ACE_ERROR ((LM_ERROR, "Bad operation <%s>\n", opname));
    ACE_THROW (CORBA_BAD_OPERATION ());
  }
  else
    skel (req, this, context, ACE_TRY_ENV);
}

const char* POA_AMI_Simple_Server_Handler::_interface_repository_id (void) const
{
  return "IDL:AMI_Simple_Server_Handler:1.0";
}


AMI_Simple_Server_Handler*
POA_AMI_Simple_Server_Handler::_this (CORBA_Environment &ACE_TRY_ENV)
{
  TAO_Stub *stub = this->_create_stub (ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);
  return new _tao_collocated_AMI_Simple_Server_Handler (this, stub);
}

void*
POA_AMI_Simple_Server_Handler::_create_collocated_objref (const char* repository_id, CORBA::ULong type, TAO_Stub *stub)
{
  if (!ACE_OS::strcmp ("IDL:AMI_Simple_Server_Handler:1.0", repository_id))
    return ACE_static_cast (
         AMI_Simple_Server_Handler_ptr,
        new _tao_collocated_AMI_Simple_Server_Handler (this, stub)
      );
  return 0;
}

void
POA_AMI_Simple_Server_Handler::get_number (CORBA::Long l, CORBA::Environment &)
{
  ACE_DEBUG ((LM_DEBUG, "%N:%l:%d\n", l));
}

void
POA_AMI_Simple_Server_Handler::get_number_skel (CORBA::ServerRequest &_tao_server_request,
                                                void *_tao_object_reference,
                                                void *_tao_context, 
                                                CORBA::Environment &ACE_TRY_ENV)
{
  TAO_InputCDR &_tao_in = _tao_server_request.incoming ();
  POA_AMI_Simple_Server_Handler *_tao_impl = (POA_AMI_Simple_Server_Handler *)_tao_object_reference;

  CORBA::Long l;
  if (!(
    (_tao_in >> l)
  ))
    ACE_THROW (CORBA::MARSHAL () );

  _tao_impl->get_number (
    l);
  ACE_CHECK;
  _tao_server_request.init_reply (ACE_TRY_ENV);
}

// *********************************************************************

_tao_collocated_AMI_Simple_Server_Handler::_tao_collocated_AMI_Simple_Server_Handler (
    POA_AMI_Simple_Server_Handler_ptr  servant,
    TAO_Stub *stub
  )
  : AMI_Simple_Server_Handler (),
    CORBA_Object (stub, servant, 1),
    servant_ (servant)
{
}

CORBA::Boolean _tao_collocated_AMI_Simple_Server_Handler::_is_a(
    const CORBA::Char *logical_type_id,
    CORBA_Environment &ACE_TRY_ENV
  )

{
  if (this->_stubobj ()->orb_core ()->get_collocation_strategy () == TAO_ORB_Core::THRU_POA)
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
          POA_AMI_Simple_Server_Handler_ptr,
          servant_upcall.servant ()->_downcast (
              "IDL:AMI_Simple_Server_Handler:1.0"
            )
        )->_is_a (logical_type_id, ACE_TRY_ENV);
    }
  return this->servant_->_is_a (logical_type_id, ACE_TRY_ENV);
}


POA_AMI_Simple_Server_Handler_ptr _tao_collocated_AMI_Simple_Server_Handler::_get_servant (void) const
{
  return this->servant_;
}

CORBA::Boolean _tao_collocated_AMI_Simple_Server_Handler::_non_existent(
    CORBA_Environment &ACE_TRY_ENV
  )

{
  if (this->_stubobj ()->orb_core ()->get_collocation_strategy () == TAO_ORB_Core::THRU_POA)
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
          POA_AMI_Simple_Server_Handler_ptr,
          servant_upcall.servant ()->_downcast (
              "IDL:AMI_Simple_Server_Handler:1.0"
            )
        )->_non_existent (ACE_TRY_ENV);
    }
  return this->servant_->_non_existent (ACE_TRY_ENV);
}

void
_tao_collocated_AMI_Simple_Server_Handler::get_number  (CORBA::Long l, CORBA::Environment &)
{
  ACE_DECLARE_NEW_CORBA_ENV;

  if (this->_stubobj ()->orb_core ()->get_collocation_strategy () == TAO_ORB_Core::THRU_POA)
    {
      TAO_Object_Adapter::Servant_Upcall servant_upcall (
          *this->_stubobj ()->servant_orb_var ()->orb_core ()->object_adapter ()
        );
      servant_upcall.prepare_for_upcall (
          this->_object_key (),
          "get_number",
          ACE_TRY_ENV
        );
      ACE_CHECK;
      ACE_reinterpret_cast (
          POA_AMI_Simple_Server_Handler_ptr,
          servant_upcall.servant ()->_downcast (
              "IDL:AMI_Simple_Server_Handler:1.0"
            )
        )->get_number (
          l);
      return;
    }
  this->servant_->get_number (
      l );

}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
    template class TAO_Object_Field_T<Simple_Server>;
    template class TAO_Object_Field_T<AMI_Simple_Server_Handler>;
  #elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
  #  pragma instantiate TAO_Object_Field_T<Simple_Server>
  #  pragma instantiate TAO_Object_Field_T<AMI_Simple_Server_Handler>
  #endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

