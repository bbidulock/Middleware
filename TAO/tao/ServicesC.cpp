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
// be\be_codegen.cpp:323


#include "ServicesC.h"
#include "tao/CDR.h"
#include "tao/TypeCode.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "ServicesC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:64

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
CORBA::ServiceDetail::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  ServiceDetail *_tao_tmp_pointer =
    ACE_static_cast (ServiceDetail *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_SERVICEOPTIONSEQ_CS_)
#define _CORBA_SERVICEOPTIONSEQ_CS_

CORBA::ServiceOptionSeq::ServiceOptionSeq (void)
{}

CORBA::ServiceOptionSeq::ServiceOptionSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceOption
      >
    (max)
{}

CORBA::ServiceOptionSeq::ServiceOptionSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ULong * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceOption
      >
    (max, length, buffer, release)
{}

CORBA::ServiceOptionSeq::ServiceOptionSeq (
    const ServiceOptionSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceOption
      >
    (seq)
{}

CORBA::ServiceOptionSeq::~ServiceOptionSeq (void)
{}

void CORBA::ServiceOptionSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ServiceOptionSeq * _tao_tmp_pointer =
    ACE_static_cast (ServiceOptionSeq *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_SERVICEDETAILSEQ_CS_)
#define _CORBA_SERVICEDETAILSEQ_CS_

CORBA::ServiceDetailSeq::ServiceDetailSeq (void)
{}

CORBA::ServiceDetailSeq::ServiceDetailSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceDetail
      >
    (max)
{}

CORBA::ServiceDetailSeq::ServiceDetailSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ServiceDetail * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceDetail
      >
    (max, length, buffer, release)
{}

CORBA::ServiceDetailSeq::ServiceDetailSeq (
    const ServiceDetailSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::ServiceDetail
      >
    (seq)
{}

CORBA::ServiceDetailSeq::~ServiceDetailSeq (void)
{}

void CORBA::ServiceDetailSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ServiceDetailSeq * _tao_tmp_pointer =
    ACE_static_cast (ServiceDetailSeq *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
CORBA::ServiceInformation::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  ServiceInformation *_tao_tmp_pointer =
    ACE_static_cast (ServiceInformation *, _tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceDetail &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.service_detail_type) &&
    (strm << _tao_aggregate.service_detail);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceDetail &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.service_detail_type) &&
    (strm >> _tao_aggregate.service_detail);
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_ServiceOptionSeq_CPP_
#define _TAO_CDR_OP_CORBA_ServiceOptionSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceOptionSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      return strm.write_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceOptionSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return 0;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      return strm.read_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
    }
  
  return 0;
}

#endif /* _TAO_CDR_OP_CORBA_ServiceOptionSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_ServiceDetailSeq_CPP_
#define _TAO_CDR_OP_CORBA_ServiceDetailSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceDetailSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = 1;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceDetailSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return 0;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = 1;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return 0;
}

#endif /* _TAO_CDR_OP_CORBA_ServiceDetailSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::ServiceInformation &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.service_options) &&
    (strm << _tao_aggregate.service_details);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::ServiceInformation &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.service_options) &&
    (strm >> _tao_aggregate.service_details);
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1628

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Var_Var_T<
        CORBA::ServiceDetail
      >;

  template class
    TAO_Var_Base_T<
        CORBA::ServiceDetail
      >;

  template class
    TAO_Out_T<
        CORBA::ServiceDetail,
        CORBA::ServiceDetail_var
      >;

  template class
    TAO_FixedSeq_Var_T<
        CORBA::ServiceOptionSeq,
        CORBA::ServiceOption
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::ServiceOptionSeq,
        CORBA::ServiceOption
      >;

  template class
    TAO_Seq_Out_T<
        CORBA::ServiceOptionSeq,
        CORBA::ServiceOptionSeq_var,
        CORBA::ServiceOption
      >;

  template class
    TAO_VarSeq_Var_T<
        CORBA::ServiceDetailSeq,
        CORBA::ServiceDetail
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::ServiceDetailSeq,
        CORBA::ServiceDetail
      >;

  template class
    TAO_Seq_Out_T<
        CORBA::ServiceDetailSeq,
        CORBA::ServiceDetailSeq_var,
        CORBA::ServiceDetail
      >;

#if !defined (_CORBA_SERVICEDETAIL__EXPLICIT_CS_)
#define _CORBA_SERVICEDETAIL__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        CORBA::ServiceDetail
      >;

#endif /* end #if !defined */

  template class
    TAO_Var_Var_T<
        CORBA::ServiceInformation
      >;

  template class
    TAO_Var_Base_T<
        CORBA::ServiceInformation
      >;

  template class
    TAO_Out_T<
        CORBA::ServiceInformation,
        CORBA::ServiceInformation_var
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_Var_Var_T< \
        CORBA::ServiceDetail \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        CORBA::ServiceDetail \
      >

# pragma instantiate \
    TAO_Out_T< \
        CORBA::ServiceDetail, \
        CORBA::ServiceDetail_var \
      >

# pragma instantiate \
    TAO_FixedSeq_Var_T< \
        CORBA::ServiceOptionSeq, \
        CORBA::ServiceOption \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::ServiceOptionSeq, \
        CORBA::ServiceOption \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        CORBA::ServiceOptionSeq, \
        CORBA::ServiceOptionSeq_var, \
        CORBA::ServiceOption \
      >

# pragma instantiate \
    TAO_VarSeq_Var_T< \
        CORBA::ServiceDetailSeq, \
        CORBA::ServiceDetail \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::ServiceDetailSeq, \
        CORBA::ServiceDetail \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        CORBA::ServiceDetailSeq, \
        CORBA::ServiceDetailSeq_var, \
        CORBA::ServiceDetail \
      >

#if !defined (_CORBA_SERVICEDETAIL__EXPLICIT_CS_)
#define _CORBA_SERVICEDETAIL__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        CORBA::ServiceDetail \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_Var_Var_T< \
        CORBA::ServiceInformation \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        CORBA::ServiceInformation \
      >

# pragma instantiate \
    TAO_Out_T< \
        CORBA::ServiceInformation, \
        CORBA::ServiceInformation_var \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 

