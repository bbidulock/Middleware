// -*- C++ -*-

//=============================================================================
/**
 *  @file   FTEC_Group_Manager.h
 *
 *  $Id$
 *
 *  @author Huang-Ming Huang <hh1@cse.wustl.edu>
 */
//=============================================================================

#ifndef TAO_FTEC_GROUP_MANAGER_H
#define TAO_FTEC_GROUP_MANAGER_H

#include "orbsvcs/FtRtecEventChannelAdminC.h"
#include "FTEC_Fault_Listener.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

struct TAO_FTEC_Group_Manager_Impl;

class TAO_FTEC_Group_Manager : private TAO_FTEC_Fault_Listener
{
public:
  TAO_FTEC_Group_Manager();
  virtual ~TAO_FTEC_Group_Manager();

  bool init(CORBA::ORB_ptr orb);

  virtual CORBA::Boolean start (
        FTRT::FaultListener_ptr listener,
        FTRT::Location_out cur
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));

  void create_group (
    const FTRT::ManagerInfoList & info_list,
    CORBA::ULong object_group_ref_version
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  void join_group (
    const FTRT::ManagerInfo & info
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  void add_member (
    const FTRT::ManagerInfo & info,
    CORBA::ULong object_group_ref_version
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  void remove_member (
    const FTRT::Location & crashed_location,
    CORBA::ULong object_group_ref_version
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);

  void replica_crashed (
    const FTRT::Location & location
    ACE_ENV_ARG_DECL_WITH_DEFAULTS);

private:
  virtual void get_state (
        FtRtecEventChannelAdmin::EventChannelState & s
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )=0;

  virtual void connection_closed();

protected:
  TAO_FTEC_Group_Manager_Impl* impl_;
};

#endif // TAO_FTEC_GROUP_MANAGER_H
