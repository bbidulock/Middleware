// -*- C++ -*-

//=============================================================================
/**
 *  @file LifespanStrategyTransient.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_LIFESPANSTRATEGYTRANSIENT_H
#define TAO_LIFESPANSTRATEGYTRANSIENT_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "LifespanStrategy.h"
#include "Creation_Time.h"
#include "tao/Object_KeyC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export LifespanStrategyTransient
      : public virtual LifespanStrategy
    {
    public:
      LifespanStrategyTransient (void);

      virtual ~LifespanStrategyTransient (void);

      virtual void notify_startup (ACE_ENV_SINGLE_ARG_DECL);

      virtual void notify_shutdown (ACE_ENV_SINGLE_ARG_DECL);

      char key_type (void) const;

      virtual CORBA::Boolean is_persistent (void) const;

      CORBA::ULong key_length (void) const;

      virtual void create_key (CORBA::Octet *buffer, CORBA::ULong& starting_at);

      virtual
      bool validate (CORBA::Boolean is_persistent,
                     const TAO::Portable_Server::Temporary_Creation_Time& creation_time) const;

      /// Check the state of the POA.
      virtual void check_state (ACE_ENV_SINGLE_ARG_DECL);

    private:
      TAO::Portable_Server::Creation_Time creation_time_;
    };
  } /* namespace Portable_Server */
} /* namespace TAO */

#include /**/ "ace/post.h"
#endif /* TAO_LIFESPANSTRATEGYTRANSIENT_H */
