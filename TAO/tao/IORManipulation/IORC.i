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

// *************************************************************
// Inline operations for exception TAO_IOP::EmptyProfileList
// *************************************************************

// *************************************************************
// Inline operations for exception TAO_IOP::NotFound
// *************************************************************

// *************************************************************
// Inline operations for exception TAO_IOP::Duplicate
// *************************************************************

// *************************************************************
// Inline operations for exception TAO_IOP::Invalid_IOR
// *************************************************************

// *************************************************************
// Inline operations for exception TAO_IOP::MultiProfileList
// *************************************************************


#if !defined (_TAO_IOP_TAO_IOR_PROPERTY___CI_)
#define _TAO_IOP_TAO_IOR_PROPERTY___CI_


#endif /* end #if !defined */


#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_

ACE_INLINE CORBA::Object **
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (CORBA::ULong nelems)
{
  CORBA::Object **buf = 0;
  
  ACE_NEW_RETURN (buf, CORBA::Object*[nelems], 0);
  
  for (CORBA::ULong i = 0; i < nelems; i++)
    {
      buf[i] = CORBA::Object::_nil ();
    }
  
  return buf;
}

ACE_INLINE void 
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::freebuf (CORBA::Object **buffer)
{
  if (buffer == 0)
    return;
  delete[] buffer;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (void)
{
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (CORBA::ULong maximum)
  : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (maximum))
{
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList (CORBA::ULong maximum,
  CORBA::ULong length,
  CORBA::Object* *value,
  CORBA::Boolean release)
: TAO_Unbounded_Base_Sequence (maximum, length, value, release)
{
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList(const _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &rhs)
  : TAO_Unbounded_Base_Sequence (rhs)
{
  if (rhs.buffer_ != 0)
  {
    CORBA::Object **tmp1 = _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (this->maximum_);
    CORBA::Object ** const tmp2 = ACE_reinterpret_cast (CORBA::Object ** ACE_CAST_CONST, rhs.buffer_);
    
    for (CORBA::ULong i = 0; i < rhs.length_; ++i)
      {
        tmp1[i] = CORBA::Object::_duplicate (tmp2[i]);
      }
    
    this->buffer_ = tmp1;
  }
  else
  {
    this->buffer_ = 0;
  }
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::operator= (const _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &rhs)
{
  if (this == &rhs)
    return *this;
  
  if (this->release_)
  {
    CORBA::Object **tmp = ACE_reinterpret_cast (CORBA::Object **, this->buffer_);
    
    for (CORBA::ULong i = 0; i < this->length_; ++i)
    {
      CORBA::release (tmp[i]);
      tmp[i] = CORBA::Object::_nil ();
    }
    if (this->maximum_ < rhs.maximum_)
    {
      _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::freebuf (tmp);
      this->buffer_ = _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (rhs.maximum_);
    }
  }
  else
    this->buffer_ = _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (rhs.maximum_);
  
  TAO_Unbounded_Base_Sequence::operator= (rhs);
  
  CORBA::Object **tmp1 = ACE_reinterpret_cast (CORBA::Object **, this->buffer_);
  CORBA::Object ** const tmp2 = ACE_reinterpret_cast (CORBA::Object ** ACE_CAST_CONST, rhs.buffer_);
  
  for (CORBA::ULong i = 0; i < rhs.length_; ++i)
    {
      tmp1[i] = CORBA::Object::_duplicate (tmp2[i]);
    }
  
  return *this;
}

ACE_INLINE TAO_Object_Manager<CORBA::Object,CORBA::Object_var>
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::operator[] (CORBA::ULong index) const
// read-write accessor
{
  ACE_ASSERT (index < this->maximum_);
  CORBA::Object ** const tmp = ACE_reinterpret_cast (CORBA::Object ** ACE_CAST_CONST, this->buffer_);
  return TAO_Object_Manager<CORBA::Object,CORBA::Object_var> (tmp + index, this->release_);
}

ACE_INLINE CORBA::Object* *
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::get_buffer (CORBA::Boolean orphan)
{
  CORBA::Object **result = 0;
  if (orphan == 0)
  {
    // We retain ownership.
    if (this->buffer_ == 0)
    {
      result = _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::allocbuf (this->maximum_);
      this->buffer_ = result;
      this->release_ = 1;
    }
    else
    {
      result = ACE_reinterpret_cast (CORBA::Object**, this->buffer_);
    }
  }
  else // if (orphan == 1)
  {
    if (this->release_ != 0)
    {
      // We set the state back to default and relinquish
      // ownership.
      result = ACE_reinterpret_cast(CORBA::Object**,this->buffer_);
      this->maximum_ = 0;
      this->length_ = 0;
      this->buffer_ = 0;
      this->release_ = 0;
    }
  }
  return result;
}

ACE_INLINE const CORBA::Object* *
TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList::get_buffer (void) const
{
  return ACE_reinterpret_cast(const CORBA::Object ** ACE_CAST_CONST, this->buffer_);
}


#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_

// *************************************************************
// Inline operations for class TAO_IOP::TAO_IOR_Manipulation::IORList_var
// *************************************************************

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::IORList_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::IORList_var (IORList *p)
  : ptr_ (p)
{}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::IORList_var (const ::TAO_IOP::TAO_IOR_Manipulation::IORList_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::TAO_IOP::TAO_IOR_Manipulation::IORList (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::~IORList_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE TAO_IOP::TAO_IOR_Manipulation::IORList_var &
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator= (IORList *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList_var &
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator= (const ::TAO_IOP::TAO_IOR_Manipulation::IORList_var &p)
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
          IORList *deep_copy =
            new IORList (*p.ptr_);
          
          if (deep_copy != 0)
            {
              IORList *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator const ::TAO_IOP::TAO_IOR_Manipulation::IORList &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator ::TAO_IOP::TAO_IOR_Manipulation::IORList &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator ::TAO_IOP::TAO_IOR_Manipulation::IORList &() const // cast 
{
  return *this->ptr_;
}

// variable-size types only
ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator ::TAO_IOP::TAO_IOR_Manipulation::IORList *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE TAO_Object_Manager<CORBA::Object,CORBA::Object_var>
TAO_IOP::TAO_IOR_Manipulation::IORList_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const ::TAO_IOP::TAO_IOR_Manipulation::IORList &
TAO_IOP::TAO_IOR_Manipulation::IORList_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList &
TAO_IOP::TAO_IOR_Manipulation::IORList_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList *&
TAO_IOP::TAO_IOR_Manipulation::IORList_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_var::_retn (void)
{
  ::TAO_IOP::TAO_IOR_Manipulation::IORList *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class TAO_IOP::TAO_IOR_Manipulation::IORList_out
// *************************************************************

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_out::IORList_out (IORList *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_out::IORList_out (IORList_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
TAO_IOP::TAO_IOR_Manipulation::IORList_out::IORList_out (const ::TAO_IOP::TAO_IOR_Manipulation::IORList_out &p) // copy constructor
  : ptr_ (ACE_const_cast (IORList_out&, p).ptr_)
{}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList_out &
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator= (const ::TAO_IOP::TAO_IOR_Manipulation::IORList_out &p)
{
  this->ptr_ = ACE_const_cast (IORList_out&, p).ptr_;
  return *this;
}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList_out &
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator= (IORList *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator ::TAO_IOP::TAO_IOR_Manipulation::IORList *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList *&
TAO_IOP::TAO_IOR_Manipulation::IORList_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::TAO_IOP::TAO_IOR_Manipulation::IORList *
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE TAO_Object_Manager<CORBA::Object,CORBA::Object_var>
TAO_IOP::TAO_IOR_Manipulation::IORList_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}


#endif /* end #if !defined */


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION___CI_)
#define _TAO_IOP_TAO_IOR_MANIPULATION___CI_


#endif /* end #if !defined */

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::EmptyProfileList &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._rep_id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &,TAO_IOP::EmptyProfileList&)
{
  return 1;
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::NotFound &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._rep_id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &,TAO_IOP::NotFound&)
{
  return 1;
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::Duplicate &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._rep_id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &,TAO_IOP::Duplicate&)
{
  return 1;
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::Invalid_IOR &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._rep_id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &,TAO_IOP::Invalid_IOR&)
{
  return 1;
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO_IOP::MultiProfileList &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._rep_id ())
    return 1;
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &,TAO_IOP::MultiProfileList&)
{
  return 1;
}

