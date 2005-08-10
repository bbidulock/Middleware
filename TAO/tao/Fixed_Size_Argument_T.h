// This may look like C, but it's really -*- C++ -*-

//=============================================================================
/**
 *  @file    Fixed_Size_Argument_T.h
 *
 *  $Id$
 *
 *  @authors Jeff Parsons and Carlos O'Ryan
 */
//=============================================================================


#ifndef TAO_FIXED_SIZE_ARGUMENT_T_H
#define TAO_FIXED_SIZE_ARGUMENT_T_H

#include /**/ "ace/pre.h"
#include "tao/Argument.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  /**
   * @class In_Fixed_Size_Argument_T
   *
   * @brief Template class for IN stub argument of fixed size IDL types.
   *
   */
  template<typename S,
           typename Insert_Policy>
  class In_Fixed_Size_Argument_T : public InArgument, private Insert_Policy
  {
  public:
    In_Fixed_Size_Argument_T (S const & x);

    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_value (CORBA::Any *any) const;
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    S const & arg (void) const;

  private:
    S const * x_;
  };

  /**
   * @class Inout_Fixed_Size_Argument_T
   *
   * @brief Template class for INOUT stub argument of fixed size IDL types.
   *
   */
  template<typename S,
           typename Insert_Policy>
  class Inout_Fixed_Size_Argument_T : public InoutArgument, private Insert_Policy
  {
  public:
    Inout_Fixed_Size_Argument_T (S & x);

    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_value (CORBA::Any *any) const;
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    S & arg (void);

  private:
    S * x_;
  };

  /**
   * @class Out_Fixed_Size_Argument_T
   *
   * @brief Template class for OUT stub argument of fixed size IDL types.
   *
   */
  template<typename S,
           typename Insert_Policy>
  class Out_Fixed_Size_Argument_T : public OutArgument, private Insert_Policy
  {
  public:
    Out_Fixed_Size_Argument_T (S & x);

    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_value (CORBA::Any *any) const;
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    S & arg (void);

  private:

    S & x_;
  };

  /**
   * @class Ret_Fixed_Size_Argument_T
   *
   * @brief Template class for return stub value of fixed size IDL types.
   *
   */
  template<typename S,
           typename Insert_Policy>
  class Ret_Fixed_Size_Argument_T : public RetArgument, private Insert_Policy
  {
  public:
    Ret_Fixed_Size_Argument_T (void);

    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_value (CORBA::Any *any) const;
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    S & arg (void);

    S excp (void);
    S retn (void);

  protected:
    S x_;
  };

  /**
   * @struct Basic_Tag
   *
   * @brief Struct for fixed size IDL type arguments id tag.
   *
   */
  struct TAO_Export Fixed_Size_Tag {};

  /**
   * @struct Fixed_Size_Arg_Traits_T
   *
   * @brief Template class for argument traits of fixed size IDL types.
   *
   */
  template<typename T,
           typename Insert_Policy>
  struct Fixed_Size_Arg_Traits_T
  {
    typedef T                                            ret_type;
    typedef T const &                                    in_type;
    typedef T &                                          inout_type;
    typedef T &                                          out_type;

    typedef In_Fixed_Size_Argument_T<T,Insert_Policy>    in_arg_val;
    typedef Inout_Fixed_Size_Argument_T<T,Insert_Policy> inout_arg_val;
    typedef Out_Fixed_Size_Argument_T<T,Insert_Policy>   out_arg_val;
    typedef Ret_Fixed_Size_Argument_T<T,Insert_Policy>   ret_val;

    typedef Fixed_Size_Tag                               idl_tag;
  };
}

#if defined (__ACE_INLINE__)
#include "tao/Fixed_Size_Argument_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "tao/Fixed_Size_Argument_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Fixed_Size_Argument_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* TAO_FIXED_SIZE_ARGUMENT_T_H */
