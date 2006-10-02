/**
 * @file Injector.cpp
 * @author Will Otte <wotte@dre.vanderbilt.edu>
 */

#include "Input_Adapters/Interactive_Input_Adapter/Interactive_Input_AdapterC.h"
#include "ace/OS.h"
#include "ace/Get_Opt.h"
#include "ace/SString.h"
#include "orbsvcs/CosNamingC.h"
#include "ace/Auto_Ptr.h"

namespace CIAO
{
  namespace RACE
  {
    namespace Injector
    {
      const char *package_uri = 0;
      const char *plan_uri = 0;
      const char *iia_ior_file = 0;
      const char *iia_name = "RACE::InteractiveInput";
      bool teardown = false;

      static void
      usage (const ACE_TCHAR* program)
      {
	ACE_ERROR ((LM_ERROR,
		    ACE_TEXT ("Usage %s\n")
		    ACE_TEXT ("-d <Flatten deployment plan URI>\n")
		    ACE_TEXT ("-p <Toplevel Package URI>\n")
		    ACE_TEXT ("-t <Teardown plan>\n")
		    ACE_TEXT ("-k <Interactive_Input_Adaptor IOR, "
                              "use naming service if not present\n"),
                    program));
      }

      static bool
      parse_args (int argc,
		  ACE_TCHAR *argv[])
      {
	ACE_Get_Opt get_opt (argc,
			     argv,
			     ACE_TEXT ("d:p:k:thn:"));
	int c;

	while ((c = get_opt ()) != EOF)
	  {
	    switch (c)
	      {
	      case 'd':
		plan_uri = get_opt.opt_arg ();
		break;

	      case 'p':
		package_uri = get_opt.opt_arg ();
		break;

	      case 'k':
		iia_ior_file = get_opt.opt_arg ();
		break;

              case 't':
                teardown = true;
		break;

              case 'n':
                iia_name = get_opt.opt_arg ();

	      case 'h':
	      default:
		usage (argv[0]);
		return false;
	      }
	  }

	return true;
      }

      CORBA::Object_ptr
      fetch_reference_naming (CORBA::ORB_ptr orb,
			      const  ACE_CString &name)
      {
	ACE_ERROR ((LM_ERROR, "Resolving via nameservice...\n"));
	using namespace CosNaming;
	// Resolve naming service
	CORBA::Object_var tmp =
	  orb->resolve_initial_references ("NameService");

	NamingContext_var pns =
	  NamingContext::_narrow (tmp.in ());

        Name ns_name;
	CORBA::ULong i = 0;

        ACE_Tokenizer tok ( name.rep ());
        tok.delimiter_replace (':', 0);
        tok.delimiter_replace ('/', 0);

        char *name_element = 0;
        while ((name_element = tok.next ()) != 0)
          {
            ns_name.length (ns_name.length () + 1);
            ns_name[i].id = CORBA::string_dup (name_element);
            ++i;
          }


	return pns->resolve (ns_name);
      }

      static int
      run_main_implementation (int argc,  ACE_TCHAR *argv[])
      {
	try
	  {
	    CORBA::ORB_var orb =
	      CORBA::ORB_init (argc, argv, "");

	    if (!parse_args (argc, argv))
	      return -1;


	    // Resolve our input adapter...
	    CORBA::Object_var tmp;

	    if (iia_ior_file != 0)
	      tmp = orb->string_to_object (iia_ior_file);
	    else // must be a name....
	      tmp = fetch_reference_naming (orb.in (), iia_name);

	    CIAO::RACE::Interactive_Input_Adapter_var iia
	      = CIAO::RACE::Interactive_Input_Adapter::_narrow (tmp.in ());

	    // Create deploy input event.
	    CIAO::RACE::Deploy_Input_var input =
	      new OBV_CIAO::RACE::Deploy_Input;

	    input->plan_uri (plan_uri);
	    input->package_uri (package_uri);

            if (teardown)
              {
                input->command (::CIAO::RACE::TEARDOWN);
              }
            else
              {
                input->command (::CIAO::RACE::DEPLOY);
              }



	    // Get the consumer for the IIA
	    ::CIAO::RACE::Deploy_InputConsumer_var consumer =
		iia->get_consumer_deployment ();

	    // push the event
	    consumer->push_Deploy_Input (input.in ());

	  }
	catch (...)
	  {
	    ACE_ERROR ((LM_ERROR,
			"(%P|%t) Injector: Unknown exception\n"));
	    return -1;
	  }

      return 0;
      }
    }
  }
}

int main (int argc, ACE_TCHAR **argv)
{
  return CIAO::RACE::Injector::run_main_implementation (argc, argv);
}
