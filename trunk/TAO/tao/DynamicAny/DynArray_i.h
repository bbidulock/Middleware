// -*- C++ -*-

// $Id$

//=============================================================================
/**
 *  @file    DynArray_i.h
 *
 *  $Id$
 *
 *  @author Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_DYNARRAY_I_H
#define TAO_DYNARRAY_I_H
#include /**/ "ace/pre.h"

#include "tao/DynamicAny/DynamicAny.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/DynamicAny/DynCommon.h"
#include "tao/LocalObject.h"
#include "ace/Containers.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class TAO_DynArray_i
 *
 * Implementation of Dynamic Any type for arrays
 */
class TAO_DynamicAny_Export TAO_DynArray_i
  : public virtual DynamicAny::DynArray,
    public virtual TAO_DynCommon,
    public virtual TAO_Local_RefCounted_Object
{
public:
  /// Constructor.
  TAO_DynArray_i (void);

  /// Destructor.
  ~TAO_DynArray_i (void);

  /// Initialize using just a TypeCode.
  void init (CORBA::TypeCode_ptr tc
             ACE_ENV_ARG_DECL);

  /// Initialize using an Any.
  void init (const CORBA::Any& any
             ACE_ENV_ARG_DECL);

  // = LocalObject methods
  static TAO_DynArray_i *_narrow (
      CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  // = Functions specific to DynArray.

  virtual DynamicAny::AnySeq * get_elements (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual void set_elements (
      const DynamicAny::AnySeq & value
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ));

  virtual DynamicAny::DynAnySeq * get_elements_as_dyn_any (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual void set_elements_as_dyn_any (
      const DynamicAny::DynAnySeq & value
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ));

  // = DynAny common functions not implemented in class TAO_DynCommon.

  virtual void from_any (
      const CORBA::Any & value
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
    ));

  virtual CORBA::Any * to_any (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual CORBA::Boolean equal (
      DynamicAny::DynAny_ptr dyn_any
      ACE_ENV_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual void destroy (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual DynamicAny::DynAny_ptr current_component (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch
      ));

private:
  /// Returns the type of elements contained in the array.
  CORBA::TypeCode_ptr get_element_type (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS);

  /// Gets the length of the array from the typecode.
  CORBA::ULong get_tc_length (CORBA::TypeCode_ptr tc
                              ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  /// Called by both versions of init().
  void init_common (void);

  // Use copy() or assign() instead of these.
  TAO_DynArray_i (const TAO_DynArray_i &src);
  TAO_DynArray_i &operator= (const TAO_DynArray_i &src);

private:
  /// Each component is also a DynAny.
  ACE_Array_Base<DynamicAny::DynAny_var> da_members_;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* TAO_DYNARRAY_I_H */
