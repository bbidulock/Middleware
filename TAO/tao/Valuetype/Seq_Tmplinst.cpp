// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO
//
// = FILENAME
//    Seq_Tmplinst.cpp
//
// = DESCRIPTION
//   Explicit instantiation of the TAO sequence template classes for ValueBase
//   and AbstractBase. These instantiations free us from having to
//   generate them over and over with the IDL compiler.
//
// = AUTHOR
//     Jeff Parsons <j.parsons@vanderbilt.edu>
//
// ============================================================================

#include "tao/Sequence_T.h"
#include "tao/Any.h"

ACE_RCSID (tao, 
           Seq_Tmplinst, 
           "$Id$")

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class TAO_Valuetype_Manager<CORBA::ValueBase,
                                     CORBA::ValueBase_var,
                                     CORBA::tao_ValueBase_life>;
template class TAO_Unbounded_Valuetype_Sequence<CORBA::ValueBase, 
                                                CORBA::ValueBase_var, 
                                                CORBA::tao_ValueBase_life>;
template class TAO_Unbounded_Pseudo_Sequence<CORBA::AbstractBase, 
                                             CORBA::AbstractBase_var>;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#pragma instantiate TAO_Valuetype_Manager<CORBA::ValueBase,
                                          CORBA::ValueBase_var,
                                          CORBA::tao_ValueBase_life>
#pragma instantiate TAO_Unbounded_Valuetype_Sequence<CORBA::ValueBase, \
                                                     CORBA::ValueBase_var, \
                                                     CORBA::tao_ValueBase_life>
#pragma instantiate TAO_Unbounded_Pseudo_Sequence<CORBA::AbstractBase, \
                                                  CORBA::AbstractBase_var>

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

