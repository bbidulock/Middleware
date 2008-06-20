// -*- C++ -*-

//=============================================================================
/**
 * @file Monitor_Base.h
 *
 * $Id$
 *
 * @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

#ifndef MONITOR_BASE_H
#define MONITOR_BASE_H

#include /**/ "ace/pre.h"

#include "ace/Monitor_Control_Types.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_MONITOR_FRAMEWORK) && (ACE_HAS_MONITOR_FRAMEWORK == 1)

#include "ace/Refcountable_T.h"
#include "ace/Thread_Mutex.h"
#include "ace/Synch_Traits.h"
#include "ace/CDR_Base.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ETCL_Constraint;

namespace ACE
{
  namespace Monitor_Control
  {
    class Control_Action;

    /**
     * @class Monitor_Base
     *
     * @brief Base class from which the template monitor point class is
     *        derived.
     *
     * All the operations are pure virtual so they can
     * be implemented in the 'disabled' template specialization
     * as no-ops.
     */
    class ACE_Export Monitor_Base
      : private ACE_Refcountable_T<ACE_SYNCH_MUTEX>
    {
    public:
      /// A monitor can hold various types of data and maintains stats
      /// differently depending upon the type of information stored.
      enum Information_Type
      {
        MC_COUNTER,
        MC_NUMBER,
        MC_TIME,
        MC_INTERVAL,
        MC_GROUP
      };

      typedef Monitor_Control_Types::ConstraintList CONSTRAINTS;
      typedef CONSTRAINTS::const_iterator CONSTRAINT_ITERATOR;

      Monitor_Base (const char* name, Information_Type type);
      virtual ~Monitor_Base (void);

      /// Implemented by the most-derived class. Does the actual
      /// work of fetching the monitored value.
      virtual void update (void);

      /// Updates the monitor's data if it is a numeric floating point.
      virtual void receive (double data);

      /// Updates the monitor's data if it is an integer size.
      virtual void receive (size_t data);

      /// Add a constraint, returns a unique constraint id.
      long add_constraint (const char* expression,
                           Control_Action* action = 0);

      /// Remove a constraint and return the associated control action,
      /// which may be shared, for deletion or further use.
      Control_Action* remove_constraint (const long constraint_id);

      /// Get all constraints
      CONSTRAINTS& constraints (void);

      /// Reset function.
      virtual void clear (void);

      /// Data accessors.
      void retrieve (Monitor_Control_Types::Data& data) const;
      void retrieve_and_clear (Monitor_Control_Types::Data& data);

      /// Common to all monitors.

      void add_to_registry (
        const ACE_Time_Value& time = ACE_Time_Value::zero);
      void remove_from_registry (void);

      const char* name (void) const;
      void name (const char* new_name);

      void add_ref (void);
      void remove_ref (void);
      
      /// Calculate the average of the accumulated samples.
      double average (void) const;

      /// Calculate the sum of the squares of the samples.
      double sum_of_squares (void) const;

      /// Returns the number of samples
      size_t count (void) const;

      /// Returns the minimum sample value
      double minimum_sample (void) const;

      /// Returns the maximum sample value
      double maximum_sample (void) const;

      /// Returns the most recent sample value
      double last_sample (void) const;

      /// Return the type of this statistic
      Information_Type type (void) const;

    protected:
      /// Overridden in some monitors (for example the OS monitors) where
      /// clearing requires monitor-specific actions.
      virtual void clear_i (void);

    protected:
      Monitor_Control_Types::Data data_;
      mutable ACE_SYNCH_MUTEX mutex_;

      CONSTRAINTS constraints_;

    private:
      ACE_CString name_;
      Information_Type type_;

      size_t index_;
      bool minimum_set_;
      double minimum_;
      double maximum_;
      double sum_;
      double sum_of_squares_;
      double last_;
    };
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Monitor_Base.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_MONITOR_FRAMEWORK==1 */

#include /**/ "ace/post.h"

#endif // MONITOR_BASE_H
