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


#if !defined (_COMPONENTS_IDDATA_CI_)
#define _COMPONENTS_IDDATA_CI_

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:226

// *************************************************************
// Inline operations for class Components::IdData_var
// *************************************************************

ACE_INLINE
Components::IdData_var::IdData_var (void)
  : ptr_ (0)
{}

ACE_INLINE
Components::IdData_var::IdData_var (IdData *p)
  : ptr_ (p)
{}

ACE_INLINE
Components::IdData_var::IdData_var (const ::Components::IdData_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::Components::IdData (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

// Fixed-size base types only.
ACE_INLINE
Components::IdData_var::IdData_var (const ::Components::IdData &p)
{
  ACE_NEW (this->ptr_, ::Components::IdData (p));
}

ACE_INLINE
Components::IdData_var::~IdData_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
Components::IdData_var &
Components::IdData_var::operator= (IdData *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
::Components::IdData_var &
Components::IdData_var::operator= (const ::Components::IdData_var &p)
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
          IdData *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              IdData (*p.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              IdData *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

// Fixed-size types only.
ACE_INLINE
::Components::IdData_var &
Components::IdData_var::operator= (const ::Components::IdData &p)
{
  if (this->ptr_ != &p)
    {
      delete this->ptr_;
      ACE_NEW_RETURN (this->ptr_, ::Components::IdData (p), *this);
    }
  
  return *this;
}

ACE_INLINE
const ::Components::IdData *
Components::IdData_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE
::Components::IdData *
Components::IdData_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
Components::IdData_var::operator const ::Components::IdData &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
Components::IdData_var::operator ::Components::IdData &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
Components::IdData_var::operator ::Components::IdData &() const // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::Octet &
Components::IdData_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
const CORBA::Octet &
Components::IdData_var::operator[] (CORBA::ULong index) const
{
  return ACE_const_cast (const CORBA::Octet &, this->ptr_->operator[] (index));
}

ACE_INLINE
const ::Components::IdData &
Components::IdData_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE
::Components::IdData &
Components::IdData_var::inout (void)
{
  return *this->ptr_;
}

ACE_INLINE
::Components::IdData *&
Components::IdData_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE
::Components::IdData *
Components::IdData_var::_retn (void)
{
  ::Components::IdData *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE
::Components::IdData *
Components::IdData_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:567

// *************************************************************
// Inline operations for class Components::IdData_out
// *************************************************************

ACE_INLINE
Components::IdData_out::IdData_out (IdData *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
Components::IdData_out::IdData_out (IdData_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
Components::IdData_out::IdData_out (const ::Components::IdData_out &p)
  : ptr_ (ACE_const_cast (IdData_out&, p).ptr_)
{}

ACE_INLINE
::Components::IdData_out &
Components::IdData_out::operator= (const ::Components::IdData_out &p)
{
  this->ptr_ = ACE_const_cast (IdData_out&, p).ptr_;
  return *this;
}

ACE_INLINE
::Components::IdData_out &
Components::IdData_out::operator= (IdData *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
Components::IdData_out::operator ::Components::IdData *&() // cast
{
  return this->ptr_;
}

ACE_INLINE
::Components::IdData *&
Components::IdData_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE
::Components::IdData *
Components::IdData_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA::Octet &
Components::IdData_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_HOMEREGISTRATION___CI_)
#define _COMPONENTS_HOMEREGISTRATION___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_CCM2CONTEXT___CI_)
#define _COMPONENTS_CCM2CONTEXT___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_PROXYHOMEREGISTRATION___CI_)
#define _COMPONENTS_PROXYHOMEREGISTRATION___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_SESSION2CONTEXT___CI_)
#define _COMPONENTS_SESSION2CONTEXT___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ci.cpp:56

ACE_INLINE
Components::StateIdValue::StateIdValue (void)
{}

ACE_INLINE
Components::StateIdValue::~StateIdValue (void)
{}

ACE_INLINE const char* 
Components::StateIdValue::_tao_obv_static_repository_id ()
{
  return "IDL:omg.org/Components/StateIdValue:1.0";
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_STATEIDFACTORY___CI_)
#define _COMPONENTS_STATEIDFACTORY___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ci.cpp:56

ACE_INLINE
Components::PersistentIdValue::PersistentIdValue (void)
{}

ACE_INLINE
Components::PersistentIdValue::~PersistentIdValue (void)
{}

ACE_INLINE const char* 
Components::PersistentIdValue::_tao_obv_static_repository_id ()
{
  return "IDL:omg.org/Components/PersistentIdValue:1.0";
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/valuetype_ci.cpp:56

ACE_INLINE
Components::SegmentDescr::SegmentDescr (void)
{}

ACE_INLINE
Components::SegmentDescr::~SegmentDescr (void)
{}

ACE_INLINE const char* 
Components::SegmentDescr::_tao_obv_static_repository_id ()
{
  return "IDL:omg.org/Components/SegmentDescr:1.0";
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/gen_unbounded_obj_sequence_ci.cpp:108

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_VALUETYPE_SEQUENCE_COMPONENTS_SEGMENTDESCRSEQ_CI_)
#define __TAO_UNBOUNDED_VALUETYPE_SEQUENCE_COMPONENTS_SEGMENTDESCRSEQ_CI_

ACE_INLINE
Components::SegmentDescr **
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::allocbuf (CORBA::ULong nelems)
{
  Components::SegmentDescr **buf = 0;
  
  ACE_NEW_RETURN (buf, Components::SegmentDescr*[nelems], 0);
  
  for (CORBA::ULong i = 0; i < nelems; i++)
    {
      buf[i] = 0;
    }
  
  return buf;
}

ACE_INLINE
void 
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::freebuf (Components::SegmentDescr **buffer)
{
  if (buffer == 0)
    {
      return;
    }
  
  delete[] buffer;
}

ACE_INLINE
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq (void)
{
}

ACE_INLINE
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq (CORBA::ULong maximum)
  : TAO_Unbounded_Base_Sequence (maximum, _TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::allocbuf (maximum))
{
}

ACE_INLINE
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq (
    CORBA::ULong maximum,
    CORBA::ULong length,
    Components::SegmentDescr* *value,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Base_Sequence (maximum, length, value, release)
{
}

ACE_INLINE
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq(
    const _TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq &rhs
  )
  : TAO_Unbounded_Base_Sequence (rhs)
{
  if (rhs.buffer_ != 0)
    {
      Components::SegmentDescr **tmp1 =
        _TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::allocbuf (this->maximum_);
      Components::SegmentDescr ** const tmp2 =
        ACE_reinterpret_cast (Components::SegmentDescr ** ACE_CAST_CONST, rhs.buffer_);
      
      for (CORBA::ULong i = 0; i < rhs.length_; ++i)
        {
          if (tmp2[i] != 0)
            {
              tmp2[i]->_add_ref ();
            }
          
          tmp1[i] = tmp2 [i];
        }
      
      this->buffer_ = tmp1;
    }
  else
    {
      this->buffer_ = 0;
    }
}

ACE_INLINE
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq &
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::operator= (
    const _TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq &rhs
  )
{
  if (this == &rhs)
    {
      return *this;
    }
  
  if (this->release_)
    {
      Components::SegmentDescr **tmp =
        ACE_reinterpret_cast (Components::SegmentDescr **, this->buffer_);
      
      for (CORBA::ULong i = 0; i < this->length_; ++i)
        {
          if (tmp[i] != 0)
            {
              tmp[i]->_remove_ref ();
            }
          
          tmp[i] = 0;
        }
      
      if (this->maximum_ < rhs.maximum_)
        {
          _TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::freebuf (tmp);
          this->buffer_ = _TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::allocbuf (rhs.maximum_);
        }
    }
  else
    {
      this->buffer_ =
        _TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::allocbuf (rhs.maximum_);
    }
  
  TAO_Unbounded_Base_Sequence::operator= (rhs);
  
  Components::SegmentDescr **tmp1 =
    ACE_reinterpret_cast (Components::SegmentDescr **, this->buffer_);
  
  Components::SegmentDescr ** const tmp2 =
    ACE_reinterpret_cast (Components::SegmentDescr ** ACE_CAST_CONST, rhs.buffer_);
  
  for (CORBA::ULong i = 0; i < rhs.length_; ++i)
    {
      if (tmp2[i] != 0)
        {
          tmp2[i]->_add_ref ();
        }
      
      tmp1[i] = tmp2 [i];
    }
  
  return *this;
}

ACE_INLINE
TAO_Valuetype_Manager<Components::SegmentDescr,Components::SegmentDescr_var>
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::operator[] (CORBA::ULong index) const
{
  ACE_ASSERT (index < this->maximum_);
  Components::SegmentDescr ** const tmp =
    ACE_reinterpret_cast (Components::SegmentDescr ** ACE_CAST_CONST, this->buffer_);
  return TAO_Valuetype_Manager<Components::SegmentDescr,Components::SegmentDescr_var> (tmp + index, this->release_);
}

ACE_INLINE
Components::SegmentDescr* *
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::get_buffer (CORBA::Boolean orphan)
{
  Components::SegmentDescr **result = 0;
  
  if (orphan == 0)
    {
      // We retain ownership.
      if (this->buffer_ == 0)
        {
          result =
            _TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::allocbuf (this->maximum_);
          this->buffer_ = result;
          this->release_ = 1;
        }
      else
        {
          result =
            ACE_reinterpret_cast (Components::SegmentDescr**, this->buffer_);
        }
    }
  else // if (orphan == 1)
    {
      if (this->release_ != 0)
        {
          // We set the state back to default and relinquish ownership.
          result =
            ACE_reinterpret_cast(Components::SegmentDescr**,this->buffer_);
          this->maximum_ = 0;
          this->length_ = 0;
          this->buffer_ = 0;
          this->release_ = 0;
        }
    }
  
  return result;
}

ACE_INLINE
const Components::SegmentDescr* *
Components::_TAO_Unbounded_Valuetype_Sequence_Components_SegmentDescrSeq::get_buffer (void) const
{
  return ACE_reinterpret_cast (const Components::SegmentDescr ** ACE_CAST_CONST, this->buffer_);
}

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */ 

#if !defined (_COMPONENTS_SEGMENTDESCRSEQ_CI_)
#define _COMPONENTS_SEGMENTDESCRSEQ_CI_

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:226

// *************************************************************
// Inline operations for class Components::SegmentDescrSeq_var
// *************************************************************

ACE_INLINE
Components::SegmentDescrSeq_var::SegmentDescrSeq_var (void)
  : ptr_ (0)
{}

ACE_INLINE
Components::SegmentDescrSeq_var::SegmentDescrSeq_var (SegmentDescrSeq *p)
  : ptr_ (p)
{}

ACE_INLINE
Components::SegmentDescrSeq_var::SegmentDescrSeq_var (const ::Components::SegmentDescrSeq_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::Components::SegmentDescrSeq (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
Components::SegmentDescrSeq_var::~SegmentDescrSeq_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
Components::SegmentDescrSeq_var &
Components::SegmentDescrSeq_var::operator= (SegmentDescrSeq *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
::Components::SegmentDescrSeq_var &
Components::SegmentDescrSeq_var::operator= (const ::Components::SegmentDescrSeq_var &p)
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
          SegmentDescrSeq *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              SegmentDescrSeq (*p.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              SegmentDescrSeq *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE
const ::Components::SegmentDescrSeq *
Components::SegmentDescrSeq_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE
::Components::SegmentDescrSeq *
Components::SegmentDescrSeq_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
Components::SegmentDescrSeq_var::operator const ::Components::SegmentDescrSeq &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
Components::SegmentDescrSeq_var::operator ::Components::SegmentDescrSeq &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
Components::SegmentDescrSeq_var::operator ::Components::SegmentDescrSeq &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
Components::SegmentDescrSeq_var::operator ::Components::SegmentDescrSeq *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE
TAO_Valuetype_Manager<Components::SegmentDescr, Components::SegmentDescr_var>
Components::SegmentDescrSeq_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
const ::Components::SegmentDescrSeq &
Components::SegmentDescrSeq_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE
::Components::SegmentDescrSeq &
Components::SegmentDescrSeq_var::inout (void)
{
  return *this->ptr_;
}

ACE_INLINE
::Components::SegmentDescrSeq *&
Components::SegmentDescrSeq_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE
::Components::SegmentDescrSeq *
Components::SegmentDescrSeq_var::_retn (void)
{
  ::Components::SegmentDescrSeq *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE
::Components::SegmentDescrSeq *
Components::SegmentDescrSeq_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/sequence_ci.cpp:567

// *************************************************************
// Inline operations for class Components::SegmentDescrSeq_out
// *************************************************************

ACE_INLINE
Components::SegmentDescrSeq_out::SegmentDescrSeq_out (SegmentDescrSeq *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
Components::SegmentDescrSeq_out::SegmentDescrSeq_out (SegmentDescrSeq_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
Components::SegmentDescrSeq_out::SegmentDescrSeq_out (const ::Components::SegmentDescrSeq_out &p)
  : ptr_ (ACE_const_cast (SegmentDescrSeq_out&, p).ptr_)
{}

ACE_INLINE
::Components::SegmentDescrSeq_out &
Components::SegmentDescrSeq_out::operator= (const ::Components::SegmentDescrSeq_out &p)
{
  this->ptr_ = ACE_const_cast (SegmentDescrSeq_out&, p).ptr_;
  return *this;
}

ACE_INLINE
::Components::SegmentDescrSeq_out &
Components::SegmentDescrSeq_out::operator= (SegmentDescrSeq *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
Components::SegmentDescrSeq_out::operator ::Components::SegmentDescrSeq *&() // cast
{
  return this->ptr_;
}

ACE_INLINE
::Components::SegmentDescrSeq *&
Components::SegmentDescrSeq_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE
::Components::SegmentDescrSeq *
Components::SegmentDescrSeq_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
TAO_Valuetype_Manager<Components::SegmentDescr, Components::SegmentDescr_var>
Components::SegmentDescrSeq_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_COMPONENTID___CI_)
#define _COMPONENTS_COMPONENTID___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_ENTITY2CONTEXT___CI_)
#define _COMPONENTS_ENTITY2CONTEXT___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_EXECUTORLOCATOR___CI_)
#define _COMPONENTS_EXECUTORLOCATOR___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_COMPONENTS_HOMEEXECUTORBASE___CI_)
#define _COMPONENTS_HOMEEXECUTORBASE___CI_

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_enum/cdr_op_ci.cpp:51

ACE_INLINE
CORBA::Boolean operator<< (TAO_OutputCDR &strm, const Components::BadComponentReferenceReason &_tao_enumval)
{
  CORBA::ULong _tao_temp = _tao_enumval;
  return strm << _tao_temp;
}

ACE_INLINE
CORBA::Boolean operator>> (TAO_InputCDR &strm, Components::BadComponentReferenceReason &_tao_enumval)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean _tao_result = strm >> _tao_temp;
  
  if (_tao_result == 1)
    {
      _tao_enumval = ACE_static_cast (Components::BadComponentReferenceReason, _tao_temp);
    }
  
  return _tao_result;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_Components_IdData_I_
#define _TAO_CDR_OP_Components_IdData_I_

CORBA::Boolean CIAO_Export operator<< (
    TAO_OutputCDR &,
    const Components::IdData &
  );

CORBA::Boolean CIAO_Export operator>> (
    TAO_InputCDR &,
    Components::IdData &
  );

#endif /* _TAO_CDR_OP_Components_IdData_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Components::BadComponentReference &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
    {
      // Now marshal the members (if any).
      if (
        (strm << _tao_aggregate.reason)
       )
        {
          return 1;
        }
      else
        {
          return 0;
        }
    }
  else
    {
      return 0;
    }
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Components::BadComponentReference &_tao_aggregate
  )
{
  // Demarshal the members.
  if (
    (strm >> _tao_aggregate.reason)
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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Components::PolicyMismatch &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    Components::PolicyMismatch&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Components::PersistenceNotAvailable &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    Components::PersistenceNotAvailable&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Components::UnknownActualHome &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    Components::UnknownActualHome&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Components::ProxyHomeNotSupported &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    Components::ProxyHomeNotSupported&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Components::InvalidStateIdData &_tao_aggregate
  )
{
  // First marshal the repository ID.
  if (strm << _tao_aggregate._rep_id ())
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
    TAO_InputCDR &,
    Components::InvalidStateIdData&
  )
{
  return 1;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:712

#if defined (__ACE_INLINE__)

TAO_NAMESPACE CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (Components::StateIdValue *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (Components::StateIdValue *);
}
TAO_NAMESPACE_CLOSE

#endif /*__ACE_INLINE__*/

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_ci.cpp:60

CIAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Components::StateIdValue *);
CIAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, Components::StateIdValue *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:712

#if defined (__ACE_INLINE__)

TAO_NAMESPACE CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (Components::PersistentIdValue *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (Components::PersistentIdValue *);
}
TAO_NAMESPACE_CLOSE

#endif /*__ACE_INLINE__*/

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_ci.cpp:60

CIAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Components::PersistentIdValue *);
CIAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, Components::PersistentIdValue *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_valuetype.cpp:712

#if defined (__ACE_INLINE__)

TAO_NAMESPACE CORBA
{
  TAO_NAMESPACE_STORAGE_CLASS void add_ref (Components::SegmentDescr *);
  TAO_NAMESPACE_STORAGE_CLASS void remove_ref (Components::SegmentDescr *);
}
TAO_NAMESPACE_CLOSE

#endif /*__ACE_INLINE__*/

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_valuetype/cdr_op_ci.cpp:60

CIAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const Components::SegmentDescr *);
CIAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, Components::SegmentDescr *&);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_Components_SegmentDescrSeq_I_
#define _TAO_CDR_OP_Components_SegmentDescrSeq_I_

CORBA::Boolean CIAO_Export operator<< (
    TAO_OutputCDR &,
    const Components::SegmentDescrSeq &
  );

CORBA::Boolean CIAO_Export operator>> (
    TAO_InputCDR &,
    Components::SegmentDescrSeq &
  );

#endif /* _TAO_CDR_OP_Components_SegmentDescrSeq_I_ */

