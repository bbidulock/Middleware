// -*- C++ -*-
//
// $Id$

template <typename STRING_TYPE>
ACE_INLINE char const *
TAO::TypeCode::Field<STRING_TYPE>::get_name (void) const
{
  return this->name;
}

// -----------------------------------------------------------------
// Some compilers exhibit warnings about better conversion sequence
// from a CORBA::String_var to a char const *.  This member
// specialization works around them by performing explicit
// conversions.
// -----------------------------------------------------------------

ACE_INLINE char const *
TAO::TypeCode::Field<CORBA::String_var>::get_name (void) const
{
  return this->name.in ();
}
