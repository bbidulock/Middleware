/* -*- C++ -*- $Id$ */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

// *************************************************************
// Inline operations for class TAO::PrioritySpecification_var
// *************************************************************

#if (TAO_HAS_CLIENT_PRIORITY_POLICY == 1)

ACE_INLINE
TAO::PrioritySpecification_var::PrioritySpecification_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
TAO::PrioritySpecification_var::PrioritySpecification_var (PrioritySpecification *p)
  : ptr_ (p)
{}

ACE_INLINE
TAO::PrioritySpecification_var::PrioritySpecification_var (const ::TAO::PrioritySpecification_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::TAO::PrioritySpecification (*p.ptr_));
  else
    this->ptr_ = 0;
}

// fixed-size types only
ACE_INLINE
TAO::PrioritySpecification_var::PrioritySpecification_var (const ::TAO::PrioritySpecification &p)
{
  ACE_NEW (this->ptr_, ::TAO::PrioritySpecification (p));
}

ACE_INLINE
TAO::PrioritySpecification_var::~PrioritySpecification_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE TAO::PrioritySpecification_var &
TAO::PrioritySpecification_var::operator= (PrioritySpecification *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE ::TAO::PrioritySpecification_var &
TAO::PrioritySpecification_var::operator= (const ::TAO::PrioritySpecification_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, ::TAO::PrioritySpecification (*p.ptr_), *this);
  }
  return *this;
}

// fixed-size types only
ACE_INLINE TAO::PrioritySpecification_var &
TAO::PrioritySpecification_var::operator= (const ::TAO::PrioritySpecification &p)
{
  if (this->ptr_ != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, ::TAO::PrioritySpecification (p), *this);
  }
  return *this;
}

ACE_INLINE const ::TAO::PrioritySpecification *
TAO::PrioritySpecification_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO::PrioritySpecification *
TAO::PrioritySpecification_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
TAO::PrioritySpecification_var::operator const ::TAO::PrioritySpecification &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO::PrioritySpecification_var::operator ::TAO::PrioritySpecification &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
TAO::PrioritySpecification_var::operator ::TAO::PrioritySpecification &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE const ::TAO::PrioritySpecification &
TAO::PrioritySpecification_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE ::TAO::PrioritySpecification &
TAO::PrioritySpecification_var::inout (void)
{
  return *this->ptr_;
}

// mapping for fixed size
ACE_INLINE ::TAO::PrioritySpecification &
TAO::PrioritySpecification_var::out (void)
{
  return *this->ptr_;
}

ACE_INLINE ::TAO::PrioritySpecification
TAO::PrioritySpecification_var::_retn (void)
{
  return *this->ptr_;
}

ACE_INLINE ::TAO::PrioritySpecification *
TAO::PrioritySpecification_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
TAO::ClientPriorityPolicy::ClientPriorityPolicy (void) // default constructor
{}

ACE_INLINE
TAO::ClientPriorityPolicy::~ClientPriorityPolicy (void) // destructor
{}


#if !defined (_TAO_CLIENTPRIORITYPOLICY___VAR_CI_)
#define _TAO_CLIENTPRIORITYPOLICY___VAR_CI_

// *************************************************************
// Inline operations for class TAO::ClientPriorityPolicy_var
// *************************************************************

ACE_INLINE
TAO::ClientPriorityPolicy_var::ClientPriorityPolicy_var (void) // default constructor
  : ptr_ (ClientPriorityPolicy::_nil ())
{}

ACE_INLINE
TAO::ClientPriorityPolicy_var::ClientPriorityPolicy_var (ClientPriorityPolicy_ptr p)
  : ptr_ (p)
{}

ACE_INLINE ::TAO::ClientPriorityPolicy_ptr
TAO::ClientPriorityPolicy_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
TAO::ClientPriorityPolicy_var::ClientPriorityPolicy_var (const ::TAO::ClientPriorityPolicy_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (ClientPriorityPolicy::_duplicate (p.ptr ()))
{}

ACE_INLINE
TAO::ClientPriorityPolicy_var::~ClientPriorityPolicy_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE TAO::ClientPriorityPolicy_var &
TAO::ClientPriorityPolicy_var::operator= (ClientPriorityPolicy_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE TAO::ClientPriorityPolicy_var &
TAO::ClientPriorityPolicy_var::operator= (const ::TAO::ClientPriorityPolicy_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::TAO::ClientPriorityPolicy::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
TAO::ClientPriorityPolicy_var::operator const ::TAO::ClientPriorityPolicy_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
TAO::ClientPriorityPolicy_var::operator ::TAO::ClientPriorityPolicy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE ::TAO::ClientPriorityPolicy_ptr
TAO::ClientPriorityPolicy_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO::ClientPriorityPolicy_ptr
TAO::ClientPriorityPolicy_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO::ClientPriorityPolicy_ptr &
TAO::ClientPriorityPolicy_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE ::TAO::ClientPriorityPolicy_ptr &
TAO::ClientPriorityPolicy_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO::ClientPriorityPolicy::_nil ();
  return this->ptr_;
}

ACE_INLINE ::TAO::ClientPriorityPolicy_ptr
TAO::ClientPriorityPolicy_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::TAO::ClientPriorityPolicy_ptr val = this->ptr_;
  this->ptr_ = ::TAO::ClientPriorityPolicy::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_TAO_CLIENTPRIORITYPOLICY___OUT_CI_)
#define _TAO_CLIENTPRIORITYPOLICY___OUT_CI_

// *************************************************************
// Inline operations for class TAO::ClientPriorityPolicy_out
// *************************************************************

ACE_INLINE
TAO::ClientPriorityPolicy_out::ClientPriorityPolicy_out (ClientPriorityPolicy_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::TAO::ClientPriorityPolicy::_nil ();
}

ACE_INLINE
TAO::ClientPriorityPolicy_out::ClientPriorityPolicy_out (ClientPriorityPolicy_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO::ClientPriorityPolicy::_nil ();
}

ACE_INLINE
TAO::ClientPriorityPolicy_out::ClientPriorityPolicy_out (const ::TAO::ClientPriorityPolicy_out &p) // copy constructor
  : ptr_ (ACE_const_cast (ClientPriorityPolicy_out &, p).ptr_)
{}

ACE_INLINE ::TAO::ClientPriorityPolicy_out &
TAO::ClientPriorityPolicy_out::operator= (const ::TAO::ClientPriorityPolicy_out &p)
{
  this->ptr_ = ACE_const_cast (ClientPriorityPolicy_out&, p).ptr_;
  return *this;
}

ACE_INLINE TAO::ClientPriorityPolicy_out &
TAO::ClientPriorityPolicy_out::operator= (const ::TAO::ClientPriorityPolicy_var &p)
{
  this->ptr_ = ::TAO::ClientPriorityPolicy::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE TAO::ClientPriorityPolicy_out &
TAO::ClientPriorityPolicy_out::operator= (ClientPriorityPolicy_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
TAO::ClientPriorityPolicy_out::operator ::TAO::ClientPriorityPolicy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE ::TAO::ClientPriorityPolicy_ptr &
TAO::ClientPriorityPolicy_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::TAO::ClientPriorityPolicy_ptr
TAO::ClientPriorityPolicy_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO::PrioritySpecification &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.mode) &&
    (strm << _tao_aggregate.min_priority) &&
    (strm << _tao_aggregate.max_priority)
  )
    return 1;
  else
    return 0;

}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, TAO::PrioritySpecification &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.mode) &&
    (strm >> _tao_aggregate.min_priority) &&
    (strm >> _tao_aggregate.max_priority)
  )
    return 1;
  else
    return 0;

}
#endif /* TAO_HAS_CLIENT_PRIORITY_POLICY == 1 */

#if (TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1)

// *************************************************************
// Inline operations for class TAO::BufferingConstraint_var
// *************************************************************

ACE_INLINE
TAO::BufferingConstraint_var::BufferingConstraint_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
TAO::BufferingConstraint_var::BufferingConstraint_var (BufferingConstraint *p)
  : ptr_ (p)
{}

ACE_INLINE
TAO::BufferingConstraint_var::BufferingConstraint_var (const ::TAO::BufferingConstraint_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, ::TAO::BufferingConstraint (*p.ptr_));
  else
    this->ptr_ = 0;
}

// fixed-size types only
ACE_INLINE
TAO::BufferingConstraint_var::BufferingConstraint_var (const ::TAO::BufferingConstraint &p)
{
  ACE_NEW (this->ptr_, ::TAO::BufferingConstraint (p));
}

ACE_INLINE
TAO::BufferingConstraint_var::~BufferingConstraint_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE TAO::BufferingConstraint_var &
TAO::BufferingConstraint_var::operator= (BufferingConstraint *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE ::TAO::BufferingConstraint_var &
TAO::BufferingConstraint_var::operator= (const ::TAO::BufferingConstraint_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, ::TAO::BufferingConstraint (*p.ptr_), *this);
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
    ACE_NEW_RETURN (this->ptr_, ::TAO::BufferingConstraint (p), *this);
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

ACE_INLINE
TAO::BufferingConstraintPolicy::BufferingConstraintPolicy (void) // default constructor
{}

ACE_INLINE
TAO::BufferingConstraintPolicy::~BufferingConstraintPolicy (void) // destructor
{}


#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___VAR_CI_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___VAR_CI_

// *************************************************************
// Inline operations for class TAO::BufferingConstraintPolicy_var
// *************************************************************

ACE_INLINE
TAO::BufferingConstraintPolicy_var::BufferingConstraintPolicy_var (void) // default constructor
  : ptr_ (BufferingConstraintPolicy::_nil ())
{}

ACE_INLINE
TAO::BufferingConstraintPolicy_var::BufferingConstraintPolicy_var (BufferingConstraintPolicy_ptr p)
  : ptr_ (p)
{}

ACE_INLINE ::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
TAO::BufferingConstraintPolicy_var::BufferingConstraintPolicy_var (const ::TAO::BufferingConstraintPolicy_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (BufferingConstraintPolicy::_duplicate (p.ptr ()))
{}

ACE_INLINE
TAO::BufferingConstraintPolicy_var::~BufferingConstraintPolicy_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE TAO::BufferingConstraintPolicy_var &
TAO::BufferingConstraintPolicy_var::operator= (BufferingConstraintPolicy_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE TAO::BufferingConstraintPolicy_var &
TAO::BufferingConstraintPolicy_var::operator= (const ::TAO::BufferingConstraintPolicy_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = ::TAO::BufferingConstraintPolicy::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
TAO::BufferingConstraintPolicy_var::operator const ::TAO::BufferingConstraintPolicy_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
TAO::BufferingConstraintPolicy_var::operator ::TAO::BufferingConstraintPolicy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraintPolicy_ptr &
TAO::BufferingConstraintPolicy_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraintPolicy_ptr &
TAO::BufferingConstraintPolicy_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_nil ();
  return this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_var::_retn (void)
{
  // yield ownership of managed obj reference
  ::TAO::BufferingConstraintPolicy_ptr val = this->ptr_;
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_TAO_BUFFERINGCONSTRAINTPOLICY___OUT_CI_)
#define _TAO_BUFFERINGCONSTRAINTPOLICY___OUT_CI_

// *************************************************************
// Inline operations for class TAO::BufferingConstraintPolicy_out
// *************************************************************

ACE_INLINE
TAO::BufferingConstraintPolicy_out::BufferingConstraintPolicy_out (BufferingConstraintPolicy_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_nil ();
}

ACE_INLINE
TAO::BufferingConstraintPolicy_out::BufferingConstraintPolicy_out (BufferingConstraintPolicy_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_nil ();
}

ACE_INLINE
TAO::BufferingConstraintPolicy_out::BufferingConstraintPolicy_out (const ::TAO::BufferingConstraintPolicy_out &p) // copy constructor
  : ptr_ (ACE_const_cast (BufferingConstraintPolicy_out &, p).ptr_)
{}

ACE_INLINE ::TAO::BufferingConstraintPolicy_out &
TAO::BufferingConstraintPolicy_out::operator= (const ::TAO::BufferingConstraintPolicy_out &p)
{
  this->ptr_ = ACE_const_cast (BufferingConstraintPolicy_out&, p).ptr_;
  return *this;
}

ACE_INLINE TAO::BufferingConstraintPolicy_out &
TAO::BufferingConstraintPolicy_out::operator= (const ::TAO::BufferingConstraintPolicy_var &p)
{
  this->ptr_ = ::TAO::BufferingConstraintPolicy::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE TAO::BufferingConstraintPolicy_out &
TAO::BufferingConstraintPolicy_out::operator= (BufferingConstraintPolicy_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
TAO::BufferingConstraintPolicy_out::operator ::TAO::BufferingConstraintPolicy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraintPolicy_ptr &
TAO::BufferingConstraintPolicy_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE ::TAO::BufferingConstraintPolicy_ptr
TAO::BufferingConstraintPolicy_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const TAO::BufferingConstraint &_tao_aggregate)
{
  if (
    (strm << _tao_aggregate.mode) &&
    (strm << _tao_aggregate.timeout) &&
    (strm << _tao_aggregate.message_count) &&
    (strm << _tao_aggregate.message_bytes)
  )
    return 1;
  else
    return 0;

}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, TAO::BufferingConstraint &_tao_aggregate)
{
  if (
    (strm >> _tao_aggregate.mode) &&
    (strm >> _tao_aggregate.timeout) &&
    (strm >> _tao_aggregate.message_count) &&
    (strm >> _tao_aggregate.message_bytes)
  )
    return 1;
  else
    return 0;

}

#endif /* TAO_HAS_BUFFERING_CONSTRAINT_POLICY == 1 */
