// $Id$

#include "server.h"
//#include <time.h>
//#include <iostream.h>

//-----------------------------------------------------------------------------

TimeOfDay
Time_impl::
get_gmt() throw(CORBA::SystemException)
{
    time_t time_now = time(0);
    struct tm * time_p = gmtime(&time_now);

    TimeOfDay tod;
    tod.hour = time_p->tm_hour;
    tod.minute = time_p->tm_min;
    tod.second = time_p->tm_sec;

    return tod;
}


void do_something_else()
{};


int
main(int argc, char * argv[])
{
    try {
        // Initialize orb
        CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

        // Get reference to Root POA.
        CORBA::Object_var obj
            = orb->resolve_initial_references("RootPOA");
        PortableServer::POA_var poa
            = PortableServer::POA::_narrow(obj.in());

        // Activate POA manager
        PortableServer::POAManager_var mgr
            = poa->the_POAManager();
        mgr->activate();

        // Create an object
        Time_impl time_servant;

        // Write its stringified reference to stdout
        Time_var tm = time_servant._this();
        CORBA::String_var str = orb->object_to_string(tm.in());
        cout << str.in() << endl;

        // Enter event loop.
        while (1) {
           if (orb->work_pending())
               orb->perform_work();
           do_something_else();
        }
        orb->shutdown(1);

    }
    catch (const CORBA::Exception &) {
        cerr << "Uncaught CORBA exception" << endl;
        return 1;
    }
    return 0;
}








