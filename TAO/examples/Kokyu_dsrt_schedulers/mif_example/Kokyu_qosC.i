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


#if !defined (_KOKYU_GUIDTYPE_CI_)
#define _KOKYU_GUIDTYPE_CI_

// TAO_IDL - Generated from 
// be/be_visitor_sequence/sequence_ci.cpp:226

// *************************************************************
// Inline operations for class Kokyu::GuidType_var
// *************************************************************

ACE_INLINE
Kokyu::GuidType_var::GuidType_var (void)
  : ptr_ (0)
{}

ACE_INLINE
Kokyu::GuidType_var::GuidType_var (GuidType *p)
  : ptr_ (p)
{}

ACE_INLINE
Kokyu::GuidType_var::GuidType_var (const ::Kokyu::GuidType_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::Kokyu::GuidType (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

// Fixed-size base types only.
ACE_INLINE
Kokyu::GuidType_var::GuidType_var (const ::Kokyu::GuidType &p)
{
  ACE_NEW (this->ptr_, ::Kokyu::GuidType (p));
}

ACE_INLINE
Kokyu::GuidType_var::~GuidType_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
Kokyu::GuidType_var &
Kokyu::GuidType_var::operator= (GuidType *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
::Kokyu::GuidType_var &
Kokyu::GuidType_var::operator= (const ::Kokyu::GuidType_var &p)
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
          GuidType *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              GuidType (*p.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              GuidType *tmp = deep_copy;
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
::Kokyu::GuidType_var &
Kokyu::GuidType_var::operator= (const ::Kokyu::GuidType &p)
{
  if (this->ptr_ != &p)
    {
      delete this->ptr_;
      ACE_NEW_RETURN (this->ptr_, ::Kokyu::GuidType (p), *this);
    }
  
  return *this;
}

ACE_INLINE
const ::Kokyu::GuidType *
Kokyu::GuidType_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE
::Kokyu::GuidType *
Kokyu::GuidType_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
Kokyu::GuidType_var::operator const ::Kokyu::GuidType &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
Kokyu::GuidType_var::operator ::Kokyu::GuidType &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
Kokyu::GuidType_var::operator ::Kokyu::GuidType &() const // cast 
{
  return *this->ptr_;
}

ACE_INLINE
CORBA::Octet &
Kokyu::GuidType_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
const CORBA::Octet &
Kokyu::GuidType_var::operator[] (CORBA::ULong index) const
{
  return ACE_const_cast (const CORBA::Octet &, this->ptr_->operator[] (index));
}

ACE_INLINE
const ::Kokyu::GuidType &
Kokyu::GuidType_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE
::Kokyu::GuidType &
Kokyu::GuidType_var::inout (void)
{
  return *this->ptr_;
}

ACE_INLINE
::Kokyu::GuidType *&
Kokyu::GuidType_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE
::Kokyu::GuidType *
Kokyu::GuidType_var::_retn (void)
{
  ::Kokyu::GuidType *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE
::Kokyu::GuidType *
Kokyu::GuidType_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from 
// be/be_visitor_sequence/sequence_ci.cpp:567

// *************************************************************
// Inline operations for class Kokyu::GuidType_out
// *************************************************************

ACE_INLINE
Kokyu::GuidType_out::GuidType_out (GuidType *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
Kokyu::GuidType_out::GuidType_out (GuidType_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
Kokyu::GuidType_out::GuidType_out (const ::Kokyu::GuidType_out &p)
  : ptr_ (ACE_const_cast (GuidType_out&, p).ptr_)
{}

ACE_INLINE
::Kokyu::GuidType_out &
Kokyu::GuidType_out::operator= (const ::Kokyu::GuidType_out &p)
{
  this->ptr_ = ACE_const_cast (GuidType_out&, p).ptr_;
  return *this;
}

ACE_INLINE
::Kokyu::GuidType_out &
Kokyu::GuidType_out::operator= (GuidType *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
Kokyu::GuidType_out::operator ::Kokyu::GuidType *&() // cast
{
  return this->ptr_;
}

ACE_INLINE
::Kokyu::GuidType *&
Kokyu::GuidType_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE
::Kokyu::GuidType *
Kokyu::GuidType_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA::Octet &
Kokyu::GuidType_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_structure.cpp:194

// *************************************************************
// Inline operations for class Kokyu::Svc_Ctxt_DSRT_QoS_var
// *************************************************************

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var::Svc_Ctxt_DSRT_QoS_var (void)
  : ptr_ (0)
{}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var::Svc_Ctxt_DSRT_QoS_var (Svc_Ctxt_DSRT_QoS *p)
  : ptr_ (p)
{}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var::Svc_Ctxt_DSRT_QoS_var (const ::Kokyu::Svc_Ctxt_DSRT_QoS_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::Kokyu::Svc_Ctxt_DSRT_QoS (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var::~Svc_Ctxt_DSRT_QoS_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var &
Kokyu::Svc_Ctxt_DSRT_QoS_var::operator= (Svc_Ctxt_DSRT_QoS *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::Kokyu::Svc_Ctxt_DSRT_QoS_var &
Kokyu::Svc_Ctxt_DSRT_QoS_var::operator= (const ::Kokyu::Svc_Ctxt_DSRT_QoS_var &_tao_struct_var)
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
          Svc_Ctxt_DSRT_QoS *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              Svc_Ctxt_DSRT_QoS (*_tao_struct_var.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              Svc_Ctxt_DSRT_QoS *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

ACE_INLINE const ::Kokyu::Svc_Ctxt_DSRT_QoS *
Kokyu::Svc_Ctxt_DSRT_QoS_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::Kokyu::Svc_Ctxt_DSRT_QoS *
Kokyu::Svc_Ctxt_DSRT_QoS_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var::operator const ::Kokyu::Svc_Ctxt_DSRT_QoS &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var::operator ::Kokyu::Svc_Ctxt_DSRT_QoS &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var::operator ::Kokyu::Svc_Ctxt_DSRT_QoS &() const // cast 
{
  return *this->ptr_;
}

// Variable-size types only.
ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_var::operator ::Kokyu::Svc_Ctxt_DSRT_QoS *&() // cast 
{
  return this->ptr_;
}

ACE_INLINE const ::Kokyu::Svc_Ctxt_DSRT_QoS &
Kokyu::Svc_Ctxt_DSRT_QoS_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::Kokyu::Svc_Ctxt_DSRT_QoS &
Kokyu::Svc_Ctxt_DSRT_QoS_var::inout (void)
{
  return *this->ptr_;
}

// Mapping for variable size.
ACE_INLINE ::Kokyu::Svc_Ctxt_DSRT_QoS *&
Kokyu::Svc_Ctxt_DSRT_QoS_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE ::Kokyu::Svc_Ctxt_DSRT_QoS *
Kokyu::Svc_Ctxt_DSRT_QoS_var::_retn (void)
{
  ::Kokyu::Svc_Ctxt_DSRT_QoS *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE ::Kokyu::Svc_Ctxt_DSRT_QoS *
Kokyu::Svc_Ctxt_DSRT_QoS_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// be/be_structure.cpp:523

// *************************************************************
// Inline operations for class Kokyu::Svc_Ctxt_DSRT_QoS_out
// *************************************************************

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_out::Svc_Ctxt_DSRT_QoS_out (::Kokyu::Svc_Ctxt_DSRT_QoS *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_out::Svc_Ctxt_DSRT_QoS_out (Svc_Ctxt_DSRT_QoS_var &p)
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_out::Svc_Ctxt_DSRT_QoS_out (const ::Kokyu::Svc_Ctxt_DSRT_QoS_out &p)
  : ptr_ (ACE_const_cast (Svc_Ctxt_DSRT_QoS_out&, p).ptr_)
{}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_out &
Kokyu::Svc_Ctxt_DSRT_QoS_out::operator= (const ::Kokyu::Svc_Ctxt_DSRT_QoS_out &p)
{
  this->ptr_ = ACE_const_cast (Svc_Ctxt_DSRT_QoS_out&, p).ptr_;
  return *this;
}

ACE_INLINE
Kokyu::Svc_Ctxt_DSRT_QoS_out &
Kokyu::Svc_Ctxt_DSRT_QoS_out::operator= (Svc_Ctxt_DSRT_QoS *_tao_struct_out)
{
  this->ptr_ = _tao_struct_out;
  return *this;
}

ACE_INLINE 
Kokyu::Svc_Ctxt_DSRT_QoS_out::operator ::Kokyu::Svc_Ctxt_DSRT_QoS *&() // cast
{
  return this->ptr_;
}

ACE_INLINE ::Kokyu::Svc_Ctxt_DSRT_QoS *&
Kokyu::Svc_Ctxt_DSRT_QoS_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::Kokyu::Svc_Ctxt_DSRT_QoS *
Kokyu::Svc_Ctxt_DSRT_QoS_out::operator-> (void)
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ci.cpp:84

#if !defined _TAO_CDR_OP_Kokyu_GuidType_I_
#define _TAO_CDR_OP_Kokyu_GuidType_I_

CORBA::Boolean  operator<< (
    TAO_OutputCDR &,
    const Kokyu::GuidType &
  );

CORBA::Boolean  operator>> (
    TAO_InputCDR &,
    Kokyu::GuidType &
  );

#endif /* _TAO_CDR_OP_Kokyu_GuidType_I_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ci.cpp:71

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Kokyu::Svc_Ctxt_DSRT_QoS &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.guid) &&
    (strm << _tao_aggregate.importance) &&
    (strm << _tao_aggregate.criticality) &&
    (strm << _tao_aggregate.desired_priority) &&
    (strm << _tao_aggregate.deadline) &&
    (strm << _tao_aggregate.estimated_initial_execution_time)
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
    Kokyu::Svc_Ctxt_DSRT_QoS &_tao_aggregate
  )
{
  if (
    (strm >> _tao_aggregate.guid) &&
    (strm >> _tao_aggregate.importance) &&
    (strm >> _tao_aggregate.criticality) &&
    (strm >> _tao_aggregate.desired_priority) &&
    (strm >> _tao_aggregate.deadline) &&
    (strm >> _tao_aggregate.estimated_initial_execution_time)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

