// $Id$

#ifndef TAO_BD_STRING_ARGUMENT_T_CPP
#define TAO_BD_STRING_ARGUMENT_T_CPP

#include "tao/BD_String_Argument_T.h"

#if !defined (__ACE_INLINE__)
#include "tao/BD_String_Argument_T.inl"
#endif /* __ACE_INLINE__ */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
CORBA::Boolean
TAO::In_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::marshal (
    TAO_OutputCDR & cdr
  )
{
  return cdr << from_S (this->x_, BOUND);
}

#if TAO_HAS_INTERCEPTORS == 1

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
void
TAO::In_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::interceptor_value (
  CORBA::Any *any) const
{
  Insert_Policy<from_S>::any_insert (any, from_S (this->x_, BOUND));
}

#endif /* TAO_HAS_INTERCEPTORS */

// ===========================================================

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
CORBA::Boolean
TAO::Inout_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::marshal (
    TAO_OutputCDR & cdr
  )
{
  return cdr << from_S (this->x_, BOUND);
}

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
CORBA::Boolean
TAO::Inout_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::demarshal (
    TAO_InputCDR & cdr
  )
{
  delete [] this->x_;
  return cdr >> to_S (this->x_, BOUND);
}

#if TAO_HAS_INTERCEPTORS == 1

template<typename S,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
void
TAO::Inout_BD_String_Argument_T<S,to_S,from_S,BOUND,Insert_Policy>::interceptor_value (
  CORBA::Any *any) const
{
  Insert_Policy<from_S>::any_insert (any, from_S (this->x_, BOUND));
}

#endif /* TAO_HAS_INTERCEPTORS */

// ==============================================================

template<typename S,
         typename S_out,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
CORBA::Boolean
TAO::Out_BD_String_Argument_T<S,S_out,to_S,from_S,BOUND,Insert_Policy>::demarshal (
    TAO_InputCDR & cdr
  )
{
  return cdr >> to_S (this->x_, BOUND);
}

#if TAO_HAS_INTERCEPTORS == 1

template<typename S,
         typename S_out,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
void
TAO::Out_BD_String_Argument_T<S,S_out,to_S,from_S,BOUND,Insert_Policy>::interceptor_value (
  CORBA::Any *any) const
{
  Insert_Policy<from_S>::any_insert (any, from_S (this->x_, BOUND));
}

#endif /* TAO_HAS_INTERCEPTORS */

// ============================================================

template<typename S,
         typename S_var,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
CORBA::Boolean
TAO::Ret_BD_String_Argument_T<S,S_var,to_S,from_S,BOUND,Insert_Policy>::demarshal (
    TAO_InputCDR & cdr
  )
{
  return cdr >> to_S (this->x_.out (), BOUND);
}

#if TAO_HAS_INTERCEPTORS == 1

template<typename S,
         typename S_var,
         typename to_S,
         typename from_S,
         size_t BOUND,
         template <typename> class Insert_Policy>
void
TAO::Ret_BD_String_Argument_T<S,S_var,to_S,from_S,BOUND,Insert_Policy>::interceptor_value (
  CORBA::Any *any) const
{
  Insert_Policy<from_S>::any_insert (any, from_S (this->x_.in (), BOUND));
}

#endif /* TAO_HAS_INTERCEPTORS */

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* TAO_BD_STRING_ARGUMENT_T_CPP */
