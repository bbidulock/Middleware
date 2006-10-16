eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# run_test.pl,v 1.5 2006/01/31 21:54:08 wotte Exp
# -*- perl -*-

use lib "$ENV{'ACE_ROOT'}/bin";
use PerlACE::Run_Test;

$DAnCE = "$ENV{'CIAO_ROOT'}/DAnCE";
$CIAO_ROOT = "$ENV{'CIAO_ROOT'}";
$TAO_ROOT = "$ENV{'TAO_ROOT'}";
$daemons_running = 0;
$em_running = 0;
$ns_running = 0;
$daemons = 10;
@ports = ( 50000, 50001, 50002, 50003, 50004,50005,50006,50007, 50008, 50009, 50010  );
@iorfiles = ( "NodeApp1.ior", "NodeApp2.ior", "NodeApp3.ior", "NodeApp4.ior", "NodeApp5.ior","NodeApp6.ior","NodeApp7.ior", "NodeApp8.ior", "NodeApp9.ior", "NodeApp10.ior", "NodeApp11.ior" );
$status = 0;
$dat_file = "NodeDetails.dat";
$cdp_file = "RACE.cdp";

$nsior = PerlACE::LocalFile ("ns.ior");

unlink $nsior;

$E = 0;
$EM = 0;

# Delete if there are any .ior files.
sub delete_ior_files {
    for ($i = 0; $i < $daemons; ++$i) {
        unlink $iorfiles[$i];
    }
    unlink PerlACE::LocalFile ("EM.ior");
    unlink PerlACE::LocalFile ("Receiver.ior");
    unlink PerlACE::LocalFile ("Sender.ior");
    unlink PerlACE::LocalFile ("DAM.ior");
    unlink PerlACE::LocalFile ("ns.ior");
}

sub kill_node_daemons {
  for ($i = 0; $i < $daemons; ++$i) {
    $Daemons[$i]->Kill (); $Daemons[$i]->TimedWait (1);
  }
}

sub kill_open_processes {
  if ($daemons_running == 1) {
    kill_node_daemons ();
  }

  if ($em_running == 1) {
    $EM->Kill ();
    $EM->TimedWait (1);
  }

  if ($ns_running == 1) {
    $NS->Kill ();
    $NS->TimedWait (1);
  }

}

sub run_node_daemons {
  for ($i = 0; $i < $daemons; ++$i)
  {
      $iorfile = $iorfiles[$i];
      $port = $ports[$i];

      $iiop = "iiop://localhost:$port";
      $node_app = "$DAnCE/NodeApplication/NodeApplication";

      $d_cmd = "$DAnCE/NodeManager/NodeManager";
      $d_param = "-n -ORBEndpoint $iiop -s $node_app -o $iorfile -d 30";

      $Daemons[$i] = new PerlACE::Process ($d_cmd, $d_param);
      $result = $Daemons[$i]->Spawn ();
      push(@processes, $Daemons[$i]);

      if (PerlACE::waitforfile_timed ($iorfile,
                          $PerlACE::wait_interval_for_process_creation) == -1) {
          print STDERR
            "ERROR: The ior file of node daemon $i could not be found\n";
          for (; $i > 0; --$i) {
            $Daemons[$i]->Kill (); $Daemons[$i]->TimedWait (1);
          }
          return -1;
      }
  }
  $daemons_running = 1;
  return 0;
}

delete_ior_files ();

# Invoke naming service

$NS = new PerlACE::Process ("$TAO_ROOT/orbsvcs/Naming_Service/Naming_Service", "-m 1 -ORBEndpoint iiop://10.1.250.100:40003 -o ns.ior");

$NS->Spawn ();

 print STDERR "Starting Naming Service\n";

 if (PerlACE::waitforfile_timed ($nsior, 10) == -1)
 {
     print STDERR "ERROR: cannot find naming service IOR file\n";
     $NS->Kill ();
     exit 1;
 }

# Set up NamingService environment
$ENV{"NameServiceIOR"} = "corbaloc:iiop:10.1.250.100:40003/NameService";

# Invoke node daemons.
print "Invoking node daemons\n";
#$status = run_node_daemons ();
$Status = 0;

if ($status != 0) {
  print STDERR "ERROR: Unable to execute the node daemons\n";
  exit 1;
}

$ns_running = 1;

# Invoke execution manager.
# print "Invoking execution manager\n";
 $EM = new PerlACE::Process ("$DAnCE/ExecutionManager/Execution_Manager",  "-n -ORBEndpoint iiop://10.1.250.100 -o EM.ior -i $dat_file");
 $EM->Spawn ();

# if (PerlACE::waitforfile_timed ("EM.ior",
#                         $PerlACE::wait_interval_for_process_creation) == -1) {
#     print STDERR
#       "ERROR: The ior file of execution manager could not be found\n";
#     kill_open_processes ();
#     exit 1;
# }

$em_running = 1;

# print " Invoke executor - start the application -."
print "Invoking executor - start the application -\n";
$E =
  new PerlACE::Process ("$DAnCE/Plan_Launcher/plan_launcher",
                        "-p $cdp_file -n");

$E->SpawnWaitKill (5000);

#if (PerlACE::waitforfile_timed (
#      "Receiver.ior",
#      $PerlACE::wait_interval_for_process_creation) == -1) {
#    print STDERR "ERROR: The ior file of receiver could not be found\n";
#    kill_open_processes ();
#    exit 1;
#}

#if (PerlACE::waitforfile_timed ("Sender.ior",
#                        $PerlACE::wait_interval_for_process_creation) == -1) {
#    print STDERR "ERROR: The ior file of sender could not be found\n";
#    kill_open_processes ();
#    exit 1;
#}

#print "Invoking the controller\n";
#$controller = new PerlACE::Process ("$controller_exec", "-k file://Sender.ior");
#$result = $controller->SpawnWaitKill (3000);

#if ($result != 0) {
#    print STDERR "ERROR: The controller returned $result\n";
#    $status = 1;
#}

# Invoke executor - stop the application -.
#print "Invoking executor - stop the application -\n";
#$E =
#  new PerlACE::Process ("$DAnCE/Plan_Launcher/plan_launcher",
#                        "-k file://EM.ior -i file://DAM.ior");
#$E->SpawnWaitKill (3000);

print "Executor returned.\n";
print "Shutting down rest of the processes.\n";

delete_ior_files ();
kill_open_processes ();

exit $status;
