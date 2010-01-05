eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::TestTarget;

$status = 0;
$debug_level = '0';

foreach $i (@ARGV) {
    if ($i eq '-debug') {
        $debug_level = '10';
    }
}

my $server = PerlACE::TestTarget::create_target (1) || die "Create target 1 failed\n";
my $client1 = PerlACE::TestTarget::create_target (2) || die "Create target 2 failed\n";
my $client2 = PerlACE::TestTarget::create_target (3) || die "Create target 3 failed\n";

my $iorbase = "server.ior";
my $expected = 400;
my $maybe_lost = 800;
my $server_iorfile = $server->LocalFile ($iorbase);
my $client1_iorfile = $client1->LocalFile ($iorbase);
my $client2_iorfile = $client2->LocalFile ($iorbase);
$server->DeleteFile($iorbase);
$client1->DeleteFile($iorbase);
$client2->DeleteFile($iorbase);

$SV = $server->CreateProcess ("server", "-ORBdebuglevel $debug_level -o $server_iorfile ".
                                        "-e $expected -l $maybe_lost");
$CL1 = $client1->CreateProcess ("client", "-k file://$client1_iorfile");
$CL2 = $client2->CreateProcess ("client", "-k file://$client2_iorfile");

# -*- perl -*-

for ($n = 0; $n < 10; ++$n) {
    print "=================================================================\n";

    $server->DeleteFile($iorbase);
    $client1->DeleteFile($iorbase);
    $client2->DeleteFile($iorbase);

    $server_status = $SV->Spawn ();
    if ($server_status != 0) {
        print STDERR "ERROR: server returned $server_status\n";
        exit 1;
    }

    if ($server->WaitForFileTimed ($iorbase,
                                   $server->ProcessStartWaitInterval()) == -1) {
        print STDERR "ERROR: cannot find file <$server_iorfile>\n";
        $SV->Kill (); $SV->TimedWait (1);
        exit 1;
    }

    if ($server->GetFile ($iorbase) == -1) {
        print STDERR "ERROR: cannot retrieve file <$server_iorfile>\n";
        $SV->Kill (); $SV->TimedWait (1);
        exit 1;
    }

    if ($client1->PutFile ($iorbase) == -1) {
        print STDERR "ERROR: cannot set file <$client1_iorfile>\n";
        $SV->Kill (); $SV->TimedWait (1);
        exit 1;
    }

    if ($client2->PutFile ($iorbase) == -1) {
        print STDERR "ERROR: cannot set file <$client2_iorfile>\n";
        $SV->Kill (); $SV->TimedWait (1);
        exit 1;
    }

    $client1_status = $CL1->Spawn ();

    if ($client1_status != 0) {
        print STDERR "ERROR: client 1 returned $client1_status\n";
        $SV->Kill();
        exit 1;
    }

    $client2_status = $CL2->Spawn ();

    if ($client2_status != 0) {
        print STDERR "ERROR: client 2 returned $client2_status\n";
        $CL1->Kill();
        $SV->Kill();
        exit 1;
    }

    $client_status = $CL1->WaitKill ($client1->ProcessStartWaitInterval() + 25);
    if ($client_status != 0) {
        print STDERR "ERROR: client 1 returned $client_status\n";
        $CL2->Kill();
        $SV->Kill();
        exit 1;
    }

    $client_status = $CL2->WaitKill ($client2->ProcessStartWaitInterval() + 25);
    if ($client_status != 0) {
        print STDERR "ERROR: client 2 returned $client_status\n";
        $SV->Kill();
        exit 1;
    }

    $server_status = $SV->WaitKill ($server->ProcessStopWaitInterval() + 45);

    if ($server_status != 0) {
        print STDERR "ERROR: server returned $server_status\n";
        $status = 1;
    }
}

$server->DeleteFile($iorbase);
$client1->DeleteFile($iorbase);
$client2->DeleteFile($iorbase);

exit $status;
