// -*- C++ -*-

//=============================================================================
/**
 *  @file    Fixed_TypeCode.h
 *
 *  $Id$
 *
 *  Header file for @c CORBA::tk_fixed @c CORBA::TypeCodes.
 *
 *  @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_FIXED_TYPECODE_H
#define TAO_FIXED_TYPECODE_H

#include /**/ "ace/pre.h"

#include "tao/TypeCode.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  namespace TypeCode
  {

    /**
     * @class Fixed
     *
     * @brief @c CORBA::TypeCode implementation for the OMG IDL @fixed
     *        types.
     *
     * This class implements a @c CORBA::TypeCode for the OMG IDL @c
     * fixed types.
     */
    template <class RefCountPolicy>
    class Fixed
      : public CORBA::TypeCode
      , private RefCountPolicy
    {
    public:

      /// Constructor.
      Fixed (CORBA::UShort digits, CORBA::UShort scale);

      /**
       * @name TAO-specific @c CORBA::TypeCode Methods
       *
       * Methods required by TAO's implementation of the
       * @c CORBA::TypeCode class.
       *
       * @see @c CORBA::TypeCode
       */
      //@{
      virtual bool tao_marshal (TAO_OutputCDR & cdr,
                                CORBA::ULong offset) const;
      virtual void tao_duplicate (void);
      virtual void tao_release (void);
      //@}

    protected:

      /**
       * @name @c TAO CORBA::TypeCode Template Methods
       *
       * @c CORBA::TypeCode template methods specific to @c tk_fixed
       * @c TypeCodes.
       *
       * @see @c CORBA::TypeCode
       */
      //@{
      virtual CORBA::Boolean equal_i (CORBA::TypeCode_ptr tc
                                      ACE_ENV_ARG_DECL) const;
      virtual CORBA::Boolean equivalent_i (CORBA::TypeCode_ptr tc
                                           ACE_ENV_ARG_DECL) const;
      virtual CORBA::TypeCode_ptr get_compact_typecode_i (
        ACE_ENV_SINGLE_ARG_DECL) const;
      virtual CORBA::UShort fixed_digits_i (ACE_ENV_SINGLE_ARG_DECL) const;
      virtual CORBA::UShort fixed_scale_i (ACE_ENV_SINGLE_ARG_DECL) const;

    private:

      /// The number of significant digits.
      CORBA::UShort const digits_;

      /// The scale factor.
      CORBA::UShort const scale_;

    };

  }  // End namespace TypeCode
}  // End namespace TAO


#ifdef __ACE_INLINE__
# include "tao/Fixed_TypeCode.inl"
#endif  /* __ACE_INLINE__ */

#ifdef ACE_TEMPLATES_REQUIRE_SOURCE
# include "tao/Fixed_TypeCode.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#ifdef ACE_TEMPLATES_REQUIRE_PRAGMA
# pragma implementation ("Fixed_TypeCode.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */


#include /**/ "ace/post.h"

#endif /* TAO_FIXED_TYPECODE_H */
