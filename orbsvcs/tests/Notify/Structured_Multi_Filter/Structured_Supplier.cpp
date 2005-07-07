// $Id$

#include "Notify_Push_Supplier.h"
#include "goS.h"
#include "Notify_Test_Client.h"

#include "orbsvcs/CosNotifyChannelAdminS.h"
#include "orbsvcs/CosNotifyCommC.h"
#include "orbsvcs/CosNamingC.h"

#include "tao/debug.h"

#include "ace/Get_Opt.h"
#include "ace/OS_NS_strings.h"
#include "ace/Auto_Ptr.h"
#include "ace/OS_NS_unistd.h"

static const char* ior_file = "supplier.ior";
static bool useFilters = false;
static Notify_Push_Supplier* supplier = 0;
static bool use_or_operator = false;
static int num_events = 90;

static const char* GRAMMAR = "TCL";

class sig_i : public POA_sig
{
public:
  sig_i(CORBA::ORB_ptr orb)
    : orb_(orb)
    , started_(false)
  {
  }

  void go (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    started_ = true;
  }

  void done (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
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
  ACE_Get_Opt get_opts (argc, argv, "e:f:");
  int x;

  while ((x = get_opts ()) != -1)
    switch (x)
  {
    case 'f':
      useFilters = true;
      if (ACE_OS::strcasecmp ("OR", get_opts.optarg) == 0)
        use_or_operator = true;
      break;

    case 'e':
      num_events = ACE_OS::atoi (get_opts.optarg);
      break;

    default:
      ACE_ERROR_RETURN ((LM_ERROR,
        "usage:  %s "
        "[-f] [-e num_events] -o <AND | OR>"
        " -ORBInitRef <Naming Service Location>"
        "\n",
        argv [0]),
        -1);
  }

  return 0; // successful parse
}


static CosNotifyChannelAdmin::SupplierAdmin_ptr
create_supplieradmin (CosNotifyChannelAdmin::EventChannel_ptr ec
                      ACE_ENV_ARG_DECL)
{
  CosNotifyChannelAdmin::AdminID adminid = 0;
  CosNotifyChannelAdmin::SupplierAdmin_var admin =
    ec->new_for_suppliers ((use_or_operator ? CosNotifyChannelAdmin::OR_OP :
  CosNotifyChannelAdmin::AND_OP),
    adminid
    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  return CosNotifyChannelAdmin::SupplierAdmin::_duplicate (admin.in ());
}

int
send_event (int id)
{
  CosNotification::StructuredEvent event;

  event.header.fixed_header.event_type.domain_name =
    CORBA::string_dup ("TAO Test Suite");
  event.header.fixed_header.event_type.type_name =
    CORBA::string_dup ("Filtered Structured Event Notification Svc test");

  event.header.fixed_header.event_name = CORBA::string_dup ("test");
  event.header.variable_header.length (1);

  event.filterable_data.length (3);
  event.filterable_data[0].name = CORBA::string_dup ("id");
  event.filterable_data[0].value <<= static_cast<CORBA::ULong>(id);
  event.filterable_data[1].name = CORBA::string_dup ("group");
  event.filterable_data[1].value <<= static_cast<CORBA::ULong>(id % 3);
  event.filterable_data[2].name = CORBA::string_dup ("type");
  // Divide by 3 first so that the type and group aren't synched
  event.filterable_data[2].value <<= static_cast<CORBA::ULong>(id / 3 % 3);

  ACE_TRY_NEW_ENV
  {
    ACE_DEBUG((LM_DEBUG, "+"));

    supplier->send_event (event ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;
  }
  ACE_CATCH (CORBA::Exception, e)
  {
    ACE_PRINT_EXCEPTION (e, "\nError: Supplier: ");
  }
  ACE_ENDTRY;

  return 0;
}

static void create_supplier (CosNotifyChannelAdmin::SupplierAdmin_ptr admin,
                             CosNotifyChannelAdmin::EventChannel_ptr ec,
                             PortableServer::POA_ptr poa
                             ACE_ENV_ARG_DECL)
{
  ACE_NEW_THROW_EX (supplier,
    Notify_Push_Supplier (),
    CORBA::NO_MEMORY ());

  supplier->init (poa ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  supplier->_connect (admin, ec, useFilters ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void add_admin_filter (CosNotifyChannelAdmin::SupplierAdmin_ptr admin,
                 CosNotifyChannelAdmin::EventChannel_ptr notify_channel
                 ACE_ENV_ARG_DECL)
{
  CosNotifyFilter::FilterFactory_var ffact =
    notify_channel->default_filter_factory (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CosNotifyFilter::Filter_var filter =
    ffact->create_filter (GRAMMAR ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT(!CORBA::is_nil (filter.in ()));

  CosNotifyFilter::ConstraintExpSeq constraint_list (1);
  constraint_list.length (1);

  constraint_list[0].event_types.length (0);
  constraint_list[0].constraint_expr = CORBA::string_dup ("type != 0");

  filter->add_constraints (constraint_list ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  admin->add_filter (filter.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

int main (int argc, char * argv[])
{
  ACE_Auto_Ptr< sig_i > sig_impl;
  ACE_TRY_NEW_ENV;
  {
    Supplier_Client client;
    int status = client.init (argc, argv ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;
    ACE_UNUSED_ARG(status);
    ACE_ASSERT(status == 0);

    CosNotifyChannelAdmin::EventChannel_var ec =
      client.create_event_channel ("Struct_Multi_Filter", 0 ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    ACE_ASSERT(! CORBA::is_nil(ec.in()));

    CORBA::ORB_ptr orb = client.orb ();

    sig_impl.reset( new sig_i( orb ) );
    sig_var sig = sig_impl->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;

    CosNotifyChannelAdmin::SupplierAdmin_var admin =
      create_supplieradmin (ec.in () ACE_ENV_ARG_PARAMETER);

    if (useFilters)
    {
      add_admin_filter (admin.in (), ec.in () ACE_ENV_ARG_PARAMETER);
    }

    ACE_ASSERT(! CORBA::is_nil (admin.in ()));

    create_supplier (admin.in(), ec.in(), client.root_poa() ACE_ENV_ARG_PARAMETER);

    // If the ior_file exists, output the ior to it
    if (ior_file != 0)
    {
      CORBA::String_var ior =
        client.orb ()->object_to_string (sig.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      FILE *output_file= ACE_OS::fopen (ior_file, "w");
      ACE_ASSERT (output_file != 0);
      ACE_OS::fprintf (output_file, "%s", ior.in ());
      ACE_OS::fclose (output_file);
    }

    ACE_DEBUG((LM_DEBUG, "Supplier ready...\n"));

    sig_impl->wait_for_startup();

    ACE_DEBUG((LM_DEBUG, "Supplier sending %d events...\n", num_events));
    for (int i = 0; i < num_events; ++i)
    {
      ACE_DEBUG((LM_DEBUG, "+"));
      send_event (i);
    }
    ACE_DEBUG((LM_DEBUG, "\nSupplier sent %d events.\n", num_events));

    sig_impl->wait_for_completion();

    ACE_OS::unlink (ior_file);

    ec->destroy(ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;

    return 0;
  }
  ACE_CATCH (CORBA::Exception, e)
  {
    ACE_PRINT_EXCEPTION (e, "Error: Supplier: ");
  }
  ACE_ENDTRY;

  return 1;
}
