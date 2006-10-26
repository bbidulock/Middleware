// $Id$

// ******************************************************************
// Include Section
// ******************************************************************

#include "ace/Get_Opt.h"
#include "ace/OS_NS_unistd.h"

#include "orbsvcs/CosNotifyCommC.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/TimeBaseC.h"
#include "Notify_Structured_Push_Consumer.h"
#include "goC.h"

#include "Notify_Test_Client.h"

// ******************************************************************
// Data Section
// ******************************************************************

static const char* ior = "file://supplier.ior";
// TimeT is in 10ths of a microsecond
static TimeBase::TimeT blocking_timeout = 2 * 1000 * 1000 * 10; // 2 secs
// Must match the number sent by supplier. (-1 if blocking_timeout less than 1)
static unsigned int expected = 20;
static Notify_Structured_Push_Consumer* consumer_1 = 0;

class Consumer_Client : public Notify_Test_Client
{
public:
  virtual int parse_args (int argc, char* argv[]);
};


int
Consumer_Client::parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:e:t:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
  {
    case 'k':
      ior = get_opts.optarg;
      break;

    case 'e':
      expected = ACE_OS::atoi (get_opts.optarg);
      break;

    case 't':
      blocking_timeout = ACE_OS::atoi (get_opts.optarg);
      blocking_timeout *= 10 * 1000;
      break;

    default:
      ACE_ERROR_RETURN ((LM_ERROR,
        "usage:  %s "
        "-k <ior> "
        "-e <expected events> "
        "-t <relative blocking timeout milliseconds> "
        "\n",
        argv [0]),
        -1);
  }
  // Indicates sucessful parsing of the command line
  return 0;
}


static CosNotifyChannelAdmin::ConsumerAdmin_ptr
create_consumeradmin (CosNotifyChannelAdmin::EventChannel_ptr ec
                      ACE_ENV_ARG_DECL)
{
  CosNotifyChannelAdmin::AdminID adminid = 0;
  CosNotifyChannelAdmin::ConsumerAdmin_var admin =
    ec->new_for_consumers (CosNotifyChannelAdmin::OR_OP,
                           adminid
                           ACE_ENV_ARG_PARAMETER);

  ACE_CHECK_RETURN (0);

  return CosNotifyChannelAdmin::ConsumerAdmin::_duplicate (admin.in ());
}


static void
create_consumers (CosNotifyChannelAdmin::ConsumerAdmin_ptr admin,
                  Notify_Test_Client* client
                  ACE_ENV_ARG_DECL)
{
  // startup the consumer
  ACE_NEW_THROW_EX (consumer_1,
    Notify_Structured_Push_Consumer (
    "consumer1",
    blocking_timeout,
    expected,
    *client),
    CORBA::NO_MEMORY ());
  consumer_1->init (client->root_poa () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  consumer_1->_connect (admin ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

// ******************************************************************
// Main Section
// ******************************************************************

int main (int argc, char* argv[])
{
  int status = 0;
  ACE_TRY_NEW_ENV
  {
    Consumer_Client client;

    status = client.init (argc, argv ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;
    if (status != 0)
      ACE_ERROR_RETURN ((LM_ERROR, "Error: Client init failed.\n"),1);

    CosNotifyChannelAdmin::EventChannel_var ec =
      client.create_event_channel ("MyEventChannel", 1 ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    CORBA::ORB_ptr orb = client.orb ();
    CORBA::Object_var object =
      orb->string_to_object (ior ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    sig_var sig = sig::_narrow (object.in () ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    if (CORBA::is_nil (sig.in ()))
      ACE_ERROR_RETURN ((LM_ERROR, "Error: Narrow failed.\n"),1);

    CosNotifyChannelAdmin::ConsumerAdmin_var admin =
      create_consumeradmin (ec.in () ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    if (CORBA::is_nil (admin.in ()))
      ACE_ERROR_RETURN ((LM_ERROR, "Error: nil ConsumerAdmin.\n"),1);

    create_consumers (admin.in (), &client ACE_ENV_ARG_PARAMETER);
    ACE_TRY_CHECK;

    sig->go (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;

    ACE_DEBUG((LM_DEBUG, "\nConsumer waiting for events...\n"));
 
    client.ORB_run (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;

    ACE_DEBUG((LM_DEBUG, "Consumer done.\n"));
    consumer_1->disconnect(ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;

    sig->done (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;
  }
  ACE_CATCH (CORBA::Exception, e)
  {
    ACE_PRINT_EXCEPTION (e, "Error: ");
    status = 1;
  }
  ACE_ENDTRY;

  return status;
}
