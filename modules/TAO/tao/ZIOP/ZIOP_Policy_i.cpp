// $Id: ZIOP_Policy_i.cpp 72141 2006-04-19 09:45:01Z jwillemsen $

#include "tao/ZIOP/ZIOP_Policy_i.h"

#include "tao/Stub.h"
#include "tao/debug.h"
#include "tao/ORB_Constants.h"

ACE_RCSID (ZIOP,
           ZIOP_Policy_i,
           "$Id: ZIOP_Policy_i.cpp 72141 2006-04-19 09:45:01Z jwillemsen $")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
CompressorIdPolicy::CompressorIdPolicy (
    const ::ZIOP::CompressorId val)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::ZIOP::CompressorIdPolicy ()
  , ::CORBA::LocalObject ()
  , TAO_Local_RefCounted_Object ()
  , value_ (val)
{
}

CompressorIdPolicy::CompressorIdPolicy (const CompressorIdPolicy &rhs)
  : ::CORBA::Object ()
  , ::CORBA::Policy ()
  , ::ZIOP::CompressorIdPolicy ()
  , ::CORBA::LocalObject ()
  , TAO_Local_RefCounted_Object ()
  , value_ (rhs.value_)
{
}

CORBA::PolicyType
CompressorIdPolicy::policy_type (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Future policy implementors: notice how this minimizes the
  // footprint of the class.
  return ZIOP::COMPRESSOR_ID_POLICY_ID;
}


CompressorIdPolicy *
CompressorIdPolicy::clone (void) const
{
  CompressorIdPolicy *copy = 0;
  ACE_NEW_RETURN (copy,
                  CompressorIdPolicy (*this),
                  0);
  return copy;
}

CORBA::Policy_ptr
CompressorIdPolicy::copy (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Future policy implementors: notice how the following code is
  // exception safe!

  CompressorIdPolicy* tmp = 0;
  ACE_NEW_THROW_EX (tmp, CompressorIdPolicy (*this),
                    CORBA::NO_MEMORY (TAO::VMCID,
                                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return tmp;
}

void
CompressorIdPolicy::destroy (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

::ZIOP::CompressorId
CompressorIdPolicy::compressor_id (
    ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((
      CORBA::SystemException))
{
  return this->value_;
}


TAO_Cached_Policy_Type
CompressorIdPolicy::_tao_cached_type (void) const
{
  return TAO_CACHED_POLICY_UNCACHED;
}
}
TAO_END_VERSIONED_NAMESPACE_DECL
