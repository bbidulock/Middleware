// $Id$

/* -*- C++ -*- */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

// *************************************************************
// Inline operations for class CORBA::InvalidPolicies::_tao_seq_UShort
// *************************************************************

ACE_INLINE
CORBA_InvalidPolicies::_tao_seq_UShort::_tao_seq_UShort (void)
{
}

ACE_INLINE
CORBA_InvalidPolicies::_tao_seq_UShort::_tao_seq_UShort (CORBA::ULong max)
  : TAO_Unbounded_Sequence<CORBA::UShort> (max)
{
}

ACE_INLINE
CORBA_InvalidPolicies::_tao_seq_UShort::_tao_seq_UShort (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::UShort *buffer,
    CORBA::Boolean release)
  : TAO_Unbounded_Sequence<CORBA::UShort> (max,
                                           length,
                                           buffer,
                                           release)
{
}

ACE_INLINE
CORBA_InvalidPolicies::_tao_seq_UShort::_tao_seq_UShort (
    const CORBA_InvalidPolicies::_tao_seq_UShort &rhs)
  : TAO_Unbounded_Sequence<CORBA::UShort> (rhs)
{
}

ACE_INLINE
CORBA_InvalidPolicies::_tao_seq_UShort::~_tao_seq_UShort (void)
{
}

// ****************************************************************

ACE_INLINE
CORBA_Policy::CORBA_Policy (void) // default constructor
{}

ACE_INLINE
CORBA_Policy::CORBA_Policy (TAO_Stub *objref,
                            TAO_ServantBase *_tao_servant,
                            CORBA::Boolean _tao_collocated)
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_Policy::~CORBA_Policy (void) // destructor
{}

ACE_INLINE
CORBA_Policy_var::CORBA_Policy_var (void) // default constructor
  : ptr_ (CORBA_Policy::_nil ())
{}

ACE_INLINE
CORBA_Policy_var::CORBA_Policy_var (CORBA_Policy_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_var::ptr (void) const
{
  return this->ptr_;
}

// copy constructor
ACE_INLINE
CORBA_Policy_var::CORBA_Policy_var (const CORBA_Policy_var &p)
  : ptr_ (CORBA_Policy::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_Policy_var::~CORBA_Policy_var (void)
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_Policy_var &
CORBA_Policy_var::operator= (CORBA_Policy_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_Policy_var &
CORBA_Policy_var::operator= (const CORBA_Policy_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_Policy::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
CORBA_Policy_var::operator const CORBA_Policy_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
CORBA_Policy_var::operator CORBA_Policy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr &
CORBA_Policy_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr &
CORBA_Policy_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_Policy::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_Policy_ptr val = this->ptr_;
  this->ptr_ = CORBA_Policy::_nil ();
  return val;
}

// *************************************************************
// Inline operations for class CORBA_Policy_out
// *************************************************************

ACE_INLINE
CORBA_Policy_out::CORBA_Policy_out (CORBA_Policy_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_Policy::_nil ();
}

ACE_INLINE
CORBA_Policy_out::CORBA_Policy_out (CORBA_Policy_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_Policy::_nil ();
}

ACE_INLINE
CORBA_Policy_out::CORBA_Policy_out (CORBA_Policy_out &p) // copy constructor
  : ptr_ (p.ptr_)
{}

ACE_INLINE CORBA_Policy_out &
CORBA_Policy_out::operator= (CORBA_Policy_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE CORBA_Policy_out &
CORBA_Policy_out::operator= (const CORBA_Policy_var &p)
{
  this->ptr_ = CORBA_Policy::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_Policy_out &
CORBA_Policy_out::operator= (CORBA_Policy_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_Policy_out::operator CORBA_Policy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr &
CORBA_Policy_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_Policy_ptr
CORBA_Policy_out::operator-> (void)
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_PolicyList_var
// *************************************************************

ACE_INLINE
CORBA_PolicyList_var::CORBA_PolicyList_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_PolicyList_var::CORBA_PolicyList_var (CORBA_PolicyList *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_PolicyList_var::CORBA_PolicyList_var (const CORBA_PolicyList_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_,
             CORBA_PolicyList (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyList_var::~CORBA_PolicyList_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_PolicyList_var &
CORBA_PolicyList_var::operator= (CORBA_PolicyList *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_PolicyList_var &
CORBA_PolicyList_var::operator= (const CORBA_PolicyList_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_,
                    CORBA_PolicyList (*p.ptr_),
		    *this);
  }
  return *this;
}

ACE_INLINE const CORBA_PolicyList *
CORBA_PolicyList_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyList *
CORBA_PolicyList_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA_PolicyList_var::operator const CORBA_PolicyList &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_PolicyList_var::operator CORBA_PolicyList &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_PolicyList_var::operator CORBA_PolicyList &() const// cast
{
  return *this->ptr_;
}

ACE_INLINE TAO_Object_Manager <CORBA_Policy,CORBA_Policy_var >
CORBA_PolicyList_var::operator[] (CORBA::ULong slot)
{
  return this->ptr_->operator[] (slot);
}

ACE_INLINE const CORBA_PolicyList &
CORBA_PolicyList_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE CORBA_PolicyList &
CORBA_PolicyList_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE CORBA_PolicyList *&
CORBA_PolicyList_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyList *
CORBA_PolicyList_var::_retn (void)
{
  CORBA_PolicyList *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE CORBA_PolicyList *
CORBA_PolicyList_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_PolicyList_out
// *************************************************************

ACE_INLINE
CORBA_PolicyList_out::CORBA_PolicyList_out (CORBA_PolicyList *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyList_out::CORBA_PolicyList_out (CORBA_PolicyList_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyList_out::CORBA_PolicyList_out (const CORBA_PolicyList_out &p) // copy constructor
  : ptr_ (p.ptr_)
{}

ACE_INLINE CORBA_PolicyList_out &
CORBA_PolicyList_out::operator= (CORBA_PolicyList_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE CORBA_PolicyList_out &
CORBA_PolicyList_out::operator= (CORBA_PolicyList *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_PolicyList_out::operator CORBA_PolicyList *&() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyList *&
CORBA_PolicyList_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyList *
CORBA_PolicyList_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE TAO_Object_Manager <CORBA_Policy,CORBA_Policy_var >
CORBA_PolicyList_out::operator[] (CORBA::ULong slot)
{
  return this->ptr_->operator[] (slot);
}

// *************************************************************
// Inline operations for class CORBA_PolicyTypeSeq_var
// *************************************************************

ACE_INLINE
CORBA_PolicyTypeSeq_var::CORBA_PolicyTypeSeq_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_PolicyTypeSeq_var::CORBA_PolicyTypeSeq_var (CORBA_PolicyTypeSeq *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_PolicyTypeSeq_var::CORBA_PolicyTypeSeq_var (const CORBA_PolicyTypeSeq_var &p)
{
  if (p.ptr_)
    ACE_NEW (this->ptr_,
             CORBA_PolicyTypeSeq (*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyTypeSeq_var::~CORBA_PolicyTypeSeq_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_PolicyTypeSeq_var &
CORBA_PolicyTypeSeq_var::operator= (CORBA_PolicyTypeSeq *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_PolicyTypeSeq_var &
CORBA_PolicyTypeSeq_var::operator= (const CORBA_PolicyTypeSeq_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_,
                    CORBA_PolicyTypeSeq (*p.ptr_),
		    *this);
  }
  return *this;
}

ACE_INLINE const CORBA_PolicyTypeSeq *
CORBA_PolicyTypeSeq_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyTypeSeq *
CORBA_PolicyTypeSeq_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA_PolicyTypeSeq_var::operator const CORBA_PolicyTypeSeq &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_PolicyTypeSeq_var::operator CORBA_PolicyTypeSeq &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_PolicyTypeSeq_var::operator CORBA_PolicyTypeSeq &() const// cast
{
  return *this->ptr_;
}

ACE_INLINE CORBA::PolicyType &
CORBA_PolicyTypeSeq_var::operator[] (CORBA::ULong slot)
{
  return this->ptr_->operator[] (slot);
}

ACE_INLINE const CORBA_PolicyTypeSeq &
CORBA_PolicyTypeSeq_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE CORBA_PolicyTypeSeq &
CORBA_PolicyTypeSeq_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE CORBA_PolicyTypeSeq *&
CORBA_PolicyTypeSeq_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyTypeSeq *
CORBA_PolicyTypeSeq_var::_retn (void)
{
  CORBA_PolicyTypeSeq *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE CORBA_PolicyTypeSeq *
CORBA_PolicyTypeSeq_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA_PolicyTypeSeq_out
// *************************************************************

ACE_INLINE
CORBA_PolicyTypeSeq_out::CORBA_PolicyTypeSeq_out (CORBA_PolicyTypeSeq *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyTypeSeq_out::CORBA_PolicyTypeSeq_out (CORBA_PolicyTypeSeq_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_PolicyTypeSeq_out::CORBA_PolicyTypeSeq_out (const CORBA_PolicyTypeSeq_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_PolicyTypeSeq_out&,p).ptr_)
{}

ACE_INLINE CORBA_PolicyTypeSeq_out &
CORBA_PolicyTypeSeq_out::operator= (const CORBA_PolicyTypeSeq_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_PolicyTypeSeq_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_PolicyTypeSeq_out &
CORBA_PolicyTypeSeq_out::operator= (CORBA_PolicyTypeSeq *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_PolicyTypeSeq_out::operator CORBA_PolicyTypeSeq *&() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyTypeSeq *&
CORBA_PolicyTypeSeq_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyTypeSeq *
CORBA_PolicyTypeSeq_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::PolicyType &
CORBA_PolicyTypeSeq_out::operator[] (CORBA::ULong slot)
{
  return this->ptr_->operator[] (slot);
}

// ****************************************************************

ACE_INLINE
CORBA_PolicyManager::CORBA_PolicyManager (void) // default constructor
{}

ACE_INLINE
CORBA_PolicyManager::CORBA_PolicyManager (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_PolicyManager::~CORBA_PolicyManager (void) // destructor
{}

ACE_INLINE CORBA_PolicyManager_ptr
CORBA_PolicyManager::_duplicate (CORBA_PolicyManager_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  return obj;
}

ACE_INLINE CORBA_PolicyManager_ptr
CORBA_PolicyManager::_nil (void)
{
  return (CORBA_PolicyManager_ptr)0;
}

// *************************************************************
// Inline operations for class CORBA_PolicyManager_var
// *************************************************************

ACE_INLINE
CORBA_PolicyManager_var::CORBA_PolicyManager_var (void) // default constructor
  : ptr_ (CORBA_PolicyManager::_nil ())
{}

ACE_INLINE
CORBA_PolicyManager_var::CORBA_PolicyManager_var (CORBA_PolicyManager_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_PolicyManager_ptr
CORBA_PolicyManager_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_PolicyManager_var::CORBA_PolicyManager_var (const CORBA_PolicyManager_var &p) // copy constructor
  : ptr_ (CORBA_PolicyManager::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_PolicyManager_var::~CORBA_PolicyManager_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_PolicyManager_var &
CORBA_PolicyManager_var::operator= (CORBA_PolicyManager_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_PolicyManager_var &
CORBA_PolicyManager_var::operator= (const CORBA_PolicyManager_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_PolicyManager::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
CORBA_PolicyManager_var::operator const CORBA_PolicyManager_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
CORBA_PolicyManager_var::operator CORBA_PolicyManager_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyManager_ptr
CORBA_PolicyManager_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyManager_ptr
CORBA_PolicyManager_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyManager_ptr &
CORBA_PolicyManager_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyManager_ptr &
CORBA_PolicyManager_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_PolicyManager::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyManager_ptr
CORBA_PolicyManager_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_PolicyManager_ptr val = this->ptr_;
  this->ptr_ = CORBA_PolicyManager::_nil ();
  return val;
}

// *************************************************************
// Inline operations for class CORBA_PolicyManager_out
// *************************************************************

ACE_INLINE
CORBA_PolicyManager_out::CORBA_PolicyManager_out (CORBA_PolicyManager_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_PolicyManager::_nil ();
}

ACE_INLINE
CORBA_PolicyManager_out::CORBA_PolicyManager_out (CORBA_PolicyManager_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_PolicyManager::_nil ();
}

ACE_INLINE
CORBA_PolicyManager_out::CORBA_PolicyManager_out (const CORBA_PolicyManager_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_PolicyManager_out&,p).ptr_)
{}

ACE_INLINE CORBA_PolicyManager_out &
CORBA_PolicyManager_out::operator= (const CORBA_PolicyManager_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_PolicyManager_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_PolicyManager_out &
CORBA_PolicyManager_out::operator= (const CORBA_PolicyManager_var &p)
{
  this->ptr_ = CORBA_PolicyManager::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_PolicyManager_out &
CORBA_PolicyManager_out::operator= (CORBA_PolicyManager_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_PolicyManager_out::operator CORBA_PolicyManager_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyManager_ptr &
CORBA_PolicyManager_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyManager_ptr
CORBA_PolicyManager_out::operator-> (void)
{
  return this->ptr_;
}

// ****************************************************************

ACE_INLINE
CORBA_PolicyCurrent::CORBA_PolicyCurrent (void) // default constructor
{}

ACE_INLINE
CORBA_PolicyCurrent::CORBA_PolicyCurrent (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_PolicyCurrent::~CORBA_PolicyCurrent (void) // destructor
{}

ACE_INLINE CORBA_PolicyCurrent_ptr
CORBA_PolicyCurrent::_duplicate (CORBA_PolicyCurrent_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  return obj;
}

ACE_INLINE CORBA_PolicyCurrent_ptr
CORBA_PolicyCurrent::_nil (void)
{
  return (CORBA_PolicyCurrent_ptr)0;
}

// *************************************************************
// Inline operations for class CORBA_PolicyCurrent_var
// *************************************************************

ACE_INLINE
CORBA_PolicyCurrent_var::CORBA_PolicyCurrent_var (void) // default constructor
  : ptr_ (CORBA_PolicyCurrent::_nil ())
{}

ACE_INLINE
CORBA_PolicyCurrent_var::CORBA_PolicyCurrent_var (CORBA_PolicyCurrent_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_PolicyCurrent_ptr
CORBA_PolicyCurrent_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_PolicyCurrent_var::CORBA_PolicyCurrent_var (const CORBA_PolicyCurrent_var &p) // copy constructor
  : ptr_ (CORBA_PolicyCurrent::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_PolicyCurrent_var::~CORBA_PolicyCurrent_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_PolicyCurrent_var &
CORBA_PolicyCurrent_var::operator= (CORBA_PolicyCurrent_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_PolicyCurrent_var &
CORBA_PolicyCurrent_var::operator= (const CORBA_PolicyCurrent_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_PolicyCurrent::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
CORBA_PolicyCurrent_var::operator const CORBA_PolicyCurrent_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
CORBA_PolicyCurrent_var::operator CORBA_PolicyCurrent_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyCurrent_ptr
CORBA_PolicyCurrent_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyCurrent_ptr
CORBA_PolicyCurrent_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyCurrent_ptr &
CORBA_PolicyCurrent_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyCurrent_ptr &
CORBA_PolicyCurrent_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_PolicyCurrent::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyCurrent_ptr
CORBA_PolicyCurrent_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_PolicyCurrent_ptr val = this->ptr_;
  this->ptr_ = CORBA_PolicyCurrent::_nil ();
  return val;
}

// *************************************************************
// Inline operations for class CORBA_PolicyCurrent_out
// *************************************************************

ACE_INLINE
CORBA_PolicyCurrent_out::CORBA_PolicyCurrent_out (CORBA_PolicyCurrent_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_PolicyCurrent::_nil ();
}

ACE_INLINE
CORBA_PolicyCurrent_out::CORBA_PolicyCurrent_out (CORBA_PolicyCurrent_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_PolicyCurrent::_nil ();
}

ACE_INLINE
CORBA_PolicyCurrent_out::CORBA_PolicyCurrent_out (const CORBA_PolicyCurrent_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_PolicyCurrent_out&,p).ptr_)
{}

ACE_INLINE CORBA_PolicyCurrent_out &
CORBA_PolicyCurrent_out::operator= (const CORBA_PolicyCurrent_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_PolicyCurrent_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_PolicyCurrent_out &
CORBA_PolicyCurrent_out::operator= (const CORBA_PolicyCurrent_var &p)
{
  this->ptr_ = CORBA_PolicyCurrent::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_PolicyCurrent_out &
CORBA_PolicyCurrent_out::operator= (CORBA_PolicyCurrent_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_PolicyCurrent_out::operator CORBA_PolicyCurrent_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyCurrent_ptr &
CORBA_PolicyCurrent_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_PolicyCurrent_ptr
CORBA_PolicyCurrent_out::operator-> (void)
{
  return this->ptr_;
}

// ****************************************************************

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const CORBA_PolicyError &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._id ())
  {
    // now marshal the members (if any)
    if (
      (strm << _tao_aggregate.reason)
    )
      return 1;
    else
      return 0;
  }
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_PolicyError &_tao_aggregate)
{
  // retrieve  RepoID and verify if we are of that type
  char *_tao_repoID;
  if ((strm >> _tao_repoID) &&
      (_tao_aggregate._is_a (_tao_repoID)))
  {
    // now marshal the members
    if (
      (strm >> _tao_aggregate.reason)
    )
      return 1;
    else
      return 0;
  }
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA_InvalidPolicies::_tao_seq_UShort &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    return strm.write_ushort_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
  }
  return 0; // error
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_InvalidPolicies::_tao_seq_UShort &_tao_sequence)
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements
    return strm.read_ushort_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
  }
  return 0; // error
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const CORBA_InvalidPolicies &_tao_aggregate)
{
  // first marshal the repository ID
  if (strm << _tao_aggregate._id ())
  {
    // now marshal the members (if any)
    if (
      (strm << _tao_aggregate.indices)
    )
      return 1;
    else
      return 0;
  }
  else
    return 0;
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_InvalidPolicies &_tao_aggregate)
{
  // retrieve  RepoID and verify if we are of that type
  char *_tao_repoID;
  if ((strm >> _tao_repoID) &&
      (_tao_aggregate._is_a (_tao_repoID)))
  {
    // now marshal the members
    if (
      (strm >> _tao_aggregate.indices)
    )
      return 1;
    else
      return 0;
  }
  else
    return 0;
}

CORBA::Boolean TAO_Export
operator<< (
    TAO_OutputCDR &,
    const CORBA_Policy_ptr
  );
CORBA::Boolean TAO_Export
operator>> (
    TAO_InputCDR &,
    CORBA_Policy_ptr &
  );


ACE_INLINE CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA_PolicyList &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm << _tao_sequence[i].in ());
    return _tao_marshal_flag;
  }
  return 0; // error
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_PolicyList &_tao_sequence)
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
    return _tao_marshal_flag;
  }
  return 0; // error
}

ACE_INLINE CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA_PolicyTypeSeq &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    return strm.write_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
  }
  return 0; // error
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_PolicyTypeSeq &_tao_sequence)
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements
    return strm.read_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
  }
  return 0; // error
}

ACE_INLINE CORBA::Boolean operator<< (TAO_OutputCDR &strm, const CORBA::SetOverrideType &_tao_enumval)
{
  return strm.write_ulong ((CORBA::ULong) _tao_enumval);
}

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA::SetOverrideType &_tao_enumval)
{
  CORBA::ULong _tao_temp;
  if (strm.read_ulong (_tao_temp))
  {
    ACE_OS::memcpy (&_tao_enumval, &_tao_temp, sizeof (CORBA::ULong));
    return 1;
  }
  else
    return 0;
}
