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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

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
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:577

#if !defined (_FOO__ODDS_N_ENDS_CH_)
#define _FOO__ODDS_N_ENDS_CH_

class foo;
typedef foo *foo_ptr;
struct tao_foo_life;

typedef
  TAO_Objref_Var_T<
      foo,
      tao_foo_life
    >
  foo_var;

typedef
  TAO_Objref_Out_T<
      foo,
      tao_foo_life
    >
  foo_out;

struct  tao_foo_life
{
  static foo_ptr tao_duplicate (foo_ptr);
  static void tao_release (foo_ptr);
  static foo_ptr tao_nil (void);
  static CORBA::Boolean tao_marshal (
      foo_ptr,
      TAO_OutputCDR &
    );
};

struct  tao_foo_cast
{
  static foo_ptr tao_narrow (
      CORBA::Object_ptr
      ACE_ENV_ARG_DECL
    );
  static CORBA::Object_ptr tao_upcast (void *);
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:53

#if !defined (_FOO_CH_)
#define _FOO_CH_

class _TAO_foo_Proxy_Impl;
class _TAO_foo_Remote_Proxy_Impl;
class _TAO_foo_Proxy_Broker;
class _TAO_foo_Remote_Proxy_Broker;

class  foo
  : public virtual CORBA::Object
{
public:
  typedef foo_ptr _ptr_type;
  typedef foo_var _var_type;
  static int _tao_class_id;

  // The static operations.
  static foo_ptr _duplicate (foo_ptr obj);

  static foo_ptr _narrow (
      CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );

  static foo_ptr _unchecked_narrow (
      CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );

  static foo_ptr _nil (void)
    {
      return (foo_ptr)0;
    }

  static void _tao_any_destructor (void *);

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46

  virtual char * all_str (
      const char * inarg,
      char *& inoutarg,
      CORBA::String_out outarg
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));


  virtual void push (
                     const char * inarg
                     ACE_ENV_ARG_DECL_WITH_DEFAULTS
                     )
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:210

  virtual CORBA::Boolean _is_a (
      const char *type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );

  virtual void *_tao_QueryInterface (ptrdiff_t type);

  virtual const char* _interface_repository_id (void) const;
  virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
private:
  _TAO_foo_Proxy_Broker *the_TAO_foo_Proxy_Broker_;

protected:
  foo (int collocated = 0);

  // These methods travese the inheritance tree and set the
  // parents piece of the given class in the right mode.
  virtual void foo_setup_collocation (int collocated);

  foo (IOP::IOR *ior,
    TAO_ORB_Core *orb_core = 0);

  foo (
      TAO_Stub *objref,
      CORBA::Boolean _tao_collocated = 0,
      TAO_Abstract_ServantBase *servant = 0,
      TAO_ORB_Core *orb_core = 0
    );
  virtual ~foo (void);

  friend class _TAO_foo_Remote_Proxy_Impl;
  friend class _TAO_foo_ThruPOA_Proxy_Impl;
  friend class _TAO_foo_Direct_Proxy_Impl;

private:
  foo (const foo &);
  void operator= (const foo &);
};

// The Proxy Implementations are used by each interface to
// perform a call. Each different implementation encapsulates
// an invocation logic.


///////////////////////////////////////////////////////////////////////
//                    Base Proxy Impl. Declaration
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/base_proxy_impl_ch.cpp:35

class  _TAO_foo_Proxy_Impl
  : public virtual TAO_Object_Proxy_Impl
{
public:
  virtual ~_TAO_foo_Proxy_Impl (void) {}

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/base_proxy_impl_ch.cpp:24

  virtual char * all_str (
      CORBA::Object *_collocated_tao_target_,
      const char * inarg,
      char *& inoutarg,
      CORBA::String_out outarg
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) = 0;

  virtual void push (
      CORBA::Object * /*_collocated_tao_target_*/,
      const char * /* inarg */
      ACE_ENV_ARG_DECL_NOT_USED
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    )) {};
protected:
  _TAO_foo_Proxy_Impl (void);
};

//
//               End Base Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                Remote Proxy Impl. Declaration
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/remote_proxy_impl_ch.cpp:37

class  _TAO_foo_Remote_Proxy_Impl
  : public virtual _TAO_foo_Proxy_Impl,
    public virtual TAO_Remote_Object_Proxy_Impl
{
public:
  _TAO_foo_Remote_Proxy_Impl (void);

  virtual ~_TAO_foo_Remote_Proxy_Impl (void) {}

  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/proxy_impl_xh.cpp:24

  virtual char * all_str (
      CORBA::Object *_collocated_tao_target_,
      const char * inarg,
      char *& inoutarg,
      CORBA::String_out outarg
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void push (
      CORBA::Object *_collocated_tao_target_,
      const char * inarg
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
};

//
//             End Remote Proxy Impl. Declaration
///////////////////////////////////////////////////////////////////////

// The Proxy Brokers are used by each interface to get
// the right proxy for performing a call. In the new
// collocation scheme, the proxy to be used can vary on
// a call by call basis.

///////////////////////////////////////////////////////////////////////
//                 Base Proxy Broker Declaration
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/base_proxy_broker_ch.cpp:35

class  _TAO_foo_Proxy_Broker
{
public:
  virtual ~_TAO_foo_Proxy_Broker (void);
  virtual _TAO_foo_Proxy_Impl &select_proxy (
      foo *object
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    ) = 0;

protected:
  _TAO_foo_Proxy_Broker (void);

};

//
//              End Base Proxy Broker Declaration
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                 Remote Proxy Broker Declaration
//

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/remote_proxy_broker_ch.cpp:40

class  _TAO_foo_Remote_Proxy_Broker
  : public virtual _TAO_foo_Proxy_Broker
{
public:
  _TAO_foo_Remote_Proxy_Broker (void);

  virtual ~_TAO_foo_Remote_Proxy_Broker (void);

  virtual _TAO_foo_Proxy_Impl &select_proxy (
      foo *object
      ACE_ENV_ARG_DECL
    );

private:
  _TAO_foo_Remote_Proxy_Impl remote_proxy_impl_;

public:
  // This member function is used to get an handle to the unique instance
  // of the Remote Proxy Broker that is available for a given
  // interface.
  static _TAO_foo_Remote_Proxy_Broker *the_TAO_foo_Remote_Proxy_Broker (void);
};

//
//              End Remote Proxy Broker Declaration
///////////////////////////////////////////////////////////////////////

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_typecode/typecode_decl.cpp:44

extern  ::CORBA::TypeCode_ptr  _tc_foo;

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/root.cpp:76

extern
_TAO_foo_Proxy_Broker *
(*_TAO_foo_Proxy_Broker_Factory_function_pointer) (
    CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/any_op_ch.cpp:52

 void operator<<= (CORBA::Any &, foo_ptr); // copying
 void operator<<= (CORBA::Any &, foo_ptr *); // non-copying
 CORBA::Boolean operator>>= (const CORBA::Any &, foo_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/cdr_op_ch.cpp:55

 CORBA::Boolean operator<< (TAO_OutputCDR &, const foo_ptr );
 CORBA::Boolean operator>> (TAO_InputCDR &, foo_ptr &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1055

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
