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
// be\be_codegen.cpp:302


#include "Dynamic_ParameterC.h"
#include "tao/CDR.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Dynamic_ParameterC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:66

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
Dynamic::Parameter::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  Parameter *_tao_tmp_pointer =
    static_cast<Parameter *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const Dynamic::Parameter &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.argument) &&
    (strm << _tao_aggregate.mode);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    Dynamic::Parameter &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.argument) &&
    (strm >> _tao_aggregate.mode);
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1509

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Var_Var_T<
        Dynamic::Parameter
      >;

  template class
    TAO_Var_Base_T<
        Dynamic::Parameter
      >;

  template class
    TAO_Out_T<
        Dynamic::Parameter,
        Dynamic::Parameter_var
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_Var_Var_T< \
        Dynamic::Parameter \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        Dynamic::Parameter \
      >

# pragma instantiate \
    TAO_Out_T< \
        Dynamic::Parameter, \
        Dynamic::Parameter_var \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
