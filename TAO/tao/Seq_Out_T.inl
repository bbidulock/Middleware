// -*- C++ -*-
//
//$Id$

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

template<typename T, typename T_var>
ACE_INLINE
TAO_Seq_Out_T<T,T_var>::TAO_Seq_Out_T (T *& p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

template<typename T, typename T_var>
ACE_INLINE
TAO_Seq_Out_T<T,T_var>::TAO_Seq_Out_T (T_var & p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

template<typename T, typename T_var>
ACE_INLINE
TAO_Seq_Out_T<T,T_var>::TAO_Seq_Out_T (
    const TAO_Seq_Out_T<T,T_var> & p
  )
  : ptr_ (p.ptr_)
{}

template<typename T, typename T_var>
ACE_INLINE
TAO_Seq_Out_T<T,T_var> &
TAO_Seq_Out_T<T,T_var>::operator= (
    const TAO_Seq_Out_T<T,T_var> & p
  )
{
  this->ptr_ = p.ptr_;
  return *this;
}

template<typename T, typename T_var>
ACE_INLINE
TAO_Seq_Out_T<T,T_var> &
TAO_Seq_Out_T<T,T_var>::operator= (T * p)
{
  this->ptr_ = p;
  return *this;
}

template<typename T, typename T_var>
ACE_INLINE
TAO_Seq_Out_T<T,T_var>::operator T *& ()
{
  return this->ptr_;
}

template<typename T, typename T_var>
ACE_INLINE
T *&
TAO_Seq_Out_T<T,T_var>::ptr (void)
{
  return this->ptr_;
}

template<typename T, typename T_var>
ACE_INLINE
T *
TAO_Seq_Out_T<T,T_var>::operator-> (void)
{
  return this->ptr_;
}

template<typename T, typename T_var>
ACE_INLINE
T::element_type &
TAO_Seq_Out_T<T,T_var>::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

// ****************************************************************
template<typename T, typename T_var>
ACE_INLINE
TAO_MngSeq_Out_T<T,T_var>::TAO_MngSeq_Out_T (T *& p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

template<typename T, typename T_var>
ACE_INLINE
TAO_MngSeq_Out_T<T,T_var>::TAO_MngSeq_Out_T (T_var & p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

template<typename T, typename T_var>
ACE_INLINE
TAO_MngSeq_Out_T<T,T_var>::TAO_MngSeq_Out_T (
    const TAO_MngSeq_Out_T<T,T_var> & p
  )
  : ptr_ (p.ptr_)
{}

template<typename T, typename T_var>
ACE_INLINE
TAO_MngSeq_Out_T<T,T_var> &
TAO_MngSeq_Out_T<T,T_var>::operator= (
    const TAO_MngSeq_Out_T<T,T_var> & p
  )
{
  this->ptr_ = p.ptr_;
  return *this;
}

template<typename T, typename T_var>
ACE_INLINE
TAO_MngSeq_Out_T<T,T_var> &
TAO_MngSeq_Out_T<T,T_var>::operator= (T * p)
{
  this->ptr_ = p;
  return *this;
}

template<typename T, typename T_var>
ACE_INLINE
TAO_MngSeq_Out_T<T,T_var>::operator T *& ()
{
  return this->ptr_;
}

template<typename T, typename T_var>
ACE_INLINE
T *&
TAO_MngSeq_Out_T<T,T_var>::ptr (void)
{
  return this->ptr_;
}

template<typename T, typename T_var>
ACE_INLINE
T *
TAO_MngSeq_Out_T<T,T_var>::operator-> (void)
{
  return this->ptr_;
}

template<typename T, typename T_var>
ACE_INLINE
T::element_type
TAO_MngSeq_Out_T<T,T_var>::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

TAO_END_VERSIONED_NAMESPACE_DECL
