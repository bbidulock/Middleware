// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#if !defined (_TAO_IDL_RTECSCHEDULERC_H_)
#define _TAO_IDL_RTECSCHEDULERC_H_

#include "tao/corba.h"

class RtecScheduler{
public:
  typedef CORBA::Double Time;typedef CORBA::Double_out Time_out;

  static CORBA::TypeCode_ptr _tc_Time;

  typedef CORBA::Long Period;typedef CORBA::Long_out Period_out;

  static CORBA::TypeCode_ptr _tc_Period;

  typedef ACE_NESTED_CLASS (RtecScheduler,Time) Quantum;typedef ACE_NESTED_CLASS (RtecScheduler,Time_out) Quantum_out;

  static CORBA::TypeCode_ptr _tc_Quantum;

  static const CORBA::Long NO_QUANTUM;

  enum Importance
  {
    VERY_LOW, 
    LOW, 
    MEDIUM, 
    HIGH, 
    VERY_HIGH
  };
  typedef Importance &Importance_out;
  static CORBA::TypeCode_ptr _tc_Importance;

  typedef CORBA::Long handle_t;typedef CORBA::Long_out handle_t_out;

  static CORBA::TypeCode_ptr _tc_handle_t;

  struct Dependency_Info
  {
    CORBA::Long number_of_calls;

    ACE_NESTED_CLASS (RtecScheduler,handle_t) rt_info;

  };

  class Dependency_Info_var
  {
  public:
    Dependency_Info_var (void); // default constructor
    Dependency_Info_var (Dependency_Info *);
    Dependency_Info_var (const Dependency_Info_var &); // copy constructor
    ~Dependency_Info_var (void); // destructor
    
    Dependency_Info_var &operator= (Dependency_Info *);
    Dependency_Info_var &operator= (const Dependency_Info_var &);
    Dependency_Info *operator-> (void);
    const Dependency_Info *operator-> (void) const;
    
    operator const Dependency_Info &() const;
    operator Dependency_Info &();
    operator Dependency_Info &() const;
    // in, inout, out, _retn 
    const Dependency_Info &in (void) const;
    Dependency_Info &inout (void);
    Dependency_Info &out (void);
    Dependency_Info _retn (void);
    Dependency_Info *ptr(void) const;

  private:
    Dependency_Info *ptr_;
  };

  typedef Dependency_Info &Dependency_Info_out;

  static CORBA::TypeCode_ptr _tc_Dependency_Info;


#if !defined (_RTECSCHEDULER__TAO__SEQ_DEPENDENCY_SET_CH_)
#define _RTECSCHEDULER__TAO__SEQ_DEPENDENCY_SET_CH_

  // *************************************************************
  // class _tao__seq_Dependency_Set
  // *************************************************************
  
  class _tao__seq_Dependency_Set
  {
  public:
    _tao__seq_Dependency_Set (void); // default constructor
    _tao__seq_Dependency_Set (CORBA::ULong max);
    _tao__seq_Dependency_Set (CORBA::ULong max, CORBA::ULong length, 
    	ACE_NESTED_CLASS (RtecScheduler,Dependency_Info) *value, CORBA::Boolean release=CORBA::B_FALSE);
    _tao__seq_Dependency_Set(const _tao__seq_Dependency_Set &); // copy constructor
    ~_tao__seq_Dependency_Set (void);
    _tao__seq_Dependency_Set &operator= (const _tao__seq_Dependency_Set &);
    CORBA::ULong maximum (void) const;
    void length (CORBA::ULong);
    CORBA::ULong length (void) const;
    ACE_NESTED_CLASS (RtecScheduler,Dependency_Info) &operator[] (CORBA::ULong index);
    const ACE_NESTED_CLASS (RtecScheduler,Dependency_Info) &operator[] (CORBA::ULong index) const;
    static ACE_NESTED_CLASS (RtecScheduler,Dependency_Info) *allocbuf (CORBA::ULong nelems);
    static void freebuf (ACE_NESTED_CLASS (RtecScheduler,Dependency_Info) *);
  private:
    CORBA::ULong maximum_;
    CORBA::ULong length_;
    ACE_NESTED_CLASS (RtecScheduler,Dependency_Info) *buffer_;
    CORBA::Boolean release_;
  };
  typedef _tao__seq_Dependency_Set* _tao__seq_Dependency_Set_ptr;
  static CORBA::TypeCode_ptr _tc__tao__seq_Dependency_Set;


#endif // end #if !defined


#if !defined (_RTECSCHEDULER__TAO__SEQ_DEPENDENCY_SET___VAR_CH_)
#define _RTECSCHEDULER__TAO__SEQ_DEPENDENCY_SET___VAR_CH_

// *************************************************************
  // class RtecScheduler::_tao__seq_Dependency_Set_var
  // *************************************************************

  class _tao__seq_Dependency_Set_var
  {
  public:
    _tao__seq_Dependency_Set_var (void); // default constructor
    _tao__seq_Dependency_Set_var (_tao__seq_Dependency_Set *);
    _tao__seq_Dependency_Set_var (const _tao__seq_Dependency_Set_var &); // copy constructor
    ~_tao__seq_Dependency_Set_var (void); // destructor
    
    _tao__seq_Dependency_Set_var &operator= (_tao__seq_Dependency_Set *);
    _tao__seq_Dependency_Set_var &operator= (const _tao__seq_Dependency_Set_var &);
    _tao__seq_Dependency_Set *operator-> (void);
    const _tao__seq_Dependency_Set *operator-> (void) const;
    
    operator const _tao__seq_Dependency_Set &() const;
    operator _tao__seq_Dependency_Set &();
    operator _tao__seq_Dependency_Set &() const;
    ACE_NESTED_CLASS (RtecScheduler,Dependency_Info) &operator[] (CORBA::ULong index);
    // in, inout, out, _retn 
    const _tao__seq_Dependency_Set &in (void) const;
    _tao__seq_Dependency_Set &inout (void);
    _tao__seq_Dependency_Set *&out (void);
    _tao__seq_Dependency_Set *_retn (void);
    _tao__seq_Dependency_Set *ptr (void) const;

  private:
    _tao__seq_Dependency_Set *ptr_;
  };


#endif // end #if !defined


#if !defined (_RTECSCHEDULER__TAO__SEQ_DEPENDENCY_SET___OUT_CH_)
#define _RTECSCHEDULER__TAO__SEQ_DEPENDENCY_SET___OUT_CH_

  class _tao__seq_Dependency_Set_out
  {
  public:
    _tao__seq_Dependency_Set_out (_tao__seq_Dependency_Set *&);
    _tao__seq_Dependency_Set_out (_tao__seq_Dependency_Set_var &);
    _tao__seq_Dependency_Set_out (_tao__seq_Dependency_Set_out &);
    _tao__seq_Dependency_Set_out &operator= (_tao__seq_Dependency_Set_out &);
    _tao__seq_Dependency_Set_out &operator= (_tao__seq_Dependency_Set *);
    operator _tao__seq_Dependency_Set *&();
    _tao__seq_Dependency_Set *&ptr (void);
    _tao__seq_Dependency_Set *operator-> (void);
    ACE_NESTED_CLASS (RtecScheduler,Dependency_Info) &operator[] (CORBA::ULong index);
    
  private:
    _tao__seq_Dependency_Set *&ptr_;
    // assignment from T_var not allowed
    void operator= (const _tao__seq_Dependency_Set_var &);
  };


#endif // end #if !defined

  typedef ACE_NESTED_CLASS (RtecScheduler,_tao__seq_Dependency_Set) Dependency_Set;
  typedef ACE_NESTED_CLASS (RtecScheduler,_tao__seq_Dependency_Set_var) Dependency_Set_var;
  typedef ACE_NESTED_CLASS (RtecScheduler,_tao__seq_Dependency_Set_out) Dependency_Set_out;

  static CORBA::TypeCode_ptr _tc_Dependency_Set;

  typedef CORBA::Long OS_Priority;typedef CORBA::Long_out OS_Priority_out;

  static CORBA::TypeCode_ptr _tc_OS_Priority;

  typedef CORBA::Long Sub_Priority;typedef CORBA::Long_out Sub_Priority_out;

  static CORBA::TypeCode_ptr _tc_Sub_Priority;

  typedef CORBA::Long Preemption_Priority;typedef CORBA::Long_out Preemption_Priority_out;

  static CORBA::TypeCode_ptr _tc_Preemption_Priority;

  struct RT_Info
  {
    CORBA::String_var entry_point;

    ACE_NESTED_CLASS (RtecScheduler,handle_t) handle;

    ACE_NESTED_CLASS (RtecScheduler,Time) worst_case_execution_time;

    ACE_NESTED_CLASS (RtecScheduler,Time) typical_execution_time;

    ACE_NESTED_CLASS (RtecScheduler,Time) cached_execution_time;

    ACE_NESTED_CLASS (RtecScheduler,Period) period;

    ACE_NESTED_CLASS (RtecScheduler,Importance) importance;

    ACE_NESTED_CLASS (RtecScheduler,Quantum) quantum;

    CORBA::Long threads;

    ACE_NESTED_CLASS (RtecScheduler,Dependency_Set) dependencies;

    ACE_NESTED_CLASS (RtecScheduler,OS_Priority) priority;

    ACE_NESTED_CLASS (RtecScheduler,Sub_Priority) subpriority;

    ACE_NESTED_CLASS (RtecScheduler,Preemption_Priority) preemption_priority;

  };

  class RT_Info_var
  {
  public:
    RT_Info_var (void); // default constructor
    RT_Info_var (RT_Info *);
    RT_Info_var (const RT_Info_var &); // copy constructor
    ~RT_Info_var (void); // destructor
    
    RT_Info_var &operator= (RT_Info *);
    RT_Info_var &operator= (const RT_Info_var &);
    RT_Info *operator-> (void);
    const RT_Info *operator-> (void) const;
    
    operator const RT_Info &() const;
    operator RT_Info &();
    operator RT_Info &() const;
    // in, inout, out, _retn 
    const RT_Info &in (void) const;
    RT_Info &inout (void);
    RT_Info *&out (void);
    RT_Info *_retn (void);
    RT_Info *ptr(void) const;

  private:
    RT_Info *ptr_;
  };

  class RT_Info_out
  {
  public:
    RT_Info_out (RT_Info *&);
    RT_Info_out (RT_Info_var &);
    RT_Info_out (const RT_Info_out &);
    RT_Info_out &operator= (const RT_Info_out &);
    RT_Info_out &operator= (RT_Info *);
    operator RT_Info *&();
    RT_Info *&ptr (void);
    RT_Info *operator-> (void);
    
  private:
    RT_Info *&ptr_;
    // assignment from T_var not allowed
    void operator= (const RT_Info_var &);
  };

  static CORBA::TypeCode_ptr _tc_RT_Info;

  
#if !defined (_RTECSCHEDULER_DUPLICATE_NAME___PTR_CH_)
#define _RTECSCHEDULER_DUPLICATE_NAME___PTR_CH_

  class DUPLICATE_NAME;
  typedef DUPLICATE_NAME *DUPLICATE_NAME_ptr;
  
#endif // end #if !defined


#if !defined (_RTECSCHEDULER_DUPLICATE_NAME_CH_)
#define _RTECSCHEDULER_DUPLICATE_NAME_CH_

  class DUPLICATE_NAME : public virtual CORBA::UserException
  {
  public:
      DUPLICATE_NAME (void);
  };
  
  
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_DUPLICATE_NAME;

  
#if !defined (_RTECSCHEDULER_UNKNOWN_TASK___PTR_CH_)
#define _RTECSCHEDULER_UNKNOWN_TASK___PTR_CH_

  class UNKNOWN_TASK;
  typedef UNKNOWN_TASK *UNKNOWN_TASK_ptr;
  
#endif // end #if !defined


#if !defined (_RTECSCHEDULER_UNKNOWN_TASK_CH_)
#define _RTECSCHEDULER_UNKNOWN_TASK_CH_

  class UNKNOWN_TASK : public virtual CORBA::UserException
  {
  public:
      UNKNOWN_TASK (void);
  };
  
  
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_UNKNOWN_TASK;

  
#if !defined (_RTECSCHEDULER_NOT_SCHEDULED___PTR_CH_)
#define _RTECSCHEDULER_NOT_SCHEDULED___PTR_CH_

  class NOT_SCHEDULED;
  typedef NOT_SCHEDULED *NOT_SCHEDULED_ptr;
  
#endif // end #if !defined


#if !defined (_RTECSCHEDULER_NOT_SCHEDULED_CH_)
#define _RTECSCHEDULER_NOT_SCHEDULED_CH_

  class NOT_SCHEDULED : public virtual CORBA::UserException
  {
  public:
      NOT_SCHEDULED (void);
  };
  
  
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_NOT_SCHEDULED;

  
#if !defined (_RTECSCHEDULER_UTILIZATION_BOUND_EXCEEDED___PTR_CH_)
#define _RTECSCHEDULER_UTILIZATION_BOUND_EXCEEDED___PTR_CH_

  class UTILIZATION_BOUND_EXCEEDED;
  typedef UTILIZATION_BOUND_EXCEEDED *UTILIZATION_BOUND_EXCEEDED_ptr;
  
#endif // end #if !defined


#if !defined (_RTECSCHEDULER_UTILIZATION_BOUND_EXCEEDED_CH_)
#define _RTECSCHEDULER_UTILIZATION_BOUND_EXCEEDED_CH_

  class UTILIZATION_BOUND_EXCEEDED : public virtual CORBA::UserException
  {
  public:
      UTILIZATION_BOUND_EXCEEDED (void);
  };
  
  
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_UTILIZATION_BOUND_EXCEEDED;

  
#if !defined (_RTECSCHEDULER_INSUFFICIENT_THREAD_PRIORITY_LEVELS___PTR_CH_)
#define _RTECSCHEDULER_INSUFFICIENT_THREAD_PRIORITY_LEVELS___PTR_CH_

  class INSUFFICIENT_THREAD_PRIORITY_LEVELS;
  typedef INSUFFICIENT_THREAD_PRIORITY_LEVELS *INSUFFICIENT_THREAD_PRIORITY_LEVELS_ptr;
  
#endif // end #if !defined


#if !defined (_RTECSCHEDULER_INSUFFICIENT_THREAD_PRIORITY_LEVELS_CH_)
#define _RTECSCHEDULER_INSUFFICIENT_THREAD_PRIORITY_LEVELS_CH_

  class INSUFFICIENT_THREAD_PRIORITY_LEVELS : public virtual CORBA::UserException
  {
  public:
      INSUFFICIENT_THREAD_PRIORITY_LEVELS (void);
  };
  
  
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_INSUFFICIENT_THREAD_PRIORITY_LEVELS;

  
#if !defined (_RTECSCHEDULER_TASK_COUNT_MISMATCH___PTR_CH_)
#define _RTECSCHEDULER_TASK_COUNT_MISMATCH___PTR_CH_

  class TASK_COUNT_MISMATCH;
  typedef TASK_COUNT_MISMATCH *TASK_COUNT_MISMATCH_ptr;
  
#endif // end #if !defined


#if !defined (_RTECSCHEDULER_TASK_COUNT_MISMATCH_CH_)
#define _RTECSCHEDULER_TASK_COUNT_MISMATCH_CH_

  class TASK_COUNT_MISMATCH : public virtual CORBA::UserException
  {
  public:
      TASK_COUNT_MISMATCH (void);
  };
  
  
#endif // end #if !defined

static CORBA::TypeCode_ptr _tc_TASK_COUNT_MISMATCH;


#if !defined (_RTECSCHEDULER__TAO__SEQ_RT_INFO_SET_CH_)
#define _RTECSCHEDULER__TAO__SEQ_RT_INFO_SET_CH_

  // *************************************************************
  // class _tao__seq_RT_Info_Set
  // *************************************************************
  
  class _tao__seq_RT_Info_Set
  {
  public:
    _tao__seq_RT_Info_Set (void); // default constructor
    _tao__seq_RT_Info_Set (CORBA::ULong max);
    _tao__seq_RT_Info_Set (CORBA::ULong max, CORBA::ULong length, 
    	ACE_NESTED_CLASS (RtecScheduler,RT_Info) *value, CORBA::Boolean release=CORBA::B_FALSE);
    _tao__seq_RT_Info_Set(const _tao__seq_RT_Info_Set &); // copy constructor
    ~_tao__seq_RT_Info_Set (void);
    _tao__seq_RT_Info_Set &operator= (const _tao__seq_RT_Info_Set &);
    CORBA::ULong maximum (void) const;
    void length (CORBA::ULong);
    CORBA::ULong length (void) const;
    ACE_NESTED_CLASS (RtecScheduler,RT_Info) &operator[] (CORBA::ULong index);
    const ACE_NESTED_CLASS (RtecScheduler,RT_Info) &operator[] (CORBA::ULong index) const;
    static ACE_NESTED_CLASS (RtecScheduler,RT_Info) *allocbuf (CORBA::ULong nelems);
    static void freebuf (ACE_NESTED_CLASS (RtecScheduler,RT_Info) *);
  private:
    CORBA::ULong maximum_;
    CORBA::ULong length_;
    ACE_NESTED_CLASS (RtecScheduler,RT_Info) *buffer_;
    CORBA::Boolean release_;
  };
  typedef _tao__seq_RT_Info_Set* _tao__seq_RT_Info_Set_ptr;
  static CORBA::TypeCode_ptr _tc__tao__seq_RT_Info_Set;


#endif // end #if !defined


#if !defined (_RTECSCHEDULER__TAO__SEQ_RT_INFO_SET___VAR_CH_)
#define _RTECSCHEDULER__TAO__SEQ_RT_INFO_SET___VAR_CH_

// *************************************************************
  // class RtecScheduler::_tao__seq_RT_Info_Set_var
  // *************************************************************

  class _tao__seq_RT_Info_Set_var
  {
  public:
    _tao__seq_RT_Info_Set_var (void); // default constructor
    _tao__seq_RT_Info_Set_var (_tao__seq_RT_Info_Set *);
    _tao__seq_RT_Info_Set_var (const _tao__seq_RT_Info_Set_var &); // copy constructor
    ~_tao__seq_RT_Info_Set_var (void); // destructor
    
    _tao__seq_RT_Info_Set_var &operator= (_tao__seq_RT_Info_Set *);
    _tao__seq_RT_Info_Set_var &operator= (const _tao__seq_RT_Info_Set_var &);
    _tao__seq_RT_Info_Set *operator-> (void);
    const _tao__seq_RT_Info_Set *operator-> (void) const;
    
    operator const _tao__seq_RT_Info_Set &() const;
    operator _tao__seq_RT_Info_Set &();
    operator _tao__seq_RT_Info_Set &() const;
    ACE_NESTED_CLASS (RtecScheduler,RT_Info) &operator[] (CORBA::ULong index);
    // in, inout, out, _retn 
    const _tao__seq_RT_Info_Set &in (void) const;
    _tao__seq_RT_Info_Set &inout (void);
    _tao__seq_RT_Info_Set *&out (void);
    _tao__seq_RT_Info_Set *_retn (void);
    _tao__seq_RT_Info_Set *ptr (void) const;

  private:
    _tao__seq_RT_Info_Set *ptr_;
  };


#endif // end #if !defined


#if !defined (_RTECSCHEDULER__TAO__SEQ_RT_INFO_SET___OUT_CH_)
#define _RTECSCHEDULER__TAO__SEQ_RT_INFO_SET___OUT_CH_

  class _tao__seq_RT_Info_Set_out
  {
  public:
    _tao__seq_RT_Info_Set_out (_tao__seq_RT_Info_Set *&);
    _tao__seq_RT_Info_Set_out (_tao__seq_RT_Info_Set_var &);
    _tao__seq_RT_Info_Set_out (const _tao__seq_RT_Info_Set_out &);
    _tao__seq_RT_Info_Set_out &operator= (const _tao__seq_RT_Info_Set_out &);
    _tao__seq_RT_Info_Set_out &operator= (_tao__seq_RT_Info_Set *);
    operator _tao__seq_RT_Info_Set *&();
    _tao__seq_RT_Info_Set *&ptr (void);
    _tao__seq_RT_Info_Set *operator-> (void);
    ACE_NESTED_CLASS (RtecScheduler,RT_Info) &operator[] (CORBA::ULong index);
    
  private:
    _tao__seq_RT_Info_Set *&ptr_;
    // assignment from T_var not allowed
    void operator= (const _tao__seq_RT_Info_Set_var &);
  };


#endif // end #if !defined

  typedef ACE_NESTED_CLASS (RtecScheduler,_tao__seq_RT_Info_Set) RT_Info_Set;
  typedef ACE_NESTED_CLASS (RtecScheduler,_tao__seq_RT_Info_Set_var) RT_Info_Set_var;
  typedef ACE_NESTED_CLASS (RtecScheduler,_tao__seq_RT_Info_Set_out) RT_Info_Set_out;

  static CORBA::TypeCode_ptr _tc_RT_Info_Set;

  
#if !defined (_RTECSCHEDULER_SCHEDULER___PTR_CH_)
#define _RTECSCHEDULER_SCHEDULER___PTR_CH_

class Scheduler;
  typedef Scheduler *Scheduler_ptr;
  
#endif // end #if !defined


#if !defined (_RTECSCHEDULER_SCHEDULER_CH_)
#define _RTECSCHEDULER_SCHEDULER_CH_

class Scheduler: public virtual ACE_CORBA_1 (Object)
  {
  public:
    // the static operations
    static Scheduler_ptr _duplicate (Scheduler_ptr obj);
    static Scheduler_ptr _narrow (CORBA::Object_ptr obj, CORBA::Environment &env);
    static Scheduler_ptr _nil (void);
    static Scheduler_ptr _bind (const char *host, CORBA::UShort port, const char *key, CORBA::Environment &env);

    virtual RtecScheduler::handle_t create (const char *entry_point, CORBA::Environment &env);
    virtual RtecScheduler::handle_t lookup (const char *entry_point, CORBA::Environment &env);
    virtual ACE_NESTED_CLASS (RtecScheduler,RT_Info) * get (ACE_NESTED_CLASS (RtecScheduler,handle_t) handle, CORBA::Environment &env);
    virtual void set (ACE_NESTED_CLASS (RtecScheduler,handle_t) handle, ACE_NESTED_CLASS (RtecScheduler,Time) time, ACE_NESTED_CLASS (RtecScheduler,Time) typical_time, ACE_NESTED_CLASS (RtecScheduler,Time) cached_time, ACE_NESTED_CLASS (RtecScheduler,Period) period, ACE_NESTED_CLASS (RtecScheduler,Importance) importance, ACE_NESTED_CLASS (RtecScheduler,Quantum) quantum, CORBA::Long threads, CORBA::Environment &env);
    virtual void add_dependency (ACE_NESTED_CLASS (RtecScheduler,handle_t) handle, ACE_NESTED_CLASS (RtecScheduler,handle_t) dependency, CORBA::Long number_of_calls, CORBA::Environment &env);
    virtual void priority (ACE_NESTED_CLASS (RtecScheduler,handle_t) handle, ACE_NESTED_CLASS (RtecScheduler,OS_Priority_out) priority, ACE_NESTED_CLASS (RtecScheduler,Sub_Priority_out) subpriority, ACE_NESTED_CLASS (RtecScheduler,Preemption_Priority_out) p_priority, CORBA::Environment &env);
    virtual void entry_point_priority (const char *entry_point, ACE_NESTED_CLASS (RtecScheduler,OS_Priority_out) priority, ACE_NESTED_CLASS (RtecScheduler,Sub_Priority_out) subpriority, ACE_NESTED_CLASS (RtecScheduler,Preemption_Priority_out) p_priority, CORBA::Environment &env);
    virtual void compute_scheduling (CORBA::Long minimum_priority, CORBA::Long maximum_priority, ACE_NESTED_CLASS (RtecScheduler,RT_Info_Set_out) infos, CORBA::Environment &env);
  protected:
    Scheduler (void); // default constructor
    Scheduler (STUB_Object *objref);
    virtual ~Scheduler (void);
  private:
    Scheduler (const Scheduler&);
    void operator= (const Scheduler&);
  };


#endif // end #if !defined


#if !defined (_RTECSCHEDULER_SCHEDULER___VAR_CH_)
#define _RTECSCHEDULER_SCHEDULER___VAR_CH_

  class Scheduler_var
  {
  public:
    Scheduler_var (void); // default constructor
    Scheduler_var (Scheduler_ptr);
    Scheduler_var (const Scheduler_var &); // copy constructor
    ~Scheduler_var (void); // destructor
    
    Scheduler_var &operator= (Scheduler_ptr);
    Scheduler_var &operator= (const Scheduler_var &);
    Scheduler_ptr operator-> (void) const;
    
    operator const Scheduler_ptr &() const;
    operator Scheduler_ptr &();
    // in, inout, out, _retn 
    Scheduler_ptr in (void) const;
    Scheduler_ptr &inout (void);
    Scheduler_ptr &out (void);
    Scheduler_ptr _retn (void);
    Scheduler_ptr ptr (void) const;

  private:
    Scheduler_ptr ptr_;
  };


#endif // end #if !defined


#if !defined (_RTECSCHEDULER_SCHEDULER___OUT_CH_)
#define _RTECSCHEDULER_SCHEDULER___OUT_CH_

  class Scheduler_out
  {
  public:
    Scheduler_out (Scheduler_ptr &);
    Scheduler_out (Scheduler_var &);
    Scheduler_out (Scheduler_out &);
    Scheduler_out &operator= (Scheduler_out &);
    Scheduler_out &operator= (const Scheduler_var &);
    Scheduler_out &operator= (Scheduler_ptr);
    operator Scheduler_ptr &();
    Scheduler_ptr &ptr (void);
    Scheduler_ptr operator-> (void);
    
  private:
    Scheduler_ptr &ptr_;
  };


#endif // end #if !defined

  static CORBA::TypeCode_ptr _tc_Scheduler;

};


#if defined (__ACE_INLINE__)
#include "RtecSchedulerC.i"
#endif // defined INLINE


#endif // if !defined
