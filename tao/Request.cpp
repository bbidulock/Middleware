// $Id$

#include "tao/corba.h"

#if !defined (__ACE_INLINE__)
# include "tao/Request.i"
#endif /* ! __ACE_INLINE__ */

ACE_RCSID(tao, Request, "$Id$")

CORBA::ULong
CORBA_Request::_incr_refcnt (void)
{
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->refcount_lock_, 0);
  return refcount_++;
}

CORBA::ULong
CORBA_Request::_decr_refcnt (void)
{
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, ace_mon, this->refcount_lock_, 0);
    this->refcount_--;
    if (this->refcount_ != 0)
      return this->refcount_;
  }

  delete this;
  return 0;
}

// Reference counting for DII Request object

// DII Request class implementation

CORBA_Request::CORBA_Request (CORBA::Object_ptr obj,
                              const CORBA::Char *op,
                              CORBA::NVList_ptr args,
                              CORBA::NamedValue_ptr result,
                              CORBA::Flags flags)
  : args_ (args),
    result_ (result),
    flags_ (flags),
    refcount_ (1)
{
  target_ = CORBA::Object::_duplicate (obj);
  opname_ = CORBA::string_copy (op);
}

CORBA_Request::CORBA_Request (CORBA::Object_ptr obj,
                              const CORBA::Char *op)
  : flags_ (0),
    refcount_ (1)
{
  target_ = CORBA::Object::_duplicate (obj);
  opname_ = CORBA::string_copy (op);

  ACE_NEW (args_, CORBA::NVList);
  ACE_NEW (result_, CORBA::NamedValue);
}

CORBA_Request::~CORBA_Request (void)
{
  assert (refcount_ == 0);

  CORBA::release (this->target_);
  CORBA::string_free ((CORBA::String) this->opname_);
  this->opname_ = 0;
  CORBA::release (this->args_);
  CORBA::release (this->result_);
}

// The argument manipulation helper functions

CORBA_Any &
CORBA_Request::add_in_arg (void)
{
  CORBA_Any inarg_holder;
  CORBA::NamedValue_ptr nv = 
    this->args_->add_value (0,
                            inarg_holder,
                            CORBA::ARG_IN,
                            this->env_);
  return *nv->value ();
}

CORBA_Any &
CORBA_Request::add_in_arg (const CORBA::Char *name)
{
  CORBA_Any inarg_holder;
  CORBA::NamedValue_ptr nv = 
    this->args_->add_value (name,
                            inarg_holder,
                            CORBA::ARG_IN,
                            this->env_);
  return *nv->value ();
}

CORBA_Any &
CORBA_Request::add_inout_arg (void)
{
  CORBA_Any inoutarg_holder;
  CORBA::NamedValue_ptr nv = 
    this->args_->add_value (0,
                            inoutarg_holder,
                            CORBA::ARG_INOUT,
                            this->env_);
  return *nv->value ();
}

CORBA_Any &
CORBA_Request::add_inout_arg (const CORBA::Char *name)
{
  CORBA_Any inoutarg_holder;
  CORBA::NamedValue_ptr nv = 
    this->args_->add_value (name,
                            inoutarg_holder,
                            CORBA::ARG_INOUT,
                            this->env_);
  return *nv->value ();
}

CORBA_Any &
CORBA_Request::add_out_arg (void)
{
  CORBA_Any outarg_holder;
  CORBA::NamedValue_ptr nv = 
    this->args_->add_value (0,
                            outarg_holder,
                            CORBA::ARG_OUT,
                            this->env_);
  return *nv->value ();
}

CORBA_Any &
CORBA_Request::add_out_arg (const CORBA::Char *name)
{
  CORBA_Any outarg_holder;
  CORBA::NamedValue_ptr nv = 
    this->args_->add_value (name,
                            outarg_holder,
                            CORBA::ARG_OUT,
                            this->env_);
  return *nv->value ();
}

// The public DII interfaces:  normal and oneway calls.
//
// NOTE that using DII, programmers can get the special behaviour of
// discarding the response for normal calls.  This doesn't change the
// semantics of any OMG-IDL interface, it just streamlines control
// flow in some exotic situations.

void
CORBA_Request::invoke (void)
{
  STUB_Object *stub = this->target_->_stubobj ();

  stub->do_dynamic_call ((char *) opname_,
                         1,
                         args_,
                         result_,
                         flags_,
                         exceptions_,
                         env_);
}

void
CORBA_Request::send_oneway (void)
{
  STUB_Object *stub = this->target_->_stubobj ();

  stub->do_dynamic_call ((char *) opname_,
                         0,
                         args_,
                         result_,
                         flags_,
                         exceptions_,
                         env_);
}
