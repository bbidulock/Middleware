eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{'ACE_ROOT'}/bin";
use PerlACE::TestTarget;

$CIAO_ROOT = "$ENV{'CIAO_ROOT'}";
$TAO_ROOT = "$ENV{'TAO_ROOT'}";
$DANCE_ROOT = "$ENV{'DANCE_ROOT'}";

$daemons_running = 0;
$em_running = 0;
$ns_running = 0;

$nr_daemon = 1;
@ports = ( 60001 );
@iorbases = ( "NodeApp1.ior" );
@iorfiles = 0;
@nodenames = ( "NodeOne" );

# ior files other than daemon
$ior_nsbase = "ns.ior";
$ior_nsfile = 0;
$ior_embase = "EM.ior";
$ior_emfile = 0;
$ior_applicationbase = "Node_APP.ior";
$ior_application = 0;
$ior_ambase = "Node_AM.ior";
$ior_am = 0;

#  Processes
$E = 0;
$EM = 0;
$NS = 0;
@DEAMONS = 0;

# targets
@tg_daemons = 0;
$tg_naming = 0;
$tg_exe_man = 0;
$tg_executor = 0;
$tg_convert_plan = 0;

$status = 0;

sub create_targets {
    #   naming service
    $tg_naming = PerlACE::TestTarget::create_target (1) || die "Create target for ns failed\n";
    $tg_naming->AddLibPath ('..');
    #   daemon
    for ($i = 0; $i < $nr_daemon; ++$i) {
        $tg_daemons[$i] = PerlACE::TestTarget::create_target ($i+1) || die "Create target for deamon $i failed\n";
        $tg_daemons[$i]->AddLibPath ('../Components');
    }
    #   execution manager
    $tg_exe_man = PerlACE::TestTarget::create_target (1) || die "Create target for EM failed\n";
    # $tg_exe_man->AddLibPath ('..');
    #   executor (plan_launcher)
    $tg_executor = PerlACE::TestTarget::create_target (1) || die "Create target for executor failed\n";
    #$tg_executor->AddLibPath ('..');

    $tg_convert_plan = PerlACE::TestTarget::create_target (1) || die "Could not create target for convert plan\n";
}

sub init_ior_files {
    $ior_nsfile = $tg_naming->LocalFile ($ior_nsbase);
    $ior_emfile = $tg_exe_man->LocalFile ($ior_embase);
    for ($i = 0; $i < $nr_daemon; ++$i) {
        $iorfiles[$i] = $tg_daemons[$i]->LocalFile ($iorbases[$i]);
    }
    $ior_application = $tg_executor->LocalFile ($ior_applicationbase);
    $ior_am = $tg_executor->LocalFile ($ior_ambase);

    delete_ior_files ();
}

# Delete if there are any .ior files.
sub delete_ior_files {
    for ($i = 0; $i < $nr_daemon; ++$i) {
        $tg_daemons[$i]->DeleteFile ($iorbases[$i]);
    }
    $tg_naming->DeleteFile ($ior_nsbase);
    $tg_exe_man->DeleteFile ($ior_embase);
    for ($i = 0; $i < $nr_daemon; ++$i) {
        $iorfiles[$i] = $tg_daemons[$i]->LocalFile ($iorbases[$i]);
    }
}

sub kill_node_daemon {
    for ($i = 0; $i < $nr_daemon; ++$i) {
        $DEAMONS[$i]->Kill (); $DEAMONS[$i]->TimedWait (1);
    }
}

sub kill_open_processes {
    if ($daemons_running == 1) {
        kill_node_daemon ();
    }

    if ($em_running == 1) {
        $EM->Kill (); $EM->TimedWait (1);
    }

    if ($ns_running == 1) {
        $NS->Kill (); $NS->TimedWait (1);
    }
    # in case shutdown did not perform as expected
    $tg_executor->KillAll ('ciao_componentserver');
}


sub run_node_daemons {
    for ($i = 0; $i < $nr_daemon; ++$i) {
        $iorbase = $iorbases[$i];
        $iorfile = $iorfiles[$i];
        $port = $ports[$i];
        $nodename = $nodenames[$i];
        $iiop = "iiop://localhost:$port";
        $node_app = "$CIAO_ROOT/bin/ciao_componentserver";

        $d_cmd = "$DANCE_ROOT/bin/dance_node_manager";
        $d_param = "-ORBEndpoint $iiop -s $node_app -n $nodename=$iorfile -t 30 --domain-nc corbaloc:rir:/NameService --instance-nc corbaloc:rir:/NameService";

        print "Run node daemon\n";

        $DEAMONS[$i] = $tg_daemons[$i]->CreateProcess ($d_cmd, $d_param);
        $DEAMONS[$i]->Spawn ();

        if ($tg_daemons[$i]->WaitForFileTimed($iorbase,
                                        $tg_daemons[$i]->ProcessStartWaitInterval ()) == -1) {
            print STDERR
              "ERROR: The ior $iorfile file of node daemon $i could not be found\n";
            for (; $i >= 0; --$i) {
                $DEAMONS[$i]->Kill (); $DEAMONS[$i]->TimedWait (1);
            }
            return -1;
        }
    }
    return 0;
}

if ($#ARGV == -1) {
    opendir(DIR, ".");
    @files = grep(/\.cdp$/,readdir(DIR));
    closedir(DIR);
}
else {
    @files = @ARGV;
}

create_targets ();
init_ior_files ();

foreach $file (@files) {
    print "Starting test for deployment $file\n";

    print STDERR "Starting Naming Service\n";

    $NS = $tg_naming->CreateProcess ("$TAO_ROOT/orbsvcs/Naming_Service/Naming_Service", "-m 0 -ORBEndpoint iiop://localhost:60003 -o $ior_nsfile");
    $NS->Spawn ();

    if ($tg_naming->WaitForFileTimed ($ior_nsbase,
                                      $tg_naming->ProcessStartWaitInterval ()) == -1) {
        print STDERR "ERROR: cannot find naming service IOR file\n";
        $NS->Kill (); $NS->TimedWait (1);
        exit 1;
    }

    $ns_running = 1;
    # Set up NamingService environment
    $ENV{"NameServiceIOR"} = "corbaloc:iiop:localhost:60003/NameService";

    # Invoke node daemon.
    print "Invoking node daemon\n";
    $status = run_node_daemons ();

    if ($status != 0) {
        print STDERR "ERROR: Unable to execute the node daemons\n";
        kill_open_processes ();
        exit 1;
    }

    $daemons_running = 1;

    print "Converting plan to CDR representation\n";
    $cdr_planbase = "$file" . ".cdr";
    $cdr_plan = $tg_convert_plan->LocalFile ($cdr_planbase);
    $convert = $tg_convert_plan->CreateProcess("$DANCE_ROOT/bin/dance_convert_plan",
                                               "-x $file -o $cdr_plan");

    $convert->Spawn ();

    if ($tg_convert_plan->WaitForFileTimed ($cdr_planbase,
                                            30) == -1) {
        print STDERR "ERROR: Convert Plan failed to output $cdr_plan.\n";
        kill_open_processes ();
        next;
    }
    
    $convert->Kill ();

    # Invoke executor - start the application -.
    print "Invoking executor - launch the application -\n";
    $E = $tg_executor->CreateProcess ("$DANCE_ROOT/bin/dance_plan_launcher",
                                      "-c $file.cdr -n file://NodeApp1.ior -l -oNode");
    $E->SpawnWaitKill (120);
    
    print "Teardown the application\n";
    $E = $tg_executor->CreateProcess ("$DANCE_ROOT/bin/dance_plan_launcher",
                                      "-n file://NodeApp1.ior -a file://Node_APP.ior -m file://Node_AM.ior -s");
    $E->SpawnWaitKill (120);
    print "Executor finished.\n";
    
    $tg_convert_plan->DeleteFile ($cdr_planbase);

    delete_ior_files ();
    kill_open_processes ();
}

delete_ior_files ();
kill_open_processes ();

exit $status;
