eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

# Make pretty look thing
print STDERR "\n";

$status = 0;

$iorfile1base = "server.ior";
$iorfile1 = PerlACE::LocalFile ("$iorfile1base");
$iorfile2 = PerlACE::LocalFile ("server2.ior");
$iorfile3 = PerlACE::LocalFile ("server3.ior");

unlink $iorfile1, $iorfile2, $iorfile3;

if (PerlACE::is_vxworks_test()) {
  $SV1 = new PerlACE::ProcessVX ("server", "-o $iorfile1base");
}
else {
  $SV1 = new PerlACE::Process ("server", "-o $iorfile1");
}
$SV2 = new PerlACE::Process ("server", "-o $iorfile2 -f file://$iorfile1");
$SV3 = new PerlACE::Process ("server", "-o $iorfile3 -f file://$iorfile2");
$CL  = new PerlACE::Process ("client", "-s 3 -k file://$iorfile3");


$SV1->Spawn ();

if (PerlACE::waitforfile_timed ($iorfile1, $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR "ERROR: cannot find file <$iorfile1>\n";
    $SV1->Kill (); 
    exit 1;
}

$SV2->Spawn ();

if (PerlACE::waitforfile_timed ($iorfile2, $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR "ERROR: cannot find file <$iorfile2>\n";
    $SV1->Kill (); 
    $SV2->Kill ();
    exit 1;
}

$SV3->Spawn ();

if (PerlACE::waitforfile_timed ($iorfile3, $PerlACE::wait_interval_for_process_creation) == -1) {
    print STDERR "ERROR: cannot find file <server3>\n";
    $SV1->Kill (); 
    $SV2->Kill ();
    $SV3->Kill ();
    exit 1;
}
    
$client  = $CL->SpawnWaitKill (60);
$server1 = $SV1->WaitKill (15);
$server2 = $SV2->WaitKill (15);
$server3 = $SV3->WaitKill (15);

unlink $iorfile1, $iorfile2, $iorfile3;
    
if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
} 

if ($server1 != 0) {
    print STDERR "ERROR: server 1 returned $server\n";
    $status = 1;
} 

if ($server2 != 0) {
    print STDERR "ERROR: server 2 returned $server\n";
    $status = 1;
} 

if ($server3 != 0) {
    print STDERR "ERROR: server 3 returned $server\n";
    $status = 1;
} 

exit $status;
