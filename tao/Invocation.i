// This may look like C, but it's really -*- C++ -*-
//
// $Id$
//

ACE_INLINE void
TAO_GIOP_Invocation::put_param (CORBA::TypeCode_ptr tc,
                                void *value,
                                CORBA::Environment &TAO_IN_ENV)
{
  (void) this->out_stream_.encode (tc, value, 0, TAO_IN_ENV);
}

ACE_INLINE TAO_OutputCDR &
TAO_GIOP_Invocation::out_stream (void)
{
  return this->out_stream_;
}

// ****************************************************************

ACE_INLINE
TAO_GIOP_Twoway_Invocation::
TAO_GIOP_Twoway_Invocation (IIOP_Object *data,
			    const char *operation,
			    TAO_ORB_Core *orb_core)
  : TAO_GIOP_Invocation (data, operation, orb_core),
    inp_stream_ (orb_core->create_input_cdr_data_block (CDR::DEFAULT_BUFSIZE),
                 TAO_ENCAP_BYTE_ORDER,
                 TAO_Marshal::DEFAULT_MARSHAL_FACTORY)
{
}

ACE_INLINE void
TAO_GIOP_Twoway_Invocation::start (CORBA::Environment &TAO_IN_ENV)
{
  TAO_GIOP_Invocation::start (1, TAO_GIOP::Request, TAO_IN_ENV);
}

ACE_INLINE void
TAO_GIOP_Twoway_Invocation::get_value (CORBA::TypeCode_ptr tc,
                                void *value,
                                CORBA::Environment &TAO_IN_ENV)
{
  (void) this->inp_stream_.decode (tc, value, 0, TAO_IN_ENV);
}

ACE_INLINE TAO_InputCDR &
TAO_GIOP_Twoway_Invocation::inp_stream (void)
{
  return this->inp_stream_;
}

// ****************************************************************

ACE_INLINE
TAO_GIOP_Oneway_Invocation::
TAO_GIOP_Oneway_Invocation (IIOP_Object *data,
			    const char *operation,
			    TAO_ORB_Core *orb_core)
  : TAO_GIOP_Invocation (data, operation, orb_core)
{
}

ACE_INLINE void
TAO_GIOP_Oneway_Invocation::start (CORBA::Environment &TAO_IN_ENV)
{
  TAO_GIOP_Invocation::start (0, TAO_GIOP::Request, TAO_IN_ENV);
}

ACE_INLINE TAO_GIOP_ReplyStatusType
TAO_GIOP_Oneway_Invocation::invoke (CORBA::Environment &TAO_IN_ENV)
{
  return TAO_GIOP_Invocation::invoke (0, TAO_IN_ENV);
}

// ****************************************************************

ACE_INLINE
TAO_GIOP_Locate_Request_Invocation::
TAO_GIOP_Locate_Request_Invocation (IIOP_Object *data,
				    TAO_ORB_Core *orb_core)
  : TAO_GIOP_Invocation (data, 0, orb_core),
    inp_stream_ (orb_core->create_input_cdr_data_block (CDR::DEFAULT_BUFSIZE))
{
}

ACE_INLINE void
TAO_GIOP_Locate_Request_Invocation::start (CORBA::Environment &TAO_IN_ENV)
{
  TAO_GIOP_Invocation::start (1, TAO_GIOP::LocateRequest, TAO_IN_ENV);
}
