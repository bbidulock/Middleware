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
// be/be_codegen.cpp:302


#include "FP_SchedulingC.h"
#include "tao/Typecode.h"
#include "tao/Any_Impl_T.h"
#include "ace/OS_NS_string.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "FP_SchedulingC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:60

// Arg traits specializations.
namespace TAO
{
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for FP_Scheduling::SegmentSchedulingParameterPolicy.

FP_Scheduling::SegmentSchedulingParameterPolicy_ptr
TAO::Objref_Traits<FP_Scheduling::SegmentSchedulingParameterPolicy>::tao_duplicate (
    FP_Scheduling::SegmentSchedulingParameterPolicy_ptr p
  )
{
  return FP_Scheduling::SegmentSchedulingParameterPolicy::_duplicate (p);
}

void
TAO::Objref_Traits<FP_Scheduling::SegmentSchedulingParameterPolicy>::tao_release (
    FP_Scheduling::SegmentSchedulingParameterPolicy_ptr p
  )
{
  CORBA::release (p);
}

FP_Scheduling::SegmentSchedulingParameterPolicy_ptr
TAO::Objref_Traits<FP_Scheduling::SegmentSchedulingParameterPolicy>::tao_nil (void)
{
  return FP_Scheduling::SegmentSchedulingParameterPolicy::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<FP_Scheduling::SegmentSchedulingParameterPolicy>::tao_marshal (
    FP_Scheduling::SegmentSchedulingParameterPolicy_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker *
(*FP_Scheduling__TAO_SegmentSchedulingParameterPolicy_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

FP_Scheduling::SegmentSchedulingParameterPolicy::SegmentSchedulingParameterPolicy (void)
{}

FP_Scheduling::SegmentSchedulingParameterPolicy::~SegmentSchedulingParameterPolicy (void)
{}

void
FP_Scheduling::SegmentSchedulingParameterPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  SegmentSchedulingParameterPolicy *_tao_tmp_pointer =
    static_cast<SegmentSchedulingParameterPolicy *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

FP_Scheduling::SegmentSchedulingParameterPolicy_ptr
FP_Scheduling::SegmentSchedulingParameterPolicy::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return SegmentSchedulingParameterPolicy::_nil ();
    }

  SegmentSchedulingParameterPolicy_ptr proxy =
    dynamic_cast<SegmentSchedulingParameterPolicy_ptr> (_tao_objref);

  return SegmentSchedulingParameterPolicy::_duplicate (proxy);
}

FP_Scheduling::SegmentSchedulingParameterPolicy_ptr
FP_Scheduling::SegmentSchedulingParameterPolicy::_duplicate (SegmentSchedulingParameterPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

CORBA::Boolean
FP_Scheduling::SegmentSchedulingParameterPolicy::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:FP_Scheduling/SegmentSchedulingParameterPolicy:1.0"
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

const char* FP_Scheduling::SegmentSchedulingParameterPolicy::_interface_repository_id (void) const
{
  return "IDL:FP_Scheduling/SegmentSchedulingParameterPolicy:1.0";
}

CORBA::Boolean
FP_Scheduling::SegmentSchedulingParameterPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_FP_Scheduling_SegmentSchedulingParameterPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  55,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x46505f53),
  ACE_NTOHL (0x63686564),
  ACE_NTOHL (0x756c696e),
  ACE_NTOHL (0x672f5365),
  ACE_NTOHL (0x676d656e),
  ACE_NTOHL (0x74536368),
  ACE_NTOHL (0x6564756c),
  ACE_NTOHL (0x696e6750),
  ACE_NTOHL (0x6172616d),
  ACE_NTOHL (0x65746572),
  ACE_NTOHL (0x506f6c69),
  ACE_NTOHL (0x63793a31),
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:FP_Scheduling/SegmentSchedulingParameterPolicy:1.0
    33,
  ACE_NTOHL (0x5365676d), 
  ACE_NTOHL (0x656e7453), 
  ACE_NTOHL (0x63686564), 
  ACE_NTOHL (0x756c696e), 
  ACE_NTOHL (0x67506172), 
  ACE_NTOHL (0x616d6574), 
  ACE_NTOHL (0x6572506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x0),  // name = SegmentSchedulingParameterPolicy
  };

static CORBA::TypeCode _tc_TAO_tc_FP_Scheduling_SegmentSchedulingParameterPolicy (
    CORBA::tk_objref,
    sizeof (_oc_FP_Scheduling_SegmentSchedulingParameterPolicy),
    (char *) &_oc_FP_Scheduling_SegmentSchedulingParameterPolicy,
    0,
    sizeof (FP_Scheduling::SegmentSchedulingParameterPolicy)
  );

namespace FP_Scheduling
{
  ::CORBA::TypeCode_ptr _tc_SegmentSchedulingParameterPolicy =
    &_tc_TAO_tc_FP_Scheduling_SegmentSchedulingParameterPolicy;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for FP_Scheduling::FP_Scheduler.

FP_Scheduling::FP_Scheduler_ptr
TAO::Objref_Traits<FP_Scheduling::FP_Scheduler>::tao_duplicate (
    FP_Scheduling::FP_Scheduler_ptr p
  )
{
  return FP_Scheduling::FP_Scheduler::_duplicate (p);
}

void
TAO::Objref_Traits<FP_Scheduling::FP_Scheduler>::tao_release (
    FP_Scheduling::FP_Scheduler_ptr p
  )
{
  CORBA::release (p);
}

FP_Scheduling::FP_Scheduler_ptr
TAO::Objref_Traits<FP_Scheduling::FP_Scheduler>::tao_nil (void)
{
  return FP_Scheduling::FP_Scheduler::_nil ();
}

CORBA::Boolean
TAO::Objref_Traits<FP_Scheduling::FP_Scheduler>::tao_marshal (
    FP_Scheduling::FP_Scheduler_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return p->marshal (cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*FP_Scheduling__TAO_FP_Scheduler_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  ) = 0;

FP_Scheduling::FP_Scheduler::FP_Scheduler (void)
{}

FP_Scheduling::FP_Scheduler::~FP_Scheduler (void)
{}

void 
FP_Scheduling::FP_Scheduler::_tao_any_destructor (void *_tao_void_pointer)
{
  FP_Scheduler *_tao_tmp_pointer =
    static_cast<FP_Scheduler *> (_tao_void_pointer);
  CORBA::release (_tao_tmp_pointer);
}

FP_Scheduling::FP_Scheduler_ptr
FP_Scheduling::FP_Scheduler::_narrow (
    CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (_tao_objref))
    {
      return FP_Scheduler::_nil ();
    }
  
  FP_Scheduler_ptr proxy =
    dynamic_cast<FP_Scheduler_ptr> (_tao_objref);
  
  return FP_Scheduler::_duplicate (proxy);
}

FP_Scheduling::FP_Scheduler_ptr
FP_Scheduling::FP_Scheduler::_duplicate (FP_Scheduler_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

CORBA::Boolean
FP_Scheduling::FP_Scheduler::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:RTScheduling/Scheduler:1.0"
        ) ||
      !ACE_OS::strcmp (
          (char *)value,
          "IDL:FP_Scheduling/FP_Scheduler:1.0"
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

const char* FP_Scheduling::FP_Scheduler::_interface_repository_id (void) const
{
  return "IDL:FP_Scheduling/FP_Scheduler:1.0";
}

CORBA::Boolean
FP_Scheduling::FP_Scheduler::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_FP_Scheduling_FP_Scheduler[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  35,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x46505f53), 
  ACE_NTOHL (0x63686564), 
  ACE_NTOHL (0x756c696e), 
  ACE_NTOHL (0x672f4650), 
  ACE_NTOHL (0x5f536368), 
  ACE_NTOHL (0x6564756c), 
  ACE_NTOHL (0x65723a31), 
  ACE_NTOHL (0x2e300000),  // repository ID = IDL:FP_Scheduling/FP_Scheduler:1.0
    13,
  ACE_NTOHL (0x46505f53), 
  ACE_NTOHL (0x63686564), 
  ACE_NTOHL (0x756c6572), 
  ACE_NTOHL (0x0),  // name = FP_Scheduler
  };

static CORBA::TypeCode _tc_TAO_tc_FP_Scheduling_FP_Scheduler (
    CORBA::tk_objref,
    sizeof (_oc_FP_Scheduling_FP_Scheduler),
    (char *) &_oc_FP_Scheduling_FP_Scheduler,
    0,
    sizeof (FP_Scheduling::FP_Scheduler)
  );

namespace FP_Scheduling
{
  ::CORBA::TypeCode_ptr _tc_FP_Scheduler =
    &_tc_TAO_tc_FP_Scheduling_FP_Scheduler;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<FP_Scheduling::SegmentSchedulingParameterPolicy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<FP_Scheduling::SegmentSchedulingParameterPolicy>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<FP_Scheduling::SegmentSchedulingParameterPolicy>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    FP_Scheduling::SegmentSchedulingParameterPolicy_ptr _tao_elem
  )
{
  FP_Scheduling::SegmentSchedulingParameterPolicy_ptr _tao_objptr =
    FP_Scheduling::SegmentSchedulingParameterPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    FP_Scheduling::SegmentSchedulingParameterPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<FP_Scheduling::SegmentSchedulingParameterPolicy>::insert (
      _tao_any,
      FP_Scheduling::SegmentSchedulingParameterPolicy::_tao_any_destructor,
      FP_Scheduling::_tc_SegmentSchedulingParameterPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    FP_Scheduling::SegmentSchedulingParameterPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<FP_Scheduling::SegmentSchedulingParameterPolicy>::extract (
        _tao_any,
        FP_Scheduling::SegmentSchedulingParameterPolicy::_tao_any_destructor,
        FP_Scheduling::_tc_SegmentSchedulingParameterPolicy,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<FP_Scheduling::FP_Scheduler>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<FP_Scheduling::FP_Scheduler>::marshal_value (TAO_OutputCDR &)
{
  return 0;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<FP_Scheduling::FP_Scheduler>::demarshal_value (TAO_InputCDR &)
{
  return 0;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    FP_Scheduling::FP_Scheduler_ptr _tao_elem
  )
{
  FP_Scheduling::FP_Scheduler_ptr _tao_objptr =
    FP_Scheduling::FP_Scheduler::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    FP_Scheduling::FP_Scheduler_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<FP_Scheduling::FP_Scheduler>::insert (
      _tao_any,
      FP_Scheduling::FP_Scheduler::_tao_any_destructor,
      FP_Scheduling::_tc_FP_Scheduler,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    FP_Scheduling::FP_Scheduler_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<FP_Scheduling::FP_Scheduler>::extract (
        _tao_any,
        FP_Scheduling::FP_Scheduler::_tao_any_destructor,
        FP_Scheduling::_tc_FP_Scheduler,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:1702

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Objref_Traits<
        FP_Scheduling::SegmentSchedulingParameterPolicy
      >;

  template class
    TAO_Objref_Var_T<
        FP_Scheduling::SegmentSchedulingParameterPolicy
      >;
  
  template class
    TAO_Objref_Out_T<
        FP_Scheduling::SegmentSchedulingParameterPolicy
      >;

  template class
    TAO::Any_Impl_T<
        FP_Scheduling::SegmentSchedulingParameterPolicy
      >;

  template class
    TAO::Objref_Traits<
        FP_Scheduling::FP_Scheduler
      >;

  template class
    TAO_Objref_Var_T<
        FP_Scheduling::FP_Scheduler
      >;
  
  template class
    TAO_Objref_Out_T<
        FP_Scheduling::FP_Scheduler
      >;

  template class
    TAO::Any_Impl_T<
        FP_Scheduling::FP_Scheduler
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Objref_Traits< \
        FP_Scheduling::SegmentSchedulingParameterPolicy \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        FP_Scheduling::SegmentSchedulingParameterPolicy
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        FP_Scheduling::SegmentSchedulingParameterPolicy
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        FP_Scheduling::SegmentSchedulingParameterPolicy \
      >

# pragma instantiate \
    TAO::Objref_Traits< \
        FP_Scheduling::FP_Scheduler \
      >

# pragma instantiate \
    TAO_Objref_Var_T< \
        FP_Scheduling::FP_Scheduler
      >
  
# pragma instantiate \
    TAO_Objref_Out_T< \
        FP_Scheduling::FP_Scheduler
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        FP_Scheduling::FP_Scheduler \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

