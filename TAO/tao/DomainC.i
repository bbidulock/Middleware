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

#if !defined (_CORBA_DOMAINMANAGER___CI_)
#define _CORBA_DOMAINMANAGER___CI_

ACE_INLINE
CORBA::DomainManager::DomainManager (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_DomainManager_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::Boolean
CORBA::DomainManager::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_CORBA_CONSTRUCTIONPOLICY___CI_)
#define _CORBA_CONSTRUCTIONPOLICY___CI_

ACE_INLINE
CORBA::ConstructionPolicy::ConstructionPolicy (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant
  )
  : CORBA_Object (objref, _tao_collocated, servant)
{
  this->CORBA_ConstructionPolicy_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::Boolean
CORBA::ConstructionPolicy::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_obj_sequence_ci.cpp:108

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_DOMAINMANAGERLIST_CI_)
#define __TAO_UNBOUNDED_OBJECT_SEQUENCE_CORBA_DOMAINMANAGERLIST_CI_

ACE_INLINE
CORBA::DomainManager **
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::allocbuf (CORBA::ULong nelems)
{
  CORBA::DomainManager **buf = 0;
  
  ACE_NEW_RETURN (buf, CORBA::DomainManager*[nelems], 0);
  
  for (CORBA::ULong i = 0; i < nelems; i++)
    {
      buf[i] = CORBA::DomainManager::_nil ();
    }
  
  return buf;
}

ACE_INLINE
void 
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::freebuf (CORBA::DomainManager **buffer)
{
  if (buffer == 0)
    {
      return;
    }
  
  delete[] buffer;
}

ACE_INLINE
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList (void)
{
}

ACE_INLINE
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList (CORBA::ULong maximum)
  : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::allocbuf (maximum))
{
}

ACE_INLINE
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList (
    CORBA::ULong maximum,
    CORBA::ULong length,
    CORBA::DomainManager* *value,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Base_Sequence (maximum, length, value, release)
{
}

ACE_INLINE
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList(
    const _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList &rhs
  )
  : TAO_Unbounded_Base_Sequence (rhs)
{
  if (rhs.buffer_ != 0)
    {
      CORBA::DomainManager **tmp1 =
        _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::allocbuf (this->maximum_);
      CORBA::DomainManager ** const tmp2 =
        ACE_reinterpret_cast (CORBA::DomainManager ** ACE_CAST_CONST, rhs.buffer_);
      
      for (CORBA::ULong i = 0; i < rhs.length_; ++i)
        {
          tmp1[i] = CORBA::DomainManager::_duplicate (tmp2[i]);
        }
      
      this->buffer_ = tmp1;
    }
  else
    {
      this->buffer_ = 0;
    }
}

ACE_INLINE
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList &
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::operator= (
    const _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList &rhs
  )
{
  if (this == &rhs)
    {
      return *this;
    }
  
  if (this->release_)
    {
      CORBA::DomainManager **tmp =
        ACE_reinterpret_cast (CORBA::DomainManager **, this->buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        {
          CORBA::release (tmp[i]);
          tmp[i] = CORBA::DomainManager::_nil ();
        }
      
      if (this->maximum_ < rhs.maximum_)
        {
          _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::freebuf (tmp);
          this->buffer_ = _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::allocbuf (rhs.maximum_);
        }
    }
  else
    {
      this->buffer_ =
        _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::allocbuf (rhs.maximum_);
    }
  
  TAO_Unbounded_Base_Sequence::operator= (rhs);
  
  CORBA::DomainManager **tmp1 =
    ACE_reinterpret_cast (CORBA::DomainManager **, this->buffer_);
  
  CORBA::DomainManager ** const tmp2 =
    ACE_reinterpret_cast (CORBA::DomainManager ** ACE_CAST_CONST, rhs.buffer_);
  
  for (CORBA::ULong i = 0; i < rhs.length_; ++i)
    {
      tmp1[i] = CORBA::DomainManager::_duplicate (tmp2[i]);
    }
  
  return *this;
}

ACE_INLINE
TAO_Object_Manager<CORBA::DomainManager,CORBA::DomainManager_var>
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::operator[] (CORBA::ULong index) const
{
  ACE_ASSERT (index < this->maximum_);
  CORBA::DomainManager ** const tmp =
    ACE_reinterpret_cast (CORBA::DomainManager ** ACE_CAST_CONST, this->buffer_);
  return TAO_Object_Manager<CORBA::DomainManager,CORBA::DomainManager_var> (tmp + index, this->release_);
}

ACE_INLINE
CORBA::DomainManager* *
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::get_buffer (CORBA::Boolean orphan)
{
  CORBA::DomainManager **result = 0;
  
  if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
        {
          result =
            _TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::allocbuf (this->maximum_);
          this->buffer_ = result;
          this->release_ = 1;
        }
      else
        {
          result =
            ACE_reinterpret_cast (CORBA::DomainManager**, this->buffer_);
        }
    }
  else // if (orphan == 1)
    {
      if (this->release_ != 0)
        {
          // We set the state back to default and relinquish ownership.
          result =
            ACE_reinterpret_cast(CORBA::DomainManager**,this->buffer_);
          this->maximum_ = 0;
          this->length_ = 0;
          this->buffer_ = 0;
          this->release_ = 0;
        }
    }
  
  return result;
}

ACE_INLINE
const CORBA::DomainManager* *
CORBA::_TAO_Unbounded_Object_Sequence_CORBA_DomainManagerList::get_buffer (void) const
{
  return ACE_reinterpret_cast (const CORBA::DomainManager ** ACE_CAST_CONST, this->buffer_);
}

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_CORBA_DOMAINMANAGERLIST_CI_)
#define _CORBA_DOMAINMANAGERLIST_CI_

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:226

// *************************************************************
// Inline operations for class CORBA::DomainManagerList_var
// *************************************************************

ACE_INLINE
CORBA::DomainManagerList_var::DomainManagerList_var (void)
  : ptr_ (0)
{}

ACE_INLINE
CORBA::DomainManagerList_var::DomainManagerList_var (DomainManagerList *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA::DomainManagerList_var::DomainManagerList_var (const ::CORBA::DomainManagerList_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::CORBA::DomainManagerList (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
CORBA::DomainManagerList_var::~DomainManagerList_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
CORBA::DomainManagerList_var &
CORBA::DomainManagerList_var::operator= (DomainManagerList *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
::CORBA::DomainManagerList_var &
CORBA::DomainManagerList_var::operator= (const ::CORBA::DomainManagerList_var &p)
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
          DomainManagerList *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              DomainManagerList (*p.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              DomainManagerList *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE
const ::CORBA::DomainManagerList *
CORBA::DomainManagerList_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE
::CORBA::DomainManagerList *
CORBA::DomainManagerList_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA::DomainManagerList_var::operator const ::CORBA::DomainManagerList &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::DomainManagerList_var::operator ::CORBA::DomainManagerList &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::DomainManagerList_var::operator ::CORBA::DomainManagerList &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
CORBA::DomainManagerList_var::operator ::CORBA::DomainManagerList *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE
TAO_Object_Manager<CORBA::DomainManager, CORBA::DomainManager_var>
CORBA::DomainManagerList_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
const ::CORBA::DomainManagerList &
CORBA::DomainManagerList_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE
::CORBA::DomainManagerList &
CORBA::DomainManagerList_var::inout (void)
{
  return *this->ptr_;
}

ACE_INLINE
::CORBA::DomainManagerList *&
CORBA::DomainManagerList_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE
::CORBA::DomainManagerList *
CORBA::DomainManagerList_var::_retn (void)
{
  ::CORBA::DomainManagerList *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE
::CORBA::DomainManagerList *
CORBA::DomainManagerList_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:567

// *************************************************************
// Inline operations for class CORBA::DomainManagerList_out
// *************************************************************

ACE_INLINE
CORBA::DomainManagerList_out::DomainManagerList_out (DomainManagerList *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::DomainManagerList_out::DomainManagerList_out (DomainManagerList_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA::DomainManagerList_out::DomainManagerList_out (const ::CORBA::DomainManagerList_out &p)
  : ptr_ (ACE_const_cast (DomainManagerList_out&, p).ptr_)
{}

ACE_INLINE
::CORBA::DomainManagerList_out &
CORBA::DomainManagerList_out::operator= (const ::CORBA::DomainManagerList_out &p)
{
  this->ptr_ = ACE_const_cast (DomainManagerList_out&, p).ptr_;
  return *this;
}

ACE_INLINE
::CORBA::DomainManagerList_out &
CORBA::DomainManagerList_out::operator= (DomainManagerList *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA::DomainManagerList_out::operator ::CORBA::DomainManagerList *&() // cast
{
  return this->ptr_;
}

ACE_INLINE
::CORBA::DomainManagerList *&
CORBA::DomainManagerList_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE
::CORBA::DomainManagerList *
CORBA::DomainManagerList_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
TAO_Object_Manager<CORBA::DomainManager, CORBA::DomainManager_var>
CORBA::DomainManagerList_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::DomainManager_ptr
  );

TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::DomainManager_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ConstructionPolicy_ptr
  );

TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ConstructionPolicy_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_CORBA_DomainManagerList_I_
#define _TAO_CDR_OP_CORBA_DomainManagerList_I_

CORBA::Boolean TAO_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::DomainManagerList &
  );

CORBA::Boolean TAO_Export operator>> (
    TAO_InputCDR &,
    CORBA::DomainManagerList &
  );

#endif /* _TAO_CDR_OP_CORBA_DomainManagerList_I_ */

