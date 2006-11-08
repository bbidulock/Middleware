
//=============================================================================
/**
 *  @file    client.cpp
 *
 *  $Id$
 *
 *  A client which uses the AMI callback model.
 *
 *
 *  @author Alexander Babu Arulanthu <alex@cs.wustl.edu>
 *  @author Michael Kircher <Michael.Kircher@mchp.siemens.de>
 */
//=============================================================================


#include "ace/Get_Opt.h"
#include "ace/Task.h"
#include "ami_testS.h"

ACE_RCSID (AMI,
           client,
           "$Id$")

const char *ior = "file://test.ior";
int nthreads = 5;
int niterations = 5;
int debug = 0;
int number_of_replies = 0;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "dk:n:i:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':
        debug = 1;
        break;
      case 'k':
        ior = get_opts.opt_arg ();
        break;
      case 'n':
        nthreads = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case 'i':
        niterations = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-d "
                           "-k <ior> "
                           "-n <nthreads> "
                           "-i <niterations> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

/**
 * @class Client
 *
 * @brief Run the client thread
 *
 * Use the ACE_Task_Base class to run the client threads.
 */
class Client : public ACE_Task_Base
{
public:
  /// ctor
  Client (A::AMI_Test_ptr server, int niterations);

  /// The thread entry point.
  virtual int svc (void);

  // private:
  /// Var for the AMI_Test object.
  A::AMI_Test_var ami_test_var_;

  /// The number of iterations on each client thread.
  int niterations_;

  /// Var for AMI_AMI_Test_ReplyHandler object.
  A::AMI_AMI_TestHandler_var the_handler_var_;
};

class Handler : public POA_A::AMI_AMI_TestHandler
{
public:
  Handler (void) {};

  void foo (CORBA::Long result,
            CORBA::Long out_l
            ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      if (debug)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "(%P | %t) : Callback method called: result <%d>, out_arg <%d>\n",
                      result,
                      out_l));
        }

      --number_of_replies;
    };

   void foo_excep (::Messaging::ExceptionHolder * excep_holder
                  ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {

      ACE_DEBUG ((LM_DEBUG,
                  "Callback method <foo_excep> called: \n"));
      ACE_TRY
        {
          excep_holder->raise_exception (ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      ACE_CATCHANY
        {
          ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                               "Caught exception:");
        }
      ACE_ENDTRY;
      ACE_CHECK;
    };

  void get_yadda (CORBA::Long result
                  ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Callback method <get_yadda> called: result <%d>\n",
                  result));
    };

  void get_yadda_excep (::Messaging::ExceptionHolder *
                        ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Callback method <get_yadda_excep> called: \n"));
    };

  void set_yadda (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Callback method <set_yadda> called: \n"));
    };

  void set_yadda_excep (::Messaging::ExceptionHolder *
                        ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException))
    {
      ACE_DEBUG ((LM_DEBUG,
                  "Callback method <set_yadda_excep> called: \n"));
    };
  ~Handler (void) {};

  void inout_arg_test (
      const char *
      ACE_ENV_ARG_DECL_NOT_USED
      )
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    ACE_DEBUG ((LM_DEBUG,
                "Callback method <set_yadda_excep> called: \n"));
  }

  void inout_arg_test_excep (::Messaging::ExceptionHolder *
                             ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
  }
};

// ReplyHandler.
Handler handler;

int
main (int argc, char *argv[])
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object (ior ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      A::AMI_Test_var server =
        A::AMI_Test::_narrow (object.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (server.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Object reference <%s> is nil\n",
                             ior),
                            1);
        }

      // Activate POA to handle the call back.

      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA" ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      poa_manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      // Let the client perform the test in a separate thread

      Client client (server.in (), niterations);
      if (client.activate (THR_NEW_LWP | THR_JOINABLE,
                           nthreads) != 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot activate client threads\n"),
                          1);

      // Main thread collects replies. It needs to collect
      // <nthreads*niterations> replies.
      number_of_replies = nthreads *niterations;

      if (debug)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "(%P|%t) : Entering perform_work loop to receive <%d> replies\n",
                      number_of_replies));
        }

      // ORB loop.

      while (number_of_replies > 0)
        {
          CORBA::Boolean pending =
            orb->work_pending(ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;

          if (pending)
            {
              orb->perform_work(ACE_ENV_SINGLE_ARG_PARAMETER);
              ACE_TRY_CHECK;
            }
        }

      if (debug)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "(%P|%t) : Exited perform_work loop Received <%d> replies\n",
                      (nthreads*niterations) - number_of_replies));
        }


      client.thr_mgr ()->wait ();

      ACE_DEBUG ((LM_DEBUG, "threads finished\n"));

      //client.ami_test_var_->shutdown ();

      root_poa->destroy (1,  // ethernalize objects
                         0  // wait for completion
                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      orb->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Caught exception:");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}

// ****************************************************************

Client::Client (A::AMI_Test_ptr server,
                int niterations)
                :  ami_test_var_ (A::AMI_Test::_duplicate (server)),
     niterations_ (niterations)
{
  the_handler_var_ = handler._this (/* ACE_ENV_SINGLE_ARG_PARAMETER */);
}

int
Client::svc (void)
{
  ACE_TRY_NEW_ENV
    {
      CORBA::Long number = 931232;

      for (int i = 0; i < this->niterations_; ++i)
        {
          ami_test_var_->sendc_foo (the_handler_var_.in (),
                                    number,
                                    "Let's talk AMI."
                                    ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }
      if (debug)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "(%P | %t):<%d> Asynchronous methods issued\n",
                      niterations));
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "MT_Client: exception raised");
    }
  ACE_ENDTRY;
  return 0;
}
