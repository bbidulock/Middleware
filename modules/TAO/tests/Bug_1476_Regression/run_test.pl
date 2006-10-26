eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
     & eval 'exec perl -S $0 $argv:q'
     if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

$iorfile = PerlACE::LocalFile ("server.ior");
unlink $iorfile;

$SV  = new PerlACE::Process ("server", "-o $iorfile");
$CL1 = new PerlACE::Process ("client", "-k file://$iorfile");


$SV->Spawn ();

if (PerlACE::waitforfile_timed ($iorfile, 15) == -1) {
    print STDERR "ERROR: cannot find file <$iorfile>\n";
    $SV->Kill (); $SV->TimedWait (1);
    exit 1;
}

$CL1->Spawn (30);

$client1 = $CL1->WaitKill (30);

if ($client1 != 0) {
    print STDERR "ERROR: client 1 returned $client1\n";
    $status = 1;
}

$server = $SV->WaitKill (30);

if ($server != 0) {
    print STDERR "ERROR: server returned $server\n";
    $status = 1;
}

unlink $iorfile;

exit $status;
