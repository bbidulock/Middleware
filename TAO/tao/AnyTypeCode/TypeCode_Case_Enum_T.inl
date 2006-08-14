// -*- C++ -*-
//
// $Id$


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename StringType,
          typename TypeCodeType>
ACE_INLINE
TAO::TypeCode::Case_Enum_T<StringType,
                           TypeCodeType>::Case_Enum_T (CORBA::TypeCode_ptr
discriminator_tc,
                                                       CORBA::ULong member_label,
                                                       char const * member_name,
                                                       TypeCodeType member_type)
  : Case<StringType, TypeCodeType> (member_name, member_type)
  , discriminator_tc_( CORBA::TypeCode::_duplicate (discriminator_tc) )
  , label_ (member_label)
{
}

template <typename StringType,
          typename TypeCodeType>
ACE_INLINE
TAO::TypeCode::Case_Enum_T<StringType,
                           TypeCodeType>::Case_Enum_T (CORBA::TypeCode_ptr
discriminator_tc,
                                                       CORBA::ULong member_label)
  : Case<StringType, TypeCodeType> ()
  , discriminator_tc_( CORBA::TypeCode::_duplicate (discriminator_tc) )
  , label_ (member_label)
{
}

TAO_END_VERSIONED_NAMESPACE_DECL
