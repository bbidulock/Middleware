eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{'ACE_ROOT'}/bin";
use PerlACE::Run_Test;

$DAnCE = "$ENV{'CIAO_ROOT'}/DAnCE";

$daemons = 2;
@ports = ( 30000, 40000 );
@iorfiles = ( "NodeApp1.ior", "NodeApp2.ior" );
$status = 0;
$dat_file = "NodeManagerMap.dat";
$cdp_file = "DeploymentPlan.cdp";
$controller_exec = "$DAnCE/examples/Hello/Sender/starter";

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
}

sub run_node_daemons {
  for ($i = 0; $i < $daemons; ++$i)
  {
      $iorfile = $iorfiles[$i];
      $port = $ports[$i];

      $iiop = "iiop://localhost:$port";
      $node_app = "$DAnCE/NodeApplication/NodeApplication";

      $d_cmd = "$DAnCE/NodeManager/Node_Daemon";
      $d_param = "-ORBEndpoint $iiop -s $node_app -o $iorfile";

      $Daemons[$i] = new PerlACE::Process ($d_cmd, $d_param);
      $result = $Daemons[$i]->Spawn ();
      push(@processes, $Daemons[$i]);

      if (PerlACE::waitforfile_timed ($iorfile,
                          $PerlACE::wait_interval_for_process_creation) == -1) {
          print STDERR
            "ERROR: The ior file of node daemon $i could not be found\n";
          kill_open_processes (); 
          exit 1;
      }
  }
}

sub kill_node_daemons {
  for ($i = 0; $i < $daemons; ++$i) {
    $Daemons[$i]->Kill (); $Daemons[$i]->TimedWait (1);
  }
}

delete_ior_files ();

# Invoke node daemons.
print "Invoking node daemons\n";
run_node_daemons ();

# Invoke execution manager.
print "Invoking execution manager\n";
$EM = new PerlACE::Process ("$DAnCE/ExecutionManager/Execution_Manager",
                            "-o EM.ior -i $dat_file");
$EM->Spawn ();

if (PerlACE::waitforfile_timed ("EM.ior",
                        $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR
      "ERROR: The ior file of execution manager could not be found\n";
    kill_open_processes (); 
    exit 1;
}

# Invoke executor - start the application -.
print "Invoking executor - start the application -\n";
$E =
  new PerlACE::Process ("$DAnCE/Plan_Launcher/plan_launcher",
                        "-p flattened_deploymentplan.cdp -k file://EM.ior -o DAM.ior");
 
$E->SpawnWaitKill (5000);

if (PerlACE::waitforfile_timed (
      "Receiver.ior",
      $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR "ERROR: The ior file of receiver could not be found\n";
    kill_open_processes (); 
    exit 1;
}

if (PerlACE::waitforfile_timed ("Sender.ior",
                        $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR "ERROR: The ior file of sender could not be found\n";
    kill_open_processes (); 
    exit 1;
}

print "Invoking the controller\n";
$controller = new PerlACE::Process ("$controller_exec", "-k file://Sender.ior");
$result = $controller->SpawnWaitKill (3000);

if ($result != 0) {
    print STDERR "ERROR: The controller returned $result\n";
    $status = 1;
}

# Invoke executor - stop the application -.
print "Invoking executor - stop the application -\n";
$E =
  new PerlACE::Process ("$DAnCE/Plan_Launcher/plan_launcher",
                        "-k file://EM.ior -i file://DAM.ior");
$E->SpawnWaitKill (3000);

print "Executor returned.\n";
print "Shutting down rest of the processes.\n";

# delete_ior_files ();
$EM->Kill (); $EM->TimedWait (1);
kill_node_daemons ();

exit $status;
