# -*- perl -*-
# $Id$
# This are the pairs "sub-directory , script" we run; the separator
# *must* be a space followed by a comma and then another space.

@RUN_LIST = (
      'tests , run_tests.bat',
      'TAO/tests/Param_Test , run_test.pl',
      'TAO/tests/Param_Test , run_test.pl -i dii',
      'TAO/performance-tests/Cubit/TAO/IDL_Cubit , run_test.pl',
      'TAO/tests/OctetSeq , run_test.pl',
      'TAO/tests/Multiple_Inheritance , run_test.pl',
      'TAO/tests/MT_Client , run_test.pl',
      'TAO/tests/MT_Server , run_test.pl',
      'TAO/tests/Faults , run_test.pl',
      'TAO/tests/NestedUpcall/Reactor , run_test.pl',
      'TAO/tests/NestedUpcall/MT_Client_Test , run_test.pl',
      'TAO/tests/POA/Identity , run_test.pl',
      'TAO/tests/POA/Destruction , run_test.pl',
      'TAO/tests/IORManipulation , run_test.pl',
      'TAO/examples/POA/Adapter_Activator , run_test.pl',
      'TAO/examples/POA/DSI , run_test.pl',
      'TAO/examples/POA/Default_Servant , run_test.pl',
      'TAO/examples/POA/Explicit_Activation , run_test.pl',
      'TAO/examples/POA/FindPOA , run_test.pl',
      'TAO/examples/POA/Forwarding , run_test.pl',
      'TAO/examples/POA/NewPOA , run_test.pl',
      'TAO/examples/POA/On_Demand_Activation , run_test.pl',
      'TAO/examples/POA/On_Demand_Loading , run_test.pl',
      'TAO/examples/POA/Reference_Counted_Servant , run_test.pl',
      'TAO/examples/Simple/bank , run_test.pl',
      'TAO/examples/Simple/grid , run_test.pl',
      'TAO/examples/Simple/time-date , run_test.pl',
      'TAO/examples/Simple/time , run_test.pl',
      'TAO/orbsvcs/tests/Simple_Naming , run_test.pl',
      'TAO/orbsvcs/tests/Trading , run_test.pl',
      'TAO/orbsvcs/tests/Event/Basic , run_test.pl',
      'TAO/orbsvcs/tests/Event/Performance , run_test.pl',
      'TAO/orbsvcs/tests/EC_Basic , run_test.pl',
      'TAO/orbsvcs/tests/EC_Custom_Marshal , run_test.pl',
      'TAO/orbsvcs/tests/EC_Throughput , run_test.pl',
#      'TAO/orbsvcs/tests/EC_Mcast , run_test.pl',
#      'TAO/orbsvcs/tests/EC_Multiple , run_test.pl',
      'TAO/orbsvcs/tests/Event_Latency , run_test.pl',
      'TAO/examples/Simple/echo , run_test.pl < Echo.idl',
#      'TAO/examples/Simple/chat , run_test.pl',
      'TAO/orbsvcs/tests/Property , run_test.pl',
      'TAO/performance-tests/POA/Object_Creation_And_Registration , run_test.pl',
      'TAO/performance-tests/Cubit/TAO/MT_Cubit , run_test.pl -n 100'
#      'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane',
#      'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane_ir',
    );

1;
