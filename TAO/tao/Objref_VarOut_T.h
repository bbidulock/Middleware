// -*- C++ -*-

//=============================================================================
/**
 *  @file    Objref_VarOut_T.h
 *
 *  $Id$
 *
 *  @author Jeff Parsons
 */
//=============================================================================


#ifndef TAO_OBJREF_VAROUT_T_H
#define TAO_OBJREF_VAROUT_T_H

#include "ace/pre.h"

#include "tao/varbase.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/CORBA_macros.h"

/**
 * @class TAO_Objref_Var_T
 *
 * @brief Parametrized implementation of _var class for object references.
 *
 */

template <typename T, typename T_life>
class TAO_Objref_Var_T : private TAO_Base_var
{
public:
  TAO_Objref_Var_T (void);
  TAO_Objref_Var_T (T * p) : ptr_ (p) {}
  TAO_Objref_Var_T (const TAO_Objref_Var_T<T, T_life> &);
  ~TAO_Objref_Var_T (void);

  TAO_Objref_Var_T<T, T_life> & operator= (T *);
  TAO_Objref_Var_T<T, T_life> & operator= (
      const TAO_Objref_Var_T<T, T_life> &
    );
  T * operator-> (void) const;

  // Cast operators.
  operator const T *& () const;
  operator T *& ();

  T * in (void) const;
  T *& inout (void);
  T *& out (void);
  T * _retn (void);

  // TAO extension. 
  T * ptr (void) const;

protected:
  T * ptr_;
  void free (void);
  void reset (T *);

private:
  // Unimplemented - prevents widening assignment.
  TAO_Objref_Var_T (const TAO_Base_var &);
  void operator= (const TAO_Base_var &);
};

/**
 * @class TAO_Objref_Out_T
 *
 * @brief Parametrized implementation of _out class for object references.
 *
 */
template <typename T, typename T_life>
class TAO_Objref_Out_T
{
public:
  TAO_Objref_Out_T (T *&);
  TAO_Objref_Out_T (TAO_Objref_Var_T<T, T_life> &);
  TAO_Objref_Out_T (const TAO_Objref_Out_T<T, T_life> &);

  TAO_Objref_Out_T &operator= (const TAO_Objref_Out_T<T, T_life> &);
  TAO_Objref_Out_T &operator= (const TAO_Objref_Var_T<T, T_life> &);
  TAO_Objref_Out_T &operator= (T *);

  // Cast operator.
  operator T *& ();

  T *& ptr (void);
  T * operator-> (void);

private:
  typedef TAO_Objref_Out_T<T, T_life> THIS_OUT_TYPE;
  T *& ptr_;
};

#if defined (__ACE_INLINE__)
#include "tao/Objref_Varout_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "tao/Objref_Varout_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Objref_Varout_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include "ace/post.h"

#endif /* TAO_OBJREF_VAROUT_T_H */
