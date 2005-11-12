// -*- C++ -*-

//=============================================================================
/**
 *  @file   Basic_Replication_Strategy.h
 *
 *  $Id$
 *
 *  @author Huang-Ming Huang <hh1@cse.wustl.edu>
 */
//=============================================================================
#ifndef BASIC_REPLICATION_STRATEGY_H
#define BASIC_REPLICATION_STRATEGY_H
#include "Replication_Strategy.h"
#include "ace/Synch.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class  Basic_Replication_Strategy
 *
 * @brief Use two-way CORBA call to replicate the state to backup replicas.
 */

class Basic_Replication_Strategy : public Replication_Strategy
{
public:
  /**
   * @param mt Specifies whether multithreaded ORB is used.
   */
  Basic_Replication_Strategy(bool mt);
  ~Basic_Replication_Strategy();

  virtual void check_validity(ACE_ENV_SINGLE_ARG_DECL);

  virtual void replicate_request(const FTRT::State& state,
    RollbackOperation rollback,
    const FtRtecEventChannelAdmin::ObjectId& oid
    ACE_ENV_ARG_DECL);
  virtual void add_member(const FTRT::ManagerInfo & info,
                          CORBA::ULong object_group_ref_version
                          ACE_ENV_ARG_DECL);

  virtual int  acquire_read (void);
  virtual int  acquire_write (void);
  virtual int  release (void);

private:
  FTRT::SequenceNumber sequence_num_;
  ACE_SYNCH_RECURSIVE_MUTEX* mutex_;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#endif
