// -*- C++ -*-
//
// $Id$

template <typename TypeCodeType, class RefCountPolicy>
ACE_INLINE
TAO::TypeCode::Sequence<TypeCodeType, RefCountPolicy>::Sequence (
  CORBA::TCKind kind,
#ifdef __BORLANDC__
  // Borland C++ currently can't handle a reference to
  // const pointer to const CORBA::TypeCode_ptr
  TypeCodeType content_type,
#else
  TypeCodeType const & content_type,
#endif
  CORBA::ULong length)
  : CORBA::TypeCode (kind)
  , RefCountPolicy ()
  , content_type_ (content_type)
  , length_ (length)
{
  // ACE_ASSERT (kind == CORBA::tk_array || kind == CORBA::tk_sequence);
}
