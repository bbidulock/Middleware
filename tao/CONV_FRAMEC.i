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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:194

// *************************************************************
// Inline operations for class CONV_FRAME::CodeSetComponent_var
// *************************************************************

ACE_INLINE
CONV_FRAME::CodeSetComponent_var::CodeSetComponent_var (void)
  : ptr_ (0)
{}

ACE_INLINE
CONV_FRAME::CodeSetComponent_var::CodeSetComponent_var (CodeSetComponent *p)
  : ptr_ (p)
{}

ACE_INLINE
CONV_FRAME::CodeSetComponent_var::CodeSetComponent_var (const ::CONV_FRAME::CodeSetComponent_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::CONV_FRAME::CodeSetComponent (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
CONV_FRAME::CodeSetComponent_var::~CodeSetComponent_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetComponent_var &
CONV_FRAME::CodeSetComponent_var::operator= (CodeSetComponent *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::CONV_FRAME::CodeSetComponent_var &
CONV_FRAME::CodeSetComponent_var::operator= (const ::CONV_FRAME::CodeSetComponent_var &_tao_struct_var)
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
          CodeSetComponent *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              CodeSetComponent (*_tao_struct_var.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              CodeSetComponent *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::CONV_FRAME::CodeSetComponent *
CONV_FRAME::CodeSetComponent_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponent *
CONV_FRAME::CodeSetComponent_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetComponent_var::operator const ::CONV_FRAME::CodeSetComponent &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetComponent_var::operator ::CONV_FRAME::CodeSetComponent &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetComponent_var::operator ::CONV_FRAME::CodeSetComponent &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
CONV_FRAME::CodeSetComponent_var::operator ::CONV_FRAME::CodeSetComponent *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::CONV_FRAME::CodeSetComponent &
CONV_FRAME::CodeSetComponent_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponent &
CONV_FRAME::CodeSetComponent_var::inout (void)
{
  return *this->ptr_;
}

// Mapping for variable size.
ACE_INLINE ::CONV_FRAME::CodeSetComponent *&
CONV_FRAME::CodeSetComponent_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponent *
CONV_FRAME::CodeSetComponent_var::_retn (void)
{
  ::CONV_FRAME::CodeSetComponent *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponent *
CONV_FRAME::CodeSetComponent_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:523

// *************************************************************
// Inline operations for class CONV_FRAME::CodeSetComponent_out
// *************************************************************

ACE_INLINE
CONV_FRAME::CodeSetComponent_out::CodeSetComponent_out (::CONV_FRAME::CodeSetComponent *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CONV_FRAME::CodeSetComponent_out::CodeSetComponent_out (CodeSetComponent_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CONV_FRAME::CodeSetComponent_out::CodeSetComponent_out (const ::CONV_FRAME::CodeSetComponent_out &p)
  : ptr_ (ACE_const_cast (CodeSetComponent_out&, p).ptr_)
{}

ACE_INLINE
CONV_FRAME::CodeSetComponent_out &
CONV_FRAME::CodeSetComponent_out::operator= (const ::CONV_FRAME::CodeSetComponent_out &p)
{
  this->ptr_ = ACE_const_cast (CodeSetComponent_out&, p).ptr_;
  return *this;
}

ACE_INLINE
CONV_FRAME::CodeSetComponent_out &
CONV_FRAME::CodeSetComponent_out::operator= (CodeSetComponent *_tao_struct_out)
{
  this->ptr_ = _tao_struct_out;
  return *this;
}

ACE_INLINE 
CONV_FRAME::CodeSetComponent_out::operator ::CONV_FRAME::CodeSetComponent *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponent *&
CONV_FRAME::CodeSetComponent_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponent *
CONV_FRAME::CodeSetComponent_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_sequence_ci.cpp:99

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID_CI_)
#define __TAO_UNBOUNDED_SEQUENCE_CONV_FRAME_CODESETCOMPONENT__TAO_SEQ_CODESETID_CI_

ACE_INLINE
CORBA::ULong *
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::allocbuf (CORBA::ULong size)
{
  CORBA::ULong *retval = 0;
  ACE_NEW_RETURN (retval, CORBA::ULong[size], 0);
  return retval;
}

ACE_INLINE
void CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::freebuf (CORBA::ULong *buffer)
{
  delete [] buffer;
}

ACE_INLINE
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (void)
{
}

ACE_INLINE
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (CORBA::ULong maximum) 
  : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::allocbuf (maximum))
{
}

ACE_INLINE
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (
    CORBA::ULong maximum,
    CORBA::ULong length,
    CORBA::ULong *data,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Base_Sequence (maximum, length, data, release)
{
}

ACE_INLINE
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId (
    const _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId &rhs
  )
  : TAO_Unbounded_Base_Sequence (rhs)
{
  if (rhs.buffer_ != 0)
    {
      CORBA::ULong *tmp1 =
        _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::allocbuf (this->maximum_);
      CORBA::ULong * const tmp2 =
        ACE_reinterpret_cast (CORBA::ULong * ACE_CAST_CONST, rhs.buffer_);
      
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
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId &
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::operator= (
    const _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId &rhs
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
          CORBA::ULong *tmp =
            ACE_reinterpret_cast (CORBA::ULong *, this->buffer_);
          
          _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::freebuf (tmp);
          
          this->buffer_ =
            _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::allocbuf (rhs.maximum_);
        }
    }
  else
    {
      this->buffer_ =
        _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::allocbuf (rhs.maximum_);
    }
  
  TAO_Unbounded_Base_Sequence::operator= (rhs);
  
  CORBA::ULong *tmp1 =
    ACE_reinterpret_cast (CORBA::ULong *, this->buffer_);
  CORBA::ULong * const tmp2 =
    ACE_reinterpret_cast (CORBA::ULong * ACE_CAST_CONST, rhs.buffer_);
  
  for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      tmp1[i] = tmp2[i];
    }
  
  return *this;
}

// = Accessors.
ACE_INLINE
CORBA::ULong &
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::operator[] (CORBA::ULong i)
{
  ACE_ASSERT (i < this->maximum_);
  CORBA::ULong* tmp =
    ACE_reinterpret_cast (CORBA::ULong*, this->buffer_);
  return tmp[i];
}

ACE_INLINE
const CORBA::ULong &
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::operator[] (CORBA::ULong i) const
{
  ACE_ASSERT (i < this->maximum_);
  CORBA::ULong * const tmp =
    ACE_reinterpret_cast (CORBA::ULong* ACE_CAST_CONST, this->buffer_);
  return tmp[i];
}

// Implement the TAO_Base_Sequence methods (see Sequence.h)

ACE_INLINE
CORBA::ULong *
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::get_buffer (CORBA::Boolean orphan)
{
  CORBA::ULong *result = 0;
  
  if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
        {
          result =
            _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::allocbuf (this->length_);
          this->buffer_ = result;
          this->release_ = 1;
        }
      else
        {
          result =
            ACE_reinterpret_cast (CORBA::ULong*, this->buffer_);
        }
    }
  else // if (orphan == 1)
    {
      if (this->release_ != 0)
        {
          // We set the state back to default and relinquish ownership.
          result =
            ACE_reinterpret_cast(CORBA::ULong*,this->buffer_);
          this->maximum_ = 0;
          this->length_ = 0;
          this->buffer_ = 0;
          this->release_ = 0;
        }
    }
  
  return result;
}

ACE_INLINE
const CORBA::ULong *
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::get_buffer (void) const
{
  return ACE_reinterpret_cast (const CORBA::ULong * ACE_CAST_CONST, this->buffer_);
}

ACE_INLINE
void
CONV_FRAME::CodeSetComponent::_TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::replace (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ULong *data,
    CORBA::Boolean release
  )
{
  this->maximum_ = max;
  this->length_ = length;
  
  if (this->buffer_ && this->release_ == 1)
    {
      CORBA::ULong *tmp =
        ACE_reinterpret_cast (CORBA::ULong*, this->buffer_);
      _TAO_Unbounded_Sequence_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId::freebuf (tmp);
    }
  
  this->buffer_ = data;
  this->release_ = release;
}

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:194

// *************************************************************
// Inline operations for class CONV_FRAME::CodeSetComponentInfo_var
// *************************************************************

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var::CodeSetComponentInfo_var (void)
  : ptr_ (0)
{}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var::CodeSetComponentInfo_var (CodeSetComponentInfo *p)
  : ptr_ (p)
{}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var::CodeSetComponentInfo_var (const ::CONV_FRAME::CodeSetComponentInfo_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::CONV_FRAME::CodeSetComponentInfo (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var::~CodeSetComponentInfo_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var &
CONV_FRAME::CodeSetComponentInfo_var::operator= (CodeSetComponentInfo *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::CONV_FRAME::CodeSetComponentInfo_var &
CONV_FRAME::CodeSetComponentInfo_var::operator= (const ::CONV_FRAME::CodeSetComponentInfo_var &_tao_struct_var)
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
          CodeSetComponentInfo *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              CodeSetComponentInfo (*_tao_struct_var.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              CodeSetComponentInfo *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::CONV_FRAME::CodeSetComponentInfo *
CONV_FRAME::CodeSetComponentInfo_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponentInfo *
CONV_FRAME::CodeSetComponentInfo_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var::operator const ::CONV_FRAME::CodeSetComponentInfo &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var::operator ::CONV_FRAME::CodeSetComponentInfo &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var::operator ::CONV_FRAME::CodeSetComponentInfo &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_var::operator ::CONV_FRAME::CodeSetComponentInfo *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::CONV_FRAME::CodeSetComponentInfo &
CONV_FRAME::CodeSetComponentInfo_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponentInfo &
CONV_FRAME::CodeSetComponentInfo_var::inout (void)
{
  return *this->ptr_;
}

// Mapping for variable size.
ACE_INLINE ::CONV_FRAME::CodeSetComponentInfo *&
CONV_FRAME::CodeSetComponentInfo_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponentInfo *
CONV_FRAME::CodeSetComponentInfo_var::_retn (void)
{
  ::CONV_FRAME::CodeSetComponentInfo *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponentInfo *
CONV_FRAME::CodeSetComponentInfo_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:523

// *************************************************************
// Inline operations for class CONV_FRAME::CodeSetComponentInfo_out
// *************************************************************

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_out::CodeSetComponentInfo_out (::CONV_FRAME::CodeSetComponentInfo *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_out::CodeSetComponentInfo_out (CodeSetComponentInfo_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_out::CodeSetComponentInfo_out (const ::CONV_FRAME::CodeSetComponentInfo_out &p)
  : ptr_ (ACE_const_cast (CodeSetComponentInfo_out&, p).ptr_)
{}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_out &
CONV_FRAME::CodeSetComponentInfo_out::operator= (const ::CONV_FRAME::CodeSetComponentInfo_out &p)
{
  this->ptr_ = ACE_const_cast (CodeSetComponentInfo_out&, p).ptr_;
  return *this;
}

ACE_INLINE
CONV_FRAME::CodeSetComponentInfo_out &
CONV_FRAME::CodeSetComponentInfo_out::operator= (CodeSetComponentInfo *_tao_struct_out)
{
  this->ptr_ = _tao_struct_out;
  return *this;
}

ACE_INLINE 
CONV_FRAME::CodeSetComponentInfo_out::operator ::CONV_FRAME::CodeSetComponentInfo *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponentInfo *&
CONV_FRAME::CodeSetComponentInfo_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetComponentInfo *
CONV_FRAME::CodeSetComponentInfo_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_structure.cpp:194

// *************************************************************
// Inline operations for class CONV_FRAME::CodeSetContext_var
// *************************************************************

ACE_INLINE
CONV_FRAME::CodeSetContext_var::CodeSetContext_var (void)
  : ptr_ (0)
{}

ACE_INLINE
CONV_FRAME::CodeSetContext_var::CodeSetContext_var (CodeSetContext *p)
  : ptr_ (p)
{}

ACE_INLINE
CONV_FRAME::CodeSetContext_var::CodeSetContext_var (const ::CONV_FRAME::CodeSetContext_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::CONV_FRAME::CodeSetContext (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

// Fixed-size types only.
ACE_INLINE
CONV_FRAME::CodeSetContext_var::CodeSetContext_var (const ::CONV_FRAME::CodeSetContext &p)
{
  ACE_NEW (this->ptr_, ::CONV_FRAME::CodeSetContext (p));
}

ACE_INLINE
CONV_FRAME::CodeSetContext_var::~CodeSetContext_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetContext_var &
CONV_FRAME::CodeSetContext_var::operator= (CodeSetContext *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::CONV_FRAME::CodeSetContext_var &
CONV_FRAME::CodeSetContext_var::operator= (const ::CONV_FRAME::CodeSetContext_var &_tao_struct_var)
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
          CodeSetContext *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              CodeSetContext (*_tao_struct_var.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              CodeSetContext *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

// fixed-size types only
ACE_INLINE CONV_FRAME::CodeSetContext_var &
CONV_FRAME::CodeSetContext_var::operator= (const ::CONV_FRAME::CodeSetContext &p)
{
  if (this->ptr_ != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (
        this->ptr_,
        ::CONV_FRAME::CodeSetContext (p),
        *this
      );
  }
  
  return *this;
}

ACE_INLINE const ::CONV_FRAME::CodeSetContext *
CONV_FRAME::CodeSetContext_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetContext *
CONV_FRAME::CodeSetContext_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetContext_var::operator const ::CONV_FRAME::CodeSetContext &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetContext_var::operator ::CONV_FRAME::CodeSetContext &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CONV_FRAME::CodeSetContext_var::operator ::CONV_FRAME::CodeSetContext &() const // cast 
{
  return *this->ptr_;
}

ACE_INLINE const ::CONV_FRAME::CodeSetContext &
CONV_FRAME::CodeSetContext_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetContext &
CONV_FRAME::CodeSetContext_var::inout (void)
{
  return *this->ptr_;
}

// mapping for fixed size 
ACE_INLINE ::CONV_FRAME::CodeSetContext &
CONV_FRAME::CodeSetContext_var::out (void)
{
  return *this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetContext
CONV_FRAME::CodeSetContext_var::_retn (void)
{
  return *this->ptr_;
}

ACE_INLINE ::CONV_FRAME::CodeSetContext *
CONV_FRAME::CodeSetContext_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId_I_
#define _TAO_CDR_OP_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const CONV_FRAME::CodeSetComponent::_tao_seq_CodeSetId &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    CONV_FRAME::CodeSetComponent::_tao_seq_CodeSetId &
  );

#endif /* _TAO_CDR_OP_CONV_FRAME_CodeSetComponent__tao_seq_CodeSetId_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:103

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CONV_FRAME::CodeSetComponent &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.native_code_set) &&
    (strm << _tao_aggregate.conversion_code_sets)
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
    CONV_FRAME::CodeSetComponent &_tao_aggregate
  )
{
  if (
    (strm >> _tao_aggregate.native_code_set) &&
    (strm >> _tao_aggregate.conversion_code_sets)
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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:103

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CONV_FRAME::CodeSetComponentInfo &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.ForCharData) &&
    (strm << _tao_aggregate.ForWcharData)
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
    CONV_FRAME::CodeSetComponentInfo &_tao_aggregate
  )
{
  if (
    (strm >> _tao_aggregate.ForCharData) &&
    (strm >> _tao_aggregate.ForWcharData)
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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:103

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CONV_FRAME::CodeSetContext &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.char_data) &&
    (strm << _tao_aggregate.wchar_data)
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
    CONV_FRAME::CodeSetContext &_tao_aggregate
  )
{
  if (
    (strm >> _tao_aggregate.char_data) &&
    (strm >> _tao_aggregate.wchar_data)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

