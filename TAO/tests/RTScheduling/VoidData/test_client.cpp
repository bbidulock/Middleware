//$Id$
//#include "tao/RTScheduling/RTSchedulerC.h"
#include "testC.h"
#include "test.h"

int
main (int argc, char* argv [])
{
  CORBA::ORB_var orb =
    CORBA::ORB_init (argc,
                     argv,
                     ""
                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);
  
  //    ACE_SString ior;
  //    ior.rep (argv [1]);
  
  //    CORBA::Object_var object = 
  //      orb->string_to_object (ior.c_str ()
  //  			   ACE_ENV_ARG_PARAMETER)
  //      ACE_CHECK;
  
  test_ptr foo_i;
  
  ACE_NEW_RETURN (foo_i,
		  test_impl,
		  -1);

  int something =  28;
  foo_i->bar ((CORBA::VoidData)something);
  //orb->run ();
  return 0;
}

