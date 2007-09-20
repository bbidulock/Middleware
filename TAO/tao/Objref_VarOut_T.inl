// -*- C++ -*-
//
// $Id$

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
template <typename T>
TAO_Objref_Var_T<T>::TAO_Objref_Var_T (void)
  : ptr_ (TAO::Objref_Traits<T>::nil ())
{
}

ACE_INLINE
template <typename T>
TAO_Objref_Var_T<T>::~TAO_Objref_Var_T (void)
{
  TAO::Objref_Traits<T>::release (this->ptr_);
}

ACE_INLINE
template <typename T>
T *
TAO_Objref_Var_T<T>::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE
template <typename T>
TAO_Objref_Var_T<T>::operator T * const & () const
{
  return this->ptr_;
}

ACE_INLINE
template <typename T>
TAO_Objref_Var_T<T>::operator T *& ()
{
  return this->ptr_;
}

ACE_INLINE
template <typename T>
T *
TAO_Objref_Var_T<T>::in (void) const
{
  return this->ptr_;
}

ACE_INLINE
template <typename T>
T *&
TAO_Objref_Var_T<T>::inout (void)
{
  return this->ptr_;
}

ACE_INLINE
template <typename T>
T *&
TAO_Objref_Var_T<T>::out (void)
{
  TAO::Objref_Traits<T>::release (this->ptr_);
  this->ptr_ = TAO::Objref_Traits<T>::nil ();
  return this->ptr_;
}

ACE_INLINE
template <typename T>
T *
TAO_Objref_Var_T<T>::_retn (void)
{
  T * val = this->ptr_;
  this->ptr_ = TAO::Objref_Traits<T>::nil ();
  return val;
}

ACE_INLINE
template <typename T>
T *
TAO_Objref_Var_T<T>::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
template <typename T>
void
TAO_Objref_Var_T<T>::free (void)
{
  TAO::Objref_Traits<T>::release (this->ptr_);
}

ACE_INLINE
template <typename T>
void
TAO_Objref_Var_T<T>::reset (T * p)
{
  TAO::Objref_Traits<T>::release (this->ptr_);
  this->ptr_ = p;
}

// ******************************************************

ACE_INLINE
template <typename T>
TAO_Objref_Out_T<T>::TAO_Objref_Out_T (T *& p)
  : ptr_ (p)
{
  this->ptr_ = TAO::Objref_Traits<T>::nil ();
}

ACE_INLINE
template <typename T>
TAO_Objref_Out_T<T>::TAO_Objref_Out_T (
    TAO_Objref_Var_T<T> & p
  )
  : ptr_ (p.out ())
{
  TAO::Objref_Traits<T>::release (this->ptr_);
  this->ptr_ = TAO::Objref_Traits<T>::nil ();
}

ACE_INLINE
template <typename T>
TAO_Objref_Out_T<T>::TAO_Objref_Out_T (
    const TAO_Objref_Out_T<T> & p
  )
  : ptr_ (p.ptr_)
{
}

ACE_INLINE
template <typename T>
TAO_Objref_Out_T<T> &
TAO_Objref_Out_T<T>::operator= (
    const TAO_Objref_Out_T<T> & p
  )
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE
template <typename T>
TAO_Objref_Out_T<T> &
TAO_Objref_Out_T<T>::operator= (T * p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
template <typename T>
T *&
TAO_Objref_Out_T<T>::ptr (void)
{
  return this->ptr_;
}

ACE_INLINE
template <typename T>
TAO_Objref_Out_T<T>::operator T *& ()
{
  return this->ptr_;
}

ACE_INLINE
template <typename T>
T *
TAO_Objref_Out_T<T>::operator-> (void)
{
  return this->ptr_;
}

TAO_END_VERSIONED_NAMESPACE_DECL

