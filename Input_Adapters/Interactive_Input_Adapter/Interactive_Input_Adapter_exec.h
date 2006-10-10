// $Id$
#ifndef CIAO_INTERACTIVE_INPUT_ADAPTER_EXEC_H
#define CIAO_INTERACTIVE_INPUT_ADAPTER_EXEC_H

#include /**/ "ace/pre.h"

#include "Interactive_Input_Adapter_svnt.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "Interactive_Input_Adapter_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_Interactive_Input_Adapter_Impl
    {
      class INTERACTIVE_INPUT_ADAPTER_EXEC_Export Interactive_Input_Adapter_exec_i
      : public virtual Interactive_Input_Adapter_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        Interactive_Input_Adapter_exec_i (void);

        virtual ~Interactive_Input_Adapter_exec_i (void);

        virtual void
        push_deployment (::CIAO::RACE::Deploy_Input *ev)
          throw (CORBA::SystemException);

        virtual void
        push_meta_data (::CIAO::RACE::Metadata *mde)
          throw (CORBA::SystemException);


        virtual void
        set_session_context (
          ::Components::SessionContext_ptr ctx
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ciao_preactivate (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ciao_postactivate (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ccm_activate (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ccm_passivate (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        virtual void
        ccm_remove (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));

        protected:
        Interactive_Input_Adapter_Context *context_;
      };

      class INTERACTIVE_INPUT_ADAPTER_EXEC_Export Interactive_Input_Adapter_Home_exec_i
      : public virtual Interactive_Input_Adapter_Home_Exec,
      public virtual TAO_Local_RefCounted_Object
      {
        public:
        Interactive_Input_Adapter_Home_exec_i (void);
        virtual ~Interactive_Input_Adapter_Home_exec_i (void);

        // Supported or inherited operations.

        // Home operations.

        // Factory and finder operations.

        // Attribute operations.

        // Implicit operations.

        virtual ::Components::EnterpriseComponent_ptr
        create (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC ((
                          ::CORBA::SystemException,
                          ::Components::CCMException));
      };

      extern "C" INTERACTIVE_INPUT_ADAPTER_EXEC_Export ::Components::HomeExecutorBase_ptr
      create_CIAO_RACE_Interactive_Input_Adapter_Home_Impl (void);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_INTERACTIVE_INPUT_ADAPTER_EXEC_H */
