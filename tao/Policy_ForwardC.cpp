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
// be\be_codegen.cpp:291


#include "Policy_ForwardC.h"
#include "tao/CDR.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Policy_ForwardC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:69

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_POLICYLIST_CS_)
#define _CORBA_POLICYLIST_CS_

CORBA::PolicyList::PolicyList (void)
{}

CORBA::PolicyList::PolicyList (
    CORBA::ULong max
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::Policy,
        CORBA::Policy_var
      >
    (max)
{}

CORBA::PolicyList::PolicyList (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Policy_ptr * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::Policy,
        CORBA::Policy_var
      >
    (max, length, buffer, release)
{}

CORBA::PolicyList::PolicyList (
    const PolicyList &seq
  )
  : TAO_Unbounded_Object_Sequence<
        CORBA::Policy,
        CORBA::Policy_var
      >
    (seq)
{}

CORBA::PolicyList::~PolicyList (void)
{}

void CORBA::PolicyList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  PolicyList * _tao_tmp_pointer =
    static_cast<PolicyList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_POLICYTYPESEQ_CS_)
#define _CORBA_POLICYTYPESEQ_CS_

CORBA::PolicyTypeSeq::PolicyTypeSeq (void)
{}

CORBA::PolicyTypeSeq::PolicyTypeSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::PolicyType
      >
    (max)
{}

CORBA::PolicyTypeSeq::PolicyTypeSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::ULong * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::PolicyType
      >
    (max, length, buffer, release)
{}

CORBA::PolicyTypeSeq::PolicyTypeSeq (
    const PolicyTypeSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::PolicyType
      >
    (seq)
{}

CORBA::PolicyTypeSeq::~PolicyTypeSeq (void)
{}

void CORBA::PolicyTypeSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  PolicyTypeSeq * _tao_tmp_pointer =
    static_cast<PolicyTypeSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_PolicyList_CPP_
#define _TAO_CDR_OP_CORBA_PolicyList_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::PolicyList &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag =
            TAO::Objref_Traits<CORBA::Policy>::marshal (
                _tao_sequence[i].in (), strm
              );
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::PolicyList &_tao_sequence
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
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_CORBA_PolicyList_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_CORBA_PolicyTypeSeq_CPP_
#define _TAO_CDR_OP_CORBA_PolicyTypeSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::PolicyTypeSeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      return strm.write_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::PolicyTypeSeq &_tao_sequence
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
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      return strm.read_ulong_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_CORBA_PolicyTypeSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_enum/cdr_op_cs.cpp:51

CORBA::Boolean operator<< (TAO_OutputCDR & strm, CORBA::SetOverrideType _tao_enumerator)
{
  return strm << static_cast<CORBA::ULong> (_tao_enumerator);
}

CORBA::Boolean operator>> (TAO_InputCDR & strm, CORBA::SetOverrideType & _tao_enumerator)
{
  CORBA::ULong _tao_temp = 0;
  CORBA::Boolean const _tao_success = strm >> _tao_temp;
  
  if (_tao_success)
    {
      _tao_enumerator = static_cast<CORBA::SetOverrideType> (_tao_temp);
    }
  
  return _tao_success;
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1528

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Object_Manager<
        CORBA::Policy,
        CORBA::Policy_var
      >;

  template class
    TAO_MngSeq_Var_T<
        CORBA::PolicyList,
        TAO_Object_Manager<
            CORBA::Policy,
            CORBA::Policy_var
          >
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::PolicyList,
        TAO_Object_Manager<
            CORBA::Policy,
            CORBA::Policy_var
          >
      >;

  template class
    TAO_MngSeq_Out_T<
        CORBA::PolicyList,
        CORBA::PolicyList_var,
        TAO_Object_Manager<
            CORBA::Policy,
            CORBA::Policy_var
          >
      >;

#if !defined (_CORBA_POLICY__EXPLICIT_CS_)
#define _CORBA_POLICY__EXPLICIT_CS_

  template class
    TAO_Unbounded_Object_Sequence<
        CORBA::Policy,
        CORBA::Policy_var
      >;

#endif /* end #if !defined */

  template class
    TAO_FixedSeq_Var_T<
        CORBA::PolicyTypeSeq,
        CORBA::PolicyType
      >;

  template class
    TAO_Seq_Var_Base_T<
        CORBA::PolicyTypeSeq,
        CORBA::PolicyType
      >;

  template class
    TAO_Seq_Out_T<
        CORBA::PolicyTypeSeq,
        CORBA::PolicyTypeSeq_var,
        CORBA::PolicyType
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_MngSeq_Var_T< \
        CORBA::PolicyList, \
        TAO_Object_Manager< \
            CORBA::Policy, \
            CORBA::Policy_var \
          > \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::PolicyList, \
        TAO_Object_Manager< \
            CORBA::Policy, \
            CORBA::Policy_var \
          > \
      >

# pragma instantiate \
    TAO_MngSeq_Out_T< \
        CORBA::PolicyList, \
        CORBA::PolicyList_var, \
        TAO_Object_Manager< \
            CORBA::Policy, \
            CORBA::Policy_var \
          > \
      >

#if !defined (_CORBA_POLICY__EXPLICIT_CS_)
#define _CORBA_POLICY__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Object_Sequence< \
        CORBA::Policy, \
        CORBA::Policy_var \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_FixedSeq_Var_T< \
        CORBA::PolicyTypeSeq, \
        CORBA::PolicyType \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        CORBA::PolicyTypeSeq, \
        CORBA::PolicyType \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        CORBA::PolicyTypeSeq, \
        CORBA::PolicyTypeSeq_var, \
        CORBA::PolicyType \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
