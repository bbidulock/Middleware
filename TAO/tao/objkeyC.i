// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html


#if !defined (_TAO__TAO_SEQ_OCTET_CI_)
#define _TAO__TAO_SEQ_OCTET_CI_

ACE_INLINE void
TAO::_tao_seq_Octet::freebuf (CORBA::Octet *seq)
{
  delete []seq;
}

//default constructor
ACE_INLINE 
TAO::_tao_seq_Octet::_tao_seq_Octet (void)
	: maximum_ (0),
	  length_ (0),
	  buffer_ (0),
	  release_ (0) // does not own
{}

ACE_INLINE CORBA::ULong
TAO::_tao_seq_Octet::maximum (void) const
{
  return this->maximum_;
}

ACE_INLINE CORBA::ULong
TAO::_tao_seq_Octet::length  (void) const
{
  return this->length_;
}

ACE_INLINE CORBA::Octet &
TAO::_tao_seq_Octet::operator[] (CORBA::ULong index) // read/write
{
  return this->buffer_[index];
}

ACE_INLINE const CORBA::Octet &
TAO::_tao_seq_Octet::operator[] (CORBA::ULong index) const // read
{
  return this->buffer_[index];
}


#endif // end #if !defined


#if !defined (_TAO__TAO_SEQ_OCTET___VAR_CI_)
#define _TAO__TAO_SEQ_OCTET___VAR_CI_

// *************************************************************
// Inline operations for class TAO::_tao_seq_Octet_var
// *************************************************************

ACE_INLINE
TAO::_tao_seq_Octet_var::_tao_seq_Octet_var (void) // default constructor
	: ptr_ (0)
{}

ACE_INLINE
TAO::_tao_seq_Octet_var::_tao_seq_Octet_var (TAO::_tao_seq_Octet_ptr p)
	: ptr_ (p)
{}

ACE_INLINE
TAO::_tao_seq_Octet_var::_tao_seq_Octet_var (const TAO::_tao_seq_Octet_var &p) // copy constructor
{
  if (p.ptr_)
  	this->ptr_ = new TAO::_tao_seq_Octet(*p.ptr_);
  else
  	this->ptr_ = 0;
}

ACE_INLINE
TAO::_tao_seq_Octet_var::~_tao_seq_Octet_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE TAO::_tao_seq_Octet_var &
TAO::_tao_seq_Octet_var::operator= (TAO::_tao_seq_Octet *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE TAO::_tao_seq_Octet_var &
TAO::_tao_seq_Octet_var::operator= (const TAO::_tao_seq_Octet_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new TAO::_tao_seq_Octet (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const TAO::_tao_seq_Octet *
TAO::_tao_seq_Octet_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE TAO::_tao_seq_Octet *
TAO::_tao_seq_Octet_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
TAO::_tao_seq_Octet_var::operator const TAO::_tao_seq_Octet &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
TAO::_tao_seq_Octet_var::operator TAO::_tao_seq_Octet &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
TAO::_tao_seq_Octet_var::operator TAO::_tao_seq_Octet &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE CORBA::Octet&
TAO::_tao_seq_Octet_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const TAO::_tao_seq_Octet &
TAO::_tao_seq_Octet_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE TAO::_tao_seq_Octet &
TAO::_tao_seq_Octet_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE TAO::_tao_seq_Octet *&
TAO::_tao_seq_Octet_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE TAO::_tao_seq_Octet *
TAO::_tao_seq_Octet_var::_retn (void)
{
  TAO::_tao_seq_Octet *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE TAO::_tao_seq_Octet *
TAO::_tao_seq_Octet_var::ptr (void) const
{
  return this->ptr_;
}


#endif // end #if !defined


#if !defined (_TAO__TAO_SEQ_OCTET___OUT_CI_)
#define _TAO__TAO_SEQ_OCTET___OUT_CI_

// *************************************************************
// Inline operations for class TAO::_tao_seq_Octet_out
// *************************************************************

ACE_INLINE
TAO::_tao_seq_Octet_out::_tao_seq_Octet_out (TAO::_tao_seq_Octet *&p)
	: ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
TAO::_tao_seq_Octet_out::_tao_seq_Octet_out (TAO::_tao_seq_Octet_var &p) // constructor from _var
	: ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
TAO::_tao_seq_Octet_out::_tao_seq_Octet_out (TAO::_tao_seq_Octet_out &p) // copy constructor
	: ptr_ (p.ptr_)
{}

ACE_INLINE TAO::_tao_seq_Octet_out &
TAO::_tao_seq_Octet_out::operator= (TAO::_tao_seq_Octet_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE TAO::_tao_seq_Octet_out &
TAO::_tao_seq_Octet_out::operator= (TAO::_tao_seq_Octet *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
TAO::_tao_seq_Octet_out::operator TAO::_tao_seq_Octet *&() // cast
{
  return this->ptr_;
}

ACE_INLINE TAO::_tao_seq_Octet *&
TAO::_tao_seq_Octet_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE TAO::_tao_seq_Octet *
TAO::_tao_seq_Octet_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::Octet& 
TAO::_tao_seq_Octet_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}


#endif // end #if !defined

