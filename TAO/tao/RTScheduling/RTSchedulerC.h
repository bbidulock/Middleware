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
// be/be_codegen.cpp:151

#ifndef _TAO_IDL_RTSCHEDULERC_H_
#define _TAO_IDL_RTSCHEDULERC_H_

#include /**/ "ace/pre.h"

#include "tao/corba.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "rtscheduler_export.h"

#include "tao/RTCORBA/RTCORBA.h"
#include "tao/PortableServer/PortableServerC.h"
#include "tao/PortableInterceptorC.h"

#ifndef TAO_RTSCHEDULER_SAFE_INCLUDE
#error "You should not include RTSchedulerC.h directly, use RTScheduler.h"
#endif /* !TAO_RTSCHEDULER_SAFE_INCLUDE */


#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_RTScheduler_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_RTScheduler_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  CORBA
{

  typedef void* VoidData;
// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module CORBA

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  RTScheduling
{

  // TAO_IDL - Generated from
  // be/be_interface.cpp:570

#if !defined (_RTSCHEDULING_THREADACTION__ODDS_N_ENDS_CH_)
#define _RTSCHEDULING_THREADACTION__ODDS_N_ENDS_CH_

  class ThreadAction;
  typedef ThreadAction *ThreadAction_ptr;
  struct tao_ThreadAction_life;

  typedef
    TAO_Objref_Var_T<
        ThreadAction,
        tao_ThreadAction_life
      >
    ThreadAction_var;

  typedef
    TAO_Objref_Out_T<
        ThreadAction,
        tao_ThreadAction_life
      >
    ThreadAction_out;

  struct TAO_RTScheduler_Export tao_ThreadAction_life
  {
    static ThreadAction_ptr tao_duplicate (ThreadAction_ptr);
    static void tao_release (ThreadAction_ptr);
    static ThreadAction_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        ThreadAction_ptr,
        TAO_OutputCDR &
      );
  };

  struct TAO_RTScheduler_Export tao_ThreadAction_cast
  {
    static ThreadAction_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:50

#if !defined (_RTSCHEDULING_THREADACTION_CH_)
#define _RTSCHEDULING_THREADACTION_CH_

  class TAO_RTScheduler_Export ThreadAction
    : public virtual CORBA::Object
  {
  public:
    typedef ThreadAction_ptr _ptr_type;
    typedef ThreadAction_var _var_type;
    static int _tao_class_id;

    // The static operations.
    static ThreadAction_ptr _duplicate (ThreadAction_ptr obj);

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
        return (ThreadAction_ptr)0;
      }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void _cxx_do (
        CORBA::VoidData data
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:207

    virtual void *_tao_QueryInterface (ptrdiff_t type);

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    ThreadAction (void);
    virtual ~ThreadAction (void);

  private:
    ThreadAction (const ThreadAction &);
    void operator= (const ThreadAction &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ThreadAction;

  // TAO_IDL - Generated from
  // be/be_interface.cpp:570

#if !defined (_RTSCHEDULING_DISTRIBUTABLETHREAD__ODDS_N_ENDS_CH_)
#define _RTSCHEDULING_DISTRIBUTABLETHREAD__ODDS_N_ENDS_CH_

  class DistributableThread;
  typedef DistributableThread *DistributableThread_ptr;
  struct tao_DistributableThread_life;

  typedef
    TAO_Objref_Var_T<
        DistributableThread,
        tao_DistributableThread_life
      >
    DistributableThread_var;

  typedef
    TAO_Objref_Out_T<
        DistributableThread,
        tao_DistributableThread_life
      >
    DistributableThread_out;

  struct TAO_RTScheduler_Export tao_DistributableThread_life
  {
    static DistributableThread_ptr tao_duplicate (DistributableThread_ptr);
    static void tao_release (DistributableThread_ptr);
    static DistributableThread_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        DistributableThread_ptr,
        TAO_OutputCDR &
      );
  };

  struct TAO_RTScheduler_Export tao_DistributableThread_cast
  {
    static DistributableThread_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:50

#if !defined (_RTSCHEDULING_DISTRIBUTABLETHREAD_CH_)
#define _RTSCHEDULING_DISTRIBUTABLETHREAD_CH_

  class TAO_RTScheduler_Export DistributableThread
    : public virtual CORBA::Object
  {
  public:
    typedef DistributableThread_ptr _ptr_type;
    typedef DistributableThread_var _var_type;
    static int _tao_class_id;

    // The static operations.
    static DistributableThread_ptr _duplicate (DistributableThread_ptr obj);

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
        return (DistributableThread_ptr)0;
      }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_enum/enum_ch.cpp:57

    enum DT_State
    {
      ACTIVE,
      CANCELLED
    };

    typedef DT_State &DT_State_out;

    // TAO_IDL - Generated from
    // be/be_visitor_typecode/typecode_decl.cpp:44

    static ::CORBA::TypeCode_ptr _tc_DT_State;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void cancel (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::RTScheduling::DistributableThread::DT_State state (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:207

    virtual void *_tao_QueryInterface (ptrdiff_t type);

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    DistributableThread (void);
    virtual ~DistributableThread (void);

  private:
    DistributableThread (const DistributableThread &);
    void operator= (const DistributableThread &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_DistributableThread;

  // TAO_IDL - Generated from
  // be/be_interface.cpp:570

#if !defined (_RTSCHEDULING_CURRENT__ODDS_N_ENDS_CH_)
#define _RTSCHEDULING_CURRENT__ODDS_N_ENDS_CH_

  class Current;
  typedef Current *Current_ptr;
  struct tao_Current_life;

  typedef
    TAO_Objref_Var_T<
        Current,
        tao_Current_life
      >
    Current_var;

  typedef
    TAO_Objref_Out_T<
        Current,
        tao_Current_life
      >
    Current_out;

  struct TAO_RTScheduler_Export tao_Current_life
  {
    static Current_ptr tao_duplicate (Current_ptr);
    static void tao_release (Current_ptr);
    static Current_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        Current_ptr,
        TAO_OutputCDR &
      );
  };

  struct TAO_RTScheduler_Export tao_Current_cast
  {
    static Current_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:50

  /*
#if !defined (_RTSCHEDULING_CURRENT___VAR_CH_)
#define _RTSCHEDULING_CURRENT___VAR_CH_

  // TAO_IDL - Generated from
  // C:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:571


  class TAO_RTScheduler_Export Current_var : public TAO_Base_var
  {
  public:
    Current_var (void); // default constructor
    Current_var (Current_ptr p) : ptr_ (p) {}
    Current_var (const Current_var &); // copy constructor
    ~Current_var (void); // destructor

    Current_var &operator= (Current_ptr);
    Current_var &operator= (const Current_var &);
    Current_ptr operator-> (void) const;

    operator const Current_ptr &() const;
    operator Current_ptr &();
    // in, inout, out, _retn
    Current_ptr in (void) const;
    Current_ptr &inout (void);
    Current_ptr &out (void);
    Current_ptr _retn (void);
    Current_ptr ptr (void) const;

    // Hooks used by template sequence and object manager classes
    // for non-defined forward declared interfaces.
    static Current_ptr tao_duplicate (Current_ptr);
    static void tao_release (Current_ptr);
    static Current_ptr tao_nil (void);
    static Current_ptr tao_narrow (
        CORBA::Object *
        ACE_ENV_ARG_DECL_NOT_USED
      );
    static CORBA::Object * tao_upcast (void *);

  private:
    Current_ptr ptr_;
    // Unimplemented - prevents widening assignment.
    Current_var (const TAO_Base_var &rhs);
    Current_var &operator= (const TAO_Base_var &rhs);
  };

  #endif */ /* end #if !defined */

#if !defined (_RTSCHEDULING_CURRENT_CH_)
#define _RTSCHEDULING_CURRENT_CH_

  class TAO_RTScheduler_Export Current
    : public virtual RTCORBA::Current
  {
  public:
    typedef Current_ptr _ptr_type;
    typedef Current_var _var_type;
    static int _tao_class_id;

    // The static operations.
    static Current_ptr _duplicate (Current_ptr obj);

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
        return (Current_ptr)0;
      }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::RTScheduling::DistributableThread_ptr spawn (
        RTScheduling::ThreadAction_ptr start,
        CORBA::VoidData data,
        const char * name,
        CORBA::Policy_ptr sched_param,
        CORBA::Policy_ptr implicit_sched_param,
        CORBA::ULong stack_size,
        RTCORBA::Priority base_priority
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_exception/exception_ch.cpp:51

#if !defined (_RTSCHEDULING_CURRENT_UNSUPPORTED_SCHEDULING_DISCIPLINE_CH_)
#define _RTSCHEDULING_CURRENT_UNSUPPORTED_SCHEDULING_DISCIPLINE_CH_

    class TAO_RTScheduler_Export UNSUPPORTED_SCHEDULING_DISCIPLINE : public CORBA::UserException
    {
    public:

      UNSUPPORTED_SCHEDULING_DISCIPLINE (void);
      UNSUPPORTED_SCHEDULING_DISCIPLINE (const UNSUPPORTED_SCHEDULING_DISCIPLINE &);
      ~UNSUPPORTED_SCHEDULING_DISCIPLINE (void);

      UNSUPPORTED_SCHEDULING_DISCIPLINE &operator= (const UNSUPPORTED_SCHEDULING_DISCIPLINE &);

      static void _tao_any_destructor (void *);

      static UNSUPPORTED_SCHEDULING_DISCIPLINE *_downcast (CORBA::Exception *);
      static CORBA::Exception *_alloc (void);

      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        ) const;

      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        );

      // TAO_IDL - Generated from
      // be/be_visitor_exception/exception_ch.cpp:125

      virtual CORBA::TypeCode_ptr _type (void) const;
    };

    // TAO_IDL - Generated from
    // be/be_visitor_typecode/typecode_decl.cpp:44

    static ::CORBA::TypeCode_ptr _tc_UNSUPPORTED_SCHEDULING_DISCIPLINE;

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void begin_scheduling_segment (
        const char * name,
        CORBA::Policy_ptr sched_param,
        CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void update_scheduling_segment (
        const char * name,
        CORBA::Policy_ptr sched_param,
        CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void end_scheduling_segment (
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_sequence/sequence_ch.cpp:91

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

      static void _tao_any_destructor (void *);

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
    // be/be_visitor_typecode/typecode_decl.cpp:44

    static ::CORBA::TypeCode_ptr _tc_IdType;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::RTScheduling::Current::IdType * id (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::RTScheduling::DistributableThread_ptr lookup (
        const RTScheduling::Current::IdType & id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::CORBA::Policy_ptr scheduling_parameter (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::CORBA::Policy_ptr implicit_scheduling_parameter (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_sequence/sequence_ch.cpp:91

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

      static void _tao_any_destructor (void *);

      typedef NameList_var _var_type;
    };

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be/be_visitor_typecode/typecode_decl.cpp:44

    static ::CORBA::TypeCode_ptr _tc_NameList;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::RTScheduling::Current::NameList * current_scheduling_segment_names (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:207

    virtual void *_tao_QueryInterface (ptrdiff_t type);

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    Current (void);
    virtual ~Current (void);

  private:
    Current (const Current &);
    void operator= (const Current &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Current;

  // TAO_IDL - Generated from
  // be/be_interface.cpp:570

#if !defined (_RTSCHEDULING_RESOURCEMANAGER__ODDS_N_ENDS_CH_)
#define _RTSCHEDULING_RESOURCEMANAGER__ODDS_N_ENDS_CH_

  class ResourceManager;
  typedef ResourceManager *ResourceManager_ptr;
  struct tao_ResourceManager_life;

  typedef
    TAO_Objref_Var_T<
        ResourceManager,
        tao_ResourceManager_life
      >
    ResourceManager_var;

  typedef
    TAO_Objref_Out_T<
        ResourceManager,
        tao_ResourceManager_life
      >
    ResourceManager_out;

  struct TAO_RTScheduler_Export tao_ResourceManager_life
  {
    static ResourceManager_ptr tao_duplicate (ResourceManager_ptr);
    static void tao_release (ResourceManager_ptr);
    static ResourceManager_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        ResourceManager_ptr,
        TAO_OutputCDR &
      );
  };

  struct TAO_RTScheduler_Export tao_ResourceManager_cast
  {
    static ResourceManager_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:50

#if !defined (_RTSCHEDULING_RESOURCEMANAGER_CH_)
#define _RTSCHEDULING_RESOURCEMANAGER_CH_

  class TAO_RTScheduler_Export ResourceManager
    : public virtual RTCORBA::Mutex
  {
  public:
    typedef ResourceManager_ptr _ptr_type;
    typedef ResourceManager_var _var_type;
    static int _tao_class_id;

    // The static operations.
    static ResourceManager_ptr _duplicate (ResourceManager_ptr obj);

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
        return (ResourceManager_ptr)0;
      }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:207

    virtual void *_tao_QueryInterface (ptrdiff_t type);

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    ResourceManager (void);
    virtual ~ResourceManager (void);

  private:
    ResourceManager (const ResourceManager &);
    void operator= (const ResourceManager &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ResourceManager;

  // TAO_IDL - Generated from
  // be/be_interface.cpp:570

#if !defined (_RTSCHEDULING_SCHEDULER__ODDS_N_ENDS_CH_)
#define _RTSCHEDULING_SCHEDULER__ODDS_N_ENDS_CH_

  class Scheduler;
  typedef Scheduler *Scheduler_ptr;
  struct tao_Scheduler_life;

  typedef
    TAO_Objref_Var_T<
        Scheduler,
        tao_Scheduler_life
      >
    Scheduler_var;

  typedef
    TAO_Objref_Out_T<
        Scheduler,
        tao_Scheduler_life
      >
    Scheduler_out;

  struct TAO_RTScheduler_Export tao_Scheduler_life
  {
    static Scheduler_ptr tao_duplicate (Scheduler_ptr);
    static void tao_release (Scheduler_ptr);
    static Scheduler_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        Scheduler_ptr,
        TAO_OutputCDR &
      );
  };

  struct TAO_RTScheduler_Export tao_Scheduler_cast
  {
    static Scheduler_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:50

#if !defined (_RTSCHEDULING_SCHEDULER_CH_)
#define _RTSCHEDULING_SCHEDULER_CH_

  class TAO_RTScheduler_Export Scheduler
    : public virtual CORBA::Object
  {
  public:
    typedef Scheduler_ptr _ptr_type;
    typedef Scheduler_var _var_type;
    static int _tao_class_id;

    // The static operations.
    static Scheduler_ptr _duplicate (Scheduler_ptr obj);

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
        return (Scheduler_ptr)0;
      }

    static void _tao_any_destructor (void *);

    // TAO_IDL - Generated from
    // be/be_visitor_exception/exception_ch.cpp:51

#if !defined (_RTSCHEDULING_SCHEDULER_INCOMPATIBLE_SCHEDULING_DISCIPLINES_CH_)
#define _RTSCHEDULING_SCHEDULER_INCOMPATIBLE_SCHEDULING_DISCIPLINES_CH_

    class TAO_RTScheduler_Export INCOMPATIBLE_SCHEDULING_DISCIPLINES : public CORBA::UserException
    {
    public:

      INCOMPATIBLE_SCHEDULING_DISCIPLINES (void);
      INCOMPATIBLE_SCHEDULING_DISCIPLINES (const INCOMPATIBLE_SCHEDULING_DISCIPLINES &);
      ~INCOMPATIBLE_SCHEDULING_DISCIPLINES (void);

      INCOMPATIBLE_SCHEDULING_DISCIPLINES &operator= (const INCOMPATIBLE_SCHEDULING_DISCIPLINES &);

      static void _tao_any_destructor (void *);

      static INCOMPATIBLE_SCHEDULING_DISCIPLINES *_downcast (CORBA::Exception *);
      static CORBA::Exception *_alloc (void);

      virtual CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (
          TAO_OutputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        ) const;

      virtual void _tao_decode (
          TAO_InputCDR &
          ACE_ENV_ARG_DECL_NOT_USED
        );

      // TAO_IDL - Generated from
      // be/be_visitor_exception/exception_ch.cpp:125

      virtual CORBA::TypeCode_ptr _type (void) const;
    };

    // TAO_IDL - Generated from
    // be/be_visitor_typecode/typecode_decl.cpp:44

    static ::CORBA::TypeCode_ptr _tc_INCOMPATIBLE_SCHEDULING_DISCIPLINES;

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::CORBA::PolicyList * scheduling_policies (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void scheduling_policies (
        const CORBA::PolicyList & scheduling_policies
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::CORBA::PolicyList * poa_policies (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual char * scheduling_discipline_name (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::RTScheduling::ResourceManager_ptr create_resource_manager (
        const char * name,
        CORBA::Policy_ptr scheduling_parameter
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void set_scheduling_parameter (
        PortableServer::Servant & resource,
        const char * name,
        CORBA::Policy_ptr scheduling_parameter
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void begin_new_scheduling_segment (
        const RTScheduling::Current::IdType & guid,
        const char * name,
        CORBA::Policy_ptr sched_param,
        CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void begin_nested_scheduling_segment (
        const RTScheduling::Current::IdType & guid,
        const char * name,
        CORBA::Policy_ptr sched_param,
        CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void update_scheduling_segment (
        const RTScheduling::Current::IdType & guid,
        const char * name,
        CORBA::Policy_ptr sched_param,
        CORBA::Policy_ptr implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void end_scheduling_segment (
        const RTScheduling::Current::IdType & guid,
        const char * name
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void end_nested_scheduling_segment (
        const RTScheduling::Current::IdType & guid,
        const char * name,
        CORBA::Policy_ptr outer_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void send_request (
        PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void receive_request (
        PortableInterceptor::ServerRequestInfo_ptr ri,
        RTScheduling::Current::IdType_out guid,
        CORBA::String_out name,
        CORBA::Policy_out sched_param,
        CORBA::Policy_out implicit_sched_param
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void send_reply (
        PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void send_exception (
        PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void send_other (
        PortableInterceptor::ServerRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void receive_reply (
        PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void receive_exception (
        PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void receive_other (
        PortableInterceptor::ClientRequestInfo_ptr ri
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , PortableInterceptor::ForwardRequest
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void cancel (
        const RTScheduling::Current::IdType & guid
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:207

    virtual void *_tao_QueryInterface (ptrdiff_t type);

    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    Scheduler (void);
    virtual ~Scheduler (void);

  private:
    Scheduler (const Scheduler &);
    void operator= (const Scheduler &);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_Scheduler;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module RTScheduling

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::ThreadAction_ptr); // copying
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::ThreadAction_ptr *); // non-copying
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::ThreadAction_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::DistributableThread_ptr); // copying
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::DistributableThread_ptr *); // non-copying
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::DistributableThread_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_enum/any_op_ch.cpp:51

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::DistributableThread::DT_State);
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::DistributableThread::DT_State &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::Current_ptr); // copying
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::Current_ptr *); // non-copying
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::Current_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, const RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE &); // copying version
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE*); // noncopying version
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE *&); // deprecated
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, const RTScheduling::Current::UNSUPPORTED_SCHEDULING_DISCIPLINE *&);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, const RTScheduling::Current::IdType &); // copying version
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::Current::IdType*); // noncopying version
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::Current::IdType *&); // deprecated
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, const RTScheduling::Current::IdType *&);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, const RTScheduling::Current::NameList &); // copying version
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::Current::NameList*); // noncopying version
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::Current::NameList *&); // deprecated
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, const RTScheduling::Current::NameList *&);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::ResourceManager_ptr); // copying
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::ResourceManager_ptr *); // non-copying
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::ResourceManager_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::Scheduler_ptr); // copying
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::Scheduler_ptr *); // non-copying
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::Scheduler_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_exception/any_op_ch.cpp:52

TAO_RTScheduler_Export void operator<<= (CORBA::Any &, const RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES &); // copying version
TAO_RTScheduler_Export void operator<<= (CORBA::Any &, RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES*); // noncopying version
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES *&); // deprecated
TAO_RTScheduler_Export CORBA::Boolean operator>>= (const CORBA::Any &, const RTScheduling::Scheduler::INCOMPATIBLE_SCHEDULING_DISCIPLINES *&);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "RTSchedulerC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */
