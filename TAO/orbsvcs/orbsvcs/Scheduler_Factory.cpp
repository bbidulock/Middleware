// $Id$

#include "ace/OS.h"

#include "orbsvcs/Runtime_Scheduler.h"
#include "orbsvcs/Scheduler_Factory.h"

#if ! defined (__ACE_INLINE__)
#include "orbsvcs/Scheduler_Factory.i"
#endif /* __ACE_INLINE__ */

RtecScheduler::Scheduler_ptr ACE_Scheduler_Factory::server_ = 0;

static int entry_count = -1;
static ACE_Scheduler_Factory::POD_RT_Info* rt_info = 0;

int ACE_Scheduler_Factory::use_runtime (int ec,
                                        POD_RT_Info rti[])
{
  if (server_ != 0 || entry_count != -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factory::use_runtime - "
                         "server already configured\n"), -1);
    }

  entry_count = ec;
  rt_info = rti;

  return 0;
}

RtecScheduler::Scheduler_ptr static_server ()
{
  RtecScheduler::Scheduler_ptr server_ = 0;

  typedef RtecScheduler::RT_Info* RT_Info_ptr;
  RtecScheduler::RT_Info** info;
  ACE_NEW_RETURN (info, RT_Info_ptr[entry_count], 0);
  for (int i = 0; i < entry_count; ++i)
    {
      info[i] = new RtecScheduler::RT_Info;
      if (info[i] == 0)
        {
          for (int j = 0; j < i; ++j)
            {
              delete info[i];
            }
          delete[] info;
          ACE_ERROR_RETURN ((LM_ERROR,
                             "ACE_Scheduler_Factory::config_runtime - "
                             "cannot allocate RT_Info\n"), 0);
        }
      info[i]->entry_point = rt_info[i].entry_point;
      info[i]->handle = rt_info[i].handle;
      info[i]->worst_case_execution_time = rt_info[i].worst_case_execution_time;
      info[i]->typical_execution_time = rt_info[i].typical_execution_time;
      info[i]->cached_execution_time = rt_info[i].cached_execution_time;
      info[i]->period = rt_info[i].period;
      info[i]->importance = rt_info[i].importance;
      info[i]->quantum = rt_info[i].quantum;
      info[i]->threads = rt_info[i].threads;
      info[i]->priority = rt_info[i].priority;
      info[i]->static_subpriority = rt_info[i].static_subpriority;
      info[i]->preemption_priority = rt_info[i].preemption_priority;
    }
  static ACE_Runtime_Scheduler scheduler(entry_count, info);
  TAO_TRY
    {
      server_ = scheduler._this (TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_DEBUG ((LM_DEBUG,
                  "ACE_Scheduler_Factory - configured static server\n"));
    }
  TAO_CATCHANY
    {
      for (int i = 0; i < entry_count; ++i)
        {
          delete info[i];
        }
      delete[] info;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factory::config_runtime - "
                         "cannot allocate server\n"), 0);
    }
  TAO_ENDTRY;
  return server_;
}

int
ACE_Scheduler_Factory::use_config (CosNaming::NamingContext_ptr naming)
{
  if (server_ != 0 || entry_count != -1)
    {
      // No errors, runtime execution simply takes precedence over
      // config runs.
      return 0;
    }

  TAO_TRY
    {
      CosNaming::Name schedule_name (1);
      schedule_name[0].id = CORBA::string_dup ("ScheduleService");
      schedule_name.length (1);
      CORBA::Object_ptr objref =
        naming->resolve (schedule_name, TAO_TRY_ENV);
      TAO_CHECK_ENV;

      server_ =
        RtecScheduler::Scheduler::_narrow(objref, TAO_TRY_ENV);
      TAO_CHECK_ENV;

      RtecScheduler::Scheduler::_duplicate (server_);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      server_ = 0;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factory::use_context - "
                         " exception while resolving server\n"), -1);
    }
  TAO_ENDTRY;
  return 0;
}

int
ACE_Scheduler_Factory::use_config (CORBA::ORB_ptr orb)
{
  if (server_ != 0 || entry_count != -1)
    {
      // No errors, runtime execution simply takes precedence over
      // config runs.
      return 0;
    }

  TAO_TRY
    {
      CORBA::Object_ptr objref =
        orb->resolve_initial_references ("ScheduleService");
      TAO_CHECK_ENV;

      server_ =
        RtecScheduler::Scheduler::_narrow(objref, TAO_TRY_ENV);
      TAO_CHECK_ENV;

      RtecScheduler::Scheduler::_duplicate (server_);
      TAO_CHECK_ENV;
    }
  TAO_CATCHANY
    {
      server_ = 0;
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factory::use_context - "
                         " exception while resolving server\n"), -1);
    }
  TAO_ENDTRY;
  return 0;
}


RtecScheduler::Scheduler_ptr
ACE_Scheduler_Factory::server (void)
{
  if (server_ == 0 && entry_count != -1)
    {
      server_ = static_server ();
    }

  if (server_ == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "ACE_Scheduler_Factor::server - "
                         "no scheduling service configured\n"), 0);
    }
  return server_;
}

static char header[] =
"// This file was automatically generated by Scheduler_Factory\n"
"// before editing the file please consider generating it again\n"
"\n"
"#include \"orbsvcs/Scheduler_Factory.h\"\n"
"\n";

static char footer[] =
"\n"
"// This setups Scheduler_Factory to use the runtime version\n"
"static int scheduler_factory_setup = \n"
"  ACE_Scheduler_Factory::use_runtime (sizeof (infos)/sizeof (infos[0]),\n"
"                                      infos);\n"
"\n"
"// EOF\n";

static char start_infos[] =
"static ACE_Scheduler_Factory::POD_RT_Info infos[] = {\n";

static char end_infos[] =
"};\n";

int ACE_Scheduler_Factory::dump_schedule
    (const RtecScheduler::RT_Info_Set& infos,
     const char* filename)
{
  FILE* file = stdout;
  if (filename != 0)
    {
      file = ACE_OS::fopen (filename, "w");
      if (file == 0)
        {
          return -1;
        }
    }
  ACE_OS::fprintf(file, header);

  ACE_OS::fprintf(file, start_infos);
  for (u_int i = 0; i < infos.length (); ++i)
    {
      if (i != 0)
        {
          // Finish previous line
          ACE_OS::fprintf(file, ",\n");
        }
      const RtecScheduler::RT_Info& info = infos[i];
      ACE_OS::fprintf (file,
"{ \"%s\", %d, %f, %f, %f, %d, %d, %f, %d, %d, %d, %d }",
                       (const char*)info.entry_point,
                       info.handle,
                       info.worst_case_execution_time,
                       info.typical_execution_time,
                       info.cached_execution_time,
                       info.period,
                       info.importance,
                       info.quantum,
                       info.threads,
                       info.priority,
                       info.static_subpriority,
                       info.preemption_priority);
    }
  // finish last line.
  ACE_OS::fprintf(file, "\n");
  ACE_OS::fprintf(file, end_infos);
  ACE_OS::fprintf(file, footer);
  ACE_OS::fclose (file);
  return 0;
}
