/* -*- C++ -*- $Id$ */
#include "Subscribe.h"
#include "orbsvcs/Notify/Notify_PushConsumer.h"
#include "orbsvcs/Notify/Notify_PushSupplier.h"
#include "orbsvcs/Notify/Notify_StructuredPushSupplier.h"
#include "orbsvcs/Notify/Notify_StructuredPushConsumer.h"

#define NOTIFY_FACTORY_NAME "NotifyEventChannelFactory"
#define NAMING_SERVICE_NAME "NameService"

#define DOMAIN_A "domain_a"
#define DOMAIN_B "domain_b"
#define DOMAIN_C "domain_c"

#define TYPE_A "type_a"
#define TYPE_B "type_b"
#define TYPE_C "type_c"

class Subscribe_Consumer : public TAO_Notify_PushConsumer
{
public:
    void push (
        const CORBA::Any & data,
        CORBA::Environment &/*ACE_TRY_ENV*/
        )
      ACE_THROW_SPEC ((
                       CORBA::SystemException,
                       CosEventComm::Disconnected
                       ))
  {
    const char* value;
    data >>= value;

    ACE_DEBUG ((LM_DEBUG, "Subscribe Consumer received an event %s!\n",
                value));
  }
};

class Subscribe_Supplier : public TAO_Notify_PushSupplier
{
};


class Subscribe_StructuredConsumer : public TAO_Notify_StructuredPushConsumer
{
public:
 void push_structured_event (
        const CosNotification::StructuredEvent & notification,
        CORBA::Environment &/*ACE_TRY_ENV*/
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        CosEventComm::Disconnected
       ))
  {
    const char* domain_name =
      notification.header.fixed_header.event_type.domain_name;

    const char* type_name =
      notification.header.fixed_header.event_type.type_name;

    ACE_DEBUG ((LM_DEBUG, "Structured Subscribe Consumer %d received event, domain = %s, type =  %s\n",
                this->proxy_id_, domain_name, type_name));
  }
};

class Subscribe_StructuredSupplier : public TAO_Notify_StructuredPushSupplier
{
};


Subscribe::Subscribe (void)
{
  // No-Op.
  ifgop_ = CosNotifyChannelAdmin::OR_OP;
}

Subscribe::~Subscribe ()
{
  // No-Op.
}

void
Subscribe::init (int argc, char *argv [], CORBA::Environment &ACE_TRY_ENV)
{
  init_ORB (argc, argv, ACE_TRY_ENV);
  ACE_CHECK;
  resolve_naming_service (ACE_TRY_ENV);
  ACE_CHECK;
  resolve_Notify_factory (ACE_TRY_ENV);
  ACE_CHECK;
  create_EC (ACE_TRY_ENV);
  ACE_CHECK;
  create_supplieradmin (ACE_TRY_ENV);
  ACE_CHECK;
  create_consumeradmin (ACE_TRY_ENV);
  ACE_CHECK;
  create_consumers (ACE_TRY_ENV);
  ACE_CHECK;
  create_suppliers (ACE_TRY_ENV);
  ACE_CHECK;
}

void
Subscribe::run (CORBA::Environment &ACE_TRY_ENV)
{
  this->send_events (ACE_TRY_ENV);
  ACE_CHECK;
}

void
Subscribe::init_ORB (int argc,
                      char *argv [],
                      CORBA::Environment &ACE_TRY_ENV)
{
  this->orb_ = CORBA::ORB_init (argc,
                                argv,
                                "",
                                ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::Object_ptr poa_object  =
    this->orb_->resolve_initial_references("RootPOA",
                                           ACE_TRY_ENV);
  ACE_CHECK;

  if (CORBA::is_nil (poa_object))
    {
      ACE_ERROR ((LM_ERROR,
                  " (%P|%t) Unable to initialize the POA.\n"));
      return;
    }
  this->root_poa_ =
    PortableServer::POA::_narrow (poa_object, ACE_TRY_ENV);
  ACE_CHECK;

  PortableServer::POAManager_var poa_manager =
    root_poa_->the_POAManager (ACE_TRY_ENV);
  ACE_CHECK;

  poa_manager->activate (ACE_TRY_ENV);
  ACE_CHECK;
}

void
Subscribe::resolve_naming_service (CORBA::Environment &ACE_TRY_ENV)
{
  CORBA::Object_var naming_obj =
    this->orb_->resolve_initial_references (NAMING_SERVICE_NAME,
                                            ACE_TRY_ENV);
  ACE_CHECK;

  // Need to check return value for errors.
  if (CORBA::is_nil (naming_obj.in ()))
    ACE_THROW (CORBA::UNKNOWN ());

  this->naming_context_ =
    CosNaming::NamingContext::_narrow (naming_obj.in (), ACE_TRY_ENV);
  ACE_CHECK;
}

void
Subscribe::resolve_Notify_factory (CORBA::Environment &ACE_TRY_ENV)
{
  CosNaming::Name name (1);
  name.length (1);
  name[0].id = CORBA::string_dup (NOTIFY_FACTORY_NAME);

  CORBA::Object_var obj =
    this->naming_context_->resolve (name,
                                   ACE_TRY_ENV);
  ACE_CHECK;

  this->notify_factory_ =
    CosNotifyChannelAdmin::EventChannelFactory::_narrow (obj.in (),
                                                         ACE_TRY_ENV);
  ACE_CHECK;
}

void
Subscribe::create_EC (CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::ChannelID id;

  ec_ = notify_factory_->create_channel (initial_qos_,
                                         initial_admin_,
                                         id,
                                         ACE_TRY_ENV);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (ec_.in ()));
}

void
Subscribe::create_supplieradmin (CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::AdminID adminid;

  supplier_admin_ =
    ec_->new_for_suppliers (this->ifgop_, adminid, ACE_TRY_ENV);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (supplier_admin_.in ()));
}

void
Subscribe:: create_consumeradmin (CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::AdminID adminid;

  consumer_admin_ =
    ec_->new_for_consumers (this->ifgop_, adminid, ACE_TRY_ENV);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (consumer_admin_.in ()));
}

void
Subscribe::create_consumers (CORBA::Environment &ACE_TRY_ENV)
{
  consumer_1_ = new Subscribe_StructuredConsumer ();
  consumer_1_->init (this->root_poa_.in (), ACE_TRY_ENV);
  ACE_CHECK;
  consumer_1_->connect (this->consumer_admin_.in (),
                        ACE_TRY_ENV);
  ACE_CHECK;

  consumer_2_ = new Subscribe_StructuredConsumer ();
  consumer_2_->init (this->root_poa_.in (), ACE_TRY_ENV);
  ACE_CHECK;
  consumer_2_->connect (this->consumer_admin_.in (),
                        ACE_TRY_ENV);
  ACE_CHECK;
}

void
Subscribe::create_suppliers (CORBA::Environment &ACE_TRY_ENV)
{
  supplier_1_ = new Subscribe_StructuredSupplier ();
  supplier_1_->init (this->root_poa_.in (), ACE_TRY_ENV);
  ACE_CHECK;
  supplier_1_->connect (this->supplier_admin_.in (),
                        ACE_TRY_ENV);
  ACE_CHECK;

  supplier_2_ = new Subscribe_StructuredSupplier ();
  supplier_2_->init (this->root_poa_.in (), ACE_TRY_ENV);
  ACE_CHECK;
  supplier_2_->connect (this->supplier_admin_.in (),
                        ACE_TRY_ENV);
  ACE_CHECK;
}

void
Subscribe::send_events (CORBA::Environment &ACE_TRY_ENV)
{
  // Setup the CA to receive event_type : "domain_A", "Type_a"
  CosNotification::EventTypeSeq added(1);
  CosNotification::EventTypeSeq removed (1);
  added.length (1);
  removed.length (1);

  added[0].domain_name =  CORBA::string_dup (DOMAIN_A);
  added[0].type_name = CORBA::string_dup (TYPE_A);

  removed[0].domain_name =  CORBA::string_dup ("*");
  removed[0].type_name = CORBA::string_dup ("*");

  this->consumer_admin_->subscription_change (added, removed, ACE_TRY_ENV);
  ACE_CHECK;

  // Setup the Consumer 1 to receive event_type : "domain_B", "Type_b"
  CosNotification::EventTypeSeq added_1(1);
  CosNotification::EventTypeSeq removed_1 (0);

  added_1[0].domain_name =  CORBA::string_dup (DOMAIN_B);
  added_1[0].type_name = CORBA::string_dup (TYPE_B);
  added_1.length (1);
  removed_1.length (0);

  this->consumer_1_->proxy_supplier_->subscription_change (added_1, removed_1,
                                                           ACE_TRY_ENV);
  ACE_CHECK;

  // Setup the Consumer 2 to receive event_type : "domain_C", "Type_c"
  CosNotification::EventTypeSeq added_2(1);
  CosNotification::EventTypeSeq removed_2 (0);

  added_2[0].domain_name =  CORBA::string_dup (DOMAIN_C);
  added_2[0].type_name = CORBA::string_dup (TYPE_C);
  added_2.length (1);
  removed_2.length (0);

  this->consumer_2_->proxy_supplier_->subscription_change (added_2, removed_2,
                                                           ACE_TRY_ENV);
  ACE_CHECK;

  // Create the events - one of each type
  // Event 1
  CosNotification::StructuredEvent event1;
  event1.header.fixed_header.event_type.domain_name =
    CORBA::string_dup(DOMAIN_A);
  event1.header.fixed_header.event_type.type_name =
    CORBA::string_dup(TYPE_A);
  event1.header.fixed_header.event_name = CORBA::string_dup("");
  event1.header.variable_header.length (0); // put nothing here
  event1.filterable_data.length (0);
  event1.remainder_of_body <<= (CORBA::Long)10;

  // Event 2
  CosNotification::StructuredEvent event2;
  event2.header.fixed_header.event_type.domain_name =
    CORBA::string_dup(DOMAIN_B);
  event2.header.fixed_header.event_type.type_name =
    CORBA::string_dup(TYPE_B);
  event2.header.fixed_header.event_name = CORBA::string_dup("");
  event2.header.variable_header.length (0); // put nothing here
  event2.filterable_data.length (0);
  event2.remainder_of_body <<= (CORBA::Long)10;

  // event 3
  CosNotification::StructuredEvent event3;
  event3.header.fixed_header.event_type.domain_name =
    CORBA::string_dup(DOMAIN_C);
  event3.header.fixed_header.event_type.type_name =
    CORBA::string_dup(TYPE_C);
  event3.header.fixed_header.event_name = CORBA::string_dup("");
  event3.header.variable_header.length (0); // put nothing here
  event3.filterable_data.length (0);
  event3.remainder_of_body <<= (CORBA::Long)10;

 // let supplier 1 send all these events
  for (int i = 0; i < 1; ++i)
    {
      supplier_1_->send_event (event1, ACE_TRY_ENV);
      supplier_1_->send_event (event2, ACE_TRY_ENV);
      supplier_1_->send_event (event3, ACE_TRY_ENV);
    }
}
