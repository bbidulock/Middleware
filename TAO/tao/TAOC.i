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
// Inline operations for class TAO::BufferingConstraint_var
// *************************************************************

ACE_INLINE
TAO::BufferingConstraint_var::BufferingConstraint_var (void)
  : ptr_ (0)
{}

ACE_INLINE
TAO::BufferingConstraint_var::BufferingConstraint_var (BufferingConstraint *p)
  : ptr_ (p)
{}

ACE_INLINE
TAO::BufferingConstraint_var::BufferingConstraint_var (const ::TAO::BufferingConstraint_var &p)
{
  if (p.ptr_)
    {
      ACE_NEW (this->ptr_, ::TAO::BufferingConstraint (*p.ptr_));
    }
  else
    {
      this->ptr_ = 0;
    }
}

// Fixed-size types only.
ACE_INLINE
TAO::BufferingConstraint_var::BufferingConstraint_var (const ::TAO::BufferingConstraint &p)
{
  ACE_NEW (this->ptr_, ::TAO::BufferingConstraint (p));
}

ACE_INLINE
TAO::BufferingConstraint_var::~BufferingConstraint_var (void)
{
  delete this->ptr_;
}

ACE_INLINE
TAO::BufferingConstraint_var &
TAO::BufferingConstraint_var::operator= (BufferingConstraint *_tao_struct_var)
{
  delete this->ptr_;
  this->ptr_ = _tao_struct_var;
  return *this;
}

ACE_INLINE
::TAO::BufferingConstraint_var &
TAO::BufferingConstraint_var::operator= (const ::TAO::BufferingConstraint_var &_tao_struct_var)
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
          BufferingConstraint *deep_copy = 0;
          ACE_NEW_RETURN (
              deep_copy,
              BufferingConstraint (*_tao_struct_var.ptr_),
              *this
            );
          
          if (deep_copy != 0)
            {
              BufferingConstraint *tmp = deep_copy;
              deep_copy = this->ptr_;
              this->ptr_ = tmp;
              delete deep_copy;
            }
        }
    }
  
  return *this;
}

// fixed-size types only
ACE_INLINE TAO::BufferingConstraint_var &
TAO::BufferingConstraint_var::operator= (const ::TAO::BufferingConstraint &p)
{
  if (this->ptr_ != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (
        this->ptr_,
        ::TAO::BufferingConstraint (p),
        *this
      );
  }
  
  return *this;
}

ACE_INLINE const ::TAO::BufferingConstraint *
TAO::BufferingConstraint_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraint *
TAO::BufferingConstraint_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
TAO::BufferingConstraint_var::operator const ::TAO::BufferingConstraint &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO::BufferingConstraint_var::operator ::TAO::BufferingConstraint &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE
TAO::BufferingConstraint_var::operator ::TAO::BufferingConstraint &() const // cast 
{
  return *this->ptr_;
}

ACE_INLINE const ::TAO::BufferingConstraint &
TAO::BufferingConstraint_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraint &
TAO::BufferingConstraint_var::inout (void)
{
  return *this->ptr_;
}

// mapping for fixed size 
ACE_INLINE ::TAO::BufferingConstraint &
TAO::BufferingConstraint_var::out (void)
{
  return *this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraint
TAO::BufferingConstraint_var::_retn (void)
{
  return *this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraint *
TAO::BufferingConstraint_var::ptr (void) const
{
  return this->ptr_;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:68

#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___CI_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___CI_

ACE_INLINE
CORBA::Boolean
TAO::BufferingConstraintPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:103

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO::BufferingConstraint &_tao_aggregate
  )
{
  if (
    (strm << _tao_aggregate.mode) &&
    (strm << _tao_aggregate.timeout) &&
    (strm << _tao_aggregate.message_count) &&
    (strm << _tao_aggregate.message_bytes)
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
    TAO::BufferingConstraint &_tao_aggregate
  )
{
  if (
    (strm >> _tao_aggregate.mode) &&
    (strm >> _tao_aggregate.timeout) &&
    (strm >> _tao_aggregate.message_count) &&
    (strm >> _tao_aggregate.message_bytes)
   )
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

