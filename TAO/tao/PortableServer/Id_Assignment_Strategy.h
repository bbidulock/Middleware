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
#include "PortableServerC.h"
#include "Policy_Strategy.h"
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
      virtual ~Id_Assignment_Strategy (void);

      void strategy_init(TAO_POA *poa, CORBA::PolicyList *policy_list);

      /**
       * Verify if this id is generated by this policy
       */
      virtual bool verify (const PortableServer::ObjectId &id) = 0;

      /// Generate a new id
      virtual void next_id (PortableServer::ObjectId &id) = 0;

      /**
       * Returns the key type the says which specific policy we have
       */
      virtual char id_assignment_key_type (void) const = 0;

      /**
       * Returns the length of the id_assignment type
       */
      char id_assignment_key_type_length (void) const;
    };

    class TAO_PortableServer_Export User_Id_Assignment_Strategy :
       public virtual Id_Assignment_Strategy
    {
    public:
      virtual ~User_Id_Assignment_Strategy (void);

      virtual char id_assignment_key_type (void) const;

    private:
    };

    class TAO_PortableServer_Export System_Id_Assignment_Strategy :
       public virtual Id_Assignment_Strategy
    {
    public:
      virtual ~System_Id_Assignment_Strategy (void);

      virtual char id_assignment_key_type (void) const;
    };
  }
}

#endif /* TAO_HAS_MINIMUM_POA == 0 */

#include /**/ "ace/post.h"
#endif /* TAO_ID_ASSIGNMENT_STRATEGY_H */
