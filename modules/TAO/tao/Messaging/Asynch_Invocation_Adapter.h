// -*- C++ -*-

//=============================================================================
/**
 *  @file    Asynch_Invocation_Adapter.h
 *
 *  $Id$
 *
 *
 *  @author Balachandran Natarajan <bala@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef TAO_MESSAGING_ASYNCH_INVOCATION_ADAPTER_H
#define TAO_MESSAGING_ASYNCH_INVOCATION_ADAPTER_H

#include /**/ "ace/pre.h"

#include "tao/Messaging/messaging_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Messaging/Messaging.h"
#include "tao/Asynch_Reply_Dispatcher_Base.h"
#include "tao/Invocation_Adapter.h"
#include "ace/CORBA_macros.h"
#include "ace/Global_Macros.h"
#include "ace/Auto_Functor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Time_Value;
ACE_END_VERSIONED_NAMESPACE_DECL

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_Operation_Details;
class TAO_Stub;
class TAO_Asynch_Reply_Dispatcher;
class TAO_Asynch_Reply_Dispatcher_Base;

namespace  CORBA
{
  class Object;
  class Environment;
  class SystemException;
}

namespace TAO
{
  class Argument;

  class Collocation_Proxy_Broker;

  /**
   * @class Asynch_Invocation_Adapter
   *
   * @brief Generic interface for the invocation object visible to the
   * IDL compiler.
   *
   */
  class TAO_Messaging_Export Asynch_Invocation_Adapter
    : public Invocation_Adapter
  {
  public:
    Asynch_Invocation_Adapter (
        CORBA::Object *target,
        Argument **args,
        int arg_number,
        const char *operation,
        size_t op_len,
        Collocation_Proxy_Broker *b,
        TAO::Invocation_Mode mode = TAO_ASYNCHRONOUS_CALLBACK_INVOCATION);

    void invoke (Messaging::ReplyHandler_ptr reply_handler_ptr,
                 const TAO_Reply_Handler_Skeleton &reply_handler_skel
                 ACE_ENV_ARG_DECL);

    virtual void invoke (TAO::Exception_Data *ex,
                         unsigned long ex_count
                         ACE_ENV_ARG_DECL);
  protected:

    virtual Invocation_Status invoke_twoway (
        TAO_Operation_Details &op,
        CORBA::Object_var &effective_target,
        Profile_Transport_Resolver &r,
        ACE_Time_Value *&max_wait_time
        ACE_ENV_ARG_DECL);

    virtual Invocation_Status invoke_collocated_i (
        TAO_Stub *stub,
        TAO_Operation_Details &details,
        CORBA::Object_var &effective_target,
        Collocation_Strategy strat
        ACE_ENV_ARG_DECL);

  private:
    /// Autofunctor to manage the reply dispatcher
    ACE_Utils::Auto_Functor<TAO_Asynch_Reply_Dispatcher_Base,
                            ARDB_Refcount_Functor> safe_rd_;

  private:
    /// Don't allow default initializations
    Asynch_Invocation_Adapter (void);

    Asynch_Invocation_Adapter (const Asynch_Invocation_Adapter &);
    Asynch_Invocation_Adapter & operator= (const Asynch_Invocation_Adapter &);

  };
} // End namespace TAO

TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* TAO_MESSAGING_ASYNCH_INVOCATION_ADAPTER_H */
