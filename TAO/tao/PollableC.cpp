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
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:301


#include "PollableC.h"
#include "ace/OS.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "PollableC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_arg_traits.cpp:59

// Arg traits specializations.
namespace TAO
{

#if !defined (_CORBA_POLLABLESET__ARG_TRAITS_CS_)
#define _CORBA_POLLABLESET__ARG_TRAITS_CS_

  ACE_TEMPLATE_SPECIALIZATION
  class TAO_Export Arg_Traits<CORBA::PollableSet>
    : public
        Object_Arg_Traits_T<
            CORBA::PollableSet_ptr,
            CORBA::PollableSet_var,
            CORBA::PollableSet_out,
            TAO::Objref_Traits<CORBA::PollableSet>
          >
  {
  };

#endif /* end #if !defined */

#if !defined (_CORBA_POLLABLE__ARG_TRAITS_CS_)
#define _CORBA_POLLABLE__ARG_TRAITS_CS_

  ACE_TEMPLATE_SPECIALIZATION
  class TAO_Export Arg_Traits<CORBA::Pollable>
    : public
        Object_Arg_Traits_T<
            CORBA::Pollable_ptr,
            CORBA::Pollable_var,
            CORBA::Pollable_out,
            TAO::Objref_Traits<CORBA::Pollable>
          >
  {
  };

#endif /* end #if !defined */

#if !defined (_CORBA_DIIPOLLABLE__ARG_TRAITS_CS_)
#define _CORBA_DIIPOLLABLE__ARG_TRAITS_CS_

  ACE_TEMPLATE_SPECIALIZATION
  class TAO_Export Arg_Traits<CORBA::DIIPollable>
    : public
        Object_Arg_Traits_T<
            CORBA::DIIPollable_ptr,
            CORBA::DIIPollable_var,
            CORBA::DIIPollable_out,
            TAO::Objref_Traits<CORBA::DIIPollable>
          >
  {
  };

#endif /* end #if !defined */

#if !defined (_CORBA_POLLABLESET__ARG_TRAITS_CS_)
#define _CORBA_POLLABLESET__ARG_TRAITS_CS_

  ACE_TEMPLATE_SPECIALIZATION
  class TAO_Export Arg_Traits<CORBA::PollableSet>
    : public
        Object_Arg_Traits_T<
            CORBA::PollableSet_ptr,
            CORBA::PollableSet_var,
            CORBA::PollableSet_out,
            TAO::Objref_Traits<CORBA::PollableSet>
          >
  {
  };

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::Pollable.

CORBA::Pollable_ptr
TAO::Objref_Traits<CORBA::Pollable>::tao_duplicate (
    CORBA::Pollable_ptr p
  )
{
  return CORBA::Pollable::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::Pollable>::tao_release (
    CORBA::Pollable_ptr p
  )
{
  CORBA::release (p);
}

CORBA::Pollable_ptr
TAO::Objref_Traits<CORBA::Pollable>::tao_nil (void)
{
  return CORBA::Pollable::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<CORBA::Pollable>::tao_marshal (
    CORBA::Pollable_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*CORBA__TAO_Pollable_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

CORBA::Pollable::Pollable (void)
{}

CORBA::Pollable::~Pollable (void)
{}

CORBA::Pollable_ptr
CORBA::Pollable::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return Pollable::_nil ();
    }

  Pollable_ptr proxy =
    dynamic_cast<Pollable_ptr> (_tao_objref);

  return Pollable::_duplicate (proxy);
}

CORBA::Pollable_ptr
CORBA::Pollable::_duplicate (Pollable_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
CORBA::Pollable::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Pollable:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* CORBA::Pollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Pollable:1.0";
}

CORBA::Boolean
CORBA::Pollable::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::DIIPollable.

CORBA::DIIPollable_ptr
TAO::Objref_Traits<CORBA::DIIPollable>::tao_duplicate (
    CORBA::DIIPollable_ptr p
  )
{
  return CORBA::DIIPollable::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::DIIPollable>::tao_release (
    CORBA::DIIPollable_ptr p
  )
{
  CORBA::release (p);
}

CORBA::DIIPollable_ptr
TAO::Objref_Traits<CORBA::DIIPollable>::tao_nil (void)
{
  return CORBA::DIIPollable::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<CORBA::DIIPollable>::tao_marshal (
    CORBA::DIIPollable_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*CORBA__TAO_DIIPollable_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

CORBA::DIIPollable::DIIPollable (void)
{}

CORBA::DIIPollable::~DIIPollable (void)
{}

CORBA::DIIPollable_ptr
CORBA::DIIPollable::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return DIIPollable::_nil ();
    }

  DIIPollable_ptr proxy =
    dynamic_cast<DIIPollable_ptr> (_tao_objref);

  return DIIPollable::_duplicate (proxy);
}

CORBA::DIIPollable_ptr
CORBA::DIIPollable::_duplicate (DIIPollable_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
CORBA::DIIPollable::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Pollable:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/DIIPollable:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* CORBA::DIIPollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/DIIPollable:1.0";
}

CORBA::Boolean
CORBA::DIIPollable::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_cs.cpp:60

// Traits specializations for CORBA::PollableSet.

CORBA::PollableSet_ptr
TAO::Objref_Traits<CORBA::PollableSet>::tao_duplicate (
    CORBA::PollableSet_ptr p
  )
{
  return CORBA::PollableSet::_duplicate (p);
}

void
TAO::Objref_Traits<CORBA::PollableSet>::tao_release (
    CORBA::PollableSet_ptr p
  )
{
  CORBA::release (p);
}

CORBA::PollableSet_ptr
TAO::Objref_Traits<CORBA::PollableSet>::tao_nil (void)
{
  return CORBA::PollableSet::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<CORBA::PollableSet>::tao_marshal (
    CORBA::PollableSet_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*CORBA__TAO_PollableSet_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_cs.cpp:63

CORBA::PollableSet::NoPossiblePollable::NoPossiblePollable (void)
  : CORBA::UserException (
        "IDL:omg.org/CORBA/PollableSet/NoPossiblePollable:1.0",
        "NoPossiblePollable"
      )
{
}

CORBA::PollableSet::NoPossiblePollable::~NoPossiblePollable (void)
{
}

CORBA::PollableSet::NoPossiblePollable::NoPossiblePollable (const ::CORBA::PollableSet::NoPossiblePollable &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

CORBA::PollableSet::NoPossiblePollable&
CORBA::PollableSet::NoPossiblePollable::operator= (const ::CORBA::PollableSet::NoPossiblePollable &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

CORBA::PollableSet::NoPossiblePollable *
CORBA::PollableSet::NoPossiblePollable::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/PollableSet/NoPossiblePollable:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (NoPossiblePollable *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *CORBA::PollableSet::NoPossiblePollable::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::PollableSet::NoPossiblePollable, 0);
  return retval;
}

CORBA::Exception *
CORBA::PollableSet::NoPossiblePollable::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::CORBA::PollableSet::NoPossiblePollable (*this),
      0
    );
  return result;
}

void CORBA::PollableSet::NoPossiblePollable::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::PollableSet::NoPossiblePollable::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA::PollableSet::NoPossiblePollable::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}



// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_cs.cpp:63

CORBA::PollableSet::UnknownPollable::UnknownPollable (void)
  : CORBA::UserException (
        "IDL:omg.org/CORBA/PollableSet/UnknownPollable:1.0",
        "UnknownPollable"
      )
{
}

CORBA::PollableSet::UnknownPollable::~UnknownPollable (void)
{
}

CORBA::PollableSet::UnknownPollable::UnknownPollable (const ::CORBA::PollableSet::UnknownPollable &_tao_excp)
  : CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

CORBA::PollableSet::UnknownPollable&
CORBA::PollableSet::UnknownPollable::operator= (const ::CORBA::PollableSet::UnknownPollable &_tao_excp)
{
  this->ACE_NESTED_CLASS (CORBA, UserException)::operator= (_tao_excp);
  return *this;
}

CORBA::PollableSet::UnknownPollable *
CORBA::PollableSet::UnknownPollable::_downcast (CORBA::Exception *_tao_excp)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/PollableSet/UnknownPollable:1.0", _tao_excp->_rep_id ()))
    {
      return ACE_dynamic_cast (UnknownPollable *, _tao_excp);
    }
  else
    {
      return 0;
    }
}

CORBA::Exception *CORBA::PollableSet::UnknownPollable::_alloc (void)
{
  CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::CORBA::PollableSet::UnknownPollable, 0);
  return retval;
}

CORBA::Exception *
CORBA::PollableSet::UnknownPollable::_tao_duplicate (void) const
{
  CORBA::Exception *result;
  ACE_NEW_RETURN (
      result,
      ::CORBA::PollableSet::UnknownPollable (*this),
      0
    );
  return result;
}

void CORBA::PollableSet::UnknownPollable::_raise (void) const
{
  TAO_RAISE (*this);
}

void CORBA::PollableSet::UnknownPollable::_tao_encode (
    TAO_OutputCDR &
    ACE_ENV_ARG_DECL
  ) const
{
  ACE_THROW (CORBA::MARSHAL ());
}

void CORBA::PollableSet::UnknownPollable::_tao_decode (
    TAO_InputCDR &
    ACE_ENV_ARG_DECL
  )
{
  ACE_THROW (CORBA::MARSHAL ());
}



CORBA::PollableSet::PollableSet (void)
{}

CORBA::PollableSet::~PollableSet (void)
{}

CORBA::PollableSet_ptr
CORBA::PollableSet::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return PollableSet::_nil ();
    }

  PollableSet_ptr proxy =
    dynamic_cast<PollableSet_ptr> (_tao_objref);

  return PollableSet::_duplicate (proxy);
}

CORBA::PollableSet_ptr
CORBA::PollableSet::_duplicate (PollableSet_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
CORBA::PollableSet::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/PollableSet:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
     )
    {
      return 1; // success using local knowledge
    }
  else
    {
      return 0;
    }
}

const char* CORBA::PollableSet::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PollableSet:1.0";
}

CORBA::Boolean
CORBA::PollableSet::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:1703

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#if !defined (_CORBA_POLLABLESET__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLLABLESET__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<CORBA::PollableSet>;

  template class
    TAO::Object_Arg_Traits_T<
        CORBA::PollableSet_ptr,
        CORBA::PollableSet_var,
        CORBA::PollableSet_out
      >;

#endif /* end #if !defined */

  template class
    TAO::Ret_Object_Argument_T<
        CORBA::DIIPollable_ptr,
        CORBA::DIIPollable_var
      >;

  template class
    TAO::In_Object_Argument_T<
        CORBA::Pollable_ptr
      >;

  template class
    TAO::Ret_Object_Argument_T<
        CORBA::Pollable_ptr,
        CORBA::Pollable_var
      >;

  template class
    TAO_Objref_Var_T<
        CORBA::PollableSet,
        TAO::Objref_Traits<CORBA::PollableSet>
      >;

  template class
    TAO_Objref_Out_T<
        CORBA::PollableSet,
        TAO::Objref_Traits<CORBA::PollableSet>
      >;

#if !defined (_CORBA_POLLABLE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLLABLE__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<CORBA::Pollable>;

  template class
    TAO::Object_Arg_Traits_T<
        CORBA::Pollable_ptr,
        CORBA::Pollable_var,
        CORBA::Pollable_out
      >;

#endif /* end #if !defined */

  template class
    TAO::Ret_Object_Argument_T<
        CORBA::PollableSet_ptr,
        CORBA::PollableSet_var
      >;

  template class
    TAO_Objref_Var_T<
        CORBA::Pollable,
        TAO::Objref_Traits<CORBA::Pollable>
      >;

  template class
    TAO_Objref_Out_T<
        CORBA::Pollable,
        TAO::Objref_Traits<CORBA::Pollable>
      >;

#if !defined (_CORBA_DIIPOLLABLE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_DIIPOLLABLE__ARG_TRAITS_TMPLINST_CS_

  template class TAO::Arg_Traits<CORBA::DIIPollable>;

  template class
    TAO::Object_Arg_Traits_T<
        CORBA::DIIPollable_ptr,
        CORBA::DIIPollable_var,
        CORBA::DIIPollable_out
      >;

#endif /* end #if !defined */

  template class
    TAO_Objref_Var_T<
        CORBA::DIIPollable,
        TAO::Objref_Traits<CORBA::DIIPollable>
      >;

  template class
    TAO_Objref_Out_T<
        CORBA::DIIPollable,
        TAO::Objref_Traits<CORBA::DIIPollable>
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#if !defined (_CORBA_POLLABLESET__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLLABLESET__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<CORBA::PollableSet>

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        CORBA::PollableSet_ptr, \
        CORBA::PollableSet_var, \
        CORBA::PollableSet_out \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO::In_Object_Argument_T< \
        CORBA::Pollable_ptr \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::PollableSet, \
        TAO::Objref_Traits<CORBA::PollableSet> \
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::PollableSet, \
        TAO::Objref_Traits<CORBA::PollableSet> \
      >

#if !defined (_CORBA_POLLABLE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_POLLABLE__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<CORBA::Pollable>

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        CORBA::Pollable_ptr, \
        CORBA::Pollable_var, \
        CORBA::Pollable_out \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::Pollable, \
        TAO::Objref_Traits<CORBA::Pollable> \
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::Pollable, \
        TAO::Objref_Traits<CORBA::Pollable> \
      >

#if !defined (_CORBA_DIIPOLLABLE__ARG_TRAITS_TMPLINST_CS_)
#define _CORBA_DIIPOLLABLE__ARG_TRAITS_TMPLINST_CS_

# pragma instantiate TAO::Arg_Traits<CORBA::DIIPollable>

# pragma instantiate \
    TAO::Object_Arg_Traits_T< \
        CORBA::DIIPollable_ptr, \
        CORBA::DIIPollable_var, \
        CORBA::DIIPollable_out \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_Objref_Var_T< \
        CORBA::DIIPollable, \
        TAO::Objref_Traits<CORBA::DIIPollable> \
      >

# pragma instantiate \
    TAO_Objref_Out_T< \
        CORBA::DIIPollable, \
        TAO::Objref_Traits<CORBA::DIIPollable> \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
