eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib '../../../bin';
use PerlACE::Run_Test;

$iterations = 5;
$ORBdebuglevel = 0;
$status = 0;

$iorfile = "ior";
unlink $iorfile;

$protocol = "diop";

$SV = new PerlACE::Process ("server", "-ORBdebuglevel $ORBdebuglevel -ORBEndpoint $protocol://");
$CL = new PerlACE::Process ("client", "-ORBdebuglevel $ORBdebuglevel -x 1 -i $iterations");

$SV->Spawn ();

if (PerlACE::waitforfile_timed ($iorfile, 10) == -1) {
    print STDERR "ERROR: cannot find file <$iorfile>\n";
    $SV->Kill ();
    exit 1;
}

$client = $CL->SpawnWaitKill (60);
$server = $SV->WaitKill (5);

unlink $iorfile;

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}

if ($server != 0) {
    print STDERR "ERROR: server returned $server\n";
    $status = 1;
}

exit $status;
