/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

ACE_INLINE
CORBA_DomainManager::CORBA_DomainManager (void) // default constructor
{}

ACE_INLINE
CORBA_DomainManager::CORBA_DomainManager (TAO_Stub *objref,
                                     TAO_ServantBase *_tao_servant,
                                     CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_DomainManager::~CORBA_DomainManager (void) // destructor
{}


// *************************************************************
// Inline operations for class CORBA::DomainManager_var
// *************************************************************

ACE_INLINE
CORBA_DomainManager_var::CORBA_DomainManager_var (void) // default constructor
  : ptr_ (CORBA::DomainManager::_nil ())
{}

ACE_INLINE CORBA::DomainManager_ptr
CORBA_DomainManager_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DomainManager_var::CORBA_DomainManager_var (const CORBA::DomainManager_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (CORBA::DomainManager::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_DomainManager_var::~CORBA_DomainManager_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA::DomainManager_var &
CORBA_DomainManager_var::operator= (CORBA::DomainManager_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA::DomainManager_var &
CORBA_DomainManager_var::operator= (const CORBA::DomainManager_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA::DomainManager::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
CORBA_DomainManager_var::operator const CORBA::DomainManager_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DomainManager_var::operator CORBA::DomainManager_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr
CORBA_DomainManager_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr
CORBA_DomainManager_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr &
CORBA_DomainManager_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr &
CORBA_DomainManager_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DomainManager::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA::DomainManager_ptr
CORBA_DomainManager_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_DomainManager_ptr val = this->ptr_;
  this->ptr_ = CORBA_DomainManager::_nil ();
  return val;
}

// *************************************************************
// Inline operations for class CORBA::DomainManager_out
// *************************************************************

ACE_INLINE
CORBA_DomainManager_out::CORBA_DomainManager_out (CORBA_DomainManager_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA::DomainManager::_nil ();
}

ACE_INLINE
CORBA_DomainManager_out::CORBA_DomainManager_out (CORBA_DomainManager_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_DomainManager::_nil ();
}

ACE_INLINE
CORBA_DomainManager_out::CORBA_DomainManager_out (const CORBA_DomainManager_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DomainManager_out&,p).ptr_)
{}

ACE_INLINE CORBA_DomainManager_out &
CORBA_DomainManager_out::operator= (const CORBA_DomainManager_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA::DomainManager_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_DomainManager_out &
CORBA_DomainManager_out::operator= (const CORBA_DomainManager_var &p)
{
  this->ptr_ = CORBA::DomainManager::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_DomainManager_out &
CORBA_DomainManager_out::operator= (CORBA_DomainManager_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_DomainManager_out::operator CORBA_DomainManager_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_DomainManager_ptr &
CORBA_DomainManager_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_DomainManager_ptr
CORBA_DomainManager_out::operator-> (void)
{
  return this->ptr_;
}

#if (TAO_HAS_MINIMUM_CORBA == 0)

ACE_INLINE
CORBA_ConstructionPolicy::CORBA_ConstructionPolicy (void) // default constructor
{}

ACE_INLINE
CORBA_ConstructionPolicy::CORBA_ConstructionPolicy (TAO_Stub *objref, TAO_ServantBase *_tao_servant, CORBA::Boolean _tao_collocated) // constructor
  : CORBA_Object (objref, _tao_servant, _tao_collocated)
{}

ACE_INLINE
CORBA_ConstructionPolicy::~CORBA_ConstructionPolicy (void) // destructor
{}

ACE_INLINE CORBA::ConstructionPolicy_ptr
CORBA_ConstructionPolicy::_nil (void)
{
  return (CORBA_ConstructionPolicy_ptr)0;
}

// *************************************************************
// Inline operations for class CORBA::ConstructionPolicy_var
// *************************************************************

ACE_INLINE
CORBA_ConstructionPolicy_var::CORBA_ConstructionPolicy_var (void) // default constructor
  : ptr_ (CORBA_ConstructionPolicy::_nil ())
{}

ACE_INLINE
CORBA_ConstructionPolicy_var::CORBA_ConstructionPolicy_var (CORBA_ConstructionPolicy_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA_ConstructionPolicy_ptr
CORBA_ConstructionPolicy_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA_ConstructionPolicy_var::CORBA_ConstructionPolicy_var (const CORBA_ConstructionPolicy_var &p) // copy constructor
  : TAO_Base_var (),
    ptr_ (CORBA_ConstructionPolicy::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA_ConstructionPolicy_var::~CORBA_ConstructionPolicy_var (void) // destructor
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA_ConstructionPolicy_var &
CORBA_ConstructionPolicy_var::operator= (CORBA_ConstructionPolicy_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_ConstructionPolicy_var &
CORBA_ConstructionPolicy_var::operator= (const CORBA_ConstructionPolicy_var &p)
{
  if (this != &p)
  {
    CORBA::release (this->ptr_);
    this->ptr_ = CORBA_ConstructionPolicy::_duplicate (p.ptr ());
  }
  return *this;
}

ACE_INLINE
CORBA_ConstructionPolicy_var::operator const CORBA_ConstructionPolicy_ptr &() const // cast
{
  return this->ptr_;
}

ACE_INLINE
CORBA_ConstructionPolicy_var::operator CORBA_ConstructionPolicy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_ConstructionPolicy_ptr
CORBA_ConstructionPolicy_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_ConstructionPolicy_ptr
CORBA_ConstructionPolicy_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_ConstructionPolicy_ptr &
CORBA_ConstructionPolicy_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA_ConstructionPolicy_ptr &
CORBA_ConstructionPolicy_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_ConstructionPolicy::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA_ConstructionPolicy_ptr
CORBA_ConstructionPolicy_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA_ConstructionPolicy_ptr val = this->ptr_;
  this->ptr_ = CORBA_ConstructionPolicy::_nil ();
  return val;
}

// *************************************************************
// Inline operations for class CORBA::ConstructionPolicy_out
// *************************************************************

ACE_INLINE
CORBA_ConstructionPolicy_out::CORBA_ConstructionPolicy_out (CORBA_ConstructionPolicy_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA_ConstructionPolicy::_nil ();
}

ACE_INLINE
CORBA_ConstructionPolicy_out::CORBA_ConstructionPolicy_out (CORBA_ConstructionPolicy_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA_ConstructionPolicy::_nil ();
}

ACE_INLINE
CORBA_ConstructionPolicy_out::CORBA_ConstructionPolicy_out (const CORBA_ConstructionPolicy_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_ConstructionPolicy_out&,p).ptr_)
{}

ACE_INLINE CORBA_ConstructionPolicy_out &
CORBA_ConstructionPolicy_out::operator= (const CORBA_ConstructionPolicy_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_ConstructionPolicy_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_ConstructionPolicy_out &
CORBA_ConstructionPolicy_out::operator= (const CORBA_ConstructionPolicy_var &p)
{
  this->ptr_ = CORBA::ConstructionPolicy::_duplicate (p.ptr ());
  return *this;
}

ACE_INLINE CORBA_ConstructionPolicy_out &
CORBA_ConstructionPolicy_out::operator= (CORBA_ConstructionPolicy_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_ConstructionPolicy_out::operator CORBA_ConstructionPolicy_ptr &() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_ConstructionPolicy_ptr &
CORBA_ConstructionPolicy_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_ConstructionPolicy_ptr
CORBA_ConstructionPolicy_out::operator-> (void)
{
  return this->ptr_;
}


#endif /* ! defined (TAO_HAS_MINIMUM_CORBA) */

// *************************************************************
// Inline operations for class CORBA::DomainManagerList_var
// *************************************************************

ACE_INLINE
CORBA_DomainManagerList_var::CORBA_DomainManagerList_var (void) // default constructor
  : ptr_ (0)
{}

ACE_INLINE
CORBA_DomainManagerList_var::CORBA_DomainManagerList_var (CORBA_DomainManagerList *p)
  : ptr_ (p)
{}

ACE_INLINE
CORBA_DomainManagerList_var::CORBA_DomainManagerList_var (const CORBA_DomainManagerList_var &p) // copy constructor
{
  if (p.ptr_)
    ACE_NEW (this->ptr_, CORBA_DomainManagerList(*p.ptr_));
  else
    this->ptr_ = 0;
}

ACE_INLINE
CORBA_DomainManagerList_var::~CORBA_DomainManagerList_var (void) // destructor
{
  delete this->ptr_;
}

ACE_INLINE CORBA_DomainManagerList_var &
CORBA_DomainManagerList_var::operator= (CORBA_DomainManagerList *p)
{
  delete this->ptr_;
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA_DomainManagerList_var &
CORBA_DomainManagerList_var::operator= (const CORBA_DomainManagerList_var &p) // deep copy
{
  if (this != &p)
  {
    delete this->ptr_;
    ACE_NEW_RETURN (this->ptr_, 
                    CORBA_DomainManagerList (*p.ptr_), 
		    *this);
  }
  return *this;
}

ACE_INLINE const CORBA_DomainManagerList *
CORBA_DomainManagerList_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA_DomainManagerList *
CORBA_DomainManagerList_var::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE
CORBA_DomainManagerList_var::operator const CORBA_DomainManagerList &() const // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_DomainManagerList_var::operator CORBA_DomainManagerList &() // cast
{
  return *this->ptr_;
}

ACE_INLINE
CORBA_DomainManagerList_var::operator CORBA_DomainManagerList &() const// cast
{
  return *this->ptr_;
}

ACE_INLINE TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var>
CORBA_DomainManagerList_var::operator[] (CORBA::ULong slot)
{
  return this->ptr_->operator[] (slot);
}

ACE_INLINE const CORBA_DomainManagerList &
CORBA_DomainManagerList_var::in (void) const
{
  return *this->ptr_;
}

ACE_INLINE CORBA_DomainManagerList &
CORBA_DomainManagerList_var::inout (void)
{
  return *this->ptr_;
}

// mapping for variable size
ACE_INLINE CORBA_DomainManagerList *&
CORBA_DomainManagerList_var::out (void)
{
  delete this->ptr_;
  this->ptr_ = 0;
  return this->ptr_;
}

ACE_INLINE CORBA_DomainManagerList *
CORBA_DomainManagerList_var::_retn (void)
{
  CORBA_DomainManagerList *tmp = this->ptr_;
  this->ptr_ = 0;
  return tmp;
}

ACE_INLINE CORBA_DomainManagerList *
CORBA::DomainManagerList_var::ptr (void) const
{
  return this->ptr_;
}

// *************************************************************
// Inline operations for class CORBA::DomainManagerList_out
// *************************************************************

ACE_INLINE
CORBA_DomainManagerList_out::CORBA_DomainManagerList_out (CORBA_DomainManagerList *&p)
  : ptr_ (p)
{
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_DomainManagerList_out::CORBA_DomainManagerList_out (CORBA_DomainManagerList_var &p) // constructor from _var
  : ptr_ (p.out ())
{
  delete this->ptr_;
  this->ptr_ = 0;
}

ACE_INLINE
CORBA_DomainManagerList_out::CORBA_DomainManagerList_out (const CORBA_DomainManagerList_out &p) // copy constructor
  : ptr_ (ACE_const_cast (CORBA_DomainManagerList_out&,p).ptr_)
{}

ACE_INLINE CORBA_DomainManagerList_out &
CORBA_DomainManagerList_out::operator= (const CORBA_DomainManagerList_out &p)
{
  this->ptr_ = ACE_const_cast (CORBA_DomainManagerList_out&,p).ptr_;
  return *this;
}

ACE_INLINE CORBA_DomainManagerList_out &
CORBA_DomainManagerList_out::operator= (CORBA_DomainManagerList *p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA_DomainManagerList_out::operator CORBA_DomainManagerList *&() // cast
{
  return this->ptr_;
}

ACE_INLINE CORBA_DomainManagerList *&
CORBA_DomainManagerList_out::ptr (void) // ptr
{
  return this->ptr_;
}

ACE_INLINE CORBA_DomainManagerList *
CORBA_DomainManagerList_out::operator-> (void)
{
  return this->ptr_;
}

ACE_INLINE TAO_Object_Manager<CORBA_DomainManager,CORBA_DomainManager_var>
CORBA_DomainManagerList_out::operator[] (CORBA::ULong slot)
{
  return this->ptr_->operator[] (slot);
}

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &,
    const CORBA_DomainManager_ptr
  );
ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &,
    CORBA_DomainManager_ptr &
  );

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA_DomainManager_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA_DomainManager_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      CORBA_DomainManager::_unchecked_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

#if (TAO_HAS_MINIMUM_CORBA == 0)

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &,
    const CORBA_ConstructionPolicy_ptr
  );
ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &,
    CORBA::ConstructionPolicy_ptr &
  );

ACE_INLINE CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA_ConstructionPolicy_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

ACE_INLINE CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA_ConstructionPolicy_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      CORBA_ConstructionPolicy::_unchecked_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

#endif /* ! defined (TAO_HAS_MINIMUM_CORBA) */

ACE_INLINE CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA_DomainManagerList &_tao_sequence
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

ACE_INLINE CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA_DomainManagerList &_tao_sequence)
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
