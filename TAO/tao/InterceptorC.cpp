/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/InterceptorS.h"
#include "tao/varout.h"

#if !defined (__ACE_INLINE__)
#include "tao/InterceptorC.i"
#endif /* !defined INLINE */

#if (TAO_HAS_INTERCEPTORS == 1)

PortableInterceptor::Cookie_ptr PortableInterceptor::Cookie::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return PortableInterceptor::Cookie::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:TAO/PortableInterceptor/Cookie:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (PortableInterceptor::Cookie::_nil ());
  if (is_a == 0)
    return PortableInterceptor::Cookie::_nil ();
  void *servant = 0;
  if (!obj->_is_collocated ()
        || !obj->_servant ()
        || (servant = obj->_servant()->_downcast ("IDL:TAO/PortableInterceptor/Cookie:1.0")) == 0
      )
    ACE_THROW_RETURN (CORBA::MARSHAL (), PortableInterceptor::Cookie::_nil ());

  PortableInterceptor::Cookie_ptr retval =
    PortableInterceptor::Cookie::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_PortableInterceptor::_tao_direct_collocated_Cookie (
          ACE_reinterpret_cast (POA_PortableInterceptor::Cookie_ptr,
                                servant),
          0
        ),
      PortableInterceptor::Cookie::_nil ()
    );

  return retval;
}

PortableInterceptor::Cookie_ptr
PortableInterceptor::Cookie::_duplicate (PortableInterceptor::Cookie_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void PortableInterceptor::Cookie::_tao_any_destructor (void *x)
{
  PortableInterceptor::Cookie *tmp = ACE_static_cast (PortableInterceptor::Cookie*,x);
  CORBA::release (tmp);
}

CORBA::Boolean PortableInterceptor::Cookie::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/Cookie:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

const char* PortableInterceptor::Cookie::_remote_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/Cookie:1.0";
}

static const CORBA::Long _oc_PortableInterceptor_Cookie[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  39, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f2f), ACE_NTOHL (0x506f7274), ACE_NTOHL (0x61626c65), ACE_NTOHL (0x496e7465), ACE_NTOHL (0x72636570), ACE_NTOHL (0x746f722f), ACE_NTOHL (0x436f6f6b), ACE_NTOHL (0x69653a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:TAO/PortableInterceptor/Cookie:1.0
  7, ACE_NTOHL (0x436f6f6b), ACE_NTOHL (0x69650000),  // name = Cookie
};
static CORBA::TypeCode _tc_TAO_tc_PortableInterceptor_Cookie (CORBA::tk_objref, sizeof (_oc_PortableInterceptor_Cookie), (char *) &_oc_PortableInterceptor_Cookie, 0, sizeof (PortableInterceptor::Cookie));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (PortableInterceptor)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Cookie, &_tc_TAO_tc_PortableInterceptor_Cookie)
TAO_NAMESPACE_END

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_PORTABLEINTERCEPTOR_COOKIES_CS_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_PORTABLEINTERCEPTOR_COOKIES_CS_

  // The Base_Sequence functions, please see tao/Sequence.h
  void
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_allocate_buffer (CORBA::ULong length)
  {
    PortableInterceptor::Cookie **tmp = 0;
    tmp = PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::allocbuf (length);

    if (this->buffer_ != 0)
    {
      PortableInterceptor::Cookie **old = ACE_reinterpret_cast (PortableInterceptor::Cookie**, this->buffer_);
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        if (!this->release_)
          tmp[i] = PortableInterceptor::Cookie::_duplicate (old[i]);
        else
          tmp[i] = old[i];

      if (this->release_)
        delete[] old;

    }
    this->buffer_ = tmp;
  }

  void
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_deallocate_buffer (void)
  {
    if (this->buffer_ == 0 || this->release_ == 0)
      return;
    PortableInterceptor::Cookie **tmp = ACE_reinterpret_cast (PortableInterceptor::Cookie**, this->buffer_);
    for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = PortableInterceptor::Cookie::_nil ();
    }
    PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::freebuf (tmp);
    this->buffer_ = 0;
  }

  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::~_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies (void)
  {
    this->_deallocate_buffer ();
  }

  void
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_shrink_buffer (CORBA::ULong nl, CORBA::ULong ol)
  {
    PortableInterceptor::Cookie **tmp = ACE_reinterpret_cast (PortableInterceptor::Cookie**, this->buffer_);

    for (CORBA::ULong i = nl; i < ol; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = PortableInterceptor::Cookie::_nil ();
    }
  }
  void
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_downcast (
      void* target,
      CORBA_Object *src,
      CORBA_Environment &ACE_TRY_ENV
    )
  {
    PortableInterceptor::Cookie **tmp = ACE_static_cast (PortableInterceptor::Cookie**, target);
    *tmp = PortableInterceptor::Cookie::_narrow (src, ACE_TRY_ENV);
  }

  CORBA_Object*
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_upcast (void *src) const
  {
    PortableInterceptor::Cookie **tmp = ACE_static_cast (PortableInterceptor::Cookie**, src);
    return *tmp;
  }

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_PORTABLEINTERCEPTOR_COOKIES_CS_)
#define _PORTABLEINTERCEPTOR_COOKIES_CS_

// *************************************************************
// PortableInterceptor::Cookies
// *************************************************************

PortableInterceptor::Cookies::Cookies (void)
{}
PortableInterceptor::Cookies::Cookies (CORBA::ULong max) // uses max size
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max)
{}
PortableInterceptor::Cookies::Cookies (CORBA::ULong max, CORBA::ULong length, PortableInterceptor::Cookie_ptr *buffer, CORBA::Boolean release)
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (max, length, buffer, release)
{}
PortableInterceptor::Cookies::Cookies (const Cookies &seq) // copy ctor
  :
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Object_Sequence<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
 (seq)
{}
PortableInterceptor::Cookies::~Cookies (void) // dtor
{}

void PortableInterceptor::Cookies::_tao_any_destructor (void *x)
{
  PortableInterceptor::Cookies *tmp = ACE_static_cast(PortableInterceptor::Cookies*,x);
  delete tmp;
}

#endif /* end #if !defined */

static const CORBA::Long _oc_PortableInterceptor_Cookies[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  40, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f2f), ACE_NTOHL (0x506f7274), ACE_NTOHL (0x61626c65), ACE_NTOHL (0x496e7465), ACE_NTOHL (0x72636570), ACE_NTOHL (0x746f722f), ACE_NTOHL (0x436f6f6b), ACE_NTOHL (0x6965733a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:TAO/PortableInterceptor/Cookies:1.0
  8, ACE_NTOHL (0x436f6f6b), ACE_NTOHL (0x69657300),  // name = Cookies
  CORBA::tk_sequence, // typecode kind
  76, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_objref, // typecode kind
    60, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      39, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f2f), ACE_NTOHL (0x506f7274), ACE_NTOHL (0x61626c65), ACE_NTOHL (0x496e7465), ACE_NTOHL (0x72636570), ACE_NTOHL (0x746f722f), ACE_NTOHL (0x436f6f6b), ACE_NTOHL (0x69653a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:TAO/PortableInterceptor/Cookie:1.0
      7, ACE_NTOHL (0x436f6f6b), ACE_NTOHL (0x69650000),  // name = Cookie

    0U,

};
static CORBA::TypeCode _tc_TAO_tc_PortableInterceptor_Cookies (CORBA::tk_alias, sizeof (_oc_PortableInterceptor_Cookies), (char *) &_oc_PortableInterceptor_Cookies, 0, sizeof (PortableInterceptor::Cookies));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (PortableInterceptor)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Cookies, &_tc_TAO_tc_PortableInterceptor_Cookies)
TAO_NAMESPACE_END
PortableInterceptor::Interceptor_ptr PortableInterceptor::Interceptor::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return PortableInterceptor::Interceptor::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:TAO/PortableInterceptor/Interceptor:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (PortableInterceptor::Interceptor::_nil ());
  if (is_a == 0)
    return PortableInterceptor::Interceptor::_nil ();
  void *servant = 0;
  if (!obj->_is_collocated ()
        || !obj->_servant ()
        || (servant = obj->_servant()->_downcast ("IDL:TAO/PortableInterceptor/Interceptor:1.0")) == 0
      )
    ACE_THROW_RETURN (CORBA::MARSHAL (), PortableInterceptor::Interceptor::_nil ());

  PortableInterceptor::Interceptor_ptr retval =
    PortableInterceptor::Interceptor::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_PortableInterceptor::_tao_direct_collocated_Interceptor (
          ACE_reinterpret_cast (POA_PortableInterceptor::Interceptor_ptr,
                                servant),
          0
        ),
      PortableInterceptor::Interceptor::_nil ()
    );

  return retval;
}

PortableInterceptor::Interceptor_ptr
PortableInterceptor::Interceptor::_duplicate (PortableInterceptor::Interceptor_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void PortableInterceptor::Interceptor::_tao_any_destructor (void* x)
{
  PortableInterceptor::Interceptor *tmp = ACE_static_cast(PortableInterceptor::Interceptor*,x);
  CORBA::release (tmp);
}

CORBA::Boolean PortableInterceptor::Interceptor::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/Interceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

const char* PortableInterceptor::Interceptor::_remote_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/Interceptor:1.0";
}

static const CORBA::Long _oc_PortableInterceptor_Interceptor[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  44, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f2f), ACE_NTOHL (0x506f7274), ACE_NTOHL (0x61626c65), ACE_NTOHL (0x496e7465), ACE_NTOHL (0x72636570), ACE_NTOHL (0x746f722f), ACE_NTOHL (0x496e7465), ACE_NTOHL (0x72636570), ACE_NTOHL (0x746f723a), ACE_NTOHL (0x312e3000),  // repository ID = IDL:TAO/PortableInterceptor/Interceptor:1.0
  12, ACE_NTOHL (0x496e7465), ACE_NTOHL (0x72636570), ACE_NTOHL (0x746f7200),  // name = Interceptor
};
static CORBA::TypeCode _tc_TAO_tc_PortableInterceptor_Interceptor (CORBA::tk_objref, sizeof (_oc_PortableInterceptor_Interceptor), (char *) &_oc_PortableInterceptor_Interceptor, 0, sizeof (PortableInterceptor::Interceptor));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (PortableInterceptor)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_Interceptor, &_tc_TAO_tc_PortableInterceptor_Interceptor)
TAO_NAMESPACE_END
PortableInterceptor::ServerRequestInterceptor_ptr PortableInterceptor::ServerRequestInterceptor::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return PortableInterceptor::ServerRequestInterceptor::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (PortableInterceptor::ServerRequestInterceptor::_nil ());
  if (is_a == 0)
    return PortableInterceptor::ServerRequestInterceptor::_nil ();
  void *servant = 0;
  if (!obj->_is_collocated ()
        || !obj->_servant ()
        || (servant = obj->_servant()->_downcast ("IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0")) == 0
      )
    ACE_THROW_RETURN (CORBA::MARSHAL (), PortableInterceptor::ServerRequestInterceptor::_nil ());

  PortableInterceptor::ServerRequestInterceptor_ptr retval =
    PortableInterceptor::ServerRequestInterceptor::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_PortableInterceptor::_tao_direct_collocated_ServerRequestInterceptor (
          ACE_reinterpret_cast (POA_PortableInterceptor::ServerRequestInterceptor_ptr,
                                servant),
          0
        ),
      PortableInterceptor::ServerRequestInterceptor::_nil ()
    );

  return retval;
}

PortableInterceptor::ServerRequestInterceptor_ptr
PortableInterceptor::ServerRequestInterceptor::_duplicate (PortableInterceptor::ServerRequestInterceptor_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void PortableInterceptor::ServerRequestInterceptor::_tao_any_destructor (void *x)
{
  PortableInterceptor::ServerRequestInterceptor *tmp = ACE_static_cast (PortableInterceptor::ServerRequestInterceptor*,x);
  CORBA::release (tmp);
}

CORBA::Boolean PortableInterceptor::ServerRequestInterceptor::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/Interceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

const char* PortableInterceptor::ServerRequestInterceptor::_remote_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0";
}

static const CORBA::Long _oc_PortableInterceptor_ServerRequestInterceptor[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  57, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f2f), ACE_NTOHL (0x506f7274), ACE_NTOHL (0x61626c65), ACE_NTOHL (0x496e7465), ACE_NTOHL (0x72636570), ACE_NTOHL (0x746f722f), ACE_NTOHL (0x53657276), ACE_NTOHL (0x65725265), ACE_NTOHL (0x71756573), ACE_NTOHL (0x74496e74), ACE_NTOHL (0x65726365), ACE_NTOHL (0x70746f72), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0
  25, ACE_NTOHL (0x53657276), ACE_NTOHL (0x65725265), ACE_NTOHL (0x71756573), ACE_NTOHL (0x74496e74), ACE_NTOHL (0x65726365), ACE_NTOHL (0x70746f72), ACE_NTOHL (0x0),  // name = ServerRequestInterceptor
};
static CORBA::TypeCode _tc_TAO_tc_PortableInterceptor_ServerRequestInterceptor (CORBA::tk_objref, sizeof (_oc_PortableInterceptor_ServerRequestInterceptor), (char *) &_oc_PortableInterceptor_ServerRequestInterceptor, 0, sizeof (PortableInterceptor::ServerRequestInterceptor));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (PortableInterceptor)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ServerRequestInterceptor, &_tc_TAO_tc_PortableInterceptor_ServerRequestInterceptor)
TAO_NAMESPACE_END
PortableInterceptor::ClientRequestInterceptor_ptr PortableInterceptor::ClientRequestInterceptor::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return PortableInterceptor::ClientRequestInterceptor::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (PortableInterceptor::ClientRequestInterceptor::_nil ());
  if (is_a == 0)
    return PortableInterceptor::ClientRequestInterceptor::_nil ();
  void *servant = 0;
  if (!obj->_is_collocated ()
        || !obj->_servant ()
        || (servant = obj->_servant()->_downcast ("IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0")) == 0
      )
    ACE_THROW_RETURN (CORBA::MARSHAL (), PortableInterceptor::ClientRequestInterceptor::_nil ());

  PortableInterceptor::ClientRequestInterceptor_ptr retval =
    PortableInterceptor::ClientRequestInterceptor::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_PortableInterceptor::_tao_direct_collocated_ClientRequestInterceptor (
          ACE_reinterpret_cast (POA_PortableInterceptor::ClientRequestInterceptor_ptr,
                                servant),
          0
        ),
      PortableInterceptor::ClientRequestInterceptor::_nil ()
    );

  return retval;
}

PortableInterceptor::ClientRequestInterceptor_ptr
PortableInterceptor::ClientRequestInterceptor::_duplicate (PortableInterceptor::ClientRequestInterceptor_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void PortableInterceptor::ClientRequestInterceptor::_tao_any_destructor (void *x)
{
  PortableInterceptor::ClientRequestInterceptor *tmp = ACE_static_cast (PortableInterceptor::ClientRequestInterceptor*,x);
  CORBA::release (tmp);
}

CORBA::Boolean PortableInterceptor::ClientRequestInterceptor::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO/PortableInterceptor/Interceptor:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

const char* PortableInterceptor::ClientRequestInterceptor::_remote_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0";
}

static const CORBA::Long _oc_PortableInterceptor_ClientRequestInterceptor[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  57, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f2f), ACE_NTOHL (0x506f7274), ACE_NTOHL (0x61626c65), ACE_NTOHL (0x496e7465), ACE_NTOHL (0x72636570), ACE_NTOHL (0x746f722f), ACE_NTOHL (0x436c6965), ACE_NTOHL (0x6e745265), ACE_NTOHL (0x71756573), ACE_NTOHL (0x74496e74), ACE_NTOHL (0x65726365), ACE_NTOHL (0x70746f72), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0
  25, ACE_NTOHL (0x436c6965), ACE_NTOHL (0x6e745265), ACE_NTOHL (0x71756573), ACE_NTOHL (0x74496e74), ACE_NTOHL (0x65726365), ACE_NTOHL (0x70746f72), ACE_NTOHL (0x0),  // name = ClientRequestInterceptor
};
static CORBA::TypeCode _tc_TAO_tc_PortableInterceptor_ClientRequestInterceptor (CORBA::tk_objref, sizeof (_oc_PortableInterceptor_ClientRequestInterceptor), (char *) &_oc_PortableInterceptor_ClientRequestInterceptor, 0, sizeof (PortableInterceptor::ClientRequestInterceptor));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (PortableInterceptor)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_ClientRequestInterceptor, &_tc_TAO_tc_PortableInterceptor_ClientRequestInterceptor)
TAO_NAMESPACE_END

void operator<<= (CORBA::Any &_tao_any, PortableInterceptor::Cookie_ptr _tao_elem)
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          PortableInterceptor::_tc_Cookie,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, PortableInterceptor::Cookie_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = PortableInterceptor::Cookie::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (PortableInterceptor::_tc_Cookie, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    TAO_InputCDR stream (
        _tao_any._tao_get_cdr (),
        _tao_any._tao_byte_order ()
      );
    CORBA::Object_var _tao_obj_var;
    if (stream >> _tao_obj_var.out ())
    {
      _tao_elem = PortableInterceptor::Cookie::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      ((CORBA::Any *)&_tao_any)->_tao_replace (
          PortableInterceptor::_tc_Cookie,
          1,
          _tao_elem,
          PortableInterceptor::Cookie::_tao_any_destructor
        );
      return 1;
    }
  }
  ACE_CATCHANY
  {
    _tao_elem = PortableInterceptor::Cookie::_nil ();
    return 0;
  }
  ACE_ENDTRY;
  _tao_elem = PortableInterceptor::Cookie::_nil ();
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>;
template class TAO_Object_Manager<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>
#  pragma instantiate TAO_Object_Manager<PortableInterceptor::Cookie,PortableInterceptor::Cookie_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

void operator<<= (
    CORBA::Any &_tao_any,
    const PortableInterceptor::Cookies &_tao_elem
  ) // copying
{
    TAO_OutputCDR stream;
    if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          PortableInterceptor::_tc_Cookies,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

void operator<<= (CORBA::Any &_tao_any, PortableInterceptor::Cookies *_tao_elem) // non copying
{
    TAO_OutputCDR stream;
    stream << *_tao_elem;
    _tao_any._tao_replace (
        PortableInterceptor::_tc_Cookies,
        TAO_ENCAP_BYTE_ORDER,
        stream.begin (),
        1,
        _tao_elem,
        PortableInterceptor::Cookies::_tao_any_destructor
      );
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, PortableInterceptor::Cookies *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (PortableInterceptor::_tc_Cookies, ACE_TRY_ENV)) // not equal
      {
        _tao_elem = 0;
        return 0;
      }
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (PortableInterceptor::Cookies *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, PortableInterceptor::Cookies, 0);
      TAO_InputCDR stream (
          _tao_any._tao_get_cdr (),
          _tao_any._tao_byte_order ()
        );
      if (stream >> *_tao_elem)
      {
        ((CORBA::Any *)&_tao_any)->_tao_replace (
            PortableInterceptor::_tc_Cookies,
            1,
            ACE_reinterpret_cast (void *, _tao_elem),
            PortableInterceptor::Cookies::_tao_any_destructor
          );
        return 1;
      }
      else
      {
        delete _tao_elem;
        _tao_elem = 0;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    _tao_elem = 0;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, const PortableInterceptor::Cookies *&_tao_elem)
{
  return _tao_any >>= ACE_const_cast(PortableInterceptor::Cookies*&,_tao_elem);
}

void operator<<= (CORBA::Any &_tao_any, PortableInterceptor::Interceptor_ptr _tao_elem)
{
  TAO_OutputCDR stream;
  if (stream << _tao_elem)
  {
    _tao_any._tao_replace (
        PortableInterceptor::_tc_Interceptor,
        TAO_ENCAP_BYTE_ORDER,
        stream.begin ()
      );
  }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, PortableInterceptor::Interceptor_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = PortableInterceptor::Interceptor::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (PortableInterceptor::_tc_Interceptor, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    TAO_InputCDR stream (
        _tao_any._tao_get_cdr (),
        _tao_any._tao_byte_order ()
      );
    CORBA::Object_var _tao_obj_var;
    if (stream >> _tao_obj_var.out ())
    {
      _tao_elem = PortableInterceptor::Interceptor::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      ((CORBA::Any *)&_tao_any)->_tao_replace (
          PortableInterceptor::_tc_Interceptor,
          1,
          _tao_elem,
          PortableInterceptor::Interceptor::_tao_any_destructor
        );
      return 1;
    }
  }
  ACE_CATCHANY
  {
    _tao_elem = PortableInterceptor::Interceptor::_nil ();
    return 0;
  }
  ACE_ENDTRY;
  _tao_elem = PortableInterceptor::Interceptor::_nil ();
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<PortableInterceptor::Interceptor,PortableInterceptor::Interceptor_var>;
template class TAO_Object_Manager<PortableInterceptor::Interceptor,PortableInterceptor::Interceptor_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<PortableInterceptor::Interceptor,PortableInterceptor::Interceptor_var>
#  pragma instantiate TAO_Object_Manager<PortableInterceptor::Interceptor,PortableInterceptor::Interceptor_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

void operator<<= (CORBA::Any &_tao_any, PortableInterceptor::ServerRequestInterceptor_ptr _tao_elem)
{
    TAO_OutputCDR stream;
    if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          PortableInterceptor::_tc_ServerRequestInterceptor,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, PortableInterceptor::ServerRequestInterceptor_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = PortableInterceptor::ServerRequestInterceptor::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (PortableInterceptor::_tc_ServerRequestInterceptor, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    TAO_InputCDR stream (
        _tao_any._tao_get_cdr (),
        _tao_any._tao_byte_order ()
      );
    CORBA::Object_var _tao_obj_var;
    if (stream >> _tao_obj_var.out ())
    {
      _tao_elem = PortableInterceptor::ServerRequestInterceptor::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      ((CORBA::Any *)&_tao_any)->_tao_replace (
          PortableInterceptor::_tc_ServerRequestInterceptor,
          1,
          _tao_elem,
          PortableInterceptor::ServerRequestInterceptor::_tao_any_destructor
        );
      return 1;
    }
  }
  ACE_CATCHANY
  {
    _tao_elem = PortableInterceptor::ServerRequestInterceptor::_nil ();
    return 0;
  }
  ACE_ENDTRY;
  _tao_elem = PortableInterceptor::ServerRequestInterceptor::_nil ();
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<PortableInterceptor::ServerRequestInterceptor,PortableInterceptor::ServerRequestInterceptor_var>;
template class TAO_Object_Manager<PortableInterceptor::ServerRequestInterceptor,PortableInterceptor::ServerRequestInterceptor_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<PortableInterceptor::ServerRequestInterceptor,PortableInterceptor::ServerRequestInterceptor_var>
#  pragma instantiate TAO_Object_Manager<PortableInterceptor::ServerRequestInterceptor,PortableInterceptor::ServerRequestInterceptor_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

void operator<<= (CORBA::Any &_tao_any, PortableInterceptor::ClientRequestInterceptor_ptr _tao_elem)
{
    TAO_OutputCDR stream;
    if (stream << _tao_elem)
    {
      _tao_any._tao_replace (
          PortableInterceptor::_tc_ClientRequestInterceptor,
          TAO_ENCAP_BYTE_ORDER,
          stream.begin ()
        );
    }
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, PortableInterceptor::ClientRequestInterceptor_ptr &_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    _tao_elem = PortableInterceptor::ClientRequestInterceptor::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equivalent (PortableInterceptor::_tc_ClientRequestInterceptor, ACE_TRY_ENV)) // not equal
      {
        return 0;
      }
    ACE_TRY_CHECK;
    TAO_InputCDR stream (
        _tao_any._tao_get_cdr (),
        _tao_any._tao_byte_order ()
      );
    CORBA::Object_var _tao_obj_var;
    if (stream >> _tao_obj_var.out ())
    {
      _tao_elem = PortableInterceptor::ClientRequestInterceptor::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      ((CORBA::Any *)&_tao_any)->_tao_replace (
          PortableInterceptor::_tc_ClientRequestInterceptor,
          1,
          _tao_elem,
          PortableInterceptor::ClientRequestInterceptor::_tao_any_destructor
        );
      return 1;
    }
  }
  ACE_CATCHANY
  {
    _tao_elem = PortableInterceptor::ClientRequestInterceptor::_nil ();
    return 0;
  }
  ACE_ENDTRY;
  _tao_elem = PortableInterceptor::ClientRequestInterceptor::_nil ();
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<PortableInterceptor::ClientRequestInterceptor,PortableInterceptor::ClientRequestInterceptor_var>;
template class TAO_Object_Manager<PortableInterceptor::ClientRequestInterceptor,PortableInterceptor::ClientRequestInterceptor_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<PortableInterceptor::ClientRequestInterceptor,PortableInterceptor::ClientRequestInterceptor_var>
#  pragma instantiate TAO_Object_Manager<PortableInterceptor::ClientRequestInterceptor,PortableInterceptor::ClientRequestInterceptor_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const PortableInterceptor::Cookies &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm << _tao_sequence[i].in ());
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    PortableInterceptor::Cookies &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // If length is 0 we return true.
    if (0 >= _tao_seq_len)
      return 1;
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
    {
      _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
    }
    return _tao_marshal_flag;
  }
  return 0; // error
}

#endif /* TAO_HAS_INTERCEPTORS */
