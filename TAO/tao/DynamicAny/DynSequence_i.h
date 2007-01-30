// -*- C++ -*-
//
// $Id$

//=============================================================================
/**
 *  @file    DynSequence_i.h
 *
 *  $Id$
 *
 *  @author Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================


#ifndef TAO_DYNSEQUENCE_I_H
#define TAO_DYNSEQUENCE_I_H
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
 * @class TAO_DynSequence_i
 *
 * Implementation of Dynamic Any type for Sequences.
 */
class TAO_DynamicAny_Export TAO_DynSequence_i
  : public virtual DynamicAny::DynSequence,
    public virtual TAO_DynCommon,
    public virtual TAO_Local_RefCounted_Object
{
public:
  /// Constructor.
  TAO_DynSequence_i (void);

  /// Destructor.
  ~TAO_DynSequence_i (void);

  /// Initialize using just a TypeCode.
  void init (CORBA::TypeCode_ptr tc
            );

  /// Initialize using an Any.
  void init (const CORBA::Any& any
            );

  // = LocalObject methods.
  static TAO_DynSequence_i *_narrow (
      CORBA::Object_ptr obj
      );

  // = Functions specific to DynSequence.

  virtual CORBA::ULong get_length (
      void)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual void set_length (
      CORBA::ULong len
      )

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::InvalidValue
      ));

  virtual DynamicAny::AnySeq * get_elements (
      void)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual void set_elements (
      const DynamicAny::AnySeq & value
      )

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ));

  virtual DynamicAny::DynAnySeq * get_elements_as_dyn_any (
      void)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual void set_elements_as_dyn_any (
      const DynamicAny::DynAnySeq & value
      )

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ));


  // = DynAny common functions not implemented in class TAO_DynCommon.

  virtual void from_any (
      const CORBA::Any & value
      )

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch,
        DynamicAny::DynAny::InvalidValue
      ));

  virtual CORBA::Any * to_any (
      void)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual CORBA::Boolean equal (
      DynamicAny::DynAny_ptr dyn_any
      )

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual void destroy (
      void)

    ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  virtual DynamicAny::DynAny_ptr current_component (
      void)

    ACE_THROW_SPEC ((
        CORBA::SystemException,
        DynamicAny::DynAny::TypeMismatch
      ));

private:
  // Utility, turns the type of elements contained in the sequence.
  CORBA::TypeCode_ptr get_element_type (void);

  // Called by both versions of init().
  void init_common (void);

  // = Use copy() or assign() instead of these
  TAO_DynSequence_i (const TAO_DynSequence_i &src);
  TAO_DynSequence_i &operator= (const TAO_DynSequence_i &src);

private:
  /// Each component is also a DynAny.
  ACE_Array_Base<DynamicAny::DynAny_var> da_members_;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* TAO_DYNSEQUENCE_I_H */
