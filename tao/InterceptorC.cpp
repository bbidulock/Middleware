/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "InterceptorC.h"

#if !defined (__ACE_INLINE__)
#include "InterceptorC.i"
#endif /* !defined INLINE */

PortableInterceptor::Cookie_ptr PortableInterceptor::Cookie::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return Cookie::_unchecked_narrow (obj, ACE_TRY_ENV);
}

PortableInterceptor::Cookie_ptr PortableInterceptor::Cookie::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return Cookie::_nil ();
  return
      ACE_reinterpret_cast
        (
          PortableInterceptor::Cookie_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &PortableInterceptor::Cookie::_narrow
                  )
              )
        );
}

PortableInterceptor::Cookie_ptr 
PortableInterceptor::Cookie::_duplicate (Cookie_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *PortableInterceptor::Cookie::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &PortableInterceptor::Cookie::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));
    
  if (retv)
    this->_add_ref ();
  return retv;
}

const char* PortableInterceptor::Cookie::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/Cookie:1.0";
}


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  
#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_PORTABLEINTERCEPTOR_COOKIES_CS_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_PORTABLEINTERCEPTOR_COOKIES_CS_

  // The Base_Sequence functions, please see tao/Sequence.h
  void
  PortableInterceptor::_TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::_allocate_buffer (CORBA::ULong length)
  {
    PortableInterceptor::Cookie **tmp = 0;
    tmp = _TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::allocbuf (length);
    
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
    _TAO_Unbounded_Object_Sequence_PortableInterceptor_Cookies::freebuf (tmp);
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
  Cookies *tmp = ACE_static_cast (Cookies*,x);
  delete tmp;
}


#endif /* end #if !defined */

PortableInterceptor::Interceptor_ptr PortableInterceptor::Interceptor::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return Interceptor::_unchecked_narrow (obj, ACE_TRY_ENV);
}

PortableInterceptor::Interceptor_ptr PortableInterceptor::Interceptor::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return Interceptor::_nil ();
  return
      ACE_reinterpret_cast
        (
          PortableInterceptor::Interceptor_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &PortableInterceptor::Interceptor::_narrow
                  )
              )
        );
}

PortableInterceptor::Interceptor_ptr 
PortableInterceptor::Interceptor::_duplicate (Interceptor_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *PortableInterceptor::Interceptor::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &PortableInterceptor::Interceptor::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));
    
  if (retv)
    this->_add_ref ();
  return retv;
}

const char* PortableInterceptor::Interceptor::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/Interceptor:1.0";
}

PortableInterceptor::ServerRequestInterceptor_ptr PortableInterceptor::ServerRequestInterceptor::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return ServerRequestInterceptor::_unchecked_narrow (obj, ACE_TRY_ENV);
}

PortableInterceptor::ServerRequestInterceptor_ptr PortableInterceptor::ServerRequestInterceptor::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return ServerRequestInterceptor::_nil ();
  return
      ACE_reinterpret_cast
        (
          PortableInterceptor::ServerRequestInterceptor_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &PortableInterceptor::ServerRequestInterceptor::_narrow
                  )
              )
        );
}

PortableInterceptor::ServerRequestInterceptor_ptr 
PortableInterceptor::ServerRequestInterceptor::_duplicate (ServerRequestInterceptor_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *PortableInterceptor::ServerRequestInterceptor::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &PortableInterceptor::ServerRequestInterceptor::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &PortableInterceptor::Interceptor::_narrow))
    retv = ACE_reinterpret_cast
      (
        void *,
        ACE_static_cast
          (
            PortableInterceptor::Interceptor_ptr,
            this
          )
      );
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));
    
  if (retv)
    this->_add_ref ();
  return retv;
}

const char* PortableInterceptor::ServerRequestInterceptor::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/ServerRequestInterceptor:1.0";
}

PortableInterceptor::ClientRequestInterceptor_ptr PortableInterceptor::ClientRequestInterceptor::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  return ClientRequestInterceptor::_unchecked_narrow (obj, ACE_TRY_ENV);
}

PortableInterceptor::ClientRequestInterceptor_ptr PortableInterceptor::ClientRequestInterceptor::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return ClientRequestInterceptor::_nil ();
  return
      ACE_reinterpret_cast
        (
          PortableInterceptor::ClientRequestInterceptor_ptr,
            obj->_tao_QueryInterface
              (
                ACE_reinterpret_cast
                  (
                    ptr_arith_t,
                    &PortableInterceptor::ClientRequestInterceptor::_narrow
                  )
              )
        );
}

PortableInterceptor::ClientRequestInterceptor_ptr 
PortableInterceptor::ClientRequestInterceptor::_duplicate (ClientRequestInterceptor_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_add_ref ();
  return obj;
}

void *PortableInterceptor::ClientRequestInterceptor::_tao_QueryInterface (ptr_arith_t type)
{
  void *retv = 0;
  if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &PortableInterceptor::ClientRequestInterceptor::_narrow))
    retv = ACE_reinterpret_cast (void*, this);
  else if (type == ACE_reinterpret_cast
    (ptr_arith_t,
      &PortableInterceptor::Interceptor::_narrow))
    retv = ACE_reinterpret_cast
      (
        void *,
        ACE_static_cast
          (
            PortableInterceptor::Interceptor_ptr,
            this
          )
      );
  else if (type == ACE_reinterpret_cast (ptr_arith_t, &CORBA::Object::_narrow))
    retv = ACE_reinterpret_cast (void *,
      ACE_static_cast (CORBA::Object_ptr, this));
    
  if (retv)
    this->_add_ref ();
  return retv;
}

const char* PortableInterceptor::ClientRequestInterceptor::_interface_repository_id (void) const
{
  return "IDL:TAO/PortableInterceptor/ClientRequestInterceptor:1.0";
}

