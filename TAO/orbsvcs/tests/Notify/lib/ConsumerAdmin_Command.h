/* -*- C++ -*- */
/**
 *  @file ConsumerAdmin_Command.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_NS_CONSUMERADMIN_COMMAND_H
#define TAO_NS_CONSUMERADMIN_COMMAND_H
#include "ace/pre.h"

#include "notify_test_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"
#include "orbsvcs/CosNotifyChannelAdminC.h"
#include "Command.h"

/**
 * @class TAO_NS_ConsumerAdmin_Command
 *
 * @brief Command for ConsumerAdmin objects.
 *
 */
class TAO_NOTIFY_TEST_Export TAO_NS_ConsumerAdmin_Command  : public TAO_NS_Command
{
public:
  /// Constuctor
  TAO_NS_ConsumerAdmin_Command (void);

  /// Destructor
  ~TAO_NS_ConsumerAdmin_Command ();

  /// Parse args and populate options.
  virtual void init (ACE_Arg_Shifter& arg_shifter);

  /// Execute the command.
  virtual void execute_i (ACE_ENV_SINGLE_ARG_DECL);

  /// Name of object
  virtual const char* get_name (void);
  static const char* name (void);

protected:

  /// = Data Members
  enum COMMAND
  {
    CREATE,
    DESTROY,
    SET_QOS,
    SET_ADMIN,
    SUBSCRIPTION,
    DUMP_STATE
  };

  COMMAND command_;

  ACE_CString name_;

  ACE_CString factory_;

  CosNotifyChannelAdmin::InterFilterGroupOperator ifgop_;

  CosNotifyChannelAdmin::AdminID id_;

  CosNotification::QoSProperties initial_qos_;

  // Subscription change
  CosNotification::EventTypeSeq added_;
  CosNotification::EventTypeSeq removed_;

  /// = Handlers
  void handle_create (ACE_ENV_SINGLE_ARG_DECL);
  void handle_subscriptions (ACE_ENV_SINGLE_ARG_DECL);
  void handle_status (ACE_ENV_SINGLE_ARG_DECL);
};

#if defined (__ACE_INLINE__)
#include "ConsumerAdmin_Command.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_NS_CONSUMERADMIN_COMMAND_H */
