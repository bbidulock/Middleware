// -*- C++ -*-

//=============================================================================
/**
 *  @file Id_Assignment_Strategy.h
 *
 *  $Id$
 *
 *  @author  Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef TAO_ID_ASSIGNMENT_STRATEGY_H
#define TAO_ID_ASSIGNMENT_STRATEGY_H
#include /**/ "ace/pre.h"

#include "portableserver_export.h"
#include "PolicyFactory.h"
#include "PortableServerC.h"
#include "PolicyStrategy.h"
#include "ace/Service_Config.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if (TAO_HAS_MINIMUM_POA == 0)

namespace CORBA
{
  class PolicyError;
  class PolicyList;
}

namespace TAO
{
  namespace Portable_Server
  {
    class TAO_PortableServer_Export Id_Assignment_Strategy :
       public virtual Policy_Strategy
    {
    public:
      virtual ~Thread_Strategy (void);

      void init(CORBA::PolicyList *policy_list)
      {
        // dependent on type create the correct strategy.
      }

      /**
       * Verify if this id is generated by this policy
       */
      bool verify (const PortableServer::ObjectId &id) = 0;

      /// Generate a new id
      void next_id (PortableServer::ObjectId &id) = 0;
    };

    class TAO_PortableServer_Export User_Id_Assignment_Strategy :
       public virtual User_Id_Assignment_Strategy
    {
    public:
      virtual ~Implicit_Activation_Strategy (void);

    private:
    };

    class TAO_PortableServer_Export System_Id_Assignment_Strategy :
       public virtual Id_Assignment_Strategy
    {
    public:
      virtual ~System_Id_Assignment_Strategy (void);
    };
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_ID_ASSIGNMENT_STRATEGY_H */
