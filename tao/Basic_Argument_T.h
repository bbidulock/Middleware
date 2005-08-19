// -*- C++ -*-

//=============================================================================
/**
 *  @file    Basic_Argument_T.h
 *
 *  $Id$
 *
 *  @authors Jeff Parsons and Carlos O'Ryan
 */
//=============================================================================


#ifndef TAO_BASIC_ARGUMENT_T_H
#define TAO_BASIC_ARGUMENT_T_H

#include /**/ "ace/pre.h"

#include "tao/Argument.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  /**
   * @class In_Basic_Argument_T
   *
   * @brief Template class for IN stub argument of basic IDL types.
   *
   * @todo
   * We really would have liked to write the code as following but MSVC6 chokes
   * on this, so we can only do this after x.5.1 has been dropped.
   *
   * template <typename S, template <typename T> class Insert_Policy>
   * class In_Basic_Argument_T : public InArgument, private Insert_Policy <S>
   * { .. };
   */
  template<typename S, typename Insert_Policy>
  class In_Basic_Argument_T : public InArgument, private Insert_Policy
  {
  public:
    In_Basic_Argument_T (S const & x);

    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_value (CORBA::Any *any) const;
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    S arg (void) const;

  private:
    S const & x_;
  };

  /**
   * @class Inout_Basic_Argument_T
   *
   * @brief Template class for INOUT stub argument of basic IDL types.
   *
   */
  template<typename S, typename Insert_Policy>
  class Inout_Basic_Argument_T : public InoutArgument, private Insert_Policy
  {
  public:
    Inout_Basic_Argument_T (S & x);

    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_value (CORBA::Any *any) const;
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    S & arg (void);

  private:
    S & x_;
  };

  /**
   * @class Out_Basic_Argument_T
   *
   * @brief Template class for OUT stub argument of basic IDL types.
   *
   */
  template<typename S, typename Insert_Policy>
  class Out_Basic_Argument_T : public OutArgument, private Insert_Policy
  {
  public:
    Out_Basic_Argument_T (S & x);

    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_value (CORBA::Any *any) const;
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    S & arg (void);

  private:
    S & x_;
  };

  /**
   * @class Ret_Basic_Argument_T
   *
   * @brief Template class for return stub value of basic IDL types.
   *
   */
  template<typename S, typename Insert_Policy>
  class Ret_Basic_Argument_T : public RetArgument, private Insert_Policy
  {
  public:
    Ret_Basic_Argument_T (void);

    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_value (CORBA::Any *any) const;
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    S & arg (void);

    S excp (void);
    S retn (void);

  private:
    S x_;
  };

  /**
   * @struct Basic_Tag
   *
   * @brief Struct for basic IDL type arguments id tag.
   *
   */
  struct TAO_Export Basic_Tag {};

  /**
   * @struct Basic_Arg_Traits_T
   *
   * @brief Template class for stub argument traits of basic IDL types.
   *
   */
  template<typename T, typename Insert_Policy>
  struct Basic_Arg_Traits_T
  {
    typedef T                                          ret_type;
    typedef T                                          in_type;
    typedef T &                                        inout_type;
    typedef T &                                        out_type;

    typedef In_Basic_Argument_T<T, Insert_Policy>      in_arg_val;
    typedef Inout_Basic_Argument_T<T, Insert_Policy>   inout_arg_val;
    typedef Out_Basic_Argument_T<T, Insert_Policy>     out_arg_val;
    typedef Ret_Basic_Argument_T<T, Insert_Policy>     ret_val;

    typedef Basic_Tag                                  idl_tag;
  };
}

#if defined (__ACE_INLINE__)
#include "tao/Basic_Argument_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "tao/Basic_Argument_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Basic_Argument_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* TAO_BASIC_ARGUMENT_T_H */
