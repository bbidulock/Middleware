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


#if !defined (_CORBA_FIXEDDEF___CI_)
#define _CORBA_FIXEDDEF___CI_

ACE_INLINE
CORBA_FixedDef::CORBA_FixedDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_FixedDef_setup_collocation (_tao_collocated);
}


#endif /* end #if !defined */

// *************************************************************
// Inline operations for class CORBA_ValueMember_var
// *************************************************************

ACE_INLINE
CORBA_ValueMember_var::CORBA_ValueMember_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_ValueMember_var::CORBA_ValueMember_var (CORBA_ValueMember *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_ValueMember_var::CORBA_ValueMember_var (const ::CORBA_ValueMember_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::CORBA_ValueMember (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueMember_var::~CORBA_ValueMember_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_ValueMember_var &
CORBA_ValueMember_var::operator= (CORBA_ValueMember *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE ::CORBA_ValueMember_var &
CORBA_ValueMember_var::operator= (const ::CORBA_ValueMember_var &p)
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
          CORBA_ValueMember *deep_copy =
            new CORBA_ValueMember (*p.ptr_);
          
          if (deep_copy != 0)
            {
              CORBA_ValueMember *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::CORBA_ValueMember *
CORBA_ValueMember_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueMember *
CORBA_ValueMember_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA_ValueMember_var::operator const ::CORBA_ValueMember &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_ValueMember_var::operator ::CORBA_ValueMember &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_ValueMember_var::operator ::CORBA_ValueMember &() const // cast 
{
  return *this->ptr_;
}

// variable-size types only
ACE_INLINE
CORBA_ValueMember_var::operator ::CORBA_ValueMember *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::CORBA_ValueMember &
CORBA_ValueMember_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CORBA_ValueMember &
CORBA_ValueMember_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE ::CORBA_ValueMember *&
CORBA_ValueMember_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueMember *
CORBA_ValueMember_var::_retn (void)
{
  ::CORBA_ValueMember *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CORBA_ValueMember *
CORBA_ValueMember_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_ValueMember_out
// *************************************************************

ACE_INLINE
CORBA_ValueMember_out::CORBA_ValueMember_out (::CORBA_ValueMember *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueMember_out::CORBA_ValueMember_out (CORBA_ValueMember_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueMember_out::CORBA_ValueMember_out (const ::CORBA_ValueMember_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_ValueMember_out&, p).ptr_)
{}

ACE_INLINE CORBA_ValueMember_out &
CORBA_ValueMember_out::operator= (const ::CORBA_ValueMember_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_ValueMember_out&, p).ptr_;
  return *this;
}

ACE_INLINE CORBA_ValueMember_out &
CORBA_ValueMember_out::operator= (CORBA_ValueMember *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_ValueMember_out::operator ::CORBA_ValueMember *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueMember *&
CORBA_ValueMember_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueMember *
CORBA_ValueMember_out::operator-> (void)
{
  return this->ptr_;
}


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  
#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_VALUEMEMBERSEQ_CI_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_VALUEMEMBERSEQ_CI_

  // = Static operations.
  ACE_INLINE CORBA_ValueMember *
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (CORBA::ULong size)
  // Allocate storage for the sequence.
  {
    CORBA_ValueMember *retval = 0;
    ACE_NEW_RETURN (retval, CORBA_ValueMember[size], 0);
    return retval;
  }
  
  ACE_INLINE void _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::freebuf (CORBA_ValueMember *buffer)
  // Free the sequence.
  {
    delete [] buffer;
  }
  
  ACE_INLINE
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq (void) // Default constructor.
  {
  }
  
  ACE_INLINE
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq (CORBA::ULong maximum) // Constructor using a maximum length value.
    : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (maximum))
  {
  }
  
  ACE_INLINE
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq (CORBA::ULong maximum,
    CORBA::ULong length,
    CORBA_ValueMember *data,
    CORBA::Boolean release)
  : TAO_Unbounded_Base_Sequence (maximum, length, data, release)
  {
  }
  
  ACE_INLINE
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq (const _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq &rhs)
  // Copy constructor.
    : TAO_Unbounded_Base_Sequence (rhs)
  {
    if (rhs.buffer_ != 0)
    {
      CORBA_ValueMember *tmp1 = _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (this->maximum_);
      CORBA_ValueMember * const tmp2 = ACE_reinterpret_cast (CORBA_ValueMember * ACE_CAST_CONST, rhs.buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        tmp1[i] = tmp2[i];
      
      this->buffer_ = tmp1;
    }
    else
    {
      this->buffer_ = 0;
    }
  }
  
  ACE_INLINE _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq &
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::operator= (const _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq &rhs)
  // Assignment operator.
  {
    if (this == &rhs)
      return *this;
    
    if (this->release_)
    {
      if (this->maximum_ < rhs.maximum_)
      {
        // free the old buffer
        CORBA_ValueMember *tmp = ACE_reinterpret_cast (CORBA_ValueMember *, this->buffer_);
        _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::freebuf (tmp);
        this->buffer_ = _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (rhs.maximum_);
      }
    }
    else
      this->buffer_ = _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (rhs.maximum_);
    
    TAO_Unbounded_Base_Sequence::operator= (rhs);
    
    CORBA_ValueMember *tmp1 = ACE_reinterpret_cast (CORBA_ValueMember *, this->buffer_);
    CORBA_ValueMember * const tmp2 = ACE_reinterpret_cast (CORBA_ValueMember * ACE_CAST_CONST, rhs.buffer_);
    
    for (CORBA::ULong i = 0; i < this->length_; ++i)
      tmp1[i] = tmp2[i];
    
    return *this;
  }
  
  // = Accessors.
  ACE_INLINE CORBA_ValueMember &
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::operator[] (CORBA::ULong i)
  // operator []
  {
    ACE_ASSERT (i < this->maximum_);
    CORBA_ValueMember* tmp = ACE_reinterpret_cast(CORBA_ValueMember*,this->buffer_);
    return tmp[i];
  }
  
  ACE_INLINE const CORBA_ValueMember &
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::operator[] (CORBA::ULong i) const
  // operator []
  {
    ACE_ASSERT (i < this->maximum_);
    CORBA_ValueMember * const tmp = ACE_reinterpret_cast (CORBA_ValueMember* ACE_CAST_CONST, this->buffer_);
    return tmp[i];
  }
  
  // Implement the TAO_Base_Sequence methods (see Sequence.h)
  
  ACE_INLINE CORBA_ValueMember *
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::get_buffer (CORBA::Boolean orphan)
  {
    CORBA_ValueMember *result = 0;
    if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
      {
        result = _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (this->length_);
        this->buffer_ = result;
        this->release_ = 1;
      }
      else
      {
        result = ACE_reinterpret_cast (CORBA_ValueMember*, this->buffer_);
      }
    }
    else // if (orphan == 1)
    {
      if (this->release_ != 0)
      {
        // We set the state back to default and relinquish
        // ownership.
        result = ACE_reinterpret_cast(CORBA_ValueMember*,this->buffer_);
        this->maximum_ = 0;
        this->length_ = 0;
        this->buffer_ = 0;
        this->release_ = 0;
      }
    }
    return result;
  }
  
  ACE_INLINE const CORBA_ValueMember *
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::get_buffer (void) const
  {
    return ACE_reinterpret_cast(const CORBA_ValueMember * ACE_CAST_CONST, this->buffer_);
  }
  
  ACE_INLINE void
  _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::replace (CORBA::ULong max,
  CORBA::ULong length,
  CORBA_ValueMember *data,
  CORBA::Boolean release)
  {
    this->maximum_ = max;
    this->length_ = length;
    if (this->buffer_ && this->release_ == 1)
    {
      CORBA_ValueMember *tmp = ACE_reinterpret_cast(CORBA_ValueMember*,this->buffer_);
      _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::freebuf (tmp);
    }
    this->buffer_ = data;
    this->release_ = release;
  }
  
#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_VALUEMEMBERSEQ_CI_)
#define _CORBA_VALUEMEMBERSEQ_CI_

// *************************************************************
// Inline operations for class CORBA_ValueMemberSeq_var
// *************************************************************

ACE_INLINE
CORBA_ValueMemberSeq_var::CORBA_ValueMemberSeq_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_ValueMemberSeq_var::CORBA_ValueMemberSeq_var (CORBA_ValueMemberSeq *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_ValueMemberSeq_var::CORBA_ValueMemberSeq_var (const ::CORBA_ValueMemberSeq_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::CORBA_ValueMemberSeq (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueMemberSeq_var::~CORBA_ValueMemberSeq_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_ValueMemberSeq_var &
CORBA_ValueMemberSeq_var::operator= (CORBA_ValueMemberSeq *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE ::CORBA_ValueMemberSeq_var &
CORBA_ValueMemberSeq_var::operator= (const ::CORBA_ValueMemberSeq_var &p)
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
          CORBA_ValueMemberSeq *deep_copy =
            new CORBA_ValueMemberSeq (*p.ptr_);
          
          if (deep_copy != 0)
            {
              CORBA_ValueMemberSeq *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::CORBA_ValueMemberSeq *
CORBA_ValueMemberSeq_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueMemberSeq *
CORBA_ValueMemberSeq_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
CORBA_ValueMemberSeq_var::operator const ::CORBA_ValueMemberSeq &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
CORBA_ValueMemberSeq_var::operator ::CORBA_ValueMemberSeq &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
CORBA_ValueMemberSeq_var::operator ::CORBA_ValueMemberSeq &() const // cast 
{
  return *this->ptr_;
}

// variable-size types only
ACE_INLINE
CORBA_ValueMemberSeq_var::operator ::CORBA_ValueMemberSeq *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA_ValueMember &
CORBA_ValueMemberSeq_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const CORBA_ValueMember &
CORBA_ValueMemberSeq_var::operator[] (CORBA::ULong index) const
{
  return ACE_const_cast (const CORBA_ValueMember &, this->ptr_->operator[] (index));
}

ACE_INLINE const ::CORBA_ValueMemberSeq &
CORBA_ValueMemberSeq_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CORBA_ValueMemberSeq &
CORBA_ValueMemberSeq_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE ::CORBA_ValueMemberSeq *&
CORBA_ValueMemberSeq_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueMemberSeq *
CORBA_ValueMemberSeq_var::_retn (void)
{
  ::CORBA_ValueMemberSeq *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CORBA_ValueMemberSeq *
CORBA_ValueMemberSeq_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_ValueMemberSeq_out
// *************************************************************

ACE_INLINE
CORBA_ValueMemberSeq_out::CORBA_ValueMemberSeq_out (CORBA_ValueMemberSeq *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueMemberSeq_out::CORBA_ValueMemberSeq_out (CORBA_ValueMemberSeq_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueMemberSeq_out::CORBA_ValueMemberSeq_out (const ::CORBA_ValueMemberSeq_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_ValueMemberSeq_out&, p).ptr_)
{}

ACE_INLINE ::CORBA_ValueMemberSeq_out &
CORBA_ValueMemberSeq_out::operator= (const ::CORBA_ValueMemberSeq_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_ValueMemberSeq_out&, p).ptr_;
  return *this;
}

ACE_INLINE ::CORBA_ValueMemberSeq_out &
CORBA_ValueMemberSeq_out::operator= (CORBA_ValueMemberSeq *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_ValueMemberSeq_out::operator ::CORBA_ValueMemberSeq *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueMemberSeq *&
CORBA_ValueMemberSeq_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueMemberSeq *
CORBA_ValueMemberSeq_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_ValueMember &
CORBA_ValueMemberSeq_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}


#endif /* end #if !defined */


#if !defined (_CORBA_VALUEMEMBERDEF___CI_)
#define _CORBA_VALUEMEMBERDEF___CI_

ACE_INLINE
CORBA_ValueMemberDef::CORBA_ValueMemberDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_ValueMemberDef_setup_collocation (_tao_collocated);
}


#endif /* end #if !defined */

// *************************************************************
// Inline operations for class CORBA_ValueDef::FullValueDescription_var
// *************************************************************

ACE_INLINE
CORBA_ValueDef::FullValueDescription_var::FullValueDescription_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_ValueDef::FullValueDescription_var::FullValueDescription_var (FullValueDescription *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_ValueDef::FullValueDescription_var::FullValueDescription_var (const ::CORBA_ValueDef::FullValueDescription_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::CORBA_ValueDef::FullValueDescription (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueDef::FullValueDescription_var::~FullValueDescription_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_ValueDef::FullValueDescription_var &
CORBA_ValueDef::FullValueDescription_var::operator= (FullValueDescription *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE ::CORBA_ValueDef::FullValueDescription_var &
CORBA_ValueDef::FullValueDescription_var::operator= (const ::CORBA_ValueDef::FullValueDescription_var &p)
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
          FullValueDescription *deep_copy =
            new FullValueDescription (*p.ptr_);
          
          if (deep_copy != 0)
            {
              FullValueDescription *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::CORBA_ValueDef::FullValueDescription *
CORBA_ValueDef::FullValueDescription_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueDef::FullValueDescription *
CORBA_ValueDef::FullValueDescription_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA_ValueDef::FullValueDescription_var::operator const ::CORBA_ValueDef::FullValueDescription &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_ValueDef::FullValueDescription_var::operator ::CORBA_ValueDef::FullValueDescription &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_ValueDef::FullValueDescription_var::operator ::CORBA_ValueDef::FullValueDescription &() const // cast 
{
  return *this->ptr_;
}

// variable-size types only
ACE_INLINE
CORBA_ValueDef::FullValueDescription_var::operator ::CORBA_ValueDef::FullValueDescription *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::CORBA_ValueDef::FullValueDescription &
CORBA_ValueDef::FullValueDescription_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CORBA_ValueDef::FullValueDescription &
CORBA_ValueDef::FullValueDescription_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE ::CORBA_ValueDef::FullValueDescription *&
CORBA_ValueDef::FullValueDescription_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueDef::FullValueDescription *
CORBA_ValueDef::FullValueDescription_var::_retn (void)
{
  ::CORBA_ValueDef::FullValueDescription *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CORBA_ValueDef::FullValueDescription *
CORBA_ValueDef::FullValueDescription_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_ValueDef::FullValueDescription_out
// *************************************************************

ACE_INLINE
CORBA_ValueDef::FullValueDescription_out::FullValueDescription_out (::CORBA_ValueDef::FullValueDescription *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueDef::FullValueDescription_out::FullValueDescription_out (FullValueDescription_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueDef::FullValueDescription_out::FullValueDescription_out (const ::CORBA_ValueDef::FullValueDescription_out &p) // copy constructor
  : ptr_ (ACE_const_cast (FullValueDescription_out&, p).ptr_)
{}

ACE_INLINE CORBA_ValueDef::FullValueDescription_out &
CORBA_ValueDef::FullValueDescription_out::operator= (const ::CORBA_ValueDef::FullValueDescription_out &p)
{
  this->ptr_ = ACE_const_cast (FullValueDescription_out&, p).ptr_;
  return *this;
}

ACE_INLINE CORBA_ValueDef::FullValueDescription_out &
CORBA_ValueDef::FullValueDescription_out::operator= (FullValueDescription *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_ValueDef::FullValueDescription_out::operator ::CORBA_ValueDef::FullValueDescription *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueDef::FullValueDescription *&
CORBA_ValueDef::FullValueDescription_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueDef::FullValueDescription *
CORBA_ValueDef::FullValueDescription_out::operator-> (void)
{
  return this->ptr_;
}


#if !defined (_CORBA_VALUEDEF___CI_)
#define _CORBA_VALUEDEF___CI_

ACE_INLINE
CORBA_ValueDef::CORBA_ValueDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_ValueDef_setup_collocation (_tao_collocated);
}


#endif /* end #if !defined */

// *************************************************************
// Inline operations for class CORBA_ValueDescription_var
// *************************************************************

ACE_INLINE
CORBA_ValueDescription_var::CORBA_ValueDescription_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_ValueDescription_var::CORBA_ValueDescription_var (CORBA_ValueDescription *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_ValueDescription_var::CORBA_ValueDescription_var (const ::CORBA_ValueDescription_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::CORBA_ValueDescription (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueDescription_var::~CORBA_ValueDescription_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_ValueDescription_var &
CORBA_ValueDescription_var::operator= (CORBA_ValueDescription *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE ::CORBA_ValueDescription_var &
CORBA_ValueDescription_var::operator= (const ::CORBA_ValueDescription_var &p)
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
          CORBA_ValueDescription *deep_copy =
            new CORBA_ValueDescription (*p.ptr_);
          
          if (deep_copy != 0)
            {
              CORBA_ValueDescription *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::CORBA_ValueDescription *
CORBA_ValueDescription_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueDescription *
CORBA_ValueDescription_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA_ValueDescription_var::operator const ::CORBA_ValueDescription &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_ValueDescription_var::operator ::CORBA_ValueDescription &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_ValueDescription_var::operator ::CORBA_ValueDescription &() const // cast 
{
  return *this->ptr_;
}

// variable-size types only
ACE_INLINE
CORBA_ValueDescription_var::operator ::CORBA_ValueDescription *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::CORBA_ValueDescription &
CORBA_ValueDescription_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CORBA_ValueDescription &
CORBA_ValueDescription_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE ::CORBA_ValueDescription *&
CORBA_ValueDescription_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueDescription *
CORBA_ValueDescription_var::_retn (void)
{
  ::CORBA_ValueDescription *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CORBA_ValueDescription *
CORBA_ValueDescription_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_ValueDescription_out
// *************************************************************

ACE_INLINE
CORBA_ValueDescription_out::CORBA_ValueDescription_out (::CORBA_ValueDescription *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueDescription_out::CORBA_ValueDescription_out (CORBA_ValueDescription_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_ValueDescription_out::CORBA_ValueDescription_out (const ::CORBA_ValueDescription_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_ValueDescription_out&, p).ptr_)
{}

ACE_INLINE CORBA_ValueDescription_out &
CORBA_ValueDescription_out::operator= (const ::CORBA_ValueDescription_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_ValueDescription_out&, p).ptr_;
  return *this;
}

ACE_INLINE CORBA_ValueDescription_out &
CORBA_ValueDescription_out::operator= (CORBA_ValueDescription *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_ValueDescription_out::operator ::CORBA_ValueDescription *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueDescription *&
CORBA_ValueDescription_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CORBA_ValueDescription *
CORBA_ValueDescription_out::operator-> (void)
{
  return this->ptr_;
}


#if !defined (_CORBA_VALUEBOXDEF___CI_)
#define _CORBA_VALUEBOXDEF___CI_

ACE_INLINE
CORBA_ValueBoxDef::CORBA_ValueBoxDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_ValueBoxDef_setup_collocation (_tao_collocated);
}


#endif /* end #if !defined */

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA_FixedDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA_FixedDef_ptr &
  );

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const CORBA_ValueMember &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.id.in ()) &&
    (strm << _tao_aggregate.defined_in.in ()) &&
    (strm << _tao_aggregate.version.in ()) &&
    (strm << _tao_aggregate.type.in ()) &&
    (strm << _tao_aggregate.type_def.in ()) &&
    (strm << _tao_aggregate.access)
  )
    return 1;
  else
    return 0;
  
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_ValueMember &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.name.out ()) &&
    (strm >> _tao_aggregate.id.out ()) &&
    (strm >> _tao_aggregate.defined_in.out ()) &&
    (strm >> _tao_aggregate.version.out ()) &&
    (strm >> _tao_aggregate.type.out ()) &&
    (strm >> _tao_aggregate.type_def.out ()) &&
    (strm >> _tao_aggregate.access)
  )
    return 1;
  else
    return 0;
  
}


#if !defined _TAO_CDR_OP_CORBA_ValueMemberSeq_I_
#define _TAO_CDR_OP_CORBA_ValueMemberSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA_ValueMemberSeq &
  );
CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA_ValueMemberSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ValueMemberSeq_I_ */

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA_ValueMemberDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA_ValueMemberDef_ptr &
  );

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA_ValueDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA_ValueDef_ptr &
  );

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const CORBA_ValueDef::FullValueDescription &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.id.in ()) &&
    (strm << CORBA::Any::from_boolean (_tao_aggregate.is_abstract)) &&
    (strm << CORBA::Any::from_boolean (_tao_aggregate.is_custom)) &&
    (strm << _tao_aggregate.defined_in.in ()) &&
    (strm << _tao_aggregate.version.in ()) &&
    (strm << _tao_aggregate.operations) &&
    (strm << _tao_aggregate.attributes) &&
    (strm << _tao_aggregate.members) &&
    (strm << _tao_aggregate.initializers) &&
    (strm << _tao_aggregate.supported_interfaces) &&
    (strm << _tao_aggregate.abstract_base_values) &&
    (strm << CORBA::Any::from_boolean (_tao_aggregate.is_truncatable)) &&
    (strm << _tao_aggregate.base_value.in ()) &&
    (strm << _tao_aggregate.type.in ())
  )
    return 1;
  else
    return 0;
  
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_ValueDef::FullValueDescription &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.name.out ()) &&
    (strm >> _tao_aggregate.id.out ()) &&
    (strm >> CORBA::Any::to_boolean (_tao_aggregate.is_abstract)) &&
    (strm >> CORBA::Any::to_boolean (_tao_aggregate.is_custom)) &&
    (strm >> _tao_aggregate.defined_in.out ()) &&
    (strm >> _tao_aggregate.version.out ()) &&
    (strm >> _tao_aggregate.operations) &&
    (strm >> _tao_aggregate.attributes) &&
    (strm >> _tao_aggregate.members) &&
    (strm >> _tao_aggregate.initializers) &&
    (strm >> _tao_aggregate.supported_interfaces) &&
    (strm >> _tao_aggregate.abstract_base_values) &&
    (strm >> CORBA::Any::to_boolean (_tao_aggregate.is_truncatable)) &&
    (strm >> _tao_aggregate.base_value.out ()) &&
    (strm >> _tao_aggregate.type.out ())
  )
    return 1;
  else
    return 0;
  
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const CORBA_ValueDescription &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.id.in ()) &&
    (strm << CORBA::Any::from_boolean (_tao_aggregate.is_abstract)) &&
    (strm << CORBA::Any::from_boolean (_tao_aggregate.is_custom)) &&
    (strm << _tao_aggregate.defined_in.in ()) &&
    (strm << _tao_aggregate.version.in ()) &&
    (strm << _tao_aggregate.supported_interfaces) &&
    (strm << _tao_aggregate.abstract_base_values) &&
    (strm << CORBA::Any::from_boolean (_tao_aggregate.is_truncatable)) &&
    (strm << _tao_aggregate.base_value.in ())
  )
    return 1;
  else
    return 0;
  
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_ValueDescription &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.name.out ()) &&
    (strm >> _tao_aggregate.id.out ()) &&
    (strm >> CORBA::Any::to_boolean (_tao_aggregate.is_abstract)) &&
    (strm >> CORBA::Any::to_boolean (_tao_aggregate.is_custom)) &&
    (strm >> _tao_aggregate.defined_in.out ()) &&
    (strm >> _tao_aggregate.version.out ()) &&
    (strm >> _tao_aggregate.supported_interfaces) &&
    (strm >> _tao_aggregate.abstract_base_values) &&
    (strm >> CORBA::Any::to_boolean (_tao_aggregate.is_truncatable)) &&
    (strm >> _tao_aggregate.base_value.out ())
  )
    return 1;
  else
    return 0;
  
}

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA_ValueBoxDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA_ValueBoxDef_ptr &
  );

