// $Id$

#ifndef TAO_UNION_TYPECODE_CPP
#define TAO_UNION_TYPECODE_CPP

#include "tao/Union_TypeCode.h"
#include "tao/TypeCode_Case.h"

#ifndef __ACE_INLINE__
# include "tao/Union_TypeCode.inl"
#endif  /* !__ACE_INLINE__ */

#include "tao/SystemException.h"

#include "ace/Value_Ptr.h"


template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
bool
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::tao_marshal (
  TAO_OutputCDR & cdr) const
{
  // A tk_union TypeCode has a "complex" parameter list type (see
  // Table 15-2 in Section 15.3.5.1 "TypeCode" in the CDR section of
  // the CORBA specification), meaning that it must be marshaled into
  // a CDR encapsulation.

  CORBA::ULong const count = this->case_count ();

  // Create a CDR encapsulation.
  TAO_OutputCDR enc;

  bool const success =
    (enc << TAO_OutputCDR::from_boolean (TAO_ENCAP_BYTE_ORDER))
    && (enc << TAO_OutputCDR::from_string (this->base_attributes_.id (), 0))
    && (enc << TAO_OutputCDR::from_string (this->base_attributes_.name (), 0))
    && (enc << Traits<StringType>::get_typecode (this->discriminant_type_))
    && (enc << this->default_index_)
    && (enc << count);

  if (!success)
    return false;

  // Note that we handle the default case below, too.

  for (unsigned int i = 0; i < count; ++i)
    {
      case_type const & c = this->the_case (i);

      if (!c.marshal (enc))
        return false;
    }

  return
    cdr << static_cast<CORBA::ULong> (enc.total_length ())
    && cdr.write_octet_array_mb (enc.begin ());
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
void
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::tao_duplicate (void)
{
  this->RefCountPolicy::add_ref ();
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
void
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::tao_release (void)
{
  this->RefCountPolicy::remove_ref ();
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
CORBA::Boolean
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::equal_i (
  CORBA::TypeCode_ptr tc
  ACE_ENV_ARG_DECL) const
{
  // These calls shouldn't throw since CORBA::TypeCode::equal()
  // verified that the TCKind is the same as our's prior to invoking
  // this method, meaning that the CORBA::tk_union TypeCode methods
  // are supported.

  CORBA::ULong const tc_count =
    tc->member_count (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Long tc_def = tc->default_index (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::ULong const this_count = this->case_count ();

  if (tc_count != this_count
      || tc_def != this->default_index_)
    return 0;

  // Check the discriminator type.
  CORBA::TypeCode_var tc_discriminator =
    tc->discriminator_type (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Boolean const equal_discriminators =
    (*this->discriminant_type_)->equal (tc_discriminator.in ()
                                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (!equal_discriminators)
    return 0;

  for (CORBA::ULong i = 0; i < this_count; ++i)
    {
      case_type const & lhs_case = this->the_case (i);

      bool const equal_case =
        lhs_case.equal (i,
                        tc
                        ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (!equal_case)
        return 0;
    }

  return 1;
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
CORBA::Boolean
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::equivalent_i (
  CORBA::TypeCode_ptr tc
  ACE_ENV_ARG_DECL) const
{
  // Perform a structural comparison, excluding the name() and
  // member_name() operations.

  CORBA::ULong const tc_count =
    tc->member_count (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Long tc_def = tc->default_index (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::ULong const this_count = this->case_count ();

  if (tc_count != this_count
      || tc_def != this->default_index_)
    return 0;

  CORBA::TypeCode_var tc_discriminator =
    tc->discriminator_type (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Boolean const equiv_discriminators =
    (*this->discriminant_type_)->equivalent (tc_discriminator.in ()
                                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (!equiv_discriminators)
    return 0;

  for (CORBA::ULong i = 0; i < this_count; ++i)
    {
      case_type const & lhs_case = this->the_case (i);

      bool const equivalent_case =
        lhs_case.equivalent (i,
                             tc
                             ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (0);

      if (!equivalent_case)
        return 0;
    }

  return 1;
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
CORBA::TypeCode_ptr
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::get_compact_typecode_i (
  ACE_ENV_SINGLE_ARG_DECL) const
{
//   typedef ACE::Value_Ptr<TAO::TypeCode::Case<CORBA::String_var,
//                                              CORBA::TypeCode_var> > elem_type;

//   ACE_Array_Base<elem_type> tc_cases (this->ncases_);

//   if (this->ncases_ > 0)
//     {
//       // Dynamically construct a new array of cases stripped of
//       // member names.

//       static char const empty_name[] = "";

//       for (CORBA::ULong i = 0; i < this->ncases_; ++i)
//         {
//           // Member names will be stripped, i.e. not embedded within
//           // the compact TypeCode.
//           tc_cases[i].name = empty_name;
//           tc_cases[i].type =
//             Traits<StringType>::get_typecode (
//               this->the_case (i).type)->get_compact_typecode (
//                 ACE_ENV_ARG_PARAMETER);
//           ACE_CHECK_RETURN (CORBA::TypeCode::_nil ());
//         }
//     }

//   // Create the compact union TypeCode.
//   TAO_TypeCodeFactory_Adapter * adapter =
//     ACE_Dynamic_Service<TAO_TypeCodeFactory_Adapter>::instance (
//       TAO_ORB_Core::typecodefactory_adapter_name ());

//   if (adapter == 0)
//     {
//       ACE_THROW_RETURN (CORBA::INTERNAL (),
//                         CORBA::TypeCode::_nil ());
//     }

//   return
//     adapter->create_union_tc (
//       this->base_attributes_.id (),
//       "",  /* empty name */
//       Traits<StringType>::get_typecode (this->discriminant_type_),
//       tc_cases,
//       this->ncases_,
//       this->default_index_,
//       "",
//       Traits<StringType>::get_typecode (this->default_case_.type)
//       ACE_ENV_ARG_PARAMETER);
//   ACE_CHECK_RETURN (CORBA::TypeCode::_nil ());

  ACE_THROW_RETURN (CORBA::NO_IMPLEMENT (), CORBA::TypeCode::_nil ());

  return CORBA::TypeCode::_nil ();
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
char const *
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::id_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  // Ownership is retained by the TypeCode, as required by the C++
  // mapping.
  return this->base_attributes_.id ();
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
char const *
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::name_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  // Ownership is retained by the TypeCode, as required by the C++
  // mapping.
  return this->base_attributes_.name ();
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
CORBA::ULong
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                      CaseArrayType,
                      RefCountPolicy>::member_count_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return this->case_count ();
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
char const *
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::member_name_i (CORBA::ULong index
                                                     ACE_ENV_ARG_DECL) const
{
  // Ownership is retained by the TypeCode, as required by the C++
  // mapping.
  if (index >= this->case_count ())
    ACE_THROW_RETURN (CORBA::TypeCode::Bounds (), 0);

  return Traits<StringType>::get_string (this->the_case (index).name ());
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
CORBA::TypeCode_ptr
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::member_type_i (CORBA::ULong index
                                                     ACE_ENV_ARG_DECL) const
{
  if (index >= this->case_count ())
    ACE_THROW_RETURN (CORBA::TypeCode::Bounds (),
                      CORBA::TypeCode::_nil ());

  return CORBA::TypeCode::_duplicate (this->the_case (index).type ());
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
CORBA::Any *
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::member_label_i (CORBA::ULong index
                                                      ACE_ENV_ARG_DECL) const
{
  if (index >= this->case_count ())
    ACE_THROW_RETURN (CORBA::TypeCode::Bounds (),
                      0);

  return this->the_case (index).label (ACE_ENV_SINGLE_ARG_PARAMETER);
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
CORBA::TypeCode_ptr
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::discriminator_type_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return
    CORBA::TypeCode::_duplicate (
      Traits<StringType>::get_typecode (this->discriminant_type_));
}

template <typename StringType,
          typename TypeCodeType,
          class CaseArrayType,
          class RefCountPolicy>
CORBA::Long
TAO::TypeCode::Union<StringType,
                     TypeCodeType,
                     CaseArrayType,
                     RefCountPolicy>::default_index_i (
  ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return this->default_index_;
}

#endif  /* TAO_UNION_TYPECODE_CPP */
