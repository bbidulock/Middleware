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
// be/be_codegen.cpp:151

#ifndef _TAO_IDL_TESTC_H_
#define _TAO_IDL_TESTC_H_


#include "tao/corba.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"

#include "tao/RTScheduling/RTSchedulerC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO 
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from 
// be/be_visitor_root/root_ch.cpp:63

namespace TAO
{
  class Collocation_Proxy_Broker;
  
  template<typename T> class Narrow_Utils;
}

// TAO_IDL - Generated from
// be/be_interface.cpp:608

#if !defined (_TEST__VAR_OUT_CH_)
#define _TEST__VAR_OUT_CH_

class test;
typedef test *test_ptr;

typedef
  TAO_Objref_Var_T<
      test
    >
  test_var;

typedef
  TAO_Objref_Out_T<
      test
    >
  test_out;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_TEST_CH_)
#define _TEST_CH_

class  test
  : public virtual CORBA::Object
{
public:
  typedef test_ptr _ptr_type;
  typedef test_var _var_type;
  
  // The static operations.
  static test_ptr _duplicate (test_ptr obj);
  
  static test_ptr _narrow (
      CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static test_ptr _nil (void)
    {
      return (test_ptr)0;
    }
  
  static void _tao_any_destructor (void *);
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual void bar (
      CORBA::VoidData data
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:186
  
  virtual CORBA::Boolean _is_a (
      const char *type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

protected:
  test (void);
  virtual ~test (void);

private:
  test (const test &);
  void operator= (const test &);
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_decl.cpp:44

extern  ::CORBA::TypeCode_ptr  _tc_test;

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:48

// Traits specializations.
namespace TAO
{
};

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

 void operator<<= (CORBA::Any &, test_ptr); // copying
 void operator<<= (CORBA::Any &, test_ptr *); // non-copying
 CORBA::Boolean operator>>= (const CORBA::Any &, test_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:920

#if defined (__ACE_INLINE__)
#include "testC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#endif /* ifndef */

