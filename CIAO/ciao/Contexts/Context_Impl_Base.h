// -*- C++ -*-

//=============================================================================
/**
 *  @file    Context_Impl_Base.h
 *
 *  $Id$
 *
 *  This file contains the non-template declaration of a base class for
 *  the template mixin for the generated context class.
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef CIAO_CONTEXT_IMPL_BASE_H
#define CIAO_CONTEXT_IMPL_BASE_H

#include /**/ "ace/pre.h"

#include "Context_Impl_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ccm/CCM_ContextC.h"

namespace CIAO
{
  class Container;
  typedef Container *Container_ptr;
  typedef TAO_Objref_Var_T<Container> Container_var;

  /**
   * @class Context_Impl_Base
   *
   * @brief Non-template base class for Context_Impl.
   *
   * Holds the non-template parts of its child class
   * Context_Impl.
   */
  class Context_Impl_Export Context_Impl_Base
    : public virtual Components::CCMContext
  {
  public:
    Context_Impl_Base (::Components::CCMHome_ptr home,
                       ::CIAO::Container_ptr c,
                       const char *instance_id);

    virtual ~Context_Impl_Base (void);

    // Operations from ::Components::CCMContext.
#if !defined (CCM_LW)
    virtual ::Components::Principal_ptr get_caller_principal ();
#endif

    virtual ::Components::CCMHome_ptr get_CCM_home ();

#if !defined (CCM_LW)
    virtual ::CORBA::Boolean get_rollback_only ();
#endif

#if !defined (CCM_LW)
    virtual Components::Transaction::UserTransaction_ptr
    get_user_transaction ();
#endif

#if !defined (CCM_LW)
    virtual CORBA::Boolean is_caller_in_role (const char *role);
#endif

#if !defined (CCM_LW)
    virtual void set_rollback_only ();
#endif

    virtual CORBA::Object_ptr resolve_service_reference(const char *service_id);

    /// Temporarily added back for a sponsor, this will be removed at some
    /// moment in favor of a resolve_service_reference() call
    const char *_ciao_instance_id (void) const;

  private:
    ::Components::CCMHome_var home_;
  protected:
    ::CIAO::Container_var container_;
  private:
    /// Private constructor, not allowed to be called
    Context_Impl_Base (void);
    ::CORBA::String_var ciao_instance_id_;
  };
}

#include /**/ "ace/post.h"

#endif /* CIAO_CONTEXT_IMPL_BASE_H */
