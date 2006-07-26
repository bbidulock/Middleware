eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib '../../../../../bin';
use PerlACE::Run_Test;
use File::stat;

# amount of delay between running the servers

$sleeptime = 6;
$status = 0;

$nsior = PerlACE::LocalFile ("ns.ior");
$test1 = PerlACE::LocalFile ("test1");
$test2 = PerlACE::LocalFile ("test2");
$input = PerlACE::LocalFile ("test_input");

unlink $nsior, $test1, $test2, $input;

# generate test stream data
# the size of this file is limited by the maximum packet size
# windows has a maximum size of 8KB
$input = PerlACE::generate_test_file("test_input", 32000);

$NS  = new PerlACE::Process ("../../../Naming_Service/Naming_Service", "-o $nsior");
$SV1 = new PerlACE::Process ("server", "-ORBInitRef NameService=file://$nsior -f $test1");
$SV2 = new PerlACE::Process ("server", "-ORBInitRef NameService=file://$nsior -f $test2");
$CL  = new PerlACE::Process ("ftp", "-ORBSvcConf components_svc$PerlACE::svcconf_ext -ORBInitRef NameService=file://$nsior -f $input");

print STDERR "Starting Naming Service\n";

if ($NS->Spawn () == -1) {
    exit 1;
}

if (PerlACE::waitforfile_timed ($nsior, 15) == -1) {
    print STDERR "ERROR: cannot find naming service IOR file\n";
    $NS->Kill ();
    exit 1;
}

print STDERR "Starting Server 1\n";

$SV1->Spawn ();

sleep $sleeptime;

print STDERR "Starting Server 2\n";

$SV2->Spawn ();

sleep $sleeptime;

print STDERR "Starting Client\n";

$client = $CL->SpawnWaitKill (200);

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}

$server = $SV1->TerminateWaitKill (5);

if ($server != 0) {
    print STDERR "ERROR: server 1 returned $server\n";
    $status = 1;
}

$server = $SV2->TerminateWaitKill (5);

if ($server != 0) {
    print STDERR "ERROR: server 2 returned $server\n";
    $status = 1;
}

$nserver = $NS->TerminateWaitKill (5);

if ($nserver != 0) {
    print STDERR "ERROR: Naming Service returned $nserver\n";
    $status = 1;
}

unlink $nsior, $test1, $test2, $input;

exit $status;
