#include "MessengerC.h"
#include <ace/Get_Opt.h>
#include <ace/Argv_Type_Converter.h>
#include <iostream>

int call_shutdown = 0;

int parse_args (int argc, ACE_TCHAR* argv[])
{
  ACE_Get_Opt get_opts (argc, argv, ACE_TEXT("x"));
  int c;

  while ((c = get_opts ()) != -1)
  {
    switch (c)
    {
      case 'x':
        call_shutdown = 1;
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage: %s\n "
                           "-x - call shutdown on server\n",
                           argv[0]),
                           -1);

    }
  }
  return 0;
}

int ACE_TMAIN( int argc, ACE_TCHAR* argv[] )
{
  try {
    // Initialize the ORB.
    ACE_Argv_Type_Converter conv(argc, argv);
    CORBA::ORB_var orb = CORBA::ORB_init(conv.get_argc(),
                                         conv.get_TCHAR_argv());

    // Parse arguments.
    if (parse_args (argc, argv) != 0)
      return 1;

    // Read and destringify the Messenger object's IOR.
    CORBA::Object_var obj = orb->string_to_object( "file://Messenger.ior" );
    if( CORBA::is_nil( obj.in() ) ) {
      std::cerr << "Could not get Messenger IOR." << std::endl;
      return 1;
    }

    // Narrow the IOR to a Messenger object reference.
    Messenger_var messenger = Messenger::_narrow( obj.in() );
    if( CORBA::is_nil( messenger.in() ) ) {
      std::cerr << "IOR was not a Messenger object reference." << std::endl;
      return 1;
    }

    // Send a message the the Messenger object.
    CORBA::String_var message = CORBA::string_dup( "Hello!" );
    messenger->send_message( "TAO User", "TAO Test", message.inout() );

    // Print the Messenger's reply.
    std::cout << "Reply: " << message.in() << std::endl;

    // Shutdown server?
    if (call_shutdown == 1)
    {
      messenger->shutdown();
      orb->perform_work();
    }

    orb->destroy();
  }
  catch(const CORBA::Exception& ex) {
    std::cerr << "CORBA exception: " << ex << std::endl;
    return 1;
  }

  return 0;
}
