// -*- C++ -*-

//=============================================================================
/**
 *  @file    FTRMFF_Bestfit.cpp
 *
 *  $Id$
 *
 *  @author  Friedhelm Wolf (fwolf@dre.vanderbilt.edu)
 */
//=============================================================================

#include <sstream>
#include "FTRMFF_Bestfit.h"

#include "Forward_Ranking_Scheduler.h"
#include "Packing_Scheduler.h"

FTRMFF_Bestfit::~FTRMFF_Bestfit ()
{
}

FTRMFF_Output
FTRMFF_Bestfit::operator () (const FTRMFF_Input & input)
{
  FTRMFF_Bestfit_Algorithm algorithm (input.processors,
                                      input.backup_count);

  FTRMFF_Output output;
  output.schedule = algorithm (input.tasks);
  output.unscheduled_tasks = algorithm.get_unschedulable ();

  DBG_OUT (algorithm.schedule ());

  return output;
}

FTRMFF_Bestfit_Algorithm::FTRMFF_Bestfit_Algorithm (
  const PROCESSOR_LIST & processors,
  unsigned int consistency_level)
  : FTRMFF_Algorithm_Impl (consistency_level),
    scheduler_ (processors,
                consistency_level_)
{
  // fill last_results data structure
  ScheduleResult result = { {"NoTask", .0, .0, .0, PRIMARY, 0}, 
                            "NO PROCESSOR", 
                            .0};

  for (PROCESSOR_LIST::const_iterator it = processors.begin ();
       it != processors.end ();
       ++it)
    {
      result.processor = *it;
      last_results_[*it] = result;
    }
}

FTRMFF_Bestfit_Algorithm::~FTRMFF_Bestfit_Algorithm ()
{
}

SCHEDULING_MAP
FTRMFF_Bestfit_Algorithm::operator () (const TASK_LIST & tasks)
{  
  // sort tasks based on their periods, which results in a priority
  // ordered list since we do rate monotonic scheduling
  TASK_LIST sorted_input = tasks;

  std::sort (sorted_input.begin (), 
	     sorted_input.end (), 
	     PeriodComparison <Task> ());

  for (TASK_LIST::iterator it = sorted_input.begin ();
       it != sorted_input.end ();
       ++it)
    {
      // create the right amount of backup replica tasks
      TASK_LIST task_group = create_ranked_tasks (*it,
                                                  consistency_level_);

      // schedule the tasks of one application
      for (TASK_LIST::iterator task_it = task_group.begin ();
           task_it != task_group.end ();
           ++task_it)
        {
          PROCESSOR_LIST processors = this->best_processors ();

          ScheduleResult schedule_result;
          for (PROCESSOR_LIST::iterator p_it = processors.begin ();
               p_it != processors.end ();
               ++p_it)
            {
              TRACE (*task_it << " on " << *p_it);

              schedule_result = scheduler_ (*task_it, *p_it);
              if (schedule_result.wcrt > .0)
                {
                  break;
                }
            }

          if (schedule_result.wcrt <= .0)
            {
              ScheduleProgress pg = {*task_it, 
                                     task_it->rank - consistency_level_ + 1};
              unschedulable_.push_back (pg);
              break;
            }
          else
            {
              scheduler_.update_schedule (schedule_result);
              last_results_[schedule_result.processor] = schedule_result;
            }
          
          
          TRACE (*task_it << " -> " << schedule_result.processor);
        }
    }

  return transform_schedule (scheduler_.schedule ());
}

const SCHEDULE &
FTRMFF_Bestfit_Algorithm::schedule () const
{
  return scheduler_.schedule ();
}

struct ScheduleResultComparison : public std::binary_function <
  RESULT_MAP::value_type, 
  RESULT_MAP::value_type,
  bool>
{
  bool operator () (const RESULT_MAP::value_type & r1, 
                    const RESULT_MAP::value_type & r2)
  {
    return (r1.second.wcrt > r2.second.wcrt);
  }
};

struct ProcessorAccumulator : public std::unary_function <
  RESULT_MAP::value_type,
  Processor>
{
public:
  Processor operator () (const RESULT_MAP::value_type & entry)
  {
    return entry.second.processor;
  }
};

typedef std::pair <Processor, ScheduleResult> RESULT_PAIR;

PROCESSOR_LIST 
FTRMFF_Bestfit_Algorithm::best_processors (void)
{
  TRACE ("last_results: " << last_results_.size ());

  std::vector <RESULT_PAIR> entries;
  std::copy (last_results_.begin (),
             last_results_.end (),
             std::inserter (entries,
                            entries.begin ()));

  std::sort (entries.begin (),
             entries.end (),
             ScheduleResultComparison ());

  TRACE ("entries : " << entries.size ());

  PROCESSOR_LIST result;
  std::transform (entries.begin (),
                  entries.end (),
                  std::inserter (result,
                                 result.begin ()),
                  ProcessorAccumulator ());

  return result;
}
