// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

// *************************************************************
// Inline operations for class RtecScheduler::Dependency_Info_var
// *************************************************************

ACE_INLINE
RtecScheduler::Dependency_Info_var::Dependency_Info_var (void) // default constructor
	: ptr_ (0)
{}

ACE_INLINE
RtecScheduler::Dependency_Info_var::Dependency_Info_var (RtecScheduler::Dependency_Info *p)
	: ptr_ (p)
{}

ACE_INLINE
RtecScheduler::Dependency_Info_var::Dependency_Info_var (const RtecScheduler::Dependency_Info_var &p) // copy constructor
{
  if (p.ptr_)
  	this->ptr_ = new RtecScheduler::Dependency_Info(*p.ptr_);
  else
  	this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::Dependency_Info_var::~Dependency_Info_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE RtecScheduler::Dependency_Info_var &
RtecScheduler::Dependency_Info_var::operator= (RtecScheduler::Dependency_Info *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecScheduler::Dependency_Info_var &
RtecScheduler::Dependency_Info_var::operator= (const RtecScheduler::Dependency_Info_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new RtecScheduler::Dependency_Info (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const RtecScheduler::Dependency_Info *
RtecScheduler::Dependency_Info_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Dependency_Info *
RtecScheduler::Dependency_Info_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
RtecScheduler::Dependency_Info_var::operator const RtecScheduler::Dependency_Info &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
RtecScheduler::Dependency_Info_var::operator RtecScheduler::Dependency_Info &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
RtecScheduler::Dependency_Info_var::operator RtecScheduler::Dependency_Info &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE const RtecScheduler::Dependency_Info &
RtecScheduler::Dependency_Info_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE RtecScheduler::Dependency_Info &
RtecScheduler::Dependency_Info_var::inout (void)
{
  return *this->ptr_;
}

// mapping for fixed size 
ACE_INLINE RtecScheduler::Dependency_Info &
RtecScheduler::Dependency_Info_var::out (void)
{
  return *this->ptr_;
}

ACE_INLINE RtecScheduler::Dependency_Info
RtecScheduler::Dependency_Info_var::_retn (void)
{
  return *this->ptr_;
}

ACE_INLINE RtecScheduler::Dependency_Info *
RtecScheduler::Dependency_Info_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Dependency_Info *
RtecScheduler::_tao__seq_Dependency_Set::allocbuf (CORBA::ULong nelems)
{
  return new RtecScheduler::Dependency_Info[nelems]; // allocate from heap
}

ACE_INLINE void
RtecScheduler::_tao__seq_Dependency_Set::freebuf (RtecScheduler::Dependency_Info *seq)
{
  delete [] seq;
}

//default constructor
ACE_INLINE 
RtecScheduler::_tao__seq_Dependency_Set::_tao__seq_Dependency_Set (void)
	: maximum_ (0),
	  length_ (0),
	  buffer_ (0),
	  release_ (0) // does not own
{}

// constructor for unbounded seq
ACE_INLINE 
RtecScheduler::_tao__seq_Dependency_Set::_tao__seq_Dependency_Set(CORBA::ULong max )
	: maximum_ (max),
	  length_ (0),
	  buffer_ (RtecScheduler::_tao__seq_Dependency_Set::allocbuf (max)),
	  release_ (1) // owns
{}

// constructor from data buffer
ACE_INLINE 
RtecScheduler::_tao__seq_Dependency_Set::_tao__seq_Dependency_Set (CORBA::ULong max, CORBA::ULong length, 
	RtecScheduler::Dependency_Info *value, CORBA::Boolean release)
	: maximum_ (max),
	  length_ (length),
	  buffer_ (value),
	  release_ (release) // ownership depends on release
{}

ACE_INLINE CORBA::ULong
RtecScheduler::_tao__seq_Dependency_Set::maximum (void) const
{
  return this->maximum_;
}

ACE_INLINE CORBA::ULong
RtecScheduler::_tao__seq_Dependency_Set::length  (void) const
{
  return this->length_;
}

ACE_INLINE RtecScheduler::Dependency_Info &
RtecScheduler::_tao__seq_Dependency_Set::operator[] (CORBA::ULong index) // read/write
{
  return this->buffer_[index];
}

ACE_INLINE const RtecScheduler::Dependency_Info &
RtecScheduler::_tao__seq_Dependency_Set::operator[] (CORBA::ULong index) const // read
{
  return this->buffer_[index];
}

// *************************************************************
// Inline operations for class RtecScheduler::_tao__seq_Dependency_Set_var
// *************************************************************

ACE_INLINE
RtecScheduler::_tao__seq_Dependency_Set_var::_tao__seq_Dependency_Set_var (void) // default constructor
	: ptr_ (0)
{}

ACE_INLINE
RtecScheduler::_tao__seq_Dependency_Set_var::_tao__seq_Dependency_Set_var (RtecScheduler::_tao__seq_Dependency_Set_ptr p)
	: ptr_ (p)
{}

ACE_INLINE
RtecScheduler::_tao__seq_Dependency_Set_var::_tao__seq_Dependency_Set_var (const RtecScheduler::_tao__seq_Dependency_Set_var &p) // copy constructor
{
  if (p.ptr_)
  	this->ptr_ = new RtecScheduler::_tao__seq_Dependency_Set(*p.ptr_);
  else
  	this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::_tao__seq_Dependency_Set_var::~_tao__seq_Dependency_Set_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set_var &
RtecScheduler::_tao__seq_Dependency_Set_var::operator= (RtecScheduler::_tao__seq_Dependency_Set *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set_var &
RtecScheduler::_tao__seq_Dependency_Set_var::operator= (const RtecScheduler::_tao__seq_Dependency_Set_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new RtecScheduler::_tao__seq_Dependency_Set (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const RtecScheduler::_tao__seq_Dependency_Set *
RtecScheduler::_tao__seq_Dependency_Set_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set *
RtecScheduler::_tao__seq_Dependency_Set_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
RtecScheduler::_tao__seq_Dependency_Set_var::operator const RtecScheduler::_tao__seq_Dependency_Set &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
RtecScheduler::_tao__seq_Dependency_Set_var::operator RtecScheduler::_tao__seq_Dependency_Set &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
RtecScheduler::_tao__seq_Dependency_Set_var::operator RtecScheduler::_tao__seq_Dependency_Set &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE RtecScheduler::Dependency_Info&
RtecScheduler::_tao__seq_Dependency_Set_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const RtecScheduler::_tao__seq_Dependency_Set &
RtecScheduler::_tao__seq_Dependency_Set_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set &
RtecScheduler::_tao__seq_Dependency_Set_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set *&
RtecScheduler::_tao__seq_Dependency_Set_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set *
RtecScheduler::_tao__seq_Dependency_Set_var::_retn (void)
{
  RtecScheduler::_tao__seq_Dependency_Set *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set *
RtecScheduler::_tao__seq_Dependency_Set_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class RtecScheduler::_tao__seq_Dependency_Set_out
// *************************************************************

ACE_INLINE
RtecScheduler::_tao__seq_Dependency_Set_out::_tao__seq_Dependency_Set_out (RtecScheduler::_tao__seq_Dependency_Set *&p)
	: ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::_tao__seq_Dependency_Set_out::_tao__seq_Dependency_Set_out (RtecScheduler::_tao__seq_Dependency_Set_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::_tao__seq_Dependency_Set_out::_tao__seq_Dependency_Set_out (RtecScheduler::_tao__seq_Dependency_Set_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set_out &
RtecScheduler::_tao__seq_Dependency_Set_out::operator= (RtecScheduler::_tao__seq_Dependency_Set_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set_out &
RtecScheduler::_tao__seq_Dependency_Set_out::operator= (RtecScheduler::_tao__seq_Dependency_Set *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecScheduler::_tao__seq_Dependency_Set_out::operator RtecScheduler::_tao__seq_Dependency_Set *&() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set *&
RtecScheduler::_tao__seq_Dependency_Set_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_Dependency_Set *
RtecScheduler::_tao__seq_Dependency_Set_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Dependency_Info& 
RtecScheduler::_tao__seq_Dependency_Set_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

// *************************************************************
// Inline operations for class RtecScheduler::RT_Info_var
// *************************************************************

ACE_INLINE
RtecScheduler::RT_Info_var::RT_Info_var (void) // default constructor
	: ptr_ (0)
{}

ACE_INLINE
RtecScheduler::RT_Info_var::RT_Info_var (RtecScheduler::RT_Info *p)
	: ptr_ (p)
{}

ACE_INLINE
RtecScheduler::RT_Info_var::RT_Info_var (const RtecScheduler::RT_Info_var &p) // copy constructor
{
  if (p.ptr_)
  	this->ptr_ = new RtecScheduler::RT_Info(*p.ptr_);
  else
  	this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::RT_Info_var::~RT_Info_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE RtecScheduler::RT_Info_var &
RtecScheduler::RT_Info_var::operator= (RtecScheduler::RT_Info *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecScheduler::RT_Info_var &
RtecScheduler::RT_Info_var::operator= (const RtecScheduler::RT_Info_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new RtecScheduler::RT_Info (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const RtecScheduler::RT_Info *
RtecScheduler::RT_Info_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::RT_Info *
RtecScheduler::RT_Info_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
RtecScheduler::RT_Info_var::operator const RtecScheduler::RT_Info &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
RtecScheduler::RT_Info_var::operator RtecScheduler::RT_Info &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
RtecScheduler::RT_Info_var::operator RtecScheduler::RT_Info &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE const RtecScheduler::RT_Info &
RtecScheduler::RT_Info_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE RtecScheduler::RT_Info &
RtecScheduler::RT_Info_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE RtecScheduler::RT_Info *&
RtecScheduler::RT_Info_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE RtecScheduler::RT_Info *
RtecScheduler::RT_Info_var::_retn (void)
{
  RtecScheduler::RT_Info *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

// *************************************************************
// Inline operations for class RtecScheduler::RT_Info_out
// *************************************************************

ACE_INLINE
RtecScheduler::RT_Info_out::RT_Info_out (RtecScheduler::RT_Info *&p)
	: ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::RT_Info_out::RT_Info_out (RtecScheduler::RT_Info_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::RT_Info_out::RT_Info_out (const RtecScheduler::RT_Info_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecScheduler::RT_Info_out &
RtecScheduler::RT_Info_out::operator= (const RtecScheduler::RT_Info_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecScheduler::RT_Info_out &
RtecScheduler::RT_Info_out::operator= (RtecScheduler::RT_Info *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecScheduler::RT_Info_out::operator RtecScheduler::RT_Info *&() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::RT_Info *&
RtecScheduler::RT_Info_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::RT_Info *
RtecScheduler::RT_Info_out::operator-> (void)
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for exception RtecScheduler::DUPLICATE_NAME
// *************************************************************

// default constructor
ACE_INLINE
RtecScheduler::DUPLICATE_NAME::DUPLICATE_NAME (void)
  : CORBA_UserException (_tc_DUPLICATE_NAME)
{
}

// *************************************************************
// Inline operations for exception RtecScheduler::UNKNOWN_TASK
// *************************************************************

// default constructor
ACE_INLINE
RtecScheduler::UNKNOWN_TASK::UNKNOWN_TASK (void)
  : CORBA_UserException (_tc_UNKNOWN_TASK)
{
}

// *************************************************************
// Inline operations for exception RtecScheduler::NOT_SCHEDULED
// *************************************************************

// default constructor
ACE_INLINE
RtecScheduler::NOT_SCHEDULED::NOT_SCHEDULED (void)
  : CORBA_UserException (_tc_NOT_SCHEDULED)
{
}

// *************************************************************
// Inline operations for exception RtecScheduler::UTILIZATION_BOUND_EXCEEDED
// *************************************************************

// default constructor
ACE_INLINE
RtecScheduler::UTILIZATION_BOUND_EXCEEDED::UTILIZATION_BOUND_EXCEEDED (void)
  : CORBA_UserException (_tc_UTILIZATION_BOUND_EXCEEDED)
{
}

// *************************************************************
// Inline operations for exception RtecScheduler::INSUFFICIENT_THREAD_PRIORITY_LEVELS
// *************************************************************

// default constructor
ACE_INLINE
RtecScheduler::INSUFFICIENT_THREAD_PRIORITY_LEVELS::INSUFFICIENT_THREAD_PRIORITY_LEVELS (void)
  : CORBA_UserException (_tc_INSUFFICIENT_THREAD_PRIORITY_LEVELS)
{
}

// *************************************************************
// Inline operations for exception RtecScheduler::TASK_COUNT_MISMATCH
// *************************************************************

// default constructor
ACE_INLINE
RtecScheduler::TASK_COUNT_MISMATCH::TASK_COUNT_MISMATCH (void)
  : CORBA_UserException (_tc_TASK_COUNT_MISMATCH)
{
}

ACE_INLINE RtecScheduler::RT_Info *
RtecScheduler::_tao__seq_RT_Info_Set::allocbuf (CORBA::ULong nelems)
{
  return new RtecScheduler::RT_Info[nelems]; // allocate from heap
}

ACE_INLINE void
RtecScheduler::_tao__seq_RT_Info_Set::freebuf (RtecScheduler::RT_Info *seq)
{
  delete [] seq;
}

//default constructor
ACE_INLINE 
RtecScheduler::_tao__seq_RT_Info_Set::_tao__seq_RT_Info_Set (void)
	: maximum_ (0),
	  length_ (0),
	  buffer_ (0),
	  release_ (0) // does not own
{}

// constructor for unbounded seq
ACE_INLINE 
RtecScheduler::_tao__seq_RT_Info_Set::_tao__seq_RT_Info_Set(CORBA::ULong max )
	: maximum_ (max),
	  length_ (0),
	  buffer_ (RtecScheduler::_tao__seq_RT_Info_Set::allocbuf (max)),
	  release_ (1) // owns
{}

// constructor from data buffer
ACE_INLINE 
RtecScheduler::_tao__seq_RT_Info_Set::_tao__seq_RT_Info_Set (CORBA::ULong max, CORBA::ULong length, 
	RtecScheduler::RT_Info *value, CORBA::Boolean release)
	: maximum_ (max),
	  length_ (length),
	  buffer_ (value),
	  release_ (release) // ownership depends on release
{}

ACE_INLINE CORBA::ULong
RtecScheduler::_tao__seq_RT_Info_Set::maximum (void) const
{
  return this->maximum_;
}

ACE_INLINE CORBA::ULong
RtecScheduler::_tao__seq_RT_Info_Set::length  (void) const
{
  return this->length_;
}

ACE_INLINE RtecScheduler::RT_Info &
RtecScheduler::_tao__seq_RT_Info_Set::operator[] (CORBA::ULong index) // read/write
{
  return this->buffer_[index];
}

ACE_INLINE const RtecScheduler::RT_Info &
RtecScheduler::_tao__seq_RT_Info_Set::operator[] (CORBA::ULong index) const // read
{
  return this->buffer_[index];
}

// *************************************************************
// Inline operations for class RtecScheduler::_tao__seq_RT_Info_Set_var
// *************************************************************

ACE_INLINE
RtecScheduler::_tao__seq_RT_Info_Set_var::_tao__seq_RT_Info_Set_var (void) // default constructor
	: ptr_ (0)
{}

ACE_INLINE
RtecScheduler::_tao__seq_RT_Info_Set_var::_tao__seq_RT_Info_Set_var (RtecScheduler::_tao__seq_RT_Info_Set_ptr p)
	: ptr_ (p)
{}

ACE_INLINE
RtecScheduler::_tao__seq_RT_Info_Set_var::_tao__seq_RT_Info_Set_var (const RtecScheduler::_tao__seq_RT_Info_Set_var &p) // copy constructor
{
  if (p.ptr_)
  	this->ptr_ = new RtecScheduler::_tao__seq_RT_Info_Set(*p.ptr_);
  else
  	this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::_tao__seq_RT_Info_Set_var::~_tao__seq_RT_Info_Set_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set_var &
RtecScheduler::_tao__seq_RT_Info_Set_var::operator= (RtecScheduler::_tao__seq_RT_Info_Set *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set_var &
RtecScheduler::_tao__seq_RT_Info_Set_var::operator= (const RtecScheduler::_tao__seq_RT_Info_Set_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new RtecScheduler::_tao__seq_RT_Info_Set (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const RtecScheduler::_tao__seq_RT_Info_Set *
RtecScheduler::_tao__seq_RT_Info_Set_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set *
RtecScheduler::_tao__seq_RT_Info_Set_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
RtecScheduler::_tao__seq_RT_Info_Set_var::operator const RtecScheduler::_tao__seq_RT_Info_Set &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
RtecScheduler::_tao__seq_RT_Info_Set_var::operator RtecScheduler::_tao__seq_RT_Info_Set &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
RtecScheduler::_tao__seq_RT_Info_Set_var::operator RtecScheduler::_tao__seq_RT_Info_Set &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE RtecScheduler::RT_Info&
RtecScheduler::_tao__seq_RT_Info_Set_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const RtecScheduler::_tao__seq_RT_Info_Set &
RtecScheduler::_tao__seq_RT_Info_Set_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set &
RtecScheduler::_tao__seq_RT_Info_Set_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set *&
RtecScheduler::_tao__seq_RT_Info_Set_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set *
RtecScheduler::_tao__seq_RT_Info_Set_var::_retn (void)
{
  RtecScheduler::_tao__seq_RT_Info_Set *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set *
RtecScheduler::_tao__seq_RT_Info_Set_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class RtecScheduler::_tao__seq_RT_Info_Set_out
// *************************************************************

ACE_INLINE
RtecScheduler::_tao__seq_RT_Info_Set_out::_tao__seq_RT_Info_Set_out (RtecScheduler::_tao__seq_RT_Info_Set *&p)
	: ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::_tao__seq_RT_Info_Set_out::_tao__seq_RT_Info_Set_out (RtecScheduler::_tao__seq_RT_Info_Set_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
RtecScheduler::_tao__seq_RT_Info_Set_out::_tao__seq_RT_Info_Set_out (const RtecScheduler::_tao__seq_RT_Info_Set_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set_out &
RtecScheduler::_tao__seq_RT_Info_Set_out::operator= (const RtecScheduler::_tao__seq_RT_Info_Set_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set_out &
RtecScheduler::_tao__seq_RT_Info_Set_out::operator= (RtecScheduler::_tao__seq_RT_Info_Set *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecScheduler::_tao__seq_RT_Info_Set_out::operator RtecScheduler::_tao__seq_RT_Info_Set *&() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set *&
RtecScheduler::_tao__seq_RT_Info_Set_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::_tao__seq_RT_Info_Set *
RtecScheduler::_tao__seq_RT_Info_Set_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::RT_Info& 
RtecScheduler::_tao__seq_RT_Info_Set_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
RtecScheduler::Scheduler::Scheduler (void) // default constructor
{}

ACE_INLINE
RtecScheduler::Scheduler::Scheduler (STUB_Object *objref) // constructor
	: ACE_CORBA_1 (Object) (objref)
{}

ACE_INLINE
RtecScheduler::Scheduler::~Scheduler (void) // destructor
{}


#if !defined (_RTECSCHEDULER_SCHEDULER___VAR_CI_)
#define _RTECSCHEDULER_SCHEDULER___VAR_CI_

// *************************************************************
// Inline operations for class RtecScheduler::Scheduler_var
// *************************************************************

ACE_INLINE
RtecScheduler::Scheduler_var::Scheduler_var (void) // default constructor
	: ptr_ (RtecScheduler::Scheduler::_nil ())
{}

ACE_INLINE
RtecScheduler::Scheduler_var::Scheduler_var (RtecScheduler::Scheduler_ptr p)
	: ptr_ (p)
{}

ACE_INLINE RtecScheduler::Scheduler_ptr 
RtecScheduler::Scheduler_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
RtecScheduler::Scheduler_var::Scheduler_var (const RtecScheduler::Scheduler_var &p) // copy constructor
	: ptr_ (RtecScheduler::Scheduler::_duplicate (p.ptr ()))
{}

ACE_INLINE
RtecScheduler::Scheduler_var::~Scheduler_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE RtecScheduler::Scheduler_var &
RtecScheduler::Scheduler_var::operator= (RtecScheduler::Scheduler_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE RtecScheduler::Scheduler_var &
RtecScheduler::Scheduler_var::operator= (const RtecScheduler::Scheduler_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = RtecScheduler::Scheduler::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
RtecScheduler::Scheduler_var::operator const RtecScheduler::Scheduler_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
RtecScheduler::Scheduler_var::operator RtecScheduler::Scheduler_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Scheduler_ptr 
RtecScheduler::Scheduler_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Scheduler_ptr
RtecScheduler::Scheduler_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Scheduler_ptr &
RtecScheduler::Scheduler_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Scheduler_ptr &
RtecScheduler::Scheduler_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecScheduler::Scheduler::_nil ();
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Scheduler_ptr 
RtecScheduler::Scheduler_var::_retn (void)
{
  // yield ownership of managed obj reference
  RtecScheduler::Scheduler_ptr val = this->ptr_;
  this->ptr_ = RtecScheduler::Scheduler::_nil ();
  return val;
}


#endif // end #if !defined


#if !defined (_RTECSCHEDULER_SCHEDULER___OUT_CI_)
#define _RTECSCHEDULER_SCHEDULER___OUT_CI_

// *************************************************************
// Inline operations for class RtecScheduler::Scheduler_out
// *************************************************************

ACE_INLINE
RtecScheduler::Scheduler_out::Scheduler_out (RtecScheduler::Scheduler_ptr &p)
	: ptr_ (p)
{
  this->ptr_ = RtecScheduler::Scheduler::_nil ();
}

ACE_INLINE
RtecScheduler::Scheduler_out::Scheduler_out (RtecScheduler::Scheduler_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = RtecScheduler::Scheduler::_nil ();
}

ACE_INLINE
RtecScheduler::Scheduler_out::Scheduler_out (RtecScheduler::Scheduler_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE RtecScheduler::Scheduler_out &
RtecScheduler::Scheduler_out::operator= (RtecScheduler::Scheduler_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE RtecScheduler::Scheduler_out &
RtecScheduler::Scheduler_out::operator= (const RtecScheduler::Scheduler_var &p)
{
  this->ptr_ = RtecScheduler::Scheduler::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE RtecScheduler::Scheduler_out &
RtecScheduler::Scheduler_out::operator= (RtecScheduler::Scheduler_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
RtecScheduler::Scheduler_out::operator RtecScheduler::Scheduler_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Scheduler_ptr &
RtecScheduler::Scheduler_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE RtecScheduler::Scheduler_ptr 
RtecScheduler::Scheduler_out::operator-> (void)
{
  return this->ptr_;
}


#endif // end #if !defined

