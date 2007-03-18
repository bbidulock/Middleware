// $Id$

// ******************************************************************
// Include Section
// ******************************************************************

#include "ace/Get_Opt.h"
#include "ace/Auto_Ptr.h"

#include "tao/ORB_Core.h"

#include "orbsvcs/CosNotifyChannelAdminS.h"
#include "orbsvcs/CosNotifyCommC.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/TimeBaseC.h"
#include "Notify_StructuredPushSupplier.h"
#include "goS.h"

#include "Notify_Test_Client.h"

#include "ace/OS_NS_unistd.h"

// ******************************************************************
// Data Section
// ******************************************************************

static TAO_Notify_Tests_StructuredPushSupplier* supplier_1 = 0;
static CORBA::Boolean use_deadline_ordering = 0;
static int num_events = 40;
static const char* ior_output_file = "supplier.ior";

// ******************************************************************
// Subroutine Section
// ******************************************************************

// The supplier will not start sending events until the
// go() operation is invoked.
class sig_i : public POA_sig
{
public:
  sig_i(CORBA::ORB_ptr orb)
    : orb_(orb)
    , started_(false)
  {
  }

  void go (void)
  {
    started_ = true;
  }

  void done (void)
  {
    started_ = false;
  }

  void wait_for_startup()
  {
    while (! started_) {
      ACE_Time_Value tv(0, 100 * 1000); // 100ms
      orb_->run(tv);
    }
  }

  void wait_for_completion()
  {
    while (started_) {
      ACE_Time_Value tv(0, 100 * 1000); // 100ms
      orb_->run(tv);
    }
  }

private:
  CORBA::ORB_ptr orb_;
  bool started_;
};

class Supplier_Client : public Notify_Test_Client
{
public:
  virtual int parse_args (int argc, char* argv[]);
};


int
Supplier_Client::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "o:e:d");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
  {
    case 'd':
      use_deadline_ordering = 1;
#if !defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
      ACE_ERROR_RETURN ((LM_ERROR,
        "This order policy requires timed message "
        "blocks.\nPlease #define "
        "ACE_HAS_TIMED_MESSAGE_BLOCKS in your "
        "config.h\n"), -1);
#else
      break;
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */
    case 'e':
      num_events = ACE_OS::atoi (get_opts.optarg);
      break;

    case 'o':
      ior_output_file = get_opts.optarg;
      break;

    default:
      ACE_ERROR_RETURN ((LM_ERROR,
        "usage:  %s "
        "-o <iorfile> -e <# of events> -d"
        "\n",
        argv [0]),
        -1);
  }

  // Indicates sucessful parsing of the command line
  return 0;
}


static CosNotifyChannelAdmin::SupplierAdmin_ptr
create_supplieradmin (CosNotifyChannelAdmin::EventChannel_ptr ec)
{
  CosNotifyChannelAdmin::AdminID adminid = 0;
  CosNotifyChannelAdmin::SupplierAdmin_var admin =
    ec->new_for_suppliers (CosNotifyChannelAdmin::AND_OP,
    adminid);


  return CosNotifyChannelAdmin::SupplierAdmin::_duplicate (admin.in ());
}


static void
SendEvent (int id)
{
  CosNotification::StructuredEvent event;

  event.header.fixed_header.event_type.domain_name = CORBA::string_dup ("a");
  event.header.fixed_header.event_type.type_name = CORBA::string_dup ("b");
  event.header.fixed_header.event_name = CORBA::string_dup ("c");

  event.header.variable_header.length (3);

  event.header.variable_header[0].name = CORBA::string_dup ("Id");
  event.header.variable_header[0].value <<= (CORBA::Long)id;

  event.header.variable_header[1].name =
    CORBA::string_dup (CosNotification::Priority);
  event.header.variable_header[1].value <<= (CORBA::Short) (id);

  event.header.variable_header[2].name =
    CORBA::string_dup (CosNotification::Timeout);
  event.header.variable_header[2].value <<= (TimeBase::TimeT) (id * 10000);

  supplier_1->send_event (event);
}

static void
create_suppliers (CosNotifyChannelAdmin::SupplierAdmin_ptr admin,
                  PortableServer::POA_ptr poa)
{
  ACE_NEW_THROW_EX (supplier_1,
    TAO_Notify_Tests_StructuredPushSupplier (),
    CORBA::NO_MEMORY ());

  supplier_1->init (poa);

  supplier_1->connect (admin);
}


// ******************************************************************
// Main Section
// ******************************************************************

int main (int argc, char* argv[])
{
  int status = 0;
  ACE_Auto_Ptr< sig_i > sig_impl;
  try
  {
    Supplier_Client client;
    status = client.init (argc, argv);

    if (status == 0)
    {
      CosNotifyChannelAdmin::EventChannel_var ec =
        client.create_event_channel ("MyEventChannel", 0);

      if (use_deadline_ordering)
      {
        CosNotification::QoSProperties qos (1);
        qos.length (1);
        qos[0].name = CORBA::string_dup (CosNotification::OrderPolicy);
        qos[0].value <<= (CORBA::Short)CosNotification::DeadlineOrder;
        ec->set_qos (qos);
      }

      sig_impl.reset( new sig_i( client.orb() ) );
      sig_var sig = sig_impl->_this ();

      // If the ior_output_file exists, output the ior to it
      if (ior_output_file != 0)
      {
        CORBA::String_var ior =
          client.orb ()->object_to_string (sig.in ());

        FILE *output_file= ACE_OS::fopen (ior_output_file, "w");
        ACE_ASSERT (output_file != 0);
        ACE_OS::fprintf (output_file, "%s", ior.in ());
        ACE_OS::fclose (output_file);
      }

      CosNotifyChannelAdmin::SupplierAdmin_var admin =
        create_supplieradmin (ec.in ());
      ACE_ASSERT(!CORBA::is_nil (admin.in ()));

      create_suppliers (admin.in (), client.root_poa ());

      sig_impl->wait_for_startup();

      ACE_DEBUG((LM_DEBUG, "1 supplier sending %d events...\n", num_events));
      for (int i = 0; i < num_events; ++i)
      {
        ACE_DEBUG((LM_DEBUG, "+"));
        SendEvent (i + 1);
      }
      ACE_DEBUG((LM_DEBUG, "\nSupplier sent %d events.\n", num_events));

      sig_impl->wait_for_completion();

      ACE_OS::unlink (ior_output_file);

      supplier_1->disconnect();

      ec->destroy();
    }
  }
  catch (const CORBA::Exception& e)
  {
    e._tao_print_exception ("Error: ");
    status = 1;
  }

  return status;
}
