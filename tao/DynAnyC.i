/* -*- C++ -*- */
// $Id$
// ======================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    DynAnyC.i
//
// = AUTHOR
//
// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html
//
//
// Modified by Jeff Parsons <jp4@cs.wustl.edu>
//
// ======================================================================

ACE_INLINE
CORBA_DynAny::CORBA_DynAny (void) // default constructor
{}

ACE_INLINE
CORBA_DynAny::CORBA_DynAny (STUB_Object *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_DynAny::~CORBA_DynAny (void) // destructor
{}


#if !defined (_CORBA_DYNANY___VAR_CI_)
#define _CORBA_DYNANY___VAR_CI_

// *************************************************************
// Inline operations for class CORBA_DynAny_var
// *************************************************************

ACE_INLINE
CORBA_DynAny_var::CORBA_DynAny_var (void) // default constructor
  : ptr_ (CORBA_DynAny::_nil ())
{}

ACE_INLINE
CORBA_DynAny_var::CORBA_DynAny_var (CORBA_DynAny_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_DynAny_ptr 
CORBA_DynAny_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DynAny_var::CORBA_DynAny_var (const CORBA_DynAny_var &p) // copy constructor
  : ptr_ (CORBA_DynAny::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_DynAny_var::~CORBA_DynAny_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_DynAny_var &
CORBA_DynAny_var::operator= (CORBA_DynAny_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_DynAny_var &
CORBA_DynAny_var::operator= (const CORBA_DynAny_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_DynAny::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
CORBA_DynAny_var::operator const CORBA_DynAny_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
CORBA_DynAny_var::operator CORBA_DynAny_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynAny_ptr 
CORBA_DynAny_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynAny_ptr
CORBA_DynAny_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynAny_ptr &
CORBA_DynAny_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynAny_ptr &
CORBA_DynAny_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynAny::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_DynAny_ptr 
CORBA_DynAny_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_DynAny_ptr val = this->ptr_;
  this->ptr_ = CORBA_DynAny::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_CORBA_DYNANY___OUT_CI_)
#define _CORBA_DYNANY___OUT_CI_

// *************************************************************
// Inline operations for class CORBA_DynAny_out
// *************************************************************

ACE_INLINE
CORBA_DynAny_out::CORBA_DynAny_out (CORBA_DynAny_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_DynAny::_nil ();
}

ACE_INLINE
CORBA_DynAny_out::CORBA_DynAny_out (CORBA_DynAny_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynAny::_nil ();
}

ACE_INLINE
CORBA_DynAny_out::CORBA_DynAny_out (const CORBA_DynAny_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DynAny_out&,p).ptr_)
{}

ACE_INLINE CORBA_DynAny_out &
CORBA_DynAny_out::operator= (const CORBA_DynAny_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_DynAny_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_DynAny_out &
CORBA_DynAny_out::operator= (const CORBA_DynAny_var &p)
{
  this->ptr_ = CORBA_DynAny::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_DynAny_out &
CORBA_DynAny_out::operator= (CORBA_DynAny_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_DynAny_out::operator CORBA_DynAny_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynAny_ptr &
CORBA_DynAny_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynAny_ptr 
CORBA_DynAny_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

// *************************************************************
// Inline operations for exception CORBA_DynAny::Invalid
// *************************************************************

// *************************************************************
// Inline operations for exception CORBA_DynAny::InvalidValue
// *************************************************************

// *************************************************************
// Inline operations for exception CORBA_DynAny::TypeMismatch
// *************************************************************

// *************************************************************
// Inline operations for exception CORBA_DynAny::InvalidSeq
// *************************************************************

ACE_INLINE
CORBA_DynEnum::CORBA_DynEnum (void) // default constructor
{}

ACE_INLINE
CORBA_DynEnum::CORBA_DynEnum (STUB_Object *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_DynEnum::~CORBA_DynEnum (void) // destructor
{}


#if !defined (_CORBA_DYNENUM___VAR_CI_)
#define _CORBA_DYNENUM___VAR_CI_

// *************************************************************
// Inline operations for class CORBA_DynEnum_var
// *************************************************************

ACE_INLINE
CORBA_DynEnum_var::CORBA_DynEnum_var (void) // default constructor
  : ptr_ (CORBA_DynEnum::_nil ())
{}

ACE_INLINE
CORBA_DynEnum_var::CORBA_DynEnum_var (CORBA_DynEnum_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_DynEnum_ptr 
CORBA_DynEnum_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DynEnum_var::CORBA_DynEnum_var (const CORBA_DynEnum_var &p) // copy constructor
  : ptr_ (CORBA_DynEnum::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_DynEnum_var::~CORBA_DynEnum_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_DynEnum_var &
CORBA_DynEnum_var::operator= (CORBA_DynEnum_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_DynEnum_var &
CORBA_DynEnum_var::operator= (const CORBA_DynEnum_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_DynEnum::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
CORBA_DynEnum_var::operator const CORBA_DynEnum_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
CORBA_DynEnum_var::operator CORBA_DynEnum_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynEnum_ptr 
CORBA_DynEnum_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynEnum_ptr
CORBA_DynEnum_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynEnum_ptr &
CORBA_DynEnum_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynEnum_ptr &
CORBA_DynEnum_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynEnum::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_DynEnum_ptr 
CORBA_DynEnum_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_DynEnum_ptr val = this->ptr_;
  this->ptr_ = CORBA_DynEnum::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_CORBA_DYNENUM___OUT_CI_)
#define _CORBA_DYNENUM___OUT_CI_

// *************************************************************
// Inline operations for class CORBA_DynEnum_out
// *************************************************************

ACE_INLINE
CORBA_DynEnum_out::CORBA_DynEnum_out (CORBA_DynEnum_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_DynEnum::_nil ();
}

ACE_INLINE
CORBA_DynEnum_out::CORBA_DynEnum_out (CORBA_DynEnum_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynEnum::_nil ();
}

ACE_INLINE
CORBA_DynEnum_out::CORBA_DynEnum_out (const CORBA_DynEnum_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DynEnum_out&,p).ptr_)
{}

ACE_INLINE CORBA_DynEnum_out &
CORBA_DynEnum_out::operator= (const CORBA_DynEnum_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_DynEnum_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_DynEnum_out &
CORBA_DynEnum_out::operator= (const CORBA_DynEnum_var &p)
{
  this->ptr_ = CORBA_DynEnum::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_DynEnum_out &
CORBA_DynEnum_out::operator= (CORBA_DynEnum_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_DynEnum_out::operator CORBA_DynEnum_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynEnum_ptr &
CORBA_DynEnum_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynEnum_ptr 
CORBA_DynEnum_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

// *************************************************************
// Inline operations for class NameValuePair_var
// *************************************************************

ACE_INLINE
NameValuePair_var::NameValuePair_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
NameValuePair_var::NameValuePair_var (NameValuePair *p)
  : ptr_ (p)
{}

ACE_INLINE
NameValuePair_var::NameValuePair_var (const NameValuePair_var &p) // copy constructor
{
  if (p.ptr_)
    this->ptr_ = new NameValuePair(*p.ptr_);
  else
    this->ptr_ = 0;
}

ACE_INLINE
NameValuePair_var::~NameValuePair_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE NameValuePair_var &
NameValuePair_var::operator= (NameValuePair *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE NameValuePair_var &
NameValuePair_var::operator= (const NameValuePair_var &p)
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new NameValuePair (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const NameValuePair *
NameValuePair_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE NameValuePair *
NameValuePair_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
NameValuePair_var::operator const NameValuePair &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
NameValuePair_var::operator NameValuePair &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
NameValuePair_var::operator NameValuePair &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE const NameValuePair &
NameValuePair_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE NameValuePair &
NameValuePair_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE NameValuePair *&
NameValuePair_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE NameValuePair *
NameValuePair_var::_retn (void)
{
  NameValuePair *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE NameValuePair *
NameValuePair_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class NameValuePair_out
// *************************************************************

ACE_INLINE
NameValuePair_out::NameValuePair_out (NameValuePair *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
NameValuePair_out::NameValuePair_out (NameValuePair_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
NameValuePair_out::NameValuePair_out (const NameValuePair_out &p) // copy constructor
  : ptr_ (ACE_const_cast (NameValuePair_out&,p).ptr_)
{}

ACE_INLINE NameValuePair_out &
NameValuePair_out::operator= (const NameValuePair_out &p)
{
  this->ptr_ = ACE_const_cast (NameValuePair_out&,p).ptr_;
  return *this;
}

ACE_INLINE NameValuePair_out &
NameValuePair_out::operator= (NameValuePair *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
NameValuePair_out::operator NameValuePair *&() // cast
{
  return this->ptr_;
}

ACE_INLINE NameValuePair *&
NameValuePair_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE NameValuePair *
NameValuePair_out::operator-> (void)
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class NameValuePairSeq_var
// *************************************************************

ACE_INLINE
NameValuePairSeq_var::NameValuePairSeq_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
NameValuePairSeq_var::NameValuePairSeq_var (NameValuePairSeq *p)
  : ptr_ (p)
{}

ACE_INLINE
NameValuePairSeq_var::NameValuePairSeq_var (const NameValuePairSeq_var &p) // copy constructor
{
  if (p.ptr_)
    this->ptr_ = new NameValuePairSeq(*p.ptr_);
  else
    this->ptr_ = 0;
}

ACE_INLINE
NameValuePairSeq_var::~NameValuePairSeq_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE NameValuePairSeq_var &
NameValuePairSeq_var::operator= (NameValuePairSeq *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE NameValuePairSeq_var &
NameValuePairSeq_var::operator= (const NameValuePairSeq_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new NameValuePairSeq (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const NameValuePairSeq *
NameValuePairSeq_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE NameValuePairSeq *
NameValuePairSeq_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
NameValuePairSeq_var::operator const NameValuePairSeq &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
NameValuePairSeq_var::operator NameValuePairSeq &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
NameValuePairSeq_var::operator NameValuePairSeq &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE NameValuePair &
NameValuePairSeq_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const NameValuePairSeq &
NameValuePairSeq_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE NameValuePairSeq &
NameValuePairSeq_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE NameValuePairSeq *&
NameValuePairSeq_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE NameValuePairSeq *
NameValuePairSeq_var::_retn (void)
{
  NameValuePairSeq *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE NameValuePairSeq *
NameValuePairSeq_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class NameValuePairSeq_out
// *************************************************************

ACE_INLINE
NameValuePairSeq_out::NameValuePairSeq_out (NameValuePairSeq *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
NameValuePairSeq_out::NameValuePairSeq_out (NameValuePairSeq_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
NameValuePairSeq_out::NameValuePairSeq_out (const NameValuePairSeq_out &p) // copy constructor
  : ptr_ (ACE_const_cast (NameValuePairSeq_out&,p).ptr_)
{}

ACE_INLINE NameValuePairSeq_out &
NameValuePairSeq_out::operator= (const NameValuePairSeq_out &p)
{
  this->ptr_ = ACE_const_cast (NameValuePairSeq_out&,p).ptr_;
  return *this;
}

ACE_INLINE NameValuePairSeq_out &
NameValuePairSeq_out::operator= (NameValuePairSeq *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
NameValuePairSeq_out::operator NameValuePairSeq *&() // cast
{
  return this->ptr_;
}

ACE_INLINE NameValuePairSeq *&
NameValuePairSeq_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE NameValuePairSeq *
NameValuePairSeq_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE NameValuePair &
NameValuePairSeq_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
CORBA_DynStruct::CORBA_DynStruct (void) // default constructor
{}

ACE_INLINE
CORBA_DynStruct::CORBA_DynStruct (STUB_Object *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_DynStruct::~CORBA_DynStruct (void) // destructor
{}


#if !defined (_CORBA_DYNSTRUCT___VAR_CI_)
#define _CORBA_DYNSTRUCT___VAR_CI_

// *************************************************************
// Inline operations for class CORBA_DynStruct_var
// *************************************************************

ACE_INLINE
CORBA_DynStruct_var::CORBA_DynStruct_var (void) // default constructor
  : ptr_ (CORBA_DynStruct::_nil ())
{}

ACE_INLINE
CORBA_DynStruct_var::CORBA_DynStruct_var (CORBA_DynStruct_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_DynStruct_ptr 
CORBA_DynStruct_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DynStruct_var::CORBA_DynStruct_var (const CORBA_DynStruct_var &p) // copy constructor
  : ptr_ (CORBA_DynStruct::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_DynStruct_var::~CORBA_DynStruct_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_DynStruct_var &
CORBA_DynStruct_var::operator= (CORBA_DynStruct_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_DynStruct_var &
CORBA_DynStruct_var::operator= (const CORBA_DynStruct_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_DynStruct::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
CORBA_DynStruct_var::operator const CORBA_DynStruct_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
CORBA_DynStruct_var::operator CORBA_DynStruct_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynStruct_ptr 
CORBA_DynStruct_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynStruct_ptr
CORBA_DynStruct_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynStruct_ptr &
CORBA_DynStruct_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynStruct_ptr &
CORBA_DynStruct_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynStruct::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_DynStruct_ptr 
CORBA_DynStruct_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_DynStruct_ptr val = this->ptr_;
  this->ptr_ = CORBA_DynStruct::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_CORBA_DYNSTRUCT___OUT_CI_)
#define _CORBA_DYNSTRUCT___OUT_CI_

// *************************************************************
// Inline operations for class CORBA_DynStruct_out
// *************************************************************

ACE_INLINE
CORBA_DynStruct_out::CORBA_DynStruct_out (CORBA_DynStruct_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_DynStruct::_nil ();
}

ACE_INLINE
CORBA_DynStruct_out::CORBA_DynStruct_out (CORBA_DynStruct_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynStruct::_nil ();
}

ACE_INLINE
CORBA_DynStruct_out::CORBA_DynStruct_out (const CORBA_DynStruct_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DynStruct_out&,p).ptr_)
{}

ACE_INLINE CORBA_DynStruct_out &
CORBA_DynStruct_out::operator= (const CORBA_DynStruct_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_DynStruct_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_DynStruct_out &
CORBA_DynStruct_out::operator= (const CORBA_DynStruct_var &p)
{
  this->ptr_ = CORBA_DynStruct::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_DynStruct_out &
CORBA_DynStruct_out::operator= (CORBA_DynStruct_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_DynStruct_out::operator CORBA_DynStruct_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynStruct_ptr &
CORBA_DynStruct_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynStruct_ptr 
CORBA_DynStruct_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

ACE_INLINE
CORBA_DynUnion::CORBA_DynUnion (void) // default constructor
{}

ACE_INLINE
CORBA_DynUnion::CORBA_DynUnion (STUB_Object *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_DynUnion::~CORBA_DynUnion (void) // destructor
{}


#if !defined (_CORBA_DYNUNION___VAR_CI_)
#define _CORBA_DYNUNION___VAR_CI_

// *************************************************************
// Inline operations for class CORBA_DynUnion_var
// *************************************************************

ACE_INLINE
CORBA_DynUnion_var::CORBA_DynUnion_var (void) // default constructor
  : ptr_ (CORBA_DynUnion::_nil ())
{}

ACE_INLINE
CORBA_DynUnion_var::CORBA_DynUnion_var (CORBA_DynUnion_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_DynUnion_ptr 
CORBA_DynUnion_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DynUnion_var::CORBA_DynUnion_var (const CORBA_DynUnion_var &p) // copy constructor
  : ptr_ (CORBA_DynUnion::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_DynUnion_var::~CORBA_DynUnion_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_DynUnion_var &
CORBA_DynUnion_var::operator= (CORBA_DynUnion_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_DynUnion_var &
CORBA_DynUnion_var::operator= (const CORBA_DynUnion_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_DynUnion::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
CORBA_DynUnion_var::operator const CORBA_DynUnion_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
CORBA_DynUnion_var::operator CORBA_DynUnion_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynUnion_ptr 
CORBA_DynUnion_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynUnion_ptr
CORBA_DynUnion_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynUnion_ptr &
CORBA_DynUnion_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynUnion_ptr &
CORBA_DynUnion_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynUnion::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_DynUnion_ptr 
CORBA_DynUnion_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_DynUnion_ptr val = this->ptr_;
  this->ptr_ = CORBA_DynUnion::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_CORBA_DYNUNION___OUT_CI_)
#define _CORBA_DYNUNION___OUT_CI_

// *************************************************************
// Inline operations for class CORBA_DynUnion_out
// *************************************************************

ACE_INLINE
CORBA_DynUnion_out::CORBA_DynUnion_out (CORBA_DynUnion_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_DynUnion::_nil ();
}

ACE_INLINE
CORBA_DynUnion_out::CORBA_DynUnion_out (CORBA_DynUnion_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynUnion::_nil ();
}

ACE_INLINE
CORBA_DynUnion_out::CORBA_DynUnion_out (const CORBA_DynUnion_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DynUnion_out&,p).ptr_)
{}

ACE_INLINE CORBA_DynUnion_out &
CORBA_DynUnion_out::operator= (const CORBA_DynUnion_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_DynUnion_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_DynUnion_out &
CORBA_DynUnion_out::operator= (const CORBA_DynUnion_var &p)
{
  this->ptr_ = CORBA_DynUnion::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_DynUnion_out &
CORBA_DynUnion_out::operator= (CORBA_DynUnion_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_DynUnion_out::operator CORBA_DynUnion_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynUnion_ptr &
CORBA_DynUnion_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynUnion_ptr 
CORBA_DynUnion_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

// *************************************************************
// Inline operations for class AnySeq_var
// *************************************************************

ACE_INLINE
AnySeq_var::AnySeq_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
AnySeq_var::AnySeq_var (AnySeq *p)
  : ptr_ (p)
{}

ACE_INLINE
AnySeq_var::AnySeq_var (const AnySeq_var &p) // copy constructor
{
  if (p.ptr_)
    this->ptr_ = new AnySeq(*p.ptr_);
  else
    this->ptr_ = 0;
}

ACE_INLINE
AnySeq_var::~AnySeq_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE AnySeq_var &
AnySeq_var::operator= (AnySeq *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE AnySeq_var &
AnySeq_var::operator= (const AnySeq_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    this->ptr_ = new AnySeq (*p.ptr_);
  }
  return *this;
}

ACE_INLINE const AnySeq *
AnySeq_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE AnySeq *
AnySeq_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE 
AnySeq_var::operator const AnySeq &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE 
AnySeq_var::operator AnySeq &() // cast 
{
  return *this->ptr_;
}

ACE_INLINE 
AnySeq_var::operator AnySeq &() const// cast 
{
  return *this->ptr_;
}

ACE_INLINE CORBA::Any &
AnySeq_var::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE const AnySeq &
AnySeq_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE AnySeq &
AnySeq_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size 
ACE_INLINE AnySeq *&
AnySeq_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE AnySeq *
AnySeq_var::_retn (void)
{
  AnySeq *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE AnySeq *
AnySeq_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class AnySeq_out
// *************************************************************

ACE_INLINE
AnySeq_out::AnySeq_out (AnySeq *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
AnySeq_out::AnySeq_out (AnySeq_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
AnySeq_out::AnySeq_out (const AnySeq_out &p) // copy constructor
  : ptr_ (ACE_const_cast (AnySeq_out&,p).ptr_)
{}

ACE_INLINE AnySeq_out &
AnySeq_out::operator= (const AnySeq_out &p)
{
  this->ptr_ = ACE_const_cast (AnySeq_out&,p).ptr_;
  return *this;
}

ACE_INLINE AnySeq_out &
AnySeq_out::operator= (AnySeq *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
AnySeq_out::operator AnySeq *&() // cast
{
  return this->ptr_;
}

ACE_INLINE AnySeq *&
AnySeq_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE AnySeq *
AnySeq_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::Any &
AnySeq_out::operator[] (CORBA::ULong index)
{
  return this->ptr_->operator[] (index);
}

ACE_INLINE
CORBA_DynSequence::CORBA_DynSequence (void) // default constructor
{}

ACE_INLINE
CORBA_DynSequence::CORBA_DynSequence (STUB_Object *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_DynSequence::~CORBA_DynSequence (void) // destructor
{}


#if !defined (_CORBA_DYNSEQUENCE___VAR_CI_)
#define _CORBA_DYNSEQUENCE___VAR_CI_

// *************************************************************
// Inline operations for class CORBA_DynSequence_var
// *************************************************************

ACE_INLINE
CORBA_DynSequence_var::CORBA_DynSequence_var (void) // default constructor
  : ptr_ (CORBA_DynSequence::_nil ())
{}

ACE_INLINE
CORBA_DynSequence_var::CORBA_DynSequence_var (CORBA_DynSequence_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_DynSequence_ptr 
CORBA_DynSequence_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DynSequence_var::CORBA_DynSequence_var (const CORBA_DynSequence_var &p) // copy constructor
  : ptr_ (CORBA_DynSequence::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_DynSequence_var::~CORBA_DynSequence_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_DynSequence_var &
CORBA_DynSequence_var::operator= (CORBA_DynSequence_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_DynSequence_var &
CORBA_DynSequence_var::operator= (const CORBA_DynSequence_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_DynSequence::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
CORBA_DynSequence_var::operator const CORBA_DynSequence_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
CORBA_DynSequence_var::operator CORBA_DynSequence_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynSequence_ptr 
CORBA_DynSequence_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynSequence_ptr
CORBA_DynSequence_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynSequence_ptr &
CORBA_DynSequence_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynSequence_ptr &
CORBA_DynSequence_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynSequence::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_DynSequence_ptr 
CORBA_DynSequence_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_DynSequence_ptr val = this->ptr_;
  this->ptr_ = CORBA_DynSequence::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_CORBA_DYNSEQUENCE___OUT_CI_)
#define _CORBA_DYNSEQUENCE___OUT_CI_

// *************************************************************
// Inline operations for class CORBA_DynSequence_out
// *************************************************************

ACE_INLINE
CORBA_DynSequence_out::CORBA_DynSequence_out (CORBA_DynSequence_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_DynSequence::_nil ();
}

ACE_INLINE
CORBA_DynSequence_out::CORBA_DynSequence_out (CORBA_DynSequence_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynSequence::_nil ();
}

ACE_INLINE
CORBA_DynSequence_out::CORBA_DynSequence_out (const CORBA_DynSequence_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DynSequence_out&,p).ptr_)
{}

ACE_INLINE CORBA_DynSequence_out &
CORBA_DynSequence_out::operator= (const CORBA_DynSequence_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_DynSequence_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_DynSequence_out &
CORBA_DynSequence_out::operator= (const CORBA_DynSequence_var &p)
{
  this->ptr_ = CORBA_DynSequence::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_DynSequence_out &
CORBA_DynSequence_out::operator= (CORBA_DynSequence_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_DynSequence_out::operator CORBA_DynSequence_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynSequence_ptr &
CORBA_DynSequence_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynSequence_ptr 
CORBA_DynSequence_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

ACE_INLINE
CORBA_DynArray::CORBA_DynArray (void) // default constructor
{}

ACE_INLINE
CORBA_DynArray::CORBA_DynArray (STUB_Object *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_DynArray::~CORBA_DynArray (void) // destructor
{}


#if !defined (_CORBA_DYNARRAY___VAR_CI_)
#define _CORBA_DYNARRAY___VAR_CI_

// *************************************************************
// Inline operations for class CORBA_DynArray_var
// *************************************************************

ACE_INLINE
CORBA_DynArray_var::CORBA_DynArray_var (void) // default constructor
  : ptr_ (CORBA_DynArray::_nil ())
{}

ACE_INLINE
CORBA_DynArray_var::CORBA_DynArray_var (CORBA_DynArray_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_DynArray_ptr 
CORBA_DynArray_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DynArray_var::CORBA_DynArray_var (const CORBA_DynArray_var &p) // copy constructor
  : ptr_ (CORBA_DynArray::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_DynArray_var::~CORBA_DynArray_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_DynArray_var &
CORBA_DynArray_var::operator= (CORBA_DynArray_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_DynArray_var &
CORBA_DynArray_var::operator= (const CORBA_DynArray_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_DynArray::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE 
CORBA_DynArray_var::operator const CORBA_DynArray_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE 
CORBA_DynArray_var::operator CORBA_DynArray_ptr &() // cast 
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynArray_ptr 
CORBA_DynArray_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynArray_ptr
CORBA_DynArray_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynArray_ptr &
CORBA_DynArray_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynArray_ptr &
CORBA_DynArray_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynArray::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_DynArray_ptr 
CORBA_DynArray_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_DynArray_ptr val = this->ptr_;
  this->ptr_ = CORBA_DynArray::_nil ();
  return val;
}


#endif /* end #if !defined */


#if !defined (_CORBA_DYNARRAY___OUT_CI_)
#define _CORBA_DYNARRAY___OUT_CI_

// *************************************************************
// Inline operations for class CORBA_DynArray_out
// *************************************************************

ACE_INLINE
CORBA_DynArray_out::CORBA_DynArray_out (CORBA_DynArray_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_DynArray::_nil ();
}

ACE_INLINE
CORBA_DynArray_out::CORBA_DynArray_out (CORBA_DynArray_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DynArray::_nil ();
}

ACE_INLINE
CORBA_DynArray_out::CORBA_DynArray_out (const CORBA_DynArray_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DynArray_out&,p).ptr_)
{}

ACE_INLINE CORBA_DynArray_out &
CORBA_DynArray_out::operator= (const CORBA_DynArray_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_DynArray_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_DynArray_out &
CORBA_DynArray_out::operator= (const CORBA_DynArray_var &p)
{
  this->ptr_ = CORBA_DynArray::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_DynArray_out &
CORBA_DynArray_out::operator= (CORBA_DynArray_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE 
CORBA_DynArray_out::operator CORBA_DynArray_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynArray_ptr &
CORBA_DynArray_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_DynArray_ptr 
CORBA_DynArray_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* end #if !defined */

