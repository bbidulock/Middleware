// $Id$

#include "ace/Get_Opt.h"
#include "Server_i.h"

ACE_RCSID(Time_Service, Server_i, "$Id$")

// Constructor.
Server_i::Server_i (void)
  : ior_output_file_ (0)
{
  // no-op.
}

// Destructor.

Server_i::~Server_i (void)
{
  // no-op.
}

// Parse the command-line arguments and set options.

int
Server_i::parse_args (void)
{
  ACE_Get_Opt get_opts (this->argc_, this->argv_, "do:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag.
        TAO_debug_level++;
        break;
      case 'o':  // output the IOR to a file.
        this->ior_output_file_ =
	  ACE_OS::fopen (get_opts.optarg, "a");

        if (this->ior_output_file_ == 0)
          ACE_ERROR_RETURN ((LM_ERROR,
                             "[SERVER] Process/Thread Id : (%P/%t)Unable to open %s for writing: %p\n",
                             get_opts.optarg), -1);
        break;
      case '?':  // display help for use of the server.
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "[SERVER] Process/Thread Id : (%P/%t)"
                           "usage:  %s"
                           " [-d]"
                           " [-o] <ior_output_file>"
                           "\n",
                           argv_ [0]),
                          1);
      }

  // Indicates successful parsing of command line.
  return 0;
}

// Initialise the Naming Service and register the TimeService Object
// with it.

int
Server_i::init_naming_service (CORBA::Environment& env)
{

  TAO_TRY
    {
      // Initialize the POA.
      this->orb_manager_.init_child_poa (this->argc_,
					 this->argv_,
					 "my_child_poa",
					 TAO_TRY_ENV);
      TAO_CHECK_ENV;

      PortableServer::POA_ptr child_poa
	= this->orb_manager_.child_poa ();

      // Initialize the Naming Server. Note the Naming Server cannot
      // be initialized with the Root POA because it has to be a
      // persistent object reference.  Hence the need for child
      // POA. The servants need not be registered in the same POA. We
      // use the Root POA for the servants.

      if (this->my_name_server_.init (this->orb_.in (),
				      child_poa) == -1)
	return -1;
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("(%P|%t) Exception from init_naming_service ()\n");
      TAO_TRY_ENV.clear ();
      return -1;
    }
  TAO_ENDTRY;

  return 0;
}

// Create a new time server object.

int
Server_i::create_server (void)
{
  TAO_TRY
    {
      // Create a new server object.
	   ACE_NEW_RETURN (this->time_service_server_impl_,
		      TAO_Time_Service_Server,
		      0);

      // Generate IOR of the <TimeService Server> and register with
      // POA.
      this->time_service_server_ =
        time_service_server_impl_->_this ();

      // Convert the server reference to a string.
      CORBA::String_var objref_server =
	this->orb_->object_to_string (this->time_service_server_.in (),
				      TAO_TRY_ENV);

      TAO_CHECK_ENV_RETURN (TAO_TRY_ENV, -1);

      // Print the server IOR on the console.
      ACE_DEBUG ((LM_DEBUG,
		  "[SERVER] Process/Thread Id : (%P/%t) The Time Service SERVER IOR is: <%s>\n",
		  objref_server.in ()));

      // Print the Time Service server IOR to a file.
      if (this->ior_output_file_)
	{
	  ACE_OS::fprintf (this->ior_output_file_,
			   "%s\n",
			   objref_server.in ());
	  ACE_OS::fclose (this->ior_output_file_);
	}
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Exception in Server_i::create_server ()");
      return -1;
    }
  TAO_ENDTRY;
  return 0;
}

// This function checks if this is the first server being executed. If yes,
// the call to resolve returns an exception and 1 is returned. If there is
// no exception 0 is returned.

int
Server_i::if_first_server (CosNaming::Name &server_context_name)
{
  TAO_TRY
    {
      this->my_name_server_->resolve
	(server_context_name, TAO_TRY_ENV);
      TAO_CHECK_ENV;
    }
  TAO_CATCH (CORBA::UserException, userex)
    {
      ACE_UNUSED_ARG (userex);
      return 1;
    }
  TAO_ENDTRY;
  return 0;
}

// Bind the Server in the context 'ServerContext' with the name
// 'Server:<hostname>'.

int
Server_i::register_server (void)
{
  TAO_TRY
    {
      CosNaming::Name server_context_name;
      server_context_name.length (1);
      server_context_name[0].id = CORBA::string_dup ("ServerContext");

      CosNaming::NamingContext_var server_context;

      // If this is the first server then get a new Naming Context
      // and bind it to the Naming Server.

      if (if_first_server (server_context_name))
	{
	  // Get context.
	  server_context =
            this->my_name_server_->new_context (TAO_TRY_ENV);
	  TAO_CHECK_ENV;

	  // Bind.
	  this->my_name_server_->rebind_context (server_context_name,
						 server_context.in (),
						 TAO_TRY_ENV);
	  TAO_CHECK_ENV;
	}

      char host_name[MAXHOSTNAMELEN];
      char server_mc_name[MAXHOSTNAMELEN];
      ACE_OS::hostname (host_name,MAXHOSTNAMELEN);

      CosNaming::Name server_name (server_context_name);

      server_name.length (2);
      strcpy (server_mc_name, "Server:");
      strcat (server_mc_name, host_name);
      server_name[1].id = CORBA::string_dup (server_mc_name);

      // Bind the compound name (ServerContext(Server:<hostname>))
      // to the Naming Server.

      this->my_name_server_->rebind (server_name,
				     this->time_service_server_.in (),
				     TAO_TRY_ENV);
      TAO_CHECK_ENV;

      ACE_DEBUG ((LM_DEBUG,
		  "Binding ServerContext -> %s\n",
		  server_name[1].id.in ()));
    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("(%P|%t) Exception from init_naming_service ()\n");
      return -1;
    }
  TAO_ENDTRY;

  return 0;
}

// Initialize the server. If a filename is specified with the -f
// commandline option, the server writes its IOR to the file besides
// binding itself with the Naming Service.

int
Server_i::init (int argc,
		char *argv[],
		CORBA::Environment &env)
{
  this->argc_ = argc;
  this->argv_ = argv;

  TAO_TRY
    {

      // Call the init of <TAO_ORB_Manager> to initialize the ORB and
      // create a child POA under the root POA.

      if (this->orb_manager_.init_child_poa (argc,
					     argv,
					     "child_poa",
					     TAO_TRY_ENV) == -1)
	ACE_ERROR_RETURN ((LM_ERROR,
			   "%p\n",
			   "init_child_poa"),
			  -1);

      TAO_CHECK_ENV_RETURN (TAO_TRY_ENV, -1);

      int result = this->parse_args ();

      if (result != 0)
	return result;

      // Get the orb.
      this->orb_ = this->orb_manager_.orb ();

      // Register the above implementation with the Naming Service.
      this->init_naming_service (TAO_TRY_ENV);

      // Create the server object.
      this->create_server ();

      // Register the server object with the Naming Service.
      this->register_server ();

    }
  TAO_CATCHANY
    {
      TAO_TRY_ENV.print_exception ("Exception:");
      return -1;
    }
  TAO_ENDTRY;

  return 0;
}

int
Server_i::run (CORBA::Environment &env)
{
TAO_TRY
    {
      // Run the main event loop for the ORB.
      if (this->orb_manager_.run (TAO_TRY_ENV) == -1)
	ACE_ERROR_RETURN ((LM_ERROR,
			   "[SERVER] Process/Thread Id : (%P/%t) Server_i::run"),
			  -1);
    }
 TAO_CATCHANY
   {
     TAO_TRY_ENV.print_exception ("Exception:");
     return -1;
  }
 TAO_ENDTRY;

 return 0;
}
