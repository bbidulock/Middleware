//$Id$
#ifndef MIF_TASK_H
#define MIF_TASK_H

#include "../Thread_Task.h"

class MIF_Task : public Thread_Task
{
 public:
  MIF_Task (int importance,
	    int start_time,
	    int load,
	    DT_Creator *dt_creator);
  
  virtual int perform_task (void);
  
  virtual void pre_activate (void);
  virtual void post_activate (void);
};

#endif /*MIF_TASK_H*/
