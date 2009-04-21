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

#include "FTRMFF_Bestfit.h"
#include "FTRMFF_Primary.h"
#include "FTRMFF_Basic.h"
#include "CTT_Enhanced.h"

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

  return output;
}

FTRMFF_Bestfit_Algorithm::FTRMFF_Bestfit_Algorithm (
  const PROCESSOR_LIST & processors,
  unsigned int consistency_level)
  : processors_ (processors),
    consistency_level_ (consistency_level)
{
}

FTRMFF_Bestfit_Algorithm::~FTRMFF_Bestfit_Algorithm ()
{
}

SCHEDULING_MAP
FTRMFF_Bestfit_Algorithm::operator () (const TASK_LIST & tasks)
{
  // step one, only schedule primaries to get lower bound
  FTRMFF_Primary_Algorithm primary_ftrmff (processors_);

  primary_ftrmff (tasks);

  unsigned long minimum = 
    processor_usage (primary_ftrmff.schedule ());

  std::cout << minimum << " ";

  // step two, schedule replicas with only state synchronization times
  CTT_Enhanced ctt_enhanced;
  FTRMFF_Basic_Algorithm only_ss_ftrmff (processors_,
                                         consistency_level_,
                                         ctt_enhanced);

  only_ss_ftrmff (tasks);
  
  unsigned long lower_bound = 
    processor_usage (only_ss_ftrmff.schedule ());

  std::cout << lower_bound << " ";

  // step three, schedule all replicas as active
  CTT_Basic ctt_basic;
  FTRMFF_Basic_Algorithm active_ftrmff (processors_,
                                        consistency_level_,
                                        ctt_basic);

  active_ftrmff (tasks);
  
  unsigned long upper_bound = 
    processor_usage (active_ftrmff.schedule ());

  std::cout << upper_bound << std::endl;

  return SCHEDULING_MAP ();
}

SCHEDULE_PROGRESS_LIST
FTRMFF_Bestfit_Algorithm::get_unschedulable ()
{
  return unschedulable_;
}
