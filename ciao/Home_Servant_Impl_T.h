// -*- C++ -*-

//=============================================================================
/**
 *  @file    Home_Servant_Impl_T.h
 *
 *  $Id$
 *
 *  This file contains the declaration of a mixin base class for
 *  the generated home servant class.
 *
 *  @authors Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================


#ifndef CIAO_HOME_SERVANT_IMPL_T_H
#define CIAO_HOME_SERVANT_IMPL_T_H

#include /**/ "ace/pre.h"

#include "Home_Servant_Impl_Base.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/Key_Adapters.h"
#include "ace/Hash_Map_Manager_T.h"

namespace CIAO
{
  class Session_Container;

  /**
   * @class Home_Servant_Impl
   *
   * @brief Mixin base class for generated home servant.
   *
   * This class implements operations
   * common to all generated home servants.
   */
  template <typename BASE_SKEL,
            typename EXEC,
            typename COMP_SVNT>
  class Home_Servant_Impl
    : public virtual BASE_SKEL,
      public virtual Home_Servant_Impl_Base
  {
  public:
    Home_Servant_Impl (typename EXEC::_ptr_type exe,
                       Session_Container * c,
                       const char *ins_name);

    virtual ~Home_Servant_Impl (void);

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

    virtual typename COMP_SVNT::_stub_ptr_type
    create (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       Components::CreateFailure));

    virtual void
    update_component_map (PortableServer::ObjectId &oid);

  protected:
    // CIAO-specific operations.

    typename COMP_SVNT::_stub_ptr_type
    _ciao_activate_component (typename COMP_SVNT::_exec_type::_ptr_type exe
                              ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

    void
    _ciao_passivate_component (typename COMP_SVNT::_stub_ptr_type comp
                               ACE_ENV_ARG_DECL_WITH_DEFAULTS)
      ACE_THROW_SPEC ((CORBA::SystemException));

  protected:
    const char *ins_name_;
    typename EXEC::_var_type executor_;

    typedef ACE_Hash_Map_Manager_Ex<PortableServer::ObjectId,
                                    Components::CCMObject_var,
                                    TAO_ObjectId_Hash,
                                    ACE_Equal_To<PortableServer::ObjectId>,
                                    ACE_SYNCH_MUTEX>
      OBJREF_MAP;

    typedef OBJREF_MAP::iterator OBJ_ITERATOR;

    OBJREF_MAP objref_map_;
  };
}

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "Home_Servant_Impl_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Home_Servant_Impl_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* CIAO_HOME_SERVANT_IMPL_T_H */
