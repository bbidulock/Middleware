// -*- C++ -*-
//

//=============================================================================
/**
 * @file  LogGraphOut.h
 *
 * This file contains the Class Description for LogGraph which is an output adapater
 * that creates graphic visualizations of the output plan.
 *
 * @author  Daniel L.C. Mack <daniel.l.mack@vanderbilt.edu>
 */
//=============================================================================

#ifndef SA_POP_LOG_GRAPH_OUT_H_
#define SA_POP_LOG_GRAPH_OUT_H_

#include <iostream>
#include "OutAdapter.h"

namespace SA_POP {

  /**
   * @class LogGraphOut
   *
   * @brief Output adapter that creates a graph visualization of the plan 
   *			as they occur.
   */
  class LogGraphOut : public OutAdapter {
  public:
    /// Constructor.
    /**
     * @param strm  Output stream to log to.
     */
    LogGraphOut (std::ostream &out, int startStep);

    /// Destructor.
    virtual ~LogGraphOut (void);

    /// Notify about task future expected utility changes.
    /**
     * @param planner  Planner for which changes have occurred.
     */
    virtual void notify_eu (SA_POP::Planner *planner);

    /// Notify about plan changes.
    /**
     * @param planner  Planner for which changes have occurred.
     */
    virtual void notify_plan (SA_POP::Planner *planner);

	/// Advance the drawing by one step in the plan
    /**
     * 
     */
	void moveStep();
	
	/// Go Back to the Beginning
    /**
     * 
     */
	void resetStep();

  protected:
    /// Output stream to log to.
    std::ostream &out_;
	int graphn;
  };

};  /* SA_POP namespace */

#endif /* SA_POP_LOG_GRAPH_OUT_H_ */
