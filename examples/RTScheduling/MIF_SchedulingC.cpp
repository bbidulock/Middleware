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
// be/be_codegen.cpp:351


#include "MIF_SchedulingC.h"
#include "tao/Stub.h"
#include "tao/Invocation.h"
#include "tao/PortableInterceptor.h"

#if TAO_HAS_INTERCEPTORS == 1
#include "tao/RequestInfo_Util.h"
#include "tao/ClientRequestInfo_i.h"
#include "tao/ClientInterceptorAdapter.h"
#endif  /* TAO_HAS_INTERCEPTORS == 1 */


#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "MIF_SchedulingC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:63

int MIF_Scheduling::SegmentSchedulingParameterPolicy::_tao_class_id = 0;

MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr
MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_life::tao_duplicate (
    SegmentSchedulingParameterPolicy_ptr p
  )
{
  return SegmentSchedulingParameterPolicy::_duplicate (p);
}

void
MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_life::tao_release (
    SegmentSchedulingParameterPolicy_ptr p
  )
{
  CORBA::release (p);
}

MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr
MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_life::tao_nil (
    void
  )
{
  return SegmentSchedulingParameterPolicy::_nil ();
}

CORBA::Boolean
MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_life::tao_marshal (
    SegmentSchedulingParameterPolicy_ptr p,
    TAO_OutputCDR &cdr
  )
{
  return p->marshal (cdr);
}

MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr
MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_cast::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return SegmentSchedulingParameterPolicy::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_cast::tao_upcast (
    void *src
  )
{
  SegmentSchedulingParameterPolicy **tmp =
    ACE_static_cast (SegmentSchedulingParameterPolicy **, src);
  return *tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class
    TAO_Objref_Var_T<
        MIF_Scheduling::SegmentSchedulingParameterPolicy,
        MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_life
      >;
  template class
    TAO_Objref_Out_T<
        MIF_Scheduling::SegmentSchedulingParameterPolicy,
        MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_life
      >;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate \
    TAO_Objref_Var_T< \
        MIF_Scheduling::SegmentSchedulingParameterPolicy, \
        MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_life \
      >
# pragma instantiate \
    TAO_Objref_Out_T< \
        MIF_Scheduling::SegmentSchedulingParameterPolicy, \
        MIF_Scheduling::tao_SegmentSchedulingParameterPolicy_life \
      >
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from 
// be/be_visitor_interface/interface_cs.cpp:245

MIF_Scheduling::SegmentSchedulingParameterPolicy::SegmentSchedulingParameterPolicy (void)
{}

MIF_Scheduling::SegmentSchedulingParameterPolicy::~SegmentSchedulingParameterPolicy (void)
{}

void 
MIF_Scheduling::SegmentSchedulingParameterPolicy::_tao_any_destructor (void *_tao_void_pointer)
{
  SegmentSchedulingParameterPolicy *tmp = ACE_static_cast (SegmentSchedulingParameterPolicy *, _tao_void_pointer);
  CORBA::release (tmp);
}

MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr
MIF_Scheduling::SegmentSchedulingParameterPolicy::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return SegmentSchedulingParameterPolicy::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr 
MIF_Scheduling::SegmentSchedulingParameterPolicy::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return SegmentSchedulingParameterPolicy::_nil ();
    }
  
  return
      ACE_reinterpret_cast (
          SegmentSchedulingParameterPolicy_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptrdiff_t,
                  &SegmentSchedulingParameterPolicy::_tao_class_id
                )
            )
        );
}

MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr
MIF_Scheduling::SegmentSchedulingParameterPolicy::_duplicate (SegmentSchedulingParameterPolicy_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void *MIF_Scheduling::SegmentSchedulingParameterPolicy::_tao_QueryInterface (ptrdiff_t type)
{
  void *retv = 0;
  
  if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &ACE_NESTED_CLASS (::MIF_Scheduling, SegmentSchedulingParameterPolicy)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &::CORBA::Policy::_tao_class_id)
            )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (
                CORBA::Policy_ptr,
                this
              )
          );
    }
  else if (type == ACE_reinterpret_cast (
               ptrdiff_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }
  
  if (retv != 0)
    {
      this->_add_ref ();
    }
  
  return retv;
}

const char* MIF_Scheduling::SegmentSchedulingParameterPolicy::_interface_repository_id (void) const
{
  return "IDL:MIF_Scheduling/SegmentSchedulingParameterPolicy:1.0";
}

CORBA::Boolean
MIF_Scheduling::SegmentSchedulingParameterPolicy::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_MIF_Scheduling_SegmentSchedulingParameterPolicy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  56,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x4d49465f), 
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c69), 
  ACE_NTOHL (0x6e672f53), 
  ACE_NTOHL (0x65676d65), 
  ACE_NTOHL (0x6e745363), 
  ACE_NTOHL (0x68656475), 
  ACE_NTOHL (0x6c696e67), 
  ACE_NTOHL (0x50617261), 
  ACE_NTOHL (0x6d657465), 
  ACE_NTOHL (0x72506f6c), 
  ACE_NTOHL (0x6963793a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:MIF_Scheduling/SegmentSchedulingParameterPolicy:1.0
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

static CORBA::TypeCode _tc_TAO_tc_MIF_Scheduling_SegmentSchedulingParameterPolicy (
    CORBA::tk_objref,
    sizeof (_oc_MIF_Scheduling_SegmentSchedulingParameterPolicy),
    (char *) &_oc_MIF_Scheduling_SegmentSchedulingParameterPolicy,
    0,
    sizeof (MIF_Scheduling::SegmentSchedulingParameterPolicy)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (MIF_Scheduling)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_SegmentSchedulingParameterPolicy,
    &_tc_TAO_tc_MIF_Scheduling_SegmentSchedulingParameterPolicy
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:63

int MIF_Scheduling::MIF_Scheduler::_tao_class_id = 0;

MIF_Scheduling::MIF_Scheduler_ptr
MIF_Scheduling::tao_MIF_Scheduler_life::tao_duplicate (
    MIF_Scheduler_ptr p
  )
{
  return MIF_Scheduler::_duplicate (p);
}

void
MIF_Scheduling::tao_MIF_Scheduler_life::tao_release (
    MIF_Scheduler_ptr p
  )
{
  CORBA::release (p);
}

MIF_Scheduling::MIF_Scheduler_ptr
MIF_Scheduling::tao_MIF_Scheduler_life::tao_nil (
    void
  )
{
  return MIF_Scheduler::_nil ();
}

CORBA::Boolean
MIF_Scheduling::tao_MIF_Scheduler_life::tao_marshal (
    MIF_Scheduler_ptr p,
    TAO_OutputCDR &cdr
  )
{
  return p->marshal (cdr);
}

MIF_Scheduling::MIF_Scheduler_ptr
MIF_Scheduling::tao_MIF_Scheduler_cast::tao_narrow (
    CORBA::Object *p
    ACE_ENV_ARG_DECL
  )
{
  return MIF_Scheduler::_narrow (p ACE_ENV_ARG_PARAMETER);
}

CORBA::Object *
MIF_Scheduling::tao_MIF_Scheduler_cast::tao_upcast (
    void *src
  )
{
  MIF_Scheduler **tmp =
    ACE_static_cast (MIF_Scheduler **, src);
  return *tmp;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class
    TAO_Objref_Var_T<
        MIF_Scheduling::MIF_Scheduler,
        MIF_Scheduling::tao_MIF_Scheduler_life
      >;
  template class
    TAO_Objref_Out_T<
        MIF_Scheduling::MIF_Scheduler,
        MIF_Scheduling::tao_MIF_Scheduler_life
      >;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate \
    TAO_Objref_Var_T< \
        MIF_Scheduling::MIF_Scheduler, \
        MIF_Scheduling::tao_MIF_Scheduler_life \
      >
# pragma instantiate \
    TAO_Objref_Out_T< \
        MIF_Scheduling::MIF_Scheduler, \
        MIF_Scheduling::tao_MIF_Scheduler_life \
      >
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from 
// be/be_visitor_interface/interface_cs.cpp:245

MIF_Scheduling::MIF_Scheduler::MIF_Scheduler (void)
{}

MIF_Scheduling::MIF_Scheduler::~MIF_Scheduler (void)
{}

void 
MIF_Scheduling::MIF_Scheduler::_tao_any_destructor (void *_tao_void_pointer)
{
  MIF_Scheduler *tmp = ACE_static_cast (MIF_Scheduler *, _tao_void_pointer);
  CORBA::release (tmp);
}

MIF_Scheduling::MIF_Scheduler_ptr
MIF_Scheduling::MIF_Scheduler::_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL
  )
{
  return MIF_Scheduler::_unchecked_narrow (obj ACE_ENV_ARG_PARAMETER);
}

MIF_Scheduling::MIF_Scheduler_ptr 
MIF_Scheduling::MIF_Scheduler::_unchecked_narrow (
    CORBA::Object_ptr obj
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (CORBA::is_nil (obj))
    {
      return MIF_Scheduler::_nil ();
    }
  
  return
      ACE_reinterpret_cast (
          MIF_Scheduler_ptr,
          obj->_tao_QueryInterface (
              ACE_reinterpret_cast (
                  ptrdiff_t,
                  &MIF_Scheduler::_tao_class_id
                )
            )
        );
}

MIF_Scheduling::MIF_Scheduler_ptr
MIF_Scheduling::MIF_Scheduler::_duplicate (MIF_Scheduler_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void *MIF_Scheduling::MIF_Scheduler::_tao_QueryInterface (ptrdiff_t type)
{
  void *retv = 0;
  
  if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &ACE_NESTED_CLASS (::MIF_Scheduling, MIF_Scheduler)::_tao_class_id)
            )
    {
      retv = ACE_reinterpret_cast (void*, this);
    }
  else if (type == ACE_reinterpret_cast (
              ptrdiff_t,
              &::RTScheduling::Scheduler::_tao_class_id)
            )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (
                RTScheduling::Scheduler_ptr,
                this
              )
          );
    }
  else if (type == ACE_reinterpret_cast (
               ptrdiff_t,
               &CORBA::Object::_tao_class_id)
             )
    {
      retv =
        ACE_reinterpret_cast (
            void *,
            ACE_static_cast (CORBA::Object_ptr, this)
          );
    }
  
  if (retv != 0)
    {
      this->_add_ref ();
    }
  
  return retv;
}

const char* MIF_Scheduling::MIF_Scheduler::_interface_repository_id (void) const
{
  return "IDL:MIF_Scheduling/MIF_Scheduler:1.0";
}

CORBA::Boolean
MIF_Scheduling::MIF_Scheduler::marshal (TAO_OutputCDR &)
{
  return 0;
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_MIF_Scheduling_MIF_Scheduler[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  37,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x4d49465f), 
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c69), 
  ACE_NTOHL (0x6e672f4d), 
  ACE_NTOHL (0x49465f53), 
  ACE_NTOHL (0x63686564), 
  ACE_NTOHL (0x756c6572), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:MIF_Scheduling/MIF_Scheduler:1.0
    14,
  ACE_NTOHL (0x4d49465f), 
  ACE_NTOHL (0x53636865), 
  ACE_NTOHL (0x64756c65), 
  ACE_NTOHL (0x72000000),  // name = MIF_Scheduler
  };

static CORBA::TypeCode _tc_TAO_tc_MIF_Scheduling_MIF_Scheduler (
    CORBA::tk_objref,
    sizeof (_oc_MIF_Scheduling_MIF_Scheduler),
    (char *) &_oc_MIF_Scheduling_MIF_Scheduler,
    0,
    sizeof (MIF_Scheduling::MIF_Scheduler)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (MIF_Scheduling)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_MIF_Scheduler,
    &_tc_TAO_tc_MIF_Scheduling_MIF_Scheduler
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr _tao_elem
  )
{
  MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr _tao_objptr =
    MIF_Scheduling::SegmentSchedulingParameterPolicy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<MIF_Scheduling::SegmentSchedulingParameterPolicy>::insert (
      _tao_any,
      MIF_Scheduling::SegmentSchedulingParameterPolicy::_tao_any_destructor,
      MIF_Scheduling::_tc_SegmentSchedulingParameterPolicy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    MIF_Scheduling::SegmentSchedulingParameterPolicy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<MIF_Scheduling::SegmentSchedulingParameterPolicy>::extract (
        _tao_any,
        MIF_Scheduling::SegmentSchedulingParameterPolicy::_tao_any_destructor,
        MIF_Scheduling::_tc_SegmentSchedulingParameterPolicy,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Impl_T<MIF_Scheduling::SegmentSchedulingParameterPolicy>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Impl_T<MIF_Scheduling::SegmentSchedulingParameterPolicy>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:50

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::MIF_Scheduler_ptr _tao_elem
  )
{
  MIF_Scheduling::MIF_Scheduler_ptr _tao_objptr =
    MIF_Scheduling::MIF_Scheduler::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    MIF_Scheduling::MIF_Scheduler_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<MIF_Scheduling::MIF_Scheduler>::insert (
      _tao_any,
      MIF_Scheduling::MIF_Scheduler::_tao_any_destructor,
      MIF_Scheduling::_tc_MIF_Scheduler,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    MIF_Scheduling::MIF_Scheduler_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<MIF_Scheduling::MIF_Scheduler>::extract (
        _tao_any,
        MIF_Scheduling::MIF_Scheduler::_tao_any_destructor,
        MIF_Scheduling::_tc_MIF_Scheduler,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Impl_T<MIF_Scheduling::MIF_Scheduler>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Impl_T<MIF_Scheduling::MIF_Scheduler>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

