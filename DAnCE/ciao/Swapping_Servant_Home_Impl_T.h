// -*- C++ -*-

//=============================================================================
/**
 *  @file    Swapping_Servant_Impl_T.h
 *
 *  $Id$
 *
 *  This file contains the declaration of a mixin base class for
 *  the generated home servant class.
 *
 */
//=============================================================================


#ifndef CIAO_SWAPPING_SERVANT_HOME_IMPL_T_H
#define CIAO_SWAPPING_SERVANT_HOME_IMPL_T_H

#include /**/ "ace/pre.h"

#include "Home_Servant_Impl_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/Key_Adapters.h"
#include "ace/Hash_Map_Manager_T.h"
#include "Dynamic_Component_Servant_Base.h"

namespace CIAO
{
  class Session_Container;

  /**
   * @class Swapping_Servant_Impl
   *
   * @brief Mixin base class for generated home servant.
   *
   * This class implements operations
   * common to all generated home servants.
   */
  template <typename BASE_SKEL,
            typename EXEC,
            typename EXEC_VAR,
            typename COMP,
            typename COMP_VAR,
            typename COMP_EXEC,
            typename COMP_EXEC_VAR,
            typename COMP_SVNT>
  class Swapping_Home_Servant_Impl
    : public virtual BASE_SKEL,
      public virtual Home_Servant_Impl_Base,
      public virtual PortableServer::RefCountServantBase
  {
  public:
    Swapping_Home_Servant_Impl (EXEC * exe,
                       Session_Container * c,
                       const char* obj_id, const char* repo_id);

    virtual ~Swapping_Home_Servant_Impl (void);

    // Operations for CCMHome interface.

    virtual void
    remove_component (Components::CCMObject_ptr comp
                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::RemoveFailure));

    // Operations for keyless home interface.

    virtual ::Components::CCMObject_ptr
    create_component (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CreateFailure));

    // Operations for implicit home interface.

    virtual COMP *
    create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CreateFailure));

    virtual void
    update_component_map (PortableServer::ObjectId &oid);

  protected:
    // CIAO-specific operations.

    COMP *
    _ciao_activate_component (::Components::EnterpriseComponent_ptr ec
                              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    void
    _ciao_passivate_component (COMP *comp
                               ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

  protected:
    EXEC_VAR executor_;

    ACE_Hash_Map_Manager_Ex<PortableServer::ObjectId,
                            COMP_SVNT *,
                            TAO_ObjectId_Hash,
                            ACE_Equal_To<PortableServer::ObjectId>,
                            ACE_SYNCH_MUTEX>
      component_map_;

    typedef ACE_Hash_Map_Manager_Ex<PortableServer::ObjectId,
                            Dynamic_Component_Servant_Base *,
                            TAO_ObjectId_Hash,
                            ACE_Equal_To<PortableServer::ObjectId>,
                            ACE_SYNCH_MUTEX> DYNAMIC_SERVANT_MAP;

    typedef DYNAMIC_SERVANT_MAP::iterator DYNAMIC_SERVANT_MAP_ITERATOR;
    DYNAMIC_SERVANT_MAP dynamic_servant_map_;

    const char* obj_id_;
    const char* repo_id_;
  };
}

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "Swapping_Servant_Home_Impl_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Swapping_Servant_Home_Impl_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* CIAO_SWAPPING_SERVANT_HOME_IMPL_T_H */
