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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_IROBJECT___CI_)
#define _CORBA_IROBJECT___CI_

ACE_INLINE
CORBA::IRObject::IRObject (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_IRObject_Proxy_Broker_ (0)
{
  this->CORBA_IRObject_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::IRObject::IRObject (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_IRObject_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_CONTAINED___CI_)
#define _CORBA_CONTAINED___CI_

ACE_INLINE
CORBA::Contained::Contained (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_Contained_Proxy_Broker_ (0)
{
  this->CORBA_Contained_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::Contained::Contained (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_Contained_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_CONTAINER___CI_)
#define _CORBA_CONTAINER___CI_

ACE_INLINE
CORBA::Container::Container (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_Container_Proxy_Broker_ (0)
{
  this->CORBA_Container_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::Container::Container (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_Container_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_IDLTYPE___CI_)
#define _CORBA_IDLTYPE___CI_

ACE_INLINE
CORBA::IDLType::IDLType (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_IDLType_Proxy_Broker_ (0)
{
  this->CORBA_IDLType_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::IDLType::IDLType (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_IDLType_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ci.cpp:70

#if !defined (_CORBA_TYPEDEFDEF___CI_)
#define _CORBA_TYPEDEFDEF___CI_

ACE_INLINE
CORBA::TypedefDef::TypedefDef (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_TypedefDef_Proxy_Broker_ (0)
{
  this->CORBA_TypedefDef_setup_collocation (_tao_collocated);
}

ACE_INLINE
CORBA::TypedefDef::TypedefDef (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_TypedefDef_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_enum/cdr_op_ci.cpp:51

ACE_INLINE
CORBA::Boolean operator<< (TAO_OutputCDR &strm, const CORBA::DefinitionKind &_tao_enumval)
{
  CORBA::ULong _tao_temp = _tao_enumval;
  return strm << _tao_temp;
}

ACE_INLINE
CORBA::Boolean operator>> (TAO_InputCDR &strm, CORBA::DefinitionKind &_tao_enumval)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean _tao_result = strm >> _tao_temp;
  
  if (_tao_result == 1)
    {
      _tao_enumval = ACE_static_cast (CORBA::DefinitionKind, _tao_temp);
    }
  
  return _tao_result;
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::IRObject_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::IRObject_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::Contained_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::Contained_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::Repository_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::Repository_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::Container_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::Container_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::Contained::Description &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.kind) &&
    (strm << _tao_aggregate.value);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::Contained::Description &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.kind) &&
    (strm >> _tao_aggregate.value);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ModuleDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ModuleDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ConstantDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ConstantDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::IDLType_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::IDLType_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::StructDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::StructDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::UnionDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::UnionDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::EnumDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::EnumDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::AliasDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::AliasDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::InterfaceDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::InterfaceDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_InterfaceDefSeq_I_
#define _TAO_CDR_OP_CORBA_InterfaceDefSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::InterfaceDefSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::InterfaceDefSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_InterfaceDefSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ExceptionDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ExceptionDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::NativeDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::NativeDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ValueDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ValueDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ValueDefSeq_I_
#define _TAO_CDR_OP_CORBA_ValueDefSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ValueDefSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ValueDefSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ValueDefSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ValueBoxDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ValueBoxDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::AbstractInterfaceDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::AbstractInterfaceDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_AbstractInterfaceDefSeq_I_
#define _TAO_CDR_OP_CORBA_AbstractInterfaceDefSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::AbstractInterfaceDefSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::AbstractInterfaceDefSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_AbstractInterfaceDefSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::LocalInterfaceDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::LocalInterfaceDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_LocalInterfaceDefSeq_I_
#define _TAO_CDR_OP_CORBA_LocalInterfaceDefSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::LocalInterfaceDefSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::LocalInterfaceDefSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_LocalInterfaceDefSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtInterfaceDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ExtInterfaceDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ExtInterfaceDefSeq_I_
#define _TAO_CDR_OP_CORBA_ExtInterfaceDefSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtInterfaceDefSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ExtInterfaceDefSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ExtInterfaceDefSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtValueDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ExtValueDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ExtValueDefSeq_I_
#define _TAO_CDR_OP_CORBA_ExtValueDefSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtValueDefSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ExtValueDefSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ExtValueDefSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtAbstractInterfaceDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ExtAbstractInterfaceDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ExtAbstractInterfaceDefSeq_I_
#define _TAO_CDR_OP_CORBA_ExtAbstractInterfaceDefSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtAbstractInterfaceDefSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ExtAbstractInterfaceDefSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ExtAbstractInterfaceDefSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface_fwd/cdr_op_ci.cpp:59

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtLocalInterfaceDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::ExtLocalInterfaceDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ExtLocalInterfaceDefSeq_I_
#define _TAO_CDR_OP_CORBA_ExtLocalInterfaceDefSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtLocalInterfaceDefSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ExtLocalInterfaceDefSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ExtLocalInterfaceDefSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ContainedSeq_I_
#define _TAO_CDR_OP_CORBA_ContainedSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ContainedSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ContainedSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ContainedSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::StructMember &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.type.in ()) &&
    CORBA::Object::marshal (
        _tao_aggregate.type_def.in (),
        strm
      );
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::StructMember &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.name.out ()) &&
    (strm >> _tao_aggregate.type.out ()) &&
    (strm >> _tao_aggregate.type_def.out ());
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_StructMemberSeq_I_
#define _TAO_CDR_OP_CORBA_StructMemberSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::StructMemberSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::StructMemberSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_StructMemberSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::Initializer &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.members) &&
    (strm << _tao_aggregate.name.in ());
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::Initializer &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.members) &&
    (strm >> _tao_aggregate.name.out ());
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_InitializerSeq_I_
#define _TAO_CDR_OP_CORBA_InitializerSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::InitializerSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::InitializerSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_InitializerSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ExceptionDescription &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.id.in ()) &&
    (strm << _tao_aggregate.defined_in.in ()) &&
    (strm << _tao_aggregate.version.in ()) &&
    (strm << _tao_aggregate.type.in ());
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ExceptionDescription &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.name.out ()) &&
    (strm >> _tao_aggregate.id.out ()) &&
    (strm >> _tao_aggregate.defined_in.out ()) &&
    (strm >> _tao_aggregate.version.out ()) &&
    (strm >> _tao_aggregate.type.out ());
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ExcDescriptionSeq_I_
#define _TAO_CDR_OP_CORBA_ExcDescriptionSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ExcDescriptionSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ExcDescriptionSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ExcDescriptionSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ExtInitializer &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.members) &&
    (strm << _tao_aggregate.exceptions) &&
    (strm << _tao_aggregate.name.in ());
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ExtInitializer &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.members) &&
    (strm >> _tao_aggregate.exceptions) &&
    (strm >> _tao_aggregate.name.out ());
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_ExtInitializerSeq_I_
#define _TAO_CDR_OP_CORBA_ExtInitializerSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::ExtInitializerSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::ExtInitializerSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_ExtInitializerSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::UnionMember &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.label) &&
    (strm << _tao_aggregate.type.in ()) &&
    CORBA::Object::marshal (
        _tao_aggregate.type_def.in (),
        strm
      );
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::UnionMember &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.name.out ()) &&
    (strm >> _tao_aggregate.label) &&
    (strm >> _tao_aggregate.type.out ()) &&
    (strm >> _tao_aggregate.type_def.out ());
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_UnionMemberSeq_I_
#define _TAO_CDR_OP_CORBA_UnionMemberSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::UnionMemberSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::UnionMemberSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_UnionMemberSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_EnumMemberSeq_I_
#define _TAO_CDR_OP_CORBA_EnumMemberSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::EnumMemberSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::EnumMemberSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_EnumMemberSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::Container::Description &_tao_aggregate
  )
{
  return
    CORBA::Object::marshal (
        _tao_aggregate.contained_object.in (),
        strm
      ) &&
    (strm << _tao_aggregate.kind) &&
    (strm << _tao_aggregate.value);
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::Container::Description &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.contained_object.out ()) &&
    (strm >> _tao_aggregate.kind) &&
    (strm >> _tao_aggregate.value);
}

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_CORBA_Container_DescriptionSeq_I_
#define _TAO_CDR_OP_CORBA_Container_DescriptionSeq_I_

CORBA::Boolean TAO_IFR_Client_Export operator<< (
    TAO_OutputCDR &,
    const CORBA::Container::DescriptionSeq &
  );

CORBA::Boolean TAO_IFR_Client_Export operator>> (
    TAO_InputCDR &,
    CORBA::Container::DescriptionSeq &
  );

#endif /* _TAO_CDR_OP_CORBA_Container_DescriptionSeq_I_ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ci.cpp:72

TAO_IFR_Client_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const CORBA::TypedefDef_ptr
  );

TAO_IFR_Client_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    CORBA::TypedefDef_ptr &
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_structure/cdr_op_ci.cpp:70

ACE_INLINE
CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::TypeDescription &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.name.in ()) &&
    (strm << _tao_aggregate.id.in ()) &&
    (strm << _tao_aggregate.defined_in.in ()) &&
    (strm << _tao_aggregate.version.in ()) &&
    (strm << _tao_aggregate.type.in ());
}

ACE_INLINE
CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::TypeDescription &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.name.out ()) &&
    (strm >> _tao_aggregate.id.out ()) &&
    (strm >> _tao_aggregate.defined_in.out ()) &&
    (strm >> _tao_aggregate.version.out ()) &&
    (strm >> _tao_aggregate.type.out ());
}

