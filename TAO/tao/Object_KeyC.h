// -*- c++ -*-
// $Id$
//
// Hand-modified by Chris Cleeland.
//
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#ifndef TAO_IDL_OBJECT_KEYC_H
#define TAO_IDL_OBJECT_KEYC_H

#include "tao/corbafwd.h"
#include "tao/Sequence.h"

class TAO_Export TAO_ObjectKey : public TAO_Unbounded_Sequence<CORBA::Octet>
{
  // = TITLE
  //   TAO class used to represent Object Keys
  //
  // = DESCRIPTION
  //   The object is basically a sequence of octets, but we derive
  //   from it to create a unique type; this is useful for
  //   overloading.
  //
public:
  #if !defined(__GNUC__) || __GNUC__ > 2 || __GNUC_MINOR__ >= 8
    typedef TAO_ObjectKey_ptr _ptr_type;
    typedef TAO_ObjectKey_var _var_type;
  #endif /* __GNUC__ */

  TAO_ObjectKey (void);
  TAO_ObjectKey (CORBA::ULong max);
  TAO_ObjectKey (CORBA::ULong max,
                  CORBA::ULong length,
                  CORBA::Octet *data,
                  CORBA::Boolean release = 0);
  TAO_ObjectKey (const TAO_ObjectKey &);
  TAO_ObjectKey& operator= (const TAO_ObjectKey &);
};

class TAO_ObjectKey_var
{
public:
  TAO_ObjectKey_var (void); // default constructor
  TAO_ObjectKey_var (TAO_ObjectKey *);
  TAO_ObjectKey_var (const TAO_ObjectKey_var &); // copy constructor
  ~TAO_ObjectKey_var (void); // destructor

  TAO_ObjectKey_var &operator= (TAO_ObjectKey *);
  TAO_ObjectKey_var &operator= (const TAO_ObjectKey_var &);
  TAO_ObjectKey *operator-> (void);
  const TAO_ObjectKey *operator-> (void) const;

  operator const TAO_ObjectKey &() const;
  operator TAO_ObjectKey &();
  operator TAO_ObjectKey &() const;
  CORBA::Octet &operator[] (CORBA::ULong index);
  // in, inout, out, _retn
  const TAO_ObjectKey &in (void) const;
  TAO_ObjectKey &inout (void);
  TAO_ObjectKey *&out (void);
  TAO_ObjectKey *_retn (void);
  TAO_ObjectKey *ptr (void) const;

private:
  TAO_ObjectKey *ptr_;
};

class TAO_ObjectKey_out
{
public:
  TAO_ObjectKey_out (TAO_ObjectKey *&);
  TAO_ObjectKey_out (TAO_ObjectKey_var &);
  TAO_ObjectKey_out (TAO_ObjectKey_out &);
  TAO_ObjectKey_out &operator= (TAO_ObjectKey_out &);
  TAO_ObjectKey_out &operator= (TAO_ObjectKey *);
  operator TAO_ObjectKey *&();
  TAO_ObjectKey *&ptr (void);
  TAO_ObjectKey *operator-> (void);
  CORBA::Octet &operator[] (CORBA::ULong index);

private:
  TAO_ObjectKey *&ptr_;
  // assignment from T_var not allowed
  void operator= (const TAO_ObjectKey_var &);
};

#if defined (__ACE_INLINE__)
#include "tao/Object_KeyC.i"
#endif /* __ACE_INLINE__ */

#endif /* TAO_IDL_OBJECT_KEYC_H */
