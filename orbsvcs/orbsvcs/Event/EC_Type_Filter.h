/* -*- C++ -*- */
// $Id$
//
// ============================================================================
//
// = LIBRARY
//   ORBSVCS Real-time Event Channel
//
// = FILENAME
//   EC_Type_Filter
//
// = AUTHOR
//   Carlos O'Ryan (coryan@cs.wustl.edu)
//
// = CREDITS
//   Based on previous work by Tim Harrison (harrison@cs.wustl.edu)
//   and other members of the DOC group.
//   More details can be found in:
//   http://www.cs.wustl.edu/~schmidt/oopsla.ps.gz
//   http://www.cs.wustl.edu/~schmidt/JSAC-98.ps.gz
//
//
// ============================================================================

#ifndef TAO_EC_TYPE_FILTER_H
#include "ace/pre.h"
#define TAO_EC_TYPE_FILTER_H

#include "EC_Filter.h"
#include "event_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_RTEvent_Export TAO_EC_Type_Filter : public TAO_EC_Filter
{
  // = TITLE
  //   A filter based on event type/source
  //
  // = DESCRIPTION
  //   This filter only accept events with a predefined type/source,
  //   both the source and the type can be wildcards.
  //
public:
  TAO_EC_Type_Filter (const RtecEventComm::EventHeader& header);
  // Constructor.

  // = The TAO_EC_Filter methods, please check the documentation in
  // TAO_EC_Filter.
  virtual int filter (const RtecEventComm::EventSet& event,
                      TAO_EC_QOS_Info& qos_info,
                      CORBA::Environment& env);
  virtual int filter_nocopy (RtecEventComm::EventSet& event,
                             TAO_EC_QOS_Info& qos_info,
                             CORBA::Environment& env);
  virtual void push (const RtecEventComm::EventSet& event,
                     TAO_EC_QOS_Info& qos_info,
                     CORBA::Environment& env);
  virtual void push_nocopy (RtecEventComm::EventSet& event,
                            TAO_EC_QOS_Info& qos_info,
                            CORBA::Environment& env);
  virtual void clear (void);
  virtual CORBA::ULong max_event_size (void) const;
  virtual int can_match (const RtecEventComm::EventHeader& header) const;
  virtual int add_dependencies (const RtecEventComm::EventHeader& header,
                                const TAO_EC_QOS_Info &qos_info,
                                CORBA::Environment &ACE_TRY_ENV);

private:
  ACE_UNIMPLEMENTED_FUNC (TAO_EC_Type_Filter
                              (const TAO_EC_Type_Filter&))
  ACE_UNIMPLEMENTED_FUNC (TAO_EC_Type_Filter& operator=
                              (const TAO_EC_Type_Filter&))

private:
  RtecEventComm::EventHeader header_;
  // Encapsulate the type/source that we must match.
};

#if defined (__ACE_INLINE__)
#include "EC_Type_Filter.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_EC_TYPE_FILTER_H */
