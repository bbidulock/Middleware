// $Id$

// This file contains executor implementations.

#include "hello_executor_export.h"
#include "helloEC.h"

#if !defined (HELLO_EXECUTORS_H)
#define HELLO_EXECUTORS_H

class HelloWorld_Impl : public virtual CCM_HelloWorld
{
public:
  /// Default ctor.
  HelloWorld_Impl ();

  /// Default dtor.
  ~HelloWorld_Impl ();

  virtual char *sayHello (const char *username
                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
};

class HelloHome_Impl : public virtual CCM_HelloHome
{
public:
  /// Default ctor.
  HelloHome_Impl ();

  /// Default dtor.
  ~HelloHome_Impl ();

  virtual ::Components::EnterpriseComponent_ptr
  create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException,
                     Components::CreateFailure));
};

// We still need to figure out a way to clean up the object created by
// the factory correctly.   Like we did in ACE_FACTORY macro, with a
// Gobbler function.

extern "C" HELLO_EXECUTOR_Export ::Components::HomeExecutorBase_ptr
createHelloHome_Impl (void);

#endif /* HELLO_EXECUTORS_H */
