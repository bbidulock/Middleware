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


// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_CORBA_FIXEDDEF___CI_)
#define _CORBA_FIXEDDEF___CI_

ACE_INLINE
CORBA::FixedDef::FixedDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_FixedDef_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::Boolean
CORBA::FixedDef::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:194

// *************************************************************
// Inline operations for class CORBA::ValueMember_var
// *************************************************************

ACE_INLINE
CORBA::ValueMember_var::ValueMember_var (void)
  : ptr_ (0)
{}

ACE_INLINE
CORBA::ValueMember_var::ValueMember_var (ValueMember *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA::ValueMember_var::ValueMember_var (const ::CORBA::ValueMember_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::CORBA::ValueMember (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
CORBA::ValueMember_var::~ValueMember_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
CORBA::ValueMember_var &
CORBA::ValueMember_var::operator= (ValueMember *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::CORBA::ValueMember_var &
CORBA::ValueMember_var::operator= (const ::CORBA::ValueMember_var &_tao_struct_var)
{
  if (this != &_tao_struct_var)
    {
      if (_tao_struct_var.ptr_ == 0)
        {
          delete this->ptr_;
          this->ptr_ = 0;
        }
      else
        {
          ValueMember *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              ValueMember (*_tao_struct_var.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              ValueMember *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::CORBA::ValueMember *
CORBA::ValueMember_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueMember *
CORBA::ValueMember_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA::ValueMember_var::operator const ::CORBA::ValueMember &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::ValueMember_var::operator ::CORBA::ValueMember &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::ValueMember_var::operator ::CORBA::ValueMember &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
CORBA::ValueMember_var::operator ::CORBA::ValueMember *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::CORBA::ValueMember &
CORBA::ValueMember_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CORBA::ValueMember &
CORBA::ValueMember_var::inout (void)
{
  return *this->ptr_;
}

// Mapping for variable size.
ACE_INLINE ::CORBA::ValueMember *&
CORBA::ValueMember_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueMember *
CORBA::ValueMember_var::_retn (void)
{
  ::CORBA::ValueMember *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CORBA::ValueMember *
CORBA::ValueMember_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:523

// *************************************************************
// Inline operations for class CORBA::ValueMember_out
// *************************************************************

ACE_INLINE
CORBA::ValueMember_out::ValueMember_out (::CORBA::ValueMember *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::ValueMember_out::ValueMember_out (ValueMember_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::ValueMember_out::ValueMember_out (const ::CORBA::ValueMember_out &p)
  : ptr_ (ACE_const_cast (ValueMember_out&, p).ptr_)
{}

ACE_INLINE
CORBA::ValueMember_out &
CORBA::ValueMember_out::operator= (const ::CORBA::ValueMember_out &p)
{
  this->ptr_ = ACE_const_cast (ValueMember_out&, p).ptr_;
  return *this;
}

ACE_INLINE
CORBA::ValueMember_out &
CORBA::ValueMember_out::operator= (ValueMember *_tao_struct_out)
{
  this->ptr_ = _tao_struct_out;
  return *this;
}

ACE_INLINE 
CORBA::ValueMember_out::operator ::CORBA::ValueMember *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueMember *&
CORBA::ValueMember_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueMember *
CORBA::ValueMember_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_ci.cpp:99

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_VALUEMEMBERSEQ_CI_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_VALUEMEMBERSEQ_CI_

ACE_INLINE
CORBA::ValueMember *
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (CORBA::ULong size)
{
  CORBA::ValueMember *retval = 0;
  ACE_NEW_RETURN (retval, CORBA::ValueMember[size], 0);
  return retval;
}

ACE_INLINE
void CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::freebuf (CORBA::ValueMember *buffer)
{
  delete [] buffer;
}

ACE_INLINE
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq (void)
{
}

ACE_INLINE
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq (CORBA::ULong maximum) 
  : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (maximum))
{
}

ACE_INLINE
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq (
    CORBA::ULong maximum,
    CORBA::ULong length,
    CORBA::ValueMember *data,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Base_Sequence (maximum, length, data, release)
{
}

ACE_INLINE
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq (
    const _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq &rhs
  )
  : TAO_Unbounded_Base_Sequence (rhs)
{
  if (rhs.buffer_ != 0)
    {
      CORBA::ValueMember *tmp1 =
        _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (this->maximum_);
      CORBA::ValueMember * const tmp2 =
        ACE_reinterpret_cast (CORBA::ValueMember * ACE_CAST_CONST, rhs.buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        {
          tmp1[i] = tmp2[i];
        }
      
      this->buffer_ = tmp1;
    }
  else
    {
      this->buffer_ = 0;
    }
}

ACE_INLINE
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq &
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::operator= (
    const _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq &rhs
  )
{
  if (this == &rhs)
    {
      return *this;
    }
  
  if (this->release_)
    {
      if (this->maximum_ < rhs.maximum_)
        {
          // Free the old buffer.
          CORBA::ValueMember *tmp =
            ACE_reinterpret_cast (CORBA::ValueMember *, this->buffer_);
          
          _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::freebuf (tmp);
          
          this->buffer_ =
            _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (rhs.maximum_);
        }
    }
  else
    {
      this->buffer_ =
        _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (rhs.maximum_);
    }
  
  TAO_Unbounded_Base_Sequence::operator= (rhs);
  
  CORBA::ValueMember *tmp1 =
    ACE_reinterpret_cast (CORBA::ValueMember *, this->buffer_);
  CORBA::ValueMember * const tmp2 =
    ACE_reinterpret_cast (CORBA::ValueMember * ACE_CAST_CONST, rhs.buffer_);
  
  for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      tmp1[i] = tmp2[i];
    }
  
  return *this;
}

// = Accessors.
ACE_INLINE
CORBA::ValueMember &
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::operator[] (CORBA::ULong i)
{
  ACE_ASSERT (i < this->maximum_);
  CORBA::ValueMember* tmp =
    ACE_reinterpret_cast (CORBA::ValueMember*, this->buffer_);
  return tmp[i];
}

ACE_INLINE
const CORBA::ValueMember &
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::operator[] (CORBA::ULong i) const
{
  ACE_ASSERT (i < this->maximum_);
  CORBA::ValueMember * const tmp =
    ACE_reinterpret_cast (CORBA::ValueMember* ACE_CAST_CONST, this->buffer_);
  return tmp[i];
}

// Implement the TAO_Base_Sequence methods (see Sequence.h)

ACE_INLINE
CORBA::ValueMember *
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::get_buffer (CORBA::Boolean orphan)
{
  CORBA::ValueMember *result = 0;
  
  if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
        {
          result =
            _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::allocbuf (this->length_);
          this->buffer_ = result;
          this->release_ = 1;
        }
      else
        {
          result =
            ACE_reinterpret_cast (CORBA::ValueMember*, this->buffer_);
        }
    }
  else // if (orphan == 1)
    {
      if (this->release_ != 0)
        {
          // We set the state back to default and relinquish ownership.
          result =
            ACE_reinterpret_cast(CORBA::ValueMember*,this->buffer_);
          this->maximum_ = 0;
          this->length_ = 0;
          this->buffer_ = 0;
          this->release_ = 0;
        }
    }
  
  return result;
}

ACE_INLINE
const CORBA::ValueMember *
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::get_buffer (void) const
{
  return ACE_reinterpret_cast (const CORBA::ValueMember * ACE_CAST_CONST, this->buffer_);
}

ACE_INLINE
void
CORBA::_TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::replace (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ValueMember *data,
    CORBA::Boolean release
  )
{
  this->maximum_ = max;
  this->length_ = length;
  
  if (this->buffer_ && this->release_ == 1)
    {
      CORBA::ValueMember *tmp =
        ACE_reinterpret_cast (CORBA::ValueMember*, this->buffer_);
      _TAO_Unbounded_Sequence_CORBA_ValueMemberSeq::freebuf (tmp);
    }
  
  this->buffer_ = data;
  this->release_ = release;
}

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_VALUEMEMBERSEQ_CI_)
#define _CORBA_VALUEMEMBERSEQ_CI_

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:226

// *************************************************************
// Inline operations for class CORBA::ValueMemberSeq_var
// *************************************************************

ACE_INLINE
CORBA::ValueMemberSeq_var::ValueMemberSeq_var (void)
  : ptr_ (0)
{}

ACE_INLINE
CORBA::ValueMemberSeq_var::ValueMemberSeq_var (ValueMemberSeq *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA::ValueMemberSeq_var::ValueMemberSeq_var (const ::CORBA::ValueMemberSeq_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::CORBA::ValueMemberSeq (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
CORBA::ValueMemberSeq_var::~ValueMemberSeq_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
CORBA::ValueMemberSeq_var &
CORBA::ValueMemberSeq_var::operator= (ValueMemberSeq *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
::CORBA::ValueMemberSeq_var &
CORBA::ValueMemberSeq_var::operator= (const ::CORBA::ValueMemberSeq_var &p)
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
          ValueMemberSeq *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              ValueMemberSeq (*p.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              ValueMemberSeq *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE
const ::CORBA::ValueMemberSeq *
CORBA::ValueMemberSeq_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE
::CORBA::ValueMemberSeq *
CORBA::ValueMemberSeq_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA::ValueMemberSeq_var::operator const ::CORBA::ValueMemberSeq &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::ValueMemberSeq_var::operator ::CORBA::ValueMemberSeq &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::ValueMemberSeq_var::operator ::CORBA::ValueMemberSeq &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
CORBA::ValueMemberSeq_var::operator ::CORBA::ValueMemberSeq *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE
CORBA::ValueMember &
CORBA::ValueMemberSeq_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
const CORBA::ValueMember &
CORBA::ValueMemberSeq_var::operator[] (CORBA::ULong index) const
{
  return ACE_const_cast (const CORBA::ValueMember &, this->ptr_->operator[] (index));
}

ACE_INLINE
const ::CORBA::ValueMemberSeq &
CORBA::ValueMemberSeq_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE
::CORBA::ValueMemberSeq &
CORBA::ValueMemberSeq_var::inout (void)
{
  return *this->ptr_;
}

ACE_INLINE
::CORBA::ValueMemberSeq *&
CORBA::ValueMemberSeq_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE
::CORBA::ValueMemberSeq *
CORBA::ValueMemberSeq_var::_retn (void)
{
  ::CORBA::ValueMemberSeq *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE
::CORBA::ValueMemberSeq *
CORBA::ValueMemberSeq_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:567

// *************************************************************
// Inline operations for class CORBA::ValueMemberSeq_out
// *************************************************************

ACE_INLINE
CORBA::ValueMemberSeq_out::ValueMemberSeq_out (ValueMemberSeq *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::ValueMemberSeq_out::ValueMemberSeq_out (ValueMemberSeq_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::ValueMemberSeq_out::ValueMemberSeq_out (const ::CORBA::ValueMemberSeq_out &p)
  : ptr_ (ACE_const_cast (ValueMemberSeq_out&, p).ptr_)
{}

ACE_INLINE
::CORBA::ValueMemberSeq_out &
CORBA::ValueMemberSeq_out::operator= (const ::CORBA::ValueMemberSeq_out &p)
{
  this->ptr_ = ACE_const_cast (ValueMemberSeq_out&, p).ptr_;
  return *this;
}

ACE_INLINE
::CORBA::ValueMemberSeq_out &
CORBA::ValueMemberSeq_out::operator= (ValueMemberSeq *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA::ValueMemberSeq_out::operator ::CORBA::ValueMemberSeq *&() // cast
{
  return this->ptr_;
}

ACE_INLINE
::CORBA::ValueMemberSeq *&
CORBA::ValueMemberSeq_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE
::CORBA::ValueMemberSeq *
CORBA::ValueMemberSeq_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA::ValueMember &
CORBA::ValueMemberSeq_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_CORBA_VALUEMEMBERDEF___CI_)
#define _CORBA_VALUEMEMBERDEF___CI_

ACE_INLINE
CORBA::ValueMemberDef::ValueMemberDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_ValueMemberDef_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::Boolean
CORBA::ValueMemberDef::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:194

// *************************************************************
// Inline operations for class CORBA::ValueDef::FullValueDescription_var
// *************************************************************

ACE_INLINE
CORBA::ValueDef::FullValueDescription_var::FullValueDescription_var (void)
  : ptr_ (0)
{}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_var::FullValueDescription_var (FullValueDescription *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_var::FullValueDescription_var (const ::CORBA::ValueDef::FullValueDescription_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::CORBA::ValueDef::FullValueDescription (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_var::~FullValueDescription_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_var &
CORBA::ValueDef::FullValueDescription_var::operator= (FullValueDescription *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::CORBA::ValueDef::FullValueDescription_var &
CORBA::ValueDef::FullValueDescription_var::operator= (const ::CORBA::ValueDef::FullValueDescription_var &_tao_struct_var)
{
  if (this != &_tao_struct_var)
    {
      if (_tao_struct_var.ptr_ == 0)
        {
          delete this->ptr_;
          this->ptr_ = 0;
        }
      else
        {
          FullValueDescription *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              FullValueDescription (*_tao_struct_var.ptr_),
              *this
            );
          
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

ACE_INLINE const ::CORBA::ValueDef::FullValueDescription *
CORBA::ValueDef::FullValueDescription_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueDef::FullValueDescription *
CORBA::ValueDef::FullValueDescription_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_var::operator const ::CORBA::ValueDef::FullValueDescription &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_var::operator ::CORBA::ValueDef::FullValueDescription &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_var::operator ::CORBA::ValueDef::FullValueDescription &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
CORBA::ValueDef::FullValueDescription_var::operator ::CORBA::ValueDef::FullValueDescription *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::CORBA::ValueDef::FullValueDescription &
CORBA::ValueDef::FullValueDescription_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CORBA::ValueDef::FullValueDescription &
CORBA::ValueDef::FullValueDescription_var::inout (void)
{
  return *this->ptr_;
}

// Mapping for variable size.
ACE_INLINE ::CORBA::ValueDef::FullValueDescription *&
CORBA::ValueDef::FullValueDescription_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueDef::FullValueDescription *
CORBA::ValueDef::FullValueDescription_var::_retn (void)
{
  ::CORBA::ValueDef::FullValueDescription *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CORBA::ValueDef::FullValueDescription *
CORBA::ValueDef::FullValueDescription_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:523

// *************************************************************
// Inline operations for class CORBA::ValueDef::FullValueDescription_out
// *************************************************************

ACE_INLINE
CORBA::ValueDef::FullValueDescription_out::FullValueDescription_out (::CORBA::ValueDef::FullValueDescription *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_out::FullValueDescription_out (FullValueDescription_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_out::FullValueDescription_out (const ::CORBA::ValueDef::FullValueDescription_out &p)
  : ptr_ (ACE_const_cast (FullValueDescription_out&, p).ptr_)
{}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_out &
CORBA::ValueDef::FullValueDescription_out::operator= (const ::CORBA::ValueDef::FullValueDescription_out &p)
{
  this->ptr_ = ACE_const_cast (FullValueDescription_out&, p).ptr_;
  return *this;
}

ACE_INLINE
CORBA::ValueDef::FullValueDescription_out &
CORBA::ValueDef::FullValueDescription_out::operator= (FullValueDescription *_tao_struct_out)
{
  this->ptr_ = _tao_struct_out;
  return *this;
}

ACE_INLINE 
CORBA::ValueDef::FullValueDescription_out::operator ::CORBA::ValueDef::FullValueDescription *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueDef::FullValueDescription *&
CORBA::ValueDef::FullValueDescription_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueDef::FullValueDescription *
CORBA::ValueDef::FullValueDescription_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_CORBA_VALUEDEF___CI_)
#define _CORBA_VALUEDEF___CI_

ACE_INLINE
CORBA::ValueDef::ValueDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_ValueDef_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::Boolean
CORBA::ValueDef::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:194

// *************************************************************
// Inline operations for class CORBA::ValueDescription_var
// *************************************************************

ACE_INLINE
CORBA::ValueDescription_var::ValueDescription_var (void)
  : ptr_ (0)
{}

ACE_INLINE
CORBA::ValueDescription_var::ValueDescription_var (ValueDescription *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA::ValueDescription_var::ValueDescription_var (const ::CORBA::ValueDescription_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::CORBA::ValueDescription (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
CORBA::ValueDescription_var::~ValueDescription_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
CORBA::ValueDescription_var &
CORBA::ValueDescription_var::operator= (ValueDescription *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::CORBA::ValueDescription_var &
CORBA::ValueDescription_var::operator= (const ::CORBA::ValueDescription_var &_tao_struct_var)
{
  if (this != &_tao_struct_var)
    {
      if (_tao_struct_var.ptr_ == 0)
        {
          delete this->ptr_;
          this->ptr_ = 0;
        }
      else
        {
          ValueDescription *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              ValueDescription (*_tao_struct_var.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              ValueDescription *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::CORBA::ValueDescription *
CORBA::ValueDescription_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueDescription *
CORBA::ValueDescription_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA::ValueDescription_var::operator const ::CORBA::ValueDescription &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::ValueDescription_var::operator ::CORBA::ValueDescription &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::ValueDescription_var::operator ::CORBA::ValueDescription &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
CORBA::ValueDescription_var::operator ::CORBA::ValueDescription *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::CORBA::ValueDescription &
CORBA::ValueDescription_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CORBA::ValueDescription &
CORBA::ValueDescription_var::inout (void)
{
  return *this->ptr_;
}

// Mapping for variable size.
ACE_INLINE ::CORBA::ValueDescription *&
CORBA::ValueDescription_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueDescription *
CORBA::ValueDescription_var::_retn (void)
{
  ::CORBA::ValueDescription *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CORBA::ValueDescription *
CORBA::ValueDescription_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:523

// *************************************************************
// Inline operations for class CORBA::ValueDescription_out
// *************************************************************

ACE_INLINE
CORBA::ValueDescription_out::ValueDescription_out (::CORBA::ValueDescription *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::ValueDescription_out::ValueDescription_out (ValueDescription_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::ValueDescription_out::ValueDescription_out (const ::CORBA::ValueDescription_out &p)
  : ptr_ (ACE_const_cast (ValueDescription_out&, p).ptr_)
{}

ACE_INLINE
CORBA::ValueDescription_out &
CORBA::ValueDescription_out::operator= (const ::CORBA::ValueDescription_out &p)
{
  this->ptr_ = ACE_const_cast (ValueDescription_out&, p).ptr_;
  return *this;
}

ACE_INLINE
CORBA::ValueDescription_out &
CORBA::ValueDescription_out::operator= (ValueDescription *_tao_struct_out)
{
  this->ptr_ = _tao_struct_out;
  return *this;
}

ACE_INLINE 
CORBA::ValueDescription_out::operator ::CORBA::ValueDescription *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueDescription *&
CORBA::ValueDescription_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CORBA::ValueDescription *
CORBA::ValueDescription_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_CORBA_VALUEBOXDEF___CI_)
#define _CORBA_VALUEBOXDEF___CI_

ACE_INLINE
CORBA::ValueBoxDef::ValueBoxDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_ValueBoxDef_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::Boolean
CORBA::ValueBoxDef::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::FixedDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::FixedDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ValueMember &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.id.in ()) &&
    (strm << _tao_aggregate.defined_in.in ()) &&
    (strm << _tao_aggregate.version.in ()) &&
    (strm << _tao_aggregate.type.in ()) &&
    _tao_aggregate.type_def.in ()->marshal (strm) &&
    (strm << _tao_aggregate.access)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ValueMember &_tao_aggregate
  )
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
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_CORBA_ValueMemberSeq_I_
#define _TAO_CDR_OP_CORBA_ValueMemberSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ValueMemberSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ValueMemberSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ValueMemberSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ValueMemberDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ValueMemberDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ValueDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ValueDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ValueDef::FullValueDescription &_tao_aggregate
  )
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
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ValueDef::FullValueDescription &_tao_aggregate
  )
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
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ValueDescription &_tao_aggregate
  )
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
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ValueDescription &_tao_aggregate
  )
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
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ValueBoxDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ValueBoxDef_ptr &
  );

