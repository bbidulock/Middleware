// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.5
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 *       http://doc.ece.uci.edu/
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/


// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:70

ACE_INLINE
Coffee::Coffee (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_Coffee_Proxy_Broker_ (0)
{
  this->Coffee_setup_collocation ();
}

ACE_INLINE
Coffee::Coffee (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc)
    , the_TAO_Coffee_Proxy_Broker_ (0)
{
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_array/array_ci.cpp:159

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Fixed_Array_forany>::free (
    Param_Test::Fixed_Array_slice * _tao_slice
  )
{
  Param_Test::Fixed_Array_free (_tao_slice);
}

ACE_INLINE
Param_Test::Fixed_Array_slice *
TAO::Array_Traits<Param_Test::Fixed_Array_forany>::dup (
    const Param_Test::Fixed_Array_slice * _tao_slice
  )
{
  return Param_Test::Fixed_Array_dup (_tao_slice);
}

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Fixed_Array_forany>::copy (
    Param_Test::Fixed_Array_slice * _tao_to,
    const Param_Test::Fixed_Array_slice * _tao_from
  )
{
  Param_Test::Fixed_Array_copy (_tao_to, _tao_from);
}

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Fixed_Array_forany>::zero (
    Param_Test::Fixed_Array_slice * _tao_slice
  )
{
  // Zero each individual element.
  for ( ::CORBA::ULong i0 = 0; i0 < 10; ++i0)
    {
      _tao_slice[i0] = ::CORBA::Long ();
    }
}

ACE_INLINE
Param_Test::Fixed_Array_slice *
TAO::Array_Traits<Param_Test::Fixed_Array_forany>::alloc (void)
{
  return Param_Test::Fixed_Array_alloc ();
}


// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_array/array_ci.cpp:159

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Var_Array_forany>::free (
    Param_Test::Var_Array_slice * _tao_slice
  )
{
  Param_Test::Var_Array_free (_tao_slice);
}

ACE_INLINE
Param_Test::Var_Array_slice *
TAO::Array_Traits<Param_Test::Var_Array_forany>::dup (
    const Param_Test::Var_Array_slice * _tao_slice
  )
{
  return Param_Test::Var_Array_dup (_tao_slice);
}

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Var_Array_forany>::copy (
    Param_Test::Var_Array_slice * _tao_to,
    const Param_Test::Var_Array_slice * _tao_from
  )
{
  Param_Test::Var_Array_copy (_tao_to, _tao_from);
}

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Var_Array_forany>::zero (
    Param_Test::Var_Array_slice * _tao_slice
  )
{
  // Zero each individual element.
  for ( ::CORBA::ULong i0 = 0; i0 < 5; ++i0)
    {
      _tao_slice[i0] = TAO::String_Manager ();
    }
}

ACE_INLINE
Param_Test::Var_Array_slice *
TAO::Array_Traits<Param_Test::Var_Array_forany>::alloc (void)
{
  return Param_Test::Var_Array_alloc ();
}


// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union Param_Test::Big_Union
// *************************************************************

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:165

ACE_INLINE
void 
Param_Test::Big_Union::_default ()
{
  this->_reset ();
  this->disc_ = -32768;
}

// Accessor to set the discriminant.
ACE_INLINE
void
Param_Test::Big_Union::_d ( ::CORBA::Short discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
::CORBA::Short
Param_Test::Big_Union::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:166

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_array (Param_Test::Fixed_Array val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 0;
  // Set the value.
  this->u_.the_array_ = Param_Test::Fixed_Array_dup (val);
}

/// Retrieve the member.
ACE_INLINE
Param_Test::Fixed_Array_slice *
Param_Test::Big_Union::the_array (void) const
{
  return this->u_.the_array_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:305

/// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_interface (Coffee_ptr val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 1;
  typedef Coffee_var OBJECT_FIELD;
  ACE_NEW (
      this->u_.the_interface_,
      OBJECT_FIELD (
          Coffee::_duplicate (val)
        )
    );
}

/// Retrieve the member.
ACE_INLINE
Coffee_ptr 
Param_Test::Big_Union::the_interface (void) const
{
  return this->u_.the_interface_->in ();
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:576

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_long (CORBA::Long val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 2;
  // Set the value.
  this->u_.the_long_ = val;
}

/// Retrieve the member.
ACE_INLINE
::CORBA::Long
Param_Test::Big_Union::the_long (void) const
{
  return this->u_.the_long_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_array/array_ci.cpp:159

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Big_Union::_another_array_forany>::free (
    Param_Test::Big_Union::_another_array_slice * _tao_slice
  )
{
  Param_Test::Big_Union::_another_array_free (_tao_slice);
}

ACE_INLINE
Param_Test::Big_Union::_another_array_slice *
TAO::Array_Traits<Param_Test::Big_Union::_another_array_forany>::dup (
    const Param_Test::Big_Union::_another_array_slice * _tao_slice
  )
{
  return Param_Test::Big_Union::_another_array_dup (_tao_slice);
}

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Big_Union::_another_array_forany>::copy (
    Param_Test::Big_Union::_another_array_slice * _tao_to,
    const Param_Test::Big_Union::_another_array_slice * _tao_from
  )
{
  Param_Test::Big_Union::_another_array_copy (_tao_to, _tao_from);
}

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Big_Union::_another_array_forany>::zero (
    Param_Test::Big_Union::_another_array_slice * _tao_slice
  )
{
  // Zero each individual element.
  for ( ::CORBA::ULong i0 = 0; i0 < 32; ++i0)
    {
      _tao_slice[i0] = ::CORBA::Short ();
    }
}

ACE_INLINE
Param_Test::Big_Union::_another_array_slice *
TAO::Array_Traits<Param_Test::Big_Union::_another_array_forany>::alloc (void)
{
  return Param_Test::Big_Union::_another_array_alloc ();
}


// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:166

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::another_array (Param_Test::Big_Union::_another_array val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 3;
  // Set the value.
  this->u_.another_array_ = Param_Test::Big_Union::_another_array_dup (val);
}

/// Retrieve the member.
ACE_INLINE
Param_Test::Big_Union::_another_array_slice *
Param_Test::Big_Union::another_array (void) const
{
  return this->u_.another_array_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:857

/// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_string (char *val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 4;
  this->u_.the_string_ = val;
}

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_string (const char *val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 4;
  // Set the value.
  this->u_.the_string_ = ::CORBA::string_dup (val);
}

/// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_string (const ::CORBA::String_var &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 4;
  // Set the value.
  ::CORBA::String_var the_string_var = val;
  this->u_.the_string_ = the_string_var._retn ();
}

ACE_INLINE
const char *
Param_Test::Big_Union::the_string (void) const // get method
{
  return this->u_.the_string_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:785

/// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_sequence (const CORBA::ShortSeq &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 5;
  ACE_NEW (
      this->u_.the_sequence_,
      CORBA::ShortSeq (val)
    );
}

/// Readonly get method.
ACE_INLINE
const CORBA::ShortSeq &
Param_Test::Big_Union::the_sequence (void) const
{
  return *this->u_.the_sequence_;
}

/// Read/write get method.
ACE_INLINE
CORBA::ShortSeq &
Param_Test::Big_Union::the_sequence (void)
{
  return *this->u_.the_sequence_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:576

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_any (const ::CORBA::Any & val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 6;
  ACE_NEW (
      this->u_.the_any_,
      ::CORBA::Any (val)
    );
}

/// Retrieve the member.
ACE_INLINE
const ::CORBA::Any &
Param_Test::Big_Union::the_any (void) const
{
  return *this->u_.the_any_;
}

/// Retrieve the member.
ACE_INLINE
::CORBA::Any &
Param_Test::Big_Union::the_any (void)
{
  return *this->u_.the_any_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:576

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_octet (CORBA::Octet val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 7;
  // Set the value.
  this->u_.the_octet_ = val;
}

/// Retrieve the member.
ACE_INLINE
::CORBA::Octet
Param_Test::Big_Union::the_octet (void) const
{
  return this->u_.the_octet_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:576

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_char (CORBA::Char val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 8;
  // Set the value.
  this->u_.the_char_ = val;
}

/// Retrieve the member.
ACE_INLINE
::CORBA::Char
Param_Test::Big_Union::the_char (void) const
{
  return this->u_.the_char_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:576

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_boolean (CORBA::Boolean val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 9;
  // Set the value.
  this->u_.the_boolean_ = val;
}

/// Retrieve the member.
ACE_INLINE
::CORBA::Boolean
Param_Test::Big_Union::the_boolean (void) const
{
  return this->u_.the_boolean_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1058

/// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_var_struct (const Param_Test::Var_Struct &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 10;
  ACE_NEW (
      this->u_.the_var_struct_,
      Param_Test::Var_Struct (val)
    );
}

// Readonly get method.
ACE_INLINE
const Param_Test::Var_Struct &
Param_Test::Big_Union::the_var_struct (void) const
{
  return *this->u_.the_var_struct_;
}

// Read/write get method.
ACE_INLINE
Param_Test::Var_Struct &
Param_Test::Big_Union::the_var_struct (void)
{
  return *this->u_.the_var_struct_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1058

/// Accessor to set the member.
ACE_INLINE
void
Param_Test::Big_Union::the_fixed_struct (const Param_Test::Fixed_Struct &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 11;
  this->u_.the_fixed_struct_ = val;
}

// Readonly get method.
ACE_INLINE
const Param_Test::Fixed_Struct &
Param_Test::Big_Union::the_fixed_struct (void) const
{
  return this->u_.the_fixed_struct_;
}

// Read/write get method.
ACE_INLINE
Param_Test::Fixed_Struct &
Param_Test::Big_Union::the_fixed_struct (void)
{
  return this->u_.the_fixed_struct_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union Param_Test::Small_Union
// *************************************************************

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:71

// Accessor to set the discriminant.
ACE_INLINE
void
Param_Test::Small_Union::_d (Param_Test::Small_Union_Switch discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
Param_Test::Small_Union_Switch
Param_Test::Small_Union::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:576

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Small_Union::the_long (CORBA::Long val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = Param_Test::A_LONG;
  // Set the value.
  this->u_.the_long_ = val;
}

/// Retrieve the member.
ACE_INLINE
::CORBA::Long
Param_Test::Small_Union::the_long (void) const
{
  return this->u_.the_long_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:576

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Small_Union::the_short (CORBA::Short val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = Param_Test::A_SHORT;
  // Set the value.
  this->u_.the_short_ = val;
}

/// Retrieve the member.
ACE_INLINE
::CORBA::Short
Param_Test::Small_Union::the_short (void) const
{
  return this->u_.the_short_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union Param_Test::nested_rec_union
// *************************************************************

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:165

ACE_INLINE
void 
Param_Test::nested_rec_union::_default ()
{
  this->_reset ();
  this->disc_ = -32768;
}

// Accessor to set the discriminant.
ACE_INLINE
void
Param_Test::nested_rec_union::_d ( ::CORBA::Short discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
::CORBA::Short
Param_Test::nested_rec_union::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:576

// Accessor to set the member.
ACE_INLINE
void
Param_Test::nested_rec_union::value (CORBA::Long val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 0;
  // Set the value.
  this->u_.value_ = val;
}

/// Retrieve the member.
ACE_INLINE
::CORBA::Long
Param_Test::nested_rec_union::value (void) const
{
  return this->u_.value_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:785

/// Accessor to set the member.
ACE_INLINE
void
Param_Test::nested_rec_union::nested_rec_member (const Param_Test::nested_rec_union::_tao_seq_Param_Test_nested_rec_union_ &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 1;
  ACE_NEW (
      this->u_.nested_rec_member_,
      Param_Test::nested_rec_union::_tao_seq_Param_Test_nested_rec_union_ (val)
    );
}

/// Readonly get method.
ACE_INLINE
const Param_Test::nested_rec_union::_tao_seq_Param_Test_nested_rec_union_ &
Param_Test::nested_rec_union::nested_rec_member (void) const
{
  return *this->u_.nested_rec_member_;
}

/// Read/write get method.
ACE_INLINE
Param_Test::nested_rec_union::_tao_seq_Param_Test_nested_rec_union_ &
Param_Test::nested_rec_union::nested_rec_member (void)
{
  return *this->u_.nested_rec_member_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union/union_ci.cpp:51

// *************************************************************
// Inline operations for union Param_Test::Recursive_Union
// *************************************************************

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union/discriminant_ci.cpp:165

ACE_INLINE
void 
Param_Test::Recursive_Union::_default ()
{
  this->_reset ();
  this->disc_ = -32768;
}

// Accessor to set the discriminant.
ACE_INLINE
void
Param_Test::Recursive_Union::_d ( ::CORBA::Short discval)
{
  this->disc_ = discval;
}

// Accessor to get the discriminant.
ACE_INLINE
::CORBA::Short
Param_Test::Recursive_Union::_d (void) const
{
  return this->disc_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:785

/// Accessor to set the member.
ACE_INLINE
void
Param_Test::Recursive_Union::rec_member (const Param_Test::Recursive_Union::_tao_seq_Param_Test_Recursive_Union_ &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 0;
  ACE_NEW (
      this->u_.rec_member_,
      Param_Test::Recursive_Union::_tao_seq_Param_Test_Recursive_Union_ (val)
    );
}

/// Readonly get method.
ACE_INLINE
const Param_Test::Recursive_Union::_tao_seq_Param_Test_Recursive_Union_ &
Param_Test::Recursive_Union::rec_member (void) const
{
  return *this->u_.rec_member_;
}

/// Read/write get method.
ACE_INLINE
Param_Test::Recursive_Union::_tao_seq_Param_Test_Recursive_Union_ &
Param_Test::Recursive_Union::rec_member (void)
{
  return *this->u_.rec_member_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_union_branch/public_ci.cpp:1214

// Accessor to set the member.
ACE_INLINE
void
Param_Test::Recursive_Union::nested_member (const Param_Test::nested_rec_union &val)
{
  // Set the discriminant value.
  this->_reset ();
  this->disc_ = 1;
  ACE_NEW (
      this->u_.nested_member_,
      Param_Test::nested_rec_union (val)
    );
}

// Readonly get method.
ACE_INLINE
const Param_Test::nested_rec_union &
Param_Test::Recursive_Union::nested_member (void) const
{
  return *this->u_.nested_member_;
}

// Read/write get method.
ACE_INLINE
Param_Test::nested_rec_union &
Param_Test::Recursive_Union::nested_member (void)
{
  return *this->u_.nested_member_;
}

// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_array/array_ci.cpp:159

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Multdim_Array_forany>::free (
    Param_Test::Multdim_Array_slice * _tao_slice
  )
{
  Param_Test::Multdim_Array_free (_tao_slice);
}

ACE_INLINE
Param_Test::Multdim_Array_slice *
TAO::Array_Traits<Param_Test::Multdim_Array_forany>::dup (
    const Param_Test::Multdim_Array_slice * _tao_slice
  )
{
  return Param_Test::Multdim_Array_dup (_tao_slice);
}

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Multdim_Array_forany>::copy (
    Param_Test::Multdim_Array_slice * _tao_to,
    const Param_Test::Multdim_Array_slice * _tao_from
  )
{
  Param_Test::Multdim_Array_copy (_tao_to, _tao_from);
}

ACE_INLINE
void
TAO::Array_Traits<Param_Test::Multdim_Array_forany>::zero (
    Param_Test::Multdim_Array_slice * _tao_slice
  )
{
  // Zero each individual element.
  for ( ::CORBA::ULong i0 = 0; i0 < 5; ++i0)
    {
      for ( ::CORBA::ULong i1 = 0; i1 < 3; ++i1)
        {
          // call the underlying _zero
          TAO::Array_Traits< Param_Test::Fixed_Array_forany>::zero (_tao_slice[i0][i1]);
        }
    }
}

ACE_INLINE
Param_Test::Multdim_Array_slice *
TAO::Array_Traits<Param_Test::Multdim_Array_forany>::alloc (void)
{
  return Param_Test::Multdim_Array_alloc ();
}


// TAO_IDL - Generated from
// w:\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:70

ACE_INLINE
Param_Test::Param_Test (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_Param_Test_Proxy_Broker_ (0)
{
  this->Param_Test_setup_collocation ();
}

ACE_INLINE
Param_Test::Param_Test (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ::CORBA::Object (ior, oc)
    , the_TAO_Param_Test_Proxy_Broker_ (0)
{
}

