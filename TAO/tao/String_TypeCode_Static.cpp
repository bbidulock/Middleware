// $Id$

#include "tao/String_TypeCode_Static.h"
#include "tao/CDR.h"

#ifndef __ACE_INLINE__
# include "tao/String_TypeCode_Static.inl"
#endif  /* !__ACE_INLINE__ */


ACE_RCSID (tao,
           String_TypeCode_Static,
           "$Id$")


bool
TAO::TypeCode::String<TAO::Null_RefCount_Policy>::tao_marshal (
  TAO_OutputCDR & cdr) const
{
  // A tk_string TypeCode has a "simple" parameter list type (see
  // Table 15-2 in Section 15.3.5.1 "TypeCode" in the CDR section of
  // the CORBA specification), meaning that its parameter(s) must be
  // marshaled immediately following the TCKind.  No CDR encapsulation
  // is to be created.

  return (cdr << this->length_);
}

void
TAO::TypeCode::String<TAO::Null_RefCount_Policy>::tao_duplicate (void)
{
}

void
TAO::TypeCode::String<TAO::Null_RefCount_Policy>::tao_release (void)
{
}

CORBA::Boolean
TAO::TypeCode::String<TAO::Null_RefCount_Policy>::equal_i (
  CORBA::TypeCode_ptr tc
  ACE_ENV_ARG_DECL) const
{
  // The following call won't throw since CORBA::TypeCode::equal() has
  // already established the kind of tc is the same as our kind.
  CORBA::ULong const tc_length = tc->length (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return (this->length_ == tc_length);
}

CORBA::Boolean
TAO::TypeCode::String<TAO::Null_RefCount_Policy>::equivalent_i (
  CORBA::TypeCode_ptr tc
  ACE_ENV_ARG_DECL) const
{
  // Since TCKind comparisons must be performed before equal_i() is
  // called, we can also call it to determine equivalence of
  // tk_string-based TypeCodes.
  return this->equal_i (tc
                        ACE_ENV_ARG_PARAMETER);
}

CORBA::TypeCode_ptr
TAO::TypeCode::String<TAO::Null_RefCount_Policy>::get_compact_typecode_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  // Already compact since tk_string and tk_wstring TypeCodes have no
  // name or member names, meaning that we can simply call
  // _duplicate() on this TypeCode.

  CORBA::TypeCode_ptr mutable_tc =
    const_cast<TAO::TypeCode::String<TAO::Null_RefCount_Policy> *> (this);

  return CORBA::TypeCode::_duplicate (mutable_tc);
}

CORBA::ULong
TAO::TypeCode::String<TAO::Null_RefCount_Policy>::length_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return this->length_;
}
