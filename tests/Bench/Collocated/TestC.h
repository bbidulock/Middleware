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
// be/be_visitor_module/module_ch.cpp:48
namespace TAO
{
  class Collocation_Proxy_Broker;
}

TAO_NAMESPACE  Test
{

  // TAO_IDL - Generated from
  // be/be_interface.cpp:584

#if !defined (_TEST_HELLO__VAR_OUT_CH_)
#define _TEST_HELLO__VAR_OUT_CH_

  class Hello;
  typedef Hello *Hello_ptr;
  struct tao_Hello_life;

  typedef  TAO_Objref_Var_T<Hello>  Hello_var;

  typedef TAO_Objref_Out_T<Hello> Hello_out;

  struct  tao_Hello_life
  {
    static Hello_ptr tao_duplicate (Hello_ptr);
    static void tao_release (Hello_ptr);
    static Hello_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        Hello_ptr,
        TAO_OutputCDR &
      );
  };

  struct  tao_Hello_cast
  {
    static Hello_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:53

#if !defined (_TEST_HELLO_CH_)
#define _TEST_HELLO_CH_

  class  Hello
    : public virtual CORBA::Object
  {
  public:
    typedef Hello_ptr _ptr_type;
    typedef Hello_var _var_type;
    static int _tao_class_id;

    // The static operations.
    static Hello_ptr _duplicate (Hello_ptr obj);

    static Hello_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static Hello_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static Hello_ptr _nil (void)
      {
        return (Hello_ptr)0;
      }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual char * get_string (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void shutdown (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:210

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual void *_tao_QueryInterface (ptrdiff_t type);

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_Hello_Proxy_Broker_;

  protected:
    Hello (int collocated = 0);

    // These methods travese the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void Test_Hello_setup_collocation (int collocated);

    Hello (IOP::IOR *ior,
      TAO_ORB_Core *orb_core = 0);

    Hello (
        TAO_Stub *objref,
        CORBA::Boolean _tao_collocated = 0,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0
      );
    virtual ~Hello (void);

  private:
    Hello (const Hello &);
    void operator= (const Hello &);
  };


#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Hello;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module Test

// Proxy Broker Factory function pointer declarations.
// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:76

extern
TAO::Collocation_Proxy_Broker *
(*Test__TAO_Hello_Collocation_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:53

// Traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_traits.cpp:99

#if !defined (_TEST_HELLO__ARG_TRAITS_CH_)
#define _TEST_HELLO__ARG_TRAITS_CH_

#endif /* end #if !defined */
};

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

 void operator<<= (CORBA::Any &, Test::Hello_ptr); // copying
 void operator<<= (CORBA::Any &, Test::Hello_ptr *); // non-copying
 CORBA::Boolean operator>>= (const CORBA::Any &, Test::Hello_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:55

 CORBA::Boolean operator<< (TAO_OutputCDR &, const Test::Hello_ptr );
 CORBA::Boolean operator>> (TAO_InputCDR &, Test::Hello_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:958

#if defined (__ACE_INLINE__)
#include "TestC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#endif /* ifndef */
