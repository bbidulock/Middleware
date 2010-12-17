// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/
#ifndef CIAO_INTERINARGST_RECEIVER_EXEC_K9F0UK_H_
#define CIAO_INTERINARGST_RECEIVER_EXEC_K9F0UK_H_

#include /**/ "ace/pre.h"

#include "InterInArgsT_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "InterInArgsT_Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_InterInArgsT_Receiver_Impl
{

  /**
   * Provider Executor Implementation Class: do_my_foo_exec_i
   */

  class do_my_foo_exec_i
    : public virtual ::InterInArgsT::CCM_MyFoo,
      public virtual ::CORBA::LocalObject
  {
  public:
    do_my_foo_exec_i (
      ::InterInArgsT::CCM_Receiver_Context_ptr ctx);
    virtual ~do_my_foo_exec_i (void);

    //@{
    /** Operations and attributes from ::InterInArgsT::MyFoo. */

    virtual
    ::CORBA::Long foo (const char * in_str,
    ::CORBA::Long cmd,
    ::CORBA::String_out answer);

    virtual
    void var_ins (const char * in_str,
    ::CORBA::String_out answer,
    ::CORBA::Double cmd);

    virtual
    void var_div_ins (const ::InterInArgsT::TestTopic & test_topic,
    const ::InterInArgsT::TopicString & topic_str,
    const ::InterInArgsT::TestArray topic_arr,
    ::CORBA::String_out answer);

    virtual
    void var_div2_ins (const ::InterInArgsT::X_Union & topic_union,
    const ::InterInArgsT::test_seq & seq,
    ::CORBA::String_out answer);

    virtual
    void enum_in (::CORBA::String_out answer,
    ::InterInArgsT::test_enum in_test);
    //@}

  private:
    ::InterInArgsT::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  class Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::InterInArgsT::CCM_MyFoo_ptr
    get_do_my_foo (void);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */

    //@}

  private:
    ::InterInArgsT::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::InterInArgsT::CCM_MyFoo_var ciao_do_my_foo_;
    //@}

    //@{
    /** User defined members. */

    //@}

    //@{
    /** User defined private operations. */

    //@}
  };

  extern "C" INTERINARGS_T_RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_InterInArgsT_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
