// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "RtecEventCommC.h"

#if !defined (__ACE_INLINE__)
#include "RtecEventCommC.i"
#endif // !defined INLINE

static const CORBA::Long _oc_RtecEventComm_Disconnected[] =
{
  0, // byte order
  35, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4469, 0x73636f6e, 0x6e656374, 0x65643a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/Disconnected:1.0
  13, 0x44697363, 0x6f6e6e65, 0x63746564, 0x0,  // name = Disconnected
  0, // member count
};
static CORBA::TypeCode _tc__tc_RtecEventComm_Disconnected (CORBA::tk_struct, sizeof (_oc_RtecEventComm_Disconnected), (unsigned char *) &_oc_RtecEventComm_Disconnected, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_Disconnected = &_tc__tc_RtecEventComm_Disconnected;

static const CORBA::Long _oc_RtecEventComm_EventData[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7444, 0x6174613a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventData:1.0
  10, 0x4576656e, 0x74446174, 0x61000000,  // name = EventData
  2, // member count
    2, 0x78000000,  // name = x
    CORBA::tk_long,

    2, 0x79000000,  // name = y
    CORBA::tk_long,

};
static CORBA::TypeCode _tc__tc_RtecEventComm_EventData (CORBA::tk_struct, sizeof (_oc_RtecEventComm_EventData), (unsigned char *) &_oc_RtecEventComm_EventData, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_EventData = &_tc__tc_RtecEventComm_EventData;

static const CORBA::Long _oc_RtecEventComm_EventSourceID[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  36, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7453, 0x6f757263, 0x6549443a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventSourceID:1.0
  14, 0x4576656e, 0x74536f75, 0x72636549, 0x44000000,  // name = EventSourceID
  CORBA::tk_long,

};
static CORBA::TypeCode _tc__tc_RtecEventComm_EventSourceID (CORBA::tk_alias, sizeof (_oc_RtecEventComm_EventSourceID), (unsigned char *) &_oc_RtecEventComm_EventSourceID, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_EventSourceID = &_tc__tc_RtecEventComm_EventSourceID;

static const CORBA::Long _oc_RtecEventComm_Time[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  27, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5469, 0x6d653a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/Time:1.0
  5, 0x54696d65, 0x0,  // name = Time
  CORBA::tk_long,

};
static CORBA::TypeCode _tc__tc_RtecEventComm_Time (CORBA::tk_alias, sizeof (_oc_RtecEventComm_Time), (unsigned char *) &_oc_RtecEventComm_Time, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_Time = &_tc__tc_RtecEventComm_Time;

static const CORBA::Long _oc_RtecEventComm_EventType[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7454, 0x7970653a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventType:1.0
  10, 0x4576656e, 0x74547970, 0x65000000,  // name = EventType
  CORBA::tk_long,

};
static CORBA::TypeCode _tc__tc_RtecEventComm_EventType (CORBA::tk_alias, sizeof (_oc_RtecEventComm_EventType), (unsigned char *) &_oc_RtecEventComm_EventType, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_EventType = &_tc__tc_RtecEventComm_EventType;

static const CORBA::Long _oc_RtecEventComm_Event[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  28, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e743a, 0x312e3000,  // repository ID = IDL:RtecEventComm/Event:1.0
  6, 0x4576656e, 0x74000000,  // name = Event
  4, // member count
    8, 0x736f7572, 0x63655f00,  // name = source_
    CORBA::tk_alias, // typecode kind for typedefs
    68, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      36, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7453, 0x6f757263, 0x6549443a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventSourceID:1.0
      14, 0x4576656e, 0x74536f75, 0x72636549, 0x44000000,  // name = EventSourceID
      CORBA::tk_long,

    6, 0x74797065, 0x5f000000,  // name = type_
    CORBA::tk_alias, // typecode kind for typedefs
    60, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7454, 0x7970653a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventType:1.0
      10, 0x4576656e, 0x74547970, 0x65000000,  // name = EventType
      CORBA::tk_long,

    6, 0x74696d65, 0x5f000000,  // name = time_
    CORBA::tk_alias, // typecode kind for typedefs
    52, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      27, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5469, 0x6d653a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/Time:1.0
      5, 0x54696d65, 0x0,  // name = Time
      CORBA::tk_long,

    6, 0x64617461, 0x5f000000,  // name = data_
    CORBA::tk_struct, // typecode kind
    84, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7444, 0x6174613a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventData:1.0
      10, 0x4576656e, 0x74446174, 0x61000000,  // name = EventData
      2, // member count
        2, 0x78000000,  // name = x
        CORBA::tk_long,

        2, 0x79000000,  // name = y
        CORBA::tk_long,

    };
static CORBA::TypeCode _tc__tc_RtecEventComm_Event (CORBA::tk_struct, sizeof (_oc_RtecEventComm_Event), (unsigned char *) &_oc_RtecEventComm_Event, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_Event = &_tc__tc_RtecEventComm_Event;

// *************************************************************
// class RtecEventComm::_tao__seq_EventSet
// *************************************************************

// copy constructor
RtecEventComm::_tao__seq_EventSet::_tao__seq_EventSet (const RtecEventComm::_tao__seq_EventSet &seq)
	: maximum_ (seq.maximum_),
	  length_ (seq.length_),
	  buffer_ (RtecEventComm::_tao__seq_EventSet::allocbuf (seq.maximum_)),
	  release_ (1) // we always own it
{
  for (CORBA::ULong i=0; i < seq.length_; i++)
  	this->buffer_[i] = seq.buffer_[i];
}

// destructor
RtecEventComm::_tao__seq_EventSet::~_tao__seq_EventSet (void)
{
  if (this->release_) // we own the buffer
  {
    RtecEventComm::_tao__seq_EventSet::freebuf (this->buffer_);
  }
}

// assignment operator
RtecEventComm::_tao__seq_EventSet& 
RtecEventComm::_tao__seq_EventSet::operator= (const RtecEventComm::_tao__seq_EventSet &seq)
{
  if (this == &seq) return *this;
  if (this->release_)
  {
    RtecEventComm::_tao__seq_EventSet::freebuf (this->buffer_);
  }
  this->length_ = seq.length_;
  this->maximum_ = seq.maximum_;
  this->buffer_ = RtecEventComm::_tao__seq_EventSet::allocbuf (seq.maximum_),
  this->release_ =1; // we always own it
  for (CORBA::ULong i=0; i < seq.length_; i++)
  	this->buffer_[i] = seq.buffer_[i];
  return *this;
}

void
RtecEventComm::_tao__seq_EventSet::length (CORBA::ULong length)
{
  if (length > this->maximum_)
  {
    RtecEventComm::Event *tmp = RtecEventComm::_tao__seq_EventSet::allocbuf (length);
    if (tmp == 0)
          return;
    for (int i = 0; i < this->length_; ++i)
    {
      tmp[i] = this->buffer_[i];
    }
    if (this->release_)
      RtecEventComm::_tao__seq_EventSet::freebuf (this->buffer_);
    this->buffer_ = tmp;
    this->release_ = 1;

this->maximum_ = length;
  }
    this->length_ = length;
}

static const CORBA::Long _oc_RtecEventComm__tao__seq_EventSet[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
  396, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    28, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e743a, 0x312e3000,  // repository ID = IDL:RtecEventComm/Event:1.0
    6, 0x4576656e, 0x74000000,  // name = Event
    4, // member count
      8, 0x736f7572, 0x63655f00,  // name = source_
      CORBA::tk_alias, // typecode kind for typedefs
      68, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        36, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7453, 0x6f757263, 0x6549443a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventSourceID:1.0
        14, 0x4576656e, 0x74536f75, 0x72636549, 0x44000000,  // name = EventSourceID
        CORBA::tk_long,

      6, 0x74797065, 0x5f000000,  // name = type_
      CORBA::tk_alias, // typecode kind for typedefs
      60, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7454, 0x7970653a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventType:1.0
        10, 0x4576656e, 0x74547970, 0x65000000,  // name = EventType
        CORBA::tk_long,

      6, 0x74696d65, 0x5f000000,  // name = time_
      CORBA::tk_alias, // typecode kind for typedefs
      52, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        27, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5469, 0x6d653a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/Time:1.0
        5, 0x54696d65, 0x0,  // name = Time
        CORBA::tk_long,

      6, 0x64617461, 0x5f000000,  // name = data_
      CORBA::tk_struct, // typecode kind
      84, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7444, 0x6174613a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventData:1.0
        10, 0x4576656e, 0x74446174, 0x61000000,  // name = EventData
        2, // member count
          2, 0x78000000,  // name = x
          CORBA::tk_long,

          2, 0x79000000,  // name = y
          CORBA::tk_long,

          0,
};
static CORBA::TypeCode _tc__tc_RtecEventComm__tao__seq_EventSet (CORBA::tk_sequence, sizeof (_oc_RtecEventComm__tao__seq_EventSet), (unsigned char *) &_oc_RtecEventComm__tao__seq_EventSet, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc__tao__seq_EventSet = &_tc__tc_RtecEventComm__tao__seq_EventSet;

static const CORBA::Long _oc_RtecEventComm_EventSet[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  31, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7453, 0x65743a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/EventSet:1.0
  9, 0x4576656e, 0x74536574, 0x0,  // name = EventSet
  CORBA::tk_sequence, // typecode kind
  420, // encapsulation length
  TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
  396, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    28, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e743a, 0x312e3000,  // repository ID = IDL:RtecEventComm/Event:1.0
    6, 0x4576656e, 0x74000000,  // name = Event
    4, // member count
      8, 0x736f7572, 0x63655f00,  // name = source_
      CORBA::tk_alias, // typecode kind for typedefs
      68, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        36, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7453, 0x6f757263, 0x6549443a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventSourceID:1.0
        14, 0x4576656e, 0x74536f75, 0x72636549, 0x44000000,  // name = EventSourceID
        CORBA::tk_long,

      6, 0x74797065, 0x5f000000,  // name = type_
      CORBA::tk_alias, // typecode kind for typedefs
      60, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7454, 0x7970653a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventType:1.0
        10, 0x4576656e, 0x74547970, 0x65000000,  // name = EventType
        CORBA::tk_long,

      6, 0x74696d65, 0x5f000000,  // name = time_
      CORBA::tk_alias, // typecode kind for typedefs
      52, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        27, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5469, 0x6d653a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/Time:1.0
        5, 0x54696d65, 0x0,  // name = Time
        CORBA::tk_long,

      6, 0x64617461, 0x5f000000,  // name = data_
      CORBA::tk_struct, // typecode kind
      84, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7444, 0x6174613a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventData:1.0
        10, 0x4576656e, 0x74446174, 0x61000000,  // name = EventData
        2, // member count
          2, 0x78000000,  // name = x
          CORBA::tk_long,

          2, 0x79000000,  // name = y
          CORBA::tk_long,

          0,
};
static CORBA::TypeCode _tc__tc_RtecEventComm_EventSet (CORBA::tk_alias, sizeof (_oc_RtecEventComm_EventSet), (unsigned char *) &_oc_RtecEventComm_EventSet, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_EventSet = &_tc__tc_RtecEventComm_EventSet;

RtecEventComm::PushConsumer_ptr RtecEventComm::PushConsumer::_duplicate (RtecEventComm::PushConsumer_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->AddRef ();
  
  return obj;
} // end of _duplicate

RtecEventComm::PushConsumer_ptr RtecEventComm::PushConsumer::_narrow (CORBA::Object_ptr obj, CORBA::Environment &env)
{
  if (CORBA::is_nil (obj)) return RtecEventComm::PushConsumer::_nil ();
  if (obj->_is_a ("IDL:RtecEventComm/PushConsumer:1.0", env))
  {
    STUB_Object *istub;
    RtecEventComm::PushConsumer_ptr new_obj; // to be returned 
    if (obj->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
      return RtecEventComm::PushConsumer::_nil ();
    
    obj->Release (); // need this since QueryIntf bumped our refcount
    new_obj = new RtecEventComm::PushConsumer (istub); // construct obj ref using the stub object
    return new_obj;
  } // end of if
  return RtecEventComm::PushConsumer::_nil (); // _narrow failed
} // end of _narrow

RtecEventComm::PushConsumer_ptr RtecEventComm::PushConsumer::_nil (void)
{
  return (RtecEventComm::PushConsumer_ptr)NULL;
} // end of _nil

RtecEventComm::PushConsumer_ptr RtecEventComm::PushConsumer::_bind (const char *host, CORBA::UShort port, const char *key, CORBA::Environment &env)
{
  CORBA::Object_ptr objref = CORBA::Object::_nil ();
  IIOP_Object *data = new IIOP_Object (host, port, key);
  if (!data) return RtecEventComm::PushConsumer::_nil ();
  // get the object_ptr using Query Interface
  if (data->QueryInterface (IID_CORBA_Object, (void **)&objref) != NOERROR)
  {
  	env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
  	return RtecEventComm::PushConsumer::_nil ();
  }
  data->Release (); // QueryInterface had bumped up our count
  if (CORBA::is_nil (objref))
  	return RtecEventComm::PushConsumer::_nil ();
  else // narrow it
  	return RtecEventComm::PushConsumer::_narrow (objref, env);
}

static const TAO_Param_Data RtecEventComm_PushConsumer_push_paramdata [] = 
{
  {CORBA::_tc_void, PARAM_RETURN, 0},
  {RtecEventComm::_tc_EventSet, PARAM_IN, 0}
};

static const TAO_Call_Data RtecEventComm_PushConsumer_push_calldata = 
{"push", 1, 2, RtecEventComm_PushConsumer_push_paramdata, 0, 0};

void  RtecEventComm::PushConsumer::push (const RtecEventComm::EventSet & data, CORBA::Environment &env)
{
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PushConsumer_push_calldata, 0, &data);
  return; // no value
  
}

static const TAO_Param_Data RtecEventComm_PushConsumer_disconnect_push_consumer_paramdata [] = 
{
  {CORBA::_tc_void, PARAM_RETURN, 0}
};

static const TAO_Call_Data RtecEventComm_PushConsumer_disconnect_push_consumer_calldata = 
{"disconnect_push_consumer", 1, 1, RtecEventComm_PushConsumer_disconnect_push_consumer_paramdata, 0, 0};

void  RtecEventComm::PushConsumer::disconnect_push_consumer (CORBA::Environment &env)
{
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PushConsumer_disconnect_push_consumer_calldata, 0);
  return; // no value
  
}

static const CORBA::Long _oc_RtecEventComm_PushConsumer[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  35, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5075, 0x7368436f, 0x6e73756d, 0x65723a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/PushConsumer:1.0
  13, 0x50757368, 0x436f6e73, 0x756d6572, 0x0,  // name = PushConsumer,
};
static CORBA::TypeCode _tc__tc_RtecEventComm_PushConsumer (CORBA::tk_objref, sizeof (_oc_RtecEventComm_PushConsumer), (unsigned char *) &_oc_RtecEventComm_PushConsumer, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_PushConsumer = &_tc__tc_RtecEventComm_PushConsumer;

RtecEventComm::PushSupplier_ptr RtecEventComm::PushSupplier::_duplicate (RtecEventComm::PushSupplier_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->AddRef ();
  
  return obj;
} // end of _duplicate

RtecEventComm::PushSupplier_ptr RtecEventComm::PushSupplier::_narrow (CORBA::Object_ptr obj, CORBA::Environment &env)
{
  if (CORBA::is_nil (obj)) return RtecEventComm::PushSupplier::_nil ();
  if (obj->_is_a ("IDL:RtecEventComm/PushSupplier:1.0", env))
  {
    STUB_Object *istub;
    RtecEventComm::PushSupplier_ptr new_obj; // to be returned 
    if (obj->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
      return RtecEventComm::PushSupplier::_nil ();
    
    obj->Release (); // need this since QueryIntf bumped our refcount
    new_obj = new RtecEventComm::PushSupplier (istub); // construct obj ref using the stub object
    return new_obj;
  } // end of if
  return RtecEventComm::PushSupplier::_nil (); // _narrow failed
} // end of _narrow

RtecEventComm::PushSupplier_ptr RtecEventComm::PushSupplier::_nil (void)
{
  return (RtecEventComm::PushSupplier_ptr)NULL;
} // end of _nil

RtecEventComm::PushSupplier_ptr RtecEventComm::PushSupplier::_bind (const char *host, CORBA::UShort port, const char *key, CORBA::Environment &env)
{
  CORBA::Object_ptr objref = CORBA::Object::_nil ();
  IIOP_Object *data = new IIOP_Object (host, port, key);
  if (!data) return RtecEventComm::PushSupplier::_nil ();
  // get the object_ptr using Query Interface
  if (data->QueryInterface (IID_CORBA_Object, (void **)&objref) != NOERROR)
  {
  	env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
  	return RtecEventComm::PushSupplier::_nil ();
  }
  data->Release (); // QueryInterface had bumped up our count
  if (CORBA::is_nil (objref))
  	return RtecEventComm::PushSupplier::_nil ();
  else // narrow it
  	return RtecEventComm::PushSupplier::_narrow (objref, env);
}

static const TAO_Param_Data RtecEventComm_PushSupplier_disconnect_push_supplier_paramdata [] = 
{
  {CORBA::_tc_void, PARAM_RETURN, 0}
};

static const TAO_Call_Data RtecEventComm_PushSupplier_disconnect_push_supplier_calldata = 
{"disconnect_push_supplier", 1, 1, RtecEventComm_PushSupplier_disconnect_push_supplier_paramdata, 0, 0};

void  RtecEventComm::PushSupplier::disconnect_push_supplier (CORBA::Environment &env)
{
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PushSupplier_disconnect_push_supplier_calldata, 0);
  return; // no value
  
}

static const CORBA::Long _oc_RtecEventComm_PushSupplier[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  35, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5075, 0x73685375, 0x70706c69, 0x65723a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/PushSupplier:1.0
  13, 0x50757368, 0x53757070, 0x6c696572, 0x0,  // name = PushSupplier,
};
static CORBA::TypeCode _tc__tc_RtecEventComm_PushSupplier (CORBA::tk_objref, sizeof (_oc_RtecEventComm_PushSupplier), (unsigned char *) &_oc_RtecEventComm_PushSupplier, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_PushSupplier = &_tc__tc_RtecEventComm_PushSupplier;

