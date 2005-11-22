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
// be\be_codegen.cpp:288


#include "IIOPC.h"
#include "tao/CDR.h"

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_structure/structure_cs.cpp:66

void
IIOP::ListenPoint::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  ListenPoint *_tao_tmp_pointer =
    static_cast<ListenPoint *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IIOP_LISTENPOINTLIST_CS_)
#define _IIOP_LISTENPOINTLIST_CS_

IIOP::ListenPointList::ListenPointList (void)
{}

IIOP::ListenPointList::ListenPointList (
    CORBA::ULong max
  )
  : TAO::unbounded_value_sequence<
        ListenPoint
      >
    (max)
{}

IIOP::ListenPointList::ListenPointList (
    CORBA::ULong max,
    CORBA::ULong length,
    IIOP::ListenPoint * buffer,
    CORBA::Boolean release
  )
  : TAO::unbounded_value_sequence<
        ListenPoint
      >
    (max, length, buffer, release)
{}

IIOP::ListenPointList::ListenPointList (
    const ListenPointList &seq
  )
  : TAO::unbounded_value_sequence<
        ListenPoint
      >
    (seq)
{}

IIOP::ListenPointList::~ListenPointList (void)
{}

void IIOP::ListenPointList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ListenPointList * _tao_tmp_pointer =
    static_cast<ListenPointList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_structure/structure_cs.cpp:66

void
IIOP::BiDirIIOPServiceContext::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  BiDirIIOPServiceContext *_tao_tmp_pointer =
    static_cast<BiDirIIOPServiceContext *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IIOP::ListenPoint &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.host.in ()) &&
    (strm << _tao_aggregate.port);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IIOP::ListenPoint &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.host.out ()) &&
    (strm >> _tao_aggregate.port);
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_IIOP_ListenPointList_CPP_
#define _TAO_CDR_OP_IIOP_ListenPointList_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IIOP::ListenPointList &_tao_sequence
  )
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IIOP::ListenPointList &_tao_sequence
  )
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}

#endif /* _TAO_CDR_OP_IIOP_ListenPointList_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IIOP::BiDirIIOPServiceContext &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.listen_points);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IIOP::BiDirIIOPServiceContext &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.listen_points);
}
