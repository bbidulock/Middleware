eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

# Purpose:
#       To test the FactoryRegistry as a component of ReplicationManager
#
# Process being tested:
#       FT_ReplicationManager
#           implements PortableGroup::FactoryRegistry interface.
# Processes used in test:
#       FT_Replica * 3
#           implements GenericFactory interface to create TestReplicas
#           TestReplica implements TestReplica interface.
#           TestReplica implements PullMonitorable interface.
#       FT_Client
#           client for TestReplica interface.
#           client for PullMonitorable.
#       Object Group Creator
#           Creates groups of objects.
#
# Test Scenario (***Test: marks behavior being tested):
#
#   First the test starts The ReplicationManager,
#   Then starts three factories.  Each factory exists at a separate location.
#   The locations are named shire, bree, and rivendell.  In a "real" system
#   these locations would be on separate computers.
#
#   The factory at the shire location knows how to create hobbits.
#   The factory at the bree location knows how to create hobbits, elves, and humans.
#   The factory at rivendell can create elves.
#   Hobbits, elves, and humans are roles for TestReplica objects.  A creation parameter
#   included as part of the registration information specifies which role they are playing.
#
#   ***Test: The factories register themselves with the factory registry in the ReplicationManager.
#   Registration information includes:
#     the role,
#     the type of object created,
#     the location,
#     an object reference to the factory and
#     a set of parameters to be passed to the factory's create_object method.
#
#   An object group creator is started and asked to create three object groups:
#   a group of hobbits, a group of elves; and another group of hobbits.
#
#   ***Test: the object group creator asks the ReplicationManager::FactoryRegistry
#   for the set of factories that can create objects for the desired role.
#   Then it uses the create_object method for each factory to create the actual object.
#
#   [temporary until IOGR's are working:  The object group creator writes the
#   IOR's of the create objects to files -- using a file naming convention to
#   distinguish members of the group.  It will be enhanced to assemble these
#   IORs into an IOGR and either write the IOGR to a file or register it with
#   the Naming Service.]
#
#   The object group creator is also told to unregister all factories that create humans.
#   ***Test: It does so using the unregister_factory_by_role method.
#
#   Three clients are started, one at a time.  Each client is given a reference
#   to an object group
#
#   [temporary until IOGRs and transparent reinvocaton work:  each client is
#   given references to the members of the group and manages its own recovery
#   (client mediated fault tolerance)]
#
#   Each client sends a few requests to first member of the object group.  Eventually
#   this member fails and the requests are then rerouted to the second (and last)
#   member of the group.
#
#   When a clients job is done, it exits and asks the remaining group member to
#   exit, too.
#
#   The factories are run with the quit-on-idle option so when the last object
#   created at that location goes away, the factory exits.
#
#   ***Test: As it exits the factory unregisters itself with the ReplicationManager::FactoryRegistry.
#   ***Test: A command line option determines whether it uses a single
#   unregister_factory_by_location call, or separate unregister_factory calles for
#   each type of object created.  In this test, the shire location uses unregister_factory,
#   and bree and rivendell use unregister_factory_by_location.
#
#   The factory registry is also run with the quit-on-idle option so when the last
#   factory unregisters itself.
#   The ReplicationManager is killed because it doesn't have a quit-on-idle option.

use lib '../../../../bin';
#use lib '$ENV{ACE_ROOT}/bin';
use PerlACE::Run_Test;

########################
#command line options
#set defaults:
my($verbose) = 0;         # 1: report perl actions before executing them
my($debug_builds) = 0;    # 0: use exes from Release directories
my($simulated) = 1;       # 1: use "client simulated" fault tolerance

foreach $i (@ARGV) {
  if ($i eq "--debug_build")
  {
    $debug_builds = 1;
  }
  elsif ($i eq "--no_simulate")  # reverse this once we have FT ORB support
  {
    $simulated = 0;
  }
  elsif ($i eq "-v")
  {
    $verbose += 1;
  }
}

my($build_directory) = "/Release";
if ( $debug_builds ) {
  $build_directory = "";
}

if ( $verbose > 1) {
  print "verbose: $verbose\n";
  print "debug_builds: $debug_builds -> $build_directory\n";
  print "simulated: $simulated\n";
}

my($role1) = "hobbit";
my($role2) = "elf";

my($location1) = "shire";
my($location2) = "bree";
my($location3) = "rivendell";

my ($rm_endpoint) = "-ORBEndpoint iiop://localhost:2833";
my ($rm_initref) = "-ORBInitRef ReplicationManager=corbaloc::localhost:2833/ReplicationManager";

#define temp files
my($rm_ior) = PerlACE::LocalFile ("rm.ior");
my($notifier_ior) = PerlACE::LocalFile ("notifier.ior");
my($detector1_ior) = PerlACE::LocalFile ("detector1.ior");
my($detector2_ior) = PerlACE::LocalFile ("detector2.ior");
my($factory1_ior) = PerlACE::LocalFile ("factory1.ior");
my($factory2_ior) = PerlACE::LocalFile ("factory2.ior");
my($factory3_ior) = PerlACE::LocalFile ("factory3.ior");
my($replica1_ior) = PerlACE::LocalFile ("${role1}_${location1}_0.ior");
my($replica2_ior) = PerlACE::LocalFile ("${role1}_${location2}_0.ior");
my($replica3_ior) = PerlACE::LocalFile ("${role2}_${location2}_1.ior");
my($replica4_ior) = PerlACE::LocalFile ("${role2}_${location3}_0.ior");
my($replica5_ior) = PerlACE::LocalFile ("${role1}_${location1}_1.ior");
my($replica6_ior) = PerlACE::LocalFile ("${role1}_${location2}_2.ior");

my($replica1_iogr) = PerlACE::LocalFile ("${role1}_0.iogr");
my($replica2_iogr) = PerlACE::LocalFile ("${role2}_1.iogr");
my($replica3_iogr) = PerlACE::LocalFile ("${role1}_2.iogr");

my($client_data) = PerlACE::LocalFile ("persistent.dat");

#discard junk from previous tests
unlink $rm_ior;
unlink $notifier_ior;
unlink $detector1_ior;
unlink $detector2_ior;
unlink $factory1_ior;
unlink $factory2_ior;
unlink $factory3_ior;
unlink $replica1_ior;
unlink $replica2_ior;
unlink $replica3_ior;
unlink $replica4_ior;
unlink $replica5_ior;
unlink $replica6_ior;
unlink $replica1_iogr;
unlink $replica2_iogr;

unlink $client_data;

my($status) = 0;

my($RM) = new PerlACE::Process ("$ENV{'TAO_ROOT'}/orbsvcs/FT_ReplicationManager$build_directory/FT_ReplicationManager", "-o $rm_ior $rm_endpoint");
my($RMC) = new PerlACE::Process (".$build_directory/replmgr_controller", "$rm_initref -x");
my($NOT) = new PerlACE::Process ("$ENV{'TAO_ROOT'}/orbsvcs/Fault_Notifier$build_directory/Fault_Notifier", "$rm_initref -o $notifier_ior -q");
my($DET1) = new PerlACE::Process ("$ENV{'TAO_ROOT'}/orbsvcs/Fault_Detector$build_directory/Fault_Detector", "$rm_initref -o $detector1_ior -l $location1 -q");
my($DET2) = new PerlACE::Process ("$ENV{'TAO_ROOT'}/orbsvcs/Fault_Detector$build_directory/Fault_Detector", "$rm_initref -o $detector2_ior -l $location2 -q");
my($FAC1) = new PerlACE::Process (".$build_directory/ft_replica", "$rm_initref -o $factory1_ior -l $location1 -i $role1 -q");
my($FAC2) = new PerlACE::Process (".$build_directory/ft_replica", "$rm_initref -o $factory2_ior -l $location2 -i $role1 -i $role2 -q");
my($FAC3) = new PerlACE::Process (".$build_directory/ft_replica", "$rm_initref -o $factory3_ior -l $location3 -i $role2 -q");

my($OGC);
my($CL1);
my($CL2);
my($CL3);
if ($simulated) {
  print "\nTEST: Preparing Client Mediated Fault Tolerance test.\n" if ($verbose);
  $OGC= new PerlACE::Process (".$build_directory/ft_create", "$rm_initref  -r $role1 -r $role2 -r $role1 -i -n");
  $CL1 = new PerlACE::Process (".$build_directory/ft_client", "-f file://$replica1_ior -f file://$replica2_ior -c testscript");
  $CL2 = new PerlACE::Process (".$build_directory/ft_client", "-f file://$replica3_ior -f file://$replica4_ior -c testscript");
  $CL3 = new PerlACE::Process (".$build_directory/ft_client", "-f file://$replica5_ior -f file://$replica6_ior -c testscript");
}else{
  print "\nTEST: Preparing IOGR based test.\n" if ($verbose);
  $OGC = new PerlACE::Process (".$build_directory/ft_create", "$rm_initref  -r $role1 -r $role2 -r $role1 -g -n");
  $CL1 = new PerlACE::Process (".$build_directory/ft_client", "-f file://$replica1_iogr -c testscript");
  $CL2 = new PerlACE::Process (".$build_directory/ft_client", "-f file://$replica2_iogr -c testscript");
  $CL3 = new PerlACE::Process (".$build_directory/ft_client", "-f file://$replica3_iogr -c testscript");
}

#######################
# Start ReplicationManager

print "\nTEST: Starting ReplicationManager " . $RM->CommandLine . "\n" if ($verbose);
$RM->Spawn ();

print "TEST: waiting for registry's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($rm_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$rm_ior>\n";
    $RM->Kill (); $RM->TimedWait (1);
    exit 1;
}

#######################
# Start FaultNotifier
print "\nTEST: Starting FaultNotifier " . $NOT->CommandLine . "\n" if ($verbose);
$NOT->Spawn ();

print "TEST: waiting for FaultNotifier's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($notifier_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$notifier_ior>\n";
    $RM->Kill (); $RM->TimedWait (1);
    $NOT->Kill (); $NOT->TimedWait (1);
    exit 1;
}


##############################
# Start FaultDetectorFactory 1
print "\nTEST: Starting FaultDetectorFactory at $location1 " . $DET1->CommandLine . "\n" if ($verbose);
$DET1->Spawn ();

print "TEST: waiting for FaultDetector's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($detector1_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$detector1_ior>\n";
    $RM->Kill (); $RM->TimedWait (1);
    $NOT->Kill (); $NOT->TimedWait (1);
    $DET1->Kill (); $DET1->TimedWait (1);
    exit 1;
}

##############################
# Start FaultDetectorFactory 2
print "\nTEST: Starting FaultDetectorFactory at $location2 " . $DET2->CommandLine . "\n" if ($verbose);
$DET2->Spawn ();

print "TEST: waiting for FaultDetector's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($detector2_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$detector2_ior>\n";
    $RM->Kill (); $RM->TimedWait (1);
    $NOT->Kill (); $NOT->TimedWait (1);
    $DET1->Kill (); $DET1->TimedWait (1);
    $DET2->Kill (); $DET2->TimedWait (1);
    exit 1;
}


#################
# Start Factories

print "\nTEST: Starting replica factory at $location1 " . $FAC1->CommandLine . "\n" if ($verbose);
$FAC1->Spawn ();

print "TEST: waiting for factory 1's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($factory1_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$factory1_ior>\n";
    $RM->Kill (); $RM->TimedWait (1);
    $NOT->Kill (); $NOT->TimedWait (1);
    $DET1->Kill (); $DET1->TimedWait (1);
    $DET2->Kill (); $DET2->TimedWait (1);
    $FAC1->Kill (); $FAC1->TimedWait (1);
    exit 1;
}

print "\nTEST: Starting replica factory at $location2 " . $FAC2->CommandLine . "\n" if ($verbose);
$FAC2->Spawn ();

print "TEST: waiting for factory 2's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($factory2_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$factory2_ior>\n";
    $RM->Kill (); $RM->TimedWait (1);
    $NOT->Kill (); $NOT->TimedWait (1);
    $DET1->Kill (); $DET1->TimedWait (1);
    $DET2->Kill (); $DET2->TimedWait (1);
    $FAC1->Kill (); $FAC1->TimedWait (1);
    $FAC2->Kill (); $FAC2->TimedWait (1);
    exit 1;
}

print "\nTEST: Starting replica factory at $location3 " . $FAC3->CommandLine . "\n" if ($verbose);
$FAC3->Spawn ();

print "TEST: waiting for factory 3's IOR\n" if ($verbose);
if (PerlACE::waitforfile_timed ($factory3_ior, 5) == -1) {
    print STDERR "ERROR: cannot find file <$factory3_ior>\n";
    $RM->Kill (); $RM->TimedWait (1);
    $NOT->Kill (); $NOT->TimedWait (1);
    $DET1->Kill (); $DET1->TimedWait (1);
    $DET2->Kill (); $DET2->TimedWait (1);
    $FAC1->Kill (); $FAC1->TimedWait (1);
    $FAC2->Kill (); $FAC2->TimedWait (1);
    $FAC3->Kill (); $FAC3->TimedWait (1);
    exit 1;
}

######################
# Create object groups

print "\nTEST: Starting object group creator " . $OGC->CommandLine . "\n" if ($verbose);
$OGC->Spawn ();

print "\nTEST: wait for object group creator.\n" if ($verbose);
$config = $OGC->WaitKill (30);
if ($config != 0) {
    print STDERR "ERROR: Object Group Creator returned $config\n";
    $RM->Kill (); $RM->TimedWait (1);
    $NOT->Kill (); $NOT->TimedWait (1);
    $DET1->Kill (); $DET1->TimedWait (1);
    $DET2->Kill (); $DET2->TimedWait (1);
    $FAC1->Kill (); $FAC1->TimedWait (1);
    $FAC2->Kill (); $FAC2->TimedWait (1);
    $FAC3->Kill (); $FAC3->TimedWait (1);
    exit 1;
}

#############
# Run clients

print "\nTEST: Starting client using first group of hobbits " . $CL1->CommandLine . "\n" if ($verbose);
$client = $CL1->SpawnWaitKill (60);

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}

print "\nTEST: Starting client using group of elves " . $CL2->CommandLine . "\n" if ($verbose);
$client2 = $CL2->SpawnWaitKill (60);

if ($client2 != 0) {
    print STDERR "ERROR: client returned $client2\n";
    $status = 1;
}

print "\nTEST: Starting client using second group of hobbits " . $CL3->CommandLine . "\n" if ($verbose);
$client3 = $CL3->SpawnWaitKill (60);

if ($client3 != 0) {
    print STDERR "ERROR: client returned $client3\n";
    $status = 1;
}

######################
# Clean house and exit

print "\nTEST: wait for factory 1.\n" if ($verbose);
$factory1 = $FAC1->WaitKill (30);
if ($factory1 != 0) {
    print STDERR "ERROR: replica returned $factory 1\n";
    $status = 1;
}

print "\nTEST: wait for factory 2.\n" if ($verbose);
$factory2 = $FAC2->WaitKill (30);
if ($factory2 != 0) {
    print STDERR "ERROR: factory 2 returned $factory2\n";
    $status = 1;
}

print "\nTEST: wait for factory 3.\n" if ($verbose);
$factory3 = $FAC3->WaitKill (30);
if ($factory3 != 0) {
    print STDERR "ERROR: factory 3 returned $factory3\n";
    $status = 1;
}

print "\nTEST: wait for FaultDetectorFactory 1.\n" if ($verbose);
$detector1 = $DET1->WaitKill (30);
if ($detector1 != 0) {
    print STDERR "ERROR: FaultDetectorFactory returned $detector1\n";
    $status = 1;
}

print "\nTEST: wait for FaultDetectorFactory 2.\n" if ($verbose);
$detector2 = $DET2->WaitKill (30);
if ($detector2 != 0) {
    print STDERR "ERROR: FaultDetectorFactory returned $detector2\n";
    $status = 1;
}

print "\nTEST: shutting down the replication manager.\n" if ($verbose);
$controller = $RMC->SpawnWaitKill (300);
if ($controller != 0) {
    print STDERR "ERROR: replication manager controller returned $controller\n";
    $status = 1;
}

print "\nTEST: wait for ReplicationManager.\n" if ($verbose);
#$RM->Kill ();
$repmgr = $RM->WaitKill (30);
if ($repmgr != 0) {
    print STDERR "ERROR: ReplicationManager returned $repmgr\n";
    $status = 1;
}

print "\nTEST: wait for FaultNotifier.\n" if ($verbose);
$notifier = $NOT->WaitKill (30);
if ($notifier != 0) {
    print STDERR "ERROR: FaultNotifier returned $notifier\n";
    $status = 1;
}

if ($status == 0 && 0) {
  print "\nTEST: releasing scratch files.\n" if ($verbose);
  unlink $rm_ior;
  unlink $detector1_ior;
  unlink $detector2_ior;
  unlink $notifier_ior;
  unlink $factory1_ior;
  unlink $factory2_ior;
  unlink $factory3_ior;
  unlink $replica1_ior;
  unlink $replica2_ior;
  unlink $replica3_ior;
  unlink $replica4_ior;
  unlink $replica5_ior;
  unlink $replica6_ior;
  unlink $replica1_iogr;
  unlink $replica2_iogr;

  unlink $client_data;
}


exit $status;
