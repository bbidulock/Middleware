// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


#if !defined (TAO_OCTETSEQ_CI)
#define TAO_OCTETSEQ_CI

// *************************************************************
// Inline operations for class CORBA_OctetSeq_var
// *************************************************************

ACE_INLINE
CORBA_OctetSeq_var::CORBA_OctetSeq_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_OctetSeq_var::CORBA_OctetSeq_var (CORBA_OctetSeq *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_OctetSeq_var::CORBA_OctetSeq_var (const ::CORBA_OctetSeq_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::CORBA_OctetSeq (*p.ptr_));
  else
    this->ptr_ = 0;
}

// fixed-size base types only
ACE_INLINE
CORBA_OctetSeq_var::CORBA_OctetSeq_var (const ::CORBA_OctetSeq &p)
{
  ACE_NEW (this->ptr_, ::CORBA_OctetSeq (p));
}

ACE_INLINE
CORBA_OctetSeq_var::~CORBA_OctetSeq_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_OctetSeq_var &
CORBA_OctetSeq_var::operator= (CORBA_OctetSeq *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_OctetSeq_var &
CORBA_OctetSeq_var::operator= (const ::CORBA_OctetSeq_var &p) // deep copy
{
  if (this != &p)
    {
      if (p.ptr_ == 0)
        {
          delete this->ptr_;
          this->ptr_ = 0;
        }
      else
        {
          CORBA_OctetSeq *deep_copy = new CORBA_OctetSeq (*p.ptr_);
          
          if (deep_copy != 0)
            {
              CORBA_OctetSeq *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

// fixed-size types only
ACE_INLINE ::CORBA_OctetSeq_var &
CORBA_OctetSeq_var::operator= (const ::CORBA_OctetSeq &p)
{
  if (this->ptr_ != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, ::CORBA_OctetSeq (p), *this);
  }
  return *this;
}

ACE_INLINE const ::CORBA_OctetSeq *
CORBA_OctetSeq_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_OctetSeq *
CORBA_OctetSeq_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
CORBA_OctetSeq_var::operator const ::CORBA_OctetSeq &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
CORBA_OctetSeq_var::operator ::CORBA_OctetSeq &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
CORBA_OctetSeq_var::operator ::CORBA_OctetSeq &() const // cast 
{
  return *this->ptr_;
}

ACE_INLINE CORBA::Octet &
CORBA_OctetSeq_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const CORBA::Octet &
CORBA_OctetSeq_var::operator[] (CORBA::ULong index) const
{
  return ACE_const_cast (const CORBA::Octet &, this->ptr_->operator[] (index));
}

ACE_INLINE const ::CORBA_OctetSeq &
CORBA_OctetSeq_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CORBA_OctetSeq &
CORBA_OctetSeq_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE ::CORBA_OctetSeq *&
CORBA_OctetSeq_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CORBA_OctetSeq *
CORBA_OctetSeq_var::_retn (void)
{
  ::CORBA_OctetSeq *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CORBA_OctetSeq *
CORBA_OctetSeq_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_OctetSeq_out
// *************************************************************

ACE_INLINE
CORBA_OctetSeq_out::CORBA_OctetSeq_out (CORBA_OctetSeq *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_OctetSeq_out::CORBA_OctetSeq_out (CORBA_OctetSeq_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_OctetSeq_out::CORBA_OctetSeq_out (const ::CORBA_OctetSeq_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_OctetSeq_out&, p).ptr_)
{}

ACE_INLINE ::CORBA_OctetSeq_out &
CORBA_OctetSeq_out::operator= (const ::CORBA_OctetSeq_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_OctetSeq_out&, p).ptr_;
  return *this;
}

ACE_INLINE ::CORBA_OctetSeq_out &
CORBA_OctetSeq_out::operator= (CORBA_OctetSeq *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_OctetSeq_out::operator ::CORBA_OctetSeq *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_OctetSeq *&
CORBA_OctetSeq_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_OctetSeq *
CORBA_OctetSeq_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::Octet &
CORBA_OctetSeq_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}


#endif /* end #if !defined */


#if !defined TAO_TAO_CDR_OP_CORBA_OctetSeq_I
#define TAO_TAO_CDR_OP_CORBA_OctetSeq_I

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const CORBA_OctetSeq &
  );
CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    CORBA_OctetSeq &
  );

#endif /* TAO_TAO_CDR_OP_CORBA_OctetSeq_I */

