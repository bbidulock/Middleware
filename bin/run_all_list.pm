# -*- perl -*-
# $Id$
# This are the pairs "sub-directory , script" we run; the separator
# *must* be a space followed by a comma and then another space.

$ace_tests = 'tests , run_tests.pl';
if ($^O eq "MSWin32") {
  $ace_tests = 'tests , run_tests.bat';
}

@RUN_LIST =
    ( $ace_tests,
      'TAO/tests/Param_Test , run_test.pl',
      'TAO/tests/Param_Test , run_test.pl -i dii',
      'TAO/performance-tests/Cubit/TAO/IDL_Cubit , run_test.pl',
      'TAO/performance-tests/Cubit/TAO/MT_Cubit , run_test.pl -n 100',
      'TAO/performance-tests/Latency , run_test.pl',
      'TAO/performance-tests/POA/Object_Creation_And_Registration , run_test.pl',
      'TAO/performance-tests/RTCorba/Oneways/Reliable , run_test.pl',
      'TAO/tests/OctetSeq , run_test.pl',
      'TAO/tests/Leader_Followers , run_test.pl',
      'TAO/tests/Multiple_Inheritance , run_test.pl',
#HANGS     'TAO/tests/Endpoint_Per_Priority, run_test.pl',
      'TAO/tests/MT_Client , run_test.pl',
      'TAO/tests/MT_Server , run_test.pl',
      'TAO/tests/Faults , run_test.pl',
      'TAO/tests/NestedUpcall/Simple , run_test.pl',
      'TAO/tests/NestedUpcall/MT_Client_Test , run_test.pl',
      'TAO/tests/NestedUpcall/Triangle_Test , run_test.pl',
      'TAO/tests/Nested_Event_Loop , run_test.pl',
      'TAO/tests/POA/Identity , run_test.pl',
      'TAO/tests/POA/Deactivation , run_test.pl',
      'TAO/tests/POA/Destruction , run_test.pl',
      'TAO/tests/IORManipulation , run_test.pl',
      'TAO/tests/Policies , run_test.pl',
      'TAO/tests/Timeout , run_test.pl',
      'TAO/tests/Timed_Buffered_Oneways , run_test.pl',
      'TAO/tests/IDL_Test , run_test.pl',
      'TAO/tests/ORB_init , run_test.pl',
      'TAO/tests/DSI_Gateway , run_test.pl',
      'TAO/tests/DynAny_Test , run_test.pl',
      'TAO/tests/Connection_Purging , run_test.pl',
      'TAO/examples/Buffered_Oneways , run_test.pl',
# REQUIRES AMI 'TAO/examples/Buffered_AMI , run_test.pl',
      'TAO/examples/InterOp-Naming , run_test.pl',
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
      'TAO/examples/POA/Loader , run_test.pl',
      'TAO/examples/POA/RootPOA , run_test.pl',
      'TAO/examples/POA/Adapter_Activator , run_test.pl',
      'TAO/examples/Simple/bank , run_test.pl',
      'TAO/examples/Simple/grid , run_test.pl',
      'TAO/examples/Simple/time-date , run_test.pl',
      'TAO/examples/Simple/time , run_test.pl',
      'TAO/examples/Load_Balancing , run_test.pl',
      'TAO/orbsvcs/tests/Simple_Naming , run_test.pl',
      'TAO/orbsvcs/tests/Trading , run_test.pl',
      'TAO/orbsvcs/tests/Event/Basic , run_test.pl',
      'TAO/orbsvcs/tests/Event/Performance , run_test.pl',
      'TAO/orbsvcs/tests/EC_Basic , run_test.pl',
      'TAO/orbsvcs/tests/EC_Custom_Marshal , run_test.pl',
      'TAO/orbsvcs/tests/EC_Throughput , run_test.pl',
# BREAKS LINUX 'TAO/orbsvcs/tests/EC_Mcast , run_test.pl',
# FAILS 'TAO/orbsvcs/tests/EC_Multiple , run_test.pl',
      'TAO/orbsvcs/tests/Event_Latency , run_test.pl',
      'TAO/examples/Simple/echo , run_test.pl < Echo.idl',
# INTERACTIVE 'TAO/examples/Simple/chat , run_test.pl',
      'TAO/orbsvcs/tests/Property , run_test.pl',
#HANGS'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane',
#HANGS'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane_ir',
    );

@MINIMUM_CORBA_LIST =
    ( $ace_tests,
# NOT MINIMUM 'TAO/tests/Param_Test , run_test.pl',
# NOT MINIMUM 'TAO/tests/Param_Test , run_test.pl -i dii',
# NOT MINIMUM 'TAO/performance-tests/Cubit/TAO/IDL_Cubit , run_test.pl',
      'TAO/performance-tests/Cubit/TAO/MT_Cubit , run_test.pl -n 100',
# NOT MINIMUM 'TAO/performance-tests/Latency , run_test.pl',
      'TAO/performance-tests/POA/Object_Creation_And_Registration , run_test.pl',
# NOT MINIMUM 'TAO/performance-tests/RTCorba/Oneways/Reliable , run_test.pl',
      'TAO/tests/OctetSeq , run_test.pl',
      'TAO/tests/Leader_Followers , run_test.pl',
      'TAO/tests/Multiple_Inheritance , run_test.pl',
#HANGS     'TAO/tests/Endpoint_Per_Priority, run_test.pl',
      'TAO/tests/MT_Client , run_test.pl',
      'TAO/tests/MT_Server , run_test.pl',
# NOT MINIMUM 'TAO/tests/Faults , run_test.pl',
      'TAO/tests/NestedUpcall/Simple , run_test.pl',
      'TAO/tests/NestedUpcall/MT_Client_Test , run_test.pl',
      'TAO/tests/NestedUpcall/Triangle_Test , run_test.pl',
      'TAO/tests/Nested_Event_Loop , run_test.pl',
      'TAO/tests/POA/Identity , run_test.pl',
      'TAO/tests/POA/Deactivation , run_test.pl',
      'TAO/tests/POA/Destruction , run_test.pl',
      'TAO/tests/IORManipulation , run_test.pl',
# NOT MINIMUM 'TAO/tests/Policies , run_test.pl',
# NOT MINIMUM 'TAO/tests/Timeout , run_test.pl',
# NOT MINIMUM 'TAO/tests/Timed_Buffered_Oneways , run_test.pl',
      'TAO/tests/IDL_Test , run_test.pl',
      'TAO/tests/ORB_init , run_test.pl',
# NOT MINIMUM 'TAO/tests/DSI_Gateway , run_test.pl',
# NOT MINIMUM 'TAO/tests/DynAny_Test , run_test.pl',
      'TAO/tests/Connection_Purging , run_test.pl',
# NOT MINIMUM 'TAO/examples/Buffered_Oneways , run_test.pl',
# NOT MINIMUM 'TAO/examples/Buffered_AMI , run_test.pl',
      'TAO/examples/InterOp-Naming , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/Adapter_Activator , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/DSI , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/Default_Servant , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/Explicit_Activation , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/FindPOA , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/Forwarding , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/NewPOA , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/On_Demand_Activation , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/On_Demand_Loading , run_test.pl',
      'TAO/examples/POA/Reference_Counted_Servant , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/Loader , run_test.pl',
      'TAO/examples/POA/RootPOA , run_test.pl',
# NOT MINIMUM 'TAO/examples/POA/Adapter_Activator , run_test.pl',
      'TAO/examples/Simple/bank , run_test.pl',
      'TAO/examples/Simple/grid , run_test.pl',
      'TAO/examples/Simple/time-date , run_test.pl',
      'TAO/examples/Simple/time , run_test.pl',
# NOT MINIMUM 'TAO/examples/Load_Balancing , run_test.pl',
      'TAO/orbsvcs/tests/Simple_Naming , run_test.pl',
# NOT MINIMUM 'TAO/orbsvcs/tests/Trading , run_test.pl',
      'TAO/orbsvcs/tests/Event/Basic , run_test.pl',
      'TAO/orbsvcs/tests/Event/Performance , run_test.pl',
      'TAO/orbsvcs/tests/EC_Basic , run_test.pl',
      'TAO/orbsvcs/tests/EC_Custom_Marshal , run_test.pl',
      'TAO/orbsvcs/tests/EC_Throughput , run_test.pl',
# BREAKS LINUX 'TAO/orbsvcs/tests/EC_Mcast , run_test.pl',
# FAILS 'TAO/orbsvcs/tests/EC_Multiple , run_test.pl',
      'TAO/orbsvcs/tests/Event_Latency , run_test.pl',
      'TAO/examples/Simple/echo , run_test.pl < Echo.idl',
# INTERACTIVE 'TAO/examples/Simple/chat , run_test.pl',
      'TAO/orbsvcs/tests/Property , run_test.pl',
# FAILS 'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane',
# FAILS 'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane_ir',
    );

@SINGLE_THREADED_LIST =
    ( $ace_tests,
      'TAO/tests/Param_Test , run_test.pl',
      'TAO/tests/Param_Test , run_test.pl -i dii',
# NOT ST 'TAO/performance-tests/Cubit/TAO/IDL_Cubit , run_test.pl',
# NOT ST 'TAO/performance-tests/Cubit/TAO/MT_Cubit , run_test.pl -n 100'
# NOT ST 'TAO/performance-tests/Latency , run_test.pl',
      'TAO/performance-tests/POA/Object_Creation_And_Registration , run_test.pl',
      'TAO/performance-tests/RTCorba/Oneways/Reliable , run_test.pl',
      'TAO/tests/OctetSeq , run_test.pl',
# NOT ST 'TAO/tests/Leader_Followers , run_test.pl',
      'TAO/tests/Multiple_Inheritance , run_test.pl',
# NOT ST 'TAO/tests/MT_Client , run_test.pl',
# NOT ST 'TAO/tests/MT_Server , run_test.pl',
      'TAO/tests/Faults , run_test.pl',
# NOT ST 'TAO/tests/NestedUpcall/Simple , run_test.pl',
      'TAO/tests/NestedUpcall/MT_Client_Test , run_test.pl',
      'TAO/tests/NestedUpcall/Triangle_Test , run_test.pl',
      'TAO/tests/Nested_Event_Loop , run_test.pl',
      'TAO/tests/POA/Identity , run_test.pl',
      'TAO/tests/POA/Deactivation , run_test.pl',
      'TAO/tests/POA/Destruction , run_test.pl',
      'TAO/tests/IORManipulation , run_test.pl',
# NOT ST 'TAO/tests/Policies , run_test.pl',
      'TAO/tests/Timeout , run_test.pl',
      'TAO/tests/Timed_Buffered_Oneways , run_test.pl',
      'TAO/tests/ORB_init , run_test.pl',
      'TAO/tests/DSI_Gateway , run_test.pl',
      'TAO/tests/DynAny_Test , run_test.pl',
      'TAO/tests/Connection_Purging , run_test.pl',
      'TAO/examples/Buffered_Oneways , run_test.pl',
# REQUIRES AMI 'TAO/examples/Buffered_AMI , run_test.pl',
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
      'TAO/examples/POA/Loader , run_test.pl',
      'TAO/examples/POA/RootPOA , run_test.pl',
      'TAO/examples/POA/Adapter_Activator , run_test.pl',
      'TAO/examples/Simple/bank , run_test.pl',
      'TAO/examples/Simple/grid , run_test.pl',
# NOT ST 'TAO/examples/Simple/time-date , run_test.pl',
      'TAO/examples/Simple/time , run_test.pl',
      'TAO/orbsvcs/tests/Simple_Naming , run_test.pl',
      'TAO/orbsvcs/tests/Trading , run_test.pl',
# NOT ST 'TAO/orbsvcs/tests/Event/Basic , run_test.pl',
# NOT ST 'TAO/orbsvcs/tests/Event/Performance , run_test.pl',
      'TAO/orbsvcs/tests/EC_Basic , run_test.pl',
# NOT ST 'TAO/orbsvcs/tests/EC_Custom_Marshal , run_test.pl',
# NOT ST 'TAO/orbsvcs/tests/EC_Throughput , run_test.pl',
# BREAKS LINUX 'TAO/orbsvcs/tests/EC_Mcast , run_test.pl',
# FAILS 'TAO/orbsvcs/tests/EC_Multiple , run_test.pl',
      'TAO/orbsvcs/tests/Event_Latency , run_test.pl',
      'TAO/examples/Simple/echo , run_test.pl < Echo.idl',
# INTERACTIVE 'TAO/examples/Simple/chat , run_test.pl',
      'TAO/orbsvcs/tests/Property , run_test.pl',
# FAILS 'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane',
# FAILS 'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane_ir',
    );

@AMI_CORBA_LIST =
    ( $ace_tests,
      'TAO/tests/Param_Test , run_test.pl',
      'TAO/tests/Param_Test , run_test.pl -i dii',
      'TAO/performance-tests/Cubit/TAO/IDL_Cubit , run_test.pl',
      'TAO/performance-tests/Cubit/TAO/MT_Cubit , run_test.pl -n 100',
      'TAO/performance-tests/Latency , run_test.pl',
      'TAO/performance-tests/POA/Object_Creation_And_Registration , run_test.pl',
      'TAO/performance-tests/RTCorba/Oneways/Reliable , run_test.pl',
      'TAO/tests/OctetSeq , run_test.pl',
      'TAO/tests/Leader_Followers , run_test.pl',
#      'TAO/tests/Endpoint_Per_Priority, run_test.pl',
      'TAO/tests/Multiple_Inheritance , run_test.pl',
      'TAO/tests/MT_Client , run_test.pl',
      'TAO/tests/MT_Server , run_test.pl',
      'TAO/tests/Faults , run_test.pl',
      'TAO/tests/NestedUpcall/Simple , run_test.pl',
      'TAO/tests/NestedUpcall/MT_Client_Test , run_test.pl',
      'TAO/tests/NestedUpcall/Triangle_Test , run_test.pl',
      'TAO/tests/Nested_Event_Loop , run_test.pl',
      'TAO/tests/POA/Identity , run_test.pl',
      'TAO/tests/POA/Deactivation , run_test.pl',
      'TAO/tests/POA/Destruction , run_test.pl',
      'TAO/tests/IORManipulation , run_test.pl',
      'TAO/tests/Policies , run_test.pl',
      'TAO/tests/Timeout , run_test.pl',
      'TAO/tests/Timed_Buffered_Oneways , run_test.pl',
      'TAO/tests/IDL_Test , run_test.pl',
      'TAO/tests/ORB_init , run_test.pl',
      'TAO/tests/DSI_Gateway , run_test.pl',
      'TAO/tests/AMI , run_test.pl',
      'TAO/examples/Buffered_Oneways , run_test.pl',
      'TAO/examples/Buffered_AMI , run_test.pl',
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
      'TAO/examples/POA/Loader , run_test.pl',
      'TAO/examples/POA/RootPOA , run_test.pl',
      'TAO/examples/POA/Adapter_Activator , run_test.pl',
      'TAO/examples/Simple/bank , run_test.pl',
      'TAO/examples/Simple/grid , run_test.pl',
      'TAO/examples/Simple/time-date , run_test.pl',
      'TAO/examples/Simple/time , run_test.pl',
      'TAO/examples/Load_Balancing , run_test.pl',
      'TAO/orbsvcs/tests/Simple_Naming , run_test.pl',
      'TAO/orbsvcs/tests/Trading , run_test.pl',
      'TAO/orbsvcs/tests/Event/Basic , run_test.pl',
      'TAO/orbsvcs/tests/Event/Performance , run_test.pl',
      'TAO/orbsvcs/tests/EC_Basic , run_test.pl',
      'TAO/orbsvcs/tests/EC_Custom_Marshal , run_test.pl',
      'TAO/orbsvcs/tests/EC_Throughput , run_test.pl',
# BREAKS LINUX 'TAO/orbsvcs/tests/EC_Mcast , run_test.pl',
# FAILS 'TAO/orbsvcs/tests/EC_Multiple , run_test.pl',
      'TAO/orbsvcs/tests/Event_Latency , run_test.pl',
      'TAO/examples/Simple/echo , run_test.pl < Echo.idl',
# INTERACTIVE 'TAO/examples/Simple/chat , run_test.pl',
      'TAO/orbsvcs/tests/Property , run_test.pl',
# HANGS'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane',
# HANGS'TAO/orbsvcs/tests/ImplRepo , run_test.pl airplane_ir',
    );
1;
