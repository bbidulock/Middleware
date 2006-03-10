// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be\be_codegen.cpp:153

#ifndef _TAO_IDL_ORIG_RTSCHEDULERC_H_
#define _TAO_IDL_ORIG_RTSCHEDULERC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/RTScheduling/rtscheduler_export.h"

#include "tao/PI_Server/ServerRequestInfoC.h"
#include "tao/PI/ClientRequestInfoC.h"
#include "tao/PI/PIForwardRequestC.h"

#include "tao/RTCORBA/RTCORBA_includeC.h"

#include "tao/PortableServer/PortableServer_includeC.h"

#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/PortableInterceptorC.h"

#ifndef TAO_RTSCHEDULER_SAFE_INCLUDE
#error "You should not include RTSchedulerC.h directly, use RTScheduler.h"
#endif /* !TAO_RTSCHEDULER_SAFE_INCLUDE */

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_RTScheduler_Export

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace CORBA
{

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

  // Hand crafted
  typedef void* VoidData;

} // module CORBA

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:48

namespace RTScheduling
{

  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_RTSCHEDULING_THREADACTION__VAR_OUT_CH_)
#define _RTSCHEDULING_THREADACTION__VAR_OUT_CH_

  class ThreadAction;
  typedef ThreadAction *ThreadAction_ptr;

  typedef
    TAO_Objref_Var_T<
        ThreadAction
      >
    ThreadAction_var;

  typedef
    TAO_Objref_Out_T<
        ThreadAction
      >
    ThreadAction_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_RTSCHEDULING_THREADACTION_CH_)
#define _RTSCHEDULING_THREADACTION_CH_

  class TAO_RTScheduler_Export ThreadAction
    : public virtual CORBA::Object
  {
  public:
    typedef ThreadAction_ptr _ptr_type;
    typedef ThreadAction_var _var_type;

    // The static operations.
    static ThreadAction_ptr _duplicate (ThreadAction_ptr obj);

    static void _tao_release (ThreadAction_ptr obj);

    static ThreadAction_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static ThreadAction_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static ThreadAction_ptr _nil (void)
    {
      return static_cast<ThreadAction_ptr> (0);
    }



    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46

    virtual void _cxx_do (
        ::CORBA::VoidData data
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210

    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    // Abstract or local interface only.
    ThreadAction (void);

    virtual ~ThreadAction (void);

  private:
    // Private and unimplemented for concrete interfaces.
    ThreadAction (const ThreadAction &);

    void operator= (const ThreadAction &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44

  extern TAO_RTScheduler_Export ::CORBA::TypeCode_ptr const _tc_ThreadAction;

  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_RTSCHEDULING_DISTRIBUTABLETHREAD__VAR_OUT_CH_)
#define _RTSCHEDULING_DISTRIBUTABLETHREAD__VAR_OUT_CH_
  
  class DistributableThread;
  typedef DistributableThread *DistributableThread_ptr;
  
  typedef
    TAO_Objref_Var_T<
        DistributableThread
      >
    DistributableThread_var;
  
  typedef
    TAO_Objref_Out_T<
        DistributableThread
      >
    DistributableThread_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_RTSCHEDULING_DISTRIBUTABLETHREAD_CH_)
#define _RTSCHEDULING_DISTRIBUTABLETHREAD_CH_
  
  class TAO_RTScheduler_Export DistributableThread
    : public virtual CORBA::Object
  {
  public:
    typedef DistributableThread_ptr _ptr_type;
    typedef DistributableThread_var _var_type;
    
    // The static operations.
    static DistributableThread_ptr _duplicate (DistributableThread_ptr obj);
    
    static void _tao_release (DistributableThread_ptr obj);
    
    static DistributableThread_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DistributableThread_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static DistributableThread_ptr _nil (void)
    {
      return static_cast<DistributableThread_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_enum/enum_ch.cpp:57
    
    enum DT_State
    {
      ACTIVE,
      CANCELLED
    };
    
    typedef DT_State &DT_State_out;
    
    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:44
    
    static ::CORBA::TypeCode_ptr const _tc_DT_State;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void cancel (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::RTScheduling::DistributableThread::DT_State state (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DistributableThread (void);
    
    virtual ~DistributableThread (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DistributableThread (const DistributableThread &);
    
    void operator= (const DistributableThread &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_RTScheduler_Export ::CORBA::TypeCode_ptr const _tc_DistributableThread;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_RTSCHEDULING_CURRENT__VAR_OUT_CH_)
#define _RTSCHEDULING_CURRENT__VAR_OUT_CH_
  
  class Current;
  typedef Current *Current_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Current
      >
    Current_var;
  
  typedef
    TAO_Objref_Out_T<
        Current
      >
    Current_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_RTSCHEDULING_CURRENT_CH_)
#define _RTSCHEDULING_CURRENT_CH_
  
  class TAO_RTScheduler_Export Current
    : public virtual ::RTCORBA::Current
  {
  public:
    typedef Current_ptr _ptr_type;
    typedef Current_var _var_type;
    
    // The static operations.
    static Current_ptr _duplicate (Current_ptr obj);
    
    static void _tao_release (Current_ptr obj);
    
    static Current_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Current_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Current_ptr _nil (void)
    {
      return static_cast<Current_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::RTScheduling::DistributableThread_ptr spawn (
        ::RTScheduling::ThreadAction_ptr start,
        ::CORBA::VoidData data,
        const char * name,
        ::CORBA::Policy_ptr sched_param,
        ::CORBA::Policy_ptr implicit_sched_param,
        ::CORBA::ULong stack_size,
        ::RTCORBA::Priority base_priority
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_RTSCHEDULING_CURRENT_UNSUPPORTED_SCHEDULING_DISCIPLINE_CH_)
#define _RTSCHEDULING_CURRENT_UNSUPPORTED_SCHEDULING_DISCIPLINE_CH_
    
    class TAO_RTScheduler_Export UNSUPPORTED_SCHEDULING_DISCIPLINE : public CORBA::UserException
    {
    public:
      
      UNSUPPORTED_SCHEDULING_DISCIPLINE (void);
      UNSUPPORTED_SCHEDULING_DISCIPLINE (const UNSUPPORTED_SCHEDULING_DISCIPLINE &);
      ~UNSUPPORTED_SCHEDULING_DISCIPLINE (void);

      UNSUPPORTED_SCHEDULING_DISCIPLINE &operator= (const UNSUPPORTED_SCHEDULING_DISCIPLINE &);
      
      static UNSUPPORTED_SCHEDULING_DISCIPLINE *_downcast (CORBA::Exception *);
      static const UNSUPPORTED_SCHEDULING_DISCIPLINE *_downcast (CORBA::Exception const *);
      
      static CORBA::Exception *_alloc (void);
      
      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL
        ) const;
      
      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL
        );
      
      // TAO_IDL - Generated from
      // be\be_visitor_exception/exception_ch.cpp:129
      
      virtual CORBA::TypeCode_ptr _tao_type (void) const;
    };
    
    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:44
    
    static ::CORBA::TypeCode_ptr const _tc_UNSUPPORTED_SCHEDULING_DISCIPLINE;

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void begin_scheduling_segment (
        const char * name,
        ::CORBA::Policy_ptr sched_param,
        ::CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void update_scheduling_segment (
        const char * name,
        ::CORBA::Policy_ptr sched_param,
        ::CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void end_scheduling_segment (
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_RTSCHEDULING_CURRENT_IDTYPE_CH_)
#define _RTSCHEDULING_CURRENT_IDTYPE_CH_
    
    class IdType;
    
    typedef
      TAO_FixedSeq_Var_T<
          IdType,
          CORBA::Octet
        >
      IdType_var;
    
    typedef
      TAO_Seq_Out_T<
          IdType,
          IdType_var,
          CORBA::Octet
        >
      IdType_out;
    
    class TAO_RTScheduler_Export IdType
      : public
          TAO_Unbounded_Sequence<
              CORBA::Octet
            >
    {
    public:
      IdType (void);
      IdType (CORBA::ULong max);
      IdType (
          CORBA::ULong max,
          CORBA::ULong length,
          CORBA::Octet* buffer, 
          CORBA::Boolean release = 0
        );
      IdType (const IdType &);
      ~IdType (void);
      
      typedef IdType_var _var_type;

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      IdType (
          CORBA::ULong length,
          const ACE_Message_Block* mb
        )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:44
    
    static ::CORBA::TypeCode_ptr const _tc_IdType;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::RTScheduling::Current::IdType * id (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::RTScheduling::DistributableThread_ptr lookup (
        const ::RTScheduling::Current::IdType & id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr scheduling_parameter (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::Policy_ptr implicit_scheduling_parameter (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_RTSCHEDULING_CURRENT_NAMELIST_CH_)
#define _RTSCHEDULING_CURRENT_NAMELIST_CH_
    
    class NameList;
    
    typedef
      TAO_MngSeq_Var_T<
          NameList,
          TAO_SeqElem_String_Manager
        >
      NameList_var;
    
    typedef
      TAO_MngSeq_Out_T<
          NameList,
          NameList_var,
          TAO_SeqElem_String_Manager
        >
      NameList_out;
    
    class TAO_RTScheduler_Export NameList
      : public
          TAO_Unbounded_String_Sequence
    {
    public:
      NameList (void);
      NameList (CORBA::ULong max);
      NameList (
          CORBA::ULong max,
          CORBA::ULong length,
          char ** buffer, 
          CORBA::Boolean release = 0
        );
      NameList (const NameList &);
      ~NameList (void);
      
      typedef NameList_var _var_type;
    };

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:44
    
    static ::CORBA::TypeCode_ptr const _tc_NameList;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::RTScheduling::Current::NameList * current_scheduling_segment_names (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Current (void);
    
    virtual ~Current (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Current (const Current &);
    
    void operator= (const Current &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_RTScheduler_Export ::CORBA::TypeCode_ptr const _tc_Current;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_RTSCHEDULING_RESOURCEMANAGER__VAR_OUT_CH_)
#define _RTSCHEDULING_RESOURCEMANAGER__VAR_OUT_CH_
  
  class ResourceManager;
  typedef ResourceManager *ResourceManager_ptr;
  
  typedef
    TAO_Objref_Var_T<
        ResourceManager
      >
    ResourceManager_var;
  
  typedef
    TAO_Objref_Out_T<
        ResourceManager
      >
    ResourceManager_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_RTSCHEDULING_RESOURCEMANAGER_CH_)
#define _RTSCHEDULING_RESOURCEMANAGER_CH_
  
  class TAO_RTScheduler_Export ResourceManager
    : public virtual ::RTCORBA::Mutex
  {
  public:
    typedef ResourceManager_ptr _ptr_type;
    typedef ResourceManager_var _var_type;
    
    // The static operations.
    static ResourceManager_ptr _duplicate (ResourceManager_ptr obj);
    
    static void _tao_release (ResourceManager_ptr obj);
    
    static ResourceManager_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ResourceManager_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static ResourceManager_ptr _nil (void)
    {
      return static_cast<ResourceManager_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ResourceManager (void);
    
    virtual ~ResourceManager (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ResourceManager (const ResourceManager &);
    
    void operator= (const ResourceManager &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_RTScheduler_Export ::CORBA::TypeCode_ptr const _tc_ResourceManager;
  
  // TAO_IDL - Generated from
  // be\be_interface.cpp:598

#if !defined (_RTSCHEDULING_SCHEDULER__VAR_OUT_CH_)
#define _RTSCHEDULING_SCHEDULER__VAR_OUT_CH_
  
  class Scheduler;
  typedef Scheduler *Scheduler_ptr;
  
  typedef
    TAO_Objref_Var_T<
        Scheduler
      >
    Scheduler_var;
  
  typedef
    TAO_Objref_Out_T<
        Scheduler
      >
    Scheduler_out;

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_RTSCHEDULING_SCHEDULER_CH_)
#define _RTSCHEDULING_SCHEDULER_CH_
  
  class TAO_RTScheduler_Export Scheduler
    : public virtual CORBA::Object
  {
  public:
    typedef Scheduler_ptr _ptr_type;
    typedef Scheduler_var _var_type;
    
    // The static operations.
    static Scheduler_ptr _duplicate (Scheduler_ptr obj);
    
    static void _tao_release (Scheduler_ptr obj);
    
    static Scheduler_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Scheduler_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Scheduler_ptr _nil (void)
    {
      return static_cast<Scheduler_ptr> (0);
    }
    
    
    
    // TAO_IDL - Generated from
    // be\be_visitor_exception/exception_ch.cpp:53

#if !defined (_RTSCHEDULING_SCHEDULER_INCOMPATIBLE_SCHEDULING_DISCIPLINES_CH_)
#define _RTSCHEDULING_SCHEDULER_INCOMPATIBLE_SCHEDULING_DISCIPLINES_CH_
    
    class TAO_RTScheduler_Export INCOMPATIBLE_SCHEDULING_DISCIPLINES : public CORBA::UserException
    {
    public:
      
      INCOMPATIBLE_SCHEDULING_DISCIPLINES (void);
      INCOMPATIBLE_SCHEDULING_DISCIPLINES (const INCOMPATIBLE_SCHEDULING_DISCIPLINES &);
      ~INCOMPATIBLE_SCHEDULING_DISCIPLINES (void);

      INCOMPATIBLE_SCHEDULING_DISCIPLINES &operator= (const INCOMPATIBLE_SCHEDULING_DISCIPLINES &);
      
      static INCOMPATIBLE_SCHEDULING_DISCIPLINES *_downcast (CORBA::Exception *);
      static const INCOMPATIBLE_SCHEDULING_DISCIPLINES *_downcast (CORBA::Exception const *);
      
      static CORBA::Exception *_alloc (void);
      
      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL
        ) const;
      
      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL
        );
      
      // TAO_IDL - Generated from
      // be\be_visitor_exception/exception_ch.cpp:129
      
      virtual CORBA::TypeCode_ptr _tao_type (void) const;
    };
    
    // TAO_IDL - Generated from
    // be\be_visitor_typecode/typecode_decl.cpp:44
    
    static ::CORBA::TypeCode_ptr const _tc_INCOMPATIBLE_SCHEDULING_DISCIPLINES;

#endif /* end #if !defined */
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::PolicyList * scheduling_policies (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void scheduling_policies (
        const ::CORBA::PolicyList & scheduling_policies
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CORBA::PolicyList * poa_policies (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * scheduling_discipline_name (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual ::RTScheduling::ResourceManager_ptr create_resource_manager (
        const char * name,
        ::CORBA::Policy_ptr scheduling_parameter
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void set_scheduling_parameter (
        ::PortableServer::Servant & resource,
        const char * name,
        ::CORBA::Policy_ptr scheduling_parameter
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void begin_new_scheduling_segment (
        const ::RTScheduling::Current::IdType & guid,
        const char * name,
        ::CORBA::Policy_ptr sched_param,
        ::CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void begin_nested_scheduling_segment (
        const ::RTScheduling::Current::IdType & guid,
        const char * name,
        ::CORBA::Policy_ptr sched_param,
        ::CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void update_scheduling_segment (
        const ::RTScheduling::Current::IdType & guid,
        const char * name,
        ::CORBA::Policy_ptr sched_param,
        ::CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void end_scheduling_segment (
        const ::RTScheduling::Current::IdType & guid,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void end_nested_scheduling_segment (
        const ::RTScheduling::Current::IdType & guid,
        const char * name,
        ::CORBA::Policy_ptr outer_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void send_request (
        ::PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void receive_request (
        ::PortableInterceptor::ServerRequestInfo_ptr ri,
        ::RTScheduling::Current::IdType_out guid,
        CORBA::String_out name,
        ::CORBA::Policy_out sched_param,
        ::CORBA::Policy_out implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void send_reply (
        ::PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void send_exception (
        ::PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void send_other (
        ::PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void send_poll (
        ::PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void receive_reply (
        ::PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void receive_exception (
        ::PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void receive_other (
        ::PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        ::PortableInterceptor::ForwardRequest
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void cancel (
        const ::RTScheduling::Current::IdType & guid
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // be\be_visitor_interface/interface_ch.cpp:210
    
    virtual CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Scheduler (void);
    
    virtual ~Scheduler (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Scheduler (const Scheduler &);
    
    void operator= (const Scheduler &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // be\be_visitor_typecode/typecode_decl.cpp:44
  
  extern TAO_RTScheduler_Export ::CORBA::TypeCode_ptr const _tc_Scheduler;

// TAO_IDL - Generated from
// be\be_visitor_module/module_ch.cpp:66

} // module RTScheduling

// TAO_IDL - Generated from
// be\be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_RTSCHEDULING_THREADACTION__TRAITS_CH_)
#define _RTSCHEDULING_THREADACTION__TRAITS_CH_
  
  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::ThreadAction>
  {
    static ::RTScheduling::ThreadAction_ptr duplicate (
        ::RTScheduling::ThreadAction_ptr
      );
    static void release (
        ::RTScheduling::ThreadAction_ptr
      );
    static ::RTScheduling::ThreadAction_ptr nil (void);
    static CORBA::Boolean marshal (
        ::RTScheduling::ThreadAction_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_RTSCHEDULING_DISTRIBUTABLETHREAD__TRAITS_CH_)
#define _RTSCHEDULING_DISTRIBUTABLETHREAD__TRAITS_CH_
  
  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::DistributableThread>
  {
    static ::RTScheduling::DistributableThread_ptr duplicate (
        ::RTScheduling::DistributableThread_ptr
      );
    static void release (
        ::RTScheduling::DistributableThread_ptr
      );
    static ::RTScheduling::DistributableThread_ptr nil (void);
    static CORBA::Boolean marshal (
        ::RTScheduling::DistributableThread_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_RTSCHEDULING_CURRENT__TRAITS_CH_)
#define _RTSCHEDULING_CURRENT__TRAITS_CH_
  
  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::Current>
  {
    static ::RTScheduling::Current_ptr duplicate (
        ::RTScheduling::Current_ptr
      );
    static void release (
        ::RTScheduling::Current_ptr
      );
    static ::RTScheduling::Current_ptr nil (void);
    static CORBA::Boolean marshal (
        ::RTScheduling::Current_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_RTSCHEDULING_RESOURCEMANAGER__TRAITS_CH_)
#define _RTSCHEDULING_RESOURCEMANAGER__TRAITS_CH_
  
  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::ResourceManager>
  {
    static ::RTScheduling::ResourceManager_ptr duplicate (
        ::RTScheduling::ResourceManager_ptr
      );
    static void release (
        ::RTScheduling::ResourceManager_ptr
      );
    static ::RTScheduling::ResourceManager_ptr nil (void);
    static CORBA::Boolean marshal (
        ::RTScheduling::ResourceManager_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_RTSCHEDULING_SCHEDULER__TRAITS_CH_)
#define _RTSCHEDULING_SCHEDULER__TRAITS_CH_
  
  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::Scheduler>
  {
    static ::RTScheduling::Scheduler_ptr duplicate (
        ::RTScheduling::Scheduler_ptr
      );
    static void release (
        ::RTScheduling::Scheduler_ptr
      );
    static ::RTScheduling::Scheduler_ptr nil (void);
    static CORBA::Boolean marshal (
        ::RTScheduling::Scheduler_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be\be_codegen.cpp:955

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"

#endif /* ifndef */


