// -*- C++ -*-
// $Id$

//=============================================================================
/**
 * @file  SA_PlanStrategy.cpp
 *
 * This file contains the implementation of the SA_PlanStrategy concrete class,
 * which implements a PlanStrategy for use with spreading activation networks
 * and precedence graphs.
 *
 * @author  John S. Kinnebrew <john.s.kinnebrew@vanderbilt.edu>
 */
//=============================================================================

#include <set>
#include "SA_POP_Types.h"
#include "SA_PlanStrategy.h"
#include "Planner.h"
#include "PlanHeuristics.h"
#include "PlanCommands.h"

using namespace SA_POP;

// Constructor.
SA_PlanStrategy::SA_PlanStrategy (SA_POP::Planner *planner,
  CondStrategy *cond_choice, TaskStrategy *task_choice,
  ImplStrategy *impl_choice)
: PlanStrategy (planner),
has_cmds_ (false),
cur_task_ (SA_POP::NULL_TASK_ID),
cur_task_inst_ (SA_POP::NULL_TASK_ID),
cur_step_ (0),
cur_decision_pt_ (SA_POP::SA_PlanStrategy::TASK_DECISION),
cur_seq_num_ (1),
cond_choice_ (cond_choice),
task_choice_ (task_choice),
impl_choice_ (impl_choice),
add_conds_cmd_ (0),
rmv_conds_cmd_ (0),
add_threats_cmd_ (0),
rmv_threats_cmd_ (0),
add_task_cmd_ (0),
assoc_impl_cmd_ (0),
resolve_threat_cmd_ (0)
{
  this->add_conds_cmd_ = new SA_AddOpenCondsCmd (this);
  this->rmv_conds_cmd_ = new SA_RemoveOpenCondsCmd (this);
  this->add_threats_cmd_ = new SA_AddOpenThreatsCmd (this);
  this->rmv_threats_cmd_ = new SA_RemoveOpenThreatsCmd (this);
  this->open_conds_.clear ();
  this->open_threats_.clear ();
};

// Destructor.
SA_PlanStrategy::~SA_PlanStrategy (void)
{
  // Delete heuristic strategies.
  delete this->cond_choice_;
  delete this->task_choice_;
  delete this->impl_choice_;
};

void SA_PlanStrategy::reset()
{
  has_cmds_ = false;
  cur_task_ = SA_POP::NULL_TASK_ID;
  cur_task_inst_ = SA_POP::NULL_TASK_ID;
  cur_step_ = 0;
  cur_decision_pt_ = SA_POP::SA_PlanStrategy::TASK_DECISION;
  cur_seq_num_ = 1;
  this->add_conds_cmd_ = new SA_AddOpenCondsCmd (this);
  this->rmv_conds_cmd_ = new SA_RemoveOpenCondsCmd (this);
  this->add_threats_cmd_ = new SA_AddOpenThreatsCmd (this);
  this->rmv_threats_cmd_ = new SA_RemoveOpenThreatsCmd (this);
  this->open_conds_.clear ();
  this->open_threats_.clear ();
};

// Set command prototypes to use in planning.
void SA_PlanStrategy::set_commands (AddTaskCmd *add_task_cmd,
  AssocTaskImplCmd *assoc_impl_cmd,
  ResolveCLThreatCmd *resolve_threat_cmd)
{
  this->has_cmds_ = true;

  if (add_task_cmd)
    this->add_task_cmd_ = add_task_cmd;
  else if (this->add_task_cmd_ == 0)
    this->has_cmds_ = false;

  if (assoc_impl_cmd)
    this->assoc_impl_cmd_ = assoc_impl_cmd;
  else if (this->assoc_impl_cmd_ == 0)
    this->has_cmds_ = false;

  if (resolve_threat_cmd)
    this->resolve_threat_cmd_ = resolve_threat_cmd;
  else if (this->resolve_threat_cmd_ == 0)
    this->has_cmds_ = false;
};

// Set goals.
void SA_PlanStrategy::set_goals (GoalMap goals)
{
  for (SA_POP::GoalMap::iterator iter = goals.begin ();
    iter != goals.end (); iter++)
  {
    Condition cond;
    cond.id = iter->first;
    if (iter->second > 0)
      cond.value = true;
    else
      cond.value = false;
    //****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP
    // Get type of condition.
    cond.kind = SA_POP::SYSTEM;

    this->open_conds_.insert (std::make_pair (cond, SA_POP::GOAL_TASK_INST_ID));
  }
};

// Get command ID to use for next command.
CommandID SA_PlanStrategy::get_next_cmd_id (void)
{
  CommandID temp;
  temp.step = this->cur_step_;
  temp.decision_pt = this->cur_decision_pt_;
  temp.seq_num = this->cur_seq_num_;

  this->cur_seq_num_++;
  return temp;
};

// Recursively satisfy all open conditions (including recursive
// scheduling constraint satisfaction through call back).
bool SA_PlanStrategy::satisfy_open_conds (void)
{
  // If all open conditions have been satisfied, then return true for success.
  if (this->open_conds_.empty ())
	  return this->planner_->full_sched();

  // Increment step counter.
  this->cur_step_++;

  // Set decision point and reset sequence number for commands.
  this->cur_decision_pt_ = SA_PlanStrategy::TASK_DECISION;
  this->cur_seq_num_ = 1;

  // Variable for preconditions of current task.
  CondSet preconds;

  // Choose an open condition to satisfy.
  Condition open_cond = this->cond_choice_->choose_cond (this->open_conds_);

  // Choose task to satisfy open condition (actually an ordered list of
  // tasks to try), passing command to planner to be executed next.
  AddTaskCmd *add_task_cmd = this->satisfy_cond (open_cond);

  // Try tasks until one yields a complete plan or all have been tried.
  while (this->planner_->try_next (add_task_cmd->get_id ())) {
    // Get current task and task instance.
    this->cur_task_ = add_task_cmd->get_task ();
    this->cur_task_inst_ = add_task_cmd->get_task_inst ();
    // Remove open condition.
    CommandID rmv_cond_cmd_id = this->rmv_open_cond (open_cond);

    // Add preconditions of this task of we didn't reuse the task instance.
	    CommandID add_preconds_cmd_id;
	if(!add_task_cmd->inst_exists())
	{
	preconds = this->planner_->get_unsat_preconds (this->cur_task_);
    add_preconds_cmd_id = 
      this->add_open_conds (preconds, this->cur_task_inst_);
	}
    // Set decision point and reset sequence number for commands.
    this->cur_decision_pt_ = SA_PlanStrategy::THREAT_DECISION;
    this->cur_seq_num_ = 1;

    // Add causal link threats to open threats.
    bool are_threats = !this->planner_->get_all_threats ().empty ();
    CommandID add_threats_cmd_id;
    if (are_threats)
      add_threats_cmd_id = 
        this->add_open_threats (this->planner_->get_all_threats ());

    // Try to satisfy threats and continue recursive planning.
    if (this->satisfy_open_threats ())
      return true;

    SA_POP_DEBUG(SA_POP_DEBUG_NORMAL, "Backtracking from task addition...");
    // Undo addition of causal link threats from this task.
    if (are_threats)
      this->planner_->undo_command (add_threats_cmd_id);
    std::cout<<" the task instance being deleted is "<<add_task_cmd->get_task_inst()<<std::endl;
    // Undo addition of preconditions from this task if we didn't reuse the task instance.
	if(!add_task_cmd->inst_exists())
		this->planner_->undo_command (add_preconds_cmd_id);

    // Undo removal of open condition.
    this->planner_->undo_command (rmv_cond_cmd_id);

  }

  SA_POP_DEBUG (SA_POP_DEBUG_NORMAL, "Backtracking to previous step...");
  // Undo addition of task.
  this->planner_->undo_command (add_task_cmd->get_id ());

  // Decrement step.
  this->cur_step_--;

  // No task could satisfy open condition, so return failure.
  return false;
};

// Get a PlanCommand prototype for adding open conditions,
// which works on this strategy.
AddOpenCondsCmd *SA_PlanStrategy::get_AddOpenCondsCmd (void)
{
  return static_cast<AddOpenCondsCmd *> (this->add_conds_cmd_->clone ());
};

// Get a PlanCommand prototype for removing open conditions,
// which works on this strategy.
RemoveOpenCondsCmd *SA_PlanStrategy::get_RemoveOpenCondsCmd (void)
{
  return static_cast<RemoveOpenCondsCmd *> (this->rmv_conds_cmd_->clone ());
};

// Get an command prototype for adding causal link threats, which works on
// this strategy.
AddOpenThreatsCmd *SA_PlanStrategy::get_AddOpenThreatsCmd (void)
{
  return static_cast<AddOpenThreatsCmd *> (this->add_threats_cmd_->clone ());
};

// Get a PlanCommand prototype for removing causal link threats,
// which works on this strategy.
RemoveOpenThreatsCmd *SA_PlanStrategy::get_RemoveOpenThreatsCmd (void)
{
  return static_cast<RemoveOpenThreatsCmd *> (this->rmv_threats_cmd_->clone ());
};

// Execute a command to add open conditions to planning.
void SA_PlanStrategy::execute (SA_AddOpenCondsCmd *cmd)
{
  for (CondSet::iterator iter = cmd->conds_.begin ();
    iter != cmd->conds_.end (); iter++)
  {
    this->open_conds_.insert (std::make_pair (*iter, cmd->task_inst_));
  }
};

// Undo a command to add open conditions to planning.
void SA_PlanStrategy::undo (SA_AddOpenCondsCmd *cmd)
{
  // Remove open conditions mapped to the specified task instance.
	std::cout<<"removing open conds mapped to "<<cmd->task_inst_<<std::endl;
	for (CondSet::iterator cond_iter = cmd->conds_.begin ();
    cond_iter != cmd->conds_.end (); cond_iter++)
  {
	  std::cout<<"checking for "<<cond_iter->id<<std::endl;
	  for (OpenCondMap::iterator open_iter =
      this->open_conds_.lower_bound (*cond_iter);
      open_iter != this->open_conds_.upper_bound (*cond_iter);)
    {
      OpenCondMap::iterator prev_iter = open_iter;
      open_iter++;
      if (prev_iter->second == cmd->task_inst_)
	  {
		  std::cout<<"in planstrat erasing from open_conds_ "<<prev_iter->first.id<<" to "<<prev_iter->second<<std::endl;
		  this->open_conds_.erase (prev_iter);
	  }
	}
  }
};

// Execute a command to remove open conditions from planning.
void SA_PlanStrategy::execute (SA_RemoveOpenCondsCmd *cmd)
{
  // Remove open conditions, keeping track of removed cond->inst mapping.
  for (CondSet::iterator cond_iter = cmd->conds_.begin ();
    cond_iter != cmd->conds_.end (); cond_iter++)
  {
    for (OpenCondMap::iterator open_iter =
      this->open_conds_.lower_bound (*cond_iter);
      open_iter != this->open_conds_.upper_bound (*cond_iter); )
    {
      cmd->removed_.insert (std::make_pair
        (open_iter->first, open_iter->second));
      OpenCondMap::iterator prev_iter = open_iter;
      open_iter++;
      this->open_conds_.erase (prev_iter);
    }
  }
};

// Undo a command to remove open conditions from planning.
void SA_PlanStrategy::undo (SA_RemoveOpenCondsCmd *cmd)
{
  // Insert removed open condition to task instance mapping.
  for (OpenCondMap::iterator open_iter = cmd->removed_.begin ();
      open_iter != cmd->removed_.end (); open_iter++)
  {
	  std::cout<<"in planstrat undo adding "<<open_iter->first.id<<" to "<<open_iter->second<<std::endl;
	  this->open_conds_.insert (std::make_pair
      (open_iter->first, open_iter->second));
  }
};

// Execute a command to add causal link threats to planning.
void SA_PlanStrategy::execute (SA_AddOpenThreatsCmd *)
{
  //****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP
};

// Undo a command to add causal link threats to planning.
void SA_PlanStrategy::undo (SA_AddOpenThreatsCmd *)
{
  //****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP
};

// Execute a command to remove causal link threats from planning.
void SA_PlanStrategy::execute (SA_RemoveOpenThreatsCmd *)
{
  //****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP
};

// Undo a command to remove causal link threats from planning.
void SA_PlanStrategy::undo (SA_RemoveOpenThreatsCmd *)
{
  //****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP****TEMP
};

// Recursively satisfy all open causal link threats and continue planning.
bool SA_PlanStrategy::satisfy_open_threats (void)
{
  if (this->open_threats_.empty ()) {
    // Set decision point and reset sequence number for commands.
    this->cur_decision_pt_ = SA_PlanStrategy::IMPL_DECISION;
    this->cur_seq_num_ = 1;

    // Choose a task implementation.
    AssocTaskImplCmd *assoc_impl_cmd =
      static_cast<AssocTaskImplCmd *> (this->assoc_impl_cmd_->clone ());
    TaskImplList impl_list;
    if(!this->planner_->inst_exists(this->cur_task_inst_)) impl_list = this->impl_choice_->choose_impl (this->cur_task_inst_);
    else impl_list.push_back(this->planner_->get_impl_id(this->cur_task_inst_));
    assoc_impl_cmd->set_id (this->get_next_cmd_id ());
    assoc_impl_cmd->set_assoc (this->cur_task_inst_, impl_list);
    this->planner_->add_command (assoc_impl_cmd);

    // Try task implementations until one yields a complete plan or all have
    // been tried.
    while (this->planner_->try_next (assoc_impl_cmd->get_id ())) {
		// Get the task instance.
		this->cur_task_inst_ = assoc_impl_cmd->get_task_inst ();
      // Set decision point and reset sequence number for commands.
      this->cur_decision_pt_ = SA_PlanStrategy::SCHEDULE_DECISION;
      this->cur_seq_num_ = 1;

      // Try to schedule and recursively continue planning.
      if (this->planner_->recurse_sched (this->cur_task_inst_))
        return true;
    }

    // No task implementation worked so return failure.
    return false;
  }

  // Choose an open threat to satisfy and remove from open threats.
  CLThreat threat = *this->open_threats_.begin ();
  CommandID rmv_threat_cmd_id = this->rmv_open_threat (threat);

  // Create threat resolution command and add to planner.
  ResolveCLThreatCmd *resolve_threat_cmd =
    static_cast<ResolveCLThreatCmd *> (this->resolve_threat_cmd_->clone ());
  resolve_threat_cmd->set_id (this->get_next_cmd_id ());
  resolve_threat_cmd->set_threat (threat);
  this->planner_->add_command (resolve_threat_cmd);

  // Try threat resolutions until one yields a complete plan or all have been
  // tried.
  while (this->planner_->try_next (resolve_threat_cmd->get_id ())) {
    if (this->satisfy_open_threats ())
      return true;
  }

  // Undo threat resolution.
  this->planner_->undo_command (resolve_threat_cmd->get_id ());

  // Undo removal of open threat.
  this->planner_->undo_command (rmv_threat_cmd_id);

  // No threat resolution was successful so return failure.
  return false;
};

// Satisfy an open condition with an appropriate task.
AddTaskCmd *SA_PlanStrategy::satisfy_cond (Condition open_cond)
{
  // Get add task command.
  AddTaskCmd *add_task_cmd =
    static_cast<AddTaskCmd *> (this->add_task_cmd_->clone ());
  TaskList task_list = this->task_choice_->choose_task (open_cond);
  add_task_cmd->set_id (this->get_next_cmd_id ());
  add_task_cmd->set_tasks (task_list);

  // Get task instances requiring this open condition, and set in command.
  TaskInstSet inst_set;
  inst_set.clear ();
  for (OpenCondMap::iterator iter = this->open_conds_.lower_bound (open_cond);
    iter != this->open_conds_.upper_bound (open_cond); iter++)
  {
    inst_set.insert (iter->second);
  }
  add_task_cmd->set_causal_info (open_cond, inst_set);

  // Add command to planner to be executed next.
  this->planner_->add_command (add_task_cmd);

  // Return pointer to command.
  return add_task_cmd;
};

// Add open conditions.
CommandID SA_PlanStrategy::add_open_conds (const CondSet &open_conds,
  TaskInstID task_inst)
{
  // Get command to add open conditions for task instance.
  AddOpenCondsCmd *add_conds_cmd =
    static_cast<AddOpenCondsCmd *> (this->add_conds_cmd_->clone ());
  add_conds_cmd->set_conds (open_conds);
  add_conds_cmd->set_task_inst (task_inst);
  CommandID cmd_id = this->get_next_cmd_id ();
  add_conds_cmd->set_id (cmd_id);

  // Execute command immediately and return command id.
  this->planner_->execute_command (add_conds_cmd);
  return cmd_id;
};

// Remove open condition.
CommandID SA_PlanStrategy::rmv_open_cond (Condition open_cond)
{
  // Get commmand to remove open conditions.
  RemoveOpenCondsCmd *rmv_conds_cmd =
    static_cast<RemoveOpenCondsCmd *> (this->rmv_conds_cmd_->clone ());
  CondSet conds;
  conds.insert (open_cond);
  rmv_conds_cmd->set_conds (conds);
  CommandID cmd_id = this->get_next_cmd_id ();
  rmv_conds_cmd->set_id (cmd_id);

  // Execute command immediately and return command id.
  this->planner_->execute_command (rmv_conds_cmd);
  return cmd_id;
};

// Add open causal link threats.
CommandID SA_PlanStrategy::add_open_threats (const CLThreatSet &threats)
{
  // Get commmand to add open threats.
  AddOpenThreatsCmd *add_threats_cmd =
    static_cast<AddOpenThreatsCmd *> (this->add_threats_cmd_->clone ());
  add_threats_cmd->set_threats (threats);
  CommandID cmd_id = this->get_next_cmd_id ();
  add_threats_cmd->set_id (cmd_id);

  // Execute command immediately and return command id.
  this->planner_->execute_command (add_threats_cmd);
  return cmd_id;
};

// Remove open causal link threat.
CommandID SA_PlanStrategy::rmv_open_threat (CLThreat threat)
{
  // Get commmand to remove open threats.
  RemoveOpenThreatsCmd *rmv_threats_cmd =
    static_cast<RemoveOpenThreatsCmd *> (this->rmv_threats_cmd_->clone ());
  CLThreatSet threats;
  threats.insert (threat);
  rmv_threats_cmd->set_threats (threats);
  CommandID cmd_id = this->get_next_cmd_id ();
  rmv_threats_cmd->set_id (cmd_id);

  // Execute command immediately and return command id.
  this->planner_->execute_command (rmv_threats_cmd);
  return cmd_id;
};
