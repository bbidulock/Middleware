// -*- C++ -*-

//=============================================================================
/**
 *  @file LifespanStrategy.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_LIFESPAN_STRATEGY_H
#define TAO_LIFESPAN_STRATEGY_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Policy_Strategy.h"
#include "tao/Object_KeyC.h"

namespace TAO
{
  namespace Portable_Server
  {
    class Temporary_Creation_Time;

    class TAO_PortableServer_Export LifespanStrategy
      : public virtual Policy_Strategy
    {
    public:
      LifespanStrategy (void);

      virtual ~LifespanStrategy (void);

      virtual
      void strategy_init (TAO_POA *poa);

      void create (const char *name,
                   const TAO::ObjectKey &key);

      virtual
      void notify_startup (ACE_ENV_SINGLE_ARG_DECL) = 0;

      virtual
      void notify_shutdown (ACE_ENV_SINGLE_ARG_DECL) = 0;

      /**
       * Validate the passed object key if it belongs to this POA.
       */
      bool validate (TAO::ObjectKey_var& key);

      /**
       * Returns the length of the key type
       */
      virtual CORBA::ULong key_length (void) const = 0;

      CORBA::ULong key_type_length (void) const;

      /// Do we have set persistent or not,
      virtual CORBA::Boolean is_persistent (void) const = 0;

      virtual void create_key (CORBA::Octet *buffer, CORBA::ULong& starting_at) = 0;

      /// Validate whether this matches the set lifespan strategy
      virtual
      bool validate (CORBA::Boolean is_persistent,
                     const TAO::Portable_Server::Temporary_Creation_Time& creation_time) const = 0;

    protected:
      TAO_POA *poa_;
    };

  } /* namespace Portable_Server */
} /* namespace TAO */

#include /**/ "ace/post.h"
#endif /* TAO_LIFESPAN_STRATEGY_H */
